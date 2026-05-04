CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "You'll run into many trainers on\n"
	.string "the way to CERULEAN's CAPE.\p"
	.string "They want to see how they stack\n"
	.string "up against other trainers.$"

CeruleanMart_Text_CooltrainerF:
	.string "MISTY is about the only person in\n"
	.string "town who can beat the trainers at\l"
	.string "CERULEAN's CAPE.$"
