#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Strong Jaw boosts Fishious Rend whether the user moves first or last")
{
    enum Ability ability;
    u32 speed;
    s16 expectedDamage;
    // Powers 170, 255, 85, and 127 respectively, including half-down rounding.
    // At level 50 with equal Attack/Defense: floor(22 * power / 50) + 2,
    // followed by a maximum damage roll and STAB (also rounded half down).
    PARAMETRIZE { speed = 100; ability = ABILITY_WATER_ABSORB; expectedDamage = 114; }
    PARAMETRIZE { speed = 100; ability = ABILITY_STRONG_JAW; expectedDamage = 171; }
    PARAMETRIZE { speed = 25; ability = ABILITY_WATER_ABSORB; expectedDamage = 58; }
    PARAMETRIZE { speed = 25; ability = ABILITY_STRONG_JAW; expectedDamage = 85; }
    GIVEN {
        ASSUME(IsBitingMove(MOVE_FISHIOUS_REND));
        ASSUME(GetMovePower(MOVE_FISHIOUS_REND) == 85);
        PLAYER(SPECIES_DRACOVISH) { Ability(ability); Level(50); Attack(100); Speed(speed); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_FISHIOUS_REND, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISHIOUS_REND, player);
        HP_BAR(opponent, damage: expectedDamage);
    }
}


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
