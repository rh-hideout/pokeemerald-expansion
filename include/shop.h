#ifndef GUARD_SHOP_H
#define GUARD_SHOP_H

#include "constants/shop.h"

extern struct ItemSlot gMartPurchaseHistory[3];

void CreatePokemartMenu(const u16 *itemsForSale, enum MartCurrency currency, enum MartMenu menu);
void CreateDecorationShop1Menu(const u16 *itemsForSale, enum MartCurrency currency, enum MartMenu menu);
void CreateDecorationShop2Menu(const u16 *itemsForSale, enum MartCurrency currency, enum MartMenu menu);
void CB2_ExitSellMenu(void);

#endif // GUARD_SHOP_H
