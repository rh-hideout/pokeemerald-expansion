#include "global.h"
#include "test/battle.h"
#include "berry.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
    ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
}

SINGLE_BATTLE_TEST("Dragonize turns a Normal-type move into a dragon-type move")
{
    GIVEN {
        PLAYER(SPECIES_DRUDDIGON);
        OPPONENT(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Dragonize boosts power of affected moves by 20% (Gen7+) or 30% (Gen1-6)", s16 damage)
{
    bool32 suppressed;
    u32 genConfig;
    PARAMETRIZE { suppressed = TRUE;  genConfig = GEN_7; }
    PARAMETRIZE { suppressed = TRUE;  genConfig = GEN_6; }
    PARAMETRIZE { suppressed = FALSE; genConfig = GEN_7; }
    PARAMETRIZE { suppressed = FALSE; genConfig = GEN_6; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, genConfig);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); Moves(MOVE_TACKLE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, suppressed ? MOVE_GASTRO_ACID : MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        if (genConfig >= GEN_7)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.8), results[2].damage); // STAB + ate
        else
            EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.95), results[3].damage); // STAB + ate
    }
}

SINGLE_BATTLE_TEST("Dragonize doesn't affect Weather Ball's type", s16 damage)
{
    enum Move move;
    bool32 suppressed;
    PARAMETRIZE { move = MOVE_CELEBRATE; suppressed = TRUE; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; suppressed = TRUE; }
    PARAMETRIZE { move = MOVE_CELEBRATE; suppressed = FALSE; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; suppressed = FALSE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
        ASSUME(GetSpeciesType(SPECIES_PINSIR, 0) == TYPE_BUG);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); SpAttack(300); Speed(1); }
        OPPONENT(SPECIES_PINSIR) { SpDefense(100); HP(2000); MaxHP(2000); Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, suppressed ? MOVE_GASTRO_ACID : MOVE_CELEBRATE); MOVE(player, move); }
        TURN { MOVE(player, MOVE_WEATHER_BALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
        if (move == MOVE_SUNNY_DAY)
            MESSAGE("It's super effective!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(6.0), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(6.0), results[3].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
        EXPECT_EQ(results[1].damage, results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Dragonize doesn't affect Natural Gift's type")
{
    bool32 suppressed;
    PARAMETRIZE { suppressed = TRUE; }
    PARAMETRIZE { suppressed = FALSE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        ASSUME(gBerries[ItemIdToBerryType(ITEM_ORAN_BERRY)].naturalGiftType == TYPE_POISON);
        ASSUME(GetSpeciesType(SPECIES_BELDUM, 0) == TYPE_STEEL);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); Item(ITEM_ORAN_BERRY); Speed(1); }
        OPPONENT(SPECIES_BELDUM) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, suppressed ? MOVE_GASTRO_ACID : MOVE_CELEBRATE); MOVE(player, MOVE_NATURAL_GIFT); }
    } SCENE {
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player); }
        MESSAGE("It doesn't affect the opposing Beldum…");
    }
}

SINGLE_BATTLE_TEST("Dragonize doesn't affect Judgment / Techno Blast / Multi-Attack's type")
{
    enum Move move;
    enum Item item;
    PARAMETRIZE { move = MOVE_JUDGMENT; item = ITEM_ZAP_PLATE; }
    PARAMETRIZE { move = MOVE_TECHNO_BLAST; item = ITEM_SHOCK_DRIVE; }
    PARAMETRIZE { move = MOVE_MULTI_ATTACK; item = ITEM_ELECTRIC_MEMORY; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_JUDGMENT) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(GetMoveEffect(MOVE_TECHNO_BLAST) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(GetMoveEffect(MOVE_MULTI_ATTACK) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(gItemsInfo[ITEM_ZAP_PLATE].holdEffect == HOLD_EFFECT_PLATE);
        ASSUME(gItemsInfo[ITEM_ZAP_PLATE].secondaryId == TYPE_ELECTRIC);
        ASSUME(gItemsInfo[ITEM_SHOCK_DRIVE].holdEffect == HOLD_EFFECT_DRIVE);
        ASSUME(gItemsInfo[ITEM_SHOCK_DRIVE].secondaryId == TYPE_ELECTRIC);
        ASSUME(gItemsInfo[ITEM_ELECTRIC_MEMORY].holdEffect == HOLD_EFFECT_MEMORY);
        ASSUME(gItemsInfo[ITEM_ELECTRIC_MEMORY].secondaryId == TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(SPECIES_DIGLETT, 0) == TYPE_GROUND);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); Item(item); }
        OPPONENT(SPECIES_DIGLETT);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NOT { ANIMATION(ANIM_TYPE_MOVE, move, player); }
        MESSAGE("It doesn't affect the opposing Diglett…");
    }
}

SINGLE_BATTLE_TEST("Dragonize doesn't affect Hidden Power's type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER) == EFFECT_HIDDEN_POWER);
        ASSUME(gTypesInfo[TYPE_ELECTRIC].isHiddenPowerType == TRUE);
        ASSUME(GetSpeciesType(SPECIES_DIGLETT, 0) == TYPE_GROUND);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); HPIV(31); AttackIV(31); DefenseIV(31); SpAttackIV(30); SpDefenseIV(31); SpeedIV(31); } // HP Electric
        OPPONENT(SPECIES_DIGLETT);
    } WHEN {
        TURN { MOVE(player, MOVE_HIDDEN_POWER); }
    } SCENE {
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER, player); }
        MESSAGE("It doesn't affect the opposing Diglett…");
    }
}

SINGLE_BATTLE_TEST("Dragonize doesn't override Electrify")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        ASSUME(GetSpeciesType(SPECIES_SANDSHREW, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_SANDSHREW, 1) == TYPE_GROUND);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); }
        OPPONENT(SPECIES_SANDSHREW);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIFY); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponent);
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player); }
        MESSAGE("It doesn't affect the opposing Sandshrew…");
    }
}

SINGLE_BATTLE_TEST("Dragonize overrides Ion Deluge")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ION_DELUGE) == EFFECT_ION_DELUGE);
        ASSUME(GetSpeciesType(SPECIES_DRUDDIGON, 0) == TYPE_DRAGON || GetSpeciesType(SPECIES_DRUDDIGON, 1) == TYPE_DRAGON);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); }
        OPPONENT(SPECIES_DRUDDIGON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ION_DELUGE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ION_DELUGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Dragonize changes Tera Blast's type when not Terastallized")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERA_BLAST) == EFFECT_TERA_BLAST);
        ASSUME(GetMoveType(MOVE_TERA_BLAST) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_CUFANT, 0) == TYPE_STEEL || GetSpeciesType(SPECIES_CUFANT, 1) == TYPE_STEEL);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); }
        OPPONENT(SPECIES_CUFANT);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
        MESSAGE("It's not very effective…");
    }
}

SINGLE_BATTLE_TEST("Dragonize doesn't change Tera Blast's type when Terastallized")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERA_BLAST) == EFFECT_TERA_BLAST);
        ASSUME(GetMoveType(MOVE_TERA_BLAST) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_MISDREAVUS, 0) == TYPE_GHOST);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_MISDREAVUS);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); }
    } SCENE {
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player); }
        MESSAGE("It doesn't affect the opposing Misdreavus…");
    }
}

SINGLE_BATTLE_TEST("Dragonize doesn't affect Terrain Pulse's type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERRAIN_PULSE) == EFFECT_TERRAIN_PULSE);
        ASSUME(GetMoveType(MOVE_TERRAIN_PULSE) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_SANDSHREW, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_SANDSHREW, 1) == TYPE_GROUND);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); }
        OPPONENT(SPECIES_SANDSHREW);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_TERRAIN_PULSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_TERRAIN_PULSE, player); }
        MESSAGE("It doesn't affect the opposing Sandshrew…");
    }
}

SINGLE_BATTLE_TEST("Dragonize doesn't affect damaging Z-Move types")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_BAGON, 0) == TYPE_DRAGON || GetSpeciesType(SPECIES_BAGON, 1) == TYPE_DRAGON);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_BAGON);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        NOT { MESSAGE("It's super effective!"); }
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dragonize turns Max Strike into Max Wyrmwind")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_FERALIGATR) { Ability(ABILITY_TORRENT); Item(ITEM_FERALIGITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, target: player, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_WYRMWIND, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dragonize does not boost Max Wyrmwind's power", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_TWISTER; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_TWISTER) == TYPE_DRAGON);
        ASSUME(GetMaxMovePower(MOVE_SCRATCH, MOVE_MAX_WYRMWIND) == GetMaxMovePower(MOVE_TWISTER, MOVE_MAX_WYRMWIND));
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); SpAttack(100); }
        OPPONENT(SPECIES_FERALIGATR) { Ability(ABILITY_TORRENT); Item(ITEM_FERALIGITE); Defense(100); SpDefense(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, target: player, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(player, move, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_WYRMWIND, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
