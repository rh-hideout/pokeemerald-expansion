# 1 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_MapScripts::
# 3 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_Greeter::
# 6 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
# 7 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 8 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 9 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk::
# 10 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	lock
# 11 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	faceplayer
# 12 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	dotimebasedevents
# 13 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
# 14 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
# 15 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
# 16 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
# 17 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
# 18 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
# 19 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmessage
# 20 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special RetrieveLotteryNumber
# 21 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 22 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special BufferLottoTicketNumber
# 23 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
# 24 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_WalkInPlaceFasterRight
# 25 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmovement 0
# 26 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	playse SE_PC_ON
# 27 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special DoLotteryCornerComputerEffect
# 28 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special PickLotteryCornerTicket
# 29 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	delay 220
# 30 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special EndLotteryCornerComputerEffect
# 31 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	delay 10
# 32 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_FacePlayer
# 33 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmovement 0
# 34 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
# 35 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
# 36 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8006, 0, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
# 37 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8006, 1, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
# 38 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8005
# 39 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8004, 1, LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
# 40 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8004, 2, LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
# 41 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8004, 3, LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
# 42 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq VAR_0x8004, 4, LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
# 43 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	giveitem VAR_0x8005
# 44 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
# 45 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special TryPutLotteryWinnerReportOnAir
# 46 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
# 47 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 48 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 49 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
# 50 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
# 51 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 52 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 53 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
# 54 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
# 55 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 56 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 57 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
# 58 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
# 59 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 60 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 61 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 62 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
# 63 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
# 64 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 65 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 66 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 67 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_NoMatch::
# 68 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
# 69 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
# 70 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 71 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 72 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
# 73 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
# 74 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 75 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 76 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 77 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
# 78 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
# 79 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 80 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 81 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
# 82 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
# 83 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 84 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 85 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch::
# 86 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
# 87 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 88 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 89 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FullMatch::
# 90 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
# 91 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 92 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 93 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
# 94 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
# 95 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
# 96 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
# 97 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 98 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 99 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
# 100 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
# 101 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 102 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 103 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 104 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
# 105 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
# 106 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	giveitem VAR_POKELOT_PRIZE_ITEM
# 107 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
# 108 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
# 109 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
# 110 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special TryPutLotteryWinnerReportOnAir
# 111 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
# 112 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setvar VAR_POKELOT_PRIZE_PLACE, 0
# 113 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 114 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 115 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 116 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PokefanF::
# 117 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
# 118 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 119 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 120 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl::
# 121 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
# 122 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 123 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 124 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PokefanM::
# 125 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
# 126 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 127 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 128 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_Azumarill::
# 129 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	lock
# 130 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	faceplayer
# 131 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitse
# 132 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
# 133 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
# 134 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmoncry
# 135 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 136 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 137 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 138 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign::
# 139 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
# 140 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 141 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 142 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
# 143 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Welcome to LILYCOVE DEPARTMENT STORE.$"
# 144 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 145 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings:
# 146 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Whenever I come to the DEPARTMENT\n"
# 147 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "STORE, I always end up buying all sorts\l"
# 148 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "of things because it's so fun.$"
# 149 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 150 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture:
# 151 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Today, my mom is going to buy me some\n"
# 152 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "nice furniture.$"
# 153 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 154 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill:
# 155 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I'm buying something for my AZUMARILL\n"
# 156 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "as a reward for winning a CONTEST.$"
# 157 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 158 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_Azumarill:
# 159 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "AZUMARILL: Maririroo!$"
# 160 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 161 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign:
# 162 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "1F: SERVICE COUNTER\n"
# 163 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "    LOTTERY CORNER\p"
# 164 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "2F: TRAINER'S ZONE\p"
# 165 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "3F: BATTLE COLLECTION\p"
# 166 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "4F: TM CORNER\p"
# 167 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "5F: POKé DOLL FLOOR\p"
# 168 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "ROOFTOP: ROOFTOP PLAZA$"
# 169 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 170 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
@ Unused
# 171 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun:
# 172 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Wireless Communication is a\n"
# 173 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "lot of fun, isn't it?\p"
# 174 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I think it lets you do things that\n"
# 175 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "weren't possible before.\p"
# 176 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "For instance, you can now trade\n"
# 177 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "with people you couldn't before.\p"
# 178 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I think it's going to be exciting!$"
# 179 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 180 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
@ Unused
# 181 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm:
# 182 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I want to spread the word about how\n"
# 183 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "fun Wireless Communication can be.$"
