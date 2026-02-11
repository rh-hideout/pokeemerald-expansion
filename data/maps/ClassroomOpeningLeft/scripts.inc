ClassroomOpeningLeft_MapScripts::
	.byte 0

ClassroomOpeningLeft_EventScript_ComplainingStudent::
	lock
	msgbox ClassroomOpeningLeft_Text_ComplainingStudent, MSGBOX_DEFAULT
	release
	end

ClassroomOpeningLeft_Text_ComplainingStudent:
	.string "This thing never works...\p"
	.string "But when I push it to three, it feels closer.\p"
	.string "...Hey.\p"
	.string "Are you listening to me?$"
