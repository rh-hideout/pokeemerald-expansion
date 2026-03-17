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
    page: 'dashboard',
    trainers: null,
    encounters: null,
    moves: null,
    items: null,
    abilities: null,
    config: null,
    maps: null,
    search: '',
    configFilter: 'all',
};

// Track pending changes: { filePath: newContent }
const pendingChanges = {};
// Track original file content for diffing
const originalContent = {};
// GitHub token
let ghToken = localStorage.getItem('gh_token') || '';
let ghUser = null;

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
    const data = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/${filePath}?ref=${BRANCH}`);
    const text = atob(data.content.replace(/\n/g, ''));
    // Handle UTF-8 properly
    const bytes = Uint8Array.from(text, c => c.charCodeAt(0));
    const decoded = new TextDecoder().decode(bytes);
    originalContent[filePath] = decoded;
    return decoded;
}

async function fetchJSON(filePath) {
    const text = await fetchFile(filePath);
    return JSON.parse(text);
}

// ─── Change Tracking ────────────────────────────────────────────────────────
function markChanged(filePath, newContent) {
    pendingChanges[filePath] = newContent;
    updateChangesUI();
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

// ─── Navigation ─────────────────────────────────────────────────────────────
$$('.nav-item').forEach(item => {
    item.addEventListener('click', () => {
        $$('.nav-item').forEach(n => n.classList.remove('active'));
        item.classList.add('active');
        state.page = item.dataset.page;
        state.search = '';
        render();
    });
});

function navigateTo(page) {
    $$('.nav-item').forEach(n => {
        n.classList.toggle('active', n.dataset.page === page);
    });
    state.page = page;
    state.search = '';
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
            case 'dashboard': await renderDashboard(); break;
            case 'trainers': await renderTrainers(); break;
            case 'encounters': await renderEncounters(); break;
            case 'moves': await renderMoves(); break;
            case 'items': await renderItems(); break;
            case 'abilities': await renderAbilities(); break;
            case 'config': await renderConfig(); break;
            case 'maps': await renderMaps(); break;
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

    const b = (id, val) => { const el = $(`#${id}`); if (el) el.textContent = val; };
    b('badge-trainers', trainers.length);
    b('badge-encounters', encCount);

    content.innerHTML = `
        <div class="page-header"><h1>Dashboard</h1></div>
        <div style="background:var(--bg-card);border:1px solid var(--border);border-radius:var(--radius);padding:16px 20px;margin-bottom:24px;font-size:13px;color:var(--text-dim)">
            <strong style="color:var(--accent)">Welcome!</strong> This is the web editor for Pokemon Brazilianite.
            Browse game data, make edits, then click <strong>"Submit PR"</strong> to send your changes for review.
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
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('trainers')">
                <div class="label">&#9876; Trainers</div>
                <div class="sub" style="margin-top:8px">Edit trainer teams, AI flags, and party Pokemon</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('encounters')">
                <div class="label">&#9733; Wild Encounters</div>
                <div class="sub" style="margin-top:8px">Browse per-route wild Pokemon and encounter rates</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('moves')">
                <div class="label">&#10038; Moves</div>
                <div class="sub" style="margin-top:8px">Edit move stats: type, power, accuracy, PP, and more</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('items')">
                <div class="label">&#9830; Items</div>
                <div class="sub" style="margin-top:8px">Edit item prices and pocket assignments</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('abilities')">
                <div class="label">&#10024; Abilities</div>
                <div class="sub" style="margin-top:8px">Edit ability descriptions, AI ratings, and flags</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('maps')">
                <div class="label">&#9873; Maps &amp; Areas</div>
                <div class="sub" style="margin-top:8px">Edit map settings, weather, connections, and flags</div>
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

    $('#trainer-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderTrainers();
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
    toast('Trainer deleted (pending PR submission)');
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
                    <input type="text" id="t-class" value="${escAttr(trainer.class || '')}">
                </div>
                <div class="form-group">
                    <label>Pic</label>
                    <input type="text" id="t-pic" value="${escAttr(trainer.pic || '')}">
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
                    <input type="text" id="t-music" value="${escAttr(trainer.music || '')}">
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
                    <input type="text" id="t-ai" value="${escAttr(trainer.ai || '')}" placeholder="e.g. Check Bad Move / Try To Faint">
                </div>
            </div>
            <div class="form-row">
                <div class="form-group">
                    <label>Items</label>
                    <input type="text" id="t-items" value="${escAttr(trainer.items || '')}" placeholder="e.g. Full Restore / Hyper Potion">
                </div>
                <div class="form-group">
                    <label>Mugshot</label>
                    <input type="text" id="t-mugshot" value="${escAttr(trainer.mugshot || '')}" placeholder="Purple, Green, Pink, Blue, Yellow">
                </div>
            </div>
            <div class="form-row">
                <div class="form-group">
                    <label>Starting Status</label>
                    <input type="text" id="t-starting-status" value="${escAttr(trainer.starting_status || '')}" placeholder="e.g. STATUS1_NONE">
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
                            <input type="text" class="mon-level" data-idx="${i}" value="${escAttr(mon.level || '')}" placeholder="1-100">
                        </div>
                        <div class="form-group">
                            <label>Nature</label>
                            <input type="text" class="mon-nature" data-idx="${i}" value="${escAttr(mon.nature || '')}" placeholder="e.g. Adamant">
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
                            <input type="text" class="mon-ball" data-idx="${i}" value="${escAttr(mon.ball || '')}">
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
                            <input type="text" class="mon-tera" data-idx="${i}" value="${escAttr(mon.tera_type || '')}">
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
        toast('Trainer saved (pending PR submission)');
        overlay.remove();
        renderTrainers();
    });
}

// ─── Encounters ─────────────────────────────────────────────────────────────
async function renderEncounters() {
    const data = await loadEncounters();
    const encounters = data.wild_encounter_groups?.[0]?.encounters || [];
    const encounterRates = data.wild_encounter_groups?.[0]?.fields || [];
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

    content.innerHTML = `
        <div class="page-header">
            <h1>Wild Encounters <span style="color:var(--text-dim);font-size:14px">(${filtered.length}/${encounters.length})</span></h1>
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

    for (const enc of filtered.slice(0, 60)) {
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
                            <span>${m.species.replace('SPECIES_', '')}</span>
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

    $('#enc-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderEncounters();
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
                                    <td><input type="text" class="enc-species" data-type="${type}" data-idx="${i}" value="${escAttr(m.species)}" style="width:180px;font-family:monospace;font-size:12px"></td>
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
        toast(`Encounters for ${mapName} updated (pending PR submission)`);
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
    $('#move-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderMoves();
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
        toast(`Move ${move.name || move.id} updated (pending PR submission)`);
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
    $('#item-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderItems();
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
        toast(`Item ${item.name || item.id} updated (pending PR submission)`);
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

    $('#ability-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderAbilities();
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
        toast(`Ability ${ability.name || ability.id} updated (pending PR submission)`);
        overlay.remove();
        renderAbilities();
    });
}

// ─── Maps/Areas ─────────────────────────────────────────────────────────────
async function renderMaps() {
    const maps = await loadMaps();
    const search = state.search.toLowerCase();
    const filtered = maps.filter(m =>
        !search ||
        (m.id || '').toLowerCase().includes(search) ||
        (m.name || '').toLowerCase().includes(search) ||
        (m._dirName || '').toLowerCase().includes(search) ||
        (m.map_type || '').toLowerCase().includes(search) ||
        (m.weather || '').toLowerCase().includes(search)
    );

    const typeGroups = {};
    for (const m of filtered) {
        const type = (m.map_type || 'UNKNOWN').replace('MAP_TYPE_', '');
        if (!typeGroups[type]) typeGroups[type] = [];
        typeGroups[type].push(m);
    }

    content.innerHTML = `
        <div class="page-header">
            <h1>Maps &amp; Areas <span style="color:var(--text-dim);font-size:14px">(${filtered.length}/${maps.length})</span></h1>
        </div>
        <div class="search-bar">
            <span class="search-icon">&#128269;</span>
            <input type="text" placeholder="Search maps by name, type, or weather..." id="map-search" value="${state.search}">
        </div>
        <div class="card-grid" id="map-grid"></div>
    `;

    const grid = $('#map-grid');
    const typeOrder = ['CITY', 'TOWN', 'ROUTE', 'UNDERGROUND', 'INDOOR', 'SECRET_BASE'];

    const sortedTypes = Object.keys(typeGroups).sort((a, b) => {
        const ai = typeOrder.indexOf(a);
        const bi = typeOrder.indexOf(b);
        if (ai >= 0 && bi >= 0) return ai - bi;
        if (ai >= 0) return -1;
        if (bi >= 0) return 1;
        return a.localeCompare(b);
    });

    for (const type of sortedTypes) {
        const typeMaps = typeGroups[type];
        for (const m of typeMaps.slice(0, 200)) {
            const displayName = (m._dirName || m.name || '').replace(/([A-Z])/g, ' $1').trim().replace(/_/g, ' ');
            const connCount = (m.connections || []).length;
            const objCount = (m.object_events || []).length;
            const warpCount = (m.warp_events || []).length;
            const bgCount = (m.bg_events || []).length;

            grid.innerHTML += `
                <div class="encounter-card">
                    <div class="encounter-card-header">
                        <h3>${escHtml(displayName)}</h3>
                        <span style="font-size:11px;color:var(--text-dim);font-family:monospace">${escHtml(m.id || '')}</span>
                    </div>
                    <div class="encounter-section">
                        <div class="encounter-row"><span>Type</span><span>${type}</span></div>
                        <div class="encounter-row"><span>Music</span><span>${(m.music || '-').replace('MUS_', '')}</span></div>
                        <div class="encounter-row"><span>Weather</span><span>${(m.weather || '-').replace('WEATHER_', '')}</span></div>
                        <div class="encounter-row"><span>Connections</span><span>${connCount}</span></div>
                        <div class="encounter-row"><span>Objects</span><span>${objCount}</span></div>
                        <div class="encounter-row"><span>Warps</span><span>${warpCount}</span></div>
                        <div class="encounter-row"><span>Signs/Items</span><span>${bgCount}</span></div>
                        <div class="encounter-row">
                            <span>Flags</span>
                            <span>
                                ${m.allow_cycling ? 'Bike' : ''}
                                ${m.allow_running ? 'Run' : ''}
                                ${m.show_map_name ? 'Name' : ''}
                                ${m.requires_flash ? 'Flash' : ''}
                            </span>
                        </div>
                    </div>
                    <div style="margin-top:8px;text-align:right">
                        <button class="btn btn-sm" onclick="editMap('${escAttr(m._dirName)}')">Edit</button>
                    </div>
                </div>
            `;
        }
    }

    $('#map-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderMaps();
    });
}

function editMap(dirName) {
    const map = state.maps.find(m => m._dirName === dirName);
    if (!map) return;

    const WEATHER_OPTIONS = ['WEATHER_NONE','WEATHER_SUNNY_CLOUDS','WEATHER_SUNNY','WEATHER_RAIN','WEATHER_SNOW','WEATHER_RAIN_THUNDERSTORM','WEATHER_FOG_HORIZONTAL','WEATHER_VOLCANIC_ASH','WEATHER_SANDSTORM','WEATHER_FOG_DIAGONAL','WEATHER_UNDERWATER','WEATHER_SHADE','WEATHER_DROUGHT','WEATHER_DOWNPOUR','WEATHER_UNDERWATER_BUBBLES','WEATHER_ABNORMAL','WEATHER_ROUTE119_CYCLE','WEATHER_ROUTE123_CYCLE'];
    const MAP_TYPES = ['MAP_TYPE_NONE','MAP_TYPE_TOWN','MAP_TYPE_CITY','MAP_TYPE_ROUTE','MAP_TYPE_UNDERGROUND','MAP_TYPE_UNDERWATER','MAP_TYPE_OCEAN_ROUTE','MAP_TYPE_INDOOR','MAP_TYPE_SECRET_BASE'];
    const BATTLE_SCENES = ['MAP_BATTLE_SCENE_NORMAL','MAP_BATTLE_SCENE_GYM','MAP_BATTLE_SCENE_MAGMA','MAP_BATTLE_SCENE_AQUA','MAP_BATTLE_SCENE_SIDNEY','MAP_BATTLE_SCENE_PHOEBE','MAP_BATTLE_SCENE_GLACIA','MAP_BATTLE_SCENE_DRAKE','MAP_BATTLE_SCENE_FRONTIER'];

    const displayName = (map._dirName || '').replace(/([A-Z])/g, ' $1').trim();

    let connectionsHtml = (map.connections || []).map((c, i) => `
        <div class="form-row" style="margin-bottom:4px">
            <div class="form-group" style="flex:2">
                <input type="text" class="conn-map" data-idx="${i}" value="${escAttr(c.map)}" placeholder="MAP_..." style="font-family:monospace;font-size:12px">
            </div>
            <div class="form-group" style="flex:1">
                <select class="conn-dir" data-idx="${i}">
                    ${['up','down','left','right','dive','emerge'].map(d => `<option ${c.direction === d ? 'selected' : ''}>${d}</option>`).join('')}
                </select>
            </div>
            <div class="form-group" style="flex:1">
                <input type="number" class="conn-offset" data-idx="${i}" value="${c.offset || 0}" style="width:60px" title="Offset">
            </div>
        </div>
    `).join('');

    const overlay = document.createElement('div');
    overlay.className = 'modal-overlay';
    overlay.innerHTML = `
        <div class="modal" style="max-width:650px">
            <div class="modal-header">
                <h2>Edit Map: ${escHtml(displayName)}</h2>
                <button class="btn btn-sm" onclick="this.closest('.modal-overlay').remove()">&#10005;</button>
            </div>
            <div class="modal-body" style="max-height:70vh;overflow-y:auto">
                <div class="form-row">
                    <div class="form-group">
                        <label>Map ID</label>
                        <input type="text" value="${escAttr(map.id || '')}" readonly style="opacity:0.6">
                    </div>
                    <div class="form-group">
                        <label>Music</label>
                        <input type="text" id="map-music" value="${escAttr(map.music || '')}" style="font-family:monospace;font-size:12px">
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Weather</label>
                        <select id="map-weather">
                            ${WEATHER_OPTIONS.map(w => `<option value="${w}" ${map.weather === w ? 'selected' : ''}>${w.replace('WEATHER_', '')}</option>`).join('')}
                        </select>
                    </div>
                    <div class="form-group">
                        <label>Map Type</label>
                        <select id="map-type">
                            ${MAP_TYPES.map(t => `<option value="${t}" ${map.map_type === t ? 'selected' : ''}>${t.replace('MAP_TYPE_', '')}</option>`).join('')}
                        </select>
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Battle Scene</label>
                        <select id="map-battle-scene">
                            ${BATTLE_SCENES.map(s => `<option value="${s}" ${map.battle_scene === s ? 'selected' : ''}>${s.replace('MAP_BATTLE_SCENE_', '')}</option>`).join('')}
                        </select>
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Allow Cycling</label>
                        <select id="map-cycling"><option value="true" ${map.allow_cycling ? 'selected' : ''}>Yes</option><option value="false" ${!map.allow_cycling ? 'selected' : ''}>No</option></select>
                    </div>
                    <div class="form-group">
                        <label>Allow Running</label>
                        <select id="map-running"><option value="true" ${map.allow_running ? 'selected' : ''}>Yes</option><option value="false" ${!map.allow_running ? 'selected' : ''}>No</option></select>
                    </div>
                    <div class="form-group">
                        <label>Allow Escaping</label>
                        <select id="map-escaping"><option value="true" ${map.allow_escaping ? 'selected' : ''}>Yes</option><option value="false" ${!map.allow_escaping ? 'selected' : ''}>No</option></select>
                    </div>
                </div>
                <div class="form-row">
                    <div class="form-group">
                        <label>Show Map Name</label>
                        <select id="map-showname"><option value="true" ${map.show_map_name ? 'selected' : ''}>Yes</option><option value="false" ${!map.show_map_name ? 'selected' : ''}>No</option></select>
                    </div>
                    <div class="form-group">
                        <label>Requires Flash</label>
                        <select id="map-flash"><option value="true" ${map.requires_flash ? 'selected' : ''}>Yes</option><option value="false" ${!map.requires_flash ? 'selected' : ''}>No</option></select>
                    </div>
                </div>
                <h3 style="margin:16px 0 8px;font-size:14px">Connections (${(map.connections || []).length})</h3>
                <div id="map-connections">${connectionsHtml || '<span style="color:var(--text-dim);font-size:12px">No connections</span>'}</div>
            </div>
            <div class="modal-footer">
                <button class="btn" onclick="this.closest('.modal-overlay').remove()">Cancel</button>
                <button class="btn btn-primary" id="save-map-btn">Save</button>
            </div>
        </div>
    `;
    document.body.appendChild(overlay);
    overlay.addEventListener('click', e => { if (e.target === overlay) overlay.remove(); });

    $('#save-map-btn').addEventListener('click', () => {
        map.music = $('#map-music').value;
        map.weather = $('#map-weather').value;
        map.map_type = $('#map-type').value;
        map.battle_scene = $('#map-battle-scene').value;
        map.allow_cycling = $('#map-cycling').value === 'true';
        map.allow_running = $('#map-running').value === 'true';
        map.allow_escaping = $('#map-escaping').value === 'true';
        map.show_map_name = $('#map-showname').value === 'true';
        map.requires_flash = $('#map-flash').value === 'true';

        // Update connections
        if (map.connections) {
            map.connections.forEach((c, i) => {
                const mapEl = overlay.querySelector(`.conn-map[data-idx="${i}"]`);
                const dirEl = overlay.querySelector(`.conn-dir[data-idx="${i}"]`);
                const offEl = overlay.querySelector(`.conn-offset[data-idx="${i}"]`);
                if (mapEl) c.map = mapEl.value;
                if (dirEl) c.direction = dirEl.value;
                if (offEl) c.offset = parseInt(offEl.value);
            });
        }

        // Serialize the map JSON, excluding internal _dirName
        const serialized = { ...map };
        delete serialized._dirName;
        markChanged(`data/maps/${map._dirName}/map.json`, JSON.stringify(serialized, null, 2) + '\n');
        toast(`Map ${map._dirName} updated (pending PR submission)`);
        overlay.remove();
        renderMaps();
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

    $('#config-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderConfig();
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
    toast(`Updated ${name} (pending PR submission)`);
}

// ─── PR Submission ──────────────────────────────────────────────────────────
function openPRModal() {
    if (!ghToken) {
        openAuthModal();
        return;
    }
    if (getChangeCount() === 0) {
        toast('No changes to submit', true);
        return;
    }

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
                    Your changes will be submitted as a Pull Request for review.
                </p>
                <div style="font-size:12px;color:var(--text-dim);margin-bottom:12px">Changed files:</div>
                <ul class="pr-changes-list">
                    ${Object.keys(pendingChanges).map(f => `<li>${escHtml(f)}</li>`).join('')}
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
            // Clear pending changes
            Object.keys(pendingChanges).forEach(k => delete pendingChanges[k]);
            updateChangesUI();
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
    // 1. Get the latest commit SHA of the base branch
    const ref = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/git/refs/heads/${BRANCH}`);
    const baseSha = ref.object.sha;

    // 2. Create a new branch
    const branchName = `editor/${ghUser.login}/${Date.now()}`;
    await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/git/refs`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
            ref: `refs/heads/${branchName}`,
            sha: baseSha
        })
    });

    // 3. Create commits for each changed file
    for (const [filePath, newContent] of Object.entries(pendingChanges)) {
        // Get the current file to obtain its SHA
        let fileSha;
        try {
            const existing = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/${filePath}?ref=${branchName}`);
            fileSha = existing.sha;
        } catch {
            // File doesn't exist yet, that's OK
        }

        // Encode content to base64, handling UTF-8 properly
        const encoder = new TextEncoder();
        const bytes = encoder.encode(newContent);
        const base64 = btoa(String.fromCharCode(...bytes));

        await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/contents/${filePath}`, {
            method: 'PUT',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({
                message: `Update ${filePath} via web editor`,
                content: base64,
                sha: fileSha,
                branch: branchName
            })
        });
    }

    // 4. Create the pull request
    const body = description
        ? `${description}\n\n---\n*Submitted via the Brazilianite web editor*`
        : '*Submitted via the Brazilianite web editor*';

    const pr = await ghFetch(`/repos/${REPO_OWNER}/${REPO_NAME}/pulls`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
            title,
            body,
            head: branchName,
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

// ─── Utils ──────────────────────────────────────────────────────────────────
function escHtml(s) {
    return String(s || '').replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;').replace(/"/g, '&quot;');
}
function escAttr(s) {
    return String(s || '').replace(/&/g, '&amp;').replace(/"/g, '&quot;').replace(/'/g, '&#39;');
}

// ─── Init ───────────────────────────────────────────────────────────────────
checkAuth();
updateChangesUI();
render();
