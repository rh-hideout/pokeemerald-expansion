// ─── Config ─────────────────────────────────────────────────────────────────
// Auto-detect repo owner/name from the GitHub Pages URL, or fall back to defaults.
// GitHub Pages URLs are: https://<owner>.github.io/<repo>/...
const REPO_OWNER = (() => {
    try {
        const host = location.hostname;
        if (host.endsWith('.github.io')) return host.replace('.github.io', '');
    } catch {}
    return 'theReuben';
})();
const REPO_NAME = (() => {
    try {
        const parts = location.pathname.split('/').filter(Boolean);
        // If deployed at /<repo>/editor/ the repo is parts[0]
        // If deployed at /<repo>/ the repo is parts[0]
        if (location.hostname.endsWith('.github.io') && parts.length > 0) {
            return parts[0];
        }
    } catch {}
    return 'pokemon-brazilianite';
})();
const BRANCH = 'master';
const API_BASE = 'https://api.github.com';

// ─── State ──────────────────────────────────────────────────────────────────
let state = {
    page: 'maps',
    trainers: null,
    encounters: null,
    moves: null,
    items: null,
    abilities: null,
    config: null,
    maps: null,
    music: null,
    pokemon: null,
    learnsets: null,   // { varName: { gen: 'gen_X', moves: [{level, move}] } }
    learnables: null,  // all_learnables.json content
    search: '',
    configFilter: 'all',
    musicFilter: 'all',
    mapDetail: null,
    mapTypeFilter: 'all',
    npcDetail: null,
    pokemonPage: 0,
};

// Track pending changes: { filePath: newContent }
const pendingChanges = {};
// Track original file content for diffing
const originalContent = {};
// GitHub token
let ghToken = localStorage.getItem('gh_token') || '';
let ghUser = null;

// ─── Editor Branch State ────────────────────────────────────────────────────
// Active editing branch — created on first edit, persisted across reloads
let editorBranch = localStorage.getItem('editor_branch') || '';
let editorBranchLastCommit = localStorage.getItem('editor_branch_last_commit') || '';
// Queue for serialising auto-commits (prevents races)
let commitQueue = Promise.resolve();

const $ = (sel, el = document) => el.querySelector(sel);
const $$ = (sel, el = document) => [...el.querySelectorAll(sel)];
const content = $('#content');

// ─── GitHub API ─────────────────────────────────────────────────────────────
async function ghFetch(path, opts = {}) {
    const headers = { 'Accept': 'application/vnd.github.v3+json', ...opts.headers };
    if (ghToken) headers['Authorization'] = `token ${ghToken}`;
    const res = await fetch(API_BASE + path, { ...opts, headers });
    if (!res.ok) {
        const body = await res.json().catch(() => ({}));
        throw new Error(body.message || `GitHub API error: ${res.status}`);
    }
    return res.json();
}

async function fetchFile(filePath) {
    try {
        const data = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/${filePath}?ref=${BRANCH}`);
        if (data.content) {
            const text = atob(data.content.replace(/\n/g, ''));
            // Handle UTF-8 properly
            const bytes = Uint8Array.from(text, c => c.charCodeAt(0));
            const decoded = new TextDecoder().decode(bytes);
            originalContent[filePath] = decoded;
            return decoded;
        }
        // File too large for Contents API — fall through to raw fetch
    } catch {
        // File may exceed GitHub's 1MB Contents API limit — fall through to raw fetch
    }
    const rawUrl = `https://raw.githubusercontent.com/${REPO_OWNER}/${REPO_NAME}/${BRANCH}/${filePath}`;
    const headers = {};
    if (ghToken) headers['Authorization'] = `token ${ghToken}`;
    const res = await fetch(rawUrl, { headers });
    if (!res.ok) throw new Error(`Failed to fetch file: ${res.status}`);
    const decoded = await res.text();
    originalContent[filePath] = decoded;
    return decoded;
}

async function fetchJSON(filePath) {
    const text = await fetchFile(filePath);
    return JSON.parse(text);
}

// ─── Change Tracking ────────────────────────────────────────────────────────

// Generate a readable timestamp for branch names: YYYY-MM-DD_HH-mm
function readableTimestamp() {
    const d = new Date();
    const pad = n => String(n).padStart(2, '0');
    return `${d.getFullYear()}-${pad(d.getMonth() + 1)}-${pad(d.getDate())}_${pad(d.getHours())}-${pad(d.getMinutes())}`;
}

// Format an ISO timestamp for display
function formatCommitTime(iso) {
    if (!iso) return '';
    const d = new Date(iso);
    return d.toLocaleString(undefined, {
        month: 'short', day: 'numeric',
        hour: '2-digit', minute: '2-digit',
    });
}

// Ensure the editor branch exists; create it on first edit
async function ensureEditorBranch() {
    if (editorBranch) return editorBranch;
    if (!ghUser) throw new Error('Sign in with GitHub before making changes.');
    return await createNewEditorBranch();
}

// Commit a single file to the editor branch
async function commitFile(filePath, content) {
    const branch = await ensureEditorBranch();

    // Get the current file SHA on the branch (needed for updates)
    let fileSha;
    try {
        const existing = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/${filePath}?ref=${branch}`);
        fileSha = existing.sha;
    } catch { /* new file */ }

    const encoder = new TextEncoder();
    const bytes = encoder.encode(content);
    let binary = '';
    for (let i = 0; i < bytes.length; i++) {
        binary += String.fromCharCode(bytes[i]);
    }
    const base64 = btoa(binary);

    const result = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/${filePath}`, {
        method: 'PUT',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
            message: `Update ${filePath} via web editor`,
            content: base64,
            sha: fileSha,
            branch
        })
    });

    // Update last commit timestamp
    editorBranchLastCommit = result.commit?.committer?.date || new Date().toISOString();
    localStorage.setItem('editor_branch_last_commit', editorBranchLastCommit);
    updateBranchUI();
}

// markChanged: queue an auto-commit for this file
function markChanged(filePath, newContent) {
    pendingChanges[filePath] = newContent;
    updateChangesUI();

    // Auto-commit (serialised via queue to prevent races)
    commitQueue = commitQueue
        .then(() => commitFile(filePath, newContent))
        .catch(e => {
            toast('Auto-save failed: ' + e.message, true);
        });
}

function getChangeCount() {
    return Object.keys(pendingChanges).length;
}

function updateChangesUI() {
    const count = getChangeCount();
    const el = $('#pending-changes');
    if (count > 0) {
        el.style.display = 'flex';
        $('#changes-count').textContent = `${count} change${count > 1 ? 's' : ''}`;
    } else {
        el.style.display = 'none';
    }
    updateBranchUI();
}

function updateBranchUI() {
    const el = $('#branch-info');
    if (!el) return;
    if (editorBranch) {
        const shortBranch = editorBranch.replace(/^editor\//, '');
        const timeStr = editorBranchLastCommit ? ` · ${formatCommitTime(editorBranchLastCommit)}` : '';
        el.style.display = 'inline-flex';
        el.innerHTML = `
            <span class="branch-info-label" onclick="openBranchPicker()" title="Click to switch branch">
                &#9741; ${escHtml(shortBranch)}${timeStr}
            </span>`;
    } else if (ghUser) {
        el.style.display = 'inline-flex';
        el.innerHTML = `
            <span class="branch-info-label" onclick="openBranchPicker()" title="Select or create an editing branch">
                &#9741; No branch &mdash; pick one
            </span>`;
    } else {
        el.style.display = 'none';
    }
}

function clearEditorBranch() {
    editorBranch = '';
    editorBranchLastCommit = '';
    localStorage.removeItem('editor_branch');
    localStorage.removeItem('editor_branch_last_commit');
    Object.keys(pendingChanges).forEach(k => delete pendingChanges[k]);
    updateChangesUI();
}

// Switch to an existing branch (updates local state, no data reload)
function switchToBranch(branchName, lastCommitDate) {
    editorBranch = branchName;
    editorBranchLastCommit = lastCommitDate || '';
    localStorage.setItem('editor_branch', branchName);
    if (lastCommitDate) localStorage.setItem('editor_branch_last_commit', lastCommitDate);
    else localStorage.removeItem('editor_branch_last_commit');
    // Clear local pending changes — the branch has its own committed state
    Object.keys(pendingChanges).forEach(k => delete pendingChanges[k]);
    updateChangesUI();
    toast(`Switched to ${branchName.replace(/^editor\//, '')}`);
}

// Create a fresh branch and switch to it
async function createNewEditorBranch() {
    if (!ghUser) { openAuthModal(); return; }
    const ref = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/git/refs/heads/${BRANCH}`);
    const baseSha = ref.object.sha;
    const branchName = `editor/${ghUser.login}/${readableTimestamp()}`;
    await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/git/refs`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ ref: `refs/heads/${branchName}`, sha: baseSha })
    });
    switchToBranch(branchName, '');
    return branchName;
}

// Fetch all editor/* branches with latest commit info
async function fetchEditorBranches() {
    // List branches matching editor/ prefix. GitHub API doesn't filter by prefix
    // on the list-branches endpoint, so we fetch pages and filter client-side.
    // For repos with many branches we limit to 100 most recent.
    let branches = [];
    let page = 1;
    while (page <= 3) { // max 300 branches scanned
        const batch = await ghFetch(
            `/repos/${REPO_OWNER}/${REPO_NAME}/branches?per_page=100&page=${page}`
        );
        branches = branches.concat(batch);
        if (batch.length < 100) break;
        page++;
    }
    const editorBranches = branches.filter(b => b.name.startsWith('editor/'));

    // Fetch latest commit date for each branch (in parallel, batched)
    const enriched = await Promise.all(editorBranches.map(async (b) => {
        try {
            const commit = await ghFetch(
                `/repos/${REPO_OWNER}/${REPO_NAME}/commits/${b.commit.sha}`
            );
            return {
                name: b.name,
                sha: b.commit.sha,
                date: commit.commit.committer.date,
                message: commit.commit.message,
            };
        } catch {
            return { name: b.name, sha: b.commit.sha, date: '', message: '' };
        }
    }));

    // Sort newest first
    enriched.sort((a, b) => (b.date || '').localeCompare(a.date || ''));
    return enriched;
}

async function openBranchPicker() {
    if (!ghUser) { openAuthModal(); return; }

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="width:560px">
            <div class="modal-header">
                <h2>Switch Branch</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body" style="padding:0">
                <div style="padding:16px 20px;border-bottom:1px solid var(--border);display:flex;align-items:center;justify-content:space-between">
                    <span style="font-size:13px;color:var(--text-dim)">Your editor branches</span>
                    <button class="btn btn-primary btn-sm" id="new-branch-btn">+ New Branch</button>
                </div>
                <div id="branch-list" style="max-height:400px;overflow-y:auto;padding:8px 0">
                    <div class="loading-center" style="padding:32px"><div class="spinner"></div> Loading branches...</div>
                </div>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    // New branch button
    overlay.querySelector('#new-branch-btn').addEventListener('click', async () => {
        const btn = overlay.querySelector('#new-branch-btn');
        btn.disabled = true;
        btn.textContent = 'Creating...';
        try {
            await createNewEditorBranch();
            overlay.remove();
        } catch (e) {
            toast('Failed to create branch: ' + e.message, true);
            btn.disabled = false;
            btn.textContent = '+ New Branch';
        }
    });

    // Load branches
    try {
        const branches = await fetchEditorBranches();
        const listEl = overlay.querySelector('#branch-list');
        if (branches.length === 0) {
            listEl.innerHTML = `
                <div style="padding:32px;text-align:center;color:var(--text-dim);font-size:13px">
                    No editor branches found.<br>Click <strong>+ New Branch</strong> to start editing, or just make an edit and one will be created automatically.
                </div>`;
            return;
        }

        listEl.innerHTML = branches.map(b => {
            const short = b.name.replace(/^editor\//, '');
            const isCurrent = b.name === editorBranch;
            const timeStr = b.date ? formatCommitTime(b.date) : 'no commits';
            const lastMsg = b.message ? b.message.split('\n')[0] : '';
            // Truncate commit message
            const msgDisplay = lastMsg.length > 60 ? lastMsg.slice(0, 57) + '...' : lastMsg;
            return `
                <div class="branch-row${isCurrent ? ' active' : ''}"
                     data-branch="${escAttr(b.name)}" data-date="${escAttr(b.date)}">
                    <div class="branch-row-main">
                        <span class="branch-row-name">${escHtml(short)}</span>
                        ${isCurrent ? '<span class="branch-row-current">current</span>' : ''}
                    </div>
                    <div class="branch-row-meta">
                        <span>${escHtml(timeStr)}</span>
                        ${msgDisplay ? `<span class="branch-row-msg" title="${escAttr(lastMsg)}">${escHtml(msgDisplay)}</span>` : ''}
                    </div>
                </div>`;
        }).join('');

        // Click to switch
        listEl.querySelectorAll('.branch-row').forEach(row => {
            row.addEventListener('click', () => {
                const name = row.dataset.branch;
                const date = row.dataset.date;
                if (name === editorBranch) { overlay.remove(); return; }
                switchToBranch(name, date);
                overlay.remove();
            });
        });
    } catch (e) {
        const listEl = overlay.querySelector('#branch-list');
        listEl.innerHTML = `<div style="padding:20px;color:var(--red);font-size:13px">Failed to load branches: ${escHtml(e.message)}</div>`;
    }
}

// ─── Auth ───────────────────────────────────────────────────────────────────
async function checkAuth() {
    if (!ghToken) {
        $('#auth-status').textContent = '';
        $('#auth-btn').textContent = 'Sign in with GitHub';
        $('#auth-btn').onclick = openAuthModal;
        return;
    }
    try {
        ghUser = await ghFetch('/user');
        $('#auth-status').textContent = `Signed in as ${ghUser.login}`;
        $('#auth-btn').textContent = 'Sign out';
        $('#auth-btn').onclick = signOut;
        updateBranchUI();
    } catch {
        $('#auth-status').textContent = 'Invalid token';
        ghToken = '';
        localStorage.removeItem('gh_token');
        $('#auth-btn').textContent = 'Sign in with GitHub';
        $('#auth-btn').onclick = openAuthModal;
    }
}

function signOut() {
    ghToken = '';
    ghUser = null;
    localStorage.removeItem('gh_token');
    clearEditorBranch();
    checkAuth();
    toast('Signed out');
}

function openAuthModal() {
    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="width:500px">
            <div class="modal-header">
                <h2>Sign in with GitHub</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <p style="font-size:13px;color:var(--text-dim);margin-bottom:16px">
                    To submit changes as a Pull Request, you need a GitHub Personal Access Token.
                    This is stored only in your browser's local storage.
                </p>
                <div class="form-group">
                    <label>GitHub Personal Access Token</label>
                    <input type="password" id="token-input" placeholder="ghp_xxxxxxxxxxxxxxxxxxxx">
                    <p class="help-text" style="margin-top:8px">
                        Create a token at GitHub &rarr; Settings &rarr; Developer settings &rarr; Personal access tokens &rarr; Fine-grained tokens.<br>
                        Required permissions: <strong>Contents</strong> (Read & Write) and <strong>Pull Requests</strong> (Read & Write) on this repository.
                    </p>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-token-btn">Save Token</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-token-btn').addEventListener('click', async () => {
        const token = $('#token-input').value.trim();
        if (!token) return toast('Please enter a token', true);
        ghToken = token;
        localStorage.setItem('gh_token', token);
        overlay.remove();
        await checkAuth();
        if (ghUser) toast('Signed in as ' + ghUser.login);
    });
}

// ─── Parsers (ported from server.js) ────────────────────────────────────────
function parseTrainers(text) {
    const trainers = [];
    const trainerBlocks = text.split(/^=== (TRAINER_\w+) ===/m);
    for (let i = 1; i < trainerBlocks.length; i += 2) {
        const trainerId = trainerBlocks[i].trim();
        const body = (trainerBlocks[i + 1] || '').trim();
        const trainer = { id: trainerId, pokemon: [] };
        const lines = body.split('\n');
        let currentMon = null;
        let pastTrainerFields = false;

        for (const rawLine of lines) {
            const line = rawLine.trim();
            if (!line || line.startsWith('/*') || line.startsWith('*/') || line.startsWith('//')) continue;

            if (!pastTrainerFields) {
                const fieldMatch = line.match(/^(Name|Class|Pic|Gender|Music|Double Battle|AI|Items|Mugshot|Starting Status):\s*(.*)$/i);
                if (fieldMatch) {
                    const key = fieldMatch[1].toLowerCase().replace(/\s+/g, '_');
                    trainer[key] = fieldMatch[2].trim();
                    continue;
                }
                pastTrainerFields = true;
            }

            const moveMatch = line.match(/^-\s+(.+)$/);
            if (moveMatch) {
                if (currentMon) {
                    if (!currentMon.moves) currentMon.moves = [];
                    currentMon.moves.push(moveMatch[1].trim());
                }
                continue;
            }

            const pokemonFieldMatch = line.match(/^(Level|Ability|Nature|IVs|EVs|Ball|Happiness|Shiny|Dynamax Level|Gigantamax|Tera Type):\s*(.*)$/i);
            if (pokemonFieldMatch) {
                if (currentMon) {
                    const key = pokemonFieldMatch[1].toLowerCase().replace(/\s+/g, '_');
                    currentMon[key] = pokemonFieldMatch[2].trim();
                }
                continue;
            }

            if (line && !line.startsWith('-')) {
                if (currentMon) trainer.pokemon.push(currentMon);
                currentMon = { species: line };
            }
        }
        if (currentMon) trainer.pokemon.push(currentMon);
        trainers.push(trainer);
    }
    return trainers;
}

function serializeTrainers(trainers) {
    const headerComment = `/*\nTrainers and their parties defined with Competetive Syntax.\nCompatible with Pokemon Showdown exports.\nhttps://github.com/smogon/pokemon-showdown/blob/master/sim/TEAMS.md\n\nA trainer specification starts with "=== TRAINER_XXXX ==="\nand includes everything until the next line that starts with "==="\nor the file ends.\nA blank line is required between the trainer and their Pokemon\nand between their Pokemon.\nTRAINER_XXXX is how the trainer is referred to within code.\n\nFields with description and/or example of usage\nRequired fields for trainers:\n    - Name\n    - Pic\nOptional (but still recommended) fields for trainers:\n    - Class (if not specified, PkMn Trainer will be used)\n    - Gender (Male/Female, affects random gender weights of party if not specified)\n    - Music\n    - Items (Some Item / Another Item / Third Item)\n            (Can also be specified with ITEM_SOME_ITEM)\n    - Battle Type (Singles / Doubles, defaults to Singles)\n    - AI (Ai Flag / Another Flag / Third Flag / ...\n          see "constants/battle_ai.h" for all flags)\n    - Mugshot (enable Mugshots during battle transition\n               set to one of Purple, Green, Pink, Blue or Yellow)\n    - Starting Status (see include/constants/battle.h for values)\n\nPokemon are then specified using the Showdown Export format.\nIf a field is not specified, it will use it\'s default value.\n\nRequired fields for Pokemon:\n    - Species (Either as SPECIES_ABRA or Abra)\n      This line also specifies Gender, Nickname and Held item.\n      Alfred (Abra) (M) @ Eviolite\n      Roberta (SPECIES_ABRA) (F) @ ITEM_CHOICE_SPECS\n      Both lines are valid. Gender (M) or (F) must use a capital letter.\n      Nickname length is limited to 10 characters using standard letters.\n      With narrow font it\'s increased to 12. Longer strings will be silently shortened.\n\nOptional fields for Pokemon:\n    - Level (Number between 1 and 100, defaults to 100)\n    - Ability (Ability Name or ABILITY_ABILITY_NAME)\n    - IVs (0 HP / 1 Atk / 2 Def / 3 SpA / 4 SpD / 5 Spe, defaults to all 31)\n          (Order does not matter)\n    - EVs (252 HP / 128 Spe / 48 Def, defaults to all 0, is not capped at 512 total)\n          (Order does not matter)\n    - Ball (Poke Ball or ITEM_POKE_BALL, defaults to Poke Ball)\n    - Happiness (Number between 1 and 255)\n    - Nature (Rash or NATURE_RASH, defaults to Hardy)\n    - Shiny (Yes/No, defaults to No)\n    - Dynamax Level (Number between 0 and 10, default 10, also sets "shouldDynamax" to True)\n    - Gigantamax (Yes/No, sets to Gigantamax factor)\n                 (doesn\'t do anything to Pokemon without a Gigantamax form, also sets "shouldDynamax" to True)\n    - Tera Type (Set to a Type, either Fire or TYPE_FIRE, also sets "shouldTerastal" to True)\nMoves are defined with a - (dash) followed by a single space, then the move name.\nEither "- Tackle" or "- MOVE_TACKLE" works. One move per line.\nMoves have to be the last lines of a Pokemon.\nIf no moves are specified, the Pokemon will use the last 4 moves it learns\nthrough levelup at its level.\n\nDefault IVs and Level can be changed in the "main" function of tools/trainerproc/main.c\n\nThis file is processed with a custom preprocessor.\n*/\n\n`;
    const parts = [];
    for (const t of trainers) {
        let block = `=== ${t.id} ===\n`;
        const fieldOrder = ['name', 'class', 'pic', 'gender', 'music', 'double_battle', 'ai', 'items', 'mugshot', 'starting_status'];
        const fieldLabels = {
            name: 'Name', class: 'Class', pic: 'Pic', gender: 'Gender',
            music: 'Music', double_battle: 'Double Battle', ai: 'AI',
            items: 'Items', mugshot: 'Mugshot', starting_status: 'Starting Status'
        };
        for (const key of fieldOrder) {
            if (t[key] !== undefined && t[key] !== '') {
                block += `${fieldLabels[key]}: ${t[key]}\n`;
            }
        }
        for (const mon of (t.pokemon || [])) {
            block += `\n${mon.species}\n`;
            const monFields = ['level', 'ability', 'nature', 'ivs', 'evs', 'ball', 'happiness', 'shiny', 'dynamax_level', 'gigantamax', 'tera_type'];
            const monLabels = {
                level: 'Level', ability: 'Ability', nature: 'Nature', ivs: 'IVs',
                evs: 'EVs', ball: 'Ball', happiness: 'Happiness', shiny: 'Shiny',
                dynamax_level: 'Dynamax Level', gigantamax: 'Gigantamax', tera_type: 'Tera Type'
            };
            for (const key of monFields) {
                if (mon[key] !== undefined && mon[key] !== '') {
                    block += `${monLabels[key]}: ${mon[key]}\n`;
                }
            }
            for (const move of (mon.moves || [])) {
                block += `- ${move}\n`;
            }
        }
        parts.push(block);
    }
    return headerComment + parts.join('\n');
}

function parseMoves(text) {
    const moves = [];
    const regex = /\[(MOVE_\w+)\]\s*=\s*\{([\s\S]*?)\n    \}/g;
    let match;
    while ((match = regex.exec(text)) !== null) {
        const id = match[1];
        const body = match[2];
        const move = { id };
        const nameMatch = body.match(/\.name\s*=\s*COMPOUND_STRING\("([^"]+)"\)/);
        const descMatch = body.match(/\.description\s*=\s*(?:COMPOUND_STRING\("([^"]+)"\)|(\w+))/);
        const powerMatch = body.match(/\.power\s*=\s*(\w+)/);
        const typeMatch = body.match(/\.type\s*=\s*(\w+)/);
        const accMatch = body.match(/\.accuracy\s*=\s*(\w+)/);
        const ppMatch = body.match(/\.pp\s*=\s*(\w+)/);
        const catMatch = body.match(/\.category\s*=\s*(\w+)/);
        const prioMatch = body.match(/\.priority\s*=\s*(-?\d+)/);
        const effectMatch = body.match(/\.effect\s*=\s*(\w+)/);
        const targetMatch = body.match(/\.target\s*=\s*(\w+)/);
        if (nameMatch) move.name = nameMatch[1];
        if (descMatch) move.description = descMatch[1] || descMatch[2];
        if (powerMatch) move.power = powerMatch[1];
        if (typeMatch) move.type = typeMatch[1].replace('TYPE_', '');
        if (accMatch) move.accuracy = accMatch[1];
        if (ppMatch) move.pp = ppMatch[1];
        if (catMatch) move.category = catMatch[1].replace('DAMAGE_CATEGORY_', '');
        if (prioMatch) move.priority = parseInt(prioMatch[1]);
        if (effectMatch) move.effect = effectMatch[1];
        if (targetMatch) move.target = targetMatch[1];
        moves.push(move);
    }
    return moves;
}

function updateMoveInFile(move) {
    const filePath = 'src/data/moves_info.h';
    let fileContent = pendingChanges[filePath] || originalContent[filePath];
    if (!fileContent) { toast('Move data not loaded yet', true); return; }

    const entryRegex = new RegExp(`(\\[${move.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.power\\s*=\\s*)\\w+`, 'm');
    const accRegex = new RegExp(`(\\[${move.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.accuracy\\s*=\\s*)\\w+`, 'm');
    const ppRegex = new RegExp(`(\\[${move.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.pp\\s*=\\s*)\\w+`, 'm');
    const typeRegex = new RegExp(`(\\[${move.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.type\\s*=\\s*)\\w+`, 'm');
    const catRegex = new RegExp(`(\\[${move.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.category\\s*=\\s*)\\w+`, 'm');
    const prioRegex = new RegExp(`(\\[${move.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.priority\\s*=\\s*)-?\\d+`, 'm');

    fileContent = fileContent.replace(entryRegex, `$1${move.power}`);
    fileContent = fileContent.replace(accRegex, `$1${move.accuracy}`);
    fileContent = fileContent.replace(ppRegex, `$1${move.pp}`);
    fileContent = fileContent.replace(typeRegex, `$1TYPE_${move.type}`);
    fileContent = fileContent.replace(catRegex, `$1DAMAGE_CATEGORY_${move.category}`);
    fileContent = fileContent.replace(prioRegex, `$1${move.priority}`);

    markChanged(filePath, fileContent);
}

function parseItems(text) {
    const items = [];
    const regex = /\[(ITEM_\w+)\]\s*=\s*\{([\s\S]*?)\n    \}/g;
    let match;
    while ((match = regex.exec(text)) !== null) {
        const id = match[1];
        const body = match[2];
        const item = { id };
        const nameMatch = body.match(/\.name\s*=\s*(?:ITEM_NAME\("([^"]+)"\)|_\("([^"]+)"\)|(\w+))/);
        const priceMatch = body.match(/\.price\s*=\s*(\w+)/);
        const pocketMatch = body.match(/\.pocket\s*=\s*(\w+)/);
        const importMatch = body.match(/\.importance\s*=\s*(\d+)/);
        if (nameMatch) item.name = nameMatch[1] || nameMatch[2] || nameMatch[3];
        if (priceMatch) item.price = priceMatch[1];
        if (pocketMatch) item.pocket = pocketMatch[1].replace('POCKET_', '');
        if (importMatch) item.importance = parseInt(importMatch[1]);
        items.push(item);
    }
    return items;
}

function updateItemInFile(item) {
    const filePath = 'src/data/items.h';
    let fileContent = pendingChanges[filePath] || originalContent[filePath];
    if (!fileContent) { toast('Item data not loaded yet', true); return; }

    const priceRegex = new RegExp(`(\\[${item.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.price\\s*=\\s*)\\w+`, 'm');
    const pocketRegex = new RegExp(`(\\[${item.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.pocket\\s*=\\s*)\\w+`, 'm');

    fileContent = fileContent.replace(priceRegex, `$1${item.price}`);
    fileContent = fileContent.replace(pocketRegex, `$1POCKET_${item.pocket}`);

    markChanged(filePath, fileContent);
}

function parseAbilities(text) {
    const abilities = [];
    const regex = /\[(\w+)\]\s*=\s*\{([^}]+)\}/g;
    let match;
    while ((match = regex.exec(text)) !== null) {
        const id = match[1];
        const body = match[2];
        const ability = { id };
        const nameMatch = body.match(/\.name\s*=\s*_\("([^"]+)"\)/);
        const descMatch = body.match(/\.description\s*=\s*COMPOUND_STRING\("([^"]+)"\)/);
        const ratingMatch = body.match(/\.aiRating\s*=\s*(\d+)/);
        if (nameMatch) ability.name = nameMatch[1];
        if (descMatch) ability.description = descMatch[1];
        if (ratingMatch) ability.aiRating = parseInt(ratingMatch[1]);
        ability.breakable = /\.breakable\s*=\s*TRUE/.test(body);
        ability.cantBeSwapped = /\.cantBeSwapped\s*=\s*TRUE/.test(body);
        ability.cantBeTraced = /\.cantBeTraced\s*=\s*TRUE/.test(body);
        abilities.push(ability);
    }
    return abilities;
}

function updateAbilityInFile(ability) {
    const filePath = 'src/data/abilities.h';
    let fileContent = pendingChanges[filePath] || originalContent[filePath];
    if (!fileContent) { toast('Ability data not loaded yet', true); return; }

    const ratingRegex = new RegExp(`(\\[${ability.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.aiRating\\s*=\\s*)\\d+`, 'm');
    const descRegex = new RegExp(`(\\[${ability.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.description\\s*=\\s*COMPOUND_STRING\\(")([^"]+)`, 'm');

    fileContent = fileContent.replace(ratingRegex, `$1${ability.aiRating}`);
    fileContent = fileContent.replace(descRegex, `$1${ability.description}`);

    // Handle boolean flags
    const boolFlags = ['breakable', 'cantBeSwapped', 'cantBeTraced'];
    for (const flag of boolFlags) {
        const flagRegex = new RegExp(`(\\[${ability.id}\\]\\s*=\\s*\\{[\\s\\S]*?\\.${flag}\\s*=\\s*)(TRUE|FALSE)`, 'm');
        const value = ability[flag] ? 'TRUE' : 'FALSE';
        if (flagRegex.test(fileContent)) {
            fileContent = fileContent.replace(flagRegex, `$1${value}`);
        }
    }

    markChanged(filePath, fileContent);
}

function parseConfig(text, filename) {
    const settings = [];
    const lines = text.split('\n');
    for (const line of lines) {
        const match = line.match(/^#define\s+(\w+)\s+(.+?)(?:\s*\/\/\s*(.*))?$/);
        if (match && !match[1].startsWith('GUARD_') && !match[1].startsWith('_')) {
            settings.push({
                name: match[1],
                value: match[2].trim(),
                comment: match[3] || '',
                file: filename
            });
        }
    }
    return settings;
}

// ─── Data Loading via GitHub API ────────────────────────────────────────────
async function loadTrainers() {
    if (!state.trainers) {
        const text = await fetchFile('src/data/trainers.party');
        state.trainers = parseTrainers(text);
    }
    return state.trainers;
}

async function loadEncounters() {
    if (!state.encounters) {
        state.encounters = await fetchJSON('src/data/wild_encounters.json');
    }
    return state.encounters;
}

async function loadMoves() {
    if (!state.moves) {
        const text = await fetchFile('src/data/moves_info.h');
        state.moves = parseMoves(text);
    }
    return state.moves;
}

async function loadItems() {
    if (!state.items) {
        const text = await fetchFile('src/data/items.h');
        state.items = parseItems(text);
    }
    return state.items;
}

async function loadAbilities() {
    if (!state.abilities) {
        const text = await fetchFile('src/data/abilities.h');
        state.abilities = parseAbilities(text);
    }
    return state.abilities;
}

// Cache for map script files
const scriptCache = {};

async function loadMapScript(dirName) {
    if (scriptCache[dirName]) return scriptCache[dirName];
    try {
        const path = `data/maps/${dirName}/scripts.inc`;
        // Check if we have a pending change for this file
        if (pendingChanges[path]) {
            scriptCache[dirName] = pendingChanges[path];
            return scriptCache[dirName];
        }
        const text = await fetchFile(path);
        scriptCache[dirName] = text;
        return text;
    } catch {
        scriptCache[dirName] = '';
        return '';
    }
}

// Detect script-based trainers (gym leaders, elite 4 members) that use TRAINER_TYPE_NONE
// but have trainerbattle commands in their scripts
function getScriptTrainers(map, scriptText) {
    if (!scriptText) return [];
    const npcEvents = (map.object_events || []).filter(e => {
        if (!e.script) return false;
        if (e.trainer_type && e.trainer_type !== 'TRAINER_TYPE_NONE') return false;
        if ((e.graphics_id || '').includes('ITEM_BALL')) return false;
        return true;
    });
    return npcEvents.filter(evt => {
        // Check if this NPC's script label contains a trainerbattle command
        const scriptLabel = evt.script + '::';
        const labelIdx = scriptText.indexOf(scriptLabel);
        if (labelIdx < 0) return false;
        // Find the next label or end of file to scope the search
        const afterLabel = scriptText.substring(labelIdx + scriptLabel.length);
        const nextLabelMatch = afterLabel.match(/\n\S+::/);
        const block = nextLabelMatch ? afterLabel.substring(0, nextLabelMatch.index) : afterLabel;
        // Check for trainerbattle commands or goto to scripts that have them
        if (/trainerbattle/.test(block)) return true;
        // Check for goto references that lead to trainerbattle scripts
        const gotoMatch = block.match(/goto\s+(\S+)/g);
        if (gotoMatch) {
            for (const g of gotoMatch) {
                const target = g.replace('goto ', '').trim();
                const targetLabel = target + '::';
                const targetIdx = scriptText.indexOf(targetLabel);
                if (targetIdx >= 0) {
                    const afterTarget = scriptText.substring(targetIdx);
                    const nextTarget = afterTarget.substring(targetLabel.length).match(/\n\S+::/);
                    const targetBlock = nextTarget ? afterTarget.substring(0, targetLabel.length + nextTarget.index) : afterTarget;
                    if (/trainerbattle/.test(targetBlock)) return true;
                }
            }
        }
        return false;
    });
}

// Parse dialogue text blocks from a script file for a given NPC script name
function parseDialogueBlocks(scriptText, dirName) {
    const blocks = [];
    if (!scriptText) return blocks;
    // Match text labels and their .string contents
    const regex = /^(\w+_Text_\w+)::\n((?:\s+\.string\s+"[^"]*"\n?)+)/gm;
    let match;
    while ((match = regex.exec(scriptText)) !== null) {
        const label = match[1];
        const rawStrings = match[2];
        // Extract individual .string values and join them
        const strings = [];
        const strRegex = /\.string\s+"([^"]*)"/g;
        let sm;
        while ((sm = strRegex.exec(rawStrings)) !== null) {
            strings.push(sm[1]);
        }
        blocks.push({ label, strings, text: strings.join('\n'), raw: match[0] });
    }
    return blocks;
}

// Also match single-colon text labels (some scripts use single colon)
function parseDialogueBlocksAll(scriptText, dirName) {
    const blocks = [];
    if (!scriptText) return blocks;
    const regex = /^(\w+_Text_\w+)::?\n((?:\s+\.string\s+"[^"]*"\n?)+)/gm;
    let match;
    while ((match = regex.exec(scriptText)) !== null) {
        const label = match[1];
        const rawStrings = match[2];
        const strings = [];
        const strRegex = /\.string\s+"([^"]*)"/g;
        let sm;
        while ((sm = strRegex.exec(rawStrings)) !== null) {
            strings.push(sm[1]);
        }
        blocks.push({ label, strings, text: strings.join('\n'), raw: match[0] });
    }
    return blocks;
}

async function loadConfig() {
    if (!state.config) {
        // List config files
        const listing = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/include/config?ref=${BRANCH}`);
        const hFiles = listing.filter(f => f.name.endsWith('.h'));
        const allSettings = [];
        for (const file of hFiles) {
            const text = await fetchFile(`include/config/${file.name}`);
            allSettings.push(...parseConfig(text, file.name));
        }
        state.config = allSettings;
    }
    return state.config;
}

async function loadMaps() {
    if (!state.maps) {
        const listing = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/data/maps?ref=${BRANCH}`);
        const dirs = listing.filter(f => f.type === 'dir');
        const maps = [];
        // Load map.json for each map directory (batch in groups of 10 for perf)
        for (let i = 0; i < dirs.length; i += 10) {
            const batch = dirs.slice(i, i + 10);
            const results = await Promise.all(batch.map(async d => {
                try {
                    const text = await fetchFile(`data/maps/${d.name}/map.json`);
                    const data = JSON.parse(text);
                    data._dirName = d.name;
                    return data;
                } catch { return null; }
            }));
            maps.push(...results.filter(Boolean));
        }
        state.maps = maps;
    }
    return state.maps;
}

// ─── Mobile Sidebar Toggle ──────────────────────────────────────────────────
function closeSidebar() {
    const sidebar = $('#sidebar');
    const overlay = $('#sidebar-overlay');
    if (sidebar) sidebar.classList.remove('open');
    if (overlay) overlay.classList.remove('active');
}
function openSidebar() {
    const sidebar = $('#sidebar');
    const overlay = $('#sidebar-overlay');
    if (sidebar) sidebar.classList.add('open');
    if (overlay) overlay.classList.add('active');
}
$('#menu-toggle')?.addEventListener('click', () => {
    const sidebar = $('#sidebar');
    if (sidebar?.classList.contains('open')) closeSidebar();
    else openSidebar();
});
$('#sidebar-overlay')?.addEventListener('click', closeSidebar);

// ─── Navigation ─────────────────────────────────────────────────────────────
$$('.nav-item').forEach(item => {
    item.addEventListener('click', () => {
        $$('.nav-item').forEach(n => n.classList.remove('active'));
        item.classList.add('active');
        state.page = item.dataset.page;
        state.search = '';
        state.mapDetail = null;
        closeSidebar();
        render();
    });
});

function navigateTo(page) {
    $$('.nav-item').forEach(n => {
        n.classList.toggle('active', n.dataset.page === page);
    });
    state.page = page;
    state.search = '';
    state.mapDetail = null;
    render();
}

// ─── Toast ──────────────────────────────────────────────────────────────────
function toast(msg, isError = false) {
    const el = document.createElement('div');
    el.className = 'toast' + (isError ? ' error' : '');
    el.textContent = msg;
    document.body.appendChild(el);
    setTimeout(() => el.remove(), 3000);
}

// ─── Render ─────────────────────────────────────────────────────────────────
async function render() {
    const page = state.page;
    content.innerHTML = '<div class="loading-center"><div class="spinner"></div> Loading...</div>';
    try {
        switch (page) {
            case 'maps': await renderMaps(); break;
            case 'npcs': await renderNPCs(); break;
            case 'pokemon': await renderPokemonPage(); break;
            case 'dashboard': await renderDashboard(); break;
            case 'moves': await renderMoves(); break;
            case 'abilities': await renderAbilities(); break;
            case 'config': await renderConfig(); break;
            case 'starters': await renderStarters(); break;
            case 'music': await renderMusic(); break;
        }
    } catch (e) {
        content.innerHTML = `<div class="loading-center" style="color:var(--red)">Error loading data: ${escHtml(e.message)}</div>`;
    }
}

// ─── Dashboard ──────────────────────────────────────────────────────────────
async function renderDashboard() {
    const trainers = await loadTrainers();
    const encounters = await loadEncounters();
    const encCount = encounters.wild_encounter_groups?.[0]?.encounters?.length || 0;

    content.innerHTML = `
        <div class="page-header"><h1>Dashboard</h1></div>
        <div style="background:var(--bg-card);border:1px solid var(--border);border-radius:var(--radius);padding:16px 20px;margin-bottom:24px;font-size:13px;color:var(--text-dim)">
            <strong style="color:var(--accent)">Welcome!</strong> This is the web editor for Pokemon Brazilianite.
            Browse areas to edit trainers, wild encounters, and items. Use <strong>"Submit PR"</strong> to send your changes for review.
            ${!ghToken ? '<br><span style="color:var(--yellow)">Sign in with GitHub (top right) to enable PR submission.</span>' : ''}
        </div>
        <div class="stat-grid">
            <div class="stat-card">
                <div class="label">Trainers</div>
                <div class="value">${trainers.length}</div>
                <div class="sub">Defined in trainers.party</div>
            </div>
            <div class="stat-card">
                <div class="label">Wild Encounter Maps</div>
                <div class="value">${encCount}</div>
                <div class="sub">Routes with wild Pokemon</div>
            </div>
            ${getChangeCount() > 0 ? `
            <div class="stat-card" style="border-color:var(--orange)">
                <div class="label" style="color:var(--orange)">Pending Changes</div>
                <div class="value" style="color:var(--orange)">${getChangeCount()}</div>
                <div class="sub">${Object.keys(pendingChanges).join(', ')}</div>
            </div>
            ` : ''}
        </div>
        <div class="page-header"><h1>Quick Access</h1></div>
        <div class="stat-grid">
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('maps')">
                <div class="label">&#9873; Areas</div>
                <div class="sub" style="margin-top:8px">Browse areas to edit trainers, wild encounters, items, and map properties</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('moves')">
                <div class="label">&#10038; Moves</div>
                <div class="sub" style="margin-top:8px">Edit move stats: type, power, accuracy, PP, and more</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('abilities')">
                <div class="label">&#10024; Abilities</div>
                <div class="sub" style="margin-top:8px">Edit ability descriptions, AI ratings, and flags</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('config')">
                <div class="label">&#9881; Config</div>
                <div class="sub" style="margin-top:8px">View and edit game config settings</div>
            </div>
        </div>
    `;
}

// ─── Trainers ───────────────────────────────────────────────────────────────
async function renderTrainers() {
    const trainers = await loadTrainers();
    const search = state.search.toLowerCase();
    const filtered = trainers.filter(t =>
        !search ||
        t.id.toLowerCase().includes(search) ||
        (t.name || '').toLowerCase().includes(search) ||
        (t.class || '').toLowerCase().includes(search) ||
        t.pokemon.some(p => p.species.toLowerCase().includes(search))
    );

    content.innerHTML = `
        <div class="page-header">
            <h1>Trainers <span style="color:var(--text-dim);font-size:14px">(${filtered.length}/${trainers.length})</span></h1>
            <div class="page-header-actions">
                <button class="btn btn-primary" onclick="addTrainer()">+ Add Trainer</button>
            </div>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search trainers by name, class, or Pokemon..." id="trainer-search" value="${state.search}">
        </div>
        <div class="card-grid" id="trainer-grid"></div>
    `;

    const grid = $('#trainer-grid');
    for (const t of filtered.slice(0, 100)) {
        grid.innerHTML += `
            <div class="trainer-card">
                <div class="trainer-card-header">
                    ${getTrainerPicHtml(t.pic, 48)}
                    <div>
                        <h3>${escHtml(t.name || '(unnamed)')}</h3>
                        <div class="trainer-id">${escHtml(t.id)}</div>
                    </div>
                </div>
                <div class="trainer-meta">
                    <span>Class: ${escHtml(t.class || '-')}</span>
                    <span>AI: ${escHtml(t.ai || 'None')}</span>
                    ${t.double_battle === 'Yes' ? '<span style="color:var(--yellow)">Double</span>' : ''}
                </div>
                <div class="trainer-pokemon">
                    ${t.pokemon.length === 0 ? '<div style="color:var(--text-dim);font-size:12px">No Pokemon</div>' :
                        t.pokemon.map(p => `
                            <div class="trainer-pokemon-item">
                                <span class="species">${escHtml(p.species.split('(')[0].trim())}</span>
                                <span class="level">Lv.${p.level || '100'}</span>
                            </div>
                        `).join('')}
                </div>
                <div class="trainer-card-actions">
                    <button class="btn btn-sm" onclick="editTrainer('${escAttr(t.id)}')">Edit</button>
                    <button class="btn btn-sm btn-danger" onclick="deleteTrainer('${escAttr(t.id)}')">Delete</button>
                </div>
            </div>
        `;
    }
    if (filtered.length > 100) {
        grid.innerHTML += `<div style="padding:20px;color:var(--text-dim);font-size:13px">Showing 100 of ${filtered.length} trainers. Use search to narrow down.</div>`;
    }

    $('#trainer-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        await renderTrainers();
        const el = $('#trainer-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

function addTrainer() {
    openTrainerModal({
        id: 'TRAINER_NEW_' + Date.now(), name: '', class: '', pic: '', gender: 'Male',
        music: '', double_battle: 'No', ai: '', pokemon: []
    }, true);
}

function editTrainer(id) {
    const trainer = state.trainers.find(t => t.id === id);
    if (trainer) openTrainerModal({ ...trainer, pokemon: trainer.pokemon.map(p => ({ ...p, moves: [...(p.moves || [])] })) }, false);
}

function deleteTrainer(id) {
    if (!confirm(`Delete trainer ${id}?`)) return;
    state.trainers = state.trainers.filter(t => t.id !== id);
    markChanged('src/data/trainers.party', serializeTrainers(state.trainers));
    toast('Trainer deleted (auto-saved)');
    renderTrainers();
}

function openTrainerModal(trainer, isNew) {
    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>${isNew ? 'Add Trainer' : 'Edit Trainer'}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body" id="trainer-modal-body"></div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-trainer-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    function renderModalBody() {
        const body = $('#trainer-modal-body');
        body.innerHTML = `
            <div style="display:flex;align-items:center;gap:12px;margin-bottom:16px;padding:12px;background:var(--bg);border-radius:6px;border:1px solid var(--border)">
                ${getTrainerPicHtml(trainer.pic, 64)}
                <div>
                    <div style="font-size:14px;font-weight:600">${escHtml(trainer.name || '(unnamed)')}</div>
                    <div style="font-size:12px;color:var(--text-dim)">${escHtml(trainer.pic || 'No pic set')}</div>
                </div>
            </div>
            <div class="form-row">
                <div class="form-group">
                    <label>Trainer ID</label>
                    <input type="text" id="t-id" value="${escAttr(trainer.id)}" ${isNew ? '' : 'readonly style="opacity:0.6"'}>
                </div>
                <div class="form-group">
                    <label>Name</label>
                    <input type="text" id="t-name" value="${escAttr(trainer.name || '')}">
                </div>
            </div>
            <div class="form-row">
                <div class="form-group">
                    <label>Class</label>
                    ${makeDatalistHtml('t-class', trainer.class || '', getUniqueTrainerClasses())}
                </div>
                <div class="form-group">
                    <label>Pic</label>
                    ${makeDatalistHtml('t-pic', trainer.pic || '', getUniqueTrainerPics())}
                </div>
            </div>
            <div class="form-row">
                <div class="form-group">
                    <label>Gender</label>
                    <select id="t-gender">
                        <option ${trainer.gender === 'Male' ? 'selected' : ''}>Male</option>
                        <option ${trainer.gender === 'Female' ? 'selected' : ''}>Female</option>
                    </select>
                </div>
                <div class="form-group">
                    <label>Music</label>
                    ${makeDatalistHtml('t-music', trainer.music || '', getUniqueTrainerMusic())}
                </div>
            </div>
            <div class="form-row">
                <div class="form-group">
                    <label>Double Battle</label>
                    <select id="t-double">
                        <option ${trainer.double_battle !== 'Yes' ? 'selected' : ''}>No</option>
                        <option ${trainer.double_battle === 'Yes' ? 'selected' : ''}>Yes</option>
                    </select>
                </div>
                <div class="form-group">
                    <label>AI Flags</label>
                    ${makeDatalistHtml('t-ai', trainer.ai || '', AI_PRESETS, 'placeholder="e.g. Check Bad Move / Try To Faint"')}
                </div>
            </div>
            <div class="form-row">
                <div class="form-group">
                    <label>Items</label>
                    <input type="text" id="t-items" value="${escAttr(trainer.items || '')}" placeholder="e.g. Full Restore / Hyper Potion">
                </div>
                <div class="form-group">
                    <label>Mugshot</label>
                    ${makeSelectHtml('t-mugshot', trainer.mugshot || '', MUGSHOT_OPTIONS)}
                </div>
            </div>
            <div class="form-row">
                <div class="form-group">
                    <label>Starting Status</label>
                    ${makeSelectHtml('t-starting-status', trainer.starting_status || '', STARTING_STATUS_OPTIONS)}
                </div>
            </div>
            <h3 style="margin:16px 0 10px;font-size:14px">Pokemon (${trainer.pokemon.length})</h3>
            <div id="pokemon-list"></div>
            <button class="btn" onclick="addPokemonToModal()" style="margin-top:8px">+ Add Pokemon</button>
        `;

        const pokemonList = $('#pokemon-list');
        trainer.pokemon.forEach((mon, i) => {
            pokemonList.innerHTML += `
                <div class="pokemon-form-card">
                    <button class="remove-mon" onclick="removePokemonFromModal(${i})">&#10005;</button>
                    <h4>Pokemon #${i + 1}</h4>
                    <div class="form-group">
                        <label>Species Line</label>
                        <input type="text" class="mon-species" data-idx="${i}" value="${escAttr(mon.species)}" placeholder="e.g. Pikachu (M) @ Light Ball">
                    </div>
                    <div class="form-row">
                        <div class="form-group">
                            <label>Level</label>
                            <input type="number" class="mon-level" data-idx="${i}" value="${escAttr(mon.level || '')}" min="1" max="100" placeholder="1-100">
                        </div>
                        <div class="form-group">
                            <label>Nature</label>
                            <select class="mon-nature" data-idx="${i}">
                                <option value="">Default (Hardy)</option>
                                ${NATURES.map(n => `<option value="${n}" ${mon.nature === n ? 'selected' : ''}>${n}</option>`).join('')}
                            </select>
                        </div>
                        <div class="form-group">
                            <label>Ability</label>
                            <input type="text" class="mon-ability" data-idx="${i}" value="${escAttr(mon.ability || '')}">
                        </div>
                    </div>
                    <div class="form-row">
                        <div class="form-group">
                            <label>IVs</label>
                            <input type="text" class="mon-ivs" data-idx="${i}" value="${escAttr(mon.ivs || '')}" placeholder="31 HP / 31 Atk / ...">
                        </div>
                        <div class="form-group">
                            <label>EVs</label>
                            <input type="text" class="mon-evs" data-idx="${i}" value="${escAttr(mon.evs || '')}" placeholder="252 Atk / 252 Spe / ...">
                        </div>
                    </div>
                    <div class="form-row">
                        <div class="form-group">
                            <label>Ball</label>
                            <select class="mon-ball" data-idx="${i}">
                                <option value="">Default (Poke Ball)</option>
                                ${BALLS.map(b => `<option value="${b}" ${mon.ball === b ? 'selected' : ''}>${b}</option>`).join('')}
                            </select>
                        </div>
                        <div class="form-group">
                            <label>Shiny</label>
                            <select class="mon-shiny" data-idx="${i}">
                                <option value="">Default (No)</option>
                                <option value="Yes" ${mon.shiny === 'Yes' ? 'selected' : ''}>Yes</option>
                                <option value="No" ${mon.shiny === 'No' ? 'selected' : ''}>No</option>
                            </select>
                        </div>
                        <div class="form-group">
                            <label>Tera Type</label>
                            <select class="mon-tera" data-idx="${i}">
                                ${TERA_TYPES.map(t => `<option value="${t}" ${mon.tera_type === t ? 'selected' : ''}>${t || 'None'}</option>`).join('')}
                            </select>
                        </div>
                    </div>
                    <div class="form-group">
                        <label>Moves (one per line)</label>
                        <textarea class="mon-moves" data-idx="${i}" rows="4" placeholder="Thunderbolt\nVolt Switch\n...">${escHtml((mon.moves || []).join('\n'))}</textarea>
                    </div>
                </div>
            `;
        });
    }

    window.addPokemonToModal = () => {
        collectPokemonFromModal(trainer);
        trainer.pokemon.push({ species: '', level: '', moves: [] });
        renderModalBody();
    };

    window.removePokemonFromModal = (idx) => {
        collectPokemonFromModal(trainer);
        trainer.pokemon.splice(idx, 1);
        renderModalBody();
    };

    function collectPokemonFromModal(t) {
        const speciesEls = $$('.mon-species');
        t.pokemon = speciesEls.map((el, i) => ({
            species: el.value,
            level: $$('.mon-level')[i]?.value || '',
            nature: $$('.mon-nature')[i]?.value || '',
            ability: $$('.mon-ability')[i]?.value || '',
            ivs: $$('.mon-ivs')[i]?.value || '',
            evs: $$('.mon-evs')[i]?.value || '',
            ball: $$('.mon-ball')[i]?.value || '',
            shiny: $$('.mon-shiny')[i]?.value || '',
            tera_type: $$('.mon-tera')[i]?.value || '',
            happiness: $$('.mon-happiness')[i]?.value || '',
            dynamax_level: $$('.mon-dynamax')[i]?.value || '',
            gigantamax: $$('.mon-gigantamax')[i]?.value || '',
            moves: ($$('.mon-moves')[i]?.value || '').split('\n').map(m => m.trim()).filter(Boolean)
        }));
    }

    renderModalBody();

    $('#save-trainer-btn').addEventListener('click', () => {
        const updated = {
            id: $('#t-id').value.trim(),
            name: $('#t-name').value.trim(),
            class: $('#t-class').value.trim(),
            pic: $('#t-pic').value.trim(),
            gender: $('#t-gender').value,
            music: $('#t-music').value.trim(),
            double_battle: $('#t-double').value,
            ai: $('#t-ai').value.trim(),
            items: $('#t-items').value.trim(),
            mugshot: $('#t-mugshot').value.trim(),
            starting_status: $('#t-starting-status').value.trim(),
            pokemon: []
        };
        collectPokemonFromModal(updated);

        if (isNew) {
            state.trainers.push(updated);
        } else {
            const idx = state.trainers.findIndex(t => t.id === trainer.id);
            if (idx >= 0) state.trainers[idx] = updated;
        }

        markChanged('src/data/trainers.party', serializeTrainers(state.trainers));
        toast('Trainer saved (auto-saved)');
        overlay.remove();
        renderTrainers();
    });
}

// ─── Encounters ─────────────────────────────────────────────────────────────

// Game progression order starting from Littleroot Town.
// Areas are listed in the order the player first encounters them.
const AREA_PROGRESSION_ORDER = [
    // Hoenn: Littleroot -> Oldale
    'MAP_ROUTE101', 'MAP_ROUTE103', 'MAP_ROUTE102',
    'MAP_PETALBURG_CITY',
    // Petalburg -> Rustboro
    'MAP_ROUTE104', 'MAP_PETALBURG_WOODS',
    'MAP_ROUTE116', 'MAP_RUSTURF_TUNNEL', 'MAP_ROUTE115',
    // Dewford via Mr. Briney
    'MAP_ROUTE106', 'MAP_DEWFORD_TOWN',
    'MAP_GRANITE_CAVE_1F', 'MAP_GRANITE_CAVE_B1F', 'MAP_GRANITE_CAVE_B2F', 'MAP_GRANITE_CAVE_STEVENS_ROOM',
    // Slateport
    'MAP_ROUTE107', 'MAP_ROUTE108', 'MAP_ROUTE109', 'MAP_SLATEPORT_CITY',
    // Mauville
    'MAP_ROUTE110', 'MAP_NEW_MAUVILLE_ENTRANCE', 'MAP_NEW_MAUVILLE_INSIDE',
    'MAP_ROUTE117',
    // Route 111 / Desert
    'MAP_ROUTE111', 'MAP_MIRAGE_TOWER_1F', 'MAP_MIRAGE_TOWER_2F', 'MAP_MIRAGE_TOWER_3F', 'MAP_MIRAGE_TOWER_4F',
    // Lavaridge
    'MAP_ROUTE112', 'MAP_FIERY_PATH', 'MAP_JAGGED_PASS',
    // Fallarbor / Meteor Falls
    'MAP_ROUTE113', 'MAP_ROUTE114',
    'MAP_METEOR_FALLS_1F_1R', 'MAP_METEOR_FALLS_1F_2R', 'MAP_METEOR_FALLS_B1F_1R', 'MAP_METEOR_FALLS_B1F_2R', 'MAP_METEOR_FALLS_STEVENS_CAVE',
    // Fortree
    'MAP_ROUTE118', 'MAP_ROUTE119', 'MAP_ROUTE120', 'MAP_ROUTE121',
    // Mt. Pyre
    'MAP_ROUTE122',
    'MAP_MT_PYRE_1F', 'MAP_MT_PYRE_2F', 'MAP_MT_PYRE_3F', 'MAP_MT_PYRE_4F', 'MAP_MT_PYRE_5F', 'MAP_MT_PYRE_6F', 'MAP_MT_PYRE_EXTERIOR', 'MAP_MT_PYRE_SUMMIT',
    'MAP_ROUTE123',
    // Lilycove / Safari Zone
    'MAP_LILYCOVE_CITY',
    'MAP_SAFARI_ZONE_SOUTH', 'MAP_SAFARI_ZONE_SOUTHWEST', 'MAP_SAFARI_ZONE_NORTH', 'MAP_SAFARI_ZONE_NORTHWEST', 'MAP_SAFARI_ZONE_SOUTHEAST', 'MAP_SAFARI_ZONE_NORTHEAST',
    // Magma Hideout
    'MAP_MAGMA_HIDEOUT_1F', 'MAP_MAGMA_HIDEOUT_2F_1R', 'MAP_MAGMA_HIDEOUT_2F_2R', 'MAP_MAGMA_HIDEOUT_2F_3R',
    'MAP_MAGMA_HIDEOUT_3F_1R', 'MAP_MAGMA_HIDEOUT_3F_2R', 'MAP_MAGMA_HIDEOUT_3F_3R', 'MAP_MAGMA_HIDEOUT_4F',
    // Mossdeep / Shoal Cave
    'MAP_ROUTE124', 'MAP_UNDERWATER_ROUTE124', 'MAP_MOSSDEEP_CITY',
    'MAP_ROUTE125',
    'MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM', 'MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM', 'MAP_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM', 'MAP_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM', 'MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM',
    // Seafloor Cavern
    'MAP_ROUTE126', 'MAP_UNDERWATER_ROUTE126', 'MAP_ROUTE127', 'MAP_ROUTE128',
    'MAP_SEAFLOOR_CAVERN_ENTRANCE', 'MAP_SEAFLOOR_CAVERN_ROOM1', 'MAP_SEAFLOOR_CAVERN_ROOM2', 'MAP_SEAFLOOR_CAVERN_ROOM3', 'MAP_SEAFLOOR_CAVERN_ROOM4',
    'MAP_SEAFLOOR_CAVERN_ROOM5', 'MAP_SEAFLOOR_CAVERN_ROOM6', 'MAP_SEAFLOOR_CAVERN_ROOM7', 'MAP_SEAFLOOR_CAVERN_ROOM8',
    // Sootopolis / Cave of Origin
    'MAP_SOOTOPOLIS_CITY',
    'MAP_CAVE_OF_ORIGIN_ENTRANCE', 'MAP_CAVE_OF_ORIGIN_1F', 'MAP_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1', 'MAP_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2', 'MAP_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3',
    'MAP_ROUTE105',
    // Water routes / Pacifidlog / Sky Pillar
    'MAP_ROUTE129', 'MAP_ROUTE130', 'MAP_ROUTE131',
    'MAP_PACIFIDLOG_TOWN',
    'MAP_SKY_PILLAR_1F', 'MAP_SKY_PILLAR_3F', 'MAP_SKY_PILLAR_5F',
    'MAP_ROUTE132', 'MAP_ROUTE133', 'MAP_ROUTE134',
    // Abandoned Ship
    'MAP_ABANDONED_SHIP_ROOMS_B1F', 'MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS',
    // Victory Road
    'MAP_EVER_GRANDE_CITY', 'MAP_VICTORY_ROAD_1F', 'MAP_VICTORY_ROAD_B1F', 'MAP_VICTORY_ROAD_B2F',
    // Post-game Hoenn
    'MAP_DESERT_UNDERPASS', 'MAP_ARTISAN_CAVE_B1F', 'MAP_ARTISAN_CAVE_1F', 'MAP_ALTERING_CAVE',
    // === Kanto (FRLG) ===
    'MAP_PALLET_TOWN', 'MAP_ROUTE1', 'MAP_VIRIDIAN_CITY', 'MAP_ROUTE22',
    'MAP_VIRIDIAN_FOREST', 'MAP_ROUTE2',
    'MAP_ROUTE3', 'MAP_MT_MOON_1F', 'MAP_MT_MOON_B1F', 'MAP_MT_MOON_B2F',
    'MAP_ROUTE4', 'MAP_CERULEAN_CITY', 'MAP_ROUTE24', 'MAP_ROUTE25',
    'MAP_ROUTE5', 'MAP_ROUTE6', 'MAP_VERMILION_CITY', 'MAP_SSANNE_EXTERIOR',
    'MAP_ROUTE11', 'MAP_DIGLETTS_CAVE_B1F',
    'MAP_ROUTE9', 'MAP_ROUTE10', 'MAP_ROCK_TUNNEL_1F', 'MAP_ROCK_TUNNEL_B1F', 'MAP_POWER_PLANT',
    'MAP_ROUTE7', 'MAP_CELADON_CITY', 'MAP_ROUTE8',
    'MAP_POKEMON_TOWER_3F', 'MAP_POKEMON_TOWER_4F', 'MAP_POKEMON_TOWER_5F', 'MAP_POKEMON_TOWER_6F', 'MAP_POKEMON_TOWER_7F',
    'MAP_ROUTE12', 'MAP_ROUTE13', 'MAP_ROUTE14', 'MAP_ROUTE15',
    'MAP_FUCHSIA_CITY',
    'MAP_SAFARI_ZONE_CENTER', 'MAP_SAFARI_ZONE_EAST', 'MAP_SAFARI_ZONE_NORTH_FRLG', 'MAP_SAFARI_ZONE_WEST',
    'MAP_ROUTE16', 'MAP_ROUTE17', 'MAP_ROUTE18',
    'MAP_ROUTE19', 'MAP_ROUTE20',
    'MAP_SEAFOAM_ISLANDS_1F', 'MAP_SEAFOAM_ISLANDS_B1F', 'MAP_SEAFOAM_ISLANDS_B2F', 'MAP_SEAFOAM_ISLANDS_B3F', 'MAP_SEAFOAM_ISLANDS_B4F',
    'MAP_CINNABAR_ISLAND',
    'MAP_POKEMON_MANSION_1F', 'MAP_POKEMON_MANSION_2F', 'MAP_POKEMON_MANSION_3F', 'MAP_POKEMON_MANSION_B1F',
    'MAP_ROUTE21_NORTH', 'MAP_ROUTE21_SOUTH',
    'MAP_ROUTE23', 'MAP_VICTORY_ROAD_1F_FRLG', 'MAP_VICTORY_ROAD_2F', 'MAP_VICTORY_ROAD_3F',
    'MAP_CERULEAN_CAVE_1F', 'MAP_CERULEAN_CAVE_2F', 'MAP_CERULEAN_CAVE_B1F',
    // === Sevii Islands ===
    'MAP_ONE_ISLAND', 'MAP_ONE_ISLAND_KINDLE_ROAD', 'MAP_ONE_ISLAND_TREASURE_BEACH',
    'MAP_MT_EMBER_EXTERIOR', 'MAP_MT_EMBER_SUMMIT_PATH_1F', 'MAP_MT_EMBER_SUMMIT_PATH_2F', 'MAP_MT_EMBER_SUMMIT_PATH_3F',
    'MAP_MT_EMBER_RUBY_PATH_1F', 'MAP_MT_EMBER_RUBY_PATH_B1F', 'MAP_MT_EMBER_RUBY_PATH_B1F_STAIRS', 'MAP_MT_EMBER_RUBY_PATH_B2F', 'MAP_MT_EMBER_RUBY_PATH_B2F_STAIRS', 'MAP_MT_EMBER_RUBY_PATH_B3F',
    'MAP_TWO_ISLAND_CAPE_BRINK',
    'MAP_THREE_ISLAND_PORT', 'MAP_THREE_ISLAND_BOND_BRIDGE', 'MAP_THREE_ISLAND_BERRY_FOREST',
    'MAP_FOUR_ISLAND', 'MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE', 'MAP_FOUR_ISLAND_ICEFALL_CAVE_1F', 'MAP_FOUR_ISLAND_ICEFALL_CAVE_B1F', 'MAP_FOUR_ISLAND_ICEFALL_CAVE_BACK',
    'MAP_FIVE_ISLAND', 'MAP_FIVE_ISLAND_RESORT_GORGEOUS', 'MAP_FIVE_ISLAND_WATER_LABYRINTH', 'MAP_FIVE_ISLAND_MEADOW', 'MAP_FIVE_ISLAND_MEMORIAL_PILLAR',
    'MAP_FIVE_ISLAND_LOST_CAVE_ROOM1', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM2', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM3', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM4', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM5',
    'MAP_FIVE_ISLAND_LOST_CAVE_ROOM6', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM7', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM8', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM9', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM10',
    'MAP_FIVE_ISLAND_LOST_CAVE_ROOM11', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM12', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM13', 'MAP_FIVE_ISLAND_LOST_CAVE_ROOM14',
    'MAP_SIX_ISLAND_PATTERN_BUSH', 'MAP_SIX_ISLAND_OUTCAST_ISLAND', 'MAP_SIX_ISLAND_GREEN_PATH', 'MAP_SIX_ISLAND_WATER_PATH', 'MAP_SIX_ISLAND_RUIN_VALLEY', 'MAP_SIX_ISLAND_ALTERING_CAVE',
    'MAP_SEVEN_ISLAND_TRAINER_TOWER', 'MAP_SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE', 'MAP_SEVEN_ISLAND_SEVAULT_CANYON', 'MAP_SEVEN_ISLAND_TANOBY_RUINS',
    'MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER', 'MAP_SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER', 'MAP_SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER',
    'MAP_SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER', 'MAP_SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER', 'MAP_SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER', 'MAP_SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER',
];

// Build a lookup for encounter ordering; unknown maps sort to end.
const AREA_ORDER_MAP = {};
AREA_PROGRESSION_ORDER.forEach((name, i) => { AREA_ORDER_MAP[name] = i; });
function areaOrder(mapName) { return AREA_ORDER_MAP[mapName] ?? 99999; }

// Resolve SPECIES_XXX to a display name using loaded pokemon data, falling back to title-cased code.
function speciesDisplayName(speciesCode) {
    if (state.pokemon) {
        const mon = state.pokemon.find(p => p.id === speciesCode);
        if (mon?.name) return mon.name;
    }
    return speciesCode.replace('SPECIES_', '').replace(/_/g, ' ').replace(/\b\w/g, c => c.toUpperCase());
}

async function renderEncounters() {
    const data = await loadEncounters();
    const encounters = data.wild_encounter_groups?.[0]?.encounters || [];
    const encounterRates = data.wild_encounter_groups?.[0]?.fields || [];

    // Pre-load pokemon names for display (non-blocking: falls back to code if not ready)
    loadPokemonSpecies().catch(() => {});

    const search = state.search.toLowerCase();
    const filtered = encounters.filter(e =>
        !search ||
        e.map.toLowerCase().includes(search) ||
        Object.values(e).some(v => {
            if (v && typeof v === 'object' && v.mons) {
                return v.mons.some(m => m.species.toLowerCase().includes(search));
            }
            return false;
        })
    );

    // Sort by game progression order
    const sorted = [...filtered].sort((a, b) => areaOrder(a.map) - areaOrder(b.map));

    content.innerHTML = `
        <div class="page-header">
            <h1>Wild Encounters <span style="color:var(--text-dim);font-size:14px">(${sorted.length}/${encounters.length})</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search by map name or species..." id="enc-search" value="${state.search}">
        </div>
        <div class="card-grid" id="enc-grid"></div>
    `;

    const grid = $('#enc-grid');
    const fieldTypes = ['land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'];
    const fieldLabels = { land_mons: 'Grass/Land', water_mons: 'Surfing', rock_smash_mons: 'Rock Smash', fishing_mons: 'Fishing' };

    for (const enc of sorted.slice(0, 60)) {
        let sections = '';
        for (const type of fieldTypes) {
            if (!enc[type]) continue;
            const rateField = encounterRates.find(f => f.type === type);
            const rates = rateField?.encounter_rates || [];
            sections += `
                <div class="encounter-section">
                    <h4>${fieldLabels[type]} (Rate: ${enc[type].encounter_rate}%)</h4>
                    ${enc[type].mons.map((m, i) => `
                        <div class="encounter-row">
                            <span>${speciesDisplayName(m.species)}</span>
                            <span>Lv ${m.min_level}-${m.max_level}</span>
                            <span class="rate">${rates[i] || '?'}%</span>
                        </div>
                    `).join('')}
                </div>
            `;
        }
        grid.innerHTML += `
            <div class="encounter-card">
                <div class="encounter-card-header">
                    <h3>${enc.map.replace('MAP_', '').replace(/_/g, ' ')}</h3>
                    <span style="font-size:11px;color:var(--text-dim);font-family:monospace">${enc.map}</span>
                </div>
                ${sections || '<div class="encounter-section" style="color:var(--text-dim)">No encounters defined</div>'}
                <div style="margin-top:8px;text-align:right">
                    <button class="btn btn-sm" onclick="editEncounter('${escAttr(enc.map)}')">Edit</button>
                </div>
            </div>
        `;
    }

    $('#enc-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        await renderEncounters();
        const el = $('#enc-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

function editEncounter(mapName) {
    const data = state.encounters;
    const encounters = data.wild_encounter_groups?.[0]?.encounters || [];
    const enc = encounters.find(e => e.map === mapName);
    if (!enc) return;

    const fieldTypes = ['land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'];
    const fieldLabels = { land_mons: 'Grass/Land', water_mons: 'Surfing', rock_smash_mons: 'Rock Smash', fishing_mons: 'Fishing' };

    let sectionsHtml = '';
    for (const type of fieldTypes) {
        if (!enc[type]) continue;
        sectionsHtml += `
            <div style="margin-bottom:16px">
                <h3 style="font-size:14px;margin-bottom:8px">${fieldLabels[type]}
                    <span style="font-weight:normal;font-size:12px;color:var(--text-dim)">Encounter Rate:</span>
                    <input type="number" class="enc-rate" data-type="${type}" value="${enc[type].encounter_rate}" min="0" max="100" style="width:60px">%
                </h3>
                <div class="table-container" style="margin:0">
                    <table>
                        <thead><tr><th>Species</th><th>Min Lv</th><th>Max Lv</th></tr></thead>
                        <tbody>
                            ${enc[type].mons.map((m, i) => `
                                <tr>
                                    <td><input type="text" class="enc-species" data-type="${type}" data-idx="${i}" value="${escAttr(m.species)}" list="dl-enc-species" style="width:180px;font-family:monospace;font-size:12px"></td>
                                    <td><input type="number" class="enc-min-lv" data-type="${type}" data-idx="${i}" value="${m.min_level}" min="1" max="100" style="width:60px"></td>
                                    <td><input type="number" class="enc-max-lv" data-type="${type}" data-idx="${i}" value="${m.max_level}" min="1" max="100" style="width:60px"></td>
                                </tr>
                            `).join('')}
                        </tbody>
                    </table>
                </div>
            </div>
        `;
    }

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="max-width:700px">
            <div class="modal-header">
                <h2>Edit Encounters: ${mapName.replace('MAP_', '').replace(/_/g, ' ')}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body" style="max-height:70vh;overflow-y:auto">
                ${sectionsHtml || '<p style="color:var(--text-dim)">No encounter types defined for this map.</p>'}
                <datalist id="dl-enc-species">${getUniqueSpeciesIds().map(s => `<option value="${escAttr(s)}">`).join('')}</datalist>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-enc-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-enc-btn').addEventListener('click', () => {
        for (const type of fieldTypes) {
            if (!enc[type]) continue;
            const rateEl = overlay.querySelector(`.enc-rate[data-type="${type}"]`);
            if (rateEl) enc[type].encounter_rate = parseInt(rateEl.value);
            enc[type].mons.forEach((m, i) => {
                const sp = overlay.querySelector(`.enc-species[data-type="${type}"][data-idx="${i}"]`);
                const minLv = overlay.querySelector(`.enc-min-lv[data-type="${type}"][data-idx="${i}"]`);
                const maxLv = overlay.querySelector(`.enc-max-lv[data-type="${type}"][data-idx="${i}"]`);
                if (sp) m.species = sp.value;
                if (minLv) m.min_level = parseInt(minLv.value);
                if (maxLv) m.max_level = parseInt(maxLv.value);
            });
        }
        markChanged('src/data/wild_encounters.json', JSON.stringify(data, null, 2));
        toast(`Encounters for ${mapName} updated (auto-saved)`);
        overlay.remove();
        renderEncounters();
    });
}

// ─── Moves ──────────────────────────────────────────────────────────────────
async function renderMoves() {
    const moves = await loadMoves();
    const search = state.search.toLowerCase();
    const filtered = moves.filter(m =>
        m.name && m.id !== 'MOVE_NONE' && (
            !search ||
            m.name.toLowerCase().includes(search) ||
            m.id.toLowerCase().includes(search) ||
            (m.type || '').toLowerCase().includes(search)
        )
    );

    content.innerHTML = `
        <div class="page-header">
            <h1>Moves <span style="color:var(--text-dim);font-size:14px">(${filtered.length})</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search moves by name or type..." id="move-search" value="${state.search}">
        </div>
        <div class="table-container">
            <table>
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Type</th>
                        <th>Category</th>
                        <th>Power</th>
                        <th>Accuracy</th>
                        <th>PP</th>
                        <th>Priority</th>
                        <th></th>
                    </tr>
                </thead>
                <tbody id="moves-tbody"></tbody>
            </table>
        </div>
        <div class="pagination" id="moves-pagination"></div>
    `;

    renderMovesPage(filtered, 0);
    $('#move-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        await renderMoves();
        const el = $('#move-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

function renderMovesPage(moves, page) {
    const perPage = 50;
    const start = page * perPage;
    const pageItems = moves.slice(start, start + perPage);
    const totalPages = Math.ceil(moves.length / perPage);

    const tbody = $('#moves-tbody');
    tbody.innerHTML = pageItems.map(m => `
        <tr>
            <td><strong>${escHtml(m.name || '-')}</strong><br><span style="font-size:11px;color:var(--text-dim);font-family:monospace">${m.id}</span></td>
            <td><span class="type-badge type-${m.type || 'NORMAL'}">${m.type || '-'}</span></td>
            <td><span class="type-badge cat-${m.category || 'STATUS'}">${m.category || '-'}</span></td>
            <td>${m.power === '0' || !m.power ? '-' : m.power}</td>
            <td>${m.accuracy === '0' || !m.accuracy ? '-' : m.accuracy}</td>
            <td>${m.pp || '-'}</td>
            <td>${m.priority || '0'}</td>
            <td><button class="btn btn-sm" onclick="editMove('${escAttr(m.id)}')">Edit</button></td>
        </tr>
    `).join('');

    $('#moves-pagination').innerHTML = `
        <span>Page ${page + 1} of ${totalPages} (${moves.length} moves)</span>
        <div class="pagination-btns">
            ${page > 0 ? `<button class="btn btn-sm" onclick="renderMovesPage(window._movesFiltered, ${page - 1})">Prev</button>` : ''}
            ${page < totalPages - 1 ? `<button class="btn btn-sm" onclick="renderMovesPage(window._movesFiltered, ${page + 1})">Next</button>` : ''}
        </div>
    `;
    window._movesFiltered = moves;
}

const POKEMON_TYPES = ['NORMAL','FIRE','WATER','GRASS','ELECTRIC','ICE','FIGHTING','POISON','GROUND','FLYING','PSYCHIC','BUG','ROCK','GHOST','DRAGON','DARK','STEEL','FAIRY'];
const DAMAGE_CATEGORIES = ['PHYSICAL','SPECIAL','STATUS'];

function editMove(id) {
    const move = state.moves.find(m => m.id === id);
    if (!move) return;
    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Move: ${escHtml(move.name || move.id)}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-row">
                    <div class="form-group">
                        <label>Move ID</label>
                        <input type="text" value="${escAttr(move.id)}" readonly style="opacity:0.6">
                    </div>
                    <div class="form-group">
                        <label>Name</label>
                        <input type="text" value="${escAttr(move.name || '')}" readonly style="opacity:0.6" title="Name is set in the source file">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Type</label>
                        <select id="move-type">
                            ${POKEMON_TYPES.map(t => `<option value="${t}" ${move.type === t ? 'selected' : ''}>${t}</option>`).join('')}
                        </select>
                    </div>
                    <div class="form-group">
                        <label>Category</label>
                        <select id="move-category">
                            ${DAMAGE_CATEGORIES.map(c => `<option value="${c}" ${move.category === c ? 'selected' : ''}>${c}</option>`).join('')}
                        </select>
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Power</label>
                        <input type="number" id="move-power" value="${move.power || 0}" min="0" max="999">
                    </div>
                    <div class="form-group">
                        <label>Accuracy</label>
                        <input type="number" id="move-accuracy" value="${move.accuracy || 0}" min="0" max="100">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>PP</label>
                        <input type="number" id="move-pp" value="${move.pp || 0}" min="1" max="64">
                    </div>
                    <div class="form-group">
                        <label>Priority</label>
                        <input type="number" id="move-priority" value="${move.priority || 0}" min="-7" max="7">
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-move-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-move-btn').addEventListener('click', () => {
        move.type = $('#move-type').value;
        move.category = $('#move-category').value;
        move.power = $('#move-power').value;
        move.accuracy = $('#move-accuracy').value;
        move.pp = $('#move-pp').value;
        move.priority = parseInt($('#move-priority').value);
        updateMoveInFile(move);
        toast(`Move ${move.name || move.id} updated (auto-saved)`);
        overlay.remove();
        renderMoves();
    });
}

// ─── Items ──────────────────────────────────────────────────────────────────
async function renderItems() {
    const items = await loadItems();
    const search = state.search.toLowerCase();
    const filtered = items.filter(m =>
        m.name && m.id !== 'ITEM_NONE' && (
            !search ||
            (m.name || '').toLowerCase().includes(search) ||
            m.id.toLowerCase().includes(search) ||
            (m.pocket || '').toLowerCase().includes(search)
        )
    );

    content.innerHTML = `
        <div class="page-header">
            <h1>Items <span style="color:var(--text-dim);font-size:14px">(${filtered.length})</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search items by name or pocket..." id="item-search" value="${state.search}">
        </div>
        <div class="table-container">
            <table>
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>ID</th>
                        <th>Pocket</th>
                        <th>Price</th>
                        <th></th>
                    </tr>
                </thead>
                <tbody id="items-tbody"></tbody>
            </table>
        </div>
        <div class="pagination" id="items-pagination"></div>
    `;

    renderItemsPage(filtered, 0);
    $('#item-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        await renderItems();
        const el = $('#item-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

function renderItemsPage(items, page) {
    const perPage = 50;
    const start = page * perPage;
    const pageItems = items.slice(start, start + perPage);
    const totalPages = Math.ceil(items.length / perPage);

    $('#items-tbody').innerHTML = pageItems.map(m => `
        <tr>
            <td><strong>${escHtml(m.name || '-')}</strong></td>
            <td style="font-family:monospace;font-size:12px;color:var(--text-dim)">${m.id}</td>
            <td>${m.pocket || '-'}</td>
            <td>${m.price || '0'}</td>
            <td><button class="btn btn-sm" onclick="editItem('${escAttr(m.id)}')">Edit</button></td>
        </tr>
    `).join('');

    $('#items-pagination').innerHTML = `
        <span>Page ${page + 1} of ${totalPages} (${items.length} items)</span>
        <div class="pagination-btns">
            ${page > 0 ? `<button class="btn btn-sm" onclick="renderItemsPage(window._itemsFiltered, ${page - 1})">Prev</button>` : ''}
            ${page < totalPages - 1 ? `<button class="btn btn-sm" onclick="renderItemsPage(window._itemsFiltered, ${page + 1})">Next</button>` : ''}
        </div>
    `;
    window._itemsFiltered = items;
}

const ITEM_POCKETS = ['POKE_BALLS','ITEMS','KEY_ITEMS','BERRIES','TM_HM','MEDICINE'];

function editItem(id) {
    const item = state.items.find(i => i.id === id);
    if (!item) return;
    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Item: ${escHtml(item.name || item.id)}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-row">
                    <div class="form-group">
                        <label>Item ID</label>
                        <input type="text" value="${escAttr(item.id)}" readonly style="opacity:0.6">
                    </div>
                    <div class="form-group">
                        <label>Name</label>
                        <input type="text" value="${escAttr(item.name || '')}" readonly style="opacity:0.6" title="Name is set in the source file">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Price</label>
                        <input type="number" id="item-price" value="${item.price || 0}" min="0">
                    </div>
                    <div class="form-group">
                        <label>Pocket</label>
                        <select id="item-pocket">
                            ${ITEM_POCKETS.map(p => `<option value="${p}" ${item.pocket === p ? 'selected' : ''}>${p}</option>`).join('')}
                        </select>
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-item-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-item-btn').addEventListener('click', () => {
        item.price = $('#item-price').value;
        item.pocket = $('#item-pocket').value;
        updateItemInFile(item);
        toast(`Item ${item.name || item.id} updated (auto-saved)`);
        overlay.remove();
        renderItems();
    });
}

// ─── Abilities ──────────────────────────────────────────────────────────────
async function renderAbilities() {
    const abilities = await loadAbilities();
    const search = state.search.toLowerCase();
    const filtered = abilities.filter(a =>
        a.name && a.id !== 'ABILITY_NONE' && (
            !search ||
            (a.name || '').toLowerCase().includes(search) ||
            a.id.toLowerCase().includes(search) ||
            (a.description || '').toLowerCase().includes(search)
        )
    );

    content.innerHTML = `
        <div class="page-header">
            <h1>Abilities <span style="color:var(--text-dim);font-size:14px">(${filtered.length})</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search abilities..." id="ability-search" value="${state.search}">
        </div>
        <div class="table-container">
            <table>
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Description</th>
                        <th>AI Rating</th>
                        <th>Breakable</th>
                        <th></th>
                    </tr>
                </thead>
                <tbody>
                    ${filtered.map(a => `
                        <tr>
                            <td><strong>${escHtml(a.name || '-')}</strong><br><span style="font-size:11px;color:var(--text-dim);font-family:monospace">${a.id}</span></td>
                            <td>${escHtml(a.description || '-')}</td>
                            <td>${a.aiRating ?? '-'}</td>
                            <td>${a.breakable ? '<span style="color:var(--yellow)">Yes</span>' : '-'}</td>
                            <td><button class="btn btn-sm" onclick="editAbility('${escAttr(a.id)}')">Edit</button></td>
                        </tr>
                    `).join('')}
                </tbody>
            </table>
        </div>
    `;

    $('#ability-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        await renderAbilities();
        const el = $('#ability-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

function editAbility(id) {
    const ability = state.abilities.find(a => a.id === id);
    if (!ability) return;
    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Ability: ${escHtml(ability.name || ability.id)}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-row">
                    <div class="form-group">
                        <label>Ability ID</label>
                        <input type="text" value="${escAttr(ability.id)}" readonly style="opacity:0.6">
                    </div>
                    <div class="form-group">
                        <label>Name</label>
                        <input type="text" value="${escAttr(ability.name || '')}" readonly style="opacity:0.6" title="Name is set in the source file">
                    </div>
                </div>
                <div class="form-group">
                    <label>Description</label>
                    <input type="text" id="ability-desc" value="${escAttr(ability.description || '')}" style="width:100%">
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>AI Rating</label>
                        <input type="number" id="ability-rating" value="${ability.aiRating || 0}" min="0" max="10">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Breakable (by Mold Breaker etc.)</label>
                        <select id="ability-breakable">
                            <option value="false" ${!ability.breakable ? 'selected' : ''}>No</option>
                            <option value="true" ${ability.breakable ? 'selected' : ''}>Yes</option>
                        </select>
                    </div>
                    <div class="form-group">
                        <label>Can't Be Swapped</label>
                        <select id="ability-noswap">
                            <option value="false" ${!ability.cantBeSwapped ? 'selected' : ''}>No</option>
                            <option value="true" ${ability.cantBeSwapped ? 'selected' : ''}>Yes</option>
                        </select>
                    </div>
                    <div class="form-group">
                        <label>Can't Be Traced</label>
                        <select id="ability-notrace">
                            <option value="false" ${!ability.cantBeTraced ? 'selected' : ''}>No</option>
                            <option value="true" ${ability.cantBeTraced ? 'selected' : ''}>Yes</option>
                        </select>
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-ability-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-ability-btn').addEventListener('click', () => {
        ability.description = $('#ability-desc').value;
        ability.aiRating = parseInt($('#ability-rating').value);
        ability.breakable = $('#ability-breakable').value === 'true';
        ability.cantBeSwapped = $('#ability-noswap').value === 'true';
        ability.cantBeTraced = $('#ability-notrace').value === 'true';
        updateAbilityInFile(ability);
        toast(`Ability ${ability.name || ability.id} updated (auto-saved)`);
        overlay.remove();
        renderAbilities();
    });
}

// ─── Maps/Areas (Unified View) ──────────────────────────────────────────────
const WEATHER_OPTIONS = ['WEATHER_NONE','WEATHER_SUNNY_CLOUDS','WEATHER_SUNNY','WEATHER_RAIN','WEATHER_SNOW','WEATHER_RAIN_THUNDERSTORM','WEATHER_FOG_HORIZONTAL','WEATHER_VOLCANIC_ASH','WEATHER_SANDSTORM','WEATHER_FOG_DIAGONAL','WEATHER_UNDERWATER','WEATHER_SHADE','WEATHER_DROUGHT','WEATHER_DOWNPOUR','WEATHER_UNDERWATER_BUBBLES','WEATHER_ABNORMAL','WEATHER_ROUTE119_CYCLE','WEATHER_ROUTE123_CYCLE'];
const MAP_TYPES = ['MAP_TYPE_NONE','MAP_TYPE_TOWN','MAP_TYPE_CITY','MAP_TYPE_ROUTE','MAP_TYPE_UNDERGROUND','MAP_TYPE_UNDERWATER','MAP_TYPE_OCEAN_ROUTE','MAP_TYPE_INDOOR','MAP_TYPE_SECRET_BASE'];
const BATTLE_SCENES = ['MAP_BATTLE_SCENE_NORMAL','MAP_BATTLE_SCENE_GYM','MAP_BATTLE_SCENE_MAGMA','MAP_BATTLE_SCENE_AQUA','MAP_BATTLE_SCENE_SIDNEY','MAP_BATTLE_SCENE_PHOEBE','MAP_BATTLE_SCENE_GLACIA','MAP_BATTLE_SCENE_DRAKE','MAP_BATTLE_SCENE_FRONTIER'];
const ENC_COLORS = { land_mons: '#22c55e', water_mons: '#6890f0', rock_smash_mons: '#b8a038', fishing_mons: '#06b6d4' };
const ENC_LABELS = { land_mons: 'Grass / Land', water_mons: 'Surfing', rock_smash_mons: 'Rock Smash', fishing_mons: 'Fishing' };
const ENC_ICONS = { land_mons: '&#127793;', water_mons: '&#127754;', rock_smash_mons: '&#9968;', fishing_mons: '&#127907;' };

const TRAINER_TYPES_LIST = ['TRAINER_TYPE_NONE', 'TRAINER_TYPE_NORMAL', 'TRAINER_TYPE_SEE_ALL_DIRECTIONS', 'TRAINER_TYPE_BURIED'];
const MUGSHOT_OPTIONS = ['', 'Purple', 'Green', 'Pink', 'Blue', 'Yellow'];
const AI_FLAG_OPTIONS = ['Check Bad Move','Try To Faint','Check Viability','Force Setup First Turn','Risky','Try To 2HKO','Prefer Baton Pass','Double Battle','HP Aware','Powerful Status','Negate Unaware','Will Suicide','Prefer Status Moves','Stall','Smart Switching','Ace Pokemon','Omniscient','Smart Mon Choices','Conservative','Sequence Switching','Double Ace Pokemon','Weigh Ability Prediction','Prefer Highest Damage Move','Predict Switch','Predict Incoming Mon','PP Stall Prevention','Predict Move','Smart Tera','Assume STAB','Assume Status Moves'];
const AI_PRESETS = ['Basic Trainer','Check Bad Move','Check Bad Move / Try To Faint','Check Bad Move / Try To Faint / Force Setup First Turn','Basic Trainer / Force Setup First Turn','Basic Trainer / Risky'];
const STARTING_STATUS_OPTIONS = ['', 'STATUS1_NONE', 'STATUS1_POISON', 'STATUS1_BURN', 'STATUS1_FREEZE', 'STATUS1_PARALYSIS', 'STATUS1_TOXIC_POISON', 'STATUS1_SLEEP', 'STATUS1_FROSTBITE'];
const COORD_EVENT_TYPES = ['trigger', 'weather'];
const NATURES = ['Hardy','Lonely','Brave','Adamant','Naughty','Bold','Docile','Relaxed','Impish','Lax','Timid','Hasty','Serious','Jolly','Naive','Modest','Mild','Quiet','Bashful','Rash','Calm','Gentle','Sassy','Careful','Quirky'];
const BALLS = ['Poke Ball','Great Ball','Ultra Ball','Master Ball','Net Ball','Dive Ball','Nest Ball','Repeat Ball','Timer Ball','Luxury Ball','Premier Ball','Dusk Ball','Heal Ball','Quick Ball','Cherish Ball','Dream Ball','Beast Ball'];
const TERA_TYPES = ['','Normal','Fire','Water','Grass','Electric','Ice','Fighting','Poison','Ground','Flying','Psychic','Bug','Rock','Ghost','Dragon','Dark','Steel','Fairy','Stellar'];

// Dynamic option extraction helpers
function getUniqueGraphicsIds() {
    if (!state.maps) return [];
    const ids = new Set();
    for (const m of state.maps) {
        for (const evt of (m.object_events || [])) {
            if (evt.graphics_id) ids.add(evt.graphics_id);
        }
    }
    return [...ids].sort();
}

function getUniqueMovementTypes() {
    if (!state.maps) return [];
    const types = new Set();
    for (const m of state.maps) {
        for (const evt of (m.object_events || [])) {
            if (evt.movement_type) types.add(evt.movement_type);
        }
    }
    return [...types].sort();
}

function getUniqueTrainerPics() {
    if (!state.trainers) return [];
    return [...new Set(state.trainers.map(t => t.pic).filter(Boolean))].sort();
}

function getUniqueTrainerClasses() {
    if (!state.trainers) return [];
    return [...new Set(state.trainers.map(t => t.class).filter(Boolean))].sort();
}

function getUniqueTrainerMusic() {
    if (!state.trainers) return [];
    return [...new Set(state.trainers.map(t => t.music).filter(Boolean))].sort();
}

function getUniqueMusicConstants() {
    if (!state.maps) return [];
    const music = new Set();
    for (const m of state.maps) {
        if (m.music) music.add(m.music);
    }
    return [...music].sort();
}

function getUniqueScripts() {
    if (!state.maps) return [];
    const scripts = new Set();
    for (const m of state.maps) {
        for (const evt of (m.object_events || [])) {
            if (evt.script) scripts.add(evt.script);
        }
    }
    return [...scripts].sort();
}

function getUniqueItemIds() {
    if (!state.items) return [];
    return state.items.map(i => i.id).filter(Boolean).sort();
}

function getUniqueSpeciesIds() {
    if (!state.pokemon) return [];
    return state.pokemon.map(p => p.id).filter(Boolean).sort();
}

function makeDatalistHtml(id, value, options, extraAttrs = '') {
    const listId = `dl-${id}-${Date.now()}`;
    return `<input type="text" id="${id}" value="${escAttr(value)}" list="${listId}" ${extraAttrs}><datalist id="${listId}">${options.map(o => `<option value="${escAttr(o)}">`).join('')}</datalist>`;
}

function makeSelectHtml(id, value, options, extraAttrs = '') {
    return `<select id="${id}" ${extraAttrs}>${options.map(o => `<option value="${escAttr(o)}" ${o === value ? 'selected' : ''}>${escHtml(o)}</option>`).join('')}</select>`;
}

function rawFileUrl(filePath) {
    return `https://raw.githubusercontent.com/${REPO_OWNER}/${REPO_NAME}/${BRANCH}/${filePath}`;
}

// Map graphics IDs to trainer front pic filenames where the name doesn't match directly
const FRONT_PIC_MAP = {
    'archie': 'aqua_leader_archie',
    'maxie': 'magma_leader_maxie',
    'aqua_member_m': 'aqua_grunt_m',
    'aqua_member_f': 'aqua_grunt_f',
    'magma_member_m': 'magma_grunt_m',
    'magma_member_f': 'magma_grunt_f',
    'brawly': 'leader_brawly',
    'roxanne': 'leader_roxanne',
    'flannery': 'leader_flannery',
    'norman': 'leader_norman',
    'wattson': 'leader_wattson',
    'winona': 'leader_winona',
    'juan': 'leader_juan',
    'wallace': 'champion_wallace',
    'drake': 'elite_four_drake',
    'phoebe': 'elite_four_phoebe',
    'glacia': 'elite_four_glacia',
    'sidney': 'elite_four_sidney',
    'brandon': 'pyramid_king_brandon',
    'rival_brendan_normal': 'brendan',
    'rival_may_normal': 'may',
    'brendan_normal': 'brendan',
    'may_normal': 'may',
    'rocker': 'guitarist',
    'maniac': 'ruin_maniac',
    'rocket_m': 'rocket_grunt_m_frlg',
    'rocket_f': 'rocket_grunt_f_frlg',
    'blackbelt': 'black_belt',
    'fisher': 'fisherman',
    'prof_birch': 'brendan', // no prof_birch front pic
    'prof_oak': 'professor_oak_frlg',
    'agatha': 'elite_four_agatha_frlg',
    'bruno': 'elite_four_bruno_frlg',
    'lorelei': 'elite_four_lorelei_frlg',
    'lance': 'elite_four_lance_frlg',
    'brock': 'leader_brock_frlg',
    'misty': 'leader_misty_frlg',
    'lt_surge': 'leader_lt_surge_frlg',
    'erika': 'leader_erika_frlg',
    'koga': 'leader_koga_frlg',
    'sabrina': 'leader_sabrina_frlg',
    'blaine': 'leader_blaine_frlg',
    'giovanni': 'leader_giovanni_frlg',
    'blue': 'rival_early_frlg',
    'channeler': 'channeler_frlg',
    'super_nerd': 'super_nerd_frlg',
    'cook': 'kindler',
    'scientist_1': 'scientist_frlg',
    'scientist_2': 'scientist_frlg',
    'tate': 'leader_tate_and_liza',
    'liza': 'leader_tate_and_liza',
    'swimmer_f_land': 'swimmer_f',
    'swimmer_f_water': 'swimmer_f',
    'swimmer_m_land': 'swimmer_m',
    'swimmer_m_water': 'swimmer_m',
    'tuber_m_swimming': 'tuber_m',
    'tuber_m_water': 'tuber_m',
};

// Graphics IDs that are overworld-only (no trainer front pic exists) - use overworld sprite
const OVERWORLD_ONLY = new Set([
    'boy', 'boy_1', 'boy_2', 'boy_3', 'girl_1', 'girl_2', 'girl_3',
    'woman_1', 'woman_2', 'woman_3', 'woman_4', 'woman_5',
    'woman_1_frlg', 'woman_2_frlg', 'woman_3_frlg',
    'man', 'man_1', 'man_2', 'man_3', 'man_4', 'man_5',
    'old_man', 'old_man_1', 'old_man_2', 'old_woman', 'old_woman_frlg',
    'little_boy', 'little_boy_frlg', 'little_girl', 'little_girl_frlg',
    'fat_man', 'fat_man_frlg', 'balding_man', 'twin',
    'cable_club_receptionist', 'link_receptionist', 'union_room_receptionist',
    'union_room_nurse', 'nurse', 'nurse_frlg', 'mart_employee',
    'policeman', 'devon_employee', 'gym_guy', 'captain',
    'hot_springs_old_woman', 'contest_judge', 'artist', 'cameraman',
    'reporter_f', 'reporter_m', 'clerk', 'chef',
    'rooftop_sale_woman', 'gameboy_kid', 'gba_kid', 'sitting_boy',
    'quinty_plump', 'scott', 'teala', 'mom', 'mom_frlg',
    'bill', 'celio', 'daisy', 'mr_fuji', 'trainer_tower_dude',
    'mg_deliveryman', 'mystery_gift_man', 'worker_f', 'worker_m',
]);

function getSpriteUrl(graphicsId) {
    const name = (graphicsId || '').replace('OBJ_EVENT_GFX_', '').toLowerCase();

    // Try trainer front pic first (mapped name or direct match)
    if (!OVERWORLD_ONLY.has(name)) {
        const frontPicName = FRONT_PIC_MAP[name] || name;
        return { url: rawFileUrl(`graphics/trainers/front_pics/${frontPicName}.png`), type: 'front' };
    }

    // Fall back to overworld sprite
    return { url: rawFileUrl(`graphics/object_events/pics/people/${name}.png`), type: 'overworld' };
}

function getSpriteHtml(graphicsId, size = 32) {
    const { url, type } = getSpriteUrl(graphicsId);
    const name = (graphicsId || '').replace('OBJ_EVENT_GFX_', '').replace(/_/g, ' ');
    const imgStyle = type === 'front'
        ? `width:${size}px;height:${size}px;object-fit:contain;image-rendering:pixelated`
        : `height:${size}px;width:auto;image-rendering:pixelated`;
    return `<div class="sprite-container" style="width:${size}px;height:${size}px">
        <img src="${url}" onerror="this.style.display='none';this.nextElementSibling.style.display='flex'" style="${imgStyle}" alt="${escAttr(name)}">
        <div class="sprite-fallback" style="display:none;width:${size}px;height:${size}px">${escHtml(name.substring(0, 2).toUpperCase())}</div>
    </div>`;
}

function getTrainerPicUrl(pic) {
    const picNameOverrides = {
        'rs brendan': 'brendan_rs',
        'rs may': 'may_rs',
    };
    const lower = (pic || '').toLowerCase();
    const name = picNameOverrides[lower] || lower.replace(/\s+/g, '_');
    return rawFileUrl(`graphics/trainers/front_pics/${name}.png`);
}

function getTrainerPicHtml(pic, size = 64) {
    const url = getTrainerPicUrl(pic);
    const name = pic || '';
    return `<div class="sprite-container" style="width:${size}px;height:${size}px">
        <img src="${url}" onerror="this.style.display='none';this.nextElementSibling.style.display='flex'" style="width:${size}px;height:${size}px;image-rendering:pixelated" alt="${escAttr(name)}">
        <div class="sprite-fallback" style="display:none;width:${size}px;height:${size}px">${escHtml((name || '??').substring(0, 2).toUpperCase())}</div>
    </div>`;
}

function getPreviewUrl(dirName) {
    return `previews/${encodeURIComponent(dirName)}.png`;
}

function getFullPreviewUrl(dirName) {
    return `previews/full/${encodeURIComponent(dirName)}.png`;
}

function getMapDisplayName(m) {
    return (m._dirName || m.name || '').replace(/([A-Z])/g, ' $1').trim().replace(/_/g, ' ');
}

function getMapType(m) {
    return (m.map_type || 'MAP_TYPE_NONE').replace('MAP_TYPE_', '');
}

function getMapEncounters(map) {
    if (!state.encounters) return null;
    const encounters = state.encounters.wild_encounter_groups?.[0]?.encounters || [];
    return encounters.find(e => e.map === map.id) || null;
}

function getMapTrainers(map) {
    return (map.object_events || []).filter(e => e.trainer_type && e.trainer_type !== 'TRAINER_TYPE_NONE');
}

// Get trainers including script-based ones (gym leaders, elite 4)
function getAllMapTrainers(map, scriptText) {
    const normalTrainers = getMapTrainers(map);
    const scriptTrainers = getScriptTrainers(map, scriptText);
    // Combine, avoiding duplicates
    const combined = [...normalTrainers];
    for (const st of scriptTrainers) {
        if (!combined.includes(st)) combined.push(st);
    }
    return combined;
}

function getMapItemBalls(map) {
    return (map.object_events || []).filter(e => (e.graphics_id || '').includes('ITEM_BALL'));
}

function getMapHiddenItems(map) {
    return (map.bg_events || []).filter(e => e.type === 'hidden_item');
}

function getEncounterRates() {
    if (!state.encounters) return [];
    return state.encounters.wild_encounter_groups?.[0]?.fields || [];
}

async function renderMaps() {
    // If viewing a specific map area, render the detail view
    if (state.mapDetail) {
        await renderMapDetail(state.mapDetail);
        return;
    }

    const maps = await loadMaps();
    // Also pre-load encounters for the tags
    try { await loadEncounters(); } catch {}

    const search = state.search.toLowerCase();
    const filtered = maps.filter(m => {
        if (!search) return true;
        const enc = getMapEncounters(m);
        const hasSearchInEnc = enc && Object.values(enc).some(v => {
            if (v && typeof v === 'object' && v.mons) {
                return v.mons.some(mon => mon.species.toLowerCase().includes(search));
            }
            return false;
        });
        return (m.id || '').toLowerCase().includes(search) ||
            (m.name || '').toLowerCase().includes(search) ||
            (m._dirName || '').toLowerCase().includes(search) ||
            (m.map_type || '').toLowerCase().includes(search) ||
            (m.weather || '').toLowerCase().includes(search) ||
            hasSearchInEnc;
    });

    const typeGroups = {};
    for (const m of filtered) {
        const type = getMapType(m);
        if (!typeGroups[type]) typeGroups[type] = [];
        typeGroups[type].push(m);
    }

    const typeOrder = ['ROUTE', 'CITY', 'TOWN', 'UNDERGROUND', 'OCEAN_ROUTE', 'UNDERWATER', 'INDOOR', 'SECRET_BASE'];
    const sortedTypes = Object.keys(typeGroups).sort((a, b) => {
        const ai = typeOrder.indexOf(a);
        const bi = typeOrder.indexOf(b);
        if (ai >= 0 && bi >= 0) return ai - bi;
        if (ai >= 0) return -1;
        if (bi >= 0) return 1;
        return a.localeCompare(b);
    });

    // Build filter chips for map types
    const typeFilter = state.mapTypeFilter || 'all';
    const typeChips = sortedTypes.map(t => {
        const count = typeGroups[t].length;
        return `<span class="filter-chip ${typeFilter === t ? 'active' : ''}" onclick="state.mapTypeFilter='${t}'; renderMaps()">${t} (${count})</span>`;
    }).join('');

    content.innerHTML = `
        <div class="page-header">
            <h1>Areas <span style="color:var(--text-dim);font-size:14px">(${filtered.length}/${maps.length})</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search by map name, type, species..." id="map-search" value="${state.search}">
        </div>
        <div class="filter-row">
            <span class="filter-chip ${typeFilter === 'all' ? 'active' : ''}" onclick="state.mapTypeFilter='all'; renderMaps()">All (${filtered.length})</span>
            ${typeChips}
        </div>
        <div class="card-grid" id="map-grid"></div>
    `;

    const grid = $('#map-grid');
    const typesToShow = typeFilter === 'all' ? sortedTypes : [typeFilter];
    let count = 0;
    const maxCards = 120;

    for (const type of typesToShow) {
        if (!typeGroups[type]) continue;
        for (const m of typeGroups[type]) {
            if (count >= maxCards) break;
            count++;
            const enc = getMapEncounters(m);
            const trainers = getMapTrainers(m);
            const itemBalls = getMapItemBalls(m);
            const hiddenItems = getMapHiddenItems(m);
            const displayName = getMapDisplayName(m);
            const bannerClass = `banner-${type}`;

            let tags = '';
            if (enc) {
                const encTypes = ['land_mons','water_mons','rock_smash_mons','fishing_mons'].filter(t => enc[t]);
                tags += `<span class="tag has-encounters">${encTypes.length} encounter type${encTypes.length !== 1 ? 's' : ''}</span>`;
            }
            if (trainers.length > 0) {
                tags += `<span class="tag has-trainers">${trainers.length} trainer${trainers.length !== 1 ? 's' : ''}</span>`;
            }
            if (itemBalls.length + hiddenItems.length > 0) {
                tags += `<span class="tag has-items">${itemBalls.length + hiddenItems.length} item${itemBalls.length + hiddenItems.length !== 1 ? 's' : ''}</span>`;
            }
            const conns = (m.connections || []).length;
            if (conns > 0) tags += `<span class="tag has-data">${conns} connection${conns !== 1 ? 's' : ''}</span>`;

            const previewUrl = getPreviewUrl(m._dirName);
            grid.innerHTML += `
                <div class="map-list-card" onclick="openMapDetail('${escAttr(m._dirName)}')">
                    <div class="map-list-card-banner ${bannerClass}" style="background-image:url('${previewUrl}')"></div>
                    <div class="map-list-card-body">
                        <h3>${escHtml(displayName)}</h3>
                        <div class="map-list-id">${escHtml(m.id || '')}</div>
                        <div class="map-list-card-tags">
                            <span class="tag">${type}</span>
                            <span class="tag">${(m.weather || 'WEATHER_NONE').replace('WEATHER_', '')}</span>
                            ${tags}
                        </div>
                    </div>
                </div>
            `;
        }
    }
    if (count >= maxCards) {
        grid.innerHTML += `<div style="padding:20px;color:var(--text-dim);font-size:13px;grid-column:1/-1">Showing ${maxCards} of ${filtered.length} maps. Use search or filters to narrow down.</div>`;
    }

    $('#map-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        await renderMaps();
        const el = $('#map-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

function openMapDetail(dirName) {
    state.mapDetail = dirName;
    renderMaps();
}

async function renderMapDetail(dirName) {
    const maps = await loadMaps();
    const map = maps.find(m => m._dirName === dirName);
    if (!map) { state.mapDetail = null; renderMaps(); return; }

    try { await loadEncounters(); } catch {}

    // Load script file for this map (for script-based trainer detection and dialogue)
    let scriptText = '';
    try { scriptText = await loadMapScript(dirName); } catch {}

    const displayName = getMapDisplayName(map);
    const mapType = getMapType(map);
    const bannerClass = `banner-${mapType}`;
    const enc = getMapEncounters(map);
    const trainers = getAllMapTrainers(map, scriptText);
    const itemBalls = getMapItemBalls(map);
    const hiddenItems = getMapHiddenItems(map);
    const encounterRates = getEncounterRates();
    const npcCount = (map.object_events || []).filter(e =>
        !(e.graphics_id || '').includes('ITEM_BALL') && !(e.graphics_id || '').includes('BERRY_TREE')
    ).length;
    const conns = (map.connections || []).length;
    const doors = (map.warp_events || []).length;

    content.innerHTML = `
        <button class="back-btn" onclick="state.mapDetail=null; renderMaps()">&#8592; Back to Areas</button>

        <!-- Banner -->
        <div class="map-area-header">
            <div class="map-area-banner ${bannerClass}" style="background-image:url('${getPreviewUrl(dirName)}')">
                <div class="map-area-banner-content">
                    <div>
                        <h1>${escHtml(displayName)}</h1>
                        <div class="map-id-label">${escHtml(map.id || '')}</div>
                    </div>
                    <span class="map-type-pill">${mapType}</span>
                </div>
            </div>
            <div class="map-area-info-bar">
                <span class="map-music-info"><span class="info-icon">&#9835;</span> ${(map.music || 'None').replace('MUS_', '')}${map.music && map.music !== 'MUS_DUMMY' ? ` <button class="btn-play-inline" onclick="event.stopPropagation(); playMapMusic('${escAttr(map.music)}')" title="Play music">&#9654;</button>` : ''}</span>
                <span><span class="info-icon">&#9729;</span> ${(map.weather || 'None').replace('WEATHER_', '')}</span>
                <span><span class="info-icon">&#9786;</span> ${npcCount} NPCs</span>
                <span><span class="info-icon">&#8644;</span> ${conns} routes, ${doors} doors</span>
            </div>
        </div>

        <div class="map-area-sections" id="map-area-sections"></div>
    `;

    const sections = $('#map-area-sections');

    // ═══════════════════════════════════════════
    // TIER 1: AREA — about the place itself
    // ═══════════════════════════════════════════
    sections.innerHTML += `<div class="section-tier">Area</div>`;
    sections.innerHTML += buildMapPreviewSection(map);
    sections.innerHTML += buildPropertiesSection(map);
    sections.innerHTML += buildNavigationSection(map);

    // ═══════════════════════════════════════════
    // TIER 2: NPCs — who's here
    // ═══════════════════════════════════════════
    sections.innerHTML += `<div class="section-tier">NPCs</div>`;
    sections.innerHTML += buildUnifiedNPCSection(map, trainers, scriptText);

    // ═══════════════════════════════════════════
    // TIER 3: WORLD — things in the environment
    // ═══════════════════════════════════════════
    sections.innerHTML += `<div class="section-tier">World</div>`;
    sections.innerHTML += buildEncounterSection(enc, encounterRates, map);
    sections.innerHTML += buildItemSection(itemBalls, hiddenItems, map);
    sections.innerHTML += buildSignsAndTriggersSection(map);

    // Wire up section toggles
    $$('.map-area-section-header').forEach(header => {
        header.addEventListener('click', () => {
            const body = header.nextElementSibling;
            if (body) body.classList.toggle('collapsed');
            const arrow = header.querySelector('.toggle-arrow');
            if (arrow) arrow.textContent = body.classList.contains('collapsed') ? '&#9654;' : '&#9660;';
        });
    });

    // Wire up NPC card expansion
    $$('.npc-card-header').forEach(header => {
        header.addEventListener('click', (e) => {
            // Don't expand if clicking a button
            if (e.target.closest('.btn')) return;
            header.closest('.npc-card').classList.toggle('expanded');
        });
    });

    // Initialize interactive map markers
    initInteractiveMap(map);
}

// ── Interactive Map Section ──
function buildMapPreviewSection(map) {
    const fullUrl = getFullPreviewUrl(map._dirName);
    const thumbUrl = getPreviewUrl(map._dirName);
    const dirName = map._dirName;

    // Collect all plottable entities
    const npcs = (map.object_events || []).filter(e =>
        !(e.graphics_id || '').includes('ITEM_BALL') && !(e.graphics_id || '').includes('BERRY_TREE')
    );
    const itemBalls = getMapItemBalls(map);
    const hiddenItems = getMapHiddenItems(map);
    const warps = map.warp_events || [];
    const signs = (map.bg_events || []).filter(e => e.type === 'sign');
    const coordEvents = map.coord_events || [];

    // Legend items
    const legendItems = [];
    if (npcs.length) legendItems.push(`<span class="imap-legend-item"><span class="imap-legend-dot imap-dot-npc"></span> NPCs (${npcs.length})</span>`);
    if (itemBalls.length) legendItems.push(`<span class="imap-legend-item"><span class="imap-legend-dot imap-dot-item"></span> Items (${itemBalls.length})</span>`);
    if (hiddenItems.length) legendItems.push(`<span class="imap-legend-item"><span class="imap-legend-dot imap-dot-hidden"></span> Hidden (${hiddenItems.length})</span>`);
    if (warps.length) legendItems.push(`<span class="imap-legend-item"><span class="imap-legend-dot imap-dot-warp"></span> Doors (${warps.length})</span>`);
    if (signs.length) legendItems.push(`<span class="imap-legend-item"><span class="imap-legend-dot imap-dot-sign"></span> Signs (${signs.length})</span>`);

    return `
        <div class="map-area-section">
            <div class="map-area-section-header">
                <h2><span class="section-icon">&#128506;</span> Interactive Map</h2>
                <span class="toggle-arrow">&#9660;</span>
            </div>
            <div class="map-area-section-body" style="padding:16px">
                <div class="imap-legend">${legendItems.join('')}</div>
                <div class="imap-container" id="imap-container" data-dir="${escAttr(dirName)}">
                    <img
                        id="imap-img"
                        src="${fullUrl}"
                        onerror="this.src='${thumbUrl}'; this.onerror=null;"
                        alt="Interactive map of ${escAttr(getMapDisplayName(map))}"
                        style="max-width:100%;height:auto;image-rendering:pixelated;display:block"
                    >
                    <div class="imap-markers" id="imap-markers"></div>
                </div>
                <div class="imap-hint">Click a marker to edit. Drag to reposition.</div>
            </div>
        </div>
    `;
}

// Place interactive markers on the map image once it loads
function initInteractiveMap(map) {
    const container = $('#imap-container');
    const img = $('#imap-img');
    const markersEl = $('#imap-markers');
    if (!container || !img || !markersEl) return;

    const dirName = map._dirName;

    function placeMarkers() {
        markersEl.innerHTML = '';
        const imgW = img.naturalWidth;
        const imgH = img.naturalHeight;
        if (!imgW || !imgH) return;

        // Compute tile size: GBA maps use 16px tiles in the source images
        const TILE = 16;

        // Collect all entities with positions
        const entities = [];

        // NPCs (non-item, non-berry)
        (map.object_events || []).forEach((evt, i) => {
            if ((evt.graphics_id || '').includes('ITEM_BALL')) {
                entities.push({ type: 'item', x: evt.x, y: evt.y, idx: i, evt, label: (evt.trainer_sight_or_berry_tree_id || '').replace('ITEM_', '').replace(/_/g, ' ') });
            } else if ((evt.graphics_id || '').includes('BERRY_TREE')) {
                // Skip berry trees
            } else {
                const isTrainer = evt.trainer_type && evt.trainer_type !== 'TRAINER_TYPE_NONE';
                let name = (evt.graphics_id || '').replace('OBJ_EVENT_GFX_', '').replace(/_/g, ' ');
                if (evt.script && evt.script !== '0x0') {
                    const parts = evt.script.split('_EventScript_');
                    if (parts.length >= 2) name = parts[parts.length - 1].replace(/_/g, ' ');
                }
                entities.push({ type: isTrainer ? 'trainer' : 'npc', x: evt.x, y: evt.y, idx: i, evt, label: name });
            }
        });

        // Hidden items
        (map.bg_events || []).forEach((evt, i) => {
            if (evt.type === 'hidden_item') {
                entities.push({ type: 'hidden', x: evt.x, y: evt.y, bgIdx: i, evt, label: (evt.item || '').replace('ITEM_', '').replace(/_/g, ' ') });
            } else if (evt.type === 'sign') {
                entities.push({ type: 'sign', x: evt.x, y: evt.y, bgIdx: i, evt, label: 'Sign' });
            }
        });

        // Warps
        (map.warp_events || []).forEach((evt, i) => {
            const dest = (evt.dest_map || '').replace('MAP_', '').replace(/_/g, ' ');
            entities.push({ type: 'warp', x: evt.x, y: evt.y, warpIdx: i, evt, label: dest || 'Warp' });
        });

        for (const ent of entities) {
            const marker = document.createElement('div');
            marker.className = `imap-marker imap-marker-${ent.type}`;
            // Position as percentage relative to image size
            // +7 offset: maps typically have a 7-tile border on each side
            const px = ((ent.x + 7) * TILE + TILE / 2) / imgW * 100;
            const py = ((ent.y + 7) * TILE + TILE / 2) / imgH * 100;
            marker.style.left = px + '%';
            marker.style.top = py + '%';
            marker.title = `${ent.type.toUpperCase()}: ${ent.label} (${ent.x}, ${ent.y})`;
            marker.dataset.entityType = ent.type;
            marker.dataset.x = ent.x;
            marker.dataset.y = ent.y;

            // Icon inside marker
            const icons = { npc: '\u263A', trainer: '\u2694', item: '\u2666', hidden: '\u2733', warp: '\uD83D\uDEAA', sign: '\uD83D\uDCCB' };
            marker.innerHTML = icons[ent.type] || '\u2022';

            // Click to open edit menu
            marker.addEventListener('click', (e) => {
                e.stopPropagation();
                openMarkerMenu(ent, map, marker);
            });

            // Drag to reposition
            setupMarkerDrag(marker, ent, map, img, TILE);

            markersEl.appendChild(marker);
        }
    }

    if (img.complete && img.naturalWidth) {
        placeMarkers();
    } else {
        img.addEventListener('load', placeMarkers);
    }
    // Recompute on resize
    const observer = new ResizeObserver(() => placeMarkers());
    observer.observe(container);
    // Store cleanup ref
    container._resizeObserver = observer;
}

function setupMarkerDrag(marker, entity, map, img, TILE) {
    let isDragging = false;
    let startX, startY;
    const DRAG_THRESHOLD = 4;

    marker.addEventListener('mousedown', (e) => {
        if (e.button !== 0) return;
        isDragging = false;
        startX = e.clientX;
        startY = e.clientY;
        marker.classList.add('imap-marker-dragging');

        const onMove = (e2) => {
            const dx = e2.clientX - startX;
            const dy = e2.clientY - startY;
            if (Math.abs(dx) > DRAG_THRESHOLD || Math.abs(dy) > DRAG_THRESHOLD) {
                isDragging = true;
                // Move marker visually
                const rect = img.getBoundingClientRect();
                const pxX = ((e2.clientX - rect.left) / rect.width) * 100;
                const pxY = ((e2.clientY - rect.top) / rect.height) * 100;
                marker.style.left = Math.max(0, Math.min(100, pxX)) + '%';
                marker.style.top = Math.max(0, Math.min(100, pxY)) + '%';
            }
        };

        const onUp = (e2) => {
            document.removeEventListener('mousemove', onMove);
            document.removeEventListener('mouseup', onUp);
            marker.classList.remove('imap-marker-dragging');

            if (isDragging) {
                // Calculate new tile coords
                const rect = img.getBoundingClientRect();
                const relX = (e2.clientX - rect.left) / rect.width;
                const relY = (e2.clientY - rect.top) / rect.height;
                const newX = Math.round((relX * img.naturalWidth) / TILE - 7 - 0.5);
                const newY = Math.round((relY * img.naturalHeight) / TILE - 7 - 0.5);

                if (newX !== entity.x || newY !== entity.y) {
                    entity.evt.x = newX;
                    entity.evt.y = newY;
                    entity.x = newX;
                    entity.y = newY;
                    const serialized = { ...map };
                    delete serialized._dirName;
                    markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
                    toast(`Moved ${entity.type} to (${newX}, ${newY})`);
                    renderMapDetail(map._dirName);
                }
            }
        };

        document.addEventListener('mousemove', onMove);
        document.addEventListener('mouseup', onUp);
        e.preventDefault();
    });
}

function openMarkerMenu(entity, map, markerEl) {
    // Remove any existing popup
    $$('.imap-popup').forEach(p => p.remove());

    const popup = document.createElement('div');
    popup.className = 'imap-popup';

    const dirName = map._dirName;
    let buttonsHtml = '';

    if (entity.type === 'npc' || entity.type === 'trainer') {
        buttonsHtml = `
            <button class="btn btn-sm" onclick="editObjectEvent('${escAttr(dirName)}', ${entity.idx}); this.closest('.imap-popup').remove()">Edit</button>
            ${entity.type === 'trainer' ? `<button class="btn btn-sm" onclick="editTrainerPartyFromScript('${escAttr(dirName)}', '${escAttr(entity.evt.script || '')}'); this.closest('.imap-popup').remove()">Party</button>` : ''}
            <button class="btn btn-sm btn-danger" onclick="deleteObjectEvent('${escAttr(dirName)}', ${entity.idx}); this.closest('.imap-popup').remove()">Delete</button>
        `;
    } else if (entity.type === 'item') {
        const itemIdx = getMapItemBalls(map).indexOf(entity.evt);
        buttonsHtml = `
            <button class="btn btn-sm" onclick="editMapItemBall('${escAttr(dirName)}', ${itemIdx}); this.closest('.imap-popup').remove()">Edit</button>
            <button class="btn btn-sm btn-danger" onclick="deleteMapItemBall('${escAttr(dirName)}', ${itemIdx}); this.closest('.imap-popup').remove()">Delete</button>
        `;
    } else if (entity.type === 'warp') {
        buttonsHtml = `
            <button class="btn btn-sm" onclick="editWarp('${escAttr(dirName)}', ${entity.warpIdx}); this.closest('.imap-popup').remove()">Edit</button>
            <button class="btn btn-sm btn-danger" onclick="deleteWarp('${escAttr(dirName)}', ${entity.warpIdx}); this.closest('.imap-popup').remove()">Delete</button>
        `;
    } else if (entity.type === 'hidden') {
        const hiddenIdx = (map.bg_events || []).filter(e => e.type === 'hidden_item').indexOf(entity.evt);
        buttonsHtml = `
            <button class="btn btn-sm" onclick="editMapHiddenItem('${escAttr(dirName)}', ${hiddenIdx}); this.closest('.imap-popup').remove()">Edit</button>
            <button class="btn btn-sm btn-danger" onclick="deleteMapHiddenItem('${escAttr(dirName)}', ${hiddenIdx}); this.closest('.imap-popup').remove()">Delete</button>
        `;
    } else if (entity.type === 'sign') {
        buttonsHtml = `<span style="font-size:11px;color:var(--text-dim)">Sign at (${entity.x}, ${entity.y})</span>`;
    }

    popup.innerHTML = `
        <div class="imap-popup-header">
            <strong>${escHtml(entity.label)}</strong>
            <span class="imap-popup-type imap-dot-${entity.type}">${entity.type}</span>
        </div>
        <div class="imap-popup-coords">(${entity.x}, ${entity.y})</div>
        <div class="imap-popup-actions">${buttonsHtml}</div>
    `;

    // Position near the marker
    const container = $('#imap-container');
    const markerRect = markerEl.getBoundingClientRect();
    const containerRect = container.getBoundingClientRect();
    popup.style.left = (markerRect.left - containerRect.left + markerRect.width / 2) + 'px';
    popup.style.top = (markerRect.top - containerRect.top - 8) + 'px';

    container.appendChild(popup);

    // Close on click elsewhere
    const closeHandler = (e) => {
        if (!popup.contains(e.target) && !markerEl.contains(e.target)) {
            popup.remove();
            document.removeEventListener('click', closeHandler);
        }
    };
    setTimeout(() => document.addEventListener('click', closeHandler), 0);
}

// ── Wild Encounters Section ──
function buildEncounterSection(enc, encounterRates, map) {
    const fieldTypes = ['land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'];
    let totalMons = 0;
    if (enc) {
        for (const t of fieldTypes) {
            if (enc[t]) totalMons += enc[t].mons.length;
        }
    }

    let body = '';
    if (!enc) {
        body = `<div class="empty-state"><div class="empty-icon">&#9733;</div>No wild encounters defined for this area</div>`;
    } else {
        for (const type of fieldTypes) {
            if (!enc[type]) continue;
            const rateField = encounterRates.find(f => f.type === type);
            const rates = rateField?.encounter_rates || [];
            const color = ENC_COLORS[type];

            // Aggregate encounters: combine duplicate species
            const speciesMap = {};
            enc[type].mons.forEach((m, i) => {
                const name = speciesDisplayName(m.species);
                const rate = rates[i] || 0;
                if (!speciesMap[name]) {
                    speciesMap[name] = { species: m.species, name, minLevel: m.min_level, maxLevel: m.max_level, totalRate: 0, count: 0 };
                }
                speciesMap[name].totalRate += rate;
                speciesMap[name].count++;
                speciesMap[name].minLevel = Math.min(speciesMap[name].minLevel, m.min_level);
                speciesMap[name].maxLevel = Math.max(speciesMap[name].maxLevel, m.max_level);
            });
            const aggregated = Object.values(speciesMap).sort((a, b) => b.totalRate - a.totalRate);

            let chartHtml = aggregated.map(a => `
                <div class="encounter-bar-row">
                    <span class="encounter-bar-species">${escHtml(a.name)}</span>
                    <div class="encounter-bar-track">
                        <div class="encounter-bar-fill" style="width:${Math.max(a.totalRate, 2)}%;background:${color}"></div>
                    </div>
                    <span class="encounter-bar-level">Lv ${a.minLevel}${a.minLevel !== a.maxLevel ? '-' + a.maxLevel : ''}</span>
                    <span class="encounter-bar-pct" style="color:${color}">${a.totalRate}%</span>
                </div>
            `).join('');

            body += `
                <div class="encounter-chart-group">
                    <h3>${ENC_ICONS[type]} ${ENC_LABELS[type]} <span class="rate-badge">Rate: ${enc[type].encounter_rate}%</span></h3>
                    ${chartHtml}
                </div>
            `;
        }
        body += `<div style="text-align:right;margin-top:12px"><button class="btn btn-sm" onclick="editMapEncounters('${escAttr(map._dirName)}')">Edit Encounters</button></div>`;
    }

    return `
        <div class="map-area-section">
            <div class="map-area-section-header">
                <h2><span class="section-icon">&#9733;</span> Wild Pokemon <span class="section-count">${totalMons} entries</span></h2>
                <span class="toggle-arrow">&#9660;</span>
            </div>
            <div class="map-area-section-body">${body}</div>
        </div>
    `;
}

// ── Trainers Section (legacy, kept for compatibility) ──
function buildTrainerSection(trainers, map) {
    return ''; // Absorbed into buildUnifiedNPCSection
}

// ── Items Section ──
function buildItemSection(itemBalls, hiddenItems, map) {
    const totalItems = itemBalls.length + hiddenItems.length;
    let body = '';
    if (totalItems === 0) {
        body = `<div class="empty-state"><div class="empty-icon">&#9830;</div>No items in this area</div>`;
    } else {
        const itemRows = itemBalls.map((item, i) => {
            const itemName = (item.trainer_sight_or_berry_tree_id || '').replace('ITEM_', '').replace(/_/g, ' ');
            return `
                <div class="area-item-row">
                    <div class="area-item-icon visible">&#9830;</div>
                    <span class="area-item-name">${escHtml(itemName)}</span>
                    <span class="area-item-type">Item Ball</span>
                    <span class="area-item-coords">(${item.x}, ${item.y})</span>
                    <div style="display:flex;gap:4px">
                        <button class="btn btn-sm" onclick="editMapItemBall('${escAttr(map._dirName)}', ${i})">Edit</button>
                        <button class="btn btn-sm btn-danger" onclick="deleteMapItemBall('${escAttr(map._dirName)}', ${i})">Delete</button>
                    </div>
                </div>
            `;
        }).join('');

        const hiddenRows = hiddenItems.map((item, i) => {
            const itemName = (item.item || '').replace('ITEM_', '').replace(/_/g, ' ');
            return `
                <div class="area-item-row">
                    <div class="area-item-icon hidden">&#10043;</div>
                    <span class="area-item-name">${escHtml(itemName)}</span>
                    <span class="area-item-type">Hidden</span>
                    <span class="area-item-coords">(${item.x}, ${item.y})</span>
                    <div style="display:flex;gap:4px">
                        <button class="btn btn-sm" onclick="editMapHiddenItem('${escAttr(map._dirName)}', ${i})">Edit</button>
                        <button class="btn btn-sm btn-danger" onclick="deleteMapHiddenItem('${escAttr(map._dirName)}', ${i})">Delete</button>
                    </div>
                </div>
            `;
        }).join('');

        body = itemRows + hiddenRows;
    }
    body += `<div style="display:flex;gap:8px;justify-content:flex-end;margin-top:12px">
        <button class="btn btn-sm btn-primary" onclick="addMapItemBall('${escAttr(map._dirName)}')">+ Item Ball</button>
        <button class="btn btn-sm btn-primary" onclick="addMapHiddenItem('${escAttr(map._dirName)}')">+ Hidden Item</button>
    </div>`;

    return `
        <div class="map-area-section">
            <div class="map-area-section-header">
                <h2><span class="section-icon">&#9830;</span> Items <span class="section-count">${totalItems}</span></h2>
                <span class="toggle-arrow">&#9660;</span>
            </div>
            <div class="map-area-section-body">${body}</div>
        </div>
    `;
}

// ── Connections Section (legacy, kept for compatibility) ──
function buildConnectionSection(map) {
    return ''; // Absorbed into buildNavigationSection
}

// ── Navigation Section (Routes + Doors) ──
function buildNavigationSection(map) {
    const conns = map.connections || [];
    const warps = map.warp_events || [];
    const dirLabels = { left: 'West', right: 'East', up: 'North', down: 'South', dive: 'Dive', emerge: 'Emerge' };

    let routesHtml = '';
    if (conns.length === 0) {
        routesHtml = `<div class="empty-state" style="padding:12px"><div class="empty-icon">&#8644;</div>No routes connected</div>`;
    } else {
        routesHtml = conns.map((c, i) => {
            const connName = (c.map || '').replace('MAP_', '').replace(/_/g, ' ');
            const dir = dirLabels[c.direction] || c.direction || '?';
            return `
                <div class="connection-row">
                    <span class="connection-dir ${c.direction || ''}">${dir}</span>
                    <span class="connection-map">${escHtml(c.map || '')}</span>
                    <span style="color:var(--text-dim);font-size:12px">${escHtml(connName)}</span>
                    <span style="color:var(--text-dim);font-size:11px">offset: ${c.offset || 0}</span>
                    <div style="display:flex;gap:4px">
                        <button class="btn btn-sm" onclick="editConnection('${escAttr(map._dirName)}', ${i})">Edit</button>
                        <button class="btn btn-sm btn-danger" onclick="deleteConnection('${escAttr(map._dirName)}', ${i})">Delete</button>
                    </div>
                </div>
            `;
        }).join('');
    }
    routesHtml += `<div style="text-align:right;margin-top:8px"><button class="btn btn-sm btn-primary" onclick="addConnection('${escAttr(map._dirName)}')">+ Add Route</button></div>`;

    let doorsHtml = '';
    if (warps.length === 0) {
        doorsHtml = `<div class="empty-state" style="padding:12px"><div class="empty-icon">&#128682;</div>No doors</div>`;
    } else {
        doorsHtml = warps.map((w, i) => {
            const destName = (w.dest_map || '').replace('MAP_', '').replace(/_/g, ' ');
            return `
                <div class="warp-row">
                    <div class="warp-icon">&#128682;</div>
                    <div class="warp-info">
                        <div class="warp-dest">${escHtml(destName)}</div>
                        <div class="warp-detail">${escHtml(w.dest_map || '')} &middot; Warp #${w.dest_warp_id || '0'}</div>
                    </div>
                    <div class="warp-coords">(${w.x}, ${w.y})</div>
                    <div style="display:flex;gap:4px">
                        <button class="btn btn-sm" onclick="editWarp('${escAttr(map._dirName)}', ${i})">Edit</button>
                        <button class="btn btn-sm btn-danger" onclick="deleteWarp('${escAttr(map._dirName)}', ${i})">Delete</button>
                    </div>
                </div>
            `;
        }).join('');
    }
    doorsHtml += `<div style="text-align:right;margin-top:8px"><button class="btn btn-sm btn-primary" onclick="addWarp('${escAttr(map._dirName)}')">+ Add Door</button></div>`;

    return `
        <div class="map-area-section">
            <div class="map-area-section-header">
                <h2><span class="section-icon">&#8644;</span> Navigation <span class="section-count">${conns.length} routes, ${warps.length} doors</span></h2>
                <span class="toggle-arrow">&#9660;</span>
            </div>
            <div class="map-area-section-body">
                <div class="nav-subsection-label">Routes (connected areas)</div>
                ${routesHtml}
                <div class="nav-subsection-label">Doors (entrances &amp; exits)</div>
                ${doorsHtml}
            </div>
        </div>
    `;
}

// ── Map Properties Section ──
function buildPropertiesSection(map) {
    const opt = (arr, current, strip) => arr.map(v => `<option value="${v}" ${v === current ? 'selected' : ''}>${v.replace(strip, '')}</option>`).join('');
    const boolSel = (val) => `<option value="true" ${val ? 'selected' : ''}>Yes</option><option value="false" ${!val ? 'selected' : ''}>No</option>`;

    return `
        <div class="map-area-section">
            <div class="map-area-section-header">
                <h2><span class="section-icon">&#9881;</span> Properties</h2>
                <span class="toggle-arrow">&#9660;</span>
            </div>
            <div class="map-area-section-body">
                <div class="map-props-grid">
                    <div class="map-prop">
                        <label>Music ${map.music && map.music !== 'MUS_DUMMY' ? `<button class="btn btn-sm music-play-btn" onclick="playMapMusic('${escAttr(map.music)}')" style="margin-left:6px" title="Play">&#9654;</button>` : ''}</label>
                        ${makeDatalistHtml('mp-music', map.music || '', getUniqueMusicConstants(), 'style="font-family:monospace"')}
                    </div>
                    <div class="map-prop">
                        <label>Weather</label>
                        <select id="mp-weather">${opt(WEATHER_OPTIONS, map.weather, 'WEATHER_')}</select>
                    </div>
                    <div class="map-prop">
                        <label>Map Type</label>
                        <select id="mp-type">${opt(MAP_TYPES, map.map_type, 'MAP_TYPE_')}</select>
                    </div>
                    <div class="map-prop">
                        <label>Battle Scene</label>
                        <select id="mp-battle">${opt(BATTLE_SCENES, map.battle_scene, 'MAP_BATTLE_SCENE_')}</select>
                    </div>
                    <div class="map-prop">
                        <label>Allow Cycling</label>
                        <select id="mp-cycling">${boolSel(map.allow_cycling)}</select>
                    </div>
                    <div class="map-prop">
                        <label>Allow Running</label>
                        <select id="mp-running">${boolSel(map.allow_running)}</select>
                    </div>
                    <div class="map-prop">
                        <label>Allow Escaping</label>
                        <select id="mp-escaping">${boolSel(map.allow_escaping)}</select>
                    </div>
                    <div class="map-prop">
                        <label>Show Map Name</label>
                        <select id="mp-showname">${boolSel(map.show_map_name)}</select>
                    </div>
                    <div class="map-prop">
                        <label>Requires Flash</label>
                        <select id="mp-flash">${boolSel(map.requires_flash)}</select>
                    </div>
                </div>
                <div style="text-align:right;margin-top:16px">
                    <button class="btn btn-primary" onclick="saveMapProperties('${escAttr(map._dirName)}')">Save Properties</button>
                </div>
            </div>
        </div>
    `;
}

function saveMapProperties(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;

    map.music = $('#mp-music').value;
    map.weather = $('#mp-weather').value;
    map.map_type = $('#mp-type').value;
    map.battle_scene = $('#mp-battle').value;
    map.allow_cycling = $('#mp-cycling').value === 'true';
    map.allow_running = $('#mp-running').value === 'true';
    map.allow_escaping = $('#mp-escaping').value === 'true';
    map.show_map_name = $('#mp-showname').value === 'true';
    map.requires_flash = $('#mp-flash').value === 'true';

    const serialized = { ...map };
    delete serialized._dirName;
    markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
    toast('Map properties saved (auto-saved)');
    renderMapDetail(dirName);
}

// ── Edit Encounters Modal (inline in detail view) ──
function editMapEncounters(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const enc = getMapEncounters(map);
    if (!enc) return;

    const fieldTypes = ['land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'];
    let sectionsHtml = '';
    for (const type of fieldTypes) {
        if (!enc[type]) continue;
        sectionsHtml += `
            <div style="margin-bottom:16px">
                <h3 style="font-size:14px;margin-bottom:8px">${ENC_LABELS[type]}
                    <span style="font-weight:normal;font-size:12px;color:var(--text-dim)">Rate:</span>
                    <input type="number" class="enc-rate" data-type="${type}" value="${enc[type].encounter_rate}" min="0" max="100" style="width:60px;background:var(--bg-input);border:1px solid var(--border);border-radius:4px;color:var(--text);padding:3px 6px;font-size:12px">%
                </h3>
                <table class="enc-edit-table">
                    <thead><tr><th>Species</th><th>Min Lv</th><th>Max Lv</th></tr></thead>
                    <tbody>
                        ${enc[type].mons.map((m, i) => `
                            <tr>
                                <td><input type="text" class="enc-species" data-type="${type}" data-idx="${i}" value="${escAttr(m.species)}" list="dl-map-enc-species"></td>
                                <td><input type="number" class="enc-min-lv" data-type="${type}" data-idx="${i}" value="${m.min_level}" min="1" max="100"></td>
                                <td><input type="number" class="enc-max-lv" data-type="${type}" data-idx="${i}" value="${m.max_level}" min="1" max="100"></td>
                            </tr>
                        `).join('')}
                    </tbody>
                </table>
            </div>
        `;
    }

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="max-width:700px">
            <div class="modal-header">
                <h2>Edit Encounters: ${getMapDisplayName(map)}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body" style="max-height:70vh;overflow-y:auto">
                ${sectionsHtml || '<p style="color:var(--text-dim)">No encounter types defined.</p>'}
                <datalist id="dl-map-enc-species">${getUniqueSpeciesIds().map(s => `<option value="${escAttr(s)}">`).join('')}</datalist>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-enc-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-enc-btn').addEventListener('click', () => {
        for (const type of fieldTypes) {
            if (!enc[type]) continue;
            const rateEl = overlay.querySelector(`.enc-rate[data-type="${type}"]`);
            if (rateEl) enc[type].encounter_rate = parseInt(rateEl.value);
            enc[type].mons.forEach((m, i) => {
                const sp = overlay.querySelector(`.enc-species[data-type="${type}"][data-idx="${i}"]`);
                const minLv = overlay.querySelector(`.enc-min-lv[data-type="${type}"][data-idx="${i}"]`);
                const maxLv = overlay.querySelector(`.enc-max-lv[data-type="${type}"][data-idx="${i}"]`);
                if (sp) m.species = sp.value;
                if (minLv) m.min_level = parseInt(minLv.value);
                if (maxLv) m.max_level = parseInt(maxLv.value);
            });
        }
        markChanged('src/data/wild_encounters.json', JSON.stringify(state.encounters, null, 2));
        toast('Encounters updated (auto-saved)');
        overlay.remove();
        renderMapDetail(dirName);
    });
}

// ── Edit Trainer Event Modal ──
function editMapTrainer(dirName, trainerIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const trainers = getMapTrainers(map);
    const trainer = trainers[trainerIdx];
    if (!trainer) return;
    // Find the actual index in object_events
    const allEvents = map.object_events || [];
    const realIdx = allEvents.indexOf(trainer);

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Trainer Event</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div style="display:flex;align-items:center;gap:12px;margin-bottom:16px;padding:12px;background:var(--bg);border-radius:6px;border:1px solid var(--border)">
                    ${getSpriteHtml(trainer.graphics_id, 48)}
                    <div>
                        <div style="font-size:13px;font-weight:600">${escHtml((trainer.graphics_id || '').replace('OBJ_EVENT_GFX_', '').replace(/_/g, ' '))}</div>
                        <div style="font-size:11px;color:var(--text-dim)">${escHtml(trainer.script || '')}</div>
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Graphics ID (Sprite)</label>
                        ${makeDatalistHtml('te-gfx', trainer.graphics_id || '', getUniqueGraphicsIds(), 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Script</label>
                        <input type="text" id="te-script" value="${escAttr(trainer.script || '')}" style="font-family:monospace;font-size:12px">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>X</label>
                        <input type="number" id="te-x" value="${trainer.x || 0}">
                    </div>
                    <div class="form-group">
                        <label>Y</label>
                        <input type="number" id="te-y" value="${trainer.y || 0}">
                    </div>
                    <div class="form-group">
                        <label>Elevation</label>
                        <input type="number" id="te-elev" value="${trainer.elevation || 0}">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Movement Type</label>
                        ${makeDatalistHtml('te-move', trainer.movement_type || '', getUniqueMovementTypes(), 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Trainer Sight Range</label>
                        <input type="number" id="te-sight" value="${escAttr(trainer.trainer_sight_or_berry_tree_id || '0')}" min="0" max="20">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Trainer Type</label>
                        ${makeSelectHtml('te-ttype', trainer.trainer_type || '', TRAINER_TYPES_LIST, 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Flag</label>
                        <input type="text" id="te-flag" value="${escAttr(trainer.flag || '0')}" style="font-family:monospace;font-size:12px">
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-te-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-te-btn').addEventListener('click', () => {
        const evt = allEvents[realIdx];
        evt.graphics_id = $('#te-gfx').value;
        evt.script = $('#te-script').value;
        evt.x = parseInt($('#te-x').value);
        evt.y = parseInt($('#te-y').value);
        evt.elevation = parseInt($('#te-elev').value);
        evt.movement_type = $('#te-move').value;
        evt.trainer_sight_or_berry_tree_id = $('#te-sight').value;
        evt.trainer_type = $('#te-ttype').value;
        evt.flag = $('#te-flag').value;

        const serialized = { ...map };
        delete serialized._dirName;
        markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
        toast('Trainer event updated (auto-saved)');
        overlay.remove();
        renderMapDetail(dirName);
    });
}

// ── Add Trainer to Map ──
function addMapTrainer(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!map.object_events) map.object_events = [];

    const newTrainer = {
        graphics_id: 'OBJ_EVENT_GFX_YOUNGSTER',
        x: 0,
        y: 0,
        elevation: 3,
        movement_type: 'MOVEMENT_TYPE_FACE_DOWN',
        movement_range_x: 0,
        movement_range_y: 0,
        trainer_type: 'TRAINER_TYPE_NORMAL',
        trainer_sight_or_berry_tree_id: '3',
        script: `${dirName}_EventScript_NewTrainer`,
        flag: '0'
    };

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Add Trainer Event</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-row">
                    <div class="form-group">
                        <label>Graphics ID (Sprite)</label>
                        ${makeDatalistHtml('at-gfx', newTrainer.graphics_id, getUniqueGraphicsIds(), 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Script</label>
                        <input type="text" id="at-script" value="${escAttr(newTrainer.script)}" style="font-family:monospace;font-size:12px">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>X</label>
                        <input type="number" id="at-x" value="${newTrainer.x}">
                    </div>
                    <div class="form-group">
                        <label>Y</label>
                        <input type="number" id="at-y" value="${newTrainer.y}">
                    </div>
                    <div class="form-group">
                        <label>Elevation</label>
                        <input type="number" id="at-elev" value="${newTrainer.elevation}">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Movement Type</label>
                        ${makeDatalistHtml('at-move', newTrainer.movement_type, getUniqueMovementTypes(), 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Trainer Sight Range</label>
                        <input type="number" id="at-sight" value="${newTrainer.trainer_sight_or_berry_tree_id}" min="0" max="20">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Trainer Type</label>
                        ${makeSelectHtml('at-ttype', newTrainer.trainer_type, TRAINER_TYPES_LIST, 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Flag</label>
                        <input type="text" id="at-flag" value="${escAttr(newTrainer.flag)}" style="font-family:monospace;font-size:12px">
                    </div>
                </div>
                <div style="margin-top:16px;padding:12px;background:var(--bg);border-radius:6px;border:1px solid var(--border)">
                    <div style="font-size:12px;color:var(--text-dim);margin-bottom:8px">Also create trainer party data?</div>
                    <label style="display:flex;align-items:center;gap:8px;font-size:13px;cursor:pointer">
                        <input type="checkbox" id="at-create-party" checked> Create matching trainer party entry
                    </label>
                    <div class="form-row" style="margin-top:8px">
                        <div class="form-group">
                            <label>Trainer ID</label>
                            <input type="text" id="at-trainer-id" value="" placeholder="TRAINER_NEW_TRAINER" style="font-family:monospace;font-size:12px">
                        </div>
                        <div class="form-group">
                            <label>Trainer Name</label>
                            <input type="text" id="at-trainer-name" value="" placeholder="NEW TRAINER">
                        </div>
                    </div>
                    <div class="form-row">
                        <div class="form-group">
                            <label>Class</label>
                            ${makeDatalistHtml('at-trainer-class', 'Youngster', getUniqueTrainerClasses(), 'placeholder="e.g. Youngster, Hiker"')}
                        </div>
                        <div class="form-group">
                            <label>Pic</label>
                            ${makeDatalistHtml('at-trainer-pic', 'Youngster', getUniqueTrainerPics(), 'placeholder="e.g. Youngster"')}
                        </div>
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="add-trainer-btn">Add Trainer</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#add-trainer-btn').addEventListener('click', async () => {
        const evt = {
            graphics_id: $('#at-gfx').value,
            x: parseInt($('#at-x').value),
            y: parseInt($('#at-y').value),
            elevation: parseInt($('#at-elev').value),
            movement_type: $('#at-move').value,
            movement_range_x: 0,
            movement_range_y: 0,
            trainer_type: $('#at-ttype').value,
            trainer_sight_or_berry_tree_id: $('#at-sight').value,
            script: $('#at-script').value,
            flag: $('#at-flag').value
        };

        map.object_events.push(evt);

        const serialized = { ...map };
        delete serialized._dirName;
        markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');

        // Optionally create trainer party entry
        if ($('#at-create-party').checked) {
            const trainerId = $('#at-trainer-id').value.trim() || ('TRAINER_' + dirName.toUpperCase() + '_NEW');
            const trainerName = $('#at-trainer-name').value.trim() || 'NEW TRAINER';
            const trainerClass = $('#at-trainer-class').value.trim() || 'Youngster';
            const trainerPic = $('#at-trainer-pic').value.trim() || 'Youngster';

            // Load trainers if not already loaded
            try { await loadTrainers(); } catch {}
            if (state.trainers) {
                const newTrainerData = {
                    id: trainerId,
                    name: trainerName,
                    class: trainerClass,
                    pic: trainerPic,
                    gender: 'Male',
                    music: trainerClass,
                    double_battle: 'No',
                    ai: 'Check Bad Move / Try To Faint',
                    pokemon: [{ species: 'Zigzagoon', level: '5', moves: [] }]
                };
                state.trainers.push(newTrainerData);
                markChanged('src/data/trainers.party', serializeTrainers(state.trainers));
            }
        }

        toast('Trainer added (auto-saved)');
        overlay.remove();
        renderMapDetail(dirName);
    });
}

// ── Edit Trainer Party from Map ──
async function editTrainerPartyFromScript(dirName, scriptName) {
    try { await loadTrainers(); } catch {
        toast('Could not load trainer data', true);
        return;
    }

    let matchedTrainer = null;
    const scriptParts = scriptName.split('_EventScript_');
    if (scriptParts.length >= 2) {
        const trainerSuffix = scriptParts[scriptParts.length - 1];
        matchedTrainer = state.trainers.find(t =>
            t.id.toUpperCase().includes(trainerSuffix.toUpperCase())
        );
    }

    // Also try looking in the script file for the TRAINER_ constant
    if (!matchedTrainer) {
        try {
            const scriptText = await loadMapScript(dirName);
            const trainerMatch = scriptText.match(new RegExp(scriptName.replace(/[.*+?^${}()|[\]\\]/g, '\\$&') + '[\\s\\S]*?trainerbattle\\w*\\s+(TRAINER_\\w+)'));
            if (trainerMatch) {
                matchedTrainer = state.trainers.find(t => t.id === trainerMatch[1]);
            }
        } catch {}
    }

    if (matchedTrainer) {
        editTrainer(matchedTrainer.id);
    } else {
        toast('Could not match script to a trainer party entry. Try searching in the Trainers tab.', true);
    }
}

async function editTrainerPartyFromMap(dirName, trainerIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const trainers = getMapTrainers(map);
    const trainerEvt = trainers[trainerIdx];
    if (!trainerEvt) return;

    // Try to load trainers data
    try { await loadTrainers(); } catch {
        toast('Could not load trainer data', true);
        return;
    }

    // Try to find the matching trainer party by script name
    const scriptName = trainerEvt.script || '';
    // Common patterns: MapName_EventScript_TrainerName → TRAINER_TRAINERNAME
    // Try multiple heuristics to match
    let matchedTrainer = null;

    // 1. Try extracting trainer ID directly from script
    const scriptParts = scriptName.split('_EventScript_');
    if (scriptParts.length >= 2) {
        const trainerSuffix = scriptParts[scriptParts.length - 1];
        // Look for trainers whose ID contains this suffix
        matchedTrainer = state.trainers.find(t =>
            t.id.toUpperCase().includes(trainerSuffix.toUpperCase())
        );
    }

    // 2. Try matching by map name prefix
    if (!matchedTrainer) {
        const candidates = state.trainers.filter(t =>
            t.id.toUpperCase().includes(dirName.toUpperCase().replace(/\s/g, '_'))
        );
        if (candidates.length === 1) matchedTrainer = candidates[0];
    }

    if (matchedTrainer) {
        // Open the trainer party editor
        editTrainer(matchedTrainer.id);
    } else {
        // Show a picker modal to find or create the trainer
        showTrainerMatchModal(dirName, trainerEvt, trainerIdx);
    }
}

function showTrainerMatchModal(dirName, trainerEvt, trainerIdx) {
    const scriptName = trainerEvt.script || 'Unknown';
    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Find Trainer Party</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <p style="font-size:13px;color:var(--text-dim);margin-bottom:12px">
                    Could not automatically match the map event <code style="color:var(--cyan)">${escHtml(scriptName)}</code> to a trainer party entry.
                    Search for the trainer or create a new one.
                </p>
                <div class="search-bar" style="margin-bottom:12px">
                    <span class="search-icon">&#128269;</span>
                    <input type="text" placeholder="Search trainers by ID or name..." id="tm-search">
                </div>
                <div id="tm-results" style="max-height:300px;overflow-y:auto"></div>
                <div style="margin-top:12px;text-align:center">
                    <button class="btn btn-primary" id="tm-create-btn">Create New Trainer Party</button>
                </div>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    function renderResults(search) {
        const filtered = (state.trainers || []).filter(t =>
            !search ||
            t.id.toLowerCase().includes(search) ||
            (t.name || '').toLowerCase().includes(search)
        ).slice(0, 20);

        const resultsEl = overlay.querySelector('#tm-results');
        resultsEl.innerHTML = filtered.map(t => `
            <div class="area-trainer-row" style="cursor:pointer" onclick="document.querySelector('.modal-overlay').remove(); editTrainer('${escAttr(t.id)}')">
                <div class="area-trainer-icon">&#9876;</div>
                <div class="area-trainer-info">
                    <div class="area-trainer-name">${escHtml(t.name || '(unnamed)')}</div>
                    <div class="area-trainer-detail">${escHtml(t.id)} &middot; ${t.pokemon.length} Pokemon</div>
                </div>
            </div>
        `).join('');
    }

    renderResults('');
    overlay.querySelector('#tm-search').addEventListener('input', e => renderResults(e.target.value.toLowerCase()));

    overlay.querySelector('#tm-create-btn').addEventListener('click', () => {
        overlay.remove();
        // Derive a trainer ID from the script name
        const parts = scriptName.split('_EventScript_');
        const suffix = parts.length >= 2 ? parts[parts.length - 1] : 'NewTrainer';
        addTrainer();
        // Pre-fill the ID field after the modal opens
        setTimeout(() => {
            const idField = document.querySelector('#t-id');
            if (idField && idField.value.startsWith('TRAINER_NEW_')) {
                idField.value = 'TRAINER_' + suffix.toUpperCase();
            }
        }, 100);
    });
}

// ── Edit Item Ball Modal ──
function editMapItemBall(dirName, itemIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const itemBalls = getMapItemBalls(map);
    const item = itemBalls[itemIdx];
    if (!item) return;
    const allEvents = map.object_events || [];
    const realIdx = allEvents.indexOf(item);

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Item Ball</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-group">
                    <label>Item</label>
                    ${makeDatalistHtml('ib-item', item.trainer_sight_or_berry_tree_id || '', getUniqueItemIds(), 'style="font-family:monospace" placeholder="ITEM_RARE_CANDY"')}
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>X</label>
                        <input type="number" id="ib-x" value="${item.x || 0}">
                    </div>
                    <div class="form-group">
                        <label>Y</label>
                        <input type="number" id="ib-y" value="${item.y || 0}">
                    </div>
                    <div class="form-group">
                        <label>Elevation</label>
                        <input type="number" id="ib-elev" value="${item.elevation || 0}">
                    </div>
                </div>
                <div class="form-group">
                    <label>Flag</label>
                    <input type="text" id="ib-flag" value="${escAttr(item.flag || '')}" style="font-family:monospace;font-size:12px">
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-ib-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-ib-btn').addEventListener('click', () => {
        const evt = allEvents[realIdx];
        evt.trainer_sight_or_berry_tree_id = $('#ib-item').value;
        evt.x = parseInt($('#ib-x').value);
        evt.y = parseInt($('#ib-y').value);
        evt.elevation = parseInt($('#ib-elev').value);
        evt.flag = $('#ib-flag').value;

        const serialized = { ...map };
        delete serialized._dirName;
        markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
        toast('Item ball updated (auto-saved)');
        overlay.remove();
        renderMapDetail(dirName);
    });
}

// ── Edit Hidden Item Modal ──
function editMapHiddenItem(dirName, hiddenIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const hiddenItems = getMapHiddenItems(map);
    const item = hiddenItems[hiddenIdx];
    if (!item) return;
    const allBg = map.bg_events || [];
    const realIdx = allBg.indexOf(item);

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Hidden Item</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-group">
                    <label>Item</label>
                    ${makeDatalistHtml('hi-item', item.item || '', getUniqueItemIds(), 'style="font-family:monospace" placeholder="ITEM_REVIVE"')}
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>X</label>
                        <input type="number" id="hi-x" value="${item.x || 0}">
                    </div>
                    <div class="form-group">
                        <label>Y</label>
                        <input type="number" id="hi-y" value="${item.y || 0}">
                    </div>
                    <div class="form-group">
                        <label>Elevation</label>
                        <input type="number" id="hi-elev" value="${item.elevation || 0}">
                    </div>
                </div>
                <div class="form-group">
                    <label>Flag</label>
                    <input type="text" id="hi-flag" value="${escAttr(item.flag || '')}" style="font-family:monospace;font-size:12px">
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-hi-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-hi-btn').addEventListener('click', () => {
        const evt = allBg[realIdx];
        evt.item = $('#hi-item').value;
        evt.x = parseInt($('#hi-x').value);
        evt.y = parseInt($('#hi-y').value);
        evt.elevation = parseInt($('#hi-elev').value);
        evt.flag = $('#hi-flag').value;

        const serialized = { ...map };
        delete serialized._dirName;
        markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
        toast('Hidden item updated (auto-saved)');
        overlay.remove();
        renderMapDetail(dirName);
    });
}

// ─── Config ─────────────────────────────────────────────────────────────────
async function renderConfig() {
    const config = await loadConfig();
    const search = state.search.toLowerCase();

    const byFile = {};
    for (const s of config) {
        if (!byFile[s.file]) byFile[s.file] = [];
        byFile[s.file].push(s);
    }

    const files = Object.keys(byFile).sort();
    const activeFile = state.configFilter === 'all' ? null : state.configFilter;

    content.innerHTML = `
        <div class="page-header">
            <h1>Config Settings</h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search settings..." id="config-search" value="${state.search}">
        </div>
        <div class="filter-row">
            <span class="filter-chip ${!activeFile ? 'active' : ''}" onclick="state.configFilter='all'; renderConfig()">All (${config.length})</span>
            ${files.map(f => `<span class="filter-chip ${activeFile === f ? 'active' : ''}" onclick="state.configFilter='${escAttr(f)}'; renderConfig()">${f.replace('.h', '')} (${byFile[f].length})</span>`).join('')}
        </div>
        <div id="config-groups"></div>
    `;

    const container = $('#config-groups');
    const filesToShow = activeFile ? [activeFile] : files;

    for (const file of filesToShow) {
        const settings = byFile[file].filter(s =>
            !search ||
            s.name.toLowerCase().includes(search) ||
            s.comment.toLowerCase().includes(search) ||
            s.value.toLowerCase().includes(search)
        );
        if (settings.length === 0) continue;

        let rows = '';
        for (const s of settings) {
            const isBool = s.value === 'TRUE' || s.value === 'FALSE';
            const isGenSetting = /^GEN_/.test(s.value) || s.value === 'GEN_LATEST';

            let valueHtml;
            if (isBool) {
                valueHtml = `<select onchange="updateConfig('${escAttr(s.file)}','${escAttr(s.name)}',this.value)">
                    <option value="TRUE" ${s.value === 'TRUE' ? 'selected' : ''}>TRUE</option>
                    <option value="FALSE" ${s.value === 'FALSE' ? 'selected' : ''}>FALSE</option>
                </select>`;
            } else if (isGenSetting) {
                valueHtml = `<select onchange="updateConfig('${escAttr(s.file)}','${escAttr(s.name)}',this.value)">
                    ${['GEN_LATEST','GEN_1','GEN_2','GEN_3','GEN_4','GEN_5','GEN_6','GEN_7','GEN_8','GEN_9'].map(g =>
                        `<option value="${g}" ${s.value === g ? 'selected' : ''}>${g}</option>`
                    ).join('')}
                </select>`;
            } else {
                valueHtml = `<input type="text" value="${escAttr(s.value)}" onchange="updateConfig('${escAttr(s.file)}','${escAttr(s.name)}',this.value)" style="width:120px">`;
            }

            rows += `
                <div class="config-row">
                    <span class="config-name">${s.name}</span>
                    <span class="config-value">${valueHtml}</span>
                    <span class="config-comment" title="${escAttr(s.comment)}">${escHtml(s.comment)}</span>
                </div>
            `;
        }

        container.innerHTML += `
            <div class="config-group">
                <div class="config-group-header" onclick="this.nextElementSibling.style.display = this.nextElementSibling.style.display === 'none' ? '' : 'none'">
                    <span>${file}</span>
                    <span class="count">${settings.length} settings</span>
                </div>
                <div>${rows}</div>
            </div>
        `;
    }

    $('#config-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        await renderConfig();
        const el = $('#config-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

function updateConfig(file, name, value) {
    // Update in-memory state
    if (state.config) {
        const setting = state.config.find(s => s.file === file && s.name === name);
        if (setting) setting.value = value;
    }

    // Read the original content and apply the change
    const filePath = `include/config/${file}`;
    let fileContent = pendingChanges[filePath] || originalContent[filePath];
    if (!fileContent) {
        toast('Config file not loaded yet', true);
        return;
    }
    const regex = new RegExp(`^(#define\\s+${name}\\s+)(.+?)(\\s*(?:\\/\\/.*)?)$`, 'm');
    fileContent = fileContent.replace(regex, `$1${value}$3`);
    markChanged(filePath, fileContent);
    toast(`Updated ${name} (auto-saved)`);
}

// ─── PR Submission ──────────────────────────────────────────────────────────
function openPRModal() {
    if (!ghToken) {
        openAuthModal();
        return;
    }
    if (!editorBranch) {
        toast('No changes to submit — make an edit first', true);
        return;
    }

    const changedFiles = Object.keys(pendingChanges);
    const fileList = changedFiles.length > 0
        ? changedFiles.map(f => `<li>${escHtml(f)}</li>`).join('')
        : '<li style="color:var(--text-dim)">All changes already committed to branch</li>';

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="width:550px">
            <div class="modal-header">
                <h2>Submit Pull Request</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <p style="font-size:13px;color:var(--text-dim);margin-bottom:12px">
                    Your changes on <code style="font-size:12px;background:var(--bg-input);padding:2px 6px;border-radius:3px">${escHtml(editorBranch)}</code> will be submitted as a Pull Request for review.
                </p>
                <div style="font-size:12px;color:var(--text-dim);margin-bottom:12px">Changed files:</div>
                <ul class="pr-changes-list">
                    ${fileList}
                </ul>
                <div class="form-group">
                    <label>PR Title</label>
                    <input type="text" id="pr-title" value="Update game data via web editor" placeholder="Brief description of changes">
                </div>
                <div class="form-group">
                    <label>Description (optional)</label>
                    <textarea id="pr-desc" rows="3" placeholder="Describe what you changed and why..."></textarea>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-success" id="submit-pr-btn">Create Pull Request</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#submit-pr-btn').addEventListener('click', async () => {
        const title = $('#pr-title').value.trim() || 'Update game data via web editor';
        const desc = $('#pr-desc').value.trim();
        const btn = $('#submit-pr-btn');
        btn.disabled = true;
        btn.textContent = 'Creating PR...';

        try {
            const prUrl = await createPullRequest(title, desc);
            overlay.remove();
            // Clear branch + pending state (next edit starts a fresh branch)
            clearEditorBranch();
            // Show success with link
            showPRSuccess(prUrl);
        } catch (e) {
            toast('Error creating PR: ' + e.message, true);
            btn.disabled = false;
            btn.textContent = 'Create Pull Request';
        }
    });
}

async function createPullRequest(title, description) {
    if (!editorBranch) throw new Error('No changes have been committed yet.');

    // All changes are already committed to the editor branch.
    // Just create the PR.
    const body = description
        ? `${description}\n\n---\n*Submitted via the Brazilianite web editor*`
        : '*Submitted via the Brazilianite web editor*';

    const pr = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/pulls`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
            title,
            body,
            head: editorBranch,
            base: BRANCH
        })
    });

    return pr.html_url;
}

function showPRSuccess(prUrl) {
    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="width:450px">
            <div class="modal-header">
                <h2 style="color:var(--green)">PR Created!</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body" style="text-align:center;padding:32px">
                <div style="font-size:48px;margin-bottom:16px">&#10003;</div>
                <p style="font-size:14px;margin-bottom:16px">Your Pull Request has been created successfully!</p>
                <a href="${escAttr(prUrl)}" target="_blank" class="btn btn-primary" style="text-decoration:none">
                    View Pull Request
                </a>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });
}

// ─── Warp Section ───────────────────────────────────────────────────────────
function buildWarpSection(map) {
    return ''; // Absorbed into buildNavigationSection
}

function editWarp(dirName, warpIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const warps = map.warp_events || [];
    const warp = warps[warpIdx];
    if (!warp) return;

    // Collect all map IDs for destination dropdown
    const mapIds = (state.maps || []).map(m => m.id).filter(Boolean).sort();

    // Build reference list of existing warps and objects for coordinate context
    const refPoints = [];
    (map.warp_events || []).forEach((w, i) => {
        if (i !== warpIdx) refPoints.push({ type: 'warp', x: w.x, y: w.y, label: `Warp #${i} → ${(w.dest_map || '').replace('MAP_', '')}` });
    });
    (map.object_events || []).forEach(o => {
        const gfx = (o.graphics_id || '').replace('OBJ_EVENT_GFX_', '').replace(/_/g, ' ');
        refPoints.push({ type: 'npc', x: o.x, y: o.y, label: gfx });
    });
    const refHtml = refPoints.length > 0 ? `
        <div style="margin-top:12px;font-size:11px;color:var(--text-dim)">
            <div style="font-weight:600;margin-bottom:4px">Reference points (click to use coordinates):</div>
            <div style="max-height:100px;overflow-y:auto;display:flex;flex-wrap:wrap;gap:4px">
                ${refPoints.map(p => `<span class="ref-point-chip" onclick="document.getElementById('warp-x').value=${p.x};document.getElementById('warp-y').value=${p.y}" style="cursor:pointer;padding:2px 8px;background:var(--bg);border:1px solid var(--border);border-radius:10px;font-size:11px" title="${escAttr(p.label)}">${p.type === 'warp' ? '&#128682;' : '&#9786;'} (${p.x},${p.y}) ${escHtml(p.label.substring(0, 20))}</span>`).join('')}
            </div>
        </div>
    ` : '';

    const fullUrl = getFullPreviewUrl(dirName);
    const thumbUrl = getPreviewUrl(dirName);

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="max-width:700px">
            <div class="modal-header">
                <h2>Edit Warp</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-group">
                    <label>Destination Map</label>
                    ${makeDatalistHtml('warp-dest', warp.dest_map || '', mapIds, 'style="font-family:monospace;font-size:12px"')}
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Dest Warp ID</label>
                        <input type="number" id="warp-dest-id" value="${escAttr(warp.dest_warp_id || '0')}" min="0">
                    </div>
                    <div class="form-group">
                        <label>X</label>
                        <input type="number" id="warp-x" value="${warp.x || 0}">
                    </div>
                    <div class="form-group">
                        <label>Y</label>
                        <input type="number" id="warp-y" value="${warp.y || 0}">
                    </div>
                    <div class="form-group">
                        <label>Elevation</label>
                        <input type="number" id="warp-elev" value="${warp.elevation || 0}">
                    </div>
                </div>
                <div style="margin-top:12px">
                    <label style="font-size:12px;font-weight:600">Click map to pick warp position (each tile = 16px):</label>
                    <div id="warp-map-picker" style="position:relative;margin-top:6px;overflow:auto;max-height:300px;border:1px solid var(--border);border-radius:6px;cursor:crosshair">
                        <img id="warp-map-img" src="${fullUrl}" onerror="this.src='${thumbUrl}';this.onerror=null;"
                            style="image-rendering:pixelated;max-width:none;display:block" alt="Map preview">
                        <div id="warp-marker" style="position:absolute;width:16px;height:16px;border:2px solid red;background:rgba(255,0,0,0.3);pointer-events:none;display:none"></div>
                    </div>
                    <div id="warp-pick-info" style="font-size:11px;color:var(--text-dim);margin-top:4px"></div>
                </div>
                ${refHtml}
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-warp-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    // Setup map click-to-pick
    const mapImg = overlay.querySelector('#warp-map-img');
    const marker = overlay.querySelector('#warp-marker');
    const pickInfo = overlay.querySelector('#warp-pick-info');

    function updateMarker() {
        const x = parseInt(overlay.querySelector('#warp-x').value) || 0;
        const y = parseInt(overlay.querySelector('#warp-y').value) || 0;
        if (mapImg.naturalWidth > 0) {
            marker.style.display = 'block';
            marker.style.left = (x * 16) + 'px';
            marker.style.top = (y * 16) + 'px';
        }
    }

    mapImg.addEventListener('load', updateMarker);
    overlay.querySelector('#warp-x').addEventListener('input', updateMarker);
    overlay.querySelector('#warp-y').addEventListener('input', updateMarker);

    overlay.querySelector('#warp-map-picker').addEventListener('click', (e) => {
        if (e.target === marker) return;
        const rect = mapImg.getBoundingClientRect();
        const scrollContainer = overlay.querySelector('#warp-map-picker');
        const px = e.clientX - rect.left;
        const py = e.clientY - rect.top;
        // Calculate scale (image may be rendered at different size than natural)
        const scaleX = mapImg.naturalWidth / mapImg.offsetWidth;
        const scaleY = mapImg.naturalHeight / mapImg.offsetHeight;
        const tileX = Math.floor((px * scaleX) / 16);
        const tileY = Math.floor((py * scaleY) / 16);
        overlay.querySelector('#warp-x').value = tileX;
        overlay.querySelector('#warp-y').value = tileY;
        pickInfo.textContent = `Selected tile: (${tileX}, ${tileY})`;
        updateMarker();
    });

    overlay.querySelector('#save-warp-btn').addEventListener('click', () => {
        warp.dest_map = overlay.querySelector('#warp-dest').value;
        warp.dest_warp_id = overlay.querySelector('#warp-dest-id').value;
        warp.x = parseInt(overlay.querySelector('#warp-x').value);
        warp.y = parseInt(overlay.querySelector('#warp-y').value);
        warp.elevation = parseInt(overlay.querySelector('#warp-elev').value);

        const serialized = { ...map };
        delete serialized._dirName;
        markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
        toast('Warp updated (auto-saved)');
        overlay.remove();
        renderMapDetail(dirName);
    });
}

// ─── Object Scripts Section (legacy, kept for compatibility) ─────────────────
function buildObjectScriptsSection(map, allTrainers) {
    return ''; // Absorbed into buildUnifiedNPCSection
}

// ─── Unified NPC Section (Area > NPC > Events hierarchy) ────────────────────
function buildUnifiedNPCSection(map, allTrainers, scriptText) {
    const dirName = map._dirName;
    const trainerSet = new Set(allTrainers || []);
    // All NPCs = every object_event that isn't an item ball or berry tree
    const allNPCs = (map.object_events || []).filter(e =>
        !(e.graphics_id || '').includes('ITEM_BALL') &&
        !(e.graphics_id || '').includes('BERRY_TREE')
    );

    // Parse all dialogue blocks from script for inline preview
    const dialogueBlocks = parseDialogueBlocksAll(scriptText, dirName);

    // Helper: find dialogue text for an NPC's script
    function getNPCDialogue(evt) {
        if (!evt.script || evt.script === '0x0') return [];
        const scriptLabel = evt.script + '::';
        const labelIdx = scriptText.indexOf(scriptLabel);
        if (labelIdx < 0) return [];
        const afterLabel = scriptText.substring(labelIdx);
        const nextLabelMatch = afterLabel.substring(scriptLabel.length).match(/\n\S+::/);
        const scriptBlock = nextLabelMatch ? afterLabel.substring(0, scriptLabel.length + nextLabelMatch.index) : afterLabel;
        // Find text labels referenced in this script block
        const textRefs = [];
        const refRegex = /(?:msgbox|trainerbattle\w*|message|pokenavcall)\s+(?:TRAINER_\w+,\s*)?(\w+_Text_\w+)/g;
        let refMatch;
        while ((refMatch = refRegex.exec(scriptBlock)) !== null) {
            textRefs.push(refMatch[1]);
        }
        // Also check goto/call targets
        const gotoRegex = /(?:goto|call)\s+(\w+EventScript\w+)/g;
        while ((refMatch = gotoRegex.exec(scriptBlock)) !== null) {
            const target = refMatch[1] + '::';
            const tidx = scriptText.indexOf(target);
            if (tidx >= 0) {
                const tBlock = scriptText.substring(tidx);
                const tNext = tBlock.substring(target.length).match(/\n\S+::/);
                const tContent = tNext ? tBlock.substring(0, target.length + tNext.index) : tBlock;
                const innerRefRegex = /(?:msgbox|trainerbattle\w*|message|pokenavcall)\s+(?:TRAINER_\w+,\s*)?(\w+_Text_\w+)/g;
                let rm;
                while ((rm = innerRefRegex.exec(tContent)) !== null) {
                    textRefs.push(rm[1]);
                }
            }
        }
        return dialogueBlocks.filter(b => textRefs.includes(b.label));
    }

    let body = '';
    if (allNPCs.length === 0) {
        body = `<div class="empty-state"><div class="empty-icon">&#9786;</div>No NPCs in this area</div>`;
    } else {
        body = allNPCs.map((evt) => {
            const realIdx = (map.object_events || []).indexOf(evt);
            const gfx = (evt.graphics_id || '').replace('OBJ_EVENT_GFX_', '').replace(/_/g, ' ');
            const isTrainer = trainerSet.has(evt);
            const isScriptTrainer = isTrainer && (evt.trainer_type === 'TRAINER_TYPE_NONE' || !evt.trainer_type);
            const hasFlag = evt.flag && evt.flag !== '0';
            const movement = (evt.movement_type || '').replace('MOVEMENT_TYPE_', '').replace(/_/g, ' ').toLowerCase();
            const npcDialogue = getNPCDialogue(evt);

            // Readable name from script label
            let npcName = gfx;
            if (evt.script && evt.script !== '0x0') {
                const parts = evt.script.split('_EventScript_');
                if (parts.length >= 2) npcName = parts[parts.length - 1].replace(/_/g, ' ');
            }

            // Badges
            let badges = '';
            if (isTrainer && !isScriptTrainer) badges += `<span class="npc-badge npc-badge-trainer">Trainer</span>`;
            if (isScriptTrainer) badges += `<span class="npc-badge npc-badge-script">Script Battle</span>`;
            if (hasFlag) badges += `<span class="npc-badge npc-badge-hidden">Conditional</span>`;

            // Inline dialogue preview (first block only)
            let dialogueHtml = '';
            if (npcDialogue.length > 0) {
                const firstText = npcDialogue[0].text
                    .replace(/\\n/g, '\n').replace(/\\p/g, '\n\n').replace(/\\l/g, '\n').replace(/\$$/g, '');
                const truncated = firstText.length > 200 ? firstText.substring(0, 200) + '...' : firstText;
                dialogueHtml = `
                    <div class="npc-event-group">
                        <div class="npc-event-label">Dialogue${npcDialogue.length > 1 ? ` (${npcDialogue.length} blocks)` : ''}</div>
                        <div class="npc-dialogue-preview">${escHtml(truncated)}</div>
                    </div>
                `;
            }

            // Trainer-specific info
            let trainerHtml = '';
            if (isTrainer) {
                const sight = evt.trainer_sight_or_berry_tree_id || '0';
                trainerHtml = `
                    <div class="npc-event-group">
                        <div class="npc-event-label">Battle Info</div>
                        <div style="font-size:12px;color:var(--text-dim)">
                            ${isScriptTrainer ? 'Triggered via script' : `Sight range: ${sight} tiles`}
                            &middot; ${(evt.trainer_type || 'TRAINER_TYPE_NONE').replace('TRAINER_TYPE_', '')}
                        </div>
                    </div>
                `;
            }

            // Script + movement info
            let scriptHtml = '';
            if (evt.script && evt.script !== '0x0') {
                scriptHtml = `
                    <div class="npc-event-group">
                        <div class="npc-event-label">Script</div>
                        <div style="font-size:12px;font-family:monospace;color:var(--cyan)">${escHtml(evt.script)}</div>
                    </div>
                `;
            }

            let movementHtml = '';
            if (movement && movement !== 'none') {
                movementHtml = `
                    <div class="npc-event-group">
                        <div class="npc-event-label">Movement</div>
                        <div style="font-size:12px;color:var(--text-dim)">${escHtml(movement)}${evt.movement_range_x || evt.movement_range_y ? ` (range: ${evt.movement_range_x || 0}x${evt.movement_range_y || 0})` : ''}</div>
                    </div>
                `;
            }

            return `
                <div class="npc-card">
                    <div class="npc-card-header">
                        ${getSpriteHtml(evt.graphics_id, 36)}
                        <div class="npc-card-info">
                            <div class="npc-card-name">${escHtml(npcName)}</div>
                            <div class="npc-card-detail">${escHtml(gfx)} &middot; (${evt.x}, ${evt.y})</div>
                        </div>
                        <div class="npc-card-badges">${badges}</div>
                        <span class="npc-card-expand">&#9654;</span>
                    </div>
                    <div class="npc-card-body">
                        <div class="npc-card-events">
                            ${dialogueHtml}
                            ${trainerHtml}
                            ${scriptHtml}
                            ${movementHtml}
                        </div>
                        <div class="npc-card-actions">
                            <button class="btn btn-sm" onclick="editObjectEvent('${escAttr(dirName)}', ${realIdx})">Edit NPC</button>
                            ${evt.script && evt.script !== '0x0' ? `<button class="btn btn-sm" onclick="editNPCDialogue('${escAttr(dirName)}', '${escAttr(evt.script)}')" title="Edit dialogue for this NPC">Dialogue</button>` : ''}
                            ${isTrainer ? `<button class="btn btn-sm" onclick="editTrainerPartyFromScript('${escAttr(dirName)}', '${escAttr(evt.script || '')}')" title="Edit trainer party">Party</button>` : ''}
                            <button class="btn btn-sm btn-danger" onclick="deleteObjectEvent('${escAttr(dirName)}', ${realIdx})">Delete</button>
                        </div>
                    </div>
                </div>
            `;
        }).join('');
    }

    body += `<div style="display:flex;gap:8px;justify-content:flex-end;margin-top:12px">
        <button class="btn btn-sm btn-primary" onclick="addObjectEvent('${escAttr(dirName)}')">+ Add NPC</button>
        <button class="btn btn-sm btn-primary" onclick="addMapTrainer('${escAttr(dirName)}')">+ Add Trainer</button>
    </div>`;

    return `
        <div class="map-area-section">
            <div class="map-area-section-header">
                <h2><span class="section-icon">&#9786;</span> People <span class="section-count">${allNPCs.length} NPCs, ${allTrainers.length} trainers</span></h2>
                <span class="toggle-arrow">&#9660;</span>
            </div>
            <div class="map-area-section-body">${body}</div>
        </div>
    `;
}

// ─── Dialogue / Text Section (legacy, kept for compatibility) ────────────────
function buildDialogueSection(map, scriptText) {
    return ''; // Dialogue is now shown inline within each NPC card in buildUnifiedNPCSection
}

async function editDialogue(dirName, label) {
    let scriptText = await loadMapScript(dirName);
    if (!scriptText) {
        toast('Could not load script file', true);
        return;
    }

    // Find the text block for this label
    const regex = new RegExp('(^' + label.replace(/[.*+?^${}()|[\]\\]/g, '\\$&') + '::?\\n)((?:\\s+\\.string\\s+"[^"]*"\\n?)+)', 'm');
    const match = scriptText.match(regex);
    if (!match) {
        toast('Could not find text label in script', true);
        return;
    }

    // Extract individual strings
    const strings = [];
    const strRegex = /\.string\s+"([^"]*)"/g;
    let sm;
    while ((sm = strRegex.exec(match[2])) !== null) {
        strings.push(sm[1]);
    }

    const labelShort = label.replace(dirName + '_Text_', '').replace(/_/g, ' ');

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="max-width:600px">
            <div class="modal-header">
                <h2>Edit Dialogue: ${escHtml(labelShort)}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div style="margin-bottom:8px;font-size:11px;color:var(--text-dim);font-family:monospace">${escHtml(label)}</div>
                <div style="margin-bottom:12px;font-size:12px;color:var(--text-dim)">
                    Format: Use <code>\\n</code> for newline within box, <code>\\p</code> for new textbox/page, <code>\\l</code> for scroll line, <code>$</code> at end to terminate.
                    Use <code>{PLAYER}</code> for player name.
                </div>
                <div id="dialogue-lines" style="display:flex;flex-direction:column;gap:6px">
                    ${strings.map((s, i) => `
                        <div class="dialogue-line-row" style="display:flex;gap:6px;align-items:center">
                            <span style="font-size:10px;color:var(--text-dim);min-width:20px">${i + 1}</span>
                            <input type="text" class="dialogue-line-input" value="${escAttr(s)}" style="flex:1;font-family:monospace;font-size:12px">
                            <button class="btn btn-sm btn-danger" onclick="this.closest('.dialogue-line-row').remove()" title="Remove line" style="padding:2px 6px">&#10005;</button>
                        </div>
                    `).join('')}
                </div>
                <div style="margin-top:8px;display:flex;gap:6px">
                    <button class="btn btn-sm" id="add-dialogue-line">+ Add Line</button>
                </div>
                <div style="margin-top:12px;padding:10px;background:var(--bg);border-radius:4px;border:1px solid var(--border)">
                    <div style="font-size:11px;font-weight:600;margin-bottom:4px;color:var(--text-dim)">Preview:</div>
                    <div id="dialogue-preview" style="font-size:13px;white-space:pre-wrap;line-height:1.5"></div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-dialogue-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    function updatePreview() {
        const inputs = overlay.querySelectorAll('.dialogue-line-input');
        const text = [...inputs].map(el => el.value).join('\n')
            .replace(/\\n/g, '\n').replace(/\\p/g, '\n\n').replace(/\\l/g, '\n').replace(/\$$/g, '');
        const preview = overlay.querySelector('#dialogue-preview');
        if (preview) preview.textContent = text;
    }

    // Wire up preview updates
    overlay.querySelectorAll('.dialogue-line-input').forEach(el => {
        el.addEventListener('input', updatePreview);
    });
    updatePreview();

    overlay.querySelector('#add-dialogue-line').addEventListener('click', () => {
        const container = overlay.querySelector('#dialogue-lines');
        const count = container.querySelectorAll('.dialogue-line-row').length;
        const row = document.createElement('div');
        row.className = 'dialogue-line-row';
        row.style.cssText = 'display:flex;gap:6px;align-items:center';
        row.innerHTML = `
            <span style="font-size:10px;color:var(--text-dim);min-width:20px">${count + 1}</span>
            <input type="text" class="dialogue-line-input" value="" style="flex:1;font-family:monospace;font-size:12px">
            <button class="btn btn-sm btn-danger" onclick="this.closest('.dialogue-line-row').remove()" title="Remove line" style="padding:2px 6px">&#10005;</button>
        `;
        container.appendChild(row);
        row.querySelector('input').addEventListener('input', updatePreview);
        row.querySelector('input').focus();
    });

    overlay.querySelector('#save-dialogue-btn').addEventListener('click', () => {
        const inputs = overlay.querySelectorAll('.dialogue-line-input');
        const newStrings = [...inputs].map(el => el.value);
        if (newStrings.length === 0) {
            toast('Dialogue must have at least one line', true);
            return;
        }

        // Rebuild the .string block
        const newBlock = match[1] + newStrings.map(s => `\t.string "${s}"`).join('\n') + '\n';
        scriptText = scriptText.replace(match[0], newBlock);

        // Save to pending changes and clear cache
        const filePath = `data/maps/${dirName}/scripts.inc`;
        markChanged(filePath, scriptText);
        scriptCache[dirName] = scriptText;

        toast('Dialogue updated (auto-saved)');
        overlay.remove();
        renderMapDetail(dirName);
    });
}

async function editNPCDialogue(dirName, scriptName) {
    let scriptText = await loadMapScript(dirName);
    if (!scriptText) {
        toast('Could not load script file for this map', true);
        return;
    }

    // Find the script label and extract all text labels it references
    const scriptLabel = scriptName + '::';
    const labelIdx = scriptText.indexOf(scriptLabel);
    if (labelIdx < 0) {
        toast('Script not found in this map\'s scripts.inc', true);
        return;
    }

    // Get the script block to find referenced text labels
    const afterLabel = scriptText.substring(labelIdx);
    const nextLabelMatch = afterLabel.substring(scriptLabel.length).match(/\n\S+::/);
    // Extend search through goto/call references - collect all related labels
    const allBlocks = parseDialogueBlocksAll(scriptText, dirName);

    // Find text labels referenced by this script (look for msgbox, trainerbattle, etc.)
    const scriptBlock = nextLabelMatch ? afterLabel.substring(0, scriptLabel.length + nextLabelMatch.index) : afterLabel;
    const textRefs = [];
    const refRegex = /(?:msgbox|trainerbattle\w*|message|pokenavcall)\s+(?:TRAINER_\w+,\s*)?(\w+_Text_\w+)/g;
    let refMatch;
    while ((refMatch = refRegex.exec(scriptBlock)) !== null) {
        textRefs.push(refMatch[1]);
    }

    // Also check goto/call targets for more text refs
    const gotoRegex = /(?:goto|call)\s+(\w+EventScript\w+)/g;
    while ((refMatch = gotoRegex.exec(scriptBlock)) !== null) {
        const target = refMatch[1] + '::';
        const tidx = scriptText.indexOf(target);
        if (tidx >= 0) {
            const tBlock = scriptText.substring(tidx);
            const tNext = tBlock.substring(target.length).match(/\n\S+::/);
            const tContent = tNext ? tBlock.substring(0, target.length + tNext.index) : tBlock;
            let rm;
            while ((rm = refRegex.exec(tContent)) !== null) {
                textRefs.push(rm[1]);
            }
        }
    }

    // Find matching dialogue blocks
    const relatedBlocks = allBlocks.filter(b => textRefs.includes(b.label));

    if (relatedBlocks.length === 0) {
        toast('No dialogue text labels found for this NPC script', true);
        return;
    }

    // Show a modal listing all related dialogue blocks with edit buttons
    const npcName = scriptName.split('_EventScript_').pop().replace(/_/g, ' ');
    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="max-width:650px">
            <div class="modal-header">
                <h2>Dialogue for: ${escHtml(npcName)}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body" style="padding:0">
                ${relatedBlocks.map(block => {
                    const labelShort = block.label.replace(dirName + '_Text_', '').replace(/_/g, ' ');
                    const displayText = block.text.replace(/\\n/g, '\n').replace(/\\p/g, '\n\n').replace(/\\l/g, '\n').replace(/\$$/g, '');
                    return `
                        <div style="padding:12px 16px;border-bottom:1px solid var(--border)">
                            <div style="display:flex;justify-content:space-between;align-items:center;margin-bottom:6px">
                                <span style="font-weight:600;font-size:12px;color:var(--text-dim)">${escHtml(labelShort)}</span>
                                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove();editDialogue('${escAttr(dirName)}', '${escAttr(block.label)}')">Edit</button>
                            </div>
                            <div style="font-size:13px;white-space:pre-wrap;line-height:1.5;background:var(--bg);padding:8px 10px;border-radius:4px;border:1px solid var(--border)">${escHtml(displayText)}</div>
                        </div>
                    `;
                }).join('')}
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Close</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });
}

function editObjectEvent(dirName, evtIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const evt = (map.object_events || [])[evtIdx];
    if (!evt) return;

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Object Event</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div style="display:flex;align-items:center;gap:12px;margin-bottom:16px;padding:12px;background:var(--bg);border-radius:6px;border:1px solid var(--border)">
                    ${getSpriteHtml(evt.graphics_id, 48)}
                    <div>
                        <div style="font-size:13px;font-weight:600">${escHtml((evt.graphics_id || '').replace('OBJ_EVENT_GFX_', '').replace(/_/g, ' '))}</div>
                        <div style="font-size:11px;color:var(--text-dim)">${escHtml(evt.script || '')}</div>
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Graphics ID (Sprite)</label>
                        ${makeDatalistHtml('oe-gfx', evt.graphics_id || '', getUniqueGraphicsIds(), 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Script</label>
                        <input type="text" id="oe-script" value="${escAttr(evt.script || '')}" style="font-family:monospace;font-size:12px">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>X</label>
                        <input type="number" id="oe-x" value="${evt.x || 0}">
                    </div>
                    <div class="form-group">
                        <label>Y</label>
                        <input type="number" id="oe-y" value="${evt.y || 0}">
                    </div>
                    <div class="form-group">
                        <label>Elevation</label>
                        <input type="number" id="oe-elev" value="${evt.elevation || 0}">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Movement Type</label>
                        ${makeDatalistHtml('oe-move', evt.movement_type || '', getUniqueMovementTypes(), 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Movement Range</label>
                        <div style="display:flex;gap:6px">
                            <input type="number" id="oe-mx" value="${evt.movement_range_x || 0}" min="0" style="width:60px" title="Range X">
                            <input type="number" id="oe-my" value="${evt.movement_range_y || 0}" min="0" style="width:60px" title="Range Y">
                        </div>
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Flag</label>
                        <input type="text" id="oe-flag" value="${escAttr(evt.flag || '0')}" style="font-family:monospace;font-size:12px">
                    </div>
                    <div class="form-group">
                        <label>Trainer Type</label>
                        ${makeSelectHtml('oe-ttype', evt.trainer_type || 'TRAINER_TYPE_NONE', TRAINER_TYPES_LIST, 'style="font-family:monospace;font-size:12px"')}
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-oe-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-oe-btn').addEventListener('click', () => {
        evt.graphics_id = $('#oe-gfx').value;
        evt.script = $('#oe-script').value;
        evt.x = parseInt($('#oe-x').value);
        evt.y = parseInt($('#oe-y').value);
        evt.elevation = parseInt($('#oe-elev').value);
        evt.movement_type = $('#oe-move').value;
        evt.movement_range_x = parseInt($('#oe-mx').value);
        evt.movement_range_y = parseInt($('#oe-my').value);
        evt.flag = $('#oe-flag').value;
        evt.trainer_type = $('#oe-ttype').value;

        const serialized = { ...map };
        delete serialized._dirName;
        markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
        toast('Object event updated (auto-saved)');
        overlay.remove();
        renderMapDetail(dirName);
    });
}

// ─── Delete Helpers ─────────────────────────────────────────────────────────
function saveMapAndRefresh(map, dirName, msg) {
    const serialized = { ...map };
    delete serialized._dirName;
    markChanged(`data/maps/${dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
    toast(msg);
    renderMapDetail(dirName);
}

function deleteMapTrainer(dirName, trainerIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const trainers = getMapTrainers(map);
    const trainer = trainers[trainerIdx];
    if (!trainer || !confirm('Delete this trainer event?')) return;
    const realIdx = (map.object_events || []).indexOf(trainer);
    if (realIdx >= 0) map.object_events.splice(realIdx, 1);
    saveMapAndRefresh(map, dirName, 'Trainer deleted (auto-saved)');
}

function deleteObjectEvent(dirName, evtIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!confirm('Delete this object event?')) return;
    (map.object_events || []).splice(evtIdx, 1);
    saveMapAndRefresh(map, dirName, 'Object event deleted (auto-saved)');
}

function addObjectEvent(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!map.object_events) map.object_events = [];

    const newEvt = {
        graphics_id: 'OBJ_EVENT_GFX_WOMAN_1',
        x: 0, y: 0, elevation: 3,
        movement_type: 'MOVEMENT_TYPE_FACE_DOWN',
        movement_range_x: 0, movement_range_y: 0,
        trainer_type: 'TRAINER_TYPE_NONE',
        trainer_sight_or_berry_tree_id: '0',
        script: `${dirName}_EventScript_NewNPC`,
        flag: '0'
    };
    map.object_events.push(newEvt);
    const idx = map.object_events.length - 1;
    saveMapAndRefresh(map, dirName, 'Object event added (auto-saved)');
    // Open the edit modal after refresh
    setTimeout(() => editObjectEvent(dirName, idx), 200);
}

function deleteMapItemBall(dirName, itemIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const itemBalls = getMapItemBalls(map);
    const item = itemBalls[itemIdx];
    if (!item || !confirm('Delete this item ball?')) return;
    const realIdx = (map.object_events || []).indexOf(item);
    if (realIdx >= 0) map.object_events.splice(realIdx, 1);
    saveMapAndRefresh(map, dirName, 'Item ball deleted (auto-saved)');
}

function addMapItemBall(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!map.object_events) map.object_events = [];

    const newItem = {
        graphics_id: 'OBJ_EVENT_GFX_ITEM_BALL',
        x: 0, y: 0, elevation: 3,
        movement_type: 'MOVEMENT_TYPE_NONE',
        movement_range_x: 0, movement_range_y: 0,
        trainer_type: 'TRAINER_TYPE_NONE',
        trainer_sight_or_berry_tree_id: 'ITEM_RARE_CANDY',
        script: `${dirName}_EventScript_ItemBall`,
        flag: 'FLAG_ITEM_' + dirName.toUpperCase() + '_NEW'
    };
    map.object_events.push(newItem);
    saveMapAndRefresh(map, dirName, 'Item ball added (auto-saved)');
    const itemBalls = getMapItemBalls(map);
    setTimeout(() => editMapItemBall(dirName, itemBalls.length - 1), 200);
}

function deleteMapHiddenItem(dirName, hiddenIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const hiddenItems = getMapHiddenItems(map);
    const item = hiddenItems[hiddenIdx];
    if (!item || !confirm('Delete this hidden item?')) return;
    const realIdx = (map.bg_events || []).indexOf(item);
    if (realIdx >= 0) map.bg_events.splice(realIdx, 1);
    saveMapAndRefresh(map, dirName, 'Hidden item deleted (auto-saved)');
}

function addMapHiddenItem(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!map.bg_events) map.bg_events = [];

    const newItem = {
        type: 'hidden_item',
        x: 0, y: 0, elevation: 0,
        item: 'ITEM_RARE_CANDY',
        flag: 'FLAG_HIDDEN_ITEM_' + dirName.toUpperCase() + '_NEW'
    };
    map.bg_events.push(newItem);
    saveMapAndRefresh(map, dirName, 'Hidden item added (auto-saved)');
    const hiddenItems = getMapHiddenItems(map);
    setTimeout(() => editMapHiddenItem(dirName, hiddenItems.length - 1), 200);
}

function deleteWarp(dirName, warpIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!confirm('Delete this warp?')) return;
    (map.warp_events || []).splice(warpIdx, 1);
    saveMapAndRefresh(map, dirName, 'Warp deleted (auto-saved)');
}

function addWarp(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!map.warp_events) map.warp_events = [];

    map.warp_events.push({
        x: 0, y: 0, elevation: 0,
        dest_map: 'MAP_LITTLEROOT_TOWN',
        dest_warp_id: '0'
    });
    saveMapAndRefresh(map, dirName, 'Warp added (auto-saved)');
    setTimeout(() => editWarp(dirName, map.warp_events.length - 1), 200);
}

// ─── Connection Edit/Add/Delete ─────────────────────────────────────────────
const CONNECTION_DIRECTIONS = ['up', 'down', 'left', 'right', 'dive', 'emerge'];

function editConnection(dirName, connIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const conns = map.connections || [];
    const conn = conns[connIdx];
    if (!conn) return;

    const mapIds = (state.maps || []).map(m => m.id).filter(Boolean).sort();

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Connection</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-row">
                    <div class="form-group">
                        <label>Direction</label>
                        ${makeSelectHtml('conn-dir', conn.direction || 'up', CONNECTION_DIRECTIONS)}
                    </div>
                    <div class="form-group">
                        <label>Offset</label>
                        <input type="number" id="conn-offset" value="${conn.offset || 0}">
                    </div>
                </div>
                <div class="form-group">
                    <label>Destination Map</label>
                    ${makeDatalistHtml('conn-map', conn.map || '', mapIds, 'style="font-family:monospace;font-size:12px"')}
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-conn-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-conn-btn').addEventListener('click', () => {
        conn.direction = $('#conn-dir').value;
        conn.offset = parseInt($('#conn-offset').value);
        conn.map = $('#conn-map').value;
        overlay.remove();
        saveMapAndRefresh(map, dirName, 'Connection updated (auto-saved)');
    });
}

function deleteConnection(dirName, connIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!confirm('Delete this connection?')) return;
    (map.connections || []).splice(connIdx, 1);
    if (map.connections && map.connections.length === 0) map.connections = null;
    saveMapAndRefresh(map, dirName, 'Connection deleted (auto-saved)');
}

function addConnection(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!map.connections) map.connections = [];

    map.connections.push({
        direction: 'up',
        offset: 0,
        map: 'MAP_LITTLEROOT_TOWN'
    });
    saveMapAndRefresh(map, dirName, 'Connection added (auto-saved)');
    setTimeout(() => editConnection(dirName, map.connections.length - 1), 200);
}

// ─── Coordinate Events Section ──────────────────────────────────────────────
function buildCoordEventsSection(map) {
    return ''; // Absorbed into buildSignsAndTriggersSection
}

// ─── Signs & Triggers Section (merged BG Events + Coord Events) ─────────────
function buildSignsAndTriggersSection(map) {
    const bgEvents = (map.bg_events || []).filter(e => e.type !== 'hidden_item');
    const coords = map.coord_events || [];
    const totalCount = bgEvents.length + coords.length;

    let signsHtml = '';
    if (bgEvents.length === 0) {
        signsHtml = `<div class="empty-state" style="padding:12px"><div class="empty-icon">&#128220;</div>No signs</div>`;
    } else {
        signsHtml = bgEvents.map((evt) => {
            const allBg = map.bg_events || [];
            const realIdx = allBg.indexOf(evt);
            const scriptShort = (evt.script || '').split('_EventScript_').pop().replace(/_/g, ' ');
            const typeBadge = evt.type === 'secret_base'
                ? '<span class="trigger-type-badge trigger-type-secret">Secret Base</span>'
                : '<span class="trigger-type-badge trigger-type-sign">Sign</span>';
            return `
                <div class="area-item-row">
                    <div class="area-item-icon" style="background:var(--yellow);color:#333">&#128220;</div>
                    ${typeBadge}
                    <span class="area-item-name">${escHtml(scriptShort || evt.type || 'sign')}</span>
                    <span class="area-item-coords">(${evt.x}, ${evt.y})</span>
                    <div style="display:flex;gap:4px">
                        <button class="btn btn-sm" onclick="editBgEvent('${escAttr(map._dirName)}', ${realIdx})">Edit</button>
                        <button class="btn btn-sm btn-danger" onclick="deleteBgEvent('${escAttr(map._dirName)}', ${realIdx})">Delete</button>
                    </div>
                </div>
            `;
        }).join('');
    }
    signsHtml += `<div style="text-align:right;margin-top:8px"><button class="btn btn-sm btn-primary" onclick="addBgEvent('${escAttr(map._dirName)}')">+ Add Sign</button></div>`;

    let triggersHtml = '';
    if (coords.length === 0) {
        triggersHtml = `<div class="empty-state" style="padding:12px"><div class="empty-icon">&#9678;</div>No step triggers</div>`;
    } else {
        triggersHtml = coords.map((c, i) => {
            const scriptShort = (c.script || '').split('_EventScript_').pop().replace(/_/g, ' ');
            const conditionText = c.var ? `${(c.var || '').replace('VAR_', '')} = ${c.var_value || '0'}` : '';
            return `
                <div class="area-item-row">
                    <div class="area-item-icon" style="background:var(--cyan);color:#fff">&#9678;</div>
                    <span class="trigger-type-badge trigger-type-step">Step Trigger</span>
                    <span class="area-item-name">${escHtml(scriptShort || 'trigger')}</span>
                    ${conditionText ? `<span style="font-size:11px;color:var(--text-dim);font-family:monospace">${escHtml(conditionText)}</span>` : ''}
                    <span class="area-item-coords">(${c.x}, ${c.y})</span>
                    <div style="display:flex;gap:4px">
                        <button class="btn btn-sm" onclick="editCoordEvent('${escAttr(map._dirName)}', ${i})">Edit</button>
                        <button class="btn btn-sm btn-danger" onclick="deleteCoordEvent('${escAttr(map._dirName)}', ${i})">Delete</button>
                    </div>
                </div>
            `;
        }).join('');
    }
    triggersHtml += `<div style="text-align:right;margin-top:8px"><button class="btn btn-sm btn-primary" onclick="addCoordEvent('${escAttr(map._dirName)}')">+ Add Step Trigger</button></div>`;

    return `
        <div class="map-area-section">
            <div class="map-area-section-header">
                <h2><span class="section-icon">&#128220;</span> Signs &amp; Triggers <span class="section-count">${totalCount}</span></h2>
                <span class="toggle-arrow">&#9660;</span>
            </div>
            <div class="map-area-section-body">
                <div class="nav-subsection-label">Signs (things you read)</div>
                ${signsHtml}
                <div class="nav-subsection-label">Step Triggers (walk-over events)</div>
                ${triggersHtml}
            </div>
        </div>
    `;
}

function editCoordEvent(dirName, idx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const evt = (map.coord_events || [])[idx];
    if (!evt) return;

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Coordinate Event</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-row">
                    <div class="form-group">
                        <label>Type</label>
                        ${makeSelectHtml('ce-type', evt.type || '', COORD_EVENT_TYPES, 'style="font-family:monospace;font-size:12px"')}
                    </div>
                    <div class="form-group">
                        <label>Script</label>
                        <input type="text" id="ce-script" value="${escAttr(evt.script || '')}" style="font-family:monospace;font-size:12px">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>X</label>
                        <input type="number" id="ce-x" value="${evt.x || 0}">
                    </div>
                    <div class="form-group">
                        <label>Y</label>
                        <input type="number" id="ce-y" value="${evt.y || 0}">
                    </div>
                    <div class="form-group">
                        <label>Elevation</label>
                        <input type="number" id="ce-elev" value="${evt.elevation || 0}">
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-ce-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-ce-btn').addEventListener('click', () => {
        evt.type = $('#ce-type').value;
        evt.script = $('#ce-script').value;
        evt.x = parseInt($('#ce-x').value);
        evt.y = parseInt($('#ce-y').value);
        evt.elevation = parseInt($('#ce-elev').value);
        overlay.remove();
        saveMapAndRefresh(map, dirName, 'Coordinate event updated (auto-saved)');
    });
}

function deleteCoordEvent(dirName, idx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map || !confirm('Delete this coordinate event?')) return;
    (map.coord_events || []).splice(idx, 1);
    saveMapAndRefresh(map, dirName, 'Coordinate event deleted (auto-saved)');
}

function addCoordEvent(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!map.coord_events) map.coord_events = [];
    map.coord_events.push({ type: 'trigger', x: 0, y: 0, elevation: 0, script: `${dirName}_EventScript_NewTrigger` });
    saveMapAndRefresh(map, dirName, 'Coordinate event added (auto-saved)');
    setTimeout(() => editCoordEvent(dirName, map.coord_events.length - 1), 200);
}

// ─── Background Events Section (legacy, kept for compatibility) ─────────────
function buildBgEventsSection(map) {
    return ''; // Absorbed into buildSignsAndTriggersSection
}

function editBgEvent(dirName, realIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const evt = (map.bg_events || [])[realIdx];
    if (!evt) return;

    const bgTypes = ['sign', 'hidden_item', 'secret_base'];

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal">
            <div class="modal-header">
                <h2>Edit Background Event</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-row">
                    <div class="form-group">
                        <label>Type</label>
                        ${makeSelectHtml('bg-type', evt.type || 'sign', bgTypes)}
                    </div>
                    <div class="form-group">
                        <label>Script</label>
                        <input type="text" id="bg-script" value="${escAttr(evt.script || '')}" style="font-family:monospace;font-size:12px">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>X</label>
                        <input type="number" id="bg-x" value="${evt.x || 0}">
                    </div>
                    <div class="form-group">
                        <label>Y</label>
                        <input type="number" id="bg-y" value="${evt.y || 0}">
                    </div>
                    <div class="form-group">
                        <label>Elevation</label>
                        <input type="number" id="bg-elev" value="${evt.elevation || 0}">
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-bg-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-bg-btn').addEventListener('click', () => {
        evt.type = $('#bg-type').value;
        evt.script = $('#bg-script').value;
        evt.x = parseInt($('#bg-x').value);
        evt.y = parseInt($('#bg-y').value);
        evt.elevation = parseInt($('#bg-elev').value);
        overlay.remove();
        saveMapAndRefresh(map, dirName, 'Background event updated (auto-saved)');
    });
}

function deleteBgEvent(dirName, realIdx) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map || !confirm('Delete this background event?')) return;
    (map.bg_events || []).splice(realIdx, 1);
    saveMapAndRefresh(map, dirName, 'Background event deleted (auto-saved)');
}

function addBgEvent(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    if (!map.bg_events) map.bg_events = [];

    const newEvt = { type: 'sign', x: 0, y: 0, elevation: 0, script: `${dirName}_EventScript_NewSign` };
    map.bg_events.push(newEvt);
    const realIdx = map.bg_events.length - 1;
    saveMapAndRefresh(map, dirName, 'Background event added (auto-saved)');
    setTimeout(() => editBgEvent(dirName, realIdx), 200);
}

// ─── NPC Tab ────────────────────────────────────────────────────────────────
function collectNPCs() {
    if (!state.maps) return [];
    const npcs = [];
    for (const map of state.maps) {
        for (const evt of (map.object_events || [])) {
            // Include all non-item-ball events (trainers can also be NPCs of interest)
            if ((evt.graphics_id || '').includes('ITEM_BALL')) continue;
            if ((evt.graphics_id || '').includes('BERRY_TREE')) continue;
            npcs.push({ ...evt, _mapDirName: map._dirName, _mapName: getMapDisplayName(map), _mapId: map.id });
        }
    }
    return npcs;
}

async function renderNPCs() {
    // If viewing a specific NPC group, render detail
    if (state.npcDetail) {
        await renderNPCGroupDetail(state.npcDetail);
        return;
    }

    const maps = await loadMaps();
    try { await loadTrainers(); } catch {}

    const allNPCs = collectNPCs();
    const search = state.search.toLowerCase();

    const filtered = allNPCs.filter(n => {
        if (!search) return true;
        return (n.graphics_id || '').toLowerCase().includes(search) ||
            (n.script || '').toLowerCase().includes(search) ||
            (n._mapName || '').toLowerCase().includes(search) ||
            (n._mapId || '').toLowerCase().includes(search);
    });

    // Group by graphics_id
    const groups = {};
    for (const n of filtered) {
        const key = n.graphics_id || 'UNKNOWN';
        if (!groups[key]) groups[key] = { graphics_id: key, count: 0, maps: new Set(), npcs: [], hasTrainer: false };
        groups[key].count++;
        groups[key].maps.add(n._mapName);
        groups[key].npcs.push(n);
        if (n.trainer_type && n.trainer_type !== 'TRAINER_TYPE_NONE') groups[key].hasTrainer = true;
    }

    const sortedGroups = Object.values(groups).sort((a, b) => b.count - a.count);

    content.innerHTML = `
        <div class="page-header">
            <h1>NPCs <span style="color:var(--text-dim);font-size:14px">(${filtered.length} events, ${sortedGroups.length} types)</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search NPCs by sprite, script, or map name..." id="npc-search" value="${state.search}">
        </div>
        <div id="npc-list"></div>
    `;

    const list = $('#npc-list');

    // Group view: each graphics_id gets a card. Click to expand into individual entries.
    const maxGroups = 100;
    const groupsToShow = sortedGroups.slice(0, maxGroups);

    let groupCards = groupsToShow.map(g => {
        const gfx = g.graphics_id.replace('OBJ_EVENT_GFX_', '').replace(/_/g, ' ');
        const mapList = [...g.maps].slice(0, 3).join(', ') + (g.maps.size > 3 ? ` +${g.maps.size - 3} more` : '');
        const trainerCount = g.npcs.filter(n => n.trainer_type && n.trainer_type !== 'TRAINER_TYPE_NONE').length;

        // If only 1 NPC, show inline with direct actions
        if (g.count === 1) {
            const n = g.npcs[0];
            const isTrainer = n.trainer_type && n.trainer_type !== 'TRAINER_TYPE_NONE';
            return `
                <div class="npc-group-card npc-group-single">
                    <div class="npc-group-header">
                        ${getSpriteHtml(g.graphics_id, 40)}
                        <div class="npc-group-info">
                            <div class="npc-group-name">${escHtml(gfx)}${isTrainer ? ' <span class="npc-badge npc-badge-trainer">Trainer</span>' : ''}</div>
                            <div class="npc-group-meta">${escHtml(n._mapName)} &middot; (${n.x}, ${n.y})</div>
                        </div>
                        <div class="npc-group-actions">
                            <button class="btn btn-sm" onclick="editNPCFromList('${escAttr(n._mapDirName)}', '${escAttr(n.script || '')}', ${n.x}, ${n.y})">Edit</button>
                            ${isTrainer ? `<button class="btn btn-sm" onclick="editNPCParty('${escAttr(n._mapDirName)}', '${escAttr(n.script || '')}')">Party</button>` : ''}
                            <button class="btn btn-sm" onclick="openMapDetail('${escAttr(n._mapDirName)}')" title="Go to map">Map</button>
                        </div>
                    </div>
                </div>
            `;
        }

        // Multiple NPCs: show as group card that can be clicked into
        return `
            <div class="npc-group-card" onclick="state.npcDetail='${escAttr(g.graphics_id)}'; renderNPCs()" style="cursor:pointer">
                <div class="npc-group-header">
                    ${getSpriteHtml(g.graphics_id, 40)}
                    <div class="npc-group-info">
                        <div class="npc-group-name">${escHtml(gfx)}</div>
                        <div class="npc-group-meta">${g.count} instances across ${g.maps.size} map${g.maps.size !== 1 ? 's' : ''}</div>
                        <div class="npc-group-maps">${escHtml(mapList)}</div>
                    </div>
                    <div class="npc-group-badges">
                        <span class="npc-group-count">${g.count}</span>
                        ${trainerCount > 0 ? `<span class="npc-badge npc-badge-trainer">${trainerCount} trainer${trainerCount !== 1 ? 's' : ''}</span>` : ''}
                    </div>
                    <span class="npc-group-arrow">&#9654;</span>
                </div>
            </div>
        `;
    }).join('');

    if (sortedGroups.length > maxGroups) {
        groupCards += `<div style="padding:16px;color:var(--text-dim);font-size:13px;text-align:center">Showing ${maxGroups} of ${sortedGroups.length} NPC types. Use search to narrow down.</div>`;
    }

    list.innerHTML = groupCards || '<div class="empty-state">No NPCs found matching your search.</div>';

    $('#npc-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        state.npcDetail = null;
        await renderNPCs();
        const el = $('#npc-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

// Detail view for a specific NPC graphics_id group
async function renderNPCGroupDetail(graphicsId) {
    const allNPCs = collectNPCs();
    const groupNPCs = allNPCs.filter(n => n.graphics_id === graphicsId);
    const gfx = graphicsId.replace('OBJ_EVENT_GFX_', '').replace(/_/g, ' ');

    content.innerHTML = `
        <button class="back-btn" onclick="state.npcDetail=null; renderNPCs()">&#8592; Back to NPCs</button>
        <div class="page-header" style="margin-bottom:16px">
            <div style="display:flex;align-items:center;gap:14px">
                ${getSpriteHtml(graphicsId, 48)}
                <div>
                    <h1>${escHtml(gfx)}</h1>
                    <div style="color:var(--text-dim);font-size:13px">${groupNPCs.length} instance${groupNPCs.length !== 1 ? 's' : ''} across ${new Set(groupNPCs.map(n => n._mapName)).size} maps</div>
                </div>
            </div>
        </div>
        <div id="npc-group-list"></div>
    `;

    const list = $('#npc-group-list');

    // Group by map for better organization
    const byMap = {};
    for (const n of groupNPCs) {
        if (!byMap[n._mapDirName]) byMap[n._mapDirName] = { name: n._mapName, npcs: [] };
        byMap[n._mapDirName].npcs.push(n);
    }

    let html = '';
    for (const [dirName, mapGroup] of Object.entries(byMap)) {
        html += `<div class="npc-group-map-section">
            <div class="npc-group-map-header" onclick="openMapDetail('${escAttr(dirName)}')" style="cursor:pointer" title="Go to map">
                <span>${escHtml(mapGroup.name)}</span>
                <span class="npc-group-map-count">${mapGroup.npcs.length}</span>
            </div>`;

        for (const n of mapGroup.npcs) {
            const isTrainer = n.trainer_type && n.trainer_type !== 'TRAINER_TYPE_NONE';
            let npcName = gfx;
            if (n.script && n.script !== '0x0') {
                const parts = n.script.split('_EventScript_');
                if (parts.length >= 2) npcName = parts[parts.length - 1].replace(/_/g, ' ');
            }

            html += `
                <div class="npc-row">
                    ${getSpriteHtml(n.graphics_id, 36)}
                    <div class="npc-row-info">
                        <div class="npc-row-name">${escHtml(npcName)}${isTrainer ? ' <span style="color:var(--red);font-size:10px">TRAINER</span>' : ''}</div>
                        <div class="npc-row-detail">${escHtml(n.script || 'No script')}</div>
                    </div>
                    <div class="npc-row-coords">(${n.x}, ${n.y})</div>
                    <div class="npc-row-actions">
                        <button class="btn btn-sm" onclick="editNPCFromList('${escAttr(n._mapDirName)}', '${escAttr(n.script || '')}', ${n.x}, ${n.y})">Edit</button>
                        ${isTrainer ? `<button class="btn btn-sm" onclick="editNPCParty('${escAttr(n._mapDirName)}', '${escAttr(n.script || '')}')">Party</button>` : ''}
                    </div>
                </div>
            `;
        }
        html += '</div>';
    }

    list.innerHTML = html || '<div class="empty-state">No NPCs found.</div>';
}

function editNPCFromList(dirName, script, x, y) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;
    const events = map.object_events || [];
    const idx = events.findIndex(e => e.script === script && e.x === x && e.y === y);
    if (idx >= 0) editObjectEvent(dirName, idx);
}

function editNPCParty(dirName, script) {
    const scriptParts = script.split('_EventScript_');
    if (scriptParts.length >= 2) {
        const trainerSuffix = scriptParts[scriptParts.length - 1];
        const matched = (state.trainers || []).find(t =>
            t.id.toUpperCase().includes(trainerSuffix.toUpperCase())
        );
        if (matched) {
            editTrainer(matched.id);
            return;
        }
    }
    toast('Could not match NPC to a trainer party entry', true);
}

// ─── Pokemon Species Tab ────────────────────────────────────────────────────
function parsePokemonSpecies(text) {
    const pokemon = [];
    const regex = /\[(SPECIES_\w+)\]\s*=\s*\{([\s\S]*?)\n    \}/g;
    let match;
    while ((match = regex.exec(text)) !== null) {
        const id = match[1];
        if (id === 'SPECIES_NONE') continue;
        const body = match[2];
        const mon = { id };

        const nameM = body.match(/\.speciesName\s*=\s*_\("([^"]+)"\)/);
        const hpM = body.match(/\.baseHP\s*=\s*(\d+)/);
        const atkM = body.match(/\.baseAttack\s*=\s*(\d+)/);
        const defM = body.match(/\.baseDefense\s*=\s*(\d+)/);
        const spdM = body.match(/\.baseSpeed\s*=\s*(\d+)/);
        const spaM = body.match(/\.baseSpAttack\s*=\s*(\d+)/);
        const spdM2 = body.match(/\.baseSpDefense\s*=\s*(\d+)/);
        const typesM = body.match(/\.types\s*=\s*MON_TYPES\((\w+)(?:,\s*(\w+))?\)/);
        const catchM = body.match(/\.catchRate\s*=\s*(\d+)/);
        const expM = body.match(/\.expYield\s*=\s*(\d+)/);
        const abilitiesM = body.match(/\.abilities\s*=\s*\{([^}]+)\}/);
        const growthM = body.match(/\.growthRate\s*=\s*(\w+)/);
        const eggM = body.match(/\.eggGroups\s*=\s*MON_EGG_GROUPS\((\w+)(?:,\s*(\w+))?\)/);
        const learnsetM = body.match(/\.levelUpLearnset\s*=\s*(\w+)/);
        const evosM = body.match(/\.evolutions\s*=\s*EVOLUTION\(([\s\S]+?)\)\s*,/);

        if (nameM) mon.name = nameM[1];
        if (learnsetM) mon.learnsetVar = learnsetM[1];

        // Parse evolution data
        if (evosM) {
            mon.evolutions = parseEvolutionEntries(evosM[1]);
        }
        if (hpM) mon.baseHP = parseInt(hpM[1]);
        if (atkM) mon.baseAttack = parseInt(atkM[1]);
        if (defM) mon.baseDefense = parseInt(defM[1]);
        if (spdM) mon.baseSpeed = parseInt(spdM[1]);
        if (spaM) mon.baseSpAttack = parseInt(spaM[1]);
        if (spdM2) mon.baseSpDefense = parseInt(spdM2[1]);
        if (typesM) {
            mon.type1 = (typesM[1] || '').replace('TYPE_', '');
            mon.type2 = typesM[2] ? typesM[2].replace('TYPE_', '') : mon.type1;
        }
        if (catchM) mon.catchRate = parseInt(catchM[1]);
        if (expM) mon.expYield = parseInt(expM[1]);
        if (abilitiesM) mon.abilities = abilitiesM[1].trim();
        if (growthM) mon.growthRate = growthM[1].replace('GROWTH_', '');
        if (eggM) {
            mon.eggGroup1 = (eggM[1] || '').replace('EGG_GROUP_', '');
            mon.eggGroup2 = eggM[2] ? eggM[2].replace('EGG_GROUP_', '') : '';
        }

        mon.bst = (mon.baseHP || 0) + (mon.baseAttack || 0) + (mon.baseDefense || 0) +
            (mon.baseSpeed || 0) + (mon.baseSpAttack || 0) + (mon.baseSpDefense || 0);

        if (mon.name) pokemon.push(mon);
    }
    return pokemon;
}

async function loadPokemonSpecies() {
    if (!state.pokemon) {
        const listing = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/src/data/pokemon/species_info?ref=${BRANCH}`);
        const genFiles = listing.filter(f => f.name.startsWith('gen_') && f.name.endsWith('.h'));
        const allPokemon = [];
        // Load in batches of 3
        for (let i = 0; i < genFiles.length; i += 3) {
            const batch = genFiles.slice(i, i + 3);
            const results = await Promise.all(batch.map(async f => {
                try {
                    const text = await fetchFile(`src/data/pokemon/species_info/${f.name}`);
                    return { file: f.name, pokemon: parsePokemonSpecies(text) };
                } catch { return { file: f.name, pokemon: [] }; }
            }));
            for (const r of results) {
                for (const p of r.pokemon) {
                    p._file = r.file;
                }
                allPokemon.push(...r.pokemon);
            }
        }
        state.pokemon = allPokemon;
    }
    return state.pokemon;
}

// ─── Evolution Constants ─────────────────────────────────────────────────────
const EVO_METHODS = [
    'EVO_LEVEL', 'EVO_ITEM', 'EVO_TRADE', 'EVO_SPIN', 'EVO_BATTLE_END',
    'EVO_THRESHOLD', 'EVO_SCRIPT_TRIGGER', 'EVO_LEVEL_BATTLE_ONLY',
    'EVO_SPLIT_FROM_EVO', 'EVO_NONE'
];

const EVO_CONDITIONS = [
    'IF_MIN_FRIENDSHIP', 'IF_TIME', 'IF_NOT_TIME', 'IF_REGION', 'IF_NOT_REGION',
    'IF_HOLD_ITEM', 'IF_KNOWS_MOVE', 'IF_KNOWS_MOVE_TYPE', 'IF_GENDER',
    'IF_ATK_GT_DEF', 'IF_ATK_LT_DEF', 'IF_ATK_EQ_DEF', 'IF_IN_MAP',
    'IF_IN_MAPSEC', 'IF_WEATHER', 'IF_SPECIES_IN_PARTY', 'IF_TYPE_IN_PARTY',
    'IF_MIN_BEAUTY', 'IF_MIN_OVERWORLD_STEPS', 'IF_BAG_ITEM_COUNT',
    'IF_CRITICAL_HITS_GE', 'IF_CURRENT_DAMAGE_GE', 'IF_RECOIL_DAMAGE_GE',
    'IF_USED_MOVE_X_TIMES', 'IF_DEFEAT_X_WITH_ITEMS', 'IF_TRADE_PARTNER_SPECIES',
    'IF_AMPED_NATURE', 'IF_LOW_KEY_NATURE',
    'IF_PID_MODULO_100_GT', 'IF_PID_MODULO_100_EQ',
    'IF_PID_MODULO_', 'IF_PID_UPPER_MODULO_'
];

function parseEvolutionEntries(evoStr) {
    const evolutions = [];
    // Strip preprocessor directives (#if, #endif, #else, etc.)
    evoStr = evoStr.replace(/^\s*#\w+.*$/gm, '');
    // Match each {EVO_METHOD, param, SPECIES_TARGET[, CONDITIONS(...)]} block
    const regex = /\{(EVO_\w+),\s*([^,}]+),\s*(SPECIES_\w+)(?:,\s*CONDITIONS\(([\s\S]*?)\)\s*)?\}/g;
    let match;
    while ((match = regex.exec(evoStr)) !== null) {
        const evo = {
            method: match[1],
            param: match[2].trim(),
            target: match[3],
            conditions: []
        };
        if (match[4]) {
            // Parse individual condition blocks: {IF_X, VALUE}
            const condRegex = /\{(\w+),\s*([^}]+)\}/g;
            let cm;
            while ((cm = condRegex.exec(match[4])) !== null) {
                evo.conditions.push({ type: cm[1], value: cm[2].trim() });
            }
        }
        evolutions.push(evo);
    }
    return evolutions;
}

function serializeEvolutions(evolutions) {
    if (!evolutions || evolutions.length === 0) return null;
    const entries = evolutions.map(evo => {
        let s = `{${evo.method}, ${evo.param}, ${evo.target}`;
        if (evo.conditions && evo.conditions.length > 0) {
            const conds = evo.conditions.map(c => `{${c.type}, ${c.value}}`).join(', ');
            s += `, CONDITIONS(${conds})`;
        }
        s += '}';
        return s;
    });
    if (entries.length === 1) {
        return `EVOLUTION(${entries[0]})`;
    }
    return `EVOLUTION(${entries.join(',\n                                ')})`;
}

function formatEvoMethod(evo) {
    const method = (evo.method || '').replace('EVO_', '');
    const param = (evo.param || '').replace('ITEM_', '').replace(/_/g, ' ');
    const labels = {
        'LEVEL': `Level ${param}`,
        'ITEM': `Use ${param}`,
        'TRADE': 'Trade',
        'SPIN': 'Spin',
        'BATTLE_END': 'After Battle',
        'THRESHOLD': `Threshold ${param}`,
        'SCRIPT_TRIGGER': 'Script Trigger',
        'LEVEL_BATTLE_ONLY': `Level ${param} (Battle)`,
    };
    let result = labels[method] || `${method} ${param}`.trim();
    // Format conditions
    const conds = Array.isArray(evo.conditions) ? evo.conditions : [];
    if (conds.length > 0) {
        const condStrs = conds.map(c => {
            const ct = (c.type || '').replace('IF_', '').replace(/_/g, ' ').toLowerCase();
            const cv = (c.value || '').replace(/^(ITEM_|MOVE_|TYPE_|TIME_|REGION_|FRIENDSHIP_|SPECIES_)/, '').replace(/_/g, ' ');
            return `${ct}: ${cv}`;
        });
        result += ` [${condStrs.join(', ')}]`;
    }
    return result;
}

function updatePokemonInFile(mon) {
    const filePath = `src/data/pokemon/species_info/${mon._file}`;
    let fileContent = pendingChanges[filePath] || originalContent[filePath];
    if (!fileContent) { toast('Pokemon data not loaded yet', true); return; }

    const fields = ['baseHP', 'baseAttack', 'baseDefense', 'baseSpeed', 'baseSpAttack', 'baseSpDefense', 'catchRate', 'expYield'];

    // Replace within the specific species block
    const blockRegex = new RegExp(`(\\[${mon.id}\\]\\s*=\\s*\\{)([\\s\\S]*?)(\\n    \\})`, 'm');
    const blockMatch = fileContent.match(blockRegex);
    if (blockMatch) {
        let block = blockMatch[2];
        for (const key of fields) {
            if (mon[key] !== undefined) {
                const fieldRegex = new RegExp(`(\\.${key}\\s*=\\s*)\\d+`);
                block = block.replace(fieldRegex, `$1${mon[key]}`);
            }
        }

        // Update types
        if (mon.type1) {
            const typeRegex = /\.types\s*=\s*MON_TYPES\(\w+(?:,\s*\w+)?\)/;
            const type2 = mon.type2 && mon.type2 !== mon.type1 ? `, TYPE_${mon.type2}` : '';
            block = block.replace(typeRegex, `.types = MON_TYPES(TYPE_${mon.type1}${type2})`);
        }

        // Update evolutions
        const hasExistingEvos = /\.evolutions\s*=\s*EVOLUTION\([\s\S]+?\)\s*,/.test(block);
        const newEvoStr = serializeEvolutions(mon.evolutions);

        if (hasExistingEvos && newEvoStr) {
            // Replace existing evolutions line(s) — greedy enough to span multi-line blocks with #if
            block = block.replace(/\.evolutions\s*=\s*EVOLUTION\([\s\S]+?\)\s*,/, `.evolutions = ${newEvoStr},`);
        } else if (hasExistingEvos && !newEvoStr) {
            // Remove evolutions line(s)
            block = block.replace(/\n\s*\.evolutions\s*=\s*EVOLUTION\([\s\S]+?\)\s*,/, '');
        } else if (!hasExistingEvos && newEvoStr) {
            // Add evolutions before the closing brace — find last field line
            const lastFieldMatch = block.match(/(.*\S.*)\n\s*$/s);
            if (lastFieldMatch) {
                const insertPos = block.lastIndexOf(lastFieldMatch[1]) + lastFieldMatch[1].length;
                block = block.substring(0, insertPos) + `\n        .evolutions = ${newEvoStr},` + block.substring(insertPos);
            }
        }

        fileContent = fileContent.replace(blockRegex, `$1${block}$3`);
    }

    markChanged(filePath, fileContent);
}

// ─── Learnset Data ─────────────────────────────────────────────────────────
function parseLevelUpLearnsets(text, genName) {
    const learnsets = {};
    const regex = /static const struct LevelUpMove (s\w+LevelUpLearnset)\[\]\s*=\s*\{([\s\S]*?)\};/g;
    let match;
    while ((match = regex.exec(text)) !== null) {
        const varName = match[1];
        const body = match[2];
        const moves = [];
        const moveRegex = /LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_\w+)\s*\)/g;
        let moveMatch;
        while ((moveMatch = moveRegex.exec(body)) !== null) {
            moves.push({ level: parseInt(moveMatch[1]), move: moveMatch[2] });
        }
        learnsets[varName] = { gen: genName, moves };
    }
    return learnsets;
}

async function loadLearnsets() {
    if (!state.learnsets) {
        let listing;
        try {
            listing = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/src/data/pokemon/level_up_learnsets?ref=${BRANCH}`);
        } catch (e) {
            throw new Error(`Could not list learnset files: ${e.message}`);
        }
        if (!Array.isArray(listing)) throw new Error('Unexpected response when listing learnset files');
        const genFiles = listing.filter(f => f.name.startsWith('gen_') && f.name.endsWith('.h'));
        const all = {};
        for (let i = 0; i < genFiles.length; i += 3) {
            const batch = genFiles.slice(i, i + 3);
            const results = await Promise.all(batch.map(async f => {
                try {
                    const text = await fetchFile(`src/data/pokemon/level_up_learnsets/${f.name}`);
                    return parseLevelUpLearnsets(text, f.name.replace('.h', ''));
                } catch { return {}; }
            }));
            for (const r of results) Object.assign(all, r);
        }
        state.learnsets = all;
    }
    return state.learnsets;
}

async function loadLearnables() {
    if (!state.learnables) {
        state.learnables = await fetchJSON('src/data/pokemon/all_learnables.json');
    }
    return state.learnables;
}

// Build lookup: MOVE_XXX -> "Readable Name"
function getMoveNameMap(moves) {
    const map = {};
    for (const m of moves) {
        map[m.id] = m.name || m.id.replace('MOVE_', '').replace(/_/g, ' ').replace(/\b\w/g, c => c.toUpperCase());
    }
    return map;
}

// Build reverse lookup: "readable name" (lowercase) -> MOVE_XXX
function getMoveIdMap(moves) {
    const map = {};
    for (const m of moves) {
        const name = m.name || m.id.replace('MOVE_', '').replace(/_/g, ' ');
        map[name.toLowerCase()] = m.id;
    }
    return map;
}

// Get the all_learnables key from a SPECIES_XXX id
function speciesKeyFromId(speciesId) {
    return speciesId.replace('SPECIES_', '');
}

function updateLevelUpLearnsetInFile(varName, genName, moves) {
    const filePath = `src/data/pokemon/level_up_learnsets/${genName}.h`;
    let fileContent = pendingChanges[filePath] || originalContent[filePath];
    if (!fileContent) { toast('Learnset file not loaded yet', true); return; }

    const blockRegex = new RegExp(
        `(static const struct LevelUpMove ${varName}\\[\\]\\s*=\\s*\\{)([\\s\\S]*?)(\\};)`, 'm'
    );
    const blockMatch = fileContent.match(blockRegex);
    if (!blockMatch) { toast(`Could not find ${varName} in ${genName}.h`, true); return; }

    const movesStr = moves.map(m => {
        const lvl = String(m.level).padStart(2, ' ');
        return `    LEVEL_UP_MOVE(${lvl}, ${m.move}),`;
    }).join('\n');

    fileContent = fileContent.replace(blockRegex, `$1\n${movesStr}\n    LEVEL_UP_END\n$3`);
    markChanged(filePath, fileContent);
}

function updateLearnablesInFile(speciesKey, moveList) {
    const filePath = 'src/data/pokemon/all_learnables.json';
    let fileContent = pendingChanges[filePath] || originalContent[filePath];
    if (!fileContent) { toast('Learnables data not loaded yet', true); return; }

    const data = JSON.parse(fileContent);
    data[speciesKey] = moveList.sort();
    markChanged(filePath, JSON.stringify(data, null, 2) + '\n');
    state.learnables = data;
}

async function editLearnset(speciesId) {
    const mon = state.pokemon.find(p => p.id === speciesId);
    if (!mon) return;

    // Show loading indicator
    const loadingOverlay = document.createElement('div');
    loadingOverlay.className = 'modal-overlay';
    loadingOverlay.innerHTML = `<div class="modal" style="padding:32px;text-align:center">
        <div class="spinner"></div>
        <div style="margin-top:12px">Loading learnset data for ${escHtml(mon.name || mon.id)}...</div>
    </div>`;
    document.body.appendChild(loadingOverlay);

    let moves, learnsets, learnables;
    try {
        [moves, learnsets, learnables] = await Promise.all([
            loadMoves(), loadLearnsets(), loadLearnables()
        ]);
    } catch (e) {
        loadingOverlay.remove();
        toast(`Failed to load learnset data: ${e.message}`, true);
        return;
    }
    loadingOverlay.remove();

    const nameMap = getMoveNameMap(moves);
    const idMap = getMoveIdMap(moves);
    const allMoveNames = moves.map(m => m.name || m.id.replace('MOVE_', '').replace(/_/g, ' ')).sort();
    const allMoveIds = moves.map(m => m.id).sort();

    // Get level-up moves
    const varName = mon.learnsetVar;
    const learnsetData = varName && learnsets[varName] ? learnsets[varName] : null;
    const levelUpMoves = learnsetData ? learnsetData.moves.map(m => ({ ...m })) : [];

    // Get teachable moves
    const speciesKey = speciesKeyFromId(speciesId);
    const teachableMoves = learnables[speciesKey] ? [...learnables[speciesKey]] : [];

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';

    function renderModal() {
        overlay.innerHTML = `
            <div class="modal" style="max-width:800px;max-height:90vh;display:flex;flex-direction:column">
                <div class="modal-header">
                    <h2>Learnset &mdash; ${escHtml(mon.name || mon.id)}</h2>
                    <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
                </div>
                <div class="modal-body" style="overflow-y:auto;flex:1">
                    <div style="margin-bottom:16px">
                        <div style="display:flex;align-items:center;justify-content:space-between;margin-bottom:8px">
                            <strong style="font-size:14px">Level-Up Moves</strong>
                            <button class="btn btn-sm btn-primary" id="add-levelup-btn">+ Add Move</button>
                        </div>
                        ${!varName ? '<div style="color:var(--text-dim);font-size:13px">No learnset variable found for this species.</div>' : ''}
                        <table style="width:100%">
                            <thead><tr><th style="width:60px">Lvl</th><th>Move</th><th style="width:40px"></th></tr></thead>
                            <tbody id="levelup-tbody">
                                ${levelUpMoves.map((m, i) => `
                                    <tr>
                                        <td><input type="number" class="lu-level" data-idx="${i}" value="${m.level}" min="1" max="100" style="width:50px"></td>
                                        <td>
                                            <input type="text" class="lu-move" data-idx="${i}" value="${escAttr(nameMap[m.move] || m.move)}" list="move-datalist" style="width:100%">
                                        </td>
                                        <td><button class="btn btn-sm" data-remove-lu="${i}" title="Remove" style="color:#e55">&#10005;</button></td>
                                    </tr>
                                `).join('')}
                            </tbody>
                        </table>
                    </div>
                    <div>
                        <div style="display:flex;align-items:center;justify-content:space-between;margin-bottom:8px">
                            <strong style="font-size:14px">Teachable Moves <span style="color:var(--text-dim);font-weight:normal">(${teachableMoves.length})</span></strong>
                            <button class="btn btn-sm btn-primary" id="add-teachable-btn">+ Add Move</button>
                        </div>
                        <div id="teachable-list" style="display:flex;flex-wrap:wrap;gap:4px">
                            ${teachableMoves.map((m, i) => `
                                <span class="type-badge" style="cursor:pointer;display:inline-flex;align-items:center;gap:4px" data-remove-teach="${i}">
                                    ${escHtml(nameMap[m] || m)}
                                    <span style="color:#e55;font-weight:bold" title="Remove">&times;</span>
                                </span>
                            `).join('')}
                        </div>
                    </div>
                    <datalist id="move-datalist">
                        ${allMoveNames.map(n => `<option value="${escAttr(n)}">`).join('')}
                    </datalist>
                </div>
                <div class="modal-footer">
                    <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                    <button class="btn btn-primary" id="save-learnset-btn">Save</button>
                </div>
            </div>
        `;

        // Event: remove level-up move
        overlay.querySelectorAll('[data-remove-lu]').forEach(btn => {
            btn.addEventListener('click', () => {
                levelUpMoves.splice(parseInt(btn.dataset.removeLu), 1);
                renderModal();
            });
        });

        // Event: remove teachable move
        overlay.querySelectorAll('[data-remove-teach]').forEach(el => {
            el.addEventListener('click', () => {
                teachableMoves.splice(parseInt(el.dataset.removeTeach), 1);
                renderModal();
            });
        });

        // Event: add level-up move
        const addLuBtn = overlay.querySelector('#add-levelup-btn');
        if (addLuBtn) addLuBtn.addEventListener('click', () => {
            levelUpMoves.push({ level: 1, move: 'MOVE_NONE' });
            renderModal();
            // Focus the last move input
            const inputs = overlay.querySelectorAll('.lu-move');
            if (inputs.length) inputs[inputs.length - 1].focus();
        });

        // Event: add teachable move
        const addTeachBtn = overlay.querySelector('#add-teachable-btn');
        if (addTeachBtn) addTeachBtn.addEventListener('click', () => {
            const name = prompt('Enter move name:');
            if (!name) return;
            const moveId = idMap[name.toLowerCase()];
            if (!moveId) { toast(`Unknown move: ${name}`, true); return; }
            if (!teachableMoves.includes(moveId)) {
                teachableMoves.push(moveId);
                renderModal();
            } else {
                toast('Move already in teachable list');
            }
        });

        // Event: sync level/move inputs on change
        overlay.querySelectorAll('.lu-level').forEach(input => {
            input.addEventListener('change', () => {
                const idx = parseInt(input.dataset.idx);
                levelUpMoves[idx].level = parseInt(input.value) || 1;
            });
        });
        overlay.querySelectorAll('.lu-move').forEach(input => {
            input.addEventListener('change', () => {
                const idx = parseInt(input.dataset.idx);
                const val = input.value.trim();
                const moveId = idMap[val.toLowerCase()];
                if (moveId) {
                    levelUpMoves[idx].move = moveId;
                } else {
                    toast(`Unknown move: ${val}`, true);
                }
            });
        });

        // Event: save
        const saveBtn = overlay.querySelector('#save-learnset-btn');
        if (saveBtn) saveBtn.addEventListener('click', () => {
            // Validate all level-up moves have valid IDs
            for (const m of levelUpMoves) {
                if (!m.move || m.move === 'MOVE_NONE') {
                    toast('Please fill in all moves before saving', true);
                    return;
                }
            }

            // Sort level-up moves by level
            levelUpMoves.sort((a, b) => a.level - b.level);

            // Save level-up learnset
            if (varName && learnsetData) {
                learnsetData.moves = levelUpMoves;
                updateLevelUpLearnsetInFile(varName, learnsetData.gen, levelUpMoves);
            }

            // Save teachable moves
            updateLearnablesInFile(speciesKey, teachableMoves);

            toast(`Learnset for ${mon.name || mon.id} updated (pending PR submission)`);
            overlay.remove();
        });
    }

    renderModal();
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });
}

async function renderPokemonPage() {
    const pokemon = await loadPokemonSpecies();
    const search = state.search.toLowerCase();

    const filtered = pokemon.filter(p =>
        !search ||
        (p.name || '').toLowerCase().includes(search) ||
        p.id.toLowerCase().includes(search) ||
        (p.type1 || '').toLowerCase().includes(search) ||
        (p.type2 || '').toLowerCase().includes(search)
    );

    const perPage = 50;
    const page = state.pokemonPage || 0;
    const totalPages = Math.ceil(filtered.length / perPage);
    const pageItems = filtered.slice(page * perPage, (page + 1) * perPage);

    // Build evolution lookup: species -> what evolves INTO it (prevolutions)
    const prevolutionMap = {};
    for (const p of pokemon) {
        if (p.evolutions) {
            for (const evo of p.evolutions) {
                if (!prevolutionMap[evo.target]) prevolutionMap[evo.target] = [];
                prevolutionMap[evo.target].push({ from: p.id, fromName: p.name, method: evo.method, param: evo.param, conditions: evo.conditions });
            }
        }
    }

    content.innerHTML = `
        <div class="page-header">
            <h1>Pokemon <span style="color:var(--text-dim);font-size:14px">(${filtered.length})</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search Pokemon by name, ID, or type..." id="pokemon-search" value="${state.search}">
        </div>
        <div class="table-container">
            <table>
                <thead>
                    <tr>
                        <th>Pokemon</th>
                        <th>Type</th>
                        <th>HP</th>
                        <th>Atk</th>
                        <th>Def</th>
                        <th>SpA</th>
                        <th>SpD</th>
                        <th>Spe</th>
                        <th>BST</th>
                        <th>Evolution</th>
                        <th></th>
                    </tr>
                </thead>
                <tbody id="pokemon-tbody">
                    ${pageItems.map(p => {
                        // Evolution display
                        let evoHtml = '';
                        if (p.evolutions && p.evolutions.length > 0) {
                            evoHtml = p.evolutions.map(e => {
                                const targetName = (pokemon.find(x => x.id === e.target) || {}).name || e.target.replace('SPECIES_', '');
                                return `<span class="evo-pill" title="${escAttr(formatEvoMethod(e))}">${escHtml(targetName)}</span>`;
                            }).join(' ');
                        }
                        // Show prevolution if exists
                        const prevos = prevolutionMap[p.id];
                        if (prevos && prevos.length > 0) {
                            const prevoHtml = prevos.map(pr => {
                                const fromName = pr.fromName || pr.from.replace('SPECIES_', '');
                                return `<span class="evo-pill evo-pill-from" title="${escAttr(formatEvoMethod(pr))}">${escHtml(fromName)}</span>`;
                            }).join(' ');
                            evoHtml = prevoHtml + (evoHtml ? ' &#8594; ' : '') + evoHtml;
                        } else if (evoHtml) {
                            evoHtml = '&#8594; ' + evoHtml;
                        }

                        return `
                        <tr>
                            <td>
                                <strong>${escHtml(p.name || '-')}</strong><br>
                                <span style="font-size:11px;color:var(--text-dim);font-family:monospace">${p.id}</span>
                            </td>
                            <td>
                                <span class="type-badge type-${p.type1 || 'NORMAL'}">${p.type1 || '-'}</span>
                                ${p.type2 && p.type2 !== p.type1 ? `<span class="type-badge type-${p.type2}">${p.type2}</span>` : ''}
                            </td>
                            <td>${p.baseHP ?? '-'}</td>
                            <td>${p.baseAttack ?? '-'}</td>
                            <td>${p.baseDefense ?? '-'}</td>
                            <td>${p.baseSpAttack ?? '-'}</td>
                            <td>${p.baseSpDefense ?? '-'}</td>
                            <td>${p.baseSpeed ?? '-'}</td>
                            <td><strong>${p.bst || '-'}</strong></td>
                            <td style="font-size:11px;max-width:180px">${evoHtml || '<span style="color:var(--text-dim)">-</span>'}</td>
                            <td>
                                <button class="btn btn-sm" onclick="editPokemon('${escAttr(p.id)}')">Stats</button>
                                <button class="btn btn-sm" onclick="editLearnset('${escAttr(p.id)}')">Moves</button>
                            </td>
                        </tr>
                    `}).join('')}
                </tbody>
            </table>
        </div>
        <div class="pagination" id="pokemon-pagination">
            <span>Page ${page + 1} of ${totalPages} (${filtered.length} Pokemon)</span>
            <div class="pagination-btns">
                ${page > 0 ? `<button class="btn btn-sm" onclick="state.pokemonPage=${page - 1}; renderPokemonPage()">Prev</button>` : ''}
                ${page < totalPages - 1 ? `<button class="btn btn-sm" onclick="state.pokemonPage=${page + 1}; renderPokemonPage()">Next</button>` : ''}
            </div>
        </div>
    `;

    $('#pokemon-search').addEventListener('input', async e => {
        const pos = e.target.selectionStart;
        state.search = e.target.value;
        state.pokemonPage = 0;
        await renderPokemonPage();
        const el = $('#pokemon-search');
        if (el) { el.focus(); el.selectionStart = el.selectionEnd = pos; }
    });
}

function editPokemon(id) {
    const mon = state.pokemon.find(p => p.id === id);
    if (!mon) return;

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="max-width:650px">
            <div class="modal-header">
                <h2>Edit ${escHtml(mon.name || mon.id)}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body">
                <div class="form-row">
                    <div class="form-group">
                        <label>Species ID</label>
                        <input type="text" value="${escAttr(mon.id)}" readonly style="opacity:0.6">
                    </div>
                    <div class="form-group">
                        <label>Name</label>
                        <input type="text" value="${escAttr(mon.name || '')}" readonly style="opacity:0.6" title="Name is set in source">
                    </div>
                </div>
                <div style="margin:12px 0 8px;font-size:13px;font-weight:600">Base Stats</div>
                <div class="form-row">
                    <div class="form-group">
                        <label>HP</label>
                        <input type="number" id="pk-hp" value="${mon.baseHP || 0}" min="1" max="255">
                    </div>
                    <div class="form-group">
                        <label>Attack</label>
                        <input type="number" id="pk-atk" value="${mon.baseAttack || 0}" min="1" max="255">
                    </div>
                    <div class="form-group">
                        <label>Defense</label>
                        <input type="number" id="pk-def" value="${mon.baseDefense || 0}" min="1" max="255">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Sp. Atk</label>
                        <input type="number" id="pk-spa" value="${mon.baseSpAttack || 0}" min="1" max="255">
                    </div>
                    <div class="form-group">
                        <label>Sp. Def</label>
                        <input type="number" id="pk-spd" value="${mon.baseSpDefense || 0}" min="1" max="255">
                    </div>
                    <div class="form-group">
                        <label>Speed</label>
                        <input type="number" id="pk-spe" value="${mon.baseSpeed || 0}" min="1" max="255">
                    </div>
                </div>
                <div style="margin:12px 0 8px;font-size:13px;font-weight:600">Types</div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Type 1</label>
                        <select id="pk-type1">
                            ${POKEMON_TYPES.map(t => `<option value="${t}" ${mon.type1 === t ? 'selected' : ''}>${t}</option>`).join('')}
                        </select>
                    </div>
                    <div class="form-group">
                        <label>Type 2</label>
                        <select id="pk-type2">
                            ${POKEMON_TYPES.map(t => `<option value="${t}" ${mon.type2 === t ? 'selected' : ''}>${t}</option>`).join('')}
                        </select>
                    </div>
                </div>
                <div style="margin:12px 0 8px;font-size:13px;font-weight:600">Other</div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Catch Rate</label>
                        <input type="number" id="pk-catch" value="${mon.catchRate || 0}" min="1" max="255">
                    </div>
                    <div class="form-group">
                        <label>Exp Yield</label>
                        <input type="number" id="pk-exp" value="${mon.expYield || 0}" min="0" max="999">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Abilities</label>
                        <input type="text" id="pk-abilities" value="${escAttr(mon.abilities || '')}" style="font-family:monospace;font-size:12px" readonly style="opacity:0.6" title="Edit in source">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Growth Rate</label>
                        <input type="text" value="${escAttr(mon.growthRate || '')}" readonly style="opacity:0.6;font-family:monospace;font-size:12px">
                    </div>
                    <div class="form-group">
                        <label>Egg Groups</label>
                        <input type="text" value="${escAttr((mon.eggGroup1 || '') + (mon.eggGroup2 ? ', ' + mon.eggGroup2 : ''))}" readonly style="opacity:0.6;font-family:monospace;font-size:12px">
                    </div>
                </div>
                <div style="margin:12px 0 8px;font-size:13px;font-weight:600">Evolutions</div>
                <div id="evo-editor"></div>
                <div style="margin-top:8px">
                    <button class="btn btn-sm btn-primary" id="add-evo-btn">+ Add Evolution</button>
                </div>
                <div style="margin-top:12px;padding:10px;background:var(--bg);border-radius:6px;font-size:12px;color:var(--text-dim)">
                    BST: <strong style="color:var(--text)">${mon.bst || 0}</strong> &middot; File: ${escHtml(mon._file || '')}
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-pk-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    // ── Evolution CRUD editor ──
    const editEvos = mon.evolutions ? JSON.parse(JSON.stringify(mon.evolutions)) : [];
    const speciesIds = getUniqueSpeciesIds();

    function renderEvoEditor() {
        const container = overlay.querySelector('#evo-editor');
        if (!container) return;

        if (editEvos.length === 0) {
            container.innerHTML = '<div class="empty-state" style="padding:12px"><div class="empty-icon">&#9733;</div>No evolutions defined</div>';
            return;
        }

        container.innerHTML = editEvos.map((evo, i) => {
            const methodOpts = EVO_METHODS.map(m =>
                `<option value="${m}" ${evo.method === m ? 'selected' : ''}>${m.replace('EVO_', '')}</option>`
            ).join('');

            const conds = evo.conditions || [];
            const condRows = conds.map((c, ci) => {
                const condTypeOpts = EVO_CONDITIONS.map(ct =>
                    `<option value="${ct}" ${c.type === ct ? 'selected' : ''}>${ct}</option>`
                ).join('');
                return `
                    <div class="evo-cond-row" data-evo="${i}" data-cond="${ci}">
                        <select class="evo-cond-type" data-evo="${i}" data-cond="${ci}" style="flex:1;min-width:0">
                            ${condTypeOpts}
                        </select>
                        <input type="text" class="evo-cond-value" data-evo="${i}" data-cond="${ci}" value="${escAttr(c.value)}" placeholder="Value" style="flex:1;min-width:0;font-family:monospace;font-size:12px">
                        <button class="btn btn-sm btn-danger evo-remove-cond" data-evo="${i}" data-cond="${ci}" title="Remove condition">&#10005;</button>
                    </div>
                `;
            }).join('');

            const targetMon = (state.pokemon || []).find(p => p.id === evo.target);
            const targetName = targetMon ? targetMon.name : '';

            return `
                <div class="evo-edit-card" data-evo="${i}">
                    <div class="evo-edit-header">
                        <span class="evo-edit-num">#${i + 1}</span>
                        <span class="evo-edit-summary">${escHtml(formatEvoMethod(evo))} &#8594; ${escHtml(targetName || evo.target.replace('SPECIES_', ''))}</span>
                        <button class="btn btn-sm btn-danger evo-remove" data-evo="${i}" title="Delete evolution">&#128465;</button>
                    </div>
                    <div class="evo-edit-body">
                        <div class="form-row">
                            <div class="form-group">
                                <label>Method</label>
                                <select class="evo-method" data-evo="${i}" style="font-family:monospace;font-size:12px">${methodOpts}</select>
                            </div>
                            <div class="form-group">
                                <label>Parameter</label>
                                <input type="text" class="evo-param" data-evo="${i}" value="${escAttr(evo.param)}" style="font-family:monospace;font-size:12px" placeholder="e.g. 16, ITEM_THUNDER_STONE">
                            </div>
                            <div class="form-group">
                                <label>Target Species</label>
                                <input type="text" class="evo-target" data-evo="${i}" value="${escAttr(evo.target)}" list="dl-evo-species" style="font-family:monospace;font-size:12px">
                            </div>
                        </div>
                        <div style="margin-top:8px">
                            <label style="font-size:11px;color:var(--text-dim);font-weight:600;text-transform:uppercase;letter-spacing:0.5px">Conditions</label>
                            <div class="evo-cond-list" data-evo="${i}">
                                ${condRows || '<div style="font-size:12px;color:var(--text-dim);padding:4px 0">No conditions</div>'}
                            </div>
                            <button class="btn btn-sm evo-add-cond" data-evo="${i}" style="margin-top:4px">+ Condition</button>
                        </div>
                    </div>
                </div>
            `;
        }).join('');

        // Add species datalist
        container.innerHTML += `<datalist id="dl-evo-species">${speciesIds.map(s => `<option value="${escAttr(s)}">`).join('')}</datalist>`;

        // Wire up events
        container.querySelectorAll('.evo-method').forEach(el => {
            el.addEventListener('change', () => {
                editEvos[parseInt(el.dataset.evo)].method = el.value;
                renderEvoEditor();
            });
        });
        container.querySelectorAll('.evo-param').forEach(el => {
            el.addEventListener('change', () => {
                editEvos[parseInt(el.dataset.evo)].param = el.value;
                renderEvoEditor();
            });
        });
        container.querySelectorAll('.evo-target').forEach(el => {
            el.addEventListener('change', () => {
                editEvos[parseInt(el.dataset.evo)].target = el.value;
                renderEvoEditor();
            });
        });
        container.querySelectorAll('.evo-cond-type').forEach(el => {
            el.addEventListener('change', () => {
                const ei = parseInt(el.dataset.evo), ci = parseInt(el.dataset.cond);
                editEvos[ei].conditions[ci].type = el.value;
                renderEvoEditor();
            });
        });
        container.querySelectorAll('.evo-cond-value').forEach(el => {
            el.addEventListener('change', () => {
                const ei = parseInt(el.dataset.evo), ci = parseInt(el.dataset.cond);
                editEvos[ei].conditions[ci].value = el.value;
                renderEvoEditor();
            });
        });
        container.querySelectorAll('.evo-remove').forEach(el => {
            el.addEventListener('click', () => {
                editEvos.splice(parseInt(el.dataset.evo), 1);
                renderEvoEditor();
            });
        });
        container.querySelectorAll('.evo-remove-cond').forEach(el => {
            el.addEventListener('click', () => {
                const ei = parseInt(el.dataset.evo), ci = parseInt(el.dataset.cond);
                editEvos[ei].conditions.splice(ci, 1);
                renderEvoEditor();
            });
        });
        container.querySelectorAll('.evo-add-cond').forEach(el => {
            el.addEventListener('click', () => {
                const ei = parseInt(el.dataset.evo);
                if (!editEvos[ei].conditions) editEvos[ei].conditions = [];
                editEvos[ei].conditions.push({ type: 'IF_MIN_FRIENDSHIP', value: 'FRIENDSHIP_EVO_THRESHOLD' });
                renderEvoEditor();
            });
        });
    }

    renderEvoEditor();

    // Add evolution button
    overlay.querySelector('#add-evo-btn').addEventListener('click', () => {
        editEvos.push({
            method: 'EVO_LEVEL',
            param: '0',
            target: 'SPECIES_NONE',
            conditions: []
        });
        renderEvoEditor();
    });

    // ── Save handler ──
    $('#save-pk-btn').addEventListener('click', () => {
        mon.baseHP = parseInt($('#pk-hp').value);
        mon.baseAttack = parseInt($('#pk-atk').value);
        mon.baseDefense = parseInt($('#pk-def').value);
        mon.baseSpAttack = parseInt($('#pk-spa').value);
        mon.baseSpDefense = parseInt($('#pk-spd').value);
        mon.baseSpeed = parseInt($('#pk-spe').value);
        mon.type1 = $('#pk-type1').value;
        mon.type2 = $('#pk-type2').value;
        mon.catchRate = parseInt($('#pk-catch').value);
        mon.expYield = parseInt($('#pk-exp').value);
        mon.bst = mon.baseHP + mon.baseAttack + mon.baseDefense + mon.baseSpAttack + mon.baseSpDefense + mon.baseSpeed;

        // Save evolution changes
        mon.evolutions = editEvos.length > 0 ? editEvos : undefined;

        updatePokemonInFile(mon);
        toast(`${mon.name || mon.id} updated (auto-saved)`);
        overlay.remove();
        renderPokemonPage();
    });
}

// ─── Starters ───────────────────────────────────────────────────────────────
const STARTER_FILE = 'src/starter_choose.c';
const STARTER_LABELS = [
    { macro: 'GRASS_STARTER', rseLabel: 'Starter 1 — Emerald (left)', frlgLabel: 'Starter 1 — FRLG (left)' },
    { macro: 'FIRE_STARTER',  rseLabel: 'Starter 2 — Emerald (middle)', frlgLabel: 'Starter 2 — FRLG (middle)' },
    { macro: 'WATER_STARTER', rseLabel: 'Starter 3 — Emerald (right)', frlgLabel: 'Starter 3 — FRLG (right)' },
];

function parseStarters(text) {
    const starters = [];
    for (const s of STARTER_LABELS) {
        const regex = new RegExp(`^#define\\s+${s.macro}\\s+\\(IS_FRLG\\s*\\?\\s*(SPECIES_\\w+)\\s*:\\s*(SPECIES_\\w+)\\s*\\)`, 'm');
        const m = text.match(regex);
        if (m) {
            starters.push({ macro: s.macro, frlg: m[1], rse: m[2], rseLabel: s.rseLabel, frlgLabel: s.frlgLabel });
        }
    }
    return starters;
}

async function renderStarters() {
    const text = pendingChanges[STARTER_FILE] || originalContent[STARTER_FILE] || await fetchFile(STARTER_FILE);
    if (!originalContent[STARTER_FILE]) originalContent[STARTER_FILE] = text;
    const starters = parseStarters(text);

    if (starters.length === 0) {
        content.innerHTML = `
            <div class="page-header"><h1>Starters</h1></div>
            <div style="color:var(--text-dim);padding:24px">Could not parse starter defines from ${STARTER_FILE}.</div>`;
        return;
    }

    let rows = '';
    for (const s of starters) {
        rows += `
            <div class="config-row">
                <span class="config-name">${s.rseLabel}</span>
                <span class="config-value">
                    ${makeDatalistHtml('starter-rse-' + s.macro, s.rse, getUniqueSpeciesIds(), 'onchange="updateStarter(\'' + s.macro + '\',\'rse\',this.value)" style="width:200px"')}
                </span>
                <span class="config-comment">${s.rse.replace('SPECIES_', '')}</span>
            </div>
            <div class="config-row">
                <span class="config-name">${s.frlgLabel}</span>
                <span class="config-value">
                    ${makeDatalistHtml('starter-frlg-' + s.macro, s.frlg, getUniqueSpeciesIds(), 'onchange="updateStarter(\'' + s.macro + '\',\'frlg\',this.value)" style="width:200px"')}
                </span>
                <span class="config-comment">${s.frlg.replace('SPECIES_', '')}</span>
            </div>`;
    }

    content.innerHTML = `
        <div class="page-header"><h1>Starters</h1></div>
        <div style="background:var(--bg-card);border:1px solid var(--border);border-radius:var(--radius);padding:16px 20px;margin-bottom:24px;font-size:13px;color:var(--text-dim)">
            Set the starter Pokemon for Emerald (RSE) and FireRed/LeafGreen (FRLG).
            Use <code style="font-size:12px;background:var(--bg-input);padding:2px 6px;border-radius:3px">SPECIES_XXX</code> format (e.g. <code style="font-size:12px;background:var(--bg-input);padding:2px 6px;border-radius:3px">SPECIES_PIKACHU</code>).
        </div>
        <div class="config-group">
            <div class="config-group-header">
                <span>Starter Pokemon</span>
                <span class="count">${starters.length * 2} settings</span>
            </div>
            <div>${rows}</div>
        </div>`;
}

function updateStarter(macro, version, value) {
    let fileContent = pendingChanges[STARTER_FILE] || originalContent[STARTER_FILE];
    if (!fileContent) { toast('Starter file not loaded yet', true); return; }

    // Match: #define MACRO (IS_FRLG ? SPECIES_X : SPECIES_Y)
    const regex = new RegExp(`^(#define\\s+${macro}\\s+\\(IS_FRLG\\s*\\?\\s*)(SPECIES_\\w+)(\\s*:\\s*)(SPECIES_\\w+)(\\s*\\))`, 'm');
    if (version === 'frlg') {
        fileContent = fileContent.replace(regex, `$1${value}$3$4$5`);
    } else {
        fileContent = fileContent.replace(regex, `$1$2$3${value}$5`);
    }
    markChanged(STARTER_FILE, fileContent);
    toast(`Updated ${macro} ${version.toUpperCase()} (auto-saved)`);
    renderStarters();
}

// ─── Utils ──────────────────────────────────────────────────────────────────
function escHtml(s) {
    return String(s || '').replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;').replace(/"/g, '&quot;');
}
function escAttr(s) {
    return String(s || '').replace(/&/g, '&amp;').replace(/"/g, '&quot;').replace(/'/g, '&#39;');
}

// ─── MIDI Player Engine ─────────────────────────────────────────────────────

window.musicPlayer = (() => {
    let audioCtx = null;
    let instruments = {};
    let player = null;
    let currentTrack = null;
    let isPlaying = false;

    function getAudioContext() {
        if (!audioCtx) audioCtx = new (window.AudioContext || window.webkitAudioContext)();
        return audioCtx;
    }

    async function loadInstrument(programNum) {
        const ac = getAudioContext();
        const gmNames = [
            'acoustic_grand_piano', 'bright_acoustic_piano', 'electric_grand_piano', 'honkytonk_piano',
            'electric_piano_1', 'electric_piano_2', 'harpsichord', 'clavinet',
            'celesta', 'glockenspiel', 'music_box', 'vibraphone',
            'marimba', 'xylophone', 'tubular_bells', 'dulcimer',
            'drawbar_organ', 'percussive_organ', 'rock_organ', 'church_organ',
            'reed_organ', 'accordion', 'harmonica', 'tango_accordion',
            'acoustic_guitar_nylon', 'acoustic_guitar_steel', 'electric_guitar_jazz', 'electric_guitar_clean',
            'electric_guitar_muted', 'overdriven_guitar', 'distortion_guitar', 'guitar_harmonics',
            'acoustic_bass', 'electric_bass_finger', 'electric_bass_pick', 'fretless_bass',
            'slap_bass_1', 'slap_bass_2', 'synth_bass_1', 'synth_bass_2',
            'violin', 'viola', 'cello', 'contrabass',
            'tremolo_strings', 'pizzicato_strings', 'orchestral_harp', 'timpani',
            'string_ensemble_1', 'string_ensemble_2', 'synth_strings_1', 'synth_strings_2',
            'choir_aahs', 'voice_oohs', 'synth_choir', 'orchestra_hit',
            'trumpet', 'trombone', 'tuba', 'muted_trumpet',
            'french_horn', 'brass_section', 'synth_brass_1', 'synth_brass_2',
            'soprano_sax', 'alto_sax', 'tenor_sax', 'baritone_sax',
            'oboe', 'english_horn', 'bassoon', 'clarinet',
            'piccolo', 'flute', 'recorder', 'pan_flute',
            'blown_bottle', 'shakuhachi', 'whistle', 'ocarina',
            'lead_1_square', 'lead_2_sawtooth', 'lead_3_calliope', 'lead_4_chiff',
            'lead_5_charang', 'lead_6_voice', 'lead_7_fifths', 'lead_8_bass_lead',
            'pad_1_new_age', 'pad_2_warm', 'pad_3_polysynth', 'pad_4_choir',
            'pad_5_bowed', 'pad_6_metallic', 'pad_7_halo', 'pad_8_sweep',
            'fx_1_rain', 'fx_2_soundtrack', 'fx_3_crystal', 'fx_4_atmosphere',
            'fx_5_brightness', 'fx_6_goblins', 'fx_7_echoes', 'fx_8_scifi',
            'sitar', 'banjo', 'shamisen', 'koto',
            'kalimba', 'bagpipe', 'fiddle', 'shanai',
            'tinkle_bell', 'agogo', 'steel_drums', 'woodblock',
            'taiko_drum', 'melodic_tom', 'synth_drum', 'reverse_cymbal',
            'guitar_fret_noise', 'breath_noise', 'seashore', 'bird_tweet',
            'telephone_ring', 'helicopter', 'applause', 'gunshot'
        ];
        const name = gmNames[programNum] || 'acoustic_grand_piano';
        if (!instruments[name]) {
            try {
                instruments[name] = await Soundfont.instrument(ac, name);
            } catch {
                if (!instruments['acoustic_grand_piano']) {
                    instruments['acoustic_grand_piano'] = await Soundfont.instrument(ac, 'acoustic_grand_piano');
                }
                instruments[name] = instruments['acoustic_grand_piano'];
            }
        }
        return instruments[name];
    }

    const channelPrograms = {};
    for (let i = 0; i < 16; i++) channelPrograms[i] = 0;

    async function play(filename, trackId) {
        stop();
        const ac = getAudioContext();
        if (ac.state === 'suspended') await ac.resume();

        currentTrack = trackId || filename;
        const bar = document.getElementById('music-player-bar');
        const title = document.getElementById('music-player-title');
        const playBtn = document.getElementById('music-player-play');
        if (bar) bar.style.display = 'flex';
        if (title) title.textContent = (trackId || filename).replace('MUS_', '').replace(/_/g, ' ');

        await loadInstrument(0);

        // Fetch MIDI file via GitHub Contents API (handles auth & CORS), with raw URL fallback
        let uint8;
        const midiPath = `sound/songs/midi/${filename}`;
        try {
            const data = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/${midiPath}?ref=${BRANCH}`);
            if (data.content) {
                const raw = atob(data.content.replace(/\n/g, ''));
                uint8 = Uint8Array.from(raw, c => c.charCodeAt(0));
            } else {
                throw new Error('No content in API response');
            }
        } catch {
            // Fallback to raw URL
            const rawUrl = `https://raw.githubusercontent.com/${REPO_OWNER}/${REPO_NAME}/${BRANCH}/${midiPath}`;
            const headers = {};
            if (ghToken) headers['Authorization'] = `token ${ghToken}`;
            const response = await fetch(rawUrl, { headers });
            if (!response.ok) throw new Error(`Failed to fetch MIDI: ${response.status}`);
            uint8 = new Uint8Array(await response.arrayBuffer());
        }

        let binary = '';
        for (let i = 0; i < uint8.length; i++) binary += String.fromCharCode(uint8[i]);
        const dataUri = 'data:audio/midi;base64,' + btoa(binary);

        player = new MidiPlayer.Player(async (event) => {
            if (event.name === 'Program Change') {
                channelPrograms[event.channel - 1] = event.value;
                loadInstrument(event.value);
            }
            if (event.name === 'Note on' && event.velocity > 0) {
                const ch = event.channel - 1;
                if (ch === 9) return;
                const prog = channelPrograms[ch] || 0;
                const inst = instruments[Object.keys(instruments)[0]] || await loadInstrument(prog);
                try {
                    inst.play(event.noteName, ac.currentTime, {
                        gain: event.velocity / 127,
                        duration: 1.5
                    });
                } catch {}
            }
        });

        player.on('endOfFile', () => {
            player.play();
        });

        player.loadDataUri(dataUri);
        player.play();
        isPlaying = true;
        if (playBtn) playBtn.innerHTML = '&#10074;&#10074;';
    }

    function stop() {
        if (player) {
            player.stop();
            player = null;
        }
        for (const inst of Object.values(instruments)) {
            try { inst.stop(); } catch {}
        }
        isPlaying = false;
        currentTrack = null;
        const bar = document.getElementById('music-player-bar');
        const playBtn = document.getElementById('music-player-play');
        if (bar) bar.style.display = 'none';
        if (playBtn) playBtn.innerHTML = '&#9654;';
    }

    function toggle() {
        if (!player) return;
        const playBtn = document.getElementById('music-player-play');
        if (isPlaying) {
            player.pause();
            isPlaying = false;
            if (playBtn) playBtn.innerHTML = '&#9654;';
        } else {
            player.play();
            isPlaying = true;
            if (playBtn) playBtn.innerHTML = '&#10074;&#10074;';
        }
    }

    function isCurrentlyPlaying(trackId) {
        return isPlaying && currentTrack === trackId;
    }

    return { play, stop, toggle, isCurrentlyPlaying };
})();

// ─── Music Page ─────────────────────────────────────────────────────────────

async function loadMusic() {
    if (!state.music) {
        const songsH = await fetchFile('include/constants/songs.h');
        // List MIDI files from the repo
        let midiFiles = [];
        try {
            const listing = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/sound/songs/midi?ref=${BRANCH}`);
            midiFiles = listing.filter(f => f.name.endsWith('.mid')).map(f => f.name);
        } catch {}

        const tracks = [];
        const musRegex = /^#define\s+(MUS_\w+)\s+(\d+)\s*\/\/\s*(.*)?$/gm;
        let match;
        while ((match = musRegex.exec(songsH)) !== null) {
            const id = match[1];
            const num = parseInt(match[2]);
            const comment = (match[3] || '').trim();
            const expectedFile = id.toLowerCase() + '.mid';
            const hasMidi = midiFiles.includes(expectedFile);
            tracks.push({ id, num, comment, file: hasMidi ? expectedFile : null });
        }
        const knownFiles = new Set(tracks.filter(t => t.file).map(t => t.file));
        for (const f of midiFiles) {
            if (!knownFiles.has(f) && f !== 'midi.cfg') {
                tracks.push({
                    id: f.replace('.mid', '').toUpperCase(),
                    num: null,
                    comment: 'Custom (unregistered)',
                    file: f
                });
            }
        }
        state.music = tracks;
    }
    return state.music;
}

async function renderMusic() {
    const tracks = await loadMusic();
    const search = state.search.toLowerCase();

    const activeFilter = state.musicFilter;
    const filtered = tracks.filter(t => {
        if (activeFilter === 'has_midi' && !t.file) return false;
        if (activeFilter === 'no_midi' && t.file) return false;
        if (!search) return true;
        return t.id.toLowerCase().includes(search) ||
            (t.comment || '').toLowerCase().includes(search);
    });

    const withMidi = tracks.filter(t => t.file).length;

    content.innerHTML = `
        <div class="page-header">
            <h1>Music <span style="color:var(--text-dim);font-size:14px">(${filtered.length}/${tracks.length})</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search music tracks by name..." id="music-search" value="${state.search}">
        </div>
        <div class="filter-row">
            <span class="filter-chip ${activeFilter === 'all' ? 'active' : ''}" onclick="state.musicFilter='all'; renderMusic()">All (${tracks.length})</span>
            <span class="filter-chip ${activeFilter === 'has_midi' ? 'active' : ''}" onclick="state.musicFilter='has_midi'; renderMusic()">Has MIDI (${withMidi})</span>
            <span class="filter-chip ${activeFilter === 'no_midi' ? 'active' : ''}" onclick="state.musicFilter='no_midi'; renderMusic()">No MIDI (${tracks.length - withMidi})</span>
        </div>
        <div class="card-grid" id="music-grid"></div>
    `;

    const grid = $('#music-grid');
    for (const t of filtered.slice(0, 100)) {
        const displayName = t.id.replace('MUS_', '').replace(/_/g, ' ');
        const isPlaying = window.musicPlayer.isCurrentlyPlaying(t.id);
        grid.innerHTML += `
            <div class="music-card ${isPlaying ? 'music-playing' : ''}">
                <div class="music-card-header">
                    <div>
                        <h3>${escHtml(displayName)}</h3>
                        <div class="music-card-id">${escHtml(t.id)}</div>
                    </div>
                    ${t.file ? `
                        <button class="btn btn-sm music-play-btn ${isPlaying ? 'playing' : ''}" onclick="event.stopPropagation(); playTrack('${escAttr(t.file)}', '${escAttr(t.id)}')" title="Play">
                            ${isPlaying ? '&#9632;' : '&#9654;'}
                        </button>
                    ` : '<span class="music-no-file">No MIDI</span>'}
                </div>
                <div class="music-card-meta">
                    ${t.num !== null ? `<span>ID: ${t.num}</span>` : ''}
                    ${t.comment ? `<span>${escHtml(t.comment)}</span>` : ''}
                    ${t.file ? `<span class="music-file-tag">${escHtml(t.file)}</span>` : ''}
                </div>
            </div>
        `;
    }
    if (filtered.length > 100) {
        grid.innerHTML += `<div style="padding:20px;color:var(--text-dim);font-size:13px">Showing 100 of ${filtered.length} tracks. Use search to narrow down.</div>`;
    }

    if ($('#badge-music')) $('#badge-music').textContent = withMidi;

    $('#music-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderMusic();
    });
}

function playTrack(filename, trackId) {
    if (window.musicPlayer.isCurrentlyPlaying(trackId)) {
        window.musicPlayer.stop();
        if (state.page === 'music') renderMusic();
    } else {
        window.musicPlayer.play(filename, trackId).then(() => {
            if (state.page === 'music') renderMusic();
        });
    }
}

async function playMapMusic(musicId) {
    if (window.musicPlayer.isCurrentlyPlaying(musicId)) {
        window.musicPlayer.stop();
        return;
    }
    const tracks = state.music || await loadMusic();
    const track = tracks.find(t => t.id === musicId);
    if (track && track.file) {
        window.musicPlayer.play(track.file, musicId);
    } else {
        toast('No MIDI file available for ' + musicId, true);
    }
}

// ─── Init ───────────────────────────────────────────────────────────────────
checkAuth();
updateChangesUI();
updateBranchUI();
render();
