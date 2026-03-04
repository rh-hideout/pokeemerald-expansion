#include "global.h"
#include "item.h"
#include "event_data.h"
#include "shop_criteria.h"

bool32 ShopCriteriaByNothing(u32 itemId)
{
    return FALSE;
}

// Always appears from the start, basically.
bool32 ShopCriteriaByTheStart(u32 itemId)
{
    return TRUE;
}

bool32 ShopCriteriaByBadgeCount(u32 itemId)
{
    u32 badgeCount = 0;

    for (u32 badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++)
    {
        if (FlagGet(badgeFlag))
            badgeCount++;
    }

    if (badgeCount >= GetItemShopCriteriaGoal(itemId))
        return TRUE;

    return FALSE;
}

// These two below are somewhat identical to ShopCriteriaByBadgeCount
// but uses only one specific event var/flag check. Useful if you need
// a specific badge flag instead of just the badge total.

bool32 ShopCriteriaByFlag(u32 itemId)
{
    if (FlagGet(GetItemShopCriteriaGoal(itemId)))
        return TRUE;

    return FALSE;
}

bool32 ShopCriteriaByVar(u32 itemId)
{
    u32 criteria = GetItemShopCriteriaGoal(itemId);
    u32 varId = READ_CRITERIA_GOAL_VAR_ID(criteria);
    u32 varValue = READ_CRITERIA_GOAL_VAR_VALUE(criteria);

    if (VarGet(varId) >= varValue)
        return TRUE;

    return FALSE;
}
