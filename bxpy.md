---
title: BXPY Asset List

---

# Original UI
![](https://i.imgur.com/1LV8Y3Z.png)
![](https://i.imgur.com/Nx8lYPP.png)


# Anatomy
![](https://i.imgur.com/KCbWna2.png)

1. Mon Nickname
2. Held Item Sprite
3. Held Item Name
4. Mon Row
5. Mon Level
6. Mon Gender
7. Mon HP
8. Species Display
9. Number of selected Pokemon
10. Number of required Pokemon
11. Cursor
12. Pokemon Menu
13. Pokemon Menu Item
14. Selected Pokemon Menu Item
15. Done Button
16. Enemy Name
17. Enemy Species Display
18. Enemy Mon Level
19. Enemy Mon Gender
20. Enemy Mon Held Item Icon

# Graphic assets notes

## bxpy_master.aseprite

### Palettes

- Palette 0: background graphics
- Palette 1: text palettes
```
    {0, 1, 3} // player mon names, items, levels
    {0, 2, 4} // player mon name when hover
    {0, 1, 5} // help bar texts (num selected, done, partners)
    {0, 1, 6} // opponent name
    {0, 2, 7} // opponent mon levels
```
- Palette 2: all BXPY sprites
- Palettes 3-8: shared by mon icon sprites (same as pokemon_storage_system or party_menu, etc.)

### 3 main sections/groups

- SPRITES - all share palette 2 of the aseprite
    - Cursor: 16x16
    - Selection tags: 16x96 for 6 tags numbered 1-6; 2 variants
    - Gender icons: not strictly necessary, can use text, just need to pick some color for pal 1 (above)
    - HP bar: 72x24 (3 rows), similar set up as hpbar.png and hpbar_anim.png in battle_interface
    - Start button (32x8) and select button (16x8) for help bar prompts
    - Party slot hover fill (16 x 64) with 2 pieces, tiles 0-7 are the left end (hflip for right end), 8-15 are the middle pieces (repeated 6 times)

- Graphics by layers: all mock-up graphics ordered by suggested layers/priority. Briefly:
    - Layer 0 - for menu and message windows, no sprite
    - Layer 1
        - sprites: majority of sprites (mon icons, cursor, selection tags, hp bar, gender icons, opponent name)
        - bg: texts for mon names, item names, levels; texts for help bar prompts (x / y, done, partners)
    - Layer 2
        - sprites: highlight fill when cursor hovers over a mon; start and select button
        - bg: player party slots, opp party slots, help bar --> select together and export for TilemapStudio, etc.
    - Layer 3
        - sprites: none
        - bg: background -> can be combined with layer 2 and leave layer 3 unused, or do stuff like scrolling bg, etc.

- Graphics by layout - the exact same as above, just how i built the mockup by purpose, etc. mostly for reference, of no importance here

### Text windows
- Player party info (mon names, item names, levels)
    - tilemapleft: 2, tilemaptop: 0, width: 11, height: 18
    - will cutoff the shadow of characters like 'g' and 'y' for the 6th slot item name to avoid overlapping bottom help bar text window
- Opponent name
    - tilemapleft: 23, tilemaptop: 0, width: 6, height: 2
- Opponent mon levels
    - tilemapleft: 23, tilemaptop: 2, width: 4, height: 16
- Bottom help bar
    - tilemapleft: 2, tilemaptop: 18, width: 26, height: 2

# Montblanc Mockup #2.5
![](https://imgur.com/6xsuoqa.png)

## Notes

- Added opponent name
- Added button prompts for Done and Partner mode
    - 'Done' should appear when selected required number of mons
    - 'Partners' should only show in multi-battles

# Montblanc Mockup #2
![](https://i.imgur.com/weulux5.png)

## Notes
- Got 14 pixels for bottom help bar by moving/squeezing both player and opp panels and mon sprite positions
- Added # selected over # required in help bar
- Removed item icon sprites (can add back for opp side if needed)
- Increased player side slots width by 1 tile to make room for mon level
- Moved gender icon to 2nd row of player side
- Examples of squeezed item names to make sure there's room for gender icon
- Mock-up of health bar (probably overkill to add text)

# Montblanc Mockup #1
![](https://i.imgur.com/g1iTf0I.png)



## Montblanc Notes

- `#2 Held Item Sprite` and `#20 Enemy Mon Held Item Icon`
    - Player side: likely too small, icon sprites were shrunk down to 25% in mock-up, some items almost unrecognizable
    - Opp side: do we need to show? SV/Champions UI doesn't show either
    - Might need some HBlank dark magic (ask Archie) since we only need to load these sprites once and do not need to persist their palettes

- `#5 Mon Level`, `#6 Mon Gender`, `#19 Enemy Mon Gender`, and `#18 Enemy Mon Level`:
    - Player side: there's not a lot of space to display level, since held item name can take up the entire bottom row of text. We could push mon sprites to the right by 8 pixels and make room, but still have to pick either level or gender, but hard to do both, unless we skip held item icon and move gender icon to 2nd row
    - Separately, in modes similar to VGC/Champions format, we could skip level info since they are auto level 50

- `#7 Mon HP`
    - This there's really no room left for this one

- General comments about mon info:
    - If we really want these info available (like VGC open team sheet), then it's probably better to do something like the pokemon info panel I have in my SwSh storage system, that user has can toggle open and close
    - (In Champions, they are also include enemy mon types info, so that could work?)
    - ![](https://i.imgur.com/kMsfTQg.png)

- `#9 Number of selected Pokemon`, `#10 Number of required Pokemon`, and `#15 Done Button`
    - There's not much space left for these, and they could be redundant in light of the `1st`, `2nd`, etc. tags
    - `#15` could be a window prompt/menu that pops up when the player has picked the required number

- `#11 Cursor`, `#12 Pokemon Menu`, `#13 Pokemon Menu Item` and `#14 Selected Pokemon Menu Item`
    - A custom menu window to match the coloring is nice but custom window is a bit annoying (for me), especially dynamically updating bg color (to yellow) when the cursor move up and down
    - The less painful way is just use the default window styles, so at least those menu windows will match players' UI in the rest of the game
    - For that reason, I'd suggest `#11` be used for hovering between mons and not be part of the menu

# Open Questions
## Player Side
- [x] How is the player's party displayed when the player has 6 Pokemon?
- [x] How is the player's party displayed when the player has less than 6 Pokemon?
    - I think we should just show all 6 slots with empties
- [ ] How are the player's partners Pokemon displayed when they have 3 Pokemon? 2? 1?
    - The best option is to switch views between player+opp1 and partner+opp2 (opp partner), similar to 12v12 battle in expansion showing partner team before battle start (here the player can switch back and forth)
    - So we would have emty slots if partners (both sides) bring fewer than 6 mons
- [ ] How are the player's partners Pokemon displayed when they have more than 3 Pokemon?
- [ ] How is the held item sprite displayed?
    - In the mock-up I shrank to 25% and it's not great but there's not a lot of space. We could increase some to see. Main concern (esp. if we load all 12 items for party and enemy is clearing sprite palettes)
- [x] How is the held item name displayed?
    - Print below nickname, with `GetFontIdToFit`
- [x] How is the Tera Type displayed?
    - No room for player side, I'd recommend something like a mon info panel
- [ ] How is level displayed?
- [x] How is HP displayed?
    - No room, I'd recommend mon info, just need to make sure we hide that info on enemy side
- [x] How is gender displayed?
    - Sprites is easier than text
- [x] How is the Pokemon's species displayed?
    - Mon icon is easier than front sprite
- [x] Where is the selected indicator placed when a Pokemon is chosen?
    - See mock-up
- [ ] How does a Pokemon change when selected by the cursor?
    - We could have it animate in place like in party menu
    - in party, all mons animate in place but the one selected have Y-position shifts. here due to the crowding of mon sprites we can have idle mons static and only the one selected animate in place.
- [ ] What does the Pokemon menu look like?
- [ ] How do the items in the Pokemon menu change when seleccted by the cursor?
- [x] How is the total number of selected Pokemon shown?
- [x] How is the total number of Pokemon to be selected shown?
- [x] How is the "Done" button displyed?

## Enemy Side
- [ ] How is the enemy's party displayed when the enemy has 6 Pokemon?
- [x] How is the enemy's party displayed when the enemy has less than 6 Pokemon?
    - Similarly, just show all 6 slots with empties
- [ ] How are the enemy's partners Pokemon displayed when they have 3 Pokemon? 2? 1?
    - Similar to first opponent's team above.
- [ ] How are the enemy's partners Pokemon displayed when they have more than 3 Pokemon?
- [ ] How is the enemy's name displayed?
- [ ] How is the enemy's name displayed when they have a partner?
    - Show name with partner's team when switch to partner view
- [ ] How is the held item sprite displayed?
    - Top of the opp mon list
- [ ] How is the held item name displayed?
    - Text printed below mon name, with find font to fit width
- [ ] How is the Tera Type displayed?
    - This could replace gender icon, otherwise it's too crowded. Note that typical type icon sets take up 3 palette slots
- [x] How is level displayed?
- [ ] How is HP displayed?
    - In vanilla health bars (see battle_interface or Rave bw_summary_screen), they have 8 sprites to mark from 0 -> 8 filled pixel, and some calc to pick the approximate sprites. need to generate yellow/red color versions as well
- [ ] How is gender displayed?
    - Sprite or text, either works
- [ ] How is the Pokemon's species displayed?
- [ ] How does a Pokemon change when selected by the cursor?
    - Similar to player as suggested above, all mons idle static, and animate in place when selected.

# Required Assets
- [ ] Pokemon cursor
- [ ] Pokemon menu cursor
- [ ] 0% HP Sprite
    - Are there contexts where players open this UI without full health? If so, this is a BG fill with some calc (see BW summary screen or vanilla party menu), not sprites
- [ ] 10% HP Sprite
- [ ] 20% HP Sprite
- [ ] 30% HP Sprite
- [ ] 40% HP Sprite
- [ ] 50% HP Sprite
- [ ] 60% HP Sprite
- [ ] 70% HP Sprite
- [ ] 80% HP Sprite
- [ ] 90% HP Sprite
- [ ] 100% HP Sprite
- [ ] Selected Mon Indicator
    - Will provide up to 6 sprites with `1st`, `2nd`, etc.
- [ ] Male Sprite
- [ ] Female Sprite
- [ ] Genderless Sprite
    - ???
- [ ] Background image
- [ ] Player Pokemon display
- [ ] Enemy Pokemon display 

## Notes
- 14 px will be reserved at the bottom to show the menu controls in the help bar.
    - This is really hard to accommodate as seen in the mock-up
- This UI needs to display **AT LEAST** as much information as Scarlet and Violet, but displaying _more_ is ideal.
    - Mon info panel is my personal recommendation
- The player will be able to move the cursor to the enemy side to see the Summary of their Pokemon. Pressing A will automatically open the Sumnmary.
    - See above
- The timer or "Standing by" is not needed.
- The feature README can be seen here: https://github.com/PokemonSanFran/pokeemerald-expansion/blob/bringXpickY/docs/tutorials/bring_x_pick_y.md
- A video of the feature in ScVi being used can be seen here: https://youtu.be/VPbTzlJ8ZeE?t=79