#include "global.h"
#include "factory_custom_mon.h"
#include "pokemon.h"

void CreateFactoryCustomMon(struct Pokemon *mon, const struct FactoryCustomMonBuild *build, u8 level, u8 fixedIV)
{
    u8 i;
    u8 value;

    CreateMonWithNature(mon, build->species, level, fixedIV, build->nature);
    SetMonData(mon, MON_DATA_HELD_ITEM, &build->heldItem);
    SetMonData(mon, MON_DATA_ABILITY_NUM, &build->abilityNum);
    if (build->hasTeraType)
        SetMonData(mon, MON_DATA_TERA_TYPE, &build->teraType);

    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, build->moves[i], i);

    for (i = 0; i < NUM_STATS; i++)
    {
        value = build->evs[i];
        SetMonData(mon, MON_DATA_HP_EV + i, &value);
    }

    CalculateMonStats(mon);
}
