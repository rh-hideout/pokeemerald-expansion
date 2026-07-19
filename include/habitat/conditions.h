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
#define HABITAT_COND_EXACT_STAGE  (1 << 1)  // §9 anti-regret: reserved; species
                                            // conds match line-at-stage-or-above
                                            // by default once rituals land
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
#define HABITAT_TYPE_ANY         0xFF  // COND_RESIDENT_COUNT: no type filter
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
