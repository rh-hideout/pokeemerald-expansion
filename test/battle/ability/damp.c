#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Damp stops blocking Explosion while suppressed")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        ASSUME(IsMoveDampBanned(MOVE_EXPLOSION));
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); MaxHP(1000); HP(1000); }
        OPPONENT(SPECIES_MEW) { MaxHP(100); HP(100); Attack(100); }
    } WHEN {
        if (suppress) {
            TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        }

        TURN { MOVE(opponent, MOVE_EXPLOSION); }
    } SCENE {
        if (suppress) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, opponent);
            HP_BAR(player);
        } else {
            ABILITY_POPUP(player, ABILITY_DAMP);
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, opponent);
                HP_BAR(player);
                HP_BAR(opponent);
            }
        }
    } THEN {
        EXPECT_EQ(opponent->hp, suppress ? 0 : 100);
    }
}

SINGLE_BATTLE_TEST("Damp prevents Explosion-like moves from enemies")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EXPLOSION; }
    PARAMETRIZE { move = MOVE_SELF_DESTRUCT; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; }
    PARAMETRIZE { move = MOVE_MISTY_EXPLOSION; }
    GIVEN {
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DAMP);
        NONE_OF { HP_BAR(player); HP_BAR(opponent); }
    }
}

DOUBLE_BATTLE_TEST("Damp prevents Explosion-like moves from enemies in a double battle")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EXPLOSION; }
    PARAMETRIZE { move = MOVE_SELF_DESTRUCT; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; }
    PARAMETRIZE { move = MOVE_MISTY_EXPLOSION; }
    GIVEN {
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, move); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_DAMP);
        NONE_OF { HP_BAR(playerLeft); HP_BAR(opponentLeft); HP_BAR(playerRight); HP_BAR(opponentRight); }
    }
}

SINGLE_BATTLE_TEST("Damp prevents Explosion-like moves from self")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EXPLOSION; }
    PARAMETRIZE { move = MOVE_SELF_DESTRUCT; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; }
    PARAMETRIZE { move = MOVE_MISTY_EXPLOSION; }
    GIVEN {
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DAMP);
        NONE_OF { HP_BAR(player); HP_BAR(opponent); }
    }
}

SINGLE_BATTLE_TEST("Damp prevents damage from Aftermath")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_PARAS) { Ability(ABILITY_DAMP); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_AFTERMATH); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_AFTERMATH);
        ABILITY_POPUP(player, ABILITY_DAMP);
        NONE_OF { HP_BAR(player); }
    }
}

//TO_DO_BATTLE_TEST("Damp affects non-adjacent Pokémon (triples)")
