# Dependencies — root first

This is a **prerequisite graph**, not a claim that every design document must wait for the entire prior layer. Explore ideas in parallel, but **do not finalize downstream storage, behavior or world layouts against unknown foundations**.

## Layer 0 — roots

| Root decision | Status | What depends on it |
|---|---|---|
| **Code foundation** | **Decided:** `rh-hideout/pokeemerald-expansion` fork | Supported species, forms, engine APIs, collision and battle features |
| **Save and runtime budgets** | **Unmeasured:** inspect actual save layouts and available ROM/EWRAM/IWRAM | Persistent record sizes, NPC/creature caps, map object limits and simulation complexity |
| **World clock and catch-up policy** | **Undecided:** playable-time vs real-world time, pausing, deltas, caps | Hunger, routines, growth, weather, ecology and offline return behavior |
| **Individual identity and records** | **Undesigned:** requires save budget and time semantics | Persistent wild Pokémon, mounts, captured individuals, trainer Pokémon if included |

### Essential root details to answer

1. **Save:** What space is genuinely free and compatible with existing save data? Which state persists, and what is recreated?
2. **Clock:** What advances when playing, when paused, and when the game is closed? Are offline changes capped? Which systems follow which time source?
3. **Identity:** Which creatures receive permanent IDs? When do ordinary herds become persistent individuals? How are capture, fainting, movement, boxed Pokémon and NPC teams represented without duplicating canonical Pokémon data?
4. **Compatibility:** Which Expansion species and features are enabled in the actual build? Which engine budgets are already consumed?

The record is a **shared identity contract**, not necessarily one identical serialized layout for every person and Pokémon. Human NPC state may need a separate record. Do not assign a record byte count or population cap before measurement.

## Layer 1 — foundations of simulation

| System | Direct prerequisites |
|---|---|
| Species and habitat traits (diet, terrain, behavior, travel ability) | Codebase and actual species list |
| Persistent ID/record storage | Save budget, time policy and identity contract |
| Hunger, food, regrowth | Time policy, species traits, per-entity state |
| Population persistence and replenishment | IDs, habitat traits, available save capacity |
| Bounded off-screen update engine | Clock/catch-up policy, persistence, species traits and budget |

## Layer 2 — behavior, life and movement

| System | Direct prerequisites |
|---|---|
| Wild Pokémon visible behavior | Species traits, nearby entity/state handling |
| Food chains and ecosystem change | Hunger, habitat, population and off-screen updates |
| Living NPC schedules and needs | Clock, NPC state, food and off-screen updates |
| Player traversal and stamina | Terrain rules, species abilities, food/time |
| Mount riding, trust and stamina | Pokémon identity, traversal, needs and weather |
| Environmental hazards | Terrain, weather/time and relevant wild behavior |
| Optional trainers and moving gym leaders | NPC schedules, trainer/battle state and badge progression |

## Layer 3 — content and presentation

| Content | Needs before finalization |
|---|---|
| Map layouts, habitats and region connections | Traversal rules, species habitat model, hazards and performance budget |
| World discovery and region quirks | Map layout, clock/weather variations and NPC/ecosystem systems |
| Gym circuits, leader personalities and badge lore | Which regions have gyms, leader autonomy and badge data |
| Species distribution | Species tags, biome topology and population rules |
| UI, saves and player feedback | Stable state/clock semantics and accessible danger/hunger cues |

## Practical dependency sequence

1. **Confirm the Expansion fork** — done. Leave its engine code unchanged while refining the design.
2. **Measure real save and memory constraints** in this specific codebase, including pre-existing expansion storage and backward-compatibility requirements.
3. **Choose the world-clock policy** and how to cap/abstract time away from the player.
4. **Specify and test** individual identity and persistence using measured limits.
5. **Prototype one vertical slice**: a small safe area, one persistent wild creature, food consumption and an off-screen update.
6. Add NPC routines, movement and danger behaviors with bounded tests.
7. Finalize Meadowmere layouts based on what the systems can truly support; expand to other regions only after proving the slice.

**Root decisions can be researched in parallel.** A region's names, theme and lore can be drafted early, but mechanical design and record counts must not be treated as fixed until their prerequisites are checked.

## Unresolved root questions for the next discussion

- World time: game-session time, device real-time, or a carefully defined hybrid?
- Offline catch-up: none, bounded, or continuous?
- Save strategy: compact per-entity records, pooled records, existing Pokémon data reuse, and migration across updates?
- Exact identity lifecycle: catch, release, NPC ownership, migration and generation of new wild individuals?

No clock choice or record size is locked by this document.
