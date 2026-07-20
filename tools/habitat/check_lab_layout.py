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
        "coords": (2, 5),
        "graphics_id": "OBJ_EVENT_GFX_VAR_7",
        "flag": "FLAG_UNUSED_0x040",
    },
    "LOCALID_HABITAT_FRAME_TREECKO": {
        "coords": (6, 5),
        "graphics_id": "OBJ_EVENT_GFX_VAR_8",
        "flag": "FLAG_UNUSED_0x041",
    },
    "LOCALID_HABITAT_FRAME_MUDKIP": {
        "coords": (10, 5),
        "graphics_id": "OBJ_EVENT_GFX_VAR_9",
        "flag": "FLAG_UNUSED_0x042",
    },
}

ENTRANCES = {
    (2, 6): "BirchsLab_EventScript_HabitatFrameTorchic",
    (6, 6): "BirchsLab_EventScript_HabitatFrameTreecko",
    (10, 6): "BirchsLab_EventScript_HabitatFrameMudkip",
}

FLOOR = 0x3202
DARK_FLOOR = 0x3203
BAY_CELLS = {
    (x, y)
    for start in (1, 5, 9)
    for x in range(start, start + 3)
    for y in range(3, 7)
}
BAY_OVERRIDES = {
    (3, 3): 0x060D,  # Poké Ball holder, top
    (3, 4): 0x3233,  # holder's table base
    (1, 5): 0x3206,  # open-slot mat, left half
    (2, 5): 0x3207,  # open-slot mat, right half / first resident
}
RESIDENT_CELLS = {(2, 5), (6, 5), (10, 5)}
CLEAR_ACCESS_CELLS = (
    {(x, 7) for x in range(WIDTH)}
    | {(6, y) for y in range(8, 12)}
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
