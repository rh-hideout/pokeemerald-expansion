#ifndef GUARD_HABITAT_ITEM_CHOICE_H
#define GUARD_HABITAT_ITEM_CHOICE_H

#include "global.h"
#include "habitat/spots.h"

// The condition-filtered chooser does not remove anything. The interaction
// layer submits this exact item/count only after the player confirms it.
struct HabitatItemChoice
{
    u16 itemId;
    u16 count;
    u8 conditionIndex;
};

bool32 Habitat_FindConditionItem(const struct HabitatSpot *spot,
                                 enum HabitatItemAction action,
                                 struct HabitatItemChoice *choice);
bool32 Habitat_SelectConditionItem(const struct HabitatSpot *spot,
                                   enum HabitatItemAction action,
                                   u16 itemId,
                                   struct HabitatItemChoice *choice);
bool32 Habitat_SelectConditionItemAtIndex(const struct HabitatSpot *spot,
                                          enum HabitatItemAction action,
                                          u8 conditionIndex,
                                          struct HabitatItemChoice *choice);

#endif // GUARD_HABITAT_ITEM_CHOICE_H
