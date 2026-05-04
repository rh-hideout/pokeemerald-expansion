CliffEdgeCave_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "If you see a fork in the road\n"
	.string "inside a cave, most likely one\l"
	.string "way is right and the other leads\l"
	.string "to a dead end.\p"
	.string "but people can't help trying both.$"
