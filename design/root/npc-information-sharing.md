# Selective social information sharing — root design decision

**Decision: LOCKED (2026-11-04).** NPCs can share **significant discoveries, warnings, news and rumors** through plausible encounters, conversations, relationships and travel. Information spreads **gradually and imperfectly**, rather than appearing instantly in everyone's knowledge. This is selective event-driven communication, not a detailed global messaging or all-pairs rumor network.

## Locked invariants

1. **Knowledge has a source.** A claim originates from a witnessed event, a credible trace, an authored notice or an identifiable report. NPCs do not know distant events merely because they occurred.
2. **Plausible transmission.** Face-to-face meetings, travel, community exchanges and supported communication channels carry information; distance, time, connectivity and access constrain spread.
3. **Partial and fallible reports.** A recipient may learn only an approximate place, uncertain identity, incomplete timing or imperfect description. Rumors can be mistaken or stale; a report is not a guaranteed fact.
4. **Selective significance.** Prioritize danger warnings, important discoveries, missing travelers, rare sightings, service disruptions and consequential social events. Everyday chatter does not produce unlimited persistent messages.
5. **Trust affects reception.** A receiver may weigh a report based on source credibility, personal history, interests and context, using [NPC social memory](npc-social-memory.md); trust never automatically proves truth.
6. **Individual knowledge differs.** Two NPCs in the same town can know different things or hold different confidence. Contradictory claims may coexist until investigated or corrected.
7. **Rumors influence, not dictate.** Learned information may alter [NPC routine/utility decisions](npc-routine-utility.md), travel, investigation, avoidance or dialogue, but must pass ordinary feasibility and safety checks.
8. **No duplicate truth or effects.** Repeating a report must not repeat the original event's resource, ownership, relationship or promotion effects. Distinguish the event from its retellings; suppress unbounded re-forwarding loops.
9. **Tiered persistence.** Notable NPCs can retain bounded significant knowledge and source summaries; ordinary crowds and settlements may carry aggregate rumor prevalence without individual permanent records.
10. **Off-screen abstraction.** Use scheduled coarse encounter and transmission opportunities, not detailed distant conversations or full network propagation each frame.
11. **No global omniscience.** A distant NPC cannot know a fact before a valid encounter, message or locally observable consequence; information sharing does not bypass [NPC perception](npc-contextual-perception.md).
12. **Player-facing coherence and fairness.** The player may learn through dialogue, notices, witnesses or regional chatter; rumors must not create unavoidable surprise danger or permanently break required services.
13. **In-game time only.** Rumor travel, aging, correction and forgetting advance only during active gameplay, never while the game is closed.

## Conceptual information flow — not implemented code

`observed event or evidence -> significance check -> bounded report with provenance and uncertainty -> plausible meeting/channel -> receiver interpretation -> optional memory/decision update -> selective forwarding`

A report may carry: a topic or originating event reference, approximate time and place, source/witness chain or summary, confidence/uncertainty, relevance and expiration status. Exact schema and sizes are open.

**Important distinction:** a report is a *claim about an event*, not the event itself. Reports may be inaccurate; event outcomes and canonical identities remain governed by the [shared world event contract](shared-world-events.md).

## Example

A ranger observes an unusual Pokémon near a mountain pass and tells a traveling merchant. The merchant later shares an approximate sighting in another town. Some residents trust the warning, others dismiss it; by the time the player hears it, the Pokémon may have moved. No NPC gains live tracking or a guaranteed exact spawn coordinate.

## Open engineering decisions

- Report/topic categories, provenance encoding, confidence, distortion, correction and expiry.
- How repeated retellings are summarized and deduplicated without retaining a full chain.
- Communication channels beyond face-to-face conversation, including notices or authored infrastructure.
- Relationship effects on sharing and belief; NPC preferences for privacy and discretion.
- Town-level aggregate rumor state, persistence budget and save migration.
- Scheduler cadence, transmission probability and anti-loop bounds.
- Player-facing dialogue/news presentation, debugging and deterministic tests.

No numeric rumor cap, travel rate, probability, byte size or global communication infrastructure is locked before profiling.

## Acceptance scenarios

1. An NPC witnesses a significant event and remembers a bounded report.
2. A traveler carries news to another town only after a plausible in-game journey.
3. A receiver can hear a partial or inaccurate account without gaining exact hidden coordinates.
4. Two listeners may trust the same rumor differently and choose different valid actions.
5. Repeated retellings cannot duplicate the originating event's effects or create infinite loops.
6. A stale rare-Pokémon sighting does not act as permanent live tracking.
7. Ordinary crowds do not allocate permanent per-person rumor histories.
8. Save/load preserves relevant notable knowledge without fabricating a new event.
9. Closing the game for any real-world duration does not propagate or age rumors.
10. Distant updates stay within measured work budgets and preserve safe gameplay.

See [NPC perception](npc-contextual-perception.md), [NPC social memory](npc-social-memory.md), [NPC navigation](npc-hybrid-navigation.md), [Shared events](shared-world-events.md), and [Adaptive scheduling](adaptive-scheduling.md).
