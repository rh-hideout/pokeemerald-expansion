import glob
import re
import os
from pathlib import Path

# All existing calls to IsTextPrinterActive targets a window
# so all function calls can be assumed to be FALSE

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

def find_close_paren(string, index):
    while not string[index] == ")":
        index += 1
    return index

def update_function(fileInput):
    fileTest = Path(fileInput)
    if not fileTest.is_file():
        return False
    allLines = list()
    with open(fileInput, 'r', encoding='UTF-8') as file:
        while line:=file.readline():
            if "bool32 IsTextPrinterActive(u32 id, bool32 isSprite)" in line:
                allLines.append(line)
            elif "IsTextPrinterActive" in line:
                funcNameIndex = line.find("IsTextPrinterActive")
                openParenIndex = line.find("(", funcNameIndex)
                closeParenIndex = find_close_paren(line, openParenIndex)
                firstHalf = line[:closeParenIndex]
                secondHalf = line[closeParenIndex:]
                line = firstHalf + ", FALSE" + secondHalf
                allLines.append(line)
            else:
                allLines.append(line)

    with open(fileInput, 'w', encoding='UTF-8') as file:
        for line in allLines:
            file.write(line)

for file in glob.glob("src/**/*.c", recursive=True):
    update_function(file)
