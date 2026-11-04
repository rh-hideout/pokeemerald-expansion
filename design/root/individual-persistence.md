# Tiered Pokémon persistence — root decision

**Decision: LOCKED (2026-11-04).** Use **tiered persistence**: notable individual Pokémon remain recognizable across visits and saves, while ordinary populations are represented abstractly until a particular individual becomes significant.

## Why

Inspired by Rain World's memorable autonomous creatures, this preserves relationships and consequences without requiring a GBA to serialize and simulate every Pokémon on the planet. **Persistence** (whether identity survives) and **simulation fidelity** (how much processing it receives right now) are separate axes.

## Identity tiers

| Tier | Saved state | Off-screen behavior |
|---|---|---|
| **Abstract population** | Habitat/population aggregate; no per-Pokémon permanent identity | Bounded aggregate food, movement, breeding/recovery or migration updates |
| **Persistent individual** | Stable identity, location/home, relevant condition and interaction history | Coarse individual updates without discarding identity |
| **Currently active** | A persistent individual, or a temporarily materialized member of a population, instantiated in nearby world/battle | Detailed behavior while visible/nearby; returns to its persistence tier afterward |

**Important:** Active is a runtime state, not automatically a third permanent storage class. An ordinary on-screen creature does not necessarily become permanently tracked merely by appearing. Rare species are not automatically special; significance, ecology and narrative context matter more than arbitrary rarity quotas.

## Locked invariants

1. **Identity survives distance.** A persistent Pokémon does not turn into a new random creature because the player left its map.
2. **Identity survives saves.** Its ID and important history persist after save/reload, within supported save compatibility.
3. **Promotion is one-way by default.** Once significant, an individual is not silently demoted to an anonymous population. Storage pressure must be handled explicitly, not by silently deleting memories.
4. **No duplicate creature.** A Pokémon cannot simultaneously be a wild persistent entity and a captured party/box Pokémon. Capture transfers ownership/representation.
5. **No automatic species rarity quota.** Habitat and ecological conditions shape distribution; special identity is not assigned simply to force rarity.
6. **Time source:** all off-screen updates consume the [in-game-only world clock](world-clock.md); closing the game does not advance populations or individuals.
7. **Fainting is not permanent death.** Individuals may recover; ecosystem replacement and breeding rules remain open.
8. **No unbounded per-frame simulation.** Abstract populations and off-screen individuals advance through bounded, deterministic or reproducible updates.
9. **Ecological cross-region migration is allowed.** Persistent wild Pokémon retain identity while moving through reachable habitats in response to needs and environmental conditions. See [Ecological migration](ecological-migration.md).

## Proposed lifecycle (needs exact implementation design)

`population -> temporary nearby encounter -> [promote if significant] persistent wild individual -> [capture] owned Pokémon`

Cross-region ecological migration is a locked capability; detailed journey state remains open. Other transitions such as release, transfer to NPC ownership, and return to the wild need explicit policies. The above is a **conceptual flow**, not code already implemented.

## Promotion policy — LOCKED: meaningful interactions AND autonomous ecosystem events

An ordinary Pokémon becomes persistent through either of two routes, independently:

1. **Meaningful player interaction (B):** a developed relationship, repeated meaningful encounters, rescue, bonding, consequential battle or comparable interaction. Mere visibility, a trivial battle or passing proximity does not necessarily promote it.
2. **Significant ecosystem event (C):** a Pokémon becomes notable through its **own actions**, even if the player has never met it — for example defending a territory over time, surviving a remarkable encounter, becoming a recognizable local figure, or changing an ecological relationship.

Both routes use the same identity system and produce a stable persistent individual. The ecosystem must not require the player to witness or trigger the event.

### Candidate promotion workflow (implementation proposal, not yet locked)

- Nearby untracked creatures may exist temporarily without permanent save records.
- Record meaningful interaction signals or notable event summaries in bounded temporary state.
- When significance criteria are met, atomically allocate a stable identity and transfer relevant temporary history to the persistent record.
- Deduplicate repeated events so one creature is not promoted multiple times.
- If capacity is exhausted, preserve existing persistent individuals; do not silently delete them. Define an explicit overflow policy after save-space measurement.

### Remaining decisions

- Exact event thresholds and how to prevent mass promotion from routine predator/prey interactions.
- Which authored/unique creatures should begin persistent, without relying on rarity quotas.
- What ecosystem evidence can be retained before promotion without storing every ordinary individual.
- How the player discovers off-screen notable individuals through tracks, rumors and changed habitats.
- Persistent pool capacity and safe overflow behavior.

**Not decided:** a single battle always promotes, every off-screen fight promotes, or rarity automatically grants identity.

## Storage and identity contract — pending measurement

- Stable ID namespace and allocation/reuse strategy.
- What fields belong in the persistent identity versus canonical party/box Pokémon data.
- A versioned record format, migration and save integrity.
- Capacity planning, graceful handling when the persistent pool is full, and how to avoid losing promoted individuals.
- Aggregate population granularity (species × habitat or another partition).
- Trainer-owned Pokémon tracking policy and the relationship between persistent wild records and the existing battle system.

These are **unresolved engineering and gameplay questions**. Do not claim a record byte size or number of simultaneously tracked Pokémon until [save budgets](save-budget.md) are measured.

## Acceptance scenarios

1. Encounter a distinctive Pokémon, establish its significance, leave for several in-game days and return: it is recognizably the same individual, possibly moved or grown.
2. Close the game for a week: no world changes occur during that offline period.
3. Walk through a common habitat without meaningful interaction: ordinary Pokémon can be represented by population aggregates rather than an ever-growing list of IDs.
4. Capture a persistent wild Pokémon: the wild entity is removed and the captured Pokémon retains the relevant identity/history; no clone remains.
5. Simulate a distant region: update aggregate ecology and notable individuals without loading all overworld sprites or running all movement AI.
