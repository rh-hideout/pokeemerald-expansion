#ifndef GUARD_CONFIG_OVERWORLD_ENCOUNTERS_H
#define GUARD_CONFIG_OVERWORLD_ENCOUNTERS_H

// If OWE_WILD_ENCOUNTERS_OVERWORLD is TRUE, it is recommended that OW_GFX_COMPRESS be set to FALSE to prevent VRAM issues.

#define OWE_VANILLA_RANDOM_ENCOUNTERS                   TRUE    // If TRUE, Pokémon can randomly spawn on tiles that can trigger wild encounters, as in vanilla.
#define OWE_WILD_ENCOUNTERS_OVERWORLD                   FALSE   // If TRUE, OW Pokémon can spawn as overworld wild encounters on the current map. Requires OW_POKEMON_OBJECT_EVENTS.
#define OWE_WILD_ENCOUNTERS_BATTLE_PIKE                 TRUE    // If TRUE, overworld wild encounters can spawn in the Battle Pike, if FALSE random encounters will be enabled instead. Requires OWE_WILD_ENCOUNTERS_OVERWORLD to be TRUE.
#define OWE_WILD_ENCOUNTERS_BATTLE_PYRAMID              TRUE    // If TRUE, overworld wild encounters can spawn in the Battle Pyramid, if FALSE random encounters will be enabled instead. Requires OWE_WILD_ENCOUNTERS_OVERWORLD to be TRUE.
#define OWE_WILD_ENCOUNTERS_RESTRICT_METATILE           TRUE    // If TRUE, OW Pokémon spawned as overworld wild encounters will stay within tiles with the same encounter metatile behavior as the one it is currently on, if any.
#define OWE_WILD_ENCOUNTERS_RESTRICT_MAP                TRUE    // If TRUE, OW Pokémon spawned as overworld wild encounters will stay within their current map bounds.
#define OWE_WILD_ENCOUNTERS_UNRESTRICT_SIGHT            FALSE   // If TRUE, OW Pokémon spawned as overworld wild encounters will ignore all movement restrictions when they can see the player.
#define OWE_WILD_ENCOUNTERS_SPAWN_REPLACEMENT           FALSE   // If TRUE, the oldest OW wild encounter objects will despawn after a short time and be replaced with a new spawn if possible.
#define OWE_WILD_ENCOUNTERS_FLEE_DESPAWN                TRUE    // If TRUE, a fleeing OW Pokémon will despawn if it is unable to take a step for a short time.
#define OWE_VANILLA_AMBIENT_CRIES                       TRUE    // If TRUE, the ambient wild Pokémon cries will play on routes with encounter tables.
#define OWE_WILD_ENCOUNTERS_AMBIENT_CRIES               TRUE    // If TRUE, generated overworld encounters will play ambient cries based on their location relative to the player.
#define OWE_WILD_ENCOUNTERS_SHINY_SPARKLE               FALSE   // If TRUE, a shiny overworld wild encounter will spawn with a sparkle animation and play the shiny sound effect.
#define OWE_WILD_ENCOUNTERS_FEEBAS_SPOTS                FALSE   // If TRUE, any spot that could result in a Feebas fishing encounter can spawn a Feebas overworld wild encounter.
#define OWE_WILD_ENCOUNTERS_DESPAWN_SOUND               TRUE    // If TRUE, plays SE_FLEE when an overworld wild encounter despawns.
#define OWE_WILD_ENCOUNTERS_APPROACH_FOR_BATTLE         TRUE    // If TRUE, the mon will take steps to be right next to the player before the battle starts.
#define OWE_WILD_ENCOUNTERS_PREVENT_SHINY_REPLACEMENT   TRUE    // If TRUE, shiny OW Pokémon objects will not be despawned if OWE_WILD_ENCOUNTERS_SPAWN_REPLACEMENT is TRUE.
#define OWE_WILD_ENCOUNTERS_PREVENT_FEEBAS_REPLACEMENT  TRUE    // If TRUE, Feebas OW objects spawned from special Feebas fishing spots (when OWE_WILD_ENCOUNTERS_FEEBAS_SPOTS is TRUE) will not be despawned if OWE_WILD_ENCOUNTERS_SPAWN_REPLACEMENT is TRUE.

#endif // GUARD_CONFIG_OVERWORLD_ENCOUNTERS_H
