import json
import pathlib
import re
import sys

RELATIONAL_PAT = re.compile(r"\d+\s*[><]=?\s*\d+")
TERNARY_PAT = re.compile(r"\(?([01])\)?\s*\?\s*([^:]+):\s*(.+?)(,\s*\.)")
COMMENT_PAT = re.compile(r"\n[ \t]*//.*")
COMMENT_PAT2 = re.compile(r"#.+\n")
FIELD_PAT = re.compile(r"\.(\w+)\s*=\s*(.+?)(?=,\s*[\.}])")

def remove_comment_lines(species_file):
    (species_file, n) = re.subn(COMMENT_PAT2, "", species_file)
    (species_file, n) = re.subn(COMMENT_PAT, "", species_file)
    return species_file

def parse_name(i, string):
    name = "";
    while string[i] != "]":
        name += string[i]
        i+=1
    return (i, name)

def parse_data_string(i, string):
    while string[i] != "{":
        i+=1
    data = ""
    bracket_count = 0
    while string[i] != "}" or bracket_count > 0:
        data += string[i]
        if string[i] == "{":
            bracket_count += 1
        i+=1
        if string[i] == "}":
            bracket_count -= 1
    data += string[i]
    return (i, data)

def parse_data(data_string):
    data = {}
    for a in re.finditer(FIELD_PAT, data_string):
        data[a[1]] = a[2]
    return data

def parse_species(index, species_file, species):
    while species_file[index] != "[":
        index+=1
        if index == len(species_file):
            return (index, species)
    (index, species_name) = parse_name(index + 1, species_file)
    (index, data_string) = parse_data_string(index, species_file)
    data = parse_data(data_string)
    species[species_name] = data
    return (index, species)

def main():
    species_file = sys.stdin.read()

    if len(sys.argv) < 2:
        print("Missing required arguments", file=sys.stderr)
        print(__doc__, file=sys.stderr)
        quit(1)

    OUTPUT_FILE = pathlib.Path(sys.argv[1])

    assert OUTPUT_FILE.parent.exists(), f"parent of {OUTPUT_FILE=} does not exist"

    species_file = remove_comment_lines(species_file)

    for a in re.finditer(RELATIONAL_PAT, species_file):
        if eval(a[0]):
            species_file = species_file.replace(a[0], "1")
        else:
            species_file = species_file.replace(a[0], "0")

    for a in re.finditer(TERNARY_PAT, species_file):
        if a[1] == 0:
            species_file = species_file.replace(a[0], a[3] + a[4])
        else:
            species_file = species_file.replace(a[0], a[2] + a[4])
    species = {}
    char_index = 0
    
    while char_index < len(species_file):
        (char_index, species) = parse_species(char_index, species_file, species)
    with open(OUTPUT_FILE, "w+") as f:
        json.dump(species, f, indent=4)

if __name__ == "__main__":
    main()