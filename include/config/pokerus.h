#ifndef GUARD_CONFIG_POKERUS_H
#define GUARD_CONFIG_POKERUS_H

//For pokerus, we refer to infection as a pokemon catching Pokerus from an enemy pokemon (trainer or wild) and we refer to spreading as pokemon catching pokerus from another infected pokemon in the party
#define POKERUS_ENABLED                TRUE       // If FALSE, Pokerus will have no effect, won't be shown and won't be aquired in any way but save data won't be affected
#define POKERUS_STRAIN_DISTRIBUTION    GEN_LATEST // Pokerus has 16 different strains and their probability distribution change depending on generation
#define POKERUS_SPREAD_ADJACENCY       GEN_LATEST // In Gen 2, Pokerus spread to one adjacent pokemon but it spreads to both adjacent pokemon in gen 3+
#define POKERUS_SPREAD_DAYS_LEFT       GEN_LATEST // In Gen 2, a freshly spreaded pokemon will get its full infection duration based on strain. In gen 3+, the pokerus duration will copy the duration from the pokemon it was spreaded from
#define POKERUS_INFECT_AGAIN           TRUE       // If TRUE, your party can get infected even when it is already infected with Pokerus (doesn't affect spreading, only TRUE in gen 2)
#define POKERUS_INFECT_EGG             FALSE      // If TRUE, eggs can receive Pokerus from spread and direction infection (gen 2). If FALSE, eggs can receive Pokerus from spread but not direct infection (gen 3). Behavior is unknown in other gens.
#define POKERUS_VISIBLE_ON_EGG         TRUE       // Controls if eggs can show pokerus symbol in summary screen (TRUE from gen 3 to 6, FALSE in gen 2,7 and 8)
#define POKERUS_FLAG_INFECTION         0          // If Pokerus can only get infected if this flag is set or undefined (0). This emulates a gen 2 mechanic where Pokemon can only get infected by Pokerus after visiting Goldernrod. This does not affect spreading

//Weird Pokerus behaviors that could be considered bugs. They are TRUE in vanilla Emerald but set to FALSE by default in Expansion (behaviors in other gens is unknown)
#define POKERUS_HERD_IMMUNITY          FALSE      // If TRUE, pokemon who have been previously infected by the pokerus in your party reduce the chances of your party getting infected by the Pokerus (because they can be rolled at the target of the infection but are now "immune")
#define POKERUS_WEAK_VARIANT           FALSE      // If TRUE, the variant 0 of pokerus can be erased by stronger variant when Pokerus is spreading

#define POKERUS_INFECTION_ODDS 3 // Actual probability is POKERUS_INFECTION_ODDS/65536
#define POKERUS_SPREAD_ODDS 21846 // Actual probability is POKERUS_SPREAD_ODDS/65536 (21846 should correspond to the vanilla Random() % 3)

#endif // GUARD_CONFIG_POKERUS_H
