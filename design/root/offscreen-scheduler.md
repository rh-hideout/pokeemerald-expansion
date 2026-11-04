# Hybrid scheduled off-screen simulation — root design decision

**Decision: LOCKED (2026-11-04).** The living world uses a **hybrid scheduled simulation**: small, bounded off-screen updates are distributed during active gameplay, with **bounded catch-up** when an area or notable individual becomes relevant. All updates advance only elapsed **in-game world time**. Closing the game creates no simulation debt.

## Why

The GBA cannot update every habitat and creature in detail every frame. Purely event-triggered simulation can create stalls on map entry; fully continuous world-wide simulation wastes CPU. A hybrid scheduler spreads work and reconciles state when the player approaches.

## Locked invariants

1. **Single time authority.** All jobs consume elapsed monotonic in-game time from [World clock](world-clock.md), never real-world wall-clock time.
2. **Distributed background work.** During gameplay, small jobs update distant habitats and notable individuals without requiring every entity to run every frame. **Adaptive scheduling with aging/fairness is locked**: approaching habitats and consequential events receive priority, but distant habitats must eventually be serviced. See [Adaptive scheduling](adaptive-scheduling.md).
3. **Bounded relevance catch-up.** On approaching, loading or otherwise querying an area, pending updates are processed within a budget. **Hybrid catch-up is locked:** aggregate ordinary ecology and selectively process consequential notable events; excess work is deferred or safely summarized rather than blocking indefinitely. See [Hybrid catch-up](hybrid-catchup.md).
4. **Tiered fidelity.** Nearby entities use detailed behavior/perception/navigation. Distant notable Pokémon use coarse individual events and journey states. Ordinary populations use aggregate ecological updates.
5. **Deterministic accounting contract.** An interval must not be applied twice. Each simulated unit tracks a logical last-processed world timestamp or equivalent progress marker; reentrant/map-entry jobs must reconcile against it.
6. **Safe materialization.** Before visible spawn, reconcile a notable Pokémon's authoritative location/identity and pending state. Never spawn both an off-screen traveler and a second local copy.
7. **Bounded dependencies.** Cross-habitat migration, reproduction and resources must reconcile consistently; outgoing and incoming counts must not double-count or become negative due to job ordering.
8. **Event significance.** Meaningful off-screen events may promote ordinary individuals or update notable families, memories and personalities, subject to persistence budgets and explicit capacity rules.
9. **Stable gameplay.** Job scheduling cannot cause uncontrolled frame stalls, infinite backlogs or unbounded memory allocation. The exact time/CPU/job budgets require measurement.
10. **Fairness and causality.** Off-screen results must respect travel graph constraints, species abilities, ecology, danger rules and event chronology. Do not retroactively create unavoidable surprise attacks.
11. **No offline catch-up.** Saving/loading after a long real-world absence advances nothing by itself.

## Conceptual scheduling model (not code)

`WorldTime_Now -> select due habitat/individual jobs -> apply bounded elapsed-time slices or aggregate summaries -> commit progress marker -> repeat across gameplay frames`

When a map becomes relevant:

`request habitat state -> prioritize overdue local dependencies -> bounded reconciliation -> materialize valid visible entities -> continue deferred background jobs`

The system must define what happens if the available budget cannot fully reconcile an area before it becomes visible: a safe, consistent fallback is required. It must **not** show stale or duplicate individuals as if catch-up had completed.

## Update layers

| Layer | Fidelity | Examples |
|---|---|---|
| Active local map | Detailed | Perception, utility selection, local pathfinding, nearby interactions |
| Distant notable individuals | Coarse event-based | Hunger/recovery, family changes, significant social encounters, graph travel |
| Habitat aggregates | Summary updates | Food resources, births, recovery, predation pressure, population migration |

These are conceptual responsibilities; update cadence and storage layouts are not yet fixed.

## Example

The player spends an in-game day exploring another region. During play, the scheduler periodically advances a distant forest's food and population state and a notable Absol's migration. On return, the forest receives bounded reconciliation before the visible population is selected. Closing the game for a week during this trip does not create an extra week of progress.

## Implementation boundaries

- Scheduler owns **when** and **how much** to update; ecology, movement, identity, AI and family modules own **what** changes.
- Jobs must be resumable or safely summarized, and should avoid keeping large persistent queues when a timestamp/dirty marker can suffice.
- Time slicing must preserve conservation/accounting and event order where causal dependencies matter.
- No assumed frame time, entity count, RAM use or save bytes without profiling.

## Open questions

- Adaptive priority and fairness/aging are locked; exact scoring, fairness mechanism, maximum job time and active-map cadence remain open.
- Hybrid catch-up is locked; exact aggregate formulas, event selection, interval slicing and activation fallback remain open.
- How world time advances during menus, battles, cutscenes and pause.
- Exact save representation of progress markers, random state and partial transactions.
- How to make migration/population transfers atomic across habitats.
- Whether to provide a debug overlay and reproducible event log for tests.
- Shared NPC–Pokémon consequential events are locked; event schema, scheduling integration and transaction boundaries remain open. See [Shared living-world events](shared-world-events.md).

## Acceptance scenarios

1. A distant forest evolves over elapsed in-game time without detailed sprites or pathfinding.
2. Entering a long-unvisited habitat does not freeze the game or duplicate notable Pokémon.
3. Multiple partial jobs over an interval produce coherent results without double-applying births or migration.
4. Saving/loading preserves simulation progress markers and does not repeat committed events.
5. Closing the game for a week produces zero additional world progress.
6. A notable individual's off-screen journey obeys habitat graph connections and remains identity-stable.
7. Large populations remain aggregate, without one scheduled job per ordinary creature.
8. Scheduler overhead remains within measured CPU/RAM budgets.

See [World clock](world-clock.md), [Individual persistence](individual-persistence.md), [Hybrid navigation](hybrid-navigation.md), [Population ecology](population-ecology.md), and [Utility AI](utility-ai.md).
