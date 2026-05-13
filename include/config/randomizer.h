#ifndef GUARD_CONFIG_RANDOMIZER_H
#define GUARD_CONFIG_RANDOMIZER_H

#define RANDOMIZER_AVAILABLE                   1
#define RANDOMIZER_SEED_IS_TRAINER_ID          1

// The rest of these defines are only usable from C code
#ifndef __ASSEMBLER__

#if RANDOMIZER_AVAILABLE

#define RZ_TRAINER_ID_IS_SEED       1

#define RANDOMIZER_DYNAMIC_SPECIES    1

#if RANDOMIZER_DYNAMIC_SPECIES
#define RANDOMIZER_MAX_EVO_STAGES   5
#endif // RANDOMIZER_DYNAMIC_SPECIES

#include "item.h"
#define RANDOMIZER_MAX_TM           ITEM_TM50

// Force-enable/disable overrides (uncomment to force)
//#define FORCE_RANDOMIZE_WILD_MON                  1
//#define FORCE_RANDOMIZE_FIELD_ITEMS               1
//#define FORCE_RANDOMIZE_TRAINER_MON               1
//#define FORCE_RANDOMIZE_FIXED_MON                 1
//#define FORCE_RANDOMIZE_STARTER_AND_GIFT_MON      1
//#define FORCE_RANDOMIZE_EGG_MON                   1
//#define FORCE_RANDOMIZE_ABILITIES                 1
//#define FORCE_RANDOMIZE_EVOLUTIONS                1
//#define FORCE_RANDOMIZE_EVO_METHODS               1
//#define FORCE_RANDOMIZE_TYPE_EFFECTIVENESS        1

// Species mode var (used for legend-aware / BST / evo-stage grouping)
#include "constants/vars.h"
#define RANDOMIZER_VAR_SPECIES_MODE               VAR_UNUSED_0x404E

#if !RANDOMIZER_SEED_IS_TRAINER_ID
#define RANDOMIZER_VAR_SEED_L                     VAR_UNUSED_0x40FA
#define RANDOMIZER_VAR_SEED_H                     VAR_UNUSED_0x40FB
#endif

#endif // RANDOMIZER_AVAILABLE

#endif // __ASSEMBLER__

#endif // GUARD_CONFIG_RANDOMIZER_H
