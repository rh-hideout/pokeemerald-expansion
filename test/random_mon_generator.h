enum
{
    SPECIES_GENERATOR_FILTERED_POOL = SPECIES_RANDOMLY_GENERATED_START,
    SPECIES_GENERATOR_MYTHICAL_FILTER,
    SPECIES_GENERATOR_BST_FILTER,
    SPECIES_GENERATOR_FORM_FILTER,
    SPECIES_GENERATOR_END,
};

#define RANDOM_SPECIES_OPTIONS_COUNT (SPECIES_GENERATOR_END - SPECIES_RANDOMLY_GENERATED_START)
#define SPECIES_OPTION(option) ((option) - SPECIES_RANDOMLY_GENERATED_START)

enum
{
    ITEM_GENERATOR_SINGLE_ITEM = ITEM_RANDOMLY_GENERATED_START,
    ITEM_GENERATOR_FILTERED_POOL,
    ITEM_GENERATOR_NONE_POOL,
    ITEM_GENERATOR_END,
};

#define RANDOM_ITEM_OPTIONS_COUNT (ITEM_GENERATOR_END - ITEM_RANDOMLY_GENERATED_START)
#define ITEM_OPTION(option) ((option) - ITEM_RANDOMLY_GENERATED_START)

static const enum Species sRandomSpeciesOption0SpeciesPool[] =
{
    SPECIES_MEW,
    SPECIES_CHARIZARD,
};

static const enum Species sRandomSpeciesOption1SpeciesPool[] =
{
    SPECIES_MEW,
    SPECIES_CHARIZARD,
};

static const enum Species sRandomSpeciesOption2SpeciesPool[] =
{
    SPECIES_WOBBUFFET,
    SPECIES_MEW,
};

static const enum Species sRandomSpeciesOption3SpeciesPool[] =
{
    SPECIES_ROTOM,
};

static bool32 IsSpeciesRotomHeat(enum Species species, u16 arg1, u16 arg2)
{
    (void)arg1;
    (void)arg2;

    return species == SPECIES_ROTOM_HEAT;
}

static const enum Item sRandomItemOption0HeldItemPool[] =
{
    ITEM_LEFTOVERS,
};

static const enum Item sRandomItemOption1HeldItemPool[] =
{
    ITEM_LEFTOVERS,
    ITEM_LUM_BERRY,
};

static const enum Item sRandomItemOption2HeldItemPool[] =
{
    ITEM_NONE,
};

static const enum HoldEffect sRandomItemOption1BannedHoldEffects[] =
{
    HOLD_EFFECT_LEFTOVERS,
};

static const enum HoldEffect sRandomItemOption2BannedHoldEffects[] =
{
    HOLD_EFFECT_NONE,
};

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[] =
{
    [SPECIES_OPTION(SPECIES_GENERATOR_FILTERED_POOL)] =
    {
        .speciesPool = sRandomSpeciesOption0SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption0SpeciesPool),
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = FALSE,
    },
    [SPECIES_OPTION(SPECIES_GENERATOR_MYTHICAL_FILTER)] =
    {
        .speciesPool = sRandomSpeciesOption1SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption1SpeciesPool),
        .allowLegendary = TRUE,
        .allowMythical = FALSE,
        .allowSubLegendary = TRUE,
        .allowUltraBeast = TRUE,
        .allowParadox = TRUE,
        .randomizeForms = FALSE,
    },
    [SPECIES_OPTION(SPECIES_GENERATOR_BST_FILTER)] =
    {
        .speciesPool = sRandomSpeciesOption2SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption2SpeciesPool),
        .allowLegendary = FALSE,
        .allowMythical = TRUE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = FALSE,
        .filterFunc = IsSpeciesAllowedByRandomBstArgs,
    },
    [SPECIES_OPTION(SPECIES_GENERATOR_FORM_FILTER)] =
    {
        .speciesPool = sRandomSpeciesOption3SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption3SpeciesPool),
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
        .filterFunc = IsSpeciesRotomHeat,
    },
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[] =
{
    [ITEM_OPTION(ITEM_GENERATOR_SINGLE_ITEM)] =
    {
        .heldItemPool = sRandomItemOption0HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption0HeldItemPool),
    },
    [ITEM_OPTION(ITEM_GENERATOR_FILTERED_POOL)] =
    {
        .heldItemPool = sRandomItemOption1HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption1HeldItemPool),
        .bannedHoldEffects = sRandomItemOption1BannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemOption1BannedHoldEffects),
    },
    [ITEM_OPTION(ITEM_GENERATOR_NONE_POOL)] =
    {
        .heldItemPool = sRandomItemOption2HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption2HeldItemPool),
        .bannedHoldEffects = sRandomItemOption2BannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemOption2BannedHoldEffects),
    },
};
