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

#define ROCK_SMASH_TABLE_STRUCT(array)  {      \
    .table = array,                            \
    .size = ARRAY_COUNT(array),                \
    .weights = NULL,                           \
    .weightsSum = 0                            \
}

static const struct RockSmashItemTable sRockSmashTables[ROCK_SMASH_ITEM_TABLE_COUNT] = {
    [ROCK_SMASH_ITEM_TABLE_DEFAULT] = ROCK_SMASH_TABLE_STRUCT(sGen6DefaultSmashTable),
    [ROCK_SMASH_ITEM_TABLE_CLIFF] = ROCK_SMASH_TABLE_STRUCT(sGen6DefaultSmashTable),
    [ROCK_SMASH_ITEM_TABLE_RUINS] = ROCK_SMASH_TABLE_STRUCT(sGen6DefaultSmashTable),
    [ROCK_SMASH_ITEM_TABLE_FOSSIL] = ROCK_SMASH_TABLE_STRUCT(sGen6FossilSmashTable),
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

static const u16 sGen4ItemTableWeights[] = {
    25,
    20,
    10,
    10,
    10,
    10,
    10,
    5,
};

#define ROCK_SMASH_TABLE_STRUCT(array)  {      \
    .table = array,                            \
    .size = ARRAY_COUNT(array),                \
    .weights = sGen4ItemTableWeights,          \
    .weightsSum = 100                          \
}

static const struct RockSmashItemTable sRockSmashTables[ROCK_SMASH_ITEM_TABLE_COUNT] = {
    [ROCK_SMASH_ITEM_TABLE_DEFAULT] = ROCK_SMASH_TABLE_STRUCT(sGen4DefaultSmashTable),
    [ROCK_SMASH_ITEM_TABLE_CLIFF] = ROCK_SMASH_TABLE_STRUCT(sGen4CliffCaveSmashTable),
    [ROCK_SMASH_ITEM_TABLE_RUINS] = ROCK_SMASH_TABLE_STRUCT(sGen4RuinsOfAlphSmashTable),
    [ROCK_SMASH_ITEM_TABLE_FOSSIL] = ROCK_SMASH_TABLE_STRUCT(sGen4DefaultSmashTable),
};

#else

static const struct RockSmashItemTable sRockSmashTables[] = {};

#endif
