ClassroomOpeninTop_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ClassroomOpeninTop_OnLoad
	.byte 0

ClassroomOpeninTop_OnLoad:
	call ClassroomOpeninTop_EventScript_CountVisit
	end

ClassroomOpeninTop_EventScript_CountVisit::
	goto_if_ge VAR_CTF_CLASSROOM_TOP_VISITS, 2, ClassroomOpeninTop_EventScript_CountVisitEnd
	addvar VAR_CTF_CLASSROOM_TOP_VISITS, 1
ClassroomOpeninTop_EventScript_CountVisitEnd::
	return

ClassroomOpeninTop_EventScript_Stasher::
	lock
	faceplayer
	msgbox ClassroomOpeninTop_Text_Stasher, MSGBOX_DEFAULT
	release
	end

ClassroomOpeninTop_Text_Stasher:
	.string "The DHBW doesn't even lock this stuff up.\p"
	.string "I grabbed one and dumped it into\n"
	.string "the corner.\p"
	.string "If you're desperate, it's yours.$"
