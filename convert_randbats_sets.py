import json
import os
import re
from itertools import combinations

INPUT_FILE = "tiers/gen9randombattle.json"
MONS_FILE = "src/data/battle_frontier/battle_frontier_mons.h"
CONSTS_FILE = "include/constants/battle_frontier_mons.h"
ABILITIES_FILE = "include/constants/abilities.h"
ITEMS_FILE = "include/constants/items.h"
MOVES_FILE = "include/constants/moves.h"
TYPES_FILE = "include/constants/pokemon.h"

MONS_BEGIN = "// BEGIN_RANDOMBATS_FRONTIER_MONS"
MONS_END = "// END_RANDOMBATS_FRONTIER_MONS"
DEFINES_BEGIN = "// BEGIN_RANDOMBATS_FRONTIER_DEFINES"
DEFINES_END = "// END_RANDOMBATS_FRONTIER_DEFINES"

# Diversity controls tuned for Smogon-like variety without over-biasing species.
MAX_ABILITY_OPTIONS = 3
MAX_ITEM_OPTIONS = 4
MAX_TERA_OPTIONS = 3
MAX_MOVE_COMBOS_PER_ROLE = 10
MAX_VARIANTS_PER_ROLE = 10
MAX_VARIANTS_PER_SPECIES = 12

ABILITY_NAME_MAP = {
    "AS_ONE_GLASTRIER": "AS_ONE_ICE_RIDER",
    "AS_ONE_SPECTRIER": "AS_ONE_SHADOW_RIDER",
}

EV_BASELINE = {
    "hp": 84,
    "atk": 84,
    "def": 84,
    "spe": 84,
    "spa": 84,
    "spd": 84,
}
EV_SIGNATURE_ORDER = ("hp", "atk", "def", "spa", "spd", "spe")
NON_STELLAR_TYPES = lambda defined_types: {t for t in defined_types if t != "STELLAR"}


def sanitize_name(name):
    name = str(name).replace("'", "").replace("é", "e").replace("É", "E")
    name = re.sub(r"[^A-Za-z0-9]", "_", name)
    name = re.sub(r"_+", "_", name).strip("_")
    return name.upper()


def parse_defined_constants(path, prefix):
    with open(path, "r", encoding="utf-8") as f:
        content = f.read()
    return set(re.findall(rf"\b{re.escape(prefix)}([A-Z0-9_]+)\b", content))


def remove_marker_block(content, begin, end):
    pattern = rf"\n\s*{re.escape(begin)}.*?{re.escape(end)}\n"
    return re.sub(pattern, "\n", content, flags=re.DOTALL)


def normalize_weighted_options(value):
    # Supports:
    # - list: ordered preferences (earlier is more likely)
    # - dict: explicit weights
    # - scalar: single option
    if value is None:
        return []
    if isinstance(value, dict):
        out = []
        for key, weight in value.items():
            try:
                w = float(weight)
            except (TypeError, ValueError):
                w = 1.0
            if w > 0:
                out.append((key, w))
        out.sort(key=lambda x: x[1], reverse=True)
        return out
    if isinstance(value, list):
        n = len(value)
        return [(v, float(n - i)) for i, v in enumerate(value)]
    return [(value, 1.0)]


def unique_preserve_order(seq):
    seen = set()
    out = []
    for x in seq:
        if x not in seen:
            seen.add(x)
            out.append(x)
    return out


def score_weighted_choice(base_score, selected, candidate_key, key_fn):
    if not selected:
        return base_score

    current = set(key_fn(candidate_key))
    if not current:
        return base_score

    # Reward diversity against already selected candidates.
    distances = []
    for s in selected:
        other = set(key_fn(s))
        union = current | other
        if not union:
            continue
        overlap = len(current & other) / len(union)
        distances.append(1.0 - overlap)
    diversity_boost = 1.0 + (sum(distances) / len(distances) if distances else 0.0)
    return base_score * diversity_boost


def select_diverse_candidates(candidates, limit, key_fn):
    # candidates: list[(payload, score)]
    if len(candidates) <= limit:
        return [c[0] for c in sorted(candidates, key=lambda x: x[1], reverse=True)]

    ranked = sorted(candidates, key=lambda x: x[1], reverse=True)
    selected = []
    selected_payloads = []

    while ranked and len(selected_payloads) < limit:
        best_i = 0
        best_score = -1.0
        for i, (payload, score) in enumerate(ranked):
            adjusted = score_weighted_choice(score, selected_payloads, payload, key_fn)
            if adjusted > best_score:
                best_i = i
                best_score = adjusted
        payload, _ = ranked.pop(best_i)
        selected_payloads.append(payload)
        selected.append(payload)

    return selected


def normalize_moves(moves):
    if not isinstance(moves, list):
        return []
    cleaned = [sanitize_name(m) for m in moves if m is not None]
    return unique_preserve_order(cleaned)


def format_moves(moves):
    return ", ".join(f"MOVE_{m}" for m in moves)


def format_evs(evs):
    # TRAINER_PARTY_EVS(hp, atk, def, speed, spatk, spdef)
    order = ["hp", "atk", "def", "spe", "spa", "spd"]
    values = [int(evs.get(stat, 0)) for stat in order]
    return f"TRAINER_PARTY_EVS({', '.join(str(v) for v in values)})"


def merged_evs(base_evs, override_evs):
    # Randbats baseline is flat 84 EVs in each stat, with sparse overrides.
    evs = dict(EV_BASELINE)
    if isinstance(base_evs, dict):
        for k, v in base_evs.items():
            if k in evs:
                evs[k] = int(v)
    if isinstance(override_evs, dict):
        for k, v in override_evs.items():
            if k in evs:
                evs[k] = int(v)
    return evs


def build_weighted_move_combos(moves):
    if not moves:
        return []

    if len(moves) <= 4:
        combo = list(moves)
        while len(combo) < 4:
            combo.append("NONE")
        return [(tuple(combo), 1.0)]

    combos = []
    n = len(moves)

    # Smogon randbats lists are priority-ordered; keep early moves "core" more often.
    if n >= 6:
        core_count = 2
    else:
        core_count = 1
    core = tuple(moves[:core_count])
    flex = moves[core_count:]
    flex_slots = 4 - core_count

    if len(flex) < flex_slots:
        combo = list(moves[:4])
        while len(combo) < 4:
            combo.append("NONE")
        return [(tuple(combo), 1.0)]

    for idxs in combinations(range(len(flex)), flex_slots):
        chosen_flex = tuple(flex[i] for i in idxs)
        combo = core + chosen_flex
        # Favor earlier flex entries while preserving variety via capped selection.
        score = sum(float(len(flex) - i) for i in idxs) + float(2 * core_count)
        combos.append({"combo": combo, "score": score})

    best_payloads = select_diverse_candidates(
        [(payload, payload["score"]) for payload in combos],
        MAX_MOVE_COMBOS_PER_ROLE,
        key_fn=lambda payload: payload["combo"],
    )
    return [(payload["combo"], payload["score"]) for payload in best_payloads]


def normalize_options_for_constants(options, defined_set, mapper=None, max_count=3, allow_none=True):
    out = []
    for raw, weight in options:
        if raw is None and allow_none:
            out.append((None, max(float(weight), 0.1)))
            continue
        if raw is None:
            continue
        name = sanitize_name(raw)
        if mapper:
            name = mapper.get(name, name)
        if name in defined_set:
            out.append((name, max(float(weight), 0.1)))
    out = unique_preserve_order(out)
    return out[:max_count]


def load_defined_constants():
    return {
        "abilities": parse_defined_constants(ABILITIES_FILE, "ABILITY_"),
        "items": parse_defined_constants(ITEMS_FILE, "ITEM_"),
        "moves": parse_defined_constants(MOVES_FILE, "MOVE_"),
        "types": parse_defined_constants(TYPES_FILE, "TYPE_"),
    }


def resolve_role_options(role_payload, base_options, defined):
    abilities = normalize_options_for_constants(
        normalize_weighted_options(role_payload.get("abilities")) or base_options["abilities"],
        defined["abilities"],
        mapper=ABILITY_NAME_MAP,
        max_count=MAX_ABILITY_OPTIONS,
        allow_none=True,
    )
    if not abilities:
        abilities = [(None, 1.0)]

    items = normalize_options_for_constants(
        normalize_weighted_options(role_payload.get("items")) or base_options["items"],
        defined["items"],
        max_count=MAX_ITEM_OPTIONS,
        allow_none=True,
    )
    if not items:
        items = [(None, 1.0)]

    tera_types = normalize_options_for_constants(
        normalize_weighted_options(role_payload.get("teraTypes")) or base_options["tera_types"],
        NON_STELLAR_TYPES(defined["types"]),
        max_count=MAX_TERA_OPTIONS,
        allow_none=True,
    )
    if not tera_types:
        tera_types = [(None, 1.0)]

    return abilities, items, tera_types


def build_role_candidates(species, role, role_level, role_evs, move_combos, abilities, items, tera_types, defined_moves):
    dedup = {}
    for combo, combo_weight in move_combos:
        if any(m != "NONE" and m not in defined_moves for m in combo):
            continue
        for ability, ability_weight in abilities:
            for item, item_weight in items:
                for tera_type, tera_weight in tera_types:
                    signature = (
                        combo,
                        tuple(int(role_evs.get(k, 0)) for k in EV_SIGNATURE_ORDER),
                        ability,
                        item,
                        role_level,
                        tera_type,
                    )
                    score = combo_weight * ability_weight * item_weight * tera_weight
                    existing = dedup.get(signature)
                    if existing is None or score > existing["score"]:
                        dedup[signature] = {
                            "species": species,
                            "role": role,
                            "moves": list(combo),
                            "evs": role_evs,
                            "ability": ability,
                            "item": item,
                            "level": role_level,
                            "tera_type": tera_type,
                            "score": score,
                        }

    return list(dedup.values())


def select_species_entries(species_candidates):
    # Guarantee at least one high-quality entry per role when possible.
    role_groups = {}
    for candidate in species_candidates:
        role_groups.setdefault(candidate["role"], []).append(candidate)
    for role in role_groups:
        role_groups[role].sort(key=lambda c: c["score"], reverse=True)

    seeded = []
    for role in sorted(role_groups.keys()):
        if len(seeded) >= MAX_VARIANTS_PER_SPECIES:
            break
        seeded.append(role_groups[role].pop(0))

    remaining_capacity = MAX_VARIANTS_PER_SPECIES - len(seeded)
    leftovers = []
    for role in role_groups:
        leftovers.extend(role_groups[role])

    selected_species_entries = list(seeded)
    if remaining_capacity > 0 and leftovers:
        extra = select_diverse_candidates(
            [(c, c["score"]) for c in leftovers],
            remaining_capacity,
            key_fn=lambda payload: payload["moves"] + [payload["ability"] or "", payload["item"] or "", payload["tera_type"] or ""],
        )
        selected_species_entries.extend(extra)

    return selected_species_entries


def finalize_variant_numbers(all_entries):
    role_counters = {}
    final_entries = []
    for entry in sorted(all_entries, key=lambda e: (e["species"], e["role"], -e["score"])):
        key = (entry["species"], entry["role"])
        role_counters[key] = role_counters.get(key, 0) + 1
        entry = dict(entry)
        entry["variant_num"] = role_counters[key]
        final_entries.append(entry)
    return final_entries


def build_randbats_entries(data):
    defined = load_defined_constants()

    all_entries = []

    for species_name, species_payload in sorted(data.items()):
        if not isinstance(species_payload, dict):
            continue

        species = sanitize_name(species_name)
        level = int(species_payload.get("level", 80))
        base_options = {
            "abilities": normalize_weighted_options(species_payload.get("abilities")),
            "items": normalize_weighted_options(species_payload.get("items")),
            "tera_types": normalize_weighted_options(species_payload.get("teraTypes")),
        }
        base_evs = species_payload.get("evs", {})
        roles = species_payload.get("roles", {})
        if not isinstance(roles, dict):
            continue

        species_candidates = []

        for role_name, role_payload in sorted(roles.items()):
            if not isinstance(role_payload, dict):
                continue

            role = sanitize_name(role_name)
            role_level = int(role_payload.get("level", level))
            role_evs = merged_evs(base_evs, role_payload.get("evs"))

            moves = normalize_moves(role_payload.get("moves", []))
            move_combos = build_weighted_move_combos(moves)
            if not move_combos:
                continue

            abilities, items, tera_types = resolve_role_options(role_payload, base_options, defined)

            role_candidates = build_role_candidates(
                species,
                role,
                role_level,
                role_evs,
                move_combos,
                abilities,
                items,
                tera_types,
                defined["moves"],
            )
            if not role_candidates:
                continue

            selected_role_entries = select_diverse_candidates(
                [(c, c["score"]) for c in role_candidates],
                MAX_VARIANTS_PER_ROLE,
                key_fn=lambda payload: payload["moves"],
            )
            species_candidates.extend(selected_role_entries)

        if not species_candidates:
            continue

        all_entries.extend(select_species_entries(species_candidates))

    return finalize_variant_numbers(all_entries)


def update_mons_file(entries):
    with open(MONS_FILE, "r", encoding="utf-8") as f:
        content = f.read()

    content = remove_marker_block(content, MONS_BEGIN, MONS_END)
    end_index = content.rfind("};")
    if end_index == -1:
        raise RuntimeError("Could not find closing brace for gBattleFrontierMons")

    before_end = content[:end_index].rstrip()
    after_end = content[end_index + 2:]

    before_end = re.sub(r"},\s*,+\s*(\n\s*// END_CUSTOM_FRONTIER_MONS)", r"},\1", before_end)
    if not before_end.endswith(","):
        last_brace = before_end.rfind("}")
        if last_brace != -1:
            trailing = before_end[last_brace + 1:]
            if "," not in trailing:
                before_end = before_end[:last_brace + 1] + "," + trailing

    mon_lines = [MONS_BEGIN, "    // --- GEN9 RANDOM BATTLES ---"]
    for entry in entries:
        index_name = f"FRONTIER_MON_GEN9RANDOMBATTLE_{entry['species']}_{entry['role']}_{entry['variant_num']}"
        mon_lines.append(f"    [{index_name}] = {{")
        mon_lines.append(f"        .species = SPECIES_{entry['species']},")
        mon_lines.append(f"        .moves = {{{format_moves(entry['moves'])}}},")
        mon_lines.append(f"        .ev = {format_evs(entry['evs'])},")
        mon_lines.append("        .nature = NATURE_HARDY,")
        if entry["ability"]:
            mon_lines.append(f"        .ability = ABILITY_{entry['ability']},")
        if entry["item"]:
            mon_lines.append(f"        .heldItem = ITEM_{entry['item']},")
        mon_lines.append(f"        .lvl = {entry['level']},")
        if entry["tera_type"]:
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
