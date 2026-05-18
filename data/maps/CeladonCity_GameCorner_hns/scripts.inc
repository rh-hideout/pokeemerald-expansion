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

	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_ICE_BEAM_COINS, 4000

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
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_TMDoubleTeam
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_TMPsychic
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlamethrower
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_TMThunderbolt
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_TMIceBeam
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TMDoubleTeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_TMPsychic::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_SoYourChoiceIsTM, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	goto_if_unset FLAG_FINITE_TMS, CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrizeInfinite
	switch VAR_TEMP_1
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMDoubleTeam
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMPsychic
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrower
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderbolt
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeam
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrizeInfinite::
	switch VAR_TEMP_1
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMDoubleTeamInfinite
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMPsychicInfinite
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrowerInfinite
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderboltInfinite
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeamInfinite
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

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMPsychicInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_PSYCHIC, 1
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrowerInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_FLAMETHROWER, 1
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderboltInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_THUNDERBOLT, 1
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeamInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_ICE_BEAM, 1
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
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

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMPsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_PSYCHIC
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_ICE_BEAM
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
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
