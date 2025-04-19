# 1 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 4 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_MapScripts::
# 5 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
# 6 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
# 7 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 9 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_OnWarp:
# 10 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
# 11 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.2byte 0
# 12 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 13 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
# 14 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 16 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 17 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 18 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_OnFrame:
# 19 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
# 20 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
# 21 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
# 22 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
# 23 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
# 24 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.2byte 0
# 25 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 26 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
# 27 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_getstatus
# 28 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 29 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 30 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
# 31 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 32 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
# 33 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 34 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK, 0
# 35 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
# 36 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 37 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 38 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 39 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 40 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 41 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
# 42 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 43 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_isbrain
# 44 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
# 45 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
# 46 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints
# 47 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 48 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
# 49 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
# 50 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
# 51 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
# 52 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_givepoints
# 53 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 54 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
# 55 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 56 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
# 57 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
# 58 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 59 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 60 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 61 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 62 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 63 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
# 64 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 65 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
# 66 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 67 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
# 68 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
# 69 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
# 70 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 71 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 72 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 73 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 74 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 75 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
# 76 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_checkairshow
# 77 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special LoadPlayerParty
# 78 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special HealPlayerParty
# 79 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 80 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_save 0
# 81 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	playse SE_SAVE
# 82 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitse
# 83 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 84 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
# 85 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
# 86 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 87 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 88 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 89 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
# 90 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
# 91 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
# 92 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 93 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
# 94 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 95 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
# 96 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	return
# 97 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 98 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
# 99 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 100 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
# 101 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 102 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_save CHALLENGE_STATUS_SAVING
# 103 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	playse SE_SAVE
# 104 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitse
# 105 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 106 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 107 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge
# 108 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 109 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Attendant::
# 110 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lock
# 111 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	faceplayer
# 112 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
# 113 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 114 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special SavePlayerParty
# 115 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
# 116 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
# 117 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
# 118 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 119 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 120 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 121 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
# 122 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
# 123 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 124 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 125 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 126 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
# 127 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
# 128 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 129 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 130 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 131 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 132 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 133 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_checkineligible
# 134 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
# 135 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 136 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 137 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 138 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 139 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 140 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 141 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 142 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 143 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitstate
# 144 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
# 145 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
# 146 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 147 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
# 148 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
# 149 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
# 150 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 151 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
# 152 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 153 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 154 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_init
# 155 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
# 156 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 157 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 158 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special LoadPlayerParty
# 159 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 160 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	delay 2
# 161 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 162 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 163 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
# 164 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
# 165 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special SavePlayerParty
# 166 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 167 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
# 168 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closemessage
# 169 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 170 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
# 171 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
# 172 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
# 173 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 174 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitstate
# 175 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 176 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 177 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
# 178 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
# 179 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge
# 180 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 181 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
# 182 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 183 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
# 184 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen
# 185 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 186 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
# 187 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 188 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge
# 189 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 190 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
# 191 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 192 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge
# 193 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 194 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
# 195 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 196 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
# 197 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 198 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
# 199 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special LoadPlayerParty
# 200 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 201 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
# 202 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
# 203 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
# 204 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	release
# 205 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 206 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 207 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
# 208 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
# 209 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
# 210 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmovement 0
# 211 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	opendoor 2, 2
# 212 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitdooranim
# 213 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
# 214 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
# 215 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmovement 0
# 216 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closedoor 2, 2
# 217 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitdooranim
# 218 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	return
# 219 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 220 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
# 221 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 222 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 223 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 224 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 225 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 226 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 227 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 228 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 229 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 230 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 231 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 232 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
# 233 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 234 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	set_invisible
# 235 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 236 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 237 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
# 238 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 239 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 240 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 241 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 242 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 243 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 244 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 245 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 246 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_left
# 247 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_in_place_faster_up
# 248 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 249 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 250 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
# 251 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 252 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 253 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	set_invisible
# 254 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 255 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 256 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
# 257 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
# 258 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
# 259 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmovement 0
# 260 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	opendoor 11, 2
# 261 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitdooranim
# 262 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
# 263 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
# 264 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmovement 0
# 265 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	closedoor 11, 2
# 266 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitdooranim
# 267 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	return
# 268 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 269 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
# 270 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 271 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 272 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 273 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 274 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 275 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 276 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 277 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 278 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 279 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 280 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
# 281 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 282 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 283 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 284 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_up
# 285 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 286 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 287 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 288 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_right
# 289 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	walk_in_place_faster_up
# 290 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	step_end
# 291 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 292 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
# 293 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 294 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_ARENA
# 295 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitbuttonpress
# 296 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	special RemoveRecordsWindow
# 297 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 298 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 299 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 300 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Youngster::
# 301 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
# 302 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 303 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 304 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Man::
# 305 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
# 306 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 307 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 308 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Camper::
# 309 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
# 310 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 311 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 312 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_Woman::
# 313 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
# 314 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 315 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 316 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
# 317 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	lockall
# 318 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 319 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 320 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 321 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 322 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
# 323 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
# 324 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	waitmessage
# 325 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
# 326 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	switch VAR_RESULT
# 327 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
# 328 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
# 329 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
# 330 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
# 331 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
# 332 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
# 333 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 334 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 335 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
# 336 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
# 337 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 338 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 339 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 340 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_MindRules::
# 341 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
# 342 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 343 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 344 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 345 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
# 346 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
# 347 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 348 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 349 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 350 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
# 351 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
# 352 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
# 353 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 354 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 355 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
# 356 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	releaseall
# 357 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	end
# 358 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 359 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
# 360 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Where the battling spirit of TRAINERS\n"
# 361 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "is put to the test!\p"
# 362 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I welcome you to the BATTLE ARENA!\p"
# 363 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I am your guide to the Set KO Tourney!$"
# 364 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 365 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
# 366 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Now, do you wish to take\n"
# 367 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the BATTLE ARENA challenge?$"
# 368 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 369 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
# 370 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We await your challenge on\n"
# 371 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "another occasion!$"
# 372 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 373 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
# 374 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "In the BATTLE ARENA, we undertake\n"
# 375 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the Set KO Tourney.\p"
# 376 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "All participants enter with a team of\n"
# 377 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three POKéMON.\p"
# 378 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The three POKéMON must be lined up in\n"
# 379 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the order in which they are to appear.\p"
# 380 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "During battle, the POKéMON will appear\n"
# 381 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "one at a time in the preset order.\p"
# 382 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Once a POKéMON enters battle, it must\n"
# 383 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "remain out until the match is decided.\p"
# 384 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If a match remains undecided in\n"
# 385 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three turns, it goes to judging.\p"
# 386 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If you wish to interrupt your challenge,\n"
# 387 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "please save the game.\p"
# 388 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If you don't save, you will not be able\n"
# 389 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "to continue with your challenge.\p"
# 390 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If you pull off the feat of beating\n"
# 391 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "seven TRAINERS in succession,\l"
# 392 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "we will present you with Battle Points.$"
# 393 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 394 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_OkayToSave:
# 395 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Before showing you to the BATTLE\n"
# 396 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "ARENA, you must save. Is that okay?$"
# 397 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 398 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
# 399 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The BATTLE ARENA offers two levels\n"
# 400 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "of challenge, Level 50 and Open Level.\l"
# 401 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Which is your choice?$"
# 402 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 403 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
# 404 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Very well, now select your\n"
# 405 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three POKéMON, please.$"
# 406 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 407 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
# 408 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "My dear challenger!\p"
# 409 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "You do not have the three POKéMON\n"
# 410 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "required for entry.\p"
# 411 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "To qualify, you must bring three\n"
# 412 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "different kinds of POKéMON.\p"
# 413 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "They also must not hold the same\n"
# 414 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "kinds of items.\p"
# 415 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 416 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "When you have made your preparations,\n"
# 417 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "please do return.$"
# 418 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 419 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
# 420 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "My dear challenger!\p"
# 421 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "You do not have the three POKéMON\n"
# 422 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "required for entry.\p"
# 423 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "To qualify, you must bring three\n"
# 424 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "different kinds of POKéMON.\p"
# 425 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The three different POKéMON\n"
# 426 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "must all be Level 50 or lower.\p"
# 427 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "They also must not hold the same\n"
# 428 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "kinds of items.\p"
# 429 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 430 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "When you have made your preparations,\n"
# 431 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "please do return.$"
# 432 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 433 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
# 434 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I shall now guide you to\n"
# 435 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the BATTLE ARENA.$"
# 436 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 437 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
# 438 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "My dear challenger!\p"
# 439 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "You did not save the game before\n"
# 440 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "shutting down, did you?\p"
# 441 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "It is unfortunate, but that has\n"
# 442 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "resulted in your disqualification\l"
# 443 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "from your challenge.\p"
# 444 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "You may, of course, start with a fresh\n"
# 445 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "challenge.$"
# 446 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 447 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
# 448 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We congratulate you for your splendid\n"
# 449 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "string of wins over seven TRAINERS!$"
# 450 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 451 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
# 452 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Your achievement will be recorded.\n"
# 453 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Please wait while I save the game.$"
# 454 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 455 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
@ Unused
# 456 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
# 457 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "In commemoration of your 7-win streak,\n"
# 458 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "we present you with this prize.$"
# 459 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 460 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
@ Unused
# 461 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
# 462 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 463 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 464 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 465 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
@ Unused
# 466 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
# 467 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Oh?\n"
# 468 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Your BAG seems to be full.\p"
# 469 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I urge you to clear space and\n"
# 470 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "return for your prize.$"
# 471 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 472 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
# 473 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Thank you so much for participating!\p"
# 474 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Please wait while I save the game.$"
# 475 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 476 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
# 477 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We await your challenge on\n"
# 478 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "another occasion!$"
# 479 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 480 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
# 481 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We have been looking forward to\n"
# 482 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "your arrival.\p"
# 483 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Before I show you to the BATTLE\n"
# 484 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "ARENA, I must save the game.\l"
# 485 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Please wait.$"
# 486 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 487 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
# 488 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Shall I record your last BATTLE ARENA\n"
# 489 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 490 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 491 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
# 492 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I lost on the REFEREE's decision…\p"
# 493 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I don't think it was a good idea to only\n"
# 494 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "use defensive moves and not attack…$"
# 495 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 496 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
# 497 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I won in judging!\p"
# 498 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Landing hits consistently on\n"
# 499 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the opponent's POKéMON worked!$"
# 500 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 501 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
# 502 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Our match was declared a draw.\p"
# 503 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "When we ran out of time, both my\n"
# 504 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "POKéMON and the opponent's had about\l"
# 505 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the same amount of HP left.$"
# 506 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 507 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
# 508 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "In the BATTLE ARENA, the order of\n"
# 509 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "POKéMON is totally important.\p"
# 510 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "For example, if your first POKéMON\n"
# 511 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "has certain type disadvantages,\l"
# 512 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "try making your second POKéMON one\l"
# 513 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "with moves that are super effective\l"
# 514 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "against the first one.\p"
# 515 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "I think that will be a good way of\n"
# 516 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "making an effective team.$"
# 517 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 518 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
# 519 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The Set KO Tourney's rules are listed.$"
# 520 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 521 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
# 522 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 523 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 524 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
# 525 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The Set KO Tourney has special rules,\n"
# 526 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "unlike standard battles.\p"
# 527 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "First, one battle lasts only\n"
# 528 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three turns.\p"
# 529 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If the outcome is not decided after\n"
# 530 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "three turns, it goes to judging.\p"
# 531 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The REFEREE will choose the winner\n"
# 532 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "based on how the POKéMON battled.\p"
# 533 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "Also, a POKéMON cannot be switched out\n"
# 534 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "until its battle's outcome is decided.$"
# 535 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 536 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
# 537 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The first judging factor is “Mind.”\n"
# 538 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "This factor evaluates how aggressive\l"
# 539 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the battlers were.\p"
# 540 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The judging is based on how often\n"
# 541 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the TRAINERS ordered the use of\l"
# 542 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "offensive moves.$"
# 543 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 544 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
# 545 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The second judging factor is “Skill.”\n"
# 546 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "This factor evaluates how effectively\l"
# 547 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "POKéMON moves were used.\p"
# 548 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If a move worked successfully,\n"
# 549 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "the Skill rating goes up.\p"
# 550 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If a move failed, the Skill rating\n"
# 551 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "is lowered.\p"
# 552 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If it was an offensive move, the Skill\n"
# 553 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "rating goes up if the move was “super\l"
# 554 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "effective” and goes down if it was\l"
# 555 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "“not very effective.”\p"
# 556 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The Skill rating will not go up for\n"
# 557 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "moves such as PROTECT and DETECT.\p"
# 558 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "If the opponent used PROTECT or\n"
# 559 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "DETECT, and your POKéMON failed to\l"
# 560 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "hit with a move, its Skill rating will not\l"
# 561 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "go down.$"
# 562 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 563 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
# 564 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The third judging factor is “Body.”\n"
# 565 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "This factor is based on how much HP\l"
# 566 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "remained at the end of a battle.\p"
# 567 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "The rating takes into account how much\n"
# 568 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "HP a POKéMON had at the start of\l"
# 569 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "battle, and what remained at the end.$"
# 570 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 571 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
# 572 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "A victory snatched from the ARENA\n"
# 573 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "TYCOON, and a seven-TRAINER sweep!\p"
# 574 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "We congratulate you on your most\n"
# 575 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "splendid challenge!$"
# 576 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"

# 577 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
# 578 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "My dear challenger, in recognition of\n"
# 579 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "your indefatigable spirit, please\l"
# 580 "data//maps/BattleFrontier_BattleArenaLobby/scripts.pory"
	.string "accept these Battle Point(s).$"
