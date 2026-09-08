#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Reckless increases recoil through damage dealt, not a second recoil multiplier", s16 damage; s16 recoil)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_RECKLESS; }
    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_HEAD_SMASH) == 50);
        PLAYER(SPECIES_MIENFOO) { Ability(ability); Level(50); MaxHP(1000); HP(1000); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEAD_SMASH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
        HP_BAR(player, captureDamage: &results[i].recoil);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.2), results[1].damage);
        for (u32 j = 0; j < 2; j++)
            EXPECT_EQ(results[j].recoil, results[j].damage / 2);
    }
}

SINGLE_BATTLE_TEST("Reckless does not increase Jump Kick crash damage (Gen 5+)")
{
    enum Ability ability;
    bool32 protect;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; protect = FALSE; }
    PARAMETRIZE { ability = ABILITY_RECKLESS; protect = FALSE; }
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; protect = TRUE; }
    PARAMETRIZE { ability = ABILITY_RECKLESS; protect = TRUE; }
    GIVEN {
        ASSUME(B_RECOIL_IF_MISS_DMG >= GEN_5);
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); }
    } WHEN {
        if (protect)
            TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_JUMP_KICK); }
        else
            TURN { MOVE(player, MOVE_JUMP_KICK, hit: FALSE); }
    } THEN {
        EXPECT_EQ(player->hp, 500);
        EXPECT_EQ(opponent->hp, 1000);
    }
}

SINGLE_BATTLE_TEST("Reckless does not treat Life Orb damage as move recoil", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_RECKLESS; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SCRATCH) != EFFECT_RECOIL);
        ASSUME(GetMoveEffect(MOVE_SCRATCH) != EFFECT_RECOIL_IF_MISS);
        PLAYER(SPECIES_MIENFOO) { Ability(ability); Level(50); MaxHP(1000); HP(1000); Attack(200); Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
        HP_BAR(player, damage: 100);
    } THEN {
        EXPECT_EQ(player->hp, 900);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless boosts recoil moves against a Substitute", u32 damage)
{
    enum Ability ability;
    bool32 substitute;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; substitute = FALSE; }
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; substitute = TRUE; }
    PARAMETRIZE { ability = ABILITY_RECKLESS; substitute = FALSE; }
    PARAMETRIZE { ability = ABILITY_RECKLESS; substitute = TRUE; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); Level(50); MaxHP(1000); HP(1000); Attack(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1000); Defense(100); Speed(50); }
    } WHEN {
        if (substitute)
            TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_DOUBLE_EDGE); }
    } THEN {
        if (substitute)
        {
            EXPECT_EQ(opponent->hp, 750);
            EXPECT(opponent->volatiles.substituteHP > 0);
            results[i].damage = 250 - opponent->volatiles.substituteHP;
        }
        else
        {
            results[i].damage = 1000 - opponent->hp;
        }
        EXPECT_LT(player->hp, 1000);
    } FINALLY {
        EXPECT_GT(results[0].damage, 0);
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
        EXPECT_GT(results[3].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless boosts physical recoil moves by 20%", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_BRAVE_BIRD; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_BRAVE_BIRD; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_HEAD_SMASH; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_HEAD_SMASH; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_WILD_CHARGE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_WILD_CHARGE; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_WOOD_HAMMER; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_WOOD_HAMMER; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 12; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.2), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless boosts special recoil moves by 20%", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_LIGHT_OF_RUIN; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_LIGHT_OF_RUIN; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.2), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless boosts crash moves by 20%", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_JUMP_KICK; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_JUMP_KICK; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_HIGH_JUMP_KICK; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_HIGH_JUMP_KICK; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 4; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.2), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Reckless does not boost Struggle", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_STRUGGLE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_STRUGGLE; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
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

SINGLE_BATTLE_TEST("Reckless does not boost ordinary attacks", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
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

SINGLE_BATTLE_TEST("Reckless does not boost moves that spend the user's HP", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_STEEL_BEAM; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_STEEL_BEAM; ability = ABILITY_RECKLESS; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_MIND_BLOWN; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
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

SINGLE_BATTLE_TEST("Reckless stops boosting recoil moves when suppressed", s16 damage)
{
    enum Ability ability;
    enum Move move;
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_DOUBLE_EDGE; ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_MIENFOO) { Ability(ability); MaxHP(1000); HP(1000); Attack(200); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); Defense(100); SpDefense(100); Speed(50); }
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
