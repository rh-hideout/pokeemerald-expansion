# 1 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
.set LOCALID_HINT_GIVER, 2
# 4 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 5 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_MapScripts::
# 6 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
# 7 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
# 8 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.byte 0
# 9 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 10 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
# 11 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_OnWarp:
# 12 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
# 13 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.2byte 0
# 14 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 15 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
# 16 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 17 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 18 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 19 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 20 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_OnFrame:
# 21 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
# 22 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
# 23 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
# 24 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
# 25 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
# 26 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.2byte 0
# 27 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 28 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
# 29 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_getstatus
# 30 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 31 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 32 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
# 33 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 34 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
# 35 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 36 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 37 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 38 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 39 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
# 40 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
# 41 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 42 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 43 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 44 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 45 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 46 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
# 47 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 48 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_isbrain
# 49 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
# 50 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
# 51 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints
# 52 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 53 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
# 54 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
# 55 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
# 56 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special DoBattlePyramidMonsHaveHeldItem
# 57 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
# 58 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
# 59 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkairshow
# 60 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 61 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_clearhelditems
# 62 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 63 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 64 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
# 65 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 66 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 67 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 68 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
# 69 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_givepoints
# 70 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 71 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
# 72 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 73 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_setprize
# 74 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_save 0
# 75 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_SAVE
# 76 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 77 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
# 78 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 79 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 80 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 81 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 82 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 83 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
# 84 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkairshow
# 85 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 86 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_clearhelditems
# 87 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 88 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 89 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 90 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
# 91 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 92 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 93 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 94 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
# 95 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 96 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
# 97 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_save 0
# 98 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_SAVE
# 99 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 100 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
# 101 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 102 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 103 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 104 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 105 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 106 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
# 107 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge
# 108 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 109 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
# 110 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lock
# 111 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	faceplayer
# 112 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
# 113 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 114 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special SavePlayerParty
# 115 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
# 116 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
# 117 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
# 118 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 119 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 120 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 121 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
# 122 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
# 123 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 124 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 125 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 126 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
# 127 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
# 128 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 129 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 130 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 131 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 132 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 133 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkineligible
# 134 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
# 135 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 136 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 137 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 138 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 139 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 140 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 141 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 142 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 143 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 144 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 145 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 146 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 147 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 148 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
# 149 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 150 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 151 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
# 152 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 153 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 154 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_init
# 155 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
# 156 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 157 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 158 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_seedfloor
# 159 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_settrainers
# 160 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 161 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 162 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	delay 2
# 163 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 164 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 165 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
# 166 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
# 167 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special SavePlayerParty
# 168 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 169 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
# 170 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 171 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
# 172 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 173 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 174 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 175 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
# 176 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 177 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 178 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 179 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 180 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
# 181 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
# 182 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge
# 183 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 184 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
# 185 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 186 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
# 187 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen
# 188 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 189 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
# 190 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 191 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge
# 192 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 193 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
# 194 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 195 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge
# 196 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 197 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
# 198 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 199 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 200 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 201 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
# 202 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 203 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 204 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
# 205 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
# 206 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
# 207 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	release
# 208 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 209 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 210 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
# 211 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 212 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_HINT_GIVER, Common_Movement_FacePlayer
# 213 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 214 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
# 215 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
# 216 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
# 217 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 218 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 219 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 220 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
# 221 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 222 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 223 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
# 224 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
# 225 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
# 226 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
# 227 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 228 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 229 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Shouldnt occur
# 230 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
# 231 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 232 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 233 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
# 234 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
# 235 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
# 236 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
# 237 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 238 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 239 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 240 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 241 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
# 242 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
# 243 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 244 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 245 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 246 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
# 247 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
# 248 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
# 249 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
# 250 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 251 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 252 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 253 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 254 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
# 255 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
# 256 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 257 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 258 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 259 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
# 260 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 261 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special GetBattlePyramidHint
# 262 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 263 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
# 264 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
# 265 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
# 266 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
# 267 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
# 268 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
# 269 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
# 270 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
# 271 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
# 272 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
# 273 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
# 274 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
# 275 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
# 276 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
# 277 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
# 278 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
# 279 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
# 280 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
# 281 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
# 282 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
# 283 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 284 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 285 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
# 286 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
# 287 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 288 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 289 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
# 290 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
# 291 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 292 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 293 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
# 294 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
# 295 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 296 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 297 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
# 298 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
# 299 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 300 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 301 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
# 302 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
# 303 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 304 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 305 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
# 306 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
# 307 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 308 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 309 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
# 310 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
# 311 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 312 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 313 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
# 314 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
# 315 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 316 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 317 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
# 318 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
# 319 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 320 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 321 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
# 322 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
# 323 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 324 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 325 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
# 326 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
# 327 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 328 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 329 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
# 330 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
# 331 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 332 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 333 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
# 334 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
# 335 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 336 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 337 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
# 338 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
# 339 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 340 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 341 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
# 342 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
# 343 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 344 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 345 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
# 346 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
# 347 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 348 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 349 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
# 350 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
# 351 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 352 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 353 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
# 354 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
# 355 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 356 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 357 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
# 358 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
# 359 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 360 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 361 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
# 362 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
# 363 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 364 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 365 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
# 366 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 367 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PYRAMID
# 368 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitbuttonpress
# 369 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special RemoveRecordsWindow
# 370 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 371 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 372 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 373 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
# 374 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
# 375 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
# 376 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 377 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
# 378 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK
# 379 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
# 380 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
# 381 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag
# 382 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 383 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
# 384 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
# 385 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
# 386 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
# 387 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 388 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 389 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 390 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
# 391 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 392 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
# 393 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 394 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
# 395 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 396 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 397 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 398 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
# 399 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 400 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 401 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 402 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 403 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 404 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 405 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 406 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	face_down
# 407 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 408 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 409 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
# 410 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 411 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 412 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 413 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 414 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 415 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 416 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 417 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 418 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 419 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
# 420 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_right
# 421 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	face_left
# 422 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 423 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 424 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
# 425 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 426 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 427 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 428 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 429 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
# 430 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
# 431 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
# 432 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special TryStoreHeldItemsInPyramidBag
# 433 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
# 434 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
# 435 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 436 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 437 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 438 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 439 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
# 440 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
# 441 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 442 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 443 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
# 444 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
# 445 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
# 446 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 447 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
# 448 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
# 449 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
# 450 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
# 451 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 452 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 453 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
# 454 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special ChooseItemsToTossFromPyramidBag
# 455 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 456 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 457 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 458 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 459 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 460 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 461 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
# 462 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special BattlePyramidChooseMonHeldItems
# 463 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 464 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 465 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 466 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 467 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 468 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 469 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
# 470 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special DoBattlePyramidMonsHaveHeldItem
# 471 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
# 472 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 473 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 474 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
# 475 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
# 476 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 477 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 478 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 479 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 480 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 481 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_Woman::
# 482 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
# 483 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 484 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 485 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
# 486 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
# 487 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 488 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 489 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
# 490 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 491 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 492 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 493 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 494 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 495 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
# 496 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
# 497 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 498 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
# 499 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 500 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
# 501 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
# 502 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
# 503 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
# 504 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
# 505 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
# 506 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 507 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 508 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
# 509 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
# 510 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 511 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 512 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 513 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
# 514 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
# 515 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 516 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 517 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 518 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
# 519 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
# 520 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 521 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 522 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 523 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
# 524 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
# 525 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 526 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 527 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 528 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
# 529 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 530 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 531 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 532 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
# 533 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Where the courage of TRAINERS\n"
# 534 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "is put to the test!\p"
# 535 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome to the BATTLE PYRAMID!\p"
# 536 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I am your guide to\n"
# 537 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the Battle Quest.$"
# 538 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 539 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
# 540 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Have you the courage to embark on\n"
# 541 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the Battle Quest challenge?$"
# 542 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 543 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
# 544 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We await your challenge in the future!$"
# 545 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 546 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
# 547 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The Battle Quest is a battling\n"
# 548 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "event in which you must explore\l"
# 549 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID and try to reach the top.\p"
# 550 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In the PYRAMID are seven floors of\n"
# 551 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "mazes, all of them filled with not only\l"
# 552 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "skilled TRAINERS but also wild POKéMON.\p"
# 553 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You must enter with three POKéMON,\n"
# 554 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "none of them holding an item.\p"
# 555 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "On your ascent, you will be provided\n"
# 556 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "with a BATTLE BAG for items.\p"
# 557 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you fail in your challenge, any item\n"
# 558 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "placed in the BATTLE BAG disappears.\p"
# 559 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 560 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "challenge, you must select “REST”\l"
# 561 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and save the game.\p"
# 562 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 563 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "you will be disqualified.$"
# 564 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 565 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
# 566 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The PYRAMID offers two courses,\n"
# 567 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Level 50 and Open Level.\l"
# 568 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Which will you enter?$"
# 569 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 570 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
# 571 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Very good. Now, please select the three\n"
# 572 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "POKéMON you wish to accompany you.$"
# 573 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 574 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
# 575 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A slight problem, adventurer!\p"
# 576 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You seem to not have the three\n"
# 577 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "POKéMON qualified for the challenge.\p"
# 578 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please also remember to take all\n"
# 579 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items from your POKéMON.\p"
# 580 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 581 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you are ready, please have\n"
# 582 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "a word with me.$"
# 583 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 584 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
# 585 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A slight problem, adventurer!\p"
# 586 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You seem to not have the three\n"
# 587 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "POKéMON qualified for the challenge.\p"
# 588 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The three POKéMON must be different\n"
# 589 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and each no higher than Level 50.\p"
# 590 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please also remember to take all\n"
# 591 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items from your POKéMON.\p"
# 592 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 593 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you are ready, please have\n"
# 594 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "a word with me.$"
# 595 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 596 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
# 597 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Before you enter the BATTLE PYRAMID,\n"
# 598 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the game must be saved. Is that okay?$"
# 599 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 600 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
# 601 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Very good. I will now show you into\n"
# 602 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE PYRAMID.$"
# 603 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 604 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
# 605 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We will hold your BAG for safekeeping,\n"
# 606 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER}, while you are exploring.$"
# 607 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 608 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
# 609 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In exchange, please take this BATTLE\n"
# 610 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BAG, the one you used previously.$"
# 611 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 612 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
# 613 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In exchange, please take this\n"
# 614 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE BAG.$"
# 615 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 616 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
# 617 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} exchanged the BAG for\n"
# 618 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE BAG.$"
# 619 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 620 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
# 621 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you step on this floor panel,\n"
# 622 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "you will be transported to a higher\l"
# 623 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "floor in the PYRAMID.\p"
# 624 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I hope for your sake that your\n"
# 625 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "quest goes safely!$"
# 626 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 627 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
# 628 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A major problem, explorer!\p"
# 629 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You did not save before ending\n"
# 630 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your challenge the last time.\p"
# 631 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Consequently, your challenge has\n"
# 632 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "been disqualified, I'm sorry to say.\p"
# 633 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is the BAG we've been holding\n"
# 634 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for you.\p"
# 635 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} got the BAG back.$"
# 636 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 637 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
# 638 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Excellent to see you back!\p"
# 639 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've conquered the PYRAMID!\n"
# 640 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "How splendid!$"
# 641 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 642 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
# 643 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Ah, a slight problem.\p"
# 644 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "At least one POKéMON is holding\n"
# 645 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "an item.\p"
# 646 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I'm sorry to say, items obtained in\n"
# 647 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID cannot be taken away.$"
# 648 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 649 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
# 650 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "All items held by your POKéMON will be\n"
# 651 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "moved to your BATTLE BAG, {PLAYER}.$"
# 652 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 653 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
# 654 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG cannot hold all your\n"
# 655 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items, I'm sorry to say.\p"
# 656 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please pick the items you'll keep in the\n"
# 657 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE BAG, and with your POKéMON.$"
# 658 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 659 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
# 660 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "At least one POKéMON is still\n"
# 661 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "holding an item.$"
# 662 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 663 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
# 664 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please pick the items you'll keep in the\n"
# 665 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE BAG, and with your POKéMON.$"
# 666 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 667 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 668 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
# 669 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} returned everything that\n"
# 670 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the POKéMON held.$"
# 671 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 672 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
# 673 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG you used will be kept\n"
# 674 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "in readiness for your next challenge.\p"
# 675 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} turned the BATTLE BAG over\n"
# 676 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for the BAG's return.$"
# 677 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 678 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
# 679 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I must record your results.\n"
# 680 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please wait.$"
# 681 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 682 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 683 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
# 684 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "As a memento for conquering\n"
# 685 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE PYRAMID, please take this.$"
# 686 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 687 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 688 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
# 689 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 690 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 691 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 692 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 693 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
# 694 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…Ah…\n"
# 695 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Your BAG appears to be filled.\p"
# 696 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please return after you've organized\n"
# 697 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your BAG's contents.$"
# 698 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 699 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
# 700 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "How disappointing for you…\p"
# 701 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is the BAG we've been holding\n"
# 702 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for you.\p"
# 703 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} got the BAG back.$"
# 704 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 705 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
# 706 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We look forward to your\n"
# 707 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "next challenge!$"
# 708 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 709 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 710 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
# 711 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We have been looking forward to\n"
# 712 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your arrival!\p"
# 713 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is your prize for conquering\n"
# 714 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID.$"
# 715 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 716 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
# 717 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome…\p"
# 718 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I shall be pleased to tell you what\n"
# 719 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "misfortunes await in the PYRAMID…$"
# 720 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 721 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_Aah:
# 722 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\n"
# 723 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\p"
# 724 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\n"
# 725 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Aah!$"
# 726 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 727 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
# 728 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see a shower of sparks…\p"
# 729 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And in it, I see your POKéMON\n"
# 730 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "struggling with paralysis…$"
# 731 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 732 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPoison:
# 733 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see poison…\p"
# 734 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 735 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from the effects of poison…$"
# 736 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 737 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintBurn:
# 738 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see bright red flames…\p"
# 739 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 740 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from burns…$"
# 741 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 742 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
# 743 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I sense the tremendous pressure of\n"
# 744 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "unrequited anger…\p"
# 745 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "It is a curse…\p"
# 746 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON drained of\n"
# 747 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Power Points and having no recourse\l"
# 748 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "but to use STRUGGLE…$"
# 749 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 750 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
# 751 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see POKéMON loftily airborne…\p"
# 752 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON frustrated\n"
# 753 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by powerless GROUND-type moves…$"
# 754 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 755 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
# 756 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I sense terrific energy rising from\n"
# 757 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the ground below…\p"
# 758 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON unable to\n"
# 759 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "escape the power's clutches…$"
# 760 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 761 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintIce:
# 762 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see ICE-type POKéMON…\p"
# 763 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON fighting\n"
# 764 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the freezing effects of ice…$"
# 765 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 766 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
# 767 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see a flurry of moves that imperil\n"
# 768 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the user…\p"
# 769 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON falling\n"
# 770 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "to them…$"
# 771 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 772 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
# 773 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see PSYCHIC-type POKéMON…\p"
# 774 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON in torment\n"
# 775 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from PSYCHIC moves…$"
# 776 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 777 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintRock:
# 778 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see ROCK-type POKéMON…\p"
# 779 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 780 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from ROCK moves…$"
# 781 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 782 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintFighting:
# 783 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see FIGHTING-type POKéMON…\p"
# 784 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON pummeled\n"
# 785 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by FIGHTING moves…$"
# 786 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 787 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintWeather:
# 788 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "RAIN DANCE… SUNNY DAY…\n"
# 789 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "SANDSTORM… HAIL…\p"
# 790 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see POKéMON that become stronger\n"
# 791 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "with the weather…\p"
# 792 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON confounded\n"
# 793 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by different types of moves…$"
# 794 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 795 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintBug:
# 796 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see BUG-type POKéMON…\p"
# 797 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 798 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from different kinds of attacks…$"
# 799 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 800 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintDark:
# 801 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see DARK-type POKéMON…\p"
# 802 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 803 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from DARK-type moves…$"
# 804 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 805 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintWater:
# 806 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see WATER-type POKéMON…\p"
# 807 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 808 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from WATER-type moves…$"
# 809 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 810 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintGhost:
# 811 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see GHOST-type POKéMON…\p"
# 812 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 813 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from GHOST-type moves…$"
# 814 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 815 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintSteel:
# 816 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see STEEL-type POKéMON…\p"
# 817 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 818 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 819 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 820 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
# 821 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see flying POKéMON…\p"
# 822 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 823 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 824 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 825 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
# 826 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see those that have evolved from\n"
# 827 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the power of stones…\p"
# 828 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I also sense fire, water,\n"
# 829 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and electricity…\p"
# 830 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 831 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from those three powers…$"
# 832 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 833 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintNormal:
# 834 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see NORMAL-type POKéMON…\p"
# 835 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 836 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 837 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 838 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
# 839 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Whether you believe my fortunes\n"
# 840 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "or not, the choice is yours…\p"
# 841 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The future can be changed anytime…\n"
# 842 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I wish you safe passage…$"
# 843 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 844 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
# 845 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Did you know?\p"
# 846 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you run fast, TRAINERS may notice\n"
# 847 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and come after you for a battle.\p"
# 848 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "So, if you want to avoid TRAINERS,\n"
# 849 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "don't catch their eyes, but sneak\l"
# 850 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "cautiously and quietly past them.$"
# 851 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 852 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
# 853 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Awaaaaaaarrrrgh!\p"
# 854 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I had a whole lot of items, but I lost\n"
# 855 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "them all when I lost!\p"
# 856 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Awaaaaaaarrrrgh!$"
# 857 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 858 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
# 859 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome back!\n"
# 860 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've done the unthinkable!\p"
# 861 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've defeated the PYRAMID KING\n"
# 862 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and conquered the BATTLE PYRAMID!$"
# 863 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 864 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
# 865 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Young explorer!\n"
# 866 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In commendation of your courage,\l"
# 867 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "we give you these Battle Point(s)!$"
# 868 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 869 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
# 870 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The Battle Quest rules are listed.$"
# 871 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 872 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
# 873 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 874 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 875 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
# 876 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When the PYRAMID is conquered,\n"
# 877 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the wild POKéMON that appear in it\l"
# 878 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "are replaced by different kinds.\p"
# 879 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Explore, observe, and learn what kinds\n"
# 880 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "of wild POKéMON you may encounter.$"
# 881 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 882 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
# 883 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "TRAINERS are lying in wait for you\n"
# 884 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "inside the PYRAMID.\p"
# 885 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "On each floor, there are up to\n"
# 886 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "eight TRAINERS.\p"
# 887 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you defeat a TRAINER, you will\n"
# 888 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "get a helpful hint for your adventure.$"
# 889 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 890 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
# 891 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The mazes in the PYRAMID rearrange\n"
# 892 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "themselves every time you enter it.\p"
# 893 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The mazes are poorly lit.\n"
# 894 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You must advance with caution.\p"
# 895 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The light grows brighter whenever you\n"
# 896 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "defeat a wild POKéMON or a TRAINER.$"
# 897 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 898 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
# 899 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG serves as your BAG\n"
# 900 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "while in the PYRAMID.\p"
# 901 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "There are two separate BATTLE BAGS--\n"
# 902 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "one each for the Level 50 and\l"
# 903 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Open Level adventures.\p"
# 904 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "They each can hold up to 99 pieces\n"
# 905 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "of ten kinds of items.\p"
# 906 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The contents of the BATTLE BAG are\n"
# 907 "data//maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "lost if you fail in your quest.$"
