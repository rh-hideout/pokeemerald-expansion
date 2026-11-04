# Design Overview

A survival-flavored, open-world Pokemon game on pokeemerald-expansion. Safe by default, dangerous by choice, alive everywhere. Story is a side thing. This file groups every idea and points to the detail docs.

## 1. World and regions (`regions.md`, `exploration.md`)

- 14 fresh regions, none copied from official Pokemon regions: Meadowmere (start), Neonport (hub), Veyra, Tundrael, Sandara, Mistvale, Cragmoor, Sunreach Steppe, Verdant Maw, Duskhollow, The Abyss, Undervale, Skyreach, Ur-Kalah.
- Open world: no linear path, no forced battles, no forced story.
- Wide but dense: something worth stopping for in every stretch.
- Each region has a defining quirk and its own tileset.
- All 1,000+ species, imported through pokeemerald-expansion.

## 2. Danger (`danger-and-ecosystem.md`, `hazards.md`)

- Four levels: Safe, Calm, Wild, Perilous.
- Danger is local, readable and optional. The player is never ambushed.
- Environmental hazards (storms, whirlpools, rockfalls, hostile flyers) are the counterweight to powerful travel.
- Ur-Kalah is the near-uncivilized continent with no gyms and no leader.

## 3. Pokemon and ecosystem (`ecosystem-simulation.md`)

- Every notable Pokemon is a tracked individual: it faints, recovers, grows, evolves and remembers the player.
- Wild Pokemon are visible on the map with behaviors: passive, skittish, territorial, predator.
- Real food chain. Off-screen creatures are updated in bulk, not simulated live.
- Natural placement: species live where their biology puts them, and rarity is a result, not a quota.

## 4. Survival (`berries.md`, covers food and survival)

- Everyone eats: the player, NPCs, wild Pokemon and the player's party.
- Berries are the base food, with cooked food, meat, fish and roots added.
- Hunger states: Fed, Peckish, Hungry, Starving. Starving means weakness and collapse, never death.
- Scarcity follows danger level.

## 5. People (`living-npcs.md`, `trainers-and-gyms.md`)

- NPCs have homes, routines, needs, wants and relationships, and they live whether or not the player is watching.
- Gym leaders can be away from their gyms. Nothing about their presence is scripted.
- Trainers may challenge the player, who can decline.
- Each gym region has its own 8 badges, and leaders react to the player's badges through lore.

## 6. Traversal (`traversal.md`, `riding-and-mounts.md`, `hazards.md`)

- Ledges are climbable routes, not one-way drops.
- Pokemon act as mounts across land, water and air, with direct control and real flight.
- Mounts have stamina, hunger and trust.
- Hazards and natural scarcity balance the power of good mounts.

## Doc index

| File | Topic |
|---|---|
| `overview.md` | This file |
| `dependencies.md` | What depends on what |
| `regions.md` | World and region list |
| `exploration.md` | Density and discovery |
| `danger-and-ecosystem.md` | Danger levels and behavior |
| `ecosystem-simulation.md` | Individuals and simulation |
| `berries.md` | Food and survival |
| `living-npcs.md` | Autonomous NPCs |
| `trainers-and-gyms.md` | Trainers, badges, leaders |
| `traversal.md` | Climbing and terrain |
| `riding-and-mounts.md` | Mounts |
| `hazards.md` | Hazards and natural placement |

## Known gaps

- `berries.md` should be renamed to a survival-oriented name.
- Root spec (code base, save budget, clock, individual record) is not yet written.
- Gym types, leaders and lore per region are not yet designed.
- Species tagging and distribution are not yet done.
