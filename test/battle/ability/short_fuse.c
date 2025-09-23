#include "global.h"
#include "test/battle.h"

#define SHORT_FUSE_STAT_RAISE(target, msg)                         \
{                                                               \
    ABILITY_POPUP(target, ABILITY_SHORT_FUSE);                     \
    ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, target);  \
    MESSAGE(msg);                                               \
}

#define SHORT_FUSE_HIT(attacker, target, move, msg, dmgVar)        \
{                                                               \
    ANIMATION(ANIM_TYPE_MOVE, move, attacker);                  \
    HP_BAR(target, captureDamage: &dmgVar);                     \
    SHORT_FUSE_STAT_RAISE(target, msg);                            \
}

SINGLE_BATTLE_TEST("Short Fuse raises Attack by 1 when hit by a move")
{
    s16 turnOneHit, turnTwoHit;
    u16 move;

    PARAMETRIZE {move = MOVE_TACKLE; }
    PARAMETRIZE {move = MOVE_GUST; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].power != 0);
        ASSUME(gMovesInfo[MOVE_GUST].power != 0);
        ASSUME(gMovesInfo[MOVE_GUST].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHORT_FUSE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, move); }
    } SCENE {
        SHORT_FUSE_HIT(opponent, player, move, "Wobbuffet's Attack rose!", turnOneHit);
        SHORT_FUSE_HIT(opponent, player, move, "Wobbuffet's Attack rose!", turnTwoHit);
    }
    THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Short Fuse activates correctly for every battler with the ability when hit by a multi target move")
{
    u16 abilityLeft, abilityRight;

    PARAMETRIZE {abilityLeft = ABILITY_NONE, abilityRight = ABILITY_SHORT_FUSE; }
    PARAMETRIZE {abilityLeft = ABILITY_SHORT_FUSE, abilityRight = ABILITY_NONE; }
    PARAMETRIZE {abilityLeft = ABILITY_SHORT_FUSE, abilityRight = ABILITY_SHORT_FUSE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_EARTHQUAKE].target == MOVE_TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET) { Ability(abilityLeft); Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(abilityRight); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(15); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);

        HP_BAR(playerLeft);
        if (abilityLeft == ABILITY_SHORT_FUSE) {
            SHORT_FUSE_STAT_RAISE(playerLeft, "Wobbuffet's Attack rose!");
        }
        NOT HP_BAR(opponentLeft); // We need to check the attacker itself does NOT get damaged. There was an issue when the targets would get overwritten by the Stamina's stat raise.

        HP_BAR(playerRight);
        if (abilityRight == ABILITY_SHORT_FUSE) {
            SHORT_FUSE_STAT_RAISE(playerRight, "Wobbuffet's Attack rose!");
        }
        NOT HP_BAR(opponentLeft); // We need to check the attacker itself does NOT get damaged. There was an issue when the targets would get overwritten by the Stamina's stat raise.

        HP_BAR(opponentRight);
    }
    THEN {
        EXPECT_NE(playerLeft->hp, playerLeft->maxHP);
        EXPECT_NE(playerRight->hp, playerRight->maxHP);
        EXPECT_NE(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
    }
}

SINGLE_BATTLE_TEST("Short Fuse activates for every hit of a multi hit move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MUDBRAY) { Ability(ABILITY_SHORT_FUSE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, player);
        HP_BAR(opponent);
        SHORT_FUSE_STAT_RAISE(opponent, "Foe Mudbray's Attack rose!");
        SHORT_FUSE_STAT_RAISE(opponent, "Foe Mudbray's Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Short Fuse is not activated by users own Substitute")
{
    GIVEN {
        PLAYER(SPECIES_MUDBRAY) { Ability(ABILITY_SHORT_FUSE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Mudbray made a SUBSTITUTE!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SHORT_FUSE);
            MESSAGE("Mudbray's Attack rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
