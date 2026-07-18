#!/bin/sh
# Prints exact save-struct sizes/offsets measured from the real headers.
# Method: compile save_probe.c with the ROM's own include flags; each probe
# symbol's size IS the measured value (nm --print-size). Measurement only —
# changes nothing.
set -e
cd "$(dirname "$0")/../.."
. tools/habitat/env.sh

OBJ="$(mktemp -d)/save_probe.o"
# Flags mirror the ROM's own CFLAGS (Makefile:170) — -mabi=apcs-gnu is layout-
# critical (enum sizing, struct packing); without it the numbers lie.
arm-none-eabi-gcc -c -iquote include -DMODERN=1 -DTESTING=0 -DEMERALD \
    -std=gnu17 -mthumb -mthumb-interwork -mabi=apcs-gnu -mtune=arm7tdmi -march=armv4t \
    tools/habitat/save_probe.c -o "$OBJ"
echo "# bytes  probe"
arm-none-eabi-nm --print-size --radix=d "$OBJ" \
    | awk '$4 ~ /^probe_/ { printf "%8d  %s\n", $2, substr($4, 7) }' \
    | sort -k2
rm -f "$OBJ"
