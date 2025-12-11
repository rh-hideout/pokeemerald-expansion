#ifndef GUARD_CONFIG_WONDER_TRADE_H
#define GUARD_CONFIG_WONDER_TRADE_H

// Dex Type

#define WT_DEX_NATIONAL                TRUE  // Toggles whether to use the national dex or the hoenn dex to generate a random pokemon.

// Wonder Trade Types

#define WT_TYPE_UNWEIGHTED              0    // Literally any pokemon within the non-weighted parameters can be traded for at any time.
#define WT_TYPE_WEIGHTED                1    // Any pokemon within the BST trade weight and non-weighted parameters can be traded for at any time.
#define WT_TYPE_CUSTOM                  2    // Can trade for any pokemon within a defined custom list of pokemon in src/data/wonder_trade_custom_mons.h

#define WT_NUM_CUSTOM_SPECIES           17   // Number of custom pokemon for array in src/data/wonder_trade_custom_mons.h for WT_TYPE_CUSTOM, default is Yancy + Curtis unique mons.

#define WT_TYPE                         WT_TYPE_WEIGHTED // The actual type of wonder trade you are doing.

// Trade Weights

#define WT_WEIGHT_STRICT                25 // BST +/- 25
#define WT_WEIGHT_AVERAGE               50 // BST +/- 50
#define WT_WEIGHT_LENIENT               100 // BST +/- 100

#define WT_WEIGHT                       WT_WEIGHT_AVERAGE // The weighted BST range you are using. Only matters for WT_TYPE_WEIGHTED

// Additional Selection Parameters (applicable to WT_TYPE_WEIGHTED and WT_TYPE_UNWEIGHTED only)

#define WT_USE_RESTRICTEDS              FALSE // Toggles whether restricted legendaries will appear (defined with .isRestrictedLegendary = TRUE in species config)
#define WT_USE_SUBLEGENDARIES           FALSE // Toggles whether non-restricted legendaries will appear (defined with .isSubLegendary = TRUE in species config)
#define WT_USE_MYTHICALS                FALSE // Toggles whether mythicals will appear (defined with .isMythical = TRUE in species config)
#define WT_USE_PARADOXES                FALSE // Toggles whether paradoxes will appear (defined with .isParadox = TRUE in species config)
#define WT_USE_ULTRA_BEASTS             FALSE // Toggles whether ultra beasts will appear (defined with .isUltraBeast = TRUE in species config)

// Moveset Config

#define WT_RANDOM_MOVESETS              FALSE // Toggles whether a pokemon should have a random in-learnset moveset, or default level up moveset.

#define WT_RANDOM_MOVESET_LEVELUP       1 // How many moves should be levelup moves. Should sum up to 4 with the other move types.
#define WT_RANDOM_MOVESET_TM            1 // How many moves should be TM moves. Should sum up to 4 with the other move types.
#define WT_RANDOM_MOVESET_EGG           1 // How many moves should be egg moves. Should sum up to 4 with the other move types.
#define WT_RANDOM_MOVESET_TUTOR         1 // How many moves should be tutor moves. Should sum up to 4 with the other move types.

// Auto-Evolve Config

#define WT_AUTO_EVOLVE                  TRUE // Toggles whether the received pokemon should arrive evolved. If you want to customize evos, edit the evolution function.

#define WT_AUTO_EVOLVE_TRADE_LEVEL      37    // Level at which a pokemon should auto-evolve by trade
#define WT_AUTO_EVOLVE_ITEM_LEVEL       37    // Level at which a pokemon should auto-evolve by item
#define WT_AUTO_EVOLVE_OTHER_LEVEL      60    // Level at which a pokemon should auto-evolve by other methods

// Item Config

#define WT_ITEMS                        FALSE // Toggles whether the received pokemon should arrive holding a random item using the options below.

#define WT_CUSTOM_ITEMS                 FALSE // Toggles whether you want to distribute random items from a list in src/data/wonder_trade_custom_items.h
#define WT_SPECIES_SPECIFIC_ITEMS       FALSE // Toggles whether the received pokemon arrives carrying species-specific items, if any.
#define WT_SPECIES_SPECIFIC_Z_CRYSTALS  FALSE // If WT_SPECIES_SPECIFIC_ITEMS is TRUE, toggles whether species-specific z-crystals are a possible hold.
#define WT_SPECIES_SPECIFIC_MEGA_STONES FALSE // If WT_SPECIES_SPECIFIC_ITEMS is TRUE, toggles whether species-specific mega stones are a possible hold.

#define WT_NUM_CUSTOM_ITEMS             4     // Number of custom items being used in src/data/wonder_trade_custom_items.h

// EVs and IVs Config

#define WT_NUM_PERFECT_IVS              3     // Number of perfect IVs a traded pokemon should have. Rest will be random.
#define WT_RANDOM_EVS                   FALSE // Attempts to simulate random evs on the incoming pokemon.

// Miscellaneous Config

#define WT_RANDOM_OT                    TRUE  // Toggles whether the OT of the pokemon should be randomly defined by src/data/wonder_trade_ots.h or the player name.
#define WT_FORMS                        TRUE  // Toggles whether the received pokemon should have a random form on arrival, or default to base (i.e. Paldean, Cosplay, etc).
#define WT_BALLS                        TRUE  // Toggles whether the received pokemon should arrive in a random ball or default to a Poke Ball.


#endif // GUARD_CONFIG_WONDER_TRADE_H