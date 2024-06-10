#ifndef GUARD_NEW_SHOP_H
#define GUARD_NEW_SHOP_H

#ifdef MUDSKIP_SHOP_UI
void NewShop_CreatePokemartMenu(const u16 *);
void NewShop_CreateDecorationShop1Menu(const u16 *);
void NewShop_CreateDecorationShop2Menu(const u16 *);
void CB2_ExitSellNewShopMenu(void);

#ifdef MUDSKIP_OUTFIT_SYSTEM
void NewShop_CreateOutfitShopMenu(const u16 *);
#endif // MUDSKIP_OUTFIT_SYSTEM

void NewShop_CreateVariablePokemartMenu(const u16 *);

#endif // MUDSKIP_SHOP_UI

#endif // GUARD_NEW_SHOP_H
