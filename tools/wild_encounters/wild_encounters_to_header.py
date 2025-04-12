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
fieldData = []
fieldInfoStrings = []

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
    global fieldInfoStrings
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
    global encounterTotalCount
    global encounterCount
    global headerIndex
    global tabStr
    global fieldData
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
            fieldCounter = 0
            for field in wFields:
                fieldData.append({})
                fieldData[fieldCounter]["name"] = field["type"]
                fieldData[fieldCounter]["pascalName"] = GetPascalCase(field["type"])
                fieldData[fieldCounter]["snakeName"] = GetSnakeCase(field["type"])
                fieldData[fieldCounter]["encounter_rates"] = field["encounter_rates"]

                if "groups" in field:
                    fieldData[fieldCounter]["groups"] = field["groups"]

                if fieldCounter == len(wFields) - 1:
                    fieldData.append({})
                    fieldData[fieldCounter + 1]["name"] = "hidden_mons"
                    fieldData[fieldCounter + 1]["pascalName"] = GetPascalCase("hidden_mons")
                    fieldData[fieldCounter + 1]["snakeName"] = GetSnakeCase("hidden_mons")
                fieldCounter += 1
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

            fieldCounter = 0
            fieldInfoStrings = []
            while fieldCounter < len(fieldData):
                fieldInfoStrings.append("")
                fieldCounter += 1

            fieldCounter = 0
            for areaTable in encounter:
                if fieldData[fieldCounter]["name"] in areaTable:
                    structMonType = fieldData[fieldCounter]["pascalName"]
                    fieldInfoStrings[fieldCounter] = f"{structLabel}_{structMonType}{structInfo}"
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

                fieldCounter += 1
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
    global fieldInfoStrings

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

    fieldCounter = 0
    while fieldCounter < len(fieldData):
        headerStructTable[tempHeaderLabel][structLabelNoTime]["encounter_types"][tempHeaderTimeIndex].append(fieldInfoStrings[fieldCounter])
        fieldCounter += 1


def SetupMonInfoVars():
    global fieldData
    global fieldInfoStrings

    i = 0
    while i < len(fieldData):
        fieldData[i]["infoStringBase"] = "." + fieldData[i]["snakeName"] + structInfo
        if fieldInfoStrings[i] == "":
            fieldInfoStrings[i] = NULL
        else:
            fieldInfoStrings[i] = "&" + fieldInfoStrings[i]

        i += 1


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
                            while infoIndex < len(fieldData):
                                if infoIndex == 0:
                                    PrintEncounterHeaders(TabStr(3) + "{")

                                if len(monInfo) == 0:
                                    PrintEncounterHeaders(f"{TabStr(4)}{GetIMonInfoStringFromIndex(infoIndex)} = NULL,")
                                else:
                                    PrintEncounterHeaders(f"{TabStr(4)}{GetIMonInfoStringFromIndex(infoIndex)} = {monInfo[infoIndex]},")

                                if infoIndex == len(fieldData) - 1:
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
                        while nullIndex <= len(fieldData) - 1:
                            if nullIndex == 0:
                                PrintEncounterHeaders(TabStr(3) + "{")

                            PrintEncounterHeaders(f"{TabStr(4)}{GetIMonInfoStringFromIndex(nullIndex)} = NULL,")

                            if nullIndex == len(fieldData) - 1:
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

    fieldCounter = 0
    # len(fieldData) - 1 here so we skip hidden_mons
    while fieldCounter < len(fieldData) - 1: 
        rateCount = 0
        if "groups" not in fieldData[fieldCounter]:
            for percent in fieldData[fieldCounter]["encounter_rates"]:
                if rateCount == 0:
                    print(f"{define} {ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{SLOT}_{rateCount} {percent}")
                else:
                    print(
                        f"{define} {ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{SLOT}_{rateCount} {ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{SLOT}_{rateCount - 1} + {percent}"
                    )

                if rateCount + 1 == len(fieldData):
                    print(
                        f"{define} {ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{TOTAL} ({ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{SLOT}_{rateCount})"
                    )
                rateCount += 1
        else:
            rates = fieldData[fieldCounter]["encounter_rates"]
            groups = fieldData[fieldCounter]["groups"]

            for encounterRate in groups:
                encounter_indices = groups[encounterRate]

                if not encounter_indices:
                    continue

                for i, encounterPercentIndex in enumerate(encounter_indices):
                    if encounterPercentIndex < 0 or encounterPercentIndex >= len(rates):
                        print(f"#error Invalid fishing encounter rate index {encounterPercentIndex} for {encounterRate.upper()}")
                        continue

                    rate_value = rates[encounterPercentIndex]

                    if i == 0:
                        print(f"{define} {ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{encounterRate.upper()}_{SLOT}_{encounterPercentIndex} {rate_value}")
                    else:
                        previous_rod_index = encounter_indices[i - 1]
                        print(f"{define} {ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{encounterRate.upper()}_{SLOT}_{encounterPercentIndex} {ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{encounterRate.upper()}_{SLOT}_{previous_rod_index} + {rate_value}")

                    if i == len(encounter_indices) - 1:
                        print(f"{define} {ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{encounterRate.upper()}_{TOTAL} ({ENCOUNTER_CHANCE}_{fieldData[fieldCounter]["name"].upper()}_{encounterRate.upper()}_{SLOT}_{encounterPercentIndex})")

        fieldCounter += 1


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
    return fieldData[index]["infoStringBase"]


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


def GetPascalCase(string):
    stringArray = string.split("_")
    pascalString = ""

    for string in stringArray:
        pascalString += string.capitalize()

    return pascalString

def GetSnakeCase(string):
    stringArray = string.split("_")
    snakeString = ""

    i = 0
    for string in stringArray:
        if i == 0:
            snakeString += string
        else:
            snakeString += string.capitalize()

        i += 1

    return snakeString


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
