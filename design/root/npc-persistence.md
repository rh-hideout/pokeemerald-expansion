# Tiered NPC persistence — root design decision

**Decision: LOCKED (2026-11-04).** Human NPCs use **tiered persistence**: important and memorable people keep stable identities and consequential histories; ordinary crowds/background people use lightweight routines or abstract population state. Ordinary NPCs can be promoted to notable status through meaningful player interaction **or independent world events**, even when unseen by the player.

## Tiers and runtime fidelity

| Tier | Persistent information | Simulation |
|---|---|---|
| Background population / routine | Aggregate demographics, service availability, habitat/town activity, or authored lightweight routine; no mandatory permanent identity for each person | Bounded routine/aggregate off-screen updates |
| Notable individual | Stable identity, meaningful home/role/location, goals, relationships, salient events and necessary state | Coarse off-screen individual events; detailed local behavior when nearby |
| Active local NPC | Runtime presentation of either tier, not automatically a separate save tier | Local movement, dialogue, perception and interactions as applicable |

**Persistence and simulation fidelity are separate.** A notable NPC remains notable off-screen; an ordinary visible NPC need not receive a permanent record.

## Locked invariants

1. **Stable notable identities:** important NPCs and promoted individuals retain identity across maps and saves, including travel and shared NPC–Pokémon events.
2. **Two promotion paths:** meaningful player involvement or consequential independent events (e.g. rescue, remarkable journey, becoming a community figure, persistent relationship). Routine greetings or mere proximity are insufficient.
3. **Authored roles remain reliable:** essential service providers, gym leaders and other important authored NPCs begin notable or have an equivalent stable authored identity; world autonomy must not permanently break critical gameplay services.
4. **No silent demotion:** established notable identities and meaningful relationships cannot disappear merely because the pool is full. Capacity overflow needs an explicit policy after save measurements.
5. **One canonical person:** an NPC cannot be instantiated twice because local object events and off-screen state both claim ownership. Transitions must reconcile identity and position.
6. **Bounded histories:** [selective NPC social memory](npc-social-memory.md) stores salient relationships and outcomes rather than an unlimited event log; background NPCs do not require full individual social graphs.
7. **Shared-world compatibility:** notable NPCs may form persistent relationships with Pokémon and other people; resource, ownership and travel consequences use the shared event contract.
8. **Geographic plausibility:** NPC travel and encounters obey reachable routes, schedules and environmental constraints; exact NPC travel graph integration remains open.
9. **Tiered off-screen work:** background people use lightweight updates; notable NPCs receive selective consequential events under the adaptive scheduler. [Hybrid routines and utility AI](npc-routine-utility.md) govern behavior without requiring detailed decisions for everyone.
10. **In-game time only:** closing the game does not advance routines, relationships, journeys or promotion.
11. **Player-facing fairness:** autonomy cannot irreversibly block required services, quests or safe recovery.

## Promotion concept (implementation not locked)

`background actor / temporary local NPC -> consequential event evidence -> stable notable identity allocation -> transfer relevant state -> ongoing persistent life`

An independent event may establish significance without requiring player observation. Prevent duplicate promotion from repeated event delivery. If a candidate cannot be allocated safely, retain a bounded pending significance signal or use another explicit capacity policy; do not silently delete an existing notable.

## Examples

- A market crowd uses aggregate town activity rather than a permanent identity for every shopper.
- A recurring vendor whose dealings affect several settlements becomes notable and can be recognized later.
- An NPC who rescues a notable wild Pokémon off-screen may become notable, preserving their bond.
- A gym leader remains a stable authored individual even when traveling elsewhere.

## Open engineering decisions

- Exact NPC identity namespace, storage schema, capacity, versioning and save migration.
- Whether authored lightweight NPCs have stable template IDs without individual history.
- Promotion thresholds, evidence buffering and overflow behavior.
- NPC-specific personality, memory and relationship limits.
- Which trainer-owned Pokémon receive permanent identity, and how ownership is stored.
- NPC pathfinding, schedules, service fallbacks and travel graph semantics.
- Local object-event reconciliation and debug/consistency tests.

Do not infer NPC record size, count or spare save space before profiling the actual Expansion build.

## Acceptance scenarios

1. A named NPC leaves town and returns later with the same identity and salient history.
2. A routine crowd does not allocate permanent records for every member.
3. An unseen rescue promotes an ordinary NPC and preserves the consequential NPC–Pokémon bond.
4. Save/reload does not duplicate an NPC or replay promotion.
5. A notable NPC remains stable when simulated coarsely off-screen.
6. Exhausted identity capacity does not silently erase established people.
7. Critical player services remain reachable despite NPC travel.
8. Closing the game creates no NPC time progression.

See [Shared world events](shared-world-events.md), [Off-screen scheduler](offscreen-scheduler.md), [Adaptive scheduling](adaptive-scheduling.md), [Individual Pokémon persistence](individual-persistence.md), and [Save budget](save-budget.md).
