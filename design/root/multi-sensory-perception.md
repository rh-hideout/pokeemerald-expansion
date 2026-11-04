# Environment-aware multi-sensory Pokémon perception — root design decision

**Decision: LOCKED (2026-11-04).** Nearby wild Pokémon perceive the world through **species-appropriate senses**, including sight, hearing and other suitable capabilities. [Contextual NPC perception](npc-contextual-perception.md) is separately locked for human observers; they may share terrain/event cues but differ in sensory abilities and interpretation. Distance, obstacles, terrain, lighting, weather and sensory ability affect detection. The design does **not** require exhaustive scent-trail simulation, detailed acoustic propagation or universal omniscient awareness.

## Intent

Perception provides **limited evidence** to the [utility AI](utility-ai.md), not perfect knowledge of every entity in the map. A creature can react to a sound without knowing exactly who made it. A hidden or obscured Pokémon is not automatically visible.

## Locked rules

1. **Multiple senses:** vision and hearing are baseline conceptual channels; species may use specialized senses where appropriate. Not every Pokémon has identical detection abilities.
2. **Environmental effects:** walls, rocks, foliage, darkness, weather, distance and other relevant conditions may reduce, block or alter detection by channel.
3. **Partial knowledge:** detection may indicate a presence, direction or approximate area without granting exact target identity and position.
4. **Species and state matter:** species traits, current behavior, attention and relevant conditions affect perception. A sleeping or distracted creature need not react like an alert one.
5. **No omniscience:** Pokémon must not chase unseen targets with perfect location knowledge merely because those targets are inside a radius.
6. **Memory is distinct from sensing:** previously learned locations or identities may inform expectations but do not become live sensor readings. See [Social memory](social-memory.md).
7. **Utility integration:** perceived evidence informs candidate actions and urgency; perception does not directly force an action except through narrow safety mechanisms.
8. **Bounded updates:** only relevant nearby entities and events receive detailed checks. Avoid all-pairs checks, per-frame full-map ray tracing or unbounded sound searches.
9. **Off-screen abstraction:** distant notable Pokémon and aggregate populations use habitat-level events and coarse environmental conditions, not full visual/audio simulation.
10. **Player-facing fairness:** danger remains telegraphed and escapable; perception does not justify impossible surprise attacks in safe regions.
11. **Time:** sensing and off-screen awareness do not advance while the game is closed.

## Conceptual inputs and outputs (not serialized data)

Inputs: observer species/sense profile, position, orientation if supported, alertness, nearby entities/events, terrain blockers, illumination, weather, sound-event cues.

Outputs: bounded set of perceived cues with channel, approximate source, confidence/freshness, and possible known identity. Confidence and exact fields are provisional.

## Example

A Pokémon behind a boulder is visually obscured from a predator. Moving noisily may still produce an audible cue. During heavy rain, the same cue may be weaker or missed. The predator may investigate the general direction, rather than tracking an exact invisible position.

## Proposed processing boundaries

`nearby event/entity -> cheap range and relevance filter -> channel-specific environment check -> limited cue -> utility evaluation -> action`

- Use map collision/visibility information where available rather than inventing expensive world physics. The [hybrid navigation](hybrid-navigation.md) layer uses the same terrain legality where applicable, but perception does not grant a complete route or omniscient map knowledge.
- Reuse/collapse events where possible, and limit active observers and cue history.
- A sensory cue can expire; exact duration and confidence formula remain open.
- Special senses can extend the channel model without requiring every species to use them.

## Open parameters

- Sight distance, facing cones, occlusion and lighting treatment.
- Sound source categories, hearing ranges and attenuation approximations.
- Which species receive specialized senses and how abilities affect detection.
- Whether scent/tracks are lightweight cues for selected species, without full persistent trail fields.
- Perception cadence, cue count, expiration and performance budgets.
- How perception survives transitions from nearby detailed simulation to off-screen abstraction.
- Debug visualization and deterministic tests.

No range, ray count, event limit, CPU budget or save byte size is locked before profiling.

## Acceptance scenarios

1. A visible nearby Pokémon can be detected, while the same Pokémon behind a solid obstruction is not visually detected.
2. A sound behind an obstruction can produce a partial cue without revealing exact target position.
3. Weather or darkness changes an appropriate sense without disabling unrelated senses.
4. Different species can react differently to the same cue.
5. The utility AI chooses between investigating, fleeing, ignoring and approaching according to needs and personality.
6. Distant Pokémon are simulated without per-frame sound or vision checks.
7. Repeated checks stay within bounded cost and do not leak omniscient target coordinates.
8. Closing the game causes no sensory or world-time progression.

See [Utility AI](utility-ai.md), [Social memory](social-memory.md), [Evolving personality](evolving-personality.md), and [World clock](world-clock.md).
