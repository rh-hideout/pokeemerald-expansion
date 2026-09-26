# 0031 — Runtime Gamemode item & ability behavior gates

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-26
- **Story:** S31
- **ME reference:** `tx_Mode_InfiniteTMs` / `PoisonSurvive` / `Synchronize` / `Mints` / `New_Citrus` / `Sturdy` in ME `tx_rac_menu.c` + call sites
- **Expansion config:** keep `I_REUSABLE_TMS`, `I_SITRUS_BERRY_HEAL`, `B_STURDY`, `OW_SYNCHRONIZE_NATURE`, `B_SYNCHRONIZE_TOXIC`, `OW_POISON_DAMAGE` at Phase 1 baselines; runtime via `MfRules_Has*`

## Context

S31 makes six Gamemode bools change live behavior. Phase 1 left them always-on via compile configs. ME forks each call site on save flags. We already have typed accessors; the work is identical one-line gates at the behavior sites without forking item/species tables behind `#if`.

ADR 0010/0011 deferred these gates to a later story (then numbered S34); S31 is the owner.

## Decision

1. **Reusable TMs** — leave `.importance = I_REUSABLE_TMS` on TM data. `GetItemImportance` returns 0 for TMs when `!MfRules_HasInfiniteTms()` so consume paths (party menu, relearner) keep working; HMs stay importance 1.
2. **Sitrus** — keep Gen4+ data in `gItemsInfo`. When `!MfRules_HasModernSitrus()`, `GetItemHoldEffect` / Param / Effect / Description return Gen3 flat-30 behavior (ME New Citrus Off).
3. **Sturdy** — Gen5+ endure-at-1HP checks also require `MfRules_HasSturdy()`. OHKO immunity stays always-on (Gen3 Sturdy).
4. **Synchronize** — `GetSynchronizedNature` picks Gen3 (50% wild) vs Gen8+ (100% wild/roamer) tables from `MfRules_HasSynchronize()`. Battle toxic pass-through uses the same bool (`!HasSynchronize` → toxic becomes poison).
5. **Survive poison** — always compile OW poison step counter (ignore `OW_POISON_DAMAGE < GEN_5` compile-out). On = Gen4 survive at 1 HP + clear poison (matches menu copy / ME); Off = Gen3 can faint. Dropped Phase 1 Gen5+ “no damage” for the On state so the toggle matches player-facing text.
6. **Nature mints** — stock all mints on Celadon Dept Store 2F item clerk. `IsItemShopCriteriaFulfilled` hides them unless `MfAreNatureMintsBuyable()`: rule On → after `FLAG_BADGE04_GET`; rule Off → after `FLAG_SYS_GAME_CLEAR` (ME postgame fallback). No new maps/NPCs.
7. **Phase 1 null defaults** — set `synchronize` and `sturdy` TRUE so engine-off / bad-version fallbacks keep the GEN_LATEST compile baselines (S07). Mints stay off. Classic preset still forces them off.

## Alternatives considered

- Gen5+ “no OW poison damage” for Survive On — rejected; menu and ME say survive at 1 HP.
- Gate mint bag use when scarce — rejected; ME only gates shop stock; debug Give Item still works for QA.
- Dual Sitrus item IDs like ME’s `SanitizeItemId` remap — rejected; getter overrides are smaller and already the item API.

## Consequences

- Upstream `field_control_avatar.c` / `field_poison.c` / `item.c` / battle sturdy sites are merge surfaces — re-apply the one-line gates after `RHH/master`.
- Survive On is slightly harsher than the old Gen5+ baseline (damage ticks until 1 HP).
- Mint shop list is always in the Celadon script; visibility is criteria-filtered so Classic pre-clear sees the vanilla item list.
