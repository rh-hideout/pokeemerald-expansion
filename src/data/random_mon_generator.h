// Pool settings for random mon generation via scripts. For more info on options, check out struct RandomMonGeneratorOptions in src/script_pokemon_util.c

static const enum Species sRandomMonOption1SpeciesPool[] =
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

static const enum Species sRandomMonOption1BannedSpecies[] =
{
    SPECIES_BELDUM,
};

static const enum HoldEffect sRandomMonStandardBannedHoldEffects[] =
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

static const enum Item sRandomMonOption1HeldItemPool[] =
{
    ITEM_LEFTOVERS,
    ITEM_SITRUS_BERRY,
    ITEM_LUM_BERRY,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SCARF,
    ITEM_CHOICE_SPECS,
};

static const struct RandomMonGeneratorOptions sRandomMonGeneratorOptions[] =
{
    [0] =
    {
        .dexMode = RANDOM_MON_DEX_NATIONAL,
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
        .randomTeachableMoveCount = 0,
        .randomizeAbility = TRUE,
        .randomizeHeldItem = FALSE,
        .randomizeBall = FALSE,
        .shinyMode = SHINY_MODE_RANDOM,
        .bstStandard = 0,
        .bstLeniency = 0,
    },
    [1] =
    {
        .speciesPool = sRandomMonOption1SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomMonOption1SpeciesPool),
        .bannedSpecies = sRandomMonOption1BannedSpecies,
        .bannedSpeciesCount = ARRAY_COUNT(sRandomMonOption1BannedSpecies),
        .heldItemPool = sRandomMonOption1HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomMonOption1HeldItemPool),
        .bannedHoldEffects = sRandomMonStandardBannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomMonStandardBannedHoldEffects),
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
        .randomTeachableMoveCount = 2,
        .randomizeAbility = TRUE,
        .randomizeHeldItem = TRUE,
        .randomizeBall = TRUE,
        .shinyMode = SHINY_MODE_RANDOM,
        .bstStandard = 0,
        .bstLeniency = 0,
    },
    [2] =
    {
        .dexMode = RANDOM_MON_DEX_HOENN,
        .bannedHoldEffects = sRandomMonStandardBannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomMonStandardBannedHoldEffects),
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
        .randomTeachableMoveCount = 4,
        .randomizeAbility = TRUE,
        .randomizeHeldItem = TRUE,
        .randomizeBall = TRUE,
        .shinyMode = SHINY_MODE_RANDOM,
        .bstStandard = 300,
        .bstLeniency = 100,
    },
};
