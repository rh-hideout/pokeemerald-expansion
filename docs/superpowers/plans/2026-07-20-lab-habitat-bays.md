# Lab Habitat Bays Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Rearrange Birch's lab into three unmistakable habitat bays and move resident sprites away from foreground furniture so every starter is fully visible.

**Architecture:** Keep the Habitat state machine, save data, spot IDs, and variable graphics unchanged. Make the presentation contract explicit in a static validator, mechanically rewrite only the affected lab metatiles, and relocate background-event entrances separately from resident object positions. Use the existing lab floor, mat, and furniture metatiles; add no new art.

**Tech Stack:** pokeemerald-expansion map JSON and binary metatile layout, Python 3 static validator, native C Habitat tests, mGBA headless verification scripts.

## Global Constraints

- Work only in the isolated worktree `/private/tmp/hoenn-habitat-stabilization` on branch `codex/hoenn-habitat-stabilization`.
- Preserve spot IDs `7`, `8`, and `9`, graphics variables `VAR_OBJ_GFX_ID_7` through `VAR_OBJ_GFX_ID_9`, flags, scripts, furnishing choices, and save representation.
- Use only existing repository-native lab metatiles; do not add temporary or generated artwork.
- Keep the doorway at `(6,12)` and `(7,12)`, a clear central aisle, and a walkable route from the spawn position to every bay entrance and the exit.
- Do not introduce or revise narrative prose under this fix.
- A dormant bay is inspected at its front background event; an active resident is rendered one tile inside the bay and uses the existing object-event interaction.

---

## File Structure

- Create `tools/habitat/check_lab_layout.py`: executable static contract for map dimensions, event identity, bay coordinates, bay metatiles, and the clear aisle.
- Modify `data/layouts/LittlerootTown_ProfessorBirchsLab/map.bin`: 13×13 metatile layout containing the visible bays.
- Modify `data/maps/LittlerootTown_ProfessorBirchsLab/map.json`: distinct front interaction and resident coordinates.
- Modify `docs/reports/2026-07-20-habitat-task-13-acceptance.md`: fresh screenshot evidence and the resolved visual defect.

### Task 1: Define and implement the lab layout contract

**Files:**
- Create: `tools/habitat/check_lab_layout.py`
- Modify: `data/layouts/LittlerootTown_ProfessorBirchsLab/map.bin`
- Modify: `data/maps/LittlerootTown_ProfessorBirchsLab/map.json`

**Interfaces:**
- Consumes: the 13×13 little-endian `u16` block grid and map event arrays already produced by Porymap.
- Produces: `python3 tools/habitat/check_lab_layout.py`, which exits zero only when the approved bay layout and event contract are present.

- [ ] **Step 1: Add the failing static layout validator**

Create `tools/habitat/check_lab_layout.py` with this complete content:

```python
#!/usr/bin/env python3
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MAP_JSON = ROOT / "data/maps/LittlerootTown_ProfessorBirchsLab/map.json"
MAP_BIN = ROOT / "data/layouts/LittlerootTown_ProfessorBirchsLab/map.bin"
WIDTH = 13
HEIGHT = 13

OBJECTS = {
    "LOCALID_HABITAT_FRAME_TORCHIC": {
        "coords": (2, 7),
        "graphics_id": "OBJ_EVENT_GFX_VAR_7",
        "flag": "FLAG_UNUSED_0x040",
    },
    "LOCALID_HABITAT_FRAME_TREECKO": {
        "coords": (6, 7),
        "graphics_id": "OBJ_EVENT_GFX_VAR_8",
        "flag": "FLAG_UNUSED_0x041",
    },
    "LOCALID_HABITAT_FRAME_MUDKIP": {
        "coords": (10, 7),
        "graphics_id": "OBJ_EVENT_GFX_VAR_9",
        "flag": "FLAG_UNUSED_0x042",
    },
}

ENTRANCES = {
    (2, 8): "BirchsLab_EventScript_HabitatFrameTorchic",
    (6, 8): "BirchsLab_EventScript_HabitatFrameTreecko",
    (10, 8): "BirchsLab_EventScript_HabitatFrameMudkip",
}

FLOOR = 0x3202
DARK_FLOOR = 0x3203
BAY_CELLS = {
    (x, y)
    for start in (1, 5, 9)
    for x in range(start, start + 3)
    for y in range(5, 9)
}
BAY_OVERRIDES = {
    (3, 5): 0x060D,  # Poké Ball holder, top
    (3, 6): 0x3233,  # holder's table base
    (1, 7): 0x3206,  # open-slot mat, left half
    (2, 7): 0x3207,  # open-slot mat, right half / first resident
}
RESIDENT_CELLS = {(2, 7), (6, 7), (10, 7)}
CLEAR_ACCESS_CELLS = (
    {(x, 9) for x in range(2, 11)}
    | {(6, y) for y in range(10, 12)}
)


def fail(message):
    print(f"lab-layout: {message}", file=sys.stderr)
    raise SystemExit(1)


def main():
    data = json.loads(MAP_JSON.read_text())
    objects = {event["local_id"]: event for event in data["object_events"]}
    if set(objects) != set(OBJECTS):
        fail(f"unexpected object IDs: {sorted(objects)}")

    for local_id, expected in OBJECTS.items():
        event = objects[local_id]
        actual = (event["x"], event["y"])
        if actual != expected["coords"]:
            fail(f"{local_id} expected {expected['coords']}, found {actual}")
        if event["graphics_id"] != expected["graphics_id"]:
            fail(f"{local_id} changed graphics variable")
        if event["flag"] != expected["flag"]:
            fail(f"{local_id} changed hide flag")
        if event["script"] != "HabitatSpot_EventScript_Interact":
            fail(f"{local_id} changed interaction script")

    entrances = {
        (event["x"], event["y"]): event["script"]
        for event in data["bg_events"]
    }
    if entrances != ENTRANCES:
        fail(f"background entrances expected {ENTRANCES}, found {entrances}")

    warps = {(event["x"], event["y"]) for event in data["warp_events"]}
    occupied = {expected["coords"] for expected in OBJECTS.values()}
    if warps & occupied or warps & set(ENTRANCES) or occupied & set(ENTRANCES):
        fail("warp, resident, and entrance coordinates must be distinct")

    raw = MAP_BIN.read_bytes()
    expected_size = WIDTH * HEIGHT * 2
    if len(raw) != expected_size:
        fail(f"map.bin expected {expected_size} bytes, found {len(raw)}")
    blocks = struct.unpack(f"<{WIDTH * HEIGHT}H", raw)

    def block_at(coords):
        x, y = coords
        return blocks[y * WIDTH + x]

    for coords in BAY_CELLS:
        expected = BAY_OVERRIDES.get(coords, DARK_FLOOR)
        if block_at(coords) != expected:
            fail(f"bay cell {coords} expected 0x{expected:04X}, found 0x{block_at(coords):04X}")
    for coords in RESIDENT_CELLS:
        if block_at(coords) not in {DARK_FLOOR, 0x3207}:
            fail(f"resident cell {coords} is not unobstructed bay floor")
    for coords in CLEAR_ACCESS_CELLS:
        if block_at(coords) != FLOOR:
            fail(f"access aisle cell {coords} is not clear floor")
    for coords in ENTRANCES:
        if block_at(coords) != DARK_FLOOR:
            fail(f"bay entrance {coords} is not walkable dark floor")

    print("lab-layout: visible bays, resident positions, entrances, and aisle are valid")


if __name__ == "__main__":
    main()
```

- [ ] **Step 2: Run the validator and confirm the existing map fails for the reported defect**

Run:

```bash
python3 tools/habitat/check_lab_layout.py
```

Expected: exit `1` and output beginning with:

```text
lab-layout: LOCALID_HABITAT_FRAME_TORCHIC expected (2, 7), found (2, 5)
```

- [ ] **Step 3: Mechanically rewrite the affected metatile region**

Run this one-time binary transformation from the repository root. It preserves rows `0–2` and `9–12`, clears the obstructing furniture in rows `3–8`, paints three 3×4 dark-floor bays, restores the first bay's Poké Ball holder, and marks its open furnishing slot with the existing lab mat:

```bash
python3 - <<'PY'
import struct
from pathlib import Path

path = Path("data/layouts/LittlerootTown_ProfessorBirchsLab/map.bin")
blocks = list(struct.unpack("<169H", path.read_bytes()))

def put(x, y, value):
    blocks[y * 13 + x] = value

for y in range(3, 9):
    for x in range(13):
        put(x, y, 0x3202)

for start in (1, 5, 9):
    for y in range(5, 9):
        for x in range(start, start + 3):
            put(x, y, 0x3203)

put(3, 5, 0x060D)
put(3, 6, 0x3233)
put(1, 7, 0x3206)
put(2, 7, 0x3207)

path.write_bytes(struct.pack("<169H", *blocks))
PY
```

- [ ] **Step 4: Relocate the resident objects and dormant-bay entrances**

Use `apply_patch` on `data/maps/LittlerootTown_ProfessorBirchsLab/map.json` to make these exact coordinate changes while leaving every other object property unchanged:

```diff
 LOCALID_HABITAT_FRAME_TORCHIC object: x 4 -> 2, y 6 -> 7
 LOCALID_HABITAT_FRAME_TREECKO object: x 6 -> 6, y 6 -> 7
 LOCALID_HABITAT_FRAME_MUDKIP object: x 8 -> 10, y 6 -> 7

 BirchsLab_EventScript_HabitatFrameTorchic bg event: x 4 -> 2, y 6 -> 8
 BirchsLab_EventScript_HabitatFrameTreecko bg event: x 6 -> 6, y 6 -> 8
 BirchsLab_EventScript_HabitatFrameMudkip bg event: x 8 -> 10, y 6 -> 8
```

- [ ] **Step 5: Run the static validator and generated-map checks**

Run:

```bash
python3 tools/habitat/check_lab_layout.py
make generated
git diff --check
```

Expected:

```text
lab-layout: visible bays, resident positions, entrances, and aisle are valid
```

`make generated` and `git diff --check` must exit `0`. Inspect `git status --short`; generated event files may change only where the six coordinates changed. Restore any unrelated generated JSON churn before continuing.

- [ ] **Step 6: Run focused native behavior tests**

Run:

```bash
make check TESTS='Habitat starter'
make check TESTS='Habitat spot'
```

Expected: both commands exit `0`; starter choice, recovery, map reload, spot lookup, and resident graphics-variable expectations remain green.

- [ ] **Step 7: Commit the green map fix**

```bash
git add tools/habitat/check_lab_layout.py \
  data/layouts/LittlerootTown_ProfessorBirchsLab/map.bin \
  data/maps/LittlerootTown_ProfessorBirchsLab/map.json \
  data/maps/LittlerootTown_ProfessorBirchsLab/events.inc
git commit -m "fix: expose visible lab habitat bays"
```

### Task 2: Prove the bays and all starter residents at native resolution

**Files:**
- Modify: `docs/reports/2026-07-20-habitat-task-13-acceptance.md`

**Interfaces:**
- Consumes: the green static layout contract and the existing `boot`, `lab-campfire`, `lab-plant`, and `lab-basin` verification scenarios.
- Produces: fresh screenshots and a report entry tying the visual evidence to the bug acceptance criteria.

- [ ] **Step 1: Capture the dormant three-bay layout from a fresh build**

Run:

```bash
HH_VERIFY_OUT=/private/tmp/hh-lab-bays-boot tools/habitat/verify.sh --no-interact
```

Expected: exit `0` and `/private/tmp/hh-lab-bays-boot/zorua_lab_boot.png`. Inspect the PNG at native resolution and confirm all three dark-floor bays are visible, the first bay has a visible mat/open slot, the central aisle is clear, and no bay reads as a cropped bookshelf.

- [ ] **Step 2: Capture each first-habitat starter outcome**

Run serially so forced builds cannot race on generated files:

```bash
HH_VERIFY_OUT=/private/tmp/hh-lab-bays-campfire tools/habitat/verify.sh --scenario lab-campfire
HH_VERIFY_OUT=/private/tmp/hh-lab-bays-plant tools/habitat/verify.sh --scenario lab-plant
HH_VERIFY_OUT=/private/tmp/hh-lab-bays-basin tools/habitat/verify.sh --scenario lab-basin
```

Expected: every command exits `0`. Inspect `lab_campfire.png`, `lab_plant.png`, and `lab_basin.png`; Torchic, Treecko, and Mudkip must each render with their complete body inside the first bay, separated from the Poké Ball holder and north-wall furniture.

- [ ] **Step 3: Capture all three completed recovery bays**

Run:

```bash
HH_VERIFY_OUT=/private/tmp/hh-lab-bays-recovery tools/habitat/verify.sh --scenario starter-recovery
```

Expected: exit `0` and `starter_recovery.png` shows three distinct residents in the three distinct bay centers, with no sprite sharing a foreground furniture cell.

- [ ] **Step 4: Run the complete Habitat regression set**

Run:

```bash
python3 tools/habitat/check_lab_layout.py
make -j4 check TESTS='Habitat'
sh tools/habitat/test_verify.sh
git diff --check
```

Expected: the static validator, all Habitat native tests, verifier self-tests, and whitespace check exit `0`.

- [ ] **Step 5: Record the evidence without overstating unrelated gates**

Update `docs/reports/2026-07-20-habitat-task-13-acceptance.md` with:

```markdown
## Lab habitat-bay visual correction

The original first-resident captures placed the resident beside foreground lab
furniture and provided no visible dormant habitat footprint. The approved
tilemap correction adds three persistent floor bays and separates dormant
interaction entrances from resident centers.

- `python3 tools/habitat/check_lab_layout.py`: passed; exact event identities,
  bay metatiles, resident positions, and central aisle validated.
- boot: `/private/tmp/hh-lab-bays-boot/zorua_lab_boot.png`
- Torchic: `/private/tmp/hh-lab-bays-campfire/lab_campfire.png`
- Treecko: `/private/tmp/hh-lab-bays-plant/lab_plant.png`
- Mudkip: `/private/tmp/hh-lab-bays-basin/lab_basin.png`
- all recovered: `/private/tmp/hh-lab-bays-recovery/starter_recovery.png`

At native GBA resolution, all three bays are visible before completion and all
three residents render completely inside their assigned bays. This evidence
resolves the reported lab layout defect; it does not approve pending narrative
copy, furnishing icons, or their provenance.
```

- [ ] **Step 6: Commit the evidence update**

```bash
git add docs/reports/2026-07-20-habitat-task-13-acceptance.md
git commit -m "docs: record visible lab habitat evidence"
```

- [ ] **Step 7: Verify final branch state**

Run:

```bash
git status --short
git log -3 --oneline
```

Expected: the worktree is clean. The newest commits are the evidence update, the visible-bays fix, and the approved design document.
