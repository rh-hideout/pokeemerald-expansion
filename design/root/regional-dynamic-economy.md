# Regional dynamic economy — root design decision

**Decision: LOCKED (2026-11-04).** Settlements and regions maintain bounded aggregate production, consumption, stocks, demand, trade and scarcity. Local prices and availability change gradually in response to these conditions. Consequential individual transactions remain possible, but routine commerce is abstracted.

## Locked invariants

1. **Settlement-level economy.** Maintain compact stocks, production/consumption pressure and price/availability signals by resource category; no detailed inventory or market simulation for every background resident.
2. **Causal production.** Farming, gathering, crafting, population demand, climate, ecology and disruption affect supply through explicit sources and sinks. Never create stock from nothing.
3. **Connected physical trade.** Shipments require source stock, permitted world-route connections, transport and elapsed in-game time. Closed routes delay or reroute deliveries.
4. **Gradual local response.** Scarcity, demand and deliveries can change prices and availability, with bounded smoothing rather than instant global uniform prices or runaway oscillation.
5. **Meaningful transactions.** Notable NPC and player purchases, gifts and deliveries may affect actor inventories and settlement aggregates, with exactly-once debit/credit semantics.
6. **Conservation across levels.** Ownership and quantities reconcile across actor, group and settlement stores; explicit production, consumption and loss explain net changes.
7. **Regional character.** Geography, resources, population, climate and connectivity allow different markets, including persistent local shortages and surpluses.
8. **Recoverable shortages.** Optional goods and prices can be affected by scarcity; critical healing, progression and other essential services remain accessible or have coherent alternatives.
9. **Behavioral integration.** NPC plans, utility decisions, travel, trade groups and shared world events can react to regional scarcity without detailed economy agents.
10. **Bounded off-screen updates.** Aggregate regional ticks and selected consequential events replace continuous merchant/household simulation. Catch-up is bounded and cannot duplicate deliveries.
11. **Stable save/load.** Stocks, in-transit shipments, update markers and transactions must be reconciled exactly once; no negative stocks, overflow or double credit.
12. **In-game time only.** Production, consumption, transport, prices and scarcity do not advance while the game is closed.

## Conceptual flow — not a prescribed formula

`settlement stock + production + received shipments - consumption - sent shipments - losses -> bounded availability and price pressure`

Categories might include food, medicine, travel supplies and crafting materials. The exact categories, stock units, price functions and update cadence remain open.

### Example

A storm ruins a coastal harvest and blocks a bridge. Food availability falls and some optional prices rise gradually. A merchant reroutes supplies from another settlement, debiting the origin and crediting the destination once after plausible travel time. Core recovery services remain usable.

## Boundaries and open engineering work

- [NPC resource management](npc-resource-management.md) owns consequential actor/group possessions and transfer rules; this system owns settlement aggregates.
- [NPC navigation](npc-hybrid-navigation.md) validates physical trade routes; [shared events](shared-world-events.md) commit consequential deliveries and disruptions; [off-screen scheduling](offscreen-scheduler.md) bounds simulation.
- Open: commodity groups, market boundaries, stock units, prices, smoothing, production/consumption, trade capacity, delays, route failure, player shop integration, save format, and profiling.
- No numerical stock, price, shipping or memory limits are locked before measuring the actual Expansion build.

## Acceptance scenarios

1. A shortage gradually changes local supply and optional prices without instantly changing all regions.
2. Two towns can have different stock and prices.
3. Trade takes valid routes and in-game time; blocked routes cannot deliver instantly.
4. One shipment debits origin and credits destination exactly once, including across save/load and catch-up.
5. Notable purchases matter without detailed background household simulation.
6. Essential recovery/progression remains accessible during shortages.
7. Aggregate updates are bounded, nonnegative and safe against overflow.
8. No economy progression occurs while the game is closed.
