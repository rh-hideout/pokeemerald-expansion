# Hybrid catch-up: aggregate ecology and selective notable events

**Decision: LOCKED (2026-11-04).** When the off-screen scheduler is behind, **ordinary habitats and populations catch up through bounded aggregate calculations**, while **notable individuals, their families and significant relationships receive selective, causally consistent event updates**. This refines the [hybrid scheduler](offscreen-scheduler.md), not the world-clock policy: only elapsed **in-game** time counts.

## Locked rules

1. **Aggregate ordinary ecology.** Food supply, population growth/decline, recovery, habitat pressure and ordinary migration are advanced through bounded summaries, not one event per anonymous Pokémon.
2. **Selective notable events.** Persistent individuals can experience consequential journeys, survival, nesting, offspring, relationships and personality development off-screen. Process only events that materially affect persistent state, within a bounded workload.
3. **Preserve chronology where it matters.** Family formation cannot precede necessary conditions; a Pokémon cannot be in two habitats simultaneously; graph travel must respect edge availability and travel time.
4. **Exactly-once interval accounting.** Every update consumes a known in-game interval; progress markers and event identifiers or equivalent safeguards prevent repeated births, transfers and promotions on re-entry/save-load.
5. **Conservation and identity.** Aggregate migration debits and credits matching habitats; notable promotion removes the corresponding anonymous member exactly once; a persistent traveler is never double-counted or cloned.
6. **Bounded processing.** Cap work per scheduling slice and use safe approximation for routine activity. No unlimited replay of distant fights, foraging or footsteps.
7. **No loss of established notables.** Backlog pressure must not silently erase existing identities, family bonds or important memories. A capacity overflow policy remains necessary.
8. **Safe activation.** Before spawning local entities, reconcile required authoritative state. If reconciliation is unfinished, use a consistent fallback and continue work incrementally; never show contradictory stale/duplicate states.
9. **No invented offline time.** Closing/loading the game produces zero catch-up for time spent closed.
10. **Player-facing fairness.** Catch-up does not retroactively spawn unavoidable threats or irreversibly soft-lock basic resources.

## Conceptual algorithm (not code)

`elapsed simulated time -> aggregate habitat state -> reconcile cross-habitat transfers -> select consequential notable events -> commit state and progress markers -> activate safe visible state`

**Implementation caveat:** This is a logical dependency ordering, not a mandate to update every habitat first. Cross-habitat changes may require staged or transactional processing so that event chronology and counts remain consistent.

## Example

While the player explores elsewhere for three in-game days, a forest's ordinary Pokémon population is advanced with a few aggregate calculations. A notable Pokémon may complete a valid migration edge, defend its offspring and gain a salient relationship or personality change. The engine does not simulate every footstep or every ordinary battle. On return, the visible area reflects the reconciled state without a long freeze.

## Open engineering parameters

- Aggregation formulas and long-interval numerical stability.
- Which notable events qualify for replay versus summary.
- Adaptive priority and fairness are locked; exact weights, age guarantees and job-cost handling remain open. See [Adaptive scheduling](adaptive-scheduling.md).
- Transactional migration, promotion, birth and save/load recovery.
- RNG/reproducibility, timestamps and intermediate event state.
- Exact job budgets, backlog thresholds and activation fallback after profiling.
- Whether aggregate updates use capped time slices, closed-form estimates or a mixture.

No numeric limits or binary layouts are locked before measuring the Expansion build.

## Acceptance scenarios

1. A habitat overdue by many in-game days catches up without one operation per ordinary Pokémon per day.
2. A notable migrant retains identity and travels only across valid graph connections.
3. Repeated partial updates equal a coherent single interval and do not duplicate births or migrants.
4. Save/reload mid-backlog does not replay committed events.
5. Significant family and social consequences remain possible without full detailed simulation.
6. A habitat activation never materializes contradictory duplicate entities.
7. Real-world time spent with the game closed causes no change.
8. Frame time and memory remain within measured limits.

See [Off-screen scheduler](offscreen-scheduler.md), [Population ecology](population-ecology.md), [Individual persistence](individual-persistence.md), [Hybrid reproduction](hybrid-reproduction.md), and [World clock](world-clock.md).
