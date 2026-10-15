#ifndef GUARD_CHAOS_ECLIPSE_H
#define GUARD_CHAOS_ECLIPSE_H

#include "pokemon.h"
#include "random.h"
#include "constants/pokedex.h"

// Chaos Eclipse v0.1: species from National Dex #1 through #1025,
// including Legendary and Mythical Pokemon; forms are not separate rolls.
// Keep the original wild encounter 20% of the time.
#define CHAOS_ECLIPSE_WILD_RANDOM_CHANCE 80

static inline enum Species ChaosEclipseRollSpecies(void)
{
    return NationalPokedexNumToSpecies(RandomUniform(RNG_NONE, 1, NATIONAL_DEX_COUNT));
}

#endif // GUARD_CHAOS_ECLIPSE_H
