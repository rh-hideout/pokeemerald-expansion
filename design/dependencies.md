# Dependencies: root first

A **prerequisite graph**, not a claim that every document must wait for the whole prior layer. Explore ideas in parallel, but **do not finalize downstream storage, behavior or layouts against unknown foundations**. Decision status is in [STATUS.md](STATUS.md).

## Layer 0: roots

| Root | Status | What depends on it |
|---|---|---|
| Code foundation: `rh-hideout/pokeemerald-expansion` fork | Locked | Species, forms, engine APIs, collision and battle features |
| Save and runtime budgets | Unmeasured. See [save budget](root/save-budget.md) | Record sizes, NPC and creature caps, object limits, simulation complexity |
| World clock | Proposed: in-game time only, awaiting owner confirmation. See [world clock](root/world-clock.md) | Hunger, routines, growth, weather, ecology |
| Individual identity and records | Tiered persistence locked; layout pending budget. See [persistence](root/individual-persistence.md) | Persistent wild Pokemon, mounts, captured individuals, trainer Pokemon if included |

Core pillars that constrain everything below: [balanced sandbox](root/balanced-pokemon-sandbox.md), [parallel progression](root/parallel-player-progression.md), [hybrid encounters](root/hybrid-wild-encounters.md) and [hybrid geography](root/hybrid-world-geography.md).

### Root questions

1. **Save:** what space is genuinely free and compatible with existing saves? What persists and what is recreated?
2. **Clock:** exact day length, pause semantics, and how existing RTC-based berry and weather systems integrate.
3. **Identity:** promotion thresholds, stable IDs, ownership transitions, capture, fainting, boxed Pokemon and NPC teams, without duplicating canonical Pokemon data.
4. **Compatibility:** which Expansion species and features are enabled in the real build, and what budgets are already used.

The record is a shared identity contract, not necessarily one serialized layout for every entity. NPC state may need a separate record. Assign no byte counts or population caps before measurement.

## Layer 1: simulation foundations

| System | Status | Direct prerequisites |
|---|---|---|
| Species and habitat traits | Proposed | Codebase, actual species list |
| Persistent ID and record storage | Proposed | Save budget, clock, identity contract |
| Hunger, food, regrowth | Locked principle | Clock, species traits, per-entity state |
| Population ecology and abstract births | Proposed | Habitat traits, clock, aggregate storage, bounded updates |
| Utility-based wild behavior | Proposed | Needs, traits, safe action filtering, bounded scheduling |
| Hybrid Pokemon navigation | Proposed | Map connectivity, traversal tags, bounded CPU |
| Ecological migration | Proposed | Habitat graph, traversal traits, identity, clock |
| Off-screen scheduler, catch-up, adaptive priority | Proposed | Clock, progress markers, ecology, identity, measured CPU and save budgets |
| Shared NPC and Pokemon events | Proposed | NPC routines, identities, clock, scheduler, event accounting |
| Tiered NPC persistence | Proposed | Save budget, scheduler, shared events, identity reconciliation |
| NPC routines and utility | Proposed | Clock, needs, relationships, shared events, navigation, scheduler |
| Pokemon social memory, personality, perception depth, family trees | Aspirational | Persistent identity, utility AI, save capacity |
| NPC social memory, personality, perception, navigation graph, information sharing, groups, long-term goals, planning, resources | Aspirational | Tiered NPC persistence, shared events, scheduler, measured save budget |
| Regional dynamic economy | Aspirational | Resource accounting, world routes, shared events, scheduler, save budget |

## Layer 2: behavior, life and movement

| System | Direct prerequisites |
|---|---|
| Wild Pokemon visible behavior | Species traits, nearby entity and state handling |
| Food chains and ecosystem change | Hunger, habitat, population, off-screen updates |
| Living NPC schedules and needs | Clock, NPC state, food, off-screen updates |
| Player traversal and stamina | Terrain rules, species abilities, food and time |
| Mount riding, trust and stamina | Pokemon identity, traversal, needs, weather |
| Environmental hazards | Terrain, weather and time, relevant wild behavior |
| Optional trainers and moving gym leaders | NPC schedules, trainer and battle state, badge data |

## Layer 3: content and presentation

| Content | Needs before finalization |
|---|---|
| Map layouts, habitats, region connections | Traversal rules, species habitat model, hazards, performance budget |
| Discovery and region quirks | Map layout, clock and weather variation, NPC and ecosystem systems |
| Gym circuits, leader personalities, badge lore | Which regions have gyms, leader autonomy, badge data |
| Species distribution | Species tags, biome topology, population rules |
| UI, saves, player feedback | Stable state and clock semantics, accessible danger and hunger cues |

## Practical sequence

1. **Expansion fork confirmed.** Leave its engine code unchanged while refining the design.
2. **Gate A:** compile the unchanged fork, record ROM size and linker memory, smoke-test in an emulator.
3. **Gate B:** enable and test the existing overworld-encounter system on an isolated branch.
4. **Measure save and memory limits** in this codebase, including existing expansion storage and compatibility.
5. **Confirm and implement the world clock**, with no offline catch-up. Decide rate, pause rules and berry and RTC integration.
6. **Gate C:** specify and test individual identity and persistence against measured limits.
7. **Gate D:** vertical slice of a compact Meadowmere: one persistent wild Pokemon, food consumption, an off-screen update, one independent NPC, and a save and reload check.
8. Add NPC routines and danger behaviors with bounded tests. Revisit Aspirational items only after the slice proves the budget.
9. Finalize Meadowmere layouts from what the systems truly support, then expand region by region.

A region's names, themes and lore can be drafted early. Mechanical design and record counts must not be treated as fixed until their prerequisites are checked.
