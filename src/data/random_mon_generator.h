// Pool settings for random mon generation via scripts. For more info on options, check out
// struct RandomSpeciesGeneratorOptions and struct RandomItemGeneratorOptions in src/random_mon_generation.c.

enum
{
    /*
    SPECIES_GENERATOR_NO_SUPERMONS,
    SPECIES_GENERATOR_LIMITED_POOL,
    SPECIES_GENERATOR_BST_RESTRICTED,
    */
    RANDOM_SPECIES_OPTIONS_COUNT,
};

enum
{
    /*
    ITEM_GENERATOR_STANDARD,
    ITEM_GENERATOR_LIMITED_POOL,
    */
    RANDOM_ITEM_OPTIONS_COUNT,
};

/*
static const enum Species sRandomSpeciesOption1SpeciesPool[] =
{
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_RALTS,
    SPECIES_ARON,
    SPECIES_TRAPINCH,
    SPECIES_BAGON,
    SPECIES_BELDUM,
};

static const enum Species sRandomSpeciesOption1BannedSpecies[] =
{
    SPECIES_BELDUM,
};

static const enum HoldEffect sRandomItemStandardBannedHoldEffects[] =
{
    HOLD_EFFECT_NONE,
    HOLD_EFFECT_REPEL,
    HOLD_EFFECT_SOUL_DEW,
    HOLD_EFFECT_DEEP_SEA_TOOTH,
    HOLD_EFFECT_DEEP_SEA_SCALE,
    HOLD_EFFECT_LIGHT_BALL,
    HOLD_EFFECT_THICK_CLUB,
    HOLD_EFFECT_LEEK,
    HOLD_EFFECT_ADAMANT_ORB,
    HOLD_EFFECT_LUSTROUS_ORB,
    HOLD_EFFECT_GRISEOUS_ORB,
    HOLD_EFFECT_ENIGMA_BERRY,
    HOLD_EFFECT_PLATE,
    HOLD_EFFECT_DRIVE,
    HOLD_EFFECT_GEMS,
    HOLD_EFFECT_MEGA_STONE,
    HOLD_EFFECT_PRIMAL_ORB,
    HOLD_EFFECT_MEMORY,
    HOLD_EFFECT_Z_CRYSTAL,
    HOLD_EFFECT_BOOSTER_ENERGY,
    HOLD_EFFECT_OGERPON_MASK,
};

static const enum Item sRandomItemOption1HeldItemPool[] =
{
    ITEM_LEFTOVERS,
    ITEM_SITRUS_BERRY,
    ITEM_LUM_BERRY,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SCARF,
    ITEM_CHOICE_SPECS,
};
*/

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[] =
{
    /*
    [SPECIES_GENERATOR_NO_SUPERMONS] =
    {
        .dexMode = RANDOM_MON_DEX_NATIONAL,
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
    },
    [SPECIES_GENERATOR_LIMITED_POOL] =
    {
        .speciesPool = sRandomSpeciesOption1SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption1SpeciesPool),
        .bannedSpecies = sRandomSpeciesOption1BannedSpecies,
        .bannedSpeciesCount = ARRAY_COUNT(sRandomSpeciesOption1BannedSpecies),
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
    },
    [SPECIES_GENERATOR_BST_RESTRICTED] =
    {
        .dexMode = RANDOM_MON_DEX_HOENN,
        .filterFunc = IsInBstRangeFilterFunc,
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
    },
    */
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[] =
{
    /*
    [ITEM_GENERATOR_STANDARD] =
    {
        .bannedHoldEffects = sRandomItemStandardBannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemStandardBannedHoldEffects),
    },
    [ITEM_GENERATOR_LIMITED_POOL] =
    {
        .heldItemPool = sRandomItemOption1HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption1HeldItemPool),
        .bannedHoldEffects = sRandomItemStandardBannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemStandardBannedHoldEffects),
    },
    */
};
