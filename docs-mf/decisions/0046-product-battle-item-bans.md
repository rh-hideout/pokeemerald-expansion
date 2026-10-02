# 0046 — Battle item bans: Bag shown-and-refused, balls exempt

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-10-02
- **Story:** S43
- **ME reference:** `ItemMenu_UseInBattle` / `gText_BattleRules_NoItems_Player` in `src/item_menu.c`; `ShouldUseItem` in `src/battle_ai_switch_items.c`; `tx_Challenges_NoItemPlayer` / `tx_Challenges_NoItemTrainer`
- **Expansion config:** —

## Context

S43 wires Difficulty `PLAYER ITEMS` / `TRAINER ITEMS` (`noItemPlayer` / `noItemTrainer`). The story asked whether Bag is hidden or shown-and-refused, and required Poké Balls to stay legal. ME keeps Bag, refuses Use with a message unless the item is a ball, and stops AI items with an early `ShouldUseItem` return. ME’s Yes-row copy mentions a 4-item Hard Mode limit from `optionsDifficulty`; we have no matching Options Hard, and S42 already mapped “Hard” onto Level Cap Hard for EXP only.

## Decision

1. **Shown-and-refused.** Bag stays on the fight menu. Use of a banned item prints ME’s “Competitive rules! No items in battle!” and returns to the bag. Catching needs Bag, so hiding the option would be worse.
2. **Balls are exempt.** Ban uses `GetItemBattleUsage == EFFECT_ITEM_THROW_BALL` (ME compared the battle func to `ItemUseInBattle_PokeBall`). Held items are untouched.
3. **Trainer items.** `ShouldUseItem` returns FALSE when `noItemTrainer` is set. `HandleAction_UseItem` also skips a banned side so tests and forced actions cannot bypass the rule.
4. **No 4-item Hard Mode cap.** That is ME Options Hard, not this Difficulty row. Leave the existing Yes description as ME copy.
5. **No Hall of Fame auto-clear.** Unlike level-cap EXP, item bans stay until the player edits Difficulty (or debug). ME only cleared them via postgame specials.

## Alternatives considered

- Hide Bag — rejected; balls still need it, and the refusal message is clearer.
- Ban balls — rejected; catching would break (story constraint).
- ME’s 4-item Hard limit — rejected; no Options Hard, and the Difficulty Yes/No bit is a full ban or not.

## Consequences

- Upstream one-liners: `item_menu.c`, `item_use.c` (`CannotUseItemsInBattle` plus embargo fail text), `battle_pyramid_bag.c`, `battle_ai_items.c`, `battle_util.c` (`HandleAction_UseItem`), `party_menu.c` (party fail text uses `gStringVar4`).
- Hardcore Nuzlocke already seeds `noItemPlayer` (ADR 0040); this story is the enforcement.
- Helpers live in `mf_items.c` so merge cost stays at the call sites.
