import json
import sys
import os

try:
    if not os.path.exists("./tools/wild_encounters/"):
        print("Please run this script from the project's root folder.")
        quit()
    sys.path.append("./tools/wild_encounters/")
    from wild_encounters_to_header import TimeOfDay, SetupUserTimeEnum
except ImportError:
    print("Could not import the file tools/wild_encounters/wild_encounters_to_header.p.")
    quit()

ARGS = [
    "--copy",
]

"""
- make sure this number is the same as `TIME_OF_DAY_DEFAULT` in config/overworld.h.
- by default in config/overworld.h it is set to `TIME_MORNING`, which is 0 in the
`TimeOfDay` enum in include/rtc.h
"""
TIME_OF_DAY_DEFAULT = 0


def GetWildEncounterFile():
    if not os.path.exists("Makefile"):
        print("Please run this script from the project's root folder.")
        quit()

    timeOfDay = SetupUserTimeEnum(TimeOfDay())

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
            for suffix in timeOfDay.fvals:
                tempSuffix = "_" + suffix
                if tempSuffix in map["base_label"]:
                    editMap = False
                    break
                else: 
                    editMap = True

            if editMap:
                k = 0
                for suffix in timeOfDay.fvals:
                    tempDict = dict()
                    if k == TIME_OF_DAY_DEFAULT or COPY_FULL_ENCOUNTER:
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
