#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GRAV_APPLE) == EFFECT_GRAV_APPLE);
    ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_GRAV_APPLE, self: FALSE, defense: -1);
}

SINGLE_BATTLE_TEST("Grav Apple lowers the target's Defense by 1 stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRAV_APPLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAV_APPLE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Defense fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor reflects Grav Apple's Defense drop and considers Simple and Contrary")
{
    enum Species species;
    enum Ability ability;
    s32 expectedDelta;

    PARAMETRIZE { species = SPECIES_BIBAREL; ability = ABILITY_SIMPLE;   expectedDelta = -2; }
    PARAMETRIZE { species = SPECIES_INKAY;   ability = ABILITY_CONTRARY; expectedDelta = 1; }

    GIVEN {
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_GRAV_APPLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAV_APPLE, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + expectedDelta);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Grav Apple's power increases by 50% under Gravity's effect", s16 damage)
{
    u32 setupMove;
    PARAMETRIZE { setupMove = MOVE_CELEBRATE; }
    PARAMETRIZE { setupMove = MOVE_GRAVITY; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRAVITY) == EFFECT_GRAVITY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, setupMove); }
        TURN { MOVE(player, MOVE_GRAV_APPLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAV_APPLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
