# M1 Phase 1: Condition Engine Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.
>
> **Execution mode for this run:** inline (superpowers:executing-plans) — same serial/stateful rationale as M0; every task compiles and tests against one shared tree.

**Goal:** The full 20-type condition vocabulary from spec §2, compiled as data, evaluated by one engine with NEGATE/OR-group semantics and per-condition met-masks (the hint-checklist feed) — with the state-independent types implemented and native-tested, and a validated HabitatSave beachhead in SaveBlock3 per Jay's M0 decision.

**Architecture:** All engine code in `src/habitat/` + `include/habitat/` (the Makefile globs `src/*/*.c`; zero build-system changes). Conditions are const ROM data authored through macros; the evaluator is stateless (stack only — EWRAM is the scarce budget, per Jay). Types whose backing state arrives in later phases (spot-local, residents, Grove) get dispatch entries that deterministically return FALSE, tagged with their landing phase — the enum and struct layout are day-one stable so Jay's content data never breaks.

**Tech Stack:** repo's native TEST() framework (`test/`, runs headless via `make check`, filter `TESTS='Habitat'`), `RUN_OVERWORLD_SCRIPT` fixtures, expansion APIs: `GetCurrentWeather()`, `RtcCalcLocalTime()`/`gLocalTime`/`RtcInitLocalTimeOffset()`, `FlagGet`, `GetGameStat`, `GetNationalPokedexCount`, `ItemIdToBerryType`, `GetMonData`.

## Global Constraints

- Spec §2 is the schema contract: condition = `{ type, paramA, paramB, paramC, flags }`; flags support `NEGATE` and `OR_GROUP(n)`; enum numbering 1–20 exactly as the spec table. Schema changes require Jay's approval. (Naming note for the report: the C identifier is `struct HabitatCondition` — project-prefixed to avoid collisions — but field names/semantics match the spec; Jay authors via macros and never types the struct name.)
- Jay's M0-review decisions (docs/design-notes.md, Task 0): HabitatSave lives in SaveBlock3; Secret Base slab stays banked; quickstart pinned to Brendan **but nothing may assume a single fixed player body** (both bodies become illusion masks later); placeholder text everywhere engine-side; EWRAM is the budget to watch.
- No polling loops (spec §2 note): this phase ships the evaluator + event-notify interface; call-site wiring lands with the spot framework (phase 2), which is the first consumer.
- Every task: `make check TESTS='Habitat'` green before commit; full `make check` + `make verify` green before the phase-final commit. EWRAM delta for the whole phase ≤ ~1 KB (expected: ~330 B from HabitatSave + evaluator locals ≈ 0).

## File Structure

- Create `include/config/habitat.h` — feature toggles + scale constants (`HABITAT_SPOT_COUNT 320`, etc.)
- Create `include/habitat/save.h` — `struct HabitatSave` (SaveBlock3 member)
- Create `include/habitat/conditions.h` — enum, struct, flags, comparators, authoring macros, evaluator API
- Create `src/habitat/conditions.c` — evaluator + per-type implementations
- Create `include/habitat/events.h` + `src/habitat/events.c` — event enum + notify stub (phase-2 interface)
- Create `test/habitat/conditions.c` — all native tests (test dir already supports subdirs)
- Modify `include/global.h` (SaveBlock3 member), `src/new_game.c` (clear on new game), `include/config/quickstart.h` (Brendan pin)
- Create `docs/design-notes.md`, `docs/habitat/authoring-conditions.md` (Jay's authoring reference)

### Task 0: Record design decisions; pin quickstart to Brendan

**Files:**
- Create: `docs/design-notes.md`
- Modify: `include/config/quickstart.h:11`

- [ ] **Step 1: Write docs/design-notes.md**

```markdown
# Design Decisions Log

Running log of decisions made between spec revisions. The spec remains the
contract; entries here are its amendments-in-waiting.

## 2026-07-18 — M0 review (Jay)

- **Save layout:** `HabitatSave` lives in SaveBlock3 (expansion extension
  region, 1,620 B free). The Secret Base slab (3,200 B in SaveBlock1) stays
  untouched, banked as the scale-out reservoir.
- **Player body:** quickstart pinned to Brendan as slice placeholder. The real
  intro's character select becomes the Zorua choosing its illusion — BOTH body
  sprite sets remain in-game as masks. Engine constraint: never architect
  against a single fixed player body (no Brendan-only assumptions in save
  data, sprites, or scripts).
- **Text:** hint/story prose is authored by Jay. Engine ships obviously-
  placeholder text.
- **Budget watch:** EWRAM (86.4 % at M0) is the scarce resource when sizing
  structures, not save space.
```

- [ ] **Step 2: Pin quickstart gender** — in `include/config/quickstart.h` change `#define QUICKSTART_GENDER            GENDER_RANDOM` to `GENDER_MALE` with a trailing comment `// slice placeholder; see docs/design-notes.md (both bodies remain as masks)`.
- [ ] **Step 3: Verify** — `make verify-boot` passes (still boots to overworld).
- [ ] **Step 4: Commit** — `docs: record M0-review design decisions; pin quickstart to Brendan`

### Task 1: HabitatSave beachhead in SaveBlock3

**Files:**
- Create: `include/config/habitat.h`
- Create: `include/habitat/save.h`
- Modify: `include/global.h` (SaveBlock3 struct, after `apricornTrees`)
- Modify: `src/new_game.c` (clear habitat state on new game)

**Interfaces:**
- Produces: `gSaveBlock3Ptr->habitat` (`struct HabitatSave`), constants `HABITAT_SPOT_COUNT`, `HABITAT_TALK_COUNTER_COUNT`. Phase 2's spot framework consumes; nothing else touches raw bytes.

- [ ] **Step 1: Write include/config/habitat.h**

```c
#ifndef GUARD_CONFIG_HABITAT_H
#define GUARD_CONFIG_HABITAT_H

// Hoenn Habitat engine configuration. Scale constants are full-game values
// from spec §5 — content grows into them; the layout never moves under saves.
#define HABITAT_SPOT_COUNT          320  // spot-state bytes reserved in SaveBlock3
#define HABITAT_TALK_COUNTER_COUNT  8    // spots needing >15 talk counts (Spiritomb-class)

#endif // GUARD_CONFIG_HABITAT_H
```

- [ ] **Step 2: Write include/habitat/save.h**

```c
#ifndef GUARD_HABITAT_SAVE_H
#define GUARD_HABITAT_SAVE_H

#include "config/habitat.h"

// Persistent habitat state. Lives in SaveBlock3 (see global.h); the save
// engine chunks it across sector spare bytes automatically and
// save.c:80 static-asserts the total fits. Layout per spec §5:
// spotStates[i] packs 2b state | 2b hint stage | 4b spot-local flags.
struct HabitatSave
{
    u8 spotStates[HABITAT_SPOT_COUNT];
    u8 talkCounters[HABITAT_TALK_COUNTER_COUNT];
};

#endif // GUARD_HABITAT_SAVE_H
```

- [ ] **Step 3: Add member to SaveBlock3** in `include/global.h` — after the `apricornTrees` block, before the closing brace:

```c
    struct HabitatSave habitat;
```

with `#include "habitat/save.h"` added next to the existing includes above the struct. Keep it unguarded (the game IS the feature; no config toggle theater).

- [ ] **Step 4: Clear on new game** — in `src/new_game.c`, find `NewGameInitData` (locate how existing SaveBlock3 fields reset — if SaveBlock3 is wholesale-memset on new game, note that and skip; otherwise add `memset(&gSaveBlock3Ptr->habitat, 0, sizeof(gSaveBlock3Ptr->habitat));` beside its siblings). Zeroed state must equal "all spots DORMANT, hint stage 0, flags 0" — spec's state machine starts at DORMANT=0 by construction.
- [ ] **Step 5: Build** — `make -j` succeeds; save.c:80's STATIC_ASSERT proves the 328 B fit (4 + 328 = 332 ≤ 1,624). Record new EWRAM % from link stats.
- [ ] **Step 6: Verify** — `make verify-boot` (boots, new game initializes).
- [ ] **Step 7: Commit** — `feat: reserve HabitatSave in SaveBlock3 (spot states + talk counters)`

### Task 2: Condition schema + evaluator core (grouping/negation/masks)

**Files:**
- Create: `include/habitat/conditions.h`
- Create: `src/habitat/conditions.c`
- Create: `test/habitat/conditions.c`

**Interfaces:**
- Produces (consumed by phase 2 spots + all later phases):
  - `enum HabitatConditionType` (COND_NONE=0 … COND_GROVE_RECIPE_DONE=20)
  - `struct HabitatCondition { u8 type; u8 flags; u16 paramA, paramB, paramC; }`
  - `HABITAT_COND_NEGATE`, `HABITAT_COND_OR_GROUP(n)` (group id in flag bits 4–7)
  - `enum HabitatComparator { HABITAT_CMP_GE=0, LE, EQ, NE, GT, LT }`
  - `struct HabitatOfferContext { u16 itemId; u16 count; }`
  - `struct HabitatConditionResult { u32 metMask; u8 count; bool8 allMet; bool8 anyMet; }`
  - `void Habitat_EvaluateConditions(const struct HabitatCondition *list, u16 spotId, const struct HabitatOfferContext *offer, struct HabitatConditionResult *out);`
  - `HABITAT_SPOT_NONE` (0xFFFF), `HABITAT_CONDITIONS_END` terminator macro, `HABITAT_COND(t, a, b, c, f)` authoring macro

- [ ] **Step 1: Write include/habitat/conditions.h** (complete):

```c
#ifndef GUARD_HABITAT_CONDITIONS_H
#define GUARD_HABITAT_CONDITIONS_H

#include "global.h"

// Condition vocabulary — spec §2 table, numbering preserved exactly.
// Types marked [phase N] return FALSE until that phase lands their state.
enum HabitatConditionType
{
    COND_NONE = 0,            // list terminator
    COND_ITEM_PLACED,         //  1 itemId, count      [phase 2: spot placement]
    COND_ITEM_OFFERED,        //  2 itemId, count      (offer context, befriend verb)
    COND_PARTY_SPECIES,       //  3 species, count
    COND_PARTY_FRIENDSHIP,    //  4 comparator, value
    COND_PARTY_MOVE,          //  5 moveId
    COND_PARTY_NATURE,        //  6 natureId
    COND_RESIDENT_SPECIES,    //  7 species, zoneId(0=any)  [phase 3: registry]
    COND_RESIDENT_COUNT,      //  8 typeFilter, count       [phase 3]
    COND_TIME_OF_DAY,         //  9 windowStartHour, windowEndHour (end-exclusive, wraps midnight)
    COND_WEATHER,             // 10 weatherId (natural or worker-generated: same getter)
    COND_STORY_FLAG,          // 11 flagId
    COND_DEX_COUNT,           // 12 comparator, value (dex caught == befriended, spec §5)
    COND_BERRY_MATURE,        // 13 berryItemId, zoneId(0=any; zone filter lands phase 2)
    COND_LIFETIME_STAT,       // 14 statId, comparator, value (gGameStats)
    COND_SPOT_STATE,          // 15 spotId, state           [phase 2]
    COND_ZONE_COMPLETE,       // 16 zoneId                  [phase 2]
    COND_BATTLE_WIN,          // 17 (spot-local won flag)   [phase 2]
    COND_ILLUSION,            // 18 species                 [phase 4+]
    COND_TALK_COUNT,          // 19 count                   [phase 2]
    COND_GROVE_RECIPE_DONE,   // 20 recipeId                [phase 4]
    HABITAT_COND_TYPES_COUNT,
};

enum HabitatComparator
{
    HABITAT_CMP_GE = 0,  // default: "at least" reads best in authored data
    HABITAT_CMP_LE,
    HABITAT_CMP_EQ,
    HABITAT_CMP_NE,
    HABITAT_CMP_GT,
    HABITAT_CMP_LT,
};

// flags: bit 0 = NEGATE (spite mechanics — inverts the whole condition);
// bits 4–7 = OR-group id (0 = standalone/ANDed; same nonzero id = any-of group).
#define HABITAT_COND_NEGATE       (1 << 0)
#define HABITAT_COND_OR_GROUP(n)  ((n) << 4)
#define HABITAT_COND_GROUP_OF(c)  (((c)->flags >> 4) & 0xF)

struct HabitatCondition
{
    u8 type;    // enum HabitatConditionType
    u8 flags;
    u16 paramA;
    u16 paramB;
    u16 paramC;
}; // 8 bytes, authored as const ROM data

#define HABITAT_COND(t, a, b, c, f) { .type = (t), .flags = (f), .paramA = (a), .paramB = (b), .paramC = (c) }
#define HABITAT_CONDITIONS_END      { .type = COND_NONE }

#define HABITAT_SPOT_NONE        0xFFFF
#define HABITAT_MAX_CONDITIONS   32  // met-mask width; evaluator stops here

// Befriend-verb input: what the player is offering right now (NULL outside
// the offer flow — COND_ITEM_OFFERED is then unmet by definition).
struct HabitatOfferContext
{
    u16 itemId;
    u16 count;
};

struct HabitatConditionResult
{
    u32 metMask;   // bit i = list[i] satisfied (after NEGATE; grouping not applied)
    u8 count;      // conditions in list (terminator excluded, capped at HABITAT_MAX_CONDITIONS)
    bool8 allMet;  // standalone conditions all pass AND every OR-group has ≥1 passer
    bool8 anyMet;  // ≥1 condition passes — drives DORMANT→STIRRING (spec §2)
};

void Habitat_EvaluateConditions(const struct HabitatCondition *list, u16 spotId,
                                const struct HabitatOfferContext *offer,
                                struct HabitatConditionResult *out);

#endif // GUARD_HABITAT_CONDITIONS_H
```

- [ ] **Step 2: Write the failing core-semantics tests** in `test/habitat/conditions.c` — empty list (`allMet TRUE / anyMet FALSE / count 0`), NEGATE on STORY_FLAG, two-member OR-group (one true → group passes; both false → fails), standalone+group mix, metMask bit accuracy, >32 cap. STORY_FLAG is the vehicle (settable from scripts). Representative test (all follow this shape):

```c
#include "global.h"
#include "event_data.h"
#include "habitat/conditions.h"
#include "test/overworld_script.h"
#include "test/test.h"

// Scratch story flags, safe to toggle in tests.
#define TEST_FLAG_A FLAG_UNUSED_0x264
#define TEST_FLAG_B FLAG_UNUSED_0x265

TEST("Habitat conditions: empty list is vacuously all-met and not any-met")
{
    static const struct HabitatCondition sList[] = { HABITAT_CONDITIONS_END };
    struct HabitatConditionResult r;
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT_EQ(r.count, 0);
    EXPECT(r.allMet);
    EXPECT(!r.anyMet);
}

TEST("Habitat conditions: OR-group passes when any member passes")
{
    static const struct HabitatCondition sList[] = {
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_A, 0, 0, HABITAT_COND_OR_GROUP(1)),
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_B, 0, 0, HABITAT_COND_OR_GROUP(1)),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    FlagClear(TEST_FLAG_A); FlagClear(TEST_FLAG_B);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    FlagSet(TEST_FLAG_B);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    EXPECT_EQ(r.metMask, 1u << 1);
}
```

(Exact FLAG_UNUSED_* names: pick two real unused flags from `include/constants/flags.h` at implementation time.)

- [ ] **Step 3: Run to confirm failure mode** — `make check TESTS='Habitat'` fails to compile (no conditions.c) — that's the expected red.
- [ ] **Step 4: Write src/habitat/conditions.c** — evaluator core (complete) with per-type dispatch; unimplemented types FALSE:

```c
#include "global.h"
#include "habitat/conditions.h"
#include "event_data.h"

static bool32 EvalOne(const struct HabitatCondition *c, u16 spotId,
                      const struct HabitatOfferContext *offer);

void Habitat_EvaluateConditions(const struct HabitatCondition *list, u16 spotId,
                                const struct HabitatOfferContext *offer,
                                struct HabitatConditionResult *out)
{
    u32 groupSeen = 0, groupMet = 0;  // bit g = OR-group g present / has a passer
    bool32 standaloneAllMet = TRUE;
    u32 i;

    out->metMask = 0;
    out->count = 0;
    out->anyMet = FALSE;

    for (i = 0; list[i].type != COND_NONE && i < HABITAT_MAX_CONDITIONS; i++)
    {
        const struct HabitatCondition *c = &list[i];
        bool32 met = EvalOne(c, spotId, offer);
        if (c->flags & HABITAT_COND_NEGATE)
            met = !met;

        u32 group = HABITAT_COND_GROUP_OF(c);
        if (met)
            out->metMask |= 1u << i;
        if (group == 0)
            standaloneAllMet = standaloneAllMet && met;
        else
        {
            groupSeen |= 1u << group;
            if (met)
                groupMet |= 1u << group;
        }
        if (met)
            out->anyMet = TRUE;
        out->count++;
    }

    out->allMet = standaloneAllMet && ((groupSeen & ~groupMet) == 0);
}

static bool32 Cmp(u32 lhs, u32 comparator, u32 rhs)
{
    switch (comparator)
    {
    case HABITAT_CMP_GE: return lhs >= rhs;
    case HABITAT_CMP_LE: return lhs <= rhs;
    case HABITAT_CMP_EQ: return lhs == rhs;
    case HABITAT_CMP_NE: return lhs != rhs;
    case HABITAT_CMP_GT: return lhs > rhs;
    case HABITAT_CMP_LT: return lhs < rhs;
    }
    return FALSE;
}

static bool32 EvalOne(const struct HabitatCondition *c, u16 spotId,
                      const struct HabitatOfferContext *offer)
{
    switch (c->type)
    {
    case COND_STORY_FLAG:
        return FlagGet(c->paramA);
    // ... per-type cases land in Tasks 3–5; every remaining spec type gets
    // an explicit `case COND_X: return FALSE; // [phase N]` entry here NOW.
    default:
        return FALSE;
    }
}
```

- [ ] **Step 5: Green** — `make check TESTS='Habitat'` passes core-semantics tests.
- [ ] **Step 6: Commit** — `feat: add habitat condition schema and evaluator core (spec §2)`

### Task 3: Party conditions (SPECIES / FRIENDSHIP / MOVE / NATURE)

**Files:** modify `src/habitat/conditions.c`, extend `test/habitat/conditions.c`

- [ ] **Step 1: Failing tests** — fixtures via `RUN_OVERWORLD_SCRIPT(givemon SPECIES_BULBASAUR, 10;)` (party starts empty in overworld tests; ASSUME gPlayerPartyCount as sanity). Cover: species present/absent; species count ≥2 (two givemon); friendship GE/LE with `setmonfriendship`-equivalent (set via `SetMonData(&gPlayerParty[0], MON_DATA_FRIENDSHIP, &val)` directly in the test — white-box fixtures are house style); move known via givemon then `SetMonMoveSlot`/`MON_DATA_MOVE1`; nature via givemon's fixed personality path — set `MON_DATA_PERSONALITY` isn't authorable, so assert on the actual `GetNature()` of the given mon for the met case and a different nature id for the unmet case.
- [ ] **Step 2: Red** — `make check TESTS='Habitat'`: new tests fail (types return FALSE).
- [ ] **Step 3: Implement** in `EvalOne`:

```c
    case COND_PARTY_SPECIES: {
        u32 n = 0, i;
        for (i = 0; i < gPlayerPartyCount; i++)
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) == c->paramA)
                n++;
        return n >= max(1, c->paramB);
    }
    case COND_PARTY_FRIENDSHIP: {
        u32 i;
        for (i = 0; i < gPlayerPartyCount; i++)
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
             && Cmp(GetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP), c->paramA, c->paramB))
                return TRUE;
        return FALSE;
    }
    case COND_PARTY_MOVE: {
        u32 i, slot;
        for (i = 0; i < gPlayerPartyCount; i++)
            for (slot = 0; slot < MAX_MON_MOVES; slot++)
                if (GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + slot) == c->paramA)
                    return TRUE;
        return FALSE;
    }
    case COND_PARTY_NATURE: {
        u32 i;
        for (i = 0; i < gPlayerPartyCount; i++)
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
             && GetNature(&gPlayerParty[i]) == c->paramA)
                return TRUE;
        return FALSE;
    }
```

(Exact helper names — `gPlayerPartyCount` freshness via `CalculatePlayerPartyCount()`, `GetNature` signature, egg handling idiom — mirror what `test/party_menu.c` / `src/pokemon.c` actually use; adjust at implementation, semantics fixed as above.)
- [ ] **Step 4: Green; commit** — `feat: implement party habitat conditions`

### Task 4: World conditions (TIME / WEATHER / DEX / STAT / BERRY)

**Files:** modify `src/habitat/conditions.c`, extend `test/habitat/conditions.c`

- [ ] **Step 1: Failing tests** — time: `RtcInitLocalTimeOffset(22, 0)` then night window (20,4) met, day window (8,17) unmet, wraparound both sides, end-exclusive boundary; weather: `RUN_OVERWORLD_SCRIPT(setweather WEATHER_RAIN; doweather;)`; dex count: three `givemon` → `COND_DEX_COUNT(GE,3)` met, `(GE,4)` unmet; lifetime stat: `SetGameStat(GAME_STAT_STEPS, 100)`; berry: write `gSaveBlock1Ptr->berryTrees[2] = (struct BerryTree){ .berry = ItemIdToBerryType(ITEM_ORAN_BERRY), .stage = BERRY_STAGE_BERRIES };` met / `.stage = BERRY_STAGE_TASTY`-less unmet (use the real stage enum).
- [ ] **Step 2: Red.**
- [ ] **Step 3: Implement:**

```c
    case COND_TIME_OF_DAY: {
        u32 start = c->paramA, end = c->paramB, h;
        RtcCalcLocalTime();
        h = gLocalTime.hours;
        if (start == end)  return TRUE;               // degenerate: whole day
        if (start < end)   return h >= start && h < end;
        return h >= start || h < end;                 // wraps midnight
    }
    case COND_WEATHER:
        return GetCurrentWeather() == c->paramA;
    case COND_DEX_COUNT:
        return Cmp(GetNationalPokedexCount(FLAG_GET_CAUGHT), c->paramA, c->paramB);
    case COND_LIFETIME_STAT:
        return Cmp(GetGameStat(c->paramA), c->paramB, c->paramC);
    case COND_BERRY_MATURE: {
        u32 i, berry = ItemIdToBerryType(c->paramA);
        // paramB (zoneId) filter lands with phase 2's zone table; 0 = anywhere.
        for (i = 0; i < BERRY_TREES_COUNT; i++)
            if (gSaveBlock1Ptr->berryTrees[i].berry == berry
             && gSaveBlock1Ptr->berryTrees[i].stage == BERRY_STAGE_BERRIES)
                return TRUE;
        return FALSE;
    }
```

- [ ] **Step 4: Green; commit** — `feat: implement world-state habitat conditions`

### Task 5: Offer context (COND_ITEM_OFFERED)

**Files:** modify `src/habitat/conditions.c`, extend `test/habitat/conditions.c`

- [ ] **Step 1: Failing tests** — NULL offer → unmet; matching item+count → met; wrong item → unmet; count below threshold → unmet; count 0 authored = treat as 1.
- [ ] **Step 2: Red.**
- [ ] **Step 3: Implement:**

```c
    case COND_ITEM_OFFERED:
        return offer != NULL
            && offer->itemId == c->paramA
            && offer->count >= max(1, c->paramB);
```

- [ ] **Step 4: Green; commit** — `feat: implement offer-context habitat condition`

### Task 6: Event-notify interface, authoring doc, phase wrap

**Files:**
- Create: `include/habitat/events.h`, `src/habitat/events.c`
- Create: `docs/habitat/authoring-conditions.md`
- Modify: `CHANGELOG.md`

- [ ] **Step 1: events.h/.c** — the no-polling interface phase 2 wires into game call sites:

```c
// include/habitat/events.h
#ifndef GUARD_HABITAT_EVENTS_H
#define GUARD_HABITAT_EVENTS_H

// Recompute triggers per spec §2: engine recomputes on events, never polls.
enum HabitatEvent
{
    HABITAT_EVENT_MAP_LOAD,
    HABITAT_EVENT_TIME_TICK,
    HABITAT_EVENT_WEATHER_CHANGE,
    HABITAT_EVENT_PARTY_CHANGE,
    HABITAT_EVENT_INVENTORY_CHANGE,
    HABITAT_EVENT_RESIDENT_CHANGE,
    HABITAT_EVENT_SPOT_STATE_CHANGE,
};

// Phase 2's spot manager subscribes here; until then this is a no-op so call
// sites can be wired incrementally without ifdef noise.
void Habitat_NotifyEvent(enum HabitatEvent event);

#endif // GUARD_HABITAT_EVENTS_H
```

```c
// src/habitat/events.c
#include "global.h"
#include "habitat/events.h"

void Habitat_NotifyEvent(enum HabitatEvent event)
{
    // Intentionally empty until the spot framework (M1 phase 2) subscribes.
    (void) event;
}
```

- [ ] **Step 2: Authoring doc** — `docs/habitat/authoring-conditions.md`: one `HABITAT_COND(...)` example per implemented type with param meanings, comparator table, NEGATE/OR-group examples (Shuppet-style spite = `COND_PARTY_FRIENDSHIP` with `HABITAT_CMP_LE`, weather-spite = NEGATE on `COND_WEATHER`), the "unimplemented until phase N" table, and the empty-list rule. This is Jay's schema reference — accuracy over brevity.
- [ ] **Step 3: CHANGELOG entry** under Unreleased: condition engine + SaveBlock3 beachhead + quickstart pin.
- [ ] **Step 4: Full gates** — `make check` (entire suite) green; `make verify` green; EWRAM delta recorded vs M0's 86.43 %.
- [ ] **Step 5: Commit** — `feat: add habitat event-notify interface and condition authoring docs`

## Self-Review

- **Spec §2 coverage:** all 20 types in the enum with spec numbering (Task 2 header); NEGATE + OR_GROUP semantics in core (Task 2); staged-hint feed via metMask/anyMet (Task 2); "recompute on events, no polling" honored as interface-now/wiring-phase-2 (Task 6, constraint noted); befriend-verb offer path (Task 5). Slice-minimum 8 types: PARTY_SPECIES ✓3, TIME_OF_DAY ✓4, WEATHER ✓4, BERRY_MATURE ✓4, ITEM_OFFERED ✓5; ITEM_PLACED/RESIDENT_SPECIES/BATTLE_WIN documented as landing with their state (phases 2–3) — enum-stable now.
- **Placeholder scan:** two adjust-at-implementation notes (unused-flag ids, party helper idioms) — each names the exact reference file to mirror; semantics are fully specified here. Acceptable.
- **Type consistency:** `HabitatCondition`/`HabitatConditionResult`/`HabitatOfferContext`/`Habitat_EvaluateConditions` spelled identically across Tasks 2–6; comparator enum order GE-first everywhere; `HABITAT_SPOT_NONE` used in all tests.
