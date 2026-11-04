# Dynamic NPC small groups within stable communities — root design decision

**Decision: LOCKED (2026-11-04).** NPCs may **form, join, leave and dissolve small social groups** through relationships, needs, shared goals and consequential events. Traveling parties, work teams, cooperative foragers, protective groups, friendship circles and households can evolve. **Towns, major institutions and essential services remain stable**; autonomous small-group behavior does not imply freely generating new cities, governments or gym institutions.

## Locked invariants

1. **Dynamic membership.** NPCs can form groups, join, separate or switch affiliation when plausible goals, bonds, opportunities or conflicts change.
2. **Individual autonomy remains.** A member retains canonical identity, personality, needs, memories, ownership and personal goals. Group membership never turns people into one undifferentiated actor.
3. **Shared purpose, not universal obedience.** Groups can coordinate travel, work, safety, care and social activity; members may disagree, pause, leave or prioritize urgent individual needs.
4. **Stable world institutions.** Towns, gym circuits, core shops, recovery and major authored organizations remain coherent and usable. A spontaneous group cannot silently remove essential player access or create permanent unplanned settlements.
5. **Plausible formation.** Membership changes require social opportunity, geographic/time compatibility or an established communication channel. A stranger cannot instantly join a distant party without a valid meeting or invitation.
6. **Social consequences.** Friendship, trust, obligations, rivalries and remembered shared events influence cooperation through [selective NPC social memory](npc-social-memory.md), but do not guarantee permanent loyalty.
7. **Independent emergent activity.** NPCs may form or change groups while off-screen through selective [shared living-world events](shared-world-events.md), including interactions involving Pokémon.
8. **Group movement obeys routes.** Shared journeys use [hybrid NPC navigation](npc-hybrid-navigation.md); members cannot teleport to a leader or travel over inaccessible terrain.
9. **Tiered fidelity and persistence.** Significant groups involving notable NPCs may retain compact purpose, membership and progress; ordinary crowds or temporary teams use aggregate/lightweight state. No exhaustive persistent social graph.
10. **Canonical membership and accounting.** Each group/member reference must reconcile with stable identity; joining, leaving, shared inventory, travel and event outcomes must not duplicate actors, resources or Pokémon.
11. **Bounded coordination.** Nearby groups may coordinate concrete actions; off-screen groups use coarse collective progress and selective individual consequences. No full all-pairs negotiation, pathfinding or global group recomputation.
12. **No closed-game progression.** Membership, travel and shared plans advance only during in-game time, never while the game is closed.
13. **Safety and continuity.** Group formation and dissolution cannot trap the player, permanently remove authored services, strand critical NPCs or erase protected family/care ties.

## Conceptual group contract — not a storage layout

A group may have a bounded identifier, type/purpose, membership references, shared destination or task, rough cohesion/commitment and last in-game update. Individual NPC records remain authoritative for identity and personal state. An NPC may belong to multiple kinds of association (e.g. household and work team), but exact concurrent membership rules remain open.

`social opportunity or shared need -> validate eligible actors and location -> form/join/leave event -> update canonical memberships once -> coordinate bounded task/travel -> reconcile outcomes and memories`

### Group examples

- Two travelers decide to cross a dangerous route together, separate when they reach a village and remember the journey.
- A few townspeople organize to help a stranded Pokémon; their cooperation can affect later relationships.
- A merchant joins a temporary caravan but continues to honor essential shop availability through a substitute or discoverable schedule.
- A family remains a meaningful enduring bond even when members travel separately; temporary group dissolution does not delete family history.

## Architecture boundaries

- Group coordination influences, but does not replace, [NPC routine/utility AI](npc-routine-utility.md).
- [NPC social memory](npc-social-memory.md) stores meaningful personal bonds; group records should not duplicate complete relationship histories.
- [NPC information sharing](npc-information-sharing.md) may spread invitations or plans through plausible communication; knowing about a group is not membership.
- Shared events own consequential transitions and deduplication; navigation owns route feasibility.
- Important authored organizations and town services are stable content structures, not freely emergent group records.

## Open engineering decisions

- Group identity and record layout, size, membership cap and overflow policy.
- Which group types are persistent, transient or derived from authored household/workplace data.
- Leadership, voting, cohesion, conflict, split/merge and coordination algorithms.
- Multi-group membership, families, NPC–Pokémon companions and player participation.
- Group supplies, shared ownership, resources and inventory conservation.
- Formation and dissolution thresholds, scheduling cadence and group travel synchronization.
- Save migration, map-object materialization and debug/consistency tests.

No group counts, member limits, byte sizes or CPU budgets are locked until the actual Expansion build is measured.

## Acceptance scenarios

1. Two compatible NPCs form a temporary travel group after a plausible encounter.
2. A member can leave without losing their identity, personal goals or memories.
3. A group can complete a joint rescue without duplicating its resources or effects.
4. Group members cannot bypass blocked world routes by following a distant leader.
5. Save/reload preserves a consequential group without duplicate membership.
6. A background crowd does not allocate a permanent social graph per person.
7. A group disbands without deleting family or other protected enduring relationships.
8. Autonomous group activity does not permanently disable shops, gyms or recovery.
9. Off-screen group updates stay bounded and do not simulate every interaction.
10. Closed-game time never advances group plans.

See [NPC persistence](npc-persistence.md), [NPC social memory](npc-social-memory.md), [NPC routines and utility](npc-routine-utility.md), [NPC navigation](npc-hybrid-navigation.md), [Shared events](shared-world-events.md), and [Save budget](save-budget.md).
