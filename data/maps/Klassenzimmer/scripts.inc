Klassenzimmer_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Klassenzimmer_OnTransition
	.byte 0


Klassenzimmer_OnTransition:
	goto_if_set FLAG_CTF_CLASSROOM_INTRO_DONE, Klassenzimmer_OnTransition_End
	goto Klassenzimmer_EventScript_FirstEntry

Klassenzimmer_OnTransition_End:
	end


Klassenzimmer_EventScript_FirstEntry::
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

	@ WICHTIG: Kein fadescreen/waitstate hier -> verhindert Black-Screen-Hänger
	releaseall

	@ Warp-ID 1 = der neue Entry-Warp in Museum_Flag1 bei (17,6)
	warp MAP_MUSEUM_FLAG1, 1, 0, 0
	end



Klassenzimmer_Movement_PlayerToSeat:
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
