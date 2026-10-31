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

def make_empty_tileset_schema(schema):
    new_schema = {}
    new_schema["size"] = schema["size"]
    new_schema["attributes"] = []
    for attr in schema["attributes"]:
        new_attr = {"field": attr["field"], "starting_bit": attr["starting_bit"], "bitfield_size": attr["bitfield_size"]}
        new_schema["attributes"].append(new_attr)
        new_schema[attr["field"]] = [None] * len(schema[attr["field"]])
    return new_schema

def write_tileset_schema(metatile_attributes_path, schema):
    tileset_schema = make_empty_tileset_schema(schema)
    with open(metatile_attributes_path, "rb") as f:
        data = f.read()
    if schema["size"] == 16:
        metatiles = list(struct.unpack("<" + "H" * (len(data) // 2), data))
    elif schema["size"] == 32:
        metatiles = list(struct.unpack("<" + "I" * (len(data) // 4), data))
    else:
        print("error: " + metatile_attributes_path + " schema has an unsupported attributes size")
        return
    metatiles_labels = []
    for attribute in schema["attributes"]:
        mask = ((1 << attribute["bitfield_size"]) - 1) << attribute["starting_bit"]
        field = attribute["field"]
        for metatile in metatiles:
            value = (metatile & mask) >> attribute["starting_bit"]
            if schema[field][value] == None:
                print("error: " + metatile_attributes_path + " tileset uses value undefined in schema")
                return
            tileset_schema[field][value] = schema[field][value]
    with open(os.path.join(os.path.dirname(metatile_attributes_path), "attributes_schema.json"), "w+") as f:
        json.dump(tileset_schema, f, indent=4)

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

