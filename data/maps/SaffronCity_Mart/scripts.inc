SaffronCity_Mart_MapScripts::
	.byte 0

SafronMart_EventScript_CooltrainerM::
	msgbox SaffronMart_Text_CooltrainerM, MSGBOX_NPC
	end
SafronMart_EventScript_CooltrainerF::
	msgbox SaffronMart_Text_CooltrainerF, MSGBOX_NPC
	end
SaffronMart_Text_CooltrainerM:
	.string "There's a big RADIO TOWER in\n"
	.string "LAVENDER.$"

SaffronMart_Text_CooltrainerF:
	.string "I want to become stronger, but\n"
	.string "I'm not good yet…\p"
	.string "Could you show me how sometime?$"
