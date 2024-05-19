import glob
import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

# Read battle_util.c and extract the icon and palette information
for file in glob.glob('./src/battle_util.c'):
    with open(file, 'r') as f:
        icon_table_content = f.read()

# Extract item icon and palette data from battle_util.c
icon_table_pattern = re.compile(r'\[ITEM_TO_BERRY\((ITEM_[A-Z_0-9]+)\)\]\s*=\s*\{([^,]+),\s*([^}]+)\}', re.MULTILINE)
icon_table_data = {}
for match in icon_table_pattern.findall(icon_table_content):
    if len(match) == 3:
        item_name, type, power = match
        icon_table_data[item_name] = (type, power)

# Read berry.c content
for file in glob.glob('./src/berry.c'):
    with open(file, 'r') as f:
        items_content = f.read()

# Modify berry.c content
def add_natural_gift_data(match):
    item_name = match.group(1)
    item_content = match.group(2)
    if item_name in icon_table_data:
        type, power = icon_table_data[item_name]
        print(f"Updating {item_name}: adding naturalGiftType = {type}, naturalGiftPower = {power}")
        return f'[{item_name} - FIRST_BERRY_INDEX] =\n    {{{item_content}    .naturalGiftType = {type},\n        .naturalGiftPower = {power},\n    }},'
    else:
        return match.group(0)

item_pattern = re.compile(r'\[(ITEM_[A-Z_0-9]+) - FIRST_BERRY_INDEX\]\s*=\s*\{([\s\S]*?)\},', re.DOTALL)
modified_items_content = item_pattern.sub(add_natural_gift_data, items_content)

# Write the modified content back to berry.c
for file in glob.glob('./src/berry.c'):
    with open(file, 'w') as f:
        f.write(modified_items_content)
        print("berry.c has been updated")