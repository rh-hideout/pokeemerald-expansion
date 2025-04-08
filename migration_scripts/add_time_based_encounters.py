import json
import sys
import os

"""
- you can change/add to these if you're adding seasons/days of the week, etc
- if you're just adding times of the day, make sure they are in the same order
as the `TimeOfDay` enum in include/rtc.h.
- you don't need to add an entry for `TIMES_OF_DAY_COUNT`
"""
ENCOUNTER_GROUP_SUFFIX = [
    "Morning",
    "Day",
    "Evening",
    "Night"
]

ARGS = [
    "--copy",
]

"""
- make sure this number is the same as `OW_TIME_OF_DAY_DEFAULT` in config/overworld.h.
- by default in config/overworld.h it is set to `TIME_MORNING`, which is 0 in the
`TimeOfDay` enum in include/rtc.h
"""
OW_TIME_OF_DAY_DEFAULT = 0


def GetWildEncounterFile():
    if not os.path.exists("Makefile"):
        print("Please run this script from the project's root folder.")
        quit()

    wFile = open("src/data/wild_encounters.json")
    wData = json.load(wFile)

    wBackupData = json.dumps(wData, indent=2)
    wBackupFile = open("src/data/wild_encounters.json.bak", mode="w", encoding="utf-8")
    wBackupFile.write(wBackupData)

    global COPY_FULL_ENCOUNTER
    COPY_FULL_ENCOUNTER = False

    for arg in ARGS:
        if len(sys.argv) > 1:
            if arg in sys.argv[1:3]:
                if arg == ARGS[0]:
                    COPY_FULL_ENCOUNTER = True

    j = 0
    for group in wData["wild_encounter_groups"]:
        wEncounters = wData["wild_encounter_groups"][j]["encounters"]
        editMap = True

        wEncounters_New = list()
        for map in wEncounters:
            for suffix in ENCOUNTER_GROUP_SUFFIX:
                tempSuffix = "_" + suffix
                if tempSuffix in map["base_label"]:
                    editMap = False
                    break
                else: 
                    editMap = True

            if editMap:
                k = 0
                for suffix in ENCOUNTER_GROUP_SUFFIX:
                    tempDict = dict()
                    if k == OW_TIME_OF_DAY_DEFAULT or COPY_FULL_ENCOUNTER:
                        tempDict = map.copy()

                    tempMapLabel = ""
                    if "map" in map:
                        tempMapLabel = map["map"]
                        tempDict["map"] = tempMapLabel

                    tempLabel = map["base_label"] + "_" + suffix
                    tempDict["base_label"] = tempLabel
                    wEncounters_New.append(tempDict)
                    if map["base_label"] in wEncounters_New:
                        wEncounters_New[map["base_label"]].pop()

                    print(tempLabel + " added")
                    k += 1
            else:
                wEncounters_New.append(map.copy())

        wData["wild_encounter_groups"][j]["encounters"] = wEncounters_New
        j += 1

    wNewData = json.dumps(wData, indent=2)
    wNewFile = open("src/data/wild_encounters.json", mode="w", encoding="utf-8")
    wNewFile.write(wNewData)


GetWildEncounterFile()
