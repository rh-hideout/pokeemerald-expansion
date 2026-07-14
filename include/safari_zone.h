#ifndef GUARD_SAFARI_ZONE_H
#define GUARD_SAFARI_ZONE_H

#include "constants/safaris.h"

//extern u8 gNumSafariBalls;
//extern u16 gSafariZoneStepCounter;


bool32 GetSafariZoneFlag(void);
//void SetSafariZoneFlag(void);
void ResetSafariZoneFlag(void);

void EnterSafariMode(enum SafariIds safariId);
void ExitSafariMode(void);

bool8 SafariZoneTakeStep(void);
void SafariZoneRetirePrompt(void);

void CB2_EndSafariBattle(void);

struct Pokeblock *SafariZoneGetActivePokeblock(void);
void SafariZoneActivatePokeblockFeeder(u8 pkblId);

bool32 IsSafariEnding(void);
void PrepareStartMenuSafariString();
bool32 InSafariThatDoesNotSendMons(void);

u32 GetSafariBallCount(void);
u32 GetSafariZoneBallMultiplier(void);
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

#endif // GUARD_SAFARI_ZONE_H
