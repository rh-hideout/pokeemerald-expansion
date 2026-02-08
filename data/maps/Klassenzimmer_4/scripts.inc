Klassenzimmer_4_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Klassenzimmer_4_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Klassenzimmer_4_OnFrame
    .byte 0

Klassenzimmer_4_OnTransition:
    @ default: nicht triggern
    setvar VAR_TEMP_0, 1

    @ wenn noch nicht passiert -> triggern
    goto_if_set FLAG_CTF_CLASSROOM_EARTHMAN_TUBE, 1f
    setvar VAR_TEMP_0, 0
1:
    end

Klassenzimmer_4_OnFrame:
    map_script_2 VAR_TEMP_0, 0, Klassenzimmer_4_EventScript_FirstEntry
    .2byte 0



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
	walk_left
	face_up
	step_end


Klassenzimmer_4_Text_StudentReceivesTube:
	.string "You received a SURFBOARD!$"


Klassenzimmer_4_Text_ComeIn:
	.string "{PLAYER}: <Fuck, I'm late \n"
	.string "today. Class is almost over.>$"

Klassenzimmer_4_Text_Story:
	.string "EARTHMAN: ... and because the\n"
	.string "weather is so beautiful today,\p"
	.string "I'll let you leave a few minutes\n"
	.string "early. You'll also all get this\p"
	.string "SURFBOARD from me, so you can\n"
	.string "float down the Rhine and maybe\p"
	.string "visit Ludwigshafen. Keep surfing\n"
	.string "and shaka brah!$"

