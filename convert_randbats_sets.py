import json
import os
import re

INPUT_FILE = "tiers/gen9randombattle.json"
MONS_FILE = "src/data/battle_frontier/battle_frontier_mons.h"
CONSTS_FILE = "include/constants/battle_frontier_mons.h"
ABILITIES_FILE = "include/constants/abilities.h"

MONS_BEGIN = "// BEGIN_RANDOMBATS_FRONTIER_MONS"
MONS_END = "// END_RANDOMBATS_FRONTIER_MONS"
DEFINES_BEGIN = "// BEGIN_RANDOMBATS_FRONTIER_DEFINES"
DEFINES_END = "// END_RANDOMBATS_FRONTIER_DEFINES"

ABILITY_NAME_MAP = {
    "AS_ONE_GLASTRIER": "AS_ONE_ICE_RIDER",
    "AS_ONE_SPECTRIER": "AS_ONE_SHADOW_RIDER",
}


def sanitize_name(name):
    name = str(name).replace("'", "").replace("é", "e").replace("É", "E")
    name = re.sub(r"[^A-Za-z0-9]", "_", name)
    name = re.sub(r"_+", "_", name).strip("_")
    return name.upper()


def listify(value):
    if value is None:
        return []
    if isinstance(value, list):
        return value
    return [value]


def load_defined_abilities():
    with open(ABILITIES_FILE, "r", encoding="utf-8") as f:
        content = f.read()
    return set(re.findall(r"\bABILITY_([A-Z0-9_]+)\b", content))


def normalize_moves(moves):
    out = list(moves)[:4]
    while len(out) < 4:
        out.append("NONE")
    return out


def format_moves(moves):
    def clean(move):
        return sanitize_name(move)

    return ", ".join(f"MOVE_{clean(move)}" for move in moves)


def format_evs(evs):
    # TRAINER_PARTY_EVS(hp, atk, def, speed, spatk, spdef)
    order = ["hp", "atk", "def", "spe", "spa", "spd"]
    values = [int(evs.get(stat, 0)) for stat in order]
    return f"TRAINER_PARTY_EVS({', '.join(str(v) for v in values)})"


def remove_marker_block(content, begin, end):
    pattern = rf"\n\s*{re.escape(begin)}.*?{re.escape(end)}\n"
    return re.sub(pattern, "\n", content, flags=re.DOTALL)


def build_randbats_entries(data):
    entries = []

    for species_name, species_payload in sorted(data.items()):
        if not isinstance(species_payload, dict):
            continue

        level = int(species_payload.get("level", 80))
        base_abilities = listify(species_payload.get("abilities"))
        base_items = listify(species_payload.get("items"))
        base_evs = species_payload.get("evs", {})
        roles = species_payload.get("roles", {})
        if not isinstance(roles, dict):
            continue

        for role_name, role_payload in sorted(roles.items()):
            if not isinstance(role_payload, dict):
                continue

            moves = normalize_moves(role_payload.get("moves", []))
            if len(moves) == 0:
                continue

            abilities = listify(role_payload.get("abilities")) or base_abilities or [None]
            items = listify(role_payload.get("items")) or base_items or [None]
            tera_types = listify(role_payload.get("teraTypes"))
            evs = role_payload.get("evs", base_evs)
            role_level = int(role_payload.get("level", level))

            variant_num = 1
            for ability in abilities:
                for item in items:
                    entry = {
                        "species": sanitize_name(species_name),
                        "role": sanitize_name(role_name),
                        "variant_num": variant_num,
                        "moves": moves,
                        "evs": evs,
                        "ability": sanitize_name(ability) if ability else None,
                        "item": sanitize_name(item) if item else None,
                        "level": role_level,
                        "tera_type": sanitize_name(tera_types[0]) if tera_types else None,
                    }
                    entries.append(entry)
                    variant_num += 1

    return entries


def update_mons_file(entries):
    with open(MONS_FILE, "r", encoding="utf-8") as f:
        content = f.read()

    content = remove_marker_block(content, MONS_BEGIN, MONS_END)
    end_index = content.rfind("};")
    if end_index == -1:
        raise RuntimeError("Could not find closing brace for gBattleFrontierMons")

    before_end = content[:end_index].rstrip()
    after_end = content[end_index + 2:]

    # Clean accidental duplicate commas from previous generation runs.
    before_end = re.sub(r"},\s*,+\s*(\n\s*// END_CUSTOM_FRONTIER_MONS)", r"},\1", before_end)

    if not before_end.endswith(","):
        last_brace = before_end.rfind("}")
        if last_brace != -1:
            trailing = before_end[last_brace + 1:]
            if "," not in trailing:
                before_end = before_end[:last_brace + 1] + "," + trailing

    mon_lines = [MONS_BEGIN, "    // --- GEN9 RANDOM BATTLES ---"]

    defined_abilities = load_defined_abilities()

    for entry in entries:
        index_name = f"FRONTIER_MON_GEN9RANDOMBATTLE_{entry['species']}_{entry['role']}_{entry['variant_num']}"
        mon_lines.append(f"    [{index_name}] = {{")
        mon_lines.append(f"        .species = SPECIES_{entry['species']},")
        mon_lines.append(f"        .moves = {{{format_moves(entry['moves'])}}},")
        mon_lines.append(f"        .ev = {format_evs(entry['evs'])},")
        mon_lines.append("        .nature = NATURE_HARDY,")
        if entry["ability"] and entry["ability"] not in ("NONE", "NO_ABILITY"):
            ability_name = ABILITY_NAME_MAP.get(entry["ability"], entry["ability"])
            if ability_name in defined_abilities:
                mon_lines.append(f"        .ability = ABILITY_{ability_name},")
        if entry["item"] and entry["item"] not in ("NONE", "NO_ITEM"):
            mon_lines.append(f"        .heldItem = ITEM_{entry['item']},")
        mon_lines.append(f"        .lvl = {entry['level']},")
        if entry["tera_type"] and entry["tera_type"] != "STELLAR":
            mon_lines.append(f"        .teraType = TYPE_{entry['tera_type']},")
        mon_lines.append("    },")
    mon_lines.append(MONS_END)

    updated_content = before_end + "\n\n" + "\n".join(mon_lines) + "\n};\n" + after_end

    with open(MONS_FILE, "w", encoding="utf-8") as f:
        f.write(updated_content)


def update_constants_file(entries):
    with open(CONSTS_FILE, "r", encoding="utf-8") as f:
        original_content = f.read()

    original_num_match = re.search(r"#define\s+NUM_ORIGINAL_FRONTIER_MONS\s+(\d+)", original_content)
    if not original_num_match:
        raise RuntimeError("Could not find NUM_ORIGINAL_FRONTIER_MONS")
    num_original = int(original_num_match.group(1))

    content = remove_marker_block(original_content, DEFINES_BEGIN, DEFINES_END)
    content = re.sub(r"#define\s+NUM_FRONTIER_MONS\s+\d+\n", "", content)
    content = re.sub(r"#define\s+NUM_ORIGINAL_FRONTIER_MONS\s+\d+\n", "", content)

    existing_indices = [int(m.group(1)) for m in re.finditer(r"#define\s+FRONTIER_MON_[A-Z0-9_]+\s+(\d+)", content)]
    if not existing_indices:
        raise RuntimeError("No existing FRONTIER_MON_* indexes found")
    current_index = max(existing_indices) + 1

    define_lines = [DEFINES_BEGIN, "// Gen9 Random Battles Indexes"]
    first_randbats_index = current_index
    for entry in entries:
        index_name = f"FRONTIER_MON_GEN9RANDOMBATTLE_{entry['species']}_{entry['role']}_{entry['variant_num']}"
        define_lines.append(f"#define {index_name:<60} {current_index}")
        current_index += 1

    last_randbats_index = current_index - 1
    define_lines.append(f"#define FRONTIER_MON_GEN9RANDOMBATTLE_FIRST{'':<25} {first_randbats_index}")
    define_lines.append(f"#define FRONTIER_MON_GEN9RANDOMBATTLE_LAST{'':<26} {last_randbats_index}")
    define_lines.append(f"#define FRONTIER_MON_GEN9RANDOMBATTLE_COUNT{'':<25} {len(entries)}")
    define_lines.append(f"#define NUM_ORIGINAL_FRONTIER_MONS    {num_original}")
    define_lines.append(f"#define NUM_FRONTIER_MONS             {current_index}")
    define_lines.append(DEFINES_END)
    define_block = "\n" + "\n".join(define_lines) + "\n"

    endif_pos = content.rfind("#endif")
    if endif_pos == -1:
        raise RuntimeError("Missing #endif in constants file")

    updated_content = content[:endif_pos].rstrip() + "\n\n" + define_block + "\n\n" + content[endif_pos:]

    with open(CONSTS_FILE, "w", encoding="utf-8") as f:
        f.write(updated_content)


def main():
    if not os.path.exists(INPUT_FILE):
        raise FileNotFoundError(f"Input file not found: {INPUT_FILE}")

    with open(INPUT_FILE, "r", encoding="utf-8") as f:
        data = json.load(f)

    entries = build_randbats_entries(data)
    if not entries:
        raise RuntimeError("No randbats entries were generated")

    update_mons_file(entries)
    update_constants_file(entries)
    print(f"Generated {len(entries)} Gen9 randbats sets.")


if __name__ == "__main__":
    main()
