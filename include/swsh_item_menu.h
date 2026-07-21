#ifndef GUARD_SWSH_ITEM_MENU_H
#define GUARD_SWSH_ITEM_MENU_H

#define SWSH_ITEM_MENU                  TRUE  // Use SwSh bag menu

#define SWSH_ITEM_MENU_CONTEST_INFO     (SWSH_ITEM_MENU && TRUE)                // Show contest info for TMs/HMs in the item menu
#define SWSH_ITEM_MENU_BERRY_STAT       (SWSH_ITEM_MENU && FALSE)               // Show berry stat (flavors, size, etc.) in the item menu
#define SWSH_ITEM_MENU_BERRY_TAG        (SWSH_ITEM_MENU_BERRY_STAT && FALSE)    // Show berry tag info
#define SWSH_ITEM_MENU_SCROLLING_BG     (SWSH_ITEM_MENU && TRUE)                // Enable scrolling background (BG3)

#define SWSH_ITEM_MENU_IN_BAG_USE       (SWSH_ITEM_MENU && TRUE)                // Perform item actions (Use/Give) in bag (skip party menu)
#define SWSH_ITEM_MENU_IN_BAG_REUSE     (SWSH_ITEM_MENU_IN_BAG_USE && TRUE)     // Keep item cursor in party after use/give
#define SWSH_ITEM_MENU_IN_BATTLE_USE    (SWSH_ITEM_MENU_IN_BAG_USE && TRUE)     // Use items in bag during battle (skip party menu)
#define SWSH_ITEM_MENU_PARTY_HP_BAR     (SWSH_ITEM_MENU_IN_BAG_USE && TRUE)     // Show HP bar in party slot for certain items usage

#define SWSH_ITEM_MENU_PYRAMID          (SWSH_ITEM_MENU && TRUE)                // Use SwSh bag menu for the Battle Pyramid
#define SWSH_ITEM_MENU_PYRAMID_ACTION   (SWSH_ITEM_MENU_PYRAMID && SWSH_ITEM_MENU_IN_BAG_USE)   // Perform inline Use/Give in the pyramid bag

#define SWSH_ITEM_MENU_BATTLE_POCKETS   (SWSH_ITEM_MENU && TRUE)                // In battle, show battle pockets (Medicine/Poké Balls/Battle Items/Berries) instead of the field pockets

#if SWSH_ITEM_MENU_IN_BAG_USE
void BagMenu_OpenPartySelect(u8 taskId);
#if SWSH_ITEM_MENU_IN_BATTLE_USE
void BagMenu_OpenPartySelectBattle(u8 taskId);
#endif // SWSH_ITEM_MENU_IN_BATTLE_USE
#endif // SWSH_ITEM_MENU_IN_BAG_USE

#endif // GUARD_SWSH_ITEM_MENU_H
