import os
import re

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit(1)

new_lines = []
with open("include/constants/trainers.h", "r") as inc_fp:
    lines = inc_fp.readlines()
    for line in lines:
        match = re.search(r'(UNUSED_FACILITY_CLASS_\w+)', line)
        if match:
            continue
        new_lines.append(line)

with open("include/constants/trainers.h", "w+") as file:
    for line in new_lines:
        file.write(line)


new_lines = []
with open("src/data/battle_frontier/facility_class.h", "r") as inc_fp:
    lines = inc_fp.readlines()
    for line in lines:
        match = re.search(r'\[(UNUSED_FACILITY_CLASS_\w+)\]', line)
        if match:
            continue
        new_lines.append(line)

with open("src/data//battle_frontier/facility_class.h", "w+") as file:
    for line in new_lines:
        file.write(line)