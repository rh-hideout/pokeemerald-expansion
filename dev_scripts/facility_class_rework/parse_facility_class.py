#this is a one time helper script of dubious quality

import json
import os
import re
import subprocess

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit(1)

facility_class_list = {}

with open("include/constants/trainers.h", "r") as inc_fp:
    lines = inc_fp.readlines()
    for line in lines:
        match = re.search(r'(FACILITY_CLASS_\w+)', line)
        if match:
            facility_class = match.group(1)
            facility_class_list[facility_class] = {"facility_class": facility_class, "doubles": False, "obj_gfx": "", "approach_music": ""}

with open("src/data/pokemon/trainer_class_lookups.h", "r") as inc_fp:
    lines = inc_fp.readlines()

    for line in lines:
        match = re.search(r'\[(FACILITY_CLASS_\w+)\]\s*=\s*(TRAINER_PIC_\w+)', line)
        if match:
            facility_class = match.group(1)
            trainer_pic = match.group(2)
            if facility_class in facility_class_list:
            	facility_class_list[facility_class]["trainer_pic"] = trainer_pic
            else:
            	facility_class_list[facility_class] = {"trainer_pic": trainer_pic, "facility_class": facility_class, "doubles": False, "obj_gfx": "", "approach_music": ""}
        match = re.search(r'\[(FACILITY_CLASS_\w+)\]\s*=\s*(TRAINER_CLASS_\w+)', line)
        if match:
            facility_class = match.group(1)
            trainer_class = match.group(2)
            if facility_class in facility_class_list:
            	facility_class_list[facility_class]["trainer_class"] = trainer_class
            else:
            	facility_class_list[facility_class] = {"trainer_class": trainer_class, "facility_class": facility_class, "doubles": False, "obj_gfx": "", "approach_music": ""}


with open("src/battle_tower.c", "r") as inc_fp:
    lines = inc_fp.readlines()

    gender = "MALE"
    for line in lines:
        match = re.search(r'const struct FacilityClass gTowerFemaleFacilityClasses', line)
        if match:
            gender = "FEMALE"
        match = re.search(r'\{(FACILITY_CLASS_\w+)\s*,\s*(OBJ_EVENT_GFX_\w+)\}', line)
        if match:
            facility_class = match.group(1)
            obj_gfx = match.group(2)
            if facility_class in facility_class_list:
            	facility_class_list[facility_class]["obj_gfx"] = obj_gfx
            else:
            	facility_class_list[facility_class] = {"obj_gfx": obj_gfx, "facility_class": facility_class, "doubles": False, "approach_music": ""}
            facility_class_list[facility_class]["gender"] = gender

approach_music_list = {}
with open("src/trainer_tower.c", "r") as inc_fp:
    lines = inc_fp.readlines()

    for line in lines:
        match = re.search(r'\{(OBJ_EVENT_GFX_\w+)\s*,\s*(FACILITY_CLASS_\w+)\s*,\s*(F?E?MALE)\}', line)
        if match:
            facility_class = match.group(2)
            obj_gfx = match.group(1)
            gender = match.group(3)
            if facility_class in facility_class_list:
                facility_class_list[facility_class]["obj_gfx"] = obj_gfx
            else:
                facility_class_list[facility_class] = {"obj_gfx": obj_gfx, "facility_class": facility_class, "doubles": False, "approach_music": ""}
            facility_class_list[facility_class]["gender"] = gender
        match = re.search(r'\{(OBJ_EVENT_GFX_\w+)\s*,\s*(OBJ_EVENT_GFX_\w+)\s*,\s*(FACILITY_CLASS_\w+)\s*,\s*(F?E?MALE)\s*,\s*(F?E?MALE)\}', line)
        if match:
            facility_class = match.group(3)
            obj_gfx = match.group(1)
            obj_gfx2 = match.group(2)
            gender = match.group(4)
            gender2 = match.group(5)
            if facility_class in facility_class_list:
                facility_class_list[facility_class]["obj_gfx"] = obj_gfx
            else:
                facility_class_list[facility_class] = {"obj_gfx": obj_gfx, "facility_class": facility_class, "approach_music": ""}
            facility_class_list[facility_class]["gender"] = gender
            facility_class_list[facility_class]["gender2"] = gender2
            facility_class_list[facility_class]["obj_gfx2"] = obj_gfx2
            facility_class_list[facility_class]["doubles"] = True


with open("src/battle_pyramid.c", "r") as inc_fp:
    lines = inc_fp.readlines()
    for line in lines:
        match = re.search(r'\{(TRAINER_CLASS_\w+)\s*,\s*(TRAINER_ENCOUNTER_MUSIC_\w+)\}', line)
        if match:
            trainer_class = match.group(1)
            approach_music = match.group(2)
            for facility_class in facility_class_list:
                if facility_class_list[facility_class]["trainer_class"] == trainer_class:
                    facility_class_list[facility_class]["approach_music"] = approach_music

with open("tmp.json", 'w+') as file:
    data = {"data": list(facility_class_list.values())}
    file.write(json.dumps(data, indent=4))

subprocess.run(["tools/jsonproc/jsonproc", "tmp.json", "dev_scripts/facility_class_rework/facility_class_constants.json.txt", "tmp_facility_class_list.h"])
subprocess.run(["tools/jsonproc/jsonproc", "tmp.json", "dev_scripts/facility_class_rework/facility_class_data.json.txt", "tmp_facility_class_data.h"])














