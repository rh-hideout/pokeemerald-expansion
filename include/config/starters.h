#ifndef GUARD_CONFIG_STARTERS_H
#define GUARD_CONFIG_STARTERS_H

// Starter Pokémon configuration
// Change these to any species to customize the three starter choices.
// The order is: left Pokéball, middle Pokéball, right Pokéball.

#if IS_FRLG
#define STARTER_1   SPECIES_BULBASAUR
#define STARTER_2   SPECIES_CHARMANDER
#define STARTER_3   SPECIES_SQUIRTLE
#else
#define STARTER_1   SPECIES_TREECKO
#define STARTER_2   SPECIES_TORCHIC
#define STARTER_3   SPECIES_MUDKIP
#endif

#endif // GUARD_CONFIG_STARTERS_H
