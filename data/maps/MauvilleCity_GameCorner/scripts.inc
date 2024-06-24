# 1 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 2 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 3 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_MapScripts::
# 4 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.byte 0
# 5 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 6 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    @ Game Corner prices
# 7 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_DOUBLE_TEAM_COINS, 1500
# 8 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_PSYCHIC_COINS, 3500
# 9 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_FLAMETHROWER_COINS, 4000
# 10 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_THUNDERBOLT_COINS, 4000
# 11 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_ICE_BEAM_COINS, 4000
# 12 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set DOLL_COINS, 1000
# 13 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 14 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_50,  1000
# 15 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_500, 10000
# 16 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 17 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CoinsClerk::
# 18 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 19 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 20 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
# 21 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 22 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
# 23 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
# 24 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 25 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmoneybox 0, 0
# 26 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 6
# 27 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
# 28 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 29 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
# 30 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
# 31 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 32 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 33 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 34 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 35 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 36 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 37 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 38 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
# 39 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
# 40 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 41 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 42 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 43 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 44 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 45 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 46 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy50Coins::
# 47 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 48 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 49 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_50
# 50 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 51 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 50
# 52 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_50
# 53 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox
# 54 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 55 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 56 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 57 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 58 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 59 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 60 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 61 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 62 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy500Coins::
# 63 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 64 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 65 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_500
# 66 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 67 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 500
# 68 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_500
# 69 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox
# 70 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 71 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 72 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 73 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 74 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 75 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 76 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 77 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 78 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NeedCoinCase::
# 79 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
# 80 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 81 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 82 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 83 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
# 84 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
# 85 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 86 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 87 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 88 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 89 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 90 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
# 91 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
# 92 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 93 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 94 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 95 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 96 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 97 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
# 98 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
# 99 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 100 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 101 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 102 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 103 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 104 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
# 105 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 106 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 107 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 108 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 109 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
# 110 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 111 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 112 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 113 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
# 114 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 115 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 116 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 117 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 118 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 119 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 120 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
# 121 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 122 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 123 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 124 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 125 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
# 126 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
# 127 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 128 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
# 129 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
# 130 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
# 131 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 132 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 133 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 134 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 135 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TreeckoDoll::
# 136 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 137 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
# 138 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 139 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 140 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TorchicDoll::
# 141 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 142 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
# 143 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 144 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 145 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_MudkipDoll::
# 146 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 147 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
# 148 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 149 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 150 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
# 151 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
# 152 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 153 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 154 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
# 155 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
# 156 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
# 157 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 158 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 159 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
# 160 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 161 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 162 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 163 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 164 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 165 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 166 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TREECKO_DOLL
# 167 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 168 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 169 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 170 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 171 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 172 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 173 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
# 174 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 175 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 176 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 177 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 178 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 179 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 180 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TORCHIC_DOLL
# 181 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 182 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 183 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 184 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 185 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 186 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 187 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
# 188 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 189 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 190 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 191 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 192 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 193 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 194 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_MUDKIP_DOLL
# 195 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 196 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 197 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 198 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 199 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 200 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 201 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
# 202 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 203 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 204 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 205 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 206 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
# 207 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 208 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 209 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 210 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 211 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelDollSelect::
# 212 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 213 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 214 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 215 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 216 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 217 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
# 218 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 219 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 220 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 221 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 222 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
# 223 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 224 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 225 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 226 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
# 227 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 228 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 229 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 230 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 231 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
# 232 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 233 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
# 234 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 235 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 236 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
# 237 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 238 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
# 239 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
# 240 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 241 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
# 242 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
# 243 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_TMFlamethrower
# 244 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
# 245 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_TMIceBeam
# 246 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 247 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 248 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 249 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 250 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
# 251 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 252 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
# 253 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
# 254 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 255 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 256 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMPsychic::
# 257 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 258 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
# 259 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
# 260 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 261 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 262 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMFlamethrower::
# 263 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 264 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
# 265 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
# 266 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 267 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 268 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMThunderbolt::
# 269 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 4
# 270 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
# 271 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
# 272 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 273 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 274 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMIceBeam::
# 275 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 5
# 276 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
# 277 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
# 278 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 279 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 280 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
# 281 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special BufferTMHMMoveName
# 282 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
# 283 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 284 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 285 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam
# 286 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTMPsychic
# 287 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower
# 288 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt
# 289 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_BuyTMIceBeam
# 290 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 291 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 292 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam::
# 293 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 294 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 295 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_DOUBLE_TEAM
# 296 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 297 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_DOUBLE_TEAM_COINS
# 298 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_DOUBLE_TEAM
# 299 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 300 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 301 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 302 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 303 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 304 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 305 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMPsychic::
# 306 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 307 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 308 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_PSYCHIC
# 309 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 310 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_PSYCHIC_COINS
# 311 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_PSYCHIC
# 312 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 313 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 314 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 315 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 316 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 317 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 318 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower::
# 319 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 320 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 321 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_FLAMETHROWER
# 322 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 323 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_FLAMETHROWER_COINS
# 324 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_FLAMETHROWER
# 325 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 326 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 327 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 328 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 329 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 330 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 331 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt::
# 332 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 333 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 334 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_THUNDERBOLT
# 335 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 336 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_THUNDERBOLT_COINS
# 337 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_THUNDERBOLT
# 338 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 339 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 340 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 341 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 342 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 343 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 344 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMIceBeam::
# 345 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 346 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 347 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_ICE_BEAM
# 348 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 349 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_ICE_BEAM_COINS
# 350 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_ICE_BEAM
# 351 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 352 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 353 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 354 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 355 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 356 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 357 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
# 358 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 359 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 360 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 361 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 362 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForTM::
# 363 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_BagIsFull
# 364 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 365 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 366 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 367 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelTMSelect::
# 368 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 369 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 370 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 371 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 372 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 373 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman2::
# 374 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
# 375 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 376 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 377 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gentleman::
# 378 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
# 379 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 380 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 381 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Girl::
# 382 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 383 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 384 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 385 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
# 386 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
# 387 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_STARTER_MON
# 388 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 389 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 390 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 391 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 392 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 393 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
# 394 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 395 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 396 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 397 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 398 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TREECKO_DOLL
# 399 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 400 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 401 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 402 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 403 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
# 404 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 405 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 406 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 407 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 408 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TORCHIC_DOLL
# 409 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 410 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 411 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 412 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 413 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
# 414 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 415 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 416 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 417 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 418 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_MUDKIP_DOLL
# 419 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 420 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 421 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 422 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 423 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
# 424 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 425 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
# 426 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 427 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 428 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 429 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
# 430 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
# 431 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 432 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 433 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 434 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
# 435 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
# 436 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 437 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 438 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 439 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanM::
# 440 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 441 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 442 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 443 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
# 444 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
# 445 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 446 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 447 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 448 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TryGive20Coins::
# 449 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 450 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 451 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
# 452 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_20_COINS
# 453 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 20
# 454 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
# 455 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 456 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 457 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 458 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 459 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanMNormal::
# 460 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
# 461 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 462 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 463 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 464 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_OldMan::
# 465 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 466 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 467 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
# 468 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 469 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 470 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 471 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Cook::
# 472 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 473 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 474 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
# 475 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 476 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 477 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 478 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Man::
# 479 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 480 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 481 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
# 482 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 483 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 484 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 485 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
# 486 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 487 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 488 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 489 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 490 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 491 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 492 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Maniac::
# 493 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 494 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 495 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
# 496 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 497 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 498 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 499 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman::
# 500 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 501 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 502 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
# 503 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 504 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 505 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 506 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine0::
# 507 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 508 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 509 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 510 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 511 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 512 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 513 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 514 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 515 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 516 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine1::
# 517 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 518 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 519 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 520 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 1
# 521 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 522 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 523 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 524 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 525 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 526 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine2::
# 527 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 528 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 529 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 530 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 2
# 531 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 532 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 533 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 534 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 535 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 536 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine3::
# 537 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 538 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 539 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 540 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 3
# 541 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 542 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 543 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 544 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 545 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 546 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine4::
# 547 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 548 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 549 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 550 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 4
# 551 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 552 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 553 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 554 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 555 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 556 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine5::
# 557 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 558 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 559 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 560 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 5
# 561 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 562 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 563 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 564 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 565 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 566 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine6::
# 567 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 568 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 569 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 570 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 6
# 571 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 572 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 573 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 574 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 575 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 576 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine7::
# 577 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 578 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 579 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 580 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 7
# 581 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 582 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 583 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 584 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 585 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 586 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine8::
# 587 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 588 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 589 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 590 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 8
# 591 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 592 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 593 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 594 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 595 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 596 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine9::
# 597 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 598 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 599 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 600 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 9
# 601 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 602 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 603 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 604 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 605 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 606 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine10::
# 607 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 608 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 609 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 610 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 10
# 611 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 612 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 613 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 614 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 615 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 616 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine11::
# 617 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 618 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 619 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 620 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 11
# 621 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 622 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 623 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 624 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 625 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 626 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoCoinCase::
# 627 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
# 628 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 629 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 630 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 631 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
# 632 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is MAUVILLE GAME CORNER.$"
# 633 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 634 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
# 635 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Okay, you wanted some COINS for\n"
# 636 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the games?\p"
# 637 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "But you don't have a COIN CASE for\n"
# 638 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "stowing the COINS.$"
# 639 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 640 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
# 641 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Were you looking for COINS?\p"
# 642 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's ¥1000 for 50 COINS.\n"
# 643 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like some?$"
# 644 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 645 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
# 646 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you very much!\n"
# 647 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here are your COINS!$"
# 648 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 649 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
# 650 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Um… You don't appear to have\n"
# 651 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "enough money…$"
# 652 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 653 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinCaseIsFull:
# 654 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh?\n"
# 655 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Your COIN CASE is full.$"
# 656 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 657 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
# 658 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh… You don't need COINS, then?\n"
# 659 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Good luck on your adventure!$"
# 660 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 661 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
# 662 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Welcome.\p"
# 663 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can exchange your COINS for\n"
# 664 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "prizes here.$"
# 665 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 666 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WhichPrize:
# 667 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Which prize would you like?$"
# 668 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 669 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
# 670 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is\n"
# 671 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"
# 672 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 673 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SendToYourHomePC:
# 674 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you!\n"
# 675 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 676 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 677 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NotEnoughCoins:
# 678 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS.$"
# 679 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 680 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 681 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
# 682 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There isn't any room available for\n"
# 683 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "placing {STR_VAR_1}.$"
# 684 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 685 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_OhIsThatSo:
# 686 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, is that so? \n"
# 687 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You need to save some COINS before\l"
# 688 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "coming back here.$"
# 689 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 690 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
# 691 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"
# 692 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 693 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo:
# 694 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 695 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 696 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 697 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
# 698 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, you can't carry any more than that.$"
# 699 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 700 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
# 701 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I made a mistake and got two of\n"
# 702 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the same DOLLS.\p"
# 703 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like one of them?$"
# 704 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 705 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo2:
# 706 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 707 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 708 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_YouWantItButNotNow:
# 709 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Huh?\n"
# 710 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You want it, but not right now?$"
# 711 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 712 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontBeNegative:
# 713 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, don't be so negative!\n"
# 714 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can have this!$"
# 715 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 716 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantWinJackpot:
# 717 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There's a prize I want, but I can't win\n"
# 718 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the jackpot.$"
# 719 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 720 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
# 721 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Hey, kid, if you want to play here,\n"
# 722 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "you need a COIN CASE.\p"
# 723 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I think the young lady next door\n"
# 724 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "had one. Go see her!$"
# 725 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 726 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
# 727 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "My luck can only last so long.\n"
# 728 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is too much for me.\l"
# 729 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here, take some COINS!$"
# 730 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 731 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
# 732 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "MAUVILLE has something for\n"
# 733 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "everyone.\p"
# 734 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "For me, it's the GAME CORNER.$"
# 735 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 736 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
# 737 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The ROULETTE tables have different\n"
# 738 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "rates.\p"
# 739 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Check your COINS if you're going to\n"
# 740 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "pick a table.$"
# 741 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 742 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
# 743 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's easy to lose track of time in here. \n"
# 744 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I should get back to work.$"
# 745 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 746 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
# 747 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "COINS are needed to play here\n"
# 748 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "in the GAME CORNER.$"
# 749 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 750 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
# 751 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This ROULETTE thing…\n"
# 752 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's rather demanding.\p"
# 753 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Win or lose, it's only by luck.$"
# 754 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 755 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
# 756 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Up to three COINS can be used to play\n"
# 757 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the SLOTS.$"
# 758 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 759 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DifficultToStopOn7:
# 760 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's very difficult to make it stop\n"
# 761 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "right on “7.”\p"
# 762 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "If it stops on “7” during the REEL TIME\n"
# 763 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonus game, you'll receive extra COINS.$"
# 764 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 765 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
# 766 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here's some information for you\n"
# 767 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "about the SLOTS.\p"
# 768 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The more lightning bolts you stock,\n"
# 769 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the more REEL TIME chances you get.\p"
# 770 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "In a game with the maximum five\n"
# 771 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "REEL TIME chances…\p"
# 772 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It is possible to receive four regular\n"
# 773 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonuses, then a big bonus.\p"
# 774 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "That would total 660 COINS, but it's\n"
# 775 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "very difficult to get.$"
# 776 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 777 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
# 778 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can't play if you don't have\n"
# 779 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "a COIN CASE.$"
# 780 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 781 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_EventScript_EggWoman::
# 782 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    lock
# 783 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    faceplayer
# 784 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    showmoneybox 0, 0
# 785 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    msgbox Gatchaegg_Text_EggsJust8500, MSGBOX_YESNO
# 786 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    goto_if_eq VAR_RESULT, NO, Gatchaegg_EventScript_DeclineEgg
# 787 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    checkmoney 8500
# 788 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    goto_if_eq VAR_RESULT, FALSE, Gatchaegg_EventScript_NotEnoughMoney
# 789 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    msgbox Gatchaegg_Text_ThankYouDear, MSGBOX_DEFAULT
# 790 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    getpartysize
# 791 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    goto_if_eq VAR_RESULT, PARTY_SIZE, Gatchaegg_EventScript_NoRoomForEgg
# 792 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    removemoney 8500
# 793 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    updatemoneybox
# 794 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 795 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    message Gatchaegg_Text_ReceivedTheEgg
# 796 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    waitfanfare
# 797 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    specialvar VAR_RESULT, ChooseRandomEggSpeciesII
# 798 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    giveegg VAR_RESULT
# 799 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    hidemoneybox
# 800 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    release
# 801 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    end
# 802 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 803 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 804 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_Text_EggsJust8500:
# 805 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "Pokémon eggs are locally found.\n"
# 806 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "These ones have been abandoned.\p"
# 807 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "Buy one. It's just ¥8500.$"
# 808 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 809 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_EventScript_DeclineEgg::
# 810 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    msgbox Gatchaegg_Text_OhFineThen, MSGBOX_DEFAULT
# 811 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    hidemoneybox
# 812 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    release
# 813 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    end
# 814 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 815 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_Text_OhFineThen:
# 816 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "Oh, fine then.$"
# 817 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 818 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_EventScript_NotEnoughMoney::
# 819 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    msgbox Gatchaegg_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 820 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    hidemoneybox
# 821 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    release
# 822 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    end
# 823 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 824 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_Text_YouveNotGotTheMoney:
# 825 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "Oh, dear. You can't buy a thing if\n"
# 826 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "you've not got the money.$"
# 827 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 828 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_Text_ThankYouDear:
# 829 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "Thank you, dear!$"
# 830 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 831 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_EventScript_NoRoomForEgg::
# 832 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    msgbox Gatchaegg_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 833 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 834 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    release
# 835 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    end
# 836 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 837 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_Text_NoRoomForThisEgg:
# 838 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "Oh? You've too many POKéMON.\n"
# 839 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "There's no room for this EGG…$"
# 840 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 841 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Gatchaegg_Text_ReceivedTheEgg:
# 842 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    .string "{PLAYER} received the EGG.$"
