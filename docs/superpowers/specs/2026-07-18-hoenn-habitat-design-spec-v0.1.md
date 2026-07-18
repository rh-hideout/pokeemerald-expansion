# Hoenn Habitat — Pre-Handoff Design Spec (v0.1)

Codename: **Hoenn Habitat**. Base: `pokeemerald-expansion` (pin latest stable release tag). Target: Mac local build, mGBA headless verification. This document is the content-schema contract between design (Jay + Claude chat) and engineering (Claude Code). Everything here is draft — react freely.

---

## 1. Core Loop (canonical statement)

> Explore freely → inspect a habitat spot → decode its staged hints → satisfy **appear conditions** → the Pokémon manifests and persists → satisfy **befriend conditions** (usually: offer the right berry/item) → it becomes a **resident** → assign it to Grove work, solo or paired → co-produce rarer berries/items → spend those on harder spots → repeat until the region's mystery is solved.

**Design law:** *Every location is approachable; every condition is inspectable; solvability is what's gated.*

---

## 2. Spot Definition Schema (the contract)

A **Spot** is a data record + a small script shell. Claude Code builds the engine that evaluates these; we author them forever after as data.

```c
struct HabitatSpot {
    u16  spotId;            // globally unique
    u16  species;           // SPECIES_* (expansion constant)
    u8   tier;              // 1–4
    u8   zoneId;            // map/region grouping
    // Condition sets (each is a list of Condition, ALL must pass unless grouped OR)
    const struct Condition *appearConditions;
    const struct Condition *befriendConditions;
    // Hint text (staged reveal)
    const u8 *hintDormant;     // vague flavor
    const u8 *hintStirring;    // partial reveal (>=1 appear condition met)
    const u8 *hintActive;      // full befriend checklist (Pokémon visible)
    // Post-befriend
    u8   workerRole;           // primary role (see §4); ROLE_NONE allowed
    const u8 *personalityId;   // dialogue pool key
};
```

### Spot state machine (per spot, saved)

```
DORMANT → STIRRING → ACTIVE → BEFRIENDED
```

- **DORMANT:** no appear conditions met. Inspect shows `hintDormant`.
- **STIRRING:** ≥1 appear condition met. Inspect shows `hintStirring`. (Optional per-spot flag: reveal a checklist of appear conditions with met/unmet ticks.)
- **ACTIVE:** all appear conditions met → species visible at the spot as an overworld sprite, persists indefinitely. Inspect/interact shows `hintActive` (full befriend checklist) and enables the offer verb.
- **BEFRIENDED:** dex "caught" flag set, resident created, spot sprite becomes ambient (Pokémon may remain visible as flavor or relocate to Grove per spot flag).

### Condition vocabulary (the enum)

Each condition = `{ type, paramA, paramB, paramC, flags }`. `flags` supports `NEGATE` (spite mechanics) and `OR_GROUP(n)` (any-of grouping).

| # | Type | Params | Example use |
|---|------|--------|-------------|
| 1 | `COND_ITEM_PLACED` | itemId, count | 4 water bottles placed at spot |
| 2 | `COND_ITEM_OFFERED` | itemId, count | Befriend verb: offer 1 Spicy Berry |
| 3 | `COND_PARTY_SPECIES` | species, count | Bring a Bulbasaur |
| 4 | `COND_PARTY_FRIENDSHIP` | comparator, value | A party member with max friendship |
| 5 | `COND_PARTY_MOVE` | moveId | Party member knows Flash |
| 6 | `COND_PARTY_NATURE` | natureId | A Jolly party member |
| 7 | `COND_RESIDENT_SPECIES` | species, zoneId (0=any) | Resident Pinsir in this zone |
| 8 | `COND_RESIDENT_COUNT` | typeFilter, count | 5 Ghost/Dark residents anywhere |
| 9 | `COND_TIME_OF_DAY` | windowStart, windowEnd | Night only (expansion has RTC/day-night) |
| 10 | `COND_WEATHER` | weatherId | Raining (natural OR worker-generated) |
| 11 | `COND_STORY_FLAG` | flagId | Chapter 2 complete |
| 12 | `COND_DEX_COUNT` | comparator, value | ≥30 residents befriended |
| 13 | `COND_BERRY_MATURE` | berryId, zoneId | Mature Oran tree in this zone |
| 14 | `COND_LIFETIME_STAT` | statId, comparator, value | 100 berries harvested (reuse Gen 3 game-stats array) |
| 15 | `COND_SPOT_STATE` | spotId, state | Spot #12 is BEFRIENDED (chain builder) |
| 16 | `COND_ZONE_COMPLETE` | zoneId | All zone-3 spots befriended |
| 17 | `COND_BATTLE_WIN` | species OR trainerId | Win a friendly bout vs. this spot's Pokémon |
| 18 | `COND_ILLUSION` | species | Zorua currently disguised as Stantler |
| 19 | `COND_TALK_COUNT` | count | Interacted with spot N times (Spiritomb: 108) |
| 20 | `COND_GROVE_RECIPE_DONE` | recipeId | Have ever co-produced a Spicy Berry |

Notes:
- **Battle-as-condition (#17):** triggers a scripted friendly battle; win sets a spot-local flag. No wild battles exist anywhere else.
- **Illusion (#18):** signature mechanic, used sparingly (~5–6 spots total). Zorua gains disguise "faces" as story rewards.
- **Spite/negation:** `NEGATE` on #4 (low-friendship party member for Shuppet), #10 (must NOT be sunny), etc.
- Engine recomputes conditions on: map load, time tick, weather change, inventory/party change events. No polling loops.

---

## 3. The Grove (home base)

A dedicated player-owned map (small town/island). Contents:

- **Berry plots** (start 3, unlock to ~12 via progression variety — story flags, dex counts, lifetime stats; no single currency).
- **Worker assignment** happens diegetically: *talk to a resident* → dialogue offers assignment options. No menus for the resident layer.
- **Resident housing/idle zone:** befriended Pokémon visibly inhabit the Grove (object-slot budget: rotate which ~8 residents render per visit; prioritize assigned workers + most recent befriends).
- **The board/dex shrine:** the dependency-graph dex lives here physically (also accessible from menu).
- **Hint NPC** (and Groupon the Deal-Wingull, shady berry merchant, non-negotiable).

---

## 4. Worker & Pairing System

### Solo roles (by type, with species exceptions)

| Role | Types (default) | Effect |
|------|-----------------|--------|
| `ROLE_TEND` | Grass | +growth speed on assigned plot |
| `ROLE_IRRIGATE` | Water | Enables water-hungry berries; rain-equivalent on plot |
| `ROLE_WARM` | Fire | Enables heat berries; frost protection |
| `ROLE_POLLINATE` | Bug/Flying | Unlocks rare berry mutations on adjacent plots |
| `ROLE_DIG` | Ground/Rock | Unlocks new plot soil; finds buried items |
| `ROLE_SPARK` | Electric | Speeds harvest cycles; powers late-game fixtures |
| `ROLE_CHILL` | Ice | Enables preserved/frost berries |
| `ROLE_WEATHER` | Legendary-only | Zone-scale weather (Kyogre rain / Groudon sun) |
| `ROLE_NONE` | — | Flavor resident; still counts for COND_RESIDENT_* |

### Pairing matrix (co-op tending — the legible rule)

Two workers on one plot combine roles → **flavor berries** (mapping onto Gen 3's five contest flavors keeps it native):

| Pair | Product tier |
|------|--------------|
| Grass + Fire | **Spicy** berries |
| Grass + Water | **Dry** berries |
| Bug + Grass | **Sweet** berries |
| Rock + Grass | **Bitter** berries |
| Ice + Water | **Sour** berries |
| Fire + Water | Steam plot → **Mist** berries (custom tier) |
| Electric + Water | Storm plot → rare mutations |

Flavor berries are the primary Tier 2–3 befriend currency (Vulpix wants Spicy, etc.).

### Species-pair exceptions (the discoverable delights)

A small hand-authored table overrides the matrix: Plusle+Minun → unique berry; Bulbasaur+Charmander specifically → superior Spicy yield; Kyogre+Groudon alternating on the sacred plot → **Enigma tier** (Rayquaza's price). Target ~15–25 exceptions total, all hinted somewhere in-world.

### Berry economy shape

- **Sources:** wild bushes (finite, slow) → Grove plots → paired plots → mutations.
- **Sinks:** befriending (primary), hint NPC, cultivation inputs (rare berries grown *from* cheaper ones), Groupon's dubious deals.
- **Curve:** early = quantity-scarce; mid = kind-scarce (need specific flavors); late = knowledge-scarce only.

---

## 5. Save Budget Sketch

Reclaim the Secret Base save region (**20 × ~160B ≈ 3.2KB**) plus, if needed, contest/Battle Frontier record space we're not using. Draft allocation:

| Data | Size | Notes |
|------|------|-------|
| Spot states | 1 byte × 320 spots = **320 B** | 2 bits state + 2 bits hint stage + 4 bits spot-local flags (battle won, talk-count bucket) |
| Talk counters (rare spots) | 8 × 1 B = **8 B** | Only spots that need >15 counts get a real counter |
| Grove plots | 8 B × 12 = **96 B** | berryId, growthStage, worker1 (residentIdx), worker2, mutation flag |
| Resident registry | 4 B × 96 = **384 B** | species(2) + personalitySeed(1) + assignment/flags(1). Dex flags already cover "befriended?"; registry is for *individuals* (cap 96 named residents; overflow = befriended but non-individualized, still counts for conditions) |
| Illusion faces unlocked | **2 B** | bitfield, 16 faces |
| Story/chapter flags | native flag space | reuse existing flag banks freed by cut content |
| Lifetime stats | native | reuse `gGameStats` array slots |
| **Total new** | **~810 B** | Comfortable inside 3.2KB with 4× headroom for growth |

Open question for Claude Code to validate in Milestone 0: exact freed regions after cutting Secret Bases, Contests, and Battle Frontier state.

---

## 6. Premise (canon, ~75% draft — prose will be refined; causal chain is locked)

**The causal chain (locked):** Alternate timeline. Long ago, Rayquaza rose to meet Deoxys and was defeated — the sky lost its guardian. When Kyogre and Groudon later awakened, nothing remained to stop them. In a final act of love, a lone Zoroark cast an illusion that drove Hoenn's humans to evacuate. They survived; they never returned. The bonds with their Pokémon broke — and the Pokémon carried those bonds to the places their trainers loved best, and waited. The player is a young Zorua, raised by the now-fading Zoroark, sent out to do what illusions cannot.

**Working intro prose (Wind Waker legend register; revise later):**

> Long ago, the people of Hoenn lived beneath a guarded sky.
>
> They rarely saw their guardian. It slept above the clouds and woke only when the sea and the land forgot their places. This had always been enough. So the people built their homes between the water and the mountains, and they did not worry, for the sky had never failed them.
>
> Then one night, a light fell from beyond the stars. The guardian rose to meet it, and did not come down again.
>
> The people told themselves it was sleeping. But when the sea began to rise and the land began to burn, no green light broke through the clouds. The old peace was over, and nothing remained to keep it.
>
> It is said that a lone Zoroark watched the people in those final days — too afraid to leave, too stubborn to be saved. And it is said that this Zoroark, who loved them in its quiet way, wove one last illusion: an ending so complete that every human heart turned toward the horizon at once. They boarded their boats. They did not look back.
>
> They lived.
>
> They never came home.
>
> But no illusion touches a Pokémon's eyes. They watched their trainers go, and waited to be called after them, and the call never came. A bond is not a broken thing. It is a set-down thing. And so each Pokémon carried theirs to the place their trainer loved best, and set it down, and stayed beside it. A Wingull meets the morning ferry. It is always the wrong ferry. It will be there tomorrow.
>
> Seasons turned. The rain and the sun fought on. And in the hollow of an old tree, a fading Zoroark told this story to the only one left who could wear a human face — and asked it to do what illusions cannot.

**Story-design consequences (locked):**
- Rayquaza and Deoxys are never named in the intro ("the guardian," "a light from beyond the stars") — seeds the Tier 4 mystery.
- Endgame reframe: Kyogre + Groudon co-tending the sacred plot is not a summons — it is proof to the sky that peace can hold. The finale **brings the guardian home**. Deoxys is the hidden final Tier 4 beyond it.
- No villain. The antagonist is a position ("maybe bonds aren't worth it"); the game out-argues it with the player's own built evidence.
- No dramatic unmasking. When the Zorua drops its illusion before its oldest residents, they already knew.
- Quiet rule, never stated: after a Pokémon is befriended, the player's Zorua never wears a face around it again.
- Tone guardrails / banned list: "destiny," "chosen," "ancient evil," "the power of friendship" said aloud. Concrete images over mythic language (rusted Pokéballs in tall grass; the overgrown gym nobody mentions).

---

## 7. Vertical Slice (Milestone 1 definition)

- **The Grove, small:** 3 plots, worker assignment via dialogue, one pairing recipe (Grass+Fire → Spicy Berry).
- **One zone** (renovated Hoenn route or clearing) with **5 spots:**
  - Tier 1: place a doll → Skitty (teaches the verb)
  - Tier 2: party Bulbasaur + rain + mature Oran tree → Lotad
  - Tier 2 (battle): win friendly bout → Machop
  - Tier 2 (product): offer Spicy Berry → Vulpix (proves the full Grove circuit)
  - Tier 3: resident Pinsir + sap trees + night → Heracross (proves chaining)
- **Systems exercised once each:** staged hints, state machine, condition engine (≥8 condition types), befriend flow, resident dialogue, worker pairing, berry growth, battle-as-condition.
- **Milestone 0 precedes it:** toolchain builds on Apple Silicon, ROM boots in mGBA headless, one scripted test spot fires, save-region reclamation validated.

## 8. Still Open (fine to resolve mid-flight)

- Premise pick (§6) — needed before zone theming, not before engine work.
- Illusion "faces" acquisition design.
- Exact dex curation list (~250–280; criterion: "does it suggest a riddle?").
- Talk/personality dialogue pool format.
- Post-slice art pipeline experiment (AI → 16-color quantize).
