# Safari Zones

## Safari Basics

In Expansion, a safari is a special event that
- is limited in the number of steps you take
- can be ended at any time by using "RETIRE" from the start menu
- modifies how some things work in the game.
Once a safari ends, the player is warped to a predetermined location and a var set to explain how the safari ended
so that a acript can appropriately respond to what occur

In Expansion,the default safaris are the Route 121 Safari Zone from Emerald and the Fuschia City Safari Zone from FRLG but you can easily edit them or create new safaris

While the Safari Zones maps are exclusive to the safari mode in vanilla Emerald or FRLG, a safari can occur anywhere using any number of maps.
Being in a safari is a game state and it is not tied to any specific location

In Expansion, safari ids are defined as `enum SafariIds` in `include/constants/safaris` so that they can be called in scripts
And the actual safari properties is defined in `sSafariZones` in `src/data/safaris.h`

## Safari Properties

A safari properties are contained in its `struct SafariZone`, so let's over each field of the struct:
- `rules` can be either `RSE_SAFARI` or `FRLG_SAFARI` and it determines if wild encounter in the safari will use bait and rock like FRLG or pokeblock and go near like Emerald
- `startingBalls` is the number of Safari balls you will have when starting the safari
- `startingSteps` is the number of steps the player will have before the safari ends
- `catchMultiplier` is a multiplier applied to your catch rate during safari, in Expansion, the Safari Ball has the same catch multiplier as a PokeBall to match gen 8 behavior so this is used to simulate increase catch rate in Safari Zone but you can stack it with regular ball multipliers. The value will be divided by 100 so 150 is a 1.5 multiplier
- `exitWarpOnWhiteout` is a flag and if it's set to TRUE, the player wil warp to the safari exit warp instead of last heal location if they get whiteout uring safari
- `exitWarp` is a `struct Warp Data` that indicates where the player will be warped to when the safari ends
- `noEscape` is a flag and if it's set to TRUE, it will prevent the player from using Escape Rope or field moves like Dig, Teleport and Fly


## Script commands

`getactivesafri` sets VAR_RESULT to the currently active safariId, returns 0/NONE_SAFARI if there is no active safari

`entersafari` let you start a safari. The command must be used with a `enum SafariIds` argument, defined in `include/constants/safaris`

`exitsafari` will end the active safari and warps the player to the safari exit location

`exitsafari_nowarp` ends the safari but does not warp the player

Both `exitsafari` and `exitsafari_nowarp` will not set `VAR_SAFARI_ZONE_STATE` because it is assumed to be in the developer perview to set up potential script follow-ups

## Understanding `VAR_SAFARI_ZONE_STATE`

`VAR_SAFARI_ZONE_STATE` is set by the when starting or finishing a safari and it can be used to set up scripts that trigger when a safari starts or ends.
However the value of the var is not maintained outside of these specific states and the value should not be used to check if the player is in a safari.
The possible values for `VAR_SAFARI_ZONE_STATE` are defined in `include/constants/safaris` and are accesible by script.
`ENTERING_SAFARI_ZONE` is used to indicate a safari is starting
`SAFARI_ZONE_NO_STEP_LEFT`, `SAFARI_ZONE_NO_BALLS_LEFT`, `SAFARI_ZONE_NO_BALLS_MID_BATTLE`, `SAFARI_ZONE_RETIRING` are used when a safari ends and indicate how the safari was ending in case you want to have different reactions.
The difference between `SAFARI_ZONE_NO_BALLS_LEFT` and `SAFARI_ZONE_NO_BALLS_MID_BATTLE` is that if you capture a pokemon with your last ball, the safari ends from the overworld insetad of the battle. There are distinct despite being similar to match the way vanilla safari scripts work.
`SAFARI_ZONE_WHITEOUT` only occurs if the safari has the `exitWarpOnWhiteout` flag and indicate that the player ended their safari by having all their pokemon knowcked out