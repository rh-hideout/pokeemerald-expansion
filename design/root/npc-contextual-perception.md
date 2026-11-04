# Contextual multi-sensory NPC perception — root design decision

**Decision: LOCKED (2026-11-04).** Nearby NPCs perceive relevant people, Pokémon, hazards and environmental events through **contextual sight, hearing and appropriate environmental cues**, limited by distance, obstacles, lighting, weather, attention and circumstances. Off-screen awareness is approximated through bounded, plausible events and regional context rather than detailed sensor simulation.

## Locked invariants

1. **Multiple contextual channels.** Sight and hearing provide baseline awareness; relevant environmental cues such as tracks, smoke, weather or nearby activity may contribute when supported.
2. **Environment matters.** Walls, terrain, foliage, darkness, rain, noise, distance and orientation or attention (where modeled) influence detection by channel.
3. **Partial evidence, not omniscience.** A sound may reveal a general direction or disturbance, not an exact unseen Pokémon identity or tile. Being on the same map or region does not imply knowledge.
4. **Different observers.** Roles, experience, attention, current activity and condition may influence perception; a distracted merchant need not react like an alert ranger.
5. **Sensing versus memory versus reports.** Live cues, [selective social memories](npc-social-memory.md) and information received from other actors are separate knowledge sources, with distinct freshness and reliability.
6. **Behavioral integration.** [NPC utility AI](npc-routine-utility.md) weighs perceived danger, opportunities and social signals; sensing does not directly force arbitrary behavior or reveal an unreachable route.
7. **Nearby detail, distant abstraction.** Local actors receive bounded cue checks. Distant notable NPCs use coarse environmental context and causally eligible [shared events](shared-world-events.md); ordinary background crowds use aggregate signals.
8. **Causal geography.** Information must have a plausible source, time and reachable location. NPCs cannot witness or hear an event across inaccessible regions without an explicit communication mechanism.
9. **Bounded cost.** Avoid full-map per-frame ray tracing, every-pair sensing, detailed acoustic propagation or persistent exhaustive cue trails. Exact ranges, caps and update cadence await profiling.
10. **Identity-safe recognition.** Recognition of a known person or Pokémon requires sufficient evidence and stable identity references; recycled local objects must not inherit a previous actor's recognized identity.
11. **Fairness.** Threat detection and reactions must respect readable danger, avoidable encounters and safe-region constraints; no impossible surprise targeting.
12. **In-game time only.** Cue aging, environmental updates and off-screen awareness advance only through elapsed in-game time; closing the game adds nothing.

## Conceptual contract — not code

`nearby actor/event -> cheap range/relevance filter -> channel-specific environment check -> bounded uncertain cue -> memory/context interpretation -> utility decision`

Potential cue attributes: channel, approximate origin, possible identity, confidence, age and event category. No field sizes, formats or formulas are locked.

### Local layer

- Sight checks use relevant terrain/visibility constraints and limited candidate observers.
- Hearing checks can communicate a disturbance even when visual line of sight is blocked.
- Context such as storms, nighttime or loud machinery changes appropriate channels.
- Cues can expire or be superseded; the exact expiration policy remains open.

### Off-screen layer

- Coarse habitat/route conditions and selective consequential events determine what a distant notable NPC could plausibly notice.
- An NPC may learn about an event later from a witness, rumor or message, but such communication must be modeled as information transfer, not instant omniscience.
- Background populations need not retain individual sensory state.

## Example

A ranger sees a Pokémon on a clear forest trail and recognizes it from an earlier rescue. A merchant behind a rock hears movement but cannot identify its source. During heavy rain, that sound is less reliable. A distant shopkeeper does not learn about the encounter unless a plausible report reaches them.

## Open engineering decisions

- Local vision, hearing and cue ranges, occlusion approximations and light/weather handling.
- Observer attention, orientation and role-specific perception traits.
- Cue representation, confidence, lifetime and deduplication.
- Whether lightweight tracks, footprints or smells exist for selected contexts.
- Witness reports, rumor transmission and message delays.
- How perception is connected to existing GBA object-event detection, scripts and trainer sight.
- Scheduling cadence, debug instrumentation and measured ROM/RAM/CPU budgets.

## Acceptance scenarios

1. An unobstructed NPC detects a nearby visible Pokémon, but not the same target visually behind a solid wall.
2. An obscured noise produces a partial cue without exact hidden coordinates.
3. Heavy rain reduces an appropriate hearing cue without universally disabling sight.
4. Two NPCs with different attention or experience respond differently to the same disturbance.
5. A remembered Pokémon is recognized only after plausible current evidence.
6. A distant NPC cannot react to an event before a valid encounter or report.
7. Off-screen updates do not perform per-person full sensory scans.
8. A stale cue expires or loses reliability rather than granting permanent live tracking.
9. Save/load does not confuse a recycled local sprite with a known actor.
10. Closed-game time does not advance cue aging or world events.

See [Pokémon perception](multi-sensory-perception.md), [NPC routines and utility](npc-routine-utility.md), [NPC social memory](npc-social-memory.md), [Shared events](shared-world-events.md), and [Off-screen scheduler](offscreen-scheduler.md).
