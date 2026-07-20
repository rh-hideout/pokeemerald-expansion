// The spot state machine (spec §2). Recomputation is event-driven — wired
// through Habitat_NotifyEvent — and scoped to the current map: sprites only
// exist here, and chain conditions read other spots' saved state directly.
#include "global.h"
#include "habitat/events.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "event_data.h"
#include "pokedex.h"
#include "constants/event_objects.h"
#include "constants/vars.h"

static void CompleteBefriend(const struct HabitatSpot *spot);
static const struct HabitatSpot *FindSpot(u16 spotId);

#if TESTING
static const struct HabitatMapSpan *sTestMapSpans;

void Habitat_SetMapSpansForTest(const struct HabitatMapSpan *spans)
{
    sTestMapSpans = spans;
}
#endif

// The hide flag is the single source of truth the object-event system reads:
// set = hidden. Home-by-default (§3): visible iff ACTIVE, or BEFRIENDED and
// its resident is not out at the Grove. Spot→resident is the first registry
// match on their origin spot, so identical species at different locations do
// not hide or recruit one another.
void Habitat_SyncSpotObjectFlag(const struct HabitatSpot *spot)
{
    u8 state = Habitat_GetSpotState(spot->spotId);
    bool32 home = TRUE;
    if (state == HABITAT_STATE_BEFRIENDED)
    {
        s32 residentIdx = Habitat_FindResidentBySpot(spot->spotId);
        if (residentIdx >= 0 && Habitat_ResidentIsOut(residentIdx))
            home = FALSE;
    }
    bool32 visible = (state == HABITAT_STATE_ACTIVE)
                  || (state == HABITAT_STATE_BEFRIENDED && home);
    if (visible)
        FlagClear(spot->hideFlag);
    else
        FlagSet(spot->hideFlag);
}

void Habitat_RecomputeSpot(const struct HabitatSpot *spot)
{
    u8 state = Habitat_GetSpotState(spot->spotId);
    struct HabitatConditionResult r;

    if (state < HABITAT_STATE_ACTIVE)
    {
        Habitat_EvaluateConditions(spot->appearConditions, spot->spotId, NULL, &r);
        if (r.allMet)
            Habitat_SetSpotState(spot->spotId, HABITAT_STATE_ACTIVE);
        else if (r.anyMet)
            Habitat_SetSpotState(spot->spotId, HABITAT_STATE_STIRRING);
        state = Habitat_GetSpotState(spot->spotId);
    }

    if (state == HABITAT_STATE_ACTIVE)
    {
        // Offer-less befriending: a befriend list that passes with no offer
        // in progress completes on recompute.
        // Lists containing COND_ITEM_OFFERED can never pass here (offer==NULL),
        // so offer-driven spots still resolve only through the offer verb.
        Habitat_EvaluateConditions(spot->befriendConditions, spot->spotId, NULL, &r);
        if (r.allMet)
            CompleteBefriend(spot);
    }

    Habitat_SyncSpotObjectFlag(spot);
}

void Habitat_RecomputeCurrentMapSpots(void)
{
    Habitat_RecomputeCurrentMapDependencies(HABITAT_DEP_MASK_ALL);
}

const struct HabitatMapSpan *Habitat_GetMapSpan(u8 mapGroup, u8 mapNum)
{
    const struct HabitatMapSpan *spans = gHabitatMapSpans;
    u32 i;

#if TESTING
    if (sTestMapSpans != NULL)
        spans = sTestMapSpans;
#endif

    for (i = 0; spans[i].count != 0; i++)
    {
        if (spans[i].mapGroup == mapGroup && spans[i].mapNum == mapNum)
            return &spans[i];
    }
    return NULL;
}

void Habitat_RecomputeCurrentMapDependencies(u32 dependencyMask)
{
    const struct HabitatSpot *spots = Habitat_GetSpotTable();
    const struct HabitatMapSpan *span = Habitat_GetMapSpan(gSaveBlock1Ptr->location.mapGroup,
                                                            gSaveBlock1Ptr->location.mapNum);
    u32 i;

    if (span == NULL)
        return;
    for (i = span->firstSpot; i < span->firstSpot + span->count; i++)
    {
        if (dependencyMask == HABITAT_DEP_MASK_ALL
         || (spots[i].dependencyMask & dependencyMask))
            Habitat_RecomputeSpot(&spots[i]);
    }
}

// The lab frames use map object graphics variables, so their chosen starter
// is restored before object events are loaded on every map transition.
void Habitat_PrepareLabFrames(void)
{
    const struct HabitatSpot *spots = Habitat_GetSpotTable();
    u32 i;

    for (i = 0; spots[i].spotId != 0xFFFF; i++)
    {
        u16 species;

        if (spots[i].graphicsVar == 0)
            continue;
        species = Habitat_GetResolvedSpotSpecies(&spots[i]);

        VarSet(spots[i].graphicsVar, species == SPECIES_NONE
               ? OBJ_EVENT_GFX_ITEM_BALL : OBJ_EVENT_MON + species);
    }
}

// Befriend resolution — shared by the offer verb and offer-less recompute.
// Spec §2 BEFRIENDED: dex "caught" flag set (== resident per §5), sprite
// becomes ambient or hides per spot flag, residents notified (phase 3).
void Habitat_CompleteBefriendById(u16 spotId)
{
    const struct HabitatSpot *spot = FindSpot(spotId);
    if (spot != NULL)
        CompleteBefriend(spot);
}

static void CompleteBefriend(const struct HabitatSpot *spot)
{
    u16 species = Habitat_GetResolvedSpotSpecies(spot);
    u16 dexNum;

    if (Habitat_GetSpotState(spot->spotId) == HABITAT_STATE_BEFRIENDED)
        return;
    if (species == SPECIES_NONE)
        return;
    dexNum = SpeciesToNationalPokedexNum(species);
    Habitat_SetSpotState(spot->spotId, HABITAT_STATE_BEFRIENDED);
    GetSetPokedexFlag(dexNum, FLAG_SET_SEEN);
    GetSetPokedexFlag(dexNum, FLAG_SET_CAUGHT);
    Habitat_TryAddResident(spot->spotId);  // -1 past the cap is fine (spec §5)
    Habitat_SyncSpotObjectFlag(spot);
    Habitat_NotifyDependency(HABITAT_DEP_RESIDENT);
}

static const struct HabitatSpot *FindSpot(u16 spotId)
{
    const struct HabitatSpot *spots = Habitat_GetSpotTable();
    u32 i;

    for (i = 0; spots[i].spotId != 0xFFFF; i++)
        if (spots[i].spotId == spotId)
            return &spots[i];
    return NULL;
}
