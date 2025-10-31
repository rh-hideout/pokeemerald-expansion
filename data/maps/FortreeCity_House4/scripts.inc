# 1 "data/maps/FortreeCity_House4/scripts.pory"

# 2 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_MapScripts::
# 3 "data/maps/FortreeCity_House4/scripts.pory"
	.byte 0
# 4 "data/maps/FortreeCity_House4/scripts.pory"

# 5 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_Woman::
# 6 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
# 7 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 8 "data/maps/FortreeCity_House4/scripts.pory"

# 9 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_Boy::
# 10 "data/maps/FortreeCity_House4/scripts.pory"
	lockall
# 11 "data/maps/FortreeCity_House4/scripts.pory"
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
# 12 "data/maps/FortreeCity_House4/scripts.pory"
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
# 13 "data/maps/FortreeCity_House4/scripts.pory"
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
# 14 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
# 15 "data/maps/FortreeCity_House4/scripts.pory"
	closemessage
# 16 "data/maps/FortreeCity_House4/scripts.pory"
	setflag FLAG_WINGULL_SENT_ON_ERRAND
# 17 "data/maps/FortreeCity_House4/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
# 18 "data/maps/FortreeCity_House4/scripts.pory"
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
# 19 "data/maps/FortreeCity_House4/scripts.pory"
	waitmovement 0
# 20 "data/maps/FortreeCity_House4/scripts.pory"
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
# 21 "data/maps/FortreeCity_House4/scripts.pory"
	releaseall
# 22 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 23 "data/maps/FortreeCity_House4/scripts.pory"

# 24 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_WingullOnErrand::
# 25 "data/maps/FortreeCity_House4/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 26 "data/maps/FortreeCity_House4/scripts.pory"
	waitmovement 0
# 27 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
# 28 "data/maps/FortreeCity_House4/scripts.pory"
	releaseall
# 29 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 30 "data/maps/FortreeCity_House4/scripts.pory"

# 31 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_WingullReturned::
# 32 "data/maps/FortreeCity_House4/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 33 "data/maps/FortreeCity_House4/scripts.pory"
	waitmovement 0
# 34 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
# 35 "data/maps/FortreeCity_House4/scripts.pory"
	giveitem ITEM_MENTAL_HERB
# 36 "data/maps/FortreeCity_House4/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 37 "data/maps/FortreeCity_House4/scripts.pory"
	setflag FLAG_RECEIVED_MENTAL_HERB
# 38 "data/maps/FortreeCity_House4/scripts.pory"
	releaseall
# 39 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 40 "data/maps/FortreeCity_House4/scripts.pory"

# 41 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_ReceivedMentalHerb::
# 42 "data/maps/FortreeCity_House4/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 43 "data/maps/FortreeCity_House4/scripts.pory"
	waitmovement 0
# 44 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
# 45 "data/maps/FortreeCity_House4/scripts.pory"
	releaseall
# 46 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 47 "data/maps/FortreeCity_House4/scripts.pory"

# 48 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Movement_WingullExit:
# 49 "data/maps/FortreeCity_House4/scripts.pory"
	walk_fast_down
# 50 "data/maps/FortreeCity_House4/scripts.pory"
	walk_fast_down
# 51 "data/maps/FortreeCity_House4/scripts.pory"
	walk_fast_right
# 52 "data/maps/FortreeCity_House4/scripts.pory"
	walk_in_place_faster_down
# 53 "data/maps/FortreeCity_House4/scripts.pory"
	delay_8
# 54 "data/maps/FortreeCity_House4/scripts.pory"
	step_end
# 55 "data/maps/FortreeCity_House4/scripts.pory"

# 56 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_Wingull::
# 57 "data/maps/FortreeCity_House4/scripts.pory"
	lock
# 58 "data/maps/FortreeCity_House4/scripts.pory"
	faceplayer
# 59 "data/maps/FortreeCity_House4/scripts.pory"
	waitse
# 60 "data/maps/FortreeCity_House4/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 61 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
# 62 "data/maps/FortreeCity_House4/scripts.pory"
	waitmoncry
# 63 "data/maps/FortreeCity_House4/scripts.pory"
	release
# 64 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 65 "data/maps/FortreeCity_House4/scripts.pory"

# 66 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_BringsWorldCloserTogether:
# 67 "data/maps/FortreeCity_House4/scripts.pory"
	.string "By being together with POKéMON,\n"
# 68 "data/maps/FortreeCity_House4/scripts.pory"
	.string "people make more and more friends.\p"
# 69 "data/maps/FortreeCity_House4/scripts.pory"
	.string "And that brings the world closer\n"
# 70 "data/maps/FortreeCity_House4/scripts.pory"
	.string "together. I think it's wonderful!$"
# 71 "data/maps/FortreeCity_House4/scripts.pory"

# 72 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_GoBirdPokemon:
# 73 "data/maps/FortreeCity_House4/scripts.pory"
	.string "There!\n"
# 74 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Go, BIRD POKéMON!$"
# 75 "data/maps/FortreeCity_House4/scripts.pory"

# 76 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_AskedWingullToRunErrand:
# 77 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Heheh, I asked my WINGULL to run\n"
# 78 "data/maps/FortreeCity_House4/scripts.pory"
	.string "an errand for me.$"
# 79 "data/maps/FortreeCity_House4/scripts.pory"

# 80 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
# 81 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Good!\n"
# 82 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Welcome back, WINGULL!\p"
# 83 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Huh? What is this?\n"
# 84 "data/maps/FortreeCity_House4/scripts.pory"
	.string "What is it holding?\p"
# 85 "data/maps/FortreeCity_House4/scripts.pory"
	.string "A MENTAL HERB?\n"
# 86 "data/maps/FortreeCity_House4/scripts.pory"
	.string "It must have picked it up somewhere.\p"
# 87 "data/maps/FortreeCity_House4/scripts.pory"
	.string "But I'm not a TRAINER, so you can\n"
# 88 "data/maps/FortreeCity_House4/scripts.pory"
	.string "have it.$"
# 89 "data/maps/FortreeCity_House4/scripts.pory"

# 90 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
# 91 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Thanks to my WINGULL, I have friends\n"
# 92 "data/maps/FortreeCity_House4/scripts.pory"
	.string "who live far away.$"
# 93 "data/maps/FortreeCity_House4/scripts.pory"

# 94 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_Wingull:
# 95 "data/maps/FortreeCity_House4/scripts.pory"
	.string "WINGULL: Pihyoh!$"
