# Balanced Pokémon sandbox — core player-experience pillar

**Decision: LOCKED (2026-11-04).** The game supports **multiple equally legitimate ways to play**. Exploration, Pokémon discovery and collection, battling, bonding and care, survival, and participation in the living world are complementary paths rather than a single mandatory progression ladder. Exploration and autonomous ecology are the game's distinctive identity, **not compulsory activities that invalidate the others**.

**Wild encounters (locked):** [hybrid overworld interactions with traditional battle compatibility](hybrid-wild-encounters.md) support both combat and noncombat play.

**Progression (locked):** [parallel player progression](parallel-player-progression.md) allows independent but interacting development through training, bonds, knowledge, traversal, discoveries and optional gyms.

## Main experience

**Explore → encounter opportunities → choose how to interact → gain experiences, relationships, knowledge, Pokémon or capabilities → explore or play differently.** This is a flexible loop, not a fixed required sequence. Players can also remain in a town, train, care for Pokémon, trade or follow a particular NPC's story.

### Equal legitimacy, not identical rewards

- **Exploration and discovery:** uncover places, routes, habitats, mysteries and useful world knowledge.
- **Collection and observation:** find, observe, befriend or capture Pokémon without requiring constant combat.
- **Battling and training:** voluntary wild/trainer challenges and optional gym circuits provide meaningful mastery.
- **Bonding and care:** feeding, trust, raising, traveling with and helping individual Pokémon matter independently of badges.
- **Survival and traversal:** prepare for journeys, manage food/stamina and use Pokémon abilities to reach interesting places; safe regions remain forgiving.
- **Living-world participation:** interact with autonomous NPCs, wildlife and emergent events, with lasting but bounded consequences.

A session specializing in any of these can be satisfying; **equal legitimacy does not mean every activity yields the same items, rewards or efficiency**.

## Locked player-facing rules

1. **No mandatory dominant path.** The game does not require completing gym circuits, a story, a fixed Pokédex quota or an economic career to enjoy or broadly explore the world.
2. **Player agency.** Wild encounters, trainer battles, NPC requests and environmental opportunities offer meaningful choices, including avoidance or refusal when appropriate. Genuine environmental danger still exists in signposted zones.
3. **World independence.** Pokémon and NPCs act on their own during active gameplay; the player can influence but does not have to manage them.
4. **Progress in multiple dimensions.** Knowledge, access, relationships, party development, discoveries, resources and optional badges can each matter. Do not force all growth through one global level or badge score.
5. **Open-world consistency.** Travel difficulty can arise from geography, environment, preparation or abilities, but not compulsory story completion.
6. **Safe by default.** Food, hazards and setbacks add context without routine punishment or irreversible starvation death. Harder areas reward preparation and risk-taking.
7. **Distinct Pokémon identity.** Significant individuals and bonds persist; captures reconcile canonical ownership with the wild ecosystem.
8. **Optional authored content.** Mysteries, character stories, trainer challenges and gym circuits enrich the sandbox without overriding autonomous world systems.
9. **Readable consequences.** Players need discoverable cues about danger, Pokémon behavior, navigation, supplies and the effects of meaningful choices; exact UI is not decided.
10. **Practical scope.** This is a design target, not evidence that every path is already implemented or equally deep at launch. Build and validate a representative gameplay slice first.

## Representative play sessions

- **Explorer:** travel from Meadowmere, notice unusual tracks, find a hidden grove, map a route and return.
- **Collector/naturalist:** observe a feeding Pokémon, learn its behavior, gain trust and attempt a capture.
- **Trainer:** practice with a partner, accept a voluntary battle and seek an optional gym challenge.
- **Caretaker:** gather berries, feed and recover companions, improve trust and assist a distressed wild Pokémon.
- **Wanderer:** meet a traveling NPC, follow a rumor, avoid a storm and discover an unexpected wildlife event.

Each session has a valid stopping point without completing another path's objectives.

## Interfaces with established design

- [Overview](../overview.md): authoritative world vision.
- [Exploration](../exploration.md), [Trainers and gyms](../trainers-and-gyms.md), [Survival](../survival.md), [Traversal](../traversal.md), [Riding and mounts](../riding-and-mounts.md): complementary activities.
- [Individual persistence](individual-persistence.md) and [Shared living-world events](shared-world-events.md): consistent world consequences.
- [Dependencies](../dependencies.md) and [Save budget](save-budget.md): feasibility prerequisites.

## Open high-level work — not additional locked decisions

- Battle/capture and visible encounter integration with the existing Pokémon engine.
- Player-facing progression and discovery rewards without a dominant mandatory ladder.
- World-map connectivity, exploration feedback, controls and navigation UX.
- Feasible initial vertical slice and measured engine budgets.

Do not branch into minor subsystem tuning until the high-level player experience and technical feasibility have been validated.
