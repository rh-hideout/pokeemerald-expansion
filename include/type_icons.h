#ifndef GUARD_TYPE_ICONS_H
#define GUARD_TYPE_ICONS_H

#include "constants/battle.h"

#define TYPE_ICON_1_FRAME(monType) ((monType - 1) * 2)
#define TYPE_ICON_2_FRAME(monType) ((monType - 11) * 2)
#define MOVE_TYPE_ICON_FRAME(monType) (monType * 8)

#define TYPE_ICON_TAG 0x2720
#define TYPE_ICON_TAG_2 0x2721
#define MOVE_TYPE_ICON_TAG 30002

#define MOVE_TYPE_ICON_NUM_FRAMES_HIDE 10
#define MOVE_TYPE_ICON_POS (MAX_POSITION_COUNT + 1)

// so the type icon isn't removed out of sync with the rest of the ui
#define MOVE_TYPE_ICON_DO_MOVE_DELAY 11
#define MOVE_TYPE_ICON_BACK_MENU_DELAY 3

#define tMonPosition      data[0]
#define tBattlerId        data[1]
#define tHideIconTimer    data[2]
#define tVerticalPosition data[3]
#define tHide             data[4]

void LoadTypeIcons(u32 battler);
void LoadTypeIconForMoveInfo(enum Type type);
void LoadMoveTypeIconSpritesAndPalettes(void);
void DestroyMoveTypeIconSprite(void);
void TryToHideMoveTypeIconSprite(void);

#endif // GUARD_TYPE_ICONS_H
