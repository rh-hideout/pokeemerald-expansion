import json
import sys
import os

try:
    if not os.path.exists("./tools/wild_encounters/"):
        print("Please run this script from the project's root folder.")
        quit()
    sys.path.append("./tools/wild_encounters/")
    from wild_encounters_to_header import Config
except ImportError:
    print("Could not import the file tools/wild_encounters/wild_encounters_to_header.py")
    quit()

ARGS = [
    "--copy",
]


def get_wild_encounter_file():
    if not os.path.exists("Makefile"):
        print("Please run this script from the project's root folder.")
        quit()

    file = open("src/data/wild_encounters.json")
    data = json.load(file)
    config = Config('include/config/overworld.h', 'include/constants/rtc.h', data)

    data_backup = json.dumps(data, indent=2)
    file_backup = open("src/data/wild_encounters.json.bak", mode="w", encoding="utf-8")
    file_backup.write(data_backup)

    copy_full_encounter = False
    time_of_day_default = 0

    for arg in ARGS:
        if len(sys.argv) > 1:
            if arg in sys.argv[1:3]:
                if arg == ARGS[0]:
                    copy_full_encounter = True

    encounter_count = 0
    for group in data["wild_encounter_groups"]:
        encounters = data["wild_encounter_groups"][encounter_count]["encounters"]
        edit_map = True

        encounters_new = list()
        for encounter_map in encounters:
            for suffix in config.times_of_day.values():
                temp_suffix = "_" + suffix
                if temp_suffix in encounter_map["base_label"]:
                    edit_map = False
                    break
                else:
                    edit_map = True

            if edit_map:
                k = 0
                for suffix in config.times_of_day.values():
                    temp_dict = dict()
                    if k == time_of_day_default or copy_full_encounter:
                        temp_dict = encounter_map.copy()

                    temp_map_label = ""
                    if "map" in encounter_map:
                        temp_map_label = encounter_map["map"]
                        temp_dict["map"] = temp_map_label

                    temp_label = encounter_map["base_label"] + "_" + suffix
                    temp_dict["base_label"] = temp_label

                    if "encounter_sets" not in temp_dict:
                        temp_dict["encounter_sets"] = dict()

                    encounters_new.append(temp_dict)

                    if encounter_map["base_label"] in encounters_new:
                        encounters_new[encounter_map["base_label"]].pop()

                    k += 1
            else:
                encounters_new.append(encounter_map.copy())

        data["wild_encounter_groups"][encounter_count]["encounters"] = encounters_new
        encounter_count += 1

    data_new = json.dumps(data, indent=2)
    file_new = open("src/data/wild_encounters.json", mode="w", encoding="utf-8")
    file_new.write(data_new)


get_wild_encounter_file()
