# How to add a new trainer pic

## Content
* [Quick Summary](#quick-summary)
* [The Graphics](#the-graphics)
  * [1. Edit the sprites](#2-edit-the-sprites)
  * [2. Register the sprites](#2-register-the-sprites)
  * [3. Connecting pictures to the data](#2-connecting-pictures-to-the-data)
* [The Data](#the-data)
  * [4. Defining the trainer pic](#2-defining-the-trainer-pic)
* [Usage](#usage)

## Quick Summary
If you've done this before and just need a quick lookup, here's what files you need:
1. GFX into [graphics/trainers/front_pics](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/graphics/trainers/front_pics)
2. Palette into [graphics/trainers/palettes](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/graphics/trainers/palettes)
3. Point game to where graphic files are found: [src/data/graphics/trainers](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/trainers.h)
4. Add trainer to [include/constants/trainers.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/trainers.h)

## The Graphics

### 1. Edit the sprites
We will start with a graphic that we want to use for our new trainer pic. Unlike with adding Pokémon, the trainer sprites aren't sorted in individual folders, but rather in one folder:
[graphics/trainers/front_pics](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/graphics/trainers/front_pics)

**Remember to limit yourself to 16 colors including transparency in the first slot!**

Export the palette and place into the same folder.

### 2. Register the sprites
Sadly, just putting the image files into the graphics folder is not enough. To use the sprites we have to register them by linking the graphic files.
[src/data/graphics/trainers](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/trainers.h):
```diff
const u16 gTrainerPalette_RubySapphireBrendan[] = INCBIN_U16("graphics/trainers/palettes/ruby_sapphire_brendan.gbapal");

const u32 gTrainerFrontPic_RubySapphireMay[] = INCBIN_U32("graphics/trainers/front_pics/ruby_sapphire.4bpp.lz");
const u16 gTrainerPalette_RubySapphireMay[] = INCBIN_U16("graphics/trainers/palettes/ruby_sapphire_may.gbapal");

+ const u32 gTrainerFrontPic_myTrainerClass[] = INCBIN_U32("graphics/trainers/front_pics/myTrainerClass.4bpp.lz");
+ const u16 gTrainerPalette_myTrainerClass[] = INCBIN_U16("graphics/trainers/palettes/myTrainerClass.gbapal");

const u8 gTrainerBackPic_Brendan[] = INCBIN_U8("graphics/trainers/back_pics/brendan.4bpp");
```

### 3. Connecting the Pictures to the Data
The last few things we have to do is prepare the graphics for usage. In [src/data/graphics/trainers.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/trainers.h) you'll find the gTrainerSprites struct, we need to add the trainer to this. You can just copy the last trainer type defined and edit it, but this is what it does: Connects the trainer type with the image we defined earlier.

So, finally, it needs to look like this:
```diff
define TRAINER_SPRITE(trainerPic, picFile, paletteFile, ...)                  \
    [trainerPic] =                                                             \
    {                                                                          \
        .frontPic = {picFile, TRAINER_PIC_SIZE, trainerPic},                   \
        .palette = {paletteFile, trainerPic},                                  \
        .mugshotCoords = {DEFAULT(0, __VA_ARGS__), DEFAULT_2(0, __VA_ARGS__)}, \
        .mugshotRotation = DEFAULT_3(0x200, __VA_ARGS__),                      \
    }

const struct TrainerSprite gTrainerSprites[] =
{
    TRAINER_SPRITE(TRAINER_PIC_HIKER, gTrainerFrontPic_Hiker, gTrainerPalette_Hiker),
    TRAINER_SPRITE(TRAINER_PIC_AQUA_GRUNT_M, gTrainerFrontPic_AquaGruntM, gTrainerPalette_AquaGruntM),
    ...
    TRAINER_SPRITE(TRAINER_PIC_RS_MAY, gTrainerFrontPic_RubySapphireMay, gTrainerPalette_RubySapphireMay),
    TRAINER_SPRITE(TRAINER_PIC_MY_TRAINER_CLASS, gTrainerFrontPic_myTrainerClass, gTrainerPalette_myTrainerClass)
};
```
### The Data
#### 4. Defining the trainer pic
Finally, let's bring it all together by defining our new trainer pic in [include/constants/trainers.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/trainers.h):

```diff
#define TRAINER_PIC_RS_MAY                92
+ #define TRAINER_PIC_MY_TRAINER_CLASS      93

#define TRAINER_BACK_PIC_BRENDAN                0
#define TRAINER_BACK_PIC_MAY                    1
```
Remember to count the number next to the trainer pic up by one!

## Usage
You can test your trainer type by going to [src/data/trainers](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/trainers.h) and changing a trainer type. For example:
```diff
    [TRAINER_BRENDAN_PLACEHOLDER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
-       .trainerPic = TRAINER_PIC_RS_BRENDAN,
+       .trainerPic = TRAINER_PIC_MY_TRAINER_CLASS,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_BrendanLinkPlaceholder),
        .party = {.NoItemDefaultMoves = sParty_BrendanLinkPlaceholder},
    },
```
