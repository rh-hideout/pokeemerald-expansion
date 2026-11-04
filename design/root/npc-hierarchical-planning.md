# Hybrid hierarchical NPC planning — root design decision

**Decision: LOCKED (2026-11-04).** Notable NPCs pursue long-term goals through **small, adaptable milestones**, while **utility-based action selection** chooses feasible immediate behavior. Plans can be interrupted, revised, resumed or abandoned as conditions change. This is bounded hierarchical planning, not unrestricted deep search or a continuously running global planner.

## Locked invariants

1. **Distinct levels of intent.** [Long-term goals](npc-long-term-goals.md) define desired outcomes; milestones define meaningful intermediate progress; [NPC utility AI](npc-routine-utility.md) chooses valid immediate actions.
2. **Adaptive milestones.** A goal may be decomposed into a short, bounded sequence or set of prerequisite steps; new information, failures or opportunities can change the remaining steps without erasing completed outcomes.
3. **No omniscient plans.** NPCs plan from their own perception, memory and received information, not hidden world truth or perfect knowledge of every route, resource or actor.
4. **Feasibility checks.** Routes, transport, resources, time, abilities, obligations and hazards constrain milestones. An impossible step must fail, wait, replan or trigger a safe fallback.
5. **Commitment and hysteresis.** Minor changes in utility do not repeatedly restart planning; urgent needs and genuine events may interrupt, with a coherent path to resume or reconsider.
6. **Autonomous off-screen progress.** Selective milestone transitions can occur during in-game time when distant, using coarse causal events rather than executing detailed pathfinding or all intermediate actions.
7. **Persistent canonical progress.** Important milestones, current commitments and progress markers belong to stable notable NPC identities across maps and save/load; local sprites are only representations.
8. **Exactly-once consequences.** Completing a milestone must not replay rewards, resource transfers, ownership changes, group membership changes or relationship effects on catch-up or reload.
9. **Independent group members.** [Dynamic groups](npc-dynamic-groups.md) can coordinate shared milestones, but individual NPCs keep separate needs, personal ambitions and the ability to decline or leave.
10. **Tiered simulation.** Ordinary crowds use lightweight routines or aggregate outcomes; not every background person gets a persistent planning tree.
11. **Bounded work.** Planning depth, active milestones, evaluation frequency, retries and storage must fit measured GBA ROM/RAM/CPU/save budgets; avoid unconstrained search.
12. **Institutional safety.** Plans cannot permanently disable essential shops, gyms, recovery or mandatory progress; coverage or discoverable alternatives must remain.
13. **In-game time only.** Planning progress, cooldowns and deadlines never advance while the game is closed.

## Conceptual pipeline — not executable code

`long-term goal -> choose reachable milestone(s) -> utility-selected local action -> observe result -> commit consequential progress -> continue / interrupt / replan / complete`

A milestone may describe an outcome, prerequisites, location or actor references, status, progress marker and optional fallback. This is **not** a locked binary layout or prescribed planning algorithm.

### Example

A ranger aims to protect a damaged forest. Possible milestones are to learn where the damage occurred, gather supplies, travel to the forest and help affected Pokémon. A blocked bridge may postpone travel; a new rumor may alter the destination; hunger may interrupt the immediate action. The ranger does not magically complete the forest mission, and their completed preparation is not repeated after save/load.

## Architecture boundaries

- Goal system owns ambitions and meaningful completion conditions.
- Planner owns bounded milestones and their prerequisites, not canonical actor identity.
- Utility AI owns immediate action selection and interruption behavior.
- Navigation validates routes; perception, social memory and rumors constrain available knowledge.
- Shared events commit consequential results once; scheduler allocates bounded work.
- Group coordination offers shared milestones without collapsing members into one actor.

## Open engineering decisions

- Milestone categories, authoring templates, decomposition rules and dependency encoding.
- Planner choice (finite-state milestones, limited HTN-like templates or equivalent), search limits and fallback rules.
- Commitment thresholds, cooldowns, replanning triggers and resume semantics.
- Milestone serialization, event deduplication and save migration.
- Group milestone synchronization, shared resources and conflict handling.
- Testing, profiling and actual memory/CPU budgets.

No numeric depth, milestone count, time budget or record size is locked before measurement.

## Acceptance scenarios

1. An NPC breaks an authored ambition into feasible intermediate steps and takes a useful immediate action.
2. A blocked route causes delay or bounded replanning rather than teleportation or an infinite search.
3. Hunger interrupts a task; the NPC can resume an unfinished milestone later.
4. New credible information changes an upcoming milestone without undoing completed events.
5. Save/reload preserves milestone progress and does not repeat a completed transaction.
6. Off-screen progress requires elapsed in-game time, access and resources.
7. Two group members can coordinate without surrendering individual autonomy.
8. Ordinary crowds do not each allocate a persistent planning tree.
9. A critical shop or gym remains usable despite an NPC's changing plans.
10. Closed-game time never advances a milestone.

See [NPC goals](npc-long-term-goals.md), [NPC routines and utility](npc-routine-utility.md), [NPC groups](npc-dynamic-groups.md), [Off-screen scheduler](offscreen-scheduler.md), [Shared events](shared-world-events.md), and [Save budget](save-budget.md).
