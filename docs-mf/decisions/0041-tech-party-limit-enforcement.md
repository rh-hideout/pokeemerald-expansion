# 0041 — Party limit: enforce on add paths without capping CalculatePlayerPartyCount

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-30
- **Story:** S40
- **ME reference:** `GetMaxPartySize()` / `tx_Challenges_PartyLimit` in `src/tx_randomizer_and_challenges.c`; PC + `GiveMonToPlayer` call sites
- **Expansion config:** —

## Context

ME caps `CalculatePlayerPartyCount` at `GetMaxPartySize()` and rewrites PC party cursor navigation so slots beyond the limit are unreachable. Difficulty can still be edited mid-run when `lockDifficulty` is off (ADR 0015), so a player who lowers the limit with a larger party would have live mons that a capped count / hidden slots would ignore in battle and the PC.

## Decision

1. **Keep `CalculatePlayerPartyCount` honest** — it still counts every occupied party slot up to `PARTY_SIZE`. Battles and menus always see the real party.
2. **Enforce only on add paths** via `MfGetMaxPartySize()` / `MfIsPlayerPartyAtLimit()` (`mf_party.c`):
   - Catch / gift: `GiveCapturedMonToPlayer` / `GiveScriptedMonToPlayer` send overflow to the PC (existing transfer messages).
   - PC withdraw / place into empty party slot: refuse with “Your party is full!”.
   - Daycare retrieve / egg give: C hard-guard + script compares against `MfGetMaxPartySize`.
   - Fusion unfuse / mystery event / safari “any room” checks: same limit helper.
3. **Do not hide PC party slots** beyond the limit (ME cursor rewrite skipped) so mid-run downsizing still allows depositing extras.

## Alternatives considered

- Cap `CalculatePlayerPartyCount` like ME — rejected; breaks mid-run limit edits and can desync battles from the actual party.
- Hide PC slots past the limit — rejected for the same mid-run deposit reason; count checks are enough.

## Consequences

- Gift scripts that only compared to `PARTY_SIZE` were patched (FR daycare/egg/safari + Hoenn leftovers) to use `MfGetMaxPartySize` / `MfIsPlayerPartyAtLimit`.
- Catch-at-limit still uses the normal “sent to PC” flow rather than a hard refuse.
- If a party already exceeds the limit, adds are blocked until the player deposits; existing mons remain usable.
