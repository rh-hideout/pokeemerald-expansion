# Food and Survival

Survival is one complementary pillar of the [balanced Pokémon sandbox](root/balanced-pokemon-sandbox.md), not a compulsory high-pressure playstyle. **Everyone eats**: the player, NPCs, wild Pokemon and the player's own Pokemon. Berries are the base food, with other foods added on top.

## Core rules

- Every living creature has a hunger state and needs to eat.
- Hunger is **slow and forgiving where the world is safe**, and **tight where the world is dangerous**. Towns and gentle regions have plenty of food. Wild and Perilous zones do not.
- Food is the thing that ties the ecosystem together: it explains where Pokemon live, roam, fight and settle.

## Hunger states

Each creature moves through simple states instead of a precise number:

| State | Effect |
|---|---|
| **Fed** | Full performance, recovers and grows normally |
| **Peckish** | No penalty, but starts looking for food |
| **Hungry** | Weaker stats, slower recovery, riskier behavior |
| **Starving** | Heavily weakened, desperate, may faint or refuse commands |

Starvation causes fainting and collapse, never permanent death.

## The player

- Has a hunger state that changes over time and with exertion (running, long trips, battling).
- Eats berries and prepared food to recover. Food type affects how long the effect lasts.
- Long expeditions (especially Ur-Kalah) require planning and carrying food.
- Safe towns make food easy to buy or cook, so ordinary play stays comfortable.

## The player's Pokemon

- Each party Pokemon has its own hunger state.
- Fed Pokemon fight better, recover faster and bond more strongly.
- Hungry Pokemon perform worse, may ignore orders, and may eat berries on their own if they find some.
- Different species prefer different foods (berries, meat, fish, roots), so feeding is part of caring for them.
- Pokemon nearby and boxed Pokemon eat on a simplified schedule so that boxes are not a chore.

## Wild Pokemon

- Herbivores and omnivores feed on berry groves and plants in their territory.
- Carnivores hunt prey. A territory with too little food pushes its Pokemon to roam, and predators follow prey.
- A starving individual is weaker and more desperate. A well-fed one recovers and grows faster.
- Rare foods and rare berries draw rare species.
- Over-harvesting a grove changes who lives there.

## NPCs

- Towns and camps keep gardens, stores and trade routes.
- Failed harvests change dialogue, prices and who is willing to travel.
- Remote camps and hermits depend on food and will trade for it.
- NPC trainers feed their Pokemon and may ask the player for specific food.

## Food sources

- **Berries:** common, rare and region-exclusive types. Trees, bushes and gardens.
- **Cooked food:** made at camps and towns from berries and other ingredients.
- **Meat, fish and roots:** hunted, fished or foraged. Mostly for carnivores and for the player.
- Food effects can include healing, status cures and short stat boosts.

## Why it stays safe by default

- Food is abundant in safe regions, so hunger rarely becomes a crisis there.
- The scarcity curve follows danger level: Safe is plentiful, Calm is easy, Wild is tight, Perilous is harsh.
- No game over from hunger. Starving means collapse and recovery, not loss of the save.

## Implementation notes

Emerald already has berry trees, growth stages, soil, mulch, berry items and a real-time clock. Hunger needs new state:

- Player hunger: a few bytes.
- Party Pokemon hunger: a small field per party member.
- Tracked wild individuals: hunger state folded into the individual record.
- Berry groves: a stock and regrowth value each.
- Off-screen creatures use bulk updates when the player changes maps or time passes.

Save space must be measured in the repo before fixing counts.

## Open questions

- Hunger decay rates for player and Pokemon (in-game world time is locked; rates remain open).
- The full food list and which species eat what.
- How boxed Pokemon are handled (simplified schedule or paused).
- How cooking works (camp action, item combination or recipe system).
