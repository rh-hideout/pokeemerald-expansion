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

# 53 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardResumeScript::
# 54 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
# 55 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_givepoints
# 56 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 57 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
# 58 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 59 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 60 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 61 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_giverewardmon
# 62 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 63 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FactoryRewardSaveAndExitScript::
# 64 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 65 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 66 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 67 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 68 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
# 69 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 70 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 71 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
# 72 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 73 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
# 74 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 75 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 76 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 77 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 78 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 79 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 80 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 81 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 82 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 83 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
# 84 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 85 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 86 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
# 87 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 88 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 89 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 90 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 91 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
# 92 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 93 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 94 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
# 95 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 96 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
# 97 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 98 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 99 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
# 104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
# 106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save CHALLENGE_STATUS_SAVING
# 108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge
# 114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
# 116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
# 124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
# 130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
# 134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
# 145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
# 159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
# 171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
# 180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
# 185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
# 186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
# 189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
# 190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
# 193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
# 198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
# 202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
# 205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
# 210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
# 217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
# 224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
# 228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
# 232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
# 236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
# 240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
# 244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
# 248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
# 256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
# 264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper::
# 268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
# 272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
# 278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
# 282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
# 288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
# 302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
# 307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
# 312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
# 317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
# 322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
# 327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
# 331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
# 338 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 339 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
# 342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a SINGLE BATTLE competition using\l"
# 344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a SINGLE BATTLE.\p"
# 349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
# 360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
# 363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Level 50 or Open Level?$"
# 365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
# 367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
# 372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your POKéMON for\n"
# 373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
# 376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
# 379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 382 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 383 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 384 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 385 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 386 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
# 387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.$"
# 389 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
# 391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 393 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 394 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
# 396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 397 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 398 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
# 401 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 402 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 405 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 406 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
# 407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 409 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 410 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
# 412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 413 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 414 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 417 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 418 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
# 419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal POKéMON.$"
# 420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 422 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
# 423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
# 427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 428 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
# 434 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
# 438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a DOUBLE BATTLE competition using\l"
# 440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 442 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 443 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 444 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a DOUBLE BATTLE.\p"
# 445 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 446 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 447 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 448 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 449 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 450 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 451 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 452 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 453 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 454 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 455 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
# 456 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 457 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the FACTORY HEAD and winning\l"
# 458 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 459 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 460 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
# 461 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 462 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 463 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 464 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 465 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
# 466 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your POKéMON\n"
# 467 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 468 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 469 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 470 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 471 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
# 472 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 473 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE FACTORY match on your\l"
# 474 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 475 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 476 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
# 477 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 478 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 479 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 480 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 481 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of POKéMON?\p"
# 482 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 483 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 484 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 485 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about POKéMON and their moves,\l"
# 486 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 487 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 488 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
# 489 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak POKéMON…\n"
# 490 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 491 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 492 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 493 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
# 494 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 495 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 496 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 497 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON during battle to see if\l"
# 498 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 499 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 500 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
# 501 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 502 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 503 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 504 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 505 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 506 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 507 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
# 508 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 509 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 510 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 511 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 512 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 513 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental POKéMON.$"
# 514 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 515 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
# 516 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 517 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 518 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
# 519 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 520 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 521 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
# 522 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 523 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three POKéMON.\p"
# 524 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 525 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 526 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same POKéMON.$"
# 527 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 528 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
# 529 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap POKéMON only with\n"
# 530 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the TRAINER you have just defeated.\p"
# 531 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those POKéMON\n"
# 532 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten TRAINER.$"
# 533 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 534 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
# 535 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 536 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 537 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's POKéMON.\p"
# 538 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap POKéMON\n"
# 539 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh TRAINER in the event.$"
# 540 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 541 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
# 542 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 543 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping POKéMON.\p"
# 544 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 545 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the POKéMON you are\l"
# 546 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 547 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the POKéMON on your team\n"
# 548 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 549 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 550 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 551 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 552 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 553 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
# 554 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In the Open Level, the rental POKéMON\n"
# 555 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing TRAINERS' POKéMON\l"
# 556 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"

BattleFrontier_BattleFactoryLobby_Noland::
# 560 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 561 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Noland_Text_0
# 562 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions::
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 567 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 568 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_3
# 570 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4
# 572 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5
# 574 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_6
# 576 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7
# 579 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1:
# 581 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_3:
# 569 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4:
# 571 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5:
# 573 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_6:
# 575 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7:
# 577 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions::
# 585 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_2
# 589 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_1
BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_1:
# 591 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_2
# 592 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_5
# 593 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 594 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_6
# 598 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_7
# 602 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_8
# 605 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_2:
# 586 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_6:
# 595 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 596 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_6
# 597 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_7:
# 599 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 600 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_7
# 601 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_8:
# 603 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions::
# 613 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0
# 614 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 615 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 616 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_3
# 618 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4
# 620 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5
# 622 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_6
# 625 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1:
# 627 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_3:
# 617 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4:
# 619 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5:
# 621 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_6:
# 623 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode::
# 631 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2
# 635 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1:
# 637 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4
# 639 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 640 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_7
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5:
# 647 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2:
# 632 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_7:
# 641 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8:
# 644 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6
# 645 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode::
# 651 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2
# 655 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1:
# 657 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2
# 658 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4
# 659 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 660 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_7
# 663 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5:
# 667 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2:
# 652 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_7:
# 661 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3
# 662 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8:
# 664 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4
# 665 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode::
# 671 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2
# 675 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1:
# 677 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2
# 678 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4
# 679 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 680 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_7
# 683 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5:
# 687 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2:
# 672 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_7:
# 681 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3
# 682 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8:
# 684 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4
# 685 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions::
# 691 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0
# 692 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 694 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 695 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2
# 697 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_3
# 699 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_4
# 701 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5
# 703 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7
# 707 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8
# 711 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9
# 714 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2:
# 696 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_3:
# 698 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_4:
# 700 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5:
# 702 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6:
# 704 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7:
# 706 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8:
# 708 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_BGM
# 709 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 710 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9:
# 712 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE::
# 719 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0
# 720 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_5
# 724 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 725 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3
# 727 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4
# 729 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5
# 731 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6
# 733 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7
# 735 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8
# 737 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9
# 739 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10
# 741 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11
# 743 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12
# 745 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13
# 747 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14
# 749 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15
# 752 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1:
# 754 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 755 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 756 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3:
# 726 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4:
# 728 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5:
# 730 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6:
# 732 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 3
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7:
# 734 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 4
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8:
# 736 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 5
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9:
# 738 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 6
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10:
# 740 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11:
# 742 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 8
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12:
# 744 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 9
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13:
# 746 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 10
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14:
# 748 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 11
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15:
# 750 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg::
# 760 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0
# 761 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_5
# 765 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 766 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3
# 768 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4
# 770 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5
# 772 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6
# 774 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7
# 776 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8
# 778 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9
# 780 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10
# 783 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1:
# 785 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 786 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 787 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3:
# 767 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4:
# 769 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 13
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5:
# 771 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 14
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6:
# 773 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 15
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7:
# 775 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 16
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8:
# 777 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9:
# 779 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 18
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10:
# 781 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP::
# 791 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0
# 792 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_5
# 797 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 798 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3
# 800 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4
# 802 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5
# 804 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6
# 806 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7
# 808 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8
# 810 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9
# 812 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10
# 814 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11
# 816 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12
# 818 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13
# 820 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14
# 822 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15
# 824 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16
# 827 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1:
# 829 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 830 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 831 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3:
# 799 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 19
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4:
# 801 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 20
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5:
# 803 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 21
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6:
# 805 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7:
# 807 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 23
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8:
# 809 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9:
# 811 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 25
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10:
# 813 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 26
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11:
# 815 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 27
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12:
# 817 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 28
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13:
# 819 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 29
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14:
# 821 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 30
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15:
# 823 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 31
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16:
# 825 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum::
# 835 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0
# 836 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_5
# 838 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 839 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3
# 841 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5
# 845 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6
# 848 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1:
# 850 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 851 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 852 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3:
# 840 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 32
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4:
# 842 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 33
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5:
# 844 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 34
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6:
# 846 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs::
# 856 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0
# 857 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_5
# 863 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 864 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3
# 866 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4
# 868 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5
# 870 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6
# 872 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7
# 874 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8
# 876 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9
# 878 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10
# 880 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11
# 882 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12
# 884 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13
# 886 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14
# 888 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15
# 890 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16
# 892 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17
# 894 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18
# 896 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19
# 898 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20
# 901 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1:
# 903 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 904 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 905 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3:
# 865 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 35
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4:
# 867 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 36
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5:
# 869 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 37
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6:
# 871 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 38
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7:
# 873 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 39
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8:
# 875 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 40
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9:
# 877 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 41
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10:
# 879 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 42
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11:
# 881 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 43
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12:
# 883 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 44
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13:
# 885 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 45
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14:
# 887 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 46
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15:
# 889 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 47
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16:
# 891 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 48
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17:
# 893 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 49
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18:
# 895 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 50
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19:
# 897 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 51
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20:
# 899 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite::
# 909 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_5
# 916 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 917 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3
# 919 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4
# 921 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5
# 923 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6
# 925 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7
# 927 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8
# 929 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9
# 931 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10
# 933 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11
# 935 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12
# 937 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14
# 941 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15
# 943 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16
# 945 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17
# 947 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18
# 949 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19
# 951 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20
# 953 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21
# 955 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22
# 957 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23
# 960 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1:
# 962 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 963 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 964 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3:
# 918 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 52
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4:
# 920 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 53
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5:
# 922 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 54
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6:
# 924 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 55
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7:
# 926 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 56
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8:
# 928 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 57
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9:
# 930 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 58
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10:
# 932 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 59
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11:
# 934 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 60
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12:
# 936 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 61
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13:
# 938 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 62
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14:
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 63
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15:
# 942 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 64
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16:
# 944 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 65
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17:
# 946 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 66
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18:
# 948 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 67
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19:
# 950 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 68
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20:
# 952 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 69
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21:
# 954 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 70
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22:
# 956 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 71
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23:
# 958 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions::
# 968 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0
# 969 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 975 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 976 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_3
# 979 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4
# 981 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_5
# 984 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6
# 987 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7
# 990 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8
# 993 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9
# 996 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10
# 999 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11
# 1002 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12
# 1005 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13
# 1008 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14
# 1011 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15
# 1014 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16
# 1017 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17
# 1020 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18
# 1023 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19
# 1026 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20
# 1029 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21
# 1032 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22
# 1035 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23
# 1038 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24
# 1041 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25
# 1044 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26
# 1047 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 24, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27
# 1050 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1:
# 1052 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1053 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_3:
# 977 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 0
# 978 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4:
# 980 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_5:
# 982 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 1
# 983 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6:
# 985 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 2
# 986 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7:
# 988 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 3
# 989 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8:
# 991 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 4
# 992 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9:
# 994 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 5
# 995 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10:
# 997 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 6
# 998 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11:
# 1000 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 7
# 1001 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12:
# 1003 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 8
# 1004 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13:
# 1006 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 9
# 1007 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14:
# 1009 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 10
# 1010 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15:
# 1012 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 11
# 1013 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16:
# 1015 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 12
# 1016 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17:
# 1018 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 13
# 1019 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18:
# 1021 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 14
# 1022 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19:
# 1024 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 15
# 1025 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20:
# 1027 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 16
# 1028 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21:
# 1030 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 17
# 1031 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22:
# 1033 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 18
# 1034 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23:
# 1036 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 19
# 1037 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24:
# 1039 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 20
# 1040 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25:
# 1042 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 21
# 1043 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26:
# 1045 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 22
# 1046 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27:
# 1048 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess::
# 1057 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1058 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0
# 1059 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1060 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess::
# 1064 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1065 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0
# 1066 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1067 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse::
# 1071 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0
# 1072 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
# 1076 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_Text_0
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_selectrewardmon
	return


BattleFrontier_BattleFactoryLobby_Noland_Text_0:
# 561 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, {PLAYER}. Can't handle the heat?\n"
	.string "Or just fancy a new challenge? Let me\l"
	.string "know and I'll adjust some things for ya.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0:
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GIMMICK OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1:
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MUSIC OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2:
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACKGROUND OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3:
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE MODE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4:
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CANCEL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_0:
# 586 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE MODE is currently set to RANDOM\n"
	.string "BATTLES.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_1:
# 589 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE MODE is currently set to\n"
	.string "CLASSIC FACTORY.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_2:
# 591 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Choose which BATTLE MODE to use in the\n"
	.string "BATTLE FACTORY.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_3:
# 592 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CLASSIC FACTORY$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_4:
# 592 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "RANDOM BATTLES$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_5:
# 592 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACK$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_6:
# 596 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Classic Factory mode selected.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBattleModeOptions_Text_7:
# 600 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Random Battles mode selected.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0:
# 613 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Interested in spicing up your battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1:
# 614 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2:
# 614 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3:
# 614 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0:
# 632 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1:
# 635 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2:
# 637 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change\n"
	.string "TERASTALLISATION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ENABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DISABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5:
# 641 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled TERASTALLISATION!\n"
	.string "POKéMON with the TERA BLAST move will\l"
	.string "also be added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6:
# 644 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled TERASTALLISATION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0:
# 652 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1:
# 655 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2:
# 657 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change MEGA\n"
	.string "EVOLUTION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3:
# 661 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled MEGA EVOLUTION! POKéMON\n"
	.string "with the ability to MEGA EVOLVE will be\l"
	.string "added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4:
# 664 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled MEGA EVOLUTION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0:
# 672 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1:
# 675 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2:
# 677 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change Z-MOVE mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3:
# 681 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled Z-MOVES! POKéMON with the\n"
	.string "ability to use Z-MOVES will be added to\l"
	.string "the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4:
# 684 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled Z-MOVES!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0:
# 691 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I can change the music that plays\n"
	.string "during your battles!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1:
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "R/S/E MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2:
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FR/LG MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3:
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "D/P MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4:
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLATINUM MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5:
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "HG/SS MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6:
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BLACK/WHITE MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7:
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SHUFFLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0:
# 719 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Ruby, Sapphire\n"
	.string "and Emerald:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. FRONTIER BRAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEW$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM AQUA & MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6:
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7:
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8:
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. REGI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9:
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE & GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10:
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RIVAL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11:
# 723 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ELITE FOUR$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12:
# 723 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. AQUA & MAGMA LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0:
# 760 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from FireRed and\n"
	.string "LeafGreen:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1:
# 763 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. DEOXYS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2:
# 764 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEWTWO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3:
# 764 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LEGEND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0:
# 791 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Diamond and\n"
	.string "Pearl:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1:
# 793 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. UXIE/ASELF/MESPRIT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2:
# 794 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC BOSS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3:
# 794 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS DIALGA/PALKIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4:
# 795 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5:
# 795 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ARCEUS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6:
# 796 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GALACTIC COMMANDER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0:
# 835 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Platinum:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1:
# 837 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GIRATINA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0:
# 856 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from HeartGold and\n"
	.string "SoulSilver:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1:
# 859 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM ROCKET$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2:
# 859 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUICUNE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3:
# 860 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ENTEI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4:
# 860 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RAIKOU$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5:
# 860 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6:
# 861 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7:
# 861 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8:
# 861 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. HO-OH$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9:
# 861 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LUGIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10:
# 862 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE/GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0:
# 909 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Black and\n"
	.string "White:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM PLASMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2:
# 912 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WINNING THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3:
# 912 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (1)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4:
# 912 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. IN A PINCH THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5:
# 913 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RESHIRAM/ZEKROM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6:
# 913 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (2)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7:
# 913 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GHETSIS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8:
# 914 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUBWAY TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9:
# 914 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CYNTHIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10:
# 914 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. STRONG WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11:
# 915 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYUREM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12:
# 915 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WCS CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0:
# 968 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Fancy a new lick of paint on your\n"
	.string "battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1:
# 970 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DEFAULT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2:
# 970 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3:
# 970 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "LONG GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4:
# 970 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SAND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5:
# 970 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "UNDERWATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6:
# 970 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "WATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7:
# 971 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8:
# 971 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MOUNTAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9:
# 971 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAVE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10:
# 971 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BUILDING$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11:
# 971 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12:
# 972 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13:
# 972 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14:
# 972 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15:
# 972 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM AQUA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR SIDNEY$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR PHOEBE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR GLACIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19:
# 974 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR DRAKE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20:
# 974 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21:
# 974 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22:
# 974 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "KYOGRE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23:
# 974 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "RAYQUAZA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0:
# 1058 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your music selection has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0:
# 1065 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your background has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0:
# 1071 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Is there anything else I can help you\n"
	.string "with?$"

BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_Text_0:
# 1076 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a reward for your display of skill,\n"
	.string "you will be able to select one of the\l"
	.string "POKéMON in your party to keep forever,\l"
	.string "for use in other BATTLE FRONTIER\l"
	.string "facilities.$"
