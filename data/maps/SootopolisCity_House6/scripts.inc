# 1 "data/maps/SootopolisCity_House6/scripts.pory"

# 2 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_MapScripts::
# 3 "data/maps/SootopolisCity_House6/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_House6/scripts.pory"

# 5 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_EventScript_Woman::
# 6 "data/maps/SootopolisCity_House6/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_House6/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_House6/scripts.pory"
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
# 9 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
# 10 "data/maps/SootopolisCity_House6/scripts.pory"
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
# 11 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
# 12 "data/maps/SootopolisCity_House6/scripts.pory"
	givedecoration DECOR_WAILMER_DOLL
# 13 "data/maps/SootopolisCity_House6/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
# 14 "data/maps/SootopolisCity_House6/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_DOLL
# 15 "data/maps/SootopolisCity_House6/scripts.pory"
	release
# 16 "data/maps/SootopolisCity_House6/scripts.pory"
	end
# 17 "data/maps/SootopolisCity_House6/scripts.pory"

# 18 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_EventScript_DeclineWailmerDoll::
# 19 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
# 20 "data/maps/SootopolisCity_House6/scripts.pory"
	release
# 21 "data/maps/SootopolisCity_House6/scripts.pory"
	end
# 22 "data/maps/SootopolisCity_House6/scripts.pory"

# 23 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
# 24 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
# 25 "data/maps/SootopolisCity_House6/scripts.pory"
	release
# 26 "data/maps/SootopolisCity_House6/scripts.pory"
	end
# 27 "data/maps/SootopolisCity_House6/scripts.pory"

# 28 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
# 29 "data/maps/SootopolisCity_House6/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
# 30 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
# 31 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
# 32 "data/maps/SootopolisCity_House6/scripts.pory"
	release
# 33 "data/maps/SootopolisCity_House6/scripts.pory"
	end
# 34 "data/maps/SootopolisCity_House6/scripts.pory"

# 35 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
# 36 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Hello! You're our first guest in\n"
# 37 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "a good while.\p"
# 38 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "You've brightened up my day, so I'll\n"
# 39 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "give you a big WAILMER DOLL.$"
# 40 "data/maps/SootopolisCity_House6/scripts.pory"

# 41 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_TakeGoodCareOfIt:
# 42 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Take good care of it!$"
# 43 "data/maps/SootopolisCity_House6/scripts.pory"

# 44 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_IllHoldItForYou:
# 45 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Oh, you want it, but not right now?\n"
# 46 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Okay, then I'll hold it for you.$"
# 47 "data/maps/SootopolisCity_House6/scripts.pory"

# 48 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_DontWantThisDoll:
# 49 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Are you sure?\n"
# 50 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "You don't want this DOLL?$"
# 51 "data/maps/SootopolisCity_House6/scripts.pory"

# 52 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_LovePlushDolls:
# 53 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "I love plush DOLLS!$"
