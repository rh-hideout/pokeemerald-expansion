#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Showdown Mode hurts the user for 1/6 of max hp")
{
    s16 showdownmodeDamage;

    GIVEN {
        PLAYER(SPECIES_VOLTORB);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHOWDOWN_MODE);}
    } WHEN {
        TURN {MOVE(opponent, MOVE_TACKLE);}
    } SCENE {
        MESSAGE("Foe Wobbuffet used Tackle!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(opponent, captureDamage: &showdownmodeDamage);
    } THEN {
        EXPECT_EQ(showdownmodeDamage, opponent->maxHP / 6);
    }
}

SINGLE_BATTLE_TEST("Showdown Mode increases physical damage by 1.5 but not special damage", s16 damage)
{
    u32 move;
    PARAMETRIZE { move = MOVE_DISCHARGE; }
    PARAMETRIZE { move = MOVE_IRON_HEAD; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHOWDOWN_MODE);};
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
