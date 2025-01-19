#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dynamax Cannon causes double damage to Dynamaxed Pokemon", s16 damage)
{
    u32 dynamax;
    PARAMETRIZE { dynamax = GIMMICK_NONE; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DYNAMAX_CANNON].effect == EFFECT_DYNAMAX_DOUBLE_DMG);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, gimmick: dynamax); MOVE(opponent, MOVE_DYNAMAX_CANNON); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}
