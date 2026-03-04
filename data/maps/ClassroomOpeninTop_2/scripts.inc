ClassroomOpeninTop_2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ClassroomOpeninTop_2_OnLoad
	.byte 0

ClassroomOpeninTop_2_OnLoad:
	call ClassroomOpeninTop_2_EventScript_CountVisit
	end

ClassroomOpeninTop_2_EventScript_CountVisit::
	goto_if_ge VAR_CTF_CLASSROOM_TOP2_VISITS, 2, ClassroomOpeninTop_2_EventScript_CountVisitEnd
	addvar VAR_CTF_CLASSROOM_TOP2_VISITS, 1
ClassroomOpeninTop_2_EventScript_CountVisitEnd::
	return

ClassroomOpeninTop_2_EventScript_OldFeel::
	lock
	faceplayer
	msgbox ClassroomOpeninTop_2_Text_OldFeel, MSGBOX_DEFAULT
	release
	end

ClassroomOpeninTop_2_Text_OldFeel:
	.string "I swear, every time\n"
	.string "I think I understand this place…\p"
	.string "It proves me wrong.$"
