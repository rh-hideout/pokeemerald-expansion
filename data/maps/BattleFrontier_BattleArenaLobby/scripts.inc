# 1 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_MapScripts::
# 3 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
# 4 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
# 5 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_OnWarp:
# 8 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
# 9 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
# 12 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 16 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_OnFrame:
# 17 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
# 18 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
# 19 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
# 20 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
# 21 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
# 22 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.2byte 0
# 23 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
# 25 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_getstatus
# 26 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 27 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 28 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
# 29 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 30 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
# 31 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 32 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK, 0
# 33 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
# 34 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 35 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 36 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 37 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 38 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 39 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
# 40 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 41 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_isbrain
# 42 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
# 43 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
# 44 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints
# 45 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 46 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
# 47 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
# 48 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
# 49 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
# 50 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_givepoints
# 51 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 52 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
# 53 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 54 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
# 55 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
# 56 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 57 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 58 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 59 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 60 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 61 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
# 62 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 63 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
# 64 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 65 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
# 66 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
# 67 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
# 68 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 69 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 70 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 71 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 72 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 73 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
# 74 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_checkairshow
# 75 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special LoadPlayerParty
# 76 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special HealPlayerParty
# 77 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 78 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_save 0
# 79 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	playse SE_SAVE
# 80 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitse
# 81 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 82 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
# 83 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
# 84 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 85 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 86 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 87 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
# 88 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
# 89 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
# 90 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 91 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
# 92 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 93 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
# 94 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	return
# 95 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 96 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
# 97 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 98 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
# 99 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 100 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_save CHALLENGE_STATUS_SAVING
# 101 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	playse SE_SAVE
# 102 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitse
# 103 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 104 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 105 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge
# 106 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 107 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Attendant::
# 108 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lock
# 109 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	faceplayer
# 110 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
# 111 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 112 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special SavePlayerParty
# 113 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
# 114 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
# 115 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
# 116 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 117 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 118 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 119 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
# 120 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
# 121 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 122 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 123 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 124 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
# 125 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
# 126 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 127 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 128 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 129 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 130 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 131 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_checkineligible
# 132 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
# 133 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 134 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 135 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 136 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 137 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 138 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 139 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 140 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 141 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitstate
# 142 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
# 143 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
# 144 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 145 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
# 146 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
# 147 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
# 148 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 149 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
# 150 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 151 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 152 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_init
# 153 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
# 154 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 155 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 156 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special LoadPlayerParty
# 157 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 158 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	delay 2
# 159 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 160 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 161 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
# 162 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
# 163 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special SavePlayerParty
# 164 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 165 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
# 166 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 167 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 168 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
# 169 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
# 170 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
# 171 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 172 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitstate
# 173 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 174 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 175 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
# 176 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
# 177 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge
# 178 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 179 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
# 180 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 181 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
# 182 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen
# 183 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 184 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
# 185 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 186 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge
# 187 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
# 189 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 190 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge
# 191 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 192 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
# 193 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 194 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 195 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 196 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
# 197 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special LoadPlayerParty
# 198 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 199 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
# 200 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
# 201 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
# 202 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	release
# 203 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 204 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 205 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
# 206 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
# 207 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
# 208 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmovement 0
# 209 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	opendoor 2, 2
# 210 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitdooranim
# 211 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
# 212 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
# 213 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmovement 0
# 214 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closedoor 2, 2
# 215 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitdooranim
# 216 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	return
# 217 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 218 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
# 219 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 220 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 221 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 222 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 223 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 224 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 225 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 226 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 227 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 228 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 229 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 230 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
# 231 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 232 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	set_invisible
# 233 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 234 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
# 236 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 237 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 238 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 239 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 240 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 241 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 242 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 243 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 244 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 245 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_in_place_faster_up
# 246 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 247 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 248 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
# 249 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 250 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 251 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	set_invisible
# 252 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 253 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 254 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
# 255 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
# 256 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
# 257 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmovement 0
# 258 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	opendoor 11, 2
# 259 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitdooranim
# 260 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
# 261 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
# 262 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmovement 0
# 263 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closedoor 11, 2
# 264 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitdooranim
# 265 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	return
# 266 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 267 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
# 268 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 269 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 270 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 271 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 272 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 273 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 274 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 275 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 276 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 277 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 278 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
# 279 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 280 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 281 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 282 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 283 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 284 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 285 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 286 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 287 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_in_place_faster_up
# 288 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 289 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 290 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
# 291 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 292 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_ARENA
# 293 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitbuttonpress
# 294 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special RemoveRecordsWindow
# 295 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 296 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 297 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 298 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Youngster::
# 299 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
# 300 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 301 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 302 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Man::
# 303 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
# 304 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 305 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 306 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Camper::
# 307 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
# 308 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 309 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 310 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Woman::
# 311 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
# 312 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 313 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 314 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
# 315 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 316 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 317 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 318 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 319 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 320 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
# 321 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
# 322 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 323 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
# 324 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 325 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
# 326 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
# 327 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
# 328 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
# 329 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
# 330 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
# 331 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 332 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 333 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
# 334 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
# 335 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 336 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 337 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 338 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_MindRules::
# 339 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
# 340 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 341 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 342 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 343 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
# 344 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
# 345 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 346 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 347 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 348 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
# 349 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
# 350 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 351 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 352 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 353 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
# 354 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 355 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 356 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 357 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
# 358 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Where the battling spirit of TRAINERS\n"
# 359 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "is put to the test!\p"
# 360 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I welcome you to the BATTLE ARENA!\p"
# 361 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I am your guide to the Set KO Tourney!$"
# 362 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 363 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
# 364 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Now, do you wish to take\n"
# 365 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the BATTLE ARENA challenge?$"
# 366 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 367 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
# 368 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We await your challenge on\n"
# 369 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "another occasion!$"
# 370 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 371 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
# 372 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "In the BATTLE ARENA, we undertake\n"
# 373 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the Set KO Tourney.\p"
# 374 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "All participants enter with a team of\n"
# 375 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three POKéMON.\p"
# 376 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The three POKéMON must be lined up in\n"
# 377 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the order in which they are to appear.\p"
# 378 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "During battle, the POKéMON will appear\n"
# 379 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "one at a time in the preset order.\p"
# 380 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Once a POKéMON enters battle, it must\n"
# 381 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "remain out until the match is decided.\p"
# 382 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If a match remains undecided in\n"
# 383 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three turns, it goes to judging.\p"
# 384 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If you wish to interrupt your challenge,\n"
# 385 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "please save the game.\p"
# 386 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If you don't save, you will not be able\n"
# 387 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "to continue with your challenge.\p"
# 388 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If you pull off the feat of beating\n"
# 389 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "seven TRAINERS in succession,\l"
# 390 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "we will present you with Battle Points.$"
# 391 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 392 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_OkayToSave:
# 393 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Before showing you to the BATTLE\n"
# 394 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "ARENA, you must save. Is that okay?$"
# 395 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 396 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
# 397 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The BATTLE ARENA offers two levels\n"
# 398 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "of challenge, Level 50 and Open Level.\l"
# 399 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Which is your choice?$"
# 400 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 401 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
# 402 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Very well, now select your\n"
# 403 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three POKéMON, please.$"
# 404 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 405 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
# 406 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "My dear challenger!\p"
# 407 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "You do not have the three POKéMON\n"
# 408 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "required for entry.\p"
# 409 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "To qualify, you must bring three\n"
# 410 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "different kinds of POKéMON.\p"
# 411 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "They also must not hold the same\n"
# 412 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "kinds of items.\p"
# 413 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 414 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "When you have made your preparations,\n"
# 415 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "please do return.$"
# 416 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 417 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
# 418 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "My dear challenger!\p"
# 419 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "You do not have the three POKéMON\n"
# 420 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "required for entry.\p"
# 421 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "To qualify, you must bring three\n"
# 422 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "different kinds of POKéMON.\p"
# 423 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The three different POKéMON\n"
# 424 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "must all be Level 50 or lower.\p"
# 425 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "They also must not hold the same\n"
# 426 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "kinds of items.\p"
# 427 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 428 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "When you have made your preparations,\n"
# 429 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "please do return.$"
# 430 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 431 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
# 432 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I shall now guide you to\n"
# 433 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the BATTLE ARENA.$"
# 434 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 435 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
# 436 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "My dear challenger!\p"
# 437 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "You did not save the game before\n"
# 438 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "shutting down, did you?\p"
# 439 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "It is unfortunate, but that has\n"
# 440 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "resulted in your disqualification\l"
# 441 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "from your challenge.\p"
# 442 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "You may, of course, start with a fresh\n"
# 443 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "challenge.$"
# 444 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 445 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
# 446 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We congratulate you for your splendid\n"
# 447 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "string of wins over seven TRAINERS!$"
# 448 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 449 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
# 450 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Your achievement will be recorded.\n"
# 451 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Please wait while I save the game.$"
# 452 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 453 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
@ Unused
# 454 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
# 455 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "In commemoration of your 7-win streak,\n"
# 456 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "we present you with this prize.$"
# 457 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 458 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
@ Unused
# 459 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
# 460 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 461 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 462 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 463 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
@ Unused
# 464 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
# 465 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Oh?\n"
# 466 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Your BAG seems to be full.\p"
# 467 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I urge you to clear space and\n"
# 468 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "return for your prize.$"
# 469 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 470 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
# 471 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Thank you so much for participating!\p"
# 472 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Please wait while I save the game.$"
# 473 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 474 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
# 475 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We await your challenge on\n"
# 476 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "another occasion!$"
# 477 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 478 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
# 479 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We have been looking forward to\n"
# 480 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "your arrival.\p"
# 481 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Before I show you to the BATTLE\n"
# 482 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "ARENA, I must save the game.\l"
# 483 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Please wait.$"
# 484 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 485 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
# 486 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Shall I record your last BATTLE ARENA\n"
# 487 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 488 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 489 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
# 490 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I lost on the REFEREE's decision…\p"
# 491 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I don't think it was a good idea to only\n"
# 492 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "use defensive moves and not attack…$"
# 493 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 494 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
# 495 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I won in judging!\p"
# 496 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Landing hits consistently on\n"
# 497 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the opponent's POKéMON worked!$"
# 498 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 499 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
# 500 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Our match was declared a draw.\p"
# 501 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "When we ran out of time, both my\n"
# 502 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "POKéMON and the opponent's had about\l"
# 503 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the same amount of HP left.$"
# 504 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 505 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
# 506 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "In the BATTLE ARENA, the order of\n"
# 507 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "POKéMON is totally important.\p"
# 508 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "For example, if your first POKéMON\n"
# 509 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "has certain type disadvantages,\l"
# 510 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "try making your second POKéMON one\l"
# 511 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "with moves that are super effective\l"
# 512 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "against the first one.\p"
# 513 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I think that will be a good way of\n"
# 514 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "making an effective team.$"
# 515 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 516 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
# 517 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The Set KO Tourney's rules are listed.$"
# 518 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 519 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
# 520 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 521 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 522 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
# 523 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The Set KO Tourney has special rules,\n"
# 524 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "unlike standard battles.\p"
# 525 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "First, one battle lasts only\n"
# 526 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three turns.\p"
# 527 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If the outcome is not decided after\n"
# 528 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three turns, it goes to judging.\p"
# 529 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The REFEREE will choose the winner\n"
# 530 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "based on how the POKéMON battled.\p"
# 531 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Also, a POKéMON cannot be switched out\n"
# 532 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "until its battle's outcome is decided.$"
# 533 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 534 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
# 535 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The first judging factor is “Mind.”\n"
# 536 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "This factor evaluates how aggressive\l"
# 537 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the battlers were.\p"
# 538 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The judging is based on how often\n"
# 539 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the TRAINERS ordered the use of\l"
# 540 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "offensive moves.$"
# 541 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 542 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
# 543 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The second judging factor is “Skill.”\n"
# 544 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "This factor evaluates how effectively\l"
# 545 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "POKéMON moves were used.\p"
# 546 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If a move worked successfully,\n"
# 547 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the Skill rating goes up.\p"
# 548 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If a move failed, the Skill rating\n"
# 549 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "is lowered.\p"
# 550 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If it was an offensive move, the Skill\n"
# 551 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "rating goes up if the move was “super\l"
# 552 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "effective” and goes down if it was\l"
# 553 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "“not very effective.”\p"
# 554 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The Skill rating will not go up for\n"
# 555 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "moves such as PROTECT and DETECT.\p"
# 556 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If the opponent used PROTECT or\n"
# 557 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "DETECT, and your POKéMON failed to\l"
# 558 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "hit with a move, its Skill rating will not\l"
# 559 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "go down.$"
# 560 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 561 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
# 562 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The third judging factor is “Body.”\n"
# 563 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "This factor is based on how much HP\l"
# 564 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "remained at the end of a battle.\p"
# 565 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The rating takes into account how much\n"
# 566 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "HP a POKéMON had at the start of\l"
# 567 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "battle, and what remained at the end.$"
# 568 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 569 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
# 570 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "A victory snatched from the ARENA\n"
# 571 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "TYCOON, and a seven-TRAINER sweep!\p"
# 572 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We congratulate you on your most\n"
# 573 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "splendid challenge!$"
# 574 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 575 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
# 576 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "My dear challenger, in recognition of\n"
# 577 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "your indefatigable spirit, please\l"
# 578 "data/maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "accept these Battle Point(s).$"
