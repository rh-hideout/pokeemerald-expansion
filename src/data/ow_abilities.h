const enum Ability sForceNatureAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_NONE
};

const enum Ability sForceOppositeGenderAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_NONE
};

const enum Ability gBlockLowLevelEncounterAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_INTIMIDATE,
    ABILITY_NONE
};

const enum Ability gForceMaxLevelAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_HUSTLE,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE
};

const enum Ability gEncounterReducingAbilities[] = {
    ABILITY_STENCH, 
    ABILITY_WHITE_SMOKE,
    ABILITY_QUICK_FEET,
#if OW_INFILTRATOR >= GEN_8
    ABILITY_INFILTRATOR,
#endif
    ABILITY_NONE
};

const enum Ability gEncounterIncreasingAbilities[] = {
    ABILITY_ILLUMINATE, 
    ABILITY_NO_GUARD,
    ABILITY_ARENA_TRAP,
    ABILITY_NONE
};

const enum Ability gHiddenBySandstormAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_NONE
};

const enum Ability gHiddenBySnowAbilities[] = {
    ABILITY_SNOW_CLOAK,
    ABILITY_NONE
};

#define WILDMON_AFFECTING_ABILITY_PERCENT_CHANCE 50

const struct WildmonTypeAffectingAbilities sWildmonTypeAffectingAbilities[] =
{
    {ABILITY_MAGNET_PULL, TYPE_STEEL},
    {ABILITY_STATIC, TYPE_ELECTRIC},
#if OW_LIGHTNING_ROD >= GEN_8
    {ABILITY_LIGHTNING_ROD, TYPE_ELECTRIC},
#endif
#if OW_FLASH_FIRE >= GEN_8
    {ABILITY_FLASH_FIRE, TYPE_FIRE},
#endif
#if OW_HARVEST >= GEN_8
    {ABILITY_HARVEST, TYPE_GRASS},
#endif
#if OW_STORM_DRAIN >= GEN_8
    {ABILITY_FLASH_FIRE, TYPE_FIRE},
#endif
    {ABILITY_NONE, TYPE_NONE}
};

const enum Ability gIncreaseHatchingSpeedAbilities[] = {
    ABILITY_MAGMA_ARMOR,
    ABILITY_FLAME_BODY,
    ABILITY_STEAM_ENGINE,
    ABILITY_NONE
};
