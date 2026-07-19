#include "global.h"
#include "habitat/conditions.h"
#include "event_data.h"
#include "pokemon.h"

static bool32 EvalOne(const struct HabitatCondition *c, u16 spotId,
                      const struct HabitatOfferContext *offer);
static bool32 Cmp(u32 lhs, u32 comparator, u32 rhs);

// Evaluates a terminated condition list. Semantics (spec §2): every
// standalone condition must pass; each OR-group needs at least one passing
// member; NEGATE inverts an individual condition before grouping. metMask
// and anyMet feed the staged-hint system (DORMANT→STIRRING on anyMet).
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
        u32 group = HABITAT_COND_GROUP_OF(c);
        bool32 met = EvalOne(c, spotId, offer);

        if (c->flags & HABITAT_COND_NEGATE)
            met = !met;

        if (met)
        {
            out->metMask |= 1u << i;
            out->anyMet = TRUE;
        }
        if (group == 0)
            standaloneAllMet = standaloneAllMet && met;
        else
        {
            groupSeen |= 1u << group;
            if (met)
                groupMet |= 1u << group;
        }
        out->count++;
    }

    out->allMet = standaloneAllMet && (groupSeen & ~groupMet) == 0;
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
    case COND_PARTY_SPECIES:
    {
        u32 i, n = 0;
        for (i = 0; i < gPlayerPartyCount && i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) == c->paramA)
                n++;
        }
        return n >= max(1, c->paramB);
    }
    case COND_PARTY_FRIENDSHIP:
    {
        u32 i;
        for (i = 0; i < gPlayerPartyCount && i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
             && Cmp(GetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP), c->paramA, c->paramB))
                return TRUE;
        }
        return FALSE;
    }
    case COND_PARTY_MOVE:
    {
        u32 i, slot;
        for (i = 0; i < gPlayerPartyCount && i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
                continue;
            for (slot = 0; slot < MAX_MON_MOVES; slot++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + slot) == c->paramA)
                    return TRUE;
            }
        }
        return FALSE;
    }
    case COND_PARTY_NATURE:
    {
        u32 i;
        for (i = 0; i < gPlayerPartyCount && i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
             && GetNature(&gPlayerParty[i]) == c->paramA)
                return TRUE;
        }
        return FALSE;
    }

    // Not yet backed by state; each returns FALSE until its phase lands.
    case COND_ITEM_PLACED:        // [phase 2: spot placement state]
    case COND_ITEM_OFFERED:       // [this phase, Task 5]
    case COND_RESIDENT_SPECIES:   // [phase 3: resident registry]
    case COND_RESIDENT_COUNT:     // [phase 3]
    case COND_TIME_OF_DAY:        // [this phase, Task 4]
    case COND_WEATHER:            // [this phase, Task 4]
    case COND_DEX_COUNT:          // [this phase, Task 4]
    case COND_BERRY_MATURE:       // [this phase, Task 4]
    case COND_LIFETIME_STAT:      // [this phase, Task 4]
    case COND_SPOT_STATE:         // [phase 2]
    case COND_ZONE_COMPLETE:      // [phase 2]
    case COND_BATTLE_WIN:         // [phase 2]
    case COND_ILLUSION:           // [phase 4+]
    case COND_TALK_COUNT:         // [phase 2]
    case COND_GROVE_RECIPE_DONE:  // [phase 4]
    default:
        return FALSE;
    }
}
