#include "global.h"
#include "apricorn_tree.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "item.h"
#include "random.h"
#include "string_util.h"
#include "data/apricorns.h"

void DailyResetApricornTrees(void)
{
    memset(&gSaveBlock3Ptr->apricornTrees[0], 0, NUM_APRICORN_TREE_BYTES);
}

void ObjectEventInteractionGetApricornTreeData(void)
{
    u8 id;
    u8 apricorn;

    id = GetObjectEventApricornTreeId(gSelectedObjectEvent);
    apricorn = GetApricornTypeByApricornTreeId(id);
    gSpecialVar_0x8004 = ApricornTypeToItemId(apricorn);
    gSpecialVar_0x8005 = GetApricornCountByApricornTreeId(id);
    CopyItemNameHandlePlural(gSpecialVar_0x8004, gStringVar1, gSpecialVar_0x8005);
}

void ObjectEventInteractionPickApricornTree(void)
{
    u8 id = GetObjectEventApricornTreeId(gSelectedObjectEvent);
    u8 apricorn = GetApricornTypeByApricornTreeId(id);

    gSpecialVar_0x8006 = CheckBagHasSpace(ApricornTypeToItemId(apricorn), GetApricornCountByApricornTreeId(id));
    if (gSpecialVar_0x8006)
    {
        AddBagItem(ApricornTypeToItemId(apricorn), GetApricornCountByApricornTreeId(id));
        SetApricornTreePicked(id);
    }
}

u8 GetApricornTypeByApricornTreeId(u8 id)
{
    return gApricornTrees[id].apricornType;
}

u8 GetApricornCountByApricornTreeId(u8 id)
{
    if (IsApricornTreePicked(id))
    {
        return 0;
    }

    return gApricornTrees[id].isSapling ? 1 : 2;
}

static u16 ApricornTypeToItemId(u8 apricorn)
{
    return ApricornTypes[apricorn];
}

bool8 IsApricornTreePicked(u8 id)
{
    if (id > APRICORN_TREE_COUNT)
        return TRUE;

    bool8 tree = gSaveBlock3Ptr->apricornTrees[id / 8] & (1 << (id % 8));
    return tree;
}

void SetApricornTreePicked(u8 id)
{
    if (id > APRICORN_TREE_COUNT)
        return;

    u8* flagByte = &gSaveBlock3Ptr->apricornTrees[id / 8];
    *flagByte = (*flagByte) | (1 << (id % 8));
}
