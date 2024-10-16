#include "global.h"
#include "test/test.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "item.h"
#include "malloc.h"
#include "main_menu.h"
#include "string_util.h"
#include "text.h"
#include "constants/abilities.h"
#include "constants/battle.h"
#include "constants/battle_string_ids.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "test/overworld_script.h"

TEST("Move names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 72;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Battle Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 64;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Contest Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 61;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    // All moves explicitly listed here are too big to fit.
    switch (move)
    {
    case MOVE_NATURES_MADNESS:
        EXPECT_GT(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
        break;
    default:
        EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
        break;
    }
}

TEST("Move names fit on TMs & HMs Bag Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 63;
    u32 move = MOVE_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemsInfo[i].pocket == POCKET_TM_HM)
        {
            PARAMETRIZE_LABEL("%S", gMovesInfo[gItemsInfo[i].secondaryId].name) { move = gItemsInfo[i].secondaryId; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move names fit on Move Relearner Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 72;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].name) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].name, 0), widthPx);
}

TEST("Move descriptions fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NORMAL, widthPx = 152;
    u32 move = MOVE_NONE;
    for (i = 1; i < MOVES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gMovesInfo[i].description) { move = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gMovesInfo[move].description, 0), widthPx);
}

TEST("Item names fit on Bag Screen (list)")
{
    u32 i;
    const u32 fontId = FONT_NARROWER;
    const u32 tmHmBerryWidthPx = 71, restWidthPx = 88;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    if (gItemsInfo[item].pocket == POCKET_TM_HM || gItemsInfo[item].pocket == POCKET_BERRIES)
        EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), tmHmBerryWidthPx);
    else
        EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), restWidthPx);
}

TEST("Item plural names fit on Bag Screen (left box)")
{
    u32 i;
    // -6 for the question mark in FONT_NORMAL.
    const u32 fontId = FONT_NARROWER, widthPx = 102 - 6;
    u32 item = ITEM_NONE;
    u8 pluralName[ITEM_NAME_PLURAL_LENGTH + 1];
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    CopyItemNameHandlePlural(item, pluralName, 2);
    EXPECT_LE(GetStringWidth(fontId, pluralName, 0), widthPx);
}

TEST("Item plural names fit on PC storage (left box)")
{
    u32 i;
    // -6 for the question mark in FONT_NORMAL.
    const u32 fontId = FONT_NARROWER, widthPx = 104 - 6;
    u32 item = ITEM_NONE;
    u8 pluralName[ITEM_NAME_PLURAL_LENGTH + 1];
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    CopyItemNameHandlePlural(item, pluralName, 2);
    EXPECT_LE(GetStringWidth(fontId, pluralName, 0), widthPx);
}

TEST("Item names fit on Pokemon Storage System")
{
    u32 i;
    const u32 fontId = FONT_SMALL_NARROWER, widthPx = 50;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemsInfo[i].importance) continue;
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    // All items explicitly listed here are too big to fit. The ones
    // with a hold effect are listed at the bottom in case you want to
    // focus on making them fit (they are the most likely to appear on
    // the storage system UI, along with anything that could be held
    // in the wild).
    switch (item)
    {
    case ITEM_ENERGY_POWDER:
    case ITEM_PEWTER_CRUNCHIES:
    case ITEM_RAGE_CANDY_BAR:
    case ITEM_LUMIOSE_GALETTE:
    case ITEM_HEALTH_FEATHER:
    case ITEM_MUSCLE_FEATHER:
    case ITEM_RESIST_FEATHER:
    case ITEM_GENIUS_FEATHER:
    case ITEM_CLEVER_FEATHER:
    case ITEM_ABILITY_CAPSULE:
    case ITEM_DYNAMAX_CANDY:
    case ITEM_MAX_MUSHROOMS:
    case ITEM_GOLD_BOTTLE_CAP:
    case ITEM_PRETTY_FEATHER:
    case ITEM_STRANGE_SOUVENIR:
    case ITEM_FOSSILIZED_BIRD:
    case ITEM_FOSSILIZED_FISH:
    case ITEM_FOSSILIZED_DRAKE:
    case ITEM_FOSSILIZED_DINO:
    case ITEM_SURPRISE_MULCH:
    case ITEM_YELLOW_APRICORN:
    case ITEM_GREEN_APRICORN:
    case ITEM_WHITE_APRICORN:
    case ITEM_BLACK_APRICORN:
    case ITEM_THUNDER_STONE:
    case ITEM_GALARICA_WREATH:
    case ITEM_STRAWBERRY_SWEET:
    case ITEM_AUSPICIOUS_ARMOR:
    case ITEM_BIG_BAMBOO_SHOOT:
    case ITEM_GIMMIGHOUL_COIN:
    case ITEM_LEADERS_CREST:
    case ITEM_MALICIOUS_ARMOR:
    case ITEM_TINY_BAMBOO_SHOOT:
    case ITEM_BUG_TERA_SHARD:
    case ITEM_DARK_TERA_SHARD:
    case ITEM_DRAGON_TERA_SHARD:
    case ITEM_ELECTRIC_TERA_SHARD:
    case ITEM_FAIRY_TERA_SHARD:
    case ITEM_FIGHTING_TERA_SHARD:
    case ITEM_FIRE_TERA_SHARD:
    case ITEM_FLYING_TERA_SHARD:
    case ITEM_GHOST_TERA_SHARD:
    case ITEM_GRASS_TERA_SHARD:
    case ITEM_GROUND_TERA_SHARD:
    case ITEM_ICE_TERA_SHARD:
    case ITEM_NORMAL_TERA_SHARD:
    case ITEM_POISON_TERA_SHARD:
    case ITEM_PSYCHIC_TERA_SHARD:
    case ITEM_ROCK_TERA_SHARD:
    case ITEM_STEEL_TERA_SHARD:
    case ITEM_WATER_TERA_SHARD:
    case ITEM_BLACK_AUGURITE:
    case ITEM_UNREMARKABLE_TEACUP:
    case ITEM_MASTERPIECE_TEACUP:
    case ITEM_FRESH_START_MOCHI:
    case ITEM_STELLAR_TERA_SHARD:
    case ITEM_JUBILIFE_MUFFIN:
    case ITEM_SUPERB_REMEDY:
    case ITEM_AUX_POWERGUARD:
    case ITEM_CHOICE_DUMPLING:
    case ITEM_TWICE_SPICED_RADISH:
    // Items with hold effects:
    case ITEM_ELECTRIC_MEMORY:
    case ITEM_FIGHTING_MEMORY:
    case ITEM_GROUND_MEMORY:
    case ITEM_PSYCHIC_MEMORY:
    case ITEM_DRAGON_MEMORY:
    case ITEM_CHARIZARDITE_X:
    case ITEM_CHARIZARDITE_Y:
    case ITEM_ULTRANECROZIUM_Z:
    case ITEM_DEEP_SEA_SCALE:
    case ITEM_DEEP_SEA_TOOTH:
    case ITEM_NEVER_MELT_ICE:
    case ITEM_WEAKNESS_POLICY:
    case ITEM_SAFETY_GOGGLES:
    case ITEM_ADRENALINE_ORB:
    case ITEM_TERRAIN_EXTENDER:
    case ITEM_PROTECTIVE_PADS:
    case ITEM_HEAVY_DUTY_BOOTS:
    case ITEM_UTILITY_UMBRELLA:
    case ITEM_MARANGA_BERRY:
    case ITEM_PUNCHING_GLOVE:
    case ITEM_BOOSTER_ENERGY:
    case ITEM_ADAMANT_CRYSTAL:
    case ITEM_LUSTROUS_GLOBE:
    case ITEM_CORNERSTONE_MASK:
    case ITEM_WELLSPRING_MASK:
    case ITEM_HEARTHFLAME_MASK:
        EXPECT_GT(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
        break;
    default:
        EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
        break;
    }
}

TEST("Item names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 72;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemsInfo[i].importance) continue;
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    // All items explicitly listed here are too big to fit.
    switch (item)
    {
    case ITEM_UNREMARKABLE_TEACUP:
        EXPECT_GT(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
        break;
    default:
        EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
        break;
    }
}

TEST("Item names fit on Shop Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 84;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].name) { item = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].name, 0), widthPx);
}

TEST("Item descriptions fit on Bag and Shop Screen")
{
    u32 i;
    const u32 fontId = FONT_NORMAL, widthPx = 102;
    u32 item = ITEM_NONE;
    for (i = 1; i < ITEMS_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gItemsInfo[i].description) { item = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gItemsInfo[item].description, 0), widthPx);
}

TEST("Species names fit on Battle Screen HP box")
{
    u32 i, genderWidthPx;
    const u32 fontId = FONT_SMALL_NARROWER, widthPx = 55;
    u32 species = SPECIES_NONE;
    genderWidthPx = GetStringWidth(fontId, COMPOUND_STRING("♂"), 0);
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    if (gSpeciesInfo[i].genderRatio != MON_GENDERLESS)
        EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0) - genderWidthPx, widthPx);
    else
        EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Party Screen")
{
    u32 i;
    const u32 fontId = FONT_SMALL_NARROWER, widthPx = 50;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 63;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Pokedex Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 50;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Pokedex Screen - Cries")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Pokemon Storage System")
{
    u32 i;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(FONT_NARROWER, gSpeciesInfo[species].speciesName, 0), 66);
    EXPECT_LE(GetStringWidth(FONT_SHORT_NARROW, gSpeciesInfo[species].speciesName, 0), 60);
}

TEST("Species names fit on Contest Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 50;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Contest Screen - Rankings")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 49;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Battle Dome Screen")
{
    u32 i;
    const u32 fontId = FONT_SHORT_NARROW, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Hall of Fame")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 66;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Naming Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 64;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on PokeNav Condition Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 57;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on PokeNav Condition Search Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on PokeNav Ribbon Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on PokeNav Ribbon List Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 60;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species names fit on Battle Screen HP box for vanilla mons with the default font")
{
    u32 i, genderWidthPx;
    const u32 fontId = FONT_SMALL, widthPx = 55;
    u32 species = SPECIES_NONE;
    genderWidthPx = GetStringWidth(fontId, COMPOUND_STRING("♂"), 0);
    for (i = 1; i < SPECIES_TURTWIG; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    if (gSpeciesInfo[i].genderRatio != MON_GENDERLESS)
        EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0) - genderWidthPx, widthPx);
    else
        EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].speciesName, 0), widthPx);
}

TEST("Species dex entries fit on Pokedex Screen")
{
    u32 i;
    const u32 fontId = FONT_NORMAL, widthPx = 224;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].description) { species = i; }
        }
    }
    EXPECT_LE(GetStringWidth(fontId, gSpeciesInfo[species].description, 0), widthPx);
}

TEST("Ability names fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NORMAL, widthPx = 144;
    u32 ability = ABILITY_NONE;
    for (i = 1; i < ABILITIES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gAbilitiesInfo[i].name) { ability = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gAbilitiesInfo[ability].name, 0), widthPx);
}

TEST("Ability names fit on Ability Pop-Up")
{
    u32 i;
    const u32 fontId = FONT_SMALL_NARROWER, widthPx = 76;
    u32 ability = ABILITY_NONE;
    for (i = 1; i < ABILITIES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gAbilitiesInfo[i].name) { ability = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gAbilitiesInfo[ability].name, 0), widthPx);
}

TEST("Ability descriptions fit on Pokemon Summary Screen")
{
    u32 i;
    const u32 fontId = FONT_NORMAL, widthPx = 146;
    u32 ability = ABILITY_NONE;
    for (i = 1; i < ABILITIES_COUNT; i++)
    {
        PARAMETRIZE_LABEL("%S", gAbilitiesInfo[i].description) { ability = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gAbilitiesInfo[ability].description, 0), widthPx);
}

TEST("Type names fit on Battle Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 39;
    u32 type = TYPE_NORMAL;
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        PARAMETRIZE_LABEL("%S", gTypesInfo[i].name) { type = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gTypesInfo[type].name, 0), widthPx);
}

TEST("Type names fit on Pokedex Search Screen")
{
    u32 i;
    const u32 fontId = FONT_NARROWER, widthPx = 38;
    u32 type = TYPE_NORMAL;
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        PARAMETRIZE_LABEL("%S", gTypesInfo[i].name) { type = i; }
    }
    EXPECT_LE(GetStringWidth(fontId, gTypesInfo[type].name, 0), widthPx);
}

extern u16 sBattlerAbilities[MAX_BATTLERS_COUNT];
//*
TEST("Battle strings fit on the battle message window")
{
    u32 i, j, strWidth;
    u32 start = BATTLESTRINGS_TABLE_START;
    u32 end = BATTLESTRINGS_TABLE_START + 300;
    const u32 fontId = FONT_NORMAL, widthPx = 208;
    u32 battleStringId = 0;
    u8 battleString[1000] = {0};

    s32 sixDigitNines = 999999;
    u8 nickname[POKEMON_NAME_LENGTH + 1] = _("MMMMMMMMMMMM");
    u32 longMoveID = MOVE_STOMPING_TANTRUM;
    u32 longAbilityID = ABILITY_SUPERSWEET_SYRUP; // 91 pixels.
    u32 longStatName = STAT_EVASION;
    u32 longTypeName = TYPE_ELECTRIC;
    u32 longSpeciesName = SPECIES_SANDY_SHOCKS;   // 47 pixels
    u32 longItemName = ITEM_UNREMARKABLE_TEACUP;

    NewGameBirchSpeech_SetDefaultPlayerName(10);  // JOHNNY

    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_WOBBUFFET, 100;
        createmon 1, 0, SPECIES_WOBBUFFET, 100;
    );
    SetMonData(&gPlayerParty[0], MON_DATA_NICKNAME, nickname);
    SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, nickname);

    for (i = start; i <= end; i++) // BATTLESTRINGS_COUNT
    {
        PARAMETRIZE_LABEL("%S", gBattleStringsTable[i - BATTLESTRINGS_TABLE_START]) { battleStringId = i - BATTLESTRINGS_TABLE_START; }
    }
    PREPARE_STRING_BUFFER(gBattleTextBuff1, STRINGID_EMPTYSTRING3);
    PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_EMPTYSTRING3);
    PREPARE_STRING_BUFFER(gBattleTextBuff3, STRINGID_EMPTYSTRING3);
    gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;
    gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;
    gBattlerPositions[2] = B_POSITION_PLAYER_RIGHT;
    gBattlerPositions[3] = B_POSITION_OPPONENT_RIGHT;
    for (j = 0; j < MAX_BATTLERS_COUNT; j++)
    {
        sBattlerAbilities[j] = longAbilityID;
    }

    gTrainerBattleOpponent_A = 1;

    // Add "The opposing " prefix to all messages.
    gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
    gBattlerAttacker = 1;
    gBattlerTarget = 1;
    gBattleScripting.battler = 1;
    gEffectBattler = 1;

    gCurrentMove = longMoveID;
    gLastUsedItem = longItemName;

    gBattleMsgDataPtr = AllocZeroed(sizeof(struct BattleMsgData));
    gBattleMsgDataPtr->currentMove = longMoveID;

    switch (battleStringId + BATTLESTRINGS_TABLE_START)
    {
    case STRINGID_TRAINER1LOSETEXT:
        // Out of current scope: testing all trainer lose messages.
        break;
    case STRINGID_PKMNGAINEDEXP:
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, 0, 0);
        PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_ABOOSTED); // 'gained a boosted'
        PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff3, 6, sixDigitNines);
        break;
    case STRINGID_PKMNGREWTOLV:
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, 0, 0);
        PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 3, 100);
        break;
    case STRINGID_PKMNLEARNEDMOVE:
    case STRINGID_TRYTOLEARNMOVE1:
    case STRINGID_TRYTOLEARNMOVE2:
    case STRINGID_TRYTOLEARNMOVE3:
    case STRINGID_PKMNFORGOTMOVE:
    case STRINGID_STOPLEARNINGMOVE:
    case STRINGID_DIDNOTLEARNMOVE:
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, 0, 0);
        PREPARE_MOVE_BUFFER(gBattleTextBuff2, longMoveID);
        break;
    case STRINGID_PKMNLEARNEDMOVE2:
    case STRINGID_TEAMSTOPPEDWORKING: // Unused
    case STRINGID_FOESTOPPEDWORKING: // Unused
    case STRINGID_PKMNHURTBY:
    case STRINGID_PKMNFREEDFROM:
    case STRINGID_PKMNMOVEWASDISABLED:
    case STRINGID_PKMNSKETCHEDMOVE:
    case STRINGID_PKMNGOTFREE:
    case STRINGID_PKMNLOSTPPGRUDGE:
    case STRINGID_PKMNSITEMRESTOREDPP:
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, longMoveID);
        break;
    case STRINGID_PLAYERGOTMONEY:
    case STRINGID_PLAYERWHITEOUT2:
    case STRINGID_PLAYERPICKEDUPMONEY:
        PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff1, 6, sixDigitNines);
        break;
    case STRINGID_HITXTIMES:
    case STRINGID_MAGNITUDESTRENGTH:
        PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff1, 2, 99);
        break;
    case STRINGID_PKMNSTOCKPILED:
    case STRINGID_PKMNPERISHCOUNTFELL:
        PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff1, 1, 9);
        break;
    case STRINGID_PKMNMADESLEEP:
    case STRINGID_PKMNPOISONEDBY:
    case STRINGID_PKMNBURNEDBY:
    case STRINGID_PKMNFROZENBY:
    case STRINGID_PKMNWASPARALYZEDBY:
        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, longAbilityID);
        break;
    case STRINGID_STATSWONTINCREASE:
    case STRINGID_STATSWONTDECREASE:
    case STRINGID_PKMNSXPREVENTSYLOSS:
        StringCopy(gBattleTextBuff1, gStatNamesTable[longStatName]);
        break;
    case STRINGID_PKMNCHANGEDTYPE:
    case STRINGID_PKMNCHANGEDTYPEWITH:
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, longTypeName);
        break;
    case STRINGID_PKMNTRANSFORMEDINTO:
    case STRINGID_WILDPKMNFLED:
        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, longSpeciesName)
        break;
    case STRINGID_PKMNATTACK:
    case STRINGID_PKMNWISHCAMETRUE:
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, 1, 0);
        break;
    case STRINGID_ENEMYABOUTTOSWITCHPKMN:
        PREPARE_MON_NICK_BUFFER(gBattleTextBuff2, 1, 0);
        break;
    case STRINGID_PKMNHURTSWITH:
    case STRINGID_PKMNCURIOUSABOUTX:
    case STRINGID_PKMNENTHRALLEDBYX:
    case STRINGID_PKMNIGNOREDX:
        PREPARE_ITEM_BUFFER(gBattleTextBuff1, longItemName);
        break;
    case STRINGID_PKMNTRACED:
        PREPARE_MON_NICK_WITH_PREFIX_LOWER_BUFFER(gBattleTextBuff1, 1, 0);
        PREPARE_ABILITY_BUFFER(gBattleTextBuff2, longAbilityID);
        break;
    case STRINGID_ATTACKERSSTATROSE:
    case STRINGID_DEFENDERSSTATROSE:
        StringCopy(gBattleTextBuff1, gStatNamesTable[longStatName]);
        StringCopy(gBattleTextBuff2, sText_drastically);
        StringAppend(gBattleTextBuff2, gText_StatRose);
        break;
    case STRINGID_ATTACKERSSTATFELL:
    case STRINGID_DEFENDERSSTATFELL:
        StringCopy(gBattleTextBuff1, gStatNamesTable[longStatName]);
        StringCopy(gBattleTextBuff2, sText_severely);
        StringAppend(gBattleTextBuff2, sText_StatFell);
        break;
    case STRINGID_PKMNSITEMCUREDPROBLEM:
    case STRINGID_PKMNSXCUREDYPROBLEM:
        StringCopy(gBattleTextBuff1, gText_Paralysis);
        break;
    default:
        break;
    }
    memset(battleString, EOS, 1000);
    BattleStringExpandPlaceholders(gBattleStringsTable[battleStringId], battleString);
    DebugPrintf("Battle String ID %d: %S", battleStringId + BATTLESTRINGS_TABLE_START, battleString);
    for (j = 1;; j++)
    {
        strWidth = GetStringLineWidth(fontId, battleString, 0, j);
        if (strWidth == 0)
            break;
        EXPECT_LE(strWidth, widthPx);
    }
    Free(gBattleMsgDataPtr);
}
//*/
