#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Super Fang (Move Effect) test titles")

SINGLE_BATTLE_TEST("Dynamax: Super Fang uses a Pokemon's non-Dynamax HP", s16 damage)
{
    u32 dynamax;
    PARAMETRIZE { dynamax = GIMMICK_NONE; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPER_FANG); MOVE(player, MOVE_SCRATCH, gimmick: dynamax); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Super Fang!");
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
