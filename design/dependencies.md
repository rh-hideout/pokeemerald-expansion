# Dependencies

Each layer needs the one above it. Nothing in a lower layer can be finalized before the layers it depends on.

## Layer 0: Root

| Piece | Why everything depends on it |
|---|---|
| **Code base** (pokeemerald-expansion) | Sets species support, forms and battle mechanics |
| **Save-space budget** | Caps how much tracked state can exist |
| **World clock** | Drives hunger, growth, weather, day and night, and off-screen updates |
| **Individual record** | One data format for any tracked creature: species, level, home, hunger, state, history |

## Layer 1: Simulation

| System | Needs |
|---|---|
| Species tags (diet, habitat, behavior, traversal traits) | Individual record |
| Hunger and food | Clock, individual record |
| Ecosystem behavior and off-screen update | Clock, individual record, species tags, hunger |

## Layer 2: Life and movement

| System | Needs |
|---|---|
| Living NPCs | Clock, hunger, off-screen update |
| Traversal and stamina | Hunger, species traits |
| Mounts | Individual record, hunger, stamina, species traits |
| Hazards | Clock and weather, wild Pokemon behavior |

## Layer 3: World content

| Content | Needs |
|---|---|
| Maps and regions | Ecosystem, traversal, hazards (natural placement and vertical layouts shape layouts) |
| Exploration details and region quirks | Maps, traversal, hazards |
| Trainers, gyms and badge lore | Living NPCs, individual record |
| Species distribution | Species tags, regions and biomes |

## Build order

1. Code base set up (fork of pokeemerald-expansion).
2. Save budget measured, clock decided, individual record drafted (root spec).
3. Species tags and hunger.
4. Ecosystem and off-screen update.
5. NPC life, traversal, mounts and hazards.
6. First region (Meadowmere) built on top of all of the above.
7. More regions, one at a time, fully dense.

## Critical path

Root spec first, since save budget and the individual record bound everything else. If the budget is too small, the designs in Layers 1 and 2 shrink to fit, not the other way around.
