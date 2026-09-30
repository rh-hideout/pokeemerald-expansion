# 0039 — Nuzlocke forced nicknaming (ME NICKNAMES)

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-09-29
- **Story:** S38
- **ME reference:** `IsNuzlockeNicknamingActive`, `Cmd_trygivecaughtmonnick`, `KeyboardKeyHandler_OK`, egg-hatch nickname states in `resetes12/pokeemerald`
- **Expansion config:** `MF_NUZLOCKE`; runtime `nuzlockeNicknaming` (`MF_TX_NUZLOCKE_NICKNAMING` default TRUE)

## Context

S38 needs ME's `NICKNAMES` rule: when Nuzlocke (Normal/Hardcore) has nicknaming on, every catch must go through the naming screen, and an empty name must be refused. The rules menu and save bit already exist (S22/S13); gameplay wiring does not. ME also forces nicknames on egg hatch via the same helper.

## Decision

1. **Helper** `MfNuzlocke_IsNicknamingActive()` mirrors ME: `nuzlocke && nuzlockeNicknaming && !FLAG_SYS_GAME_CLEAR`. Easy mini-mode keeps `nuzlocke` false (and clears the nicknaming bit), so it never forces. Post–Elite Four (`FLAG_SYS_GAME_CLEAR`) matches our other Nuzlocke gates (ME's `FLAG_IS_CHAMPION`).
2. **Catch path:** `Cmd_trygivecaughtmonnick` skips the Yes/No box and jumps straight to the naming fade when active. With the rule off, vanilla optional Yes/No is unchanged.
3. **Empty name:** `KeyboardKeyHandler_OK` ignores OK while nicknaming is active and the text buffer is empty (`GetTextEntryPosition() == 0`). Keeping the species default name is allowed (caret past char 0).
4. **Egg hatch:** same force path as ME (skip prompt / Yes/No, open naming). Same helper, so catch and hatch stay consistent.

## Alternatives considered

- **Force only on wild catch, not eggs** — rejected; ME wires hatch and it is the same NICKNAMES option.
- **Change the battle string to mandatory copy** — rejected; keep ME's existing “Would you like…” print then auto-advance into naming.
- **Block summary-screen rename / allow empty after clear** — out of scope; game-clear already disables the force.

## Consequences

- Upstream touches: `battle_script_commands.c`, `naming_screen.c`, `egg_hatch.c` — each a one-call hook into `mf_nuzlocke`.
- S39 tier bundles can keep defaulting NICKNAMES on via `MF_TX_NUZLOCKE_NICKNAMING`.
- Gifts/statics that never open the catch nickname flow are unchanged (same as ME).
