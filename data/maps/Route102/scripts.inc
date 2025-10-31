# 1 "data/maps/Route102/scripts.pory"

# 2 "data/maps/Route102/scripts.pory"
Route102_MapScripts::
# 3 "data/maps/Route102/scripts.pory"
	.byte 0
# 4 "data/maps/Route102/scripts.pory"

# 5 "data/maps/Route102/scripts.pory"
Route102_EventScript_LittleBoy::
# 6 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
# 7 "data/maps/Route102/scripts.pory"
	end
# 8 "data/maps/Route102/scripts.pory"

# 9 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale::
# 10 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 11 "data/maps/Route102/scripts.pory"
	end
# 12 "data/maps/Route102/scripts.pory"

# 13 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg::
# 14 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 15 "data/maps/Route102/scripts.pory"
	end
# 16 "data/maps/Route102/scripts.pory"

# 17 "data/maps/Route102/scripts.pory"
Route102_EventScript_Boy::
# 18 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
# 19 "data/maps/Route102/scripts.pory"
	end
# 20 "data/maps/Route102/scripts.pory"

# 21 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 22 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
# 23 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 24 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
# 25 "data/maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 26 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 27 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
# 28 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 29 "data/maps/Route102/scripts.pory"
	release
# 30 "data/maps/Route102/scripts.pory"
	end
# 31 "data/maps/Route102/scripts.pory"

# 32 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
# 33 "data/maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 34 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 35 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 36 "data/maps/Route102/scripts.pory"
	release
# 37 "data/maps/Route102/scripts.pory"
	end
# 38 "data/maps/Route102/scripts.pory"

# 39 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall::
# 40 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 41 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 42 "data/maps/Route102/scripts.pory"
	release
# 43 "data/maps/Route102/scripts.pory"
	end
# 44 "data/maps/Route102/scripts.pory"

# 45 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister::
# 46 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 47 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 48 "data/maps/Route102/scripts.pory"
	release
# 49 "data/maps/Route102/scripts.pory"
	end
# 50 "data/maps/Route102/scripts.pory"

# 51 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister::
# 52 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 53 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 54 "data/maps/Route102/scripts.pory"
	release
# 55 "data/maps/Route102/scripts.pory"
	end
# 56 "data/maps/Route102/scripts.pory"

# 57 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch::
# 58 "data/maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 59 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 60 "data/maps/Route102/scripts.pory"
	end
# 61 "data/maps/Route102/scripts.pory"

# 62 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 63 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 64 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 65 "data/maps/Route102/scripts.pory"
	end
# 66 "data/maps/Route102/scripts.pory"

# 67 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 68 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
# 69 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 70 "data/maps/Route102/scripts.pory"
	end
# 71 "data/maps/Route102/scripts.pory"

# 72 "data/maps/Route102/scripts.pory"
Route102_EventScript_Allen::
# 73 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
# 74 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 75 "data/maps/Route102/scripts.pory"
	end
# 76 "data/maps/Route102/scripts.pory"

# 77 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 78 "data/maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 79 "data/maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 80 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 81 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 82 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 83 "data/maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 84 "data/maps/Route102/scripts.pory"

# 85 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 86 "data/maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 87 "data/maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 88 "data/maps/Route102/scripts.pory"

# 89 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 90 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 91 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 92 "data/maps/Route102/scripts.pory"

# 93 "data/maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall:
# 94 "data/maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
# 95 "data/maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 96 "data/maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 97 "data/maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 98 "data/maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 99 "data/maps/Route102/scripts.pory"

# 100 "data/maps/Route102/scripts.pory"
Route102_Text_CatchWholeBunchOfPokemon:
# 101 "data/maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
# 102 "data/maps/Route102/scripts.pory"
	.string "POKéMON!$"
# 103 "data/maps/Route102/scripts.pory"

# 104 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 105 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 106 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 107 "data/maps/Route102/scripts.pory"

# 108 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 109 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 110 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"
