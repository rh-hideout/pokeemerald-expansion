import json
import pathlib
import re
import sys

CONFIG_ENABLED_PAT = re.compile(r"#define P_LEARNSET_HELPER_TEACHABLE\s+(?P<cfg_val>[^ ]*)")
LEARNSET_PAT = re.compile(r"s(?P<name>\w+?)TeachableLearnset")
SNAKIFY_PAT = re.compile(r"(?!^)([A-Z]+)")

def enabled() -> bool:
    """
    Check if the user has explicitly enabled this opt-in helper.
    """
    with open("./include/config/pokemon.h", "r") as cfg_pokemon_fp:
        cfg_pokemon = cfg_pokemon_fp.read()
        cfg_defined = CONFIG_ENABLED_PAT.search(cfg_pokemon)
        return cfg_defined is not None and cfg_defined.group("cfg_val") in ("TRUE", "1")

def extract_repo_species_data() -> list:
    teaching_types = {}

    with open("build/emerald/species.json", "r") as f:
        species_data = json.load(f)

    for name, species in species_data.items():
        learnset_name = species["teachableLearnset"]
        species_name = re.sub(LEARNSET_PAT, r"\1", learnset_name)
        species_name = SNAKIFY_PAT.sub(r"_\1", species_name).upper()
        learnset = {"species_name": species_name}
        if species["teachableLearnset"] in teaching_types:
            continue
        if "teachingType" in species:
            learnset["teachingType"] = species["teachingType"]
        else:
            learnset["teachingType"] = "DEFAULT_LEARNING"
        teaching_types[learnset_name] = learnset

    return teaching_types

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

    teaching_types_list = extract_repo_species_data()
    new_teaching_types = json.dumps(teaching_types_list, indent=2)
    old_teaching_types = ""
    if OUTPUT_FILE.exists() and OUTPUT_FILE.is_file():
        with open(OUTPUT_FILE, "r") as fp:
            old_teaching_types = fp.read()

    dump_output(OUTPUT_FILE, new_teaching_types)

    if new_teaching_types != old_teaching_types:
        pathlib.Path("./tools/learnset_helpers/make_teachables.py").touch()


if __name__ == "__main__":
    main()
