# Rule accessors & runtime-gate pattern (S13)

How gameplay code asks “is this rule on?” and how Phase 4+ converts a compile-time expansion config into a player-toggleable rule.

See also: ADR [0003](./decisions/0003-tech-runtime-rules-over-compile-time.md) (runtime over compile-time), ADR [0012](./decisions/0012-tech-rules-save-storage.md) (save layout), ADR [0013](./decisions/0013-tech-rules-accessor-null-defaults.md) (null defaults).

## API surface

| Call | Use when |
| ---- | -------- |
| `MfRules_HasFairyTypes()` (and other typed helpers in `include/mf_rules.h`) | Battle / overworld / hot paths — preferred |
| `MfRules_GetBool(MF_RULE_BOOL_…)` | Menus, debug, generic iteration over bool flags |
| `MfRules_GetValue(MF_RULE_VAL_…)` | Multi-bit fields (shiny chance, party limit, monotype, …) |
| `MfRules_GetActiveRules()` | Need several fields at once from the same active blob |
| `MfRules_GetSaveRules()` | **Writers only** (new-game init, rules menu, debug) — never for gameplay reads |
| `MfRules_TrySetBool` / `MfRules_TrySetValue` | Menu / debug writes that must honor the mid-run lock (ADR 0015) |
| `MfRules_CanEdit(MF_RULE_EDIT_…)` | Grey-out / read-only UI before attempting a write |
| `MfRules_CommitAndLock()` | New-game SAVE (S26); skip-menu path today via `InitNewGame` |

All gameplay reads go through `MfRules_GetActiveRules()` (directly or via helpers). Do not read `gSaveBlock3Ptr->mfRules` from battle/OW code.

## Mid-run lock (S15)

After `MfRules_CommitAndLock()`, `rulesLocked` is set. Writers:

- **Core** pages — refused
- **Difficulty** page — allowed only if `lockDifficulty` is off
- **Meta** (`rulesLocked`, `lockDifficulty`) — refused (debug override only)

Non-release builds can call `MfRules_DebugSetUnlockOverride(TRUE)` (debug menu **Rules inspector… → Meta → Unlock**, or any inspector edit which auto-enables it) to bypass for the session. Under `NDEBUG` / `make release` that API always fails closed. Details: [ADR 0015](./decisions/0015-product-rules-mid-run-lock.md).

## Null behavior

`MfRules_GetActiveRules()` returns `&gMfRulesPhase1Defaults` when:

1. **`MF_RULES_ENGINE` is compiled out** (`make … MF_CPPFLAGS='-DMF_RULES_ENGINE=0'`), or
2. **Save `version != MF_RULES_VERSION`** (pre-S12 flash junk, future unrecognized layout until S64 migrates).

Those defaults equal **vanilla Kanto progression + Phase 1 always-on modernization**:

- On: reusable TMs, survive poison, Gen4+ Sitrus, modern types / Fairy / stats / moves / type chart
- Off: randomizer, Nuzlocke, difficulty, challenges (`monotype == 31`)

A **valid** empty save (`version == MF_RULES_VERSION`, fields zeroed by `MfRules_ResetToEmpty`) is **not** null — accessors return Classic-like zeros. New games call `MfRules_InitNewGame()` (S14 / ADR 0014), which applies `MF_TX_*` defaults then the `MF_DEFAULT_GAMEMODE_PRESET` (default Modern), then `MfRules_CommitAndLock()` (S15 skip-menu; S19+S26 will defer lock to menu SAVE).

## Runtime-gate pattern (worked example)

Phase 1 left reusable TMs always on via `I_REUSABLE_TMS` in `include/config/item.h`. Phase 4 (S34) must make that a Gamemode toggle without forking the whole item table behind `#if`.

**Before (compile-time only):**

```c
// ItemUseCB_TMHM — importance already set from I_REUSABLE_TMS
if (item->importance == 0)
    RemoveBagItem(); // consume TM
```

**After (runtime gate — sketch for S34):**

```c
#include "mf_rules.h"

// Keep I_REUSABLE_TMS = TRUE so TM data can be reusable.
// Gate the *consume* step on the player's rule:
if (!MfRules_HasInfiniteTms())
    RemoveBagItem();
```

When the engine is off, `MfRules_HasInfiniteTms()` is TRUE (Phase 1). When the player picks Classic (S14), it is FALSE and TMs consume again — matching ME — without a second ROM build.

### Worked example: Fairy types (S27)

`P_UPDATED_TYPES` keeps modern Fairy assignments in `gSpeciesInfo`. `GetSpeciesType` calls `MfGetSpeciesType`, which applies a small pre-Gen-6 fallback table when `!MfRules_HasFairyTypes()`. Dex / summary / battle all use `GetSpeciesType`, so one gate covers every surface (ADR 0027).

### Worked example: modern types & TYPE CHART (S28)

`gSpeciesInfo` stays vanilla (plus Fairy-on). When `MfRules_HasModernTypes()`, `MfGetSpeciesType` overlays ME’s balance retypes (Arbok Poison/Dark, etc.). `GetTypeModifier` indexes `MfGetTypeEffectivenessTable()` — Gen VI+ (`gTypeEffectivenessTable`) or ME Improved — so the hot path is one rule check then a 2D lookup (ADR 0028).

### Worked example: modern base stats (S29)

`P_UPDATED_STATS` keeps Gen-latest values in `gSpeciesInfo`. `GetSpeciesBase*` / `GetSpeciesBaseStat` call `MfGetSpeciesBaseStat`, which returns those values when `MfRules_HasModernStats()`. When off, a compact classic table (Gen-3 / intro-gen `P_UPDATED_STATS` else-branches, binary-searched) supplies the original six. Modern-on is one rule check and no scan. Dex / summary / `CalculateMonStats` already go through the getters, so battle and UI stay consistent (ADR 0029).

### Worked example: modern movepools (S30)

`P_LVL_UP_LEARNSETS` stays `GEN_LATEST` in `gSpeciesInfo` (plus modern teachable/egg tables). `GetSpeciesLevelUpLearnset` / `GetSpeciesTeachableLearnset` / `GetSpeciesEggMoves` call `MfGetSpecies*`, which return those pointers when `MfRules_HasModernMoves()`. When off, FRLG classic tables (from `frlg.json`, binary-searched) supply level-up, TM/HM+tutor, and egg lists. Relearner, dex+, daycare, and `CanLearnTeachableMove` all go through the getters (ADR 0030).

### Rules for gates

1. Prefer an existing expansion primitive (`I_*`, `B_*`, `P_*`) as the capability baseline.
2. Add a one-line `MfRules_Has…()` / `MfRules_Get…()` check at the **behavior** call site, not a new `#if` fork of the whole system.
3. Never invent a player-facing `#define` for something the menu can toggle (ADR 0003).
4. Keep the check cheap: typed helpers are one pointer load + field access after `GetActiveRules`.

## Hot-path notes

- Typed helpers are `static inline` in the header; they call `MfRules_GetActiveRules()` once.
- `GetActiveRules` is a single version compare (or a compile-time constant pointer when the engine is off).
- Do not call `MfRules_GetBool` in damage loops when a typed helper exists — the switch is for menus/debug.

## Tests

```bash
make check -j$(sysctl -n hw.ncpu) TESTS='MF: rules'
```

Covers pack/unpack, every `GetBool` / `GetValue` against a patterned save, null path via bad `version`, and typed-helper agreement.
