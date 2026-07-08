#ifndef GUARD_CONFIG_SWSH_ITEM_MENU_H
#define GUARD_CONFIG_SWSH_ITEM_MENU_H

#define SWSH_ITEM_MENU                    TRUE  // Use SwSh bag menu

#define SWSH_ITEM_MENU_TMHM_CONTEST_INFO  (SWSH_ITEM_MENU && TRUE)  // Show contest info for TMs/HMs in the item menu
#define SWSH_ITEM_MENU_BERRY_INFO         TRUE  // Show berry info in the item menu
#define SWSH_ITEM_MENU_CHECK_BERRY_TAG    FALSE // Keep or turn off the vanilla berry tag check
#define SWSH_ITEM_MENU_SCROLLING_BG       TRUE  // Enable scrolling background

#define SWSH_ITEM_MENU_ACTION_IN_BAG      (SWSH_ITEM_MENU && TRUE)  // Perform item actions (Use/Give) in bag (avoid opening party menu)
#define SWSH_ITEM_MENU_PARTY_HP_BAR       (SWSH_ITEM_MENU_ACTION_IN_BAG && TRUE)    // Show HP bar in party slot during item use
#define SWSH_ITEM_MENU_ACTION_IN_BATTLE   (SWSH_ITEM_MENU_ACTION_IN_BAG && TRUE)    // Use items directly in bag during battle (without opening party menu)

#define SWSH_ITEM_MENU_PYRAMID_BAG        (SWSH_ITEM_MENU && TRUE)  // Use the SwSh bag for the Battle Pyramid
#define SWSH_ITEM_MENU_PYRAMID_ACTION     (SWSH_ITEM_MENU_PYRAMID_BAG && SWSH_ITEM_MENU_ACTION_IN_BAG && TRUE)  // Perform inline Use/Give in the pyramid bag

#endif // GUARD_CONFIG_SWSH_ITEM_MENU_H
