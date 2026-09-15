# 0010 — Item & progression QoL baseline (TMs, Exp Share, mints, Sitrus)

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-09-12
- **Story:** S10
- **ME reference:** Gamemode `REUSABLE TMS`, `NATURE MINTS`, `SITRUS BERRY` (`tx_rac_menu.c`); Pretty Petal mint shop when `tx_Mode_Mints` / `FLAG_MINTS_ENABLED`
- **Expansion config:** `I_REUSABLE_TMS`, `I_EXP_SHARE_ITEM`, `I_EXP_SHARE_FLAG`, `I_SITRUS_BERRY_HEAL` in `include/config/item.h`

## Context

Phase 1 removes the most-felt vanilla item friction before the rules engine can toggle the same behaviors. Expansion already implements reusable TMs, Gen6+ party-wide Exp Share (flag-gated), nature mints as usable items, and Gen-split Sitrus healing. S10 must flip what belongs always-on now, and record choices that affect Phase 7 (EXP multiplier) and S34 (Gamemode gates).

Story text assumed `I_EXP_SHARE_ITEM` was `GEN_LATEST`; this tree already has `GEN_5` (held-item Exp Share) with `I_EXP_SHARE_FLAG` at `0`.

## Decision

- **Reusable TMs:** set `I_REUSABLE_TMS` to `TRUE`. All vanilla TMs use `.importance = I_REUSABLE_TMS`, so teaching a move no longer consumes the TM (`ItemUseCB_TMHM` skips `RemoveBagItem` when importance is set).
- **Exp Share:** keep **Gen 5 held-item** behavior — leave `I_EXP_SHARE_ITEM` at `GEN_5` and `I_EXP_SHARE_FLAG` at `0`. Do **not** enable Gen6+ party-wide Exp Share in Phase 1. FireRed already awards a held Exp. Share via Oak’s aide; Gen6 mode needs a persistent unused flag, turns the item into a Key Item toggle, and changes how Phase 7’s EXP multiplier should feel.
- **Nature mints:** items `ITEM_LONELY_MINT`–`ITEM_SERIOUS_MINT` and `ItemUseOutOfBattle_Mint` / `ItemUseCB_Mint` are present and usable from the bag. Expansion applies mints to `MON_DATA_HIDDEN_NATURE` (stats) while personality nature stays for breeding/flavors. **Summary nature name shows the mint/hidden nature** (`BufferNatureString` → `mintNature`) so players see e.g. Adamant after an Adamant Mint; mint confirm/done text names the target nature (ME-style). **No map or story edits in S10.** In-world shop stock is deferred to **S34** (Gamemode `NATURE MINTS`), targeting a Celadon florist / Dept Store stock list gated like ME’s Pretty Petal (after badge threshold when Modern/on). Until then, obtainability for QA is debug **Give item XYZ…**.
- **Sitrus:** leave `I_SITRUS_BERRY_HEAL` at `GEN_LATEST` (≥ Gen 4). Actual code path: held `HOLD_EFFECT_RESTORE_PCT_HP` at 25% and bag/battle `ITEM6_HEAL_HP_QUARTER` — matching ME’s “New Citrus” On (not the inverted comment on the config line). Noted as a future Gamemode toggle in S34; no Phase 1 change.

## Alternatives considered

- Gen6+ party-wide Exp Share with an unused FR flag — rejected for Phase 1; softens early game heavily and couples awkwardly to Difficulty EXP work before that UI exists.
- Stock mints in Celadon scripts now — rejected; story forbids map/story edits here, and S34 must gate availability by Gamemode anyway.
- Downgrade Sitrus to Gen 3 (flat 30 HP) for FRLG authenticity — rejected; conflicts with Phase 1 modern baseline and ME Modern’s New Citrus On.

## Consequences

- Editing upstream `item.h` (`I_REUSABLE_TMS`) is a known `RHH/master` merge surface; re-apply if upstream flips the default.
- S34 must runtime-gate reusable TMs, Sitrus heal mode, and mint shop visibility without assuming Gen6 Exp Share is on.
- Solo trade-evo obtainability (Linking Cord mart stock + `I_USE_EVO_HELD_ITEMS_FROM_BAG`) is **S69**, not S10.
- Phase 7 EXP multiplier should assume held Exp Share only unless a later story deliberately enables `I_EXP_SHARE_FLAG`.
- Config lock: `test/modern_firered/mf_item_baseline.c`. Manual TM reuse: [`docs-mf/manual-qa-s10-item-qol.md`](../manual-qa-s10-item-qol.md).
