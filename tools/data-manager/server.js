const express = require('express');
const path = require('path');
const fs = require('fs');
const multer = require('multer');

const app = express();
const PORT = 3000;
const ROOT = path.resolve(__dirname, '..', '..');

// Multer storage for MIDI uploads
const midiStorage = multer.diskStorage({
    destination: path.join(ROOT, 'sound/songs/midi'),
    filename: (req, file, cb) => {
        // Sanitize: lowercase, replace spaces with underscores, ensure .mid extension
        let name = file.originalname.toLowerCase().replace(/\s+/g, '_');
        if (!name.startsWith('mus_')) name = 'mus_' + name;
        if (!name.endsWith('.mid')) name = name.replace(/\.[^.]+$/, '') + '.mid';
        cb(null, name);
    }
});
const uploadMidi = multer({
    storage: midiStorage,
    fileFilter: (req, file, cb) => {
        const ext = path.extname(file.originalname).toLowerCase();
        if (ext === '.mid' || ext === '.midi') {
            cb(null, true);
        } else {
            cb(new Error('Only MIDI files (.mid, .midi) are allowed'));
        }
    },
    limits: { fileSize: 5 * 1024 * 1024 } // 5MB limit
});

app.use(express.json({ limit: '50mb' }));
app.use(express.static(path.join(__dirname, 'public')));

// ─── Parsers ────────────────────────────────────────────────────────────────

function parseTrainers(content) {
    const trainers = [];
    const trainerBlocks = content.split(/^=== (TRAINER_\w+) ===/m);
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
    const headerComment = `/*
Trainers and their parties defined with Competetive Syntax.
Compatible with Pokemon Showdown exports.
https://github.com/smogon/pokemon-showdown/blob/master/sim/TEAMS.md

A trainer specification starts with "=== TRAINER_XXXX ==="
and includes everything until the next line that starts with "==="
or the file ends.
A blank line is required between the trainer and their Pokemon
and between their Pokemon.
TRAINER_XXXX is how the trainer is referred to within code.

Fields with description and/or example of usage
Required fields for trainers:
    - Name
    - Pic
Optional (but still recommended) fields for trainers:
    - Class (if not specified, PkMn Trainer will be used)
    - Gender (Male/Female, affects random gender weights of party if not specified)
    - Music
    - Items (Some Item / Another Item / Third Item)
            (Can also be specified with ITEM_SOME_ITEM)
    - Battle Type (Singles / Doubles, defaults to Singles)
    - AI (Ai Flag / Another Flag / Third Flag / ...
          see "constants/battle_ai.h" for all flags)
    - Mugshot (enable Mugshots during battle transition
               set to one of Purple, Green, Pink, Blue or Yellow)
    - Starting Status (see include/constants/battle.h for values)

Pokemon are then specified using the Showdown Export format.
If a field is not specified, it will use it's default value.

Required fields for Pokemon:
    - Species (Either as SPECIES_ABRA or Abra)
      This line also specifies Gender, Nickname and Held item.
      Alfred (Abra) (M) @ Eviolite
      Roberta (SPECIES_ABRA) (F) @ ITEM_CHOICE_SPECS
      Both lines are valid. Gender (M) or (F) must use a capital letter.
      Nickname length is limited to 10 characters using standard letters.
      With narrow font it's increased to 12. Longer strings will be silently shortened.

Optional fields for Pokemon:
    - Level (Number between 1 and 100, defaults to 100)
    - Ability (Ability Name or ABILITY_ABILITY_NAME)
    - IVs (0 HP / 1 Atk / 2 Def / 3 SpA / 4 SpD / 5 Spe, defaults to all 31)
          (Order does not matter)
    - EVs (252 HP / 128 Spe / 48 Def, defaults to all 0, is not capped at 512 total)
          (Order does not matter)
    - Ball (Poke Ball or ITEM_POKE_BALL, defaults to Poke Ball)
    - Happiness (Number between 1 and 255)
    - Nature (Rash or NATURE_RASH, defaults to Hardy)
    - Shiny (Yes/No, defaults to No)
    - Dynamax Level (Number between 0 and 10, default 10, also sets "shouldDynamax" to True)
    - Gigantamax (Yes/No, sets to Gigantamax factor)
                 (doesn't do anything to Pokemon without a Gigantamax form, also sets "shouldDynamax" to True)
    - Tera Type (Set to a Type, either Fire or TYPE_FIRE, also sets "shouldTerastal" to True)
Moves are defined with a - (dash) followed by a single space, then the move name.
Either "- Tackle" or "- MOVE_TACKLE" works. One move per line.
Moves have to be the last lines of a Pokemon.
If no moves are specified, the Pokemon will use the last 4 moves it learns
through levelup at its level.

Default IVs and Level can be changed in the "main" function of tools/trainerproc/main.c

This file is processed with a custom preprocessor.
*/

`;
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

function parseAbilities(content) {
    const abilities = [];
    const regex = /\[(\w+)\]\s*=\s*\{([^}]+)\}/g;
    let match;
    while ((match = regex.exec(content)) !== null) {
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

function parseMoves(content) {
    const moves = [];
    const regex = /\[(MOVE_\w+)\]\s*=\s*\{([\s\S]*?)\n    \}/g;
    let match;
    while ((match = regex.exec(content)) !== null) {
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
        if (nameMatch) move.name = nameMatch[1];
        if (descMatch) move.description = descMatch[1] || descMatch[2];
        if (powerMatch) move.power = powerMatch[1];
        if (typeMatch) move.type = typeMatch[1].replace('TYPE_', '');
        if (accMatch) move.accuracy = accMatch[1];
        if (ppMatch) move.pp = ppMatch[1];
        if (catMatch) move.category = catMatch[1].replace('DAMAGE_CATEGORY_', '');
        if (prioMatch) move.priority = parseInt(prioMatch[1]);
        moves.push(move);
    }
    return moves;
}

function parseItems(content) {
    const items = [];
    const regex = /\[(ITEM_\w+)\]\s*=\s*\{([\s\S]*?)\n    \}/g;
    let match;
    while ((match = regex.exec(content)) !== null) {
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

function parseConfig(content, filename) {
    const settings = [];
    const lines = content.split('\n');
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

// ─── Serializers for C header files ─────────────────────────────────────────

function updateCHeaderField(content, id, field, newValue) {
    // Find the block for [ID] = { ... }
    const blockRegex = new RegExp(`(\\[${id}\\]\\s*=\\s*\\{)([\\s\\S]*?)(\\n    \\})`, 'g');
    return content.replace(blockRegex, (match, prefix, body, suffix) => {
        const fieldRegex = new RegExp(`(\\.${field}\\s*=\\s*)([^,\\n]+)`);
        const newBody = body.replace(fieldRegex, `$1${newValue}`);
        return prefix + newBody + suffix;
    });
}

// ─── API Routes ─────────────────────────────────────────────────────────────

// Trainers
app.get('/api/trainers', (req, res) => {
    try {
        const content = fs.readFileSync(path.join(ROOT, 'src/data/trainers.party'), 'utf-8');
        res.json(parseTrainers(content));
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/trainers', (req, res) => {
    try {
        const output = serializeTrainers(req.body);
        fs.writeFileSync(path.join(ROOT, 'src/data/trainers.party'), output, 'utf-8');
        res.json({ success: true });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Wild Encounters
app.get('/api/encounters', (req, res) => {
    try {
        const data = JSON.parse(fs.readFileSync(path.join(ROOT, 'src/data/wild_encounters.json'), 'utf-8'));
        res.json(data);
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/encounters', (req, res) => {
    try {
        fs.writeFileSync(path.join(ROOT, 'src/data/wild_encounters.json'), JSON.stringify(req.body, null, 2) + '\n', 'utf-8');
        res.json({ success: true });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Moves (now editable)
app.get('/api/moves', (req, res) => {
    try {
        const content = fs.readFileSync(path.join(ROOT, 'src/data/moves_info.h'), 'utf-8');
        res.json(parseMoves(content));
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/moves', (req, res) => {
    try {
        const { id, field, value } = req.body;
        const filePath = path.join(ROOT, 'src/data/moves_info.h');
        let content = fs.readFileSync(filePath, 'utf-8');

        // Map frontend field names to C struct fields and format values
        const fieldMap = {
            name: { cField: 'name', format: v => `COMPOUND_STRING("${v}")` },
            description: { cField: 'description', format: v => `COMPOUND_STRING("${v}")` },
            power: { cField: 'power', format: v => v },
            type: { cField: 'type', format: v => v.startsWith('TYPE_') ? v : `TYPE_${v}` },
            accuracy: { cField: 'accuracy', format: v => v },
            pp: { cField: 'pp', format: v => v },
            category: { cField: 'category', format: v => v.startsWith('DAMAGE_CATEGORY_') ? v : `DAMAGE_CATEGORY_${v}` },
            priority: { cField: 'priority', format: v => v },
        };

        const mapping = fieldMap[field];
        if (!mapping) return res.status(400).json({ error: `Unknown field: ${field}` });

        content = updateCHeaderField(content, id, mapping.cField, mapping.format(value));
        fs.writeFileSync(filePath, content, 'utf-8');
        res.json({ success: true });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Items (now editable)
app.get('/api/items', (req, res) => {
    try {
        const content = fs.readFileSync(path.join(ROOT, 'src/data/items.h'), 'utf-8');
        res.json(parseItems(content));
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/items', (req, res) => {
    try {
        const { id, field, value } = req.body;
        const filePath = path.join(ROOT, 'src/data/items.h');
        let content = fs.readFileSync(filePath, 'utf-8');

        const fieldMap = {
            name: { cField: 'name', format: v => `_("${v}")` },
            price: { cField: 'price', format: v => v },
            pocket: { cField: 'pocket', format: v => v.startsWith('POCKET_') ? v : `POCKET_${v}` },
            importance: { cField: 'importance', format: v => v },
        };

        const mapping = fieldMap[field];
        if (!mapping) return res.status(400).json({ error: `Unknown field: ${field}` });

        content = updateCHeaderField(content, id, mapping.cField, mapping.format(value));
        fs.writeFileSync(filePath, content, 'utf-8');
        res.json({ success: true });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Abilities (now editable)
app.get('/api/abilities', (req, res) => {
    try {
        const content = fs.readFileSync(path.join(ROOT, 'src/data/abilities.h'), 'utf-8');
        res.json(parseAbilities(content));
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/abilities', (req, res) => {
    try {
        const { id, field, value } = req.body;
        const filePath = path.join(ROOT, 'src/data/abilities.h');
        let content = fs.readFileSync(filePath, 'utf-8');

        const fieldMap = {
            name: { cField: 'name', format: v => `_("${v}")` },
            description: { cField: 'description', format: v => `COMPOUND_STRING("${v}")` },
            aiRating: { cField: 'aiRating', format: v => v },
            breakable: { cField: 'breakable', format: v => v },
            cantBeSwapped: { cField: 'cantBeSwapped', format: v => v },
            cantBeTraced: { cField: 'cantBeTraced', format: v => v },
        };

        const mapping = fieldMap[field];
        if (!mapping) return res.status(400).json({ error: `Unknown field: ${field}` });

        content = updateCHeaderField(content, id, mapping.cField, mapping.format(value));
        fs.writeFileSync(filePath, content, 'utf-8');
        res.json({ success: true });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Routes/Maps
app.get('/api/maps', (req, res) => {
    try {
        const mapsDir = path.join(ROOT, 'data/maps');
        const mapFolders = fs.readdirSync(mapsDir).filter(f => {
            return fs.statSync(path.join(mapsDir, f)).isDirectory();
        });
        const maps = [];
        for (const folder of mapFolders) {
            const mapJsonPath = path.join(mapsDir, folder, 'map.json');
            if (!fs.existsSync(mapJsonPath)) continue;
            try {
                const mapData = JSON.parse(fs.readFileSync(mapJsonPath, 'utf-8'));
                // Extract trainers from scripts.inc if it exists
                const trainersOnMap = [];
                const scriptsPath = path.join(mapsDir, folder, 'scripts.inc');
                if (fs.existsSync(scriptsPath)) {
                    const scripts = fs.readFileSync(scriptsPath, 'utf-8');
                    const trainerRegex = /trainerbattle_(?:single|double|rematch)\s+(TRAINER_\w+)/g;
                    let m;
                    const seen = new Set();
                    while ((m = trainerRegex.exec(scripts)) !== null) {
                        if (!seen.has(m[1])) {
                            seen.add(m[1]);
                            trainersOnMap.push(m[1]);
                        }
                    }
                }
                maps.push({
                    folder,
                    id: mapData.id,
                    name: mapData.name,
                    layout: mapData.layout,
                    music: mapData.music,
                    weather: mapData.weather,
                    map_type: mapData.map_type,
                    region_map_section: mapData.region_map_section,
                    allow_cycling: mapData.allow_cycling,
                    allow_escaping: mapData.allow_escaping,
                    allow_running: mapData.allow_running,
                    show_map_name: mapData.show_map_name,
                    requires_flash: mapData.requires_flash,
                    battle_scene: mapData.battle_scene,
                    connections: mapData.connections || [],
                    object_events_count: (mapData.object_events || []).length,
                    warp_events_count: (mapData.warp_events || []).length,
                    trainers: trainersOnMap,
                });
            } catch (e) { /* skip malformed map.json */ }
        }
        res.json(maps);
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.get('/api/maps/:folder', (req, res) => {
    try {
        const mapJsonPath = path.join(ROOT, 'data/maps', req.params.folder, 'map.json');
        const mapData = JSON.parse(fs.readFileSync(mapJsonPath, 'utf-8'));

        // Get trainers from scripts
        const trainersOnMap = [];
        const scriptsPath = path.join(ROOT, 'data/maps', req.params.folder, 'scripts.inc');
        if (fs.existsSync(scriptsPath)) {
            const scripts = fs.readFileSync(scriptsPath, 'utf-8');
            const trainerRegex = /trainerbattle_(?:single|double|rematch)\s+(TRAINER_\w+)/g;
            let m;
            const seen = new Set();
            while ((m = trainerRegex.exec(scripts)) !== null) {
                if (!seen.has(m[1])) {
                    seen.add(m[1]);
                    trainersOnMap.push(m[1]);
                }
            }
        }

        mapData.trainers = trainersOnMap;
        mapData.folder = req.params.folder;
        res.json(mapData);
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/maps/:folder', (req, res) => {
    try {
        const mapJsonPath = path.join(ROOT, 'data/maps', req.params.folder, 'map.json');
        const mapData = JSON.parse(fs.readFileSync(mapJsonPath, 'utf-8'));

        // Update allowed fields
        const editableFields = ['music', 'weather', 'map_type', 'allow_cycling', 'allow_escaping',
            'allow_running', 'show_map_name', 'requires_flash', 'battle_scene'];
        for (const field of editableFields) {
            if (req.body[field] !== undefined) {
                mapData[field] = req.body[field];
            }
        }

        fs.writeFileSync(mapJsonPath, JSON.stringify(mapData, null, 2) + '\n', 'utf-8');
        res.json({ success: true });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Config
app.get('/api/config', (req, res) => {
    try {
        const configDir = path.join(ROOT, 'include/config');
        const files = fs.readdirSync(configDir).filter(f => f.endsWith('.h'));
        const allSettings = [];
        for (const file of files) {
            const content = fs.readFileSync(path.join(configDir, file), 'utf-8');
            allSettings.push(...parseConfig(content, file));
        }
        res.json(allSettings);
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/config', (req, res) => {
    try {
        const { file, name, value } = req.body;
        const filePath = path.join(ROOT, 'include/config', file);
        let content = fs.readFileSync(filePath, 'utf-8');
        const regex = new RegExp(`^(#define\\s+${name}\\s+)(.+?)(\\s*(?:\\/\\/.*)?)$`, 'm');
        content = content.replace(regex, `$1${value}$3`);
        fs.writeFileSync(filePath, content, 'utf-8');
        res.json({ success: true });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// ─── Music ──────────────────────────────────────────────────────────────────

// List all music tracks (MUS_ constants from songs.h) with MIDI file availability
app.get('/api/music', (req, res) => {
    try {
        const songsH = fs.readFileSync(path.join(ROOT, 'include/constants/songs.h'), 'utf-8');
        const midiDir = path.join(ROOT, 'sound/songs/midi');
        const midiFiles = fs.readdirSync(midiDir).filter(f => f.endsWith('.mid'));

        const tracks = [];
        const musRegex = /^#define\s+(MUS_\w+)\s+(\d+)\s*\/\/\s*(.*)?$/gm;
        let match;
        while ((match = musRegex.exec(songsH)) !== null) {
            const id = match[1];
            const num = parseInt(match[2]);
            const comment = (match[3] || '').trim();
            // Map MUS_ROUTE101 -> mus_route101.mid
            const expectedFile = id.toLowerCase() + '.mid';
            const hasMidi = midiFiles.includes(expectedFile);
            tracks.push({ id, num, comment, file: hasMidi ? expectedFile : null });
        }
        // Also include any MIDI files that don't have a matching constant
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

        res.json(tracks);
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Serve a MIDI file for playback
app.get('/api/music/file/:filename', (req, res) => {
    const filename = path.basename(req.params.filename);
    const filePath = path.join(ROOT, 'sound/songs/midi', filename);
    if (!fs.existsSync(filePath)) {
        return res.status(404).json({ error: 'MIDI file not found' });
    }
    res.setHeader('Content-Type', 'audio/midi');
    res.sendFile(filePath);
});

// Upload a new MIDI file
app.post('/api/music/upload', uploadMidi.single('midi'), (req, res) => {
    try {
        if (!req.file) {
            return res.status(400).json({ error: 'No file uploaded' });
        }

        const filename = req.file.filename;
        const trackName = filename.replace('.mid', '');

        // Add to midi.cfg if not already present
        const cfgPath = path.join(ROOT, 'sound/songs/midi/midi.cfg');
        let cfg = fs.readFileSync(cfgPath, 'utf-8');
        if (!cfg.includes(filename)) {
            // Use a default voice group and settings
            const entry = `${filename}:${' '.repeat(Math.max(1, 30 - filename.length))}-E -R50 -V080`;
            cfg = cfg.trimEnd() + '\n' + entry + '\n';
            fs.writeFileSync(cfgPath, cfg, 'utf-8');
        }

        res.json({
            success: true,
            filename,
            trackName,
            message: `Uploaded ${filename}. Add a MUS_ constant to songs.h and register in song_table.inc to use in-game.`
        });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Delete a custom MIDI file
app.delete('/api/music/file/:filename', (req, res) => {
    try {
        const filename = path.basename(req.params.filename);
        const filePath = path.join(ROOT, 'sound/songs/midi', filename);
        if (!fs.existsSync(filePath)) {
            return res.status(404).json({ error: 'File not found' });
        }
        fs.unlinkSync(filePath);

        // Remove from midi.cfg
        const cfgPath = path.join(ROOT, 'sound/songs/midi/midi.cfg');
        let cfg = fs.readFileSync(cfgPath, 'utf-8');
        const lines = cfg.split('\n').filter(line => !line.startsWith(filename + ':'));
        fs.writeFileSync(cfgPath, lines.join('\n'), 'utf-8');

        res.json({ success: true });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

// Dashboard stats
app.get('/api/stats', (req, res) => {
    try {
        const trainers = fs.readFileSync(path.join(ROOT, 'src/data/trainers.party'), 'utf-8');
        const trainerCount = (trainers.match(/^===/gm) || []).length / 2;
        const encounters = JSON.parse(fs.readFileSync(path.join(ROOT, 'src/data/wild_encounters.json'), 'utf-8'));
        const encounterCount = encounters.wild_encounter_groups?.[0]?.encounters?.length || 0;
        const configDir = path.join(ROOT, 'include/config');
        const configFiles = fs.readdirSync(configDir).filter(f => f.endsWith('.h'));
        let configCount = 0;
        for (const file of configFiles) {
            const content = fs.readFileSync(path.join(configDir, file), 'utf-8');
            configCount += parseConfig(content, file).length;
        }
        // Count maps
        const mapsDir = path.join(ROOT, 'data/maps');
        const mapCount = fs.readdirSync(mapsDir).filter(f => {
            return fs.statSync(path.join(mapsDir, f)).isDirectory() &&
                fs.existsSync(path.join(mapsDir, f, 'map.json'));
        }).length;
        res.json({
            trainers: trainerCount,
            encounters: encounterCount,
            configSettings: configCount,
            configFiles: configFiles.length,
            maps: mapCount
        });
    } catch (e) { res.status(500).json({ error: e.message }); }
});

app.listen(PORT, () => {
    console.log(`\n  Pokemon Brazilianite Data Manager`);
    console.log(`  ─────────────────────────────────`);
    console.log(`  Running at http://localhost:${PORT}\n`);
});
