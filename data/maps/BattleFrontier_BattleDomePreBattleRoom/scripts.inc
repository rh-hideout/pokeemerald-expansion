# 1 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 4 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_MapScripts::
# 5 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnFrame
# 6 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnWarp
# 7 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 9 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_OnWarp:
# 10 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_TurnPlayerNorth
# 11 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.2byte 0
# 12 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 13 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TurnPlayerNorth::
# 14 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 16 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	end
# 17 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 18 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_OnFrame:
# 19 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_EnterRoom
# 20 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.2byte 0
# 21 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 22 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_EnterRoom::
# 23 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReturnFromBattle
# 24 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 25 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 26 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter
# 27 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmovement 0
# 28 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	lockall
# 29 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound::
# 30 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForNextRoundMessage
# 31 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 32 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT  @ No case?
# 33 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 34 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRoundNoRecord
# 35 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	multichoice 16, 0, MULTI_TOURNEY_WITH_RECORD, TRUE
# 36 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 37 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo
# 38 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree
# 39 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge
# 40 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRecordBattle
# 41 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge
# 42 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge
# 43 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 44 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 45 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRoundNoRecord::
# 46 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	multichoice 16, 2, MULTI_TOURNEY_NO_RECORD, TRUE
# 47 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 48 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo
# 49 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree
# 50 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge
# 51 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge
# 52 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge
# 53 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 54 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 55 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRecordBattle::
# 56 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_RecordLastMatch
# 57 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 58 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 59 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 60 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 61 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_RecordBattle
# 62 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 63 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 64 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_RecordBattle::
# 65 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 66 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 67 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 68 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge::
# 69 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 70 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 71 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 72 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleDomePreBattleRoom_EventScript_PauseChallenge
# 73 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 74 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 75 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge::
# 76 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_RetireYourChallenge
# 77 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 78 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 79 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 80 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 81 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_RetireChallenge
# 82 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 83 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 84 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_RetireChallenge::
# 85 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_RETIRED
# 86 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost
# 87 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 88 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_PauseChallenge::
# 89 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_SavingDataPleaseWait
# 90 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 91 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_save CHALLENGE_STATUS_PAUSED
# 92 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	playse SE_SAVE
# 93 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitse
# 94 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 95 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_reset
# 96 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	end
# 97 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 98 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo::
# 99 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_PlayersNextOpponentIsTrainer, MSGBOX_DEFAULT
# 100 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 101 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_showopponentinfo
# 102 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 103 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 104 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 105 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree::
# 106 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowRoundMessage
# 107 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 108 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_showtourneytree
# 109 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 110 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 111 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 112 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowRoundMessage::
# 113 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 114 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 115 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound1
# 116 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound2
# 117 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInSemifinals
# 118 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInFinals
# 119 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 120 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 121 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound1::
# 122 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound1, MSGBOX_DEFAULT
# 123 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 124 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 125 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound2::
# 126 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound2, MSGBOX_DEFAULT
# 127 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 128 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 129 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInSemifinals::
# 130 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInSemifinals, MSGBOX_DEFAULT
# 131 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 132 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 133 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInFinals::
# 134 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInFinals, MSGBOX_DEFAULT
# 135 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 136 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 137 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge::
# 138 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ChooseTwoMons
# 139 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmessage
# 140 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitbuttonpress
# 141 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 142 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 143 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 144 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_0x8005, DOME_BATTLE_PARTY_SIZE  @ 2 of the 3 party mons are selected for battle
# 145 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	special ChoosePartyForBattleFrontier
# 146 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 147 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_resetsketch
# 148 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 149 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_set DOME_DATA_SELECTED_MONS
# 150 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_reduceparty
# 151 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_setopponent
# 152 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
# 153 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	closemessage
# 154 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomePreBattleRoom_Movement_AttendantMoveAside
# 155 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmovement 0
# 156 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerWalkToDoor
# 157 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmovement 0
# 158 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	opendoor 5, 1
# 159 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitdooranim
# 160 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnterDoor
# 161 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitmovement 0
# 162 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	closedoor 5, 1
# 163 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitdooranim
# 164 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM, 9, 5
# 165 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 166 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 167 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	end
# 168 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 169 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForNextRoundMessage::
# 170 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 171 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 172 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound1
# 173 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound2
# 174 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForSemifinals
# 175 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForFinals
# 176 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 177 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 178 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound1::
# 179 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound1
# 180 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 181 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 182 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound2::
# 183 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound2
# 184 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 185 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 186 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForSemifinals::
# 187 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForSemifinals
# 188 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 189 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 190 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForFinals::
# 191 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 192 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 193 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver
# 194 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold
# 195 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver
# 196 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold
# 197 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForFinals
# 198 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 199 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 200 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver::
# 201 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilverShort
# 202 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver, MSGBOX_DEFAULT
# 203 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 204 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 205 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 206 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold::
# 207 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGoldShort
# 208 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold, MSGBOX_DEFAULT
# 209 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 210 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 211 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 212 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilverShort::
# 213 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilverShort, MSGBOX_DEFAULT
# 214 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 215 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 216 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGoldShort::
# 217 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGoldShort, MSGBOX_DEFAULT
# 218 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 219 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 220 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_ReturnFromBattle::
# 221 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 222 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 223 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	special LoadPlayerParty
# 224 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 225 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 226 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitfanfare
# 227 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	special HealPlayerParty
# 228 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_RoundCompleteMessage
# 229 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 230 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	dome_showstatictourneytree
# 231 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	waitstate
# 232 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
# 233 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 234 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_RoundCompleteMessage::
# 235 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 236 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 237 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_Round1Complete
# 238 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_Round2Complete
# 239 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_SemifinalsComplete
# 240 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 241 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 242 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_Round1Complete::
# 243 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_Round1Complete, MSGBOX_DEFAULT
# 244 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 245 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 246 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_Round2Complete::
# 247 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_Round2Complete, MSGBOX_DEFAULT
# 248 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 249 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 250 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_SemifinalsComplete::
# 251 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_SemifinalsComplete, MSGBOX_DEFAULT
# 252 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	return
# 253 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 254 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Movement_AttendantMoveAside:
# 255 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_right
# 256 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	face_left
# 257 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	step_end
# 258 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 259 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter:
# 260 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 261 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 262 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 263 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 264 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	step_end
# 265 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 266 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerWalkToDoor:
# 267 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 268 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	step_end
# 269 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 270 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnterDoor:
# 271 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	walk_up
# 272 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	set_invisible
# 273 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	step_end
# 274 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 275 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound1:
# 276 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your 1st-round match is next.\n"
# 277 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 278 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 279 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound2:
# 280 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your 2nd-round match is next.\n"
# 281 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 282 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 283 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForSemifinals:
# 284 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your semifinal match is next.\n"
# 285 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 286 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 287 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForFinals:
# 288 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your final match is next.\n"
# 289 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 290 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 291 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ChooseTwoMons:
# 292 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Please choose the two POKéMON\n"
# 293 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "that are to appear in battle.$"
# 294 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 295 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_RightThisWay:
# 296 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Right this way, please.$"
# 297 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 298 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_RestoreMonsToFullHealth:
# 299 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Thank you for competing!\p"
# 300 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "I'll restore your POKéMON to\n"
# 301 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "full health.$"
# 302 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 303 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_Round1Complete:
# 304 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "All 1st-round matches have been\n"
# 305 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "completed.\p"
# 306 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "These are the teams that advanced!$"
# 307 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 308 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_Round2Complete:
# 309 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "All 2nd-round matches have been\n"
# 310 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "completed.\p"
# 311 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "These are the teams that advanced!$"
# 312 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 313 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_SemifinalsComplete:
# 314 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "All semifinal matches have been\n"
# 315 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "completed.\p"
# 316 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "These are the teams that advanced!$"
# 317 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 318 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Unused
# 319 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForRound2:
# 320 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for getting through\n"
# 321 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "the 1st round.\p"
# 322 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The 2nd round is next.\n"
# 323 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 324 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 325 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Unused
# 326 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForSemifinals:
# 327 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for advancing\n"
# 328 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "to the semifinals.\p"
# 329 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The best four teams meet in this round.\n"
# 330 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 331 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 332 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Unused
# 333 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForFinals:
# 334 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for advancing\n"
# 335 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "to the final match.\p"
# 336 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "You're one win from the championship.\n"
# 337 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 338 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 339 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_PlayersNextOpponentIsTrainer:
# 340 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "{PLAYER}'s next opponent\n"
# 341 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "is this TRAINER.$"
# 342 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 343 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound1:
# 344 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The tournament is in the 1st round.$"
# 345 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 346 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound2:
# 347 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The tournament is in the 2nd round.$"
# 348 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 349 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInSemifinals:
# 350 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The tournament is in the semifinals.$"
# 351 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 352 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInFinals:
# 353 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "The tournament is up to the final.$"
# 354 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 355 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_SaveAndQuitGame:
# 356 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Would you like to save and\n"
# 357 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "quit the game?$"
# 358 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 359 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_RetireYourChallenge:
# 360 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 361 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Battle Tournament challenge?$"
# 362 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 363 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_SavingDataPleaseWait:
# 364 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "I am saving your data.\n"
# 365 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Please wait.$"
# 366 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 367 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_RecordLastMatch:
# 368 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Should I record your last match\n"
# 369 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "on your FRONTIER PASS?$"
# 370 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 371 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver:
# 372 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for advancing\n"
# 373 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "to the final match.\p"
# 374 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "For the final match, you will challenge\n"
# 375 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "the DOME ACE TUCKER.\p"
# 376 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 377 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 378 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Identical to ReadyForTuckerSilver
# 379 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold:
# 380 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Congratulations for advancing\n"
# 381 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "to the final match.\p"
# 382 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "For the final match, you will challenge\n"
# 383 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "the DOME ACE TUCKER.\p"
# 384 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 385 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 386 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilverShort:
# 387 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your final battle against TUCKER is\n"
# 388 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "next. Are you ready?$"
# 389 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"

# 390 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
@ Identical again
# 391 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGoldShort:
# 392 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "Your final battle against TUCKER is\n"
# 393 "data//maps/BattleFrontier_BattleDomePreBattleRoom/scripts.pory"
	.string "next. Are you ready?$"
