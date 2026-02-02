Klassenzimmer_SoEn_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Klassenzimmer_SoEn_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Klassenzimmer_SoEn_OnFrame
	.byte 0

Klassenzimmer_SoEn_OnTransition:
	goto_if_set FLAG_CTF_CLASSROOM_INTRO_DONE, Klassenzimmer_SoEn_OnTransition_End
	setvar VAR_TEMP_0, 0
	end

Klassenzimmer_SoEn_OnTransition_End:
	end

Klassenzimmer_SoEn_OnFrame:

	map_script_2 VAR_TEMP_0, 0, Klassenzimmer_SoEn_EventScript_FirstEntry

	map_script_2 VAR_TEMP_1, 0, Klassenzimmer_SoEn_EventScript_CheckStrengthToolScene
	.2byte 0


@ Erstes Betreten des Klassenzimmers
Klassenzimmer_SoEn_EventScript_FirstEntry::
	@ sofort "deaktivieren", damit es nicht mehrfach triggert
	setvar VAR_TEMP_0, 1
	setflag FLAG_CTF_CLASSROOM_APPLES_RASPBERRY

	lockall

	turnobject LOCALID_PROF_APPLES, DIR_SOUTH
	turnobject LOCALID_PLAYER, DIR_NORTH

	msgbox Klassenzimmer_SoEn_Text_ComeIn, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_PLAYER, Klassenzimmer_SoEn_Movement_PlayerToSeat
	waitmovement 0

	msgbox Klassenzimmer_SoEn_Text_Story, MSGBOX_DEFAULT
	closemessage

    msgbox Klassenzimmer_SoEn_Text_StudentReceivesPi, MSGBOX_DEFAULT
    closemessage

	giveitem ITEM_RASPBERRY_PI, 1

	@ Script freigeben bevor Warp
	releaseall
	end



Klassenzimmer_SoEn_EventScript_CheckStrengthToolScene::
	@ sofort "deaktivieren", damit Check nicht jeden Frame wieder anspringt
	@ (falls die Bedingungen nicht erfüllt sind, setzen wir es wieder auf 0)
	setvar VAR_TEMP_1, 1

	@ Nur wenn Server Tap done ist...
	goto_if_set FLAG_BLACKHANSA_SERVER_TAP_DONE, Klassenzimmer_SoEn_EventScript_StrengthToolScene_CheckDone

	@ Bedingungen nicht erfüllt -> Check nächstes Mal wieder erlauben
	setvar VAR_TEMP_1, 0
	end

Klassenzimmer_SoEn_EventScript_StrengthToolScene_CheckDone:
	@ ...und nur einmal insgesamt
	goto_if_set FLAG_CLASSROOM_STRENGTH_TOOL_SCENE_DONE, Klassenzimmer_SoEn_EventScript_StrengthToolScene_End

	goto Klassenzimmer_SoEn_EventScript_StrengthToolScene

Klassenzimmer_SoEn_EventScript_StrengthToolScene::
	lockall

	turnobject LOCALID_PROF_APPLES, DIR_SOUTH
	turnobject LOCALID_PLAYER, DIR_NORTH

	@ zuerst wieder zum Platz
	applymovement LOCALID_PLAYER, Klassenzimmer_SoEn_Movement_PlayerToSeat
	waitmovement 0

	@ bisschen blabla
	msgbox Klassenzimmer_SoEn_Text_StrengthTool_Blabla, MSGBOX_DEFAULT
	closemessage

	@ Tool geben
	giveitem ITEM_STRENGTH_TOOL, 1

	@ Gedankenstimme
	msgbox Klassenzimmer_SoEn_Text_StrengthTool_Thought, MSGBOX_DEFAULT
	closemessage

	@ Szene abschließen
	setflag FLAG_CLASSROOM_STRENGTH_TOOL_SCENE_DONE

	releaseall
	end

Klassenzimmer_SoEn_EventScript_StrengthToolScene_End:
	end


Klassenzimmer_SoEn_Movement_PlayerToSeat:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end


Klassenzimmer_SoEn_Text_StudentReceivesPi:
	.string "{PLAYER}: Wow! A Raspberry Pi! \n"
	.string "Thank you, Mister Apples!\p"
	.string "You received a Raspberry Pi!$"


Klassenzimmer_SoEn_Text_ComeIn:
	.string "{PLAYER}: Sorry, the train \n"
	.string "was late.$"

Klassenzimmer_SoEn_Text_Story:
	.string "APPLES: For today's project, we\n"
	.string "are using a Raspberry Pi. We will\p"
	.string "use it to program a small script\n"
	.string "that allows us to record data. The\p"
	.string "best script wins a Powerglove!$"



Klassenzimmer_SoEn_Text_StrengthTool_Blabla:
	.string "APPLES: Excellent work {PLAYER}.\n"
	.string "This is some interesting data.\p"
	.string "I really hope you didn't make\n"
	.string "something illegal.\p"
	.string "You received the POWERGLOVE.$"

Klassenzimmer_SoEn_Text_StrengthTool_Thought:
	.string "{PLAYER}: <This allows me to move the\n"
	.string "entrance to this cave on the Rhine-\p"
	.string "promenade. I should test it immediately!>$"


