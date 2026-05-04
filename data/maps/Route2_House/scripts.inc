Route2_House_MapScripts::
	.byte 0

Route2_House_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROUTE2_NUGGET, Route2_House_EventScript_ManAfter
	msgbox Route2_House_Text_Fisher, MSGBOX_DEFAULT 
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_ROUTE2_NUGGET
	release
	end

Route2_House_EventScript_ManAfter::
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	release
	end

Route2_House_Text_Fisher:
	.string "Hi! Wow, I'm glad to see you.\p"
	.string "You're the first visitor I've had in a\n"
	.string "long time.\p"
	.string "I'm super-happy! Let me give you a\n"
	.string "little present.$"

Route2_House_Text_Fisher_GotNugget:
	.string "That's a NUGGET.\p"
	.string "I can't give you any nuggets of\n"
	.string "wisdom, so that'll have to do!$"
