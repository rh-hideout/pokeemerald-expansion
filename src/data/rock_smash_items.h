// these are used in fldeff_rocksmash.c
#if OW_ROCK_SMASH_ITEMS >= GEN_6

static const enum Item sGen6DefaultSmashTable[] = {
    ITEM_STAR_PIECE,
    ITEM_HARD_STONE,
    ITEM_SOFT_SAND,
    ITEM_REVIVE,
    ITEM_MAX_REVIVE,
    ITEM_ETHER,
    ITEM_MAX_ETHER,
    ITEM_PEARL,
    ITEM_BIG_PEARL,
    ITEM_HEART_SCALE,
    ITEM_NORMAL_GEM,
};

static const enum Item sGen6FossilSmashTable[] = {
    ITEM_DOME_FOSSIL,
    ITEM_ARMOR_FOSSIL,
    ITEM_PLUME_FOSSIL,
    ITEM_OLD_AMBER,
    ITEM_HELIX_FOSSIL,
    ITEM_SKULL_FOSSIL,
    ITEM_COVER_FOSSIL,
};

static const struct WeightedArray sGen6DefaultTableWeights = UNIFORM_WEIGHTS(ARRAY_COUNT(sGen6DefaultSmashTable));
static const struct WeightedArray sGen6FossilTableWeights = UNIFORM_WEIGHTS(ARRAY_COUNT(sGen6FossilSmashTable));

static const struct RockSmashItemTable sRockSmashTables[ROCK_SMASH_ITEM_TABLE_COUNT] = {
    [ROCK_SMASH_ITEM_TABLE_DEFAULT] = {
        .table = sGen6DefaultSmashTable,
        .weights = &sGen6DefaultTableWeights,
    },
    [ROCK_SMASH_ITEM_TABLE_CLIFF] = {
        .table = sGen6DefaultSmashTable,
        .weights = &sGen6DefaultTableWeights,
    },
    [ROCK_SMASH_ITEM_TABLE_RUINS] = {
        .table = sGen6DefaultSmashTable,
        .weights = &sGen6DefaultTableWeights,
    },
    [ROCK_SMASH_ITEM_TABLE_FOSSIL] = {
        .table = sGen6FossilSmashTable,
        .weights = &sGen6FossilTableWeights,
    },
};

#elif OW_ROCK_SMASH_ITEMS >= GEN_4

static const enum Item sGen4DefaultSmashTable[] = {
    ITEM_MAX_ETHER,     //25
    ITEM_REVIVE,        //20
    ITEM_HEART_SCALE,   //10
    ITEM_RED_SHARD,
    ITEM_GREEN_SHARD,
    ITEM_BLUE_SHARD,
    ITEM_YELLOW_SHARD,
    ITEM_STAR_PIECE,    //5
};

static const enum Item sGen4RuinsOfAlphSmashTable[] = {
    ITEM_RED_SHARD,     //25
    ITEM_YELLOW_SHARD,  //20
    ITEM_HELIX_FOSSIL,  //10
    ITEM_MAX_ETHER,
    ITEM_BLUE_SHARD,
    ITEM_GREEN_SHARD,
    ITEM_OLD_AMBER,
    ITEM_MAX_REVIVE,    //5
};

static const enum Item sGen4CliffCaveSmashTable[] = {
    ITEM_MAX_ETHER, //25
    ITEM_PEARL,     //20
    ITEM_BIG_PEARL, //10
    ITEM_RED_SHARD,
    ITEM_YELLOW_SHARD,
    ITEM_CLAW_FOSSIL,
    ITEM_CLAW_FOSSIL,
    ITEM_RARE_BONE, //5
};

static const struct WeightedArray sGen4ItemTableWeights = WEIGHTED_ARRAY(25, 20, 10, 10, 10, 10, 10, 5);

static const struct RockSmashItemTable sRockSmashTables[ROCK_SMASH_ITEM_TABLE_COUNT] = {
    [ROCK_SMASH_ITEM_TABLE_DEFAULT] = {
        .table = sGen4DefaultSmashTable,
        .weights = &sGen4ItemTableWeights,
    },
    [ROCK_SMASH_ITEM_TABLE_CLIFF] = {
        .table = sGen4CliffCaveSmashTable,
        .weights = &sGen4ItemTableWeights,
    },
    [ROCK_SMASH_ITEM_TABLE_RUINS] = {
        .table = sGen4RuinsOfAlphSmashTable,
        .weights = &sGen4ItemTableWeights,
    },
    [ROCK_SMASH_ITEM_TABLE_FOSSIL] = {
        .table = sGen4DefaultSmashTable,
        .weights = &sGen4ItemTableWeights,
    },
};

#else

static const struct RockSmashItemTable sRockSmashTables[] = {};

#endif
