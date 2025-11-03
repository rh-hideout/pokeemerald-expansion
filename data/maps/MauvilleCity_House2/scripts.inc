# 1 "data/maps/MauvilleCity_House2/scripts.pory"

# 2 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_MapScripts::
# 3 "data/maps/MauvilleCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_House2/scripts.pory"

# 5 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_Woman::
# 6 "data/maps/MauvilleCity_House2/scripts.pory"
	lock
# 7 "data/maps/MauvilleCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
# 9 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
# 10 "data/maps/MauvilleCity_House2/scripts.pory"
	checkitem ITEM_HARBOR_MAIL
# 11 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
# 12 "data/maps/MauvilleCity_House2/scripts.pory"
	release
# 13 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 14 "data/maps/MauvilleCity_House2/scripts.pory"

# 15 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
# 16 "data/maps/MauvilleCity_House2/scripts.pory"
	playse SE_PIN
# 17 "data/maps/MauvilleCity_House2/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 18 "data/maps/MauvilleCity_House2/scripts.pory"
	waitmovement 0
# 19 "data/maps/MauvilleCity_House2/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
# 20 "data/maps/MauvilleCity_House2/scripts.pory"
	waitmovement 0
# 21 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
# 22 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
# 23 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
# 24 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 25 "data/maps/MauvilleCity_House2/scripts.pory"

# 26 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_AcceptTrade::
# 27 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
# 28 "data/maps/MauvilleCity_House2/scripts.pory"
	giveitem ITEM_COIN_CASE
# 29 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 30 "data/maps/MauvilleCity_House2/scripts.pory"
	removeitem ITEM_HARBOR_MAIL
# 31 "data/maps/MauvilleCity_House2/scripts.pory"
	setflag FLAG_RECEIVED_COIN_CASE
# 32 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
# 33 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 34 "data/maps/MauvilleCity_House2/scripts.pory"

# 35 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_ReceivedCoinCase::
# 36 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
# 37 "data/maps/MauvilleCity_House2/scripts.pory"
	release
# 38 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 39 "data/maps/MauvilleCity_House2/scripts.pory"

# 40 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_DeclineTrade::
# 41 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
# 42 "data/maps/MauvilleCity_House2/scripts.pory"
	release
# 43 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 44 "data/maps/MauvilleCity_House2/scripts.pory"

# 45 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
# 46 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "If I had a BIKE, it'd be easy to cycle to\n"
# 47 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "SLATEPORT for some shopping.\p"
# 48 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "I'd be able to buy HARBOR MAIL at the\n"
# 49 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "POKéMON MART in SLATEPORT…$"
# 50 "data/maps/MauvilleCity_House2/scripts.pory"

# 51 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
# 52 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Oh! You have HARBOR MAIL?\n"
# 53 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Will you trade it for a COIN CASE?$"
# 54 "data/maps/MauvilleCity_House2/scripts.pory"

# 55 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_IllTradeYouCoinCase:
# 56 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Oh, I'm so happy!\n"
# 57 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Okay, I'll trade you a COIN CASE!$"
# 58 "data/maps/MauvilleCity_House2/scripts.pory"

# 59 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
# 60 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "That COIN CASE can be used\n"
# 61 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "at the GAME CORNER.$"
# 62 "data/maps/MauvilleCity_House2/scripts.pory"

# 63 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_ThatsDisappointing:
# 64 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Oh, that's disappointing.\p"
# 65 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "A COIN CASE is needed for the\n"
# 66 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "GAME CORNER.$"
