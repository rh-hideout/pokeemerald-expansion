# Selective NPC social memory and evolving relationships

**Decision: LOCKED (2026-11-04).** Notable NPCs retain **bounded, selective memories of meaningful experiences** and evolving relationships with other people and Pokémon. Memories affect choices, trust, obligations and recognition across maps, saves and off-screen events. Ordinary background crowds do not receive permanent per-person social histories.

## Locked invariants

1. **Meaning over exhaustive logs.** Record salient consequences and compact relationship state, not every greeting, conversation or passing encounter. [Information sharing](npc-information-sharing.md) separately models bounded claims and rumors, not automatic firsthand memories.
2. **Relationships evolve.** Trust, affection, gratitude, fear, rivalry, obligation and other useful dispositions may change through consequential events. No immutable friend/enemy classification.
3. **Cross-species and human ties.** A notable NPC can remember another notable NPC, a notable Pokémon or the player; significant care/rescue/trade events can influence both NPC behavior and Pokémon behavior.
4. **Independent events count.** Relationships may form or change without the player observing, through the [shared living-world event system](shared-world-events.md).
5. **Stable identity references.** Memory targets use canonical identity with actor type and safe record-generation/version semantics where needed; no accidental attachment to a recycled identity or duplicate local actor.
6. **Meaningful asymmetry.** Two actors need not have identical memories or feelings. Event outcomes may affect each participant differently; one-sided memories are valid.
7. **Behavioral consequences.** NPC [routine/utility decisions](npc-routine-utility.md) may incorporate remembered trust, obligations, danger and prior outcomes, without turning social memory into a compulsory action script. Long-term dispositions evolve separately through [NPC personality](npc-evolving-personality.md).
8. **Bounded persistence and processing.** Memory slots, history summaries, event evaluation and relationship updates must fit measured GBA save/RAM/CPU budgets; no global all-pairs social simulation.
9. **Protect important bonds.** Family, ownership/care, essential authored narrative ties and similarly consequential bonds cannot be silently discarded when capacity is exhausted. A measured, explicit summarization/overflow policy remains open.
10. **Promotion compatibility.** A consequential social event may promote an ordinary NPC to notable status under [tiered NPC persistence](npc-persistence.md); preserve the relevant outcome without creating duplicate identities.
11. **No closed-game progress.** Forgetting, reconciliation and relationship changes advance only through elapsed in-game time, never while the game is closed.
12. **Player-facing coherence.** Later dialogue, help, avoidance, hospitality, rumors or routines may reveal significant memories; the exact presentation is not locked.

## Conceptual memory contract — not a binary layout

A notable NPC may hold a bounded set of:
- Stable typed references to relevant people, Pokémon or the player.
- Current relationship dispositions and obligations.
- Compact evidence or a summary of a consequential event, such as a rescue, betrayal, repeated assistance or shared travel.
- In-game progress timestamps where decay or evolving sentiments require them.

An event can modify a summarized relationship without allocating an additional permanent event record. Reciprocal effects are resolved explicitly, not assumed.

## Example

A traveler helps an injured wild Pokémon while the player explores elsewhere. The event may promote the traveler to notable status and create a persistent bond with that Pokémon. Later, the traveler may recognize it, alter a journey to help it, or speak about the rescue. Neither party needs a full transcript of the encounter.

## Architecture boundaries

- Shared events validate that participants and circumstances plausibly intersect.
- NPC social memory stores consequential summaries and typed relationships; Pokémon social memory retains its own behavior-specific model.
- Utility AI reads social signals but does not own canonical identity or event transaction commits.
- Scheduler performs selective off-screen social updates under bounded budgets.
- Cross-actor effects must be applied coherently once, including across save/load.

## Open engineering questions

- NPC relationship slot count, record size, reference encoding and save versioning.
- Event significance thresholds, memory summarization and retention priority.
- Directionality, reciprocity, decay, forgetting and emotional weight formulas.
- Handling ordinary/untracked NPC partners in a notable NPC's history.
- Player identity, authored character references and trainer-owned Pokémon linkage.
- Dialogue/news exposure, consent/ownership rules and test instrumentation.

Do not lock numeric capacities or claim implementation until measured and tested.

## Acceptance scenarios

1. A notable NPC recognizes a Pokémon it rescued after map travel and save/reload.
2. An off-screen NPC–NPC event changes later behavior without player observation.
3. Two participants can remember the same event differently.
4. A routine crowd encounter does not allocate a permanent memory for each person.
5. Repeated delivery of one event cannot duplicate social effects or promotion.
6. Capacity pressure does not silently erase protected family or ownership/care bonds.
7. A recycled runtime object cannot inherit another NPC's relationships.
8. Closing the game for a week does not advance memory decay.
9. A social obligation changes an NPC's preferred routine without permanently disabling essential services.

See [NPC persistence](npc-persistence.md), [NPC routines and utility](npc-routine-utility.md), [Shared events](shared-world-events.md), [Pokémon social memory](social-memory.md), and [Save budget](save-budget.md).
