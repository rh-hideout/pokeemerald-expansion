#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Gluttony activates confusion-healing Berries at half HP but not above it")
{
    enum Item item;
    enum Ability ability;
    u32 damage;
    bool32 consumed;
    PARAMETRIZE { item = ITEM_FIGY_BERRY; ability = ABILITY_THICK_FAT; damage = 49; }
    PARAMETRIZE { item = ITEM_FIGY_BERRY; ability = ABILITY_THICK_FAT; damage = 50; }
    PARAMETRIZE { item = ITEM_FIGY_BERRY; ability = ABILITY_GLUTTONY; damage = 49; }
    PARAMETRIZE { item = ITEM_FIGY_BERRY; ability = ABILITY_GLUTTONY; damage = 50; }
    PARAMETRIZE { item = ITEM_WIKI_BERRY; ability = ABILITY_THICK_FAT; damage = 49; }
    PARAMETRIZE { item = ITEM_WIKI_BERRY; ability = ABILITY_THICK_FAT; damage = 50; }
    PARAMETRIZE { item = ITEM_WIKI_BERRY; ability = ABILITY_GLUTTONY; damage = 49; }
    PARAMETRIZE { item = ITEM_WIKI_BERRY; ability = ABILITY_GLUTTONY; damage = 50; }
    PARAMETRIZE { item = ITEM_MAGO_BERRY; ability = ABILITY_THICK_FAT; damage = 49; }
    PARAMETRIZE { item = ITEM_MAGO_BERRY; ability = ABILITY_THICK_FAT; damage = 50; }
    PARAMETRIZE { item = ITEM_MAGO_BERRY; ability = ABILITY_GLUTTONY; damage = 49; }
    PARAMETRIZE { item = ITEM_MAGO_BERRY; ability = ABILITY_GLUTTONY; damage = 50; }
    PARAMETRIZE { item = ITEM_AGUAV_BERRY; ability = ABILITY_THICK_FAT; damage = 49; }
    PARAMETRIZE { item = ITEM_AGUAV_BERRY; ability = ABILITY_THICK_FAT; damage = 50; }
    PARAMETRIZE { item = ITEM_AGUAV_BERRY; ability = ABILITY_GLUTTONY; damage = 49; }
    PARAMETRIZE { item = ITEM_AGUAV_BERRY; ability = ABILITY_GLUTTONY; damage = 50; }
    PARAMETRIZE { item = ITEM_IAPAPA_BERRY; ability = ABILITY_THICK_FAT; damage = 49; }
    PARAMETRIZE { item = ITEM_IAPAPA_BERRY; ability = ABILITY_THICK_FAT; damage = 50; }
    PARAMETRIZE { item = ITEM_IAPAPA_BERRY; ability = ABILITY_GLUTTONY; damage = 49; }
    PARAMETRIZE { item = ITEM_IAPAPA_BERRY; ability = ABILITY_GLUTTONY; damage = 50; }
    ASSUME(B_CONFUSE_BERRIES_HEAL >= GEN_8);
    consumed = ability == ABILITY_GLUTTONY && damage == 50;
    GIVEN {
        PLAYER(SPECIES_SNORLAX) { Ability(ability); Nature(NATURE_HARDY); MaxHP(100); HP(100); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(damage); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } THEN {
        EXPECT_EQ(player->hp, 100 - damage + (consumed ? 33 : 0));
        EXPECT_EQ(player->item, consumed ? ITEM_NONE : item);
    }
}

SINGLE_BATTLE_TEST("Gluttony activates a Berry after Belly Drum only if the user reaches half HP")
{
    enum Ability ability;
    u32 maxHP;
    bool32 consumed;
    PARAMETRIZE { ability = ABILITY_THICK_FAT; maxHP = 100; }
    PARAMETRIZE { ability = ABILITY_THICK_FAT; maxHP = 101; }
    PARAMETRIZE { ability = ABILITY_GLUTTONY; maxHP = 100; }
    PARAMETRIZE { ability = ABILITY_GLUTTONY; maxHP = 101; }
    ASSUME(B_CONFUSE_BERRIES_HEAL >= GEN_8);
    consumed = ability == ABILITY_GLUTTONY && maxHP == 100;
    GIVEN {
        PLAYER(SPECIES_SNORLAX) { Ability(ability); Nature(NATURE_HARDY); MaxHP(maxHP); HP(maxHP); Item(ITEM_FIGY_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
        EXPECT_EQ(player->hp, maxHP - maxHP / 2 + (consumed ? 33 : 0));
        EXPECT_EQ(player->item, consumed ? ITEM_NONE : ITEM_FIGY_BERRY);
    }
}


SINGLE_BATTLE_TEST("Gluttony activates stat-raising Berries at half HP")
{
    enum Item item;
    u32 stat;
    PARAMETRIZE { item = ITEM_LIECHI_BERRY; stat = STAT_ATK; }
    PARAMETRIZE { item = ITEM_GANLON_BERRY; stat = STAT_DEF; }
    PARAMETRIZE { item = ITEM_SALAC_BERRY; stat = STAT_SPEED; }
    PARAMETRIZE { item = ITEM_PETAYA_BERRY; stat = STAT_SPATK; }
    PARAMETRIZE { item = ITEM_APICOT_BERRY; stat = STAT_SPDEF; }
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_GLUTTONY); MaxHP(100); HP(100); Item(item); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(50); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } THEN {
        EXPECT_EQ(player->hp, 50);
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(player->statStages[stat], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Gluttony changes the pinch Berry threshold from one quarter to one half")
{
    enum Ability ability;
    u32 damage;
    bool32 consumed;
    PARAMETRIZE { ability = ABILITY_CHLOROPHYLL; damage = 49; consumed = FALSE; }
    PARAMETRIZE { ability = ABILITY_CHLOROPHYLL; damage = 50; consumed = FALSE; }
    PARAMETRIZE { ability = ABILITY_CHLOROPHYLL; damage = 51; consumed = FALSE; }
    PARAMETRIZE { ability = ABILITY_CHLOROPHYLL; damage = 74; consumed = FALSE; }
    PARAMETRIZE { ability = ABILITY_CHLOROPHYLL; damage = 75; consumed = TRUE; }
    PARAMETRIZE { ability = ABILITY_GLUTTONY; damage = 49; consumed = FALSE; }
    PARAMETRIZE { ability = ABILITY_GLUTTONY; damage = 50; consumed = TRUE; }
    PARAMETRIZE { ability = ABILITY_GLUTTONY; damage = 51; consumed = TRUE; }
    PARAMETRIZE { ability = ABILITY_GLUTTONY; damage = 74; consumed = TRUE; }
    PARAMETRIZE { ability = ABILITY_GLUTTONY; damage = 75; consumed = TRUE; }
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { Ability(ability); MaxHP(100); HP(100); Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(damage); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } THEN {
        EXPECT_EQ(player->hp, 100 - damage);
        EXPECT_EQ(player->item, consumed ? ITEM_NONE : ITEM_LIECHI_BERRY);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + consumed);
    }
}

SINGLE_BATTLE_TEST("Gluttony rounds the half-HP threshold down")
{
    u32 damage;
    PARAMETRIZE { damage = 50; }
    PARAMETRIZE { damage = 51; }
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_GLUTTONY); MaxHP(101); HP(101); Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(damage); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } THEN {
        EXPECT_EQ(player->hp, 101 - damage);
        EXPECT_EQ(player->item, damage == 51 ? ITEM_NONE : ITEM_LIECHI_BERRY);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + (damage == 51));
    }
}

SINGLE_BATTLE_TEST("Gluttony does not raise Oran and Sitrus Berry thresholds above half HP")
{
    enum Item item;
    u32 damage, healing;
    PARAMETRIZE { item = ITEM_ORAN_BERRY; damage = 49; healing = 0; }
    PARAMETRIZE { item = ITEM_ORAN_BERRY; damage = 50; healing = 10; }
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; damage = 49; healing = 0; }
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; damage = 50; healing = 25; }
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_GLUTTONY); MaxHP(100); HP(100); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(damage); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } THEN {
        EXPECT_EQ(player->hp, 100 - damage + healing);
        EXPECT_EQ(player->item, healing ? ITEM_NONE : item);
    }
}

SINGLE_BATTLE_TEST("Gluttony does not bypass Unnerve")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_COMPOUND_EYES; }
    PARAMETRIZE { ability = ABILITY_UNNERVE; }
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_GLUTTONY); MaxHP(100); HP(100); Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_JOLTIK) { Ability(ability); Level(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } THEN {
        EXPECT_EQ(player->hp, 50);
        EXPECT_EQ(player->item, ability == ABILITY_UNNERVE ? ITEM_LIECHI_BERRY : ITEM_NONE);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + (ability != ABILITY_UNNERVE));
    }
}

SINGLE_BATTLE_TEST("Suppressing Gluttony restores the quarter-HP Berry threshold")
{
    u32 damage;
    PARAMETRIZE { damage = 50; }
    PARAMETRIZE { damage = 75; }
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_GLUTTONY); MaxHP(100); HP(100); Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(damage); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } THEN {
        EXPECT_EQ(player->hp, 100 - damage);
        EXPECT_EQ(player->item, damage == 75 ? ITEM_NONE : ITEM_LIECHI_BERRY);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + (damage == 75));
    }
}
