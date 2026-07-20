# Task 2 implementer report

Implementation commit: `e6c37c837` (`fix: make habitat bouts transactional and non-capturable`).

Authorization correction commit: `ee013ccfb` (`fix: harden habitat finale authorization`).

Battle-action correction commit: `811e7966a` (`fix: guard habitat ball actions`).

Visible-rejection correction commit: `8c6ce522e` (`fix: show rejected habitat ball actions`).

No-net-consumption correction commit: `87e17ede7` (`fix: restore rejected habitat balls`).

## Changed files

- `include/habitat/bouts.h`, `src/habitat/bouts.c`, `test/habitat/bouts.c`: generic, non-nestable bout transaction backed by `SavePlayerParty`/`LoadPlayerParty`; byte-exact six-member restoration coverage for win, loss, flee, setup failure, and idempotent abort cleanup.
- `include/battle_setup.h`, `src/battle_setup.c`: generic bout battle start/end callback; all engine outcomes finish the transaction, and losses return to the calling script rather than whiteout.
- `include/config/habitat.h`, `src/item_use.c`, `src/battle_util.c`, `test/battle/item_effect/throw_ball.c`: `HABITAT_NO_CAPTURE`, shared ball rejection at both the Bag and battle-action boundaries, plus ordinary Bag-consumable single-use coverage.
- `include/habitat/finale.h`, `src/habitat/finale_data.c`: the sole dedicated Deoxys-finale completion flag, with no Deoxys combat, level, move, dialogue, choreography, reward, or runnable-encounter details.

## TDD evidence

- RED: `. tools/habitat/env.sh && make check TESTS='Habitat bout'` failed before implementation at link with undefined `Habitat_BoutBegin`, `Habitat_BoutFinish`, `Habitat_BoutIsActive`, and `Habitat_GetLastBoutOutcome` symbols.
- GREEN: `. tools/habitat/env.sh && make check TESTS='Habitat bout'` exited 0 after the transaction implementation.
- GREEN: `. tools/habitat/env.sh && make check TESTS='throw ball'` exited 0.
- GREEN: `. tools/habitat/env.sh && make check TESTS='Habitat spot'` exited 0.
- Additional focused check: `. tools/habitat/env.sh && make check TESTS='normal battle Bag consumables'` exited 0.

## Flag audit and remaining limitations

- `FLAG_UNUSED_0x036` was rejected after review because Grove workers use `0x036` through `0x03B`. A repo-wide search found `FLAG_UNUSED_0x047` unused outside its constants definition; the dedicated finale flag uses that value.
- The generic subsystem supports test-only definitions. The authored Deoxys finale remains intentionally non-runnable until approved encounter details are supplied.

## Authorization correction evidence

- Finale authorization now snapshots at `Habitat_BoutBegin`: the generic definition is copied by value, and a separate boolean is computed solely from pointer identity with `gHabitatDeoxysFinale.bout`. No async path retains caller-owned definition memory or trusts matching `boutId`/`winFlag` fields.
- The canonical Deoxys record has only its stable identity, species, and dedicated flag. Its levels and player-combat data remain unset, so `Habitat_BoutBegin(gHabitatDeoxysFinale.bout)` rejects it until an approved encounter definition exists.
- The new red-specification forged-definition test initially exposed an unrelated `-Werror=maybe-uninitialized` failure in the throw-ball test; initializing that local lets the full test ROM build. The habitat unit-test seam also explicitly resets the unrun battle-start task after direct lifecycle calls.
- The recorded-player test seam bypasses the Bag menu and directly selects the ball action. It exposed a real secondary capture path, now blocked in `HandleAction_UseItem` by the same categorical `CanThrowBall()` decision before `BattleScript_BallThrow` is selected. Its fallback uses a normal battle script with the existing neutral item-unavailable message rather than silently finishing the action.
- The focused test gives two literal Poké Balls. The recorder consumes one before action execution; this fallback restores exactly that pre-consumed ball before it shows the neutral rejection, so the test proves no net loss (two remain), the unavailable message, and no throw animation.
- `Habitat_BoutOutcomeFromBattleOutcome` is the helper used by the real battle callback and is covered for win, loss/draw/forfeit, flee/teleport/opponent-flee, and abort; the callback's loss field-return decision is covered through `Habitat_BoutReturnsToField`.
- GREEN: `. tools/habitat/env.sh && make check TESTS='Habitat bout'` passed 10/10.
- GREEN: `. tools/habitat/env.sh && make check TESTS='Habitat spot'` passed 8/8.
- GREEN: `. tools/habitat/env.sh && make check TESTS='Habitat: every throw ball'` passed 1/1.
- GREEN: `. tools/habitat/env.sh && make check TESTS='Habitat: normal battle Bag consumables'` passed 1/1.
