# 0035 — Solo trade evolutions always-on (bag use + Celadon stock)

- **Type:** product
- **Status:** Accepted
- **Date:** 2026-09-27
- **Story:** S69
- **ME reference:** Linking Cord / PLA-style bag evo items exist in expansion; ME has no separate Gamemode toggle for this
- **Expansion config:** `I_USE_EVO_HELD_ITEMS_FROM_BAG` → `TRUE` in `include/config/item.h`

## Context

S69 removes link-cable friction for trade and trade+held evolutions under the S08 Gen 1–3 (+ cross-gen) ceiling. Expansion already maps pure trade lines to `{EVO_ITEM, ITEM_LINKING_CORD}` and trade+held lines to `{EVO_ITEM, ITEM_*}` with `EVO_HELD_ITEM_*` macros gated by `I_USE_EVO_HELD_ITEMS_FROM_BAG` (default `FALSE`). The story allows either a Modern/Classic runtime gate or always-on; ME does not expose a matching toggle.

## Decision

1. **Always-on bag use** — set `I_USE_EVO_HELD_ITEMS_FROM_BAG` to `TRUE`. No new `ModernRules` bit and no Gamemode menu row. Linking Cord was already `ItemUseOutOfBattle_EvolutionStone`; held evo items (Metal Coat, King's Rock, etc.) now share that party-menu path.
2. **Celadon Dept Store 4F stock** — add Linking Cord plus every Kanto-relevant trade-held item to the existing Wise Man Gifts clerk (already sells evolution stones). No new maps/NPCs. List is always visible (unlike nature mints, which stay badge/rule-gated).
3. **Items stocked** (S08 coverage): `LINKING_CORD`, `METAL_COAT`, `KINGS_ROCK`, `DRAGON_SCALE`, `UPGRADE`, `DUBIOUS_DISC`, `PROTECTOR`, `ELECTIRIZER`, `MAGMARIZER`, `PRISM_SCALE`, `REAPER_CLOTH`, `DEEP_SEA_TOOTH`, `DEEP_SEA_SCALE`.
4. **S47 composition** — leave refusal to the future evo-limit hook in `GetEvolutionTargetSpecies` / bag CB; do not special-case S69 items here. Spot-check when S47 lands.

## Alternatives considered

- Runtime Gamemode bool (Modern on / Classic off) — rejected; ME has no equivalent option, adds save/menu surface for pure QoL, and Classic still benefits from solo play without a second device.
- Gate shop stock behind a rule or postgame like mints — rejected; acceptances require a normal playthrough path, and Celadon 4F is mid-game after Erika’s badge anyway.
- Stock only Linking Cord + Metal Coat — rejected; incomplete vs S08 trade lines (Kingdra, Electivire, Clamperl splits, etc.).

## Consequences

- Upstream `item.h` default flip is an `RHH/master` merge surface; re-apply if upstream stays `FALSE`.
- Players can buy high-price evo items mid-game (King's Rock / Linking Cord are expensive by design).
- Gen 6+ only trade items (Whipped Dream, Sachet) stay unstocked — those families are off.
- Config lock: `test/modern_firered/mf_item_baseline.c`. Manual QA: Celadon 4F + bag use on Haunter / Scyther.
