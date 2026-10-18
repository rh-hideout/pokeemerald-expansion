import json
import pathlib
import re
import sys

import c_data_parser

COMMENT_PAT1 = re.compile(r"^#.+")
COMMENT_PAT2 = re.compile(r"\n#.+")

def remove_comment_lines(species_file):
    (species_file, n) = re.subn(COMMENT_PAT2, "", species_file)
    species_file = re.sub(COMMENT_PAT1, "", species_file)
    return species_file

def main():
    species_file = sys.stdin.read()

    if len(sys.argv) < 2:
        print("Missing required arguments", file=sys.stderr)
        print(__doc__, file=sys.stderr)
        quit(1)

    OUTPUT_FILE = pathlib.Path(sys.argv[1])

    assert OUTPUT_FILE.parent.exists(), f"parent of {OUTPUT_FILE=} does not exist"

    species_file = remove_comment_lines(species_file)
    result = c_data_parser.file_parse(species_file)

    all_species = {}
    for gen in result.values():
        all_species = all_species | gen

    with open(OUTPUT_FILE, "w+") as f:
        json.dump(all_species, f, indent=4)

    quit(0)

if __name__ == "__main__":
    main()