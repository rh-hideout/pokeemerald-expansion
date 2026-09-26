#ifndef GUARD_MF_MOVES_H
#define GUARD_MF_MOVES_H

#include "global.h"
#include "pokemon.h"

// Runtime movepool helpers (S30). GetSpecies*Learnset route here so
// {PKMN} MOVEPOOL toggles FRLG classic vs GEN_LATEST without forking
// species_info.

const struct LevelUpMove *MfGetSpeciesLevelUpLearnset(enum Species species);
const u16 *MfGetSpeciesTeachableLearnset(enum Species species);
const u16 *MfGetSpeciesEggMoves(enum Species species);

#endif // GUARD_MF_MOVES_H
