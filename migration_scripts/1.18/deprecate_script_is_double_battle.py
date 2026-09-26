from itertools import chain

import glob
import os
import re

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

trainers = set()
for inc_fname in chain(glob.glob("./data/scripts/*.inc"), glob.glob("./data/maps/*/scripts.inc")):
    new_lines = []
    with open(inc_fname, "r") as inc_fp:
        lines = inc_fp.readlines()
        for line in lines:
            match = re.search(r'trainerbattle_double\s+(\w+)\s*,', line)
            if match:
                trainers.add(match.group(1))

isDouble = False;
with open("src/data/trainers.party", "r") as party_file:
    lines = party_file.readlines()
    for line in lines:
        match = re.search(r'===\s+(\w+)\s+===', line)
        if match:
            current_trainer = match.group(1)
            if current_trainer in trainers:
                isDouble = True;
            else:
                isDouble = False;
        if isDouble:
            match = re.search(r'Double Battle:\s+No', line)
            if match:
                print(f"Update {current_trainer} to double battle")
                line = "Double Battle: Yes\n"
        new_lines.append(line)

with open("src/data/trainers.party", 'w+') as file:
    for line in new_lines:
        file.write(line)
