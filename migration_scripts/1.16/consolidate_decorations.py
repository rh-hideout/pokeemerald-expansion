import glob
import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

# Icons
## Read decoration/icon.h
with open("./src/data/decoration/icon.h", 'r') as file:
    source_content = file.read()

## Extract party info from decoration/icon.h
source_pattern = re.compile(r'(\[DECOR_.*\])\s*=\s(\{.*\})*')
source_data = {}
for match in source_pattern.findall(source_content):
    if len(match) == 2:
        decor_name, decor_icon = match
        source_data[decor_name] = (decor_icon)

## Read decoration/header.h content
with open("./src/data/decoration/header.h", 'r') as file:
    destination_content = file.read()

## Modify decoration/header.h content
def add_filter_data(match):
    decor_name = match.group(1)
    if decor_name in source_data:
        decor_icon = source_data[decor_name]
        print(f"Updating {decor_name}: adding {decor_icon}")
        return f'{match.group(0)}\n        .icon = {decor_icon},'
    else:
        return match.group(0)

destination_pattern = re.compile(r'(\[DECOR_[A-Z_0-9]+\])\s*=\s*{\n.*id.*\n.*name.*\n.*permission.*\n.*shape.*\n.*category.*\n.*price.*\n.*description.*\n.*tiles.*')
modified_content = destination_pattern.sub(add_filter_data, destination_content)

## Write the modified content back to decoration/header.h
for file in glob.glob('./src/data/decoration/header.h'):
    with open(file, 'w') as f:
        f.write(modified_content)
        print("decoration/header.h has been updated")
