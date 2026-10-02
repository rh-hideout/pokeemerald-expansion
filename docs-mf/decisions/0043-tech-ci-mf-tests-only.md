# 0043 — CI test gate is MF: tests only

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-30
- **Story:** —
- **ME reference:** —
- **Expansion config:** —

## Context

ADR 0002 kept expansion’s full `make check` as a required CI job. That runner is Emerald-only, and Phase 1 defaults turn on the Improved type chart and modern species typings. Upstream battle tests assume the stock Gen 6+ chart and vanilla types, so the suite fails (20 failures on the 2026-09-27 run) even when the FireRed ROM and `test/modern_firered/` tests are fine. This project ships FireRed; those expansion failures are not a product signal.

Modern FireRed unit tests already share that Emerald binary and use the `MF:` name prefix (ADR 0006).

## Decision

- CI’s `test` job runs `make check TESTS='MF:'` with `GAME_VERSION=EMERALD`.
- The `build` gate still depends on `build-firered` and `test`.
- Story definition of done uses the same filter. A full `make check` remains available locally and is not required.

## Alternatives considered

- Delete the `test` job — rejected; that also drops the `MF:` helpers (rules, chart, nuzlocke, shiny, party limit).
- Keep failing the gate on the full expansion suite — rejected; the failures are our defaults versus stock assumptions, and we do not treat that suite as the product.

## Consequences

- PRs go red when the FireRed ROM fails to build or an `MF:` test fails.
- Upstream battle regressions that do not touch `MF:` tests will not fail CI.
- ADR 0002 still describes the slim job matrix; this record narrows what `test` executes.
