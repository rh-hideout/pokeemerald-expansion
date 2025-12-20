#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Big Pecks prevents Defense stage reduction from moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LEER) == EFFECT_DEFENSE_DOWN);
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEER); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
        MESSAGE("The opposing Wobbuffet's Big Pecks prevents Defense loss!");
    }
}

SINGLE_BATTLE_TEST("Big Pecks is ignored by Mold Breaker")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LEER) == EFFECT_DEFENSE_DOWN);
        PLAYER(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEER); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MOLD_BREAKER);
        MESSAGE("Wobbuffet breaks the mold!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, player);
        MESSAGE("The opposing Wobbuffet's Defense fell!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
            MESSAGE("The opposing Wobbuffet's Big Pecks prevents Defense loss!");
        }
    }
}

SINGLE_BATTLE_TEST("Big Pecks doesn't prevent Defense stage reduction from moves used by the user")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_SUPERPOWER, MOVE_EFFECT_ATK_DEF_DOWN) == TRUE);
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPERPOWER); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPERPOWER, opponent);
        MESSAGE("The opposing Wobbuffet's Attack fell!");
        MESSAGE("The opposing Wobbuffet's Defense fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Big Pecks doesn't prevent Topsy-Turvy")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HARDEN) == EFFECT_DEFENSE_UP);
        ASSUME(GetMoveEffect(MOVE_TOPSY_TURVY) == EFFECT_TOPSY_TURVY);
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HARDEN); MOVE(player, MOVE_TOPSY_TURVY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, opponent);
        MESSAGE("The opposing Wobbuffet's Defense rose!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOPSY_TURVY, player);
        MESSAGE("All stat changes on the opposing Wobbuffet were inverted!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Big Pecks doesn't prevent Spectral Thief from resetting positive Defense stage changes")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HARDEN) == EFFECT_DEFENSE_UP);
        ASSUME(GetMoveEffect(MOVE_SPECTRAL_THIEF) == EFFECT_SPECTRAL_THIEF);
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player,MOVE_SOAK); }
        TURN { MOVE(opponent, MOVE_HARDEN); MOVE(player, MOVE_SPECTRAL_THIEF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, opponent);
        MESSAGE("The opposing Wobbuffet's Defense rose!");
        MESSAGE("Wobbuffet stole the target's boosted stats!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPECTRAL_THIEF, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Big Pecks doesn't prevent receiving negative Defense stage changes from Baton Pass")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LEER) == EFFECT_DEFENSE_DOWN);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET);
        OPPONENT(TEST_SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEER);
               MOVE(opponent, MOVE_BATON_PASS);
               SEND_OUT(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        MESSAGE("2 sent out Wobbuffet!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}
