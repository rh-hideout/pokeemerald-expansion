# Changelog

All notable changes to Hoenn Habitat. Base: pokeemerald-expansion `expansion/1.16.2`.

## [Unreleased] — Milestone 0: Toolchain & Foundations

- Pin project base to pokeemerald-expansion tag `expansion/1.16.2`; add project README banner and legal stance.
- Add design spec v0.1 and Milestone 0 implementation plan under `docs/superpowers/`.
- Add headless mGBA verification harness (`make verify`): builds the ROM, boots it
  with SDL dummy drivers, quickstarts past the intro, confirms the overworld via
  `gMain.callback2`, and captures screenshots. (`tools/habitat/`)
- Add throwaway scripted test spot in the moving truck (sign at (1,0)) proving the
  map.json → event script → msgbox pipeline. Remove when the real spot framework lands.
- Add save-region measurement probes (`tools/habitat/save_probe.c`) — measurement
  only; no save layout changes in M0.

## [Unreleased] — Milestone 1 phase 1: Condition Engine

- Record M0-review design decisions (docs/design-notes.md); pin quickstart to
  Brendan as the slice placeholder body.
- Reserve `HabitatSave` (320 spot states + 8 talk counters, 328 B) in the
  expansion's SaveBlock3 region per the approved layout decision.
- Add the spec §2 condition engine: full 20-type vocabulary as const data,
  NEGATE + OR-group semantics, met-mask/anyMet outputs for staged hints.
  Implemented and native-tested this phase: ITEM_OFFERED, PARTY_SPECIES,
  PARTY_FRIENDSHIP, PARTY_MOVE, PARTY_NATURE, TIME_OF_DAY, WEATHER,
  STORY_FLAG, DEX_COUNT, BERRY_MATURE (any-zone), LIFETIME_STAT. Types
  backed by later-phase state evaluate unmet until then.
- Add `Habitat_NotifyEvent` interface (event-driven recomputation contract;
  spot manager subscribes in phase 2).
- Add designer-facing schema reference: docs/habitat/authoring-conditions.md.
