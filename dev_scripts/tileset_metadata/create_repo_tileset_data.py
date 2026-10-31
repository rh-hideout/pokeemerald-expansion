import glob
import json
import os
import re
import sys

import tileset_metadata

def exit_with_msg(msg):
    print(msg)
    sys.exit(1)

def is_tileset_folder(folder_path):
    try:
        tileset_metadata.verify_tileset(folder_path, "data/tilesets")
        return True
    except:
        return False

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

metatiles_in_primary = [0, 0]
pals_in_primary = [0, 0]
repo_schemas = []
num_pals_total = 0
with open("include/fieldmap.h", "r") as f:
    lines = f.readlines()
    for line in lines:
        match = re.match(r'#define\s+(\w+)\s+(\d+)', line)
        if match:
            if match.group(1) == "NUM_METATILES_IN_PRIMARY":
                if metatiles_in_primary[0] == 0:
                    metatiles_in_primary[0] = int(match.group(2))
                else:
                    exit_with_msg("NUM_METATILES_IN_PRIMARY is defined twice")
            elif match.group(1) == "NUM_METATILES_IN_PRIMARY_FRLG":
                if metatiles_in_primary[1] == 0:
                    metatiles_in_primary[1] = int(match.group(2))
                else:
                    exit_with_msg("NUM_METATILES_IN_PRIMARY_FRLG is defined twice")
            elif match.group(1) == "NUM_PALS_IN_PRIMARY":
                if pals_in_primary[0] == 0:
                    pals_in_primary[0] = int(match.group(2))
                else:
                    exit_with_msg("NUM_PALS_IN_PRIMARY is defined twice")
            elif match.group(1) == "NUM_PALS_IN_PRIMARY_FRLG":
                if pals_in_primary[1] == 0:
                    pals_in_primary[1] = int(match.group(2))
                else:
                    exit_with_msg("NUM_METATILES_IN_PRIMARY_FRLG is defined twice")
            elif match.group(1) == "NUM_PALS_TOTAL":
                num_pals_total = int(match.group(2))


if metatiles_in_primary[0] == 0:
    exit_with_msg("NUM_METATILES_IN_PRIMARY was not found")
if pals_in_primary[0] == 0:
    exit_with_msg("NUM_PALS_IN_PRIMARY was not found")
if num_pals_total == 0:
    exit_with_msg("NUM_PALS_TOTAL was not found")

if metatiles_in_primary[1] == 0 and pals_in_primary[1] == 0:
    isExpansion = False
elif metatiles_in_primary[1] > 0 and pals_in_primary[1] > 0:
    isExpansion = True
else:
    exit_with_msg("weird repo data")

with open('metatile_attributes_schema.json', 'r') as f:
    repo_schemas.append(json.load(f))
    if not tileset_metadata.is_valid_schema(repo_schemas[0]):
        sys.exit(1)

if isExpansion:
    if not os.path.exists("metatile_attributes_schema_frlg.json"):
        exit_with_msg("expansion repo is missing frlg metaile attributes schema")
    with open('metatile_attributes_schema_frlg.json', 'r') as f:
        repo_schemas.append(json.load(f))
    if not tileset_metadata.is_valid_schema(repo_schemas[1]):
        sys.exit(1)

for root, subdirs, files in os.walk("data/tilesets/primary"):
    if not is_tileset_folder(root):
        continue
    locations, result = tileset_metadata.get_tileset_metadata(root, "data/tilesets")
    if (result == None):
        print("error in " + root)
        continue
    result["palettes_start"] = 0
    if result["has_32bit_attributes"] and isExpansion:
        result["padded_metatiles"] = metatiles_in_primary[1]
        result["palettes_end"] = pals_in_primary[1]
        schema = repo_schemas[1]
    else:
        result["padded_metatiles"] = metatiles_in_primary[0]
        result["palettes_end"] = pals_in_primary[0]
        schema = repo_schemas[0]
    metadata_path = os.path.join(root, "metadata.json")
    with open(metadata_path, 'w+') as f:
        json.dump(result, f, indent=4)
    tileset_metadata.write_tileset_schema(locations["metatile_attributes"], schema)

for root, subdirs, files in os.walk("data/tilesets/secondary"):
    if not is_tileset_folder(root):
        continue
    locations, result = tileset_metadata.get_tileset_metadata(root, "data/tilesets")
    if (result == None):
        print("error in " + root)
        continue
    if result["has_32bit_attributes"] and isExpansion:
        result["metatile_offset"] = metatiles_in_primary[1]
        result["palettes_start"] = pals_in_primary[1]
        schema = repo_schemas[1]
    else:
        result["metatile_offset"] = metatiles_in_primary[0]
        result["palettes_start"] = pals_in_primary[0]
        schema = repo_schemas[0]
    result["palettes_end"] = num_pals_total
    metadata_path = os.path.join(root, "metadata.json")
    with open(metadata_path, 'w+') as f:
        json.dump(result, f, indent=4)
    tileset_metadata.write_tileset_schema(locations["metatile_attributes"], schema)
