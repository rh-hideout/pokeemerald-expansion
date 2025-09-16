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

# 18 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 19 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated
# 20 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 21 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
# 22 "data/maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 23 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 24 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
# 25 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 26 "data/maps/Route102/scripts.pory"
	release
# 27 "data/maps/Route102/scripts.pory"
	end
# 28 "data/maps/Route102/scripts.pory"

# 29 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
# 30 "data/maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 31 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 32 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 33 "data/maps/Route102/scripts.pory"
	release
# 34 "data/maps/Route102/scripts.pory"
	end
# 35 "data/maps/Route102/scripts.pory"

# 36 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall::
# 37 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 38 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 39 "data/maps/Route102/scripts.pory"
	release
# 40 "data/maps/Route102/scripts.pory"
	end
# 41 "data/maps/Route102/scripts.pory"

# 42 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister::
# 43 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 44 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 45 "data/maps/Route102/scripts.pory"
	release
# 46 "data/maps/Route102/scripts.pory"
	end
# 47 "data/maps/Route102/scripts.pory"

# 48 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister::
# 49 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 50 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 51 "data/maps/Route102/scripts.pory"
	release
# 52 "data/maps/Route102/scripts.pory"
	end
# 53 "data/maps/Route102/scripts.pory"

# 54 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch::
# 55 "data/maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 56 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 57 "data/maps/Route102/scripts.pory"
	end
# 58 "data/maps/Route102/scripts.pory"

# 59 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 60 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 61 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 62 "data/maps/Route102/scripts.pory"
	end
# 63 "data/maps/Route102/scripts.pory"

# 64 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 65 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated, Route102_EventScript_Route_Clear
# 66 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 67 "data/maps/Route102/scripts.pory"
	end
# 68 "data/maps/Route102/scripts.pory"

# 69 "data/maps/Route102/scripts.pory"

# 70 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 71 "data/maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 72 "data/maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 73 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 74 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 75 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 76 "data/maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 77 "data/maps/Route102/scripts.pory"

# 78 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 79 "data/maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 80 "data/maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 81 "data/maps/Route102/scripts.pory"

# 82 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 83 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 84 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 85 "data/maps/Route102/scripts.pory"

# 86 "data/maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall:
# 87 "data/maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
# 88 "data/maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 89 "data/maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 90 "data/maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 91 "data/maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 92 "data/maps/Route102/scripts.pory"

# 93 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 94 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 95 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 96 "data/maps/Route102/scripts.pory"

# 97 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 98 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 99 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"

Route102_EventScript_PokemonBlockade::
# 104 "data/maps/Route102/scripts.pory"
	lock
# 105 "data/maps/Route102/scripts.pory"
	faceplayer
# 106 "data/maps/Route102/scripts.pory"
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
# 107 "data/maps/Route102/scripts.pory"
	waitmoncry
# 108 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_PokemonBlockade_Text_0, MSGBOX_AUTOCLOSE
# 109 "data/maps/Route102/scripts.pory"
	turnobject 9, DIR_EAST
# 110 "data/maps/Route102/scripts.pory"
	turnobject 10, DIR_SOUTH
# 111 "data/maps/Route102/scripts.pory"
	waitmessage
# 112 "data/maps/Route102/scripts.pory"
	release
	end


Route102_EventScript_Route_Clear::
# 123 "data/maps/Route102/scripts.pory"
	lockall
# 124 "data/maps/Route102/scripts.pory"
	fadescreen FADE_TO_BLACK
# 125 "data/maps/Route102/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 126 "data/maps/Route102/scripts.pory"
	setflag FLAG_ROUTE102_CLEAR
# 127 "data/maps/Route102/scripts.pory"
	removeobject 9
# 128 "data/maps/Route102/scripts.pory"
	removeobject 10
# 129 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Route_Clear_Text_0, MSGBOX_DEFAULT
# 130 "data/maps/Route102/scripts.pory"
	waitmessage
# 131 "data/maps/Route102/scripts.pory"
	waitfanfare
# 132 "data/maps/Route102/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 133 "data/maps/Route102/scripts.pory"
	releaseall
	end


Route102_EventScript_Boy::
# 139 "data/maps/Route102/scripts.pory"
	lockall
# 140 "data/maps/Route102/scripts.pory"
	faceplayer
# 141 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Boy_Text_0, MSGBOX_DEFAULT
# 143 "data/maps/Route102/scripts.pory"
	waitmessage
# 144 "data/maps/Route102/scripts.pory"
	releaseall
	end


Route102_EventScript_Route_Rewards::
# 150 "data/maps/Route102/scripts.pory"
	lockall
# 151 "data/maps/Route102/scripts.pory"
	goto_if_unset FLAG_ROUTE102_REWARD, Route102_EventScript_Route_Rewards_1
# 171 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Route_Rewards_Text_2, MSGBOX_AUTOCLOSE
# 172 "data/maps/Route102/scripts.pory"
	waitmessage
# 173 "data/maps/Route102/scripts.pory"
	releaseall
	end

Route102_EventScript_Route_Rewards_1:
# 152 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Route_Rewards_Text_0, MSGBOX_YESNO
# 153 "data/maps/Route102/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route102_EventScript_Route_Rewards_4
# 164 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Route_Rewards_Text_1, MSGBOX_DEFAULT
# 165 "data/maps/Route102/scripts.pory"
	waitmessage
# 166 "data/maps/Route102/scripts.pory"
	releaseall
	end

Route102_EventScript_Route_Rewards_4:
# 155 "data/maps/Route102/scripts.pory"
	giveitem ITEM_SILK_SCARF, 1
# 156 "data/maps/Route102/scripts.pory"
	giveitem ITEM_SOOTHE_BELL, 1
# 157 "data/maps/Route102/scripts.pory"
	giveitem ITEM_AIR_BALLOON, 1
# 158 "data/maps/Route102/scripts.pory"
	setflag FLAG_ROUTE102_REWARD
# 159 "data/maps/Route102/scripts.pory"
	removeobject 11
# 160 "data/maps/Route102/scripts.pory"
	releaseall
	end


Route102_EventScript_PokemonBlockade_Text_0:
# 108 "data/maps/Route102/scripts.pory"
	.string "The POKéMON seems upset! Try clearing\n"
	.string "the trainers so it will leave.$"

Route102_EventScript_Route_Clear_Text_0:
# 129 "data/maps/Route102/scripts.pory"
	.string "Route 102 has been cleared!\n"
	.string "The level cap is now 9.$"

Route102_EventScript_Boy_Text_0:
# 141 "data/maps/Route102/scripts.pory"
	.string "Well, I WAS gonna catch a bunch of\n"
	.string "POKéMON, but these trainers are in the\l"
	.string "way! When this happens, you can either\l"
	.string "risk the trainer battles while saving\l"
	.string "the encounters until after, or just\l"
	.string "picking up an encounter before.$"

Route102_EventScript_Route_Rewards_Text_0:
# 152 "data/maps/Route102/scripts.pory"
	.string "Would you like the route rewards?$"

Route102_EventScript_Route_Rewards_Text_1:
# 164 "data/maps/Route102/scripts.pory"
	.string "You didn't take the route rewards.$"

Route102_EventScript_Route_Rewards_Text_2:
# 171 "data/maps/Route102/scripts.pory"
	.string "An error occurred.$"
