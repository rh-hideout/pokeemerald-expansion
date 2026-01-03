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
