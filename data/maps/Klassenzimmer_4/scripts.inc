Klassenzimmer_4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Klassenzimmer_4_OnTransition
	.byte 0

Klassenzimmer_4_OnTransition:
	goto_if_set FLAG_CTF_CLASSROOM_INTRO_DONE, Klassenzimmer_4_OnTransition_End
	setvar VAR_TEMP_0, 0
	end

Klassenzimmer_4_OnTransition_End:
	end


@ Erstes Betreten des Klassenzimmers
Klassenzimmer_4_EventScript_FirstEntry::
	@ sofort "deaktivieren", damit es nicht mehrfach triggert
	setvar VAR_TEMP_0, 1
	setflag FLAG_CTF_CLASSROOM_EARTHMAN_TUBE

	lockall

	turnobject LOCALID_PROF_APPLES, DIR_SOUTH
	turnobject LOCALID_PLAYER, DIR_NORTH

	msgbox Klassenzimmer_4_Text_ComeIn, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_PLAYER, Klassenzimmer_4_Movement_PlayerToSeat
	waitmovement 0

	msgbox Klassenzimmer_4_Text_Story, MSGBOX_DEFAULT
	closemessage

    msgbox Klassenzimmer_4_Text_StudentReceivesTube, MSGBOX_DEFAULT
    closemessage

	giveitem ITEM_SURF_TOOL, 1

	@ Script freigeben bevor Warp
	releaseall
	end


Klassenzimmer_4_Movement_PlayerToSeat:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end


Klassenzimmer_4_Text_StudentReceivesTube:
	.string "You received a LAPRAS TUBE!$"


Klassenzimmer_4_Text_ComeIn:
	.string "{PLAYER}: <Fuck, I'm late \n"
	.string "today. Class is almost over.>$"

Klassenzimmer_4_Text_Story:
	.string "EARTHMAN: ... and because the\n"
	.string "weather is so beautiful today,\p"
	.string "I'll let you leave a few minutes\n"
	.string "early. You'll also all get this\p"
	.string "Lapras Tube from me, so you can\n"
	.string "float down the Rhine and maybe\p"
	.string "visit Ludwigshafen. Keep surfing\n"
	.string "and shaka brah!$"

