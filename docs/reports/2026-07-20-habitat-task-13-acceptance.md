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
command exists. Fill each row with the command, exit status, commit hash,
tool version, and output directory from the actual run.

## Required evidence ledger

| Check | Status | Evidence to archive |
| --- | --- | --- |
| `sh tools/habitat/test_env.sh` | focused-tested | terminal log |
| `sh tools/habitat/test_verify.sh` | focused-tested | terminal log |
| `python3 tools/habitat/test_check_memory.py` | focused-tested | terminal log |
| `make check TESTS='Habitat verification probe'` | focused-tested | native result |
| `tools/habitat/verify.sh --no-interact` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario lab-campfire` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario lab-plant` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario lab-basin` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario starter-recovery` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario skitty` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario machop` | pending headless verification | output directory |
| `tools/habitat/verify.sh --scenario route103` | pending headless verification | output directory |
| `python3 tools/habitat/check_memory.py --map pokeemerald.map` | pending fresh measurement | JSON/log |
| `tools/habitat/save_sizes.sh` | pending fresh measurement | terminal log |

## Intentional limits

The development command bridge exercises approved item/condition transitions
through the production APIs and is absent from release builds. It does not
author Deoxys, a story battle, dialogue, or assets. Non-capture win/loss/flee
and reset-during-bout recovery remain covered by the native bout contract;
there is no approved finale scene to convert them into a player-facing golden
path. Save migration/persistence remains native-test coverage until a
serialized fresh-save fixture is explicitly approved.

`validate_provenance.py --release` is expected to fail while Task 12 has
unapproved release provenance. Record that exit status as an intentional
release hold, never as a green acceptance result.
