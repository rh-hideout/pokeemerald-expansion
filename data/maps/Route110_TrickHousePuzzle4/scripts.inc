# 1 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_MapScripts::
# 3 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.byte 0
# 4 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 5 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Scroll::
# 6 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	lockall
# 7 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
# 8 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 9 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 10 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 11 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_FoundScroll::
# 12 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
# 13 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 14 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 15 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 16 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Cora::
# 17 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
# 18 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
# 19 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 20 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 21 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Yuji::
# 22 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
# 23 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
# 24 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 25 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 26 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Paula::
# 27 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
# 28 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
# 29 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 30 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 31 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
# 32 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 33 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "on the door.\p"
# 34 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "“TRICK MASTER is cool.”\n"
# 35 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "… … … … … … … …\p"
# 36 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "The lock clicked open!$"
# 37 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 38 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraIntro:
# 39 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "It's too much bother to think this out.\n"
# 40 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "I only wanted to battle!$"
# 41 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 42 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraDefeat:
# 43 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Even though I lost, I still like battling\n"
# 44 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "the best!$"
# 45 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 46 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraPostBattle:
# 47 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Wouldn't you agree? You would go\n"
# 48 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "anywhere if TRAINERS were there.$"
# 49 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 50 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiIntro:
# 51 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Heh! Boulders like this, I can brush\n"
# 52 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "aside with one finger!$"
# 53 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 54 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiDefeat:
# 55 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "I can push boulders, but I can't solve\n"
# 56 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "the puzzle…$"
# 57 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 58 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiPostBattle:
# 59 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "It's not good enough to be brawny…\n"
# 60 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "You have to use your head. Be brainy!$"
# 61 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 62 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaIntro:
# 63 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "The TRICK HOUSE is getting trickier,\n"
# 64 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "isn't it?$"
# 65 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 66 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaDefeat:
# 67 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Aaak!$"
# 68 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 69 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
# 70 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Has anyone made it to the end?$"
