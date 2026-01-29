@ Spawn rechts 
#define ROCKET_SPAWN_X  19
#define JESSIE_SPAWN_Y  3
#define JAMES_SPAWN_Y   4

#define STUDENT_SPAWN_X 19
#define STUDENT_SPAWN_Y 5

@ Wo die Schülerin nach 3 Schritten links steht
#define STUDENT_END_X   16
#define STUDENT_END_Y   5


Museum_Flag1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Museum_Flag1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Museum_Flag1_OnFrame
	.byte 0


Museum_Flag1_OnTransition:
	@ Türzustand anwenden ist ok im Transition
	goto_if_set FLAG_CTF_MUSEUM_DOOR_OPEN, Museum_Flag1_ApplyDoorOnLoad

	@ Cutscene nur “armen”, NICHT starten
	goto_if_set FLAG_CTF_MUSEUM_SCENE_PENDING, Museum_Flag1_ArmScene
	end

Museum_Flag1_ApplyDoorOnLoad:
	call Museum_Flag1_EventScript_ApplyDoorOpen
	goto_if_set FLAG_CTF_MUSEUM_SCENE_PENDING, Museum_Flag1_ArmScene
	end

Museum_Flag1_ArmScene:
	setvar VAR_TEMP_1, 0
	end


Museum_Flag1_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Museum_Flag1_EventScript_RocketCutscene
	.2byte 0


Museum_Flag1_EventScript_RocketCutscene::
	@ sofort deaktivieren
	setvar VAR_TEMP_1, 1
	clearflag FLAG_CTF_MUSEUM_SCENE_PENDING

	lockall

	@ Spieler soll nach dem Teleport nach oben schauen
	turnobject LOCALID_PLAYER, DIR_NORTH

	msgbox Museum_Flag1_Text_FarmerMess, MSGBOX_DEFAULT
	closemessage

	@ Rockets sichtbar machen + sofort spawnen
	clearflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
	clearflag FLAG_HIDE_MUSEUM_FLAG1_JAMES
	addobject LOCALID_MUSEUM_JESSIE
	addobject LOCALID_MUSEUM_JAMES

	setobjectxy LOCALID_MUSEUM_JESSIE, 19, 3
	setobjectxy LOCALID_MUSEUM_JAMES,  19, 4

	turnobject LOCALID_MUSEUM_JESSIE, DIR_WEST
	turnobject LOCALID_MUSEUM_JAMES,  DIR_WEST
	turnobject LOCALID_PLAYER, DIR_EAST

	applymovement LOCALID_MUSEUM_JESSIE, Museum_Flag1_Movement_RocketEnter
	applymovement LOCALID_MUSEUM_JAMES,  Museum_Flag1_Movement_RocketEnter
	waitmovement 0

	msgbox Museum_Flag1_Text_RocketDialog, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_MUSEUM_JESSIE, Museum_Flag1_Movement_RocketLeave
	applymovement LOCALID_MUSEUM_JAMES,  Museum_Flag1_Movement_RocketLeave
	waitmovement 0

	@ verschwinden + dauerhaft verstecken
	setflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
	setflag FLAG_HIDE_MUSEUM_FLAG1_JAMES
	removeobject LOCALID_MUSEUM_JESSIE
	removeobject LOCALID_MUSEUM_JAMES

	@ Student sichtbar machen + sofort spawnen
	clearflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
	addobject LOCALID_MUSEUM_STUDENT
	setobjectxy LOCALID_MUSEUM_STUDENT, 19, 3
	turnobject LOCALID_MUSEUM_STUDENT, DIR_WEST

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


Museum_Flag1_EventScript_Terminal::
	lock
	faceplayer

	goto_if_set FLAG_CTF_MUSEUM_DOOR_OPEN, Museum_Flag1_Terminal_AlreadyOpen

	msgbox Museum_Flag1_Text_TerminalPrompt, MSGBOX_DEFAULT
	closemessage

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
	call Museum_Flag1_EventScript_ApplyDoorOpen
	special DrawWholeMapView

	release
	end


Museum_Flag1_EventScript_ApplyDoorOpen::

	setmetatile 9,  0, 0x0261, FALSE    @ oben links
	setmetatile 10,  0, 0x0207, FALSE   @ oben mitte
	setmetatile 11,  0, 0x0257, FALSE   @ oben rechts

	setmetatile 9,  1, 0x0262, FALSE    @ unten links
	setmetatile 10,  1, 0x020F, FALSE   @ unten mitte (Warp)
	setmetatile 11,  1, 0x025F, FALSE   @ unten rechts
	return


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