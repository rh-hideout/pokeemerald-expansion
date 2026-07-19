# Hoenn Habitat — Pre-Handoff Design Spec (v0.1)

Codename: **Hoenn Habitat**. Base: `pokeemerald-expansion` (pin latest stable release tag). Target: Mac local build, mGBA headless verification. This document is the content-schema contract between design (Jay + Claude chat) and engineering (Claude Code). Everything here is draft — react freely.

---

## 1. Core Loop (canonical statement)

> Explore freely → inspect a habitat spot → decode its staged hints → satisfy **appear conditions** → the Pokémon manifests and persists → satisfy **befriend conditions** (usually: offer the right berry/item) → it becomes a **resident** → assign it to Grove work, solo or paired → co-produce rarer berries/items → spend those on harder spots → repeat until the region's mystery is solved.

**Design law:** *Every location is approachable; every condition is inspectable; solvability is what's gated.*

**Design law 2 — Wants, not riddles:** The default spot is a plainly stated, characterful **want** (Trubbish wants an armful of trash; Skitty wants something soft; Numel wants warmth). The player's satisfaction comes from *providing*, not decoding. Actual riddles — obscured, multi-system, figure-it-out conditions — are a scarce spice reserved for rare Pokémon, legendaries, and story-critical spots (roughly: most of Tier 1–2 states its wants outright; Tier 3 chains stated wants; only Tier 4 and a handful of marked Tier 3s are true riddles). Hint staging still applies everywhere, but for common spots the "hint" is simply the want, said charmingly. Not every Pokémon is tied to the story — but every Pokémon can be *used by* the story.

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
| 20 | `COND_GROVE_RECIPE_DONE` | recipeId | Have ever grown a Spelon Berry (pair recipe) |

Notes:
- **Battle-as-condition (#17):** triggers a scripted friendly battle; win sets a spot-local flag. No wild battles exist anywhere else.
- **Illusion (#18):** signature mechanic, used sparingly (~5–6 spots total). Zorua gains disguise "faces" as story rewards.
- **Spite/negation:** `NEGATE` on #4 (low-friendship party member for Shuppet), #10 (must NOT be sunny), etc.
- Engine recomputes conditions on: map load, time tick, weather change, inventory/party change events. No polling loops.

---

## 3. The Grove (home base) — REVISED: the Grove is the "PC"

A dedicated player-owned map (small town/island). **Framing law: no Pokémon is ever in a box.** The Grove's resident list is a *directory*, not storage — every befriended Pokémon actually lives somewhere real (see Residency below). This is the premise as UI, never stated aloud.

- **Six out per section [CANON]:** each Grove section lets the player choose up to **6 residents "out"** — out means present, visible, and working (plots, fixtures). Six echoes party size without a party system existing. Scaling is structural: each new Grove section is its own map with its own object budget.
- **Berry plots** (start 3, unlock to ~12 via progression variety — story flags, dex counts, lifetime stats; no single currency).
- **Worker assignment is diegetic:** *talk to a resident* → dialogue offers assignment/come-to-the-Grove options. No menus for the resident layer.
- **The board/dex shrine:** the dependency-graph dex lives here physically (also accessible from menu).
- **Hint NPC** (and Groupon the Deal-Wingull, shady berry merchant, non-negotiable).

### Residency & world rendering [CANON]

- **Home-by-default:** a befriended Pokémon visibly inhabits its habitat spot whenever it is not out at the Grove. Render rule: a spot draws its species sprite iff the spot is ACTIVE, **or** BEFRIENDED and its resident is not currently out. (Same flag-gated sprite machinery as ACTIVE spots — one more state.)
- The Zubat you befriended hangs in its cave when you pass through; after its ritual, your **Crobat** hangs in the same cave. Evolution renders at home.
- The world is its own progress meter: the region visibly fills with life exactly where the player restored it. "Healed but still hidden" becomes something you can *walk through*.
- The former "stays-in-world" per-spot exception (porch Mightyena) dissolves — staying home is now the rule, not the flag.
- **Map budget law [engine + zone-authoring]:** worst case is every spot on a map befriended with no one out, so per map: **NPCs + habitat spots ≤ ~13** (16 object-event cap minus player + scripted reserves). Spot density per map is a designed number, checked at authoring time.

---

## 4. Berries & Workers — REVISED (supersedes the flavor-pair matrix entirely)

### Berry ↔ type table [CANON — Pokémon Sleep mapping]

| Type | Berry | Type | Berry |
|---|---|---|---|
| Normal | Persim | Flying | Pamtre |
| Fire | Leppa | Psychic | Mago |
| Water | Oran | Bug | Lum |
| Grass | Durin | Rock | Sitrus |
| Electric | Grepa | Ghost | Bluk |
| Ice | Rawst | Dragon | Yache |
| Fighting | Cheri | Dark | Wiki |
| Poison | Chesto | Steel | Belue |
| Ground | Figy | Fairy | Pecha |

All exist in Gen 3 except Yache (expansion provides it). *Engineering note: verify the full table against a Pokémon Sleep reference before minting item/plot data.*

### The two rules the economy runs on [CANON]

1. **Workers grow their type's berry.** Assign a resident to a plot → the plot yields that type's berry. No type algebra, no invented flavors.
2. **A Pokémon's default befriend want is its own type's berry** (Sleep-faithful: Pokémon favor their type's berry). Vulpix wants a Leppa. Characterful exceptions override the default and pop *because* it exists (Trubbish wants trash; Aron wants rusted Pokéballs).

Bootstrap: wild berry bushes (finite, slow) and the lab starter habitats provide the first-of-type before any worker exists.

### Leftover Gen 3 berries (~25) [CANON — ratified 2026-07-19]

Per design law: leftovers are rare/legendary-tier or require a specific Pokémon.
- **Enigma** → Rayquaza's price via the Kyogre+Groudon sacred plot.
- **Starf** (the star fruit) → **Jirachi**. **Lansat** + the stat five (**Liechi, Ganlon, Salac, Petaya, Apicot**) → legendary/Tier 4 prices (individual assignments authored with Tier 4 content).
- **The Pokéblock six (Spelon, Watmel, Cornn, Magost, Rabuta, Nomel)** → species-pair co-tend exclusives (see below).
- **Remainder (Razz, Nanab, Wepear, Pinap, Aspear, Aguav, Iapapa, Pomeg, Kelpsy, Qualot, Hondew, Tamato)** → specific-Pokémon sources: grown/produced only by particular residents (Tropius fruits one on its neck; Shuckle ferments one into existence) or minor stated wants. Individual assignments authored content-side.

### Pair recipes [CANON as structure; individual assignments PROPOSAL]

A small **hand-authored table** — a specific pair co-tending one plot grows a specific leftover berry. Discoverable recipes, not derivable formula. Examples: Treecko+Torchic → Spelon; Plusle+Minun → a unique yield; Kyogre+Groudon alternating on the sacred plot → Enigma [CANON]. Target ~15–25 recipes, all hinted somewhere in-world.

### Worker role effects [PROPOSAL — secondary layer, awaiting ratification]

Beyond berry output, roles add utility: Tend (+growth), Irrigate, Warm, Pollinate (mutations), Dig (new soil/finds), Spark (fixtures), Chill (preservation), Weather (legendary, zone-scale), plus curation-pass proposals (Forage, Recycle, Compost, Ferment, Deliver, Care, Art) and per-stage upgrade tiers per §9. ROLE_NONE residents still count for all COND_RESIDENT_* checks.

### Berry economy shape

- **Sources:** wild bushes → Grove plots (type berries) → pair plots (rare berries) → specific-Pokémon sources.
- **Sinks:** befriending (primary), hint NPC, cultivation inputs, Groupon's dubious deals.
- **Curve:** early = quantity-scarce; mid = kind-scarce (the *right* type/rare berry); late = knowledge-scarce only.

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

**RESOLVED (M0, 2026-07-18):** Habitat save data lives in **SaveBlock3** (the expansion's sanctioned 1,624 B extension region; measured 720 B in use after M1 phases 1–3). The Secret Base slab (measured at exactly 3,200 B + 176 B decorations in SaveBlock1) stays banked as the scale-out reservoir for the full 320-spot game; total reclaimable ceiling ≈ 10.8 KB if ever needed. §9's +96 B work counters fit within SaveBlock3 headroom.

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
- No villain. The antagonist is a position ("maybe bonds aren't worth it"); the game out-argues it with the player's own built evidence.
- No dramatic unmasking. When the Zorua drops its illusion before its oldest residents, they already knew.
- Quiet rule, never stated: after a Pokémon is befriended, the player's Zorua never wears a face around it again.
- Tone guardrails / banned list: "destiny," "chosen," "ancient evil," "the power of friendship" said aloud. Concrete images over mythic language (rusted Pokéballs in tall grass; the overgrown gym nobody mentions).

### Two-act structure (locked)

**Act structure follows the "true ending" pattern: main story for everyone, epilogue for the devoted.**

**MAIN STORY** — open progression; gated only on *story-critical* befriends (weather trio, the elder's thread, key residents such as the ferry Wingull), never on dex percentage.
- Spine: restore habitats → befriend Kyogre & Groudon → they co-tend the sacred plot (proof that peace can hold) → **Rayquaza descends: the guardian comes home** → the guardian's return surfaces the truth of the light that fell → **climax: Deoxys**.
- **The Deoxys encounter is the game's only mandatory battle** — the fight that broke the sky, faced again, ending this time in befriending. Battle-as-condition deployed exactly once, at maximum weight.
- The main story ends with Hoenn **healed but still hidden**: the sky is whole, the veil is still up, the world doesn't know. Credits roll on that deliberate ache — the pull toward the epilogue is longing, not obligation.

**EPILOGUE (true ending)** — gated on **100% of habitat spots befriended** (spots, not evolution stages; full evolution completion feeds a separate post-game reward).
- The elder's last lesson → **Zorua's evolution ceremony**, witnessed by every resident — the player, subject to the same law as every creature in Hoenn (evolution only through earned bonds and shared work), finally at the center of the circle it spent the game conducting.
- The veil lifts → the ferry comes → the trainers return. The Wingull meets the right ferry at last.
- "No one left behind" is the epilogue's bar *because it is the epilogue's subject.*
- OPEN WRITING QUESTION (most important remaining): ten years passed — not every trainer returns. Which reunions happen and which don't (the porch Mightyena foremost) decides what the ending says. The thesis to honor: mending is possible, and the bonds built in the meantime are real ones.

**Design obligations created by the 100% epilogue gate (engine-level law):**
1. **Nothing is ever missable.** No condition may become permanently unsatisfiable in any game state. Choice-locks are temporary redirections only; feud pairs (Zangoose/Seviper) must both remain reachable.
2. **The gate counts spots, not stages.** Branch evolutions never block completion.
3. **No spot may hard-stall.** The hint NPC provides escalating hints for every spot without exception (priced in berries) — stuck-proof by design, cryptic by choice.
4. **The dex dependency graph carries the endgame:** the final stretch should read as a homecoming tour, not an audit.

---

## 7. Vertical Slice (Milestone 1 definition — RE-AMENDED: lab opening + berry system recast)

- **The lab opening ships in the slice** (see §10): three habitat frames in the professor's lab; the furnished one's final-slot choice (campfire / potted plant / water basin) grants Torchic, Treecko, or Mudkip. Dev verification config pins **Torchic**; players choose freely. The other two furnishings (a PC, a bookshelf, a Pokéball holder — [CANON, ratified 2026-07-19]) are placed as finds on Route 103 to prove the scavenge loop in-slice.
- **The Grove, small:** 3 plots, worker assignment via dialogue. Core circuit: **Torchic assigned to a plot grows Leppa** (type-berry rule, §4). Stretch goal: one pair recipe (Treecko+Torchic → Spelon [PROPOSAL]).
- **Route 103, 6 spots** (Bulbasaur/Charmander spots removed — superseded by lab starters; the Kanto trio returns to the general dex):
  - Tier 1: place a doll → Skitty (teaches the verb)
  - Tier 1–2 (stated want): Pinsir — a sap-slathered log [placeholder want]
  - Tier 2: **resident** Treecko + rain + mature **Cheri** tree → Lotad *(RESIDENT_SPECIES, not PARTY_SPECIES — party/companion deliberately deferred; engine keeps PARTY_SPECIES for the future. Conditions bend to the world's real Cheri trees, never vice versa)*
  - Tier 2 (battle): win friendly bout → Machop
  - Tier 2 (product): **offer a Leppa Berry → Vulpix** (type-want default, §4; proves the full solve → befriend → assign → grow → spend circuit)
  - Tier 3: resident Pinsir + sap trees + night → Heracross (proves chaining)
- **Systems exercised once each:** lab slot choice, staged hints, state machine, condition engine (≥8 condition types), befriend flow, resident dialogue, home-by-default rendering (§3), worker berry output, battle-as-condition, scavenge-and-place.
- **Verb UX feel target (phase 4+):** diegetic and quiet — contextual verbs (Place/Offer appear only when applicable), offering plays as a 2–3 textbox beat (the Pokémon considers, then accepts), soft SE, no fanfare. Text register: species voice + italic narrator interpretation.
- **Status:** Milestone 0 complete (2026-07-18). M1 phases 1–3 (condition engine, spot framework, resident registry) built, tested, merged; approved amendments: monotonic spot transitions; placing manifests dormant spots (always-present inspect sign); dev spawn kit behind `HABITAT_SLICE_SPAWN`; resident conditions read dex with registry holding individuals. *This recast lands before phase 4 (the Grove), so no built phase is invalidated: the original spots need a data-only recast (Lotad's condition species, Vulpix's offer item) plus removal of the two superseded spots.*
- **Authoring rule (engine lesson):** text routed through `gStringVar4` must be pre-expanded — placeholder-bearing self-expansion corrupts memory. Content-side hint prose must respect this.

## 8. Still Open (fine to resolve mid-flight)

- Premise prose polish (§6 — causal chain locked, ~75% on prose).
- Pair recipe table authoring (~15–25 recipes).
- Worker role effects ratification (§4 secondary layer).
- Illusion "faces" acquisition design.
- Dex curation finalization (first pass lives in `hoenn-habitat-dex-curation.xlsx`; criterion: "does it suggest a characterful *want*?" — riddles are reserved per Design law 2).
- Talk/personality dialogue pool format.
- Rebuilt-human-places habitat category (§10 [PROPOSAL]) — scope decision post-slice.
- Post-slice art pipeline experiment (AI → 16-color quantize).

---

## 9. Evolution Rituals

**Core rule:** No Pokémon evolves in the wild or automatically. Evolution happens only when the player brings a resident (or party member) to a **ritual site** while that Pokémon's **evolution conditions** are met. Evolution conditions reuse the exact `Condition` schema and engine from §2 — no new evaluation tech.

### Ritual sites

Small dedicated locations scattered across the region (elemental shrines, the stone circle, the moss hollow, the magnetic ruins, the tidal pool, etc.). Per Design law, every site is approachable from day one; what's gated is whether a given Pokémon's conditions are met. Site data:

```c
struct RitualSite {
    u16 siteId;
    u16 mapId; u8 x, y;
    u16 element;        // flavor/eligibility filter (which evolutions can fire here)
};
```

### Evolution definitions (per line stage)

```c
struct EvolutionRitual {
    u16 fromSpecies;
    u16 toSpecies;           // branch lines have multiple entries with distinct conditions
    u16 siteElement;         // which site type accepts it
    const struct Condition *conditions;  // same enum as spots
    const u8 *ceremonyScript;            // scene id
};
```

### Canon method translation

- **Level evos** → work-based: per-resident labor counter (`COND_LIFETIME_STAT` scoped to resident) — bonds deepen through shared work.
- **Friendship evos** (Crobat, Blissey…) → flagship work-based rituals; the theme made mechanical.
- **Trade evos** (Machamp, Gengar, Golem…) → ritual offerings (found relic items).
- **Stone evos** → the elemental shrine sites themselves.
- **Condition evos** (Milotic, Alcremie, Magnezone, Cherrim…) → nearly canon-faithful; showcase pieces.
- **Branch evos** (Vileplume/Bellossom, Glalie/Froslass, Gardevoir/Gallade, cocoon lines…) → same site, different condition lists; the player's build choice.

### Worker upgrade tiers

Evolution is the economy's vertical axis: each stage upgrades or *changes* the worker role (Oddish tends its plot → Gloom adds mutation chance → Vileplume tends adjacent plots / Bellossom boosts mutation odds instead). Branch evolutions are therefore **builds**. Role tiers ship in the worker table (§4) as per-stage entries.

### Anti-regret rule (locked)

Conditions and recipes that name a species match **the evolutionary line at that stage or above** by default (`COND_RESIDENT_SPECIES` resolves Oddish→Gloom→Vileplume as satisfying "Oddish"). Stage-*exact* requirements are rare, deliberate, and always telegraphed in hint text **before** the evolution choice could be made — evolution must feel like growth, never like closing a door. (Engine note: species conditions carry an `EXACT_STAGE` flag, default off.)

### Ceremony framing (locked)

- Evolution is always **player-initiated at the site** — the Pokémon waits to be brought; consent is baked into the mechanic.
- Each ritual plays as a short authored **scene** (~30 seconds: approach, beat, transformation, one line of resident dialogue after), never a menu confirmation. Marquee ceremonies (Bagon's first flight, Milotic, Shedinja's "birth") get bespoke staging.
- Post-befriend illusion rule applies during ceremonies: the player's Zorua attends every ritual in its true form.

### Save impact

+1 byte per resident registry entry (work counter, 0–255 bucketed) → +96 B against the §5 headroom. Fits.

---

## 10. The Opening: The Professor's Lab [CANON]

The tutorial is the thesis in miniature: you cannot bring the people back, but you can rebuild what they left — and someone will come home to it.

- **Three habitat frames** stand in the professor's old lab, visible from minute one. One is furnished (a PC, a Pokéball holder, a bookshelf — Birch's canonical lab furniture; the belongings of someone who left) [CANON, ratified 2026-07-19] with **one final slot open**. The other two are bare skeletons, teaching by silhouette: the player can see the shape of what's missing before understanding the system.
- The player is given a **campfire, a potted plant, and a water basin**. Placing one in the open slot completes the habitat — and **Torchic, Treecko, or Mudkip comes home to it.** The choice is a verb (start a fire / plant a tree / fill a basin): providing, before a single menu exists.
- **Completed habitats are never editable.** The diegetic law, generalized to every habitat in the game: *someone lives there now.* Not a lock — respect.
- **The other two starters:** scavenge the missing furnishings (a PC, a bookshelf, a Pokéball holder) from the abandoned region, bring them back, complete the remaining frames. Nothing-missable honored; the choice shapes the early economy's tilt (Fire/Grass/Water first) but loses nothing.
- **The pocket dimension [CANON]:** the Zorua carries any placeable or furnishing, full stop. One line of flavor text ("...it goes somewhere"), zero inventory-size systems. The correct amount of whimsy.

### Rebuilt human places [PROPOSAL — direction memo, not law]

The lab establishes a second habitat species alongside nature spots: **restored human rooms.** The Pokémon who loved humans most don't want berries — they want the rooms back. Candidates if/when we open this door: the porch Mightyena as a furnishing habitat (repair the steps, place the chair, set the bowl); Machop's gym corner; Sinistea's tea room with a real antique cup; Rotom's placed appliances (already specced); the lab's choice-slot pattern reused anywhere (one open slot decides *who* comes, other option seeds a habitat elsewhere per nothing-missable). Implies a scavenging loop parallel to berries and promotes Klefki (keeper of the abandoned houses' keys) off the bench. Engine cost is modest — a furniture item class + slot UX — but this is a **post-slice scope decision**, not a change order.
