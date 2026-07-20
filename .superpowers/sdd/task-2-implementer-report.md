# Task 2 implementer report

Implementation commit: `e6c37c837` (`fix: make habitat bouts transactional and non-capturable`).

## Changed files

- `include/habitat/bouts.h`, `src/habitat/bouts.c`, `test/habitat/bouts.c`: generic, non-nestable bout transaction backed by `SavePlayerParty`/`LoadPlayerParty`; byte-exact six-member restoration coverage for win, loss, flee, setup failure, and idempotent abort cleanup.
- `include/battle_setup.h`, `src/battle_setup.c`: generic bout battle start/end callback; all engine outcomes finish the transaction, and losses return to the calling script rather than whiteout.
- `include/config/habitat.h`, `src/item_use.c`, `test/battle/item_effect/throw_ball.c`: `HABITAT_NO_CAPTURE`, shared ball boundary rejection for every ball, and ordinary Bag-consumable single-use coverage.
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
