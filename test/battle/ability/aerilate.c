#include "global.h"
#include "test/battle.h"
#include "berry.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
    ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
}

SINGLE_BATTLE_TEST("Aerilate turns a Normal-type move into Flying-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_DUSKULL, 0) == TYPE_GHOST);
        PLAYER(SPECIES_DUSKULL);
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Aerilate cannot turn certain moves into Flying type moves")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_WEATHER_BALL; }
    PARAMETRIZE { move = MOVE_JUDGMENT; }
    PARAMETRIZE { move = MOVE_TECHNO_BLAST; }
    PARAMETRIZE { move = MOVE_REVELATION_DANCE; }
    PARAMETRIZE { move = MOVE_MULTI_ATTACK; }
    PARAMETRIZE { move = MOVE_TERRAIN_PULSE; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_DUSKULL, 0) == TYPE_GHOST);
        ASSUME(GetSpeciesType(SPECIES_CLEFAIRY, 0) == TYPE_FAIRY);
        ASSUME(GetSpeciesType(SPECIES_SALAMENCE_MEGA, 0) == TYPE_DRAGON);
        ASSUME(GetMoveType(move) == TYPE_NORMAL);
        PLAYER(move == MOVE_REVELATION_DANCE ? SPECIES_CLEFAIRY : SPECIES_DUSKULL);
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); }
    } WHEN {
        TURN { MOVE(opponent, move, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, opponent);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Aerilate boosts power of affected moves by 20% (Gen7+) or 30% (Gen1-6)", s16 damage)
{
    enum Move move;
    u32 genConfig;
    PARAMETRIZE { move = MOVE_CELEBRATE;   genConfig = GEN_7; }
    PARAMETRIZE { move = MOVE_CELEBRATE;   genConfig = GEN_6; }
    PARAMETRIZE { move = MOVE_SKILL_SWAP;  genConfig = GEN_7; }
    PARAMETRIZE { move = MOVE_SKILL_SWAP;  genConfig = GEN_6; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, genConfig);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SALAMENCE) { Ability(ABILITY_MOXIE); Item(ITEM_SALAMENCITE); }
    } WHEN {
        TURN { MOVE(opponent, move, gimmick: GIMMICK_MEGA); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[2].damage);
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.3), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Aerilate doesn't affect Weather Ball's type", s16 damage)
{
    enum Move move1, move2;
    PARAMETRIZE { move1 = MOVE_CELEBRATE; move2 = MOVE_CELEBRATE; }
    PARAMETRIZE { move1 = MOVE_SUNNY_DAY; move2 = MOVE_CELEBRATE; }
    PARAMETRIZE { move1 = MOVE_CELEBRATE; move2 = MOVE_SKILL_SWAP; }
    PARAMETRIZE { move1 = MOVE_SUNNY_DAY; move2 = MOVE_SKILL_SWAP; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
        ASSUME(GetMoveType(MOVE_WEATHER_BALL) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME(GetSpeciesType(SPECIES_PINSIR, 0) == TYPE_BUG);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PINSIR) { Ability(ABILITY_HYPER_CUTTER); Item(ITEM_PINSIRITE); }
    } WHEN {
        TURN { MOVE(opponent, move2, gimmick: GIMMICK_MEGA); MOVE(player, move1); }
        TURN { MOVE(player, MOVE_WEATHER_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move2, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move1, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WEATHER_BALL, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(6.0), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(6.0), results[3].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
        EXPECT_EQ(results[1].damage, results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Aerilate doesn't affect Natural Gift's type")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SKILL_SWAP; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME(gBerries[ItemIdToBerryType(ITEM_PERSIM_BERRY)].naturalGiftType == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_SALAMENCE_MEGA, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_SALAMENCE_MEGA, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PERSIM_BERRY); }
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); }
    } WHEN {
        TURN { MOVE(opponent, move, gimmick: GIMMICK_MEGA); MOVE(player, MOVE_NATURAL_GIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Aerilate doesn't affect Judgment / Techno Blast / Multi-Attack's type")
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
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME(gItemsInfo[ITEM_ZAP_PLATE].holdEffect == HOLD_EFFECT_PLATE);
        ASSUME(gItemsInfo[ITEM_ZAP_PLATE].secondaryId == TYPE_ELECTRIC);
        ASSUME(gItemsInfo[ITEM_SHOCK_DRIVE].holdEffect == HOLD_EFFECT_DRIVE);
        ASSUME(gItemsInfo[ITEM_SHOCK_DRIVE].secondaryId == TYPE_ELECTRIC);
        ASSUME(gItemsInfo[ITEM_ELECTRIC_MEMORY].holdEffect == HOLD_EFFECT_MEMORY);
        ASSUME(gItemsInfo[ITEM_ELECTRIC_MEMORY].secondaryId == TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(SPECIES_DIGLETT, 0) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); }
        OPPONENT(SPECIES_DIGLETT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, gimmick: GIMMICK_MEGA); }
        TURN { SWITCH(opponent, 1); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Aerilate doesn't affect Hidden Power's type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER) == EFFECT_HIDDEN_POWER);
        ASSUME(gTypesInfo[TYPE_ELECTRIC].isHiddenPowerType == TRUE);
        ASSUME(GetSpeciesType(SPECIES_DIGLETT, 0) == TYPE_GROUND);
        // These IVs make Hidden Power Electric-type.
        PLAYER(SPECIES_PINSIR) { Item(ITEM_PINSIRITE); HPIV(31); AttackIV(31); DefenseIV(31); SpAttackIV(30); SpDefenseIV(31); SpeedIV(31); }
        OPPONENT(SPECIES_DIGLETT);
    } WHEN {
        TURN { MOVE(player, MOVE_HIDDEN_POWER, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Aerilate doesn't override Electrify")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        ASSUME(GetSpeciesType(SPECIES_SANDSHREW, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_SANDSHREW, 1) == TYPE_GROUND);
        PLAYER(SPECIES_PINSIR) { Item(ITEM_PINSIRITE); Speed(1); }
        OPPONENT(SPECIES_SANDSHREW) { Moves(MOVE_ELECTRIFY); Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIFY); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Aerilate overrides Ion Deluge")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ION_DELUGE) == EFFECT_ION_DELUGE);
        ASSUME(GetSpeciesType(SPECIES_SANDSHREW, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_SANDSHREW, 1) == TYPE_GROUND);
        PLAYER(SPECIES_PINSIR) { Item(ITEM_PINSIRITE); Speed(1); }
        OPPONENT(SPECIES_SANDSHREW) { Moves(MOVE_ION_DELUGE); Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ION_DELUGE); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ION_DELUGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Aerilate changes Tera Blast's type when not Terastallized")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERA_BLAST) == EFFECT_TERA_BLAST);
        ASSUME(GetMoveType(MOVE_TERA_BLAST) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_DUSKULL, 0) == TYPE_GHOST || GetSpeciesType(SPECIES_DUSKULL, 1) == TYPE_GHOST);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); Moves(MOVE_SKILL_SWAP); }
        OPPONENT(SPECIES_DUSKULL);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, gimmick: GIMMICK_MEGA, target: player); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_TERA_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Aerilate doesn't change Tera Blast's type when Terastallized")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERA_BLAST) == EFFECT_TERA_BLAST);
        ASSUME(GetMoveType(MOVE_TERA_BLAST) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_MISDREAVUS, 0) == TYPE_GHOST);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); Moves(MOVE_SKILL_SWAP); }
        OPPONENT(SPECIES_MISDREAVUS);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, gimmick: GIMMICK_MEGA, target: player); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Aerilate doesn't affect Terrain Pulse's type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERRAIN_PULSE) == EFFECT_TERRAIN_PULSE);
        ASSUME(GetMoveType(MOVE_TERRAIN_PULSE) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME(GetSpeciesType(SPECIES_SANDSHREW, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_SANDSHREW, 1) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); Moves(MOVE_SKILL_SWAP); }
        OPPONENT(SPECIES_SANDSHREW);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, gimmick: GIMMICK_MEGA, target: player); MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_TERRAIN_PULSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TERRAIN_PULSE, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Aerilate doesn't affect damaging Z-Move types")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_DUSKULL, 0) == TYPE_GHOST || GetSpeciesType(SPECIES_DUSKULL, 1) == TYPE_GHOST);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); Moves(MOVE_SKILL_SWAP); }
        OPPONENT(SPECIES_DUSKULL);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, gimmick: GIMMICK_MEGA, target: player); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Aerilate turns Max Strike into Max Airstream")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SALAMENCE) { Ability(ABILITY_MOXIE); Item(ITEM_SALAMENCITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, target: player, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_AIRSTREAM, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Aerilate does not boost Max Airstream's power", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_GUST; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_GUST) == TYPE_FLYING);
        ASSUME(GetMaxMovePower(MOVE_SCRATCH, MOVE_MAX_AIRSTREAM) == GetMaxMovePower(MOVE_GUST, MOVE_MAX_AIRSTREAM));
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { Attack(100); SpAttack(100); }
        OPPONENT(SPECIES_SALAMENCE) { Ability(ABILITY_MOXIE); Item(ITEM_SALAMENCITE); Defense(100); SpDefense(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP, target: player, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(player, move, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_AIRSTREAM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
