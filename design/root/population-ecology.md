# Dynamic population ecology — root design decision

**Decision: LOCKED (2026-11-04).** Wild Pokémon populations can reproduce, expand, decline, migrate, and recover in response to ecological conditions. Populations are **not fixed encounter quotas** and are **not permitted to grow without simulation safeguards**.

## Intent

Borrow Rain World's independent ecological relationships and off-screen consequences, not a mandatory global pressure timer. The world is alive when the player is elsewhere; its dynamics are not scripted around player arrival. Safe regions remain approachable even as local species abundance changes.

## Locked principles

1. **Dynamic populations:** local abundance responds to food, habitat capacity, predators, weather, disease or other environmental pressure, competition and migration.
2. **Natural replenishment:** breeding, immigration and habitat recovery can restore depleted populations over in-game time. No instant magical replacement of a captured individual.
3. **Local scarcity and abundance are possible:** habitats may temporarily lose or gain species. No universal static spawn quota or forced rarity balancing.
4. **Bounded ecology:** population calculations must avoid unbounded growth, negative counts, numerical overflow and runaway performance costs. Exact ecological carrying capacities and recovery rates are **not yet fixed**.
5. **No permanent save soft-lock:** ecological changes must not irreversibly block essential progress, food or basic movement; recovery pathways or appropriate alternatives are required. This is a playability constraint, not a promise of identical abundance everywhere.
6. **Identity stays distinct:** ordinary creatures are represented as habitat aggregates; promoted persistent individuals keep identity. Births and migration do not silently clone or erase persistent Pokémon.
7. **Ecological migration:** aggregate populations and persistent individuals may move along plausible species-accessible habitat connections. See [Ecological migration](ecological-migration.md).
8. **Time:** changes happen only as in-game time advances. Closing the game freezes all ecological processes.
9. **Off-screen efficiency:** use bounded batch updates rather than frame-by-frame simulation of every distant Pokémon.

## Conceptual habitat state (not a binary record)

- Habitat ID and environmental conditions
- Species or ecological-group population abundance
- Available food and habitat capacity
- Predator/prey and competition pressure
- Reproduction and recovery readiness
- Incoming/outgoing migration
- Last processed in-game timestamp

These are candidate logical fields; storage layout, grouping, and precision depend on actual measured save and memory budgets.

## Proposed update flow (not a finalized formula)

`food and habitat -> survival/reproduction pressure -> births and recovery -> predation/competition -> migration -> bounded resulting population`

Fainting is not death: predator encounters can cause temporary incapacitation, displacement, resource competition and reduced breeding success. Population decline must not be modeled as Pokémon being permanently killed by default.

### Population accounting invariant

**A Pokémon promoted from an anonymous population must not also remain counted as an anonymous member of that same habitat.** Similarly, capture or movement of a persistent Pokémon must not decrement an unrelated aggregate a second time. The exact representation for births, juveniles, and ownership transfers remains to be designed.

## Open parameters

- Species-specific reproduction and maturity rates
- How carrying capacity is calculated from food and territory
- What constitutes a habitat and how many population aggregates fit in save memory
- How population counts respond to fainting versus capture
- Ecological recovery when a species is locally absent
- Stable bounds and how the simulation handles saturation or empty habitats
- How to make changes observable through sightings, tracks, NPC rumors and food availability

No numerical rates, population caps or save record sizes are locked.

## Acceptance scenarios

1. Food improves in a suitable habitat; a prey species gradually becomes more abundant over in-game days, subject to capacity.
2. Predators increase pressure; prey abundance falls and predators may migrate rather than being permanently deleted.
3. After habitat recovery or immigration, a locally depleted species can return without an instantaneous respawn.
4. A memorable persistent Pokémon migrates without being duplicated or silently replaced by an aggregate.
5. The player closes the game for a week; no births, declines or migrations occur while closed.
6. Very long in-game play does not overflow population counters or cause unbounded off-screen processing.

See [Ecosystem simulation](../ecosystem-simulation.md), [Individual persistence](individual-persistence.md), [Ecological migration](ecological-migration.md), and [World clock](world-clock.md).
