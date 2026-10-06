#ifndef GUARD_BATTLE_SAFARI_H
#define GUARD_BATTLE_SAFARI_H

const u8 *GetSafariControllerMenu(void);
const u8 *GetSafariControllerActions(void);
u32 GetInitialSafariCatchFactor(void);
void HandleAction_WatchesCarefully(void);
void HandleAction_SafariZoneBallThrow(void);
void HandleAction_ThrowPokeblock(void);
void HandleAction_GoNear(void);
void HandleAction_ThrowBait(void);
void HandleAction_ThrowRock(void);
void HandleAction_SafariZoneRun(void);

#endif // GUARD_BATTLE_SAFARI_H