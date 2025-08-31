#!/bin/sh
set -e
if [ "$1" != "" ]; then
    mkdir -p $1/tools/poryscript
    if test -f "poryscript"; then
        cp poryscript $1/tools/poryscript
    elif test -f "poryscript.exe"; then
        cp poryscript.exe $1/tools/poryscript
    else
        echo "Could not find executable to install. Try building first!"
        exit 1
    fi
    cp font_config.json $1/tools/poryscript
    cp command_config.json $1/tools/poryscript
else
    echo "Usage: install.sh PATH"
fi
