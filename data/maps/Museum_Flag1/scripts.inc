@ Spawn rechts 
#define ROCKET_SPAWN_X  19
#define JESSIE_SPAWN_Y  3
#define JAMES_SPAWN_Y   4

#define STUDENT_SPAWN_X 19
#define STUDENT_SPAWN_Y 5

@ Wo die Schülerin nach 3 Schritten links steht
#define STUDENT_END_X   16
#define STUDENT_END_Y   3


Museum_Flag1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Museum_Flag1_OnTransition
	.byte 0


Museum_Flag1_OnTransition:
	@ Tür dauerhaft anwenden, falls schon geöffnet
	goto_if_set FLAG_CTF_MUSEUM_DOOR_OPEN, Museum_Flag1_ApplyDoorOnLoad

Museum_Flag1_CheckScene:
	@ Wenn Cutscene schon vorbei ist: Student korrekt positionieren
	goto_if_set FLAG_CTF_MUSEUM_ROCKET_SCENE_DONE, Museum_Flag1_PostSceneState

	@ Cutscene nur starten, wenn sie vom Klassenzimmer "pending" gesetzt wurde
	goto_if_set FLAG_CTF_MUSEUM_SCENE_PENDING, Museum_Flag1_EventScript_RocketCutscene
	end

Museum_Flag1_ApplyDoorOnLoad:
	call Museum_Flag1_EventScript_ApplyDoorOpen
	goto Museum_Flag1_CheckScene

Museum_Flag1_PostSceneState:
	@ Student sichtbar lassen und an Endposition setzen
	clearflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
	setobjectxy LOCALID_MUSEUM_STUDENT, STUDENT_END_X, STUDENT_END_Y
	end


@ --------------------------------------------------------------------------
@ CUTSCENE nach dem Teleport
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_RocketCutscene::
	clearflag FLAG_CTF_MUSEUM_SCENE_PENDING

	lockall

	msgbox Museum_Flag1_Text_FarmerMess, MSGBOX_DEFAULT
	closemessage

	@ Rockets sichtbar machen + Position setzen
	clearflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
	clearflag FLAG_HIDE_MUSEUM_FLAG1_JAMES

	setobjectxy LOCALID_MUSEUM_JESSIE, ROCKET_SPAWN_X, JESSIE_SPAWN_Y
	setobjectxy LOCALID_MUSEUM_JAMES,  ROCKET_SPAWN_X, JAMES_SPAWN_Y

	turnobject LOCALID_MUSEUM_JESSIE, DIR_LEFT
	turnobject LOCALID_MUSEUM_JAMES,  DIR_LEFT
	turnobject LOCALID_PLAYER, DIR_RIGHT

	@ 3 Felder nach links reinlaufen
	applymovement LOCALID_MUSEUM_JESSIE, Museum_Flag1_Movement_RocketEnter
	applymovement LOCALID_MUSEUM_JAMES,  Museum_Flag1_Movement_RocketEnter
	waitmovement 0

	msgbox Museum_Flag1_Text_RocketDialog, MSGBOX_DEFAULT
	closemessage

	@ wieder nach rechts raus
	applymovement LOCALID_MUSEUM_JESSIE, Museum_Flag1_Movement_RocketLeave
	applymovement LOCALID_MUSEUM_JAMES,  Museum_Flag1_Movement_RocketLeave
	waitmovement 0

	@ verschwinden
	setflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
	setflag FLAG_HIDE_MUSEUM_FLAG1_JAMES
	removeobject LOCALID_MUSEUM_JESSIE
	removeobject LOCALID_MUSEUM_JAMES

	@ Schülerin rein
	clearflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
	setobjectxy LOCALID_MUSEUM_STUDENT, STUDENT_SPAWN_X, STUDENT_SPAWN_Y
	turnobject LOCALID_MUSEUM_STUDENT, DIR_LEFT

	applymovement LOCALID_MUSEUM_STUDENT, Museum_Flag1_Movement_StudentEnter
	waitmovement 0

	msgbox Museum_Flag1_Text_StudentDialog, MSGBOX_DEFAULT
	closemessage

	setflag FLAG_CTF_MUSEUM_ROCKET_SCENE_DONE

	releaseall
	end


Museum_Flag1_Movement_RocketEnter:
	walk_left
	walk_left
	walk_left
	step_end

Museum_Flag1_Movement_RocketLeave:
	walk_right
	walk_right
	walk_right
	step_end

Museum_Flag1_Movement_StudentEnter:
	walk_left
	walk_left
	walk_left
	step_end


@ --------------------------------------------------------------------------
@ TERMINAL: Gym 1 Flag prüfen (VAR_0x8000 = 1 -> "SLEEP")
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_Terminal::
	lock
	faceplayer

	goto_if_set FLAG_CTF_MUSEUM_DOOR_OPEN, Museum_Flag1_Terminal_AlreadyOpen

	msgbox Museum_Flag1_Text_TerminalPrompt, MSGBOX_DEFAULT
	closemessage

	@ Gym 1 = 1
	setvar VAR_0x8000, 1
	callnative Ctf_FlagTerminal
	waitstate

	goto_if_eq VAR_RESULT, 1, Museum_Flag1_Terminal_Correct
	goto Museum_Flag1_Terminal_Wrong


Museum_Flag1_Terminal_Wrong:
	msgbox Museum_Flag1_Text_TerminalWrong, MSGBOX_DEFAULT
	release
	end

Museum_Flag1_Terminal_AlreadyOpen:
	msgbox Museum_Flag1_Text_TerminalAlreadyOpen, MSGBOX_DEFAULT
	release
	end

Museum_Flag1_Terminal_Correct:
	msgbox Museum_Flag1_Text_TerminalCorrect, MSGBOX_DEFAULT
	closemessage

	setflag FLAG_CTF_MUSEUM_DOOR_OPEN

	@ 3x2 Tür in die Wand setzen
	call Museum_Flag1_EventScript_ApplyDoorOpen
	special DrawWholeMapView

	release
	end


@ --------------------------------------------------------------------------
@ TÜR 3x2 METATILES setzen (DEINE WERTE)
@ Top-Left: (0,9)
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_ApplyDoorOpen::
	setmetatile 0,  9, 0x0261, FALSE   @ oben links
	setmetatile 1,  9, 0x0207, FALSE   @ oben mitte
	setmetatile 2,  9, 0x0257, FALSE   @ oben rechts

	setmetatile 0, 10, 0x0262, FALSE   @ unten links
	setmetatile 1, 10, 0x020F, FALSE   @ unten mitte (HIER Warp in Porymap!)
	setmetatile 2, 10, 0x025F, FALSE   @ unten rechts

	return


@ --------------------------------------------------------------------------
@ TEXTE
@ --------------------------------------------------------------------------
Museum_Flag1_Text_FarmerMess:
	.string "PROF. FARMER: What's all\n"
	.string "this mess?$"

Museum_Flag1_Text_RocketDialog:
	.string "JESSIE: Prepare for trouble!\n"
	.string "JAMES: And make it double!\p"
	.string "PROF. FARMER: Cut that crap\n"
	.string "who are you?\p"
	.string "JESSIE: How rude!\p"
	.string "JAMES: We are TEAM ROCKET and\n"
	.string "we have stolen your XXX.\p"
	.string "JESSIE: See ya losers!$"

Museum_Flag1_Text_StudentDialog:
	.string "They've barricaded the door.\n"
	.string "How are we going to get out\n"
	.string "of here?$"

Museum_Flag1_Text_TerminalPrompt:
	.string "TERMINAL: Enter the code.$"

Museum_Flag1_Text_TerminalWrong:
	.string "TERMINAL: Access denied.$"

Museum_Flag1_Text_TerminalCorrect:
	.string "TERMINAL: Code accepted.\n"
	.string "Opening hidden door...$"

Museum_Flag1_Text_TerminalAlreadyOpen:
	.string "TERMINAL: Door already opened.$"
