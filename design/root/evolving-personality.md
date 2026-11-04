# Evolving Pokémon personality — root design decision

**Decision: LOCKED (2026-11-04).** Notable Pokémon have recognizable individual behavioral dispositions that **can gradually change through significant experiences**. Personality influences [utility-based action selection](utility-ai.md) but never overrides physical capabilities, hard safety rules or the game's danger-telegraphing contract.

## Design intent

Two Pokémon of the same species can behave differently; a timid creature may become more confident after surviving challenges or receiving help. Growth should be gradual and believable, not an instantaneous role switch. Pokémon can change through independent ecosystem experiences even if the player is absent.

## Locked invariants

1. **Individual starting dispositions:** notable Pokémon have stable, recognizable initial differences, shaped by species tendencies and individual variation.
2. **Experience-driven adaptation:** meaningful survival, rescue, repeated conflict, family care, successful exploration and other consequential events may shift traits over in-game time.
3. **Slow, bounded change:** a single trivial encounter does not rewrite personality. Changes must be bounded to avoid runaway extremes, oscillation or indistinguishable individuals.
4. **Separate traits, needs and memories:** personality describes longer-term tendencies; hunger/fear in the moment are transient needs; memories/relationships reference particular experiences and individuals.
5. **Utility AI integration:** traits influence relative action preferences (e.g., boldness affects investigate-versus-retreat) but do not make invalid actions possible.
6. **Species identity remains:** individual adaptation must not erase species ecology, movement limits or biology.
7. **Tiered persistence:** ordinary populations use species/habitat tendencies without permanent per-creature personality histories. Promoted individuals acquire a coherent initial personality; the exact initialization method remains open.
8. **Off-screen development:** noteworthy autonomous events may affect a notable Pokémon's personality through bounded abstract updates.
9. **Save and identity safety:** notable personality persists across map changes, migration and save/load, with no cloning or silent reset on capture/release.
10. **No offline progression:** changes occur only during in-game simulation time; the game being closed freezes development.
11. **Fairness:** evolving boldness or aggression does not bypass readable danger cues or create unavoidable surprise attacks.

## Conceptual state (not a storage format)

- Baseline dispositions from species and individual variation.
- Current long-term traits, such as boldness, curiosity, sociability, territoriality or resilience (examples only).
- Optional accumulated experience signals or bounded adjustment state.
- Recent in-game update time if required for gradual change.

**Do not conflate Pokémon Nature (existing battle mechanic) with these proposed AI personality traits.** Their relationship is undecided.

## Conceptual evolution flow

`meaningful event -> significance check -> bounded trait influence -> gradual adjustment -> altered future utility scores`

The AI can use the resulting traits without re-running an entire memory log. Memory summaries may trigger adjustments; the personality system does not need a complete event archive.

## Example

A cautious wild Pokémon repeatedly avoids danger. After surviving several threatening encounters and being protected by a trusted companion, its boldness may increase slightly. It still retreats from overwhelming threats and retains species-appropriate behavior. Another Pokémon of the same species may remain more cautious.

## Open questions

- Exact trait dimensions, scales, default values and species distributions.
- Event significance thresholds, learning rates, decay or stabilization.
- How traits interact with existing Natures, abilities and friendship.
- Whether experiences shift a baseline, temporary modifier, or both.
- How personality survives capture, storage, evolution, release and trading.
- Representation of individual traits in constrained save space.
- Observable behavior, animation and player-facing feedback.

No trait count, byte size, learning rate or numeric range is locked before budget measurement.

## Acceptance scenarios

1. Two notable Pokémon of the same species show distinct preferences in comparable circumstances.
2. A meaningful series of experiences gradually changes a trait and observable action selection.
3. A routine encounter does not produce a dramatic permanent personality reversal.
4. A migrated or reloaded Pokémon retains its developed dispositions.
5. An off-screen notable Pokémon can adapt from consequential ecosystem events.
6. An anonymous population does not allocate a permanent personality record per creature.
7. Closing the game does not change traits.
8. Personality never enables an impossible action or violates safe-region danger rules.

See [Utility AI](utility-ai.md), [Social memory](social-memory.md), [Individual persistence](individual-persistence.md), and [World clock](world-clock.md).
