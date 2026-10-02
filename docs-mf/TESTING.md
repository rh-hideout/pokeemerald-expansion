# Testing Modern FireRed

How rules and helper logic get automated coverage, and when manual QA is required.

## What `make check` covers

Expansion’s test runner (`TESTELF` / `make check` / mGBA headless hydra) builds and runs against the **Emerald** game version (`GAME_VERSION=EMERALD`). CI’s `test` job uses that binary but only runs tests whose names start with `MF:` (ADR 0043).

| Covered well | Not covered by `make check` |
| ------------ | --------------------------- |
| Pure helpers in `src/mf_*.c` / `include/mf_*.h` (math, seed mapping, pack/unpack, accessors with controlled inputs) | FireRed-only maps, scripts, heal locations, FR window/menu layout |
| Expansion battle/engine regressions that share Emerald + FR code | Anything gated on `FIRERED` / FR constants that differ from Emerald |
| Our tests under `test/modern_firered/` (linked into the Emerald TESTELF) | End-to-end “does this rule change overworld behavior in Kanto?” |

`src/mf_*.c` is still compiled into the Emerald TESTELF (Makefile wildcards all of `src/`), so **keep rules logic Emerald-safe** (no FR-only `#ifdef` walls around the pure helpers themselves). Put FR-only UI/wiring behind thin call sites and cover those by hand.

Do **not** use `make firered check` for the suite: the `firered` goal flips `GAME_VERSION` to `FIRERED`, which is not the supported TESTELF path. Use:

```bash
make check -j$(sysctl -n hw.ncpu)
```

After switching between FireRed ROM builds and the Emerald test build in the same tree, `make clean` first if objects look wrong (same hazard as Emerald↔FireRed ROM builds — see `BUILDING.md`).

## Where our tests live

| Kind | Path | Naming |
| ---- | ---- | ------ |
| Modern FireRed unit tests | `test/modern_firered/*.c` | One file per `mf_` module or concern (`mf_version.c`, `mf_rules.c`, `mf_random.c`, …) |
| Upstream expansion tests | `test/` (and subdirs) | Leave alone; merge cost |

Makefile already picks up `test/*/*.c`, so `test/modern_firered/` needs no Makefile change.

### Convention for pure helpers

1. Implement testable logic in `include/mf_*.h` / `src/mf_*.c` (no map IDs, no FR-only script hooks).
2. Add `TEST("…")` cases in `test/modern_firered/` using `include/test/test.h` (`EXPECT_*`, `PARAMETRIZE`, etc.).
3. Prefer deterministic inputs; for randomness, go through the S16 seeded service (`mf_random.h` / ADR 0016) — never call `Random()` directly in rules or randomizer mapping tests.
4. If a story only wires gameplay (encounter hooks, faint deletion, FR menus), leave a filled-in copy of the [manual QA template](./manual-qa-template.md) in that story’s Tests / acceptance notes — do not pretend `make check` covered it.

Sample smoke test: `test/modern_firered/mf_version.c` (asserts `MF_VERSION` is reachable from the Emerald TESTELF).

## Filtering

CI and local iteration both use the `MF:` name prefix:

```bash
make check -j$(sysctl -n hw.ncpu) TESTS='MF:'
```

(Exact filter strings match test **names**, not filenames — name MF tests with a stable prefix such as `MF:`.)

`make check` with no `TESTS` still runs the full expansion suite. That suite is not a CI gate. It assumes the stock type chart and vanilla species, so Phase 1 defaults (Improved chart, modern typings) fail upstream battle tests.

## Related

- Manual QA template: [`manual-qa-template.md`](./manual-qa-template.md)
- S09 summary IV/EV checklist: [`manual-qa-s09-summary-iv-ev.md`](./manual-qa-s09-summary-iv-ev.md)
- S10 item QoL checklist: [`manual-qa-s10-item-qol.md`](./manual-qa-s10-item-qol.md)
- S11 battle/OW speed checklist: [`manual-qa-s11-battle-ow-speed.md`](./manual-qa-s11-battle-ow-speed.md)
- S12 rules save storage checklist: [`manual-qa-s12-rules-storage.md`](./manual-qa-s12-rules-storage.md)
- S13 rule accessors & runtime-gate pattern: [`RULES_ACCESSORS.md`](./RULES_ACCESSORS.md)
- Phase 1 battle config inventory: [`BATTLE_BASELINE.md`](./BATTLE_BASELINE.md)
- Phase 1 species / movepool availability: [`SPECIES_BASELINE.md`](./SPECIES_BASELINE.md)
- CI layout: ADR 0002, `.github/workflows/build.yml`
- Debug / fast iteration: [`DEBUG.md`](./DEBUG.md)
