# 1 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_MapScripts::
# 3 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.set BET_AMOUNT_5,  5
# 6 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.set BET_AMOUNT_10, 10
# 7 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.set BET_AMOUNT_15, 15
# 8 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 9 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Gambler::
# 10 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	lock
# 11 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	faceplayer
# 12 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
# 13 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
# 14 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
# 15 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
# 16 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
# 17 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
# 18 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 20 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
# 21 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special ShowFrontierGamblerLookingMessage
# 22 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 23 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitbuttonpress
# 24 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
# 25 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
# 26 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
# 27 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
# 28 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
# 29 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 30 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special ShowBattlePointsWindow
# 31 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
# 32 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 33 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 34 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
# 35 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
# 36 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
# 37 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	switch VAR_RESULT
# 38 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
# 39 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
# 40 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
# 41 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
# 42 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
# 43 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 45 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Bet5::
# 46 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8008, BET_AMOUNT_5
# 47 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
# 48 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 49 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 50 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Bet10::
# 51 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8008, BET_AMOUNT_10
# 52 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
# 53 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 54 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 55 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Bet15::
# 56 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8008, BET_AMOUNT_15
# 57 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
# 58 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 59 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 60 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_TryPlaceBet::
# 61 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 62 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
# 63 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
# 64 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
# 65 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 66 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
# 67 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 68 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 69 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_PlaceBet::
# 70 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 71 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special TakeFrontierBattlePoints
# 72 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
# 73 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special UpdateBattlePointsWindow
# 74 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	playse SE_SHOP
# 75 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
# 76 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FinishBet
# 77 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 78 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 79 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_FinishBet::
# 80 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special ShowFrontierGamblerGoMessage
# 81 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 82 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitbuttonpress
# 83 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special CloseBattlePointsWindow
# 84 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 85 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 86 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 87 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
# 88 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8004, 0
# 89 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 90 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 91 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 92 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 93 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 94 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 95 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 96 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 97 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 98 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
# 99 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	addvar VAR_0x8004, 1
# 100 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 101 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 102 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
# 103 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
# 104 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
# 105 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 106 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 107 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
# 108 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
# 109 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
# 110 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
# 111 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 112 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 113 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_CheckBetResults::
# 114 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
# 115 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
# 116 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
# 117 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 118 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 119 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_WonChallenge::
# 120 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
# 121 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
# 122 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
# 123 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
# 124 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
# 125 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special GiveFrontierBattlePoints
# 126 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
# 127 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
# 128 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 129 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 130 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 131 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_LostChallenge::
# 132 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
# 133 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
# 134 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 135 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 136 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 137 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_RewardBet5::
# 138 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
# 139 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
# 140 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 141 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 142 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_RewardBet10::
# 143 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
# 144 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
# 145 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 146 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 147 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_RewardBet15::
# 148 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
# 149 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
# 150 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 151 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 152 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
# 153 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special ShowFrontierGamblerGoMessage
# 154 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 155 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitbuttonpress
# 156 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 157 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 158 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 159 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_DeclineChallenge::
# 160 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
# 161 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 162 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 163 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 164 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_CancelBet::
# 165 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special CloseBattlePointsWindow
# 166 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
# 167 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 168 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 169 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Man::
# 170 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
# 171 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 172 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 173 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Woman::
# 174 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	lock
# 175 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	faceplayer
# 176 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
# 177 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
# 178 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 179 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 180 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_PokefanF::
# 181 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	lock
# 182 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	faceplayer
# 183 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
# 184 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
# 185 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 186 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 187 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_FatMan::
# 188 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	lock
# 189 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	faceplayer
# 190 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
# 191 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
# 192 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 193 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 194 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
# 195 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	closemessage
# 196 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 197 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmovement 0
# 198 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 199 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 200 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 201 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
# 202 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "…What's that you want?\p"
# 203 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Can't you see we're kind of busy here?\n"
# 204 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Can't your business wait till later?$"
# 205 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 206 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
# 207 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "…Huh?\n"
# 208 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "You look to me like a tough TRAINER.\p"
# 209 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Heheh…\n"
# 210 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Listen, I have this proposition.\p"
# 211 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "We have a little group going here,\n"
# 212 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "and we play a little game with what\l"
# 213 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "goes on in the BATTLE FRONTIER.\p"
# 214 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "The rules are really simple.\p"
# 215 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "First, we pick one of the facilities\n"
# 216 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "in the BATTLE FRONTIER.\p"
# 217 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Then, we each pick a different TRAINER\n"
# 218 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "who's taking that facility's challenge,\l"
# 219 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "and bet with our Battle Points.\p"
# 220 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "The guy who bet on the TRAINER with\n"
# 221 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "the best record takes all the Battle\l"
# 222 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Points in the pool.\p"
# 223 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Sounds simple, huh?\n"
# 224 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So, anyway…$"
# 225 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 226 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
# 227 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 228 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 229 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "TOWER's SINGLE BATTLE ROOMS.\p"
# 230 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 231 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 232 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 233 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
# 234 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 235 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 236 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "TOWER's DOUBLE BATTLE ROOMS.\p"
# 237 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 238 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 239 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 240 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
# 241 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 242 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 243 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "TOWER's MULTI BATTLE ROOMS.\p"
# 244 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 245 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 246 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 247 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
# 248 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 249 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 250 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "DOME's SINGLE BATTLE Tourney.\p"
# 251 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 252 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 253 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 254 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
# 255 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 256 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 257 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "DOME's DOUBLE BATTLE Tourney.\p"
# 258 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 259 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 260 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 261 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
# 262 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 263 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 264 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "FACTORY's Battle Swap Single Tourney.\p"
# 265 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 266 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 267 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 268 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
# 269 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 270 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 271 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "FACTORY's Battle Swap Double Tourney.\p"
# 272 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 273 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 274 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 275 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
# 276 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 277 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 278 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "PALACE's SINGLE BATTLE HALLS.\p"
# 279 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 280 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 281 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 282 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
# 283 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 284 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 285 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "PALACE's DOUBLE BATTLE HALLS.\p"
# 286 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 287 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 288 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 289 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleArena::
# 290 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 291 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 292 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "ARENA's Set KO Tourney.\p"
# 293 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 294 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 295 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 296 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattlePike::
# 297 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 298 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE PIKE's\l"
# 299 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Choice.\p"
# 300 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 301 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 302 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 303 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
# 304 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a TRAINER who's\n"
# 305 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 306 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "PYRAMID's Battle Quest.\p"
# 307 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a TRAINER\n"
# 308 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 309 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 310 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
# 311 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I'll see to it that you benefit, too.\n"
# 312 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So how about it?\l"
# 313 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "How about entering that event for me?$"
# 314 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 315 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
# 316 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "All right, that's perfect.\n"
# 317 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So, uh… How about spotting me some\l"
# 318 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "of your Battle Points?\p"
# 319 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Trust me, I'll show you my gratitude\n"
# 320 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "afterward.$"
# 321 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 322 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
# 323 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Great, great!\n"
# 324 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So, how much can you spot me?$"
# 325 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 326 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
# 327 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Oh, no, no, no!\n"
# 328 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "You don't have enough Battle Points!\p"
# 329 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I wish you wouldn't monkey around and\n"
# 330 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "waste everyone's time!$"
# 331 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 332 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ThanksOffYouGo::
# 333 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Heheh! Thanks much!\n"
# 334 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So, off you go!$"
# 335 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 336 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
# 337 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE TOWER's\n"
# 338 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "SINGLE BATTLE ROOMS pronto!\p"
# 339 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 340 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 341 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 342 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 343 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
# 344 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE TOWER's\n"
# 345 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "DOUBLE BATTLE ROOMS pronto!\p"
# 346 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 347 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 348 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 349 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 350 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
# 351 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE TOWER's\n"
# 352 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "MULTI BATTLE ROOMS pronto!\p"
# 353 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 354 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 355 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 356 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 357 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
# 358 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE DOME's\n"
# 359 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "SINGLE BATTLE Tourney pronto!\p"
# 360 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 361 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 362 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 363 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 364 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
# 365 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE DOME's\n"
# 366 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "DOUBLE BATTLE Tourney pronto!\p"
# 367 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 368 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 369 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 370 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 371 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
# 372 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE FACTORY's\n"
# 373 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Swap Single Tourney pronto!\p"
# 374 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 375 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 376 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 377 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 378 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
# 379 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE FACTORY's\n"
# 380 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Swap Double Tourney pronto!\p"
# 381 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 382 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 383 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 384 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 385 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
# 386 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE PALACE's\n"
# 387 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "SINGLE BATTLE HALLS pronto!\p"
# 388 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 389 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 390 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 391 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 392 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
# 393 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE PALACE's\n"
# 394 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "DOUBLE BATTLE HALLS pronto!\p"
# 395 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 396 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 397 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 398 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 399 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleArena::
# 400 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE ARENA's\n"
# 401 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Set KO Tourney pronto!\p"
# 402 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 403 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 404 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 405 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 406 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattlePike::
# 407 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE PIKE's\n"
# 408 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Choice pronto!\p"
# 409 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 410 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 411 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 412 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 413 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattlePyramid::
# 414 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE PYRAMID's\n"
# 415 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Quest pronto!\p"
# 416 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 417 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 418 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 419 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 420 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
# 421 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Oh, it's you…\n"
# 422 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Nice try…\p"
# 423 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I hate to break it to you, but I can't\n"
# 424 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "return your Battle Points…\p"
# 425 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I guess we'll have to let it motivate\n"
# 426 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "us to try harder next time!$"
# 427 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 428 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
# 429 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Oh, yes!\n"
# 430 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Hello there, champ!\p"
# 431 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I knew you could!\n"
# 432 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I knew you would!\l"
# 433 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "We're both big winners!\p"
# 434 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I'll return your Battle Points and,\n"
# 435 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "of course, a little extra from me!$"
# 436 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 437 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
# 438 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "{PLAYER} obtained\n"
# 439 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "{STR_VAR_1} Battle Points.$"
# 440 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 441 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
# 442 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "If you're up for another challenge,\n"
# 443 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "please do think of me!$"
# 444 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 445 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_NotInterested::
# 446 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Not interested?! You shouldn't be\n"
# 447 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "so afraid to take a chance!$"
# 448 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 449 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_Oh::
# 450 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Oh…$"
# 451 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 452 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_BackedWrongTrainer::
# 453 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I backed the wrong TRAINER again!\p"
# 454 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Maybe I should be battling normally\n"
# 455 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "like everyone else…$"
# 456 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 457 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
# 458 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "That TRAINER…\p"
# 459 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "He's good, but he gets rattled too\n"
# 460 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "easily to survive the BATTLE DOME…$"
# 461 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 462 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
# 463 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Giggle!\n"
# 464 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I know a winner when I see one!$"
# 465 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 466 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
# 467 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Those TRAINERS…\n"
# 468 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What are they doing?\l"
# 469 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "They should be taking challenges.$"
