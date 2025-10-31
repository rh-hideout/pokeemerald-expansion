# 1 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_MapScripts::
# 3 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
# 4 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
# 5 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnWarp:
# 8 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
# 9 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
# 12 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 16 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnFrame:
# 17 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
# 18 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
# 19 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
# 20 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
# 21 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
# 22 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 23 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
# 25 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_getstatus
# 26 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 27 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 28 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
# 29 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 30 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 31 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 32 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_setswapped
# 33 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
# 34 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK, 0
# 35 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 36 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 37 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 38 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 39 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 41 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
# 42 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 43 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_isbrain
# 44 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
# 45 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
# 46 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 47 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints
# 48 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 49 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
# 50 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
# 51 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 52 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
# 53 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
# 54 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_givepoints
# 55 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 56 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
# 57 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 58 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 59 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 60 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 61 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 62 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 63 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 64 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
# 65 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 66 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 67 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
# 68 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 69 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
# 70 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 71 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 72 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 73 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 74 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 75 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 76 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 77 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 78 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 79 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
# 80 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 81 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 82 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
# 83 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 84 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 85 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 86 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 87 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
# 88 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 89 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 90 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
# 91 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 92 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
# 93 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 94 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 95 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 96 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 97 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 98 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 99 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
# 100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
# 102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save CHALLENGE_STATUS_SAVING
# 104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge
# 110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
# 112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
# 120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
# 126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
# 130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
# 141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
# 155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
# 167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
# 176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
# 181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
# 182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
# 185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
# 186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
# 189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
# 194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
# 198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
# 201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
# 206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
# 213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
# 220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
# 224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
# 228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
# 232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
# 236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
# 240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
# 244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
# 252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
# 260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper::
# 264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
# 268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
# 274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
# 278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
# 284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
# 298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
# 303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
# 308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
# 313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
# 318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
# 323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
# 327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
# 334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
# 338 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 339 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a SINGLE BATTLE competition using\l"
# 340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a SINGLE BATTLE.\p"
# 345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
# 356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
# 359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Level 50 or Open Level?$"
# 361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
# 363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
# 368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your POKéMON for\n"
# 369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
# 372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
# 375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 382 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
# 383 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 384 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.$"
# 385 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 386 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
# 387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 389 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
# 392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 393 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 394 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
# 397 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 398 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 401 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 402 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
# 403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 405 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 406 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
# 408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 409 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 410 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 413 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 414 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
# 415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal POKéMON.$"
# 416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 417 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 418 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
# 419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 422 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
# 423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 428 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
# 430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
# 434 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a DOUBLE BATTLE competition using\l"
# 436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a DOUBLE BATTLE.\p"
# 441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 442 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 443 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 444 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 445 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 446 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 447 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 448 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 449 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 450 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 451 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
# 452 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 453 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the FACTORY HEAD and winning\l"
# 454 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 455 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 456 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
# 457 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 458 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 459 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 460 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 461 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
# 462 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your POKéMON\n"
# 463 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 464 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 465 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 466 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 467 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
# 468 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 469 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE FACTORY match on your\l"
# 470 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 471 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 472 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
# 473 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 474 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 475 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 476 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 477 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of POKéMON?\p"
# 478 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 479 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 480 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 481 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about POKéMON and their moves,\l"
# 482 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 483 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 484 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
# 485 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak POKéMON…\n"
# 486 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 487 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 488 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 489 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
# 490 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 491 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 492 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 493 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON during battle to see if\l"
# 494 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 495 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 496 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
# 497 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 498 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 499 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 500 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 501 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 502 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 503 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
# 504 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 505 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 506 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 507 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 508 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 509 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental POKéMON.$"
# 510 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 511 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
# 512 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 513 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 514 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
# 515 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 516 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 517 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
# 518 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 519 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three POKéMON.\p"
# 520 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 521 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 522 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same POKéMON.$"
# 523 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 524 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
# 525 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap POKéMON only with\n"
# 526 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the TRAINER you have just defeated.\p"
# 527 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those POKéMON\n"
# 528 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten TRAINER.$"
# 529 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 530 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
# 531 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 532 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 533 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's POKéMON.\p"
# 534 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap POKéMON\n"
# 535 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh TRAINER in the event.$"
# 536 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 537 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
# 538 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 539 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping POKéMON.\p"
# 540 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 541 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the POKéMON you are\l"
# 542 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 543 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the POKéMON on your team\n"
# 544 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 545 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 546 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 547 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 548 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 549 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
# 550 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In the Open Level, the rental POKéMON\n"
# 551 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing TRAINERS' POKéMON\l"
# 552 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"
