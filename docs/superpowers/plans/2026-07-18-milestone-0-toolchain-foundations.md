# Milestone 0: Toolchain & Foundations Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.
>
> **Execution mode chosen for this run:** inline (superpowers:executing-plans). Every task mutates shared machine state (brew packages, PATH, build dir, emulator behavior discovered at runtime) and tasks are strictly serial — fresh subagents would re-discover environment state each time for no review benefit.

**Goal:** A pinned, building, booting pokeemerald-expansion base with a scripted headless mGBA verification loop, one proven end-to-end event script, and measured save-region reclamation numbers — reported against spec §5 before any feature work.

**Architecture:** Keep upstream untouched except for surgical additions: all new tooling under `tools/habitat/`, all docs under `docs/`, one guarded `verify` target appended to the root `Makefile`, and a two-line test-spot diff in the truck map. Verification is symbol-driven: scripts read `pokeemerald.map` to find `gMain`/`CB2_Overworld`/`gSaveBlock1Ptr`, so they survive rebuilds without hardcoded addresses.

**Tech Stack:** pokeemerald-expansion @ `expansion/1.16.2`, brew `arm-none-eabi-gcc` + `arm-none-eabi-binutils` (Makefile supports system toolchain, no devkitPro needed — verified at Makefile:69–86), brew `mgba` 0.10.5 (Lua scripting compiled in — `lua` is a required dep of the formula), bundled `tools/mgba/mgba-rom-test-mac` (universal binary, native arm64) for `make check`.

## Global Constraints

- Base pinned to tag `expansion/1.16.2`; record in README. Never commit ROMs (`*.gba`), save files, or Nintendo-owned binaries. Repo ships source + patches only; never monetized.
- The design spec (`docs/superpowers/specs/2026-07-18-hoenn-habitat-design-spec-v0.1.md`) is the schema contract. M0 changes NOTHING player-facing except one throwaway test sign.
- Save-layout changes (flipping `FREE_*` configs, cutting Secret Bases) are **measured, not applied** in M0 — application needs Jay's sign-off on the layout proposal (working agreement: ask before save-layout changes).
- Verify before reporting: every claim below ends in a command with observable output (screenshot or PASS line).
- Small commits, imperative messages, CHANGELOG from the start.

## Discovered facts this plan relies on (recon, 2026-07-18)

- Tag `expansion/1.16.2` = latest stable (`git ls-remote --tags`). Cloned with `--filter=blob:none`, branch `main`, remote renamed `upstream`. No push remote — publishing is Jay's call.
- Makefile builds with any `arm-none-eabi-` toolchain on PATH when `$(DEVKITARM)` is unset (Makefile:69–86). Modern-only (`-DMODERN=1` hardcoded). ROM name: `pokeemerald.gba` + `.elf` + `.map`.
- `include/config/quickstart.h`: `ENABLE_QUICKSTART TRUE` → **SELECT on the title screen starts a new game directly** (`src/quickstart.c` → `CB2_SkipToNewGame` → default name BRENDAN/MAY → `CB2_NewGame`). Kills the whole intro-input problem: headless boot needs only SELECT taps.
- New game lands in `MAP_INSIDE_OF_TRUCK` under `CB2_Overworld` with immediate player control. Truck interior: existing sign bg_event at (1,0) whose script we can repoint; player position readable at `*gSaveBlock1Ptr + 0x00/0x02` (pos is SaveBlock1's first field — re-verify offset comment in `include/global.h` before relying on it).
- `include/config/save.h` documents 3,790 B of config-freeable save space (2,516 B in SaveBlock1 incl. 1,104 B ramScript + 876 B Mystery Gift; 1,274 B in SaveBlock2). **No FREE_ option for Secret Bases** — `secretBases[SECRET_BASES_COUNT]` still sits in SaveBlock1 at 0x1A9C (global.h:1136), so cutting it is our own change later; §5's 3.2 KB assumption looks alive but must be measured.
- `make check` = repo's own headless test system via bundled `mgba-rom-test-mac` (arm64-native slice confirmed with `file`). Debug overworld menu (R+Start) is ON in non-release builds — future M1 testing aid.
- mGBA scripting Lua API (0.10.x): `emu:read8/16/32`, `emu:screenshot(path)`, `emu:addKey/clearKey` with `C.GBA_KEY.*`, `callbacks:add("frame", fn)`. Exact quirks (io/os availability, throttle flags `-C audioSync=0 -C videoSync=0`) are **verified live in Task 2 Step 2 with a 30-second probe script before the real harness is written** — if an API differs, adapt the harness and note it in the M0 report.

---

### Task 0: Project hygiene baseline

**Files:**
- Modify: `README.md` (top: project banner, pinned tag, legal stance)
- Create: `CHANGELOG.md`
- Create: `docs/superpowers/specs/2026-07-18-hoenn-habitat-design-spec-v0.1.md` (copy of Jay's spec — already staged in working tree)
- Create: `docs/superpowers/plans/2026-07-18-milestone-0-toolchain-foundations.md` (this file)
- Modify: `.gitignore` (append `verify-out/` and `.DS_Store`)

**Interfaces:**
- Produces: branch `main` at `expansion/1.16.2` (done during recon), docs conventions all later tasks follow.

- [ ] **Step 1: Prepend project banner to README.md**

```markdown
# Hoenn Habitat

A non-commercial fan project transforming Pokémon Emerald into a habitat/befriending
game — no wild battles, no capture. Built on
[pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion),
**pinned to tag `expansion/1.16.2`**.

- Design contract: `docs/superpowers/specs/2026-07-18-hoenn-habitat-design-spec-v0.1.md`
- This repository distributes **source and patches only** — never ROMs, never
  Nintendo-owned binaries, never monetized. Building requires your own legally
  dumped copy of Pokémon Emerald for comparison purposes only; the build itself
  compiles entirely from this source tree.
- Verification: `make verify` (headless mGBA boot + screenshot loop, see
  `tools/habitat/`).

---

<original upstream README follows>
```

- [ ] **Step 2: Create CHANGELOG.md** with an `## [Unreleased]` section listing M0 entries as they land.

- [ ] **Step 3: Append to .gitignore**: `verify-out/`, `.DS_Store`.

- [ ] **Step 4: Verify clean status** — `git status` shows only intended files; `git log --oneline -1` shows we sit on `expansion/1.16.2`'s commit.

- [ ] **Step 5: Commit** — `docs: pin expansion/1.16.2 base, add spec, changelog, M0 plan`

### Task 1: Toolchain install + clean ROM build

**Files:** none in-repo (system packages + build artifacts only; artifacts are gitignored)

**Interfaces:**
- Produces: `pokeemerald.gba`, `pokeemerald.elf`, `pokeemerald.map` at repo root — consumed by every later task.

- [ ] **Step 1: Install toolchain** — `brew install libpng pkg-config arm-none-eabi-gcc coreutils` (docs/install/mac/MAC_OS.md deps, minus devkitPro; `arm-none-eabi-binutils` arrives as a dependency). Expected: all formulas install without sudo.
- [ ] **Step 2: Confirm tools** — `arm-none-eabi-gcc --version` prints 16.x; `arm-none-eabi-ld --version` prints binutils version.
- [ ] **Step 3: Build** — `make -j$(sysctl -n hw.ncpu) 2>&1 | tail -20`. Expected: exits 0; `pokeemerald.gba` + `.elf` + `.map` exist. Record `shasum pokeemerald.gba` and byte size for the report. (Contingency: if brew GCC 16 trips on the tree, `brew install arm-none-eabi-gcc@14` or file a targeted `-Wno-…`/patch fix — document whatever was needed. Check the pokeemerald wiki/RHH docs before improvising.)
- [ ] **Step 4: Run repo's own test system** — `make check -j$(sysctl -n hw.ncpu)` in background; it is allowed to take tens of minutes. Expected: test summary with 0 failures (known-flaky upstream tests, if any, get named in the report). This proves the bundled headless runner works on this machine — the same infrastructure M1 unit tests will use.
- [ ] **Step 5: Commit** — nothing to commit (system state only). CHANGELOG note happens in Task 4's commit.

### Task 2: Headless mGBA verification harness (`make verify`)

**Files:**
- Create: `tools/habitat/gen_syms.sh` (map file → `verify-out/syms.lua`)
- Create: `tools/habitat/boot_verify.lua` (mGBA script: boot → quickstart → overworld → interact → screenshots → result file)
- Create: `tools/habitat/verify.sh` (orchestrator: build, gen syms, launch mgba headless, poll result, kill, PASS/FAIL)
- Modify: `Makefile` (append guarded `verify` phony target)

**Interfaces:**
- Consumes: `pokeemerald.map` symbols `gMain`, `CB2_Overworld`, `gSaveBlock1Ptr`.
- Produces: `make verify` → exit 0 + `verify-out/{title,overworld,interact}.png` + `verify-out/result.txt` containing `PASS`. Task 3 extends `boot_verify.lua`'s interact stage; M1 will grow this into a playthrough-script library.

- [ ] **Step 1: Install emulator** — `brew install mgba`. Expected: `mgba --version` prints 0.10.5.
- [ ] **Step 2: Probe scripting API** (30-second throwaway, `verify-out/probe.lua`): log a line from a frame callback, read `emu:romSize()` or similar, take one screenshot, test `io.open` write and `os.exit`, run via `SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy mgba --script verify-out/probe.lua -C audioSync=0 -C videoSync=0 pokeemerald.gba` for ~5s. Confirms: script flag name, screenshot pathing, io/os availability, throttle behavior. Adapt the next steps to what the probe reveals.
- [ ] **Step 3: Write `gen_syms.sh`** — greps `pokeemerald.map` for the three symbols, emits a Lua table:

```sh
#!/bin/sh
# Usage: gen_syms.sh <mapfile> <out.lua> — extracts addresses the verify script needs.
set -e
MAP="$1"; OUT="$2"
sym() { awk -v s="$1" '$2 == s { print $1; exit }' "$MAP"; }
cat > "$OUT" <<EOF
return {
  gMain = $(sym gMain),
  CB2_Overworld = $(sym CB2_Overworld),
  gSaveBlock1Ptr = $(sym gSaveBlock1Ptr),
}
EOF
```

(Exact awk field layout depends on the generated map format — adjust after eyeballing `grep -n " gMain$" pokeemerald.map`.)

- [ ] **Step 4: Write `boot_verify.lua`** — frame-callback state machine:

```lua
-- Headless boot verification for Hoenn Habitat.
-- Env: HH_OUT (output dir), HH_SYMS (syms.lua path), HH_INTERACT (0/1).
local out = os.getenv("HH_OUT") or "verify-out"
local syms = dofile(os.getenv("HH_SYMS") or (out .. "/syms.lua"))
local interact = (os.getenv("HH_INTERACT") or "1") == "1"

local THUMB = 1
local frame, phase, holdUntil, nextTap = 0, "boot", 0, 0
local overworldFrames, shots = 0, {}

local function cb2() return emu:read32(syms.gMain + 4) end
local function inOverworld() return cb2() == (syms.CB2_Overworld + THUMB) end
local function playerPos()
  local sb1 = emu:read32(syms.gSaveBlock1Ptr)
  return emu:read16(sb1), emu:read16(sb1 + 2)
end
local function tap(key)  -- press for 2 frames
  emu:addKey(key); holdUntil = frame + 2
end
local function shot(name)
  if not shots[name] then emu:screenshot(out .. "/" .. name .. ".png"); shots[name] = true end
end
local function finish(status, msg)
  local f = io.open(out .. "/result.txt", "w")
  f:write(status .. " " .. msg .. "\n"); f:close()
  console:log("HH_RESULT " .. status .. " " .. msg)
  phase = "done"
end

callbacks:add("frame", function()
  frame = frame + 1
  if holdUntil > 0 and frame >= holdUntil then
    emu:setKeys(0); holdUntil = 0
  end
  if phase == "boot" then
    -- SELECT does nothing on copyright/intro; on title it quickstarts.
    if frame > 240 and frame >= nextTap and holdUntil == 0 then
      shot("title")                      -- refreshed cheaply? no: only first call sticks; acceptable
      tap(C.GBA_KEY.SELECT); nextTap = frame + 20
    end
    if inOverworld() then phase = "settle"; overworldFrames = 0 end
    if frame > 18000 then finish("FAIL", "never reached overworld") end
  elseif phase == "settle" then
    overworldFrames = overworldFrames + 1
    if not inOverworld() then overworldFrames = 0 end
    if overworldFrames == 120 then
      shot("overworld")
      if interact then phase = "walk" else finish("PASS", "overworld reached") end
    end
  elseif phase == "walk" then
    -- Target: stand at (1,1) facing UP toward the (1,0) sign, then A.
    local x, y = playerPos()
    if holdUntil == 0 and frame >= nextTap then
      if x > 1 then tap(C.GBA_KEY.LEFT); nextTap = frame + 24
      elseif x < 1 then tap(C.GBA_KEY.RIGHT); nextTap = frame + 24
      elseif y > 1 then tap(C.GBA_KEY.UP); nextTap = frame + 24
      elseif y < 1 then tap(C.GBA_KEY.DOWN); nextTap = frame + 24
      else phase = "face"; nextTap = frame + 10 end
    end
    if frame > 22000 then finish("FAIL", "walk timeout at " .. x .. "," .. y) end
  elseif phase == "face" then
    if frame >= nextTap then tap(C.GBA_KEY.UP); phase = "press"; nextTap = frame + 30 end
  elseif phase == "press" then
    if frame >= nextTap then tap(C.GBA_KEY.A); phase = "textbox"; nextTap = frame + 120 end
  elseif phase == "textbox" then
    if frame >= nextTap then shot("interact"); finish("PASS", "interacted with test spot") end
  end
end)
```

Notes: tap-length 2 frames turns/steps reliably; 24-frame gaps let a step finish; `walk` re-reads position every tap so drift self-corrects. If `io`/`os` turn out sandboxed (Step 2 probe), fall back to `console:log` only and have `verify.sh` parse stdout.

- [ ] **Step 5: Write `verify.sh`**:

```sh
#!/bin/sh
# Headless build-and-boot verification. Usage: tools/habitat/verify.sh [--no-interact]
set -e
cd "$(dirname "$0")/../.."
OUT=verify-out; ROM=pokeemerald.gba
INTERACT=1; [ "$1" = "--no-interact" ] && INTERACT=0
rm -rf "$OUT"; mkdir -p "$OUT"
make -j"$(sysctl -n hw.ncpu)" >/dev/null
tools/habitat/gen_syms.sh pokeemerald.map "$OUT/syms.lua"
HH_OUT="$OUT" HH_SYMS="$OUT/syms.lua" HH_INTERACT=$INTERACT \
  SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy \
  mgba --script tools/habitat/boot_verify.lua -C audioSync=0 -C videoSync=0 "$ROM" \
  > "$OUT/mgba.log" 2>&1 &
PID=$!
for i in $(seq 1 180); do
  [ -f "$OUT/result.txt" ] && break
  kill -0 $PID 2>/dev/null || break
  sleep 1
done
kill $PID 2>/dev/null || true; wait $PID 2>/dev/null || true
if grep -q "^PASS" "$OUT/result.txt" 2>/dev/null; then
  echo "VERIFY PASS: $(cat "$OUT/result.txt")"; ls "$OUT"/*.png; exit 0
fi
echo "VERIFY FAIL"; cat "$OUT/result.txt" 2>/dev/null; tail -20 "$OUT/mgba.log"; exit 1
```

(Exact mgba CLI flags per Step 2 probe — `--script` vs `-l`, config flag spelling.)

- [ ] **Step 6: Append guarded target to Makefile** (bottom of file):

```make
# --- Hoenn Habitat additions (keep this block at end of file; upstream-merge-friendly) ---
.PHONY: verify
verify:
	@tools/habitat/verify.sh
```

- [ ] **Step 7: Run `make verify --no-interact` path first** (`tools/habitat/verify.sh --no-interact` directly): expect `VERIFY PASS: PASS overworld reached` + `title.png` + `overworld.png`. Iterate here until green — this is the step where emulator reality bites; keep fixes inside the harness files.
- [ ] **Step 8: Visually confirm screenshots** (Read the PNGs): title screen with quickstart HUD chip; truck interior with player. A black or garbage frame = FAIL even if the script said PASS.
- [ ] **Step 9: Commit** — `build: add headless mGBA verification harness (make verify)`

### Task 3: Throwaway test spot (event pipeline proof)

**Files:**
- Modify: `data/maps/InsideOfTruck/map.json` (bg_event at (1,0): `"script": "InsideOfTruck_EventScript_MovingBox"` → `"InsideOfTruck_EventScript_HabitatTestSpot"`)
- Modify: `data/maps/InsideOfTruck/scripts.inc` (append script + text)

**Interfaces:**
- Consumes: Task 2's harness with `HH_INTERACT=1` (walk → face (1,0) → A → screenshot).
- Produces: proof that map.json → mapjson tool → event scripts → msgbox pipeline works end to end. Removed again when M1's real spot framework lands (tracked in CHANGELOG).

- [ ] **Step 1: Append to scripts.inc** (match the file's existing msgbox style before writing — if `MovingBox` uses a different msgbox macro form, mirror it):

```asm
@ --- Hoenn Habitat: throwaway M0 pipeline test. Delete when the real spot framework lands. ---
InsideOfTruck_EventScript_HabitatTestSpot::
	msgbox InsideOfTruck_Text_HabitatTestSpot, MSGBOX_SIGN
	end

InsideOfTruck_Text_HabitatTestSpot:
	.string "HABITAT TEST SPOT: something is\n"
	.string "listening under the floorboards.$"
```

- [ ] **Step 2: Repoint the (1,0) bg_event script in map.json.**
- [ ] **Step 3: Run full `make verify`** (interact path). Expected: `VERIFY PASS: PASS interacted with test spot`, `interact.png` shows the textbox with the habitat line.
- [ ] **Step 4: Read `interact.png`** and confirm the exact text renders.
- [ ] **Step 5: Commit** — `feat: add throwaway habitat test spot in moving truck`

### Task 4: Save-region reclamation measurement

**Files:**
- Create: `tools/habitat/save_probe.c` (sizeof/offsetof probes as char-array symbols)
- Create: `tools/habitat/save_sizes.sh` (compile probe with the ROM's own include flags, `nm --print-size`, print table)

**Interfaces:**
- Consumes: build includes (`include/`, generated headers if any probe needs them).
- Produces: exact byte numbers for the M0 report and M1's save-layout proposal. **No config flips, no struct edits** — measurement only.

- [ ] **Step 1: Write `save_probe.c`** — one `char probe_<name>[EXPR];` per quantity so `nm --print-size` reports EXPR as the symbol size:

```c
// Compile-only probe: symbol sizes encode sizeof()s. Never linked into the ROM.
#include "global.h"

#define PROBE(name, expr) char probe_##name[expr];
PROBE(SaveBlock1_total,        sizeof(struct SaveBlock1))
PROBE(SaveBlock2_total,        sizeof(struct SaveBlock2))
PROBE(PokemonStorage_total,    sizeof(struct PokemonStorage))
PROBE(SecretBases_slab,        sizeof(((struct SaveBlock1 *)0)->secretBases))
PROBE(SecretBase_one,          sizeof(struct SecretBase))
PROBE(Frontier_slab,           sizeof(((struct SaveBlock2 *)0)->frontier))
PROBE(ContestWinners_slab,     sizeof(((struct SaveBlock1 *)0)->contestWinners))
PROBE(SecretBases_offset,      offsetof(struct SaveBlock1, secretBases) + 1)
```

(Exact member list adjusted to what `struct SaveBlock1/2` actually contain at this tag — check `include/global.h` first; add contest/lilycove-lady/frontier members found there. The `+1` on offsets avoids zero-sized arrays.)

- [ ] **Step 2: Write `save_sizes.sh`** — compiles with the same `-I` set the ROM uses (crib from a `make -n` line or `compile_commands`-style echo), `arm-none-eabi-gcc -c -o /tmp/probe.o`, then `arm-none-eabi-nm --print-size --radix=d /tmp/probe.o | sort` pretty-printed.
- [ ] **Step 3: Run it; capture the table.** Also compute save-sector budget: grep `SECTOR_DATA_SIZE` and the SaveBlock1/2 sector counts from `include/save.h`/`src/save.c` to state headroom (allocated sector bytes − sizeof).
- [ ] **Step 4: Cross-check** `SecretBases_slab` ≈ 3,200 B (§5 assumption) and reconcile with config/save.h's documented 3,790 B of FREE_* space. Any surprise (secret bases smaller, SaveBlock1 already near sector limit, expansion-added fields) goes in the report verbatim.
- [ ] **Step 5: Commit** — `build: add save-region measurement probes`

### Task 5: Milestone 0 report + wrap-up

**Files:**
- Create: `docs/reports/2026-07-18-milestone-0.md`
- Modify: `CHANGELOG.md` (finalize M0 entries)

- [ ] **Step 1: Write the report**: pinned tag + commit; toolchain versions; build result (size, sha1, `make check` summary); verify harness description + screenshot paths; save-region table vs §5 budget with a concrete recommendation for where `HabitatSave` should live; deviations/risks (e.g., brew mgba formula deprecation, GCC version quirks); batched questions for Jay; explicit "M1 not started — awaiting go".
- [ ] **Step 2: Commit** — `docs: add Milestone 0 report`
- [ ] **Step 3: Deliver**: send screenshots + report to Jay; save project memory file (`hoenn-habitat-project.md`) with location, tag, state; **stop before Milestone 1** (working agreement: report M0 results before proceeding; the save-layout decision needs Jay's eyes anyway).

## Self-Review

- **Spec coverage (M0 brief items 1–5):** builds+boots (Task 1), headless smoke + make verify (Task 2), scripted test spot (Task 3), save validation with exact numbers (Task 4), commit hygiene + CHANGELOG + no-ROM policy (Task 0 + every commit step). §5's open question is Task 4's whole job. ✓
- **Placeholder scan:** two deliberate adapt-on-contact notes remain (mGBA CLI flag spelling, map-file awk fields) — each is paired with a concrete probe step that resolves it before use, not deferred work. ✓
- **Type consistency:** symbol names (`gMain`, `CB2_Overworld`, `gSaveBlock1Ptr`), env vars (`HH_OUT`, `HH_SYMS`, `HH_INTERACT`), and file paths match across Tasks 2–3. ✓
