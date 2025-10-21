#!/usr/bin/env python3

"""
Usage: python3 make_teachable.py SOURCE_LEARNSETS_JSON

Build a C-header defining the set of teachable moves for each configured-on
species-family based on the learnable moves defined in SOURCE_LEARNSETS_JSON.

A move is "teachable" if it is:
    1. Can be taught by some Move Tutor in the overworld, which is identified by
       using the ChooseMonForMoveTutor special in a script and setting VAR_0x8005
       to the offered MOVE constant. (e.g., MOVE_SWAGGER)
    2. Assigned to some TM or HM in include/constants/tms_hms.h using the
       FOREACH_TM macro.
    3. Not a universal move, as defined by sUniversalMoves in src/pokemon.c.

For a given species, a move is considered teachable to that species if:
    1. The species is not NONE -- which learns nothing -- nor MEW -- which
       learns everything.
    2. The species can learn the move via *any* method within any Expansion-
       supported game.
"""

from itertools import chain
from textwrap import dedent

import glob
import json
import pathlib
import re
import sys
import typing


CONFIG_ENABLED_PAT = re.compile(r"#define P_LEARNSET_HELPER_TEACHABLE\s+(?P<cfg_val>[^ ]*)")
ALPHABETICAL_ORDER_ENABLED_PAT = re.compile(r"#define HGSS_SORT_TMS_BY_NUM\s+(?P<cfg_val>[^ ]*)")
TM_LITTERACY_PAT = re.compile(r"#define P_TM_LITERACY\s+GEN_(?P<cfg_val>[^ ]*)")
TMHM_MACRO_PAT = re.compile(r"F\((\w+)\)")
SNAKIFY_PAT = re.compile(r"(?!^)([A-Z]+)")
TUTOR_ARRAY_ENABLED_PAT = re.compile(r"#define\s+POKEDEX_PLUS_HGSS\s+(?P<cfg_val>[^ ]*)")
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

def extract_repo_tms() -> typing.Generator[str, None, None]:
    """
    Yield MOVE constants assigned to a TM or HM in the user's repo.
    """
    with open("./include/constants/tms_hms.h", "r") as tmshms_fp:
        tmshms = tmshms_fp.read()
        match_it = TMHM_MACRO_PAT.finditer(tmshms)
        if not match_it:
            return

        for match in match_it:
            yield f"MOVE_{match.group(1)}"

def extract_repo_species_data() -> dict[str, str]:
    species_teaching_types = {}
    for families_fname in sorted(glob.glob("src/data/pokemon/species_info/gen_*_families.h")):
        with open(families_fname, "r") as family_fp:
            family_file = family_fp.read()
            for family_match in SPECIES_FAMILY_PAT.finditer(family_file):
                family = {}
                for pokemon in POKEMON_TEACHING_TYPE_PAT.finditer(family_match.group("content")):
                    if pokemon.group("teaching_type"):
                        family[pokemon.group("name")] = pokemon.group("teaching_type")
                    else:
                        family[pokemon.group("name")] = "DEFAULT_LEARNING"
                species_teaching_types[family_match.group("family")] = family;
    return species_teaching_types

def extract_tm_litteracy_config() -> bool:
    config = False
    with open("./include/config/pokemon.h", "r") as cfg_pokemon_fp:
        cfg_pokemon = cfg_pokemon_fp.read()
        cfg_defined = TM_LITTERACY_PAT.search(cfg_pokemon)
        if cfg_defined:
            cfg_val = cfg_defined.group("cfg_val")
            if ((cfg_val == "LATEST") or (int(cfg_val) > 6)):
                config = True
    return config

def prepare_output(all_learnables: dict[str, set[str]], tms: list[str], tutors: list[str], special_movesets, header: str) -> str:
    """
    Build the file content for teachable_learnsets.h.
    """

    repo_teaching_types = extract_repo_species_data()
    tm_litteracy_config = extract_tm_litteracy_config()

    cursor = 0
    new = header + dedent("""
    static const u16 sNoneTeachableLearnset[] = {
        MOVE_UNAVAILABLE,
    };
    """)

    joinpat = ",\n    "
    for family, members in repo_teaching_types.items():
        new += (f"\n#if P_FAMILY_{family}\n")
        i = 0
        for species, teaching_type in members.items():
            if i > 0:
                 new += "\n"
            new += f"static const u16 s{species}TeachableLearnset[] = "
            new += "{\n"
            species_upper =  SNAKIFY_PAT.sub(r"_\1", species).upper()
            if teaching_type == "ALL_TEACHABLES":
                learnables = filter(lambda m: m not in special_movesets["signatureTeachables"], tms + tutors)
            elif teaching_type == "TM_ILLITERATE":
                learnables = all_learnables[species_upper]
                if not tm_litteracy_config:
                    learnables = filter(lambda m: m not in special_movesets["universalMoves"], learnables)
            else:
                learnables = all_learnables[species_upper] + special_movesets["universalMoves"]

            part1 = list(filter(lambda m: m in learnables, tms))
            part2 = list(filter(lambda m: m in learnables, tutors))
            repo_species_teachables = part1 + part2
            if species_upper == "TERAPAGOS":
                 repo_species_teachables = filter(lambda m: m != "MOVE_TERA_BLAST", repo_species_teachables)

            repo_species_teachables = list(dict.fromkeys(repo_species_teachables))
            new += "\n".join([
                f"    {joinpat.join(chain(repo_species_teachables, ('MOVE_UNAVAILABLE',)))},",
                "};\n",
            ])
            i += 1
        new += (f"#endif //P_FAMILY_{family}\n")

    return new


def prepare_header(h_align: int, tmshms: list[str], tutors: list[str], universals: list[str]) -> str:
    universals_title = "Near-universal moves found in data/special_movesets.json:"
    tmhm_title = "TM/HM moves found in \"include/constants/tms_hms.h\":"
    tutor_title = "Tutor moves found from map scripts:"
    h_align = max(h_align, len(universals_title), len(tmhm_title), len(tutor_title))

    lines = [
         "//",
         "// DO NOT MODIFY THIS FILE! It is auto-generated by tools/learnset_helpers/make_teachables.py",
         "//",
         "",
        f"// {'*' * h_align} //",
        f"// {tmhm_title: >{h_align}} //",
    ]
    lines.extend([f"// - {move: <{h_align - 2}} //" for move in tmshms])
    lines.extend([
        f"// {'*' * h_align} //",
        f"// {tutor_title: <{h_align}} //",
    ])
    lines.extend([f"// - {move: <{h_align - 2}} //" for move in sorted(tutors)])
    lines.extend([
        f"// {'*' * h_align} //",
        f"// {universals_title: <{h_align}} //",
    ])
    lines.extend([f"// - {move: <{h_align - 2}} //" for move in universals])
    lines.extend([
        f"// {'*' * h_align} //",
         "",
    ])

    return "\n".join(lines)


def main():
    if not enabled():
        quit()

    if len(sys.argv) < 2:
        print("Missing required arguments", file=sys.stderr)
        print(__doc__, file=sys.stderr)
        quit(1)

    SOURCE_LEARNSETS_JSON = pathlib.Path(sys.argv[1])
    SOURCE_TUTORS_JSON = pathlib.Path(sys.argv[2])

    assert SOURCE_LEARNSETS_JSON.exists(), f"{SOURCE_LEARNSETS_JSON=} does not exist"
    assert SOURCE_LEARNSETS_JSON.is_file(), f"{SOURCE_LEARNSETS_JSON=} is not a file"

    assert SOURCE_TUTORS_JSON.exists(), f"{SOURCE_TUTORS_JSON=} does not exist"
    assert SOURCE_TUTORS_JSON.is_file(), f"{SOURCE_TUTORS_JSON=} is not a file"

    repo_tms = list(extract_repo_tms())
    order_alphabetically = False

    with open("./include/config/pokedex_plus_hgss.h", "r") as cfg_pokemon_fp:
        cfg_pokemon = cfg_pokemon_fp.read()
        cfg_defined = ALPHABETICAL_ORDER_ENABLED_PAT.search(cfg_pokemon)
        if cfg_defined is None or cfg_defined.group("cfg_val") in ("FALSE", "0"):
            repo_tms = sorted(repo_tms)

    with open(SOURCE_TUTORS_JSON, "r") as fp:
        repo_tutors = json.load(fp)

    with open("src/data/pokemon/special_movesets.json", "r") as file:
        special_movesets = json.load(file)

    h_align = max(map(lambda move: len(move), chain(special_movesets["universalMoves"], repo_tms, repo_tutors))) + 2
    header = prepare_header(h_align, repo_tms, repo_tutors, special_movesets["universalMoves"])

    with open(SOURCE_LEARNSETS_JSON, "r") as source_fp:
        all_learnables = json.load(source_fp)

    content = prepare_output(all_learnables, repo_tms, repo_tutors, special_movesets, header)
    with open("./src/data/pokemon/teachable_learnsets.h", "w") as teachables_fp:
        teachables_fp.write(content)

if __name__ == "__main__":
    main()
