#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Strong Jaw boosts biting moves by 50%", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_BITE; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_BITE; ability = ABILITY_STRONG_JAW; }
    PARAMETRIZE { move = MOVE_CRUNCH; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_CRUNCH; ability = ABILITY_STRONG_JAW; }
    PARAMETRIZE { move = MOVE_FIRE_FANG; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_FIRE_FANG; ability = ABILITY_STRONG_JAW; }
    PARAMETRIZE { move = MOVE_ICE_FANG; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_ICE_FANG; ability = ABILITY_STRONG_JAW; }
    PARAMETRIZE { move = MOVE_THUNDER_FANG; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_THUNDER_FANG; ability = ABILITY_STRONG_JAW; }
    PARAMETRIZE { move = MOVE_POISON_FANG; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_POISON_FANG; ability = ABILITY_STRONG_JAW; }
    PARAMETRIZE { move = MOVE_PSYCHIC_FANGS; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_PSYCHIC_FANGS; ability = ABILITY_STRONG_JAW; }
    PARAMETRIZE { move = MOVE_JAW_LOCK; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_JAW_LOCK; ability = ABILITY_STRONG_JAW; }
    GIVEN {
        ASSUME(IsBitingMove(move));
        PLAYER(SPECIES_TYRUNT) { Ability(ability); Attack(200); Speed(100); Item(ITEM_NONE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 16; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.5), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Strong Jaw does not boost Bug Bite", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_BUG_BITE; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_BUG_BITE; ability = ABILITY_STRONG_JAW; }
    GIVEN {
        ASSUME(!IsBitingMove(move));
        PLAYER(SPECIES_TYRUNT) { Ability(ability); Attack(200); Speed(100); Item(ITEM_NONE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Strong Jaw does not boost ordinary physical or special moves", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_STRONG_JAW; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_STRONG_JAW; }
    GIVEN {
        ASSUME(!IsBitingMove(move));
        PLAYER(SPECIES_TYRUNT) { Ability(ability); Attack(200); Speed(100); Item(ITEM_NONE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 4; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Strong Jaw stops boosting biting moves when suppressed", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_BITE; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_BITE; ability = ABILITY_STRONG_JAW; }
    GIVEN {
        ASSUME(IsBitingMove(move));
        PLAYER(SPECIES_TYRUNT) { Ability(ability); Attack(200); Speed(100); Item(ITEM_NONE); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Strong Jaw boosts biting moves while holding Protective Pads", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_BITE; ability = ABILITY_STURDY; }
    PARAMETRIZE { move = MOVE_BITE; ability = ABILITY_STRONG_JAW; }
    GIVEN {
        ASSUME(IsBitingMove(move));
        PLAYER(SPECIES_TYRUNT) { Ability(ability); Attack(200); Speed(100); Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_NATURAL_CURE); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.5), results[j + 1].damage);
    }
}
