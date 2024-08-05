#include "constants/abilities.h"
#include "species_info/shared_dex_text.h"

// Macros for ease of use.

#define EVOLUTION(...) (const struct Evolution[]) { __VA_ARGS__, { EVOLUTIONS_END }, }

#if P_FOOTPRINTS
#define FOOTPRINT(sprite) .footprint = gMonFootprint_## sprite,
#else
#define FOOTPRINT(sprite)
#endif

#define SIZE_32x32 1
#define SIZE_64x64 0

// Set .compressed = OW_GFX_COMPRESS
#define COMP OW_GFX_COMPRESS

#if OW_POKEMON_OBJECT_EVENTS
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
#define OVERWORLD_PAL(...)                                  \
    .overworldPalette = DEFAULT(NULL, __VA_ARGS__),         \
    .overworldShinyPalette = DEFAULT_2(NULL, __VA_ARGS__),
#else
#define OVERWORLD_PAL(...)
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE

#define OVERWORLD(picTable, _size, shadow, _tracks, ...)                                    \
.overworldData = {                                                                          \
    .tileTag = TAG_NONE,                                                                    \
    .paletteTag = OBJ_EVENT_PAL_TAG_DYNAMIC,                                                \
    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,                                         \
    .size = (_size == SIZE_32x32 ? 512 : 2048),                                             \
    .width = (_size == SIZE_32x32 ? 32 : 64),                                               \
    .height = (_size == SIZE_32x32 ? 32 : 64),                                              \
    .paletteSlot = PALSLOT_NPC_1,                                                           \
    .shadowSize = shadow,                                                                   \
    .inanimate = FALSE,                                                                     \
    .compressed = COMP,                                                                     \
    .tracks = _tracks,                                                                      \
    .oam = (_size == SIZE_32x32 ? &gObjectEventBaseOam_32x32 : &gObjectEventBaseOam_64x64), \
    .subspriteTables = (_size == SIZE_32x32 ? sOamTables_32x32 : sOamTables_64x64),         \
    .anims = sAnimTable_Following,                                                          \
    .images = picTable,                                                                     \
    .affineAnims = gDummySpriteAffineAnimTable,                                             \
},                                                                                          \
    OVERWORLD_PAL(__VA_ARGS__)
#else
#define OVERWORLD(picTable, _size, shadow, _tracks, ...)
#endif //OW_POKEMON_OBJECT_EVENTS

// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

#define MON_TYPES(type1, ...) { type1, DEFAULT(type1, __VA_ARGS__) }
#define MON_EGG_GROUPS(group1, ...) { group1, DEFAULT(group1, __VA_ARGS__) }

#define FLIP    0
#define NO_FLIP 1

#if POKEMON_NAME_LENGTH >= 12
#define HANDLE_EXPANDED_SPECIES_NAME(_name, ...) _(DEFAULT(_name, __VA_ARGS__))
#else
#define HANDLE_EXPANDED_SPECIES_NAME(_name, ...) _(_name)
#endif

const struct SpeciesInfo gSpeciesInfo[] =
{
    [SPECIES_NONE] =
    {
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = gFallbackPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_None,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        FOOTPRINT(QuestionMark)
    #if OW_POKEMON_OBJECT_EVENTS
        .overworldData = {
            .tileTag = TAG_NONE,
            .paletteTag = OBJ_EVENT_PAL_TAG_SUBSTITUTE,
            .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,
            .size = 512,
            .width = 32,
            .height = 32,
            .paletteSlot = PALSLOT_NPC_1,
            .shadowSize = SHADOW_SIZE_M,
            .inanimate = FALSE,
            .compressed = COMP,
            .tracks = TRACKS_FOOT,
            .oam = &gObjectEventBaseOam_32x32,
            .subspriteTables = sOamTables_32x32,
            .anims = sAnimTable_Following,
            .images = sPicTable_Substitute,
            .affineAnims = gDummySpriteAffineAnimTable,
        },
    #endif
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .eggMoveLearnset = sNoneEggMoveLearnset,
    },

    #include "species_info/gen_1_families.h"
    #include "species_info/gen_2_families.h"
    #include "species_info/gen_3_families.h"
    #include "species_info/gen_4_families.h"
    #include "species_info/gen_5_families.h"
    #include "species_info/gen_6_families.h"
    #include "species_info/gen_7_families.h"
    #include "species_info/gen_8_families.h"
    #include "species_info/gen_9_families.h"

    [SPECIES_EGG] =
    {
        .frontPic = gMonFrontPic_Egg,
        .frontPicSize = MON_COORDS_SIZE(24, 24),
        .frontPicYOffset = 20,
        .backPic = gMonFrontPic_Egg,
        .backPicSize = MON_COORDS_SIZE(24, 24),
        .backPicYOffset = 20,
        .palette = gMonPalette_Egg,
        .shinyPalette = gMonPalette_Egg,
        .iconSprite = gMonIcon_Egg,
        .iconPalIndex = 1,
    },

    /* You may add any custom species below this point based on the following structure: */
[SPECIES_ALT_ABSOL] =
    {
        .baseHP        = 65,
        .baseAttack    = 140,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 110,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_DARK, TYPE_DRAGON),
        .catchRate = 30,
        .expYield = 180,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SUPER_LUCK, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_WHITE,
	    .noFlip = TRUE,
        .speciesName = _("ALT ABSOL"),
        .cryId = CRY_ALTABSOL,
        .natDexNum = NATIONAL_DEX_ALT_ABSOL,
        .categoryName = _("Disaster"),
        .height = 12,
        .weight = 490,
        .description = COMPOUND_STRING(
            "It sharply senses even subtle changes in\n"
            "the sky and the land to predict disasters.\n"
            "It is an Altered Pokémon that has changed\n"
            "types and evolved into something more."),
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AltAbsol,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_AltAbsol,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AltAbsol,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_AltAbsol,
        .shinyPalette = gMonShinyPalette_AltAbsol,
        .iconSprite = gMonIcon_AltAbsol,
        .iconPalIndex = 0,
        FOOTPRINT(AltAbsol)
        .levelUpLearnset = sAltAbsolLevelUpLearnset,
        .teachableLearnset = sAltAbsolTeachableLearnset,
        .eggMoveLearnset = sAltAbsolEggMoveLearnset,
    },

[SPECIES_ALT_LAPRAS] =
    {
        .baseHP        = 135,
        .baseAttack    = 85,
        .baseDefense   = 90,
        .baseSpeed     = 50,
        .baseSpAttack  = 85,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_POISON, TYPE_ICE),
        .catchRate = 45,
        .expYield = 187,
        .evYield_HP = 2,
        .itemCommon = ITEM_BLACK_SLUDGE,
        .itemRare = ITEM_POISON_GEM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_POISON_POINT, ABILITY_SHELL_ARMOR, ABILITY_CORROSION },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Alt Lapras"),
        .cryId = CRY_ALTLAPRAS,
        .natDexNum = NATIONAL_DEX_ALT_LAPRAS,
        .categoryName = _("Pollution"),
        .height = 25,
        .weight = 2200,
        .description = COMPOUND_STRING(
            "People have feared riding it due to poison.\n"
            "It’s also known to have a cold personality.\n"
            "It is an Altered Pokémon that has changed\n"
            "types and evolved into something more."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_AltLapras,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_AltLapras,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_AltLapras,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_AltLapras,
        .shinyPalette = gMonShinyPalette_AltLapras,
        .iconSprite = gMonIcon_AltLapras,
        .iconPalIndex = 2,
        FOOTPRINT(AltLapras)
        .levelUpLearnset = sAltLaprasLevelUpLearnset,
        .teachableLearnset = sAltLaprasTeachableLearnset,
        .eggMoveLearnset = sAltLaprasEggMoveLearnset,
},

#if P_FAMILY_ALT_RALTS
 [SPECIES_ALT_RALTS] =
    {
        .baseHP        = 30,
        .baseAttack    = 25,
        .baseDefense   = 30,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_DARK),
        .catchRate = 235,
        .expYield = 70,
        .evYield_SpAttack = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE, EGG_GROUP_FIELD),
        .abilities = { ABILITY_TRACE, ABILITY_BERSERK, ABILITY_SYNCHRONIZE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Alt Ralts"),
        .cryId = CRY_ALTRALTS,
        .natDexNum = NATIONAL_DEX_ALT_RALTS,
        .categoryName = _("Dark Spirit"),
        .height = 4,
        .weight = 66,
        .description = COMPOUND_STRING(
            "A twisted Pokémon that has the power to\n"
            "alter emotions of people and Pokémon near.\n"
            "It is an Altered Pokémon that has changed\n"
            "types and evolved into something more."),
        .pokemonScale = 457,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AltRalts,
        .frontPicSize = MON_COORDS_SIZE(24, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_AltRalts,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_AltRalts,
        .backPicSize = MON_COORDS_SIZE(32, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_AltRalts,
        .shinyPalette = gMonShinyPalette_AltRalts,
        .iconSprite = gMonIcon_AltRalts,
        .iconPalIndex = 1,
        FOOTPRINT(AltRalts)
        .levelUpLearnset = sAltRaltsLevelUpLearnset,
        .teachableLearnset = sAltRaltsTeachableLearnset,
        .eggMoveLearnset = sAltRaltsEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_ALT_KIRLIA}),
    },


    [SPECIES_ALT_KIRLIA] =
    {
        .baseHP        = 50,
        .baseAttack    = 35,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_DARK),
        .catchRate = 120,
        .expYield = 140,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE, EGG_GROUP_FIELD),
        .abilities = { ABILITY_TRACE, ABILITY_BERSERK, ABILITY_SYNCHRONIZE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Alt Kirlia"),
        .cryId = CRY_ALTKIRLIA,
        .natDexNum = NATIONAL_DEX_ALT_KIRLIA,
        .categoryName = _("Dark Witch"),
        .height = 8,
        .weight = 202,
        .description = COMPOUND_STRING(
            "It has dark psychic power to create a\n"
            "rip in the dimensions and see calamities.\n"
            "It is an Altered Pokémon that has changed\n"
            "types and evolved into something more."),
        .pokemonScale = 354,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AltKirlia,
        .frontPicSize = MON_COORDS_SIZE(32, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_AltKirlia,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AltKirlia,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_AltKirlia,
        .shinyPalette = gMonShinyPalette_AltKirlia,
        .iconSprite = gMonIcon_AltKirlia,
        .iconPalIndex = 1,
        FOOTPRINT(AltKirlia)
        .levelUpLearnset = sAltKirliaLevelUpLearnset,
        .teachableLearnset = sAltKirliaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_ALT_GARDEVOIR}),
    },


    [SPECIES_ALT_GARDEVOIR] =
    {
        .baseHP        = 100,
        .baseAttack    = 60,
        .baseDefense   = 85,
        .baseSpeed     = 95,
        .baseSpAttack  = 140,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_DARK),
        .catchRate = 45,
        .expYield = 259,
        .evYield_SpAttack = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE, EGG_GROUP_FIELD),
        .abilities = { ABILITY_TRACE, ABILITY_BERSERK, ABILITY_QUEENLY_MAJESTY },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("AltGardvir"),
        .cryId = CRY_ALTGARDEVOIR,
        .natDexNum = NATIONAL_DEX_ALT_GARDEVOIR,
        .categoryName = _("Dark Queen"),
        .height = 16,
        .weight = 484,
        .description = COMPOUND_STRING(
            "It does not feel many emotions. But it\n"
            "will destroy everything for their trainer.\n"
            "It is an Altered Pokémon that has changed\n"
            "types and evolved into something more."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AltGardevoir,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_AltGardevoir,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_AltGardevoir,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_AltGardevoir,
        .shinyPalette = gMonShinyPalette_AltGardevoir,
        .iconSprite = gMonIcon_AltGardevoir,
        .iconPalIndex = 1,
        FOOTPRINT(AltGardevoir)
        .levelUpLearnset = sAltGardevoirLevelUpLearnset,
        .teachableLearnset = sAltGardevoirTeachableLearnset,
    },
#endif //P_FAMILY_ALT_RALTS

#if P_FAMILY_MISSINGNO
    [SPECIES_MISSINGNO] =
    {
        .baseHP        = 178,
        .baseAttack    = 136,
        .baseDefense   = 80,
        .baseSpeed     = 46,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FLYING, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 300,
        .evYield_Attack = 3,
        .itemCommon = ITEM_ENIGMA_BERRY,
        .itemRare = ITEM_LUXURY_BALL,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SHADOW_TAG, ABILITY_NEUTRALIZING_GAS, ABILITY_AERILATE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("MissingNo"),
        .cryId = CRY_MISSINGNO,
        .natDexNum = NATIONAL_DEX_MISSINGNO,
        .categoryName = _("Glitch Bird"),
        .height = 32,
        .weight = 9999,
        .description = COMPOUND_STRING(
            "A Pokémon created from corrupted data.\n"
            "It was capable of corrupting any system.\n"
            "However as time went on it stabalized.\n"
            "It’s subject to horror stories of old."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Missingno,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Missingno,
        .frontAnimId = ANIM_SHRINK_GROW,
        .enemyMonElevation = 13,
        .backPic = gMonBackPic_Missingno,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Missingno,
        .shinyPalette = gMonShinyPalette_Missingno,
        .iconSprite = gMonIcon_Missingno,
        .iconPalIndex = 2,
        FOOTPRINT(Missingno)
        .isMythical = TRUE,
        .levelUpLearnset = sMissingnoLevelUpLearnset,
        .teachableLearnset = sMissingnoTeachableLearnset,
    },
#endif //P_FAMILY_MISSINGNO

    /*
    [SPECIES_NONE] =
    {
        .baseHP        = 1,
        .baseAttack    = 1,
        .baseDefense   = 1,
        .baseSpeed     = 1,
        .baseSpAttack  = 1,
        .baseSpDefense = 1,
        .types = MON_TYPES(TYPE_MYSTERY),
        .catchRate = 255,
        .expYield = 67,
        .evYield_HP = 1,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NONE, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        //.frontPicFemale = gMonFrontPic_CircledQuestionMark,
        //.frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_None,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        //.backPicFemale = gMonBackPic_CircledQuestionMarkF,
        //.backPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        //.paletteFemale = gMonPalette_CircledQuestionMarkF,
        .shinyPaletteFemale = gMonShinyPalette_CircledQuestionMarkF,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        //.iconSpriteFemale = gMonIcon_QuestionMarkF,
        //.iconPalIndexFemale = 1,
        FOOTPRINT(QuestionMark)
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 100, SPECIES_NONE},
                                {EVO_ITEM, ITEM_MOOMOO_MILK, SPECIES_NONE}),
        //.formSpeciesIdTable = sNoneFormSpeciesIdTable,
        //.formChangeTable = sNoneFormChangeTable,
        .allPerfectIVs = TRUE,
    },
    */
};
