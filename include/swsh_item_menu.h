#ifndef GUARD_SWSH_ITEM_MENU_H
#define GUARD_SWSH_ITEM_MENU_H

#include "config/swsh_item_menu.h"

#if SWSH_ITEM_MENU_ACTION_IN_BAG
void BagMenu_OpenPartySelect(u8 taskId);
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
void BagMenu_OpenPartySelectBattle(u8 taskId);
#endif // SWSH_ITEM_MENU_ACTION_IN_BATTLE
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

#endif // GUARD_SWSH_ITEM_MENU_H
