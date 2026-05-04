CliffEdgeGate_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "Did you know? There's a SAFARI ZONE\n"
	.string "just around the corner.\p"
	.string "It's really fun!\n"
	.string "You will see many different kinds of\l"
	.string "POKéMON, and it's all you can catch!\p"
	.string "There is no reason not to go, right?\n"
	.string "Just around the corner.$"

CliffEdgeGate_Text_Expectations:
	.string "I appreciate that everybody is looking\n"
	.string "forward to it.\p"
	.string "But the lady at the reception seems\n"
	.string "a bit too dramatic...\p"
	.string "Don't get your expectations too high!$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "Everything Is Thrilling!\n"
	.string "Explore to Find Wild POKéMON!\l"
	.string "Warden BAOBA's SAFARI ZONE\l"
	.string "Up and Running!$"

