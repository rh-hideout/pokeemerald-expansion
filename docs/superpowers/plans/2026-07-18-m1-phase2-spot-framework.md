# M1 Phase 2: Spot Framework Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: superpowers:subagent-driven-development or superpowers:executing-plans. Inline execution chosen (same serial/stateful rationale as prior phases).

**Goal:** Spec §2's HabitatSpot table and DORMANT→STIRRING→ACTIVE→BEFRIENDED machine running against real save state, with event-driven recomputation, spot-local conditions, staged hints, place/offer verbs, and the five slice spots present on Route 103 as flag-gated species overworld sprites — native tests for all logic, hh-runner for the overworld loop.

**Architecture:** Two waves. **2a (Tasks 1–5):** pure engine — spot table schema + slice records, save accessors, monotonic state machine, spot-local conditions, event call-site wiring, slice spawn. Everything native-testable. **2b (Tasks 6–7):** overworld presence — map objects, interact script via `special` dispatch (berry-tree pattern), verbs, befriend resolution, hh-runner scenario. Sprites use the expansion's `OBJ_EVENT_GFX_SPECIES(x)` follower graphics; visibility uses standard flag-gated object events (no polling; flags sync on state change + map load).

**Key mechanics decided here (batch-report to Jay):**
- Transitions are **monotonic** (spec: ACTIVE "persists indefinitely") — appear conditions lapsing never regress a spot.
- The C spot record carries **engine-only binding fields** (hide-flag, map/localId, spot flags) after the spec §2 authored fields; Jay's authoring surface is unchanged.
- **Slice spawn:** new games warp to Route 103 (the slice zone) instead of the truck, behind `HABITAT_SLICE_SPAWN` in `config/habitat.h` — the vanilla intro isn't this game, and it makes the slice playable/verifiable immediately. Trivially revertible when the real intro lands.
- ITEM_PLACED persistence: `placedCounters[8]` (u8) + const spotId→slot map, same pattern as §5's talk counters; place verb validates against the spot's ITEM_PLACED condition and decrements the bag. SaveBlock3 grows 328→344 B (guard test updated).
- Spot-local flag bits (the 4 bits in spotStates): bit0 = battle won, bit1 = reserved-placed-done, bits2–3 reserved.
- `COND_SPOT_STATE` compares EQ on the state param; `COND_ZONE_COMPLETE` = all spots of the zone BEFRIENDED; `COND_BERRY_MATURE` zone filter = per-zone berry-tree id ranges in the zone table.
- Recompute scope = spots on the **current map** (sprites exist only there; chain conditions read other spots' saved state directly).

## Global Constraints

- Spec §2 authored fields verbatim: `spotId, species, tier, zoneId, appearConditions, befriendConditions, hintDormant/Stirring/Active, workerRole, personalityId`. Placeholder prose everywhere (Jay authors real text). Roles enum from §4 defined now; consumed in phase 4.
- Slice spots per §7: Skitty (place doll), Lotad (party Bulbasaur + rain + mature Oran), Machop (friendly bout — battle TRIGGER lands phase 5; its BATTLE_WIN condition + flag land now), Vulpix (offer Spicy Berry — flavor berry item constant TBD phase 4; placeholder ITEM_ORAN_BERRY with loud comment), Heracross (resident Pinsir + night + sap trees → RESIDENT_SPECIES unmet until phase 3, fine).
- Gates per task: `make check TESTS='Habitat'`; phase-final: full `make check`, `make verify`, EWRAM delta recorded. No ROM/screenshot commits.

## Task Summary (files)

- T1 schema+data: `include/habitat/spots.h`, `src/habitat/spot_data.c`, `include/habitat/roles.h`, table-integrity native test
- T2 save accessors: `include/habitat/save.h` (+placedCounters), `src/habitat/spot_state.c`, `test/habitat/spot_state.c`, `test/save.c` guard 332→340‑ish (measure)
- T3 machine: `src/habitat/spot_manager.c` (`Habitat_RecomputeCurrentMapSpots`, `Habitat_SyncSpotObjectFlags`), tests
- T4 local conditions: extend `src/habitat/conditions.c` (SPOT_STATE, TALK_COUNT, BATTLE_WIN, ITEM_PLACED, ZONE_COMPLETE + zone table in spots.h/spot_data.c), tests
- T5 wiring: `src/new_game.c` (slice spawn), `src/overworld.c` (map-load + hour-tick notify), `src/field_weather.c` (weather notify), `src/pokemon.c` or script cmd (givemon notify), events.c dispatches to spot manager; `make verify-boot` proves spawn
- T6 presence+inspect: `data/maps/Route103/map.json` (5 flag-gated species objects), flag aliases in `include/constants/flags.h` unused range, `data/scripts/habitat_spot.inc` + `data/specials.inc` entries, `src/habitat/spot_interaction.c` (hint buffering special, state in VAR_0x8004), delete truck test spot, hh-runner: spawn→walk→inspect shows dormant hint
- T7 verbs+befriend: place/offer flows (berry-tree bag-picker pattern, `ITEMMENULOCATION`-style callback), befriend = dex caught flag + state + `HABITAT_EVENT_RESIDENT_CHANGE` stub + ambient-sprite flag, hh-runner Skitty end-to-end (place doll → sprite appears → befriend), full gates

## Schema (T1, complete — the contract)

```c
// include/habitat/roles.h — spec §4 solo roles
enum HabitatWorkerRole
{
    ROLE_NONE = 0, ROLE_TEND, ROLE_IRRIGATE, ROLE_WARM, ROLE_POLLINATE,
    ROLE_DIG, ROLE_SPARK, ROLE_CHILL, ROLE_WEATHER, HABITAT_ROLES_COUNT,
};

// include/habitat/spots.h
#include "habitat/conditions.h"
#include "habitat/roles.h"

enum HabitatSpotState { HABITAT_STATE_DORMANT = 0, HABITAT_STATE_STIRRING, HABITAT_STATE_ACTIVE, HABITAT_STATE_BEFRIENDED };

#define HABITAT_SPOT_LOCAL_BATTLE_WON (1 << 0)  // 4-bit local flag field, bits 1–3 reserved

struct HabitatZone
{
    u8 zoneId;
    u8 berryTreeIdFirst, berryTreeIdLast;  // BERRY_MATURE zone filter (inclusive; 0,0 = none)
    // maps belong to a zone via the spots that live on them
};

struct HabitatSpot
{
    // ---- spec §2 authored fields (Jay's surface — do not reorder) ----
    u16 spotId;
    u16 species;
    u8 tier;
    u8 zoneId;
    const struct HabitatCondition *appearConditions;
    const struct HabitatCondition *befriendConditions;
    const u8 *hintDormant;
    const u8 *hintStirring;
    const u8 *hintActive;
    u8 workerRole;
    const u8 *personalityId;
    // ---- engine bindings (filled alongside, not designer-authored) ----
    u16 hideFlag;               // object event's flag: set = hidden (not ACTIVE)
    u8 mapGroup, mapNum, localId;
    u8 engineFlags;             // HABITAT_SPOTDEF_* (e.g. STAY_AMBIENT after befriend)
};

#define HABITAT_SPOTDEF_STAY_AMBIENT (1 << 0)  // sprite remains after befriending

extern const struct HabitatSpot gHabitatSpots[];   // terminated by spotId == 0xFFFF
extern const struct HabitatZone gHabitatZones[];   // terminated by zoneId == 0
const struct HabitatSpot *Habitat_GetSpot(u16 spotId);
const struct HabitatSpot *Habitat_GetSpotByObject(u8 mapGroup, u8 mapNum, u8 localId);
```

Save accessors (T2, complete):

```c
// spot_state.c API (declared in habitat/save.h)
enum HabitatSpotState Habitat_GetSpotState(u16 spotId);
void Habitat_SetSpotState(u16 spotId, enum HabitatSpotState state);  // monotonic ratchet: never lowers
u8   Habitat_GetSpotLocalFlags(u16 spotId);
void Habitat_SetSpotLocalFlags(u16 spotId, u8 flags);                // OR-in, 4-bit masked
u8   Habitat_GetTalkCount(u16 spotId);   // 0 if spot has no counter slot
void Habitat_IncrementTalkCount(u16 spotId);  // saturating; no-op without slot
u8   Habitat_GetPlacedCount(u16 spotId);
void Habitat_AddPlacedCount(u16 spotId, u8 n);  // saturating; no-op without slot
```

Recompute core (T3, complete semantics):

```c
void Habitat_RecomputeSpot(const struct HabitatSpot *spot)
{
    enum HabitatSpotState state = Habitat_GetSpotState(spot->spotId);
    struct HabitatConditionResult r;
    if (state >= HABITAT_STATE_ACTIVE)
        return;  // monotonic; befriending handled by the offer flow
    Habitat_EvaluateConditions(spot->appearConditions, spot->spotId, NULL, &r);
    if (r.allMet)
        Habitat_SetSpotState(spot->spotId, HABITAT_STATE_ACTIVE);
    else if (r.anyMet)
        Habitat_SetSpotState(spot->spotId, HABITAT_STATE_STIRRING);
    Habitat_SyncSpotObjectFlag(spot);  // hideFlag set iff state != ACTIVE && !(BEFRIENDED && STAY_AMBIENT)
}
```

`Habitat_NotifyEvent` (events.c) routes MAP_LOAD/TIME_TICK/WEATHER_CHANGE/PARTY_CHANGE → `Habitat_RecomputeCurrentMapSpots()` (walk `gHabitatSpots`, filter by current map, recompute, then respawn/remove live objects whose flags changed via `TrySpawnObjectEvent`/`RemoveObjectEventByLocalIdAndMap`).

Each task: failing test → red (`make check TESTS='Habitat'`) → implement → green → commit, exactly as phase 1 practiced. hh-runner scenarios in T6/T7 extend `tools/habitat/verify.sh` with a `--scenario skitty` mode (target coords on Route 103; assertions via saved state reads at `gSaveBlock3Ptr` symbol + screenshot evidence).

## Self-Review

- §2 spot fields verbatim ✓; state machine + staged hints + persistent sprite + befriend flow ✓ (T3/T6/T7); event-driven recompute with named call sites ✓ (T5); all remaining slice-needed condition types land T4 except RESIDENT_* (phase 3, per build order) ✓; §7 slice spots as data ✓ (T1; Machop trigger phase 5, Vulpix currency placeholder flagged); no polling ✓; placeholder text only ✓.
- Placeholders: Vulpix's Spicy Berry item + Skitty/Machop/Heracross befriend items are placeholder data with loud comments (Jay's side); exact new SaveBlock3 size measured at T2 (guard updated with the number, not a guess).
- Names consistent: `Habitat_GetSpot*`, `Habitat_RecomputeSpot`, `HABITAT_STATE_*`, `HABITAT_SPOTDEF_*` used identically across tasks.
