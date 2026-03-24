from itertools import chain

import glob
import os

replacements = [
    ["special BattleSetup_StartLatiBattle", "startlegendarybattle"],
    ["special StartRegiBattle", "startlegendarybattle"],
    ["special BattleSetup_StartLegendaryBattle", "startlegendarybattle"],
]

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

for inc_fname in chain(glob.glob("./data/scripts/*.inc"), glob.glob("./data/maps/*/scripts.inc")):
    new_lines = []
    with open(inc_fname, "r") as inc_fp:
        lines = inc_fp.readlines()
        for line in lines:
            for replacement in replacements:
                line = line.replace(replacement[0], replacement[1])
            new_lines.append(line)
    with open(inc_fname, 'w+') as file:
        for line in new_lines:
            file.write(line)