AzaleaTown_Mart_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "Are you able to buy a GREAT BALL?\n"
	.string "All I can buy are POKé BALLS.\p"
	.string "I heard that more items become\n"
	.string "available to buy when you earn\l"
	.string "GYM BADGES!\p"
	.string "I wish KURT would make me some\n"
	.string "of his custom BALLS.$"

AzaleaMart_Text_BugCatcher:
	.string "A GREAT BALL is better for catch-\n"
	.string "ing POKéMON than a POKé BALL.\p"
	.string "But KURT's might be better some-\n"
	.string "times.$"

