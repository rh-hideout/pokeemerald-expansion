#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bombs Away increases same-type attack bonus from x1.5 to x2", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_HYPER_CUTTER; }
    PARAMETRIZE { ability = ABILITY_BOMBS_AWAY; }
    GIVEN {
        PLAYER(SPECIES_CRAWDAUNT) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHADOW_BALL); }
    } SCENE {
        MESSAGE("Crawdaunt used Shadow Ball!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_BALL, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // The jump from 1.5x STAB to 2.0x STAB is a 1.33x boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}