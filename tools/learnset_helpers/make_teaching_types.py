import glob
import json
import pathlib
import re
import sys
import typing

CONFIG_ENABLED_PAT = re.compile(r"#define P_LEARNSET_HELPER_TEACHABLE\s+(?P<cfg_val>[^ ]*)")
SPECIES_FAMILY_PAT = re.compile(r"#if P_FAMILY_(?P<family>\w+)(?P<content>[\s\S]*?)#endif //P_FAMILY_\w+")
POKEMON_TEACHING_TYPE_PAT = re.compile(r"\{[\s\S]*?(.teachingType\s*=\s*(?P<teaching_type>[A-Z_]+),[\s\S]*?)?\.teachableLearnset\s*=\s*s(?P<name>\w+?)TeachableLearnset[\s\S]*?\}")

def enabled() -> bool:
    """
    Check if the user has explicitly enabled this opt-in helper.
    """
    with open("./include/config/pokemon.h", "r") as cfg_pokemon_fp:
        cfg_pokemon = cfg_pokemon_fp.read()
        cfg_defined = CONFIG_ENABLED_PAT.search(cfg_pokemon)
        return cfg_defined is not None and cfg_defined.group("cfg_val") in ("TRUE", "1")

def extract_repo_species_data() -> dict[str, str]:
    teaching_types = {}
    for families_fname in sorted(glob.glob("src/data/pokemon/species_info/*_families.h")):
        with open(families_fname, "r") as family_fp:
            family_file = family_fp.read()
            for family_match in SPECIES_FAMILY_PAT.finditer(family_file):
                family = {}
                for pokemon in POKEMON_TEACHING_TYPE_PAT.finditer(family_match.group("content")):
                    if pokemon.group("teaching_type"):
                        family[pokemon.group("name")] = pokemon.group("teaching_type")
                    else:
                        family[pokemon.group("name")] = "DEFAULT_LEARNING"
                teaching_types[family_match.group("family")] = family;
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