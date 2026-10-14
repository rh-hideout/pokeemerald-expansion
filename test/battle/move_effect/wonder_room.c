#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_WONDER_ROOM) == EFFECT_WONDER_ROOM);
    ASSUME(GetMoveCategory(MOVE_COVET) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMovePower(MOVE_COVET) == GetMovePower(MOVE_SWIFT));
    ASSUME(GetMoveType(MOVE_COVET) == GetMoveType(MOVE_SWIFT));
}

SINGLE_BATTLE_TEST("Wonder Room swaps Defense and Sp. Def for physical and special damage", s16 damage)
{
    bool32 useWonderRoom;
    enum Move move;

    PARAMETRIZE { useWonderRoom = FALSE; move = MOVE_COVET; }
    PARAMETRIZE { useWonderRoom = TRUE;  move = MOVE_COVET; }
    PARAMETRIZE { useWonderRoom = FALSE; move = MOVE_SWIFT; }
    PARAMETRIZE { useWonderRoom = TRUE;  move = MOVE_SWIFT; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); SpAttack(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(200); SpDefense(100); Speed(50); }
    } WHEN {
        if (useWonderRoom)
            TURN { MOVE(player, MOVE_WONDER_ROOM); }
        TURN { MOVE(player, move); }
    } SCENE {
        if (useWonderRoom)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WONDER_ROOM, player);
            MESSAGE("It created a bizarre area in which Defense and Sp. Def stats are swapped!");
        }
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[3].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
        EXPECT_LT(results[0].damage, results[1].damage);
    }
}
