# 1 "data/maps/Route102/scripts.pory"

# 2 "data/maps/Route102/scripts.pory"
Route102_MapScripts::
# 3 "data/maps/Route102/scripts.pory"
	.byte 0
# 4 "data/maps/Route102/scripts.pory"

# 5 "data/maps/Route102/scripts.pory"

# 6 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale::
# 7 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 8 "data/maps/Route102/scripts.pory"
	end
# 9 "data/maps/Route102/scripts.pory"

# 10 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg::
# 11 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 12 "data/maps/Route102/scripts.pory"
	end
# 13 "data/maps/Route102/scripts.pory"

# 14 "data/maps/Route102/scripts.pory"

# 15 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 16 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated
# 17 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 18 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
# 19 "data/maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 20 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 21 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
# 22 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 23 "data/maps/Route102/scripts.pory"
	release
# 24 "data/maps/Route102/scripts.pory"
	end
# 25 "data/maps/Route102/scripts.pory"

# 26 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
# 27 "data/maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 28 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 29 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 30 "data/maps/Route102/scripts.pory"
	release
# 31 "data/maps/Route102/scripts.pory"
	end
# 32 "data/maps/Route102/scripts.pory"

# 33 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall::
# 34 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 35 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 36 "data/maps/Route102/scripts.pory"
	release
# 37 "data/maps/Route102/scripts.pory"
	end
# 38 "data/maps/Route102/scripts.pory"

# 39 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister::
# 40 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 41 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 42 "data/maps/Route102/scripts.pory"
	release
# 43 "data/maps/Route102/scripts.pory"
	end
# 44 "data/maps/Route102/scripts.pory"

# 45 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister::
# 46 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 47 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 48 "data/maps/Route102/scripts.pory"
	release
# 49 "data/maps/Route102/scripts.pory"
	end
# 50 "data/maps/Route102/scripts.pory"

# 51 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch::
# 52 "data/maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 53 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 54 "data/maps/Route102/scripts.pory"
	end
# 55 "data/maps/Route102/scripts.pory"

# 56 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 57 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 58 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 59 "data/maps/Route102/scripts.pory"
	end
# 60 "data/maps/Route102/scripts.pory"

# 61 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 62 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated, Route102_EventScript_Route_Clear
# 63 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 64 "data/maps/Route102/scripts.pory"
	end
# 65 "data/maps/Route102/scripts.pory"

# 66 "data/maps/Route102/scripts.pory"

# 67 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 68 "data/maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 69 "data/maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 70 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 71 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 72 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 73 "data/maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 74 "data/maps/Route102/scripts.pory"

# 75 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 76 "data/maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 77 "data/maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 78 "data/maps/Route102/scripts.pory"

# 79 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 80 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 81 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 82 "data/maps/Route102/scripts.pory"

# 83 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 84 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 85 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 86 "data/maps/Route102/scripts.pory"

# 87 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 88 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 89 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"

Route102_EventScript_PokemonBlockade::
# 94 "data/maps/Route102/scripts.pory"
	lock
# 95 "data/maps/Route102/scripts.pory"
	faceplayer
# 96 "data/maps/Route102/scripts.pory"
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
# 97 "data/maps/Route102/scripts.pory"
	waitmoncry
# 98 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_PokemonBlockade_Text_0, MSGBOX_AUTOCLOSE
# 99 "data/maps/Route102/scripts.pory"
	turnobject 9, DIR_EAST
# 100 "data/maps/Route102/scripts.pory"
	turnobject 10, DIR_SOUTH
# 101 "data/maps/Route102/scripts.pory"
	waitmessage
# 102 "data/maps/Route102/scripts.pory"
	release
	end


Route102_EventScript_Route_Clear::
# 113 "data/maps/Route102/scripts.pory"
	lockall
# 114 "data/maps/Route102/scripts.pory"
	fadescreen FADE_TO_BLACK
# 115 "data/maps/Route102/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 116 "data/maps/Route102/scripts.pory"
	setflag FLAG_ROUTE102_CLEAR
# 117 "data/maps/Route102/scripts.pory"
	removeobject 9
# 118 "data/maps/Route102/scripts.pory"
	removeobject 10
# 119 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Route_Clear_Text_0, MSGBOX_DEFAULT
# 120 "data/maps/Route102/scripts.pory"
	waitmessage
# 121 "data/maps/Route102/scripts.pory"
	waitfanfare
# 122 "data/maps/Route102/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 123 "data/maps/Route102/scripts.pory"
	releaseall
	end


Route102_EventScript_Boy::
# 129 "data/maps/Route102/scripts.pory"
	lock
# 130 "data/maps/Route102/scripts.pory"
	faceplayer
# 131 "data/maps/Route102/scripts.pory"
	goto_if_unset FLAG_ROUTE102_CLEAR, Route102_EventScript_Boy_2
# 138 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Boy_Text_1, MSGBOX_DEFAULT
# 139 "data/maps/Route102/scripts.pory"
	waitmessage
Route102_EventScript_Boy_1:
# 141 "data/maps/Route102/scripts.pory"
	release
	end

Route102_EventScript_Boy_2:
# 133 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Boy_Text_0, MSGBOX_DEFAULT
# 135 "data/maps/Route102/scripts.pory"
	waitmessage
	goto Route102_EventScript_Boy_1


Route102_EventScript_Route_Rewards::
# 147 "data/maps/Route102/scripts.pory"
	lock
# 148 "data/maps/Route102/scripts.pory"
	goto_if_unset FLAG_ROUTE102_REWARD, Route102_EventScript_Route_Rewards_1
# 167 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Route_Rewards_Text_2, MSGBOX_AUTOCLOSE
# 168 "data/maps/Route102/scripts.pory"
	waitmessage
# 169 "data/maps/Route102/scripts.pory"
	release
	end

Route102_EventScript_Route_Rewards_1:
# 149 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Route_Rewards_Text_0, MSGBOX_YESNO
# 150 "data/maps/Route102/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route102_EventScript_Route_Rewards_4
# 160 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Route_Rewards_Text_1, MSGBOX_DEFAULT
# 161 "data/maps/Route102/scripts.pory"
	waitmessage
# 162 "data/maps/Route102/scripts.pory"
	release
	end

Route102_EventScript_Route_Rewards_4:
# 152 "data/maps/Route102/scripts.pory"
	removeobject 11
# 153 "data/maps/Route102/scripts.pory"
	giveitem ITEM_SILK_SCARF, 1
# 154 "data/maps/Route102/scripts.pory"
	giveitem ITEM_SOOTHE_BELL, 1
# 155 "data/maps/Route102/scripts.pory"
	setflag FLAG_ROUTE102_REWARD
# 156 "data/maps/Route102/scripts.pory"
	release
	end


Route102_EventScript_LittleBoy::
# 177 "data/maps/Route102/scripts.pory"
	faceplayer
# 178 "data/maps/Route102/scripts.pory"
	lock
# 179 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_LittleBoy_Text_0, MSGBOX_DEFAULT
# 181 "data/maps/Route102/scripts.pory"
	release
	end


Route102_EventScript_PokemonBlockade_Text_0:
# 98 "data/maps/Route102/scripts.pory"
	.string "The POKéMON seems upset! Try clearing\n"
	.string "the trainers so it will leave.$"

Route102_EventScript_Route_Clear_Text_0:
# 119 "data/maps/Route102/scripts.pory"
	.string "Route 102 has been cleared!\n"
	.string "The level cap is now 9.$"

Route102_EventScript_Boy_Text_0:
# 133 "data/maps/Route102/scripts.pory"
	.string "Well, I WAS gonna catch a bunch of\n"
	.string "POKéMON, but these trainers are in the\l"
	.string "way! When this happens, you can either\l"
	.string "risk the trainer battles while saving\l"
	.string "the encounters until after, or just\l"
	.string "picking up an encounter before.$"

Route102_EventScript_Boy_Text_1:
# 138 "data/maps/Route102/scripts.pory"
	.string "Thanks for your help! I'll be around if\n"
	.string "you need anything.$"

Route102_EventScript_Route_Rewards_Text_0:
# 149 "data/maps/Route102/scripts.pory"
	.string "Would you like the route rewards?$"

Route102_EventScript_Route_Rewards_Text_1:
# 160 "data/maps/Route102/scripts.pory"
	.string "You didn't take the route rewards.$"

Route102_EventScript_Route_Rewards_Text_2:
# 167 "data/maps/Route102/scripts.pory"
	.string "An error occurred.$"

Route102_EventScript_LittleBoy_Text_0:
# 179 "data/maps/Route102/scripts.pory"
	.string "I'm hiding from my parents. They got mad\n"
	.string "at me for eating off the berry trees\l"
	.string "before dinner. How was I supposed to\l"
	.string "know they are reserved for POKéMON?$"
