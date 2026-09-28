#ifndef GUARD_CONFIG_PENTARA_H
#define GUARD_CONFIG_PENTARA_H

// Pentara gameplay tuning. See PLAN.md for the design behind these numbers.

#define PENTARA_PRIZE_MULTIPLIER      20   // Important trainers pay this many times vanilla prize money.
#define PENTARA_START_MONEY           50000 // Money at the start of a new game.
#define PENTARA_WILD_PRIZE_PER_LEVEL  60   // Money earned for defeating a wild Pokemon, per level of that Pokemon.
#define PENTARA_CATCHUP_EXP_PERCENT   50   // Extra EXP % per level a Pokemon is below the level cap...
#define PENTARA_CATCHUP_EXP_MAX_LEVELS 6   // ...counting at most this many levels (6 -> up to 4x EXP).
#define PENTARA_START_LEVEL_CAP       8    // Level cap before the first badge.

#include "config/pentara_test.h"

#endif // GUARD_CONFIG_PENTARA_H
