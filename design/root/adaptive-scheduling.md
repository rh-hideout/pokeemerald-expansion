# Adaptive off-screen scheduling with fairness — root design decision

**Decision: LOCKED (2026-11-04).** The [hybrid off-screen scheduler](offscreen-scheduler.md) assigns higher priority to habitats near the player, relevant notable individuals, pending migration transitions and consequential events, while **guaranteeing eventual service for distant habitats**. Priority is not a permission to skip ecological time or silently discard persistent individuals.

## Locked invariants

1. **Relevance matters.** Active/approaching areas and their dependencies are prioritized for timely, consistent activation.
2. **Notable events matter.** Significant family, relationship, survival and migration transitions may receive priority without running full distant AI.
3. **Fairness is mandatory.** Every eligible distant habitat eventually receives bounded simulation service during continued active gameplay, even if the player never visits it.
4. **Aging prevents starvation.** Waiting or accumulated in-game simulation debt increases effective priority or triggers a guaranteed service opportunity; repeatedly nearby work cannot permanently exclude distant habitats.
5. **Urgency is bounded.** Priority cannot bypass CPU budgets, trigger unbounded synchronous catch-up or block the game indefinitely.
6. **Dependencies are respected.** Before applying cross-habitat migration, births or other consequential updates, reconcile required upstream state or defer the transaction safely.
7. **Tiered work remains.** Ordinary ecology uses aggregate catch-up; notable Pokémon receive selective consequential events. No one-job-per-anonymous-Pokémon queue.
8. **Identity and conservation remain intact.** Priority ordering must not duplicate migrants, repeat promotions or double-apply elapsed intervals.
9. **Only in-game time counts.** Closing the game neither ages the world nor creates additional overdue work.
10. **Graceful activation.** A high-priority entering habitat must reach a consistent visible state or use a safe fallback while unfinished work continues.

## Conceptual selection model (not an implementation formula)

`eligible jobs -> estimate relevance + consequential urgency + age/fairness -> select within per-frame budget -> process bounded slice -> commit progress -> requeue if due`

Potential inputs:
- Player proximity or likely map transition
- Importance of an imminent event
- Notable individual involvement
- Time since last service / outstanding simulated-time interval
- Cross-habitat dependencies and unfinished transactions
- Estimated work cost

No exact scoring weights, scheduling cadence, queue capacity or aging constant is locked.

## Fairness contract

- **Eventually served:** under sustained active gameplay and finite eligible work, every habitat with outstanding work receives service.
- **No absolute latency promise yet:** a numeric maximum wait requires measured CPU/RAM and actual world size.
- **No permanent monopolization:** frequently refreshed nearby jobs cannot always jump ahead of an aged distant job.
- **Safe degradation:** if overload occurs, aggregate more routine activity, postpone nonessential detail and preserve authoritative progress markers. Do not erase notable identities.

## Example

The player approaches a forest while an important wild Pokémon is migrating elsewhere. The scheduler prioritizes preparing the forest and processing the travel transition. A distant desert remains lower priority initially, but its wait increases its effective priority; it eventually receives an aggregate ecological update without being visited.

## Open engineering choices

- Priority queue versus buckets, round-robin fairness lane or another bounded scheduler.
- Age measurement, guaranteed service policy and maximum outstanding interval.
- How to estimate job cost and prevent many expensive jobs from clustering.
- What qualifies as a consequential event and how to avoid priority inflation.
- Handling repeated map transitions, save/load, and partial transaction recovery.
- Performance profiling, diagnostics and starvation tests.

## Acceptance scenarios

1. A habitat about to be entered gets timely reconciliation ahead of routine distant work.
2. A remote habitat eventually updates despite continuous nearby activity.
3. A notable migrant's valid graph transition is not indefinitely delayed.
4. Repeated player map transitions do not starve unrelated ecosystems.
5. Priority order changes do not duplicate births, migrations or identities.
6. Frame workload remains bounded under many due jobs.
7. Save/load preserves authoritative progress without creating offline elapsed time.

See [Off-screen scheduler](offscreen-scheduler.md), [Hybrid catch-up](hybrid-catchup.md), [World clock](world-clock.md), and [Individual persistence](individual-persistence.md).
