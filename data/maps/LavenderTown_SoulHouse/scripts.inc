LavenderTown_SoulHouse_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "MR.FUJI: Welcome.\p"
	.string "Hmm… You appear to be raising\n"
	.string "your POKéMON in a kind and\l"
	.string "loving manner.\p"
	.string "POKéMON lovers come here to pay\n"
	.string "their respects to departed\l"
	.string "POKéMON.\p"
	.string "Please offer condolences for the\n"
	.string "souls of the departed POKéMON.\p"
	.string "I'm sure that will make them\n"
	.string "happy.$"

SoulHouse_Text_Teacher:
	.string "There are other graves of POKéMON\n"
	.string "here, I think.\p"
	.string "There are many chambers that only\n"
	.string "MR.FUJI may enter.$"

SoulHouse_Text_Lass:
	.string "I came with my mom to visit\n"
	.string "POKéMON graves…$"

SoulHouse_Text_Granny:
	.string "The POKéMON that lived with me…\p"
	.string "I loved them like my\n"
	.string "grandchildren…$"
