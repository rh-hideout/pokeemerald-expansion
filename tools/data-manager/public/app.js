// ─── State ──────────────────────────────────────────────────────────────────
let state = {
    page: 'dashboard',
    trainers: null,
    encounters: null,
    moves: null,
    items: null,
    abilities: null,
    config: null,
    stats: null,
    search: '',
    configFilter: 'all',
};

const $ = (sel, el = document) => el.querySelector(sel);
const $$ = (sel, el = document) => [...el.querySelectorAll(sel)];
const content = $('#content');

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

// ─── API ────────────────────────────────────────────────────────────────────
async function api(url, opts) {
    const res = await fetch('/api/' + url, opts);
    return res.json();
}

async function loadData(endpoint) {
    if (!state[endpoint]) {
        state[endpoint] = await api(endpoint);
    }
    return state[endpoint];
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
        }
    } catch (e) {
        content.innerHTML = `<div class="loading-center" style="color:var(--red)">Error loading data: ${e.message}</div>`;
    }
}

// ─── Dashboard ──────────────────────────────────────────────────────────────
async function renderDashboard() {
    const stats = await api('stats');
    state.stats = stats;
    $('#badge-trainers').textContent = stats.trainers;
    $('#badge-encounters').textContent = stats.encounters;
    $('#badge-config').textContent = stats.configSettings;

    content.innerHTML = `
        <div class="page-header"><h1>Dashboard</h1></div>
        <div class="stat-grid">
            <div class="stat-card">
                <div class="label">Trainers</div>
                <div class="value">${stats.trainers}</div>
                <div class="sub">Defined in trainers.party</div>
            </div>
            <div class="stat-card">
                <div class="label">Wild Encounter Maps</div>
                <div class="value">${stats.encounters}</div>
                <div class="sub">Routes with wild Pokemon</div>
            </div>
            <div class="stat-card">
                <div class="label">Config Settings</div>
                <div class="value">${stats.configSettings}</div>
                <div class="sub">Across ${stats.configFiles} config files</div>
            </div>
        </div>
        <div class="page-header"><h1>Quick Access</h1></div>
        <div class="stat-grid">
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('trainers')">
                <div class="label">&#9876; Trainers</div>
                <div class="sub" style="margin-top:8px">Edit trainer teams, AI flags, and party Pokemon</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('encounters')">
                <div class="label">&#9733; Wild Encounters</div>
                <div class="sub" style="margin-top:8px">Manage per-route wild Pokemon and encounter rates</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('config')">
                <div class="label">&#9881; Config</div>
                <div class="sub" style="margin-top:8px">Toggle battle mechanics, experience, and game settings</div>
            </div>
            <div class="stat-card" style="cursor:pointer" onclick="navigateTo('moves')">
                <div class="label">&#10038; Moves</div>
                <div class="sub" style="margin-top:8px">Browse the complete moves database</div>
            </div>
        </div>
    `;
}

function navigateTo(page) {
    $$('.nav-item').forEach(n => {
        n.classList.toggle('active', n.dataset.page === page);
    });
    state.page = page;
    state.search = '';
    render();
}

// ─── Trainers ───────────────────────────────────────────────────────────────
async function renderTrainers() {
    const trainers = await loadData('trainers');
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
    const trainers = state.trainers;
    const newId = 'TRAINER_NEW_' + Date.now();
    openTrainerModal({
        id: newId, name: '', class: '', pic: '', gender: 'Male',
        music: '', double_battle: 'No', ai: '', pokemon: []
    }, true);
}

function editTrainer(id) {
    const trainer = state.trainers.find(t => t.id === id);
    if (trainer) openTrainerModal({ ...trainer, pokemon: trainer.pokemon.map(p => ({ ...p, moves: [...(p.moves || [])] })) }, false);
}

async function deleteTrainer(id) {
    if (!confirm(`Delete trainer ${id}?`)) return;
    state.trainers = state.trainers.filter(t => t.id !== id);
    await api('trainers', { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify(state.trainers) });
    toast('Trainer deleted');
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
            moves: ($$('.mon-moves')[i]?.value || '').split('\n').map(m => m.trim()).filter(Boolean)
        }));
    }

    renderModalBody();

    $('#save-trainer-btn').addEventListener('click', async () => {
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
            pokemon: []
        };
        collectPokemonFromModal(updated);
        updated.pokemon = updated.pokemon;

        if (isNew) {
            state.trainers.push(updated);
        } else {
            const idx = state.trainers.findIndex(t => t.id === trainer.id);
            if (idx >= 0) state.trainers[idx] = updated;
        }

        await api('trainers', { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify(state.trainers) });
        toast('Trainer saved');
        overlay.remove();
        renderTrainers();
    });
}

// ─── Encounters ─────────────────────────────────────────────────────────────
async function renderEncounters() {
    const data = await loadData('encounters');
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
            </div>
        `;
    }

    $('#enc-search').addEventListener('input', e => {
        state.search = e.target.value;
        renderEncounters();
    });
}

// ─── Moves ──────────────────────────────────────────────────────────────────
async function renderMoves() {
    const moves = await loadData('moves');
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

// ─── Items ──────────────────────────────────────────────────────────────────
async function renderItems() {
    const items = await loadData('items');
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

// ─── Abilities ──────────────────────────────────────────────────────────────
async function renderAbilities() {
    const abilities = await loadData('abilities');
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
                    </tr>
                </thead>
                <tbody>
                    ${filtered.map(a => `
                        <tr>
                            <td><strong>${escHtml(a.name || '-')}</strong><br><span style="font-size:11px;color:var(--text-dim);font-family:monospace">${a.id}</span></td>
                            <td>${escHtml(a.description || '-')}</td>
                            <td>${a.aiRating ?? '-'}</td>
                            <td>${a.breakable ? '<span style="color:var(--yellow)">Yes</span>' : '-'}</td>
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

// ─── Config ─────────────────────────────────────────────────────────────────
async function renderConfig() {
    const config = await loadData('config');
    const search = state.search.toLowerCase();

    // Group by file
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
            ${files.map(f => `<span class="filter-chip ${activeFile === f ? 'active' : ''}" onclick="state.configFilter='${f}'; renderConfig()">${f.replace('.h', '')} (${byFile[f].length})</span>`).join('')}
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
            const isGenSetting = /^GEN_/.test(s.value) || s.value === 'GEN_LATEST';
            const isBool = s.value === 'TRUE' || s.value === 'FALSE';

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

async function updateConfig(file, name, value) {
    try {
        await api('config', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ file, name, value })
        });
        // Update local state
        if (state.config) {
            const setting = state.config.find(s => s.file === file && s.name === name);
            if (setting) setting.value = value;
        }
        toast(`Updated ${name}`);
    } catch (e) {
        toast('Error saving: ' + e.message, true);
    }
}

// ─── Utils ──────────────────────────────────────────────────────────────────
function escHtml(s) {
    return String(s || '').replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;').replace(/"/g, '&quot;');
}
function escAttr(s) {
    return String(s || '').replace(/&/g, '&amp;').replace(/"/g, '&quot;').replace(/'/g, '&#39;');
}

// ─── Init ───────────────────────────────────────────────────────────────────
render();
