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

## [Unreleased] — Milestone 1 phase 2: Spot Framework

- Add the spec §2 HabitatSpot schema (authored fields verbatim + engine
  bindings), zone table, and the five §7 slice spots on Route 103 with
  loudly-placeholder text, currencies, and coordinates.
- Add the monotonic spot state machine (DORMANT→STIRRING→ACTIVE→BEFRIENDED),
  save accessors over SaveBlock3 (states, local flags, talk/placed counters;
  336 B), and befriend resolution (dex caught == befriended).
- Implement spot-local conditions: SPOT_STATE, BATTLE_WIN, ITEM_PLACED,
  TALK_COUNT, ZONE_COMPLETE, and BERRY_MATURE's zone filter.
- Wire event-driven recomputation: map load, hourly time tick, weather
  changes, scripted mon gives; live sprite spawn/despawn in the overworld.
- Slice spawn: new games start on Route 103 with a starter kit (behind
  HABITAT_SLICE_SPAWN); vanilla truck intro bypassed until the real intro.
- Spots are inspectable in every state: bg-sign under the spot object
  (signs answer while the Pokémon is unmanifested; the object takes over
  once visible). Staged hints via Habitat_OnInspectSpot(+ById).
- Add PLACE (any state; manifests spots, spec's approachability law) and
  OFFER (berry-bag round trip) verbs; befriending consumes the offered item.
- Remove the M0 throwaway truck test spot.
- hh-runner: scenario DSL driven by gStringVar4 text identity;
  `make verify` inspects Machop, `--scenario skitty` proves the full
  place→manifest→offer→befriend loop with screenshot evidence.
