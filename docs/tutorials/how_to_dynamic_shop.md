# How to Use Dynamic Shop

## Overview

![Showcase](/docs/tutorials/img/dynamic_shop/showcase.gif)

This is a feature for the Shop Menu to allow developers to have a shop with automagically added items based off a certain Criteria. In the core series games, items are gated behind badge progression - this feature allows for that an further expands it to gate items based on any criteria the developer wants.

## Usage

To use this feature, simply use `pokemart` in a script without any arguments.
```
MartScript::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
```

Using `pokemart 0` also works.

## What is a Criteria?

Criteria is the meat that helps the code automagically add items. By default, no items will be added to the shop as you'll need to explicitly set the criteria for desired items. This prevents unintended items from appearing.

A Criteria is split into two parts:
- a *goal* for the minimum requirement of a criteria (if necessary), and
- a *function* for checking if the criteria is fulfilled.

For example, a badge count Criteria would need a goal for the minimum amount of badges the player owns and a function for checking if the player has said minimum amount.

## Adding Criteria to an Item

Adding a Criteria to an Item is simple enough, you'd just add the fields at the bottom of an item's data:
```diff
     [ITEM_POKE_BALL] =
     {
         .name = ITEM_NAME("Poké Ball"),
         .price = 200,
         .description = COMPOUND_STRING(
             "A tool used for\n"
             "catching wild\n"
             "Pokémon."),
         .pocket = POCKET_POKE_BALLS,
         .type = ITEM_USE_BAG_MENU,
         .battleUsage = EFFECT_ITEM_THROW_BALL,
         .secondaryId = BALL_POKE,
         .iconPic = gItemIcon_PokeBall,
         .iconPalette = gItemIconPalette_PokeBall,
+        .shopCriteriaGoal = <goal>,
+        .shopCriteriaFunc = <func>,
     },
```

`.shopCriteriaGoal` typically depends on what Criteria function you're using for `.shopScriteriaFunc`, below are Criteria functions that are shipped by default.

### `ShopCriteriaByNothing`
This function only returns `FALSE`, this is the failsafe function that prevents unintended items from being added. There is no reason to use it explicitly, all items will have this Criteria unless otherwise defined.

### `ShopCriteriaByTheStart`
This function only returns `TRUE`, the opposite of `Nothing`. This lets you always add the item regardless of any conditions.
```diff
     [ITEM_POKE_BALL] =
     {
         .name = ITEM_NAME("Poké Ball"),
         .price = 200,
         .description = COMPOUND_STRING(
             "A tool used for\n"
             "catching wild\n"
             "Pokémon."),
         .pocket = POCKET_POKE_BALLS,
         .type = ITEM_USE_BAG_MENU,
         .battleUsage = EFFECT_ITEM_THROW_BALL,
         .secondaryId = BALL_POKE,
         .iconPic = gItemIcon_PokeBall,
         .iconPalette = gItemIconPalette_PokeBall,
+        .shopCriteriaFunc = ShopCriteriaByTheStart,
     },
```

In this example, regardless of `shopCriteriaGoal`, PokeBalls will always be available for purchase from dynamic shops.

### `ShopCriteriaByBadgeCount`
This function is what you'll probably be using the most. It has the goal of a certain number of badges the player owns.
```diff
     [ITEM_ULTRA_BALL] =
     {
         .name = ITEM_NAME("Ultra Ball"),
         .price = (I_PRICE >= GEN_7) ? 800 : 1200,
         .description = COMPOUND_STRING(
                 "A better Ball with\n"
                 "a higher catch rate\n"
                 "than a Great Ball."),
         .pocket = POCKET_POKE_BALLS,
         .type = ITEM_USE_BAG_MENU,
         .battleUsage = EFFECT_ITEM_THROW_BALL,
         .secondaryId = BALL_ULTRA,
         .iconPic = gItemIcon_UltraBall,
         .iconPalette = gItemIconPalette_UltraBall,
+        .shopCriteriaGoal = 6,
+        .shopCriteriaFunc = ShopCriteriaByBadgeCount,
    },
```

Here, Ultra Balls will appear in the dynamic shop if the player has 6 or more badges.

### `ShopCriteriaByFlag`
This function is basically what `BadgeCount` partially do, but you'd explicitly use one flag instead. Useful if you need a certain badge flag instead of just the amount, or a quest-only item. The goal uses the flag ids found in [`include/constants/flags.h`](/include/constants/flags.h), like `FLAG_BADGE07_GET`, and returns depending on if the flag is set or not.
```diff
     [ITEM_MASTER_BALL] =
     {
         .name = ITEM_NAME("Master Ball"),
         .price = 0,
         .description = COMPOUND_STRING(
                 "The best Ball that\n"
                 "catches a Pokémon\n"
                 "without fail."),
         .pocket = POCKET_POKE_BALLS,
         .type = ITEM_USE_BAG_MENU,
         .battleUsage = EFFECT_ITEM_THROW_BALL,
         .secondaryId = BALL_MASTER,
         .iconPic = gItemIcon_MasterBall,
         .iconPalette = gItemIconPalette_MasterBall,
+        .shopCriteriaGoal = FLAG_SYS_GAME_CLEAR,
+        .shopCriteriaFunc = ShopCriteriaByFlag,
     },
```

Master Balls will be able available in the dynamic shop after the player defeated the Champion.

### `ShopCriteriaByVar`
This function is basically the `Flag` function but with variables instead. The goal is both the variable id found in [`include/constants/vars.h`](/include/constants/vars.h) and a value to compare with said variable id. *Be sure to use `WRITE_CRITERIA_GOAL_VAR` for setting the `.shopCriteriaGoal`*, like so: `.shopCriteriaGoal = WRITE_CRITERIA_GOAL_VAR(VAR_LITTLEROOT_TOWN_STATE, 3)`
```diff
     [ITEM_FERALIGITE] =
     {
         .name = ITEM_NAME("Feraligite"),
         .price = 0,
         .holdEffect = HOLD_EFFECT_MEGA_STONE,
         .description = COMPOUND_STRING(
             "This stone enables\n"
             "Feraligatr to Mega\n"
             "Evolve in battle."),
         .pocket = POCKET_ITEMS,
         .sortType = ITEM_TYPE_MEGA_STONE,
         .type = ITEM_USE_BAG_MENU,
         .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
         .flingPower = 80,
         .iconPic = gItemIcon_QuestionMark, // gItemIcon_Feraligite,
         .iconPalette = gItemIconPalette_QuestionMark, // gItemIconPalette_Feraligite,
+        .shopCriteriaGoal = WRITE_CRITERIA_GOAL_VAR(VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6),
+        .shopCriteriaFunc = ShopCriteriaByVar,
     },
```

This will add Feraligite to dynamic shops once the player has recieved the Johto Starter from Professor Birch.

## Create a Custom Criteria
But what if you need a specific criteria that cannot be covered by the default shipped criterias? Well, you can write your own! Here's how:

First, we'll add a function for our criteria in [`src/shop_criteria.c`](/src/shop_criteria.c), preferably at the bottom of the file, like so:
```diff
 }
+
+bool32 ShopCriteriaByMyNeed(u32 itemId)
+{
+    // add your stuff here, be sure to handle both boolean values!
+}
```

Then, you'll need to add a declaration for your custom function so that it can be used by your items.
```diff
 bool32 ShopCriteriaByVar(u32 itemId);
+bool32 ShopCriteriaByMyNeed(u32 itemId);

 #endif // GUARD_SHOP_CRITERIA_H
```

And that's it! You should now be good to go and can immediately use that function for your items. Don't forget to set the goal as well if your function uses it, too.
```diff
     [ITEM_POKE_BALL] =
     {
         .name = ITEM_NAME("Poké Ball"),
         .price = 200,
         .description = COMPOUND_STRING(
             "A tool used for\n"
             "catching wild\n"
             "Pokémon."),
         .pocket = POCKET_POKE_BALLS,
         .type = ITEM_USE_BAG_MENU,
         .battleUsage = EFFECT_ITEM_THROW_BALL,
         .secondaryId = BALL_POKE,
         .iconPic = gItemIcon_PokeBall,
         .iconPalette = gItemIconPalette_PokeBall,
+        .shopCriteriaGoal = 0,
+        .shopCriteriaFunc = ShopCriteriaByMyNeed,
     },
```

### Specific Example

We want to allow the player to purchase the Light Ball, but only after they have already captured Pikachu and defeated Wattson's final rematch.

#### [`src/shop_criteria.c`](/src/shop_criteria.c)
```diff
+bool32 ShopCriteriaHasPikachu(u32 itemId)
+{
+    if (FlagGet(TRAINER_FLAGS_START + WATTSON_5) == FALSE)
+        return FALSE;
+
+    return (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_PIKACHU), FLAG_GET_CAUGHT));
+}
```

#### [`include/shop_criteria.h`](/include/shop_criteria.h)
```diff
+bool32 ShopCriteriaHasPikachu(u32 itemId);
```

#### [`src/data/items`](/src/data/items.c)
```diff
     [ITEM_LIGHT_BALL] =
     {
         .name = ITEM_NAME("Light Ball"),
         .price = (I_PRICE >= GEN_7) ? 1000 : 100,
         .holdEffect = HOLD_EFFECT_LIGHT_BALL,
         .description = COMPOUND_STRING(
                 "A hold item that\n"
                 "raises the Atk and\n"
                 "Sp. Atk of Pikachu."),
         .pocket = POCKET_ITEMS,
         .sortType = ITEM_TYPE_HELD_ITEM,
         .type = ITEM_USE_BAG_MENU,
         .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
         .flingPower = 30,
         .iconPic = gItemIcon_LightBall,
         .iconPalette = gItemIconPalette_LightBall,
+        .shopCriteriaGoal = TRUE,
+        .shopCriteriaFunc = ShopCriteriaHasPikachu,
      },
```
