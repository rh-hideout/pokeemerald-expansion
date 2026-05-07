# How to Use the Random Mon Generator
*Written by Jordan/harbingerofruination*

## What is the random mon generator?

The random mon generator is a script-based command that can be used to set up in-game trades, events, or other scenarios where you would need a random mon. It is only entirely random if you want it to be, and has a wide range of customization and feature options. The purpose of this document is to explain and show you how to set it up for your own use case.

# Step 1: Setting Up Your Rules

So you want to make a custom ruleset for a possible random pokemon you'd like to use or distribute. Well, naturally, if you're giving something to the player early, it's unlikely you're going to want to have them receive a legendary or mythical pokemon, or a pokemon holding the choice specs or assault vest. Let's look at how to set it up such that you have the perfect pool of pokemon for your script to fetch from.

## Species Generation Options

### Setting Up Our Random Species

First thing's first, we need a way for the logic to read that we want a specific kind of random mon. The species constants file only defines the start of the random species range with `SPECIES_RANDOMLY_GENERATED_START`. Add your named species generator options in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h), then use those names in scripts.

### The Random Species Struct

```
struct RandomSpeciesGeneratorOptions
{
    enum RandomMonDexMode dexMode;
    const enum Species *speciesPool;
    u16 speciesPoolCount;
    const enum Species *bannedSpecies;
    u16 bannedSpeciesCount;
    u8 allowLegendary:1;
    u8 allowMythical:1;
    u8 allowSubLegendary:1;
    u8 allowUltraBeast:1;
    u8 allowParadox:1;
    u8 randomizeForms:1;
    u8 padding:2;
    bool32 (*filterFunc)(enum Species species);
};
```

These are the options you can toggle and change to select the ideal possible species. Let's go over the options one-by-one.

* `enum RandomMonDexMode dexMode`: With values of either `RANDOM_MON_DEX_NATIONAL` or `RANDOM_MON_DEX_HOENN`, allows you to select whether you want to choose from your National Dex or the Hoenn Dex. If you've replaced the hoenn dex but want to use that functionality, be sure that you investigate that path and substitute any references or functions specific to the hoenn dex to parallel ones for your custom dex.
* `const enum Species *speciesPool`: A pointer to the specific species pool you want to use, if any. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h). Examples of this will come later.
* `u16 speciesPoolCount`: The total number of species in your pool, if any.
* `const enum Species *bannedSpecies`: A pointer to the a pool containing any species of pokemon you want *banned* from selection. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h). You shouldn't use this in combination with the speciesPool, as that doesn't really make sense. Leave this one NULL if you have a specific pool of species you want to pick from, or use it if you want more randomness but with some specific banning restrictions that the other options below don't allow.
* `u16 bannedSpeciesCount`: The total number of banned species in the above pool, if any.
* `u8 allowLegendary`: Whether to allow restricted legendary pokemon to be viable selected mons.
* `u8 allowMythical`: Whether to allow mythical pokemon to be viable selected mons.
* `u8 allowSubLegendary`: Whether to allow sub-legendary pokemon (Regi trio, genies, etc) to be viable selected mons.
* `u8 allowUltraBeast`: Whether to allow ultra beast pokemon to be viable selected mons.
* `u8 allowParadox`: Whether to allow paradox pokemon to be viable selected mons.
* `u8 randomizeForms`: Whether to randomize forms of pokemon. By default, megas, fusions, and in-battle transformations are disallowed. To add exceptions, see and modify IsRandomMonFormTableException in [src/random_mon_generation.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/random_mon_generation.c).

### Filter Functions

Now you may notice that we didn't discuss `bool32 (*filterFunc)(enum Species species)`, and for good reason, as that element is more complicated than the others. This is a pointer an additional filter you can mess with or add to select for specific traits or features. For example, one of the default options for pools has `.filterFunc = IsSpeciesAllowedByRandomBstVars`. This function, if you set up VAR_0x8007 and VAR_0x8008 prior to calling, will filter out pokemon that are not within a specific BST range, as laid out in IsSpeciesAllowedByRandomBstVars in [src/random_mon_generation.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/random_mon_generation.c).

You could also, using similar logic, create a function that reads a VAR with a type value, and then filter only for pokemon of that type if possible, and have that function be the filterFunc in your ruleset. If you do not pass a filter function, then no filter beyond the other elements is applied.

### Example Setup

For a named random mon option, define the script-facing value and use `SPECIES_OPTION` to keep the array index tied to that value. With separate species and/or ban pools, your setup in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h) would look like this:

```
enum
{
    SPECIES_GENERATOR_NO_SUPERMONS = SPECIES_RANDOMLY_GENERATED_START,
    SPECIES_GENERATOR_LIMITED_POOL,
    SPECIES_GENERATOR_BST_RESTRICTED,
    SPECIES_GENERATOR_END,
};

#define RANDOM_SPECIES_OPTIONS_COUNT (SPECIES_GENERATOR_END - SPECIES_RANDOMLY_GENERATED_START)
#define SPECIES_OPTION(option) ((option) - SPECIES_RANDOMLY_GENERATED_START)

static const enum Species sRandomSpeciesOption0SpeciesPool[] =
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

static const enum Species sRandomSpeciesOption0BannedSpecies[] =
{
    SPECIES_BELDUM,
};

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[] =
{
    [SPECIES_OPTION(SPECIES_GENERATOR_LIMITED_POOL)] =
    {
        .speciesPool = sRandomSpeciesOption0SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption0SpeciesPool),
        .bannedSpecies = sRandomSpeciesOption0BannedSpecies,
        .bannedSpeciesCount = ARRAY_COUNT(sRandomSpeciesOption0BannedSpecies),
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
    },

    [SPECIES_OPTION(SPECIES_GENERATOR_BST_RESTRICTED)] =
    {
        .dexMode = RANDOM_MON_DEX_HOENN,
        .filterFunc = IsSpeciesAllowedByRandomBstVars,
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
    },
}
```

> [!NOTE]
> You really don't need to use a choosable species pool and a banned species pool in the same ruleset, it just doesn't make sense and may end up causing more trouble than anything. Additionally, you should never include SPECIES_NONE in either of these kinds of pools, only actual, defined species.

Small explicit species pools are checked exhaustively before choosing, which gives clear errors if every entry is filtered out. Larger explicit pools and full dex searches use repeated random attempts, then fall back to the first valid entry if the filters are too restrictive.

## Item Generator Options

Item randomization is handled separately from pokemon randomization, meaning that you could always give a charmander but it could always hold a random or semi-random item. Compared to the species generation options, here we have far fewer to discuss.

### Setting Up Our Random Items

As we did for our random species, we need to also do for our random items. The item constants file only defines the start of the random item range with `ITEM_RANDOMLY_GENERATED_START`. Add your named item generator options in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h), then use those names in scripts.

### The Random Item Struct

```
struct RandomItemGeneratorOptions
{
    const enum Item *heldItemPool;
    u16 heldItemPoolCount;
    const enum HoldEffect *bannedHoldEffects;
    u16 bannedHoldEffectsCount;
};
```

* `const enum Item *heldItemPool`: A pointer to the specific item pool you want to use, if any. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h).
* `u16 heldItemPoolCount`: The number of items in your held item pool, if any.
* `const enum HoldEffect *bannedHoldEffects`: A pointer to the specific list of banned hold effects you want to use, if any. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h).
* `u16 bannedHoldEffectsCount`: The number of banned hold effects in your pool, if any.

### Example Setup

For a named random item option, define the script-facing value and use `ITEM_OPTION` to keep the array index tied to that value. With separate held item pools and/or hold effect ban pools, your setup in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h) would look like this:

```
enum
{
    ITEM_GENERATOR_STANDARD = ITEM_RANDOMLY_GENERATED_START,
    ITEM_GENERATOR_END,
};

#define RANDOM_ITEM_OPTIONS_COUNT (ITEM_GENERATOR_END - ITEM_RANDOMLY_GENERATED_START)
#define ITEM_OPTION(option) ((option) - ITEM_RANDOMLY_GENERATED_START)

static const enum HoldEffect sRandomItemOption0BannedHoldEffects[] =
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

static const enum Item sRandomItemOption0HeldItemPool[] =
{
    ITEM_LEFTOVERS,
    ITEM_SITRUS_BERRY,
    ITEM_LUM_BERRY,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SCARF,
    ITEM_CHOICE_SPECS,
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[] =
{
    [ITEM_OPTION(ITEM_GENERATOR_STANDARD)] =
    {
        .heldItemPool = sRandomItemOption0HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption0HeldItemPool),
        .bannedHoldEffects = sRandomItemOption0BannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemOption0BannedHoldEffects),
    },
};
```

> [!NOTE]
> `ITEM_NONE` is never selected during full item randomization, but it can be included in an explicit held item pool if you want that option to sometimes produce no held item. Small explicit item pools are checked exhaustively before choosing, while larger explicit pools and full item searches use repeated random attempts.

# Step 2: Other options to be aware of

## Random Ball Generation

This feature also includes random ball generation. When doing givemon/createmon, just use `ball=BALL_RANDOM` as an argument.

## Random Move Generation

This feature also includes random teachable move generation. When doing givemon/createmon, for move slot x, just use `movex=MOVE_RANDOM_TEACHABLE` as an argument.

# Step 3: Putting it all together

Here's an example of how you'd call it in a script when it all comes together:

```
EventScript_GiveFilteredRandomMon::
    // BST target = 300, leniency = 100, so valid BST range is 200-400.
    // SPECIES_GENERATOR_BST_RESTRICTED, in this scenario, is the option using IsSpeciesAllowedByRandomBstVars as a filterFunc.
    setvar VAR_0x8007, 300
    setvar VAR_0x8008, 100

    givemon SPECIES_GENERATOR_BST_RESTRICTED, 50,
        item=ITEM_GENERATOR_LIMITED_POOL,
        ball=BALL_RANDOM,
        move1=MOVE_RANDOM_TEACHABLE,
        move2=MOVE_RANDOM_TEACHABLE,
        move3=MOVE_RANDOM_TEACHABLE,
        move4=MOVE_DEFAULT;

    // Optional cleanup: makes future BST-filtered random mons skip BST filtering
    // unless the script intentionally sets these vars again.
    setvar VAR_0x8007, 0
    setvar VAR_0x8008, 0
    end
```

This will produce a random mon from the BST-restricted species option with between 200 and 400 BST, a random item from the limited item pool, a random ball, with 3 random teachable moves, and with one move it'd normally have at that level (MOVE_DEFAULT)
