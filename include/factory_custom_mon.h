#ifndef GUARD_FACTORY_CUSTOM_MON_H
#define GUARD_FACTORY_CUSTOM_MON_H

#include "global.h"
#include "constants/pokemon.h"

struct FactoryCustomMonBuild
{
    u16 species;
    u8 nature;
    u16 heldItem;
    u8 abilityNum;
    bool8 hasTeraType;
    u8 teraType;
    u8 evs[NUM_STATS];
    u16 moves[MAX_MON_MOVES];
};

void CreateFactoryCustomMon(struct Pokemon *mon, const struct FactoryCustomMonBuild *build, u8 level, u8 fixedIV);

#endif // GUARD_FACTORY_CUSTOM_MON_H
