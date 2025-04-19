# 1 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
.set LOCALID_ATTENDANT_SINGLES, 1
# 3 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
.set LOCALID_ATTENDANT_DOUBLES, 6
# 4 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 5 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_MapScripts::
# 6 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
# 7 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
# 8 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.byte 0
# 9 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 10 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnWarp:
# 11 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
# 12 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 13 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 14 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
# 15 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 16 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 17 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 18 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 19 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnFrame:
# 20 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
# 21 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
# 22 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
# 23 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
# 24 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
# 25 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 26 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 27 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
# 28 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_getstatus
# 29 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 30 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 31 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
# 32 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 33 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 34 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 35 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_setswapped
# 36 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
# 37 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK, 0
# 38 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 39 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 40 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 41 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 42 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 43 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 44 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
# 45 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 46 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_isbrain
# 47 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
# 48 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
# 49 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 50 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints
# 51 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 52 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
# 53 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
# 54 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 55 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
# 56 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
# 57 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_givepoints
# 58 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 59 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
# 60 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 61 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 62 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 63 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 64 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 65 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 66 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 67 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
# 68 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 69 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 70 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
# 71 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 72 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
# 73 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 74 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 75 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 76 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 77 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 78 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 79 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 80 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 81 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 82 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
# 83 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 84 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 85 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
# 86 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 87 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 88 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 89 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 90 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
# 91 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 92 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 93 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
# 94 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 95 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
# 96 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 97 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 98 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 99 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 100 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 101 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 102 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
# 103 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 104 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
# 105 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 106 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save CHALLENGE_STATUS_SAVING
# 107 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 108 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 109 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 110 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 111 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 112 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge
# 113 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 114 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
# 115 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 116 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 117 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 118 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 119 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 120 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 121 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 122 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
# 123 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 124 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 125 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 126 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 127 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 128 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
# 129 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 130 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 131 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 132 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
# 133 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 134 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 135 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 136 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 137 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 138 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 139 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 140 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 141 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 142 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 143 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
# 144 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 145 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 146 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 147 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 148 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 149 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 150 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 151 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 152 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 153 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 154 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 155 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 156 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 157 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
# 158 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 159 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 160 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 161 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 162 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 163 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 164 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 165 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 166 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 167 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 168 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 169 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
# 170 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 171 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 172 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 173 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 174 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 175 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 176 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 177 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 178 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
# 179 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 180 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 181 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 182 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 183 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
# 184 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
# 185 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 186 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 187 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
# 188 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
# 189 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 190 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 191 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
# 192 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 193 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 194 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 195 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 196 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
# 197 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 198 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 199 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 200 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
# 201 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 202 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 203 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
# 204 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 205 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 206 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 207 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 208 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
# 209 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 210 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 211 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 212 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 213 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 214 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 215 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
# 216 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 217 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 218 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 219 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 220 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 221 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 222 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
# 223 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 224 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 225 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 226 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
# 227 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 228 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 229 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 230 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
# 231 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 232 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 233 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 234 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
# 235 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 236 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 237 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 238 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
# 239 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 240 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 241 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 242 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
# 243 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 244 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 245 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 246 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
# 247 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 248 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 249 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 250 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 251 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 252 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 253 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 254 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
# 255 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 256 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 257 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 258 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 259 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 260 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 261 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 262 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
# 263 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 264 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 265 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 266 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper::
# 267 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 268 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 269 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 270 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
# 271 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 272 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 273 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 274 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 275 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 276 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
# 277 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 278 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 279 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 280 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
# 281 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 282 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 283 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 284 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 285 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 286 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
# 287 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 288 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 289 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 290 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 291 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 292 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 293 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 294 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 295 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 296 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 297 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 298 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 299 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 300 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
# 301 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 302 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 303 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 304 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 305 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
# 306 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 307 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 308 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 309 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 310 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
# 311 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 312 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 313 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 314 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 315 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
# 316 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 317 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 318 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 319 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 320 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
# 321 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 322 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 323 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 324 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 325 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
# 326 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 327 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 328 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 329 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
# 330 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 331 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 332 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 333 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 334 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 335 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 336 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
# 337 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 338 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 339 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 340 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
# 341 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 342 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a SINGLE BATTLE competition using\l"
# 343 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 344 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 345 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 346 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 347 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a SINGLE BATTLE.\p"
# 348 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 349 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 350 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 351 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 352 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 353 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 354 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 355 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 356 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 357 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 358 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
# 359 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 360 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 361 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
# 362 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 363 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Level 50 or Open Level?$"
# 364 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 365 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
# 366 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 367 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 368 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 369 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 370 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
# 371 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your POKéMON for\n"
# 372 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 373 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 374 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
# 375 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 376 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 377 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
# 378 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 379 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 380 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 381 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 382 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 383 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 384 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 385 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
# 386 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 387 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.$"
# 388 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 389 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
# 390 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 391 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 392 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 393 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 394 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
# 395 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 396 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 397 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 398 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 399 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
# 400 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 401 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 402 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 403 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 404 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 405 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
# 406 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 407 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 408 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 409 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 410 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
# 411 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 412 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 413 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 414 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 415 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 416 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 417 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
# 418 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal POKéMON.$"
# 419 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 420 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 421 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
# 422 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 423 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 424 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 425 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
# 426 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 427 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 428 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 429 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 430 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 431 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 432 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
# 433 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 434 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 435 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 436 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
# 437 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 438 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a DOUBLE BATTLE competition using\l"
# 439 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 440 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 441 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 442 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 443 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a DOUBLE BATTLE.\p"
# 444 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 445 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 446 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 447 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 448 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 449 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 450 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 451 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 452 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 453 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 454 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
# 455 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 456 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the FACTORY HEAD and winning\l"
# 457 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 458 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 459 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
# 460 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 461 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 462 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 463 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 464 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
# 465 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your POKéMON\n"
# 466 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 467 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 468 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 469 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 470 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
# 471 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 472 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE FACTORY match on your\l"
# 473 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 474 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 475 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
# 476 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 477 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 478 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 479 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 480 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of POKéMON?\p"
# 481 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 482 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 483 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 484 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about POKéMON and their moves,\l"
# 485 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 486 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 487 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
# 488 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak POKéMON…\n"
# 489 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 490 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 491 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 492 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
# 493 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 494 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 495 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 496 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON during battle to see if\l"
# 497 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 498 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 499 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
# 500 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 501 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 502 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 503 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 504 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 505 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 506 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
# 507 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 508 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 509 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 510 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 511 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 512 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental POKéMON.$"
# 513 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 514 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
# 515 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 516 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 517 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
# 518 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 519 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 520 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
# 521 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 522 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three POKéMON.\p"
# 523 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 524 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 525 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same POKéMON.$"
# 526 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 527 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
# 528 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap POKéMON only with\n"
# 529 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the TRAINER you have just defeated.\p"
# 530 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those POKéMON\n"
# 531 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten TRAINER.$"
# 532 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 533 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
# 534 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 535 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 536 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's POKéMON.\p"
# 537 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap POKéMON\n"
# 538 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh TRAINER in the event.$"
# 539 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 540 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
# 541 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 542 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping POKéMON.\p"
# 543 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 544 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the POKéMON you are\l"
# 545 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 546 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the POKéMON on your team\n"
# 547 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 548 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 549 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 550 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 551 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 552 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
# 553 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In the Open Level, the rental POKéMON\n"
# 554 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing TRAINERS' POKéMON\l"
# 555 "data//maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"
