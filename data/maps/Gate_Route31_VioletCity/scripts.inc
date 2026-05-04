Gate_Route31_VioletCity_MapScripts::
	.byte 0

Gate_Route31_VioletCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_Text_Policeman:
	.string "Hi there! Did you visit\n"
	.string "SPROUT TOWER?$"

Gate_Route31_VioletCity_Text_CooltrainerF:
	.string "I saw the cutest POKéMON out\n"
	.string "there.\p"
	.string "It looked a lot like PIKACHU!$"
