MahoganyTown_House1_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 10, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
    .string "I heard that a red GYARADOS appeared\n"
    .string "at the LAKE.\p"
    .string "That's odd, since even ordinary\n"
    .string "GYARADOS are rare in that lake…$"

MahoganyRedGyaradosHouse_Text_Teacher:
    .string "My favorite radio program? I'd say\n"
    .string "POKéMON MUSIC.$"

MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
    .string "I've been hearing laughter on the\n"
    .string "radio…\p"
    .string "It's creepy.$"
