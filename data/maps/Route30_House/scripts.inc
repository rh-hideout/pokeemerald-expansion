Route30_House_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "When you follow that path up north,\n"
	.string "you will see MR. POKéMON’s house.\p"
	.string "But before you go, allow me to\n"
	.string "tell you about BERRIES!\p"
	.string "POKéMON get healthier by eating\n"
	.string "BERRIES.\p"
	.string "They can even eat BERRIES\n"
	.string "they're holding in battle.\p"
	.string "BERRIES can also be turned into\n"
	.string "BALLS by KURT in AZALEA TOWN.\p"
	.string "Here. I'll share one with you!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Check trees for BERRIES.\n"
	.string "They grow back after a few hours.$"
