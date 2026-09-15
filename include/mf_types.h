#ifndef GUARD_MF_TYPES_H
#define GUARD_MF_TYPES_H

#include "global.h"
#include "constants/pokemon.h"
#include "fpmath.h"

// Runtime type helpers (S27–S28). GetSpeciesType / GetTypeModifier route here so
// Fairy, modern typings, and TYPE CHART stay out of upstream species_info / chart data.

enum Type MfGetSpeciesType(enum Species species, u8 slot);

// Active type-effectiveness matrix (Gen VI+ or ME Improved). Hot path: one rule
// check, then a single 2D index — no per-matchup branching.
const uq4_12_t (*MfGetTypeEffectivenessTable(void))[NUMBER_OF_MON_TYPES];

#endif // GUARD_MF_TYPES_H
