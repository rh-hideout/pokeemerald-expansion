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
        "local_id": "LOCALID_HABITAT_FRAME_TORCHIC",
        "graphics_id": "OBJ_EVENT_GFX_VAR_7",
        "x": 2,
        "y": 7,
        "elevation": 3,
        "movement_type": "MOVEMENT_TYPE_LOOK_AROUND",
        "movement_range_x": 0,
        "movement_range_y": 0,
        "trainer_type": "TRAINER_TYPE_NONE",
        "trainer_sight_or_berry_tree_id": "0",
        "script": "HabitatSpot_EventScript_Interact",
        "flag": "FLAG_UNUSED_0x040",
    },
    "LOCALID_HABITAT_FRAME_TREECKO": {
        "local_id": "LOCALID_HABITAT_FRAME_TREECKO",
        "graphics_id": "OBJ_EVENT_GFX_VAR_8",
        "x": 6,
        "y": 7,
        "elevation": 3,
        "movement_type": "MOVEMENT_TYPE_LOOK_AROUND",
        "movement_range_x": 0,
        "movement_range_y": 0,
        "trainer_type": "TRAINER_TYPE_NONE",
        "trainer_sight_or_berry_tree_id": "0",
        "script": "HabitatSpot_EventScript_Interact",
        "flag": "FLAG_UNUSED_0x041",
    },
    "LOCALID_HABITAT_FRAME_MUDKIP": {
        "local_id": "LOCALID_HABITAT_FRAME_MUDKIP",
        "graphics_id": "OBJ_EVENT_GFX_VAR_9",
        "x": 10,
        "y": 7,
        "elevation": 3,
        "movement_type": "MOVEMENT_TYPE_LOOK_AROUND",
        "movement_range_x": 0,
        "movement_range_y": 0,
        "trainer_type": "TRAINER_TYPE_NONE",
        "trainer_sight_or_berry_tree_id": "0",
        "script": "HabitatSpot_EventScript_Interact",
        "flag": "FLAG_UNUSED_0x042",
    },
}

ENTRANCES = [
    {
        "type": "sign",
        "x": 2,
        "y": 8,
        "elevation": 0,
        "player_facing_dir": "BG_EVENT_PLAYER_FACING_ANY",
        "script": "BirchsLab_EventScript_HabitatFrameTorchic",
    },
    {
        "type": "sign",
        "x": 6,
        "y": 8,
        "elevation": 0,
        "player_facing_dir": "BG_EVENT_PLAYER_FACING_ANY",
        "script": "BirchsLab_EventScript_HabitatFrameTreecko",
    },
    {
        "type": "sign",
        "x": 10,
        "y": 8,
        "elevation": 0,
        "player_facing_dir": "BG_EVENT_PLAYER_FACING_ANY",
        "script": "BirchsLab_EventScript_HabitatFrameMudkip",
    },
]

WARPS = [
    {
        "x": 6,
        "y": 12,
        "elevation": 0,
        "dest_map": "MAP_LITTLEROOT_TOWN",
        "dest_warp_id": "2",
    },
    {
        "x": 7,
        "y": 12,
        "elevation": 0,
        "dest_map": "MAP_LITTLEROOT_TOWN",
        "dest_warp_id": "2",
    },
]

FLOOR = 0x3202
DARK_FLOOR = 0x3203
BAY_CELLS = {
    (x, y)
    for start in (1, 5, 9)
    for x in range(start, start + 3)
    for y in range(5, 9)
}
FURNISHED_BAY = {
    (0, 5): 0x0618, (1, 5): 0x0619,
    (0, 6): 0x0620, (1, 6): 0x3221,
    (2, 5): 0x0612, (3, 5): 0x0613,
    (2, 6): 0x061A, (3, 6): 0x061B,
    (4, 5): 0x060D,
    (4, 6): 0x3233,
    (1, 7): 0x3206,
    (2, 7): 0x3207,
}
UPPER_CLEAR_CELLS = {(x, y) for x in range(4) for y in range(3, 5)}
RESIDENT_CELLS = {(2, 7), (6, 7), (10, 7)}
CLEAR_ACCESS_CELLS = (
    {(x, 9) for x in range(2, 11)}
    | {(6, y) for y in range(10, 12)}
)
SPAWN = (6, 10)
WALKABLE = {FLOOR, DARK_FLOOR, 0x3206, 0x3207, 0x0206, 0x0207}


def fail(message):
    print(f"lab-layout: {message}", file=sys.stderr)
    raise SystemExit(1)


def main():
    data = json.loads(MAP_JSON.read_text())
    objects = {event["local_id"]: event for event in data["object_events"]}
    if len(objects) != len(data["object_events"]) or set(objects) != set(OBJECTS):
        fail(f"unexpected object IDs: {sorted(objects)}")

    for local_id, expected in OBJECTS.items():
        event = objects[local_id]
        if event != expected:
            fail(f"{local_id} expected {expected}, found {event}")

    if data["bg_events"] != ENTRANCES:
        fail(f"background entrances expected {ENTRANCES}, found {data['bg_events']}")
    if data["warp_events"] != WARPS:
        fail(f"warp events expected {WARPS}, found {data['warp_events']}")
    if data["coord_events"] != []:
        fail(f"coordinate events expected [], found {data['coord_events']}")

    entrance_cells = {(event["x"], event["y"]) for event in ENTRANCES}
    warps = {(event["x"], event["y"]) for event in WARPS}
    occupied = {(expected["x"], expected["y"]) for expected in OBJECTS.values()}
    if warps & occupied or warps & entrance_cells or occupied & entrance_cells:
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
        expected = FURNISHED_BAY.get(coords, DARK_FLOOR)
        if block_at(coords) != expected:
            fail(f"bay cell {coords} expected 0x{expected:04X}, found 0x{block_at(coords):04X}")
    for coords, expected in FURNISHED_BAY.items():
        if block_at(coords) != expected:
            fail(f"furnished bay cell {coords} expected 0x{expected:04X}, found 0x{block_at(coords):04X}")
    for coords in UPPER_CLEAR_CELLS:
        if block_at(coords) != FLOOR:
            fail(f"upper cleared cell {coords} expected 0x{FLOOR:04X}, found 0x{block_at(coords):04X}")
    for coords in RESIDENT_CELLS:
        if block_at(coords) not in {DARK_FLOOR, 0x3207}:
            fail(f"resident cell {coords} is not unobstructed bay floor")
    for coords in CLEAR_ACCESS_CELLS:
        if block_at(coords) != FLOOR:
            fail(f"access aisle cell {coords} is not clear floor")
    for coords in entrance_cells:
        if block_at(coords) != DARK_FLOOR:
            fail(f"bay entrance {coords} is not walkable dark floor")

    if block_at(SPAWN) not in WALKABLE:
        fail(f"spawn {SPAWN} is not walkable")
    reachable = {SPAWN}
    frontier = [SPAWN]
    while frontier:
        x, y = frontier.pop()
        for neighbor in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
            nx, ny = neighbor
            if (0 <= nx < WIDTH and 0 <= ny < HEIGHT and neighbor not in reachable
                    and block_at(neighbor) in WALKABLE):
                reachable.add(neighbor)
                frontier.append(neighbor)
    required_reachable = entrance_cells | warps
    if not required_reachable <= reachable:
        fail(f"spawn cannot reach {sorted(required_reachable - reachable)}")

    print("lab-layout: visible bays, resident positions, entrances, and aisle are valid")


if __name__ == "__main__":
    main()
