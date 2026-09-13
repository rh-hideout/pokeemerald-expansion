#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_BUG_BITE) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveEffect(MOVE_SEISMIC_TOSS) == EFFECT_LEVEL_DAMAGE);
}

SINGLE_BATTLE_TEST("Tinted Lens doubles damage against a target with one resistance", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; }
    PARAMETRIZE { ability = ABILITY_TINTED_LENS; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_ROGGENROLA, 0) == TYPE_ROCK || GetSpeciesType(SPECIES_ROGGENROLA, 1) == TYPE_ROCK);
        PLAYER(SPECIES_VENOMOTH) { Ability(ability); Attack(200); Level(50); }
        OPPONENT(SPECIES_ROGGENROLA) { Defense(100); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Tinted Lens doubles damage against a target with two resistances", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; }
    PARAMETRIZE { ability = ABILITY_TINTED_LENS; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_MAWILE, 0) == TYPE_STEEL || GetSpeciesType(SPECIES_MAWILE, 1) == TYPE_STEEL);
        ASSUME(GetSpeciesType(SPECIES_MAWILE, 0) == TYPE_FAIRY || GetSpeciesType(SPECIES_MAWILE, 1) == TYPE_FAIRY);
        PLAYER(SPECIES_VENOMOTH) { Ability(ability); Attack(200); Level(50); }
        OPPONENT(SPECIES_MAWILE) { Defense(100); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Tinted Lens does not boost neutral damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; }
    PARAMETRIZE { ability = ABILITY_TINTED_LENS; }
    GIVEN {
        PLAYER(SPECIES_VENOMOTH) { Ability(ability); Attack(200); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(100); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Tinted Lens does not boost super-effective damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; }
    PARAMETRIZE { ability = ABILITY_TINTED_LENS; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_ABRA, 0) == TYPE_PSYCHIC || GetSpeciesType(SPECIES_ABRA, 1) == TYPE_PSYCHIC);
        PLAYER(SPECIES_VENOMOTH) { Ability(ability); Attack(200); Level(50); }
        OPPONENT(SPECIES_ABRA) { Defense(100); HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Tinted Lens does not bypass type immunity")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_DUSKULL, 0) == TYPE_GHOST || GetSpeciesType(SPECIES_DUSKULL, 1) == TYPE_GHOST);
        PLAYER(SPECIES_VENOMOTH) { Ability(ABILITY_TINTED_LENS); }
        OPPONENT(SPECIES_DUSKULL) { HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->hp, 1000);
    }
}

SINGLE_BATTLE_TEST("Tinted Lens does not increase fixed damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; }
    PARAMETRIZE { ability = ABILITY_TINTED_LENS; }
    GIVEN {
        PLAYER(SPECIES_VENOMOTH) { Ability(ability); Level(50); }
        OPPONENT(SPECIES_ROGGENROLA) { HP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, 50);
        EXPECT_EQ(results[1].damage, 50);
    }
}

SINGLE_BATTLE_TEST("Tinted Lens stops boosting resisted damage while suppressed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; }
    PARAMETRIZE { ability = ABILITY_TINTED_LENS; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SHUCKLE, 0) == TYPE_ROCK || GetSpeciesType(SPECIES_SHUCKLE, 1) == TYPE_ROCK);
        PLAYER(SPECIES_VENOMOTH) { Ability(ability); Attack(200); Level(50); Speed(50); }
        OPPONENT(SPECIES_SHUCKLE) { Ability(ABILITY_STURDY); Defense(100); HP(1000); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
