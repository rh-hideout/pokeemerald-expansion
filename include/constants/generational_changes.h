#ifndef GUARD_CONSTANTS_GENERATIONAL_CHANGES_H
#define GUARD_CONSTANTS_GENERATIONAL_CHANGES_H


/* Config definitions */
#define CONFIG_DEFINITIONS(F) \
    F(CRIT_CHANCE,               critChance,             (u32, GEN_9)) \
    F(CRIT_MULTIPLIER,           critMultiplier,         (u32, GEN_9)) \
    F(FOCUS_ENERGY_CRIT_RATIO,   focusEnergyCritRatio,   (u32, GEN_9)) \
    F(PARALYSIS_SPEED,           paralysisSpeed,         (u32, GEN_9)) \
    F(CONFUSION_SELF_DMG_CHANCE, confusionSelfDmgChance, (u32, GEN_9)) \
    F(MULTI_HIT_CHANCE,          multiHitChance,         (u32, GEN_9)) \
    F(GALE_WINGS,                galeWings,              (u32, GEN_9)) \
    F(HEAL_BELL_SOUNDPROOF,      healBellSoundproof,     (u32, GEN_9)) \
    F(TELEPORT_BEHAVIOR,         teleportBehavior,       (u32, GEN_9)) \
    F(ABILITY_WEATHER,           abilityWeather,         (u32, GEN_9)) \
    F(MOODY_ACC_EVASION,         moodyStats,             (u32, GEN_9)) \
    F(BATTLE_BOND,               battleBond,             (u32, GEN_9)) \
    F(ATE_MULTIPLIER,            ateMultiplier,          (u32, GEN_9)) \
    F(FELL_STINGER_STAT_RAISE,   fellStingerStatRaise,   (u32, GEN_9)) \
    F(DEFIANT_STICKY_WEB,        defiantStickyWeb,       (u32, GEN_9)) \
    F(ENCORE_TARGET,             encoreTarget,           (u32, GEN_9)) \
    F(TIME_OF_DAY_HEALING_MOVES, timeOfDayHealingMoves,  (u32, GEN_9)) \
    F(PICKUP_WILD,               pickupWild,             (u32, GEN_9)) \
    F(PROTEAN_LIBERO,            proteanLibero,          (u32, GEN_9)) \
    F(INTREPID_SWORD,            intrepidSword,          (u32, GEN_9)) \
    F(DAUNTLESS_SHIELD,          dauntlessShield,        (u32, GEN_9)) \
    F(ILLUMINATE_EFFECT,         illuminateEffect,       (u32, GEN_9)) \
    F(STEAL_WILD_ITEMS,          stealWildItems,         (u32, GEN_9)) \
    F(SNOW_WARNING,              snowWarning,            (u32, GEN_9)) \
    F(ALLY_SWITCH_FAIL_CHANCE,   allySwitchFailChance,   (u32, GEN_9)) \
    F(DREAM_EATER_LIQUID_OOZE,   dreamEaterLiquidOoze,   (u32, GEN_9)) \
    F(TRANSISTOR_BOOST,          transistorBoost,        (u32, GEN_9)) \

#define GET_CONFIG_MAXIMUM(_typeMaxValue, ...) INVOKE_WITH_B(GET_CONFIG_MAXIMUM_, _typeMaxValue)
#define GET_CONFIG_MAXIMUM_(_type, ...) FIRST(__VA_OPT__(FIRST(__VA_ARGS__),) MAX_BITS((sizeof(_type) * 8)))

#define UNPACK_CONFIG_ENUMS(_name, ...) GEN_CONFIG_##_name,

enum GenConfigTag
{
    CONFIG_DEFINITIONS(UNPACK_CONFIG_ENUMS)
};

#endif // GUARD_CONSTANTS_GENERATIONAL_CHANGES_H
