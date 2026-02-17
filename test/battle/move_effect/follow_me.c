#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FOLLOW_ME) == EFFECT_FOLLOW_ME);
    ASSUME(GetMoveEffect(MOVE_SPOTLIGHT) == EFFECT_FOLLOW_ME);
}

DOUBLE_BATTLE_TEST("Follow Me redirects single target moves used by opponents to user")
{
    struct BattlePokemon *moveUser = NULL;
    struct BattlePokemon *partner = NULL;
    PARAMETRIZE { moveUser = opponentLeft; partner = opponentRight; }
    PARAMETRIZE { moveUser = opponentRight; partner = opponentLeft; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: moveUser);
               MOVE(playerRight, MOVE_SCRATCH, target: partner);
               MOVE(moveUser, MOVE_FOLLOW_ME);
               MOVE(partner, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, moveUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(moveUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(moveUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, partner);
        HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Spotlight redirects single target moves used by the opposing side to Spotlight's target")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerRight; }
    PARAMETRIZE { moveTarget = opponentLeft; }
    PARAMETRIZE { moveTarget = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPOTLIGHT, target: moveTarget);
               MOVE(playerRight, MOVE_SCRATCH, target: opponentRight);
               MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
               MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPOTLIGHT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        if (moveTarget != playerRight)
            HP_BAR(moveTarget);
        else
            HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        if (moveTarget == playerRight)
            HP_BAR(moveTarget);
        else
            HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        if (moveTarget == playerRight)
            HP_BAR(moveTarget);
        else
            HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Follow Me redirects random target moves used by opponents to user")
{
    PASSES_RANDOMLY(2, 2, RNG_RANDOM_TARGET);
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_OUTRAGE) == MOVE_TARGET_RANDOM);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FOLLOW_ME);
               MOVE(opponentLeft, MOVE_OUTRAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OUTRAGE, opponentLeft);
        HP_BAR(playerRight);
        NOT HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Follow Me does not change Me First's copy target but redirects the copied move")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_ME_FIRST) == MOVE_TARGET_OPPONENT);
        ASSUME(GetMoveEffect(MOVE_ME_FIRST) == EFFECT_ME_FIRST);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WYNAUT) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WYNAUT) { Speed(120); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FOLLOW_ME);
               MOVE(playerLeft, MOVE_ME_FIRST, target: opponentLeft);
               MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ME_FIRST, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
        HP_BAR(opponentRight);
        NOT HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Follow Me doesn't redirect moves that can't target opponents")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_AROMATIC_MIST) == MOVE_TARGET_ALLY);
        ASSUME(GetMoveEffect(MOVE_AROMATIC_MIST) == EFFECT_AROMATIC_MIST);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FOLLOW_ME);
               MOVE(opponentLeft, MOVE_AROMATIC_MIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AROMATIC_MIST, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Follow Me no longer redirects if the center of attention faints mid-turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        PLAYER(SPECIES_WYNAUT) { HP(1); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(60); }
        OPPONENT(SPECIES_WYNAUT) { Speed(40); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FOLLOW_ME);
               MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft);
               MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        HP_BAR(playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Follow Me can only redirect charging moves on the turn that they would hit")
{
    bool32 useFollowMeTurn2;
    PARAMETRIZE { useFollowMeTurn2 = FALSE; }
    PARAMETRIZE { useFollowMeTurn2 = TRUE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH); }
        PLAYER(SPECIES_WYNAUT) { Moves(MOVE_FOLLOW_ME, MOVE_SPLASH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_FLY); }
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_SPLASH); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FOLLOW_ME);
               MOVE(opponentLeft, MOVE_FLY, target: playerLeft);
               MOVE(playerLeft, MOVE_SPLASH);
               MOVE(opponentRight, MOVE_SPLASH); }
        TURN { if (useFollowMeTurn2)
                   MOVE(playerRight, MOVE_FOLLOW_ME);
               else
                   MOVE(playerRight, MOVE_SPLASH);
               SKIP_TURN(opponentLeft);
               MOVE(playerLeft, MOVE_SPLASH);
               MOVE(opponentRight, MOVE_SPLASH); }
    } SCENE {
        if (useFollowMeTurn2)
            HP_BAR(playerRight);
        else
            HP_BAR(playerLeft);
        if (useFollowMeTurn2)
            NOT HP_BAR(playerLeft);
        else
            NOT HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Follow Me does not redirect Future Sight (Gen 6+)")
{
    GIVEN {
        WITH_CONFIG(B_FOLLOW_ME_FUTURE_SIGHT, GEN_6);
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FOLLOW_ME);
               MOVE(playerLeft, MOVE_FUTURE_SIGHT, target: opponentLeft); }
        TURN { }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, playerLeft);
        MESSAGE("The opposing Wobbuffet took the Future Sight attack!");
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Follow Me can only redirect Future Sight on the turn they were selected (Gen3-5)")
{
    GIVEN {
        WITH_CONFIG(B_FOLLOW_ME_FUTURE_SIGHT, GEN_5);
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FOLLOW_ME);
               MOVE(playerLeft, MOVE_FUTURE_SIGHT, target: opponentLeft); }
        TURN { }
        TURN { MOVE(opponentLeft, MOVE_FOLLOW_ME); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentLeft);
        MESSAGE("The opposing Wynaut took the Future Sight attack!");
        HP_BAR(opponentRight);
        NOT HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Follow Me draws single-target Electric/Water moves even if there's a Pokémon with Lightning Rod/Storm Drain")
{
    u16 move, species;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_THUNDERBOLT; ability = ABILITY_LIGHTNING_ROD; species = SPECIES_PIKACHU; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_STORM_DRAIN; species = SPECIES_GASTRODON; }

    GIVEN {
        ASSUME(GetMoveTarget(move) == MOVE_TARGET_SELECTED);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FOLLOW_ME);
               MOVE(opponentLeft, move, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
        HP_BAR(playerLeft);
        NONE_OF {
            HP_BAR(playerRight);
            ABILITY_POPUP(opponentRight, ability);
        }
    }
}

DOUBLE_BATTLE_TEST("Follow Me doesn't redirect spread Electric/Water moves even with Lightning Rod/Storm Drain")
{
    u16 move, species;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_OVERDRIVE; ability = ABILITY_LIGHTNING_ROD; species = SPECIES_PIKACHU; }
    PARAMETRIZE { move = MOVE_ORIGIN_PULSE; ability = ABILITY_STORM_DRAIN; species = SPECIES_GASTRODON; }

    GIVEN {
        ASSUME(GetMoveTarget(move) == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FOLLOW_ME);
               MOVE(opponentLeft, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerLeft);
        HP_BAR(playerLeft);
        ABILITY_POPUP(playerRight, ability);
    }
}

DOUBLE_BATTLE_TEST("Follow Me prioritizes the first Pokémon that used it") // There can be 2 centers of attention. If the first is gone, the 2nd is used
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FOLLOW_ME);
               MOVE(opponentRight, MOVE_FOLLOW_ME);
               MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);
    }
}


SINGLE_BATTLE_TEST("Follow Me fails in Single Battles (BDSP+)")
{
    GIVEN {
        WITH_CONFIG(B_FOLLOW_ME_SINGLES_FAIL, TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOLLOW_ME); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Follow Me can be used in Single Battles (Gen3-SwSh)")
{
    GIVEN {
        WITH_CONFIG(B_FOLLOW_ME_SINGLES_FAIL, FALSE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOLLOW_ME); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, player);
        NOT MESSAGE("But it failed!");
    }
}

DOUBLE_BATTLE_TEST("Follow Me cannot redirect Sky Drop")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKY_DROP) == EFFECT_SKY_DROP);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FOLLOW_ME);
               MOVE(opponentLeft, MOVE_SKY_DROP, target: playerLeft); }
        TURN { SKIP_TURN(opponentLeft); SKIP_TURN(playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        MESSAGE("The opposing Wobbuffet took Wynaut into the sky!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Follow Me does not draw attack when the user is being Sky-Dropped")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKY_DROP) == EFFECT_SKY_DROP);
        PLAYER(SPECIES_WOBBUFFET) { Speed(60); }
        PLAYER(SPECIES_WYNAUT) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(90); }
        OPPONENT(SPECIES_WYNAUT) { Speed(80); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FOLLOW_ME);
               MOVE(opponentLeft, MOVE_SKY_DROP, target: playerRight);
               MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
               MOVE(playerLeft, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, playerLeft);
    }
}

//TO_DO_BATTLE_TEST("Triples: Follow Me can only draw non-adjacent moves if they use a long-range move")
