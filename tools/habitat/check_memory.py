#!/usr/bin/env python3
"""Measure and enforce the approved Hoenn Habitat memory ceilings.

The checked-in JSON records the approved capacities and ceilings.  When a map
file is available, measurements are taken from that freshly linked artifact;
the JSON's recorded values are only a review snapshot, never the source of
truth for a normal repository check.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
REQUIRED_METRICS = ("ewram", "iwram", "rom", "saveblock3")
SECTION_RE = re.compile(r"^\.(?P<section>ewram(?:\.sbss)?|iwram(?:\.bss)?)\s+0x(?P<start>[0-9a-fA-F]+)\s+0x(?P<size>[0-9a-fA-F]+)")
ROM_END_RE = re.compile(r"^\s*0x(?P<end>[0-9a-fA-F]+)\s+__rom_end\s*=\s*\.")
SAVE_RE = re.compile(r"^\s*(?P<size>\d+)\s+SaveBlock3_total$", re.MULTILINE)


def fail(message: str) -> int:
    print(f"check_memory: {message}", file=sys.stderr)
    return 1


def parse_map(path: Path) -> dict[str, int]:
    if not path.is_file():
        raise ValueError(f"missing link map: {path}")
    totals = {"ewram": 0, "iwram": 0}
    rom_end = None
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        section = SECTION_RE.match(line)
        if section:
            key = "ewram" if section.group("section").startswith("ewram") else "iwram"
            totals[key] += int(section.group("size"), 16)
            continue
        end = ROM_END_RE.match(line)
        if end:
            rom_end = int(end.group("end"), 16)
    if rom_end is None:
        raise ValueError(f"{path}: missing __rom_end")
    totals["rom"] = rom_end - 0x08000000
    return totals


def measure_saveblock3() -> int:
    result = subprocess.run(
        [str(ROOT / "tools/habitat/save_sizes.sh")],
        cwd=ROOT,
        text=True,
        capture_output=True,
        check=False,
    )
    if result.returncode:
        raise ValueError("save-size probe failed: " + result.stderr.strip())
    found = SAVE_RE.search(result.stdout)
    if found is None:
        raise ValueError("save-size probe did not report SaveBlock3_total")
    return int(found.group("size"))


def fresh_measurements(map_path: Path) -> dict[str, int]:
    measurements = parse_map(map_path)
    measurements["saveblock3"] = measure_saveblock3()
    return measurements


def check_metrics(metrics: dict[str, object]) -> list[str]:
    errors: list[str] = []
    for name in REQUIRED_METRICS:
        metric = metrics.get(name)
        if not isinstance(metric, dict):
            errors.append(f"missing required metric: {name}")
            continue
        used = metric.get("used")
        capacity = metric.get("capacity")
        if not isinstance(used, int) or used < 0:
            errors.append(f"{name}: used must be a non-negative integer")
            continue
        if not isinstance(capacity, int) or capacity <= 0:
            errors.append(f"{name}: capacity must be a positive integer")
            continue
        if "ceiling_bytes" in metric:
            ceiling = metric["ceiling_bytes"]
            if not isinstance(ceiling, int) or ceiling <= 0:
                errors.append(f"{name}: ceiling_bytes must be a positive integer")
                continue
        else:
            percent = metric.get("ceiling_percent")
            if not isinstance(percent, (int, float)) or not 0 < percent <= 100:
                errors.append(f"{name}: ceiling_percent must be in (0, 100]")
                continue
            ceiling = capacity * percent / 100
        if used > ceiling:
            errors.append(f"{name}: {used} bytes exceeds approved ceiling {ceiling:g}")
    return errors


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--budget", type=Path, default=ROOT / "tools/habitat/memory_budget.json")
    parser.add_argument("--map", type=Path, default=None,
                        help="measure this freshly linked map instead of recorded review values")
    args = parser.parse_args()
    try:
        budget = json.loads(args.budget.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        return fail(f"cannot read budget: {error}")
    if not isinstance(budget, dict) or not isinstance(budget.get("metrics"), dict):
        return fail("budget must contain a metrics object")
    metrics = budget["metrics"]
    map_path = args.map
    if map_path is None and args.budget.resolve() == (ROOT / "tools/habitat/memory_budget.json").resolve():
        candidate = ROOT / "pokeemerald.map"
        if candidate.is_file():
            map_path = candidate
    if map_path is not None:
        try:
            measured = fresh_measurements(map_path)
        except ValueError as error:
            return fail(str(error))
        metrics = {name: {**value, "used": measured[name]} for name, value in metrics.items()
                   if isinstance(value, dict) and name in measured}
        print("check_memory: fresh measurements " + ", ".join(
            f"{name}={measured[name]}" for name in REQUIRED_METRICS))
    errors = check_metrics(metrics)
    if errors:
        for error in errors:
            print(f"check_memory: {error}", file=sys.stderr)
        return 1
    print("check_memory: memory budgets pass")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
