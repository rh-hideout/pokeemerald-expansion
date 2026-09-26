#ifndef GUARD_MF_STATS_H
#define GUARD_MF_STATS_H

#include "global.h"
#include "constants/pokemon.h"

// Runtime base-stat helpers (S29). GetSpeciesBase* route here so POKéMON STATS
// toggles Gen-3 classic vs Gen-latest without forking species_info.

u32 MfGetSpeciesBaseStat(enum Species species, u32 statIndex);

// Recalculate the player party’s stored stats after a mid-run modernStats
// debug toggle so summary / battle match the active rule.
void MfRecalculatePartyStats(void);

#endif // GUARD_MF_STATS_H
