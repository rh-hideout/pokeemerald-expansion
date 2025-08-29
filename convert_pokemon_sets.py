import json
import os
import re
from itertools import product

# --- CONFIGURATION ---
INPUT_DIR = "tiers"
MONS_FILE = "src/data/battle_frontier/battle_frontier_mons.h"
CONSTS_FILE = "include/constants/battle_frontier_mons.h"
HIDDEN_POWER_REGEX = re.compile(r"^HIDDEN_POWER_([A-Z]+)$", re.IGNORECASE)

# --- HELPERS ---
def sanitize_name(name):
    name = name.replace("'", "").replace("É", "E")
    name = re.sub(r"[^A-Za-z0-9]", "_", name)
    name = re.sub(r"_+", "_", name).strip("_")  # collapse __ and trim _
    return name.upper()

def format_evs(evs):
    ev_order = ["hp", "atk", "def", "spa", "spd", "spe"]
    values = [evs.get(stat, 0) for stat in ev_order]
    return f"TRAINER_PARTY_EVS({', '.join(str(v) for v in values)})"

def format_moves(moves):
    def clean(move):
        return move.upper().replace("'", "").replace(" ", "_").replace("-", "_")
    return ", ".join(f"MOVE_{clean(move)}" for move in moves[:4])

def expand_variants(base):
    items = base.get("item", [None])
    if not isinstance(items, list):
        items = [items]

    abilities = base.get("ability", [None])
    if not isinstance(abilities, list):
        abilities = [abilities]

    nature = base.get("nature")
    if isinstance(nature, list):
        nature = nature[0]

    evs = base.get("evs", {})
    if isinstance(evs, list):
        evs = evs[0]

    ivs = base.get("ivs")
    if isinstance(ivs, list):
        ivs = ivs[0]

    tera_type = base.get("teratypes")
    if isinstance(tera_type, list):
        tera_type = tera_type[0]
    elif isinstance(tera_type, str):
        tera_type = tera_type
    else:
        tera_type = None

    return [{
        "moves": base["moves"],
        "item": item,
        "nature": nature,
        "evs": evs,
        "ability": ability,
        "ivs": ivs,
        "teraType": tera_type
    } for item in items for ability in abilities]

def detect_hidden_power_type(moves):
    for move in moves:
        if isinstance(move, str):
            match = HIDDEN_POWER_REGEX.match(sanitize_name(move))
            if match:
                return match.group(1).upper()
        elif isinstance(move, list):
            for m in move:
                match = HIDDEN_POWER_REGEX.match(sanitize_name(m))
                if match:
                    return match.group(1).upper()
    return None

def replace_hidden_power(move):
    if isinstance(move, str) and HIDDEN_POWER_REGEX.match(sanitize_name(move)):
        return "TERA_BLAST"
    return move

def expand_moves(moves):
    move_slots = [(m if isinstance(m, list) else [m]) for m in moves]
    return list(product(*move_slots))

# --- STEP 1: Load Existing Constants ---
existing_indices = []
if os.path.exists(CONSTS_FILE):
    with open(CONSTS_FILE, "r") as f:
        for line in f:
            if line.strip() == "// Custom Frontier Mon Indexes":
                break
            match = re.match(r"#define\s+(\w+)\s+(\d+)", line)
            if match:
                name, index = match.groups()
                if name not in ("NUM_FRONTIER_MONS", "NUM_ORIGINAL_FRONTIER_MONS"):
                    existing_indices.append((name, int(index)))

start_index = max((index for _, index in existing_indices), default=-1) + 1
current_index = start_index
new_indices = []
tiered_defines = {}
structs_by_tier = []

# --- STEP 2: Collect JSON Files ---
json_files = [f for f in os.listdir(INPUT_DIR) if f.endswith(".json")]

# --- STEP 3: Parse Each Tier File ---
for filename in sorted(json_files):
    filepath = os.path.join(INPUT_DIR, filename)
    tier_label = os.path.splitext(filename)[0].upper()
    tier_structs = [f"    // --- {tier_label} ---"]
    tiered_defines[tier_label] = []

    with open(filepath, "r") as f:
        try:
            smogon_data = json.load(f)
        except Exception as e:
            print(f"Error reading {filename}: {e}")
            continue

    for species_name, sets in smogon_data.items():
        for set_name, details in sets.items():
            if not isinstance(details.get("moves"), list):
                continue

            variants = expand_variants(details)

            for i, variant in enumerate(variants, 1):
                # Handle HIDDEN_POWER_<TYPE> replacement
                hp_type = detect_hidden_power_type(variant["moves"])
                if hp_type:
                    variant["moves"] = [replace_hidden_power(m) if not isinstance(m, list)
                                        else [replace_hidden_power(x) for x in m]
                                        for m in variant["moves"]]
                    if not variant.get("teraType"):
                        variant["teraType"] = hp_type.capitalize()

                move_combos = expand_moves(variant["moves"])

                for j, move_combo in enumerate(move_combos, 1):
                    raw_name = f"FRONTIER_MON_{tier_label}_{species_name}_{set_name}_{i}_{j}"
                    index_name = sanitize_name(raw_name)

                    new_indices.append((tier_label, index_name, current_index))
                    tiered_defines[tier_label].append((index_name, current_index))

                    mon_lines = [
                        f"    [{index_name}] = {{",
                        f"        .species = SPECIES_{sanitize_name(species_name)},",
                        f"        .moves = {{{format_moves(move_combo)}}},",
                        f"        .ev = {format_evs(variant['evs'])},",
                        f"        .nature = NATURE_{variant['nature'].upper()},",
                    ]
                    if variant["ability"]:
                        mon_lines.append(f"        .ability = ABILITY_{variant['ability'].upper().replace(' ', '_')},")

                    item = variant.get("item")
                    if item and item.strip().lower() != "no item":
                        mon_lines.append(f"        .heldItem = ITEM_{sanitize_name(item)},")

                    if variant["teraType"]:
                        mon_lines.append(f"        .teraType = TYPE_{variant['teraType'].upper()},")

                    mon_lines.append("    },")
                    tier_structs.append("\n".join(mon_lines))
                    current_index += 1

    if len(tier_structs) > 1:
        structs_by_tier.append("\n".join(tier_structs))

# --- STEP 4: Update Mons File ---
with open(MONS_FILE, "r+") as f:
    content = f.read()
    content = re.sub(r"\n\s*// BEGIN_CUSTOM_FRONTIER_MONS.*?// END_CUSTOM_FRONTIER_MONS\n", "", content, flags=re.DOTALL)

    end_index = content.rfind("};")
    if end_index == -1:
        raise RuntimeError("Could not find closing brace for gBattleFrontierMons")

    before_end = content[:end_index].rstrip()
    after_end = content[end_index + 2:]

    if not before_end.endswith(","):
        last_brace = before_end.rfind("}")
        if last_brace != -1:
            before_end = before_end[:last_brace+1] + "," + before_end[last_brace+1:]

    updated_structs = (
            "// BEGIN_CUSTOM_FRONTIER_MONS\n"
            + "\n\n".join(structs_by_tier)
            + "\n// END_CUSTOM_FRONTIER_MONS"
    )

    updated_content = before_end + "\n\n" + updated_structs + "\n};\n" + after_end

    f.seek(0)
    f.write(updated_content)
    f.truncate()

# --- STEP 5: Update Constants File ---
with open(CONSTS_FILE, "r+") as f:
    content = f.read()
    content = re.sub(r"\n\s*// BEGIN_CUSTOM_FRONTIER_DEFINES.*?// END_CUSTOM_FRONTIER_DEFINES\n", "", content, flags=re.DOTALL)
    content = re.sub(r"#define\s+NUM_FRONTIER_MONS\s+\d+\n", "", content)
    content = re.sub(r"#define\s+NUM_ORIGINAL_FRONTIER_MONS\s+\d+\n", "", content)

    endif_pos = content.rfind("#endif")
    if endif_pos == -1:
        raise RuntimeError("Missing #endif in constants file")

    original_max = max((index for _, index in existing_indices), default=-1)
    max_new_index = max((index for _, _, index in new_indices), default=original_max)

    define_lines = ["// BEGIN_CUSTOM_FRONTIER_DEFINES"]
    define_lines.append("// Custom Frontier Mon Indexes")
    for tier in sorted(tiered_defines):
        define_lines.append(f"// --- {tier} ---")
        for name, index in tiered_defines[tier]:
            define_lines.append(f"#define {name:<40} {index}")
    define_lines.append(f"#define NUM_ORIGINAL_FRONTIER_MONS    {original_max + 1}")
    define_lines.append(f"#define NUM_FRONTIER_MONS             {max_new_index + 1}")
    define_lines.append("// END_CUSTOM_FRONTIER_DEFINES")

    define_block = "\n" + "\n".join(define_lines) + "\n"
    updated_content = content[:endif_pos].rstrip() + "\n\n" + define_block + "\n\n" + content[endif_pos:]

    f.seek(0)
    f.write(updated_content)
    f.truncate()

# --- Optional: Print Missing Indexes ---
used = [index for _, _, index in new_indices]
expected = list(range(min(used), max(used) + 1))
missing = sorted(set(expected) - set(used))
if missing:
    print(f"⚠️ Warning: Missing indexes: {missing}")
else:
    print(f"✅ All indexes from {min(used)} to {max(used)} accounted for ({len(used)} mons)")
