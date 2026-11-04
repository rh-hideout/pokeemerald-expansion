# Dependencies — root first

This is a **prerequisite graph**, not a claim that every design document must wait for the entire prior layer. Explore ideas in parallel, but **do not finalize downstream storage, behavior or world layouts against unknown foundations**.

## Layer 0 — roots

| Root decision | Status | What depends on it |
|---|---|---|
| **Code foundation** | **Decided:** `rh-hideout/pokeemerald-expansion` fork | Supported species, forms, engine APIs, collision and battle features |
| **Save and runtime budgets** | **Unmeasured:** inspect actual save layouts and available ROM/EWRAM/IWRAM | Persistent record sizes, NPC/creature caps, map object limits and simulation complexity |
| **World clock and catch-up policy** | **Decided:** game-session time only; fully paused while closed; no offline catch-up. [Specification](root/world-clock.md) | Hunger, routines, growth, weather and ecology |
| **Individual identity and records** | **Tiered persistence decided:** notable individuals permanently tracked, ordinary populations abstracted. [Specification](root/individual-persistence.md); binary layout pending save budget | Persistent wild Pokémon, mounts, captured individuals, trainer Pokémon if included |

### Essential root details to answer

1. **Save:** What space is genuinely free and compatible with existing save data? Which state persists, and what is recreated?
2. **Clock:** In-game-only time is decided. Still specify exact day length, menus/pause semantics, and how existing RTC-based berry and weather systems integrate.
3. **Identity:** Tiered persistence and both promotion pathways (meaningful player interaction + independent ecosystem events) are locked. Specify thresholds, stable IDs, ownership transitions, capture, fainting, movement, boxed Pokémon and NPC teams without duplicating canonical Pokémon data.
4. **Compatibility:** Which Expansion species and features are enabled in the actual build? Which engine budgets are already consumed?

The record is a **shared identity contract**, not necessarily one identical serialized layout for every person and Pokémon. Human NPC state may need a separate record. Do not assign a record byte count or population cap before measurement.

## Layer 1 — foundations of simulation

| System | Direct prerequisites |
|---|---|
| Species and habitat traits (diet, terrain, behavior, travel ability) | Codebase and actual species list |
| Persistent ID/record storage | Save budget, time policy and identity contract |
| Hunger, food, regrowth | Time policy, species traits, per-entity state |
| Dynamic population persistence and replenishment | **Dynamic ecology locked:** food, reproduction, decline and recovery; requires habitat traits, in-game time, aggregate storage, and bounded updates. [Specification](root/population-ecology.md) |
| Hybrid reproduction and notable families | **Hybrid policy locked:** abstract births plus persistent family relationships; requires population accounting, identity, species traits, clock and save capacity. [Specification](root/hybrid-reproduction.md) |
| Ecological cross-region migration | Habitat connectivity graph, species traversal traits, persistent identity, clock and off-screen updates; [specification](root/ecological-migration.md) |
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
3. **Implement the chosen in-game world clock** with no offline catch-up; decide its rate, pause semantics and berry/RTC integration.
4. **Specify and test** individual identity and persistence using measured limits.
5. **Prototype one vertical slice**: a small safe area, one persistent wild creature, food consumption and an off-screen update.
6. Add NPC routines, movement and danger behaviors with bounded tests.
7. Finalize Meadowmere layouts based on what the systems can truly support; expand to other regions only after proving the slice.

**Root decisions can be researched in parallel.** A region's names, theme and lore can be drafted early, but mechanical design and record counts must not be treated as fixed until their prerequisites are checked.

## Unresolved root questions for the next discussion

- World clock **locked:** in-game-only, no offline catch-up. Remaining questions: rate, menu/pause behavior and RTC integration.
- Save strategy: compact per-entity records, pooled records, existing Pokémon data reuse, and migration across updates?
- Ecological cross-region migration is locked; its graph, motivations and travel rates remain to be designed.
- Dynamic population ecology is locked; reproduction rates, carrying capacity, aggregate granularity and recovery safeguards remain to be designed.
- Hybrid reproduction is locked; nest/egg lifecycle, family-reference format, juvenile promotion and capacity handling remain to be designed.
- Exact tiered identity lifecycle: promotion, catch, release, NPC ownership and generation of new wild individuals?

The clock source and no-offline-progression rule are locked. No record size, population cap or day length is locked.
