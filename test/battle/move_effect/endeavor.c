#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ENDEAVOR) == EFFECT_ENDEAVOR);
}

SINGLE_BATTLE_TEST("Endeavor causes the target's HP to equal the user's current HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDEAVOR, player);
    } THEN {
        EXPECT_EQ(player->hp, opponent->hp);
    }
}
TO_DO_BATTLE_TEST("Endeavor does not change HP if the target has less HP than the user, but still plays the animation")
TO_DO_BATTLE_TEST("Endeavor fails on Ghost-type Pokémon");

SINGLE_BATTLE_TEST("Dynamax: Endeavor uses a Pokemon's non-Dynamax HP", s16 damage)
{
    u32 dynamax;
    PARAMETRIZE { dynamax = GIMMICK_NONE; }
    PARAMETRIZE { dynamax = GIMMICK_DYNAMAX; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENDEAVOR) == EFFECT_ENDEAVOR);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDEAVOR); MOVE(player, MOVE_SCRATCH, gimmick: dynamax); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Endeavor!");
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
