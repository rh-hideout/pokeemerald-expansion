#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Heatproof reduces physical Fire-type damage", s16 damage)
{
    enum Ability ability;
    enum Move move, weather;
    PARAMETRIZE { ability = ABILITY_LEVITATE; move = MOVE_FIRE_PUNCH; weather = MOVE_CELEBRATE; }
    PARAMETRIZE { ability = ABILITY_HEATPROOF; move = MOVE_FIRE_PUNCH; weather = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Level(50); Attack(200); SpAttack(200); }
        OPPONENT(SPECIES_BRONZONG) { Ability(ability); MaxHP(1000); HP(1000); Defense(100); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, weather); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 2; j += 2)
            EXPECT_MUL_EQ(results[j + 1].damage, UQ_4_12(2.0), results[j].damage);
    }
}

SINGLE_BATTLE_TEST("Heatproof does not reduce non-Fire physical or special damage", s16 damage)
{
    enum Ability ability;
    enum Move move, weather;
    PARAMETRIZE { ability = ABILITY_LEVITATE; move = MOVE_TACKLE; weather = MOVE_CELEBRATE; }
    PARAMETRIZE { ability = ABILITY_HEATPROOF; move = MOVE_TACKLE; weather = MOVE_CELEBRATE; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; move = MOVE_WATER_GUN; weather = MOVE_CELEBRATE; }
    PARAMETRIZE { ability = ABILITY_HEATPROOF; move = MOVE_WATER_GUN; weather = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Level(50); Attack(200); SpAttack(200); }
        OPPONENT(SPECIES_BRONZONG) { Ability(ability); MaxHP(1000); HP(1000); Defense(100); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, weather); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 4; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Heatproof still reduces Fire-type damage in sun and rain", s16 damage)
{
    enum Ability ability;
    enum Move move, weather;
    PARAMETRIZE { ability = ABILITY_LEVITATE; move = MOVE_FLAMETHROWER; weather = MOVE_SUNNY_DAY; }
    PARAMETRIZE { ability = ABILITY_HEATPROOF; move = MOVE_FLAMETHROWER; weather = MOVE_SUNNY_DAY; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; move = MOVE_FLAMETHROWER; weather = MOVE_RAIN_DANCE; }
    PARAMETRIZE { ability = ABILITY_HEATPROOF; move = MOVE_FLAMETHROWER; weather = MOVE_RAIN_DANCE; }
    GIVEN {
        PLAYER(SPECIES_MEW) { Ability(ABILITY_SYNCHRONIZE); Level(50); Attack(200); SpAttack(200); }
        OPPONENT(SPECIES_BRONZONG) { Ability(ability); MaxHP(1000); HP(1000); Defense(100); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, weather); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 4; j += 2)
            EXPECT_MUL_EQ(results[j + 1].damage, UQ_4_12(2.0), results[j].damage);
    }
}

SINGLE_BATTLE_TEST("Heatproof does not prevent Will-O-Wisp from burning its user")
{
    GIVEN {
        WITH_CONFIG(B_BURN_DAMAGE, GEN_7);
        PLAYER(SPECIES_VULPIX) { Ability(ABILITY_FLASH_FIRE); }
        OPPONENT(SPECIES_BRONZONG) { Ability(ABILITY_HEATPROOF); MaxHP(320); HP(320); }
    } WHEN {
        TURN { MOVE(player, MOVE_WILL_O_WISP); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_BURN);
        EXPECT_EQ(opponent->hp, 310);
    }
}

SINGLE_BATTLE_TEST("Heatproof stops reducing burn damage when suppressed")
{
    GIVEN {
        WITH_CONFIG(B_BURN_DAMAGE, GEN_7);
        PLAYER(SPECIES_BRONZONG) { Ability(ABILITY_HEATPROOF); MaxHP(320); HP(320); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_SHUCKLE) { Ability(ABILITY_STURDY); }
    } WHEN {
        TURN {}
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
    } SCENE {
        HP_BAR(player, damage: 10);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        HP_BAR(player, damage: 20);
    } THEN {
        EXPECT_EQ(player->hp, 290);
        EXPECT(player->status1 & STATUS1_BURN);
    }
}


ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
    ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
}

SINGLE_BATTLE_TEST("Heatproof halves damage from fire type moves")
{
    s16 damage[2];
    GIVEN {
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_BRONZONG) { Ability(ABILITY_HEATPROOF); }
    }
    WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
        TURN { MOVE(player, MOVE_WORRY_SEED); }
        TURN { MOVE(player, MOVE_EMBER); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        EXPECT_MUL_EQ(damage[0], Q_4_12(2), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Heatproof halves the damage done by burn from 1/8th to 1/16th (Gen1-6) or 1/16th to 1/32nd (Gen 7+)")
{
    u32 config, burnRate;

    PARAMETRIZE { config = GEN_7; burnRate = 32; }
    PARAMETRIZE { config = GEN_6; burnRate = 16; }

    GIVEN {
        WITH_CONFIG(B_BURN_DAMAGE, config);
        PLAYER (SPECIES_BRONZONG) { Ability(ABILITY_HEATPROOF); Status1(STATUS1_BURN); }
        OPPONENT (SPECIES_WOBBUFFET);
    }
    WHEN {
        TURN {}
    }
    SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        HP_BAR(player, damage: maxHP / burnRate);
    }
}
