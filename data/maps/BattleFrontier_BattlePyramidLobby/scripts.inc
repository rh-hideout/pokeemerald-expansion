# 1 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
# 4 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
# 5 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 7 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
# 8 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_OnWarp:
# 9 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
# 10 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.2byte 0
# 11 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 12 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
# 13 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 14 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 15 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 16 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 17 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_OnFrame:
# 18 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
# 19 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
# 20 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
# 21 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
# 22 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
# 23 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.2byte 0
# 24 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 25 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
# 26 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_getstatus
# 27 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 28 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 29 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
# 30 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 31 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
# 32 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 33 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 34 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 35 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 36 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
# 37 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
# 38 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 39 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 40 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 41 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 42 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 43 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
# 44 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 45 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_isbrain
# 46 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
# 47 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
# 48 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints
# 49 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 50 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
# 51 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
# 52 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
# 53 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special DoBattlePyramidMonsHaveHeldItem
# 54 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
# 55 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
# 56 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkairshow
# 57 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 58 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_clearhelditems
# 59 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 60 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 61 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
# 62 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 63 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 64 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 65 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
# 66 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_givepoints
# 67 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 68 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
# 69 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 70 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_setprize
# 71 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_save 0
# 72 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_SAVE
# 73 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 74 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
# 75 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 76 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 77 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 78 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 79 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 80 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
# 81 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkairshow
# 82 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 83 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_clearhelditems
# 84 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 85 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 86 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 87 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
# 88 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 89 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 90 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 91 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
# 92 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 93 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
# 94 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_save 0
# 95 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_SAVE
# 96 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 97 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
# 98 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 99 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 100 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 101 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 102 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 103 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
# 104 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge
# 105 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 106 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
# 107 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lock
# 108 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	faceplayer
# 109 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
# 110 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 111 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special SavePlayerParty
# 112 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
# 113 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
# 114 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
# 115 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 116 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 117 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 118 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
# 119 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
# 120 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 121 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 122 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 123 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
# 124 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
# 125 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 126 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 127 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 128 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 129 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 130 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkineligible
# 131 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
# 132 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 133 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 134 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 135 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 136 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 137 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 138 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 139 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 140 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 141 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 142 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 143 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 144 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 145 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
# 146 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 147 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 148 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
# 149 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 150 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 151 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_init
# 152 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
# 153 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 154 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 155 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_seedfloor
# 156 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_settrainers
# 157 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 158 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 159 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	delay 2
# 160 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 161 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 162 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
# 163 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
# 164 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special SavePlayerParty
# 165 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 166 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
# 167 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 168 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
# 169 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 170 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 171 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 172 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
# 173 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 174 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 175 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 176 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 177 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
# 178 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
# 179 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge
# 180 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 181 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
# 182 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 183 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
# 184 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen
# 185 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 186 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
# 187 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 188 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge
# 189 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 190 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
# 191 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 192 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge
# 193 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 194 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
# 195 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 196 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 197 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 198 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
# 199 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 200 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 201 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
# 202 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
# 203 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
# 204 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	release
# 205 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 206 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 207 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
# 208 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 209 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
# 210 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 211 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
# 212 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
# 213 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
# 214 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 215 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 216 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 217 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
# 218 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 219 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 220 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
# 221 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
# 222 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
# 223 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
# 224 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 225 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 226 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Shouldnt occur
# 227 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
# 228 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 229 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 230 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
# 231 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
# 232 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
# 233 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
# 234 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 235 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 236 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 237 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 238 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
# 239 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
# 240 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 241 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 242 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 243 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
# 244 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
# 245 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
# 246 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
# 247 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 248 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 249 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 250 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 251 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
# 252 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
# 253 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 254 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 255 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 256 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
# 257 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 258 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special GetBattlePyramidHint
# 259 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 260 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
# 261 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
# 262 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
# 263 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
# 264 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
# 265 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
# 266 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
# 267 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
# 268 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
# 269 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
# 270 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
# 271 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
# 272 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
# 273 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
# 274 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
# 275 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
# 276 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
# 277 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
# 278 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
# 279 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
# 280 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 281 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 282 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
# 283 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
# 284 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 285 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 286 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
# 287 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
# 288 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 289 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 290 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
# 291 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
# 292 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 293 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 294 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
# 295 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
# 296 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 297 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 298 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
# 299 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
# 300 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 301 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 302 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
# 303 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
# 304 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 305 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 306 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
# 307 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
# 308 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 309 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 310 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
# 311 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
# 312 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 313 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 314 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
# 315 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
# 316 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 317 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 318 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
# 319 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
# 320 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 321 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 322 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
# 323 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
# 324 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 325 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 326 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
# 327 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
# 328 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 329 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 330 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
# 331 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
# 332 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 333 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 334 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
# 335 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
# 336 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 337 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 338 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
# 339 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
# 340 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 341 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 342 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
# 343 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
# 344 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 345 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 346 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
# 347 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
# 348 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 349 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 350 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
# 351 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
# 352 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 353 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 354 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
# 355 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
# 356 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 357 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 358 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
# 359 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
# 360 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 361 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 362 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
# 363 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 364 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PYRAMID
# 365 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitbuttonpress
# 366 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special RemoveRecordsWindow
# 367 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 368 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 369 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 370 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
# 371 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
# 372 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
# 373 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 374 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
# 375 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK
# 376 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
# 377 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
# 378 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag
# 379 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 380 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
# 381 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
# 382 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
# 383 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
# 384 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 385 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 386 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 387 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
# 388 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 389 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
# 390 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 391 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
# 392 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 393 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 394 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 395 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
# 396 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 397 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 398 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 399 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 400 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 401 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 402 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 403 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	face_down
# 404 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 405 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 406 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
# 407 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 408 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 409 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 410 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 411 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 412 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 413 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 414 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 415 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 416 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
# 417 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_right
# 418 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	face_left
# 419 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 420 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 421 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
# 422 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 423 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 424 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 425 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 426 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
# 427 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
# 428 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
# 429 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special TryStoreHeldItemsInPyramidBag
# 430 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
# 431 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
# 432 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 433 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 434 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 435 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 436 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
# 437 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
# 438 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 439 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 440 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
# 441 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
# 442 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
# 443 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 444 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
# 445 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
# 446 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
# 447 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
# 448 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 449 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 450 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
# 451 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special ChooseItemsToTossFromPyramidBag
# 452 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 453 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 454 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 455 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 456 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 457 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 458 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
# 459 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special BattlePyramidChooseMonHeldItems
# 460 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 461 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 462 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 463 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 464 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 465 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 466 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
# 467 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special DoBattlePyramidMonsHaveHeldItem
# 468 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
# 469 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 470 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 471 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
# 472 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
# 473 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 474 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 475 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 476 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 477 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 478 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_Woman::
# 479 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
# 480 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 481 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 482 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
# 483 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
# 484 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 485 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 486 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
# 487 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 488 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 489 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 490 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 491 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 492 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
# 493 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
# 494 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 495 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
# 496 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 497 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
# 498 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
# 499 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
# 500 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
# 501 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
# 502 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
# 503 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 504 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 505 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
# 506 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
# 507 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 508 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 509 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 510 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
# 511 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
# 512 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 513 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 514 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 515 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
# 516 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
# 517 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 518 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 519 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 520 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
# 521 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
# 522 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 523 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 524 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 525 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
# 526 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 527 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 528 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 529 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
# 530 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Where the courage of TRAINERS\n"
# 531 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "is put to the test!\p"
# 532 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome to the BATTLE PYRAMID!\p"
# 533 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I am your guide to\n"
# 534 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the Battle Quest.$"
# 535 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 536 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
# 537 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Have you the courage to embark on\n"
# 538 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the Battle Quest challenge?$"
# 539 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 540 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
# 541 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We await your challenge in the future!$"
# 542 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 543 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
# 544 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The Battle Quest is a battling\n"
# 545 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "event in which you must explore\l"
# 546 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID and try to reach the top.\p"
# 547 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In the PYRAMID are seven floors of\n"
# 548 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "mazes, all of them filled with not only\l"
# 549 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "skilled TRAINERS but also wild POKéMON.\p"
# 550 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You must enter with three POKéMON,\n"
# 551 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "none of them holding an item.\p"
# 552 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "On your ascent, you will be provided\n"
# 553 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "with a BATTLE BAG for items.\p"
# 554 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you fail in your challenge, any item\n"
# 555 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "placed in the BATTLE BAG disappears.\p"
# 556 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 557 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "challenge, you must select “REST”\l"
# 558 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and save the game.\p"
# 559 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 560 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "you will be disqualified.$"
# 561 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 562 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
# 563 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The PYRAMID offers two courses,\n"
# 564 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Level 50 and Open Level.\l"
# 565 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Which will you enter?$"
# 566 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 567 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
# 568 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Very good. Now, please select the three\n"
# 569 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "POKéMON you wish to accompany you.$"
# 570 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 571 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
# 572 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A slight problem, adventurer!\p"
# 573 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You seem to not have the three\n"
# 574 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "POKéMON qualified for the challenge.\p"
# 575 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please also remember to take all\n"
# 576 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items from your POKéMON.\p"
# 577 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 578 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you are ready, please have\n"
# 579 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "a word with me.$"
# 580 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 581 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
# 582 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A slight problem, adventurer!\p"
# 583 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You seem to not have the three\n"
# 584 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "POKéMON qualified for the challenge.\p"
# 585 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The three POKéMON must be different\n"
# 586 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and each no higher than Level 50.\p"
# 587 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please also remember to take all\n"
# 588 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items from your POKéMON.\p"
# 589 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 590 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you are ready, please have\n"
# 591 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "a word with me.$"
# 592 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 593 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
# 594 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Before you enter the BATTLE PYRAMID,\n"
# 595 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the game must be saved. Is that okay?$"
# 596 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 597 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
# 598 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Very good. I will now show you into\n"
# 599 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE PYRAMID.$"
# 600 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 601 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
# 602 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We will hold your BAG for safekeeping,\n"
# 603 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER}, while you are exploring.$"
# 604 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 605 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
# 606 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In exchange, please take this BATTLE\n"
# 607 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BAG, the one you used previously.$"
# 608 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 609 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
# 610 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In exchange, please take this\n"
# 611 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE BAG.$"
# 612 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 613 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
# 614 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} exchanged the BAG for\n"
# 615 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE BAG.$"
# 616 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 617 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
# 618 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you step on this floor panel,\n"
# 619 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "you will be transported to a higher\l"
# 620 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "floor in the PYRAMID.\p"
# 621 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I hope for your sake that your\n"
# 622 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "quest goes safely!$"
# 623 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 624 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
# 625 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A major problem, explorer!\p"
# 626 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You did not save before ending\n"
# 627 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your challenge the last time.\p"
# 628 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Consequently, your challenge has\n"
# 629 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "been disqualified, I'm sorry to say.\p"
# 630 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is the BAG we've been holding\n"
# 631 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for you.\p"
# 632 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} got the BAG back.$"
# 633 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 634 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
# 635 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Excellent to see you back!\p"
# 636 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've conquered the PYRAMID!\n"
# 637 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "How splendid!$"
# 638 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 639 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
# 640 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Ah, a slight problem.\p"
# 641 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "At least one POKéMON is holding\n"
# 642 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "an item.\p"
# 643 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I'm sorry to say, items obtained in\n"
# 644 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID cannot be taken away.$"
# 645 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 646 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
# 647 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "All items held by your POKéMON will be\n"
# 648 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "moved to your BATTLE BAG, {PLAYER}.$"
# 649 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 650 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
# 651 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG cannot hold all your\n"
# 652 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items, I'm sorry to say.\p"
# 653 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please pick the items you'll keep in the\n"
# 654 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE BAG, and with your POKéMON.$"
# 655 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 656 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
# 657 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "At least one POKéMON is still\n"
# 658 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "holding an item.$"
# 659 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 660 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
# 661 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please pick the items you'll keep in the\n"
# 662 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE BAG, and with your POKéMON.$"
# 663 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 664 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 665 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
# 666 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} returned everything that\n"
# 667 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the POKéMON held.$"
# 668 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 669 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
# 670 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG you used will be kept\n"
# 671 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "in readiness for your next challenge.\p"
# 672 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} turned the BATTLE BAG over\n"
# 673 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for the BAG's return.$"
# 674 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 675 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
# 676 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I must record your results.\n"
# 677 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please wait.$"
# 678 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 679 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 680 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
# 681 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "As a memento for conquering\n"
# 682 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE PYRAMID, please take this.$"
# 683 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 684 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 685 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
# 686 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 687 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 688 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 689 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 690 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
# 691 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…Ah…\n"
# 692 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Your BAG appears to be filled.\p"
# 693 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please return after you've organized\n"
# 694 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your BAG's contents.$"
# 695 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 696 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
# 697 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "How disappointing for you…\p"
# 698 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is the BAG we've been holding\n"
# 699 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for you.\p"
# 700 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} got the BAG back.$"
# 701 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 702 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
# 703 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We look forward to your\n"
# 704 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "next challenge!$"
# 705 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 706 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 707 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
# 708 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We have been looking forward to\n"
# 709 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your arrival!\p"
# 710 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is your prize for conquering\n"
# 711 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID.$"
# 712 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 713 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
# 714 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome…\p"
# 715 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I shall be pleased to tell you what\n"
# 716 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "misfortunes await in the PYRAMID…$"
# 717 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 718 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_Aah:
# 719 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\n"
# 720 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\p"
# 721 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\n"
# 722 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Aah!$"
# 723 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 724 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
# 725 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see a shower of sparks…\p"
# 726 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And in it, I see your POKéMON\n"
# 727 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "struggling with paralysis…$"
# 728 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 729 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPoison:
# 730 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see poison…\p"
# 731 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 732 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from the effects of poison…$"
# 733 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 734 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintBurn:
# 735 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see bright red flames…\p"
# 736 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 737 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from burns…$"
# 738 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 739 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
# 740 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I sense the tremendous pressure of\n"
# 741 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "unrequited anger…\p"
# 742 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "It is a curse…\p"
# 743 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON drained of\n"
# 744 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Power Points and having no recourse\l"
# 745 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "but to use STRUGGLE…$"
# 746 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 747 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
# 748 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see POKéMON loftily airborne…\p"
# 749 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON frustrated\n"
# 750 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by powerless GROUND-type moves…$"
# 751 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 752 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
# 753 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I sense terrific energy rising from\n"
# 754 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the ground below…\p"
# 755 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON unable to\n"
# 756 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "escape the power's clutches…$"
# 757 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 758 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintIce:
# 759 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see ICE-type POKéMON…\p"
# 760 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON fighting\n"
# 761 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the freezing effects of ice…$"
# 762 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 763 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
# 764 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see a flurry of moves that imperil\n"
# 765 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the user…\p"
# 766 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON falling\n"
# 767 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "to them…$"
# 768 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 769 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
# 770 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see PSYCHIC-type POKéMON…\p"
# 771 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON in torment\n"
# 772 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from PSYCHIC moves…$"
# 773 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 774 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintRock:
# 775 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see ROCK-type POKéMON…\p"
# 776 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 777 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from ROCK moves…$"
# 778 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 779 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintFighting:
# 780 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see FIGHTING-type POKéMON…\p"
# 781 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON pummeled\n"
# 782 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by FIGHTING moves…$"
# 783 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 784 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintWeather:
# 785 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "RAIN DANCE… SUNNY DAY…\n"
# 786 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "SANDSTORM… HAIL…\p"
# 787 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see POKéMON that become stronger\n"
# 788 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "with the weather…\p"
# 789 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON confounded\n"
# 790 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by different types of moves…$"
# 791 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 792 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintBug:
# 793 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see BUG-type POKéMON…\p"
# 794 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 795 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from different kinds of attacks…$"
# 796 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 797 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintDark:
# 798 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see DARK-type POKéMON…\p"
# 799 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 800 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from DARK-type moves…$"
# 801 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 802 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintWater:
# 803 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see WATER-type POKéMON…\p"
# 804 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 805 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from WATER-type moves…$"
# 806 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 807 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintGhost:
# 808 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see GHOST-type POKéMON…\p"
# 809 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 810 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from GHOST-type moves…$"
# 811 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 812 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintSteel:
# 813 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see STEEL-type POKéMON…\p"
# 814 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 815 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 816 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 817 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
# 818 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see flying POKéMON…\p"
# 819 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 820 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 821 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 822 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
# 823 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see those that have evolved from\n"
# 824 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the power of stones…\p"
# 825 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I also sense fire, water,\n"
# 826 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and electricity…\p"
# 827 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 828 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from those three powers…$"
# 829 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 830 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintNormal:
# 831 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see NORMAL-type POKéMON…\p"
# 832 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your POKéMON suffering\n"
# 833 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 834 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 835 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
# 836 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Whether you believe my fortunes\n"
# 837 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "or not, the choice is yours…\p"
# 838 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The future can be changed anytime…\n"
# 839 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I wish you safe passage…$"
# 840 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 841 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
# 842 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Did you know?\p"
# 843 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you run fast, TRAINERS may notice\n"
# 844 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and come after you for a battle.\p"
# 845 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "So, if you want to avoid TRAINERS,\n"
# 846 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "don't catch their eyes, but sneak\l"
# 847 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "cautiously and quietly past them.$"
# 848 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 849 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
# 850 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Awaaaaaaarrrrgh!\p"
# 851 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I had a whole lot of items, but I lost\n"
# 852 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "them all when I lost!\p"
# 853 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Awaaaaaaarrrrgh!$"
# 854 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 855 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
# 856 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome back!\n"
# 857 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've done the unthinkable!\p"
# 858 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've defeated the PYRAMID KING\n"
# 859 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and conquered the BATTLE PYRAMID!$"
# 860 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 861 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
# 862 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Young explorer!\n"
# 863 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In commendation of your courage,\l"
# 864 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "we give you these Battle Point(s)!$"
# 865 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 866 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
# 867 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The Battle Quest rules are listed.$"
# 868 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 869 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
# 870 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 871 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 872 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
# 873 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When the PYRAMID is conquered,\n"
# 874 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the wild POKéMON that appear in it\l"
# 875 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "are replaced by different kinds.\p"
# 876 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Explore, observe, and learn what kinds\n"
# 877 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "of wild POKéMON you may encounter.$"
# 878 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 879 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
# 880 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "TRAINERS are lying in wait for you\n"
# 881 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "inside the PYRAMID.\p"
# 882 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "On each floor, there are up to\n"
# 883 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "eight TRAINERS.\p"
# 884 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you defeat a TRAINER, you will\n"
# 885 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "get a helpful hint for your adventure.$"
# 886 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 887 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
# 888 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The mazes in the PYRAMID rearrange\n"
# 889 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "themselves every time you enter it.\p"
# 890 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The mazes are poorly lit.\n"
# 891 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You must advance with caution.\p"
# 892 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The light grows brighter whenever you\n"
# 893 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "defeat a wild POKéMON or a TRAINER.$"
# 894 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 895 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
# 896 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG serves as your BAG\n"
# 897 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "while in the PYRAMID.\p"
# 898 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "There are two separate BATTLE BAGS--\n"
# 899 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "one each for the Level 50 and\l"
# 900 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Open Level adventures.\p"
# 901 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "They each can hold up to 99 pieces\n"
# 902 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "of ten kinds of items.\p"
# 903 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The contents of the BATTLE BAG are\n"
# 904 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "lost if you fail in your quest.$"
