# Hybrid NPC long-term goals — root design decision

**Decision: LOCKED (2026-11-04).** Notable NPCs begin with meaningful **authored backgrounds, obligations and ambitions**, but can **discover, revise, defer, achieve or abandon long-term goals** through significant experiences, changing needs, relationships and opportunities. Stable character identity and essential world institutions coexist with autonomous personal growth.

## Locked invariants

1. **Grounded starting direction.** An authored notable NPC begins with coherent home, role, background and relevant commitments; not every NPC must start with a grand ambition.
2. **Emergent change.** Meaningful successes, failures, journeys, losses, discoveries, social bonds and world events can introduce new goals or alter existing ones, including while off-screen.
3. **Personal ownership.** A long-term goal belongs to the canonical NPC identity, not a map sprite, temporary group or routine task. Save/load and travel preserve consequential progress.
4. **Distinct planning horizons.** Long-term ambitions describe desired outcomes; [hybrid hierarchical planning](npc-hierarchical-planning.md) provides bounded adaptive milestones; daily routines and [NPC utility AI](npc-routine-utility.md) choose feasible immediate actions.
5. **Personality and memory influence.** [Slowly evolving personality](npc-evolving-personality.md), [selective social memory](npc-social-memory.md), needs and current circumstances shape which goals matter, without treating every momentary emotion as a new ambition.
6. **Revision without thrashing.** Goals may be pursued, suspended, completed or abandoned through meaningful evidence and commitment rules, not oscillate with every small utility-score change.
7. **Multiple priorities, bounded scope.** NPCs may balance personal aspirations, family, work, care and group commitments. Active goal sets and update costs must be bounded by measured GBA budgets.
8. **Autonomous but plausible progress.** Off-screen progress uses selective causal events and accessible routes/resources; NPCs cannot instantly complete journeys, acquire unavailable items or gain impossible knowledge.
9. **Group goals remain voluntary.** [Dynamic small groups](npc-dynamic-groups.md) can offer shared objectives; membership does not erase personal goals or require unconditional obedience.
10. **Protected institutional obligations.** Important shops, gyms, recovery and mandatory progression remain accessible through coherent coverage, alternatives or authored constraints. Personal ambition cannot silently break critical services.
11. **Meaningful resolution.** Completing or abandoning a major ambition may create bounded memories, personality adjustments, relationships or new opportunities through [shared events](shared-world-events.md), applied exactly once.
12. **Tiered simulation.** Notable NPCs can persist compact ambitions and progress; ordinary crowds rely on aggregate activity or lightweight role routines rather than individual persistent plans.
13. **In-game time only.** Goal progress, deadlines and reconsideration occur only through elapsed in-game time. Closing the game never advances a plan.

## Conceptual goal contract — not a binary schema

A notable NPC may hold a bounded set of goal references or compact descriptors with: desired outcome, motivation/source, priority or commitment, relevant actors/places/resources, progress state and last processed in-game time. Exact encoding and quantities are open.

`authored commitments + significant experience -> candidate ambition -> plausibility/priority check -> active long-term goal -> feasible short-term tasks -> consequential progress event -> continue, revise, complete or abandon`

Goals express *intentions*, not guarantees. Utility AI decides what to do now; navigation validates reachability; perception and social reports limit what an NPC can know; shared events validate and commit outcomes.

## Example

A young ranger initially patrols near their hometown. After helping an injured Pokémon and hearing credible reports of habitat damage, they gradually develop an ambition to protect a distant forest. They plan journeys and recruit a temporary team, but still need supplies and a reachable route. If conditions change, they can postpone or revise the ambition rather than teleporting to success.

## Open engineering decisions

- Goal categories, authored definitions, references and compact serialization.
- Priority, commitment, suspension and abandonment thresholds.
- Goal progress representation and event-to-progress mapping.
- Multi-goal conflict resolution and group-goal coordination.
- Player influence, dialogue visibility, authored narrative safeguards and goal completion rewards.
- Off-screen update cadence, save migration and test instrumentation.
- Exact goal count, record sizes and ROM/RAM/CPU budgets.

Do not lock numerical limits or claim implementation before measurement.

## Acceptance scenarios

1. A notable NPC begins with a coherent authored commitment and can pursue it through ordinary routines.
2. Significant independent experiences can create a new plausible long-term ambition.
3. A single trivial event does not repeatedly replace the NPC's principal goal.
4. A goal may be suspended or abandoned without erasing its consequential history.
5. Save/reload preserves identity, goal progress and completed-event accounting.
6. Off-screen progress requires plausible time, travel and resources, not instant success.
7. A group objective can influence a member without overriding essential personal needs or identity.
8. A shopkeeper's ambition cannot permanently eliminate essential player access.
9. Background crowds do not each require persistent long-term planning.
10. No goals advance while the game is closed.

See [NPC routines and utility](npc-routine-utility.md), [NPC personality](npc-evolving-personality.md), [NPC groups](npc-dynamic-groups.md), [NPC persistence](npc-persistence.md), [Shared events](shared-world-events.md), and [Save budget](save-budget.md).
