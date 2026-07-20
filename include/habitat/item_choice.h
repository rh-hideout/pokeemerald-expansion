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
};

bool32 Habitat_FindConditionItem(const struct HabitatSpot *spot,
                                 enum HabitatItemAction action,
                                 struct HabitatItemChoice *choice);

#endif // GUARD_HABITAT_ITEM_CHOICE_H
