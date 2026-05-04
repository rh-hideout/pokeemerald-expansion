Route28_House_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	goto_if_set FLAG_GOT_TM_STEEL_WING Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "Oh, dear. You've found me.\p"
	.string "Please don't tell anyone about me.\p"
	.string "I'll give you this for keeping my\n"
	.string "secret. Please?$"

Route28House_Text_Celebrity2:
	.string "It's tough being a top celebrity.\p"
	.string "Everywhere I go, people chase me.\p"
	.string "I just want to be left alone…$"

Route28House_Text_Fearow:
	.string "FEAROW: Feero!$"

