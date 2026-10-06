#ifndef GUARD_SAFARI_ZONE_H
#define GUARD_SAFARI_ZONE_H

#include "constants/safaris.h"

extern const u8 SafariZone_EventScript_TimesUp[];
extern const u8 SafariZone_EventScript_RetirePrompt[];
extern const u8 SafariZone_EventScript_OutOfBallsMidBattle[];
extern const u8 SafariZone_EventScript_OutOfBalls[];
extern const u8 *const gBattlescriptsForSafariActions[];

enum SafariActions
{
    SAFARI_ACTIONS_RSE,
    SAFARI_ACTIONS_FRLG,
};

bool32 GetSafariZoneFlag(void);
void ResetSafariZoneFlag(void);

void EnterSafariMode(enum SafariEvents safariId);
void SetSafariExitWarp(void);
void ExitSafariMode(void);
bool32 ShouldRetireFromSafariOnWhiteout(void);
void SetSafariWhiteoutWarp(void);
bool32 CannotEscapeSafari(void);

bool8 SafariZoneTakeStep(void);
void SafariZoneRetirePrompt(void);

void IncrementSafariValuesPostBattle(u32 pokeblocksUsed, bool32 wasMonCaught);

void SafariZoneActivatePokeblockFeeder(u8 pkblId);
u32 GetPokeblockFeederNature(void);

bool32 IsSafariEnding(void);
void PrepareStartMenuSafariString();
bool32 InSafariThatDoesNotSendMons(void);

u32 GetSafariBallCount(void);
u32 GetSafariZoneBallMultiplier(void);
enum SafariActions GetSafariActions(void);
void DecrementSafariBalls(void);

#endif // GUARD_SAFARI_ZONE_H
