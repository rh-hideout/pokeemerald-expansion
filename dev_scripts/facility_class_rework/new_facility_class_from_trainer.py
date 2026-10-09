from itertools import chain

import json
import glob
import os
import re
import sys

def find_obj_event_gfx(filename, script):
    with open(filename, 'r') as f:
        tmp = json.load(f)
    for obj in tmp["object_events"]:
        if obj["script"] == script:
            return obj["graphics_id"]
    return ""

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit(1)

if len(sys.argv) < 2:
    quit(1)


trainer_constant = sys.argv[1]

facility_class = {}
active = False
with open("src/data/trainers.h", "r") as inc_fp:
    lines = inc_fp.readlines()
    for line in lines:
        regex = r"\[" + re.escape(trainer_constant) + r"\]"
        match = re.search(regex, line)
        if match:
            active = True
            continue
        if not active:
            continue
        match = re.search(r'\[DIFFICULTY_NORMAL\]', line)
        if match:
            active = False
            continue
        match = re.search(r'.(\w+)\s*=\s*(TRAINER_\w+)', line)
        if match:
            key = match.group(1)
            if key in facility_class:
                continue
            facility_class[key] = match.group(2)

if not facility_class:
    with open("src/data/trainers_frlg.h", "r") as inc_fp:
        lines = inc_fp.readlines()
        for line in lines:
            regex = r"\[" + re.escape(trainer_constant) + r"\]"
            match = re.search(regex, line)
            if match:
                active = True
                continue
            if not active:
                continue
            match = re.search(r'\[DIFFICULTY_NORMAL\]', line)
            if match:
                active = False
                continue
            match = re.search(r'.(\w+)\s*=\s*(TRAINER_\w+)', line)
            if match:
                key = match.group(1)
                if key in facility_class:
                    continue
                facility_class[key] = match.group(2)

if not facility_class:
    print("Could not find trainer amongs party files")
    quit(1)

facility_class["gfxId"] = ""

script_function = ""
for inc_fname in chain(glob.glob("./data/maps/*/scripts.inc")):
    with open(inc_fname, "r") as inc_fp:
        lines = inc_fp.readlines()
        for line in lines:
            match = re.match(r'(\w+)::', line)
            if match:
                script_function = match.group(1)
            match = re.search(re.escape(trainer_constant), line)
            if match:
                facility_class["gfxId"] =find_obj_event_gfx(inc_fname.replace("scripts.inc", "map.json"), script_function)

facility_constant = facility_class["trainerClass"].replace("TRAINER_", "FACILITY_")
print(f"    [{facility_constant}] = " + "{")
print(f"        .trainerClass = " + facility_class["trainerClass"] + ",")
print(f"        .trainerPic = "   + facility_class["trainerPic"] + ",")
print(f"        .approachMusic = " + facility_class["encounterMusic"] + ",")
print(f"        .gfxId = " + facility_class["gfxId"] + ",")
print(f"        .gender = " + facility_class["gender"] + ",")
print("    },")


