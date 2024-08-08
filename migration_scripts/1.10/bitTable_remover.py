import sys

try:
    fileName = sys.argv[1]
except:
    print(f"usage: python3 {sys.argv[0]} <file_with_gBitTable>")
else:
    fileData = ""

    with open(fileName, 'r', encoding="utf-8") as f:
        fileData = f.read()
        prevIndex = 0
        while prevIndex != -1:
            tableIndex = fileData.find("gBitTable[", prevIndex+1)
            if tableIndex == -1:
                break
            openBracketCount = 1
            bracketContentStart = tableIndex + 10
            bracketContentCounter = 0;
            while openBracketCount > 0:
                if fileData[bracketContentStart + bracketContentCounter] == '[':
                    openBracketCount += 1
                elif fileData[bracketContentStart + bracketContentCounter] == ']':
                    openBracketCount -= 1
                if openBracketCount > 0:
                    bracketContentCounter += 1
                if bracketContentStart + bracketContentCounter >= len(fileData):
                    prevIndex = tableIndex + 1
                    openBracketCount = -1
            if openBracketCount == -1:
                continue
            bracketContentEnd = bracketContentStart + bracketContentCounter + 1
            bracketContent = fileData[bracketContentStart:bracketContentEnd-1]
            if len(bracketContent) == 0:
                prevIndex = tableIndex
                continue
            if tableIndex > 0:
                fileData = fileData[:(tableIndex)] + "(1 << ("+ bracketContent + "))" + fileData[(bracketContentEnd):]
            else:
                fileData = "(1 << ("+ bracketContent + "))" + fileData[(bracketContentEnd):]
            prevIndex = tableIndex
    with open(fileName, 'w', encoding="utf-8") as f:
        f.write(fileData)
