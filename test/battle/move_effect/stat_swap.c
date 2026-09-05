#include "global.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "fpmath.h"
#include "move.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Power Swap switches the user's Attack and Sp. Atk stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{

    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_COVET; }
    PARAMETRIZE { attackMove =  MOVE_SWIFT; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_COVET) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_IRON_BALL);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {

        boostMove = GetMoveCategory(attackMove) == DAMAGE_CATEGORY_PHYSICAL
                      ? MOVE_SWORDS_DANCE
                      : MOVE_NASTY_PLOT;

        TURN { MOVE(player, MOVE_POWER_SWAP); MOVE(opponent, boostMove);}
        TURN { MOVE(player, attackMove); MOVE(opponent, attackMove);};
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_SWAP, player);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgOpponent, Q_4_12(2), results[0].dmgPlayer);
        EXPECT_MUL_EQ(results[1].dmgOpponent, Q_4_12(2), results[1].dmgPlayer);
    }
}

SINGLE_BATTLE_TEST("Guard Swap switches the user's Defense and Sp. Def stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_COVET; }
    PARAMETRIZE { attackMove =  MOVE_SWIFT; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_COVET) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_IRON_BALL);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {

        boostMove = GetMoveCategory(attackMove) == DAMAGE_CATEGORY_PHYSICAL
                      ? MOVE_IRON_DEFENSE
                      : MOVE_AMNESIA;

        TURN { MOVE(player, MOVE_GUARD_SWAP); MOVE(opponent, boostMove);}
        TURN { MOVE(player, attackMove); MOVE(opponent, attackMove);};
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SWAP, player);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgOpponent, Q_4_12(2), results[0].dmgPlayer);
        EXPECT_MUL_EQ(results[1].dmgOpponent, Q_4_12(2), results[1].dmgPlayer);
    }
}

SINGLE_BATTLE_TEST("Heart Swap switches the user's stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_COVET; }
    PARAMETRIZE { attackMove =  MOVE_SWIFT; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_COVET) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_IRON_BALL);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {

        boostMove = GetMoveCategory(attackMove) == DAMAGE_CATEGORY_PHYSICAL
                      ? MOVE_IRON_DEFENSE
                      : MOVE_AMNESIA;

        TURN { MOVE(player, MOVE_GUARD_SWAP); MOVE(opponent, boostMove);}
        TURN { MOVE(player, attackMove); MOVE(opponent, attackMove);};
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SWAP, player);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgOpponent, Q_4_12(2), results[0].dmgPlayer);
        EXPECT_MUL_EQ(results[1].dmgOpponent, Q_4_12(2), results[1].dmgPlayer);
    }
}

SINGLE_BATTLE_TEST("Heart Swap switches the user's Attack and Sp. Atk stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_COVET; }
    PARAMETRIZE { attackMove = MOVE_SWIFT; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_COVET) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_IRON_BALL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {

        boostMove = GetMoveCategory(attackMove) == DAMAGE_CATEGORY_PHYSICAL
                      ? MOVE_SWORDS_DANCE
                      : MOVE_NASTY_PLOT;

        TURN { MOVE(player, MOVE_HEART_SWAP); MOVE(opponent, boostMove); }
        TURN { MOVE(player, attackMove); MOVE(opponent, attackMove); };
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEART_SWAP, player);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgOpponent, Q_4_12(2), results[0].dmgPlayer);
        EXPECT_MUL_EQ(results[1].dmgOpponent, Q_4_12(2), results[1].dmgPlayer);
    }
}

SINGLE_BATTLE_TEST("Heart Swap switches the user's Defense and Sp. Def stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_COVET; }
    PARAMETRIZE { attackMove = MOVE_SWIFT; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_COVET) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_IRON_BALL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {

        boostMove = GetMoveCategory(attackMove) == DAMAGE_CATEGORY_PHYSICAL
                      ? MOVE_IRON_DEFENSE
                      : MOVE_AMNESIA;

        TURN { MOVE(player, MOVE_HEART_SWAP); MOVE(opponent, boostMove); }
        TURN { MOVE(player, attackMove); MOVE(opponent, attackMove); };
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEART_SWAP, player);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgOpponent, Q_4_12(2), results[0].dmgPlayer);
        EXPECT_MUL_EQ(results[1].dmgOpponent, Q_4_12(2), results[1].dmgPlayer);
    }
}

SINGLE_BATTLE_TEST("Heart Swap swaps user and target's speed stats")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    }WHEN {
        TURN { MOVE(opponent, MOVE_AGILITY); MOVE(player, MOVE_SPEED_SWAP); }
    } SCENE {
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}
