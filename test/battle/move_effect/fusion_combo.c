#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FUSION_FLARE) == EFFECT_FUSION_COMBO);
    ASSUME(GetMoveEffect(MOVE_FUSION_BOLT) == EFFECT_FUSION_COMBO);
}

DOUBLE_BATTLE_TEST("Fusion Flare and Fusion Bolt double in power if the other move was used immediately before in the same turn", s16 damage)
{
    enum Move firstMove;
    enum Move secondMove;
    PARAMETRIZE { firstMove = MOVE_CELEBRATE;    secondMove = MOVE_FUSION_BOLT; }
    PARAMETRIZE { firstMove = MOVE_FUSION_FLARE; secondMove = MOVE_FUSION_BOLT; }
    PARAMETRIZE { firstMove = MOVE_CELEBRATE;    secondMove = MOVE_FUSION_FLARE; }
    PARAMETRIZE { firstMove = MOVE_FUSION_BOLT;  secondMove = MOVE_FUSION_FLARE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(90); Attack(100); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); SpDefense(100); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN {
            MOVE(playerLeft, firstMove, target: opponentLeft);
            MOVE(playerRight, secondMove, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, secondMove, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(2.0), results[3].damage);
    }
}

DOUBLE_BATTLE_TEST("Fusion Flare and Fusion Bolt do not double in power if another move was used between them", s16 damage)
{
    enum Move firstMove;
    enum Move secondMove;
    PARAMETRIZE { firstMove = MOVE_CELEBRATE;    secondMove = MOVE_FUSION_BOLT; }
    PARAMETRIZE { firstMove = MOVE_FUSION_FLARE; secondMove = MOVE_FUSION_BOLT; }
    PARAMETRIZE { firstMove = MOVE_CELEBRATE;    secondMove = MOVE_FUSION_FLARE; }
    PARAMETRIZE { firstMove = MOVE_FUSION_BOLT;  secondMove = MOVE_FUSION_FLARE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); Attack(100); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); SpDefense(100); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(90); }
    } WHEN {
        TURN {
            MOVE(playerLeft, firstMove, target: opponentLeft);
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerRight, secondMove, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, secondMove, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
    }
}

DOUBLE_BATTLE_TEST("Fusion Flare and Fusion Bolt double in power if the same Pokémon uses both in one turn through Instruct", s16 damage)
{
    bool32 useInstruct;
    enum Move firstMove;
    enum Move secondMove;
    PARAMETRIZE { useInstruct = FALSE; firstMove = MOVE_FUSION_FLARE; secondMove = MOVE_FUSION_BOLT; }
    PARAMETRIZE { useInstruct = TRUE;  firstMove = MOVE_FUSION_FLARE; secondMove = MOVE_FUSION_BOLT; }
    PARAMETRIZE { useInstruct = FALSE; firstMove = MOVE_FUSION_BOLT;  secondMove = MOVE_FUSION_FLARE; }
    PARAMETRIZE { useInstruct = TRUE;  firstMove = MOVE_FUSION_BOLT;  secondMove = MOVE_FUSION_FLARE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); SpAttack(100); Speed(50); }
        PLAYER(SPECIES_ORANGURU) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); SpDefense(100); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(playerLeft, firstMove, target: opponentLeft); }
        TURN {
            if (useInstruct)
                MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft);
            else
                MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(playerLeft, secondMove, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, secondMove, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(2.0), results[3].damage);
    }
}
