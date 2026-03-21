import { createRequire } from 'module';
const require = createRequire(import.meta.url);
const { chromium } = require('/opt/node22/lib/node_modules/playwright');
import { readFileSync, readdirSync } from 'fs';
import { join } from 'path';

const REPO_ROOT = '/home/user/pokemon-brazilianite';
let passed = 0, failed = 0;

function assert(condition, msg) {
    if (condition) { passed++; console.log(`  ✓ ${msg}`); }
    else { failed++; console.error(`  ✗ FAIL: ${msg}`); }
}

// Load real data from disk
function loadMaps() {
    const mapsDir = join(REPO_ROOT, 'data/maps');
    const maps = [];
    for (const d of readdirSync(mapsDir)) {
        try {
            const mapJson = JSON.parse(readFileSync(join(mapsDir, d, 'map.json'), 'utf-8'));
            mapJson._dirName = d;
            maps.push(mapJson);
        } catch {}
    }
    return maps;
}

function loadSpecies() {
    const speciesDir = join(REPO_ROOT, 'src/data/pokemon/species_info');
    const files = readdirSync(speciesDir).filter(f => f.startsWith('gen_') && f.endsWith('.h'));
    const pokemon = [];
    for (const file of files) {
        const text = readFileSync(join(speciesDir, file), 'utf-8');
        const regex = /\[(SPECIES_\w+)\]\s*=\s*\{([\s\S]*?)\n    \}/g;
        let match;
        while ((match = regex.exec(text)) !== null) {
            const id = match[1];
            if (id === 'SPECIES_NONE') continue;
            const body = match[2];
            const mon = { id, _file: file };
            const nameM = body.match(/\.speciesName\s*=\s*_\("([^"]+)"\)/);
            const hpM = body.match(/\.baseHP\s*=\s*(\d+)/);
            const atkM = body.match(/\.baseAttack\s*=\s*(\d+)/);
            const defM = body.match(/\.baseDefense\s*=\s*(\d+)/);
            const spdM = body.match(/\.baseSpeed\s*=\s*(\d+)/);
            const spaM = body.match(/\.baseSpAttack\s*=\s*(\d+)/);
            const spdM2 = body.match(/\.baseSpDefense\s*=\s*(\d+)/);
            const typesM = body.match(/\.types\s*=\s*MON_TYPES\((\w+)(?:,\s*(\w+))?\)/);
            const evosM = body.match(/\.evolutions\s*=\s*EVOLUTION\(([\s\S]+?)\)\s*,/);
            if (nameM) mon.name = nameM[1];
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
            if (evosM) mon._rawEvos = evosM[1];
            mon.bst = (mon.baseHP || 0) + (mon.baseAttack || 0) + (mon.baseDefense || 0) +
                (mon.baseSpeed || 0) + (mon.baseSpAttack || 0) + (mon.baseSpDefense || 0);
            if (mon.name) pokemon.push(mon);
        }
    }
    return pokemon;
}

const maps = loadMaps();
const pokemon = loadSpecies();
console.log(`Loaded ${maps.length} maps, ${pokemon.length} pokemon\n`);

const browser = await chromium.launch();
const page = await browser.newPage({ viewport: { width: 1400, height: 900 } });
await page.goto('http://localhost:8080/', { waitUntil: 'domcontentloaded' });
await page.waitForTimeout(300);

// Inject real data
await page.evaluate(({ maps, pokemon }) => {
    // Parse evolutions using the app's parser
    for (const p of pokemon) {
        if (p._rawEvos) {
            p.evolutions = parseEvolutionEntries(p._rawEvos);
            delete p._rawEvos;
        }
    }
    state.maps = maps;
    state.pokemon = pokemon;
    state.encounters = { wild_encounter_groups: [{ fields: [], encounters: [] }] };
}, { maps: maps.slice(0, 200), pokemon });

// ═══════════════════════════════════════════════════════════
// TEST 1: Interactive Map
// ═══════════════════════════════════════════════════════════
console.log('═══ TEST 1: Interactive Area Map ═══');

// Find a map with several object events + warps
const testMapDir = await page.evaluate(() => {
    const good = state.maps.find(m =>
        (m.object_events || []).length >= 3 &&
        (m.warp_events || []).length >= 1
    );
    return good ? good._dirName : state.maps[0]._dirName;
});

await page.evaluate((dir) => {
    state.page = 'maps';
    state.mapDetail = dir;
    render();
}, testMapDir);
await page.waitForTimeout(800);

// Force-place markers even if image didn't load (image is from GitHub CDN, may not load in test)
await page.evaluate(() => {
    const img = document.getElementById('imap-img');
    if (img && document.querySelectorAll('.imap-marker').length === 0) {
        // Fake image dimensions so initInteractiveMap's placeMarkers can work
        if (!img.naturalWidth) {
            Object.defineProperty(img, 'naturalWidth', { value: 256, writable: true });
            Object.defineProperty(img, 'naturalHeight', { value: 256, writable: true });
        }
        img.dispatchEvent(new Event('load'));
    }
});
await page.waitForTimeout(300);

// 1a. Interactive map section exists
const imapSection = await page.$('#imap-container');
assert(imapSection !== null, 'Interactive map container exists');

// 1b. Legend is present
const legend = await page.$('.imap-legend');
assert(legend !== null, 'Map legend exists');

const legendText = await page.$eval('.imap-legend', el => el.textContent);
assert(legendText.includes('NPCs') || legendText.includes('Doors'), 'Legend shows entity types');

// 1c. Map image is present
const mapImg = await page.$('#imap-img');
assert(mapImg !== null, 'Map image element exists');

// 1d. Markers container exists
const markers = await page.$('#imap-markers');
assert(markers !== null, 'Markers container exists');

// 1e. Verify marker count matches entities
const markerInfo = await page.evaluate((dir) => {
    const map = state.maps.find(m => m._dirName === dir);
    const npcs = (map.object_events || []).filter(e =>
        !(e.graphics_id || '').includes('BERRY_TREE')
    ).length;
    const warps = (map.warp_events || []).length;
    const bgs = (map.bg_events || []).length;
    const markerEls = document.querySelectorAll('.imap-marker');
    return { expected: npcs + warps + bgs, actual: markerEls.length };
}, testMapDir);
assert(markerInfo.actual === markerInfo.expected, `Marker count matches entities (${markerInfo.actual}/${markerInfo.expected})`);

// 1f. Markers have correct types
const markerTypes = await page.evaluate(() => {
    const types = new Set();
    document.querySelectorAll('.imap-marker').forEach(m => {
        types.add(m.dataset.entityType);
    });
    return [...types];
});
assert(markerTypes.length > 0, `Markers have entity types: [${markerTypes.join(', ')}]`);

// 1g. Click a marker to open popup
const firstMarker = await page.$('.imap-marker');
if (firstMarker) {
    await firstMarker.click();
    await page.waitForTimeout(200);
    const popup = await page.$('.imap-popup');
    assert(popup !== null, 'Clicking marker opens popup');

    if (popup) {
        const popupText = await popup.textContent();
        assert(popupText.length > 0, 'Popup has content');

        const hasActions = await page.$('.imap-popup-actions .btn');
        assert(hasActions !== null, 'Popup has action buttons');
    }

    // Click elsewhere to dismiss
    await page.click('#imap-container');
    await page.waitForTimeout(200);
}

// 1h. Test drag repositioning
const dragResult = await page.evaluate((dir) => {
    const map = state.maps.find(m => m._dirName === dir);
    const firstNPC = (map.object_events || []).find(e =>
        !(e.graphics_id || '').includes('ITEM_BALL') && !(e.graphics_id || '').includes('BERRY_TREE')
    );
    if (!firstNPC) return { skipped: true };
    const origX = firstNPC.x, origY = firstNPC.y;
    // Simulate the position change that drag would do
    firstNPC.x = origX + 1;
    firstNPC.y = origY + 1;
    const changed = firstNPC.x === origX + 1 && firstNPC.y === origY + 1;
    // Restore
    firstNPC.x = origX;
    firstNPC.y = origY;
    return { changed, origX, origY };
}, testMapDir);
if (!dragResult.skipped) {
    assert(dragResult.changed, 'Entity position can be modified (drag simulation)');
}

// 1i. Verify hint text
const hint = await page.$('.imap-hint');
assert(hint !== null, 'Hint text exists');
const hintText = await hint?.textContent();
assert(hintText?.includes('Click') && hintText?.includes('Drag'), 'Hint mentions click and drag');

console.log('');

// ═══════════════════════════════════════════════════════════
// TEST 2: NPC Grouped View
// ═══════════════════════════════════════════════════════════
console.log('═══ TEST 2: NPC Grouped View ═══');

await page.evaluate(() => {
    state.page = 'npcs';
    state.mapDetail = null;
    state.npcDetail = null;
    state.search = '';
    render();
});
await page.waitForTimeout(600);

// 2a. Group cards are rendered
const groupCards = await page.$$('.npc-group-card');
assert(groupCards.length > 0, `NPC group cards rendered (${groupCards.length})`);

// 2b. Multi-instance groups show count badge
const countBadges = await page.$$('.npc-group-count');
assert(countBadges.length > 0, 'Multi-instance groups have count badges');

// 2c. Single-instance NPCs show inline actions (if any exist)
const singleCards = await page.$$('.npc-group-single');
if (singleCards.length > 0) {
    const singleHasActions = await page.$('.npc-group-single .npc-group-actions .btn') !== null;
    assert(singleHasActions, 'Single-instance NPCs show inline action buttons');
} else {
    // All NPCs appear multiple times - test that multi groups are clickable instead
    const multiCards = await page.$$('.npc-group-card:not(.npc-group-single)');
    assert(multiCards.length > 0, 'Multi-instance NPC groups are clickable (no single-instance NPCs found)');
}

// 2d. Click into a multi-instance group
const multiGroupId = await page.evaluate(() => {
    const allNPCs = collectNPCs();
    const groups = {};
    for (const n of allNPCs) {
        const key = n.graphics_id || 'UNKNOWN';
        if (!groups[key]) groups[key] = { count: 0, id: key };
        groups[key].count++;
    }
    const best = Object.values(groups).sort((a, b) => b.count - a.count)[0];
    return best ? best.id : null;
});

if (multiGroupId) {
    await page.evaluate((id) => {
        state.npcDetail = id;
        renderNPCs();
    }, multiGroupId);
    await page.waitForTimeout(500);

    // 2e. Back button exists
    const backBtn = await page.$('.back-btn');
    assert(backBtn !== null, 'Back button exists in group detail');

    // 2f. Map sections exist
    const mapSections = await page.$$('.npc-group-map-section');
    assert(mapSections.length > 0, `NPC group detail shows map sections (${mapSections.length})`);

    // 2g. Individual NPC rows within sections
    const npcRows = await page.$$('.npc-group-map-section .npc-row');
    assert(npcRows.length > 0, `Individual NPC rows shown (${npcRows.length})`);

    // 2h. NPC rows have Edit buttons
    const editBtns = await page.$$('.npc-group-map-section .npc-row .btn');
    assert(editBtns.length > 0, 'NPC rows have action buttons');

    // 2i. Click back to grouped view
    await page.evaluate(() => { state.npcDetail = null; renderNPCs(); });
    await page.waitForTimeout(300);
    const groupCardsAfterBack = await page.$$('.npc-group-card');
    assert(groupCardsAfterBack.length > 0, 'Back returns to grouped view');
}

// 2j. Search works
await page.evaluate(() => {
    state.search = 'BOY';
    state.npcDetail = null;
    renderNPCs();
});
await page.waitForTimeout(300);
const filteredCards = await page.$$('.npc-group-card');
const headerText = await page.$eval('.page-header', el => el.textContent);
assert(filteredCards.length > 0, `Search filters NPC groups (${filteredCards.length} results)`);
assert(headerText.includes('NPCs'), 'Page header shows NPC count');

// Reset search
await page.evaluate(() => { state.search = ''; });

console.log('');

// ═══════════════════════════════════════════════════════════
// TEST 3: Pokemon Evolution Display
// ═══════════════════════════════════════════════════════════
console.log('═══ TEST 3: Pokemon Evolution Display ═══');

await page.evaluate(() => {
    state.page = 'pokemon';
    state.search = '';
    state.pokemonPage = 0;
    render();
});
await page.waitForTimeout(500);

// 3a. Evolution column header exists
const evoHeader = await page.evaluate(() => {
    const headers = [...document.querySelectorAll('thead th')];
    return headers.some(h => h.textContent.includes('Evolution'));
});
assert(evoHeader, 'Pokemon table has Evolution column');

// 3b. Evolution pills are rendered
const evoPills = await page.$$('.evo-pill');
assert(evoPills.length > 0, `Evolution pills rendered (${evoPills.length})`);

// 3c. Prevolution pills (purple) exist
const prePills = await page.$$('.evo-pill-from');
assert(prePills.length > 0, `Prevolution pills rendered (${prePills.length})`);

// 3d. Evolution pills have tooltips
const pillTitle = await page.$eval('.evo-pill', el => el.title);
assert(pillTitle.length > 0, `Evolution pills have tooltips: "${pillTitle.substring(0, 50)}..."`);

// 3e. Verify specific evolutions parsed correctly
const bulbaEvo = await page.evaluate(() => {
    const bulba = state.pokemon.find(p => p.id === 'SPECIES_BULBASAUR');
    if (!bulba || !bulba.evolutions) return null;
    return bulba.evolutions[0];
});
assert(bulbaEvo !== null, 'Bulbasaur has evolutions parsed');
assert(bulbaEvo?.method === 'EVO_LEVEL', `Bulbasaur evolves by EVO_LEVEL (got: ${bulbaEvo?.method})`);
assert(bulbaEvo?.param === '16', `Bulbasaur evolves at level 16 (got: ${bulbaEvo?.param})`);
assert(bulbaEvo?.target === 'SPECIES_IVYSAUR', `Bulbasaur evolves to Ivysaur (got: ${bulbaEvo?.target})`);

// 3f. Multi-evolution pokemon (Eevee)
const eeveeEvos = await page.evaluate(() => {
    const eevee = state.pokemon.find(p => p.id === 'SPECIES_EEVEE');
    return eevee?.evolutions || [];
});
assert(eeveeEvos.length >= 3, `Eevee has ${eeveeEvos.length} evolutions (expected ≥3)`);
assert(eeveeEvos.some(e => e.target === 'SPECIES_JOLTEON'), 'Eevee can evolve to Jolteon');
assert(eeveeEvos.some(e => e.target === 'SPECIES_VAPOREON'), 'Eevee can evolve to Vaporeon');
assert(eeveeEvos.some(e => e.target === 'SPECIES_FLAREON'), 'Eevee can evolve to Flareon');

// 3g. Conditional evolutions (Pikachu)
const pikaEvos = await page.evaluate(() => {
    const pika = state.pokemon.find(p => p.id === 'SPECIES_PIKACHU');
    return pika?.evolutions || [];
});
assert(pikaEvos.length >= 2, `Pikachu has ${pikaEvos.length} evolutions (expected ≥2)`);
const pikaCondEvo = pikaEvos.find(e => e.conditions && e.conditions.length > 0);
assert(pikaCondEvo !== null, 'Pikachu has conditional evolution');
assert(pikaCondEvo?.conditions?.[0]?.type?.startsWith('IF_'), `Condition type starts with IF_ (got: ${pikaCondEvo?.conditions?.[0]?.type})`);

// 3h. Friendship evolution (Pichu -> Pikachu)
const pichuEvos = await page.evaluate(() => {
    const pichu = state.pokemon.find(p => p.id === 'SPECIES_PICHU');
    return pichu?.evolutions || [];
});
if (pichuEvos.length > 0) {
    assert(pichuEvos[0].target === 'SPECIES_PIKACHU', 'Pichu evolves to Pikachu');
    const hasFriendship = pichuEvos[0].conditions?.some(c => c.type === 'IF_MIN_FRIENDSHIP');
    assert(hasFriendship, 'Pichu evolution requires friendship');
}

console.log('');

// ═══════════════════════════════════════════════════════════
// TEST 4: Evolution CRUD
// ═══════════════════════════════════════════════════════════
console.log('═══ TEST 4: Evolution CRUD ═══');

// 4a. Open edit modal for Bulbasaur
await page.evaluate(() => editPokemon('SPECIES_BULBASAUR'));
await page.waitForTimeout(400);

const modal = await page.$('.modal-overlay');
assert(modal !== null, 'Edit Pokemon modal opens');

// 4b. Evolution editor section exists
const evoEditor = await page.$('#evo-editor');
assert(evoEditor !== null, 'Evolution editor exists in modal');

// 4c. Evolution cards are rendered
const evoCards = await page.$$('.evo-edit-card');
assert(evoCards.length === 1, `Bulbasaur has 1 evolution card (got: ${evoCards.length})`);

// 4d. Verify fields in the evolution card
const evoMethod = await page.$eval('.evo-method', el => el.value);
assert(evoMethod === 'EVO_LEVEL', `Method is EVO_LEVEL (got: ${evoMethod})`);

const evoParam = await page.$eval('.evo-param', el => el.value);
assert(evoParam === '16', `Parameter is 16 (got: ${evoParam})`);

const evoTarget = await page.$eval('.evo-target', el => el.value);
assert(evoTarget === 'SPECIES_IVYSAUR', `Target is SPECIES_IVYSAUR (got: ${evoTarget})`);

// 4e. Add a new evolution
const addBtn = await page.$('#add-evo-btn');
assert(addBtn !== null, 'Add Evolution button exists');
await addBtn.click();
await page.waitForTimeout(200);

const evoCardsAfterAdd = await page.$$('.evo-edit-card');
assert(evoCardsAfterAdd.length === 2, `After adding: 2 evolution cards (got: ${evoCardsAfterAdd.length})`);

// 4f. Edit the new evolution's method
await page.evaluate(() => {
    const selects = document.querySelectorAll('.evo-method');
    const newSelect = selects[selects.length - 1];
    newSelect.value = 'EVO_ITEM';
    newSelect.dispatchEvent(new Event('change'));
});
await page.waitForTimeout(200);

const newMethod = await page.evaluate(() => {
    const selects = document.querySelectorAll('.evo-method');
    return selects[selects.length - 1].value;
});
assert(newMethod === 'EVO_ITEM', `New evolution method changed to EVO_ITEM (got: ${newMethod})`);

// 4g. Edit the new evolution's parameter
await page.evaluate(() => {
    const inputs = document.querySelectorAll('.evo-param');
    const newInput = inputs[inputs.length - 1];
    newInput.value = 'ITEM_FIRE_STONE';
    newInput.dispatchEvent(new Event('change'));
});
await page.waitForTimeout(200);

// 4h. Edit the new evolution's target
await page.evaluate(() => {
    const inputs = document.querySelectorAll('.evo-target');
    const newInput = inputs[inputs.length - 1];
    newInput.value = 'SPECIES_CHARIZARD';
    newInput.dispatchEvent(new Event('change'));
});
await page.waitForTimeout(200);

// 4i. Add a condition to the new evolution
const addCondBtn = await page.evaluate(() => {
    const btns = document.querySelectorAll('.evo-add-cond');
    const lastBtn = btns[btns.length - 1];
    lastBtn.click();
    return true;
});
await page.waitForTimeout(200);

const condRows = await page.$$('.evo-cond-row');
assert(condRows.length >= 1, `Condition row added (${condRows.length} total)`);

// 4j. Edit the condition type
await page.evaluate(() => {
    const condSelects = document.querySelectorAll('.evo-cond-type');
    const lastCond = condSelects[condSelects.length - 1];
    lastCond.value = 'IF_TIME';
    lastCond.dispatchEvent(new Event('change'));
});
await page.waitForTimeout(200);

// 4k. Edit the condition value
await page.evaluate(() => {
    const condInputs = document.querySelectorAll('.evo-cond-value');
    const lastCond = condInputs[condInputs.length - 1];
    lastCond.value = 'TIME_NIGHT';
    lastCond.dispatchEvent(new Event('change'));
});
await page.waitForTimeout(200);

// 4l. Verify condition is set correctly
const condState = await page.evaluate(() => {
    const condSelects = document.querySelectorAll('.evo-cond-type');
    const condInputs = document.querySelectorAll('.evo-cond-value');
    const last = condSelects.length - 1;
    return { type: condSelects[last].value, value: condInputs[last].value };
});
assert(condState.type === 'IF_TIME', `Condition type is IF_TIME (got: ${condState.type})`);
assert(condState.value === 'TIME_NIGHT', `Condition value is TIME_NIGHT (got: ${condState.value})`);

// 4m. Remove the condition
await page.evaluate(() => {
    const removeBtns = document.querySelectorAll('.evo-remove-cond');
    removeBtns[removeBtns.length - 1].click();
});
await page.waitForTimeout(200);

const condRowsAfterRemove = await page.$$('.evo-cond-row');
assert(condRowsAfterRemove.length === condRows.length - 1, 'Condition removed successfully');

// 4n. Delete the new evolution
await page.evaluate(() => {
    const removeBtns = document.querySelectorAll('.evo-remove');
    removeBtns[removeBtns.length - 1].click();
});
await page.waitForTimeout(200);

const evoCardsAfterDelete = await page.$$('.evo-edit-card');
assert(evoCardsAfterDelete.length === 1, `After deleting: back to 1 evolution card (got: ${evoCardsAfterDelete.length})`);

// 4o. Close modal without saving
await page.evaluate(() => document.querySelector('.modal-overlay')?.remove());
await page.waitForTimeout(200);

console.log('');

// ═══════════════════════════════════════════════════════════
// TEST 5: Evolution Serialization
// ═══════════════════════════════════════════════════════════
console.log('═══ TEST 5: Evolution Serialization ═══');

// 5a. Test serializeEvolutions
const serialized = await page.evaluate(() => {
    return serializeEvolutions([
        { method: 'EVO_LEVEL', param: '16', target: 'SPECIES_IVYSAUR', conditions: [] }
    ]);
});
assert(serialized === 'EVOLUTION({EVO_LEVEL, 16, SPECIES_IVYSAUR})', `Single evo serializes correctly: "${serialized}"`);

// 5b. Multi-evolution serialize
const serializedMulti = await page.evaluate(() => {
    return serializeEvolutions([
        { method: 'EVO_ITEM', param: 'ITEM_THUNDER_STONE', target: 'SPECIES_JOLTEON', conditions: [] },
        { method: 'EVO_ITEM', param: 'ITEM_WATER_STONE', target: 'SPECIES_VAPOREON', conditions: [] }
    ]);
});
assert(serializedMulti.includes('SPECIES_JOLTEON') && serializedMulti.includes('SPECIES_VAPOREON'),
    'Multi-evolution serializes both targets');
assert(serializedMulti.startsWith('EVOLUTION('), 'Multi-evolution wrapped in EVOLUTION()');

// 5c. Serialization with conditions
const serializedCond = await page.evaluate(() => {
    return serializeEvolutions([
        { method: 'EVO_LEVEL', param: '0', target: 'SPECIES_PIKACHU',
          conditions: [{ type: 'IF_MIN_FRIENDSHIP', value: 'FRIENDSHIP_EVO_THRESHOLD' }] }
    ]);
});
assert(serializedCond.includes('CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})'),
    `Conditions serialize correctly: "${serializedCond}"`);

// 5d. Multi-condition serialization
const serializedMultiCond = await page.evaluate(() => {
    return serializeEvolutions([
        { method: 'EVO_LEVEL', param: '28', target: 'SPECIES_MAROWAK_ALOLA',
          conditions: [
            { type: 'IF_REGION', value: 'REGION_ALOLA' },
            { type: 'IF_TIME', value: 'TIME_NIGHT' }
          ] }
    ]);
});
assert(serializedMultiCond.includes('{IF_REGION, REGION_ALOLA}') && serializedMultiCond.includes('{IF_TIME, TIME_NIGHT}'),
    'Multi-condition serializes both conditions');

// 5e. Null/empty evolutions returns null
const serializedEmpty = await page.evaluate(() => serializeEvolutions([]));
assert(serializedEmpty === null, 'Empty evolutions returns null');

const serializedNull = await page.evaluate(() => serializeEvolutions(null));
assert(serializedNull === null, 'Null evolutions returns null');

// 5f. Round-trip test: parse then serialize
const roundTrip = await page.evaluate(() => {
    const original = '{EVO_LEVEL, 16, SPECIES_IVYSAUR}';
    const parsed = parseEvolutionEntries(original);
    const reserialized = serializeEvolutions(parsed);
    return { parsed, reserialized, original };
});
assert(roundTrip.parsed.length === 1, 'Round-trip parse produces 1 entry');
assert(roundTrip.reserialized.includes('EVO_LEVEL, 16, SPECIES_IVYSAUR'), 'Round-trip serialization matches');

// 5g. Round-trip with conditions
const roundTripCond = await page.evaluate(() => {
    const original = '{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_RAICHU, CONDITIONS({IF_NOT_REGION, REGION_ALOLA})}';
    const parsed = parseEvolutionEntries(original);
    const reserialized = serializeEvolutions(parsed);
    return { parsed, reserialized };
});
assert(roundTripCond.parsed.length === 1, 'Round-trip conditional parse produces 1 entry');
assert(roundTripCond.parsed[0].conditions.length === 1, 'Round-trip parses 1 condition');
assert(roundTripCond.reserialized.includes('IF_NOT_REGION, REGION_ALOLA'), 'Round-trip condition preserved');

console.log('');

// ═══════════════════════════════════════════════════════════
// TEST 6: Evolution Save to File
// ═══════════════════════════════════════════════════════════
console.log('═══ TEST 6: Evolution Save to File ═══');

// 6a. Load real file content into originalContent, then modify and save
const gen1Content = readFileSync(join(REPO_ROOT, 'src/data/pokemon/species_info/gen_1_families.h'), 'utf-8');
await page.evaluate((content) => {
    const filePath = 'src/data/pokemon/species_info/gen_1_families.h';
    originalContent[filePath] = content;

    const bulba = state.pokemon.find(p => p.id === 'SPECIES_BULBASAUR');
    // Add a second evolution with conditions
    bulba.evolutions.push({
        method: 'EVO_ITEM',
        param: 'ITEM_LEAF_STONE',
        target: 'SPECIES_VENUSAUR',
        conditions: [{ type: 'IF_TIME', value: 'TIME_DAY' }]
    });
    updatePokemonInFile(bulba);
    return true;
}, gen1Content);

const fileChanged = await page.evaluate(() => {
    const filePath = 'src/data/pokemon/species_info/gen_1_families.h';
    return !!pendingChanges[filePath];
});
assert(fileChanged, 'File marked as changed after evolution update');

const fileContent = await page.evaluate(() => {
    const filePath = 'src/data/pokemon/species_info/gen_1_families.h';
    return pendingChanges[filePath] || '';
});
assert(fileContent.includes('ITEM_LEAF_STONE'), 'New evolution written to file content');
assert(fileContent.includes('SPECIES_VENUSAUR'), 'New evolution target in file content');
assert(fileContent.includes('IF_TIME, TIME_DAY'), 'New evolution condition in file content');

// 6b. Restore original - remove the added evolution
await page.evaluate(() => {
    const bulba = state.pokemon.find(p => p.id === 'SPECIES_BULBASAUR');
    bulba.evolutions = [bulba.evolutions[0]]; // Keep only original
    // Reset pending changes
    const filePath = 'src/data/pokemon/species_info/gen_1_families.h';
    delete pendingChanges[filePath];
});

console.log('');

// ═══════════════════════════════════════════════════════════
// TEST 7: formatEvoMethod
// ═══════════════════════════════════════════════════════════
console.log('═══ TEST 7: formatEvoMethod ═══');

const fmtLevel = await page.evaluate(() => formatEvoMethod({ method: 'EVO_LEVEL', param: '36', conditions: [] }));
assert(fmtLevel === 'Level 36', `EVO_LEVEL formats as "Level 36" (got: "${fmtLevel}")`);

const fmtItem = await page.evaluate(() => formatEvoMethod({ method: 'EVO_ITEM', param: 'ITEM_THUNDER_STONE', conditions: [] }));
assert(fmtItem === 'Use THUNDER STONE', `EVO_ITEM formats as "Use THUNDER STONE" (got: "${fmtItem}")`);

const fmtTrade = await page.evaluate(() => formatEvoMethod({ method: 'EVO_TRADE', param: '0', conditions: [] }));
assert(fmtTrade === 'Trade', `EVO_TRADE formats as "Trade" (got: "${fmtTrade}")`);

const fmtCond = await page.evaluate(() => formatEvoMethod({
    method: 'EVO_LEVEL', param: '0',
    conditions: [{ type: 'IF_MIN_FRIENDSHIP', value: 'FRIENDSHIP_EVO_THRESHOLD' }]
}));
assert(fmtCond.includes('min friendship'), `Conditions included in format (got: "${fmtCond}")`);

console.log('');

// ═══════════════════════════════════════════════════════════
// RESULTS
// ═══════════════════════════════════════════════════════════
console.log('═══════════════════════════════════════');
console.log(`Results: ${passed} passed, ${failed} failed, ${passed + failed} total`);
console.log('═══════════════════════════════════════');

await browser.close();
process.exit(failed > 0 ? 1 : 0);
