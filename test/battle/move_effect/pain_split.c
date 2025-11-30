#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Pain Split (Move Effect) test titles")

SINGLE_BATTLE_TEST("Dynamax: Pain Split uses a Pokemon's non-Dynamax HP", s16 damage)
{
    u32 dynamax;
    PARAMETRIZE { dynamax = GIMMICK_NONE; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PAIN_SPLIT) == EFFECT_PAIN_SPLIT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PAIN_SPLIT); MOVE(player, MOVE_SCRATCH, gimmick: dynamax); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Pain Split!");
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
