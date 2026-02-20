#ifndef GUARD_FACTORY_BOSS_TEAM_H
#define GUARD_FACTORY_BOSS_TEAM_H

#include "global.h"
#include "data.h"
#include "factory_boss.h"

u16 ChooseFactoryBossAceMonIdInRange(const struct FactoryBossProfile *bossProfile,
                                     const struct TrainerMon *facilityMons,
                                     const struct RentalMon *rentalMons,
                                     s32 firstMonId,
                                     s32 lastMonId);
u16 ChooseFactoryBossAceMonId(const struct FactoryBossProfile *bossProfile,
                              const struct TrainerMon *facilityMons,
                              const struct RentalMon *rentalMons);
bool8 FactoryBossCanUseAceMonIdForSlot(const struct TrainerMon *facilityMons,
                                       const struct RentalMon *rentalMons,
                                       u16 monId,
                                       s32 aceSlot,
                                       const u16 *species,
                                       const u16 *heldItems);

#endif // GUARD_FACTORY_BOSS_TEAM_H
