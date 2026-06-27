#!/usr/bin/env python3

"""
Reads a list of region maps data and create a sections layout file it doesn't exist
The layout file are created with only "null" sections that compile but still need to be edited 
through a text editor or porymap to fulfill their gameplay purposes
"""

import json
import os
import pathlib
import sys


def create_missing_files(json_data):
    for region in json_data["region_maps"]:
        if not "layoutFile" in region:
            continue
        if os.path.exists(region["layoutFile"]):
            continue

        string = "static const mapsec_u8_t sRegionMap_SectionLayout_" + region["label"].capitalize()
        string = string + "[" + str(region["layout_height"]) + "][" + str(region["layout_width"]) + "] = {\n"
        for y in range(0, region["layout_height"]):
            line = "    {"
            for x in range(0, region["layout_width"]):
                line += " MAPSEC_NONE,"
            line = ''.join(list(line)[:-1]) + " },"
            string = string + line + "\n"
        string += "};\n"

        with open(region["layoutFile"], "w+") as f:
            f.write(string)


def main():
    if len(sys.argv) != 2:
        print("Invalid number of arguments", file=sys.stderr)
        print(__doc__, file=sys.stderr)
        quit(1)

    SOURCE_FILE = pathlib.Path(sys.argv[1])
    with open(SOURCE_FILE, "r") as f:
        json_data = json.load(f)
    create_missing_files(json_data)

if __name__ == "__main__":
    main()
