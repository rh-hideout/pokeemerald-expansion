# Modern FireRed — decision records

Short ADRs for non-trivial tech / product / UX choices. Upstream’s `docs/` is their mdbook; keep ours under `docs-mf/` to avoid merge collisions.

## Template

Create `NNNN-<type>-<slug>.md` with the next zero-padded `NNNN`. Types: `tech` | `product` | `ux`.

```markdown
# NNNN — <Title>

- **Type:** tech | product | ux
- **Status:** Accepted
- **Date:** YYYY-MM-DD
- **Story:** S## (or —)
- **ME reference:** <ME file or option> (or —)
- **Expansion config:** <macro + default> (or —)

## Context
Why a decision was needed; the forces at play.

## Decision
What was decided, stated plainly.

## Alternatives considered
- <option> — why not chosen.

## Consequences
Trade-offs, follow-ups, upstream-merge implications, and any affected stories or future work.
```

Append a row to the index below when you add a record.

## Index

| ID | Type | Title | Story | Date |
| -- | ---- | ----- | ----- | ---- |
| 0001 | tech | Track `.python-version` and document the FireRed toolchain in `BUILDING.md` | S01 | 2026-09-11 |
| 0002 | tech | Slim CI to FireRed + Emerald test suite | S02 | 2026-09-11 |
| 0003 | tech | Runtime rules layer over compile-time expansion configs | S03 | 2026-09-11 |
| 0004 | tech | MF_ config namespace via global.h | S04 | 2026-09-11 |
| 0005 | tech | MF debug submenu via public DebugMenuOption | S05 | 2026-09-11 |
| 0006 | tech | Emerald TESTELF for MF pure helpers; FR wiring stays manual | S06 | 2026-09-11 |
| 0007 | tech | Keep GEN_LATEST battle baseline (no Kanto downgrade) | S07 | 2026-09-11 |
| 0008 | product | Species families Gen 1–3 + cross-gen Kanto evolutions | S08 | 2026-09-11 |
| 0009 | ux | Summary screen IV/EV: always-on, raw values, tileset labels | S09 | 2026-09-12 |
| 0010 | product | Item QoL baseline: reusable TMs, held Exp Share, deferred mint shops, Gen4+ Sitrus | S10 | 2026-09-12 |
| 0011 | product | Battle & OW speed: no-slide intro, wait×8, Options text intact, Gen5+ poison | S11 | 2026-09-12 |
| 0012 | tech | Store ModernRules in SaveBlock3 | S12 | 2026-09-12 |
| 0013 | tech | Rule accessor null defaults = Phase 1 baseline | S13 | 2026-09-12 |
| 0014 | product | Classic / Modern / Custom gamemode preset tables | S14 | 2026-09-12 |
| 0015 | product | Rule immutability & mid-run lock semantics | S15 | 2026-09-12 |
| 0016 | tech | Deterministic randomizer seed service (not OT ID) | S16 | 2026-09-12 |
| 0017 | tech | Debug rules inspector via paged mf_debug menus | S17 | 2026-09-12 |
| 0018 | tech | Data-driven FR rules menu shell | S18 | 2026-09-12 |
| 0019 | tech | Rules menu after NewGameInitData, before overworld | S19 | 2026-09-12 |
| 0020 | ux | Gamemode page: ME order, no EXTRA LEGEND., Custom-gated edits | S20 | 2026-09-12 |
| 0021 | ux | Features page: FR subset and deliberate ME omissions | S21 | 2026-09-12 |
| 0022 | ux | Nuzlocke page: tier packing, Easy mini-mode gate | S22 | 2026-09-13 |
| 0023 | ux | Difficulty page: ME order, Yes/No item bans, clear PLAYER IVs labels | S23 | 2026-09-13 |
| 0024 | ux | Challenges page: ME order, monotype Off+types, gated PC heal / Mirror Thief | S24 | 2026-09-13 |
| 0025 | ux | Randomizer page: master gate, nested ME conditions, live clear/seed | S25 | 2026-09-13 |
| 0026 | ux | SAVE confirm + start-menu rules viewer | S26 | 2026-09-13 |
| 0027 | tech | Runtime Fairy retypes via GetSpeciesType fallback table | S27 | 2026-09-13 |
| 0028 | tech | Dual static type charts + modern-type overlay | S28 | 2026-09-14 |
