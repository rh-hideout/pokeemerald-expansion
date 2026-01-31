#ifndef GUARD_CONFIG_WILD_ENCOUNTER_OVERWORLD_H
#define GUARD_CONFIG_WILD_ENCOUNTER_OVERWORLD_H

// Vanilla
#define WE_VANILLA_RANDOM                   TRUE    // If TRUE, Pokémon can randomly spawn on tiles that can trigger wild encounters, as in vanilla.

// Overworld Wild Encounters
#define WE_OW_ENCOUNTERS                    FALSE   // If TRUE, OW Pokémon can spawn as overworld wild encounters on the current map. Requires OW_POKEMON_OBJECT_EVENTS.
                                                    // If WE_OW_ENCOUNTERS is TRUE, it is recommended that OW_GFX_COMPRESS be set to FALSE to prevent VRAM issues.s
#define WE_OWE_BATTLE_PIKE                  TRUE    // If TRUE, overworld wild encounters can spawn in the Battle Pike, if FALSE random encounters will be enabled instead. Requires WE_OW_ENCOUNTERS to be TRUE.
#define WE_OWE_BATTLE_PYRAMID               TRUE    // If TRUE, overworld wild encounters can spawn in the Battle Pyramid, if FALSE random encounters will be enabled instead. Requires WE_OW_ENCOUNTERS to be TRUE.
#define WE_OWE_RESTRICT_METATILE            TRUE    // If TRUE, OW Pokémon spawned as overworld wild encounters will stay within tiles with the same encounter metatile behavior as the one it is currently on, if any.
#define WE_OWE_RESTRICT_MAP                 TRUE    // If TRUE, OW Pokémon spawned as overworld wild encounters will stay within their current map bounds.
#define WE_OWE_UNRESTRICT_SIGHT             FALSE   // If TRUE, OW Pokémon spawned as overworld wild encounters will ignore all movement restrictions when they can see the player.
#define WE_OWE_SPAWN_REPLACEMENT            FALSE   // If TRUE, the oldest OW wild encounter objects will despawn after a short time and be replaced with a new spawn if possible.
#define WE_OWE_FLEE_DESPAWN                 TRUE    // If TRUE, a fleeing OW Pokémon will despawn if it is unable to take a step for a short time.
#define WE_OWE_SHINY_SPARKLE                FALSE   // If TRUE, a shiny overworld wild encounter will spawn with a sparkle animation and play the shiny sound effect.
#define WE_OWE_FEEBAS_SPOTS                 FALSE   // If TRUE, any spot that could result in a Feebas fishing encounter can spawn a Feebas overworld wild encounter.
#define WE_OWE_DESPAWN_SOUND                TRUE    // If TRUE, plays SE_FLEE when an overworld wild encounter despawns.
#define WE_OWE_APPROACH_FOR_BATTLE          TRUE    // If TRUE, the mon will take steps to be right next to the player before the battle starts.
#define WE_OWE_PREVENT_SHINY_DESPAWN        FALSE   // If TRUE, shiny OW Pokémon objects will not be despawned when off-screen if on the same map as the player, or be replaced if WE_OWE_SPAWN_REPLACEMENT is TRUE.
#define WE_OWE_PREVENT_FEEBAS_DESPAWN       FALSE   // If TRUE, Feebas OW objects spawned from special Feebas fishing spots (when WE_OWE_FEEBAS_SPOTS is TRUE) will not be despawned when off-screen if on the same map as the player, or be replaced if WE_OWE_SPAWN_REPLACEMENT is TRUE.
#define WE_OWE_DESPAWN_ON_ENTER_TOWN        TRUE    // If TRUE, despawns all OW wild encounter objects upon entering a city or town (MAP_TYPE_TOWN or MAP_TYPE_CITY).
#define WE_OWE_REPEL_DEXNAV_COLLISION       FALSE   // If TRUE, overworld wild encounters can still be triggered by a collision if a Repel or the DexNav is active.

// Should Move Other Configs?

#endif // GUARD_CONFIG_WILD_ENCOUNTER_OVERWORLD_H
