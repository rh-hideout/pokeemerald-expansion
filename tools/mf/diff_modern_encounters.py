#!/usr/bin/env python3
"""
Diff stock FireRed wild tables vs generated modern tables.

  python3 tools/mf/diff_modern_encounters.py
  python3 tools/mf/diff_modern_encounters.py --map ROUTE1
  python3 tools/mf/diff_modern_encounters.py --map ROUTE --land-only
  python3 tools/mf/diff_modern_encounters.py -o /tmp/mf_enc_diff.txt

Slot odds (land): 0-1=20% each, 2-5=10%, 6-7=5%, 8-9=4%, 10-11=1%.
Showcase mid-rate slots are usually 4 (10%) and 6 (5%).
"""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
WILD_JSON = ROOT / "src/data/wild_encounters.json"
MODERN_H = ROOT / "src/data/mf_modern_wild_encounters.h"

LAND_ODDS = [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]
WATER_ODDS = [60, 30, 5, 4, 1]
ROCK_ODDS = [60, 30, 5, 4, 1]
FISH_ODDS = [70, 30, 60, 20, 20, 40, 40, 15, 4, 1]

FIELD_ODDS = {
    "land_mons": LAND_ODDS,
    "water_mons": WATER_ODDS,
    "rock_smash_mons": ROCK_ODDS,
    "fishing_mons": FISH_ODDS,
}


def camel_to_field(token: str) -> str:
    # LandMons -> land_mons
    return re.sub(r"(?<!^)(?=[A-Z])", "_", token).lower()


def short(species: str) -> str:
    return species.replace("SPECIES_", "")


def load_modern() -> dict[str, dict[str, list[str]]]:
    text = MODERN_H.read_text()
    out: dict[str, dict[str, list[str]]] = {}
    for m in re.finditer(
        r"static const struct WildPokemon (s\w+_FireRedModern)_(\w+)\[\] =\s*\{(.*?)\};",
        text,
        re.S,
    ):
        base, field_tok, body = m.group(1), m.group(2), m.group(3)
        field = camel_to_field(field_tok)
        out.setdefault(base, {})[field] = re.findall(r"SPECIES_\w+", body)
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--map", default="", help="Substring filter on map name (e.g. ROUTE1, SAFARI, VIRIDIAN)")
    ap.add_argument("--land-only", action="store_true", help="Only show land_mons diffs")
    ap.add_argument("--all-slots", action="store_true", help="Print every slot, not only changes")
    ap.add_argument("-o", "--output", type=Path, help="Write full report to this path")
    args = ap.parse_args()

    wild = json.loads(WILD_JSON.read_text())
    fr = [
        e
        for e in wild["wild_encounter_groups"][0]["encounters"]
        if "FireRed" in e.get("base_label", "") and "Modern" not in e.get("base_label", "")
    ]
    modern = load_modern()

    lines: list[str] = []
    tables = 0
    for e in fr:
        if args.map and args.map.upper() not in e["map"].upper():
            continue
        mlabel = e["base_label"].replace("_FireRed", "_FireRedModern")
        if mlabel not in modern:
            lines.append(f"MISSING modern header for {e['map']} ({e['base_label']})")
            continue
        for field, odds in FIELD_ODDS.items():
            if args.land_only and field != "land_mons":
                continue
            if field not in e or field not in modern[mlabel]:
                continue
            van = [m["species"] for m in e[field]["mons"]]
            mod = modern[mlabel][field]
            if van == mod and not args.all_slots:
                continue
            tables += 1
            lines.append(f"=== {e['map']}  {field}  ({e['base_label']}) ===")
            for i, (a, b) in enumerate(zip(van, mod)):
                if a == b and not args.all_slots:
                    continue
                mark = "" if a == b else "  **"
                pct = odds[i] if i < len(odds) else "?"
                lines.append(f"  [{i:2d} | {pct:2}%] {short(a):12s} -> {short(b):12s}{mark}")
            lines.append("")

    report = "\n".join(lines) if lines else "(no diffs matched filters)\n"
    header = f"# {tables} changed encounter tables\n# filter map={args.map!r} land_only={args.land_only}\n\n"
    text = header + report
    if args.output:
        args.output.write_text(text)
        print(f"Wrote {args.output} ({tables} tables)")
    else:
        print(text)


if __name__ == "__main__":
    main()
