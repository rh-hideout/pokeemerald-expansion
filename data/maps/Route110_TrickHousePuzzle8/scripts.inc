# 1 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_MapScripts::
# 3 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.byte 0
# 4 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 5 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Scroll::
# 6 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	lockall
# 7 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
# 8 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 9 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 10 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 11 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_FoundScroll::
# 12 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
# 13 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 14 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 15 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 16 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Vincent::
# 17 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
# 18 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
# 19 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 20 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 21 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Keira::
# 22 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
# 23 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
# 24 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 25 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 26 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Leroy::
# 27 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
# 28 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
# 29 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 30 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 31 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
# 32 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 33 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "on the door.\p"
# 34 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "“TRICK MASTER I love.”\n"
# 35 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "… … … … … … … …\p"
# 36 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "The lock clicked open!$"
# 37 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 38 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentIntro:
# 39 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Not many TRAINERS have made it\n"
# 40 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "this far.$"
# 41 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 42 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentDefeat:
# 43 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "That must mean you're tough, too…$"
# 44 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 45 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentPostBattle:
# 46 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You've beaten the POKéMON LEAGUE\n"
# 47 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "CHAMPION? That's too much!$"
# 48 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 49 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraIntro:
# 50 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Consider yourself lucky to be\n"
# 51 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "battling me!$"
# 52 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 53 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraDefeat:
# 54 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "This isn't right!\n"
# 55 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "I can't lose!$"
# 56 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 57 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
# 58 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "It's a miracle that you beat me.\n"
# 59 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You can brag about it.$"
# 60 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 61 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyIntro:
# 62 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You've been slugging through the TRICK\n"
# 63 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "HOUSE challenge, too.$"
# 64 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 65 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyDefeat:
# 66 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "I see…\n"
# 67 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You possess an extraordinary style.$"
# 68 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 69 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
# 70 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Seeing someone like you should please\n"
# 71 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "the TRICK MASTER.$"
