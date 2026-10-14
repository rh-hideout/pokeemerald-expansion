#!/usr/bin/env python3

"""Apply project-owned additions and removals to official learnability data.

Usage: python3 apply_learnset_overrides.py OFFICIAL_FILE OVERRIDES_FILE OUTPUT_FILE
"""

import json
import sys
from pathlib import Path


OPERATIONS = ("add", "remove")


def load_json(path: Path) -> object:
    with path.open("r", encoding="utf-8") as file:
        return json.load(file)


def validate_moves(species: str, operation: str, moves: object) -> list[str]:
    if not isinstance(moves, list) or not all(
        isinstance(move, str) for move in moves
    ):
        raise ValueError(
            f"{species}.{operation} must be a list of move constants"
        )

    if len(moves) != len(set(moves)):
        raise ValueError(f"{species}.{operation} contains duplicate moves")

    return moves


def load_official_learnables(path: Path) -> dict[str, list[str]]:
    source = load_json(path)
    if not isinstance(source, dict):
        raise ValueError(f"{path} must contain an object keyed by species")

    learnables = {}
    for species, moves in source.items():
        if not isinstance(species, str):
            raise ValueError(f"{path} contains a non-string species name")

        learnables[species] = validate_moves(species, "official", moves)

    return learnables


def load_overrides(path: Path) -> dict[str, dict[str, list[str]]]:
    source = load_json(path)
    if not isinstance(source, dict):
        raise ValueError(f"{path} must contain an object keyed by species")

    overrides = {}
    for species, operations in source.items():
        if not isinstance(species, str) or not isinstance(operations, dict):
            raise ValueError(
                f"{path} entries must map species names to add/remove objects"
            )

        unknown_operations = set(operations) - set(OPERATIONS)
        if unknown_operations:
            names = ", ".join(sorted(unknown_operations))
            raise ValueError(f"{species} has unknown override operations: {names}")

        overrides[species] = {
            operation: validate_moves(
                species,
                operation,
                operations.get(operation, []),
            )
            for operation in OPERATIONS
        }

    return overrides


def apply_overrides(
    official: dict[str, list[str]],
    overrides: dict[str, dict[str, list[str]]],
) -> dict[str, list[str]]:
    effective = {}

    for species in sorted(official.keys() | overrides.keys()):
        moves = set(official.get(species, []))
        moves.update(overrides.get(species, {}).get("add", []))
        moves.difference_update(overrides.get(species, {}).get("remove", []))
        effective[species] = sorted(moves)

    return effective


def main() -> None:
    if len(sys.argv) != 4:
        raise SystemExit(__doc__)

    official_path, overrides_path, output_path = map(Path, sys.argv[1:])
    official = load_official_learnables(official_path)
    overrides = load_overrides(overrides_path)
    effective = apply_overrides(official, overrides)

    with output_path.open("w", encoding="utf-8", newline="\n") as file:
        json.dump(effective, file, indent=2)
        file.write("\n")


if __name__ == "__main__":
    main()
