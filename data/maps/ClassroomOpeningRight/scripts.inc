ClassroomOpeningRight_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ClassroomOpeningRight_OnLoad
	.byte 0

ClassroomOpeningRight_OnLoad:
	call ClassroomOpeningRight_EventScript_CountVisit
	end

ClassroomOpeningRight_EventScript_CountVisit::
	goto_if_ge VAR_CTF_CLASSROOM_RIGHT_VISITS, 2, ClassroomOpeningRight_EventScript_CountVisitEnd
	addvar VAR_CTF_CLASSROOM_RIGHT_VISITS, 1
ClassroomOpeningRight_EventScript_CountVisitEnd::
	return

ClassroomOpeningRight_EventScript_Guy1::
	lock
	msgbox ClassroomOpeningRight_Text_Guy1, MSGBOX_DEFAULT
	release
	end

ClassroomOpeningRight_EventScript_Guy2::
	lock
	msgbox ClassroomOpeningRight_Text_Guy2, MSGBOX_DEFAULT
	release
	end

ClassroomOpeningRight_Text_Guy1:
	.string "Guy 1:\p"
	.string "I'm telling you, I've tried every number.\p"
	.string "I don't know.\p"
	.string "When I land on five, it almost lets me in.$"

ClassroomOpeningRight_Text_Guy2:
	.string "Guy 2:\p"
	.string "And?\p"
	.string "Almost doesn't count.\p"
	.string "Stop talking. Someone's here.$"
