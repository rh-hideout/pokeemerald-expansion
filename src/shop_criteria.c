#include "global.h"
#include "item.h"
#include "script.h"
#include "event_data.h"
#include "malloc.h"
#include "shop_criteria.h"

static EWRAM_DATA u16 *sDynamicShopItemsListPtr = NULL;
static EWRAM_DATA const u16 *sDynamicShopItemListRef = NULL;

// Remove the UNUSED if you'll use the functions!
static UNUSED bool32 ShopCriteriaByBadgeCount(u32 count);
static UNUSED bool32 ShopCriteriaByFlag(u32 flagId);
static UNUSED bool32 ShopCriteriaByVar(u32 varId, u32 varValue);

void TryBuildDynamicShopItemList(const u16 **ogItemList, u16 *resultingTotal)
{
    sDynamicShopItemListRef = *ogItemList;
    sDynamicShopItemsListPtr = AllocZeroed(MAX_DYN_LIST_ITEMS * sizeof(u16));

    u32 overallIdx = 0;

    for (u32 itemId = 0; itemId < ITEMS_COUNT; itemId++)
    {
        if (IsItemShopCriteriaFulfilled(itemId))
        {
            sDynamicShopItemsListPtr[overallIdx] = itemId;
            overallIdx++;
        }

        if (overallIdx == MAX_DYN_LIST_ITEMS)
            break;
    }

    *ogItemList = sDynamicShopItemsListPtr;
    *resultingTotal = overallIdx;
}

void TryFreeDynamicShopItemList(const u16 **ogItemList)
{
    TRY_FREE_AND_SET_NULL(sDynamicShopItemsListPtr);
    *ogItemList = sDynamicShopItemListRef;
}

bool32 ShopCriteriaByTheStart(u32 itemId)
{
    return TRUE;
}

static UNUSED bool32 ShopCriteriaByBadgeCount(u32 count)
{
    u32 badgeCount = 0;

    for (u32 badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++)
    {
        if (FlagGet(badgeFlag))
            badgeCount++;
    }

    if (badgeCount >= count)
        return TRUE;

    return FALSE;
}

// These two below are somewhat identical to ShopCriteriaByBadgeCount
// but uses only one specific event var/flag check. Useful if you need
// a specific badge flag instead of just the badge total.

static UNUSED bool32 ShopCriteriaByFlag(u32 flagId)
{
    if (FlagGet(flagId))
        return TRUE;

    return FALSE;
}

static UNUSED bool32 ShopCriteriaByVar(u32 varId, u32 varValue)
{
    if (VarGet(varId) >= varValue)
        return TRUE;

    return FALSE;
}
