CeladonCity_GameCorner_hns_MapScripts::
	.byte 0

CeladonGameCorner_EventScript_PokefanM::
	msgbox CeladonGameCorner_Text_PokefanM, MSGBOX_NPC
	end

CeladonGameCorner_EventScript_Teacher::
	msgbox CeladonGameCorner_Text_Teacher, MSGBOX_NPC
	end

CeladonGameCorner_EventScript_FishingGuru::
	msgbox CeladonGameCorner_Text_FishingGuru, MSGBOX_NPC
	end

CeladonGameCorner_EventScript_Fisher1::
	msgbox CeladonGameCorner_Text_Fisher1, MSGBOX_NPC
	end

CeladonGameCorner_EventScript_Fisher2::
	msgbox CeladonGameCorner_Text_Fisher2, MSGBOX_NPC
	end

CeladonGameCorner_EventScript_GymGuide::
	msgbox CeladonGameCorner_Text_GymGuide, MSGBOX_NPC
	end

CeladonGameCorner_EventScript_Gramps::
	msgbox CeladonGameCorner_Text_Gramps, MSGBOX_NPC
	end

CeladonGameCorner_Text_PokefanM:
	.string "The slot machines are all state\n"
	.string "of the art.$"

CeladonGameCorner_Text_Teacher:
	.string "It's this machine I want.\p"
	.string "It cleaned me out yesterday, so it\n"
	.string "should pay out today.$"

CeladonGameCorner_Text_FishingGuru:
	.string "I think this slot machine will pay\n"
	.string "out…\p"
	.string "The odds vary among machines.$"

CeladonGameCorner_Text_Fisher1:
	.string "Gahahaha!\p"
	.string "The coins just keep popping out!\p"
	.string "Hm? What, kid? You want to play?\p"
	.string "I'll share my luck with you!$"

CeladonGameCorner_Text_Fisher2:
	.string "Gahahaha!\p"
	.string "It makes me feel good to do nice\n"
	.string "things for other people!$"

CeladonGameCorner_Text_GymGuide:
	.string "Hey! CHAMP in making!\p"
	.string "Are you playing the slots too?\p"
	.string "I'm trying to get enough coins for\n"
	.string "a prize POKéMON.\p"
	.string "But I don't have enough coins yet…$"

CeladonGameCorner_Text_Gramps:
	.string "Hmmm… The odds are surely\n"
	.string "better for PIKACHU's line,\l"
	.string "but... what to do?$"

	.set TM_DOUBLE_TEAM_COINS, 2000
	.set TM_ENDURE_COINS, 2000
	.set TM_GIGA_IMPACT_COINS, 3000
	.set TM_GYRO_BALL_COINS, 3000

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorIntro, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrizeMessage
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrizeMessage::
	message CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorWhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize::
	message CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorWhichPrize
	waitmessage
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize::
	dynmultichoice 12, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, CeladonCity_GameCorner_PrizeRoom_Text_TM32, CeladonCity_GameCorner_PrizeRoom_Text_TM58, CeladonCity_GameCorner_PrizeRoom_Text_TM68, CeladonCity_GameCorner_PrizeRoom_Text_TM74, CeladonCity_GameCorner_PrizeRoom_Text_Cancel
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_TMDoubleTeam
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_TMEndure
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_TMGigaImpact
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_TMGyroBall
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TMDoubleTeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_TMEndure::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM58
	setvar VAR_0x8004, ITEM_TM58
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_TMGigaImpact::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM68
	setvar VAR_0x8004, ITEM_TM68
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_TMGyroBall::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM74
	setvar VAR_0x8004, ITEM_TM74
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_SoYourChoiceIsTM, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	goto_if_unset FLAG_FINITE_TMS, CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrizeInfinite
	switch VAR_TEMP_1
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMDoubleTeam
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMEndure
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMGigaImpact
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMGyroBall
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrizeInfinite::
	switch VAR_TEMP_1
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMDoubleTeamInfinite
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMEndureInfinite
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMGigaImpactInfinite
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMGyroBallInfinite
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMDoubleTeamInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_DOUBLE_TEAM, 1
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_DOUBLE_TEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMEndureInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ENDURE_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM58, 1
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_ENDURE_COINS
	additem ITEM_TM58
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMGigaImpactInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_GIGA_IMPACT_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM68, 1
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_GIGA_IMPACT_COINS
	additem ITEM_TM68
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMGyroBallInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_GYRO_BALL_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM74, 1
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_GYRO_BALL_COINS
	additem ITEM_TM74
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_DOUBLE_TEAM
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_DOUBLE_TEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMEndure::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ENDURE_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM58
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_ENDURE_COINS
	additem ITEM_TM58
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMGigaImpact::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_GIGA_IMPACT_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM68
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_GIGA_IMPACT_COINS
	additem ITEM_TM68
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMGyroBall::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_GYRO_BALL_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM74
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_GYRO_BALL_COINS
	additem ITEM_TM74
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorNeedMoreCoins, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorNoCoinCase
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorQuit, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

CeladonCity_GameCorner_PrizeRoom_Text_TM32:
	.string "Double Team 2000$"

CeladonCity_GameCorner_PrizeRoom_Text_TM58:
	.string "Endure     2000$"

CeladonCity_GameCorner_PrizeRoom_Text_TM68:
	.string "Giga Impact 3000$"

CeladonCity_GameCorner_PrizeRoom_Text_TM74:
	.string "Gyro Ball  3000$"

CeladonCity_GameCorner_PrizeRoom_Text_Cancel:
	.string "Cancel$"

CeladonCity_GameCorner_PrizeRoom_Text_SoYourChoiceIsTM:
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorIntro:
	.string "Welcome!\p"
	.string "We exchange your game coins for\n"
	.string "fabulous prizes!$"

CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorWhichPrize:
	.string "Which prize would you like?$"

CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo:
	.string "Here you go!$"

CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorNeedMoreCoins:
	.string "Sorry! You need more coins.$"

CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorNoCoinCase:
	.string "Oh? You don't have a COIN CASE.$"

CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorQuit:
	.string "OK. Please save your coins and come\n"
	.string "again!$"

CeladonCity_GameCorner_PrizeRoom_Text_YouAlreadyHaveThis:
	.string "You already have that item.$"
