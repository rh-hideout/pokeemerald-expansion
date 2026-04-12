#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mental Herb cures infatuation")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MENTAL_HERB].holdEffect == HOLD_EFFECT_MENTAL_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); Gender(MON_MALE); }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ATTRACT); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Attract!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ATTRACT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet cured its infatuation status using its Mental Herb!");
    } THEN {
        EXPECT(player->volatiles.infatuation == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Torment volatile status (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(gItemsInfo[ITEM_MENTAL_HERB].holdEffect == HOLD_EFFECT_MENTAL_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TORMENT); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Torment!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is no longer tormented!");
    } THEN {
        EXPECT(player->volatiles.tormentTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Disable volatile status (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(gItemsInfo[ITEM_MENTAL_HERB].holdEffect == HOLD_EFFECT_MENTAL_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_DISABLE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Disable!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, opponent);
        MESSAGE("Wobbuffet's move is no longer disabled!");
    } THEN {
        EXPECT(player->volatiles.disableTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Heal Block volatile status (Gen 5+)")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_HEAL_BLOCK; }
    PARAMETRIZE { move = MOVE_PSYCHIC_NOISE; }

    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(gItemsInfo[ITEM_MENTAL_HERB].holdEffect == HOLD_EFFECT_MENTAL_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        if (move == MOVE_HEAL_BLOCK)
            MESSAGE("The opposing Wobbuffet used Heal Block!");
        else
            MESSAGE("The opposing Wobbuffet used Psychic Noise!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        MESSAGE("Wobbuffet was prevented from healing!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is no longer prevented from healing!");
    } THEN {
        EXPECT(player->volatiles.healBlock == FALSE);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Encore volatile status (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(gItemsInfo[ITEM_MENTAL_HERB].holdEffect == HOLD_EFFECT_MENTAL_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENCORE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Encore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        MESSAGE("Wobbuffet must do an encore!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet ended its encore!");
    } THEN {
        EXPECT(player->volatiles.encoreTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Taunt volatile status (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(gItemsInfo[ITEM_MENTAL_HERB].holdEffect == HOLD_EFFECT_MENTAL_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAUNT); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Taunt!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponent);
        MESSAGE("Wobbuffet fell for the taunt!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet shook off the taunt!");
    } THEN {
        EXPECT(player->volatiles.encoreTimer == 0);
    }
}

DOUBLE_BATTLE_TEST("Mental Herb cures volatile statuses in the following order - Infatuation, Torment, Disable, Heal Block, Encore, Taunt")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(gItemsInfo[ITEM_MENTAL_HERB].holdEffect == HOLD_EFFECT_MENTAL_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_MALE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_MENTAL_HERB); };
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE);
               MOVE(opponentLeft, MOVE_HEAL_BLOCK, target: playerLeft);
               MOVE(playerRight, MOVE_DISABLE, target: playerLeft);
               MOVE(opponentRight, MOVE_TORMENT, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_SPLASH);
               MOVE(opponentLeft, MOVE_CELEBRATE);
               MOVE(playerRight, MOVE_CELEBRATE);
               MOVE(opponentRight, MOVE_TAUNT, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_POUND, target: opponentRight);
               MOVE(opponentLeft, MOVE_ATTRACT, target: playerLeft);
               MOVE(playerRight, MOVE_ENCORE, target: playerLeft);
               MOVE(opponentRight, MOVE_TRICK, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet cured its infatuation status using its Mental Herb!");
        MESSAGE("Wobbuffet is no longer tormented!");
        MESSAGE("Wobbuffet's move is no longer disabled!");
        MESSAGE("Wobbuffet is no longer prevented from healing!");
        MESSAGE("Wobbuffet ended its encore!");
        MESSAGE("Wobbuffet shook off the taunt!");
    }
}
