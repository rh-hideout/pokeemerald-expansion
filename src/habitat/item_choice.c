// Condition-filtered item selection for habitat interactions. The chooser
// scans every Bag pocket and returns a viable authored item/count without
// changing inventory; removal happens only in Habitat_SubmitItem.
#include "global.h"
#include "habitat/item_choice.h"
#include "habitat/conditions.h"
#include "item.h"

static const struct HabitatCondition *GetConditions(const struct HabitatSpot *spot,
                                                    enum HabitatItemAction action)
{
    if (spot == NULL)
        return NULL;
    switch (action)
    {
    case HABITAT_ITEM_ACTION_PLACE:
        return spot->appearConditions;
    case HABITAT_ITEM_ACTION_OFFER:
        return spot->befriendConditions;
    default:
        return NULL;
    }
}

static bool32 IsWantedType(u8 type, enum HabitatItemAction action)
{
    return (action == HABITAT_ITEM_ACTION_PLACE && type == COND_ITEM_PLACED)
        || (action == HABITAT_ITEM_ACTION_OFFER && type == COND_ITEM_OFFERED);
}

static bool32 BagHasAuthoredCount(u16 itemId, u16 count)
{
    u32 pocket, slot;
    u32 found = 0;

    for (pocket = 0; pocket < POCKETS_COUNT; pocket++)
    {
        for (slot = 0; slot < gBagPockets[pocket].capacity; slot++)
        {
            struct ItemSlot item = GetBagItemIdAndQuantity(pocket, slot);
            if (item.itemId == itemId)
                found += item.quantity;
        }
    }
    return found >= count;
}

bool32 Habitat_FindConditionItem(const struct HabitatSpot *spot,
                                 enum HabitatItemAction action,
                                 struct HabitatItemChoice *choice)
{
    return Habitat_SelectConditionItem(spot, action, ITEM_NONE, choice);
}

bool32 Habitat_SelectConditionItem(const struct HabitatSpot *spot,
                                   enum HabitatItemAction action,
                                   u16 itemId,
                                   struct HabitatItemChoice *choice)
{
    const struct HabitatCondition *conditions = GetConditions(spot, action);
    u32 i;

    if (choice == NULL || conditions == NULL)
        return FALSE;
    for (i = 0; conditions[i].type != COND_NONE && i < HABITAT_MAX_CONDITIONS; i++)
    {
        u16 count = max(1, conditions[i].paramB);

        if (!IsWantedType(conditions[i].type, action))
            continue;
        if (itemId != ITEM_NONE && conditions[i].paramA != itemId)
            continue;
        if (!Habitat_CanSubmitItem(spot, action, conditions[i].paramA, count))
            continue;
        if (!BagHasAuthoredCount(conditions[i].paramA, count))
            continue;
        choice->itemId = conditions[i].paramA;
        choice->count = count;
        return TRUE;
    }
    return FALSE;
}
