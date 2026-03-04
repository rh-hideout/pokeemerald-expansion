#ifndef GUARD_SHOP_CRITERIA_H
#define GUARD_SHOP_CRITERIA_H

// Used by the Buy Menu to avoid way too many items
// than necessary.
#define MAX_DYN_LIST_ITEMS (17)

// used by ShopCriteriaByVar
#define WRITE_CRITERIA_GOAL_VAR(varId, varValue) ((varId << 16) | (varValue))
#define READ_CRITERIA_GOAL_VAR_ID(criteria) ((criteria) >> 16)
#define READ_CRITERIA_GOAL_VAR_VALUE(criteria) ((criteria) & 0xFFFF)

bool32 ShopCriteriaByNothing(u32 itemId);
bool32 ShopCriteriaByTheStart(u32 itemId);
bool32 ShopCriteriaByBadgeCount(u32 itemId);
bool32 ShopCriteriaByFlag(u32 itemId);
bool32 ShopCriteriaByVar(u32 itemId);

#endif // GUARD_SHOP_CRITERIA_H
