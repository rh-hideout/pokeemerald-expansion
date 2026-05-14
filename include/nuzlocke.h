#ifndef GUARD_NUZLOCKE_H
#define GUARD_NUZLOCKE_H

#include "global.h"

#define NUZLOCKE_NUM_ZONES 96
#define NUZLOCKE_FLAG_BYTES ((NUZLOCKE_NUM_ZONES + 7) / 8)

bool8 IsNuzlockeActive(void);
bool8 IsNuzlockeNicknamingActive(void);

u8 NuzlockeFlagSet(u16 mapsec);
u8 NuzlockeFlagClear(u16 mapsec);
u8 NuzlockeFlagGet(u16 mapsec);

void NuzlockeDeletePartyMon(u8 position);
void NuzlockeDeletePartyMonOption(u8 position);
void NuzlockeDeleteFaintedPartyPokemon(void);

u8 NuzlockeGetCurrentRegionMapSectionId(void);

extern u8 NuzlockeIsCaptureBlocked;
extern u8 NuzlockeIsSpeciesClauseActive;
extern u8 OneTypeChallengeCaptureBlocked;

void SetNuzlockeChecks(void);
u8 NuzlockeIsCaptureBlockedBySpeciesClause(u16 species);

#endif // GUARD_NUZLOCKE_H
