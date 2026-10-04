#!/usr/bin/env python3

"""Read active level-up arrays and species mappings through the build preprocessor.

Usage: make_level_up_tms.py CPP [CPP_ARG ...] -- OUTPUT_FILE
"""

import json
import re
import sys
from pathlib import Path

from make_level_up_learnsets import run_cpp


def initializer(source: str, symbol: str) -> str:
    match = re.search(rf"\b{re.escape(symbol)}\s*\[[^]]*\]\s*=\s*\{{", source)
    if match is None:
        raise ValueError(f"Missing initializer for {symbol}")
    start = match.end()
    depth = 1
    for index in range(start, len(source)):
        if source[index] == "{":
            depth += 1
        elif source[index] == "}":
            depth -= 1
            if depth == 0:
                return source[start:index]
    raise ValueError(f"Unclosed initializer for {symbol}")


def species_entries(body: str):
    depth = 0
    start = 0
    for index, character in enumerate(body):
        if character == "{":
            if depth == 0:
                start = index + 1
            depth += 1
        elif character == "}":
            depth -= 1
            if depth == 0:
                yield body[start:index]


def collect_compatibility(source: str) -> dict[str, list[str]]:
    # Strings may contain braces; they carry no learnset information.
    source = re.sub(r'"(?:\\.|[^"\\])*"', '""', source)
    tms = set(re.findall(r"\bMOVE_[A-Z0-9_]+\b", initializer(source, "levelUpPolicyTms")))
    result = {}
    arrays = {}
    for entry in species_entries(initializer(source, "gSpeciesInfo")):
        level_up = re.search(r"\.levelUpLearnset\s*=\s*(\w+)", entry)
        teachable = re.search(r"\.teachableLearnset\s*=\s*s(\w+)TeachableLearnset", entry)
        if level_up is None or teachable is None or teachable[1] == "None":
            continue
        symbol = level_up[1]
        if symbol not in arrays:
            moves = re.findall(r"\.move\s*=\s*(MOVE_[A-Z0-9_]+)\b", initializer(source, symbol))
            arrays[symbol] = set(moves) & tms
        result.setdefault(teachable[1], set()).update(arrays[symbol])
    return {name: sorted(moves) for name, moves in sorted(result.items())}


def main() -> None:
    separator = sys.argv.index("--")
    cpp, *cpp_args = sys.argv[1:separator]
    output_path = Path(sys.argv[separator + 1])
    # Boolean definitions must precede the -imacros config headers.
    cpp_args = ["-DTRUE=1", "-DFALSE=0", *cpp_args]
    enabled = run_cpp(cpp, cpp_args, "\n".join((
        "#if P_LEVEL_UP_TM_COMPATIBILITY && P_LEARNSET_HELPER_TEACHABLE",
        "enabled",
        "#else",
        "disabled",
        "#endif",
    ))).strip()
    compatibility = {}
    if enabled == "enabled":
        source = run_cpp(cpp, cpp_args, "\n".join((
            '#include "constants/pokemon.h"',
            '#include "constants/species.h"',
            '#include "constants/tms_hms.h"',
            '#include "src/data/pokemon/level_up_learnsets.h"',
            '#include "src/data/pokemon/species_info.h"',
            "#define POLICY_TM(move) MOVE_ ## move,",
            "const int levelUpPolicyTms[] = { FOREACH_TMHM(POLICY_TM) };",
        )))
        compatibility = collect_compatibility(source)
    elif enabled != "disabled":
        raise ValueError("Unable to resolve P_LEVEL_UP_TM_COMPATIBILITY")
    output_path.write_text(json.dumps(compatibility, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
