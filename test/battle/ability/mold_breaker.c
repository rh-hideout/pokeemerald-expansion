#include "global.h"
#include "test/battle.h"

static bool32 IsBreakableAbility(enum Ability ability)
{
    switch (ability)
    {
    default:
        return FALSE;
    case ABILITY_BATTLE_ARMOR:
    case ABILITY_STURDY:
    case ABILITY_DAMP:
    case ABILITY_LIMBER:
    case ABILITY_SAND_VEIL:
    case ABILITY_VOLT_ABSORB:
    case ABILITY_WATER_ABSORB:
    case ABILITY_OBLIVIOUS:
    case ABILITY_INSOMNIA:
    case ABILITY_IMMUNITY:
    case ABILITY_FLASH_FIRE:
    case ABILITY_SHIELD_DUST:
    case ABILITY_OWN_TEMPO:
    case ABILITY_SUCTION_CUPS:
    case ABILITY_WONDER_GUARD:
    case ABILITY_LEVITATE:
    case ABILITY_CLEAR_BODY:
    case ABILITY_LIGHTNING_ROD:
    case ABILITY_ILLUMINATE:
    case ABILITY_INNER_FOCUS:
    case ABILITY_MAGMA_ARMOR:
    case ABILITY_WATER_VEIL:
    case ABILITY_SOUNDPROOF:
    case ABILITY_THICK_FAT:
    case ABILITY_KEEN_EYE:
    case ABILITY_HYPER_CUTTER:
    case ABILITY_STICKY_HOLD:
    case ABILITY_MARVEL_SCALE:
    case ABILITY_VITAL_SPIRIT:
    case ABILITY_WHITE_SMOKE:
    case ABILITY_SHELL_ARMOR:
    case ABILITY_TANGLED_FEET:
    case ABILITY_MOTOR_DRIVE:
    case ABILITY_SNOW_CLOAK:
    case ABILITY_HEATPROOF:
    case ABILITY_SIMPLE:
    case ABILITY_DRY_SKIN:
    case ABILITY_LEAF_GUARD:
    case ABILITY_UNAWARE:
    case ABILITY_FILTER:
    case ABILITY_STORM_DRAIN:
    case ABILITY_SOLID_ROCK:
    case ABILITY_FLOWER_GIFT:
    case ABILITY_CONTRARY:
    case ABILITY_FRIEND_GUARD:
    case ABILITY_HEAVY_METAL:
    case ABILITY_LIGHT_METAL:
    case ABILITY_MULTISCALE:
    case ABILITY_TELEPATHY:
    case ABILITY_OVERCOAT:
    case ABILITY_BIG_PECKS:
    case ABILITY_WONDER_SKIN:
    case ABILITY_MAGIC_BOUNCE:
    case ABILITY_SAP_SIPPER:
    case ABILITY_AROMA_VEIL:
    case ABILITY_FLOWER_VEIL:
    case ABILITY_FUR_COAT:
    case ABILITY_BULLETPROOF:
    case ABILITY_SWEET_VEIL:
    case ABILITY_GRASS_PELT:
    case ABILITY_AURA_BREAK:
    case ABILITY_WATER_BUBBLE:
    case ABILITY_DISGUISE:
    case ABILITY_QUEENLY_MAJESTY:
    case ABILITY_FLUFFY:
    case ABILITY_DAZZLING:
    case ABILITY_MIRROR_ARMOR:
    case ABILITY_PUNK_ROCK:
    case ABILITY_ICE_SCALES:
    case ABILITY_ICE_FACE:
    case ABILITY_PASTEL_VEIL:
    case ABILITY_THERMAL_EXCHANGE:
    case ABILITY_PURIFYING_SALT:
    case ABILITY_WELL_BAKED_BODY:
    case ABILITY_WIND_RIDER:
    case ABILITY_GUARD_DOG:
    case ABILITY_GOOD_AS_GOLD:
    case ABILITY_VESSEL_OF_RUIN:
    case ABILITY_SWORD_OF_RUIN:
    case ABILITY_TABLETS_OF_RUIN:
    case ABILITY_BEADS_OF_RUIN:
    case ABILITY_ARMOR_TAIL:
    case ABILITY_EARTH_EATER:
    case ABILITY_MINDS_EYE:
    case ABILITY_TERA_SHELL:
        return TRUE;
    }
}

TEST("Correct abilities have the breakable flag")
{
    for (u32 i = 0; i < ABILITIES_COUNT; i++) {
        bool32 isBreakable = gAbilitiesInfo[i].breakable;
        EXPECT_EQ(IsBreakableAbility(i), isBreakable);
    }
}

SINGLE_BATTLE_TEST("Mold Breaker cancels damage reduction from Ice Scales", s16 damage)
{
    u16 ability;
    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_PSYCHIC) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_FROSMOTH) { Ability(ABILITY_ICE_SCALES); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.5), results[0].damage);
    }
}

TO_DO_BATTLE_TEST("TODO: Write more Mold Breaker (Ability) test titles")

