#include "global.h"
#include "constants/battle.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "fpmath.h"
#include "test/battle.h"
#include "test/test.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_WONDER_ROOM) == EFFECT_WONDER_ROOM);
}

DOUBLE_BATTLE_TEST("Wonder room swaps the defense and special defense of all battlers")
{
    s16 preDamage[4], postDamage[4];
    enum Move move;
    u32 def, spdef;

    PARAMETRIZE(move = MOVE_COVET);
    PARAMETRIZE(move = MOVE_SWIFT);

    GIVEN {
        if (move == MOVE_COVET)
        {
            def = 200;
            spdef = 100;
        }
        else
        {
            def = 100;
            spdef = 200;
        }

        PLAYER(SPECIES_WOBBUFFET)   {Defense(def); SpDefense(spdef);}
        PLAYER(SPECIES_WOBBUFFET)   {Defense(def); SpDefense(spdef);}
        OPPONENT(SPECIES_WOBBUFFET) {Defense(def); SpDefense(spdef);}
        OPPONENT(SPECIES_WOBBUFFET) {Defense(def); SpDefense(spdef);}

    } WHEN {
        TURN {
            MOVE(playerLeft,    move, target : opponentLeft),
            MOVE(opponentLeft,  move, target : playerLeft),
            MOVE(playerRight,   move, target : opponentRight),
            MOVE(opponentRight, move, target : playerRight);
            }
        TURN { MOVE(playerLeft, MOVE_WONDER_ROOM); }

        TURN {
            MOVE(playerLeft,    move, target : opponentLeft),
            MOVE(opponentLeft,  move, target : playerLeft),
            MOVE(playerRight,   move, target : opponentRight),
            MOVE(opponentRight, move, target : playerRight);
            }
    } SCENE {

        HP_BAR(opponentLeft,  captureDamage: &preDamage[2]);
        HP_BAR(playerLeft,    captureDamage: &preDamage[0]);
        HP_BAR(opponentRight, captureDamage: &preDamage[3]);
        HP_BAR(playerRight,   captureDamage: &preDamage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WONDER_ROOM, playerLeft);
        MESSAGE("It created a bizarre area in which Defense and Sp. Def stats are swapped!");

        HP_BAR(opponentLeft,  captureDamage: &postDamage[2]);
        HP_BAR(playerLeft,    captureDamage: &postDamage[0]);
        HP_BAR(opponentRight, captureDamage: &postDamage[3]);
        HP_BAR(playerRight,   captureDamage: &postDamage[1]);

    } THEN {
        for (u32 i = 0; i < 4; i++)
        {
            EXPECT_MUL_EQ(preDamage[i], Q_4_12(2.0), postDamage[i]);
        }
    }

}
