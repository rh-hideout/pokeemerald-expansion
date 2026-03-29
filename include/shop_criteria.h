#ifndef GUARD_SHOP_CRITERIA_H
#define GUARD_SHOP_CRITERIA_H

// Used by the Buy Menu to avoid way too many items
// than necessary.
#define MAX_DYN_LIST_ITEMS (17)

void TryBuildDynamicShopItemList(const u16 **ogItemList, u16 *resultingTotal);
void TryFreeDynamicShopItemList(const u16 **ogItemList);
bool32 ShopCriteriaByTheStart(u32 itemId);

#endif // GUARD_SHOP_CRITERIA_H
