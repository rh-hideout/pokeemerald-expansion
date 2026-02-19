#include "global.h"
#include "event_data.h"
#include "factory_boss.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/opponents.h"
#include "constants/event_objects.h"
#include "constants/songs.h"
#include "constants/species.h"

#include "data/battle_factory/factory_boss_text_sets.h"

static const struct FactoryBossProfile sFactoryBossProfiles[FACTORY_BOSS_COUNT] =
{
#include "data/battle_factory/factory_boss_profiles.h"
};

u8 GetActiveFactoryBossId(void)
{
    u16 bossId = VarGet(VAR_FACTORY_ACTIVE_BOSS);

    if (bossId < FACTORY_BOSS_COUNT)
        return bossId;

    // Compatibility fallback while older code/scripts may still only toggle the flag.
    if (FlagGet(FLAG_BATTLE_FACTORY_DEBUG_STEVEN_BOSS))
        return FACTORY_BOSS_STEVEN;

    return FACTORY_BOSS_NONE;
}

const struct FactoryBossProfile *GetFactoryBossProfile(u8 bossId)
{
    if (bossId <= FACTORY_BOSS_NONE || bossId >= FACTORY_BOSS_COUNT)
        return NULL;

    if (!sFactoryBossProfiles[bossId].enabled)
        return NULL;

    return &sFactoryBossProfiles[bossId];
}

const struct FactoryBossProfile *GetActiveFactoryBossProfile(void)
{
    return GetFactoryBossProfile(GetActiveFactoryBossId());
}
