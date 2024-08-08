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

        [SPECIES_MAPLAGE] =
    { 
       .baseHP        = 50,
       .baseAttack    = 50,
       .baseDefense   = 45,
       .baseSpeed     = 70,
       .baseSpAttack  = 60,
       .baseSpDefense = 45,
       .types = { TYPE_GRASS, TYPE_FAIRY },
       .catchRate = 3,
       .expYield = 67,
       .evYield_SpAttack  = 3,
       .genderRatio = PERCENT_FEMALE(12.5),
       .eggCycles = 120,
       .friendship = 50,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_FAIRY },
       .abilities = { ABILITY_OVERGROW, ABILITY_TECHNICIAN, ABILITY_SHARPNESS, ABILITY_NONE },
       .bodyColor = BODY_COLOR_GREEN,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Maplage"),
       .cryId = CRY_MAPLAGE,
       .natDexNum = NATIONAL_DEX_MAPLAGE,
       .categoryName = _("Leaf"),
       .height = 15,
       .weight = 330,
       .description = COMPOUND_STRING(
           "A docile and shy species, Maplage waft\n"
           "into the air to escape attacks, not by\n"
           "wind, but by an odd magical power."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Maplage,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Maplage,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Maplage,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Maplage,
       .shinyPalette = gMonShinyPalette_Maplage,
       .iconSprite = gMonIcon_Maplage,
       .iconPalIndex = 1,
       FOOTPRINT(Maplage)
       .levelUpLearnset = sMaplageLevelUpLearnset,
    },

        [SPECIES_ARACHNOTE] =
    { 
       .baseHP        = 67,
       .baseAttack    = 80,
       .baseDefense   = 62,
       .baseSpeed     = 101,
       .baseSpAttack  = 107,
       .baseSpDefense = 60,
       .types = { TYPE_BUG, TYPE_NORMAL },
       .catchRate = 73,
       .expYield = 148,
       .evYield_SpAttack  = 1,
       .evYield_Speed  = 1,
       .genderRatio = PERCENT_FEMALE(50),
       .eggCycles = 120,
       .friendship = 50,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_NO_EGGS_DISCOVERED },
       .abilities = { ABILITY_SOUNDPROOF, ABILITY_BOOMBOX, ABILITY_SWARM, ABILITY_UNNERVE },
       .bodyColor = BODY_COLOR_WHITE,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Arachnote"),
       .natDexNum = NATIONAL_DEX_ARACHNOTE,
       .categoryName = _("Otamatone"),
       .height = 15,
       .weight = 330,
       .description = COMPOUND_STRING(
           "A frequent night walker, it can be\n"
           "picked up and squeezed to emit an\n"
           "oddly melodic and soothing sound."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Arachnote,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Arachnote,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Arachnote,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Arachnote,
       .shinyPalette = gMonShinyPalette_Arachnote,
       .iconSprite = gMonIcon_Arachnote,
       .iconPalIndex = 2,
       FOOTPRINT(Arachnote)
       .levelUpLearnset = sArachnoteLevelUpLearnset,
    },

        [SPECIES_FUCKER] =
    { 
       .baseHP        = 65,
       .baseAttack    = 125,
       .baseDefense   = 80,
       .baseSpeed     = 90,
       .baseSpAttack  = 45,
       .baseSpDefense = 60,
       .types = { TYPE_FIGHTING, TYPE_FIGHTING },
       .catchRate = 35,
       .expYield = 148,
       .evYield_Attack  = 3,
       .genderRatio = PERCENT_FEMALE(12.5),
       .eggCycles = 120,
       .friendship = 50,
       .growthRate = GROWTH_MEDIUM_FAST,
       .eggGroups = {EGG_GROUP_FLYING, EGG_GROUP_WATER_2},
       .abilities = { ABILITY_IRON_FIST, ABILITY_NONE, ABILITY_SCRAPPY, ABILITY_SWIFT_SWIM },
       .bodyColor = BODY_COLOR_BROWN,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Fucker"),
       .natDexNum = NATIONAL_DEX_FUCKER,
       .categoryName = _("Fish Duck"),
       .height = 15,
       .weight = 330,
       .description = COMPOUND_STRING(
           "What the fuck is this? What would\n"
           "you even call this thing? A dish? A\n"
           "ofuck? A fighter? A fucker? A fucker."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Fucker,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Fucker,
       .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
       .frontAnimDelay = 10,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Fucker,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Fucker,
       .shinyPalette = gMonShinyPalette_Fucker,
       .iconSprite = gMonIcon_Fucker,
       .iconPalIndex = 2,
       FOOTPRINT(Fucker)
       .levelUpLearnset = sFuckerLevelUpLearnset,
    },

    /* You may add any custom species below this point based on the following structure: */

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
