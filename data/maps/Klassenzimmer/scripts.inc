Klassenzimmer_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Klassenzimmer_OnTransition
	.byte 0


Klassenzimmer_OnTransition:
	goto_if_set FLAG_CTF_CLASSROOM_INTRO_DONE, Klassenzimmer_OnTransition_End
	goto Klassenzimmer_EventScript_FirstEntry

Klassenzimmer_OnTransition_End:
	end


@ Erstes Betreten des Klassenzimmers (Flag 1)
Klassenzimmer_EventScript_FirstEntry::
	@ sofort setzen => garantiert nur beim ersten Betreten
	setflag FLAG_CTF_CLASSROOM_INTRO_DONE

	lockall

	turnobject LOCALID_PROF_FARMER, DIR_DOWN
	turnobject LOCALID_PLAYER, DIR_UP

	msgbox Klassenzimmer_Text_Welcome, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_PLAYER, Klassenzimmer_Movement_PlayerToSeat
	waitmovement 0

	msgbox Klassenzimmer_Text_Museum, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	waitfadescreen

	@ Museum-Cutscene beim Ankommen starten lassen
    setflag FLAG_CTF_MUSEUM_SCENE_PENDING

    @ Rocket + Schülerin beim Laden verstecken
    setflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
    setflag FLAG_HIDE_MUSEUM_FLAG1_JAMES
    setflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT

	@ Zielmap: data/maps/Museum_Flag1
	warp MAP_MUSEUM_FLAG1, 255, 17, 6
	waitstate

	fadescreen FADE_FROM_BLACK
	waitfadescreen

	releaseall
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
