ClassroomOpeningRight_2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ClassroomOpeningRight_2_OnLoad
	.byte 0

ClassroomOpeningRight_2_OnLoad:
	call ClassroomOpeningRight_2_EventScript_CountVisit
	end

ClassroomOpeningRight_2_EventScript_CountVisit::
	goto_if_ge VAR_CTF_CLASSROOM_RIGHT2_VISITS, 2, ClassroomOpeningRight_2_EventScript_CountVisitEnd
	addvar VAR_CTF_CLASSROOM_RIGHT2_VISITS, 1
ClassroomOpeningRight_2_EventScript_CountVisitEnd::
	return

ClassroomOpeningRight_2_EventScript_WaitingFriend::
	lock
	faceplayer
	msgbox ClassroomOpeningRight_2_Text_WaitingFriend, MSGBOX_DEFAULT
	release
	end

ClassroomOpeningRight_2_Text_WaitingFriend:
	.string "I'm just waiting for a friend.\p"
	.string "This building feels way too quiet today.$"
