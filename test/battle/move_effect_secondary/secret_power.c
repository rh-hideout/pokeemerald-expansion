#include "global.h"
#include "battle_environment.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SECRET_POWER) == EFFECT_SECRET_POWER);
    ASSUME(GetMoveSecondaryEffectChance(MOVE_SECRET_POWER) == 30);
}

SINGLE_BATTLE_TEST("Secret Power inflicts paralysis in Electric Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Secret Power inflicts sleep in Grassy Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_GRASSY_TERRAIN) == B_TERRAIN_GRASSY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRASSY_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Secret Power lowers Speed in Psychic Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_PSYCHIC_TERRAIN) == B_TERRAIN_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Secret Power lowers Sp. Atk in Misty Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MISTY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_MISTY_TERRAIN) == B_TERRAIN_MISTY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MISTY_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Serene Grace doubles Secret Power's secondary effect chance")
{
    PASSES_RANDOMLY(60, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        PLAYER(SPECIES_TOGEPI) { Ability(ABILITY_SERENE_GRACE); Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Rainbow doubles Secret Power's secondary effect chance")
{
    PASSES_RANDOMLY(60, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ELECTRIC_TERRAIN);
               MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight); }
        TURN { MOVE(playerLeft, MOVE_SECRET_POWER, target: opponentRight); }
    } SCENE {
        STATUS_ICON(opponentRight, paralysis: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Rainbow and Serene Grace stack for Secret Power's non-flinch effects")
{
    PASSES_RANDOMLY(100, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        PLAYER(SPECIES_TOGEPI) { Ability(ABILITY_SERENE_GRACE); Speed(5); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ELECTRIC_TERRAIN);
               MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight); }
        TURN { MOVE(playerLeft, MOVE_SECRET_POWER, target: opponentRight); }
    } SCENE {
        STATUS_ICON(opponentRight, paralysis: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Rainbow and Serene Grace do not stack for Secret Power's flinch effect")
{
    PASSES_RANDOMLY(60, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(gBattleEnvironmentInfo[BATTLE_ENVIRONMENT_CAVE].secretPowerEffect == MOVE_EFFECT_FLINCH);
        PLAYER(SPECIES_TOGEPI) { Ability(ABILITY_SERENE_GRACE); Speed(8); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
        Environment(BATTLE_ENVIRONMENT_CAVE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight); }
        TURN { MOVE(playerLeft, MOVE_SECRET_POWER, target: opponentRight); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Wynaut flinched and couldn't move!");
    }
}

SINGLE_BATTLE_TEST("Secret Power does not inflict its secondary effect if the user faints")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        ASSUME(GetMoveCategory(MOVE_SECRET_POWER) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gItemsInfo[ITEM_JABOCA_BERRY].holdEffect == HOLD_EFFECT_JABOCA_BERRY);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_JABOCA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN { MOVE(player, MOVE_SECRET_POWER, WITH_RNG(RNG_SECONDARY_EFFECT, TRUE)); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        HP_BAR(player, hp: 0);
        MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Jaboca Berry!");
        MESSAGE("Wobbuffet fainted!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}
