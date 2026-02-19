ClassroomOpeningLeft_2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ClassroomOpeningLeft_2_OnLoad
	.byte 0

ClassroomOpeningLeft_2_OnLoad:
	call ClassroomOpeningLeft_2_EventScript_CountVisit
	end

ClassroomOpeningLeft_2_EventScript_CountVisit::
	goto_if_ge VAR_CTF_CLASSROOM_LEFT2_VISITS, 2, ClassroomOpeningLeft_2_EventScript_CountVisitEnd
	addvar VAR_CTF_CLASSROOM_LEFT2_VISITS, 1
ClassroomOpeningLeft_2_EventScript_CountVisitEnd::
	return

ClassroomOpeningLeft_2_EventScript_Storyteller::
	lock
	faceplayer
	msgbox ClassroomOpeningLeft_2_Text_Storyteller, MSGBOX_DEFAULT
	release
	end

ClassroomOpeningLeft_2_Text_Storyteller:
	.string "There's this old story about the DHBW.\p"
	.string "They say matriculation numbers\naren't random at all.\p"
	.string "Something about an old method\nthey never replaced.$"

ClassroomOpeningLeft_2_EventScript_OldFeel::
	lock
	faceplayer
	msgbox ClassroomOpeningLeft_2_Text_OldFeel, MSGBOX_DEFAULT
	release
	end

ClassroomOpeningLeft_2_Text_OldFeel:
	.string "You ever notice\n"
	.string "how old this place feels?\p"
	.string "Like it's been running the same way\n"
	.string "forever.$"
