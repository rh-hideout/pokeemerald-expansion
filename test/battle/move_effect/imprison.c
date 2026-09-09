#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_IMPRISON) == EFFECT_IMPRISON);
}

SINGLE_BATTLE_TEST("Imprison fails before Gen 5 if the user shares no moves with the foe")
{
    GIVEN {
        WITH_CONFIG(B_IMPRISON, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_IMPRISON, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_POUND); }
    } WHEN {
        TURN { MOVE(player, MOVE_IMPRISON); MOVE(opponent, MOVE_POUND); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_IMPRISON, player);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(!player->volatiles.imprison);
    }
}

SINGLE_BATTLE_TEST("Imprison succeeds before Gen 5 if the user shares a move with the foe")
{
    GIVEN {
        WITH_CONFIG(B_IMPRISON, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_IMPRISON, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_CELEBRATE, MOVE_POUND); }
    } WHEN {
        TURN { MOVE(player, MOVE_IMPRISON); MOVE(opponent, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_IMPRISON, player);
        MESSAGE("Wobbuffet sealed any moves its target shares with it!");
    } THEN {
        EXPECT(player->volatiles.imprison);
    }
}

SINGLE_BATTLE_TEST("Imprison succeeds without a shared move from Gen 5 onward and then fails while active")
{
    GIVEN {
        WITH_CONFIG(B_IMPRISON, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_IMPRISON, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_POUND); }
    } WHEN {
        TURN { MOVE(player, MOVE_IMPRISON); MOVE(opponent, MOVE_POUND); }
        TURN { MOVE(player, MOVE_IMPRISON); MOVE(opponent, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_IMPRISON, player);
        MESSAGE("Wobbuffet sealed any moves its target shares with it!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_IMPRISON, player);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->volatiles.imprison);
    }
}

SINGLE_BATTLE_TEST("Baton Pass doesn't pass Imprison's effect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_IMPRISON, MOVE_BATON_PASS); }
        PLAYER(SPECIES_WYNAUT) { Speed(75); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_POUND); }
    } WHEN {
        TURN { MOVE(player, MOVE_IMPRISON); MOVE(opponent, MOVE_POUND); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); MOVE(opponent, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_IMPRISON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT(!player->volatiles.imprison);
    }
}
