# 0002 — Slim CI to FireRed + Emerald test suite

- **Type:** tech
- **Status:** Accepted
- **Date:** 2026-09-11
- **Story:** S02
- **ME reference:** —
- **Expansion config:** —

## Context

Upstream `.github/workflows/build.yml` builds Emerald, FireRed, LeafGreen, a release ROM, and `make check`, then gates on a job named `build`. Modern FireRed only ships the FireRed ROM. Keeping unused targets burns CI minutes and widens the merge surface when RHH changes those jobs, without giving us a signal we look at.

Separately, expansion already compiles with `-Werror`, but local builds on forks demote unused/deprecated diagnostics unless `UNUSED_ERROR` / `DEPRECATED_ERROR` are set. Our `src/mf_*.c` sources should not inherit that loophole.

## Decision

- Keep **`build-firered`** (`make firered`) and **`test`** (`make check`).
- Keep the aggregate gate job **`build`** as the required branch-protection check; it depends only on those two.
- Drop **Emerald ROM**, **LeafGreen**, and **release** jobs from this fork’s workflow.
- Leave **`docs_validate`** and **`allcontributors`** alone (cheap; not part of the gate).
- Document in the workflow that `make check` targets **Emerald** (expansion’s TESTELF path), not FireRed.
- Add a Makefile pattern for `$(C_BUILDDIR)/mf_%.o` that re-elevates unused/deprecated to `-Werror=…` so Modern FireRed sources fail the build on those warnings even when local env softens them. CI already sets `UNUSED_ERROR=1` and `DEPRECATED_ERROR=1`.

## Alternatives considered

- Keep full upstream job matrix for merge friendliness — rejected; unused green checks are noise and the conflict cost is real when RHH edits those jobs.
- Require only `build-firered` (omit `test` from the gate) — rejected; S02 and S06 need the test suite as a permanent signal.
- Rename the gate job to `firered` — rejected; upstream’s branch-protection convention uses the check name `build`, and renaming forces a one-time settings change with no product benefit.
- Rely solely on CI `UNUSED_ERROR=1` for warning policy — rejected; agents and contributors build locally without that env; the `mf_%.o` rule closes the gap for our namespace.

## Consequences

- PRs go red when FireRed fails to build or `make check` fails. ADR 0043 later narrowed the `test` job to `TESTS='MF:'`; the full expansion suite is no longer a gate.
- Upstream merges that only touch Emerald/LeafGreen/release CI steps may conflict less often; when `build.yml` does conflict, prefer our slim matrix and re-apply any new shared install/cache steps from RHH.
- Branch protection should require the check named **`build`** (workflow display: `CI / build`).
- Future `src/mf_*.c` files inherit strict unused/deprecated errors without further CI edits.
