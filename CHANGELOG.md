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

## [Unreleased] — Milestone 1 phase 5: Lab Opening & Slice Wiring (2026-07-19)

- Six §10 furnishing items (campfire/plant/basin + PC/bookshelf/ball holder).
- Placement counters are per-(spot, condition) — multi-furnishing frames.
- Lab frame spots (Torchic/Treecko/Mudkip) with auto-befriend on completion;
  spawn moved into the abandoned lab; vanilla story cast hidden in-slice.
- Machop's friendly bout: borrowed-resident battler, win sets BATTLE_WIN,
  recompute auto-befriends (native-tested).
- Scavenge finds (bookshelf/PC/ball holder) on Route 103.
- Runner: walk/until-map ops, Y-first goto (face-tap stepping fix).
- Resolved the headless recruit-dialogue "hang": the game was never at fault —
  the runner's dismissal taps stopped too early for the final waitbuttonpress.
  Human-cadence A-taps after dismiss-until fix it; richer fail-path
  diagnostics kept in the runner. Hardened along the way (kept on purpose):
  recruit dialogue completes before any state mutation
  (Habitat_CanRecruitToGrove pre-check + post-release Habitat_TryRecruitToGrove),
  and live-object sync never removes the locked talked-to object mid-script.
- Relocate Grove plots/workers out of Littleroot's southern tree wall
  (plots (12,13)–(14,13), workers (11,12)–(16,12)) — found via manual play.
- `make verify` now runs the full §10→Grove circuit headlessly: place
  campfire → Torchic manifests + auto-befriends → recruit → walk to the
  Grove → Torchic's worker status confirms at the row (screenshot evidence).
  Route 103 scenarios re-route with phase 6's acceptance circuit.

## [Unreleased] — Milestone 1 phase 4: The Grove (2026-07-19)

- Grove core on the Littleroot placeholder map: 12-plot save array (slice
  renders 3), §4 type-berry table as engine data, event-driven growth with
  offline RTC reconcile, harvest to bag, six-out cap, home/out sprite sync
  completing §3's home-by-default law.
- Diegetic flows: recruit at the home spot ("come tend the Grove?"), worker
  status/rest dialogue at the Grove, plot inspect/harvest. Worker sprites use
  var-gfx template objects (slots A–F); placeholder prose in the §7 register.
- In-game Grove click-through lands with phase 5's spawn move to Littleroot
  (the lab); all Grove logic is native-tested now and Route 103 scenarios
  stay green.

## [Unreleased] — Milestone 1 phase 3.5: Spec v0.1-rev Recast (2026-07-19)

- Recast slice data to the §4 type-berry economy (Sleep mapping, verified
  against references): Vulpix wants Leppa, Skitty Persim, Lotad Oran,
  Heracross/Pinsir Lum. No new items needed.
- Lotad appear now keys on resident Treecko (party layer deferred; engine
  keeps PARTY_SPECIES for the future).
- Add the sixth slice spot: Pinsir (sap-log stated want, ITEM_HONEY
  placeholder) — feeds Heracross's chain in-slice.
- Home-by-default rendering (§3): befriended spots keep their sprite,
  STAY_AMBIENT flag dissolved; "out at the Grove" subtraction lands phase 4.
- Reserve HABITAT_COND_EXACT_STAGE (§9 anti-regret); add per-map spot
  density check (§3 budget law); trim dev kit (pouch auto-sorts by id —
  first-slot determinism needs a single kit berry kind).

## [Unreleased] — Milestone 1 phase 3: Resident Registry

- Add the spec §5 resident registry: 96 individualized residents (species,
  personality seed, Grove assignment byte) created on befriend; SaveBlock3
  now 720 of 1,624 B.
- Implement RESIDENT_SPECIES and RESIDENT_COUNT (type-filtered) — dex-backed
  so past-cap residents still count for conditions per spec §5. Heracross's
  chain (resident Pinsir + night + mature sap tree) proven in native tests.
