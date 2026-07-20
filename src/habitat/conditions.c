#include "global.h"
#include "habitat/conditions.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "event_data.h"
#include "field_weather.h"
#include "item.h"
#include "overworld.h"
#include "pokedex.h"
#include "pokemon.h"
#include "rtc.h"
#include "constants/berry.h"

static bool32 EvalOne(const struct HabitatCondition *c, u32 condIndex, u16 spotId,
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
        bool32 met = EvalOne(c, i, spotId, offer);

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

static bool32 EvalOne(const struct HabitatCondition *c, u32 condIndex, u16 spotId,
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

    case COND_TIME_OF_DAY:
    {
        u32 start = c->paramA, end = c->paramB, h;
        RtcCalcLocalTime();
        h = gLocalTime.hours;
        if (start == end)
            return TRUE;                       // degenerate window: whole day
        if (start < end)
            return h >= start && h < end;
        return h >= start || h < end;          // wraps midnight
    }
    case COND_WEATHER:
        return GetCurrentWeather() == c->paramA;
    case COND_DEX_COUNT:
        return Cmp(GetNationalPokedexCount(FLAG_GET_CAUGHT), c->paramA, c->paramB);
    case COND_LIFETIME_STAT:
        return Cmp(GetGameStat(c->paramA), c->paramB, c->paramC);
    case COND_BERRY_MATURE:
    {
        // paramB = zoneId filter (0 = anywhere); zones map to berry-tree id ranges.
        u32 i, berry = ItemIdToBerryType(c->paramA);
        u32 first = 0, last = BERRY_TREES_COUNT - 1;
        if (c->paramB != 0)
        {
            const struct HabitatZone *zone = Habitat_GetZone(c->paramB);
            if (zone == NULL || (zone->berryTreeIdFirst == 0 && zone->berryTreeIdLast == 0))
                return FALSE;  // zone has no trees
            first = zone->berryTreeIdFirst;
            last = zone->berryTreeIdLast;
        }
        for (i = first; i <= last && i < BERRY_TREES_COUNT; i++)
        {
            if (gSaveBlock1Ptr->berryTrees[i].berry == berry
             && gSaveBlock1Ptr->berryTrees[i].stage == BERRY_STAGE_BERRIES)
                return TRUE;
        }
        return FALSE;
    }
    case COND_SPOT_STATE:
        return Habitat_GetSpotState(c->paramA) == c->paramB;
    case COND_ITEM_PLACED:
        // paramA (itemId) is enforced by the PLACE verb; each ITEM_PLACED
        // condition tracks its own counter (multi-furnishing frames, §10).
        return spotId != HABITAT_SPOT_NONE
            && Habitat_GetPlacedCount(spotId, condIndex) >= max(1, c->paramB);
    case COND_ZONE_COMPLETE:
    {
        u32 i;
        bool32 any = FALSE;
        for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
        {
            if (gHabitatSpots[i].zoneId != c->paramA)
                continue;
            any = TRUE;
            if (Habitat_GetSpotState(gHabitatSpots[i].spotId) != HABITAT_STATE_BEFRIENDED)
                return FALSE;
        }
        return any;
    }

    case COND_ITEM_OFFERED:
        return offer != NULL
            && offer->itemId == c->paramA
            && offer->count >= max(1, c->paramB);

    case COND_TALK_COUNT:
        return spotId != HABITAT_SPOT_NONE
            && Habitat_GetTalkCount(spotId) >= max(1, c->paramA);

    case COND_RESIDENT_SPECIES:
        // Dex caught == befriended (spec §5); zone filter (paramB) awaits
        // residents carrying zones — 0 (any) is the supported form.
        return GetSetPokedexFlag(SpeciesToNationalPokedexNum(c->paramA), FLAG_GET_CAUGHT);
    case COND_RESIDENT_COUNT:
    {
        u32 species, n = 0;
        for (species = 1; species < NUM_SPECIES; species++)
        {
            if (!IsSpeciesEnabled(species))
                continue;  // config-disabled families assert in dex-num lookup
            if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                continue;
            if (c->paramA != HABITAT_TYPE_ANY
             && gSpeciesInfo[species].types[0] != c->paramA
             && gSpeciesInfo[species].types[1] != c->paramA)
                continue;
            n++;
        }
        return n >= max(1, c->paramB);
    }

    // Not yet backed by state; each returns FALSE until its phase lands.
    case COND_ILLUSION:           // [phase 4+]
    case COND_GROVE_RECIPE_DONE:  // [phase 4]
    default:
        return FALSE;
    }
}
