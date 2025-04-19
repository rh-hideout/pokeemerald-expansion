# 1 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_MapScripts::
# 3 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
# 4 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.byte 0
# 5 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 6 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_OnLoad:
# 7 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
# 8 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 9 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 10 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_OpenDoor::
# 11 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 12 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 13 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 14 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Scroll::
# 15 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	lockall
# 16 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
# 17 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 18 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 19 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 20 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_FoundScroll::
# 21 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
# 22 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 23 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 24 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 25 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Sally::
# 26 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
# 27 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 29 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 30 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Eddie::
# 31 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
# 32 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
# 33 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 34 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 35 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Robin::
# 36 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
# 37 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 39 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 40 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
# 41 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 42 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "on the door.\p"
# 43 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "“TRICK MASTER is fabulous.”\n"
# 44 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "… … … … … … … …\p"
# 45 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "The lock clicked open!$"
# 46 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 47 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyIntro:
# 48 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I'll hack and slash my way to victory\n"
# 49 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "with the CUT we just learned!$"
# 50 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 51 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyDefeat:
# 52 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Why are you so serious?$"
# 53 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 54 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyPostBattle:
# 55 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I never get tired of hacking\n"
# 56 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "and slashing!$"
# 57 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 58 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddieIntro:
# 59 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I wandered into this weird house\n"
# 60 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "by accident…$"
# 61 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 62 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddieDefeat:
# 63 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "And now I've lost…$"
# 64 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 65 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddiePostBattle:
# 66 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I lost my way, I lost a battle, and I'm\n"
# 67 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "now even more lost… I can't get out…$"
# 68 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 69 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinIntro:
# 70 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Just who is the TRICK MASTER?$"
# 71 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 72 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinDefeat:
# 73 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I lost while I was lost in thought!$"
# 74 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 75 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinPostBattle:
# 76 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "You're strong!\n"
# 77 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Just who are you?$"
