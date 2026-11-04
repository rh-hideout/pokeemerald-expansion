# Hybrid wild Pokémon encounters — core gameplay decision

**Decision: LOCKED (2026-11-04).** Wild Pokémon exist as observable, autonomous creatures in the overworld. The player may observe, approach, avoid, feed, help, befriend, or challenge them. **Traditional Pokémon battles remain a supported primary combat and capture path**, rather than replacing the battle engine with real-time overworld combat.

**Progression interface:** combat and noncombat encounters support different meaningful growth paths; see [parallel player progression](parallel-player-progression.md).

## Player experience

- **See the creature first:** wild Pokémon have visible world presence and behavior. No mandatory invisible random-grass ambush is part of the intended core experience.
- **Choose how to engage:** observe, follow, leave alone, offer food, build trust, intervene in a meaningful event, or initiate an appropriate battle.
- **Behavior has consequences:** the Pokémon can flee, approach, defend territory, accept or refuse interaction, and remember significant encounters when promoted to notable persistence.
- **Battles remain Pokémon battles:** an overworld confrontation can transition into the established turn-based battle interface; Pokémon stats, moves, fainting and standard capture compatibility are preserved unless a separate future design decision changes them.
- **Capture is identity-safe:** successful capture transfers the same canonical individual from wild to owned state, with relevant history preserved and no duplicate wild copy. Failed capture must not accidentally create or destroy a Pokémon.
- **Noncombat play matters:** feeding, observing and bonding can be worthwhile without obligating battle or capture; exact noncombat rewards and whether trust can directly enable capture remain open.
- **Readable risk:** territorial and predatory behavior can create danger, but telegraphing, retreat and safe-area protections still apply. Player-initiated encounters are generally optional; not every wild Pokémon must be friendly.
- **Independent ecosystem:** creatures continue their own activities during active gameplay when the player is elsewhere, using existing tiered persistence and off-screen abstraction.

## Conceptual interaction flow

1. A wild Pokémon becomes relevant to a loaded habitat and appears as an overworld entity, reconciled with the habitat population and any persistent identity.
2. The player observes its cues and chooses whether/how to engage.
3. A noncombat interaction resolves in the overworld; a confrontation may enter the traditional battle system.
4. On battle completion, fainting, retreat, capture or other outcomes reconcile to one canonical world state.
5. The Pokémon or population continues living and updating when the player leaves; captured Pokémon do not also remain wild.

This is a gameplay contract, **not** a claim that a particular overworld encounter API, capture trigger, sprite system or battle transition has been implemented.

## Integration boundaries

- [Balanced Pokémon sandbox](balanced-pokemon-sandbox.md): battling, observation, collecting and care are equally legitimate paths.
- [Individual persistence](individual-persistence.md): identity promotion, canonical ownership, fainting and save/load.
- [Ecosystem simulation](../ecosystem-simulation.md), [Danger](../danger-and-ecosystem.md): visible autonomous wildlife, behavior, risk and ecological context.
- [Utility AI](utility-ai.md), [Multi-sensory perception](multi-sensory-perception.md): how creatures select and perceive actions; not dictated by this gameplay pillar.
- [Dependencies](../dependencies.md): actual engine integration and runtime limits remain to be measured.

## Open high-level questions

- Which noncombat interactions affect trust, capture opportunity, field information and rewards?
- What precisely starts a battle (player challenge, proximity, threat escalation, collision or other context)?
- How does an encounter's location, time and actor state survive the transition into and out of battle?
- Which battle formats and capture rules can be retained unchanged from the configured Expansion build?

Keep these open until the player loop and engine feasibility are evaluated. Avoid premature micro-design.
