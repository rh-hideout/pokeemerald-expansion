#include "global.h"
#include "event_data.h"
#include "item.h"
#include "mf_items.h"
#include "mf_rules.h"
#include "constants/flags.h"
#include "constants/item_effects.h"
#include "constants/items.h"

// Gen 3 Sitrus: flat 30 HP heal from the bag / battle item path.
static const u8 sItemEffect_SitrusBerryClassic[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = 30,
};

static const u8 sDesc_SitrusBerryClassic[] = _(
    "A held item that\n"
    "restores 30 HP in\n"
    "battle.");

bool32 MfIsTmItem(enum Item itemId)
{
    return itemId >= ITEM_TM01 && itemId <= ITEM_TM100;
}

bool32 MfIsNatureMintItem(enum Item itemId)
{
    return itemId >= ITEM_LONELY_MINT && itemId <= ITEM_SERIOUS_MINT;
}

// ME: On → Pretty Petal after 4th badge; Off → postgame only.
// FR: Celadon Dept Store 2F after Rainbow Badge (BADGE04) when the rule is on.
bool32 MfAreNatureMintsBuyable(void)
{
    if (MfRules_HasMints())
        return FlagGet(FLAG_BADGE04_GET);
    return FlagGet(FLAG_SYS_GAME_CLEAR);
}

const u8 *MfGetClassicSitrusItemEffect(void)
{
    return sItemEffect_SitrusBerryClassic;
}

const u8 *MfGetClassicSitrusDescription(void)
{
    return sDesc_SitrusBerryClassic;
}
