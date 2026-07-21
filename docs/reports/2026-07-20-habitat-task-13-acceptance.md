# Hoenn Habitat Task 13 acceptance evidence

## Status labels

- **Built:** development verification ROM and host runner build from the same
  fresh source snapshot.
- **Focused-tested:** native Habitat tests and tool self-tests named below.
- **Headless-verified:** a scenario exits zero and archives its `result.txt`,
  runner log, and screenshots under its resolved output directory.
- **Full-suite-tested:** the complete native suite is green.
- **Audit-accepted:** a reviewer has checked this report and its archived
  evidence.

This report intentionally does not mark a label achieved merely because the
command exists. Evidence below is from this working tree on 2026-07-20; the
fresh ROM command records an output directory and a build log whenever it is
able to run to completion.

## Required evidence ledger

| Check | Status | Evidence to archive |
| --- | --- | --- |
| `sh tools/habitat/test_env.sh` | focused-tested | exit 0: configured paths/defaults and missing-path diagnostics |
| `sh tools/habitat/test_verify.sh` | focused-tested | exit 0: structured parser, release guard, fresh-build and safe-output contracts; validates `bout-win` field assertion |
| `python3 tools/habitat/test_check_memory.py` | focused-tested | exit 0: 3 checks passed |
| focused ARM compile of the probe plus `src/battle_main.c` and `src/battle_setup.c` | focused-tested | exit 0 with `TESTING=1` / `HABITAT_TEST_PROBE=1`; includes the guarded battle terminal seam and callback assertion |
| `make check TESTS='Habitat verification probe'` | focused-tested | exit 0 on 2026-07-20; seven tests include a real `Habitat_BoutBegin` fixture that drives the production end-turn handler and `BattleMainCB1` through teardown before dispatching the saved habitat callback |
| `make -j4 check TESTS='Habitat'` | focused-tested (historical, pre-live-graphics-fix) | exit 0 on 2026-07-20; 105/105 Habitat tests passed |
| `make check` | attempted, not green | exit 2 on 2026-07-20: 4,941 passed, 18 unrelated battle/capture failures, 12 known-failing, 593 TODO, and 7 expected-failing tests |
| `make -j4` | built | exit 0 on 2026-07-20; EWRAM 227,880 B (86.93%), IWRAM 28,464 B (86.87%), ROM 26,483,532 B (78.93%) |
| `tools/habitat/verify.sh --no-interact` | headless-verified | `/private/tmp/hh-final-boot/`: Zorua lab overworld, frame 877 |
| `tools/habitat/verify.sh --scenario lab-campfire` | headless-verified | `/private/tmp/hh-final-lab-campfire/`: Torchic, frame 883 |
| `tools/habitat/verify.sh --scenario lab-plant` | headless-verified | `/private/tmp/hh-final-lab-plant/`: Treecko, frame 883 |
| `tools/habitat/verify.sh --scenario lab-basin` | headless-verified | `/private/tmp/hh-final-lab-basin/`: Mudkip, frame 883 |
| `tools/habitat/verify.sh --scenario starter-recovery` | headless-verified | `/private/tmp/hh-final-starter-recovery-serial/`: both unchosen starters through authored furnishings, frame 890 |
| `tools/habitat/verify.sh --scenario skitty` | headless-verified | `/private/tmp/hh-final-skitty/`: placement/offer/befriend, frame 886 |
| `tools/habitat/verify.sh --scenario machop` | headless-verified | `/private/tmp/hh-final-machop/`: Cheri transition with `bout_outcome=0`, frame 882 |
| `tools/habitat/verify.sh --scenario route103` | headless-verified | `/private/tmp/hh-final-route103/`: traversal without random battle, frame 4242 |
| `tools/habitat/verify.sh --scenario bout-win` | headless-verified | fresh `-B` run on 2026-07-20 exited 0; `/private/tmp/hh-bout-verify-final/result.txt` records outcome 1 at frame 1402, with `approved_bout_win_live.png`, `runner.log`, and `build.log` beside it |
| `tools/habitat/verify.sh --scenario bout-loss` | headless-verified | `/private/tmp/hh-final-bout-loss/`: live non-capture callback outcome 2, frame 1402 |
| `tools/habitat/verify.sh --scenario bout-flee` | headless-verified | `/private/tmp/hh-final-bout-flee/`: live non-capture callback outcome 3, frame 1402 |
| `tools/habitat/verify.sh --scenario bout-reset` | headless verified: `PASS Live bout reset recovered durable save (frame 2441, pos 6,10)` | save to flash before live bout, emulated-console reset, durable resident reload; `/private/tmp/hh-bout-reset-verify-clean/` |
| `tools/habitat/verify.sh --scenario save-migration` | headless-verified | `/private/tmp/hh-final-save-migration/`: legacy resident has stable origin, frame 881 |
| `tools/habitat/verify.sh --scenario save-persistence` | headless-verified | `/private/tmp/hh-final-save-persistence/`: flash round trip preserves resident, frame 882 |
| `tools/habitat/verify.sh --scenario grove` | headless-verified | `/private/tmp/hh-final-grove/`: worker visual checkpoint, frame 1420 |
| future item-chooser checkpoint (disabled) | pending native UI implementation | the Route 103 interaction currently shows placeholder dialogue and a yes/no prompt; it does not render an item-chooser view to capture |
| future approved-icons checkpoint (disabled) | pending native icon UI / release hold | the interaction does not render furnishing icons; the manifest also records six temporary question-mark icons, so this cannot be approved until Task 12 supplies art, provenance, and an icon-bearing surface |
| `python3 tools/habitat/check_memory.py --map pokeemerald.map` | focused-tested | exit 0 on 2026-07-20: EWRAM 227,880, IWRAM 28,460, ROM 26,483,532, SaveBlock3 1,308 bytes; all budgets pass |
| `tools/habitat/save_sizes.sh` | focused-tested | exit 0 on 2026-07-20: `SaveBlock3_total` 1,308 of 1,624 bytes |

## Intentional limits

The development command bridge exercises production item/condition, bout,
migration, flash-save/load, and Grove APIs and is absent from release builds.
The bout fixture is expressly non-finale (Treecko versus Zigzagoon). Its
win/loss/flee commands enter the normal battle scene and finish only through
the production end-turn state machine, resource teardown, and
`ReturnFromBattleToOverworld` callback. A development-only assertion verifies
`gMain.inBattle` is false, `callback1` is restored, and battle allocations are
released before `CB2_EndHabitatBoutBattle` records the structured outcome. The
runner captures the live scene before waiting for that outcome. The reset command saves through the normal
flash-sector path, begins the live bout without a finish task, and has the
runner reset the emulated console before checking the reloaded resident. The
chooser and icon checkpoints will enter real native Route 103 UI only after
those surfaces exist, then archive screenshots without inspecting message
bytes. Until then, they remain disabled rather than passing on placeholder
dialogue. Only the unauthored Deoxys story golden path remains exempt under
the plan.

The focused native lifecycle fixture is deliberately narrower than a rendered
bout: it starts the production Habitat bout boundary and uses the engine's
resource allocation, end-turn handler, `BattleMainCB1`, fade, teardown, and
return callback sequence. It suppresses only the test runner's unrelated
"turns specified" bookkeeping for that synthetic fixture; it does not claim a
headless live-scene capture. That evidence remains pending in the matrix above.

The future icon scenario will be a required visual capture, not a claim that
artwork is already approved: the live manifest still marks all six furnishing
icons as temporary and release-blocking. Once a native icon-bearing surface
exists, its screenshot will give Task 12's art review a stable checkpoint;
the provenance gate will remain red until approved source records and
replacements exist.

## Fresh-build limitation

The prior `make -B` verification attempt (before the live-bout/reload rewrite)
used `HH_VERIFY_OUT=/private/tmp/hh-task13-final` and `--scenario bout-win`.
The execution harness stopped it during generated asset compilation before the
runner began; its partial build log is retained at
`/private/tmp/hh-task13-final/build.log`. It is not evidence for the current
matrix. An interruption is not a build failure and is not headless evidence;
until a fresh invocation of the current build reaches the runner, every
scenario and visual checkpoint above remains **pending**. The focused evidence
is intentionally not promoted to headless-verified, visually reviewed,
full-suite-tested, or audit-accepted.

The fresh current-build `bout-win` invocation completed after that interruption:
`HH_VERIFY_OUT=/private/tmp/hh-bout-verify-final HH_VERIFY_JOBS=12
tools/habitat/verify.sh --scenario bout-win` exited 0. Its `result.txt` records
`PASS Live non-capture bout win returned through call (frame 1402, pos 6,10)`.
The later runs used the serial forced-build safeguard added in `687bee270`;
the rows above name their exact output directories. All currently implemented
portable scenarios now have fresh evidence. The two disabled UI checkpoints
remain pending their native surfaces and Task 12 approvals.

`validate_provenance.py --release` is expected to fail while Task 12 has
unapproved release provenance. Record that exit status as an intentional
release hold, never as a green acceptance result.

## Fresh terminal provenance

The fresh production-build and memory evidence above came from commit
`62c6fa1eea1a6499c6e62203814c037ab41900d9`, using Arm GNU Toolchain
14.2.Rel1 (GCC 14.2.1, 20241119) and mGBA 0.10.5
(`26b7884bc25a5933960f3cdcd98bac1ae14d42e2`).

## Lab habitat-bay visual correction

The original first-resident captures placed the resident beside foreground lab
furniture and provided no visible dormant habitat footprint. The approved
tilemap correction adds three persistent floor bays and separates dormant
interaction entrances from resident centers.

- `python3 tools/habitat/check_lab_layout.py`: passed; visible bays, resident
  positions, entrances, and aisle validated.
- `HH_VERIFY_OUT=/private/tmp/hh-lab-bays-boot tools/habitat/verify.sh --no-interact`:
  passed; `/private/tmp/hh-lab-bays-boot/zorua_lab_boot.png` (frame 877).
- `HH_VERIFY_OUT=/private/tmp/hh-lab-bays-campfire tools/habitat/verify.sh --scenario lab-campfire`:
  passed; `/private/tmp/hh-lab-bays-campfire/lab_campfire.png` (frame 883).
- `HH_VERIFY_OUT=/private/tmp/hh-lab-bays-plant tools/habitat/verify.sh --scenario lab-plant`:
  passed; `/private/tmp/hh-lab-bays-plant/lab_plant.png` (frame 883).
- `HH_VERIFY_OUT=/private/tmp/hh-lab-bays-basin tools/habitat/verify.sh --scenario lab-basin`:
  passed; `/private/tmp/hh-lab-bays-basin/lab_basin.png` (frame 883).
- `HH_VERIFY_OUT=/private/tmp/hh-lab-bays-recovery tools/habitat/verify.sh --scenario starter-recovery`:
  passed; `/private/tmp/hh-lab-bays-recovery/starter_recovery.png` (frame 890).
- `. tools/habitat/env.sh && make -j4 check TESTS='Habitat'`: passed 106/106.
- `sh tools/habitat/test_verify.sh`: passed; parser, release guard,
  fresh-build, and safe-output contracts pass.
- `git diff --check 48393a140..HEAD`: passed for the complete correction range.
- `git diff --check`: passed after restoring verifier-generated
  `src/data/pokemon/all_learnables.json` churn.

All images are native 240 x 160 GBA PNGs. The desktop preview renderer showed
spurious black tiles for several raw captures; ffmpeg re-encodes with
`-frames:v 1 -update 1` were reviewed at unique paths and Pillow confirmed
non-black room pixels at the affected coordinates. Final review copies are
`zorua_lab_boot_review_81620d347.png`,
`lab_campfire_review_81620d347.png`, `lab_plant_review_81620d347.png`,
`lab_basin_review_81620d347.png`, and
`starter_recovery_review_81620d347.png` alongside their canonical captures.
At the native camera, the left bay visibly groups the complete compact
bookshelf (x0-1), PC (x2-3), holder (x4), and open mat. The resident body is
unobstructed. All three bays and the central aisle remain readable. Torchic,
Treecko, and Mudkip are the real complete sprites in the left bay for their
respective first-habitat outcomes, and recovery shows the three distinct
residents in their three bay centers.

The live resident-graphics correction in `8f45b2da1` is a runtime fix. The
intermediate capture-settle commits `0f44f63ba1` and `7ad03714f` were reverted
by `6b6df219a` after the black appearance was proven to be a preview artifact,
not missing ROM or map graphics. The furnishing contract was completed in
`78d8432fc`, and `81620d347` moved that complete grouping into the native
camera. This evidence resolves the reported lab layout defect; it does not
approve pending narrative copy, furnishing icons, or their provenance.
