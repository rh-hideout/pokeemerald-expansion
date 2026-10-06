# Safari Zones

## Safari Basics

In Expansion, a safari is a special event that
- limits the number of steps that you can take
- can be ended by using "RETIRE" from the overworld start menu
- modifies some mechanics about encounters and battles
Once a safari ends, the player is warped to a predetermined location and a var set to explain how the safari ended
so that a script can appropriately respond to the outcome

In Expansion, the default safaris are the Route 121 Safari Zone from Emerald and the Fuschia City Safari Zone from FRLG but you can easily edit them or create new safaris

While the Safari Zone maps are exclusive to the safari mode in vanilla Emerald or FRLG, a safari state can occur anywhere using any number of maps.
Being in a safari is a game state and it is not tied to any specific location

In Expansion, safari ids are defined as `enum SafariEvents` in `include/constants/safaris` so that they can be called in scripts
and the actual safari properties are defined in `sSafariZones` in `src/data/safaris.h`

## Safari Properties

A safari's properties are contained in its `struct SafariData`, so let's go over each field of the struct:
- `rules` can be either `RSE_SAFARI` or `FRLG_SAFARI`, which determines two of the wild encounter battle actions in the safari as either "Bait" and "Rock", as in FRLG, or "Pokeblock" and "Go Near" like in Emerald
- `startingBalls` is the number of Safari balls you will have when starting the safari
- `startingSteps` is the number of steps the player will have before the safari ends
- `catchMultiplier` is a multiplier applied to your catch rate during the safari. In Expansion, the Safari Ball has the same catch multiplier as a PokeBall to match gen 8 behaviour, so this is used to simulate increase catch rate in Safari Zone. You can stack it with regular ball multipliers. The value will be divided by 100 so 150 is a 1.5 multiplier
- `exitWarpOnWhiteout` is a flag and if it's set to TRUE, the player wil warp to the safari exit warp instead of last heal location if they whiteout during safari
- `exitWarp` is a `struct WarpData` that indicates where the player will be warped to when the safari ends
- `noEscape` is a flag and if it's set to TRUE, it will prevent the player from using Escape Rope or field moves like Dig, Teleport and Fly


## Script commands

`getactivesafari` sets VAR_RESULT to the currently active safariId, returns 0/SAFARI_EVENT_NONE if there is no active safari

`safari_enter` let you start a safari. The command must be used with an `enum SafariEvents` argument, defined in `include/constants/safaris.h`

`safari_exit` will end the active safari and warps the player to the safari exit location

`safari_exitnowarp` ends the safari but does not warp the player

Both `safari_exit` and `safari_exitnowarp` will not set `VAR_SAFARI_ZONE_STATE` allowing it to be used to trigger post-exit map scripts

## Understanding `VAR_SAFARI_ZONE_STATE`

`VAR_SAFARI_ZONE_STATE` is set by the when starting or finishing a safari and it can be used to set up scripts that trigger when a safari starts or ends.
However the value of the var is not maintained outside of these specific states and the value should not be used to check if the player is in a safari.
The possible values for `VAR_SAFARI_ZONE_STATE` are defined in `include/constants/safaris.h` and are accessible by scripts.
`ENTERING_SAFARI_ZONE` is used to indicate a safari is starting
`SAFARI_ZONE_NO_STEP_LEFT`, `SAFARI_ZONE_NO_BALLS_LEFT`, `SAFARI_ZONE_NO_BALLS_MID_BATTLE`, `SAFARI_ZONE_RETIRING` are used when a safari ends and indicate how the safari was ending in case you want to have different post-exit events.
The difference between `SAFARI_ZONE_NO_BALLS_LEFT` and `SAFARI_ZONE_NO_BALLS_MID_BATTLE` is that if you capture a pokemon with your last ball, the safari ends from the overworld instead of the battle. These are distinct, despite being similar, to match the way vanilla safari scripts work.
`SAFARI_ZONE_WHITEOUT` only occurs if the safari has the `exitWarpOnWhiteout` flag and indicate that the player ended their safari by having all their pokemon knocked out