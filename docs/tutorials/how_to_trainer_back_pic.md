# How to add a new trainer back pic

## Content
* [Quick Summary](#quick-summary)
* [The Graphics](#the-graphics)
  * [1. Edit the sprites](#2-edit-the-sprites)
  * [2. Register the sprites](#2-register-the-sprites)
  * [3. Connecting pictures to the data](#2-connecting-pictures-to-the-data)
* [The Data](#the-data)
  * [4. Defining the trainer back pic](#2-defining-the-trainer-back-pic)
* [Usage](#usage)

## Quick Summary
If you've done this before and just need a quick lookup, here's what files you need:
1. GFX into [`graphics/trainers/back_pics`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/graphics/trainers/back_pics).
2. Point game to where graphic files are found: [`src/data/graphics/trainers`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/trainers.h).
3. Add trainer to [`include/constants/trainers.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/trainers.h),

## The Graphics

### 1. Add the sprites
We will start with a graphic that we want to use for our new trainer pic. Unlike with adding Pokémon, the trainer sprites aren't sorted in individual folders, but rather in one folder: [`graphics/trainers/back_pics`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/graphics/trainers/back_pics).

**Remember to limit yourself to 16 colors including transparency in the first slot!**

### 2. Register the sprites
Sadly, just putting the image files into the graphics folder is not enough. To use the sprites we have to register them by linking the graphic files in [`src/data/graphics/trainers`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/trainers.h):
```diff
 const u8 gTrainerBackPic_Wally[] = INCBIN_U8("graphics/trainers/back_pics/wally.4bpp");
 const u8 gTrainerBackPic_Steven[] = INCBIN_U8("graphics/trainers/back_pics/steven.4bpp");
+const u8 gTrainerBackPic_NewOne[] = INCBIN_U8("graphics/trainers/back_pics/new_one.4bpp");

 const u16 gTrainerBackPicPalette_Red[] = INCBIN_U16("graphics/trainers/back_pics/red.gbapal");
 const u16 gTrainerBackPicPalette_Leaf[] = INCBIN_U16("graphics/trainers/back_pics/leaf.gbapal");
+const u16 gTrainerBackPicPalette_NewOne[] = INCBIN_U16("graphics/trainers/back_pics/new_one.gbapal");
```

### 3. Connecting the Pictures to the Data
The last few things we have to do is prepare the graphics for usage. In [`src/data/graphics/trainers.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/trainers.h) you'll find the `gTrainerBacksprites` struct, we need to add the trainer to this. You can just copy the last trainer type defined and edit it, but this is what it does: Connects the new trainer with the image we defined earlier.

So, finally, it needs to look like this:
```diff
 #define TRAINER_BACK_SPRITE(trainerPic, yOffset, sprite, pal, anim)                          \
     [trainerPic] =                                                                           \
     {                                                                                        \
         .coordinates = {.size = 8, .y_offset = yOffset},                                     \
         .backPic = {.data = sprite, .size = TRAINER_PIC_SIZE, .relativeFrames = TRUE},       \
         .palette = {.data = pal, .tag = trainerPic},                                         \
         .animation = anim,                                                                   \
     }

 const struct TrainerBacksprite gTrainerBacksprites[] =
 {
     TRAINER_BACK_SPRITE(TRAINER_BACK_PIC_BRENDAN, 4, gTrainerBackPic_Brendan, gTrainerPalette_Brendan, sBackAnims_Hoenn),
     ...
     TRAINER_BACK_SPRITE(TRAINER_BACK_PIC_STEVEN, 4, gTrainerBackPic_Steven, gTrainerPalette_Steven, sBackAnims_Hoenn),
+    TRAINER_BACK_SPRITE(TRAINER_BACK_PIC_NEW_ONE, 4, gTrainerBackPic_NewOne, gTrainerBackPicPalette_NewOne, sBackAnims_Hoenn),
};
```

Note: If you have your back pic structured like FRLG Red (which uses 5 frames instead of 4), change the `4` to `5` and the `sBackAnims_Hoenn` to `sBackAnims_Kanto`.

### The Data
#### 4. Defining the trainer back pic
Finally, let's bring it all together by defining our new trainer pic in [`include/constants/trainers.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/trainers.h):

```diff
 #define TRAINER_BACK_PIC_WALLY                  6
 #define TRAINER_BACK_PIC_STEVEN                 7
+#define TRAINER_BACK_PIC_NEW_ONE                8
```
Remember to count the number next to the trainer pic up by one!

## Usage
You can test your new trainer back pic by going to [`src/data/battle_partners.party`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/battle_partners.party) and change the `Pic` field. For example:
```diff
 === PARTNER_STEVEN ===
 Name: STEVEN
 Class: Rival
-Pic: Steven
+Pic: New One
 Gender: Male
 Music: Male
```

Otherwise if you use [`src/data/battle_partners.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/battle_partners.h), change the `trainerPic` field instead. For example:
```diff
     [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
     {
         .trainerName = _("STEVEN"),
         .trainerClass = TRAINER_CLASS_RIVAL,
-        .trainerPic = TRAINER_BACK_PIC_STEVEN,
+        .trainerPic = TRAINER_BACK_PIC_NEW_ONE,
         .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
```
