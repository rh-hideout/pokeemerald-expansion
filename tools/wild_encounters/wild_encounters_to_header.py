import json
import re
import os


IS_ENABLED            = False

# C string vars
define                = "#define"
ENCOUNTER_CHANCE      = "ENCOUNTER_CHANCE"
SLOT                  = "SLOT"
TOTAL                 = "TOTAL"
NULL                  = "NULL"
UNDEFINED             = "UNDEFINED"
MAP_UNDEFINED         = "MAP_UNDEFINED"

# encounter group header types, filled out programmatically
MON_HEADERS = []

# mon encounter group types
LAND_MONS             = "land_mons"
LAND_MONS_LABEL       = "LandMons"
LAND_MONS_INDEX       = 0
WATER_MONS            = "water_mons"
WATER_MONS_LABEL      = "WaterMons"
WATER_MONS_INDEX      = 1
ROCK_SMASH_MONS       = "rock_smash_mons"
ROCK_SMASH_MONS_LABEL = "RockSmashMons"
ROCK_SMASH_MONS_INDEX = 2
FISHING_MONS          = "fishing_mons"
FISHING_MONS_LABEL    = "FishingMons"
FISHING_MONS_INDEX    = 3
HIDDEN_MONS           = "hidden_mons"
HIDDEN_MONS_LABEL     = "HiddenMons"
HIDDEN_MONS_INDEX     = 4
MONS_INFO_TOTAL       = HIDDEN_MONS_INDEX + 1

# fishing encounter data
GOOD_ROD              = "good_rod"
GOOD_ROD_FIRST_INDEX  = 2
GOOD_ROD_LAST_INDEX   = 4
OLD_ROD               = "old_rod"
OLD_ROD_FIRST_INDEX   = 0
OLD_ROD_LAST_INDEX    = 1
SUPER_ROD             = "super_rod"
SUPER_ROD_FIRST_INDEX = 5
SUPER_ROD_LAST_INDEX  = 9

# time of day encounter data
TIME_DEFAULT       = "OW_TIME_OF_DAY_DEFAULT"
TIME_DEFAULT_LABEL = ""
TIME_DEFAULT_INDEX = 0
TIME_MORNING       = "time_morning"
TIME_MORNING_LABEL = "Morning"
TIME_MORNING_INDEX = 0
TIME_DAY           = "time_day"
TIME_DAY_LABEL     = "Day"
TIME_DAY_INDEX     = 1
TIME_EVENING       = "time_evening"
TIME_EVENING_LABEL = "Evening"
TIME_EVENING_INDEX = 2
TIME_NIGHT         = "time_night"
TIME_NIGHT_LABEL   = "Night"
TIME_NIGHT_INDEX   = 3
TOTAL_TIME_STAGES  = TIME_NIGHT_INDEX + 1

# struct building blocks
baseStruct          = "const struct WildPokemon"
structLabel         = ""
structMonType       = ""
structTime          = ""
structMap           = ""

structInfo          = "Info"
structHeader        = "Header"
structArrayAssign   = "[] ="

baseStructLabel     = ""
baseStructContent   = []
infoStructString    = ""
infoStructRate      = 0
infoStructContent   = []
headerStructLabel   = ""
headerStructContent = {}
headerStructTable   = {}
headerIndex = 0

# map header data variables
hLabel       = ""
hForMaps     = True
headersArray = [headerIndex]

# headersArrayItems
landMonsInfo      = ""
waterMonsInfo     = ""
rockSmashMonsInfo = ""
fishingMonsInfo   = ""

# encounter rate variables
eLandMons      = []
eWaterMons     = []
eRockSmashMons = []
eFishingMons   = []


# debug output control
printEncounterHeaders           = True
printEncounterRateMacros        = True
printEncounterStructsInfoString = True
printEncounterStructs           = True


def ImportWildEncounterFile():
    # make sure we're in the right directory before anything else
    if not os.path.exists("Makefile"):
        print("Please run this script from the project's root folder.")
        quit()

    global MON_HEADERS
    global landMonsInfo
    global waterMonsInfo
    global rockSmashMonsInfo
    global fishingMonsInfo
    global hiddenMonsInfo
    global structLabel
    global structMonType
    global structTime
    global structMap
    global baseStructLabel
    global baseStructContent
    global infoStructString
    global infoStructRate
    global headerStructLabel
    global headerStructContent
    global hLabel
    global headersArray
    global eLandMons
    global eWaterMons
    global eRockSmashMons
    global eFishingMons
    global encounterTotalCount
    global encounterCount
    global headerIndex
    global tabStr
    tabStr = "    "

    global IS_ENABLED
    IS_ENABLED = IsConfigEnabled()

    wFile = open("src/data/wild_encounters.json")
    wData = json.load(wFile)

    encounterTotalCount = []
    encounterCount = []
    groupCount = 0
    while groupCount < len(wData["wild_encounter_groups"]):
        encounterTotalCount.append(0)
        encounterCount.append(0)
        groupCount += 1

    for data in wData["wild_encounter_groups"]:
        wEncounters = wData["wild_encounter_groups"][headerIndex]["encounters"]
        headerSuffix = structHeader + "s"

        if data["label"]:
            hLabel = wData["wild_encounter_groups"][headerIndex]["label"]
            if headerSuffix in hLabel:
                hLabel = hLabel[:len(hLabel) - len(headerSuffix)]
            MON_HEADERS.append(hLabel)

        if data["for_maps"]:
            hForMaps = wData["wild_encounter_groups"][headerIndex]["for_maps"]
    
        # for the encounter rate macros, so we don't worry about hidden mons here
        if headerIndex == 0:
            wFields = wData["wild_encounter_groups"][headerIndex]["fields"]
            for field in wFields:
                if field["type"] == LAND_MONS:
                    eLandMons = field["encounter_rates"]
                elif field["type"] == WATER_MONS:
                    eWaterMons = field["encounter_rates"]
                elif field["type"] == ROCK_SMASH_MONS:
                    eRockSmashMons = field["encounter_rates"]
                elif field["type"] == FISHING_MONS:
                    eFishingMons = field["encounter_rates"]
                    eFishingMons.append(field["groups"])

            PrintGeneratedWarningText()

            print('#include "rtc.h"')
            print("\n")

            PrintEncounterRateMacros()
            print("\n")

        for encounter in wEncounters:
            if "map" in encounter:
                structMap = encounter["map"]
            else:
                structMap = encounter["base_label"]
            structLabel = encounter["base_label"]
            
            if encounterTotalCount[headerIndex] != len(wEncounters):
                encounterTotalCount[headerIndex] = len(wEncounters)
            encounterCount[headerIndex] += 1
            headersArray = []

            if not IS_ENABLED:
                structTime = TIME_DEFAULT_LABEL
            elif TIME_MORNING_LABEL in structLabel:
                structTime = TIME_MORNING_LABEL
            elif TIME_DAY_LABEL in structLabel:
                structTime = TIME_DAY_LABEL
            elif TIME_EVENING_LABEL in structLabel:
                structTime = TIME_EVENING_LABEL
            elif TIME_NIGHT_LABEL in structLabel:
                structTime = TIME_NIGHT_LABEL
            else:
                structTime = TIME_MORNING_LABEL
                structLabel = structLabel + "_Morning"

            landMonsInfo      = ""
            waterMonsInfo     = ""
            rockSmashMonsInfo = ""
            fishingMonsInfo   = ""
            hiddenMonsInfo    = ""
            for areaTable in encounter:
                if LAND_MONS in areaTable:
                    structMonType = LAND_MONS_LABEL
                    landMonsInfo = f"{structLabel}_{structMonType}{structInfo}"
                elif WATER_MONS in areaTable:
                    structMonType = WATER_MONS_LABEL
                    waterMonsInfo = f"{structLabel}_{structMonType}{structInfo}"
                elif ROCK_SMASH_MONS in areaTable:
                    structMonType = ROCK_SMASH_MONS_LABEL
                    rockSmashMonsInfo = f"{structLabel}_{structMonType}{structInfo}"
                elif FISHING_MONS in areaTable:
                    structMonType = FISHING_MONS_LABEL
                    fishingMonsInfo = f"{structLabel}_{structMonType}{structInfo}"
                elif HIDDEN_MONS in areaTable:
                    structMonType = HIDDEN_MONS_LABEL
                    hiddenMonsInfo = f"{structLabel}_{structMonType}{structInfo}"
                else:
                    structMonType = ""
                    continue
                
                baseStructContent = []
                for group in encounter[areaTable]:
                    if "mons" in group:
                        for mon in encounter[areaTable][group]:
                            baseStructContent.append(list(mon.values()))

                    if "encounter_rate" in group:
                        infoStructRate = encounter[areaTable][group]
                
                baseStructLabel = f"{baseStruct} {structLabel}_{structMonType}{structArrayAssign}"
                if printEncounterStructs:
                    print()
                    print(baseStructLabel)
                    print("{")
                    PrintStructContent(baseStructContent)
                    print("};")

                if printEncounterStructsInfoString:
                    infoStructString = f"{baseStruct}{structInfo} {structLabel}_{structMonType}{structInfo} = {{ {infoStructRate}, {structLabel}_{structMonType} }};"
                    print(infoStructString)

            AssembleMonHeaderContent()
        headerIndex += 1
    PrintWildMonHeadersContent()


def PrintStructContent(contentList):
    for monList in contentList:
        print(f"{tabStr}{{ {monList[0]}, {monList[1]}, {monList[2]} }},")
    return


def GetStructLabelWithoutTime(label):
    labelLength = len(label)
    timeLength = 0

    if not IS_ENABLED:
        return label
    elif TIME_MORNING_LABEL in label:
        timeLength = len(TIME_MORNING_LABEL)
    elif TIME_DAY_LABEL in label:
        timeLength = len(TIME_DAY_LABEL)
    elif TIME_EVENING_LABEL in label:
        timeLength = len(TIME_EVENING_LABEL)
    elif TIME_NIGHT_LABEL in label:
        timeLength = len(TIME_NIGHT_LABEL)
    return label[:(labelLength - (timeLength + 1))]


def AssembleMonHeaderContent():
    global structLabel

    SetupMonInfoVars()

    tempHeaderLabel = GetWildMonHeadersLabel()
    tempHeaderTimeIndex = GetTimeIndexFromString(structTime)
    structLabelNoTime = GetStructLabelWithoutTime(structLabel)
    
    if tempHeaderLabel not in headerStructTable:
        headerStructTable[tempHeaderLabel] = {}
        headerStructTable[tempHeaderLabel]["groupNum"] = headerIndex

    if structLabelNoTime not in headerStructTable[tempHeaderLabel]:
        headerStructTable[tempHeaderLabel][structLabelNoTime] = {}
        headerStructTable[tempHeaderLabel][structLabelNoTime]["headerType"] = GetWildMonHeadersLabel()
        headerStructTable[tempHeaderLabel][structLabelNoTime]["mapGroup"] = structMap
        headerStructTable[tempHeaderLabel][structLabelNoTime]["mapNum"] = structMap
        headerStructTable[tempHeaderLabel][structLabelNoTime]["encounterTotalCount"] = encounterTotalCount[headerIndex]
        headerStructTable[tempHeaderLabel][structLabelNoTime]["encounter_types"] = []

        timeStart = TIME_DEFAULT_INDEX
        timeEnd = TIME_NIGHT_INDEX if IS_ENABLED else TIME_DEFAULT_INDEX
        while timeStart <= timeEnd:
            headerStructTable[tempHeaderLabel][structLabelNoTime]["encounter_types"].append([])
            timeStart += 1

    headerStructTable[tempHeaderLabel][structLabelNoTime]["encounter_types"][tempHeaderTimeIndex].append(landMonsInfo)
    headerStructTable[tempHeaderLabel][structLabelNoTime]["encounter_types"][tempHeaderTimeIndex].append(waterMonsInfo)
    headerStructTable[tempHeaderLabel][structLabelNoTime]["encounter_types"][tempHeaderTimeIndex].append(rockSmashMonsInfo)
    headerStructTable[tempHeaderLabel][structLabelNoTime]["encounter_types"][tempHeaderTimeIndex].append(fishingMonsInfo)
    headerStructTable[tempHeaderLabel][structLabelNoTime]["encounter_types"][tempHeaderTimeIndex].append(hiddenMonsInfo)


def SetupMonInfoVars():
    global landMonsInfo
    global waterMonsInfo
    global rockSmashMonsInfo
    global fishingMonsInfo
    global hiddenMonsInfo

    if landMonsInfo == "":
        landMonsInfo = NULL
    else:
        landMonsInfo = f"&{landMonsInfo}"

    if waterMonsInfo == "":
        waterMonsInfo = NULL
    else:
        waterMonsInfo = f"&{waterMonsInfo}"

    if rockSmashMonsInfo == "":
        rockSmashMonsInfo = NULL
    else:
        rockSmashMonsInfo = f"&{rockSmashMonsInfo}"

    if fishingMonsInfo == "":
        fishingMonsInfo = NULL
    else:
        fishingMonsInfo = f"&{fishingMonsInfo}"

    if hiddenMonsInfo == "":
        hiddenMonsInfo = NULL
    else:
        hiddenMonsInfo = f"&{hiddenMonsInfo}"
    

def PrintWildMonHeadersContent():
    global tabStr

    groupCount = 0
    for group in headerStructTable:
        labelCount = 0
        for label in headerStructTable[group]:
            if label != "groupNum":
                if labelCount == 0:
                    PrintEncounterHeaders("\n")
                    PrintEncounterHeaders(headerStructTable[group][label]["headerType"])

                PrintEncounterHeaders(tabStr + "{")

                for stat in headerStructTable[group][label]:
                    mapData = headerStructTable[group][label][stat]

                    if stat == "mapGroup":
                        PrintEncounterHeaders(f"{TabStr(2)}.mapGroup = {GetMapGroupEnum(mapData)},")
                    elif stat == "mapNum":
                        PrintEncounterHeaders(f"{TabStr(2)}.mapNum = {GetMapGroupEnum(mapData, labelCount + 1)},")

                    if type(headerStructTable[group][label][stat]) == list:
                        PrintEncounterHeaders(f"{TabStr(2)}.encounterTypes =")
                        PrintEncounterHeaders(TabStr(2) + "{")

                        infoCount = 0
                        for monInfo in headerStructTable[group][label][stat]:
                            PrintEncounterHeaders(f"{TabStr(3)}[{GetTimeStrFromIndex(infoCount)}] = ")

                            infoIndex = 0
                            while infoIndex <= MONS_INFO_TOTAL - 1:
                                if infoIndex == 0:
                                    PrintEncounterHeaders(TabStr(3) + "{")

                                if len(monInfo) == 0:
                                    PrintEncounterHeaders(f"{TabStr(4)}{GetIMonInfoStringFromIndex(infoIndex)} = NULL,")
                                else:
                                    PrintEncounterHeaders(f"{TabStr(4)}{GetIMonInfoStringFromIndex(infoIndex)} = {monInfo[infoIndex]},")

                                if infoIndex == MONS_INFO_TOTAL - 1:
                                    PrintEncounterHeaders(TabStr(3) + "},")

                                infoIndex += 1
                            infoCount += 1
                        PrintEncounterHeaders(TabStr(2) + "},")
                PrintEncounterHeaders(tabStr + "},")

                if labelCount + 1 == headerStructTable[group][label]["encounterTotalCount"]:
                    PrintEncounterHeaders(tabStr + "{")
                    PrintEncounterHeaders(f"{TabStr(2)}.mapGroup = {GetMapGroupEnum(MAP_UNDEFINED)},")
                    PrintEncounterHeaders(f"{TabStr(2)}.mapNum = {GetMapGroupEnum(MAP_UNDEFINED, labelCount + 1)},")

                    timeEnd = TIME_NIGHT_INDEX if IS_ENABLED else TIME_DEFAULT_INDEX
                    nullCount = 0
                    while nullCount <= timeEnd:
                        if nullCount == 0:
                            PrintEncounterHeaders(f"{TabStr(2)}.encounterTypes =")
                            PrintEncounterHeaders(TabStr(2)+ "{")

                        PrintEncounterHeaders(f"{TabStr(3)}[{GetTimeStrFromIndex(nullCount)}] = ")

                        nullIndex = 0
                        while nullIndex <= MONS_INFO_TOTAL - 1:
                            if nullIndex == 0:
                                PrintEncounterHeaders(TabStr(3) + "{")

                            PrintEncounterHeaders(f"{TabStr(4)}{GetIMonInfoStringFromIndex(nullIndex)} = NULL,")

                            if nullIndex == MONS_INFO_TOTAL - 1:
                                PrintEncounterHeaders(TabStr(3) + "},")

                            nullIndex += 1
                        nullCount += 1
                    PrintEncounterHeaders(TabStr(2) + "},")
                    PrintEncounterHeaders(tabStr + "},")
                labelCount += 1
        groupCount += 1
        PrintEncounterHeaders("};")


def GetWildMonHeadersLabel():
        return f"{baseStruct}{structHeader} {MON_HEADERS[headerIndex]}{structHeader}s{structArrayAssign}" + "\n{"


def PrintEncounterHeaders(content):
    if printEncounterHeaders:
        print(content)


def PrintEncounterRateMacros():
    if not printEncounterRateMacros:
        return

    rateCount = 0
    for percent in eLandMons:
        if rateCount == 0:
            print(f"{define} {ENCOUNTER_CHANCE}_{LAND_MONS.upper()}_{SLOT}_{rateCount} {percent}")
        else:
            print(
                f"{define} {ENCOUNTER_CHANCE}_{LAND_MONS.upper()}_{SLOT}_{rateCount} {ENCOUNTER_CHANCE}_{LAND_MONS.upper()}_{SLOT}_{rateCount - 1} + {percent}"
            )

        if rateCount + 1 == len(eLandMons):
            print(
                f"{define} {ENCOUNTER_CHANCE}_{LAND_MONS.upper()}_{TOTAL} ({ENCOUNTER_CHANCE}_{LAND_MONS.upper()}_{SLOT}_{rateCount})"
            )
        rateCount += 1

    rateCount = 0
    for percent in eWaterMons:
        if rateCount == 0:
            print(f"{define} {ENCOUNTER_CHANCE}_{WATER_MONS.upper()}_{SLOT}_{rateCount} {percent}")
        else:
            print(
                f"{define} {ENCOUNTER_CHANCE}_{WATER_MONS.upper()}_{SLOT}_{rateCount} {ENCOUNTER_CHANCE}_{WATER_MONS.upper()}_{SLOT}_{rateCount - 1} + {percent}"
            )

        if rateCount + 1 == len(eWaterMons):
            print(
                f"{define} {ENCOUNTER_CHANCE}_{WATER_MONS.upper()}_{TOTAL} ({ENCOUNTER_CHANCE}_{WATER_MONS.upper()}_{SLOT}_{rateCount})"
            )
        rateCount += 1

    rateCount = 0
    for percent in eRockSmashMons:
        if rateCount == 0:
            print(f"{define} {ENCOUNTER_CHANCE}_{ROCK_SMASH_MONS.upper()}_{SLOT}_{rateCount} {percent}")
        else:
            print(
                f"{define} {ENCOUNTER_CHANCE}_{ROCK_SMASH_MONS.upper()}_{SLOT}_{rateCount} {ENCOUNTER_CHANCE}_{ROCK_SMASH_MONS.upper()}_{SLOT}_{rateCount - 1} + {percent}"
            )

        if rateCount + 1 == len(eRockSmashMons):
            print(
                f"{define} {ENCOUNTER_CHANCE}_{ROCK_SMASH_MONS.upper()}_{TOTAL} ({ENCOUNTER_CHANCE}_{ROCK_SMASH_MONS.upper()}_{SLOT}_{rateCount})"
            )
        rateCount += 1

    for rodRate in eFishingMons[-1]:
        for rodPercentIndex in eFishingMons[-1][rodRate]:
            if rodPercentIndex == OLD_ROD_FIRST_INDEX or rodPercentIndex == GOOD_ROD_FIRST_INDEX or rodPercentIndex == SUPER_ROD_FIRST_INDEX:
                print(
                    f"{define} {ENCOUNTER_CHANCE}_{FISHING_MONS.upper()}_{rodRate.upper()}_{SLOT}_{rodPercentIndex} {eFishingMons[rodPercentIndex]}"
                )
            else:
                print(
                    f"{define} {ENCOUNTER_CHANCE}_{FISHING_MONS.upper()}_{rodRate.upper()}_{SLOT}_{rodPercentIndex} {ENCOUNTER_CHANCE}_{FISHING_MONS.upper()}_{rodRate.upper()}_{SLOT}_{rodPercentIndex - 1} + {eFishingMons[rodPercentIndex]}"
                )
            
            if rodPercentIndex == OLD_ROD_LAST_INDEX or rodPercentIndex == GOOD_ROD_LAST_INDEX or rodPercentIndex == SUPER_ROD_LAST_INDEX:
                print(
                    f"{define} {ENCOUNTER_CHANCE}_{FISHING_MONS.upper()}_{rodRate.upper()}_{TOTAL} ({ENCOUNTER_CHANCE}_{FISHING_MONS.upper()}_{rodRate.upper()}_{SLOT}_{rodPercentIndex})"
                )


def GetTimeStrFromIndex(index):
    if not IS_ENABLED:
        return TIME_DEFAULT
    elif index == TIME_MORNING_INDEX:
        return TIME_MORNING.upper()
    elif index == TIME_DAY_INDEX:
        return TIME_DAY.upper()
    elif index == TIME_EVENING_INDEX:
        return TIME_EVENING.upper()
    elif index == TIME_NIGHT_INDEX:
        return TIME_NIGHT.upper()
    return index


def GetTimeIndexFromString(string):
    if not IS_ENABLED:
        return TIME_DEFAULT_INDEX
    elif string.lower() == TIME_MORNING or string == TIME_MORNING_LABEL:
        return TIME_MORNING_INDEX
    elif string.lower() == TIME_DAY or string == TIME_DAY_LABEL:
        return TIME_DAY_INDEX
    elif string.lower() == TIME_EVENING or string == TIME_EVENING_LABEL:
        return TIME_EVENING_INDEX
    elif string.lower() == TIME_NIGHT or string == TIME_NIGHT_LABEL:
        return TIME_NIGHT_INDEX
    return string


def GetIMonInfoStringFromIndex(index):
    if index == LAND_MONS_INDEX:
        return ".landMonsInfo"
    elif index == WATER_MONS_INDEX:
        return ".waterMonsInfo"
    elif index == ROCK_SMASH_MONS_INDEX:
        return ".rockSmashMonsInfo"
    elif index == FISHING_MONS_INDEX:
        return ".fishingMonsInfo"
    elif index == HIDDEN_MONS_INDEX:
        return ".hiddenMonsInfo"
    return index


def GetMapGroupEnum(string, index = 0):
    if "MAP_" in string and index == 0:
        return "MAP_GROUP(" + string[4:len(string)] + ")"
    elif "MAP_" in string and index != 0:
        return "MAP_NUM(" + string[4:len(string)] + ")"
    return index


"""
get copied lhea :^ ) 
- next two functions copied almost verbatim from @lhearachel's python scripts in tools/learnset_helpers
"""
def PrintGeneratedWarningText():
    print("//")
    print("// DO NOT MODIFY THIS FILE! It is auto-generated by tools/wild_encounters/wild_encounters_to_header.py")
    print("//")
    print("\n")


def IsConfigEnabled():
    CONFIG_ENABLED_PAT = re.compile(r"#define OW_TIME_OF_DAY_ENCOUNTERS\s+(?P<cfg_val>[^ ]*)")

    with open("./include/config/overworld.h", "r") as overworld_config_file:
        config_overworld = overworld_config_file.read()
        config_setting = CONFIG_ENABLED_PAT.search(config_overworld)
        return config_setting is not None and config_setting.group("cfg_val") in ("TRUE", "1")


def TabStr(amount):
    global tabStr
    return tabStr * amount


ImportWildEncounterFile()


"""
!!!! EXAMPLE OUTPUT !!!!
- when OW_TIME_OF DAY_ENCOUNTERS is FALSE in configoverworld.h

#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 20
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 + 20
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 + 5
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 + 5
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 + 4
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 + 4
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 + 1
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_11 ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 + 1
#define ENCOUNTER_CHANCE_LAND_MONS_TOTAL (ENCOUNTER_CHANCE_LAND_MONS_SLOT_11)
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 60
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 + 30
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 + 5
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 + 4
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_4 ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 + 1
#define ENCOUNTER_CHANCE_WATER_MONS_TOTAL (ENCOUNTER_CHANCE_WATER_MONS_SLOT_4)
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 60
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 + 30
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 + 5
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 + 4
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 + 1
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_TOTAL (ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4)
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 60
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 70
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1 ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 + 30
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1)
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 40
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 + 40
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 + 15
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 + 4
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 + 1
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)

const struct WildPokemon gRoute101_LandMons_Day[] =
{
    { 2, 2, SPECIES_WURMPLE },
    { 2, 2, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_WURMPLE },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
};

const struct WildPokemonInfo gRoute101_Day_LandMonsInfo= { 20, gRoute101_Day_LandMons };
const struct WildPokemonHeader gWildMonHeaders[] =
{
    {
        .mapGroup = MAP(ROUTE101),
        .mapNum = MAP_NUM(ROUTE101),
        .encounterTypes =
            [OW_TIME_OF_DAY_DEFAULT] =
            {
                .landMonsInfo = &gRoute101_LandMonsInfo,
                .waterMonsInfo = NULL,
                .rockSmashMonsInfo = NULL,
                .fishingMonsInfo = NULL,
                .hiddenMonsInfo = NULL,
            }
    },
}
"""
