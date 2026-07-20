// Script-facing interaction layer: specials called from
// data/scripts/habitat_spot.inc. Text placeholders are engine-side; hint
// prose is authored content (spec working agreement).
#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "habitat/item_choice.h"
#include "event_data.h"
#include "habitat/conditions.h"
#include "habitat/events.h"
#include "item.h"
#include "item_menu.h"
#include "string_util.h"
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

#if TESTING
void Habitat_SetInteractionSpotForTest(u16 spotId)
{
    sInteractionSpotId = spotId;
}
#endif

static void InspectSpot(const struct HabitatSpot *spot);
static bool32 HasUnmetPlacement(const struct HabitatSpot *spot, u16 itemId, u16 count);
static bool32 HasActiveOffer(const struct HabitatSpot *spot, u16 itemId, u16 count);

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

// specialvar VAR_RESULT, Habitat_TryOffer — the preview or selector places
// the confirmed choice in gSpecialVar_ItemId. Consumes it only on success.
u16 Habitat_TryOffer(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(sInteractionSpotId);
    struct HabitatItemChoice choice;

    if (!Habitat_SelectConditionItem(spot, HABITAT_ITEM_ACTION_OFFER,
                                     gSpecialVar_ItemId, &choice))
        return FALSE;
    return Habitat_SubmitItem(spot, HABITAT_ITEM_ACTION_OFFER,
                              choice.itemId, choice.count);
}

// specialvar VAR_RESULT, Habitat_TryPlaceItem — the PLACE verb. The spot's
// COND_ITEM_PLACED names the item it wants (paramA); one is moved from the
// bag to the spot. Recompute runs via the inventory event so a newly
// satisfied appear list manifests the Pokémon immediately.
u16 Habitat_TryPlaceItem(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(sInteractionSpotId);
    struct HabitatItemChoice choice;

    if (!Habitat_FindConditionItem(spot, HABITAT_ITEM_ACTION_PLACE, &choice))
        return FALSE;
    return Habitat_SubmitItem(spot, HABITAT_ITEM_ACTION_PLACE, choice.itemId, choice.count);
}

static u16 PreviewItemAction(enum HabitatItemAction action, u16 selectedItemId)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(sInteractionSpotId);
    struct HabitatItemChoice choice;

    if (!Habitat_SelectConditionItem(spot, action, selectedItemId, &choice))
        return FALSE;
    gSpecialVar_ItemId = choice.itemId;
    CopyItemName(choice.itemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, choice.count, STR_CONV_MODE_LEFT_ALIGN, 2);
    return TRUE;
}

u16 Habitat_PreviewOfferItem(void)
{
    return PreviewItemAction(HABITAT_ITEM_ACTION_OFFER, ITEM_NONE);
}

u16 Habitat_PreviewPlaceItem(void)
{
    return PreviewItemAction(HABITAT_ITEM_ACTION_PLACE, ITEM_NONE);
}

// Script-facing offer selector. A declined preview advances to the next
// viable authored offer; exhausting the choices returns FALSE without moving
// any inventory, so the script can leave or offer PLACE instead.
u16 Habitat_SelectOfferItem(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpot(sInteractionSpotId);
    struct HabitatItemChoice choice;
    u32 i;
    bool32 afterCurrent = FALSE;

    if (spot == NULL)
        return FALSE;
    for (i = 0; spot->befriendConditions[i].type != COND_NONE && i < HABITAT_MAX_CONDITIONS; i++)
    {
        const struct HabitatCondition *c = &spot->befriendConditions[i];
        if (c->type != COND_ITEM_OFFERED)
            continue;
        if (!afterCurrent)
        {
            if (c->paramA == gSpecialVar_ItemId)
                afterCurrent = TRUE;
            continue;
        }
        if (!Habitat_SelectConditionItem(spot, HABITAT_ITEM_ACTION_OFFER,
                                         c->paramA, &choice))
            continue;
        gSpecialVar_ItemId = choice.itemId;
        CopyItemName(choice.itemId, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, choice.count, STR_CONV_MODE_LEFT_ALIGN, 2);
        return TRUE;
    }
    return FALSE;
}

static bool32 HasUnmetPlacement(const struct HabitatSpot *spot, u16 itemId, u16 count)
{
    const struct HabitatCondition *c;
    u32 i;

    if (spot == NULL)
        return FALSE;
    for (i = 0; spot->appearConditions[i].type != COND_NONE && i < HABITAT_MAX_CONDITIONS; i++)
    {
        c = &spot->appearConditions[i];
        if (c->type == COND_ITEM_PLACED
         && c->paramA == itemId
         && max(1, c->paramB) == count
         && Habitat_GetPlacedCount(c->paramC) < count)
            return TRUE;
    }
    return FALSE;
}

static bool32 HasActiveOffer(const struct HabitatSpot *spot, u16 itemId, u16 count)
{
    struct HabitatOfferContext offer = { .itemId = itemId, .count = count };
    struct HabitatConditionResult result;
    u32 i;
    bool32 matchesWant = FALSE;

    if (spot == NULL || Habitat_GetSpotState(spot->spotId) != HABITAT_STATE_ACTIVE)
        return FALSE;
    for (i = 0; spot->befriendConditions[i].type != COND_NONE && i < HABITAT_MAX_CONDITIONS; i++)
    {
        const struct HabitatCondition *c = &spot->befriendConditions[i];
        if (c->type == COND_ITEM_OFFERED
         && c->paramA == itemId
         && max(1, c->paramB) == count)
            matchesWant = TRUE;
    }
    if (!matchesWant)
        return FALSE;
    Habitat_EvaluateConditions(spot->befriendConditions, spot->spotId, &offer, &result);
    return result.allMet;
}

bool32 Habitat_CanSubmitItem(const struct HabitatSpot *spot,
                             enum HabitatItemAction action,
                             u16 itemId, u16 count)
{
    if (itemId == ITEM_NONE || count == 0)
        return FALSE;
    switch (action)
    {
    case HABITAT_ITEM_ACTION_PLACE:
        return HasUnmetPlacement(spot, itemId, count);
    case HABITAT_ITEM_ACTION_OFFER:
        return HasActiveOffer(spot, itemId, count);
    default:
        return FALSE;
    }
}

bool32 Habitat_SubmitItem(const struct HabitatSpot *spot,
                          enum HabitatItemAction action,
                          u16 itemId, u16 count)
{
    u8 placedBefore;
    const struct HabitatCondition *c;
    u32 i;

    if (!Habitat_CanSubmitItem(spot, action, itemId, count)
     || !CheckBagHasItem(itemId, count)
     || !RemoveBagItem(itemId, count))
        return FALSE;

    if (action == HABITAT_ITEM_ACTION_OFFER)
    {
        Habitat_CompleteBefriendById(spot->spotId);
        if (Habitat_GetSpotState(spot->spotId) == HABITAT_STATE_BEFRIENDED)
            return TRUE;
        AddBagItem(itemId, count);
        return FALSE;
    }

    for (i = 0; spot->appearConditions[i].type != COND_NONE && i < HABITAT_MAX_CONDITIONS; i++)
    {
        c = &spot->appearConditions[i];
        if (c->type != COND_ITEM_PLACED || c->paramA != itemId || max(1, c->paramB) != count
         || Habitat_GetPlacedCount(c->paramC) >= count)
            continue;
        placedBefore = Habitat_GetPlacedCount(c->paramC);
        Habitat_AddPlacedCount(c->paramC, count);
        if (Habitat_GetPlacedCount(c->paramC) >= placedBefore + count)
        {
            Habitat_RecomputeSpot(spot);
            Habitat_NotifyEvent(HABITAT_EVENT_INVENTORY_CHANGE);
            return TRUE;
        }
        Habitat_SetPlacedCount(c->paramC, placedBefore);
        AddBagItem(itemId, count);
        return FALSE;
    }
    AddBagItem(itemId, count);
    return FALSE;
}

u8 Habitat_GetAvailableVerbs(const struct HabitatSpot *spot)
{
    u8 verbs = 0;
    u32 i;
    s32 residentIdx;
    struct HabitatItemChoice choice;

    if (spot == NULL)
        return 0;
    verbs = HABITAT_VERB_INSPECT;
    for (i = 0; spot->appearConditions[i].type != COND_NONE && i < HABITAT_MAX_CONDITIONS; i++)
    {
        const struct HabitatCondition *c = &spot->appearConditions[i];
        if (c->type == COND_ITEM_PLACED
         && Habitat_GetPlacedCount(c->paramC) < max(1, c->paramB))
            verbs |= HABITAT_VERB_PLACE;
    }
    if (Habitat_GetSpotState(spot->spotId) == HABITAT_STATE_ACTIVE
     && Habitat_FindConditionItem(spot, HABITAT_ITEM_ACTION_OFFER, &choice))
        verbs |= HABITAT_VERB_OFFER;
    if (Habitat_GetSpotState(spot->spotId) == HABITAT_STATE_BEFRIENDED)
    {
        residentIdx = Habitat_FindResidentBySpot(spot->spotId);
        if (residentIdx >= 0 && !Habitat_ResidentIsOut(residentIdx))
            verbs |= HABITAT_VERB_RECRUIT;
    }
    return verbs;
}

u16 Habitat_GetInteractionAvailableVerbs(void)
{
    return Habitat_GetAvailableVerbs(Habitat_GetSpot(sInteractionSpotId));
}
