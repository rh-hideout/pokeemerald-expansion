---
name: species-data
description: Add or modify Pokemon species data including stats, types, evolutions, learnsets, forms, and sprites. Use when adding new Pokemon, editing existing species, or working with form changes.
allowed-tools: Read, Grep, Glob, Write, Edit, Bash(make:*)
---

# Species Data Guide

## Key Files

| File | Purpose |
|------|---------|
| `include/constants/species.h` | Species ID constants |
| `src/data/pokemon/species_info.h` | Main species array include |
| `src/data/pokemon/species_info/gen_*.h` | Species data by generation |
| `src/data/pokemon/level_up_learnsets/*.h` | Level-up moves |
| `src/data/pokemon/egg_moves.h` | Egg moves |
| `src/data/pokemon/form_change_tables.h` | Form change definitions |
| `src/data/pokemon/form_species_tables.h` | Form ID mappings |
| `src/data/graphics/pokemon.h` | Graphics pointers |
| `include/config/species_enabled.h` | Species toggle config |

## SpeciesInfo Structure (Key Fields)

```c
struct SpeciesInfo {
    // Base Stats
    u8 baseHP, baseAttack, baseDefense;
    u8 baseSpeed, baseSpAttack, baseSpDefense;

    // Core Data
    enum Type types[2];
    u8 catchRate;
    u16 expYield;
    u8 genderRatio;              // PERCENT_FEMALE(50) or MON_GENDERLESS
    u8 eggCycles;
    u8 friendship;               // STANDARD_FRIENDSHIP = 70
    u8 growthRate;               // GROWTH_MEDIUM_FAST, etc.
    u8 eggGroups[2];
    enum Ability abilities[3];   // [Normal, Normal, Hidden]

    // Pokedex
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    u8 categoryName[13];
    u16 height;                  // decimeters
    u16 weight;                  // hectograms
    const u8 *description;

    // Graphics
    const u32 *frontPic, *backPic;
    const u16 *palette, *shinyPalette;
    const u8 *iconSprite;
    u8 frontPicSize, backPicSize;
    u8 frontPicYOffset, backPicYOffset;

    // Learnsets & Evolution
    const struct LevelUpMove *levelUpLearnset;
    const u16 *teachableLearnset;
    const u16 *eggMoveLearnset;
    const struct Evolution *evolutions;
    const u16 *formSpeciesIdTable;
    const struct FormChange *formChangeTable;

    // Flags
    u32 isLegendary:1, isMythical:1, isUltraBeast:1;
    u32 isMegaEvolution:1, isGigantamax:1, isTeraForm:1;
};
```

## Adding a New Pokemon

### Step 1: Add Species Constant

In `include/constants/species.h`:
```c
#define SPECIES_MYNEWMON    [next_available_number]
```

### Step 2: Enable Family (if creating new family)

In `include/config/species_enabled.h`:
```c
#define P_FAMILY_MYNEWMON    TRUE
```

### Step 3: Create Graphics

Directory: `graphics/pokemon/mynewmon/`
- `anim_front.png` - Front sprite (2 frames stacked)
- `back.png` - Back sprite
- `normal.pal` / `shiny.pal` - Palettes
- `icon.png` - Party/summary icon
- `footprint.png` - Footprint

### Step 4: Add Graphics Pointers

In `src/data/graphics/pokemon.h`:
```c
#if P_FAMILY_MYNEWMON
const u32 gMonFrontPic_MyNewMon[] = INCBIN_U32("graphics/pokemon/mynewmon/anim_front.4bpp.smol");
const u32 gMonBackPic_MyNewMon[] = INCBIN_U32("graphics/pokemon/mynewmon/back.4bpp.smol");
const u16 gMonPalette_MyNewMon[] = INCBIN_U16("graphics/pokemon/mynewmon/normal.gbapal");
const u16 gMonShinyPalette_MyNewMon[] = INCBIN_U16("graphics/pokemon/mynewmon/shiny.gbapal");
const u8 gMonIcon_MyNewMon[] = INCBIN_U8("graphics/pokemon/mynewmon/icon.4bpp");
#endif
```

### Step 5: Create Learnsets

Level-up moves in `src/data/pokemon/level_up_learnsets/gen_X.h`:
```c
#if P_FAMILY_MYNEWMON
static const struct LevelUpMove sMyNewMonLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 7, MOVE_EMBER),
    LEVEL_UP_MOVE(12, MOVE_QUICK_ATTACK),
    LEVEL_UP_END
};
#endif
```

Egg moves in `src/data/pokemon/egg_moves.h`:
```c
#if P_FAMILY_MYNEWMON
static const u16 sMyNewMonEggMoveLearnset[] = {
    MOVE_WISH,
    MOVE_CURSE,
    MOVE_UNAVAILABLE,
};
#endif
```

### Step 6: Define Species Data

In `src/data/pokemon/species_info/gen_X_families.h`:
```c
#if P_FAMILY_MYNEWMON
    [SPECIES_MYNEWMON] = {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 49,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("MyNewMon"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_MYNEWMON,
        .categoryName = _("Fire"),
        .height = 6,
        .weight = 85,
        .description = COMPOUND_STRING(
            "A newly discovered Fire-type.\n"
            "It breathes small flames."),
        .pokemonScale = 379,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MyNewMon,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_MyNewMon,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MyNewMon,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_MyNewMon,
        .shinyPalette = gMonShinyPalette_MyNewMon,
        .iconSprite = gMonIcon_MyNewMon,
        .iconPalIndex = 0,
        SHADOW(-1, 5, SHADOW_SIZE_S)
        FOOTPRINT(MyNewMon)
        .levelUpLearnset = sMyNewMonLevelUpLearnset,
        .teachableLearnset = sMyNewMonTeachableLearnset,
        .eggMoveLearnset = sMyNewMonEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_MYNEWMON_EVO}),
    },
#endif
```

## Evolution Methods

| Method | Parameters | Example |
|--------|------------|---------|
| `EVO_LEVEL` | level | `{EVO_LEVEL, 16, SPECIES_X}` |
| `EVO_ITEM` | item ID | `{EVO_ITEM, ITEM_FIRE_STONE, SPECIES_X}` |
| `EVO_TRADE` | none | `{EVO_TRADE, 0, SPECIES_X}` |
| `EVO_TRADE_ITEM` | item ID | `{EVO_TRADE_ITEM, ITEM_METAL_COAT, SPECIES_X}` |
| `EVO_FRIENDSHIP` | none | `{EVO_FRIENDSHIP, 0, SPECIES_X}` |
| `EVO_FRIENDSHIP_DAY` | none | `{EVO_FRIENDSHIP_DAY, 0, SPECIES_X}` |
| `EVO_FRIENDSHIP_NIGHT` | none | `{EVO_FRIENDSHIP_NIGHT, 0, SPECIES_X}` |
| `EVO_MOVE` | move ID | `{EVO_MOVE, MOVE_ANCIENT_POWER, SPECIES_X}` |
| `EVO_ITEM_HOLD_DAY` | item ID | `{EVO_ITEM_HOLD_DAY, ITEM_RAZOR_CLAW, SPECIES_X}` |
| `EVO_LEVEL_ATK_GT_DEF` | level | `{EVO_LEVEL_ATK_GT_DEF, 20, SPECIES_X}` |

Multiple evolutions:
```c
.evolutions = EVOLUTION(
    {EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_RAICHU},
    {EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_RAICHU_ALOLA, CONDITIONS(IF_IN_REGION, REGION_ALOLA)},
),
```

## Form Changes

### Form Change Types

| Type | Use Case |
|------|----------|
| `FORM_CHANGE_ITEM_HOLD` | Holding item |
| `FORM_CHANGE_ITEM_USE` | Item used on Pokemon |
| `FORM_CHANGE_MOVE` | Knows/forgets move |
| `FORM_CHANGE_BEGIN_BATTLE` | Battle starts |
| `FORM_CHANGE_END_BATTLE` | Battle ends |
| `FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM` | Mega with stone |
| `FORM_CHANGE_BATTLE_PRIMAL_REVERSION` | Primal orbs |
| `FORM_CHANGE_BATTLE_GIGANTAMAX` | G-Max |
| `FORM_CHANGE_BATTLE_TERASTALLIZE` | Tera form |

### Form Tables

In `src/data/pokemon/form_species_tables.h`:
```c
static const u16 sMyNewMonFormSpeciesIdTable[] = {
    SPECIES_MYNEWMON,
#if P_MEGA_EVOLUTIONS
    SPECIES_MYNEWMON_MEGA,
#endif
    FORM_SPECIES_END,
};
```

In `src/data/pokemon/form_change_tables.h`:
```c
static const struct FormChange sMyNewMonFormChangeTable[] = {
#if P_MEGA_EVOLUTIONS
    {FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM, SPECIES_MYNEWMON_MEGA, ITEM_MYNEWMONITE},
#endif
    {FORM_CHANGE_TERMINATOR},
};
```

Link in species data:
```c
.formSpeciesIdTable = sMyNewMonFormSpeciesIdTable,
.formChangeTable = sMyNewMonFormChangeTable,
```

## Useful Macros

```c
// Types (single or dual)
.types = MON_TYPES(TYPE_FIRE),
.types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),

// Egg groups
.eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
.eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),

// Gender ratio
.genderRatio = PERCENT_FEMALE(50),      // 50% female
.genderRatio = PERCENT_FEMALE(12.5),    // 12.5% female (starters)
.genderRatio = MON_MALE,                // Always male
.genderRatio = MON_FEMALE,              // Always female
.genderRatio = MON_GENDERLESS,          // No gender

// Sprite size
.frontPicSize = MON_COORDS_SIZE(64, 64),  // width, height

// Shadow
SHADOW(x_offset, y_offset, SHADOW_SIZE_S)  // S, M, L, XL

// Evolution
.evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_X}),
```

## Growth Rates

| Constant | Pokemon Examples |
|----------|------------------|
| `GROWTH_MEDIUM_FAST` | Most Pokemon |
| `GROWTH_MEDIUM_SLOW` | Starters |
| `GROWTH_SLOW` | Legendaries |
| `GROWTH_FAST` | Common Pokemon |
| `GROWTH_ERRATIC` | Some Gen 3 |
| `GROWTH_FLUCTUATING` | Some Gen 3 |

## Body Colors

`BODY_COLOR_RED`, `BODY_COLOR_BLUE`, `BODY_COLOR_YELLOW`, `BODY_COLOR_GREEN`, `BODY_COLOR_BLACK`, `BODY_COLOR_BROWN`, `BODY_COLOR_PURPLE`, `BODY_COLOR_GRAY`, `BODY_COLOR_WHITE`, `BODY_COLOR_PINK`

## Config Toggles

In `include/config/species_enabled.h`:
```c
#define P_GEN_1_POKEMON         TRUE
#define P_MEGA_EVOLUTIONS       TRUE
#define P_GIGANTAMAX_FORMS      TRUE
#define P_ALOLAN_FORMS          TRUE
// etc.
```

In `include/config/pokemon.h`:
```c
#define P_UPDATED_STATS         GEN_LATEST
#define P_LVL_UP_LEARNSETS      GEN_LATEST
#define P_GENDER_DIFFERENCES    TRUE
#define P_FOOTPRINTS            TRUE
```
