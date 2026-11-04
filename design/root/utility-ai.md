# Utility-based wild Pokémon AI — design decision

**Decision: LOCKED (2026-11-04).** Wild Pokémon choose actions by evaluating competing needs and opportunities with a **utility-based behavior selector**. Urgency, species traits, personality, memories, relationships, local environment and immediate threats influence their choices. **Hard safety overrides** handle urgent danger or invalid actions. This is not a mandate for a full multi-step planner.

## Why

Rain World inspires creatures with independent needs, not fixed roles. The same Pokémon can forage, guard offspring, flee, rest, explore, cooperate or migrate as circumstances change. The player is not always its focus.

## Locked principles

1. **Dynamic action selection.** Eligible behaviors receive contextual utility based on current state. No permanently assigned camper/rusher/predator role determines every action.
2. **Safety and validity first.** Immediate hazards, incapacitation, blocked terrain, inaccessible targets and impossible actions override or filter ordinary utility choices.
3. **Personality and species matter.** A cautious creature and a bold one may respond differently to the same stimuli; species capabilities constrain actions. Notable individuals' dispositions can gradually evolve through meaningful experiences. See [Evolving personality](evolving-personality.md).
4. **Memory and relationships matter.** Significant trust, fear, rivalry and family ties can change utility and reactions. See [Social memory](social-memory.md).
5. **Ecology matters.** Hunger, available food, territorial pressure, weather, predators, prey, nesting and migration motivations influence choices.
6. **Behavior is not player-centric.** Pokémon can interact with other Pokémon and the habitat while the player is absent.
7. **Simulation fidelity is tiered.** Nearby creatures evaluate and execute concrete actions; off-screen notable individuals advance through coarse decisions/events; ordinary populations update through aggregates.
8. **Bounded CPU and memory.** No per-frame global all-Pokémon scoring, exhaustive search or unbounded pathfinding. Evaluation cadence, candidate set and caching require performance tests.
9. **Avoid indecision.** The implementation must prevent rapid oscillation between equally attractive behaviors, e.g. through action commitment, cooldowns or hysteresis.
10. **In-game-only time.** Need changes and off-screen decisions do not progress while the game is closed.
11. **Player-facing fairness.** Threats should be telegraphed and escapable according to local danger rules; AI sophistication must not create unavoidable surprise attacks.

## Conceptual decision loop — not implemented code

`perceive local context -> filter invalid/unsafe actions -> apply urgent safety overrides -> score eligible actions -> choose/commit -> execute -> observe outcome -> update needs and memories`

Potential candidate actions: idle, rest, forage, drink, patrol, seek shelter, defend territory, protect offspring, flee, approach friend, avoid rival, explore, pursue prey, migrate. These are examples, not a locked exhaustive behavior list.

### Example

A notable Pokémon with high hunger may choose to forage instead of patrolling. If its offspring are threatened, protective urgency changes the selected action. After the threat passes, the same individual may return to feeding or decide to move its nest. Its prior memories influence whom it approaches or avoids.

## Architectural boundaries

- **Decision selection** is distinct from movement/pathfinding, animation, collision, battle resolution, ecological accounting and persistent identity.
- A utility score is a relative action preference, **not** a guarantee that the action is reachable or safe.
- Hard overrides should be narrowly defined so they do not erase personality or create forced aggression.
- Off-screen decisions must remain coherent with the visible world without simulating all detailed steps.
- Species traits, utility weights and action availability should be data-driven where feasible; exact format awaits engine and ROM budget checks.

## Open parameters

- Action catalog and which actions are supported in the first vertical slice.
- Utility scoring formula, weight ranges and personality representation.
- Evaluation frequency, action commitment and interrupt policy.
- Perception radius, line-of-sight, hearing and event signals.
- Navigation/pathfinding algorithm and object-event budget.
- Determinism, random variation, save/reload consistency and test instrumentation.
- Off-screen utility approximation and transition between detailed and abstract simulation.

No CPU cost, entity limit, fixed utility weights or record size is claimed until measured.

## Acceptance scenarios

1. The same Pokémon changes from foraging to protecting its offspring when circumstances change.
2. Two individuals of the same species with different traits make different plausible choices.
3. A known rival is avoided or confronted differently than an unknown Pokémon based on selective memory.
4. A distant notable Pokémon can migrate or forage without an active overworld sprite or full pathfinding.
5. No invalid action crosses impassable terrain, and an urgent danger override interrupts appropriately.
6. Repeated simulation does not rapidly flip between actions or exceed a bounded update budget.
7. Closing the game causes no additional decisions or hunger changes.

See [Social memory](social-memory.md), [Individual persistence](individual-persistence.md), [Population ecology](population-ecology.md), and [World clock](world-clock.md).
