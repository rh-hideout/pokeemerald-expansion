# 0034 — Wild ITEM DROP via battle-end held-item grant

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-27
- **Story:** S34
- **ME reference:** `tx_Features_WildMonDropItems` + `VARIOUS_GIVE_DROPPED_ITEMS` / `BattleScript_ItemDropped` in ME `battle_script_commands.c` / `battle_scripts_1.s`
- **Expansion config:** — (uses existing `SetWildMonHeldItem` rates; Features bool `wildItemDrops`)

## Context

Features already stores `wildItemDrops` and the rules menu exposes ITEM DROP Off/On (S21). ME grants the wild foe’s hold item into the bag on victory with a short battle message, using a faint-time snapshot so consumed berries do not drop. Expansion already rolls wild held items in `SetWildMonHeldItem` and tracks `itemLost.originalItem`, but had no drop path.

## Decision

1. **Source of the drop** — the foe’s **remaining** held item at battle end (`gParties[B_TRAINER_OPPONENT_A]` / `gBattleMons`), not a separate drop table and not `originalItem`. Consumed berries and stolen items yield nothing (ME-aligned).
2. **Delivery** — auto-`AddBagItem` with an in-battle prompt (“dropped its …” / “Bag is full”). No confirmation yes/no. Bag-full still clears the candidate so the item is lost (ME behavior).
3. **Hook** — `callnative BS_TryGiveWildItemDrops` on `BattleScript_PayDayMoneyAndPickUpItems` (wild win path only). Logic lives in `mf_item_drops.c`; selection helpers are unit-tested.
4. **RNG** — no extra roll and no S16 seed use. Drop frequency equals existing wild held-item odds (~50% none / ~45% common / ~5% rare, or 100% when common==rare).
5. **Exclusions** — trainer, first-battle, Safari, ghost, link, Frontier, e-Reader battles never drop.

## Alternatives considered

- Grant `itemLost.originalItem` even after berry consume — rejected; ME and the menu copy say “hold item,” and Thief would not recover a consumed berry either.
- Silent bag add with no battle text — rejected; ME’s prompt is the expected Features UX.
- Seeded separate drop table — rejected; story allows held-item data; duplicating rates adds merge surface for no product gain.

## Consequences

- Upstream touch points: `data/battle_scripts_1.s` (one native + message script), two `STRINGID_*` + `gBattleStringsTable` rows, `battle_scripts.h` extern.
- Mid-run Features toggle (debug unlock) affects the next wild win only.
- Doubles: native re-enters after each message so both foes can drop.
