ClassroomOpeningRight_MapScripts::
	.byte 0

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
