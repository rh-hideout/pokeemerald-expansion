# Authoring Conditions — Schema Reference (M1 phase 1)

This is the designer-facing contract for spec §2's condition vocabulary as
implemented. Conditions are authored as const data with the `HABITAT_COND`
macro; you never touch the C struct directly.

```c
HABITAT_COND(type, paramA, paramB, paramC, flags)
```

A condition **list** is an array of these ending in `HABITAT_CONDITIONS_END`.
Max 32 conditions per list. An **empty list is vacuously satisfied** (all-met,
never any-met) — a spot with no appear conditions is born ACTIVE-eligible.

## Combining conditions

- Conditions are **ANDed** by default.
- `HABITAT_COND_OR_GROUP(n)` (n = 1–15) in `flags` puts a condition in group
  *n*; a group passes when **any** member passes. Groups AND with everything
  else.
- `HABITAT_COND_NEGATE` inverts one condition (spite mechanics). Combine with
  `|`: `HABITAT_COND_OR_GROUP(2) | HABITAT_COND_NEGATE`.

## Comparators (for types that take one)

`HABITAT_CMP_GE` (default, "at least") · `LE` · `EQ` · `NE` · `GT` · `LT`

## The vocabulary

| Type | Params (A, B, C) | Status | Example |
|---|---|---|---|
| `COND_ITEM_PLACED` | itemId, count, — | phase 2 | 4 water bottles placed at the spot |
| `COND_ITEM_OFFERED` | itemId, count, — | ✅ | `HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 1, 0, 0)` |
| `COND_PARTY_SPECIES` | species, count, — | ✅ | bring a Bulbasaur: `(COND_PARTY_SPECIES, SPECIES_BULBASAUR, 1, 0, 0)` |
| `COND_PARTY_FRIENDSHIP` | comparator, value, — | ✅ | Shuppet spite: `(COND_PARTY_FRIENDSHIP, HABITAT_CMP_LE, 30, 0, 0)` |
| `COND_PARTY_MOVE` | moveId, —, — | ✅ | `(COND_PARTY_MOVE, MOVE_FLASH, 0, 0, 0)` |
| `COND_PARTY_NATURE` | natureId, —, — | ✅ | `(COND_PARTY_NATURE, NATURE_JOLLY, 0, 0, 0)` |
| `COND_RESIDENT_SPECIES` | species, zoneId (0=any), — | phase 3 | resident Pinsir in this zone |
| `COND_RESIDENT_COUNT` | typeFilter, count, — | phase 3 | 5 Ghost/Dark residents |
| `COND_TIME_OF_DAY` | startHour, endHour, — | ✅ | night: `(COND_TIME_OF_DAY, 20, 4, 0, 0)` — end-exclusive, wraps midnight; start==end means "always" |
| `COND_WEATHER` | weatherId, —, — | ✅ | raining: `(COND_WEATHER, WEATHER_RAIN, 0, 0, 0)`; not-sunny spite: add `HABITAT_COND_NEGATE` |
| `COND_STORY_FLAG` | flagId, —, — | ✅ | `(COND_STORY_FLAG, FLAG_..., 0, 0, 0)` |
| `COND_DEX_COUNT` | comparator, value, — | ✅ | ≥30 befriended: `(COND_DEX_COUNT, HABITAT_CMP_GE, 30, 0, 0)` |
| `COND_BERRY_MATURE` | berry **item** id, zoneId, — | ✅ (zone filter phase 2; use 0) | `(COND_BERRY_MATURE, ITEM_ORAN_BERRY, 0, 0, 0)` |
| `COND_LIFETIME_STAT` | statId, comparator, value | ✅ | 100 berries harvested: `(COND_LIFETIME_STAT, GAME_STAT_..., HABITAT_CMP_GE, 100, 0)` |
| `COND_SPOT_STATE` | spotId, state, — | phase 2 | chain builder |
| `COND_ZONE_COMPLETE` | zoneId, —, — | phase 2 | all zone spots befriended |
| `COND_BATTLE_WIN` | —, —, — | phase 2 | friendly bout won at this spot |
| `COND_ILLUSION` | species, —, — | phase 4+ | Zorua disguised as Stantler |
| `COND_TALK_COUNT` | count, —, — | phase 2 | Spiritomb's 108 |
| `COND_GROVE_RECIPE_DONE` | recipeId, —, — | phase 4 | ever co-produced Spicy |

"Phase N" types are **safe to author today** — they evaluate as unmet until
their backing state lands, and the enum/params will not change under you.

## Worked example (slice's Lotad spot, spec §7)

```c
static const struct HabitatCondition sLotadAppear[] = {
    HABITAT_COND(COND_PARTY_SPECIES, SPECIES_BULBASAUR, 1, 0, 0),
    HABITAT_COND(COND_WEATHER, WEATHER_RAIN, 0, 0, 0),
    HABITAT_COND(COND_BERRY_MATURE, ITEM_ORAN_BERRY, 0, 0, 0),
    HABITAT_CONDITIONS_END,
};
static const struct HabitatCondition sLotadBefriend[] = {
    HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 1, 0, 0),
    HABITAT_CONDITIONS_END,
};
```

## What the engine hands back (for staged hints)

Evaluation returns per-condition met bits (`metMask`), `anyMet` (drives
DORMANT→STIRRING), and `allMet` (drives STIRRING→ACTIVE / befriend success) —
the hint UI in phase 2 renders checklists straight from these.
