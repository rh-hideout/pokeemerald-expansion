# Trainers and Gyms

## Trainers

- When a trainer sees the player there is a **chance** they challenge. Many just let the player pass.
- The player can **accept or decline** with no penalty. Trainers may remember.
- Trainer mood can affect the chance (for example, a team that just lost may be eager, a hurt team may not offer).
- The player can also challenge a trainer by talking to them.
- No forced gauntlet routes. Nobody blocks a path.

## Gyms

- Gyms are challenges the player seeks out. Most sit in Safe or Calm towns.
- **Each region has its own set of 8 badges** (64 total across 8 regions). Ur-Kalah has no gyms.
- There is no official top leader or champion title. Reputation is part of untold lore.

## Leaders read the player

The game tracks which badges the player holds (each is a flag). Leaders react through dialogue and team choice.

| What the leader sees | Reaction |
|---|---|
| No badges | Welcoming, beginner team |
| A few local badges | Standard team |
| Many badges from several regions | Serious team, more signature Pokemon |
| A badge from someone they know or respect | Personal line, may go all in |
| Only weak or common badges | Standard team, maybe dismissive |

- Each leader has a pool of 8 to 10 Pokemon and picks 3 to 6 based on the player's badges.
- Signature Pokemon appear only when the leader respects or is provoked by the player.
- Some leaders may ask how the player wants to battle (full team, 3v3, single).

## Lore hooks

Each leader gets:

- A pool of lines for different badge situations.
- Personal hooks ("I heard about you from the old man in Basalt Quay", "That badge... I trained with its leader once.").
- Relationships with other leaders (rivals, former students, old friends). A badge from a leader they know changes their tone.

Example: the player shows a badge from another region. The leader pauses, says they have faced its owner before, and uses their full signature team.

## Implementation notes

Badges are flags, already supported in pokeemerald. Each leader script checks flags and picks dialogue and team. This needs no engine changes.

## Open questions

- Ranked badges (bronze, silver, gold) were skipped for now.
- Gym types per region are still to be decided.
