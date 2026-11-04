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
| Selective social memory | **Evolving relationships locked:** bounded salient memory and social references; requires persistent identity, significant-event signals, family ties, clock and save capacity. [Specification](root/social-memory.md) |
| Utility-based wild behavior selection | **Utility AI locked:** needs, traits, memory, perception, safe action filtering, and bounded scheduling. [Specification](root/utility-ai.md) |
| Evolving individual personality | **Experience-shaped traits locked:** species baselines, significant-event signals, persistent identity, utility AI and bounded updates. [Specification](root/evolving-personality.md) |
| Multi-sensory perception | **Environment-aware senses locked:** species traits, nearby event cues, terrain/lighting/weather and bounded detection feed utility AI. [Specification](root/multi-sensory-perception.md) |
| Hybrid Pokémon navigation | **Two-scale routing locked:** local collision/pathfinding plus species-accessible habitat/region graph; requires map connectivity, traversal tags and bounded CPU. [Specification](root/hybrid-navigation.md) |
| Ecological cross-region migration | Habitat connectivity graph, species traversal traits, persistent identity, clock and off-screen updates; [specification](root/ecological-migration.md) |
| Hybrid scheduled off-screen update engine | **Hybrid scheduler locked:** distributed in-game jobs plus bounded relevance catch-up; requires clock, persistence/progress markers, ecology, identity and measured CPU/save budgets. [Specification](root/offscreen-scheduler.md) |
| Hybrid catch-up strategy | **Aggregate ecology + selective notable events locked:** requires timestamp accounting, identity safety, cross-habitat reconciliation and bounded work. [Specification](root/hybrid-catchup.md) |
| Adaptive scheduler priority | **Relevance + urgency + fairness locked:** approaching habitats, consequential notable events and aged distant work share bounded scheduling time. [Specification](root/adaptive-scheduling.md) |
| Shared NPC–Pokémon events | **Consequential shared events locked:** NPC routines, Pokémon identities, world clock, scheduler, actor co-location, event accounting and relationship storage. [Specification](root/shared-world-events.md) |
| Tiered NPC persistence | **Notable identity + abstract crowds locked:** authored important NPCs and promoted individuals retain histories; depends on save budget, scheduler, shared events and identity reconciliation. [Specification](root/npc-persistence.md) |
| Hybrid NPC routines and utility | **Schedules + autonomous interruption locked:** requires in-game clock, needs, goals, relationships, safe action filtering, shared events, navigation and bounded scheduler. [Specification](root/npc-routine-utility.md) |
| Selective NPC social memory | **Meaningful bounded memories and evolving NPC–NPC/NPC–Pokémon relationships locked:** requires typed stable identity, tiered NPC persistence, shared events, in-game clock and save budget. [Specification](root/npc-social-memory.md) |
| Evolving NPC personality | **Slow experience-shaped traits locked:** requires tiered NPC persistence, significant shared events, social memory, utility behavior, in-game clock and save budget. [Specification](root/npc-evolving-personality.md) |
| Hybrid NPC navigation | **Bounded local routing + connected world-route travel locked:** requires actual map/transport topology, actor-specific access, in-game clock, persistent location, NPC goals and scheduler. [Specification](root/npc-hybrid-navigation.md) |
| Contextual NPC perception | **Bounded sight, hearing, environmental cues and off-screen approximation locked:** requires map visibility, nearby event cues, environmental state, identity-safe recognition, NPC utility AI and scheduler. [Specification](root/npc-contextual-perception.md) |
| Selective NPC information sharing | **Gradual imperfect rumor/news spread locked:** requires plausible perception, source provenance, NPC social memory, meetings/travel, shared events and bounded scheduler. [Specification](root/npc-information-sharing.md) |
| Dynamic NPC small groups | **Emergent small-group membership within stable institutions locked:** requires canonical NPC identities, social memory, utility decisions, plausible meetings, shared events, navigation and save budget. [Specification](root/npc-dynamic-groups.md) |
| Hybrid NPC long-term goals | **Authored commitments plus evolving ambitions locked:** requires tiered NPC persistence, personality, social memory, shared events, routine/utility behavior, travel and measured save budget. [Specification](root/npc-long-term-goals.md) |
| Hybrid hierarchical NPC planning | **Adaptive bounded milestones + utility actions locked:** requires long-term goals, NPC routines/utility, navigation, perception, shared events, scheduler and save budget. [Specification](root/npc-hierarchical-planning.md) |

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
- Selective social memory is locked; significance thresholds, memory priority, relationship reference format and limits remain to be designed.
- Utility-based wild AI is locked; action catalog, scoring, scheduling, navigation and off-screen approximation remain to be designed.
- Evolving personality is locked; trait dimensions, event thresholds, rates, save representation and Nature integration remain to be designed.
- Multi-sensory perception is locked; ranges, occlusion approximation, cue expiration and per-frame budgets remain to be designed.
- Hybrid navigation is locked; local algorithm, graph granularity, edge constraints, travel rates and reconciliation remain to be designed.
- Hybrid off-screen scheduling, hybrid catch-up and adaptive fairness are locked; job budgets, priority weights, fairness implementation, aggregate formulas, notable-event selection, atomic transfer rules and progress-marker serialization remain to be designed.
- Shared NPC–Pokémon events, tiered NPC persistence, hybrid NPC routine/utility behavior, selective NPC social memory, slow personality evolution, hybrid NPC navigation, contextual NPC perception, selective information sharing, dynamic NPC small groups, hybrid NPC long-term goals and hybrid hierarchical NPC planning are locked; NPC record layouts, trait dimensions/learning rates, relationship capacity/retention, promotion thresholds, schedule representation, utility scoring, ownership transfers, deduplication and event significance remain to be designed.
- Exact tiered identity lifecycle: promotion, catch, release, NPC ownership and generation of new wild individuals?

The clock source and no-offline-progression rule are locked. No record size, population cap or day length is locked.
