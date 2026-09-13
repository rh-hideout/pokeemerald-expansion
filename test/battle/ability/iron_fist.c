#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Iron Fist boosts punches even when Punching Glove removes contact", s16 damage)
{
    enum Ability ability;
    enum Item item;
    PARAMETRIZE { ability = ABILITY_KEEN_EYE; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_IRON_FIST; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_KEEN_EYE; item = ITEM_PUNCHING_GLOVE; }
    PARAMETRIZE { ability = ABILITY_IRON_FIST; item = ITEM_PUNCHING_GLOVE; }
    GIVEN {
        ASSUME(IsPunchingMove(MOVE_FIRE_PUNCH));
        PLAYER(SPECIES_HITMONCHAN) { Ability(ability); Level(50); Attack(200); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FIRE_PUNCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.2), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, UQ_4_12(1.2), results[3].damage);
        EXPECT_GT(results[2].damage, results[0].damage);
        EXPECT_GT(results[3].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Iron Fist increases Drain Punch healing through damage dealt", s16 damage; s16 healing)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { ability = ABILITY_IRON_FIST; }
    GIVEN {
        ASSUME(IsPunchingMove(MOVE_DRAIN_PUNCH));
        PLAYER(SPECIES_HITMONCHAN) { Ability(ability); Level(50); Attack(200); MaxHP(1000); HP(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAIN_PUNCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
        HP_BAR(player, captureDamage: &results[i].healing);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.2), results[1].damage);
        for (u32 j = 0; j < 2; j++)
            EXPECT_MUL_EQ(results[j].damage, Q_4_12(-0.5), results[j].healing);
    }
}

SINGLE_BATTLE_TEST("Iron Fist boosts both hits of a two-hit Comet Punch", s16 firstHit; s16 secondHit)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { ability = ABILITY_IRON_FIST; }
    GIVEN {
        ASSUME(IsPunchingMove(MOVE_COMET_PUNCH));
        PLAYER(SPECIES_HITMONCHAN) { Ability(ability); Level(50); Attack(200); MaxHP(1000); HP(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_COMET_PUNCH, WITH_RNG(RNG_HITS, 2)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].firstHit);
        HP_BAR(opponent, captureDamage: &results[i].secondHit);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].firstHit, UQ_4_12(1.2), results[1].firstHit);
        EXPECT_MUL_EQ(results[0].secondHit, UQ_4_12(1.2), results[1].secondHit);
    }
}

SINGLE_BATTLE_TEST("Iron Fist boosts punching damage to a Substitute", u32 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { ability = ABILITY_IRON_FIST; }
    GIVEN {
        PLAYER(SPECIES_HITMONCHAN) { Ability(ability); Level(50); Attack(200); MaxHP(1000); HP(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_FIRE_PUNCH); }
    } THEN {
        EXPECT_EQ(opponent->hp, 750);
        EXPECT(opponent->volatiles.substituteHP > 0);
        results[i].damage = 250 - opponent->volatiles.substituteHP;
    } FINALLY {
        EXPECT_GT(results[0].damage, 0);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.2), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Iron Fist stops boosting punches when suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { ability = ABILITY_IRON_FIST; }
    GIVEN {
        PLAYER(SPECIES_HITMONCHAN) { Ability(ability); Level(50); Attack(200); MaxHP(1000); HP(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_FIRE_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PUNCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}


SINGLE_BATTLE_TEST("Iron Fist increases the power of punching moves by 20%", s16 damage)
{
    enum Move move;
    enum Ability ability;
    PARAMETRIZE { move = MOVE_BULLET_PUNCH; ability = ABILITY_IRON_FIST; }
    PARAMETRIZE { move = MOVE_BULLET_PUNCH; ability = ABILITY_BLAZE; }
    PARAMETRIZE { move = MOVE_SCRATCH;      ability = ABILITY_IRON_FIST; }
    PARAMETRIZE { move = MOVE_SCRATCH;      ability = ABILITY_BLAZE; }

    GIVEN {
        ASSUME(IsPunchingMove(MOVE_BULLET_PUNCH));
        ASSUME(!IsPunchingMove(MOVE_SCRATCH));
        ASSUME(GetMovePower(MOVE_BULLET_PUNCH) == GetMovePower(MOVE_SCRATCH));
        PLAYER(SPECIES_CHIMCHAR) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.2), results[0].damage); // Iron Fist affects punching moves
        EXPECT_EQ(results[2].damage, results[3].damage); // Iron Fist does not affect non-punching moves
    }
}
