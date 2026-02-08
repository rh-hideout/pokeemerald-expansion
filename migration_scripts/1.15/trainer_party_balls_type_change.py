import re
import os
import shutil

item_to_ball = {
    "ITEM_STRANGE_BALL": "STRANGE",
    "ITEM_POKE_BALL": "POKE",
    "ITEM_GREAT_BALL": "GREAT",
    "ITEM_ULTRA_BALL": "ULTRA",
    "ITEM_MASTER_BALL": "MASTER",
    "ITEM_PREMIER_BALL": "PREMIER",
    "ITEM_HEAL_BALL": "HEAL",
    "ITEM_NET_BALL": "NET",
    "ITEM_NEST_BALL": "NEST",
    "ITEM_DIVE_BALL": "DIVE",
    "ITEM_DUSK_BALL": "DUSK",
    "ITEM_TIMER_BALL": "TIMER",
    "ITEM_QUICK_BALL": "QUICK",
    "ITEM_REPEAT_BALL": "REPEAT",
    "ITEM_LUXURY_BALL": "LUXURY",
    "ITEM_LEVEL_BALL": "LEVEL",
    "ITEM_LURE_BALL": "LURE",
    "ITEM_MOON_BALL": "MOON",
    "ITEM_FRIEND_BALL": "FRIEND",
    "ITEM_LOVE_BALL": "LOVE",
    "ITEM_FAST_BALL": "FAST",
    "ITEM_HEAVY_BALL": "HEAVY",
    "ITEM_DREAM_BALL": "DREAM",
    "ITEM_SAFARI_BALL": "SAFARI",
    "ITEM_SPORT_BALL": "SPORT",
    "ITEM_PARK_BALL": "PARK",
    "ITEM_BEAST_BALL": "BEAST",
    "ITEM_CHERISH_BALL": "CHERISH",
}

def make_backup_files(files):
    for file in files:
        backup = os.path.basename(file) + ".backup"
        if not os.path.isfile(backup):
            print("Creating backup for " + file)
            shutil.copy2(file, backup, follow_symlinks=True)

def parse_ball(line):
    line = line.removeprefix("Ball:").strip()
    item = "ITEM_"
    for c in line:
        if ('A' <= c and c <= 'Z') or ('0' <= c and c <= '9'):
            item += c
        elif 'a' <= c and c <= 'z':
            item += c.upper()
        elif c == '\'':
            pass
        else:
            item += "_"

    if item not in item_to_ball:
        print("unrecognized pattern:" + item)
        quit()
    return ("Ball: " + item_to_ball[item] + "\n")

def parse_and_change(filepath):
    backup = os.path.basename(filepath) + ".backup"
    allLines = list()
    with open(backup, 'r', encoding='UTF-8') as file:
        while line:=file.readline():
            if "Ball:" in line:
                allLines.append(parse_ball(line))
            else:
                allLines.append(line)

    with open(filepath, 'w+', encoding='UTF-8') as file:
        for line in allLines:
            file.write(line)

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

files = ["src/data/battle_partners.party", "src/data/trainers.party"]
make_backup_files(files)

for file in files:
    parse_and_change(file)

print("Migration complete. You can delete battle_partners.party.backup and trainers.party.backup if things are working properly")