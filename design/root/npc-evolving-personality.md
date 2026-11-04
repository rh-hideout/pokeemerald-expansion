# Slowly evolving NPC personalities — root design decision

**Decision: LOCKED (2026-11-04).** Notable NPCs have recognizable, enduring dispositions that **change gradually through significant experiences**, including consequential events they experience without the player. Changes affect autonomous decisions while preserving believable continuity. This is a separate human personality model compatible with, but not identical to, [evolving Pokémon personality](evolving-personality.md).

## Locked rules

1. **Recognizable individual baseline.** Notable NPCs start with distinct tendencies influenced by personal background, role and authored characterization, not identical generic behavior.
2. **Slow experience-shaped change.** Consequential journeys, rescue, loss, cooperation, conflict, hardship and repeated success can gradually alter longer-term traits. Routine greetings or a single trivial event do not rewrite a person.
3. **Continuity and bounds.** Change must be gradual, limited and stable enough to avoid abrupt reversals, runaway extremes or frequent oscillation.
4. **Separate personality, needs and relationships.** Long-term dispositions differ from temporary hunger, fatigue or fear, and from [selective memories](npc-social-memory.md) of particular people or Pokémon.
5. **Behavioral influence.** Personality modifies [NPC utility decisions](npc-routine-utility.md), such as caution, generosity, curiosity or sociability, without replacing routines, obligations, valid-action checks or emergency safety rules.
6. **Autonomous growth.** Meaningful off-screen events can shape notable NPCs using bounded selective updates; no exhaustive replay of everyday experiences.
7. **Tiered persistence.** Ordinary background people do not require full permanent trait records. When an ordinary NPC becomes notable, initialize coherent traits consistent with known background and significant promotion event, without fabricating detailed history.
8. **Stable identity and saves.** Developed traits remain attached to the canonical notable NPC across travel, local object instances, save/load and shared-world events.
9. **Fairness and authored obligations.** Evolving personality cannot permanently break essential services, mandatory progress or basic safe recovery. Important authored characterization must remain recognizable.
10. **In-game time only.** No trait change occurs while the game is closed.
11. **Measured resource limits.** No trait counts, byte sizes, update intervals or learning rates are locked until the Expansion build's save/RAM/CPU budgets are measured.

## Conceptual model — not a binary format

- Stable starting disposition or authored character baseline.
- A bounded set of longer-term current tendencies.
- Compact accumulated significance signals or gradual adaptation state, if needed.
- A last-processed in-game timestamp or equivalent progress marker.

`consequential event -> significance check -> bounded gradual trait adjustment -> changed utility preferences -> observable behavior`

Personality does not own event deduplication, identity allocation, navigation or memory storage. Shared events must apply consequential updates once; repeated processing after save/load must not multiply growth.

## Example

A cautious traveling merchant experiences several successful expeditions and meaningful assistance from a Pokémon. Over time the merchant becomes slightly more willing to explore and help others, while still valuing safety and continuing to honor essential trading commitments. Another merchant can respond differently because their dispositions and memories differ.

## Open engineering choices

- Trait vocabulary, range, authored defaults and individual variation.
- Learning/decay rates, significance thresholds and stability mechanics.
- How strong scripted characterization constrains evolution.
- Cross-influence between NPC social memory, personality and utility scores.
- Trait initialization on NPC promotion, and save serialization/versioning.
- Observable dialogue, animation and behavioral feedback.
- Performance profiling, testing and capacity/overflow behavior.

## Acceptance scenarios

1. Two notable NPCs with different dispositions make different valid choices under similar conditions.
2. Several consequential experiences gradually change a notable NPC's behavior.
3. One routine encounter does not instantly reverse long-term traits.
4. A notable NPC retains evolved traits after travel and save/reload.
5. An unseen consequential NPC–Pokémon event can shape a notable NPC's personality.
6. An anonymous crowd does not allocate permanent trait histories per person.
7. No personality changes accumulate while the game is closed.
8. No trait change creates an impossible action or permanently removes essential player services.
9. Replaying a committed event does not apply the same trait change twice.

See [NPC social memory](npc-social-memory.md), [NPC routines and utility](npc-routine-utility.md), [NPC persistence](npc-persistence.md), [Shared events](shared-world-events.md), [Pokémon personality](evolving-personality.md), and [Save budget](save-budget.md).
