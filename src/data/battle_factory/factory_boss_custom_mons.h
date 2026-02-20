static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_StevenAceMetagross =
{
    .species = SPECIES_METAGROSS,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_METAGROSSITE,
    .abilityNum = 0, // Clear Body
    .hasTeraType = FALSE,
    .teraType = TYPE_NONE,
    .evs =
    {
        [STAT_HP] = 232,
        [STAT_ATK] = 60,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 40,
        [STAT_SPEED] = 176,
    },
    .moves =
    {
        MOVE_METEOR_MASH,
        MOVE_ICE_PUNCH,
        MOVE_ROCK_SLIDE,
        MOVE_BULLET_PUNCH,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_WallyGallade =
{
    .species = SPECIES_GALLADE,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_GALLADITE,
    .abilityNum = 2, // Justified
    .hasTeraType = FALSE,
    .teraType = TYPE_NONE,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 252,
        [STAT_DEF] = 4,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_CLOSE_COMBAT,
        MOVE_ZEN_HEADBUTT,
        MOVE_KNOCK_OFF,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_RedPikachu =
{
    .species = SPECIES_PIKACHU,
    .nature = NATURE_HASTY,
    .heldItem = ITEM_LIGHT_BALL,
    .abilityNum = 0, // Static
    .hasTeraType = TRUE,
    .teraType = TYPE_ELECTRIC,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 252,
        [STAT_DEF] = 0,
        [STAT_SPATK] = 4,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_FAKE_OUT,
        MOVE_EXTREME_SPEED,
        MOVE_VOLT_SWITCH,
        MOVE_SURF,
    },
};

static const struct FactoryCustomMonBuild sFactoryCustomMonBuild_NormanKangaskhan =
{
    .species = SPECIES_KANGASKHAN,
    .nature = NATURE_JOLLY,
    .heldItem = ITEM_KANGASKHANITE,
    .abilityNum = 1, // Scrappy
    .hasTeraType = TRUE,
    .teraType = TYPE_NORMAL,
    .evs =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 252,
        [STAT_DEF] = 4,
        [STAT_SPATK] = 0,
        [STAT_SPDEF] = 0,
        [STAT_SPEED] = 252,
    },
    .moves =
    {
        MOVE_FAKE_OUT,
        MOVE_RETURN,
        MOVE_SUCKER_PUNCH,
        MOVE_POWER_UP_PUNCH,
    },
};

static const struct FactoryCustomMonBuild *const sFactoryBossRewardMonBuilds[FACTORY_BOSS_COUNT] =
{
    [FACTORY_BOSS_NONE] = NULL,
    [FACTORY_BOSS_STEVEN] = &sFactoryCustomMonBuild_StevenAceMetagross,
    [FACTORY_BOSS_WALLY] = &sFactoryCustomMonBuild_WallyGallade,
    [FACTORY_BOSS_RED] = &sFactoryCustomMonBuild_RedPikachu,
    [FACTORY_BOSS_NORMAN] = &sFactoryCustomMonBuild_NormanKangaskhan,
};

static const struct FactoryCustomMonBuild *const sFactoryBossAceMonBuilds[FACTORY_BOSS_COUNT] =
{
    [FACTORY_BOSS_NONE] = NULL,
    [FACTORY_BOSS_STEVEN] = &sFactoryCustomMonBuild_StevenAceMetagross,
    [FACTORY_BOSS_WALLY] = NULL,
    [FACTORY_BOSS_RED] = NULL,
    [FACTORY_BOSS_NORMAN] = &sFactoryCustomMonBuild_NormanKangaskhan,
};
