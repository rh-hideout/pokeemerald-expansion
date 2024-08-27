MauvilleCity_GameCorner_MapScripts::
	.byte 0

MauvilleCity_GameCorner_EventScript_Cashier::
	lockall
	goto_if_set FLAG_MAUVILLE_GAME_CORNER, MauvilleCity_GameCorner_EventScript_CashierDone
	msgbox MauvilleCity_GameCorner_Text_Cashier, MSGBOX_AUTOCLOSE
	giveitem ITEM_TM_FLAMETHROWER
	giveitem ITEM_TM_PSYCHIC
	giveitem ITEM_TM_ICE_BEAM
	setflag FLAG_MAUVILLE_GAME_CORNER
	releaseall
	end

MauvilleCity_GameCorner_EventScript_CashierDone::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_AUTOCLOSE
	releaseall
	end

MauvilleCity_GameCorner_Text_Cashier:
	.string "Gambling is bad kids. Don't gamble.\n"
	.string "Here, take these.$"

MauvilleCity_GameCorner_Text_OhIsThatSo:
	.string "Oh, you already got the TMs.$"
