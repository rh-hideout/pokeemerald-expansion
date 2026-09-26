#ifndef GUARD_MF_ITEMS_H
#define GUARD_MF_ITEMS_H

#include "global.h"
#include "item.h"

bool32 MfIsTmItem(enum Item itemId);
bool32 MfIsNatureMintItem(enum Item itemId);
bool32 MfAreNatureMintsBuyable(void);

const u8 *MfGetClassicSitrusItemEffect(void);
const u8 *MfGetClassicSitrusDescription(void);

#endif // GUARD_MF_ITEMS_H
