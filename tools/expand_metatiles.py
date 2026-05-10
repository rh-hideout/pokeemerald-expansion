#!/usr/bin/env python3
"""
Migrate data/layouts/*/map.bin and border.bin from the original 10/2/4-bit
(metatile/collision/elevation) packing to the expanded 11/1/4-bit packing.

Old layout:  [elev:4][coll:2][metatile:10]   (NUM_METATILES_IN_PRIMARY = 512)
New layout:  [elev:4][coll:1][metatile:11]   (NUM_METATILES_IN_PRIMARY = 1024)

- Secondary tileset metatiles (old IDs 512..1023) shift up by 512 to land in
  the new secondary range (1024..1535).
- Collision is reduced to its low bit. The original 2-bit field only ever held
  0 or "impassable" (= mask), and the impassable encoding's low bit is 1, so
  the mapping preserves semantics.
- Elevation is unchanged (still 4 bits, still in the top nibble), so no
  elevation values are lost.

Run from the repo root:
    python3 tools/expand_metatiles.py
"""

import os
import struct

OLD_METATILE_MASK  = 0x03FF  # bits 0-9
OLD_COLLISION_MASK = 0x0C00  # bits 10-11
OLD_ELEVATION_MASK = 0xF000  # bits 12-15
OLD_COLLISION_SHIFT = 10
OLD_ELEVATION_SHIFT = 12

NEW_METATILE_MASK   = 0x07FF  # bits 0-10
NEW_COLLISION_MASK  = 0x0800  # bit 11
NEW_ELEVATION_MASK  = 0xF000  # bits 12-15 (unchanged)
NEW_COLLISION_SHIFT = 11
NEW_ELEVATION_SHIFT = 12

OLD_PRIMARY_COUNT = 512
NEW_PRIMARY_COUNT = 1024
SECONDARY_SHIFT   = NEW_PRIMARY_COUNT - OLD_PRIMARY_COUNT  # 512

def remap_metatile_id(metatile_id):
    if metatile_id >= OLD_PRIMARY_COUNT:
        return metatile_id + SECONDARY_SHIFT
    return metatile_id

def process_map_value(value):
    metatile_id = value & OLD_METATILE_MASK
    collision   = (value & OLD_COLLISION_MASK) >> OLD_COLLISION_SHIFT
    elevation   = (value & OLD_ELEVATION_MASK) >> OLD_ELEVATION_SHIFT

    metatile_id = remap_metatile_id(metatile_id)
    collision  &= 0x1  # reduce 2-bit field to its low bit

    return (metatile_id & NEW_METATILE_MASK) \
         | ((collision & 0x1) << NEW_COLLISION_SHIFT) \
         | ((elevation & 0xF) << NEW_ELEVATION_SHIFT)

def process_border_value(value):
    # Border blocks store only the metatile id; no collision or elevation.
    return remap_metatile_id(value & OLD_METATILE_MASK) & NEW_METATILE_MASK

def read_bin(path):
    with open(path, "rb") as f:
        data = f.read()
    return list(struct.unpack("<" + "H" * (len(data) // 2), data))

def write_bin(path, values):
    with open(path, "wb") as f:
        f.write(struct.pack("<" + "H" * len(values), *values))

def find_files(name):
    out = []
    for root, _, files in os.walk("data/layouts"):
        if name in files:
            out.append(os.path.join(root, name))
    return out

def process_all(name, fn):
    for path in find_files(name):
        print(f"Processing {path}...")
        write_bin(path, [fn(v) for v in read_bin(path)])

if __name__ == "__main__":
    process_all("map.bin", process_map_value)
    process_all("border.bin", process_border_value)
