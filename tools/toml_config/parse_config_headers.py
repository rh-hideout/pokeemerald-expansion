#!/usr/bin/env python3

import glob
import os
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
    file_list = sorted(glob.glob("include/config/*.h"))
    for config_fname in file_list:
        config_name = os.path.basename(config_fname)
        if config_name == "test.h":
            continue
        output = []
        with open(config_fname, "r") as config_fp:
            config_lines = config_fp.readlines()
        for line in config_lines:
            if is_guard(line):
                continue
            match = re.match(DEFINE_CONFIG_PAT, line)
            if match.group("define"):
                value = clean_values(match.group("value"))
                new_line = match.group("config") + match.group("whitespace") + "= " + value
                if match.group("comment"):
                    new_line = new_line + " #" + match.group("comment")
            elif match.group("comment"):
                new_line = "# " + match.group("comment")
            else:
                new_line = line
            output.append(new_line)
        config_name = config_name.replace(".h", ".toml")
        with open(f"toml_config/{config_name}", "w+") as f:
            for line in output:
                f.write(f"{line}\n")

def main():

    extract_config_data()

if __name__ == "__main__":
    main()
