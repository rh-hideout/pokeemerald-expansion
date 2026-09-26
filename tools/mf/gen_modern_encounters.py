#!/usr/bin/env python3
"""
Generate FireRed modern wild-encounter tables (S32).

Reads stock FireRed entries from src/data/wild_encounters.json, remaps slots so
every non-legendary Gen 1–3 species is obtainable, with placements gated by
route level (evo stage) and biome — not an arbitrary leftover list.

  python3 tools/mf/gen_modern_encounters.py
"""

from __future__ import annotations

import json
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
WILD_JSON = ROOT / "src/data/wild_encounters.json"
SPECIES_H = ROOT / "include/constants/species.h"
SPECIES_INFO_DIR = ROOT / "src/data/pokemon/species_info"
OUT_H = ROOT / "src/data/mf_modern_wild_encounters.h"

LEGENDARY_IDS = {
    144, 145, 146, 150, 151,
    243, 244, 245, 249, 250, 251,
    377, 378, 379, 380, 381, 382, 383, 384, 385, 386,
}

SPECIAL_KEEP = {"SPECIES_UNOWN"}

# Early-route land showcase (ME Route101 vibe): unevolved Gen2/3 commons only.
# Keep this list to species that feel OK on Routes 1–15 at low levels.
EARLY_LAND_POOL = [
    "SPECIES_SENTRET", "SPECIES_HOOTHOOT", "SPECIES_LEDYBA", "SPECIES_SPINARAK",
    "SPECIES_PICHU", "SPECIES_MAREEP", "SPECIES_MARILL", "SPECIES_HOPPIP",
    "SPECIES_AIPOM", "SPECIES_SUNKERN", "SPECIES_YANMA", "SPECIES_WOOPER",
    "SPECIES_MURKROW", "SPECIES_MISDREAVUS", "SPECIES_GIRAFARIG", "SPECIES_PINECO",
    "SPECIES_DUNSPARCE", "SPECIES_SNUBBULL", "SPECIES_TEDDIURSA", "SPECIES_SLUGMA",
    "SPECIES_SWINUB", "SPECIES_PHANPY", "SPECIES_STANTLER", "SPECIES_SMEARGLE",
    "SPECIES_TYROGUE", "SPECIES_SMOOCHUM", "SPECIES_ELEKID", "SPECIES_MAGBY",
    "SPECIES_MILTANK", "SPECIES_LARVITAR",
    "SPECIES_POOCHYENA", "SPECIES_ZIGZAGOON", "SPECIES_WURMPLE", "SPECIES_LOTAD",
    "SPECIES_SEEDOT", "SPECIES_TAILLOW", "SPECIES_WINGULL", "SPECIES_RALTS",
    "SPECIES_SURSKIT", "SPECIES_SHROOMISH", "SPECIES_SLAKOTH", "SPECIES_NINCADA",
    "SPECIES_WHISMUR", "SPECIES_MAKUHITA", "SPECIES_AZURILL", "SPECIES_NOSEPASS",
    "SPECIES_SKITTY", "SPECIES_ARON", "SPECIES_MEDITITE",
    "SPECIES_ELECTRIKE", "SPECIES_PLUSLE", "SPECIES_MINUN", "SPECIES_VOLBEAT",
    "SPECIES_ILLUMISE", "SPECIES_ROSELIA", "SPECIES_GULPIN",
    "SPECIES_NUMEL", "SPECIES_SPOINK", "SPECIES_SPINDA",
    "SPECIES_TRAPINCH", "SPECIES_CACNEA", "SPECIES_SWABLU",
    "SPECIES_BARBOACH", "SPECIES_CORPHISH", "SPECIES_BALTOY",
    "SPECIES_SHUPPET", "SPECIES_DUSKULL", "SPECIES_WYNAUT", "SPECIES_SNORUNT",
    "SPECIES_SPHEAL", "SPECIES_BAGON", "SPECIES_CHIMECHO",
]

# Mid/late-only basics — OK on Safari / Sevii / late routes, not early Kanto grass.
LATE_LAND_POOL = [
    "SPECIES_SABLEYE", "SPECIES_MAWILE", "SPECIES_TROPIUS", "SPECIES_ABSOL",
    "SPECIES_KECLEON", "SPECIES_CASTFORM", "SPECIES_RELICANTH", "SPECIES_LUVDISC",
    "SPECIES_CARVANHA", "SPECIES_WAILMER", "SPECIES_FEEBAS", "SPECIES_CLAMPERL",
    "SPECIES_LILEEP", "SPECIES_ANORITH", "SPECIES_CORSOLA", "SPECIES_QWILFISH",
    "SPECIES_REMORAID", "SPECIES_MANTINE", "SPECIES_SKARMORY", "SPECIES_HOUNDOUR",
    "SPECIES_GLIGAR", "SPECIES_HERACROSS", "SPECIES_SNEASEL", "SPECIES_DELIBIRD",
    "SPECIES_NATU", "SPECIES_XATU",
]

# Biome-preferred land pools (intersected with placeable at runtime).
CAVE_LAND_POOL = [
    "SPECIES_GEODUDE", "SPECIES_ZUBAT", "SPECIES_PARAS", "SPECIES_CLEFAIRY",
    "SPECIES_ONIX", "SPECIES_CUBONE", "SPECIES_RHYHORN",
    "SPECIES_SLUGMA", "SPECIES_SWINUB", "SPECIES_LARVITAR", "SPECIES_DUNSPARCE",
    "SPECIES_SHUCKLE", "SPECIES_TEDDIURSA", "SPECIES_SNEASEL",
    "SPECIES_WHISMUR", "SPECIES_MAKUHITA", "SPECIES_NOSEPASS", "SPECIES_ARON",
    "SPECIES_MEDITITE", "SPECIES_SABLEYE", "SPECIES_MAWILE", "SPECIES_NUMEL",
    "SPECIES_SPOINK", "SPECIES_TRAPINCH", "SPECIES_BALTOY", "SPECIES_LILEEP",
    "SPECIES_ANORITH", "SPECIES_SHUPPET", "SPECIES_DUSKULL", "SPECIES_SNORUNT",
    "SPECIES_SPHEAL", "SPECIES_BAGON", "SPECIES_ABSOL",
]

FOREST_LAND_POOL = [
    # Modern / cross-gen forest fits. Gen1 bugs/plants stay as stock filler.
    "SPECIES_LEDYBA", "SPECIES_SPINARAK", "SPECIES_HOPPIP", "SPECIES_SUNKERN",
    "SPECIES_YANMA", "SPECIES_PINECO", "SPECIES_HERACROSS", "SPECIES_SEEDOT",
    "SPECIES_SHROOMISH", "SPECIES_SLAKOTH", "SPECIES_NINCADA", "SPECIES_WURMPLE",
    "SPECIES_SURSKIT", "SPECIES_VOLBEAT", "SPECIES_ILLUMISE", "SPECIES_ROSELIA",
    "SPECIES_TROPIUS", "SPECIES_KECLEON",
]

GRASS_ROUTE_POOL = EARLY_LAND_POOL  # open routes / fields

# Water showcase basics (never Ludicolo / Gyarados on early surf).
EARLY_WATER_POOL = [
    "SPECIES_WOOPER", "SPECIES_MARILL", "SPECIES_CHINCHOU", "SPECIES_QWILFISH",
    "SPECIES_CORSOLA", "SPECIES_REMORAID", "SPECIES_MANTINE",
    "SPECIES_LOTAD", "SPECIES_WINGULL", "SPECIES_SURSKIT", "SPECIES_AZURILL",
    "SPECIES_CARVANHA", "SPECIES_WAILMER", "SPECIES_BARBOACH", "SPECIES_CORPHISH",
    "SPECIES_FEEBAS", "SPECIES_CLAMPERL", "SPECIES_LUVDISC", "SPECIES_SPHEAL",
]

WATER_POOL = EARLY_WATER_POOL + [
    "SPECIES_PSYDUCK", "SPECIES_POLIWAG", "SPECIES_TENTACOOL", "SPECIES_SLOWPOKE",
    "SPECIES_SEEL", "SPECIES_SHELLDER", "SPECIES_KRABBY", "SPECIES_HORSEA",
    "SPECIES_GOLDEEN", "SPECIES_STARYU", "SPECIES_MAGIKARP",
    "SPECIES_TOTODILE", "SPECIES_MUDKIP",
    "SPECIES_LOMBRE", "SPECIES_PELIPPER", "SPECIES_MASQUERAIN",
    "SPECIES_QUAGSIRE", "SPECIES_AZUMARILL", "SPECIES_LANTURN",
    "SPECIES_OCTILLERY", "SPECIES_SHARPEDO", "SPECIES_WHISCASH",
    "SPECIES_CRAWDAUNT", "SPECIES_SEALEO",
]

ROCK_POOL = [
    "SPECIES_GEODUDE", "SPECIES_ONIX", "SPECIES_RHYHORN", "SPECIES_SUDOWOODO",
    "SPECIES_SHUCKLE", "SPECIES_SLUGMA", "SPECIES_SWINUB", "SPECIES_PHANPY",
    "SPECIES_LARVITAR", "SPECIES_NOSEPASS", "SPECIES_ARON", "SPECIES_NUMEL",
    "SPECIES_MAKUHITA", "SPECIES_SOLROCK", "SPECIES_LUNATONE",
    "SPECIES_LILEEP", "SPECIES_ANORITH", "SPECIES_RELICANTH",
]

# Type → biome affinity for scoring.
TYPE_BIOME = {
    "TYPE_WATER": {"water"},
    "TYPE_ICE": {"water", "cave"},
    "TYPE_ROCK": {"cave"},
    "TYPE_GROUND": {"cave", "land"},
    "TYPE_STEEL": {"cave"},
    "TYPE_GHOST": {"building", "cave"},
    "TYPE_DARK": {"cave", "building"},
    "TYPE_BUG": {"forest", "land"},
    "TYPE_GRASS": {"forest", "land", "safari"},
    "TYPE_FLYING": {"land", "sevii"},
    "TYPE_NORMAL": {"land", "safari"},
    "TYPE_FIRE": {"cave", "land"},
    "TYPE_ELECTRIC": {"land", "building"},
    "TYPE_PSYCHIC": {"land", "building"},
    "TYPE_FIGHTING": {"land", "cave"},
    "TYPE_POISON": {"forest", "land"},
    "TYPE_DRAGON": {"cave", "sevii"},
    "TYPE_FAIRY": {"land", "forest"},
}

FIELD_SLOT_COUNTS = {
    "land_mons": 12,
    "water_mons": 5,
    "rock_smash_mons": 5,
    "fishing_mons": 10,
}


def load_species_names() -> dict[int, str]:
    text = SPECIES_H.read_text()
    ids: dict[int, str] = {}
    for m in re.finditer(r"SPECIES_(\w+)\s*=\s*(\d+)", text):
        full = f"SPECIES_{m.group(1)}"
        sid = int(m.group(2))
        if sid not in ids:
            ids[sid] = full
    return ids


def parse_species_meta() -> tuple[dict[str, int], dict[str, set[str]]]:
    """Return evo_stage (0=basic) and types for Gen1–3 family headers."""
    evo_into: dict[str, str] = {}  # child -> parent? better: parent evolves to child
    types: dict[str, set[str]] = defaultdict(set)
    evolves_to: dict[str, list[str]] = defaultdict(list)

    for path in sorted(SPECIES_INFO_DIR.glob("gen_[123]_families.h")):
        text = path.read_text()
        # Split on [SPECIES_FOO] =
        for m in re.finditer(
            r"\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*\{(.*?)\n    \},",
            text,
            re.S,
        ):
            species, body = m.group(1), m.group(2)
            if "_GALAR" in species or "_ALOLA" in species or "_HISUI" in species:
                continue
            for tm in re.finditer(r"TYPE_[A-Z]+", body):
                types[species].add(tm.group(0))
            for em in re.finditer(r"EVO_\w+\s*,\s*[^,]+,\s*(SPECIES_[A-Z0-9_]+)", body):
                evolves_to[species].append(em.group(1))

    # Stage: walk from roots (never appears as evolution target among Gen1-3).
    targets = {t for kids in evolves_to.values() for t in kids}
    stage: dict[str, int] = {}

    def set_stage(sp: str, s: int) -> None:
        if sp in stage and stage[sp] <= s:
            return
        stage[sp] = s
        for child in evolves_to.get(sp, []):
            set_stage(child, s + 1)

    for sp in list(evolves_to.keys()) + list(targets):
        if sp not in targets:
            set_stage(sp, 0)
    # Species with no evo data default to 0 (treat as basic).
    return stage, types


def max_stage_for_level(max_level: int) -> int:
    """How far along an evo line is allowed on this route."""
    if max_level <= 12:
        return 0  # basics only (Route 1–3, early forest)
    if max_level <= 22:
        return 1  # mid stages ok
    return 2     # finals allowed in late areas


def biome_tags(map_name: str) -> set[str]:
    tags: set[str] = {"land"}
    u = map_name.upper()
    if any(x in u for x in ("WATER", "SEA", "OCEAN", "BEACH", "ROUTE19", "ROUTE20", "ROUTE21", "SEAFOAM", "ICEFALL")):
        tags.add("water")
    # Indoor / underground only — not mountain exteriors (Mt Ember Exterior keeps birds).
    if any(
        x in u
        for x in (
            "CAVE", "MT_MOON", "TUNNEL", "DIGLETT", "VICTORY_ROAD", "SEAFOAM",
            "CERULEAN_CAVE", "ROCK_TUNNEL", "ALTERING", "LOST_CAVE", "ICEFALL",
            "EMBER_RUBY", "EMBER_SUMMIT_PATH",
        )
    ):
        tags.add("cave")
    if any(x in u for x in ("FOREST", "BERRY", "PATTERN_BUSH", "VIRIDIAN_FOREST")):
        tags.add("forest")
    # Viridian Forest is early-game; Sevii forests are not.
    if "VIRIDIAN_FOREST" in u:
        tags.add("early_kanto")
    if "SAFARI" in u:
        tags.add("safari")
    if any(x in u for x in ("ONE_ISLAND", "TWO_ISLAND", "THREE_ISLAND", "FOUR_ISLAND", "FIVE_ISLAND", "SIX_ISLAND", "SEVEN_ISLAND", "KINDLE", "BOND_BRIDGE", "CAPE_BRINK", "RESORT", "OUTCAST", "GREEN_PATH", "WATER_PATH", "RUIN_VALLEY", "SEVAULT", "TANOBY", "TREASURE", "MEMORIAL", "MEADOW", "PORT")):
        tags.add("sevii")
    if "TOWER" in u or "MANSION" in u or "POWER_PLANT" in u:
        tags.add("building")
    if re.search(r"ROUTE([1-9]|1[0-5])\b", u):
        tags.add("early_kanto")
    if re.search(r"ROUTE(1[6-9]|2[0-5])\b", u) or "VICTORY" in u or "CERULEAN_CAVE" in u:
        tags.add("late_kanto")
    return tags


def entry_max_level(entry: dict) -> int:
    mx = 1
    for field in FIELD_SLOT_COUNTS:
        if field not in entry:
            continue
        for m in entry[field]["mons"]:
            mx = max(mx, int(m["max_level"]))
    return mx


def clean_types(types: dict[str, set[str]], species: str) -> set[str]:
    return {t for t in types.get(species, set()) if t not in {"TYPE_NONE", "TYPE_SLOW"}}


def biome_allows(species: str, tags: set[str], types: dict[str, set[str]], field: str = "land_mons") -> bool:
    """Hard naturalness gates. False = never place here."""
    sp_types = clean_types(types, species)

    if field in ("water_mons", "fishing_mons"):
        return "TYPE_WATER" in sp_types or "TYPE_ICE" in sp_types
    if field == "rock_smash_mons":
        return bool(sp_types & {"TYPE_ROCK", "TYPE_GROUND", "TYPE_STEEL", "TYPE_FIGHTING", "TYPE_BUG"})

    if "cave" in tags:
        # Birds / open-sky flyers out. Cave bats (Flying+Poison) and Murkrow (Flying+Dark) OK.
        if "TYPE_FLYING" in sp_types and not (sp_types & {"TYPE_POISON", "TYPE_DARK"}):
            return False
        # Open-field grass (Seedot/Tropius) out; Bug/Grass like Paras OK.
        if "TYPE_GRASS" in sp_types and "TYPE_BUG" not in sp_types:
            return False
        # Surf fish out of dry cave floors. Ice/Water (Seel) and watery caves (Seafoam) OK.
        if "TYPE_WATER" in sp_types and "TYPE_ICE" not in sp_types and "water" not in tags:
            return False
        return True

    if "forest" in tags:
        if "TYPE_ROCK" in sp_types or "TYPE_STEEL" in sp_types:
            return False
        if "TYPE_WATER" in sp_types and "TYPE_GRASS" not in sp_types:
            return False
        if not sp_types & {
            "TYPE_BUG", "TYPE_GRASS", "TYPE_NORMAL", "TYPE_FLYING",
            "TYPE_POISON", "TYPE_FAIRY", "TYPE_GHOST",
        }:
            return False
        return True

    if "building" in tags:
        if "TYPE_WATER" in sp_types or "TYPE_ROCK" in sp_types:
            return False
        if "TYPE_FLYING" in sp_types and "TYPE_POISON" not in sp_types:
            return False
        return bool(sp_types & {
            "TYPE_GHOST", "TYPE_DARK", "TYPE_POISON", "TYPE_PSYCHIC",
            "TYPE_FIRE", "TYPE_ELECTRIC", "TYPE_NORMAL",
        })

    # Open land: no fish / surf mons in grass (Lotad/Grass+Water still OK).
    if "TYPE_WATER" in sp_types and "TYPE_GRASS" not in sp_types:
        return False
    # Ice belongs in caves / surf, not sunny Kanto grass.
    if "TYPE_ICE" in sp_types:
        return False
    return True


def score_species(
    species: str,
    tags: set[str],
    max_level: int,
    stage: dict[str, int],
    types: dict[str, set[str]],
    preferred_pool: set[str] | None = None,
    field: str = "land_mons",
) -> int | None:
    """Lower is better. None = disallowed."""
    st = stage.get(species, 0)
    if st > max_stage_for_level(max_level):
        return None
    if not biome_allows(species, tags, types, field=field):
        return None

    score = st * 10
    if preferred_pool is not None and species in preferred_pool:
        score -= 50

    sp_types = clean_types(types, species)
    if "cave" in tags:
        score -= 5 * len(sp_types & {"TYPE_ROCK", "TYPE_GROUND", "TYPE_STEEL", "TYPE_GHOST", "TYPE_DARK"})
    if "forest" in tags:
        score -= 5 * len(sp_types & {"TYPE_BUG", "TYPE_GRASS"})
    if field in ("water_mons", "fishing_mons"):
        score -= 5 * len(sp_types & {"TYPE_WATER", "TYPE_ICE"})

    if sp_types:
        affinity = 0
        for t in sp_types:
            for b in TYPE_BIOME.get(t, set()):
                if b in tags:
                    affinity += 1
        if affinity == 0 and tags & {"water", "cave", "forest", "building"}:
            score += 25
        else:
            score -= affinity * 3

    if "early_kanto" in tags and st >= 2:
        return None
    if "early_kanto" in tags and species in {
        "SPECIES_LOMBRE", "SPECIES_LUDICOLO", "SPECIES_NUZLEAF", "SPECIES_SHIFTRY",
        "SPECIES_PELIPPER", "SPECIES_KIRLIA", "SPECIES_GARDEVOIR", "SPECIES_BRELOOM",
        "SPECIES_VIGOROTH", "SPECIES_SLAKING", "SPECIES_NINJASK", "SPECIES_SHEDINJA",
        "SPECIES_LOUDRED", "SPECIES_EXPLOUD", "SPECIES_HARIYAMA", "SPECIES_LAIRON",
        "SPECIES_AGGRON", "SPECIES_MEDICHAM", "SPECIES_MANECTRIC", "SPECIES_SWALOT",
        "SPECIES_SHARPEDO", "SPECIES_WAILORD", "SPECIES_CAMERUPT", "SPECIES_GRUMPIG",
        "SPECIES_VIBRAVA", "SPECIES_FLYGON", "SPECIES_CACTURNE", "SPECIES_ALTARIA",
        "SPECIES_WHISCASH", "SPECIES_CRAWDAUNT", "SPECIES_CLAYDOL", "SPECIES_CRADILY",
        "SPECIES_ARMALDO", "SPECIES_MILOTIC", "SPECIES_BANETTE", "SPECIES_DUSCLOPS",
        "SPECIES_GLALIE", "SPECIES_SEALEO", "SPECIES_WALREIN", "SPECIES_HUNTAIL",
        "SPECIES_GOREBYSS", "SPECIES_SHELGON", "SPECIES_SALAMENCE",
        "SPECIES_LINOONE", "SPECIES_MIGHTYENA", "SPECIES_SILCOON", "SPECIES_CASCOON",
        "SPECIES_BEAUTIFLY", "SPECIES_DUSTOX", "SPECIES_SWELLOW",
    }:
        return None
    return score


def pick_best(
    candidates: list[str],
    tags: set[str],
    max_level: int,
    stage: dict[str, int],
    types: dict[str, set[str]],
    preferred_pool: set[str] | None = None,
    usage: dict[str, int] | None = None,
    rotate: int = 0,
    field: str = "land_mons",
) -> str | None:
    scored: list[tuple[int, int, str]] = []
    for sp in candidates:
        sc = score_species(sp, tags, max_level, stage, types, preferred_pool, field=field)
        if sc is None:
            continue
        uses = usage.get(sp, 0) if usage is not None else 0
        scored.append((uses, sc, sp))
    if not scored:
        return None
    min_uses = min(u for u, _, _ in scored)
    tier = [(sc, sp) for u, sc, sp in scored if u == min_uses]
    tier.sort(key=lambda t: t[0])
    best_sc = tier[0][0]
    best = [sp for sc, sp in tier if sc == best_sc]
    return best[rotate % len(best)]


def inject_species(mons: list[dict], species: str, slot: int | None = None, prefer_tail: bool = True) -> None:
    if not mons:
        return
    if slot is not None:
        i = max(0, min(slot, len(mons) - 1))
        mons[i] = {"min_level": mons[i]["min_level"], "max_level": mons[i]["max_level"], "species": species}
        return
    idxs = list(range(len(mons) - 1, -1, -1)) if prefer_tail else list(range(len(mons)))
    counts: dict[str, int] = defaultdict(int)
    for m in mons:
        counts[m["species"]] += 1
    for i in idxs:
        if counts[mons[i]["species"]] > 1:
            mons[i] = {"min_level": mons[i]["min_level"], "max_level": mons[i]["max_level"], "species": species}
            return
    i = idxs[0]
    mons[i] = {"min_level": mons[i]["min_level"], "max_level": mons[i]["max_level"], "species": species}


def clone_entry(entry: dict) -> dict:
    return json.loads(json.dumps(entry))


def collect_covered(modern: list[dict]) -> set[str]:
    covered: set[str] = set()
    for e in modern:
        for field in FIELD_SLOT_COUNTS:
            if field not in e:
                continue
            for m in e[field]["mons"]:
                covered.add(m["species"])
    return covered


def is_unown_chamber(map_name: str) -> bool:
    return "TANOBY_RUINS_" in map_name and "CHAMBER" in map_name


def build_modern_tables(
    fr_entries: list[dict],
    placeable: list[str],
    stage: dict[str, int],
    types: dict[str, set[str]],
) -> list[dict]:
    modern: list[dict] = []
    for entry in fr_entries:
        e = clone_entry(entry)
        e["base_label"] = entry["base_label"].replace("_FireRed", "_FireRedModern")
        if not e["base_label"].endswith("Modern"):
            e["base_label"] = entry["base_label"] + "Modern"
        modern.append(e)

    def maps_with(field: str) -> list[int]:
        return [i for i, e in enumerate(modern) if field in e]

    def remaining_species() -> list[str]:
        covered = collect_covered(modern)
        return [s for s in placeable if s not in covered]

    land_usable = [i for i in maps_with("land_mons") if not is_unown_chamber(modern[i]["map"])]
    early_land = set(EARLY_LAND_POOL) & set(placeable)
    late_land = set(LATE_LAND_POOL) & set(placeable)
    cave_land = set(CAVE_LAND_POOL) & set(placeable)
    forest_land = set(FOREST_LAND_POOL) & set(placeable)
    early_water = set(EARLY_WATER_POOL) & set(placeable)
    water_set = set(WATER_POOL) & set(placeable)
    rock_set = set(ROCK_POOL) & set(placeable)

    # 1) Showcase land: mid-rate slots 4+6. Biome pools first (cave/forest), then
    #    early Kanto dibs on the early pool; round-robin stays inside the pool.
    showcase_usage: dict[str, int] = defaultdict(int)

    def showcase_pool_for(tags: set[str]) -> set[str]:
        if "cave" in tags:
            base = cave_land
        elif "forest" in tags:
            base = forest_land
        elif "early_kanto" in tags and "safari" not in tags:
            base = early_land
        else:
            base = early_land | late_land
        if "early_kanto" in tags and "safari" not in tags:
            # Keep early routes/caves/forests on basics only.
            return base & early_land if base & early_land else base
        return base

    def land_assign_order(i: int) -> tuple[int, str]:
        tags = biome_tags(modern[i]["map"])
        # early Kanto first, then forests/caves, then safari/sevii/late
        if "early_kanto" in tags and "safari" not in tags:
            pri = 0
        elif "forest" in tags or "cave" in tags:
            pri = 1
        elif "safari" in tags or "sevii" in tags:
            pri = 3
        else:
            pri = 2
        return (pri, modern[i]["map"])

    for slot_i, mi in enumerate(sorted(land_usable, key=land_assign_order)):
        tags = biome_tags(modern[mi]["map"])
        max_lv = entry_max_level(fr_entries[mi])
        pool = showcase_pool_for(tags)
        prefer = cave_land if "cave" in tags else forest_land if "forest" in tags else early_land
        stock = {m["species"] for m in modern[mi]["land_mons"]["mons"]}
        for slot_n, slot in enumerate((4, 6)):
            # Prefer species not already on this map's stock table.
            pool_land = [s for s in pool if s not in stock] or list(pool)
            pick = pick_best(
                pool_land,
                tags,
                max_lv,
                stage,
                types,
                preferred_pool=prefer - stock if prefer - stock else prefer,
                usage=showcase_usage,
                rotate=slot_i * 2 + slot_n,
                field="land_mons",
            )
            if pick is None:
                # Only if the whole pool is stage/biome-illegal for this map.
                fallback = [
                    s for s in placeable
                    if stage.get(s, 0) <= max_stage_for_level(max_lv)
                    and s not in late_land
                    and s not in stock
                ]
                pick = pick_best(
                    fallback,
                    tags,
                    max_lv,
                    stage,
                    types,
                    preferred_pool=prefer,
                    usage=showcase_usage,
                    rotate=slot_i * 2 + slot_n,
                    field="land_mons",
                )
            if pick is None:
                continue
            inject_species(modern[mi]["land_mons"]["mons"], pick, slot=slot)
            showcase_usage[pick] += 1
            stock.add(pick)

    # 2) Water / fishing / rock: inject fit members; round-robin within field.
    field_usage: dict[str, dict[str, int]] = {
        "water_mons": defaultdict(int),
        "fishing_mons": defaultdict(int),
        "rock_smash_mons": defaultdict(int),
    }
    for field, pool in (
        ("water_mons", water_set),
        ("fishing_mons", water_set),
        ("rock_smash_mons", rock_set),
    ):
        for inj_i, mi in enumerate(maps_with(field)):
            tags = biome_tags(modern[mi]["map"])
            max_lv = entry_max_level(fr_entries[mi])
            prefer = early_water if field != "rock_smash_mons" else rock_set
            for k in range(2):
                cand = [s for s in remaining_species() if s in pool] or list(pool)
                pick = pick_best(
                    cand,
                    tags,
                    max_lv,
                    stage,
                    types,
                    preferred_pool=prefer,
                    usage=field_usage[field],
                    rotate=inj_i * 2 + k,
                    field=field,
                )
                if pick is None:
                    break
                inject_species(modern[mi][field]["mons"], pick, prefer_tail=True)
                field_usage[field][pick] += 1

    # 3) Water-only maps: one modern basic in the 30% slot (round-robin).
    water_only_usage: dict[str, int] = defaultdict(int)
    for mi, entry in enumerate(fr_entries):
        if "land_mons" in modern[mi] or "water_mons" not in modern[mi]:
            continue
        tags = biome_tags(modern[mi]["map"]) | {"water"}
        max_lv = entry_max_level(entry)
        cand = [s for s in remaining_species() if s in early_water] or list(early_water)
        pick = pick_best(
            cand,
            tags,
            max_lv,
            stage,
            types,
            preferred_pool=early_water,
            usage=water_only_usage,
            rotate=mi,
            field="water_mons",
        )
        if pick:
            inject_species(modern[mi]["water_mons"]["mons"], pick, slot=1)
            water_only_usage[pick] += 1

    # 4) Dump leftovers onto late / safari / sevii land only, respecting biome.
    def dump_priority(i: int) -> tuple[int, str]:
        tags = biome_tags(modern[i]["map"])
        score = 0
        if "safari" in tags:
            score -= 20
        if "sevii" in tags:
            score -= 10
        if "late_kanto" in tags:
            score -= 5
        # Prefer open land for leftovers — caves/forests only get biome-legal dumps.
        if "cave" in tags:
            score += 25
        if "forest" in tags:
            score += 15
        if "building" in tags:
            score += 20
        if "early_kanto" in tags:
            score += 50  # avoid dumping leftovers onto Route 1–15
        return (score, modern[i]["map"])

    dump_maps = sorted(land_usable, key=dump_priority)
    dump_slots = [11, 10, 9, 8, 7, 5, 3, 2]
    cells: list[tuple[int, int]] = []
    for mi in dump_maps:
        tags = biome_tags(modern[mi]["map"])
        if "early_kanto" in tags and "safari" not in tags:
            continue  # do not use early routes as coverage dumps
        cells.extend((mi, slot) for slot in dump_slots)

    spill = [
        (mi, slot)
        for mi in dump_maps
        for slot in (1, 0)
        if "early_kanto" not in biome_tags(modern[mi]["map"]) or "safari" in biome_tags(modern[mi]["map"])
    ]
    all_dump_cells = cells + spill
    ci = 0
    passes_without_place = 0
    while True:
        rem = remaining_species()
        if not rem:
            break
        if ci >= len(all_dump_cells):
            if passes_without_place >= len(all_dump_cells):
                break  # leave leftovers for re-home / soft placement
            ci = 0
            continue
        mi, slot = all_dump_cells[ci]
        tags = biome_tags(modern[mi]["map"])
        max_lv = entry_max_level(fr_entries[mi])
        prefer = cave_land if "cave" in tags else forest_land if "forest" in tags else None
        pick = pick_best(rem, tags, max_lv, stage, types, preferred_pool=prefer, field="land_mons")
        ci += 1
        if pick is None:
            passes_without_place += 1
            continue
        passes_without_place = 0
        mons = modern[mi]["land_mons"]["mons"]
        if slot >= len(mons):
            slot = len(mons) - 1
        mons[slot] = {
            "min_level": mons[slot]["min_level"],
            "max_level": mons[slot]["max_level"],
            "species": pick,
        }

    # 5) Re-home anything still missing into duplicate slots on dump maps (biome-gated).
    rem = remaining_species()
    if rem:
        for mi in dump_maps:
            if not rem:
                break
            tags = biome_tags(modern[mi]["map"])
            if "early_kanto" in tags and "safari" not in tags:
                continue
            max_lv = entry_max_level(fr_entries[mi])
            prefer = cave_land if "cave" in tags else forest_land if "forest" in tags else None
            mons = modern[mi]["land_mons"]["mons"]
            counts: dict[str, int] = defaultdict(int)
            for m in mons:
                counts[m["species"]] += 1
            for i, m in enumerate(mons):
                if counts[m["species"]] <= 1 or not rem:
                    continue
                pick = pick_best(rem, tags, max_lv, stage, types, preferred_pool=prefer, field="land_mons")
                if pick is None:
                    break
                rem = [s for s in rem if s != pick]
                mons[i] = {
                    "min_level": m["min_level"],
                    "max_level": m["max_level"],
                    "species": pick,
                }
                counts[m["species"]] -= 1
                counts[pick] = counts.get(pick, 0) + 1

    # 6) Soft last resort: stage-only on open land (still biome-gated).
    rem = remaining_species()
    if rem:
        for mi in dump_maps:
            if not rem:
                break
            tags = biome_tags(modern[mi]["map"])
            if "cave" in tags or "forest" in tags or "building" in tags:
                continue
            if "early_kanto" in tags and "safari" not in tags:
                continue
            max_lv = entry_max_level(fr_entries[mi])
            mons = modern[mi]["land_mons"]["mons"]
            for i, m in enumerate(mons):
                if not rem:
                    break
                pick = pick_best(rem, tags, max_lv, stage, types, field="land_mons")
                if pick is None:
                    break
                rem = [s for s in rem if s != pick]
                mons[i] = {
                    "min_level": m["min_level"],
                    "max_level": m["max_level"],
                    "species": pick,
                }

    # 7) Water leftovers → surf/fish slots only (never grass).
    rem = remaining_species()
    if rem:
        water_maps = [
            i for i in maps_with("water_mons") + maps_with("fishing_mons")
        ]
        # Unique preserve order
        seen: set[int] = set()
        water_maps_u: list[int] = []
        for i in water_maps:
            if i not in seen:
                seen.add(i)
                water_maps_u.append(i)
        for mi in water_maps_u:
            if not rem:
                break
            tags = biome_tags(modern[mi]["map"]) | {"water"}
            max_lv = entry_max_level(fr_entries[mi])
            for field in ("water_mons", "fishing_mons"):
                if field not in modern[mi] or not rem:
                    continue
                mons = modern[mi][field]["mons"]
                for i, m in enumerate(mons):
                    if not rem:
                        break
                    pick = pick_best(rem, tags, max_lv, stage, types, field=field)
                    if pick is None:
                        break
                    rem = [s for s in rem if s != pick]
                    mons[i] = {
                        "min_level": m["min_level"],
                        "max_level": m["max_level"],
                        "species": pick,
                    }

    rem = remaining_species()
    if rem:
        raise SystemExit(f"Failed to place {len(rem)} species: {rem[:20]}")

    return modern


def emit_header(modern: list[dict]) -> str:
    lines: list[str] = [
        "//",
        "// DO NOT MODIFY THIS FILE! It is auto-generated by tools/mf/gen_modern_encounters.py",
        "//",
        "",
        "#if defined(FIRERED)",
        "",
    ]
    info_names: dict[str, dict[str, str]] = {}

    for entry in modern:
        base = entry["base_label"]
        info_names[base] = {}
        for field, count in FIELD_SLOT_COUNTS.items():
            if field not in entry:
                continue
            mons = entry[field]["mons"]
            if len(mons) != count:
                raise SystemExit(f"{base} {field}: expected {count} slots, got {len(mons)}")
            camel = "".join(p.title() for p in field.split("_"))
            arr = f"{base}_{camel}"
            lines.append(f"static const struct WildPokemon {arr}[] =")
            lines.append("{")
            for m in mons:
                lines.append(f"    {{ {m['min_level']}, {m['max_level']}, {m['species']} }},")
            lines.append("};")
            lines.append("")
            info = f"{arr}Info"
            lines.append(f"static const struct WildPokemonInfo {info} = {{ {entry[field]['encounter_rate']}, {arr} }};")
            lines.append("")
            info_names[base][field] = info

    lines.append("const struct WildPokemonHeader gMfModernWildMonHeaders[] =")
    lines.append("{")
    for entry in modern:
        base = entry["base_label"]
        map_name = entry["map"]
        infos = info_names[base]
        lines.append("    {")
        lines.append(f"        .mapGroup = MAP_GROUP({map_name}),")
        lines.append(f"        .mapNum = MAP_NUM({map_name}),")
        lines.append("        .encounterTypes =")
        lines.append("        {")
        lines.append("            [TIME_MORNING] =")
        lines.append("            {")
        for field, member in (
            ("land_mons", "landMonsInfo"),
            ("water_mons", "waterMonsInfo"),
            ("rock_smash_mons", "rockSmashMonsInfo"),
            ("fishing_mons", "fishingMonsInfo"),
            ("hidden_mons", "hiddenMonsInfo"),
        ):
            if field in infos:
                lines.append(f"                .{member} = &{infos[field]},")
            else:
                lines.append(f"                .{member} = NULL,")
        lines.append("            },")
        lines.append("        },")
        lines.append("    },")
    lines += [
        "    {",
        "        .mapGroup = MAP_GROUP(MAP_UNDEFINED),",
        "        .mapNum = MAP_NUM(MAP_UNDEFINED),",
        "        .encounterTypes =",
        "        {",
        "            [TIME_MORNING] =",
        "            {",
        "                .landMonsInfo = NULL,",
        "                .waterMonsInfo = NULL,",
        "                .rockSmashMonsInfo = NULL,",
        "                .fishingMonsInfo = NULL,",
        "                .hiddenMonsInfo = NULL,",
        "            },",
        "        },",
        "    },",
        "};",
        "",
        "#endif // FIRERED",
        "",
    ]
    return "\n".join(lines)


def main() -> None:
    id_to_name = load_species_names()
    stage, types = parse_species_meta()
    placeable = [
        id_to_name[i]
        for i in range(1, 387)
        if i in id_to_name and i not in LEGENDARY_IDS and id_to_name[i] not in SPECIAL_KEEP
    ]

    data = json.loads(WILD_JSON.read_text())
    fr_entries = [
        e
        for e in data["wild_encounter_groups"][0]["encounters"]
        if "FireRed" in e.get("base_label", "") and "Modern" not in e.get("base_label", "")
    ]
    if not fr_entries:
        raise SystemExit("No FireRed wild encounter entries found")

    modern = build_modern_tables(fr_entries, placeable, stage, types)
    covered = collect_covered(modern)
    missing = [s for s in placeable if s not in covered]
    if missing:
        raise SystemExit(f"Coverage incomplete ({len(missing)} missing): {missing[:30]}")

    # Sanity: Route 1 showcase must be early-pool basics.
    r1 = next(e for e in modern if e["map"] == "MAP_ROUTE1")
    r1_showcase = {r1["land_mons"]["mons"][4]["species"], r1["land_mons"]["mons"][6]["species"]}
    for sp in r1_showcase:
        if stage.get(sp, 0) > 0:
            raise SystemExit(f"Route 1 showcase not basic: {sp}")
        if sp not in EARLY_LAND_POOL:
            raise SystemExit(f"Route 1 showcase not in EARLY_LAND_POOL: {sp}")

    # Sanity: no showcase species paints early Kanto (max 2 uses across Routes 1–15 land).
    early_showcase_counts: dict[str, int] = defaultdict(int)
    for e in modern:
        tags = biome_tags(e["map"])
        if "early_kanto" not in tags or "land_mons" not in e:
            continue
        for slot in (4, 6):
            early_showcase_counts[e["land_mons"]["mons"][slot]["species"]] += 1
    offenders = {sp: n for sp, n in early_showcase_counts.items() if n > 2}
    if offenders:
        raise SystemExit(f"Early-Kanto showcase overused: {offenders}")

    OUT_H.write_text(emit_header(modern))
    print(f"Wrote {OUT_H.relative_to(ROOT)}")
    print(f"  headers: {len(modern)}")
    print(f"  placeable Gen1-3 non-legendaries: {len(placeable)}")
    print(f"  covered: {len(covered & set(placeable))}")
    print(f"  Route1 showcase: {sorted(r1_showcase)}")
    top = sorted(early_showcase_counts.items(), key=lambda kv: -kv[1])[:8]
    print(f"  Early-Kanto showcase top uses: {top}")


if __name__ == "__main__":
    main()
