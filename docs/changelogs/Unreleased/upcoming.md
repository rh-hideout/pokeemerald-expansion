# Unreleased changes (master branch)

```md
## How to update
- If you haven't set up a remote, run the command `git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion`.
- Once you have your remote set up, run the command `git pull RHH upcoming`.
```

## 🎲 UNSORTED CHANGES 🎲:
* FRLG+ whiteout message by @cawtds in [#4967](https://github.com/rh-hideout/pokeemerald-expansion/pull/4967)
* Remove metadata in AIF files by @SombrAbsol in [#4958](https://github.com/rh-hideout/pokeemerald-expansion/pull/4958)
* 03.08.2024 Master merge by @AlexOn1ine in [#5083](https://github.com/rh-hideout/pokeemerald-expansion/pull/5083)
* Remove gPaletteDecompressionBuffer and unused palette functions/vars by @DizzyEggg in [#4841](https://github.com/rh-hideout/pokeemerald-expansion/pull/4841)
* Changes Evolution methods to Enums by @AlexOn1ine in [#4977](https://github.com/rh-hideout/pokeemerald-expansion/pull/4977)
* Doesn't compile on some compilers by @AlexOn1ine in [#5099](https://github.com/rh-hideout/pokeemerald-expansion/pull/5099)
* Change GET_MOVE_TYPE to a function by @AlexOn1ine in [#5090](https://github.com/rh-hideout/pokeemerald-expansion/pull/5090)
* Update event.inc to accomodate new gDecompressionBuffer name by @Bassoonian in [#5100](https://github.com/rh-hideout/pokeemerald-expansion/pull/5100)
* Dynamic Move Types in Summary Screen/Battle by @Galaxeeh in [#5084](https://github.com/rh-hideout/pokeemerald-expansion/pull/5084)
* Created COMPOUND_STRINGs for default player names by @fdeblasio in [#5037](https://github.com/rh-hideout/pokeemerald-expansion/pull/5037)
* Changed single-use berry blender strings to be COMPOUND_STRINGs by @fdeblasio in [#4963](https://github.com/rh-hideout/pokeemerald-expansion/pull/4963)
* Made perfect IV count into a granular setting by @AsparagusEduardo in [#5115](https://github.com/rh-hideout/pokeemerald-expansion/pull/5115)
* Add some null pointer checks by @tertu-m in [#5130](https://github.com/rh-hideout/pokeemerald-expansion/pull/5130)
* Dynamic move type clean up by @AlexOn1ine in [#5132](https://github.com/rh-hideout/pokeemerald-expansion/pull/5132)
* Add B_SHOW_TYPES and cleaned up IsDoubleBattle by @pkmnsnfrn in [#5131](https://github.com/rh-hideout/pokeemerald-expansion/pull/5131)
* Remove agbcc by @mrgriffin in [#4994](https://github.com/rh-hideout/pokeemerald-expansion/pull/4994)
* Refactor Frontier Brains by @fdeblasio in [#5027](https://github.com/rh-hideout/pokeemerald-expansion/pull/5027)
* Fix a sprite issue with B_SHOW_TYPES by @pkmnsnfrn in [#5157](https://github.com/rh-hideout/pokeemerald-expansion/pull/5157)
* Removed some hardcoding of move IDs + Gen4/5 Defog by @AsparagusEduardo in [#5156](https://github.com/rh-hideout/pokeemerald-expansion/pull/5156)
* Teatime animations use B_WAIT_TIME_LONG by @AsparagusEduardo in [#5173](https://github.com/rh-hideout/pokeemerald-expansion/pull/5173)
* Created PokeNav COMPOUND_STRINGS by @fdeblasio in [#4983](https://github.com/rh-hideout/pokeemerald-expansion/pull/4983)
* Consolidated the values of Rotom's moves and added Gen9 base form effect by @fdeblasio in [#5186](https://github.com/rh-hideout/pokeemerald-expansion/pull/5186)
* Removed all instances of gBitTable[x] by @hedara90 in [#5123](https://github.com/rh-hideout/pokeemerald-expansion/pull/5123)
* Removed gBitTable usage again by @hedara90 in [#5193](https://github.com/rh-hideout/pokeemerald-expansion/pull/5193)
* Adds OW_BERRY_IMMORTAL by @pkmnsnfrn in [#5187](https://github.com/rh-hideout/pokeemerald-expansion/pull/5187)
* DoBattleIntro state documentation by @AsparagusEduardo in [#5231](https://github.com/rh-hideout/pokeemerald-expansion/pull/5231)
* Remove support for the original LCG random number generator by @tertu-m in [#5078](https://github.com/rh-hideout/pokeemerald-expansion/pull/5078)
* Dynamic Move Display fixes by @Galaxeeh in [#5251](https://github.com/rh-hideout/pokeemerald-expansion/pull/5251)
* Add Population Bomb animation by @kittenchilly in [#5194](https://github.com/rh-hideout/pokeemerald-expansion/pull/5194)
* Add I_REPEL_INCLUDE_FAINTED config and behavior by @kittenchilly in [#5239](https://github.com/rh-hideout/pokeemerald-expansion/pull/5239)
* Fix a display issue with B_SHOW_TYPES by @pkmnsnfrn in [#5201](https://github.com/rh-hideout/pokeemerald-expansion/pull/5201)
* Chilly Reception AI by @kittenchilly in [#5271](https://github.com/rh-hideout/pokeemerald-expansion/pull/5271)
* Shed Tail AI by @SarnPoke in [#5275](https://github.com/rh-hideout/pokeemerald-expansion/pull/5275)
* More missing AI logic by @kittenchilly in [#5279](https://github.com/rh-hideout/pokeemerald-expansion/pull/5279)
* Added performance counter by @hedara90 in [#5284](https://github.com/rh-hideout/pokeemerald-expansion/pull/5284)
* Deprecate MMBN Names by @pkmnsnfrn in [#5240](https://github.com/rh-hideout/pokeemerald-expansion/pull/5240)
* Adds basic trainer and smart trainer flags by @AlexOn1ine in [#5298](https://github.com/rh-hideout/pokeemerald-expansion/pull/5298)
* Convert 8 various to callnatives by @AsparagusEduardo in [#5172](https://github.com/rh-hideout/pokeemerald-expansion/pull/5172)
* EV Caps and EV Items by @Flash1Lucky in [#5269](https://github.com/rh-hideout/pokeemerald-expansion/pull/5269)
* Adds config to show target of ingame partner by @AlexOn1ine in [#5307](https://github.com/rh-hideout/pokeemerald-expansion/pull/5307)
* (Default Off) Item Description Headers by @ghoulslash in [#4767](https://github.com/rh-hideout/pokeemerald-expansion/pull/4767)
* RTC-based wild encounters by @hjk321 in [#5313](https://github.com/rh-hideout/pokeemerald-expansion/pull/5313)
* AI_FLAG_SETUP_FIRST_TURN Rename and Clarifications by @Pawkkie in [#5310](https://github.com/rh-hideout/pokeemerald-expansion/pull/5310)
* Move battle anim arrays to C by @cawtds in [#5306](https://github.com/rh-hideout/pokeemerald-expansion/pull/5306)
* Converted Mechadoll text to COMPOUND_STRINGs by @fdeblasio in [#5276](https://github.com/rh-hideout/pokeemerald-expansion/pull/5276)
* Fix Gen 3 foreseen and Beat Up damage type by @hedara90 in [#5323](https://github.com/rh-hideout/pokeemerald-expansion/pull/5323)
* Converted PC strings to COMPOUND_STRINGs by @fdeblasio in [#5314](https://github.com/rh-hideout/pokeemerald-expansion/pull/5314)
* new terrain bgs by @TheTrueSadfish in [#5162](https://github.com/rh-hideout/pokeemerald-expansion/pull/5162)
* RTC-based wild encounters follow up by @AlexOn1ine in [#5328](https://github.com/rh-hideout/pokeemerald-expansion/pull/5328)
* Revert rtc based encounters by @AlexOn1ine in [#5331](https://github.com/rh-hideout/pokeemerald-expansion/pull/5331)
* add debug build target by @u8-Salem in [#4817](https://github.com/rh-hideout/pokeemerald-expansion/pull/4817)
* Grass/Water Pledge Swamp Animation + Sea of Fire animation tweak by @SonikkuA-DatH in [#5325](https://github.com/rh-hideout/pokeemerald-expansion/pull/5325)
* Cleaned up duplicate dynamic type functions by @AsparagusEduardo in [#5338](https://github.com/rh-hideout/pokeemerald-expansion/pull/5338)
* Add Composite AI Flags to Docs by @Pawkkie in [#5349](https://github.com/rh-hideout/pokeemerald-expansion/pull/5349)
* Removes redundant moveTargetType ai function by @AlexOn1ine in [#5354](https://github.com/rh-hideout/pokeemerald-expansion/pull/5354)
* AI burn score fixes and improvements by @Pawkkie in [#5356](https://github.com/rh-hideout/pokeemerald-expansion/pull/5356)
* Reset item flags on new game by @ghoulslash in [#5363](https://github.com/rh-hideout/pokeemerald-expansion/pull/5363)
* AI frostbite score fixes and improvements by @Pawkkie in [#5362](https://github.com/rh-hideout/pokeemerald-expansion/pull/5362)
* Made BuildColorMaps redundant by using static tables by @pkmnsnfrn in [#5289](https://github.com/rh-hideout/pokeemerald-expansion/pull/5289)
* Add in-battle shadows underneath all enemy battlers by @lhearachel in [#5178](https://github.com/rh-hideout/pokeemerald-expansion/pull/5178)
* Improve AI's Skill Swap handling in double battles by @Pawkkie in [#5360](https://github.com/rh-hideout/pokeemerald-expansion/pull/5360)
* Switch AI hitsToKO considers one shot prevention by @Pawkkie in [#5371](https://github.com/rh-hideout/pokeemerald-expansion/pull/5371)
* Some Strings were switched by @AlexOn1ine in [#5374](https://github.com/rh-hideout/pokeemerald-expansion/pull/5374)
* Adds CanEndureHit AI function by @AlexOn1ine in [#5373](https://github.com/rh-hideout/pokeemerald-expansion/pull/5373)
* Switch AI hitsToKO considers Disguise by @Pawkkie in [#5375](https://github.com/rh-hideout/pokeemerald-expansion/pull/5375)
* Fixes Defog used by the wrong side when there is a Substitue and Screen by @AlexOn1ine in [#5381](https://github.com/rh-hideout/pokeemerald-expansion/pull/5381)
* new animations for many moves more details in description by @TheTrueSadfish in [#5367](https://github.com/rh-hideout/pokeemerald-expansion/pull/5367)
* Cleaned up a bit of code with GetBattlerPartyData by @AlexOn1ine in [#5378](https://github.com/rh-hideout/pokeemerald-expansion/pull/5378)
* Minor Gem check optimazation by @AlexOn1ine in [#5401](https://github.com/rh-hideout/pokeemerald-expansion/pull/5401)
* Add AUTO_SCROLL_TEXT and NUM_FRAMES_AUTO_SCROLL_DELAY by @pkmnsnfrn in [#5054](https://github.com/rh-hideout/pokeemerald-expansion/pull/5054)
* Simplify HP Logic by @AreaZR in [#5403](https://github.com/rh-hideout/pokeemerald-expansion/pull/5403)
* anger shell use saveattacker by @ghoulslash in [#5409](https://github.com/rh-hideout/pokeemerald-expansion/pull/5409)
* Add `OW_AUTO_SIGNPOST` and associated metatile behaviors by @pkmnsnfrn in [#5044](https://github.com/rh-hideout/pokeemerald-expansion/pull/5044)
* Converted berry and PokeBlock strings to COMPOUND_STRINGs  by @fdeblasio in [#5324](https://github.com/rh-hideout/pokeemerald-expansion/pull/5324)
* Removed FRONTIER_BRAIN_SPRITES and updated TRAINER_SPRITE, TRAINER_BACK_SPRITE, and TRAINER_CLASS by @fdeblasio in [#5166](https://github.com/rh-hideout/pokeemerald-expansion/pull/5166)
* Merge item description branch history by @Bassoonian in [#5419](https://github.com/rh-hideout/pokeemerald-expansion/pull/5419)
* Clean up Unseen Fist Check by @AlexOn1ine in [#5420](https://github.com/rh-hideout/pokeemerald-expansion/pull/5420)
* Adds SAVE_TYPE_ERROR_SCREEN by @pkmnsnfrn in [#5188](https://github.com/rh-hideout/pokeemerald-expansion/pull/5188)
* Merge level_caps and ev_caps into one caps file by @kittenchilly in [#5429](https://github.com/rh-hideout/pokeemerald-expansion/pull/5429)
* Use move effect for some moves instead of ids by @AlexOn1ine in [#5433](https://github.com/rh-hideout/pokeemerald-expansion/pull/5433)
* Added MB_X_Y_STAIR_WARP metatile behaviors by @pkmnsnfrn in [#5278](https://github.com/rh-hideout/pokeemerald-expansion/pull/5278)
* Add ShouldSwitch result to AiLogicData by @Pawkkie in [#5440](https://github.com/rh-hideout/pokeemerald-expansion/pull/5440)
* Add Gen 1 Crit Chance by @Pawkkie in [#5439](https://github.com/rh-hideout/pokeemerald-expansion/pull/5439)
* Adds Commander and Order Up by @AlexOn1ine in [#5246](https://github.com/rh-hideout/pokeemerald-expansion/pull/5246)
* Add Sideways Stairs by @ghoulslash in [#4836](https://github.com/rh-hideout/pokeemerald-expansion/pull/4836)
* Switch AI refactor + considers free switches by @Pawkkie in [#5379](https://github.com/rh-hideout/pokeemerald-expansion/pull/5379)
* Remove trailing whitespace pass 10-2-2024 (Upcoming) by @kittenchilly in [#5456](https://github.com/rh-hideout/pokeemerald-expansion/pull/5456)
* Fix Commander test name by @Bassoonian in [#5458](https://github.com/rh-hideout/pokeemerald-expansion/pull/5458)
* Updated species defines by @pkmnsnfrn in [#5075](https://github.com/rh-hideout/pokeemerald-expansion/pull/5075)
* Fixes Hidden Power dynamic type bug by @AlexOn1ine in [#5463](https://github.com/rh-hideout/pokeemerald-expansion/pull/5463)
* Add functionality to Poké Flute and Town Map by @kittenchilly in [#5405](https://github.com/rh-hideout/pokeemerald-expansion/pull/5405)

## New Contributors
* @SombrAbsol made their first contribution in [#4958](https://github.com/rh-hideout/pokeemerald-expansion/pull/4958)
* @Galaxeeh made their first contribution in [#5084](https://github.com/rh-hideout/pokeemerald-expansion/pull/5084)
* @Flash1Lucky made their first contribution in [#5269](https://github.com/rh-hideout/pokeemerald-expansion/pull/5269)

## 🌋 *REFACTORS* 🌋
📜 = Uses a migration script.
* N/A

## 💥 *Hardlock/Softlock/Crash/Compiling fixes* 💥
* N/A

## 🧬 General 🧬
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## ✨ Feature Branches ✨
### ***TheXaman's Debug Menu***:
#### Added
* N/A
#### Changed
* N/A
#### Fixed
* N/A
### ***TheXaman's HGSS Pokédex Plus***:
#### Added
* N/A
#### Changed
* N/A
#### Fixed
* N/A
### ***SBird/Karathan's Dynamic Multichoices***:
#### Added
* N/A
#### Changed
* N/A
#### Fixed
* N/A
### ***ghoulslash's Saveblock Cleansing***:
#### Added
* N/A
#### Changed
* N/A
#### Fixed
* N/A
### ***merrp/aarant's Followers***
#### Added
* N/A
#### Changed
* N/A
#### Fixed
* N/A

## 🐉 Pokémon 🐉
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## ⚔️ Battle General ⚔️ ##
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## 🤹 Moves 🤹
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## 🎭 Abilities 🎭
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## 🧶 Items 🧶
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## 🤖 Battle AI 🤖
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## 🧹 Other Cleanup 🧹
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## 🧪 Test Runner 🧪
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## 📚 Documentation 📚
### Added
* N/A
### Changed
* N/A
### Fixed
* N/A

## 📦 Branch Synchronisation 📦
### pret's base pokeemerald
* N/A
### merrp/aarant's followers
* N/A

**Full Changelog**: https://github.com/rh-hideout/pokeemerald-expansion/compare/expansion/1.Y.Z...expansion/1.Y.Z

<!--Last PR: 5405-->
<!--Used to keep track of the last PR merged in case new ones come in before the changelog is done.-->
