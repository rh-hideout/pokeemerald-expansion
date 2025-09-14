#ifndef GUARD_CONSTANTS_GENERATIONAL_CHANGES_H
#define GUARD_CONSTANTS_GENERATIONAL_CHANGES_H

/* Config definitions */
#define CONFIG_DEFINITIONS(F) \
    /* Calculation settings */ \
    F(CRIT_CHANCE,               critChance,              (u32, GEN_9)) \
    F(CRIT_MULTIPLIER,           critMultiplier,          (u32, GEN_9)) \
    F(PARALYSIS_SPEED,           paralysisSpeed,          (u32, GEN_9)) \
    F(CONFUSION_SELF_DMG_CHANCE, confusionSelfDmgChance,  (u32, GEN_9)) \
    F(MULTI_HIT_CHANCE,          multiHitChance,          (u32, GEN_9)) \
    F(WHITEOUT_MONEY,            whiteoutMoney,           (u32, GEN_9)) /* TODO */ \
    F(LIGHT_BALL_ATTACK_BOOST,   lightBallAttackBoost,    (u32, GEN_9)) /* TODO */ \
    /* Experience settings */ \
    F(EXP_CATCH,                 expCatch,                (u32, GEN_9)) /* TODO */ \
    F(TRAINER_EXP_MULTIPLIER,    trainerExpMultiplier,    (u32, GEN_9)) /* TODO */ \
    F(SPLIT_EXP,                 splitExp,                (u32, GEN_9)) /* TODO */ \
    F(SCALED_EXP,                scaledExp,               (u32, GEN_9)) /* TODO */ \
    F(UNEVOLVED_EXP_MULTIPLIER,  unevolvedExpMultiplier,  (u32, GEN_9)) /* TODO */ \
    F(LEVEL_UP_NOTIFICATION,     levelUpNotification,     (u32, GEN_9)) /* TODO */ \
    /* Stat settings */ \
    F(BADGE_BOOST,               badgeBoost,              (u32, GEN_9)) /* TODO */ \
    F(FRIENDSHIP_BOOST,          friendshipBoost,         (u32, GEN_9)) /* TODO */ \
    F(MAX_LEVEL_EV_GAINS,        maxLevelEvGains,         (u32, GEN_9)) /* TODO */ \
    F(RECALCULATE_STATS,         recalculateStats,        (u32, GEN_9)) /* TODO */ \
    /* Damage settings */ \
    F(BURN_DAMAGE,               burnDamage,              (u32, GEN_9)) /* TODO */ \
    F(BURN_FACADE_DMG,           burnFacadeDmg,           (u32, GEN_9)) /* TODO */ \
    F(BINDING_DAMAGE,            bindingDamage,           (u32, GEN_9)) /* TODO */ \
    F(PSYWAVE_DMG,               psywaveDmg,              (u32, GEN_9)) /* TODO */ \
    F(PAYBACK_SWITCH_BOOST,      paybackSwitchBoost,      (u32, GEN_9)) /* TODO */ \
    F(HIDDEN_POWER_DMG,          hiddenPowerDmg,          (u32, GEN_9)) /* TODO */ \
    F(ROUGH_SKIN_DMG,            roughSkinDmg,            (u32, GEN_9)) /* TODO */ \
    F(KNOCK_OFF_DMG,             knockOffDmg,             (u32, GEN_9)) /* TODO */ \
    F(SPORT_DMG_REDUCTION,       sportDmgReduction,       (u32, GEN_9)) /* TODO */ \
    F(EXPLOSION_DEFENSE,         explosionDefense,        (u32, GEN_9)) /* TODO */ \
    F(PARENTAL_BOND_DMG,         parentalBondDmg,         (u32, GEN_9)) /* TODO */ \
    F(MULTIPLE_TARGETS_DMG,      multipleTargetsDmg,      (u32, GEN_9)) /* TODO */ \
    /* Type settings */ \
    F(GHOSTS_ESCAPE,             ghostsEscape,            (u32, GEN_9)) /* TODO */ \
    F(PARALYZE_ELECTRIC,         paralyzeElectric,        (u32, GEN_9)) /* TODO */ \
    F(POWDER_GRASS,              powderGrass,             (u32, GEN_9)) /* TODO */ \
    F(UPDATED_TYPE_MATCHUPS,     updatedTypeMatchups,     (u32, GEN_9)) /* TODO */ \
    F(PRANKSTER_DARK_TYPES,      pranksterDarkTypes,      (u32, GEN_9)) \
    F(SHEER_COLD_IMMUNITY,       sheerColdImmunity,       (u32, GEN_9)) \
    F(ROOST_PURE_FLYING,         roostPureFlying,         (u32, GEN_9)) /* TODO */ \
    F(STATUS_TYPE_IMMUNITY,      statusTypeImmunity,      (u32, GEN_9)) /* TODO */ \
    /* Turn settings */ \
    F(BINDING_TURNS,             bindingTurns,            (u32, GEN_9)) /* TODO */ \
    F(UPROAR_TURNS,              uproarTurns,             (u32, GEN_9)) /* TODO */ \
    F(UPROAR_IGNORE_SOUNDPROOF,  uproarIgnoreSoundproof,  (u32, GEN_9)) /* TODO */ \
    F(DISABLE_TURNS,             disableTurns,            (u32, GEN_9)) /* TODO */ \
    F(TAILWIND_TURNS,            tailwindTurns,           (u32, GEN_9)) /* TODO */ \
    F(SLEEP_TURNS,               sleepTurns,              (u32, GEN_9)) /* TODO */ \
    F(TAUNT_TURNS,               tauntTurns,              (u32, GEN_9)) /* TODO */ \
    F(SPORT_TURNS,               sportTurns,              (u32, GEN_9)) /* TODO */ \
    F(MEGA_EVO_TURN_ORDER,       megaEvoTurnOrder,        (u32, GEN_9)) \
    F(RECALC_TURN_AFTER_ACTIONS, recalcTurnAfterActions,  (u32, GEN_9)) \
    F(FAINT_SWITCH_IN,           faintSwitchIn,           (u32, GEN_9)) /* TODO */ \
    /* Move data settings */ \
    F(UPDATED_MOVE_DATA,         updatedMoveData,         (u32, GEN_9)) /* TODO */ \
    F(UPDATED_MOVE_TYPES,        updatedMoveTypes,        (u32, GEN_9)) /* TODO */ \
    F(UPDATED_MOVE_FLAGS,        updatedMoveFlags,        (u32, GEN_9)) /* TODO */ \
    F(PHYSICAL_SPECIAL_SPLIT,    physicalSpecialSplit,    (u32, GEN_9)) /* TODO */ \
    F(RECOIL_IF_MISS_DMG,        recoilIfMissDmg,         (u32, GEN_9)) /* TODO */ \
    F(KLUTZ_FLING_INTERACTION,   klutzFlingInteraction,   (u32, GEN_9)) /* TODO */ \
    F(UPDATED_CONVERSION,        updatedConversion,       (u32, GEN_9)) /* TODO */ \
    F(UPDATED_CONVERSION_2,      updatedConversion2,      (u32, GEN_9)) /* TODO */ \
    F(PP_REDUCED_BY_SPITE,       ppReducedBySpite,        (u32, GEN_9)) /* TODO */ \
    F(EXTRAPOLATED_MOVE_FLAGS,   extrapolatedMoveFlags,   (u32, GEN_9)) /* TODO */ \
    /* Ability data settings */ \
    F(UPDATED_ABILITY_DATA,      updatedAbilityData,      (u32, GEN_9)) /* TODO */ \
    /* Move accuracy settings */ \
    F(TOXIC_NEVER_MISS,          toxicNeverMiss,          (u32, GEN_9)) /* TODO */ \
    F(MINIMIZE_DMG_ACC,          minimizeDmgAcc,          (u32, GEN_9)) /* TODO */ \
    F(BLIZZARD_HAIL,             blizzardHail,            (u32, GEN_9)) /* TODO */ \
    F(SHEER_COLD_ACC,            sheerColdAcc,            (u32, GEN_9)) /* TODO */ \
    /* Move stat change settings */ \
    F(FELL_STINGER_STAT_RAISE,   fellStingerStatRaise,    (u32, GEN_9)) \
    F(KINGS_SHIELD_LOWER_ATK,    kingsShieldLowerAtk,     (u32, GEN_9)) /* TODO */ \
    F(SPEED_BUFFING_RAPID_SPIN,  speedBuffingRapidSpin,   (u32, GEN_9)) /* TODO */ \
    F(CHARGE_SPDEF_RAISE,        chargeSpDefRaise,        (u32, GEN_9)) /* TODO */ \
    F(MINIMIZE_EVASION,          minimizeEvasion,         (u32, GEN_9)) /* TODO */ \
    F(GROWTH_STAT_RAISE,         growthStatRaise,         (u32, GEN_9)) /* TODO */ \
    F(FOCUS_ENERGY_CRIT_RATIO,   focusEnergyCritRatio,    (u32, GEN_9)) \
    /* Other move settings */ \
    F(INCINERATE_GEMS,           incinerateGems,          (u32, GEN_9)) /* TODO */ \
    F(CAN_SPITE_FAIL,            canSpiteFail,            (u32, GEN_9)) /* TODO */ \
    F(CRASH_IF_TARGET_IMMUNE,    crashIfTargetImmune,     (u32, GEN_9)) /* TODO */ \
    F(MEMENTO_FAIL,              mementoFail,             (u32, GEN_9)) /* TODO */ \
    F(GLARE_GHOST,               glareGhost,              (u32, GEN_9)) /* TODO */ \
    F(SKILL_SWAP,                skillSwap,               (u32, GEN_9)) /* TODO */ \
    F(BRICK_BREAK,               brickBreak,              (u32, GEN_9)) /* TODO */ \
    F(WISH_HP_SOURCE,            wishHpSource,            (u32, GEN_9)) /* TODO */ \
    F(RAMPAGE_CANCELLING,        rampageCancelling,       (u32, GEN_9)) /* TODO */ \
    F(HEAL_BLOCKING,             healBlocking,            (u32, GEN_9)) /* TODO */ \
    F(ROOTED_GROUNDING,          rootedGrounding,         (u32, GEN_9)) /* TODO */ \
    F(METRONOME_MOVES,           metronomeMoves,          (u32, GEN_9)) /* TODO */ \
    F(TELEPORT_BEHAVIOR,         teleportBehavior,        (u32, GEN_9)) \
    F(BEAT_UP,                   beatUp,                  (u32, GEN_9)) /* TODO */ \
    F(DARK_VOID_FAIL,            darkVoidFail,            (u32, GEN_9)) /* TODO */ \
    F(BURN_HIT_THAW,             burnHitThaw,             (u32, GEN_9)) /* TODO */ \
    F(HEALING_WISH_SWITCH,       healingWishSwitch,       (u32, GEN_9)) \
    F(DEFOG_EFFECT_CLEARING,     defogEffectClearing,     (u32, GEN_9)) /* TODO */ \
    F(STOCKPILE_RAISES_DEFS,     stockpileRaisesDefs,     (u32, GEN_9)) /* TODO */ \
    F(TRANSFORM_SHINY,           transformShiny,          (u32, GEN_9)) /* TODO */ \
    F(TRANSFORM_FORM_CHANGES,    transformFormChanges,    (u32, GEN_9)) /* TODO */ \
    F(WIDE_GUARD,                wideGuard,               (u32, GEN_9)) /* TODO */ \
    F(QUICK_GUARD,               quickGuard,              (u32, GEN_9)) /* TODO */ \
    F(IMPRISON,                  imprison,                (u32, GEN_9)) /* TODO */ \
    F(ALLY_SWITCH_FAIL_CHANCE,   allySwitchFailChance,    (u32, GEN_9)) \
    F(SKETCH_BANS,               sketchBans,              (u32, GEN_9)) /* TODO */ \
    F(KNOCK_OFF_REMOVAL,         knockOffRemoval,         (u32, GEN_9)) /* TODO */ \
    F(HEAL_BELL_SOUNDPROOF,      healBellSoundproof,      (u32, GEN_9)) \
    F(CHARGE,                    charge,                  (u32, GEN_9)) /* TODO */ \
    F(POWDER_RAIN,               powderRain,              (u32, GEN_9)) \
    F(AFTER_YOU_TURN_ORDER,      afterYouTurnOrder,       (u32, GEN_9)) \
    F(QUASH_TURN_ORDER,          quashTurnOrder,          (u32, GEN_9)) /* TODO */ \
    F(DESTINY_BOND_FAIL,         destinyBondFail,         (u32, GEN_9)) \
    F(PURSUIT_TARGET,            pursuitTarget,           (u32, GEN_9)) /* TODO */ \
    F(SKIP_RECHARGE,             skipRecharge,            (u32, GEN_9)) /* TODO */ \
    F(ENCORE_TARGET,             encoreTarget,            (u32, GEN_9)) \
    F(TIME_OF_DAY_HEALING_MOVES, timeOfDayHealingMoves,   (u32, GEN_9)) \
    F(DREAM_EATER_LIQUID_OOZE,   dreamEaterLiquidOoze,    (u32, GEN_9)) \
    /* Ability settings */ \
    F(GALE_WINGS,                galeWings,               (u32, GEN_9)) \
    F(STANCE_CHANGE_FAIL,        stanceChangeFail,        (u32, GEN_9)) /* TODO */ \
    F(SHADOW_TAG_ESCAPE,         shadowTagEscape,         (u32, GEN_9)) /* TODO */ \
    F(MOODY_ACC_EVASION,         moodyAccEvasion,         (u32, GEN_9)) \
    F(FLASH_FIRE_FROZEN,         flashFireFrozen,         (u32, GEN_9)) /* TODO */ \
    F(SYNCHRONIZE_TOXIC,         synchronizeToxic,        (u32, GEN_9)) /* TODO */ \
    F(UPDATED_INTIMIDATE,        updatedIntimidate,       (u32, GEN_9)) \
    F(OBLIVIOUS_TAUNT,           obliviousTaunt,          (u32, GEN_9)) /* TODO */ \
    F(STURDY,                    sturdy,                  (u32, GEN_9)) /* TODO */ \
    F(PLUS_MINUS_INTERACTION,    plusMinusInteraction,    (u32, GEN_9)) /* TODO */ \
    F(WEATHER_FORMS,             weatherForms,            (u32, GEN_9)) /* TODO */ \
    F(SYMBIOSIS_GEMS,            symbiosisGems,           (u32, GEN_9)) /* TODO */ \
    F(ABSORBING_ABILITY_STRING,  absorbingAbilityString,  (u32, GEN_9)) /* TODO */ \
    F(REDIRECT_ABILITY_IMMUNITY, redirectAbilityImmunity, (u32, GEN_9)) /* TODO */ \
    F(REDIRECT_ABILITY_ALLIES,   redirectAbilityAllies,   (u32, GEN_9)) /* TODO */ \
    F(LEAF_GUARD_PREVENTS_REST,  leafGuardPreventsRest,   (u32, GEN_9)) /* TODO */ \
    F(TRANSISTOR_BOOST,          transistorBoost,         (u32, GEN_9)) \
    F(ILLUMINATE_EFFECT,         illuminateEffect,        (u32, GEN_9)) \
    F(WEAK_ARMOR_SPEED,          weakArmorSpeed,          (u32, GEN_9)) \
    F(PROTEAN_LIBERO,            proteanLibero,           (u32, GEN_9)) \
    F(INTREPID_SWORD,            intrepidSword,           (u32, GEN_9)) \
    F(DAUNTLESS_SHIELD,          dauntlessShield,         (u32, GEN_9)) \
    F(DISGUISE_HP_LOSS,          disguiseHpLoss,          (u32, GEN_9)) \
    F(ABILITY_TRIGGER_CHANCE,    abilityTriggerChance,    (u32, GEN_9)) /* TODO */ \
    F(PICKUP_WILD,               pickupWild,              (u32, GEN_9)) \
    F(MAGIC_GUARD,               magicGuard,              (u32, GEN_9)) /* TODO */ \
    F(BATTLE_BOND,               battleBond,              (u32, GEN_9)) \
    F(ATE_MULTIPLIER,            ateMultiplier,           (u32, GEN_9)) \
    F(DEFIANT_STICKY_WEB,        defiantStickyWeb,        (u32, GEN_9)) \
    /* Item settings */ \
    F(HP_BERRIES,                hpBerries,               (u32, GEN_9)) /* TODO */ \
    F(BERRIES_INSTANT,           berriesInstant,          (u32, GEN_9)) /* TODO */ \
    F(CONFUSE_BERRIES_HEAL,      confuseBerriesHeal,      (u32, GEN_9)) /* TODO */ \
    F(X_ITEMS_BUFF,              xItemsBuff,              (u32, GEN_9)) /* TODO */ \
    F(MENTAL_HERB,               mentalHerb,              (u32, GEN_9)) /* TODO */ \
    F(TRAINERS_KNOCK_OFF_ITEMS,  trainersKnockOffItems,   (u32, GEN_9)) /* TODO */ \
    F(RETURN_STOLEN_NPC_ITEMS,   returnStolenNpcItems,    (u32, GEN_9)) /* TODO */ \
    F(STEAL_WILD_ITEMS,          stealWildItems,          (u32, GEN_9)) \
    F(RESTORE_HELD_BATTLE_ITEMS, restoreHeldBattleItems,  (u32, GEN_9)) /* TODO */ \
    F(SOUL_DEW_BOOST,            soulDewBoost,            (u32, GEN_9)) /* TODO */ \
    F(NET_BALL_MODIFIER,         netBallModifier,         (u32, GEN_9)) /* TODO */ \
    F(DIVE_BALL_MODIFIER,        diveBallModifier,        (u32, GEN_9)) /* TODO */ \
    F(NEST_BALL_MODIFIER,        nestBallModifier,        (u32, GEN_9)) /* TODO */ \
    F(REPEAT_BALL_MODIFIER,      repeatBallModifier,      (u32, GEN_9)) /* TODO */ \
    F(TIMER_BALL_MODIFIER,       timerBallModifier,       (u32, GEN_9)) /* TODO */ \
    F(DUSK_BALL_MODIFIER,        duskBallModifier,        (u32, GEN_9)) /* TODO */ \
    F(QUICK_BALL_MODIFIER,       quickBallModifier,       (u32, GEN_9)) /* TODO */ \
    F(LURE_BALL_MODIFIER,        lureBallModifier,        (u32, GEN_9)) /* TODO */ \
    F(HEAVY_BALL_MODIFIER,       heavyBallModifier,       (u32, GEN_9)) /* TODO */ \
    F(DREAM_BALL_MODIFIER,       dreamBallModifier,       (u32, GEN_9)) /* TODO */ \
    F(SPORT_BALL_MODIFIER,       sportBallModifier,       (u32, GEN_9)) /* TODO */ \
    F(SAFARI_BALL_MODIFIER,      safariBallModifier,      (u32, GEN_9)) /* TODO */ \
    F(FRIEND_BALL_MODIFIER,      friendBallModifier,      (u32, GEN_9)) /* TODO */ \
    F(SERENE_GRACE_BOOST,        sereneGraceBoost,        (u32, GEN_9)) /* TODO */ \
    F(IRON_BALL,                 ironBall,                (u32, GEN_9)) /* TODO */ \
    /* Weather settings */ \
    F(ABILITY_WEATHER,           abilityWeather,          (u32, GEN_9)) \
    F(SANDSTORM_SPDEF_BOOST,     sandstormSpDefBoost,     (u32, GEN_9)) /* TODO */ \
    F(OVERWORLD_FOG,             overworldFog,            (u32, GEN_9)) /* TODO */ \
    F(OVERWORLD_SNOW,            overworldSnow,           (u32, GEN_9)) /* TODO */ \
    F(SNOW_WARNING,              snowWarning,             (u32, GEN_9)) \
    F(PREFERRED_ICE_WEATHER,     preferredIceWeather,     (u32, B_ICE_WEATHER_SNOW)) /* TODO */ \
    /* Terrain settings */ \
    F(TERRAIN_TYPE_BOOST,        terrainTypeBoost,        (u32, GEN_9)) /* TODO */ \
    F(SECRET_POWER_EFFECT,       secretPowerEffect,       (u32, GEN_9)) /* TODO */ \
    F(SECRET_POWER_ANIMATION,    secretPowerAnimation,    (u32, GEN_9)) /* TODO */ \
    F(NATURE_POWER_MOVES,        naturePowerMoves,        (u32, GEN_9)) /* TODO */ \
    F(CAMOUFLAGE_TYPES,          camouflageTypes,         (u32, GEN_9)) /* TODO */ \
    /* Other settings */ \
    F(WILD_NATURAL_ENEMIES,      wildNaturalEnemies,      (u32, TRUE))  /* TODO */ \
    F(AFFECTION_MECHANICS,       affectionMechanics,      (u32, TRUE))  /* TODO */ \
    F(OBEDIENCE_MECHANICS,       obedienceMechanics,      (u32, GEN_9)) /* TODO */ \
    F(USE_FROSTBITE,             useFrostbite,            (u32, GEN_9)) /* TODO */ \


#define GET_CONFIG_MAXIMUM(_typeMaxValue, ...) INVOKE_WITH_B(GET_CONFIG_MAXIMUM_, _typeMaxValue)
#define GET_CONFIG_MAXIMUM_(_type, ...) FIRST(__VA_OPT__(FIRST(__VA_ARGS__),) MAX_BITS((sizeof(_type) * 8)))

#define UNPACK_CONFIG_ENUMS(_name, ...) GEN_CONFIG_##_name,

enum GenConfigTag
{
    CONFIG_DEFINITIONS(UNPACK_CONFIG_ENUMS)
};

#endif // GUARD_CONSTANTS_GENERATIONAL_CHANGES_H
