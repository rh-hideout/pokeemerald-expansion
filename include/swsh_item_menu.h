#ifndef GUARD_SWSH_ITEM_MENU_H
#define GUARD_SWSH_ITEM_MENU_H

#include "config/swsh_item_menu.h"

#if SWSH_ITEM_MENU_IN_BAG_USE
void BagMenu_OpenPartySelect(u8 taskId);
#if SWSH_ITEM_MENU_IN_BATTLE_USE
void BagMenu_OpenPartySelectBattle(u8 taskId);
#endif // SWSH_ITEM_MENU_IN_BATTLE_USE
#endif // SWSH_ITEM_MENU_IN_BAG_USE

#endif // GUARD_SWSH_ITEM_MENU_H
