SaffronCity_House1_MapScripts::
	.byte 0

SaffronCity_House1_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_PSYCHIC, SaffronCity_House1_EventScript_MrPsychicAfter
	msgbox MrPsychic_Text_1, MSGBOX_NPC
	giveitem ITEM_TM_PSYCHIC
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	setflag FLAG_GOT_TM_PSYCHIC
	release
	end

SaffronCity_House1_EventScript_MrPsychicAfter::
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	end

MrPsychic_Text_1:
	.string "…\p"
	.string "…\p"
	.string "…\p"
	.string "…I got it!\p"
	.string "You wanted this!$"

MrPsychic_Text_2:
	.string "TM29 is PSYCHIC.\p"
	.string "It may lower the target's\n"
	.string "SPCL.DEF.$"
