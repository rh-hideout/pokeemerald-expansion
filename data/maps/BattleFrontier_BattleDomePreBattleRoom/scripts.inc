# 1 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_MapScripts::
# 3 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnFrame
# 4 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnWarp
# 5 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_OnWarp:
# 8 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_TurnPlayerNorth
# 9 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TurnPlayerNorth::
# 12 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 16 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_OnFrame:
# 17 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_EnterRoom
# 18 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.2byte 0
# 19 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 20 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_EnterRoom::
# 21 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReturnFromBattle
# 22 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	delay 1
# 23 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 24 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 25 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter
# 26 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmovement 0
# 27 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	lockall
# 28 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound::
# 29 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForNextRoundMessage
# 30 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 31 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT  @ No case?
# 32 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 33 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRoundNoRecord
# 34 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	multichoice 16, 0, MULTI_TOURNEY_WITH_RECORD, TRUE
# 35 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 36 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo
# 37 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree
# 38 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge
# 39 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRecordBattle
# 40 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge
# 41 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge
# 42 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 43 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 44 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRoundNoRecord::
# 45 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	multichoice 16, 2, MULTI_TOURNEY_NO_RECORD, TRUE
# 46 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 47 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo
# 48 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree
# 49 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge
# 50 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge
# 51 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge
# 52 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 53 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 54 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRecordBattle::
# 55 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_RecordLastMatch
# 56 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 57 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 58 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 59 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 60 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_RecordBattle
# 61 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 62 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 63 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_RecordBattle::
# 64 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 65 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 66 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 67 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge::
# 68 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 69 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 70 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 71 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleDomePreBattleRoom_EventScript_PauseChallenge
# 72 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 73 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 74 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge::
# 75 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_RetireYourChallenge
# 76 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 77 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 78 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 79 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 80 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_RetireChallenge
# 81 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 82 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 83 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_RetireChallenge::
# 84 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_RETIRED
# 85 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost
# 86 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 87 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_PauseChallenge::
# 88 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_SavingDataPleaseWait
# 89 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 90 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_save CHALLENGE_STATUS_PAUSED
# 91 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	playse SE_SAVE
# 92 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitse
# 93 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_reset
# 95 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	end
# 96 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 97 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo::
# 98 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_PlayersNextOpponentIsTrainer, MSGBOX_DEFAULT
# 99 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 100 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_showopponentinfo
# 101 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 102 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 103 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 104 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree::
# 105 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowRoundMessage
# 106 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 107 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_showtourneytree
# 108 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 109 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 110 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 111 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowRoundMessage::
# 112 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 113 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 114 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound1
# 115 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound2
# 116 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInSemifinals
# 117 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInFinals
# 118 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 119 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 120 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound1::
# 121 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound1, MSGBOX_DEFAULT
# 122 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 123 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 124 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound2::
# 125 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound2, MSGBOX_DEFAULT
# 126 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 127 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 128 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInSemifinals::
# 129 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInSemifinals, MSGBOX_DEFAULT
# 130 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 131 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 132 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInFinals::
# 133 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInFinals, MSGBOX_DEFAULT
# 134 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 135 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 136 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge::
# 137 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ChooseTwoMons
# 138 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 139 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitbuttonpress
# 140 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 141 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 142 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 143 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_0x8005, DOME_BATTLE_PARTY_SIZE  @ 2 of the 3 party mons are selected for battle
# 144 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	special ChoosePartyForBattleFrontier
# 145 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 146 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_resetsketch
# 147 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 148 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_set DOME_DATA_SELECTED_MONS
# 149 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_reduceparty
# 150 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_setopponent
# 151 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
# 152 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	closemessage
# 153 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleDomePreBattleRoom_Movement_AttendantMoveAside
# 154 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmovement 0
# 155 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerWalkToDoor
# 156 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmovement 0
# 157 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	opendoor 5, 1
# 158 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitdooranim
# 159 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnterDoor
# 160 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmovement 0
# 161 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	closedoor 5, 1
# 162 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitdooranim
# 163 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM, 9, 5
# 164 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 165 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 166 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	end
# 167 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 168 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForNextRoundMessage::
# 169 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 170 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 171 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound1
# 172 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound2
# 173 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForSemifinals
# 174 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForFinals
# 175 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 176 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 177 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound1::
# 178 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound1
# 179 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 180 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 181 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound2::
# 182 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound2
# 183 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 184 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 185 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForSemifinals::
# 186 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForSemifinals
# 187 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 188 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 189 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForFinals::
# 190 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 191 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 192 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver
# 193 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold
# 194 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver
# 195 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold
# 196 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForFinals
# 197 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 198 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 199 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver::
# 200 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilverShort
# 201 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver, MSGBOX_DEFAULT
# 202 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 203 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 204 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 205 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold::
# 206 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGoldShort
# 207 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold, MSGBOX_DEFAULT
# 208 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 209 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 210 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 211 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilverShort::
# 212 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilverShort, MSGBOX_DEFAULT
# 213 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 214 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 215 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGoldShort::
# 216 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGoldShort, MSGBOX_DEFAULT
# 217 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 218 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 219 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReturnFromBattle::
# 220 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 221 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 222 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	special LoadPlayerParty
# 223 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 224 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 225 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitfanfare
# 226 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	special HealPlayerParty
# 227 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_RoundCompleteMessage
# 228 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 229 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_showstatictourneytree
# 230 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 231 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 232 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 233 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_RoundCompleteMessage::
# 234 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 235 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 236 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_Round1Complete
# 237 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_Round2Complete
# 238 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_SemifinalsComplete
# 239 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 240 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 241 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_Round1Complete::
# 242 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_Round1Complete, MSGBOX_DEFAULT
# 243 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 244 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 245 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_Round2Complete::
# 246 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_Round2Complete, MSGBOX_DEFAULT
# 247 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 248 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 249 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_SemifinalsComplete::
# 250 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_SemifinalsComplete, MSGBOX_DEFAULT
# 251 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 252 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 253 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Movement_AttendantMoveAside:
# 254 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_right
# 255 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	face_left
# 256 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	step_end
# 257 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 258 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter:
# 259 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 260 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 261 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 262 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 263 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	step_end
# 264 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 265 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerWalkToDoor:
# 266 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 267 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	step_end
# 268 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 269 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnterDoor:
# 270 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 271 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	set_invisible
# 272 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	step_end
# 273 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 274 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound1:
# 275 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your 1st-round match is next.\n"
# 276 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 277 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 278 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound2:
# 279 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your 2nd-round match is next.\n"
# 280 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 281 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 282 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForSemifinals:
# 283 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your semifinal match is next.\n"
# 284 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 285 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 286 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForFinals:
# 287 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your final match is next.\n"
# 288 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 289 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 290 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ChooseTwoMons:
# 291 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Please choose the two POKéMON\n"
# 292 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "that are to appear in battle.$"
# 293 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 294 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_RightThisWay:
# 295 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Right this way, please.$"
# 296 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 297 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_RestoreMonsToFullHealth:
# 298 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Thank you for competing!\p"
# 299 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "I'll restore your POKéMON to\n"
# 300 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "full health.$"
# 301 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 302 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_Round1Complete:
# 303 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "All 1st-round matches have been\n"
# 304 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "completed.\p"
# 305 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "These are the teams that advanced!$"
# 306 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 307 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_Round2Complete:
# 308 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "All 2nd-round matches have been\n"
# 309 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "completed.\p"
# 310 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "These are the teams that advanced!$"
# 311 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 312 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_SemifinalsComplete:
# 313 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "All semifinal matches have been\n"
# 314 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "completed.\p"
# 315 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "These are the teams that advanced!$"
# 316 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 317 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Unused
# 318 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForRound2:
# 319 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for getting through\n"
# 320 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "the 1st round.\p"
# 321 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The 2nd round is next.\n"
# 322 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 323 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 324 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Unused
# 325 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForSemifinals:
# 326 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for advancing\n"
# 327 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "to the semifinals.\p"
# 328 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The best four teams meet in this round.\n"
# 329 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 330 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 331 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Unused
# 332 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForFinals:
# 333 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for advancing\n"
# 334 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "to the final match.\p"
# 335 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "You're one win from the championship.\n"
# 336 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 337 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 338 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_PlayersNextOpponentIsTrainer:
# 339 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "{PLAYER}'s next opponent\n"
# 340 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "is this TRAINER.$"
# 341 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 342 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound1:
# 343 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The tournament is in the 1st round.$"
# 344 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 345 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound2:
# 346 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The tournament is in the 2nd round.$"
# 347 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 348 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInSemifinals:
# 349 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The tournament is in the semifinals.$"
# 350 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 351 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInFinals:
# 352 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The tournament is up to the final.$"
# 353 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 354 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_SaveAndQuitGame:
# 355 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Would you like to save and\n"
# 356 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "quit the game?$"
# 357 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_RetireYourChallenge:
# 359 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 360 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Battle Tournament challenge?$"
# 361 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 362 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_SavingDataPleaseWait:
# 363 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "I am saving your data.\n"
# 364 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Please wait.$"
# 365 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 366 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_RecordLastMatch:
# 367 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Should I record your last match\n"
# 368 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "on your FRONTIER PASS?$"
# 369 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 370 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver:
# 371 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for advancing\n"
# 372 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "to the final match.\p"
# 373 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "For the final match, you will challenge\n"
# 374 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "the DOME ACE TUCKER.\p"
# 375 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 376 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 377 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Identical to ReadyForTuckerSilver
# 378 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold:
# 379 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for advancing\n"
# 380 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "to the final match.\p"
# 381 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "For the final match, you will challenge\n"
# 382 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "the DOME ACE TUCKER.\p"
# 383 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 384 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 385 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilverShort:
# 386 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your final battle against TUCKER is\n"
# 387 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "next. Are you ready?$"
# 388 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 389 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Identical again
# 390 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGoldShort:
# 391 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your final battle against TUCKER is\n"
# 392 "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "next. Are you ready?$"
