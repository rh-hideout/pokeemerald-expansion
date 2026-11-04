# Shared NPC–Pokémon living-world events — root design decision

**Decision: LOCKED (2026-11-04).** Human NPCs and Pokémon participate in a **shared living-world event system**. Consequential interactions can occur during active play even when the player is elsewhere, changing persistent relationships, journeys, ownership, resources and ecological conditions. This is **selective event simulation**, not continuous detailed battles or conversations for every off-screen pair.

## Locked rules

1. **Common event semantics, distinct actors.** NPC and Pokémon systems may publish/consume compatible events, while maintaining separate species-specific needs, behavior and identity records.
2. **Autonomous consequences.** Meaningful rescue, feeding, care, conflict, travel encounters, trade and habitat disturbance can occur without the player being present.
3. **Selective persistence.** [Tiered NPC persistence](npc-persistence.md) and [NPC social memory](npc-social-memory.md) are locked: notable NPCs and Pokémon retain consequential outcomes and bounded evolving social ties; ordinary people and Pokémon participate through aggregate or summary effects without full permanent records. Meaningful shared events may promote an ordinary NPC.
4. **Canonical ownership and identity.** A Pokémon transferred to an NPC or player remains the same individual; an event must not create duplicate owners, wild counts or local instances. Whether all trainer-owned Pokémon get full persistent records remains open.
5. **Causal consistency.** Participants must plausibly coexist in time and reachable place; migration routes, NPC travel, species abilities, world conditions and resource availability constrain events.
6. **Fairness and safety.** Fainting is not death. Shared events must not cause irreversible player softlocks, remove essential NPC services without alternatives, or generate unavoidable surprise danger.
7. **Bounded off-screen cost.** The [adaptive scheduler](adaptive-scheduling.md) runs selective significant events, not all-pairs interactions, detailed dialogue, or off-screen frame-by-frame battles. NPCs use [hybrid routine/utility decisions](npc-routine-utility.md), not continuous full-world planning.
8. **Exactly-once effects.** An event's changes to inventory/resources, population counts, relationships and ownership must be applied coherently once, including across save/load and partial catch-up.
9. **Player-independent world.** An event may happen without player observation; player-facing rumors, tracks or later encounters can reveal consequences, but need not reveal every event.
10. **In-game time only.** Closing the game pauses the event system; no offline event backlog accrues.

## Conceptual event contract (not a storage layout)

An event may refer to: event kind; bounded in-game time or interval; habitat/location; involved stable actor IDs or aggregate actor categories; eligibility and preconditions; consequential effects; and a deduplication/progress marker.

Examples of event types (not a mandatory exhaustive catalog):
- An NPC feeds a hungry wild Pokémon, improving trust and consuming food.
- A traveler rescues a notable Pokémon; later they recognize each other.
- A trainer meets a wild Pokémon and a battle leaves one fainted, not dead.
- A merchant trades with another NPC and changes available local supplies.
- A forager's actions alter habitat resources, influencing future wildlife behavior.
- A trainer takes ownership of a Pokémon through a valid capture/transfer event.

## Conceptual flow

`scheduled encounter opportunity -> verify location/time/actors/resources -> resolve coarse event -> atomically apply authoritative effects -> emit bounded memories/news -> update progress markers`

Nearby active actors may use detailed behavior and interactions. Off-screen actors use coarse resolution; both must respect the same authoritative identities and conservation rules.

## Open engineering decisions

- Event schema, ID allocation, deduplication and transaction/recovery method.
- NPC persistence tiers are locked; exact NPC record layouts, NPC–Pokémon relationship storage and cross-type references remain open.
- Trainer Pokémon ownership, capture/trade permissions and reconciliation with vanilla party/box structures.
- Event eligibility, selection probabilities, frequency and significance thresholds.
- Whether NPC trade/economy is fully modeled or only event-driven.
- How the player learns about significant events through rumors, schedules and environment.
- CPU, RAM, ROM and save budgets; event log length or absence of a persistent log.

No actor counts, event caps, numeric rates or binary layouts are locked before measurement.

## Acceptance scenarios

1. An off-screen NPC feeds a notable Pokémon; resources decrease and a bounded relationship effect persists.
2. A significant NPC–Pokémon rescue is remembered when they later meet on-screen.
3. An NPC capture or trade never duplicates a Pokémon or leaves it counted in the wild.
4. Participants cannot interact across an impassable region without valid travel.
5. Save/load mid-catch-up cannot repeat resource or ownership transfers.
6. Ordinary background encounters do not allocate a persistent record for every participant.
7. No real-world elapsed time creates events while the game is closed.
8. The scheduler stays within measured work budgets and preserves safe gameplay.

See [Off-screen scheduler](offscreen-scheduler.md), [Hybrid catch-up](hybrid-catchup.md), [Adaptive scheduling](adaptive-scheduling.md), [Individual persistence](individual-persistence.md), and [Social memory](social-memory.md).
