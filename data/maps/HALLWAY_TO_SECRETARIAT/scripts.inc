HALLWAY_TO_SECRETARIAT_MapScripts::
	.byte 0

HALLWAY_TO_SECRETARIAT_EventScript_LostStudent::
	lock
	faceplayer
	msgbox HALLWAY_TO_SECRETARIAT_Text_LostStudent, MSGBOX_DEFAULT
	release
	end

HALLWAY_TO_SECRETARIAT_Text_LostStudent:
	.string "I still get lost in here.\p"
	.string "Every corridor looks the same.$"
