Gate_AzaleaTown_IlexForest_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "ILEX FOREST is big.\n"
	.string "Be careful!\n"
	.string "Don't get lost.$"

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "The ILEX FOREST is watched\n"
	.string "over by its protector.\p"
	.string "Stay out of mischief!$"
