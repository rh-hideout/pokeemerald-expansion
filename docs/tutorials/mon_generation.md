# Generation of struct Pokemon instances

This document describes the ways you generate an instance of struct Pokemon through script or through code.
These Pokemon can be given to your players, be used as enemy trainer pokemon or as static wild pokemon.

## Through script (`givemon` and `createmon`)

### `createmon`

`createmon` is a script command that allows you to generate a pokemon with any of the properties you might want.
It has a lot of arguments in order to offer this flexibility.
`side`, `slot`, `species` and `level` are the required arguments
`side` determines if the pokemon will be created as a player pokemon or an enemy pokemon: 0 will put the pokemon in the player party and 1 in the enemy party
`slot` determines the slot in the player or enemy party the pokemon will occupy. `slot` goes from 0 to 5 but if `side` is 0 (player pokemon), setting the slot to 6 will instead give the pokemon to player automatically putting it in the first empty slot or sending it to the PC when the party is the full. (Setting `slot` to 6 when trying to create an enemy pokemon will result in the `createmon` command being ignored)
`species` and `level` refers to the species id and the level of the pokemon you want to generate
`item`, `ball`, `nature`, `abilityNum`, `gender`, `hpEv`, `atkEv`, `defEv`, `speedEv`, `spAtkEv`, `spDefEv`, `hpIv`, `atkIv`, `defIv`, `speedIv`, `spAtkIv`, `spDefIv`, `move1`, `move2`, `move3`, `move4`, `shinyMode`, `gmaxFactor`, `teraType`, `dmaxLevel` are the optional arguments. They are pretty explicit in what they refer to but let's describe what they default to when they are not present.
`item` refers to the item the mon is holding. If the argument is missing, the mon won't be holding anything
`ball` refers to the type of ball the pokemon comes out of. This defaults to a PokeBall and if you are generating a wildmon, this will be overwritten if the pokemon is captured
`nature`, and `gender` will default to random values
`abilityNum` will default to the value corresponding to the personality they will roll (in practice, it's random but it will have correlations with other if the pokemon parameters)
`hpEv`, `atkEv`, `defEv`, `speedEv`, `spAtkEv`, `spDefEv` will default to 0
`hpIv`, `atkIv`, `defIv`, `speedIv`, `spAtkIv`, `spDefIv` will default to `USE_RANDOM_IVS` which tell the game to roll a random IV value (between 0 and 31). If the generated species has a `perfectIVCount`, only the random values will be eligible to be perfected.
`move1`, `move2`, `move3`, `move4` will default to `MOVE_DEFAULT` which tells the game to fill the slot with the last level up move available
`shinyMode` will default to SHINY_MODE_RANDOM doing random roll(s) to check if the mon is shiny. (The other possibile values for shinyMode are SHINY_MODE_ALWAYS and SHINY_MODE_NEVER to force the pokemon to be shiny or not be shiny respectively)
`gmaxFactor` default to FALSE
`teraType` will default to the value corresponding to the personality they will roll (in practice, it's random but it will have correlations with other if the pokemon parameters)
`dmaxLevel` will deafult to 0

### `givemon`

`givemon` uses the same arguments as `createmon` minus `side` and `slot`. This is because `givemon` is almost equivalent to `createmon 0 6 ...` and just gives the mon to the player after generating it. The exception being that `givemon` interacts with the abilities `Synchronize` and `Cute Charm` slightly differently than `createmon` when `nature` or `gender` are not explicitly set.

### `setwildbattle (species:req, level:req, item=ITEM_NONE, species2=SPECIES_NONE, level2=0, item2=ITEM_NONE)`

`setwildbattle` is a much simpler way to generate a wildmon ready for the player to fight.
It only takes 3 arguments (or 6 if you want to make it a double wild battle)
`species` and `level` refers to the species id and the level of the pokemon you want to generate
`item` refers to the item the mon is holding. If the argument is missing, the mon won't be holding anything
`species2`, `level2`, and `item2` are relate to the species, level and item of the second mon generated in case you want to make a double wild battle
The other properties will like IVs and personality will be set random just like for a regular wild battle
Mons generated with `setwildbattle` will always be considered static encounters (STATIC_WILDMON_ORIGIN) and will thus be eligible to be affected by Synchronize and Cute Charm

### Synchronize and Cute Charm

`nature` and `gender` also accept `NATURE_MAY_SYNCHRONIZE` and `MON_GENDER_MAY_CUTE_CHARM` respectively as arguments
`NATURE_RANDOM` and `MON_GENDER_RANDOM` always return a random nature/gender and never check for Synchronize or Cute Charm. If you want the generated mon to have a chance to receive the effcets of Synchronize or Cute Charm, you need to use `NATURE_MAY_SYNCHRONIZE` and `MON_GENDER_MAY_CUTE_CHARM` respectively for nature and gender.
When you use `NATURE_MAY_SYNCHRONIZE` or `MON_GENDER_MAY_CUTE_CHARM`, you are telling the game can check if the player has a pokemon with Synchronize or Cute Charm in the first slot of its party and roll a die to see if the nature or gender should be fixed based on the ability or rolled normally.
The mon generated also need to be of the right "origin" to be eligible for Synchronize or Cute Charm. We don't want to "synchronize" a mon belonging to a trainer or change the gender of a gift mon with Cute Charm. So if a mon is generated for the player side, it will be considered a "gift mon" (GIFTMON_ORIGIN) and if a mon is generated on the enemy side, it will be considered a static wild encounter (STATIC_WILDMON_ORIGIN). 
`givemon` will default to use `NATURE_MAY_SYNCHRONIZE` and `MON_GENDER_MAY_CUTE_CHARM` because we assume you will use givemon to create "gift mons" but if you don't want it to apply in a specific script, you can explicitly use `NATURE_RANDOM` and `MON_GENDER_RANDOM` instead
`createmon` on the other hand default to `NATURE_RANDOM` and `MON_GENDER_RANDOM` so you need to explicitly use `NATURE_MAY_SYNCHRONIZE` or `MON_GENDER_MAY_CUTE_CHARM` for the generated mon to be considered a gift mon or a static wild encounter
Static encounters and Gift mons eligibility to Synchronize vary through generations in the official games so you can use the config `OW_SYNCHRONIZE_NATURE` to match your preference or you can check the `src/ow_synchronize.c` to modify the Synchronize and Cute Charm eligibility of different origins however you like

## Through Code

A lot of places in the game generate mons, when you start a wild encounter, when a trainer generates its party from the data in trainers.party or even when you call one of the script described in the previous section. So let's go through some of the most common functions.
Note: None of the functions described here allocate memory for the Pokemon struct, they all expect a pointer they will fill the data with.
It means they are usually called with `&gPlayerParty[index]` or `&gEnemyParty[index]` because these are places in memory reserved for Pokemon struct.

### The basics

To generate a mon ready for battle, you usually need to go through these steps:
- generate a personality value
- fill the generic mon structure based on species, level and personality
- set IVs and EVs
- (re-)compute stats (this step does not happen if you are generating a `struct boxPokemon` instead of `struct Pokemon`)
- set the moves

### `GetMonPersonality`

`GetMonPersonality` is the easiest way to make a personality value. It takes 4 arguments `species`, `gender`, `nature` and `unownLetter` then it rolls random personality values until it finds one that match all the selected criteria.
For example, if you want a personality for Wally's male Ralts, you would write:
`personality = GetMonPersonality(SPECIES_RALTS, MON_MALE, NATURE_RANDOM, RANDOM_UNOWN_LETTER);`
and if you want a personality for a brave J Unown, you would write
`personality = GetMonPersonality(SPECIES_UNOWN, MON_GENDER_RANDOM, NATURE_BRAVE, 9);` (J is the 10th letter of alphabet but for unown A starts at 0 so B is 1 and J is 9)
As you can see, you can use either a specific value or a special value `MON_GENDER_RANDOM`, `NATURE_RANDOM` or `RANDOM_UNOWN_LETTER` to tell the function to return any pokemon matching the other properties. This means, writing:
`personality = GetMonPersonality(SPECIES_X, MON_GENDER_RANDOM, NATURE_RANDOM, RANDOM_UNOWN_LETTER);`
id equivalent to
`personality = Random32();`
which is why `Random32()` is used throughout to generate a personality value in certain circumstances

### `CreateMon` and `CreateBoxMon`

`CreateMon` is the most basic function to create a generic Pokemon struct. It takes 5 arguments:
`mon` is a pointer to the mon struct you want to set the data for
`species` and `level` are fairly explicit
`personality` is the personality value you want to use to create your mon, it will determine a lot of your mon properties and will usually be a number that you generated by following the instructions from the previous section
`trainerID` is a special type of struct that explain how the function should set up the otId of the pokemon. Usually you will want to use one of these 3 macros for the argument:
`OTID_STRUCT_PLAYER_ID` which means the pokemon should the player otId (used for wildmon so they the get the player id when captured)
`OTID_STRUCT_PRESET(value)` which set a specific otId that you pick/write yourself
`OTID_STRUCT_RANDOM_NO_SHINY` which picks a random otId and forces the mon to not be shiny even if the random otId and chosen personality would have made the mon shiny. It is used by NPC trainers.
Both `CreateMon` and `CreateBoxMon` erase the pokemon data in the pointer before they add the new data so every value they don't set will be zero-ed in some way. This is why they are considered "base" functions.
The values set by `CreateMon` and `CreateBoxMon` are the gender, ability num, tera type and nature (based on personality); the met info (location, level and game), the original trainer name, gender and language (always set to the player even for enemy trainer mons), the starting xp (based on the xp required to reach the level the pokemon is at), the starting friendship (based on the species info) and the shinyness.
`CreateMon` and `CreateBoxMon` are very similar. In fact, the `CreateMon` function calls `CreateBoxMon` to generate the boxmon part of its structure but it also sets the level and a mail object (to an empty value)

### Setting IVs and EVs

Usually, you will want to use `SetBoxMonIVs(mon->box, ivs)` to set the ivs of the pokemon you are generating. The reason is that not only can you quickly set all ivs of your mon to a single value: `SetBoxMonIVs(mon->box, 15)` will set all IVs to 15. You can also use the special argument `USE_RANDOM_IVS`. When used with `USE_RANDOM_IVS`, `SetBoxMonIvs` will not only pick a random value between 0 and 31 for each stat, it will also allocate some perfect iv if the species of the mon has a perfectIvCount set in the species data. For example if you are generating a legendary with a perfectIvCount of 3, using `SetBoxMonIVs(mon->box, USE_RANDOM_IVS)` will guarantee that at least 3 IVs are set to 31
The other way to assign IV is to use `SetMonData`, for example:
`SetMonData(mon, MON_DATA_HP_IV, 15)`
with the stats being in order `MON_DATA_HP_IV`, `MON_DATA_ATK_IV`, `MON_DATA_DEF_IV`, `MON_DATA_SPEED_IV`, `MON_DATA_SPATK_IV` and `MON_DATA_SPDEF_IV`
You can also use a loop like this:
```c
for (i = 0; i < NUM_STATS; i++)
    SetMonData(mon, MON_DATA_HP_IV + i, iv_array[i])
```
if you happen to have an array containing the values you want but be careful about the order if you use this method
EVs default to 0 when a mon is generated with `CreateMon` or `CreateBoxMon` so you may not need to anything if you want to keep it that way. If you want to change them, there are currently no utilities to set EVs at the moment so you will need to use the `SetMonData` method as well:
`SetMonData(mon, MON_DATA_HP_EV, 252)`
The stats have the same names as the IVs with I cheange into an E : `MON_DATA_HP_EV`, `MON_DATA_ATK_EV`, `MON_DATA_DEF_EV`, `MON_DATA_SPEED_EV`, `MON_DATA_SPATK_EV` and `MON_DATA_SPDEF_EV` so the loop method works here too
```c
for (i = 0; i < NUM_STATS; i++)
    SetMonData(mon, MON_DATA_HP_EV + i, ev_array[i])
```
Just be careful when setting IVs and EVs with SetMonData because they are no check to make sure the IV and EV values you are setting are valid and this may cause some issues.

### `CalculateMonStats`

After all the IVs and EVs have been set for your mon, it's important to run `CalculateMonStats(mon)`. The function only has one argument so it's pretty simple but don't forget this step or you may have some isseus

### Setting moves

To set a move in slot `slot`, you would need to write:
```c
enum Move move = MOVE_X;
u32 pp = GetMovePP(move);
SetMonData(mon, MON_DATA_MOVE1 + slot, &move);
SetMonData(mon, MON_DATA_PP1 + slot, &spp);
```
where slot can be between 0 and 3 to represent the 1st to 4th move
You can also call the function `GiveMonInitialMoveset(mon)` that will give your pokemon its last 4 level-up moves available similarly to the wild pokemon you might enciunter

## Going from 1.14 to 1.15

When going from 1.14 to 1.15, Expansion deleted multiple functions related to mon generation that were not used in Expansion anymore.
The following functions were deleted
```c
void CreateMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 nature);
void CreateMonWithGenderNatureLetter(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 gender, u8 nature, u8 unownLetter);
void CreateMonWithIVsOTID(struct Pokemon *mon, u16 species, u8 level, u8 *ivs, u32 otId);
void CreateMonWithEVSpread(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 evSpread);
void CreateMonWithEVSpreadNatureOTID(struct Pokemon *mon, u16 species, u8 level, u8 nature, u8 fixedIV, u8 evSpread, u32 otId);
```
If you add custom code relying on those functions, I would advise to simple recode them using the methods described in the previous section. If you follow the steps, you should be able to rewrite a function with the same effect easily.

However the move to 1.15 also completely rewrote these two functions:
```c
void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);
void CreateBoxMon(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);
```
`CreateMon` and `CreateBoxMon` now have different arguments and do less things than their 1.14 counterparts. If you have code that used those functions, we recommend you use these legacy version of `CreateMon` and `CreateBoxMon`:
```c
void CreateMonLegacy(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u32 personality = hasFixedPersonality ? fixedPersonality : Random32();
    struct OriginalTrainerId otId = {otIdType, fixedOtId};
    CreateMonWithIVs(mon, species, level, personality, otId, fixedIV);
    GiveMonInitialMoveset(mon);
}

void CreateBoxMonLegacy(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u32 personality = hasFixedPersonality ? fixedPersonality : Random32();
    struct OriginalTrainerId otId = {otIdType, fixedOtId};
    CreateBoxMon(boxMon, species, level, personality, otId);
    SetBoxMonIVs(boxMon, fixedIV);
    GiveBoxMonInitialMoveset(boxMon);
}
```
These two legacy functions use the 1.15 functions to recreate the 1.14 versions of `CreateMon` and `CreateBoxMon` with the same arguments and the same effects. Add these two legacy functions to your code then change your custom code that was relying on 1.14 `CreateMon` or `CreateBoxMon` to use `CreateMonLegacy` or `CreateBoxMonLegacy` instead and everything should work the same as before
