# Regions

A fresh world of 14 regions. None are copies of official Pokemon regions. The world is open: any region can be explored at any time. No linear path, and story is a side thing.

| # | Region | Biome | Typical danger |
|---|---|---|---|
| 1 | **Meadowmere** | Temperate meadows, farms, gentle hills | Safe |
| 2 | **Neonport** | Dense urban, bridges, rooftops | Safe to Calm |
| 3 | **Veyra** | Volcanic archipelago, tidal paths | Wild |
| 4 | **Tundrael** | Frozen north, glaciers, ice caves | Wild |
| 5 | **Sandara** | Desert, canyons, oases, ruins | Wild |
| 6 | **Mistvale** | Swamp, fog, dense forest | Wild |
| 7 | **Cragmoor** | Mountains, cliffs, mining valleys | Calm to Wild |
| 8 | **Sunreach Steppe** | Savanna, herds, long sightlines | Calm to Wild |
| 9 | **Verdant Maw** | Rainforest, jungle canopy | Wild |
| 10 | **Duskhollow** | Twilight ruins, fog, quiet and eerie | Wild |
| 11 | **The Abyss** | Open ocean, trenches, island chains | Wild to Perilous |
| 12 | **Undervale** | Underground caverns, lakes, fossil fields | Wild to Perilous |
| 13 | **Skyreach** | Floating islands, high altitude | Wild |
| 14 | **Ur-Kalah** | Untamed continent, almost no civilization | Perilous |

## Why these regions

Every biome exists so that the full Pokemon roster (all generations, 1,000+ species) has a believable home. Regions are added to fill habitat gaps, not for their own sake.

## Starting point and hub

- **Meadowmere** is the gentle starting area: safe, cozy, easy food.
- **Neonport** is the travel hub: urban, calm, many routes and ferries.
- The player is free to leave in any direction. The start is a suggestion, not a gate.

## Connections (draft)

- Land links: Meadowmere, Neonport, Cragmoor, Sunreach Steppe and Mistvale connect by land.
- Boat links from Neonport: Veyra, Tundrael, Sandara, Verdant Maw, The Abyss.
- Hidden or rare links: Undervale (cave mouths in other regions), Duskhollow (fog roads), Skyreach (high-altitude routes).
- **Ur-Kalah** has no ferry. Reaching it means following lore, a rare expedition boat, or a hidden route from a Perilous spot elsewhere.

## Map design principles

- Distinct tileset (palette and building style) per region.
- One signature city and one signature dungeon per region (Ur-Kalah and Undervale are exceptions).
- Regions are wide but dense with detail (see `exploration.md`).
- Each region gets its own map group and region map entries.
- Region map screen needs per-region art and `MAPSEC` entries (selector or one stitched map).
- Tile art and layout painting happen in Porymap.
- Build in phases: Meadowmere and one neighbor first, then the rest. The design stays complete while the build stays manageable.

## Ur-Kalah

No gyms, no leader, no cities, no ferries. Only camps, hermits, lost explorers and ruins.

| Biome | Feel | Signature danger |
|---|---|---|
| The Rootwood | Giant ancient trees, canopy paths | Apex predators hunt from above |
| The Bone Plains | Open grassland, fossil fields | Migrating herds, territorial stampedes |
| The Hollow Deep | Cave networks, glowing fungus | Darkness, warned territorial cave predators, cave-ins |
| The Ash Wastes | Dead volcanic land, toxic air | Poison and heat, few safe spots |
| The Heart | Central ruin of an unknown civilization | The strongest Pokemon in the game |

Rules: almost everything is Wild or Perilous, no fast travel inside, no map at first (the player fills it in), and rare Pokemon found nowhere else.

## Open questions

- Exact connection graph and travel methods between regions.
- Map counts per region (target: smaller and denser, to be set during build planning).
- Whether the existing Hoenn maps in the repo are reused as raw material (tilesets, scripts, structure).
