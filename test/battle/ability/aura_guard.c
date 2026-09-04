#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
}

SINGLE_BATTLE_TEST("Aura Guard halves damage taken from moves that make direct contact", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SKILL_SWAP; }
    GIVEN {
        PLAYER(SPECIES_LUCARIO) { Item(ITEM_LUCARIONITE_Z); }
        OPPONENT(SPECIES_WOBBUFFET) {};
    } WHEN {
        TURN {
            MOVE(player, move, gimmick: GIMMICK_MEGA);
            MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.5), results[0].damage);
    }
}
