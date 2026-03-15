import json
import pathlib
import re
import sys

TERNARY_CONDITION_PAT = re.compile(r"=([^,\n]+)\?")
TERNARY_PAT = re.compile(r"\(?([01])\)?\s*\?\s*([^:]+):\s*(.+?)(,\s*\.)")
COMMENT_PAT = re.compile(r"\n#.+")
FIELD_PAT = re.compile(r"\.(\w+)\s*=\s*([\s\S]+?)(?=,\s*[\.}])")

ABILITY_PAT = re.compile(r"ABILITY_\w+")
ANIMFRAMES_PAT = re.compile(r"[A-Z_]+\([\d, ]+\)")
PICSIZE_PAT = re.compile(r"MON_COORDS_SIZE+\(\s*(\d+)\s*,\s*(\d+)\s*\)")
EVOLUTION_PAT = re.compile(r"\{\s*(EVO_\w+)\s*,\s*(\w+)\s*,\s*(SPECIES_\w+)\s*,?\s*(\[.+?\])?\s*\}")
EVO_CONDITION_PAT = re.compile(r"\{\s*(\w+)\s*(,\s*\w+\s*){0,3}\}")

def remove_comment_lines(species_file):
    #(species_file, n) = re.subn(COMMENT_PAT2, "", species_file)
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
        data[a[1]] = a[2].strip()
    return data

def parse_abilities(abilties_string):
    a = re.findall(ABILITY_PAT, abilties_string)
    abilities = [a[0], "ABILITY_NONE"]
    hidden_ability = "ABILITY_NONE"
    if len(a) >= 2:
        abilities[1] = a[1]
    if len(a) == 3:
        hidden_ability = a[2]
    return (abilities, hidden_ability)

def parse_conditions(conditions_string):
    conditions = []
    for a in re.finditer(EVO_CONDITION_PAT, conditions_string):
        cond = {"type": a[1], "params": []}
        for i in range(2, a.lastindex + 1):
            cond["params"].append(a[i].strip(" ,"))
        conditions.append(cond)
    return conditions;

def parse_evolution(evolution_string):
    evolutions = []
    for a in re.finditer(EVOLUTION_PAT, evolution_string):
        evo = {"type": a[1], "param": a[2], "targetSpecies": a[3]}
        if evo["param"].isdigit():
            evo["param"] = int(evo["param"])
        if a[4]:
            evo["conditions"] = parse_conditions(a[4])
        evolutions.append(evo)
    return evolutions

def parse_description(description_string):
    if description_string[0] != "[":
        return description_string
    description_string = description_string.replace("\" \"", "\", \"")
    return eval(description_string)

def parse_animframes(animframes_string):
    if animframes_string[0] != "{":
        return animframes_string
    animframes = []
    for a in re.finditer(ANIMFRAMES_PAT, animframes_string):
        animframes.append(a[0])
    return animframes

def parse_picsize(picsize_string):
    a = re.search(PICSIZE_PAT, picsize_string)
    return {"width": int(a[1]), "height": int(a[2])}

def clean_data(species):
    cleaned_species = {}
    for key, value in species.items():
        if key == "abilities":
            (abilities, hidden_ability) = parse_abilities(value)
            cleaned_species["abilities"] = abilities
            cleaned_species["hidden_ability"] = hidden_ability
        elif key in ["shadow", "overworld", "overworldF"]:
            cleaned_species[key] = eval(value)
        elif key in ["backPicSize", "frontPicSize"]:
            cleaned_species[key] = parse_picsize(value)
        elif key == "evolutions":
            cleaned_species["evolutions"] = parse_evolution(value)
        elif key == "description":
            cleaned_species["description"] = parse_description(value)
        elif key == "frontAnimFrames":
            cleaned_species["frontAnimFrames"] = parse_animframes(value)
        elif value.isdigit():
            cleaned_species[key] = int(value)
        elif value[0] == "[" or value[0] == "\"":
            cleaned_species[key] = eval(value)
        else:
            cleaned_species[key] = value

    return cleaned_species


def parse_species(index, species_file, species):
    while species_file[index] != "[":
        index+=1
        if index == len(species_file):
            return (index, species)
    (index, species_name) = parse_name(index + 1, species_file)
    (index, data_string) = parse_data_string(index, species_file)
    data_string = re.sub(r"[^,\s](\s+\})$", r",\1", data_string) #add trailing commas if missing
    data = parse_data(data_string)
    data = clean_data(data)
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

    for a in re.finditer(TERNARY_CONDITION_PAT, species_file):
        condition = a[1].strip("() ")
        (condition, n) = re.subn(r"([A-Z_]+)", r'"\1"', condition)
        for b in [("||", "or"), ("&&", "and"), ("!", "not ")]:
            condition = condition.replace(b[0], b[1])
        if eval(condition):
            species_file = species_file.replace(a[1], "1")
        else:
            species_file = species_file.replace(a[1], "0")

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