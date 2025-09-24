#include "global.h"
#include "apricorn_tree.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "item.h"
#include "random.h"
#include "string_util.h"
#include "data/apricorns.h"

static u16 ApricornTypeToItemId(u8 apricorn)
{
    return ApricornTypes[apricorn];
}

void DailyResetApricornTrees(void)
{
    #if (APRICORN_TREE_COUNT > 0)
        memset(&gSaveBlock3Ptr->apricornTrees[0], 0, NUM_APRICORN_TREE_BYTES);
    #endif
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
    #if (APRICORN_TREE_COUNT > 0)
        return gApricornTrees[id].apricornType;
    #else
        return 0;
    #endif
}

u8 GetApricornCountByApricornTreeId(u8 id)
{
    if (IsApricornTreePicked(id))
    {
        return 0;
    }

    #if (APRICORN_TREE_COUNT > 0)
        return gApricornTrees[id].isSapling ? 1 : 2;
    #else
        return 0;
    #endif
}

bool8 IsApricornTreePicked(u8 id)
{
    if (id > APRICORN_TREE_COUNT)
        return TRUE;

    #if (APRICORN_TREE_COUNT > 0)
        bool8 tree = gSaveBlock3Ptr->apricornTrees[id / 8] & (1 << (id % 8));
        return tree;
    #else
        return TRUE;
    #endif
}

void SetApricornTreePicked(u8 id)
{
    if (id > APRICORN_TREE_COUNT)
        return;
    #if (APRICORN_TREE_COUNT > 0)
        u8* flagByte = &gSaveBlock3Ptr->apricornTrees[id / 8];
        *flagByte = (*flagByte) | (1 << (id % 8));
    #endif
}
