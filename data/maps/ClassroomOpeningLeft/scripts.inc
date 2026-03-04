ClassroomOpeningLeft_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ClassroomOpeningLeft_OnLoad
	.byte 0

ClassroomOpeningLeft_OnLoad:
	call ClassroomOpeningLeft_EventScript_CountVisit
	end

ClassroomOpeningLeft_EventScript_CountVisit::
	goto_if_ge VAR_CTF_CLASSROOM_LEFT_VISITS, 2, ClassroomOpeningLeft_EventScript_CountVisitEnd
	addvar VAR_CTF_CLASSROOM_LEFT_VISITS, 1
ClassroomOpeningLeft_EventScript_CountVisitEnd::
	return

ClassroomOpeningLeft_EventScript_ComplainingStudent::
	lock
	msgbox ClassroomOpeningLeft_Text_ComplainingStudent, MSGBOX_DEFAULT
	release
	end

ClassroomOpeningLeft_Text_ComplainingStudent:
	.string "This thing never works...\p"
	.string "But when I push it to three, \n"
	.string	 "it feels closer.\p"
	.string "...Hey.\p"
	.string "Are you listening to me?$"
