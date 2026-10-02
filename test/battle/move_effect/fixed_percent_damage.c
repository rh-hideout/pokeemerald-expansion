#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
    ASSUME(GetMoveDamagePercentage(MOVE_SUPER_FANG) == 50);
}

SINGLE_BATTLE_TEST("Super Fang does 50% damage to the target's current HP")
{
    s16 damage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(200); HP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 50);
    }
}

SINGLE_BATTLE_TEST("Super Fang always deals at least 1 HP of damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(200); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent, damage: 1);
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Super Fang is unaffected by type immunities (Gen 1)")
{
    s16 damage;

    GIVEN {
        WITH_CONFIG(B_FIXED_DMG_IGNORES_TYPE, GEN_1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY) { MaxHP(100); HP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 50);
    }
}

SINGLE_BATTLE_TEST("Super Fang doesn't hit Ghost-type Pokémon (Gen 2+)")
{
    u32 genConfig;

    PARAMETRIZE { genConfig = GEN_2; }
    PARAMETRIZE { genConfig = GEN_5; }
    PARAMETRIZE { genConfig = GEN_LATEST; }
    GIVEN {
        WITH_CONFIG(B_FIXED_DMG_IGNORES_TYPE, genConfig);
        ASSUME(GetMoveType(MOVE_SUPER_FANG) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_GASTLY, 0) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY) { MaxHP(100); HP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        MESSAGE("It doesn't affect the opposing Gastly…");
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Guardian of Alola does 75% damage to the target's current HP")
{
    s16 damage;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GUARDIAN_OF_ALOLA) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetMoveDamagePercentage(MOVE_GUARDIAN_OF_ALOLA) == 75);
        PLAYER(SPECIES_TAPU_KOKO) { Item(ITEM_TAPUNIUM_Z); Moves(MOVE_NATURES_MADNESS); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(200); HP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_NATURES_MADNESS, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARDIAN_OF_ALOLA, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 75);
    }
}
