# 1 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
.set LOCALID_LOTTERY_CLERK, 2
# 3 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 4 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_MapScripts::
# 5 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.byte 0
# 6 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 7 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_Greeter::
# 8 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
# 9 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 10 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 11 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk::
# 12 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	lock
# 13 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	faceplayer
# 14 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	dotimebasedevents
# 15 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
# 16 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
# 17 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
# 18 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
# 19 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
# 20 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
# 21 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmessage
# 22 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special RetrieveLotteryNumber
# 23 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 24 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special BufferLottoTicketNumber
# 25 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
# 26 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_WalkInPlaceFasterRight
# 27 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmovement 0
# 28 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	playse SE_PC_ON
# 29 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special DoLotteryCornerComputerEffect
# 30 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special PickLotteryCornerTicket
# 31 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	delay 220
# 32 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special EndLotteryCornerComputerEffect
# 33 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	delay 10
# 34 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_FacePlayer
# 35 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmovement 0
# 36 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
# 37 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
# 38 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8006, 0, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
# 39 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8006, 1, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
# 40 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8005
# 41 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8004, 1, LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
# 42 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8004, 2, LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
# 43 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8004, 3, LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
# 44 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8004, 4, LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
# 45 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	giveitem VAR_0x8005
# 46 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
# 47 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special TryPutLotteryWinnerReportOnAir
# 48 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
# 49 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 50 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 51 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
# 52 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
# 53 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 54 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 55 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
# 56 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
# 57 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 58 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 59 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
# 60 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
# 61 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 62 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 63 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 64 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
# 65 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
# 66 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 67 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 68 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 69 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_NoMatch::
# 70 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
# 71 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
# 72 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 73 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 74 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
# 75 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
# 76 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 77 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 78 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 79 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
# 80 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
# 81 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 82 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 83 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
# 84 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
# 85 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 86 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 87 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch::
# 88 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
# 89 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 90 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 91 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FullMatch::
# 92 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
# 93 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 94 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 95 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
# 96 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
# 97 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
# 98 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
# 99 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 100 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 101 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
# 102 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
# 103 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 104 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 105 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 106 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
# 107 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
# 108 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	giveitem VAR_POKELOT_PRIZE_ITEM
# 109 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
# 110 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
# 111 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
# 112 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special TryPutLotteryWinnerReportOnAir
# 113 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
# 114 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setvar VAR_POKELOT_PRIZE_PLACE, 0
# 115 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 116 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 117 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 118 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PokefanF::
# 119 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
# 120 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 121 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 122 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl::
# 123 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
# 124 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 125 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 126 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PokefanM::
# 127 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
# 128 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 129 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 130 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_Azumarill::
# 131 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	lock
# 132 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	faceplayer
# 133 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitse
# 134 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
# 135 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
# 136 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmoncry
# 137 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 138 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 139 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 140 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign::
# 141 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
# 142 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 143 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 144 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
# 145 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Welcome to LILYCOVE DEPARTMENT STORE.$"
# 146 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 147 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings:
# 148 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Whenever I come to the DEPARTMENT\n"
# 149 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "STORE, I always end up buying all sorts\l"
# 150 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "of things because it's so fun.$"
# 151 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 152 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture:
# 153 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Today, my mom is going to buy me some\n"
# 154 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "nice furniture.$"
# 155 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 156 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill:
# 157 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I'm buying something for my AZUMARILL\n"
# 158 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "as a reward for winning a CONTEST.$"
# 159 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 160 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_Azumarill:
# 161 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "AZUMARILL: Maririroo!$"
# 162 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 163 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign:
# 164 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "1F: SERVICE COUNTER\n"
# 165 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "    LOTTERY CORNER\p"
# 166 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "2F: TRAINER'S ZONE\p"
# 167 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "3F: BATTLE COLLECTION\p"
# 168 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "4F: TM CORNER\p"
# 169 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "5F: POKé DOLL FLOOR\p"
# 170 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "ROOFTOP: ROOFTOP PLAZA$"
# 171 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 172 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
@ Unused
# 173 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun:
# 174 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Wireless Communication is a\n"
# 175 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "lot of fun, isn't it?\p"
# 176 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I think it lets you do things that\n"
# 177 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "weren't possible before.\p"
# 178 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "For instance, you can now trade\n"
# 179 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "with people you couldn't before.\p"
# 180 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I think it's going to be exciting!$"
# 181 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 182 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
@ Unused
# 183 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm:
# 184 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I want to spread the word about how\n"
# 185 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "fun Wireless Communication can be.$"
