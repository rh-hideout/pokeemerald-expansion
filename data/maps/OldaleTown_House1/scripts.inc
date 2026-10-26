OldaleTown_House1_MapScripts::
	.byte 0


OldaleTown_House1_EventScript_Woman::
# 7 "data/maps/OldaleTown_House1/scripts.pory"
	lock
# 8 "data/maps/OldaleTown_House1/scripts.pory"
	faceplayer
# 11 "data/maps/OldaleTown_House1/scripts.pory"
	goto_if_set FLAG_UNUSED_0x020, OldaleTown_House1_EventScript_Woman_2
# 14 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox OldaleTown_House1_EventScript_Woman_Text_1, MSGBOX_YESNO
# 15 "data/maps/OldaleTown_House1/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq OldaleTown_House1_EventScript_Woman_5
# 20 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox OldaleTown_House1_EventScript_Woman_Text_3
OldaleTown_House1_EventScript_Woman_1:
# 23 "data/maps/OldaleTown_House1/scripts.pory"
	release
	return

OldaleTown_House1_EventScript_Woman_2:
# 12 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox OldaleTown_House1_EventScript_Woman_Text_0
	goto OldaleTown_House1_EventScript_Woman_1

OldaleTown_House1_EventScript_Woman_5:
# 16 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox OldaleTown_House1_EventScript_Woman_Text_2
# 17 "data/maps/OldaleTown_House1/scripts.pory"
	giveitem ITEM_POTION
# 18 "data/maps/OldaleTown_House1/scripts.pory"
	setflag FLAG_UNUSED_0x020
	goto OldaleTown_House1_EventScript_Woman_1


OldaleTown_House1_EventScript_Woman_Text_0:
# 12 "data/maps/OldaleTown_House1/scripts.pory"
	.string "When a POKéMON battle starts, the one\n"
	.string "at the left of the list goes out first.\p"
	.string "So, try switching around the order of\n"
	.string "your POKéMON.$"

OldaleTown_House1_EventScript_Woman_Text_1:
# 14 "data/maps/OldaleTown_House1/scripts.pory"
	.string "Oh, a new TRAINER! Are you just\n"
	.string "starting out on your journey?$"

OldaleTown_House1_EventScript_Woman_Text_2:
# 16 "data/maps/OldaleTown_House1/scripts.pory"
	.string "How exciting! Here, take this. It'll help\n"
	.string "in a pinch.$"

OldaleTown_House1_EventScript_Woman_Text_3:
# 20 "data/maps/OldaleTown_House1/scripts.pory"
	.string "A seasoned TRAINER, then! Good luck\n"
	.string "out there.$"
