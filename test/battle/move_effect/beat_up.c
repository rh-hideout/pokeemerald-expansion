#include "global.h"
#include "test/battle.h"

// General
SINGLE_BATTLE_TEST("Beat Up hits the target for each non-fainted, non-statused member in the party")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_PICHU)
        PLAYER(SPECIES_PIKACHU) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_RAICHU)
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        MESSAGE("The Pokémon was hit 4 time(s)!");
    } THEN {
        EXPECT_EQ(gBattleStruct->beatUpSpecies[0], SPECIES_WOBBUFFET);
        EXPECT_EQ(gBattleStruct->beatUpSpecies[1], SPECIES_WYNAUT);
        EXPECT_EQ(gBattleStruct->beatUpSpecies[2], SPECIES_PICHU);
        EXPECT_EQ(gBattleStruct->beatUpSpecies[3], SPECIES_RAICHU);
    }
}

#if B_BEAT_UP < GEN_5
SINGLE_BATTLE_TEST("Gen3 Beat Up still triggers move-end effects like Life Orb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        HP_BAR(player);
        MESSAGE("Wobbuffet was hurt by the Life Orb!");
    } THEN {
        u8 beatUpSlot = gBattleStruct->beatUpSlot;
        EXPECT_EQ(beatUpSlot, 2);
    }
}
#endif

SINGLE_BATTLE_TEST("Beat Up doesn't consider Comatose as a status")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        MESSAGE("The Pokémon was hit 2 time(s)!");
    }
}

// TODO: Beat Up's strikes have each an independent chance of a critical hit

// B_BEAT_UP Gen2-4
// TO_DO_BATTLE_TEST("Beat Up lists each party member's name");
// TO_DO_BATTLE_TEST("Beat Up's damage is typeless");
// TO_DO_BATTLE_TEST("Beat Up's damage doesn't consider STAB");
// TO_DO_BATTLE_TEST("Beat Up's last strike-only can trigger King's Rock");
// TO_DO_BATTLE_TEST("Beat Up's base power is the same for each strike");
// TO_DO_BATTLE_TEST("Beat Up's damage is determined by each striking Pokémon's base attack and level and the target's defense");
// TO_DO_BATTLE_TEST("Beat Up ignores stat stage changes"); //eg. Swords Dance
// TO_DO_BATTLE_TEST("Beat Up ignores Huge Power");
// TO_DO_BATTLE_TEST("Beat Up ignores Choice Band");

#if B_BEAT_UP >= GEN_5
SINGLE_BATTLE_TEST("Beat Up doesn't list party member's name")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        NONE_OF {
            MESSAGE("Wobbuffet's attack!");
            MESSAGE("Wynaut's attack!");
        }
        MESSAGE("The Pokémon was hit 2 time(s)!");
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage is Dark-typed", s16 damage)
{
    bool32 targetIsFairy;
    PARAMETRIZE { targetIsFairy = FALSE; }
    PARAMETRIZE { targetIsFairy = TRUE; }

    ASSUME(GetMoveType(MOVE_BEAT_UP) == TYPE_DARK);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(targetIsFairy ? SPECIES_SYLVEON : SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (targetIsFairy)
            EXPECT_LT(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up's base power is determined by each striking Pokémon")
{
    s16 firstHit, secondHit;

    GIVEN {
        PLAYER(SPECIES_SHUCKLE);
        PLAYER(SPECIES_DEOXYS_ATTACK);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_BLISSEY);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &secondHit);
    } THEN {
        EXPECT_LT(firstHit, secondHit);
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage considers stat stage changes", s16 damage)
{
    bool32 boosted;
    PARAMETRIZE { boosted = FALSE; }
    PARAMETRIZE { boosted = TRUE; }

    GIVEN {
        PLAYER(SPECIES_UMBREON);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { if (boosted) { MOVE(player, MOVE_SWORDS_DANCE); } else { MOVE(player, MOVE_CELEBRATE); } }
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        if (boosted)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (boosted)
            EXPECT_GT(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage considers Huge Power and Choice Band", s16 damage)
{
    u16 ability;
    u16 item;

    PARAMETRIZE { ability = ABILITY_THICK_FAT;   item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER;  item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_THICK_FAT;   item = ITEM_CHOICE_BAND; }

    GIVEN {
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); Item(item); Moves(MOVE_BEAT_UP); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1)
            EXPECT_GT(results[i].damage, results[0].damage);
        if (i == 2)
            EXPECT_GT(results[i].damage, results[0].damage);
    }
}
#endif

#if B_BEAT_UP < GEN_5
static u16 CalcGen3BeatUpDamage(u16 attackerSpecies, u16 targetSpecies, u8 level)
{
    u32 dmg = GetSpeciesBaseAttack(attackerSpecies);
    dmg *= GetMovePower(MOVE_BEAT_UP);
    dmg *= (level * 2 / 5 + 2);
    dmg /= GetSpeciesBaseDefense(targetSpecies);
    dmg = dmg / 50 + 2;
    return dmg;
}

SINGLE_BATTLE_TEST("Beat Up lists each party member's name")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        MESSAGE("Wobbuffet's attack!");
        MESSAGE("Wynaut's attack!");
        NOT MESSAGE("Wynaut's attack!");
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage is typeless")
{
    PARAMETRIZE { } // Dummy to satisfy harness
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SABLEYE);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent);
        NONE_OF { MESSAGE("It doesn't affect"); }
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage doesn't consider STAB", s16 damage)
{
    s16 damageVal = 0;
    bool32 dummy;
    PARAMETRIZE { dummy = FALSE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damageVal);
    } THEN {
        u16 expected = CalcGen3BeatUpDamage(SPECIES_WOBBUFFET, SPECIES_WOBBUFFET, 50);
        EXPECT_EQ(damageVal, expected);
    }
}

SINGLE_BATTLE_TEST("Beat Up's base power is the same for each strike", s16 damage)
{
    // Uses two identical low-Attack Wynaut strikers to verify per-hit base power stays constant.
    s16 firstHit = 0, secondHit = 0;
    bool32 dummy;
    PARAMETRIZE { dummy = FALSE; }
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &secondHit);
    } THEN {
        EXPECT_EQ(firstHit, secondHit);
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage is determined by each striking Pokémon's base attack and level and the target's defense", s16 damage)
{
    // Shuckle has minimal base Attack, Deoxys-A has maximal base Attack; compare their hits.
    s16 shuckleHit = 0, deoxysHit = 0;
    bool32 dummy;
    PARAMETRIZE { dummy = FALSE; }
    PARAMETRIZE { }
    GIVEN {
        PLAYER(SPECIES_SHUCKLE);
        PLAYER(SPECIES_DEOXYS_ATTACK);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_BLISSEY);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &shuckleHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &deoxysHit);
    } THEN {
        u16 shuckleDmg = CalcGen3BeatUpDamage(SPECIES_SHUCKLE, SPECIES_BLISSEY, 50);
        u16 deoxysDmg = CalcGen3BeatUpDamage(SPECIES_DEOXYS_ATTACK, SPECIES_BLISSEY, 50);
        EXPECT_EQ(shuckleHit, shuckleDmg);
        EXPECT_EQ(deoxysHit, deoxysDmg);
        EXPECT_LT(shuckleHit, deoxysHit);
    }
}

SINGLE_BATTLE_TEST("Beat Up ignores stat stage changes", s16 damage)
{
    bool32 boosted;
    PARAMETRIZE { boosted = FALSE; }
    PARAMETRIZE { boosted = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { if (boosted) { MOVE(player, MOVE_SWORDS_DANCE); } else { MOVE(player, MOVE_CELEBRATE); } }
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        if (boosted)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (boosted)
            EXPECT_EQ(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up ignores Huge Power", s16 damage)
{
    u16 ability;

    PARAMETRIZE { ability = ABILITY_THICK_FAT; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER; }

    GIVEN {
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); Moves(MOVE_BEAT_UP); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (ability == ABILITY_HUGE_POWER)
            EXPECT_EQ(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up ignores Choice Band", s16 damage)
{
    u16 item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHOICE_BAND; }

    GIVEN {
        PLAYER(SPECIES_URSARING) { Item(item); Moves(MOVE_BEAT_UP); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (item == ITEM_CHOICE_BAND)
            EXPECT_EQ(results[i].damage, results[0].damage);
    }
}
#endif

// Unconfirmed by Bulbapedia
// - Technician interacion
