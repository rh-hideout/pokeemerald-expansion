// The spot state machine (spec §2). Recomputation is event-driven — wired
// through Habitat_NotifyEvent — and scoped to the current map: sprites only
// exist here, and chain conditions read other spots' saved state directly.
#include "global.h"
#include "habitat/events.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "event_data.h"
#include "pokedex.h"

static void CompleteBefriend(const struct HabitatSpot *spot);
static const struct HabitatSpot *FindSpot(u16 spotId);

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
    u32 i;
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;

    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        if (gHabitatSpots[i].mapGroup == mapGroup && gHabitatSpots[i].mapNum == mapNum)
            Habitat_RecomputeSpot(&gHabitatSpots[i]);
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
    u16 dexNum = SpeciesToNationalPokedexNum(spot->species);

    if (Habitat_GetSpotState(spot->spotId) == HABITAT_STATE_BEFRIENDED)
        return;
    Habitat_SetSpotState(spot->spotId, HABITAT_STATE_BEFRIENDED);
    GetSetPokedexFlag(dexNum, FLAG_SET_SEEN);
    GetSetPokedexFlag(dexNum, FLAG_SET_CAUGHT);
    Habitat_TryAddResident(spot->spotId);  // -1 past the cap is fine (spec §5)
    Habitat_SyncSpotObjectFlag(spot);
    Habitat_NotifyEvent(HABITAT_EVENT_RESIDENT_CHANGE);
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
