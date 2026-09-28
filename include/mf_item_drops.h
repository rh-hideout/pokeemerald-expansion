#ifndef GUARD_MF_ITEM_DROPS_H
#define GUARD_MF_ITEM_DROPS_H

#include "global.h"
#include "item.h"

// Features ITEM DROP (ME tx_Features_WildMonDropItems).
// On wild victory, grant the foe's remaining held item to the bag.

enum MfItemDropMsg
{
    MF_ITEM_DROP_MSG_GRANTED = 0,
    MF_ITEM_DROP_MSG_BAG_FULL = 1,
};

// TRUE when battle-type flags allow wild drops (not trainer / tutorial / etc.).
bool32 MfWildBattleAllowsItemDrops(u32 battleTypeFlags);

// Item to grant from a defeated wild mon's remaining held item.
// Returns ITEM_NONE when the feature is off or heldItem is empty (consumed/stolen).
enum Item MfSelectWildItemDrop(enum Item heldItem, bool32 featureEnabled);

// Try AddBagItem(item, 1). Returns MF_ITEM_DROP_MSG_* for the battle string table.
u32 MfTryGrantWildItemDrop(enum Item item);

// Battle-script native: grant remaining wild held items with a message, then continue.
void BS_TryGiveWildItemDrops(void);

extern const u16 gMfItemDroppedStringIds[];

#endif // GUARD_MF_ITEM_DROPS_H
