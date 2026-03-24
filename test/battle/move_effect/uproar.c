#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_UPROAR, MOVE_EFFECT_UPROAR));
}

DOUBLE_BATTLE_TEST("Uproar status causes sleeping Pokémon to wake up before they move except those with Soundproof (Gen 3-4)")
{
    GIVEN {
        WITH_CONFIG(B_UPROAR, GEN_4);
        WITH_CONFIG(B_UPROAR_IGNORE_SOUNDPROOF, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_UPROAR, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("The uproar woke Wobbuffet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        NONE_OF {
            MESSAGE("The uproar woke the opposing Voltorb!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        }
        MESSAGE("The uproar woke the opposing Wobbuffet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Uproar status causes sleeping Pokémon to wake up immediately after damage is dealt on the first turn (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_UPROAR, GEN_5);
        WITH_CONFIG(B_UPROAR_IGNORE_SOUNDPROOF, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_UPROAR, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("The opposing Voltorb woke up!");
        MESSAGE("Wobbuffet woke up!");
        MESSAGE("The opposing Wobbuffet woke up!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

SINGLE_BATTLE_TEST("Uproar wakes up other pokemon on field (Gen 5)")
{
    GIVEN {
        ASSUME(B_UPROAR_TURNS >= GEN_5);
        WITH_CONFIG(B_UPROAR, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_UPROAR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, opponent);
        MESSAGE("Wobbuffet woke up!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
