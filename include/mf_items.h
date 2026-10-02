#ifndef GUARD_MF_ITEMS_H
#define GUARD_MF_ITEMS_H

#include "global.h"
#include "item.h"

bool32 MfIsTmItem(enum Item itemId);
bool32 MfIsNatureMintItem(enum Item itemId);
bool32 MfAreNatureMintsBuyable(void);

const u8 *MfGetClassicSitrusItemEffect(void);
const u8 *MfGetClassicSitrusDescription(void);

// S43 — PLAYER ITEMS / TRAINER ITEMS. Balls stay legal so catching works.
const u8 *MfGetNoPlayerBattleItemsMessage(void);
bool32 MfIsBattlePokeBall(enum Item itemId);
bool32 MfIsPlayerBattleItemAllowed(enum Item itemId);
bool32 MfAreTrainerBattleItemsAllowed(void);
bool32 MfIsBattlerBattleItemAllowed(bool32 isPlayerSide, enum Item itemId);

#endif // GUARD_MF_ITEMS_H
