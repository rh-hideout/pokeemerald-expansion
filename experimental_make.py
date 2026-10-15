#!/usr/bin/env python3

from datetime import datetime, timedelta

import base64
import glob
import json
import os
import re
import subprocess
import sys

INITIAL_MEMORY = {
    "last_update": 0
}

def parse_configs():
    configs = {}
    for config_fname in glob.glob("./include/config/*.h"):
        #print(config_fname)
        with open(config_fname, "r") as config_fp:
            lines = config_fp.readlines()
            for line in lines:
                match = re.search(r'#define\s+([A-Z_]+)\s+\"?([^"\s]+)\"?', line)
                if match:
                    key = match.group(1)
                    value = match.group(2)
                    if value == "TRUE":
                        value = True
                    elif value == "FALSE":
                        value = False
                    elif value.isdigit():
                        value = int(value)
                    configs[key] = value
    return configs

def parse_memory():
    if not os.path.exists("memory"):
        return INITIAL_MEMORY.copy()
    with open("memory", "rb") as memory_file:
        tmp = base64.b64decode(memory_file.read()).decode()
        return json.loads(tmp)

def write_memory():
    with open("memory", "wb+") as memory_file:
        tmp = json.dumps(memory)
        tmp = base64.b64encode(tmp.encode())
        memory_file.write(tmp)


#print(json.dumps(parse_configs(), indent=4))
def check_auto_update_timing():
    if memory["last_update"] == "IN_PROGRESS":
        return True
    frequency = configs["MAKE_AUTO_UPDATE_FREQUENCY"]
    now = datetime.now()
    if frequency == "ALL":
        return True
    elif frequency == "DAILY" and memory["last_update"] + timedelta(days=1) < now:
        return True
    elif frequency == "WEEKLY" and memory["last_update"] + timedelta(days=7) < now:
        return True
    elif frequency == "MONTHLY" and memory["last_update"] + timedelta(days=30) < now:
        return True
    return False

def check_auto_update_local_branch():
    result = subprocess.run(["git", "rev-parse", "--abbrev-ref", "HEAD"], capture_output=True, text=True)
    current_branch = result.stdout.strip()
    print(current_branch)
    print(configs["MAKE_AUTO_UPDATE_LOCAL_BRANCHES"])
    match = re.search(configs["MAKE_AUTO_UPDATE_LOCAL_BRANCHES"], current_branch)
    print(match)
    if match:
        return True
    return False

def try_auto_update():
    if not configs["MAKE_AUTO_UPDATE_ACTIVE"]:
        return
    if not check_auto_update_local_branch():
        return
    if not check_auto_update_timing():
        return
    memory["last_update"] = "IN_PROGRESS"
    write_memory()
    result = subprocess.run(["python3", "dev_scripts/auto_migration.py", configs["MAKE_AUTO_UPDATE_REMOTE_BRANCH"]])
    if result.returncode:
        exit(1)
    else:
        memory["last_update"] = int(datetime.timestamp(datetime.now()))
        write_memory()

def get_max_processes():
    result = subprocess.run(["nproc"], capture_output=True, text=True)
    return result.stdout.strip()

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    exit(1)

configs = parse_configs()
memory = parse_memory()

try_auto_update()
#nproc = get_max_processes()
#subprocess.run(["make", "-j", nproc])
