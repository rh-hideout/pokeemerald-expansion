#ifndef GUARD_MF_ENCOUNTERS_H
#define GUARD_MF_ENCOUNTERS_H

#include "wild_encounter.h"

// Gamemode ENCOUNTERS (ME tx_Mode_Encounters / alternateSpawns):
#define MF_ENCOUNTERS_VANILLA   0
#define MF_ENCOUNTERS_MODERN    1
#define MF_ENCOUNTERS_POSTGAME  2

// TRUE when the active rules should use the modern wild tables right now
// (Modern always; Postgame only after FLAG_SYS_GAME_CLEAR).
bool32 MfShouldUseModernWildEncounters(void);

// Active wild header table for the current rules (FR modern vs stock).
const struct WildPokemonHeader *MfGetActiveWildMonHeaders(void);

#endif // GUARD_MF_ENCOUNTERS_H
