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
       .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_TECHNICIAN, ABILITY_SHARPNESS },
       .bodyColor = BODY_COLOR_GREEN,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Maplage"),
       .cryId = CRY_MAPLAGE,
       .natDexNum = NATIONAL_DEX_MAPLAGE,
       .categoryName = _("Leaf"),
       .height = 4,
       .weight = 14,
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
       .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_HAZELNAUT}),
    },

        [SPECIES_HAZELNAUT] =
    { 
       .baseHP        = 60,
       .baseAttack    = 85,
       .baseDefense   = 50,
       .baseSpeed     = 100,
       .baseSpAttack  = 80,
       .baseSpDefense = 50,
       .types = { TYPE_GRASS, TYPE_FAIRY },
       .catchRate = 3,
       .expYield = 97,
       .evYield_SpAttack  = 3,
       .genderRatio = PERCENT_FEMALE(12.5),
       .eggCycles = 120,
       .friendship = 50,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_FAIRY },
       .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_TECHNICIAN, ABILITY_SHARPNESS },
       .bodyColor = BODY_COLOR_GREEN,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Hazelnaut"),
       .cryId = CRY_HAZELNAUT,
       .natDexNum = NATIONAL_DEX_HAZELNAUT,
       .categoryName = _("Squire"),
       .height = 8,
       .weight = 212,
       .description = COMPOUND_STRING(
           "It hones its blade against the bark of \n"
           "the edge is pristine and sharp, Hazelnaut\n"
           "can be seen quite frequently sparring with\n"
           "one another."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Hazelnaut,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Hazelnaut,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Hazelnaut,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Hazelnaut,
       .shinyPalette = gMonShinyPalette_Hazelnaut,
       .iconSprite = gMonIcon_Hazelnaut,
       .iconPalIndex = 1,
       FOOTPRINT(Hazelnaut)
       .levelUpLearnset = sHazelnautLevelUpLearnset,
       .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GINOCCHIO}),
       },

        [SPECIES_GINOCCHIO] =
    { 
       .baseHP        = 65,
       .baseAttack    = 110,
       .baseDefense   = 70,
       .baseSpeed     = 115,
       .baseSpAttack  = 110,
       .baseSpDefense = 60,
       .types = { TYPE_GRASS, TYPE_FAIRY },
       .catchRate = 3,
       .expYield = 157,
       .evYield_SpAttack  = 3,
       .genderRatio = PERCENT_FEMALE(12.5),
       .eggCycles = 120,
       .friendship = 76,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_FAIRY },
       .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_TECHNICIAN, ABILITY_SKILL_LINK },
       .bodyColor = BODY_COLOR_GREEN,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Ginocchio"),
       .cryId = CRY_GINOCCHIO,
       .natDexNum = NATIONAL_DEX_GINOCCHIO,
       .categoryName = _("Battlemaster"),
       .height = 16,
       .weight = 600,
       .description = COMPOUND_STRING(
           "Ginocchio are often seen wandering alone \n"
           "and aimless like a hermit, appearing to \n"
           "be lost.Its wooden skin allows it to easily\n"
           "lurk within trees."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Ginocchio,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Ginocchio,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Ginocchio,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Ginocchio,
       .shinyPalette = gMonShinyPalette_Ginocchio,
       .iconSprite = gMonIcon_Ginocchio,
       .iconPalIndex = 1,
       FOOTPRINT(Ginocchio)
       .levelUpLearnset = sGinocchioLevelUpLearnset,
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
      .cryId = CRY_ARACHNOTE,
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
       .iconPalIndex = 0,
       FOOTPRINT(Arachnote)
       .levelUpLearnset = sArachnoteLevelUpLearnset,
    },

        [SPECIES_KRACKODEMON] =
    { 
       .baseHP        = 109,
       .baseAttack    = 73,
       .baseDefense   = 64,
       .baseSpeed     = 69,
       .baseSpAttack  = 142,
       .baseSpDefense = 90,
       .types = { TYPE_ELECTRIC, TYPE_DARK },
       .catchRate = 54,
       .expYield = 148,
       .evYield_SpAttack  = 1,
       .evYield_Speed  = 1,
       .genderRatio = PERCENT_FEMALE(50),
       .eggCycles = 120,
       .friendship = 50,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_AMORPHOUS },
       .abilities = { ABILITY_CLOUD_NINE, ABILITY_LEVITATE, ABILITY_SHOWER_POWER, ABILITY_IRON_BARBS }, 
       .bodyColor = BODY_COLOR_BLACK,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Krackodemon"),
      .cryId = CRY_KRACKODEMON,
       .natDexNum = NATIONAL_DEX_KRACKODEMON,
       .categoryName = _("Storm Cloud"),
       .height = 31,
       .weight = 6666,
       .description = COMPOUND_STRING(
           "It is unknown if Krackodemon cause storms\n"
           "or merely wander into them. Researchers\n"
           "cannot determine this even with assistance\n"
           "from Cyclonian."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Krackodemon,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Krackodemon,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 4,
       .backPic = gMonBackPic_Krackodemon,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Krackodemon,
       .shinyPalette = gMonShinyPalette_Krackodemon,
       .iconSprite = gMonIcon_Krackodemon,
       .iconPalIndex = 0,
       FOOTPRINT(Krackodemon)
       .levelUpLearnset = sKrackodemonLevelUpLearnset,
    },
        [SPECIES_YUUKIINO] =
    { 
       .baseHP        = 80,
       .baseAttack    = 50,
       .baseDefense   = 50,
       .baseSpeed     = 70,
       .baseSpAttack  = 90,
       .baseSpDefense = 140,
       .types = { TYPE_ICE, TYPE_ICE },
       .catchRate = 80,
       .expYield = 88,
       .evYield_SpDefense  = 3,
       .genderRatio = PERCENT_FEMALE(100),
       .eggCycles = 120,
       .friendship = 10,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_MINERAL },
       .abilities = { ABILITY_OVERCOAT, ABILITY_OBLIVIOUS, ABILITY_MINUS, ABILITY_QUEENLY_MAJESTY },
       .bodyColor = BODY_COLOR_WHITE,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Yuukiino"),
       .cryId = CRY_YUUKIINO,
       .natDexNum = NATIONAL_DEX_YUUKIINO,
       .categoryName = _("Cold Hearted"),
       .height = 14,
       .weight = 1117,
       .description = COMPOUND_STRING(
           "Locked away in their chilling crystaline \n"
           "bodies is a bitter black heart that trusts\n"
           "a single soul. Anything that approaches \n"
           "it too quickly may get encased in ice."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Yuukiino,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Yuukiino,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Yuukiino,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Yuukiino,
       .shinyPalette = gMonShinyPalette_Yuukiino,
       .iconSprite = gMonIcon_Yuukiino,
       .iconPalIndex = 2,
       FOOTPRINT(Yuukiino)
       .levelUpLearnset = sYuukiinoLevelUpLearnset,
       .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_AQUADIIVA}),
    },
    
        [SPECIES_AQUADIIVA] =
    { 
       .baseHP        = 80,
       .baseAttack    = 62,
       .baseDefense   = 88,
       .baseSpeed     = 77,
       .baseSpAttack  = 121,
       .baseSpDefense = 112,
       .types = { TYPE_WATER, TYPE_WATER },
       .catchRate = 50,
       .expYield = 180,
       .evYield_SpDefense  = 3,
       .genderRatio = PERCENT_FEMALE(100),
       .eggCycles = 120,
       .friendship = 190,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_MINERAL },
       .abilities = { ABILITY_NATURAL_CURE, ABILITY_IMMUNITY, ABILITY_PLUS, ABILITY_SUPPORTIVE}, 
       .bodyColor = BODY_COLOR_BLUE,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Aquadiiva"),
       .cryId = CRY_AQUADIIVA,
       .natDexNum = NATIONAL_DEX_AQUADIIVA,
       .categoryName = _("Embracing"),
       .height = 15,
       .weight = 945,
       .description = COMPOUND_STRING(
           "Their bodies emanate a warmth that\n"
           "always brightens the mood of anyone\n"
           "that sees it. When excited, the water\n"
           "on its body shimmers with blue light."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Aquadiiva,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Aquadiiva,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Aquadiiva,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Aquadiiva,
       .shinyPalette = gMonShinyPalette_Aquadiiva,
       .iconSprite = gMonIcon_Aquadiiva,
       .iconPalIndex = 2,
       FOOTPRINT(Aquadiiva)
       .levelUpLearnset = sAquadiivaLevelUpLearnset,
    },
        [SPECIES_PARMIAUSAN] =
    { 
       .baseHP        = 115,
       .baseAttack    = 80,
       .baseDefense   = 72,
       .baseSpeed     = 105,
       .baseSpAttack  = 50,
       .baseSpDefense = 72,
       .types = { TYPE_NORMAL, TYPE_NORMAL },
       .catchRate = 90,
       .expYield = 106,
       .evYield_HP  = 2,
       .genderRatio = PERCENT_FEMALE(50),
       .eggCycles = 160,
       .friendship = 100,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FIELD },
       .abilities = { ABILITY_AROMA_VEIL, ABILITY_PICKUP, ABILITY_UNAWARE, ABILITY_CUTE_CHARM}, 
       .bodyColor = BODY_COLOR_YELLOW,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Parmiausan"),
       .cryId = CRY_PARMIAUSAN,
       .natDexNum = NATIONAL_DEX_PARMIAUSAN,
       .categoryName = _("Parmesan"),
       .height = 5,
       .weight = 50,
       .description = COMPOUND_STRING(
           "Parmiausan's thick, high-quality skin can\n"
           "be endlessly grated for cheese without it\n"
           "feeling pain. This has lead to it being\n"
           "hunted by cheese factories."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Parmiausan,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Parmiausan,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Parmiausan,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 4,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Parmiausan,
       .shinyPalette = gMonShinyPalette_Parmiausan,
       .iconSprite = gMonIcon_Parmiausan,
       .iconPalIndex = 0,
       FOOTPRINT(Parmiausan)
       .levelUpLearnset = sParmiausanLevelUpLearnset,
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
       .catchRate = 65,
       .expYield = 148,
       .evYield_Attack  = 3,
       .genderRatio = PERCENT_FEMALE(12.5),
       .eggCycles = 100,
       .friendship = 60,
       .growthRate = GROWTH_MEDIUM_FAST,
       .eggGroups = {EGG_GROUP_FLYING, EGG_GROUP_WATER_2},
       .abilities = { ABILITY_IRON_FIST, ABILITY_NONE, ABILITY_SCRAPPY, ABILITY_SWIFT_SWIM },
       .bodyColor = BODY_COLOR_BROWN,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Fucker"),
      .cryId = CRY_FUCKER,
       .natDexNum = NATIONAL_DEX_FUCKER,
       .categoryName = _("Fish Duck"),
       .height = 8,
       .weight = 212,
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
       .iconPalIndex = 5,
       FOOTPRINT(Fucker)
       OVERWORLD(
            sPicTable_Fucker,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Fucker,
            gShinyOverworldPalette_Fucker
        )
       .levelUpLearnset = sFuckerLevelUpLearnset,
    },

        [SPECIES_NOXILIUM] =
    { 
       .baseHP        = 65,
       .baseAttack    = 110,
       .baseDefense   = 70,
       .baseSpeed     = 115,
       .baseSpAttack  = 110,
       .baseSpDefense = 60,
       .types = { TYPE_GHOST, TYPE_FLYING },
       .catchRate = 55,
       .expYield = 183,
       .evYield_SpAttack  = 3,
       .genderRatio = PERCENT_FEMALE(50),
       .eggCycles = 180,
       .friendship = 40,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_NONE },
       .abilities = { ABILITY_CURSED_BODY, ABILITY_BERSERK, ABILITY_NO_GUARD, ABILITY_DELTA_STREAM },
       .bodyColor = BODY_COLOR_PURPLE,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Noxilium"),
       .cryId = CRY_NOXILIUM,
       .natDexNum = NATIONAL_DEX_NOXILIUM,
       .categoryName = _("Mola Gay"),
       .height = 21,
       .weight = 400,
       .description = COMPOUND_STRING(
           "It is said that those who see Noxilium\n"
           "go insane unable to comprehend the meaning\n"
           "behind it and the book that it carries.\n"),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Noxilium,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Noxilium,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 2,
       .backPic = gMonBackPic_Noxilium,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Noxilium,
       .shinyPalette = gMonShinyPalette_Noxilium,
       .iconSprite = gMonIcon_Noxilium,
       .iconPalIndex = 5,
       FOOTPRINT(Noxilium)
       .levelUpLearnset = sNoxiliumLevelUpLearnset,
    },
    
        [SPECIES_DUBSNAKE] =
    { 
       .baseHP        = 62,
       .baseAttack    = 42,
       .baseDefense   = 62,
       .baseSpeed     = 22,
       .baseSpAttack  = 72,
       .baseSpDefense = 52,
       .types = { TYPE_ICE, TYPE_POISON },
       .catchRate = 99,
       .expYield = 77,
       .evYield_SpDefense  = 1,
       .genderRatio = PERCENT_FEMALE(50),
       .eggCycles = 150,
       .friendship = 30,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_MONSTER },
       .abilities = { ABILITY_COMPETITIVE, ABILITY_ANGER_POINT, ABILITY_ICE_BODY, ABILITY_POISON_POINT },
       .bodyColor = BODY_COLOR_GRAY,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Dubsnake"),
       .cryId = CRY_DUBSNAKE,
       .natDexNum = NATIONAL_DEX_DUBSNAKE,
       .categoryName = _("Rivalry"),
       .height = 14,
       .weight = 1117,
       .description = COMPOUND_STRING(
           "Its two heads don't get along. They spend\n"
           "much of their time slithering in opposite\n"
           "directions, going nowhere. However,\n"
           "predators still have a hard time getting it."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Dubsnake,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Dubsnake,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Dubsnake,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Dubsnake,
       .shinyPalette = gMonShinyPalette_Dubsnake,
       .iconSprite = gMonIcon_Dubsnake,
       .iconPalIndex = 0,
       FOOTPRINT(Dubsnake)
       .levelUpLearnset = sDubsnakeLevelUpLearnset,
       .evolutions = EVOLUTION({EVO_MOVE, MOVE_FLAME_BURST, SPECIES_HYDROIL})
    },
        [SPECIES_HYDROIL] =
    { 
       .baseHP        = 92,
       .baseAttack    = 82,
       .baseDefense   = 102,
       .baseSpeed     = 42,
       .baseSpAttack  = 112,
       .baseSpDefense = 92,
       .types = { TYPE_WATER, TYPE_FIRE },
       .catchRate = 47,
       .expYield = 200,
       .evYield_Defense  = 2,
       .evYield_SpAttack  = 2,
       .genderRatio = PERCENT_FEMALE(50),
       .eggCycles = 120,
       .friendship = 190,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_MONSTER },
       .abilities = { ABILITY_COMPETITIVE, ABILITY_ANGER_POINT, ABILITY_DRIZZLE, ABILITY_DROUGHT}, 
       .bodyColor = BODY_COLOR_BLUE,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Hydroil"),
       .cryId = CRY_HYDROIL,
       .natDexNum = NATIONAL_DEX_HYDROIL,
       .categoryName = _("Competitive"),
       .height = 22,
       .weight = 2222,
       .description = COMPOUND_STRING(
           "Its two heads fight each other more than\n"
           "fight their opponent. But it still usually \n"
           "has the upper hand, since their bickering\n"
           "flings hot oil, boiling water, and steam."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Hydroil,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Hydroil,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Hydroil,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Hydroil,
       .shinyPalette = gMonShinyPalette_Hydroil,
       .iconSprite = gMonIcon_Hydroil,
       .iconPalIndex = 0,
       FOOTPRINT(Hydroil)
       .levelUpLearnset = sHydroilLevelUpLearnset,
    },
        [SPECIES_BEAREDAZE] =
    { 
       .baseHP        = 75,
       .baseAttack    = 90,
       .baseDefense   = 65,
       .baseSpeed     = 55,
       .baseSpAttack  = 45,
       .baseSpDefense = 45,
       .types = { TYPE_NORMAL, TYPE_FIGHTING },
       .catchRate = 70,
       .expYield = 84,
       .evYield_Attack  = 1,
       .genderRatio = PERCENT_FEMALE(50),
       .eggCycles = 120,
       .friendship = 190,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_FIELD },
       .abilities = { ABILITY_DEFIANT, ABILITY_NONE, ABILITY_IRON_FIST, ABILITY_UNSEEN_FIST}, 
       .bodyColor = BODY_COLOR_YELLOW,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Bearedaze"),
       .cryId = CRY_BEAREDAZE,
       .natDexNum = NATIONAL_DEX_BEAREDAZE,
       .categoryName = _("Star"),
       .height = 6,
       .weight = 120,
       .description = COMPOUND_STRING(
           "Although Beardaze are normally docile,\n"
           "they have the power to pummel any foe if\n"
           "provoked.\n"),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Bearedaze,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Bearedaze,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Bearedaze,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 11,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Bearedaze,
       .shinyPalette = gMonShinyPalette_Bearedaze,
       .iconSprite = gMonIcon_Bearedaze,
       .iconPalIndex = 2,
       FOOTPRINT(Bearedaze)
       .levelUpLearnset = sBearedazeLevelUpLearnset,
       .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_KUMATARO}),
    },
        [SPECIES_KUMATARO] =
    { 
       .baseHP        = 80,
       .baseAttack    = 120,
       .baseDefense   = 85,
       .baseSpeed     = 105,
       .baseSpAttack  = 80,
       .baseSpDefense = 80,
       .types = { TYPE_NORMAL, TYPE_FIGHTING },
       .catchRate = 44,
       .expYield = 170,
       .evYield_Attack  = 3,
       .genderRatio = PERCENT_FEMALE(50),
       .eggCycles = 120,
       .friendship = 190,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_FIELD },
       .abilities = { ABILITY_DEFIANT, ABILITY_NONE, ABILITY_IRON_FIST, ABILITY_UNSEEN_FIST}, 
       .bodyColor = BODY_COLOR_YELLOW,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Kumataro"),
       .cryId = CRY_KUMATARO,
       .natDexNum = NATIONAL_DEX_KUMATARO,
       .categoryName = _("Platinum"),
       .height = 20,
       .weight = 1420,
       .description = COMPOUND_STRING(
           "Like Warudio, Kumataro has the power to\n"
           "stop time, but it usually chooses not to\n"
           "use it in fights, and much prefers admiring\n"
           "Eccosmic."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Kumataro,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Kumataro,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 0,
       .backPic = gMonBackPic_Kumataro,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 4,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Kumataro,
       .shinyPalette = gMonShinyPalette_Kumataro,
       .iconSprite = gMonIcon_Kumataro,
       .iconPalIndex = 0,
       FOOTPRINT(Kumataro)
       .levelUpLearnset = sKumataroLevelUpLearnset,
    },
    
        [SPECIES_FORGOTNO] =
    { 
       .baseHP        = 33,
       .baseAttack    = 136,
       .baseDefense   = 0,
       .baseSpeed     = 143,
       .baseSpAttack  = 143,
       .baseSpDefense = 91,
       .types = { TYPE_STEEL, TYPE_MYSTERY },
       .catchRate = 25,
       .expYield = 111,
       .evYield_SpAttack  = 3,
       .genderRatio = MON_GENDERLESS,
       .eggCycles = 120,
       .friendship = 40,
       .growthRate = GROWTH_MEDIUM_SLOW,
       .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
       .abilities = { ABILITY_KLUTZ, ABILITY_NONE, ABILITY_PUPPETEER, ABILITY_GALE_WINGS },
       .bodyColor = BODY_COLOR_GRAY,
       .isLegendary = FALSE,
       .allPerfectIVs = FALSE,
      .speciesName = _("Forgotno"),
       .cryId = CRY_FORGOTNO,
       .natDexNum = NATIONAL_DEX_FORGOTNO,
       .categoryName = _("Garbage Data"),
       .height = 28,
       .weight = 197,
       .description = COMPOUND_STRING(
           "Barely considered a Pokémon, Forgotno are \n"
           "found in secluded places where they slowly\n"
           "cause the world around them to deteriorate \n"
           "on a molecular level."),
       .pokemonScale = 356,
       .pokemonOffset = 16,
       .trainerScale = 256,
       .trainerOffset = -2,
       .frontPic = gMonFrontPic_Forgotno,
       .frontPicSize = MON_COORDS_SIZE(64, 64),
       .frontPicYOffset = 4,
       .frontAnimFrames = sAnims_Forgotno,
       .frontAnimId = ANIM_GROW_VIBRATE,
       .frontAnimDelay = 15,
       .enemyMonElevation = 2,
       .backPic = gMonBackPic_Forgotno,
       .backPicSize = MON_COORDS_SIZE(64, 64),
       .backPicYOffset = 0,
       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
       .palette = gMonPalette_Forgotno,
       .shinyPalette = gMonShinyPalette_Forgotno,
       .iconSprite = gMonIcon_Forgotno,
       .iconPalIndex = 5,
       FOOTPRINT(Forgotno)
       .levelUpLearnset = sForgotnoLevelUpLearnset,
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
