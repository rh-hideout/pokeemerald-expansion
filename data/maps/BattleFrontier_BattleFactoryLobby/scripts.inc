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
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
# 125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendant::
# 132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE
# 135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain
# 138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain::
# 141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForRandomBattle, MSGBOX_DEFAULT
# 143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeRandomChallenge
# 144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesTryEnterChallenge
# 148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesExplainChallenge
# 149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesExplainChallenge::
# 153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainRandomChallenge, MSGBOX_DEFAULT
# 154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesAttendantMain
# 155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RandomBattlesTryEnterChallenge::
# 157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
# 158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
# 165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
# 169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
# 180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
# 194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
# 206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_RANDOM_BATTLES_MODE, BattleFrontier_BattleFactoryLobby_EventScript_UseCurrentTalkedNpc
# 210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_UseCurrentTalkedNpc::
# 213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
# 217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
# 222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
# 223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
# 226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
# 227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
# 230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
# 235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
# 239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
# 242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
# 247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
# 254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
# 261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
# 265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
# 269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
# 273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
# 277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
# 281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
# 285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
# 293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
# 301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper::
# 305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
# 309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
# 315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
# 319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
# 325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 338 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
# 339 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
# 344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
# 349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
# 354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
# 359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
# 364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
# 368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
# 375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
# 379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a SINGLE BATTLE competition using\l"
# 381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 382 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 383 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 384 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 385 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a SINGLE BATTLE.\p"
# 386 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 389 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 390 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 393 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 394 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
# 397 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 398 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
# 400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 401 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Level 50 or Open Level?$"
# 402 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
# 404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 405 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 406 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
# 409 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your POKéMON for\n"
# 410 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
# 413 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 414 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
# 416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 417 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 418 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 422 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
# 424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your POKéMON in exchange\n"
# 425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.$"
# 426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
# 428 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
# 433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 434 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
# 438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 442 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 443 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
# 444 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 445 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 446 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 447 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 448 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
# 449 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 450 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 451 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 452 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 453 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 454 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 455 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
# 456 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal POKéMON.$"
# 457 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 458 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 459 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
# 460 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 461 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 462 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 463 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
# 464 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 465 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 466 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 467 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 468 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 469 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 470 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
# 471 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 472 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 473 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 474 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
# 475 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 476 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a DOUBLE BATTLE competition using\l"
# 477 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental POKéMON.\p"
# 478 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 479 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON specifically for this event.\p"
# 480 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental POKéMON,\n"
# 481 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a DOUBLE BATTLE.\p"
# 482 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 483 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental POKéMON.\p"
# 484 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 485 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 486 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 487 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 488 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 489 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 490 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 491 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 492 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForRandomBattle:
# 493 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of TRAINERS\n"
# 494 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 495 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 496 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Random\n"
# 497 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battles challenge.\p"
# 498 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please note: this mode is still under\n"
# 499 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "development and may contain bugs.$"
# 500 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 501 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeRandomChallenge:
# 502 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Random\n"
# 503 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battles challenge?$"
# 504 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 505 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainRandomChallenge:
# 506 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This challenge uses rental POKeMON\n"
# 507 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "sets from a Random Battles pool.\p"
# 508 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please note: this mode is under\n"
# 509 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "development, so issues may occur.\p"
# 510 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Unlike Level 50 or Open Level modes,\n"
# 511 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "each rental set has its own level,\l"
# 512 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "balanced for that set.\p"
# 513 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Rules for battling and swapping are\n"
# 514 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "otherwise the same as the regular\l"
# 515 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap challenge.$"
# 516 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 517 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
# 518 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 519 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the FACTORY HEAD and winning\l"
# 520 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 521 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 522 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
# 523 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 524 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 525 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 526 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 527 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
# 528 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your POKéMON\n"
# 529 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental POKéMON.\p"
# 530 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 531 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 532 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 533 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
# 534 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 535 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE FACTORY match on your\l"
# 536 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 537 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 538 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
# 539 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 540 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 541 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 542 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 543 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of POKéMON?\p"
# 544 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 545 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 546 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 547 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about POKéMON and their moves,\l"
# 548 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 549 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 550 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
# 551 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak POKéMON…\n"
# 552 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 553 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 554 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 555 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
# 556 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 557 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 558 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 559 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POKéMON during battle to see if\l"
# 560 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 561 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 562 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
# 563 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 564 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 565 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 566 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 567 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 568 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 569 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
# 570 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 571 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 572 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 573 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 574 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 575 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental POKéMON.$"
# 576 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 577 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
# 578 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 579 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 580 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
# 581 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 582 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 583 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
# 584 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 585 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three POKéMON.\p"
# 586 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 587 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 588 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same POKéMON.$"
# 589 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 590 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
# 591 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap POKéMON only with\n"
# 592 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the TRAINER you have just defeated.\p"
# 593 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those POKéMON\n"
# 594 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten TRAINER.$"
# 595 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 596 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
# 597 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 598 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 599 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's POKéMON.\p"
# 600 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap POKéMON\n"
# 601 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh TRAINER in the event.$"
# 602 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 603 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
# 604 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 605 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping POKéMON.\p"
# 606 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 607 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the POKéMON you are\l"
# 608 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 609 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the POKéMON on your team\n"
# 610 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 611 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 612 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 613 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 614 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 615 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
# 616 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In the Open Level, the rental POKéMON\n"
# 617 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing TRAINERS' POKéMON\l"
# 618 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"

BattleFrontier_BattleFactoryLobby_Noland::
# 622 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 623 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Noland_Text_0
# 624 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices
# 625 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions::
# 629 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1:
# 632 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4:
# 635 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 639 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 640 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_12
# 642 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_13
# 644 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_14
# 646 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_15
# 648 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_16
# 651 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10:
# 653 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_2:
# 630 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_5:
# 633 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_8:
# 636 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_12:
# 641 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_13:
# 643 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_14:
# 645 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_15:
# 647 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_16:
# 649 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_10


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic::
# 657 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 658 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 659 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_3
# 661 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_4
# 664 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1:
# 666 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_3:
# 660 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_4:
# 662 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreMusic_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground::
# 670 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 671 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 672 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_3
# 674 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_4
# 676 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_5
# 679 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1:
# 681 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_3:
# 673 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_4:
# 675 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_5:
# 677 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreBackground_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks::
# 685 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 686 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 687 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_3
# 689 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_4
# 691 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_5
# 693 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_6
# 696 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1:
# 698 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_3:
# 688 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_4:
# 690 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_5:
# 692 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_6:
# 694 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_PreGimmicks_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins::
# 702 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_FACTORY_TOTAL_WINS
# 703 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_0
# 704 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_1:
# 708 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_4:
# 712 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_8
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_7:
# 716 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_10:
# 720 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_14
BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_13:
# 724 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_6
# 725 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_2:
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_1
# 706 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_5:
# 709 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_2
# 710 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_8:
# 713 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_3
# 714 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_11:
# 717 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_4
# 718 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_10

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_14:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_5
# 722 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_13


BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices::
# 729 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1:
# 737 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4:
# 745 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_10
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9:
# 753 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_15
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14:
# 761 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_ge BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_20
BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19:
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_2:
# 730 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MUSIC, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_5:
# 738 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_BACKGROUND, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_7:
# 731 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 732 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 733 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_0
# 734 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MUSIC
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_10:
# 746 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MEGA, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_12:
# 739 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 740 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 741 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_1
# 742 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_BACKGROUND
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_15:
# 754 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_17:
# 747 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 748 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 749 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_2
# 750 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_MEGA
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_9

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_20:
# 762 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_unset FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_TERA, BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_22:
# 755 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 756 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 757 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_3
# 758 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_14

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_24:
# 763 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 764 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitfanfare
# 765 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_4
# 766 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_UNLOCK_NOTICE_TERA
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_19


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions::
# 776 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0
# 777 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1:
# 780 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4:
# 783 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 784 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 785 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_9
# 787 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_10
# 789 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_11
# 791 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_12
# 794 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7:
# 796 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_2:
# 778 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_5:
# 781 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_9:
# 786 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_10:
# 788 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_11:
# 790 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_12:
# 792 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_7


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly::
# 800 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 801 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 802 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_3
# 804 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_4
# 807 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1:
# 809 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_3:
# 803 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_4:
# 805 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaOnly_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ::
# 813 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 814 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 815 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_3
# 817 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_4
# 819 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_5
# 822 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1:
# 824 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_3:
# 816 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_4:
# 818 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_5:
# 820 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_MegaAndZ_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode::
# 828 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 50
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1:
# 832 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5
# 836 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_4:
# 838 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3
# 839 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 840 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 841 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_10
# 844 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8:
# 848 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_2:
# 829 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0
# 830 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_5:
# 833 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_10:
# 842 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6
# 843 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_11:
# 845 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_7
# 846 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode::
# 852 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 30
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1:
# 856 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5
# 860 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_4:
# 862 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3
# 863 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 864 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 865 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_10
# 868 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8:
# 872 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_2:
# 853 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0
# 854 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_5:
# 857 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_10:
# 866 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4
# 867 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_11:
# 869 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_5
# 870 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode::
# 876 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 40
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1:
# 880 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5
# 884 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_4:
# 886 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3
# 887 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5
# 888 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 889 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_10
# 892 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_11
BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8:
# 896 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_2:
# 877 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0
# 878 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_5:
# 881 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_10:
# 890 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4
# 891 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_11:
# 893 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_5
# 894 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_8


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions::
# 900 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 10
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_1:
# 904 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1
# 905 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 907 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 908 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5
# 910 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6
# 912 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7
# 914 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8
# 916 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9
# 918 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_10
# 920 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_11
# 924 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_12
# 927 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_2:
# 901 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0
# 902 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_5:
# 909 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_6:
# 911 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_7:
# 913 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_8:
# 915 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_9:
# 917 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_10:
# 919 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_11:
# 921 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_BGM
# 922 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 923 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_12:
# 925 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE::
# 932 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0
# 933 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 937 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 938 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3
# 940 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4
# 942 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5
# 944 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6
# 946 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7
# 948 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8
# 950 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9
# 952 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10
# 954 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11
# 956 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12
# 958 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13
# 960 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14
# 962 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15
# 965 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1:
# 967 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 968 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 969 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_3:
# 939 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_4:
# 941 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 1
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_5:
# 943 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_6:
# 945 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 3
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_7:
# 947 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 4
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_8:
# 949 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 5
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_9:
# 951 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 6
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_10:
# 953 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 7
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_11:
# 955 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 8
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_12:
# 957 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 9
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_13:
# 959 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 10
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_14:
# 961 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 11
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_15:
# 963 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg::
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0
# 974 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 978 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 979 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3
# 981 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4
# 983 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5
# 985 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6
# 987 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7
# 989 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8
# 991 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9
# 993 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10
# 996 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1:
# 998 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 999 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1000 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_3:
# 980 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 12
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_4:
# 982 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 13
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_5:
# 984 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 14
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_6:
# 986 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 15
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_7:
# 988 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 16
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_8:
# 990 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 17
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_9:
# 992 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 18
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_10:
# 994 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP::
# 1004 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0
# 1005 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1010 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1011 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3
# 1013 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4
# 1015 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5
# 1017 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6
# 1019 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7
# 1021 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8
# 1023 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9
# 1025 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10
# 1027 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11
# 1029 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12
# 1031 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13
# 1033 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14
# 1035 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15
# 1037 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16
# 1040 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1:
# 1042 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1043 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1044 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_3:
# 1012 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 19
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_4:
# 1014 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 20
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_5:
# 1016 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 21
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_6:
# 1018 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 22
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_7:
# 1020 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 23
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_8:
# 1022 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 24
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_9:
# 1024 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 25
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_10:
# 1026 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 26
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_11:
# 1028 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 27
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_12:
# 1030 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 28
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_13:
# 1032 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 29
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_14:
# 1034 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 30
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_15:
# 1036 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 31
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_16:
# 1038 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum::
# 1048 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0
# 1049 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1051 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1052 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3
# 1054 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4
# 1056 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5
# 1058 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6
# 1061 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1:
# 1063 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1064 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1065 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_3:
# 1053 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 32
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_4:
# 1055 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 33
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_5:
# 1057 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 34
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_6:
# 1059 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs::
# 1069 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0
# 1070 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1076 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1077 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3
# 1079 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4
# 1081 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5
# 1083 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6
# 1085 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7
# 1087 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8
# 1089 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9
# 1091 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10
# 1093 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11
# 1095 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12
# 1097 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13
# 1099 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14
# 1101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15
# 1103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16
# 1105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17
# 1107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18
# 1109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19
# 1111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20
# 1114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1:
# 1116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_3:
# 1078 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 35
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_4:
# 1080 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 36
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_5:
# 1082 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 37
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_6:
# 1084 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 38
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_7:
# 1086 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 39
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_8:
# 1088 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 40
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_9:
# 1090 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 41
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_10:
# 1092 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 42
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_11:
# 1094 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 43
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_12:
# 1096 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 44
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_13:
# 1098 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 45
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_14:
# 1100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 46
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_15:
# 1102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 47
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_16:
# 1104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 48
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_17:
# 1106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 49
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_18:
# 1108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 50
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_19:
# 1110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 51
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_20:
# 1112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite::
# 1122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0
# 1123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13
# 1129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3
# 1132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4
# 1134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5
# 1136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6
# 1138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7
# 1140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8
# 1142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9
# 1144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10
# 1146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11
# 1148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12
# 1150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13
# 1152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14
# 1154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15
# 1156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16
# 1158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17
# 1160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18
# 1162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19
# 1164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20
# 1166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21
# 1168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22
# 1170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23
# 1173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1:
# 1175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_BGM
# 1176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_3:
# 1131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 52
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_4:
# 1133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 53
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_5:
# 1135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 54
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_6:
# 1137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 55
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_7:
# 1139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 56
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_8:
# 1141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 57
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_9:
# 1143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 58
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_10:
# 1145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 59
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_11:
# 1147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 60
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_12:
# 1149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 61
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_13:
# 1151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 62
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_14:
# 1153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 63
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_15:
# 1155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 64
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_16:
# 1157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 65
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_17:
# 1159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 66
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_18:
# 1161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 67
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_19:
# 1163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 68
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_20:
# 1165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 69
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_21:
# 1167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 70
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_22:
# 1169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BGM, 71
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_23:
# 1171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_1


BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions::
# 1181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FACTORY_TOTAL_WINS, 20
	goto_if_lt BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_2
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1:
# 1185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1
# 1186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2, BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_24, BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4
# 1192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 1193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6
# 1196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7
# 1198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8
# 1201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9
# 1204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10
# 1207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11
# 1210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 6, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12
# 1213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 7, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13
# 1216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 8, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14
# 1219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 9, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15
# 1222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 10, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16
# 1225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 11, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17
# 1228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 12, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18
# 1231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 13, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19
# 1234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 14, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20
# 1237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 15, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21
# 1240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 16, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22
# 1243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 17, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23
# 1246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 18, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24
# 1249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 19, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25
# 1252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 20, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26
# 1255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 21, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27
# 1258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 22, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_28
# 1261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 23, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_29
# 1264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 24, BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_30
# 1267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4:
# 1269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess
	return

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_2:
# 1182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0
# 1183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_1

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_6:
# 1194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 0
# 1195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_7:
# 1197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_8:
# 1199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 1
# 1200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_9:
# 1202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 2
# 1203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_10:
# 1205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 3
# 1206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_11:
# 1208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 4
# 1209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_12:
# 1211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 5
# 1212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_13:
# 1214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 6
# 1215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_14:
# 1217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 7
# 1218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_15:
# 1220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 8
# 1221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_16:
# 1223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 9
# 1224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_17:
# 1226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 10
# 1227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_18:
# 1229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 11
# 1230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_19:
# 1232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 12
# 1233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_20:
# 1235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 13
# 1236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_21:
# 1238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 14
# 1239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_22:
# 1241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 15
# 1242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_23:
# 1244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 16
# 1245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_24:
# 1247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 17
# 1248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_25:
# 1250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 18
# 1251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_26:
# 1253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 19
# 1254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_27:
# 1256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 20
# 1257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_28:
# 1259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 21
# 1260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_29:
# 1262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_ENVIRONMENT, 22
# 1263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	clearflag FLAG_SHUFFLE_FRONTIER_ENVIRONMENT
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_30:
# 1265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_4


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess::
# 1274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0
# 1276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess::
# 1281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SUCCESS
# 1282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0
# 1283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 1284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse
	return


BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse::
# 1288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0
# 1289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions
	return


BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
# 1293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_Text_0
# 1295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_selectrewardmon
	return


BattleFrontier_BattleFactoryLobby_Noland_Text_0:
# 623 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, {PLAYER}. Can't handle the heat?\n"
	.string "Or just fancy a new challenge? Let me\l"
	.string "know and I'll adjust some things for ya.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_0:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GIMMICK OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_1:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MUSIC OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_2:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACKGROUND OPTIONS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_3:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TOTAL WINS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandOptions_Text_4:
# 638 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CANCEL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_0:
# 703 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You've won {STR_VAR_1} Battle\n"
	.string "Factory battle(s) in total.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_1:
# 705 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 10 wins: MUSIC OPTIONS.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_2:
# 709 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 20 wins: BACKGROUND\n"
	.string "OPTIONS.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_3:
# 713 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 30 wins: MEGA EVOLUTION.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_4:
# 717 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 40 wins: Z-MOVES.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_5:
# 721 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Next unlock at 50 wins:\n"
	.string "TERASTALLISATION.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandShowTotalWins_Text_6:
# 724 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All current Noland options are\n"
	.string "unlocked.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_0:
# 733 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hey, nice going! You've unlocked MUSIC\n"
	.string "OPTIONS!\p"
	.string "From now on, I can tune your battles\n"
	.string "however you like--pick your tracks or\l"
	.string "let me shuffle them.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_1:
# 741 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whoa! You're on a roll--BACKGROUND\n"
	.string "OPTIONS unlocked!\p"
	.string "Now you can pick your battle scenery,\n"
	.string "or leave it to chance with a shuffle.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_2:
# 749 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Now that's battle sense! MEGA\n"
	.string "EVOLUTION is unlocked!\p"
	.string "Want mega power in your runs? Just tell\n"
	.string "me and I'll switch it on--or off.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_3:
# 757 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You're really heating up! Z-MOVES are\n"
	.string "unlocked!\p"
	.string "If you want high-impact finishes, I can\n"
	.string "enable them for your Factory runs\l"
	.string "anytime.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandCheckUnlockNotices_Text_4:
# 765 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Outstanding battling! You've unlocked\n"
	.string "TERASTALLISATION!\p"
	.string "You've got the full set now--I can\n"
	.string "toggle it on or off for your next\l"
	.string "challenge.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_0:
# 776 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Interested in spicing up your battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_1:
# 783 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_2:
# 783 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandGimmickOptions_Text_3:
# 783 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_0:
# 829 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION unlocks at 50 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_1:
# 833 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_2:
# 836 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TERASTALLISATION is currently\n"
	.string "DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_3:
# 838 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change\n"
	.string "TERASTALLISATION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_4:
# 839 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ENABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_5:
# 839 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DISABLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_6:
# 842 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled TERASTALLISATION!\n"
	.string "POKéMON with the TERA BLAST move will\l"
	.string "also be added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseTeraMode_Text_7:
# 845 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled TERASTALLISATION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_0:
# 853 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION unlocks at 30 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_1:
# 857 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_2:
# 860 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MEGA EVOLUTION is currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_3:
# 862 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change MEGA\n"
	.string "EVOLUTION mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_4:
# 866 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled MEGA EVOLUTION! POKéMON\n"
	.string "with the ability to MEGA EVOLVE will be\l"
	.string "added to the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseMegaMode_Text_5:
# 869 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled MEGA EVOLUTION!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_0:
# 877 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES unlock at 40 total Battle\n"
	.string "Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_1:
# 881 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently ENABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_2:
# 884 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Z-MOVES are currently DISABLED.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_3:
# 886 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to change Z-MOVE mode?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_4:
# 890 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You enabled Z-MOVES! POKéMON with the\n"
	.string "ability to use Z-MOVES will be added to\l"
	.string "the selection pool.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChooseZMoveMode_Text_5:
# 893 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You disabled Z-MOVES!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_0:
# 901 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Music options unlock at 10 total Battle\n"
	.string "Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_1:
# 904 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I can change the music that plays\n"
	.string "during your battles!$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_2:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "R/S/E MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_3:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FR/LG MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_4:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "D/P MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_5:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLATINUM MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_6:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "HG/SS MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_7:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BLACK/WHITE MUSIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Text_8:
# 906 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SHUFFLE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_0:
# 932 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Ruby, Sapphire\n"
	.string "and Emerald:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_1:
# 934 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_2:
# 934 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. FRONTIER BRAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_3:
# 934 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEW$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_4:
# 934 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_5:
# 934 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM AQUA & MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_6:
# 935 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_7:
# 935 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_8:
# 935 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. REGI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_9:
# 935 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE & GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_10:
# 935 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RIVAL$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_11:
# 936 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ELITE FOUR$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_12:
# 936 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. AQUA & MAGMA LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_RSE_Text_13:
# 936 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BACK$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_0:
# 973 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from FireRed and\n"
	.string "LeafGreen:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_1:
# 976 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. DEOXYS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_2:
# 977 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. MEWTWO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_FrLg_Text_3:
# 977 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LEGEND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_0:
# 1004 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Diamond and\n"
	.string "Pearl:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_1:
# 1006 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. UXIE/ASELF/MESPRIT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_2:
# 1007 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC BOSS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_3:
# 1007 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS DIALGA/PALKIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_4:
# 1008 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM GALACTIC$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_5:
# 1008 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ARCEUS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_DP_Text_6:
# 1009 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GALACTIC COMMANDER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_0:
# 1048 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Platinum:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_Platinum_Text_1:
# 1050 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GIRATINA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_0:
# 1069 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from HeartGold and\n"
	.string "SoulSilver:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_1:
# 1072 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM ROCKET$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_2:
# 1072 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUICUNE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_3:
# 1073 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. ENTEI$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_4:
# 1073 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RAIKOU$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_5:
# 1073 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WILD POKEMON KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_6:
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TRAINER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_7:
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GYM LEADER KANTO$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_8:
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. HO-OH$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_9:
# 1074 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. LUGIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_HgSs_Text_10:
# 1075 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYOGRE/GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_0:
# 1122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Select battle music from Black and\n"
	.string "White:$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_1:
# 1124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. TEAM PLASMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_2:
# 1125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WINNING THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_3:
# 1125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (1)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_4:
# 1125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. IN A PINCH THEME$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_5:
# 1126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. RESHIRAM/ZEKROM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_6:
# 1126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. N (2)$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_7:
# 1126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. GHETSIS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_8:
# 1127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. SUBWAY TRAINER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_9:
# 1127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. CYNTHIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_10:
# 1127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. STRONG WILD POKEMON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_11:
# 1128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. KYUREM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandMusicOptions_BlackWhite_Text_12:
# 1128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "VS. WCS CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_0:
# 1182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Background options unlock at 20 total\n"
	.string "Battle Factory wins.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_1:
# 1185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Fancy a new lick of paint on your\n"
	.string "battles?$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_2:
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "DEFAULT$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_3:
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_4:
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "LONG GRASS$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_5:
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "SAND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_6:
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "UNDERWATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_7:
# 1187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "WATER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_8:
# 1188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "POND$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_9:
# 1188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "MOUNTAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_10:
# 1188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CAVE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_11:
# 1188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BUILDING$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_12:
# 1188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "PLAIN$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_13:
# 1189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_14:
# 1189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GYM LEADER$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_15:
# 1189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM MAGMA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_16:
# 1189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "TEAM AQUA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_17:
# 1190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR SIDNEY$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_18:
# 1190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR PHOEBE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_19:
# 1190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR GLACIA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_20:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "ELITE FOUR DRAKE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_21:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "CHAMPION$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_22:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "GROUDON$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_23:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "KYOGRE$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandBackgroundOptions_Text_24:
# 1191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "RAYQUAZA$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeMusicSuccess_Text_0:
# 1275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your music selection has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandChangeBackgroundSuccess_Text_0:
# 1282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "All done! Your background has been\n"
	.string "changed.$"

BattleFrontier_BattleFactoryLobby_EventScript_NolandAnythingElse_Text_0:
# 1288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Is there anything else I can help you\n"
	.string "with?$"

BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_Text_0:
# 1293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a reward for your display of skill,\n"
	.string "you will be able to select one of the\l"
	.string "POKéMON in your party to keep forever,\l"
	.string "for use in other BATTLE FRONTIER\l"
	.string "facilities.$"
