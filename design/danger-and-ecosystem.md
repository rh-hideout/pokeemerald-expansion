# Danger and Ecosystem

The world is a living ecosystem, not a difficulty ladder. Strong, average and weak Pokemon all exist. Nothing forces a fight, and danger is always readable.

**Encounter design (locked):** Pokémon are observable overworld creatures, with noncombat interactions and optional traditional battles; hostile behavior remains readable and avoidable where appropriate. See [Hybrid wild encounters](root/hybrid-wild-encounters.md).

## Danger levels

| Level | Feel | What lives there |
|---|---|---|
| **Safe** | Towns, farms, shrines | No hostile wild Pokemon, weak passives wander freely |
| **Calm** | Most routes | Mostly weak and average, a rare territorial one |
| **Wild** | Deep forest, caves, open sea | Territorial and predator Pokemon are common |
| **Perilous** | Peaks, volcano cores, ruins, deep trenches | Strong apex Pokemon, no safety net |

## Wild Pokemon behavior

- **Passive:** ignores the player (grazers, small Pokemon).
- **Skittish:** flees on approach.
- **Territorial:** warns first, then chases if the player stays.
- **Predator:** hunts weaker Pokemon and may chase the player.

Wild Pokemon are visible on the map (overworld encounters), not random grass ambushes.

## Telegraphing

- Tracks and scars: claw marks, flattened grass, broken trees.
- Silence: ambient sounds stop when a predator is near.
- Fleeing Pokemon running away from something.
- Music drops to a low tone in Perilous zones.
- Signs and NPC warnings.

## Rules

- There are no unavoidable surprise attacks. Nearby threats are visible or clearly telegraphed before they become unavoidable; stalking enemies can still create tension.
- Escape is real: territorial Pokemon only chase within their range.
- Camps and shrines inside Wild and Perilous zones allow rest and healing.
- Risk pays: Perilous zones hold rare Pokemon, rare items and hidden lore.
- Strong Pokemon live where their habitat, diet and territory support them; rarity follows ecology rather than designer-enforced quotas.

## Example local danger areas (draft)

These are examples within the **14 original regions** in [Regions](regions.md), not a complete regional table. Typical danger for all regions is maintained in that file.

| Region | Typical danger | Proposed high-risk location |
|---|---|---|
| Veyra | Wild | The Drowned Stair (tide-flooded ruin) |
| Tundrael | Wild | Glacier Heart (blizzard cavern) |
| Sandara | Wild | The Buried City |
| Mistvale | Wild | The Sunken Bog |
| Cragmoor | Calm to Wild | Ironfang Peak |
| Neonport | Safe to Calm | Undercity Tunnels |
| Skyreach | Wild | The Storm Crown |
| Ur-Kalah | Perilous | The Heart |

No official Hoenn region is part of the planned new world. Other locations remain to be designed.

## Engine notes

Visible overworld Pokemon are possible in pokeemerald but need custom movement AI in C and testing. No level scaling is needed since players choose their exposure.
