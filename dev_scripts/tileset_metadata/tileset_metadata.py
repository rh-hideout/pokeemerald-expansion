import json
import os
import re
import struct
import sys

def exit_with_msg(msg):
    raise Exception(msg)

def get_number_of_tiles(folder_path, locations):
    with open(locations["tiles"], 'rb') as f:
        data = f.read()
    if (not (data[:8] == b'\211PNG\r\n\032\n'and (data[12:16] == b'IHDR'))):
        exit_with_msg("tiles.png data does not match standard png")
    w, h = struct.unpack('>LL', data[16:24])
    width = int(w)
    height = int(h)
    return int(width * height / 64)

def get_number_of_palettes(folder_path):
    num_palettes = 0
    for i in range(16):
        palette_path = os.path.join(folder_path, "palettes/" + str(i).zfill(2) + ".pal")
        is_empty_palette = True
        if not os.path.exists(palette_path):
            break
        with open(palette_path, 'r') as f:
            palette_file = f.readlines()
        for j, line in enumerate(palette_file):
            if j < 3:
                continue
            if j == 19:
                break
            match = re.match(r"(\d+) (\d+) (\d+)", line)
            if not match:
                exit_with_msg("could not properlay parse " + palette_path)
            if (int(match.group(1)) != 0 or int(match.group(2)) != 0 or int(match.group(3)) != 0):
                is_empty_palette = False
                break
        if not is_empty_palette:
            num_palettes += 1
    return num_palettes

def get_metatiles_info(folder_path, locations):
    metatiles_size = os.path.getsize(locations["metatiles"])
    metatile_attributes_size = os.path.getsize(locations["metatile_attributes"])
    ratio = metatiles_size / metatile_attributes_size;
    if ratio % 3 == 0:
        has_triple_layer = True
        ratio /= 3
        metatiles_count = int(metatiles_size / 24)
    else:
        has_triple_layer = False
        ratio /= 2
        metatiles_count = int(metatiles_size / 16)
    if ratio == 4:
        has_32bit_attributes = False
    elif ratio == 2:
        has_32bit_attributes = True
    else:
        exit_with_msg("could not parse metatile information")
    return metatiles_count, has_triple_layer, has_32bit_attributes


def verify_tileset(folder_path, tilesets_folder):
    if os.path.exists(os.path.join(folder_path, "locations.json")):
        with open(os.path.join(folder_path, "locations.json"), "r") as f:
            locations = json.load(f)
        for key, path in locations.items():
            locations[key] = os.path.join(tilesets_folder, path)
        return locations
    locations = {}
    if not os.path.exists(os.path.join(folder_path, "palettes")):
        exit_with_msg("tileset folder is missing palettes folder")
    else:
        locations["palettes"] = os.path.join(folder_path, "palettes")
    if not os.path.exists(os.path.join(folder_path, "tiles.png")):
        exit_with_msg("tileset folder is missing tiles.png file")
    else:
        locations["tiles"] = os.path.join(folder_path, "tiles.png")
    if not os.path.exists(os.path.join(folder_path, "metatiles.bin")):
        exit_with_msg("tileset folder is missing metatiles.bin file")
    else:
        locations["metatiles"] = os.path.join(folder_path, "metatiles.bin")
    if not os.path.exists(os.path.join(folder_path, "metatile_attributes.bin")):
        exit_with_msg("tileset folder is missing metatile_attributes.bin file")
    else:
        locations["metatile_attributes"] = os.path.join(folder_path, "metatile_attributes.bin")
    return locations

def get_tileset_metadata(folder_path, tilesets_folder):
    try:
        locations = verify_tileset(folder_path, tilesets_folder)
        tiles = get_number_of_tiles(folder_path, locations)
        #palettes = get_number_of_palettes(folder_path)
        metatiles, has_triple_layer, has_32bit_attributes = get_metatiles_info(folder_path, locations)
    except Exception as e:
      print(e)
      return (None, None)
    result = {"tiles": tiles, "metatiles": metatiles, "has_triple_layer": has_triple_layer, "has_32bit_attributes": has_32bit_attributes}
    return (locations, result)

'''
def is_valid_schema(schema):
    bitfield = [0] * schema["size"]
    for attribute in schema["attributes"]:
        if attribute["starting_bit"] + attribute["bitfield_size"] > schema["size"]:
            print("Invalid attribute schema, field " + attribute["field"] + " is outside bit range")
            return False
        for i in range(attribute["starting_bit"]):
            if bitfield[attribute["bitfield_size"] + i] == 1:
                print("Invalid attribute schema, field " + attribute["field"] + " is overlapping with another field")
                return False
            bitfield[i] = 1;
        field_values_count = 1 << attribute["bitfield_size"]
        if len(schema[attribute["field"]]) != field_values_count:
            print("Invalid attribute schema, field " + attribute["field"] + " has " + str(len(schema[attribute["field"]])) + " elements, expected " + str(field_values_count))
            return False
    return True
'''

def write_metatiles_csv(tileset_name, metatile_attributes_path, metatiles_path, schema, is_triple_layer):
    with open(metatiles_path, "rb") as f:
        data = f.read()
    metatiles_data = list(struct.unpack("<" + "H" * (len(data) // 2), data))
    with open(metatile_attributes_path, "rb") as f:
        data = f.read()
    if schema["size"] == 16:
        metatile_attributes = list(struct.unpack("<" + "H" * (len(data) // 2), data))
    elif schema["size"] == 32:
        metatile_attributes = list(struct.unpack("<" + "I" * (len(data) // 4), data))
    else:
        print("error: " + metatile_attributes_path + " schema has an unsupported attributes size")
        return
    #print(metatile_attributes)
    first_line = "label," + ",".join(schema["attributes"].keys()) + ",tile1,tile2,tile3,tile4,tile5,tile6,tile7,tile8"
    if is_triple_layer:
        first_line += ",tile9,tile10,tile11,tile12"
        tiles_per_metatile = 12
    else:
        tiles_per_metatile = 8
    csv_lines = [first_line + "\n"]
    for i in range(len(metatiles_data) // tiles_per_metatile):
        line = tileset_name.capitalize() + "Label" + str(i) + ","
        for attribute, mask in schema["attributes"].items():
            mask = int(mask, 16)
            value = metatile_attributes[i] & mask;
            while mask & 1 == 0:
                mask = mask >> 1
                value = value >> 1
            if schema[attribute][value] == None:
                print("error: " + metatile_attributes_path + " schema does not support value " + str(value) + "for " + attribute + " attribute")
                return
            value = schema[attribute][value]
            line += str(value) + ","
        metatile_offset = i * tiles_per_metatile
        tiles = metatiles_data[(i * tiles_per_metatile):((i + 1) * tiles_per_metatile)]
        tiles = [str(tile) for tile in tiles]
        line = line + (",").join(tiles)
        csv_lines.append(line + "\n")
    with open(os.path.join(os.path.dirname(metatiles_path), "metatiles.csv"), "w+") as f:
        f.writelines(csv_lines)

def clean_tileset_palettes(palettes_folder_path, palettes_start, palettes_end):
    for i in range(16):
        if i >= palettes_start and i < palettes_end:
            continue
        palette_path = os.path.join(palettes_folder_path, str(i).zfill(2) + ".pal")
        new_lines = []
        with open(palette_path, 'r') as f:
            palette_file = f.readlines()
        for j, line in enumerate(palette_file):
            if j >= 3 and j < 19:
                line = "0 0 0\n"
            new_lines.append(line)
        with open(palette_path, 'w+') as f:
            f.writelines(new_lines)

if __name__ == '__main__':
    if len(sys.argv) > 1:
        folder_path = sys.argv[1]
    else:
        print("need tileset folder as argument")
        sys.exit(1)
    if (len(sys.argv) > 2):
        tilesets_folder = sys.argv[2]
    else:
        tilesets_folder = "data/tilesets"
    locations, result = get_tileset_metadata(folder_path)
    if (result == None):
        sys.exit(1)
    print(json.dumps(result, indent=4))
    #with open("test.json", "w+") as f:
    #    json.dump(result, f, indent=4)

