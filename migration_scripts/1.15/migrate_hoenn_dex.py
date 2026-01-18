import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

#include/constants/pokedex.h
newMacro = """

#if P_NEW_EVOS_IN_REGIONAL_DEX
#define HOENN_DEX_IF(config, ...) CAT(HOENN_DEX_IF_, config)(__VA_ARGS__)
#define HOENN_DEX_IF_0(...)
#define HOENN_DEX_IF_1(...) __VA_ARGS__
#else
#define HOENN_DEX_IF(config, ...)
#endif

#define FOREACH_SPECIES_IN_HOENN_DEX_ORDER(F) \\
"""

output = ""
crossEvo = False
lastSpecies = ""

with open("include/constants/pokedex.h", "r") as file:
    lines = file.readlines()
    for line in lines:
        if "HOENN_DEX_NONE" in line:
            output += line + """    #define HOENN_DEX_ENUM(name) HOENN_DEX_ ##name,
    FOREACH_SPECIES_IN_HOENN_DEX_ORDER(HOENN_DEX_ENUM)
    #undef HOENN_DEX_ENUM
"""
        elif "    HOENN_DEX_" in line:
            macroedSpecies = line.replace("HOENN_DEX_", "F(")
            lastSpecies = macroedSpecies.strip().replace(",", "")
            if crossEvo:
                newMacro += macroedSpecies.strip().replace(",", ")) \\")
            else:
                newMacro += macroedSpecies.replace(",", ") \\")
        elif "P_NEW_EVOS_IN_REGIONAL_DEX" in line:
            crossEvo = True
            config = line.replace("#if P_NEW_EVOS_IN_REGIONAL_DEX && ", "").replace("\n", "")
            newMacro += f"    HOENN_DEX_IF({config}, "
        elif "#else" in line and crossEvo:
            continue
        elif "#endif" in line:
            if crossEvo:
                newMacro += "\n"
                crossEvo = False
            else:
                output += line
        else:
            output += line

lineBeforeMacro = "#define POKEMON_SLOTS_NUMBER (NATIONAL_DEX_COUNT + 1)"
newMacro = newMacro.replace(lastSpecies + ") \\", lastSpecies + ")")
output = output.replace(lineBeforeMacro, lineBeforeMacro + newMacro)

with open("include/constants/pokedex.h", "w") as f:
    f.write(output)
    print("include/constants/pokedex.h has been updated")

#src/pokemon.c
output = ""
ifStatement = False
hoennToNational = False

with open("src/pokemon.c", "r") as file:
    lines = file.readlines()
    for line in lines:
        if "HOENN_TO_NATIONAL" in line and "#define" not in line:
            hoennToNational = True
        elif "#if P_NEW_EVOS_IN_REGIONAL_DEX" in line:
            ifStatement = True
        elif "#else" in line and ifStatement:
            continue
        elif "#endif" in line and ifStatement:
            ifStatement = False
        elif hoennToNational:
            output += "    FOREACH_SPECIES_IN_HOENN_DEX_ORDER(HOENN_TO_NATIONAL)\n" + line
            hoennToNational = False
        else:
            output += line

hoennToNationalDefine = "#define HOENN_TO_NATIONAL(name)     [HOENN_DEX_##name - 1] = NATIONAL_DEX_##name"
output = output.replace(hoennToNationalDefine, hoennToNationalDefine + ",")

with open("src/pokemon.c", "w") as f:
    f.write(output)
    print("src/pokemon.c has been updated")
