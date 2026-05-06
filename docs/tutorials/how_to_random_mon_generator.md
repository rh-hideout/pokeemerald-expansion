# How to Use the Random Mon Generator
*Written by Jordan/harbingerofruination*

## What is the random mon generator?

The random mon generator is a script-based command that can be used to set up in-game trades, events, or other scenarios where you would need a random mon. It is only entirely random if you want it to be, and has a wide range of customization and feature options. The purpose of this document is to explain and show you how to set it up for your own use case.

# Step 1: Setting Up Your Rules

So you want to make a custom ruleset for a possible random pokemon you'd like to use or distribute. Well, naturally, if you're giving something to the player early, it's unlikely you're going to want to have them receive a legendary or mythical pokemon, or a pokemon holding the choice specs or assault vest. Let's look at how to set it up such that you have the perfect pool of pokemon for your script to fetch from.

## Species Generation Options

### Setting Up Our Random Species

First thing's first, we need a way for the logic to read that we want a specific kind of random mon. This is done by editing [include/constants/species.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/species.h) and adding in a new random species or editing an existing random species at the bottom of the file, incrementing as necessary.

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

For random mon option 0, defined as `#define SPECIES_RANDOM_MON_OPTION_0 6000` in [include/constants/species.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/species.h), we'd use index 0 in RandomSpeciesGeneratorOptions, with separate species and/or ban pools like so in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h):

```
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
    [0] =
    {
        .dexMode = RANDOM_MON_DEX_NATIONAL,
        .allowLegendary = FALSE,
        .allowMythical = FALSE,
        .allowSubLegendary = FALSE,
        .allowUltraBeast = FALSE,
        .allowParadox = FALSE,
        .randomizeForms = TRUE,
        .filterFunc = IsSpeciesAllowedByRandomBstVars,
    },
}
```

> [!NOTE]
> You really don't need to use a choosable species pool and a banned species pool in the same ruleset, it just doesn't make sense and may end up causing more trouble than anything. Additionally, you should never include SPECIES_NONE in either of these kinds of pools, only actual, defined species.

## Item Generator Options

Item randomization is handled separately from pokemon randomization, meaning that you could always give a charmander but it could always hold a random or semi-random item. Compared to the species generation options, here we have far fewer to discuss.

### Setting Up Our Random Species

As we did for our random species, we need to also do for our random items. This is done by editing [include/constants/items.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/items.h) and adding in a new random species or editing an existing random species at the bottom of the file, incrementing as necessary.

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
* `const enum HoldEffect *bannedHoldEffects`: A pointer to the specific list of banned hold effects you want to use, if any. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h). Do not use with heldItemPool, use one or the other.
* `u16 bannedHoldEffectsCount`: The number of banned hold effects in your pool, if any.

### Example Setup

For random mon option 0, defined as `#define ITEM_RANDOM_OPTION_0 6000` in [include/constants/items.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/items.h), we'd use index 0 in RandomItemGeneratorOptions, with separate held item pools and/or hold effect ban pools like so in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h):

```
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
    [0] =
    {
        .bannedHoldEffects = sRandomItemStandardBannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemStandardBannedHoldEffects),
    },
    [1] =
    {
        .heldItemPool = sRandomItemOption0HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption0HeldItemPool),
        .bannedHoldEffects = sRandomItemOption0BannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemOption0BannedHoldEffects),
    },
};
```

> [!NOTE]
> You really don't need to use a choosable item pool and a banned hold effects pool in the same ruleset, it just doesn't make sense and may end up causing more trouble than anything.

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
    // SPECIES_RANDOM_MON_OPTION_0, in this scenario, is the option using IsSpeciesAllowedByRandomBstVars.
    setvar VAR_0x8007, 300
    setvar VAR_0x8008, 100

    givemon SPECIES_RANDOM_MON_OPTION_0, 50,
        item=ITEM_RANDOM_OPTION_0,
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

This will produce a random mon from pool 0 with between 200 and 400 BST, a random item from pool 0, a random ball, with 3 random teachable moves, and with one move it'd normally have at that level (MOVE_DEFAULT)