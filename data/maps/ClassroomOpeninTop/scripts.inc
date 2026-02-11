ClassroomOpeninTop_MapScripts::
	.byte 0

ClassroomOpeninTop_EventScript_Stasher::
	lock
	faceplayer
	msgbox ClassroomOpeninTop_Text_Stasher, MSGBOX_DEFAULT
	release
	end

ClassroomOpeninTop_Text_Stasher:
	.string "The DHBW doesn't even lock this stuff up.\p"
	.string "I grabbed one and dumped it into the corner.\p"
	.string "If you're desperate, it's yours.$"
