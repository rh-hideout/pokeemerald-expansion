#!/usr/bin/env python3
"""Fail closed on renovated map template budgets and tracked slice surfaces."""

from __future__ import annotations

import json
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
RENOVATED = ROOT / "tools/habitat/renovated_maps.txt"
REACHABLE = ROOT / "tools/habitat/reachable_maps.txt"
INVENTORY = ROOT / "docs/story-readiness/vanilla-surface-inventory.md"
MAX_OBJECT_TEMPLATES = 13
DISPOSITIONS = {
    "removed",
    "unreachable behind tested gate",
    "deliberately retained with approved rationale",
    "blocking with map held closed",
}


def manifest_paths(path: Path) -> list[Path]:
    if not path.is_file():
        raise ValueError(f"missing manifest: {path.relative_to(ROOT)}")
    paths = []
    for line in path.read_text().splitlines():
        line = line.strip()
        if line and not line.startswith("#"):
            paths.append(ROOT / line)
    if not paths:
        raise ValueError(f"empty manifest: {path.relative_to(ROOT)}")
    return paths


def inventory_rows() -> dict[tuple[str, str], dict[str, str]]:
    if not INVENTORY.is_file():
        raise ValueError(f"missing inventory: {INVENTORY.relative_to(ROOT)}")
    rows = {}
    for line in INVENTORY.read_text().splitlines():
        if not line.startswith("|"):
            continue
        cells = [cell.strip() for cell in line.strip().strip("|").split("|")]
        if len(cells) != 7 or cells[0] in {"Map", "---"} or all(set(cell) <= {"-", ":"} for cell in cells):
            continue
        map_path, surface, symbols, disposition, owner, rationale, test = cells
        map_path = map_path.strip("`")
        if disposition not in DISPOSITIONS:
            raise ValueError(f"invalid disposition for {map_path} / {symbol}: {disposition}")
        if not all((map_path, surface, symbols, owner, rationale, test)):
            raise ValueError(f"incomplete inventory row: {line}")
        for symbol in (symbol.strip().strip("`") for symbol in symbols.split("<br>")):
            if not symbol:
                raise ValueError(f"empty symbol in inventory row: {line}")
            key = (map_path, symbol)
            if key in rows:
                raise ValueError(f"duplicate inventory row for {map_path} / {symbol}")
            rows[key] = {
                "surface": surface,
                "disposition": disposition,
                "owner": owner,
                "rationale": rationale,
                "test": test,
            }
    return rows


def map_json(path: Path) -> dict:
    if not path.is_file():
        raise ValueError(f"missing map: {path.relative_to(ROOT)}")
    return json.loads(path.read_text())


def object_symbol(event: dict) -> str:
    return event.get("script", "0x0")


def print_object(path: Path, total: int, event: dict, disposition: str) -> None:
    print(
        f"{path.relative_to(ROOT)} total={total} "
        f"local_id={event.get('local_id', '-')} "
        f"graphics_id={event.get('graphics_id', '-')} "
        f"trainer_type={event.get('trainer_type', '-')} "
        f"script={object_symbol(event)} flag={event.get('flag', '-')} "
        f"disposition={disposition}"
    )


def validate_renovated(rows: dict[tuple[str, str], dict[str, str]]) -> list[str]:
    errors = []
    for path in manifest_paths(RENOVATED):
        data = map_json(path)
        objects = data.get("object_events", [])
        relpath = str(path.relative_to(ROOT))
        if len(objects) > MAX_OBJECT_TEMPLATES:
            errors.append(f"{relpath}: {len(objects)} object templates exceeds {MAX_OBJECT_TEMPLATES}")
        for event in objects:
            row = rows.get((relpath, object_symbol(event)))
            print_object(path, len(objects), event, row["disposition"] if row else "MISSING")
            if row is None:
                errors.append(f"{relpath}: object script {object_symbol(event)} has no inventory disposition")
            elif row["disposition"] == "removed":
                errors.append(f"{relpath}: removed script {object_symbol(event)} is still an object reference")
    return errors


def map_script_symbols(map_dir: Path) -> set[str]:
    scripts = map_dir / "scripts.inc"
    if not scripts.is_file():
        return set()
    # This is deliberately only the direct map callback edge. A legacy label
    # may remain in the assembled script file, but it is not reachable merely
    # because it is defined there.
    callbacks = set()
    for line in scripts.read_text().splitlines():
        fields = line.strip().split()
        if fields and fields[0].startswith("map_script") and len(fields) >= 3:
            callbacks.add(fields[-1])
    return callbacks


def script_body(map_dir: Path, symbol: str) -> str:
    """Return one direct label body without treating sibling labels as live."""
    scripts = map_dir / "scripts.inc"
    if not scripts.is_file() or symbol.startswith("warp:"):
        return ""
    lines = scripts.read_text().splitlines()
    marker = f"{symbol}::"
    try:
        start = next(i for i, line in enumerate(lines) if line.strip() == marker)
    except StopIteration:
        return ""
    body = []
    for line in lines[start + 1:]:
        if line and not line[0].isspace() and line.rstrip().endswith("::"):
            break
        body.append(line)
    return "\n".join(body)


def is_story_hazard(map_dir: Path, symbol: str) -> bool:
    body = script_body(map_dir, symbol)
    lower_symbol = symbol.lower()
    lower_body = body.lower()
    if "rival" in lower_symbol:
        return True
    return any(marker in lower_body for marker in (
        "trainerbattle", "choosestarter", "checkplayergender",
        "item_poke_ball", "setwildbattle", "team_aqua", "team_magma",
        "villain", "capture",
    ))


def validate_reachable(rows: dict[tuple[str, str], dict[str, str]]) -> list[str]:
    errors = []
    for path in manifest_paths(REACHABLE):
        data = map_json(path)
        relpath = str(path.relative_to(ROOT))
        event_symbols = {object_symbol(event) for event in data.get("object_events", [])}
        event_symbols.update(event.get("script", "0x0") for event in data.get("coord_events", []))
        event_symbols.update(event.get("script", "0x0") for event in data.get("bg_events", []))
        event_symbols.update(f"warp:{event['dest_map']}" for event in data.get("warp_events", []))
        event_symbols.discard("0x0")
        for symbol in sorted(event_symbols | map_script_symbols(path.parent)):
            row = rows.get((relpath, symbol))
            if row is None:
                errors.append(f"{relpath}: reachable symbol {symbol} has no inventory disposition")
                continue
            if row["disposition"] == "removed":
                errors.append(f"{relpath}: removed symbol {symbol} is still reachable")
            if is_story_hazard(path.parent, symbol) and row["disposition"] not in {
                "unreachable behind tested gate", "blocking with map held closed"
            }:
                errors.append(
                    f"{relpath}: story hazard {symbol} must be gated or held closed, "
                    f"not {row['disposition']}"
                )
    return errors


def main() -> int:
    try:
        rows = inventory_rows()
        errors = validate_renovated(rows) + validate_reachable(rows)
    except (OSError, ValueError, json.JSONDecodeError) as exc:
        print(f"validate_maps: {exc}", file=sys.stderr)
        return 1
    if errors:
        for error in errors:
            print(f"validate_maps: {error}", file=sys.stderr)
        return 1
    print("validate_maps: renovated budgets and reachable-map inventory pass")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
