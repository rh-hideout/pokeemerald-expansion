# 0033 — Runtime SHINY CHANCE tiers over SHINY_ODDS

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-27
- **Story:** S33
- **ME reference:** `tx_Features_ShinyChance` + `IsShinyOtIdPersonality` / CreateBoxMon branches in ME `src/pokemon.c`; Features menu 8192…512 in `tx_rac_menu.c`
- **Expansion config:** `SHINY_ODDS` (`include/constants/pokemon.h`, default `8`); `I_SHINY_CHARM_ADDITIONAL_ROLLS` (`include/config/item.h`)

## Context

Features already stores `shinyChance` (0–4) and the rules menu offers ME’s five denominators (1/8192 … 1/512). Expansion rolls shinies with compile-time `SHINY_ODDS` inside `ComputePlayerShinyOdds`, while `MON_DATA_IS_SHINY` get/set XOR against that same constant via `shinyModifier`. Changing the comparison threshold at read time would flip existing Pokémon when the player’s rule changes. Shiny Charm already adds personality rerolls on top of the base threshold.

## Decision

1. **Tiers** match ME / S21 labels: `0`→8 (1/8192), `1`→16 (1/4096), `2`→32 (1/2048), `3`→64 (1/1024), `4`→128 (1/512), i.e. `SHINY_ODDS << shinyChance`. No separate “off” row.
2. **Generation** uses `MfGetShinyOddsThreshold()` from `mf_shiny.c` in `ComputePlayerShinyOdds` and the `OT_ID_PRESET` create path.
3. **Persistence** keeps compile-time `SHINY_ODDS` for `GetBoxMonData` / `SetBoxMonData` `MON_DATA_IS_SHINY` so stored shininess does not depend on the current Features tier.
4. **Shiny Charm (and lure / chain / DexNav)** still add rerolls; each roll compares against the runtime threshold (boosted base rate + charm, not charm-replacing-tier).
5. **S37 helpers:** `MfIsShinyValue` / `MfIsShinyOtIdPersonality` expose the same threshold for the Nuzlocke shiny clause; after creation, prefer `MON_DATA_IS_SHINY`.

## Alternatives considered

- Rewrite `IsShinyOtIdPersonality` display checks like ME — rejected; expansion’s `shinyModifier` already stores shininess independently of live odds.
- Replace charm rerolls with a multiplied threshold only — rejected; would drop charm/lure/chain/DexNav stacking already in expansion.
- Raw numeric odds in the menu — rejected; S21 / ME use five fixed denominators.

## Consequences

- Upstream touch is a small hook in `src/pokemon.c` only.
- Mid-run Features edits (debug unlock) affect **new** rolls only; existing party/box shinies stay put.
- S37 can reuse `MfIsShinyOtIdPersonality` without re-deriving tier math.
