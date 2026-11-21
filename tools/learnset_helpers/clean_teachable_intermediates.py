import re
import subprocess

CONFIG_ENABLED_PAT = re.compile(r"^#define P_LEARNSET_HELPER_TEACHABLE\s+(?P<cfg_val>[^ ]*)", flags=re.MULTILINE)

with open("./include/config/pokemon.h", "r") as cfg_pokemon_fp:
    cfg_pokemon = cfg_pokemon_fp.read()
    cfg_defined = CONFIG_ENABLED_PAT.search(cfg_pokemon)
    enabled = cfg_defined is not None and cfg_defined.group("cfg_val") in ("TRUE", "1")

if enabled:
    result = subprocess.run(["rm", "-f", "src/data/tutor_moves.h"]);
    print("rm -f src/data/tutor_moves.h")
    result = subprocess.run(["rm", "-f", "src/data/pokemon/teachable_learnsets.h"]);
    print("rm -f src/data/pokemon/teachable_learnsets.h")
    result = subprocess.run(["rm", "-Rf", "tools/learnset_helpers/build"]);
    print("rm -Rf tools/learnset_helpers/build")
