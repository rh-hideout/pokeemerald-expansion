
// JARED'S EMERALD - EVERYTHING RANDOM CONFIG
// File: include/configs/randomizer.h or include/config/randomizer.h

#ifndef GUARD_CONFIG_RANDOMIZER_H
#define GUARD_CONFIG_RANDOMIZER_H

#define CONFIG_RANDOMIZER TRUE

#define RANDOM_WILD_MONS TRUE
#define RANDOM_TRAINER_MONS TRUE
#define RANDOM_WILD_MONS_SIMILAR_POWER FALSE // Harder - everything random
#define RANDOM_TRAINER_MONS_SIMILAR_POWER FALSE

#define RANDOM_ITEMS TRUE
#define RANDOM_ABILITIES TRUE
#define RANDOM_MOVES TRUE
#define RANDOM_EVERYTHING TRUE

// New seed per save file - new save = new random, same save keeps same
#define RANDOM_SEED_PER_SAVE_FILE TRUE
#define RANDOM_SEED_TYPE SEED_PER_SAVE

#define RANDOM_TRAINER_KEEP_ACE FALSE

#endif
