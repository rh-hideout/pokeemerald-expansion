Klassenzimmer_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Klassenzimmer_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Klassenzimmer_OnFrame
	.byte 0

Klassenzimmer_OnTransition:
	@ OnTransition nur vorbereiten – keine msgbox/Bewegung hier!
	goto_if_set FLAG_CTF_CLASSROOM_INTRO_DONE, Klassenzimmer_OnTransition_End
	setvar VAR_TEMP_0, 0
	end

Klassenzimmer_OnTransition_End:
	end

Klassenzimmer_OnFrame:
	@ Cutscene läuft erst im Frame-Loop, wenn Map sichtbar ist
	map_script_2 VAR_TEMP_0, 0, Klassenzimmer_EventScript_FirstEntry
	.2byte 0


@ Erstes Betreten des Klassenzimmers
Klassenzimmer_EventScript_FirstEntry::
	@ sofort "deaktivieren", damit es nicht mehrfach triggert
	setvar VAR_TEMP_0, 1
	setflag FLAG_CTF_CLASSROOM_INTRO_DONE

	lockall

	turnobject LOCALID_PROF_FARMER, DIR_SOUTH
	turnobject LOCALID_PLAYER, DIR_NORTH

	msgbox Klassenzimmer_Text_Welcome, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_PLAYER, Klassenzimmer_Movement_PlayerToSeat
	waitmovement 0

	msgbox Klassenzimmer_Text_Museum, MSGBOX_DEFAULT
	closemessage

	@ Museum-Cutscene beim Ankommen starten lassen
	setflag FLAG_CTF_MUSEUM_SCENE_PENDING

	@ Rocket + Schülerin beim Laden verstecken
	setflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
	setflag FLAG_HIDE_MUSEUM_FLAG1_JAMES
	setflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT

	@ Script freigeben bevor Warp (robuster)
	releaseall

	@ Warp per Koordinate (dein Branch kann 255 offenbar)
	warp MAP_MUSEUM_FLAG1, 255, 17, 6
	end


Klassenzimmer_Movement_PlayerToSeat:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end


Klassenzimmer_Text_Welcome:
	.string "Ahh {PLAYER}, we waited\n"
	.string "especially for you.$"

Klassenzimmer_Text_Museum:
	.string "PRO. FARMER: Today we will\n"
	.string "visit the museum...\p"
	.string "(Platzhaltertext)$"
