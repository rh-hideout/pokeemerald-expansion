---
title: Goldenrod City
slug: goldenrodcity-hns
kind: City
act: 1
stage: "3 — Goldenrod"
depth: full
wiki: goldenrodcity-hns
maps: [GoldenrodCity_hns]
also_maps: [PlasticOx_WhitneyGym, GoldenrodCity_Gym_hns, GoldenrodCity_BillsHouse_hns, GoldenrodCity_UndergroundTunnel_hns, GoldenrodCity_FlowerShop_hns, GoldenrodCity_GameCorner_hns]
flags: [FLAG_POX_STORY_MTMOON, FLAG_BADGE02_GET, FLAG_POX_STORY_STARTER, FLAG_POX_GIFT_FAMILY, FLAG_POX_BAD_HAIRCUT_KNOWN, FLAG_POX_HIDE_HAIRCUT_OLDER, FLAG_POX_HIDE_HAIRCUT_YOUNGER]
badges: [2]
trainers: [TRAINER_PLASTIC_OX_WHITNEY]
items: [ITEM_SQUIRT_BOTTLE, ITEM_COIN_CASE]
status: drafted
---

# Goldenrod City

## Snapshot

One long commercial street on a slope, entered from `Route33_hns` in the south and left through the Route 35 gatehouse in the north. The player shops, climbs the Department Store, wins badge 2 in the Gym, and is handed a borrowed bottle to carry north. Nothing here is a dungeon and everything here is on a schedule, which is the emotional note: prices, weekdays, broadcast times, and a station clock kept right for trains that are not running.

## Plot points

1. **Arrival from the south.** The four-tile passage at `(32,45)`–`(35,45)` (`PoxRegion_route33_goldenrod_b`) is always open and drops the player at `Route33_hns` `(1,23)`; the sign at `(32,43)` says how, not why. Goldenrod is the act's only return address, so it must never be sealed for a beat.
2. **Badge 2.** `Pox_Whitney` at `GoldenrodCity_Gym_hns` `(15,8)` requires `FLAG_BADGE01_GET` and `FLAG_POX_STORY_MTMOON`, fights six Lv. 19–20 partners, and sets `FLAG_BADGE02_GET`. Whitney is the early difficulty spike: a trainer with a team and a game plan, not a tutorial with a badge attached.
3. **Bill's family — reveal-ladder step 4.** `Pox_Family` at `(8,4)` opens after `FLAG_POX_STORY_STARTER` and hands a Lv. 5 EEVEE, setting `FLAG_POX_GIFT_FAMILY`. The mother's knees ended her Ecruteak dancing; the father at `(5,4)` receives humming machines instead of letters; the sister at `(8,7)` wants seven of her own. This is the entire Bill motif in the city, and it stays domestic.
4. **The errand north.** After badge 2 `Pox_SquirtBottle` lends `ITEM_SQUIRT_BOTTLE` for the odd tree on Route 36, including a real branch for a full KEY ITEMS pocket. It is a loan from a shop, not a prize: the Flower Shop expects the bottle back and is the only place allowed to hand it over.
5. **The underground is the back corridor.** The Tunnel's own stair at `(12,10)` runs into `GoldenrodCity_UndergroundSwitches_hns`, then Storage, then the Department Store basement; its other two warps surface at the street entrances. The HAIRCUT BROTHERS keep a Gen 2 rota at `(6,20)` (Tue/Thu/Sat, ¥500, friendship to maximum) and `(6,16)` (Sun/Mon/Wed, ¥300, friendship to nothing, `FLAG_POX_BAD_HAIRCUT_KNOWN`), hidden correctly by `FLAG_POX_HIDE_HAIRCUT_OLDER` / `..._YOUNGER`. The COIN CASE is at `(13,13)`.
6. **The Game Corner** runs sixteen slots and four Lv. 15 prizes — ABRA 200, LUVDISC 500, CASTFORM 1,500, PORYGON 4,000 — with one rule: bring a coin case, and the hiker at `(7,6)` says where it is.
7. **North gate.** `(33,7)`/`(34,7)` into `Gate_GoldenrodCity_Route35_hns`, which Route 35's note owns. The long-distance links are the city's real subject: the coast train is suspended and the platform is still polished daily.

**Must not:** stage a Rocket appearance (their three are Mt. Moon, Pokémon Tower, Silph); name Bill beside the network, Silph, or the Weather Institute; let anyone explain badges as a system; hand out the SquirtBottle before `FLAG_BADGE02_GET`; open Route 36 east or Saffron from here; say "convergence"; turn the suspended train into a plot clue.

## Key interactions

| Interaction | Where | Trigger / state | Current behavior | Target behavior |
| --- | --- | --- | --- | --- |
| Gym door | town `(39,13)` | always | warps into the **legacy** `GoldenrodCity_Gym_hns`, whose own `Pox_Whitney` stands at `(15,8)` | keep the door; settle which Gym is real |
| Whitney | `GoldenrodCity_Gym_hns` `(15,8)` | `FLAG_BADGE01_GET` + `FLAG_POX_STORY_MTMOON`; `FLAG_BADGE02_GET` unset | `TRAINER_PLASTIC_OX_WHITNEY`, sets badge 2 | keep; the city's only battle |
| Unreachable twin | `PlasticOx_WhitneyGym` `(5,2)` | same label, same six partners | 0 warps; a second Whitney and an exit NPC at `(4,17)` nobody can reach | delete it, or move the Gym here and repoint the door |
| Gym-floor voices | `GoldenrodCity_Gym_hns` `(10,20)`,`(7,7)`,`(15,18)`,`(26,10)`,`(16,11)` Bridget | always | five distinct lines about Whitney's lineup — the best-written room in the city | keep all five verbatim |
| Bystander | town `(25,13)` `Pox_WhitneyGuide` | always | "WHITNEY always gives them a tough battle!" | keep; she should point at the door the game actually uses |
| SquirtBottle, twice | town `(27,15)` and Flower Shop `(2,4)`, both `Pox_SquirtBottle` | `FLAG_BADGE02_GET` | both dispense `ITEM_SQUIRT_BOTTLE`; both refuse before the badge | one dispenser in the shop; the street woman names it |
| Bill's mother | `(8,4)` `Pox_Family` | `FLAG_POX_STORY_STARTER`; `FLAG_POX_GIFT_FAMILY` unset | EEVEE Lv. 5, then a Sea Cottage follow-up | keep; "on the ferry" is the one line the harbor question decides |
| Hiker | town `(20,30)` `Pox_ParkRoad` | always | "Take ROUTE 35 north to NATIONAL PARK." | give him an errand; a signpost is not a person |
| Street voices | town `(17,36)`,`(39,22)`,`(30,21)`,`(20,25)`,`(7,23)`,`(30,39)`,`(39,15)`,`(44,40)`,`(23,22)`,`(12,35)` | always | ten distinct, already-good lines: no bench on seven floors, the 8 o'clock lullaby, the empty coast track, the downhill harbor, flowers, basement herbs, the Gym crowd, Hoenn bike crates, the results broadcast, the pavement | keep; attach jobs — shoe repair, radio requests, station clock, florist's cart, herb buyer, bike assembler |
| Coin clerk | Game Corner `(3,2)` `MauvilleCity_GameCorner_EventScript_CoinsClerk` | no `ITEM_COIN_CASE` | a Mauville donor script with no counter behind it | rewrite as a Goldenrod attendant who sells coins |
| Prize desks | Game Corner `(16,2)` and `(18,2)`, both `POX_PU_CoinPrizes` | `ITEM_COIN_CASE` | each walks the same four offers, one YES/NO per prize | one desk; the other becomes a floor host |
| Haircut brothers | Tunnel `(6,20)` / `(6,16)` | weekday rota | priced, flagged, and funny; the younger brother warns on a second visit | keep; no third brother, no apology scene |
| Closed chamber | Tunnel `(12,10)` stair, Kimono at `(12,11)` | always | guard says the chamber is closed; the stair is open and holds `ITEM_MAX_REVIVE`, `ITEM_MAX_POTION`, `ITEM_SMOKE_BALL` | gate the stair, or change the line |
| Herb counter | Tunnel `(6,24)` `LavaridgeTown_HerbShop_EventScript_Clerk` | always | "Please come again!" with no goods and a Lavaridge label | build the bitter-herb counter, or retire the object |
| South passage | `(32,45)`–`(35,45)` | always | `PoxRegion_route33_goldenrod_b` → `Route33_hns` `(1,23)` | keep |

## Dialogue guidance

- **Who speaks:** shop-floor staff, commuters, a bike assembler, two barbers, a prize-desk attendant, and Bill's parents. All of them measure something — seven floors, ten minutes, eight o'clock, three hundred yen.
- **Register:** retail deadpan. Short sentences ending in a price, a time, or an address; no exclamation marks outside the Game Corner and the children. Goldenrod is the first place where the player is not the most interesting person on the street.
- **Allowed to know:** the Gym queue, the broadcast schedule, which shops changed hands, that the coast train has not run in a while. **Not allowed:** why the roads changed, who Bill works for, or what is under the department store.
- **Before/after badge 2:** the Gym crowd thins, the results broadcast names the challenger, and one shopkeeper stops calling the player a tourist. Three lines, not a fan club.
- **Bill's family stays light.** The mother is funny about her knees and serious about the Eevee; the father is baffled by the gadget; the sister haggles.

> BIKE ASSEMBLER: Frames come up from HOENN in a crate. I build them, then the north hill decides whether they were worth the money.

> PRIZE ATTENDANT: Four thousand coins for a PORYGON. In eleven years I have never once heard anybody count that high out loud.

> YOUNGER HAIRCUT BROTHER: My hands are steady on Wednesdays. Most Wednesdays.

> BILL'S FATHER: He sends me machines. A postcard would fit in the same box.

> PAVEMENT WALKER: The shops change hands every spring. This pavement has never been sold.

- **Do not:** mention Rocket, Silph, the convergence, or the adaptive system; explain the badge system; let Whitney apologise or monologue; hand another NPC the lullaby or bench line as a joke; make the train station foreshadow anything.

## Inspiration

- **The Japanese department-store stack, basement to roof.** Food hall below, barber two doors down, prize desk at street level, a roof with nothing on it. That vertical order is already built on this map and reframes the Tunnel→Switches→Storage→Basement loop as a service corridor, not a dungeon.
- **A family barbershop rota.** Two chairs, fixed days, a price board, one brother better with scissors and one better with talk. Converts straight into the haircut brothers and gives the cheaper cut its real-world sting.
- **American small-city downtown, 1970s.** A suspended platform, a shoe-repair counter, a local station reading the ball scores. The Train Station's eight NPCs and the "gym results on the evening broadcast" line are stock footage of that downtown.
- **Arcade culture without the mob basement.** Coin buckets, a lucky seat by the wall, a grandmother reading the reels faster than her grandson. The Game Corner is a room, not a plot.
- **Sunday hill-climb cycling towns.** Crates assembled in the shop, brakes tuned before the north hill, a ten-minute descent paid for by an hour of climbing.
- **Late-winter wet pavement.** Imported flowers on a cart, exhaust, cold concrete — the season that lets the flower line about "the town we grew up in" land with no lore at all.

## Implementation hooks

- Wiki page: `goldenrodcity-hns.html`. Maps in `also_maps` above; live interiors no note claims: `GoldenrodCity_TrainStation_hns`, `GoldenrodCity_BikeShop_hns`, `GoldenrodCity_RadioTower_1F_hns`, `GoldenrodCity_UndergroundSwitches_hns`, `GoldenrodCity_UndergroundStorage_hns`.
- Scripts: `data/maps/GoldenrodCity_hns/scripts.inc`, `data/maps/GoldenrodCity_Gym_hns/scripts.inc`; `data/scripts/plastic_ox_story.inc` (`Pox_Whitney`, `Pox_WhitneyGuide`, `Pox_ParkRoad`, `Pox_SquirtBottle`, `Pox_Family`); `data/scripts/plastic_ox_goldenrod.inc` (`PoxGoldenrod_OlderHaircut`, `PoxGoldenrod_YoungerHaircut`, `PoxGoldenrod_Bike`, `PoxGoldenrod_Slots`, `PoxGoldenrod_Directory`); `data/scripts/plastic_ox_pu_acquisitions.inc` (`POX_PU_CoinPrizes`); `data/scripts/plastic_ox_region.inc` (`PoxRegion_route33_goldenrod_b`).
- Gates: badge 2 needs `FLAG_BADGE01_GET` and `FLAG_POX_STORY_MTMOON`; the family EEVEE needs `FLAG_POX_STORY_STARTER`; the SquirtBottle needs `FLAG_BADGE02_GET`.
- Known gaps: two Gyms, and the badge is won in the legacy HNS room; two `Pox_SquirtBottle` objects with identical text; two identical prize desks; the coin clerk is a Mauville script; the Kimono guard calls the switch chamber closed while `(12,10)` is open and stocked with a Max Revive before badge 2; the Lavaridge herb clerk sells nothing; `PoxGoldenrod_Directory` is pasted on shelf signs inside the Bike Shop, the switch chamber, the Department Store and two corners of the Game Corner; `PoxGoldenrod_Bike` gives `ITEM_MACH_BIKE` with no flag and no price, so repeat visits say "Your bicycle is ready"; the south portal's `_Closed` branch is dead code.

## Open questions

- Keep `GoldenrodCity_Gym_hns` as Gym 2 and delete `PlasticOx_WhitneyGym`, or move `Pox_Whitney` into the empty new room and repoint `(39,13)`? Today the badge lives in the legacy room.
- RESOLVED (pox-2ma.7): the switch chamber stays open; the story bible has no Steel Tablet/kimono gate, so the dead flags were retired. Revisit only if the bible adds a Registeel beat.
- Where does the bitter-herb counter belong: the Tunnel, where the Lavaridge clerk stands, or the Department Store basement, where the street voice at `(30,39)` sends people?
- Does the coast train ever run again? That answer decides whether Bill's mother says "ferry" and whether the station gets a second state.
- Claim the Train Station, Bike Shop and Radio Tower here, or leave them for a separate service-buildings note?
