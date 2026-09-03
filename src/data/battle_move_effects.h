#include "battle.h"
#include "battle_scripts.h"
#include "constants/battle_factory.h"
#include "constants/battle_move_effects.h"

const struct BattleMoveEffect gBattleMoveEffects[NUM_BATTLE_MOVE_EFFECTS] =
{
    [EFFECT_PLACEHOLDER] =
    {
        .battleTvScore = 0,
    },

    [EFFECT_HIT] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_STAT_CHANGE] =
    {
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_DEFENSE_CURL] =
    {
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_MINIMIZE] =
    {
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_AUTOTOMIZE] =
    {
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_GEOMANCY] =
    {
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
        .twoTurnEffect = TRUE,
    },

    [EFFECT_NON_VOLATILE_STATUS] =
    {
        .battleTvScore = 0, // Handled within the battle TV functions
        .encourageEncore = TRUE,
    },

    [EFFECT_TERRAIN_BOOST] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DREAM_EATER] =
    {
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_MIRROR_MOVE] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_HAZE] =
    {
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_BIDE] =
    {
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_ROAR] =
    {
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_CONVERSION] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_RESTORE_HP] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_LIGHT_SCREEN] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_REST] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_OHKO] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_FUSION_COMBO] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FIXED_PERCENT_DAMAGE] =
    {
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_FIXED_HP_DAMAGE] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_HEAL_BLOCK] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_RECOIL_IF_MISS] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_MIST] =
    {
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_FOCUS_ENERGY] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_CONFUSE] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_TRANSFORM] =
    {
        .battleTvScore = 0, // Natural 0
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_REFLECT] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_TWO_TURNS_ATTACK] =
    {
        .battleTvScore = 3,
        .twoTurnEffect = TRUE,
    },

    [EFFECT_SUBSTITUTE] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_MIMIC] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_METRONOME] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_LEECH_SEED] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_DO_NOTHING] =
    {
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_HOLD_HANDS] =
    {
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_CELEBRATE] =
    {
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_HAPPY_HOUR] =
    {
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_DISABLE] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_LEVEL_DAMAGE] =
    {
        .battleTvScore = 2,
    },

    [EFFECT_PSYWAVE] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_REFLECT_DAMAGE] =
    {
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
        .encourageEncore = TRUE,
    },

    [EFFECT_ENCORE] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_PAIN_SPLIT] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_SNORE] =
    {
        .battleTvScore = 3,
    },

    [EFFECT_CONVERSION_2] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_LOCK_ON] =
    {
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_SKETCH] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_SLEEP_TALK] =
    {
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_DESTINY_BOND] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_FLAIL] =
    {
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_SPITE] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_WEAKENING,
    },

    [EFFECT_FALSE_SWIPE] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_HEAL_BELL] =
    {
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_TRIPLE_KICK] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_MEAN_LOOK] =
    {
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_NIGHTMARE] =
    {
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_CURSE] =
    {
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_HEALING_WISH] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_LUNAR_DANCE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PROTECT] =
    {
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
        .usesProtectCounter = TRUE,
    },

    [EFFECT_SPIKES] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_FORESIGHT] =
    {
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_PERISH_SONG] =
    {
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
        .encourageEncore = TRUE,
    },

    [EFFECT_ENDURE] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
        .usesProtectCounter = TRUE,
    },

    [EFFECT_ROLLOUT] =
    {
        .battleTvScore = 3,
    },

    [EFFECT_SWAGGER] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_FURY_CUTTER] =
    {
        .battleTvScore = 2,
    },

    [EFFECT_ATTRACT] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_RETURN] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_PRESENT] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_FRUSTRATION] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_SAFEGUARD] =
    {
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_MAGNITUDE] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_BATON_PASS] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
    },

    [EFFECT_PURSUIT] =
    {
        .battleTvScore = 2,
    },

    [EFFECT_CAPTIVATE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MORNING_SUN] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_SYNTHESIS] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_MOONLIGHT] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_HIDDEN_POWER] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_WEATHER] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_WEATHER,
        .encourageEncore = TRUE,
    },

    [EFFECT_FELL_STINGER] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STAT_CHANGE_HALF_HP] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_BELLY_DRUM] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_PSYCH_UP] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_EARTHQUAKE] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_FUTURE_SIGHT] =
    {
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SOLAR_BEAM] =
    {
        .battleTvScore = 1,
        .twoTurnEffect = TRUE,
    },

    [EFFECT_TELEPORT] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_BEAT_UP] =
    {
        .battleTvScore = 2,
    },

    [EFFECT_SEMI_INVULNERABLE] =
    {
        .battleTvScore = 3,
        .twoTurnEffect = TRUE,
        .semiInvulnerableEffect = TRUE,
    },

    [EFFECT_SOFTBOILED] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_FIRST_TURN_ONLY] =
    {
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_STOCKPILE] =
    {
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPIT_UP] =
    {
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_SWALLOW] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_OVERWRITE_ABILITY] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TORMENT] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_MEMENTO] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_FACADE] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_FOCUS_PUNCH] =
    {
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_DOUBLE_POWER_ON_ARG_STATUS] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_FOLLOW_ME] =
    {
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_NATURE_POWER] =
    {
        .battleTvScore = 0, // Natural 0
    },

    [EFFECT_CHARGE] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_TAUNT] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_HELPING_HAND] =
    {
        .battleTvScore = 4,
    },

    [EFFECT_TRICK] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_ROLE_PLAY] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_WISH] =
    {
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
    },

    [EFFECT_ASSIST] =
    {
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_INGRAIN] =
    {
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_MAGIC_COAT] =
    {
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
    },

    [EFFECT_RECYCLE] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_REVENGE] =
    {
        .battleTvScore = 4,
    },

    [EFFECT_YAWN] =
    {
        .battleTvScore = 5,
    },

    [EFFECT_KNOCK_OFF] =
    {
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_WEAKENING,
    },

    [EFFECT_STEAL_ITEM] =
    {
        .battleTvScore = 3,
    },

    [EFFECT_ENDEAVOR] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_POWER_BASED_ON_USER_HP] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_SKILL_SWAP] =
    {
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_IMPRISON] =
    {
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_REFRESH] =
    {
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_GRUDGE] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
        .encourageEncore = TRUE,
    },

    [EFFECT_SNATCH] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_LOW_KICK] =
    {
        .battleTvScore = 1,
    },

    [EFFECT_HIT_ESCAPE] =
    {
        .battleTvScore = 4,
    },

    [EFFECT_MUD_SPORT] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_WEATHER_BALL] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_WEATHER,
    },

    [EFFECT_WATER_SPORT] =
    {
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_CAMOUFLAGE] =
    {
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_PLEDGE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FLING] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_NATURAL_GIFT] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_POWER_BASED_ON_TARGET_HP] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ASSURANCE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TRUMP_CARD] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ACROBATICS] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HEAT_CRASH] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PUNISHMENT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STORED_POWER] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ELECTRO_BALL] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GYRO_BALL] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ECHOED_VOICE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PAYBACK] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ROUND] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BRINE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RETALIATE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FOUL_PLAY] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PSYSHOCK] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ROOST] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GRAVITY] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_MIRACLE_EYE] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TAILWIND] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_EMBARGO] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_AQUA_RING] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TRICK_ROOM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_WONDER_ROOM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAGIC_ROOM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAGNET_RISE] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TOXIC_SPIKES] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GASTRO_ACID] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STEALTH_ROCK] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TELEKINESIS] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_POWER_SWAP] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GUARD_SWAP] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_HEART_SWAP] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POWER_SPLIT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GUARD_SPLIT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STICKY_WEB] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_LUCKY_CHANT] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SUCKER_PUNCH] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ENTRAINMENT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HEAL_PULSE] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_QUASH] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_ION_DELUGE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SUPER_EFFECTIVE_ON_ARG] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TOPSY_TURVY] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TERRAIN] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TWO_TYPED_MOVE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ME_FIRST] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ELECTRIFY] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_REFLECT_TYPE] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_OVERWRITE_TYPE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GROWTH] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_LAST_RESORT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STAT_CHANGE_ON_STATUS] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TOXIC_THREAD] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HIT_SWITCH_TARGET] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FINAL_GAMBIT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CHANGE_TYPE_ON_ITEM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_COPYCAT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DEFOG] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_HIT_ENEMY_HEAL_ALLY] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SYNCHRONOISE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PSYCHO_SHIFT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POWER_TRICK] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_AFTER_YOU] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_BESTOW] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_ROTOTILLER] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FLOWER_SHIELD] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SPEED_SWAP] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_REVELATION_DANCE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_AURORA_VEIL] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_THIRD_TYPE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ACUPRESSURE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POWDER] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BELCH] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PARTING_SHOT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAT_BLOCK] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_STOMPING_TANTRUM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_INSTRUCT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_LASER_FOCUS] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_STAT_CHANGE_MAGNETIC] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_STRENGTH_SAP] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PURIFY] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_FAIL_IF_NOT_ARG_TYPE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHORE_UP] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_FAIRY_LOCK] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ALLY_SWITCH] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BODY_PRESS] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_JUNGLE_HEALING] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_LASH_OUT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GRASSY_GLIDE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DYNAMAX_DOUBLE_DMG] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SNIPE_SHOT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STRUGGLE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STUFF_CHEEKS] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GRAV_APPLE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HYPERSPACE_FURY] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_AURA_WHEEL] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PHOTON_GEYSER] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TERRAIN_PULSE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_NO_RETREAT] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TAR_SHOT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POLTERGEIST] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_OCTOLOCK] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CLANGOROUS_SOUL] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BOLT_BEAK] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SKY_DROP] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .twoTurnEffect = TRUE,
        .semiInvulnerableEffect = TRUE,
    },

    [EFFECT_BEAK_BLAST] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_COURT_CHANGE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAX_HP_50_RECOIL] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CHLOROBLAST] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_EXTREME_EVOBOOST] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DARK_VOID] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TEATIME] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SHELL_TRAP] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HYDRO_STEAM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_REVIVAL_BLESSING] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TAKE_HEART] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_COLLISION_COURSE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CORROSIVE_GAS] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .battleFactoryStyle = FACTORY_STYLE_WEAKENING,
    },

    [EFFECT_POPULATION_BOMB] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_WEATHER_AND_SWITCH] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .battleFactoryStyle = FACTORY_STYLE_WEATHER,
    },

    [EFFECT_MAX_MOVE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RAGING_BULL] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RAGE_FIST] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DOODLE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_IVY_CUDGEL] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FICKLE_BEAM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHED_TAIL] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_UPPER_HAND] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_DRAGON_CHEER] =
    {
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_LAST_RESPECTS] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TIDY_UP] =
    {
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TERA_BLAST] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TERA_STARSTORM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHELL_SIDE_ARM] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RAPID_SPIN] =
    {
        .battleTvScore = 2,
    },

    [EFFECT_RECOIL] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SMACK_DOWN] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_LIFE_DEW] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ICE_SPINNER] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STEEL_ROLLER] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STONE_AXE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CEASELESS_EDGE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SPECIES_POWER_OVERRIDE] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SCALE_SHOT] =
    {
        .battleTvScore = 0, // TODO: Assign points
    },
};
