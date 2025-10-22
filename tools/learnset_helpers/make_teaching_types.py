import glob
import json
import pathlib
import re
import sys
import typing

CONFIG_ENABLED_PAT = re.compile(r"#define P_LEARNSET_HELPER_TEACHABLE\s+(?P<cfg_val>[^ ]*)")

TEACHING_TYPE_PAT =  re.compile(r"\s*\.teachingType\s*=\s*(?P<teaching_type>[A-Z_]+),")
LEARNSET_PAT = re.compile(r"\s*\.teachableLearnset\s*=\s*s(?P<name>\w+?)TeachableLearnset")
FAMILY_PAT = re.compile(r"#(?P<end>end)?if (//)?P_FAMILY_\w+")
FORMS_PAT = re.compile(r"#(?P<end>end)?if (//)?P_(?P<forms>\w+)_FORMS")
CROSSGEN_EVOS_PAT = re.compile(r"#(?P<end>end)?if (//)?P_GEN_\d+_CROSS_EVOS")


def enabled() -> bool:
    """
    Check if the user has explicitly enabled this opt-in helper.
    """
    with open("./include/config/pokemon.h", "r") as cfg_pokemon_fp:
        cfg_pokemon = cfg_pokemon_fp.read()
        cfg_defined = CONFIG_ENABLED_PAT.search(cfg_pokemon)
        return cfg_defined is not None and cfg_defined.group("cfg_val") in ("TRUE", "1")

def is_valid_preprocessor(line: str) -> (bool, bool):
    match = re.match(FAMILY_PAT, line)
    if match:
        return (True, match.group("end"))
    match = re.match(CROSSGEN_EVOS_PAT, line)
    if match:
        return (True, match.group("end"))
    match = re.match(FORMS_PAT, line)
    if match:
        if match.group("forms") in ["GIGANTAMAX", "TERA", "ULTRA_BURST", "COSPLAY_PIKACHU", "CAP_PIKACHU"]:
            return (False, False)
        return (True, match.group("end"))
    return (False, False)

def extract_repo_species_data() -> list:
    species_data = []
    pokemon_list = []
    teaching_type = "DEFAULT_LEARNING"
    for families_fname in sorted(glob.glob("src/data/pokemon/species_info/*_families.h")):
        with open(families_fname, "r") as family_fp:
            species_lines = family_fp.readlines()
        is_endif_last = False
        is_last_line_preprocessor = False
        for line in species_lines:
            (valid, is_endif) = is_valid_preprocessor(line)
            if valid:
                if is_endif:
                    is_endif_last = True
                else:
                    if is_endif_last or not is_last_line_preprocessor:
                        species_data.append("\n")
                    is_endif_last = False
                is_last_line_preprocessor = True
                species_data.append(line)
                continue

            match = re.match(LEARNSET_PAT, line)
            if match:
                if match.group("name") not in pokemon_list:
                    if not is_last_line_preprocessor or is_endif_last:
                        species_data.append("\n")
                    is_last_line_preprocessor = False
                    is_endif_last = False
                    species_data.append({"name": match.group("name"), "teaching_type": teaching_type})
                    pokemon_list.append(match.group("name"))
                teaching_type = "DEFAULT_LEARNING"
                continue
            match = re.match(TEACHING_TYPE_PAT, line)
            if match:
                teaching_type = match.group("teaching_type")
    return species_data


def dump_output(file, data):
    with open(file, "w") as fp:
        fp.write(data)

def main():
    if not enabled():
        quit()

    if len(sys.argv) < 2:
        print("Missing required arguments", file=sys.stderr)
        print(__doc__, file=sys.stderr)
        quit(1)

    OUTPUT_FILE = pathlib.Path(sys.argv[1])

    assert OUTPUT_FILE.parent.exists(), f"parent of {OUTPUT_FILE=} does not exist"

    new_tutors = json.dumps(extract_repo_species_data(), indent=2)
    if OUTPUT_FILE.exists() and OUTPUT_FILE.is_file():
        with open(OUTPUT_FILE, "r") as fp:
            old_tutors = fp.read()
    else:
        dump_output(OUTPUT_FILE, new_tutors)
        return

    if new_tutors != old_tutors:
         dump_output(OUTPUT_FILE, new_tutors)


if __name__ == "__main__":
    main()