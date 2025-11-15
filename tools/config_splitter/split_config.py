#!/usr/bin/env python3

import json
import glob
import os
import pathlib
import re

GUARD_CONFIG_PAT = re.compile(r"#[^A-Z]+GUARD_CONFIG_[A-Z_]+?_H")
DEFINE_CONFIG_PAT = re.compile(r"(?P<define>#define\s+(?P<config>\w+)(?P<whitespace>\s+)(?P<value>\w+))?\s*(//(?P<comment>.+))?")
#COMMENT_PAT = re.compile(r"\s*//(?P<comment>.+)")

def is_guard(line: str) -> bool:
    if re.match(GUARD_CONFIG_PAT, line):
        return True
    return False

def clean_values(value: str) -> str:
    if value == "TRUE":
        return "true"
    if value == "FALSE":
        return "false"
    if re.match(r"(0x)?\d+", value):
        return value
    return ('"' + value + '"')

def extract_config_data():
    with open("tools/config_splitter/config_locations.json", "r") as f:
        config_locations = json.load(f)
    file_list = sorted(glob.glob("include/config/*.h"))
    user_configs = {}
    for config_fname in file_list:
        config_name = os.path.basename(config_fname)
        if config_name == "test.h":
            continue
        config_name = "config_" + config_name
        with open(config_fname, "r") as config_fp:
            config_lines = config_fp.readlines()
        for line in config_lines:
            if is_guard(line):
                continue
            match = re.match(DEFINE_CONFIG_PAT, line)
            if match.group("define"):
                config = match.group("config")
                if not config in config_locations:
                    sys.exit(f"No file location found for {config}")
                location =  config_locations[config]
                if not location in user_configs:
                    user_configs[location] = []
                new_line = "#define " + match.group("config") + " " + match.group("value")
                new_line += " // DO NOT MODIFY THIS LINE, change "+ config_fname + " instead"
                user_configs[location].append(new_line)
    return user_configs

def dump_output(file, data):
    with open(file, "w") as fp:
        fp.write(data)

def print_split_configs(all_configs):
    for filename in all_configs:
        file_output = [
            "// DO NOT MODIFY THIS FILE",
            "// This file was auto-generate by tools/config_splitter/split_config.py",
            "// Modify the files in the include/config/ directory instead\n",
            "#ifndef GUARD_" + filename.removesuffix('.h').upper() + "_H",
            "#define GUARD_" + filename.removesuffix('.h').upper() + "_H",
        ]
        file_output += all_configs[filename]
        file_output.append("#endif\n")
        new_config = "\n".join(file_output);
        split_config_file =  pathlib.Path("include/" + filename)
        if split_config_file .exists() and split_config_file .is_file():
            with open(split_config_file, "r") as fp:
                old_config = fp.read()
        else:
            dump_output(split_config_file, new_config)
            continue

        if new_config != old_config:
             dump_output(split_config_file, new_config)

def main():

    user_configs = extract_config_data()
    print_split_configs(user_configs)


if __name__ == "__main__":
    main()