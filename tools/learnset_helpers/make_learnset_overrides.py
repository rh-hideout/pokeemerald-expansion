#!/usr/bin/env python3

"""Propose overrides that preserve an existing all_learnables.json file.

Usage: python3 make_learnset_overrides.py CURRENT_FILE OFFICIAL_FILE OUTPUT_FILE
"""

import json
import sys
from pathlib import Path


def load_learnables(path: Path) -> dict[str, set[str]]:
    with path.open("r", encoding="utf-8") as file:
        source = json.load(file)

    if not isinstance(source, dict):
        raise ValueError(f"{path} must contain an object keyed by species")

    learnables = {}
    for species, moves in source.items():
        if not isinstance(species, str):
            raise ValueError(f"{path} contains a non-string species name")
        if not isinstance(moves, list) or not all(
            isinstance(move, str) for move in moves
        ):
            raise ValueError(f"{species} must contain a list of move constants")

        learnables[species] = set(moves)

    return learnables


def make_overrides(
    current: dict[str, set[str]],
    official: dict[str, set[str]],
) -> dict[str, dict[str, list[str]]]:
    overrides = {}

    for species in sorted(current.keys() | official.keys()):
        current_moves = current.get(species, set())
        official_moves = official.get(species, set())
        additions = sorted(current_moves - official_moves)
        removals = sorted(official_moves - current_moves)
        operations = {}

        if additions:
            operations["add"] = additions
        if removals:
            operations["remove"] = removals
        if operations:
            overrides[species] = operations

    return overrides


def main() -> None:
    if len(sys.argv) != 4:
        raise SystemExit(__doc__)

    current_path, official_path, output_path = map(Path, sys.argv[1:])
    current = load_learnables(current_path)
    official = load_learnables(official_path)
    overrides = make_overrides(current, official)

    # A proposal may already contain the user's review edits.
    with output_path.open("x", encoding="utf-8", newline="\n") as file:
        json.dump(overrides, file, indent=2)
        file.write("\n")


if __name__ == "__main__":
    main()
