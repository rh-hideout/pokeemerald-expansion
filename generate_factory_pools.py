import re
import os
from collections import defaultdict

# --- CONFIGURATION ---
CONSTS_FILE = "include/constants/battle_frontier_mons.h"
HEADER_OUT = "include/constants/factory_pools.h"
SOURCE_OUT = "src/data/battle_factory/factory_pools.c"

# --- Ensure output directory exists ---
os.makedirs(os.path.dirname(HEADER_OUT), exist_ok=True)
os.makedirs(os.path.dirname(SOURCE_OUT), exist_ok=True)

# --- STEP 1: Parse NUM_ORIGINAL_FRONTIER_MONS ---
NUM_ORIGINAL_FRONTIER_MONS = 0
with open(CONSTS_FILE, "r") as f:
    for line in f:
        match = re.match(r"#define NUM_ORIGINAL_FRONTIER_MONS\s+(\d+)", line)
        if match:
            NUM_ORIGINAL_FRONTIER_MONS = int(match.group(1))
            break

if NUM_ORIGINAL_FRONTIER_MONS == 0:
    print("❌ Could not find NUM_ORIGINAL_FRONTIER_MONS in the constants file.")
    exit(1)

# --- STEP 2: Parse macro defines and filter by index ---
tier_macros = defaultdict(list)
with open(CONSTS_FILE, "r") as f:
    for line in f:
        match = re.match(r"#define\s+(FRONTIER_MON_[A-Z0-9_]+)\s+(\d+)", line)
        if match:
            macro, index = match.groups()
            index = int(index)

            if index < NUM_ORIGINAL_FRONTIER_MONS:
                continue  # Skip original Pokémon

            parts = macro.split("_")
            if len(parts) >= 4 and parts[0] == "FRONTIER" and parts[1] == "MON":
                tier = parts[2]  # FRONTIER_MON_<TIER>_<SPECIES>_...
                tier_macros[tier].append(macro)

if not tier_macros:
    print("❌ No valid custom Pokémon found.")
    exit(1)

# --- STEP 3: Write Header and Source Files (Idempotent) ---
MARKER_BEGIN = "// BEGIN_GENERATED_FACTORY_POOLS"
MARKER_END = "// END_GENERATED_FACTORY_POOLS"

header_block = ["#ifndef GUARD_FACTORY_POOLS_H", "#define GUARD_FACTORY_POOLS_H", "", "// Auto-generated Frontier Factory Pool Declarations", MARKER_BEGIN]
source_block = [
    '#include "../../../include/global.h"',
    '#include "../../../include/constants/factory_pools.h"',
    '#include "../../../include/constants/battle_frontier_mons.h"',
    "",
    MARKER_BEGIN
]

for tier in sorted(tier_macros.keys()):
    macros = tier_macros[tier]
    count_macro = f"FRONTIER_FACTORY_POOL_{tier}_COUNT"

    # Header block
    header_block.append(f"#define {count_macro} {len(macros)}")
    header_block.append(f"extern const u16 gFrontierFactoryPool_{tier}[{count_macro}];")

    # Source block
    source_block.append(f"const u16 gFrontierFactoryPool_{tier}[{count_macro}] = {{")
    for macro in macros:
        source_block.append(f"    {macro},")
    source_block.append("};\n")

header_block.append(MARKER_END)
header_block.append("\n#endif // GUARD_FACTORY_POOLS_H\n")

source_block.append(MARKER_END)

# --- Write header file idempotently ---
if os.path.exists(HEADER_OUT):
    with open(HEADER_OUT, "r") as f:
        content = f.read()
    content = re.sub(rf"{MARKER_BEGIN}.*?{MARKER_END}", "\n".join(header_block[4:-2]), content, flags=re.DOTALL)
    if MARKER_BEGIN not in content:
        content = "\n".join(header_block)
else:
    content = "\n".join(header_block)

with open(HEADER_OUT, "w") as f:
    f.write(content)

# --- Write source file idempotently ---
if os.path.exists(SOURCE_OUT):
    with open(SOURCE_OUT, "r") as f:
        content = f.read()
    content = re.sub(rf"{MARKER_BEGIN}.*?{MARKER_END}", "\n".join(source_block[4:-1]), content, flags=re.DOTALL)
    if MARKER_BEGIN not in content:
        content = "\n".join(source_block)
else:
    content = "\n".join(source_block)

with open(SOURCE_OUT, "w") as f:
    f.write(content)

print(f"✅ Pools written to:\n- {HEADER_OUT}\n- {SOURCE_OUT}")