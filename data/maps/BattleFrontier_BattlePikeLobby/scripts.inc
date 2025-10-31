# 1 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
# 4 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
# 5 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 7 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_OnFrame:
# 8 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
# 9 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
# 10 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
# 11 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
# 12 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.2byte 0
# 13 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 14 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_OnWarp:
# 15 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
# 16 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.2byte 0
# 17 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 18 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
# 19 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 20 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 21 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 22 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 23 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
# 24 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_getstatus
# 25 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 26 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 27 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
# 28 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special HealPlayerParty
# 29 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_resethelditems
# 30 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 31 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
# 32 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 33 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK, 0
# 34 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
# 35 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 36 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 37 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 38 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 39 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 40 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
# 41 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 42 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_isbrain
# 43 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
# 44 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
# 45 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 46 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints
# 47 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 48 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
# 49 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
# 50 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 51 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
# 52 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
# 53 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_givepoints
# 54 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 55 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_checkairshow
# 56 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_get PIKE_DATA_TOTAL_STREAKS
# 57 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	addvar VAR_RESULT, 1
# 58 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
# 59 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special LoadPlayerParty
# 60 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special HealPlayerParty
# 61 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 62 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_resethelditems
# 63 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
# 64 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 65 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_save 0
# 66 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	playse SE_SAVE
# 67 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitse
# 68 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
# 69 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 70 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 71 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 72 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 73 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 74 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
# 75 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 76 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
# 77 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 78 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_checkairshow
# 79 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
# 80 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
# 81 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special LoadPlayerParty
# 82 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special HealPlayerParty
# 83 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 84 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_resethelditems
# 85 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_save 0
# 86 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	playse SE_SAVE
# 87 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitse
# 88 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
# 89 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 90 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 91 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 92 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 93 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 94 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_Attendant::
# 95 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lock
# 96 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	faceplayer
# 97 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
# 98 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 99 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special SavePlayerParty
# 100 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
# 101 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
# 102 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
# 103 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 104 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 105 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 106 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
# 107 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
# 108 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 109 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 110 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 111 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
# 112 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
# 113 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 114 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 115 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 116 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 117 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 118 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_checkineligible
# 119 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
# 120 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 121 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
# 122 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 123 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 124 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 125 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 126 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 127 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 128 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitstate
# 129 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
# 130 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
# 131 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 132 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
# 133 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
# 134 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
# 135 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 136 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
# 137 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 138 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_1, 0
# 139 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 140 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_init
# 141 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 142 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
# 143 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_savehelditems
# 144 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 145 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special LoadPlayerParty
# 146 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 147 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	delay 2
# 148 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 149 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 150 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_savehelditems
# 151 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
# 152 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special SavePlayerParty
# 153 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 154 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 155 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 156 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_settrainers
# 157 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
# 158 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special HealPlayerParty
# 159 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
# 160 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
# 161 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 162 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitstate
# 163 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 164 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 165 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
# 166 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
# 167 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge
# 168 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 169 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
# 170 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 171 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
# 172 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen
# 173 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 174 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
# 175 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 176 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge
# 177 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 178 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
# 179 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 180 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge
# 181 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 182 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
# 183 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 184 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 185 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 186 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
# 187 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special LoadPlayerParty
# 188 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 189 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
# 190 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
# 191 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
# 192 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	release
# 193 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 194 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 195 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
# 196 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 197 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PIKE
# 198 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitbuttonpress
# 199 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special RemoveRecordsWindow
# 200 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 201 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 202 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 203 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
# 204 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
# 205 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
# 206 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmovement 0
# 207 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	return
# 208 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 209 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
# 210 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	walk_up
# 211 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
# 212 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	walk_up
# 213 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	walk_up
# 214 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	set_invisible
# 215 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	step_end
# 216 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 217 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_Hiker::
# 218 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
# 219 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 220 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 221 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_Twin::
# 222 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
# 223 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 224 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 225 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_Beauty::
# 226 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
# 227 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 228 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 229 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
# 230 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 231 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 232 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
# 233 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 234 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 235 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
# 236 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
# 237 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 238 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
# 239 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 240 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
# 241 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
# 242 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
# 243 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
# 244 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
# 245 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 246 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 247 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
# 248 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
# 249 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
# 250 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 251 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 252 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
# 253 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
# 254 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
# 255 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 256 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 257 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
# 258 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
# 259 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
# 260 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 261 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 262 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
# 263 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 264 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 265 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 266 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePike_EventScript_CloseCurtain::
# 267 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	playse SE_PIKE_CURTAIN_CLOSE
# 268 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special CloseBattlePikeCurtain
# 269 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitstate
# 270 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitse
# 271 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	return
# 272 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 273 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
# 274 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Where the luck of TRAINERS\n"
# 275 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "is put to the test…\p"
# 276 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Welcome to the BATTLE PIKE…\p"
# 277 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I am your guide to the BATTLE PIKE…$"
# 278 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 279 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
# 280 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 281 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Choice challenge?$"
# 282 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 283 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
# 284 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Here we conduct an event we call\n"
# 285 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "the Battle Choice.\p"
# 286 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "The Battle Choice rules are very\n"
# 287 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "simple…\p"
# 288 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Choose one of three paths and make\n"
# 289 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "your way to the goal room at the end\l"
# 290 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "of the BATTLE PIKE. It's that simple.\p"
# 291 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "However, what happens on the chosen\n"
# 292 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "path depends entirely on the luck\l"
# 293 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "of the challenger…\p"
# 294 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "If you reach the goal, you will be\n"
# 295 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "rewarded with Battle Points.\p"
# 296 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 297 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "challenge, please have a word with\l"
# 298 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "our staff in the big rooms on the way.\p"
# 299 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 300 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you will be disqualified.$"
# 301 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 302 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
# 303 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "We look forward to seeing you\n"
# 304 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "on another occasion…$"
# 305 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 306 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
# 307 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You have the choice of two courses,\n"
# 308 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Level 50 and Open Level.\l"
# 309 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Which will you challenge?$"
# 310 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 311 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
# 312 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I beg your pardon, but…\p"
# 313 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You do not have three eligible\n"
# 314 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "POKéMON for the Battle Choice event.\p"
# 315 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You must have three different POKéMON\n"
# 316 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 317 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "They also must be holding different\n"
# 318 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "kinds of items.\p"
# 319 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 320 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please come see me when\n"
# 321 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you are ready…$"
# 322 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 323 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
# 324 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I beg your pardon, but…\p"
# 325 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You do not have three eligible\n"
# 326 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "POKéMON for the Battle Choice event.\p"
# 327 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You must have three different\n"
# 328 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "POKéMON to enter.\p"
# 329 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "They also must be holding different\n"
# 330 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "kinds of items.\p"
# 331 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 332 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please come see me when\n"
# 333 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you are ready…$"
# 334 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 335 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
# 336 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please choose the three POKéMON\n"
# 337 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you wish to enter in the challenge…$"
# 338 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 339 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
# 340 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Before starting your Battle Choice\n"
# 341 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "challenge, I must save the game.\l"
# 342 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Is that acceptable?$"
# 343 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 344 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_StepThisWay:
# 345 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please step this way…$"
# 346 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 347 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
# 348 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Your challenge has ended…\p"
# 349 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I shall record your results.\n"
# 350 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please wait…$"
# 351 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 352 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
# 353 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You have completed the challenge…\p"
# 354 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I must say… You seem to possess luck\n"
# 355 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "in abundance…$"
# 356 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 357 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
# 358 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I shall record your results.\n"
# 359 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please wait…$"
# 360 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 361 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
@ Unused
# 362 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
# 363 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "To commemorate your completion of\n"
# 364 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "the Battle Choice challenge, we award\l"
# 365 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you these Battle Point(s)…$"
# 366 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 367 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
@ Unused
# 368 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
# 369 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You appear to have reached the limit\n"
# 370 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "for Battle Points…\p"
# 371 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please exchange some Battle Points\n"
# 372 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "for prizes, then return…$"
# 373 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 374 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
# 375 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I beg your pardon, but…\p"
# 376 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You failed to save before you quit\n"
# 377 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "your challenge the last time.\p"
# 378 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Because of that, your challenge so far\n"
# 379 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "has been disqualified. I am sorry…$"
# 380 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 381 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
# 382 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Congratulations…\p"
# 383 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You have snatched victory from the\n"
# 384 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "PIKE QUEEN and cleared the event…$"
# 385 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 386 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
# 387 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "In recognition of your amazing luck,\n"
# 388 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "we award you these Battle Point(s)…$"
# 389 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 390 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
# 391 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Arrgh! I blew my chance!\n"
# 392 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I was one room away from the goal!\p"
# 393 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "In this place, you'd better watch out\n"
# 394 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "for poison, freezing, and so on.$"
# 395 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 396 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
# 397 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I've completed the challenge 10 times\n"
# 398 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "now, but I've never had to battle\l"
# 399 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "a TRAINER once.$"
# 400 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 401 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
# 402 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Listen! Listen!\p"
# 403 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Don't you think that the special\n"
# 404 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "abilities of POKéMON will be useful\l"
# 405 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "here?$"
# 406 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 407 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
@ Unused
# 408 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
# 409 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "What is this weird place?\n"
# 410 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I can't figure it out at all!\p"
# 411 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I've taken the challenge a bunch\n"
# 412 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "of times, but all I ever do is run into\l"
# 413 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "TRAINERS whichever path I choose.$"
# 414 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 415 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
# 416 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "The Battle Choice's rules are listed.$"
# 417 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 418 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
# 419 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 420 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 421 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
# 422 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "The BAG and POKéNAV may not be used\n"
# 423 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "during a Battle Choice challenge.$"
# 424 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 425 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
# 426 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "During a Battle Choice challenge,\n"
# 427 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "any BERRY or HERB held by POKéMON\l"
# 428 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "will be effective only once.$"
# 429 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 430 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
# 431 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "During a Battle Choice challenge,\n"
# 432 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "the sequence of POKéMON cannot be\l"
# 433 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "changed.\p"
# 434 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "The sequence must be set before\n"
# 435 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "starting your challenge.$"
