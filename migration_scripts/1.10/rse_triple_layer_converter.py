import os
import struct

layer_type_mask = 0xF000
layer_type_shift = 12
tileset_root = './data/tilesets'

if not os.path.exists("Makefile"):
    print("Please run this script from the root folder containing the Makefile.")
    exit(1)

primary_path = os.path.join(tileset_root, 'primary')
secondary_path = os.path.join(tileset_root, 'secondary')

if not os.path.exists(primary_path):
    print(f"[ERR] The primary folder does not exist within {tileset_root}, aborting.")
    exit(1)

    if not os.path.exists(secondary_path):
        print(f"[ERR] The secondary folder does not exist within {tileset_root}, aborting.")
    exit(1)

tileset_dirs = []

_, dirs, _ = next(os.walk(primary_path))
tileset_dirs += [os.path.join(primary_path, d) for d in dirs]
_, dirs, _ = next(os.walk(secondary_path))
tileset_dirs += [os.path.join(secondary_path, d) for d in dirs]

for tileset_dir in tileset_dirs:
    tileset_name = os.path.basename(tileset_dir)
    metatiles_path = os.path.join(tileset_dir, 'metatiles.bin')
    metatile_attributes_path = os.path.join(tileset_dir, 'metatile_attributes.bin')

    if not os.path.exists(metatiles_path):
        print(f"[SKIP] {tileset_name} skipped because metatiles.bin was not found.")
        continue
    if not os.path.exists(metatile_attributes_path):
        print(f"[SKIP] {tileset_name} skipped because metatile_attributes.bin was not found.")
        continue
    if os.path.getsize(metatiles_path) != 8 * os.path.getsize(metatile_attributes_path):
        print(f"[SKIP] {tileset_name} skipped because metatiles.bin is not eight times the size of metatile_attributes.bin (already converted?)")
        continue

    layer_types = []
    meta_attributes = []
    with open(metatile_attributes_path, 'rb') as fileobj:
        while (chunk := fileobj.read(2)):
            metatile_attribute = struct.unpack('<H', chunk)[0]
            meta_attributes.append(metatile_attribute & 0x0FFF)
            layer_types.append((metatile_attribute & layer_type_mask) >> layer_type_shift)

    i = 0
    new_metatile_data = []

    with open(metatiles_path, 'rb') as fileobj:
        while (chunk := fileobj.read(16)):
            metatile_data = struct.unpack('<HHHHHHHH', chunk)
            if layer_types[i] == 0:
                new_metatile_data += [0]*4
                new_metatile_data += metatile_data
            elif layer_types[i] == 1:
                new_metatile_data += metatile_data
                new_metatile_data += [0]*4
            elif layer_types[i] == 2:
                new_metatile_data += metatile_data[:4]
                new_metatile_data += [0]*4
                new_metatile_data += metatile_data[4:]
            else:
                new_metatile_data += [0]*12
            i += 1

    metatile_buffer = struct.pack(f'<{len(new_metatile_data)}H', *new_metatile_data)
    metatile_attribute_buffer = struct.pack(f'<{len(meta_attributes)}H', *meta_attributes)
    with open(metatiles_path, 'wb') as fileobj:
        fileobj.write(metatile_buffer)
    with open(metatile_attributes_path, 'wb') as fileobj:
        fileobj.write(metatile_attribute_buffer)
    print(f'[OK] Converted {tileset_name}')

    config_path = './porymap.project.cfg'

if os.path.exists(config_path):
    with open(config_path, 'r') as file:
        config_lines = file.readlines()

    modified = False
    for i, line in enumerate(config_lines):
        if "enable_triple_layer_metatiles=0" in line:
            config_lines[i] = "enable_triple_layer_metatiles=1\n"
            modified = True

    if modified:
        with open(config_path, 'w') as file:
            file.writelines(config_lines)
        print("[OK] Porymap has been changed to enable triple layer metatiles. If you have the program open, please close it and open it again.")
    else:
        print("[OK] Porymap already enabled triple layer metatiles.")
else:
    print("[WARN] Porymap's project config file could not be found to automatically enable triple layer metatiles.")
