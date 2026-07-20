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
| `tools/habitat/verify.sh --no-interact` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario lab-campfire` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario lab-plant` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario lab-basin` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario starter-recovery` | pending headless verification | actual Bookshelf+Plant and PC+Ball Holder+Basin recovery chains; output directory |
| `tools/habitat/verify.sh --scenario skitty` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario machop` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario route103` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario bout-win` | headless-verified | fresh `-B` run on 2026-07-20 exited 0; `/private/tmp/hh-bout-verify-final/result.txt` records outcome 1 at frame 1402, with `approved_bout_win_live.png`, `runner.log`, and `build.log` beside it |
| `tools/habitat/verify.sh --scenario bout-loss` | pending headless verification | live non-capture battle screenshot, real callback outcome 2 |
| `tools/habitat/verify.sh --scenario bout-flee` | pending headless verification | live non-capture battle screenshot, real callback outcome 3 |
| `tools/habitat/verify.sh --scenario bout-reset` | headless verified: `PASS Live bout reset recovered durable save (frame 2441, pos 6,10)` | save to flash before live bout, emulated-console reset, durable resident reload; `/private/tmp/hh-bout-reset-verify-clean/` |
| `tools/habitat/verify.sh --scenario save-migration` | pending headless verification | legacy Machop-origin migration, screenshot |
| `tools/habitat/verify.sh --scenario save-persistence` | pending headless verification | `TrySavingData` sector write and `LoadGameSave` reload, screenshot |
| `tools/habitat/verify.sh --scenario grove` | pending visual review | Grove worker screenshot |
| future item-chooser checkpoint (disabled) | pending native UI implementation | the Route 103 interaction currently shows placeholder dialogue and a yes/no prompt; it does not render an item-chooser view to capture |
| future approved-icons checkpoint (disabled) | pending native icon UI / release hold | the interaction does not render furnishing icons; the manifest also records six temporary question-mark icons, so this cannot be approved until Task 12 supplies art, provenance, and an icon-bearing surface |
| `python3 tools/habitat/check_memory.py --map pokeemerald.map` | pending fresh measurement | JSON/log |
| `tools/habitat/save_sizes.sh` | pending fresh measurement | terminal log |

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
This verifies only the win row above; the remaining scenario matrix is still
pending.

`validate_provenance.py --release` is expected to fail while Task 12 has
unapproved release provenance. Record that exit status as an intentional
release hold, never as a green acceptance result.
