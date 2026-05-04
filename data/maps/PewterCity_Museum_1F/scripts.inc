.set LOCALID_MUSEUM_ROOTFOSSIL, 5
.set LOCALID_MUSEUM_CLAWFOSSIL, 6

PewterCity_Museum_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "Welcome!\p"
	.string "Just to let you know, all the large\n"
	.string "specimens have been taken to the\l"
	.string "other museums for display.\p"
	.string "So for now, admission is free of\n"
	.string "charge!\p"
	.string "Please go ahead.$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "You must be a strong trainer.\p"
	.string "We don't have much use for the\n"
	.string "fossils on the counter over there.\p"
	.string "A strange man with silver hair\n"
	.string "dropped a ton of them off here.\p"
	.string "Go ahead and take them if you like.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "We often share research with the\n"
	.string "RUINS OF ALPH researchers.\p"
	.string "We even share fossils with them\n"
	.string "through the PC!$"

PewterCity_Museum_1F_Text_Oldman:
	.string "I should be grateful for my long\n"
	.string "life.\p"
	.string "Never did I think I would get to\n"
	.string "see the bones of a dragon!$"

PewterCity_Museum_1F_Text_Bones:
	.string "Bones of an ancient dragon\n"
	.string "POKéMON.$"
