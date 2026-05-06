static const enum Species sRandomSpeciesOption0SpeciesPool[] =
{
    SPECIES_CHARIZARD,
};

static const enum Species sRandomSpeciesOption1SpeciesPool[] =
{
    SPECIES_MEW,
};

static const enum Species sRandomSpeciesOption2SpeciesPool[] =
{
    SPECIES_WOBBUFFET,
};

static const enum Item sRandomItemOption0HeldItemPool[] =
{
    ITEM_LEFTOVERS,
};

static const enum HoldEffect sRandomItemOption1BannedHoldEffects[] =
{
    HOLD_EFFECT_LEFTOVERS,
};

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[] =
{
    [0] =
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
    [1] =
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
    [2] =
    {
        .speciesPool = sRandomSpeciesOption2SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption2SpeciesPool),
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = FALSE,
        .filterFunc = IsSpeciesAllowedByRandomBstVars,
    },
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[] =
{
    [0] =
    {
        .heldItemPool = sRandomItemOption0HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption0HeldItemPool),
    },
    [1] =
    {
        .heldItemPool = sRandomItemOption0HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption0HeldItemPool),
        .bannedHoldEffects = sRandomItemOption1BannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemOption1BannedHoldEffects),
    },
};
