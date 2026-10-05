#include "global.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "fpmath.h"
#include "move.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Power Swap switches the user's Attack and Sp. Atk stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_POUND; boostMove = MOVE_SWORDS_DANCE; }
    PARAMETRIZE { attackMove =  MOVE_SWIFT; boostMove = MOVE_NASTY_PLOT; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_POUND) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME_STAT_CHANGE(MOVE_NASTY_PLOT, spAtk: +2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, boostMove); MOVE(player, MOVE_POWER_SWAP); }
        TURN { MOVE(opponent, attackMove); MOVE(player, attackMove); };
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, boostMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_SWAP, player);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, opponent);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, player);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgPlayer, Q_4_12(2), results[0].dmgOpponent);
        EXPECT_MUL_EQ(results[1].dmgPlayer, Q_4_12(2), results[1].dmgOpponent);
    }
}

SINGLE_BATTLE_TEST("Power Swap switches only the user's Attack and Sp. Atk stat stages with the target")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_ANCIENT_POWER, self: TRUE, attack: +1, defense: +1, spAtk: +1, spDef: +1, speed: +1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ANCIENT_POWER); MOVE(player, MOVE_POWER_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ANCIENT_POWER, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_SWAP, player);
    } THEN {
        for (enum Stat stat = STAT_ATK; stat < NUM_STATS; stat++) {
            if (stat == STAT_ATK || stat == STAT_SPATK) {
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE + 1);
                EXPECT_EQ(opponent->statStages[stat], DEFAULT_STAT_STAGE);
            } else {
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE);
                EXPECT_EQ(opponent->statStages[stat], DEFAULT_STAT_STAGE + 1);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Guard Swap switches the user's Defense and Sp. Def stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_COVET; boostMove = MOVE_IRON_DEFENSE; }
    PARAMETRIZE { attackMove =  MOVE_SWIFT; boostMove = MOVE_AMNESIA; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_POUND) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE , defense: +2);
        ASSUME_STAT_CHANGE(MOVE_AMNESIA, spDef: +2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, boostMove); MOVE(player, MOVE_GUARD_SWAP); }
        TURN { MOVE(opponent, attackMove); MOVE(player, attackMove); };
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, boostMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SWAP, player);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, opponent);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, player);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgPlayer, Q_4_12(2), results[0].dmgOpponent);
        EXPECT_MUL_EQ(results[1].dmgPlayer, Q_4_12(2), results[1].dmgOpponent);
    }
}

SINGLE_BATTLE_TEST("Guard Swap switches only the user's Defense and Sp. Def stat stages with the target")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_ANCIENT_POWER, self: TRUE, attack: +1, defense: +1, spAtk: +1, spDef: +1, speed: +1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ANCIENT_POWER); MOVE(player, MOVE_GUARD_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ANCIENT_POWER, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SWAP, player);
    } THEN {
        for (enum Stat stat = STAT_ATK; stat < NUM_STATS; stat++) {
            if (stat == STAT_DEF || stat == STAT_SPDEF) {
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE + 1);
                EXPECT_EQ(opponent->statStages[stat], DEFAULT_STAT_STAGE);
            } else {
                EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE);
                EXPECT_EQ(opponent->statStages[stat], DEFAULT_STAT_STAGE + 1);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Heart Swap switches the user's stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_POUND; boostMove = MOVE_IRON_DEFENSE; }
    PARAMETRIZE { attackMove =  MOVE_SWIFT; boostMove = MOVE_AMNESIA; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_POUND) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
        ASSUME_STAT_CHANGE(MOVE_AMNESIA, spDef: +2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, boostMove); MOVE(player, MOVE_HEART_SWAP); }
        TURN { MOVE(opponent, attackMove); MOVE(player, attackMove); };
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, boostMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEART_SWAP, player);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, opponent);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, player);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgPlayer, Q_4_12(2), results[0].dmgOpponent);
        EXPECT_MUL_EQ(results[1].dmgPlayer, Q_4_12(2), results[1].dmgOpponent);
    }
}

SINGLE_BATTLE_TEST("Heart Swap switches the user's Attack and Sp. Atk stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_POUND; boostMove = MOVE_SWORDS_DANCE; }
    PARAMETRIZE { attackMove = MOVE_SWIFT; boostMove = MOVE_NASTY_PLOT; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_POUND) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME_STAT_CHANGE(MOVE_NASTY_PLOT, spAtk: +2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, boostMove); MOVE(player, MOVE_HEART_SWAP); }
        TURN { MOVE(opponent, attackMove); MOVE(player, attackMove); };
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, boostMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEART_SWAP, player);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, opponent);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, player);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgPlayer, Q_4_12(2), results[0].dmgOpponent);
        EXPECT_MUL_EQ(results[1].dmgPlayer, Q_4_12(2), results[1].dmgOpponent);
    }
}

SINGLE_BATTLE_TEST("Heart Swap switches the user's Defense and Sp. Def stat stages with the target", s16 dmgPlayer, s16 dmgOpponent)
{
    enum Move boostMove, attackMove;

    PARAMETRIZE { attackMove = MOVE_POUND; boostMove = MOVE_IRON_DEFENSE; }
    PARAMETRIZE { attackMove = MOVE_SWIFT; boostMove = MOVE_AMNESIA; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_POUND) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, boostMove); MOVE(player, MOVE_HEART_SWAP); }
        TURN { MOVE(opponent, attackMove); MOVE(player, attackMove); };
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, boostMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEART_SWAP, player);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, opponent);
        HP_BAR(player, captureDamage: &results[i].dmgPlayer);

        ANIMATION(ANIM_TYPE_MOVE, attackMove, player);
        HP_BAR(opponent, captureDamage: &results[i].dmgOpponent);
    } THEN {
        EXPECT_MUL_EQ(results[0].dmgPlayer, Q_4_12(2), results[0].dmgOpponent);
        EXPECT_MUL_EQ(results[1].dmgPlayer, Q_4_12(2), results[1].dmgOpponent);
    }
}

SINGLE_BATTLE_TEST("Heart Swap switches all user's stat stages with the target")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_ANCIENT_POWER, self: TRUE, attack: +1, defense: +1, spAtk: +1, spDef: +1, speed: +1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ANCIENT_POWER); MOVE(player, MOVE_HEART_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ANCIENT_POWER, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEART_SWAP, player);
    } THEN {
        for (enum Stat stat = STAT_ATK; stat < NUM_STATS; stat++) {
            EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE + 1);
            EXPECT_EQ(opponent->statStages[stat], DEFAULT_STAT_STAGE);
        }
    }
}
SINGLE_BATTLE_TEST("Speed Swap swaps user and target's speed stats but not stat boosts")
{
    u32 playerSpeed;
    u32 opponentSpeed;

    PARAMETRIZE { playerSpeed = 2; opponentSpeed = 3; }
    PARAMETRIZE { playerSpeed = 10; opponentSpeed = 30; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(playerSpeed); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(opponentSpeed); };
        ASSUME_STAT_CHANGE(MOVE_AGILITY, speed: +2);
    }WHEN {
        TURN { MOVE(opponent, MOVE_AGILITY); MOVE(player, MOVE_SPEED_SWAP); }
        if (playerSpeed == 2) {
            TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
        } else {
            TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPEED_SWAP, player);

        // Turn 2
        if (playerSpeed == 2) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}
