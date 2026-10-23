#ifndef GUARD_CONSTANTS_SHOP_H
#define GUARD_CONSTANTS_SHOP_H

// u16 of martitem list to indicate prices are manually inlined
// (instead of reading from item data)
#define MART_LIST_INLINE_PRICES      0xFFFF

enum MartCurrency
{
    MART_CURRENCY_MONEY,
    MART_CURRENCY_BATTLE_POINTS,
};

enum MartMenu
{
    MART_MENU_ACTIONS,   // vanilla Buy/Sell/Quit
    MART_MENU_BUY_ONLY,  // goes directly to buy list (e.g. BP shops)
};

#endif // GUARD_CONSTANTS_SHOP_H
