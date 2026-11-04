# Hybrid NPC routines and utility AI — root design decision

**Decision: LOCKED (2026-11-04).** NPCs have recognizable daily routines and commitments, but can autonomously change plans in response to needs, goals, relationships and consequential events. **Utility-based selection** weighs valid alternatives; routines provide meaningful defaults rather than unbreakable scripts. This shares scheduling and event contracts with Pokémon AI without requiring identical behavior logic.

## Locked invariants

1. **Predictable baseline.** Home, work, meals, rest, travel and social commitments create legible routines. A shopkeeper is normally found at their shop during working hours. [Hybrid long-term goals](npc-long-term-goals.md) provide persistent ambitions and obligations; [hierarchical planning](npc-hierarchical-planning.md) organizes bounded milestones, while routines and utility AI choose feasible immediate actions.
2. **Autonomous interruptions.** Hunger, exhaustion, danger, urgent care, relationships, unusual opportunities and shared world events may override routine actions.
3. **Utility-driven choice.** Contextual needs, temperament, goals, obligations, relationships, environmental state and available opportunities influence action priority; no fixed role dictates every action. [Dynamic NPC groups](npc-dynamic-groups.md) can provide shared opportunities and commitments without eliminating individual choice. Notable NPCs draw on [selective social memory](npc-social-memory.md) for meaningful relationship context and [slowly evolving personality](npc-evolving-personality.md) for longer-term dispositions.
4. **Narrow hard overrides.** Incapacitation, inaccessible locations and urgent hazards block invalid actions; safety handling must not turn all NPCs into identical agents.
5. **Action commitment.** NPCs avoid rapidly oscillating between work, meals and travel; cooldowns, hysteresis or commitments are required, with justified urgent interruptions.
6. **Role reliability.** Important services and gym challenges remain discoverable/recoverable when their NPCs travel or change plans. Absence may be meaningful, never an irreversible progression lock.
7. **Independent lives.** NPCs may act and encounter Pokémon or other NPCs without player observation. Significant results use the [shared event contract](shared-world-events.md).
8. **Tiered fidelity.** Nearby NPCs perform concrete movement/interaction; distant notable NPCs make coarse schedule/utility decisions; ordinary background people use lightweight routines or aggregate updates.
9. **Identity continuity.** Changes in activity, route or relationship do not replace a notable NPC's identity. Temporary local object events must reconcile with the canonical actor.
10. **Bounded work and fair scheduling.** Use the adaptive scheduler for distant decisions; no global per-frame scoring of every person, exhaustive planning or unlimited pathfinding.
11. **In-game-only time.** No NPC activity or need progression while the game is closed.
12. **Readable player experience.** Dialog, notices, witnesses and patterns can communicate departures and schedule changes; exact UI is open.

## Conceptual NPC decision loop (not code)

`current routine/commitment -> observe needs and local/event context -> filter impossible actions -> score viable alternatives -> choose or continue committed activity -> execute local or coarse action -> update state and significant events`

Example candidates: work, rest, eat, shop, travel, train, socialize, help another actor, seek shelter, flee, explore, return home. This is not an exhaustive locked action catalog.

## Example

A shopkeeper usually opens in the morning. If hungry, they may take a short break; if a friend is injured, they may leave to help. Another worker, substitute, reopening window or discoverable location keeps essential services usable. Their off-screen journey is simulated coarsely, not tile by tile.

## Architectural boundaries

- Routine/calendar module supplies baseline activities and commitments.
- NPC utility selector chooses among valid actions; it is separate from pathfinding, event resolution and persistence.
- Shared events are the interface to Pokémon ecology and other NPCs; not every casual interaction deserves a saved event.
- A notable NPC's persistent identity is independent of its currently visible object-event instance.
- No fixed CPU budget, evaluation frequency, action weights or saved record format until the Expansion build is measured.

## Open engineering decisions

- Routine representation, schedule flexibility and time-of-day integration.
- Utility weights, personality dimensions, obligation strength and interruption thresholds.
- Hybrid NPC navigation is locked; exact graph, transport access, local routing and itinerary format remain open. See [NPC navigation](npc-hybrid-navigation.md).
- Which roles require substitutes or guaranteed availability and how players locate absent people.
- Coarse off-screen decision cadence, scheduler priorities and save/reload recovery.
- Contextual multi-sensory NPC perception is locked; exact cue representation, dialogue/news and relationship memory formats remain open. See [NPC perception](npc-contextual-perception.md).
- Exact RAM, ROM, save and object-event budgets.

## Acceptance scenarios

1. A shopkeeper follows a recognizable schedule during ordinary days.
2. A meaningful emergency interrupts that schedule without permanent service loss.
3. A hungry NPC chooses food before a low-urgency errand, then resumes appropriately.
4. NPCs with different goals or temperament respond differently to the same event.
5. A notable NPC travels off-screen without cloning on return or losing identity.
6. An NPC–Pokémon rescue has persistent consequences without detailed distant pathfinding.
7. A background crowd does not run full per-person utility scoring.
8. Save/reload and closed-game time preserve the clock and completed-event rules.
9. Frequent equal utility scores do not cause frame-by-frame action switching.

See [NPC persistence](npc-persistence.md), [Shared events](shared-world-events.md), [Adaptive scheduling](adaptive-scheduling.md), [Off-screen scheduler](offscreen-scheduler.md), and [Pokémon utility AI](utility-ai.md).
