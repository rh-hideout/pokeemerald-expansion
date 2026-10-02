# 0045 — Scaled EXP toggle

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-10-02
- **Story:** S70
- **ME reference:** — (Modern Emerald has no matching row)
- **Expansion config:** `B_SCALED_EXP` stays `GEN_LATEST`

## Context

Expansion Gen 9 scaled experience weights the reward by the gap between the receiver and the fainted Pokémon. That is compile-time today and is not a rules-menu option. Players who want the older flat formula (same Exp from the same foe at any level) had no way to turn it off. S70 adds that toggle without compiling `B_SCALED_EXP` off.

Existing saves already have the spare `paddingTail` byte at 0. A version bump would force S64 work for one bit.

## Decision

1. **Default is Off.** Off uses yield × fainted level / 7 and skips the Gen 5+ per-mon scaling table. On keeps the Gen 9 pool divisor (`/5`) and the level-gap weighting. `B_SCALED_EXP` remains `GEN_LATEST`; the two battle checks go through `MfIsScaledExpActive()`.
2. **Store the bit in `paddingTail` bit 0** as `scaledExp`. Do not reorder `ModernRules` or bump `MF_RULES_VERSION`. Existing saves read as Off.
3. **Menu:** Difficulty page Off/On row `SCALED EXP`, immediately after `EXP. MULTIPLIER`. Editable mid-run with the other Difficulty options unless LOCK DIFFICULTY is on. The S42 multiplier and HARD MODE EXP still apply either way.

## Alternatives considered

- Compile `B_SCALED_EXP` to Gen 3 — rejected. The story requires the config stay on; a compile-time cut cannot be toggled at new game.
- Default On to match expansion Gen 9 — rejected. The story sets Off so a default save matches the flat formula, and zeroed padding already means Off.
- New `ModernRules` field with a version bump — rejected. The spare byte is enough and keeps old saves readable.

## Consequences

- Default Modern/Classic runs no longer match the Gen 9 level-gap curve; they match the flat `/7` pool. Turn SCALED EXP On to restore expansion behavior.
- Upstream touch: `battle_script_commands.c` (the two `B_SCALED_EXP` sites).
- ADR 0044’s “scaled by level” default is superseded for new games.
