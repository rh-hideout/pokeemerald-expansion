#ifndef GUARD_CONFIG_FRLG_H
#define GUARD_CONFIG_FRLG_H

#define FIRE_RED   1
#define LEAF_GREEN 2

// IMPORTANT: Run `make clean` after changing any of these settings.

// Settings for Emerald mode
#define FRLG_INCLUDE_OBJECT_EVENTS      FALSE    // Include data for FRLG's object events
#define FRLG_INCLUDE_KANTO_TILESETS     FALSE    // Include data for FRLG's tilesets
#define FRLG_INCLUDE_KANTO_MAPS         FALSE    // Include data for FRLG's maps. IMPORTANT: Requires FRLG_INCLUDE_OBJECT_EVENTS and FRLG_INCLUDE_KANTO_TILESETS!!
                                                 // Flags and Vars are not handled, so events may be in a broken state.
#define FRLG_KANTO_MAP_WILD_PKMN        FIRE_RED // Wild encounter data to be used when enabling FRLG_INCLUDE_KANTO_MAPS

// Settings for FRLG mode
#define FRLG_INCLUDE_HOENN_TILESETS     FALSE // Include data for Emerald's tilesets.
#define FRLG_INCLUDE_HOENN_MAPS         FALSE // Include data for Emerald's maps. IMPORTANT: Requires FRLG_INCLUDE_HOENN_TILESETS!!
                                              // Flags and Vars are not handled, so events may be in a broken state.

#endif // GUARD_CONFIG_FRLG_H
