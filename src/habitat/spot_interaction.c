// Script-facing interaction layer: specials called from
// data/scripts/habitat_spot.inc. Text placeholders are engine-side; hint
// prose is authored content (spec working agreement).
#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "event_data.h"
#include "habitat/conditions.h"
#include "habitat/events.h"
#include "item.h"
#include "item_menu.h"
#include "battle.h"
#include "random.h"
#include "pokemon.h"
#include "string_util.h"
#include "constants/battle.h"
#include "constants/habitat.h"

static const u8 sText_NotASpot[] = _("PLACEHOLDER: nothing here.$");

// The spot the player is currently talking to. Set by Habitat_OnInspectSpot;
// consumed by the verb specials after the bag round-trip (gSpecialVar_
// LastTalked is not trustworthy across a CB2 change).
static u16 sInteractionSpotId;

u16 Habitat_GetInteractionSpotId(void)
{
    return sInteractionSpotId;
}

static void InspectSpot(const struct HabitatSpot *spot);

// special Habitat_OnInspectSpot — resolves the talked object to a spot,
// counts the talk, buffers {STR_VAR_1}=species name and gStringVar4=staged
// hint, and returns the spot state (or HABITAT_INSPECT_NOT_A_SPOT).
void Habitat_OnInspectSpot(void)
{
    InspectSpot(Habitat_GetSpotByObject(gSaveBlock1Ptr->location.mapGroup,
                                        gSaveBlock1Ptr->location.mapNum,
                                        gSpecialVar_LastTalked));
}

// special Habitat_OnInspectSpotById — bg-sign entry; the map wrapper script
// put the spotId in VAR_0x8004.
void Habitat_OnInspectSpotById(void)
{
    InspectSpot(Habitat_GetSpot(gSpecialVar_0x8004));
}

static void InspectSpot(const struct HabitatSpot *spot)
{
    u8 state;
    const u8 *hint;

    if (spot == NULL)
    {
        sInteractionSpotId = HABITAT_SPOT_NONE;
        StringCopy(gStringVar4, sText_NotASpot);
        gSpecialVar_Result = HABITAT_INSPECT_NOT_A_SPOT;
        return;
    }
    sInteractionSpotId = spot->spotId;

    Habitat_IncrementTalkCount(spot->spotId);
    state = Habitat_GetSpotState(spot->spotId);
    switch (state)
    {
    case HABITAT_STATE_DORMANT:  hint = spot->hintDormant;  break;
    case HABITAT_STATE_STIRRING: hint = spot->hintStirring; break;
    default:                     hint = spot->hintActive;   break;
    }
    // Expand ROM hint -> gStringVar4 NOW (species name via {STR_VAR_1}).
    // The field-message pipeline re-expands gStringVar4 into itself at
    // display time; a with-placeholders self-expansion shifts lengths over
    // an overlapping buffer and corrupts EWRAM (found the hard way in the
    // M1 phase 2 headless runs). Text handed to msgbox from gStringVar4
    // must always arrive here fully expanded.
    StringCopy(gStringVar1, GetSpeciesName(spot->species));
    StringExpandPlaceholders(gStringVar4, hint);
    gSpecialVar_Result = state;
}

// specialvar VAR_RESULT, Habitat_TryOffer — after the berry-bag round trip.
// gSpecialVar_ItemId holds the chosen item. Consumes it only on success.
u16 Habitat_TryOffer(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(sInteractionSpotId);
    struct HabitatOfferContext offer = { .itemId = gSpecialVar_ItemId, .count = 1 };
    struct HabitatConditionResult r;

    if (spot == NULL || Habitat_GetSpotState(spot->spotId) != HABITAT_STATE_ACTIVE)
        return FALSE;
    Habitat_EvaluateConditions(spot->befriendConditions, spot->spotId, &offer, &r);
    if (!r.allMet)
        return FALSE;
    RemoveBagItem(gSpecialVar_ItemId, 1);
    Habitat_CompleteBefriendById(spot->spotId);
    return TRUE;
}

// specialvar VAR_RESULT, Habitat_TryPlaceItem — the PLACE verb. The spot's
// COND_ITEM_PLACED names the item it wants (paramA); one is moved from the
// bag to the spot. Recompute runs via the inventory event so a newly
// satisfied appear list manifests the Pokémon immediately.
u16 Habitat_TryPlaceItem(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(sInteractionSpotId);
    const struct HabitatCondition *c;
    u32 i;

    if (spot == NULL)
        return FALSE;
    for (i = 0; spot->appearConditions[i].type != COND_NONE; i++)
    {
        c = &spot->appearConditions[i];
        if (c->type != COND_ITEM_PLACED)
            continue;
        if (Habitat_GetPlacedCount(spot->spotId, i) >= max(1, c->paramB))
            continue;  // this furnishing is already set down
        if (!CheckBagHasItem(c->paramA, 1))
            continue;  // don't have this one; maybe the next
        RemoveBagItem(c->paramA, 1);
        Habitat_AddPlacedCount(spot->spotId, i, 1);
        Habitat_NotifyEvent(HABITAT_EVENT_INVENTORY_CHANGE);
        return TRUE;
    }
    return FALSE;
}

// ---- the friendly bout (§7 battle-as-condition; Machop) ----

// special: TRUE if the interaction spot befriends through a bout.
u16 Habitat_SpotWantsBout(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(sInteractionSpotId);
    u32 i;
    if (spot == NULL)
        return FALSE;
    for (i = 0; spot->befriendConditions[i].type != COND_NONE; i++)
    {
        if (spot->befriendConditions[i].type == COND_BATTLE_WIN)
            return TRUE;
    }
    return FALSE;
}

// special: stage the bout. PLACEHOLDER BATTLER (question batched for Jay):
// the party layer is deferred, so the first resident steps up as a temp
// party member; no residents -> the bout is declined. Level 50 keeps dev
// losses (and the ugly empty-party whiteout path) unlikely.
u16 Habitat_PrepareBout(void)
{
    const struct HabitatResident *r = Habitat_GetResident(0);
    if (r == NULL)
        return FALSE;
    ZeroPlayerPartyMons();
    CreateMon(&gPlayerParty[0], r->species, 50, Random32(), OTID_STRUCT_PLAYER_ID);
    CalculatePlayerPartyCount();
    StringCopy(gStringVar2, GetSpeciesName(r->species));
    return TRUE;
}

// special: settle the bout — restore the empty party, set the spot-local
// win flag on victory, and let recompute auto-befriend (BATTLE_WIN list).
u16 Habitat_ResolveBout(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(sInteractionSpotId);
    bool32 won = gBattleOutcome == B_OUTCOME_WON;
    ZeroPlayerPartyMons();
    if (spot != NULL && won)
    {
        Habitat_AddSpotLocalFlags(spot->spotId, HABITAT_SPOT_LOCAL_BATTLE_WON);
        Habitat_RecomputeSpot(spot);
    }
    return won;
}
