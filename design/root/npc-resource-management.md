# Hybrid NPC resource management — root design decision

**Decision: LOCKED (2026-11-04).** Notable NPCs track **consequential possessions, supplies and resource needs**, while routine economic activity, ordinary people and background trade use **aggregated resource state**. Food, money, tools, equipment and scarcity may influence behavior, travel, cooperation and long-term plans without simulating a complete item-by-item economy for every inhabitant.

## Locked invariants

1. **Two levels of accounting.** Named or otherwise notable NPCs retain important owned items, relevant supply quantities and meaningful obligations. Ordinary background consumption and production use bounded town, group or population aggregates.
2. **Consequential versus incidental goods.** Track individual possessions when identity, scarcity, ownership, trade, survival or a goal makes them matter. Do not persist every mundane meal or commodity movement as a separate item.
3. **Real resource constraints.** Food, rest supplies, tools, equipment, money and access to goods can enable, delay or change utility actions and [hierarchical milestones](npc-hierarchical-planning.md). Missing supplies do not magically appear because a goal requires them.
4. **Canonical ownership.** Resources belong to a single actor, group, settlement stock or world location at a time, with explicit transfers. No duplicate inventory from local/off-screen representations, trading, save/load or catch-up.
5. **Conservation and source rules.** Transactions debit their source and credit their destination once. Renewable resources require a defined production, gathering or replenishment source; bounded aggregates cannot mint unlimited goods accidentally.
6. **Shared but distinct group stores.** [Dynamic NPC groups](npc-dynamic-groups.md) may pool food, money or equipment where plausible, without erasing personal ownership or allowing simultaneous spending from both group and member records.
7. **Survival and personality matter.** Hunger, travel preparation, generosity, caution, habits and relationships can influence acquisition, consumption and sharing; essential needs and safety still override optional commerce.
8. **Tiered off-screen economy.** Notable actors receive selective resource events; ordinary shops, households and trade routes use aggregate inflow/outflow or availability bands rather than continuous detailed transactions.
9. **Geographic and temporal causality.** Obtaining or trading goods requires accessible sources, valid meetings/routes and elapsed in-game time. Distant purchases cannot occur instantly without an explicitly supported communication/delivery system.
10. **Stable player services.** Ordinary scarcity may affect availability and prices, but essential healing, progression and core town services must remain recoverable and discoverable. Economic simulation cannot permanently softlock the player.
11. **Bounded work and storage.** Persistent inventories, resource categories, transaction history and simulation frequency must fit measured GBA CPU/RAM/save budgets. Use compact state and exactly-once events, not unlimited logs.
12. **No closed-game progression.** Production, spoilage, consumption, travel supplies and trade advance only while the game runs; no offline catch-up.

## Conceptual resource contract — not executable code

`actor/group/settlement stock + need or milestone -> availability and ownership check -> valid gather/buy/trade/consume/share action -> exactly-once resource transfer -> updated needs, plans and world events`

A notable NPC might retain a compact list of meaningful possessions and supplies plus coarse wealth or food reserve. A settlement might retain aggregate food availability, demand and replenishment. Exact representation, units and prices are open.

### Example

A traveling ranger wants to visit a distant forest. They need food and appropriate equipment. They may buy supplies from a merchant, gather some along a safe route or postpone travel if stock is low. A companion may share provisions through an explicit group transfer. The village economy is updated in aggregate rather than simulating every villager shopping.

## Boundaries with other systems

- [NPC routines and utility](npc-routine-utility.md) select when to eat, trade, gather or prepare.
- [NPC hierarchical planning](npc-hierarchical-planning.md) checks resource prerequisites for milestones.
- [Shared world events](shared-world-events.md) own consequential transfer semantics and replay safety.
- [NPC groups](npc-dynamic-groups.md) coordinate pooled resources with canonical ownership.
- Population ecology, Pokémon ownership and player inventory may interact through explicit conversion/transfer boundaries; this decision does not redefine the game's existing item mechanics.

## Open engineering decisions

- Which goods require item identity, counts, quality, durability or merely abstract availability.
- NPC money/wealth representation, prices, replenishment, shortages and trade routes.
- How player item inventory, Pokémon held items, shops and NPC inventories reconcile.
- Food production, spoilage, gathering and consumption formulas.
- Group resource allocation, lending, gifting, theft and contested ownership rules.
- Resource serialization, transaction deduplication, migration and debug tooling.
- Actual capacities, update rates and CPU/RAM/save measurements.

No inventory slot count, currency amount, transaction cap or economic rate is locked before measurement.

## Acceptance scenarios

1. A notable traveler buys supplies, and both their inventory and seller stock change once.
2. A ranger cannot start a resource-dependent milestone without valid supplies or an alternate plan.
3. A group shares food without duplicating it across member and group records.
4. Save/reload mid-trade does not repeat a transfer.
5. Ordinary crowds do not each require detailed persistent inventories.
6. A distant settlement's shortages are simulated with bounded aggregate updates.
7. Off-screen trade obeys plausible routes, meetings and elapsed in-game time.
8. A critical service remains usable or has a coherent recovery path despite shortages.
9. No negative stock or unbounded resource creation occurs through repeated catch-up.
10. Closing the game does not advance resource production, consumption or spoilage.

See [NPC planning](npc-hierarchical-planning.md), [NPC routines](npc-routine-utility.md), [NPC groups](npc-dynamic-groups.md), [Shared events](shared-world-events.md), [Population ecology](population-ecology.md), and [Save budget](save-budget.md).
