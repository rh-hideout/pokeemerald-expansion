# Design Decisions Log

Running log of decisions made between spec revisions. The spec remains the
contract; entries here are its amendments-in-waiting.

## 2026-07-18 — M0 review (Jay)

- **Save layout:** `HabitatSave` lives in SaveBlock3 (expansion extension
  region, 1,620 B free at M0). The Secret Base slab (3,200 B in SaveBlock1)
  stays untouched, banked as the scale-out reservoir.
- **Player body:** quickstart pinned to Brendan as slice placeholder. The real
  intro's character select becomes the Zorua choosing its illusion — BOTH body
  sprite sets remain in-game as masks. Engine constraint: never architect
  against a single fixed player body (no Brendan-only assumptions in save
  data, sprites, or scripts).
- **Text:** hint/story prose is authored by Jay. Engine ships obviously-
  placeholder text.
- **Budget watch:** EWRAM (86.4 % at M0 baseline) is the scarce resource when
  sizing structures, not save space.
