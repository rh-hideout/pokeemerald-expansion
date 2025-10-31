# 1 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
# 4 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
# 5 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 7 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_OnWarp:
# 8 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
# 9 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 11 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
# 12 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 16 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_OnFrame:
# 17 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
# 18 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
# 19 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
# 20 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
# 21 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
# 22 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.2byte 0
# 23 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 24 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
# 25 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_getstatus
# 26 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 27 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 28 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
# 29 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 30 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
# 31 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 32 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_set PALACE_DATA_WIN_STREAK, 0
# 33 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
# 34 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 35 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 36 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 37 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 38 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 39 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
# 40 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 41 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_isbrain
# 42 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
# 43 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
# 44 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints
# 45 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 46 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
# 47 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
# 48 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
# 49 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
# 50 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_givepoints
# 51 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 52 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
# 53 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 54 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
# 55 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
# 56 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 57 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 58 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 59 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 60 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 61 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
# 62 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 63 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
# 64 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 65 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
# 66 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
# 67 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
# 68 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 69 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 70 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 71 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 72 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 73 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
# 74 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_checkairshow
# 75 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special LoadPlayerParty
# 76 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special HealPlayerParty
# 77 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 78 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_save 0
# 79 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	playse SE_SAVE
# 80 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitse
# 81 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 82 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
# 83 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
# 84 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 85 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 86 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 87 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
# 88 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
# 89 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
# 90 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 91 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
# 92 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 93 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
# 94 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 95 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 96 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
# 97 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 98 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
# 99 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
# 100 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 101 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_save CHALLENGE_STATUS_SAVING
# 102 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	playse SE_SAVE
# 103 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitse
# 104 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 105 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 106 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge
# 107 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 108 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
# 109 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lock
# 110 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	faceplayer
# 111 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
# 112 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 113 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
# 114 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 115 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 116 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
# 117 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lock
# 118 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	faceplayer
# 119 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
# 120 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 121 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
# 122 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 123 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 124 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
# 125 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_get PALACE_DATA_PRIZE
# 126 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
# 127 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special SavePlayerParty
# 128 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
# 129 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
# 130 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
# 131 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
# 132 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
# 133 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 134 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 135 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 136 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
# 137 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
# 138 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 139 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 140 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 141 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
# 142 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
# 143 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 144 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 145 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 147 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 148 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_checkineligible
# 149 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
# 150 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 151 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
# 152 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 153 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 154 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 155 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 156 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 157 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 158 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitstate
# 159 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
# 160 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
# 161 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 162 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
# 163 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
# 164 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
# 165 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 166 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
# 167 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 168 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 169 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_init
# 170 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
# 171 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 172 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 173 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special LoadPlayerParty
# 174 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 175 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	delay 2
# 176 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 177 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 178 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
# 179 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
# 180 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special SavePlayerParty
# 181 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 182 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
# 183 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 184 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
# 185 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
# 186 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 187 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitstate
# 188 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 189 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 190 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
# 191 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
# 192 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
# 193 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge
# 194 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 195 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
# 196 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
# 197 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge
# 198 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 199 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
# 200 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 201 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
# 202 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen
# 203 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 204 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
# 205 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 206 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge
# 207 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 208 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
# 209 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 210 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge
# 211 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 212 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
# 213 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 214 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 215 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 216 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
# 217 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special LoadPlayerParty
# 218 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	callnative LoadPlayerParty
# 219 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
# 220 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
# 221 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
# 222 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	release
# 223 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 224 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 225 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
# 226 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 227 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 228 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 229 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
# 230 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 231 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 232 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 233 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
# 234 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
# 235 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 236 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 237 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
# 238 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
# 239 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 240 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 241 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
# 242 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
# 243 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
# 244 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
# 245 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
# 246 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmovement 0
# 247 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
# 248 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
# 249 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitdooranim
# 250 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
# 251 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
# 252 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmovement 0
# 253 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
# 254 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
# 255 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitdooranim
# 256 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 257 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 258 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
# 259 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
# 260 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 261 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 262 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
# 263 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
# 264 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 265 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 266 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
# 267 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	opendoor 5, 4
# 268 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 269 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 270 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
# 271 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	opendoor 19, 4
# 272 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 273 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 274 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
# 275 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closedoor 5, 4
# 276 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 277 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 278 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
# 279 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closedoor 19, 4
# 280 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 281 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 282 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
# 283 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	walk_up
# 284 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	step_end
# 285 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 286 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
# 287 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	walk_up
# 288 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	set_invisible
# 289 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	step_end
# 290 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 291 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
# 292 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	walk_up
# 293 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	walk_up
# 294 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	set_invisible
# 295 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	step_end
# 296 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 297 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
# 298 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 299 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
# 300 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitbuttonpress
# 301 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special RemoveRecordsWindow
# 302 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 303 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 304 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 305 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
# 306 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 307 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
# 308 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitbuttonpress
# 309 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special RemoveRecordsWindow
# 310 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 311 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 312 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 313 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
# 314 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
# 315 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 316 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 317 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_Man::
# 318 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
# 319 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 320 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 321 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
# 322 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
# 323 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 324 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 325 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
# 326 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
# 327 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 328 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 329 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
# 330 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 331 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 332 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 333 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 334 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 335 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
# 336 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
# 337 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 338 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
# 339 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 340 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
# 341 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
# 342 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
# 343 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
# 344 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
# 345 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
# 346 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
# 347 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 348 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 349 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
# 350 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
# 351 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 352 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 353 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 354 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
# 355 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
# 356 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 357 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 358 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 359 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
# 360 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
# 361 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 362 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 363 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 364 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
# 365 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
# 366 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 367 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 368 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 369 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
# 370 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
# 371 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 372 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 373 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 374 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
# 375 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 376 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 377 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 378 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
# 379 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Where the hearts of TRAINERS\n"
# 380 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "are put to the test.\p"
# 381 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I welcome you to the BATTLE PALACE.\p"
# 382 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I accept challenges to the SINGLE\n"
# 383 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "BATTLE HALLS.$"
# 384 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 385 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
# 386 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Do you wish to take\n"
# 387 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the SINGLE BATTLE HALL challenge?$"
# 388 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 389 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
# 390 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "In the BATTLE PALACE, there are\n"
# 391 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "several auditoriums for SINGLE BATTLES\l"
# 392 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "that are named SINGLE BATTLE HALLS.\p"
# 393 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The SINGLE BATTLES are conducted in\n"
# 394 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the usual way, except with one crucial\l"
# 395 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "rule that must be obeyed.\p"
# 396 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "TRAINERS are permitted only to switch\n"
# 397 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "their POKéMON in and out.\p"
# 398 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "TRAINERS are otherwise forbidden to\n"
# 399 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "command their POKéMON.\p"
# 400 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The POKéMON are to behave according\n"
# 401 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "to their nature and battle on their own.\p"
# 402 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You must put your trust in your\n"
# 403 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "POKéMON and watch over them.\p"
# 404 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you achieve the honor of beating\n"
# 405 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "seven TRAINERS in succession,\l"
# 406 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "we will present you with Battle Points.\p"
# 407 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 408 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "challenge, you must save the game.\p"
# 409 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 410 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "you will be disqualified.$"
# 411 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 412 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
# 413 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "When you have fortified your heart\n"
# 414 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "and POKéMON, you must return.$"
# 415 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 416 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
# 417 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "There are two BATTLE HALLS,\n"
# 418 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Level 50 and Open Level.\l"
# 419 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Which is your choice of a challenge?$"
# 420 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 421 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
# 422 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Sigh…\p"
# 423 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You do not have the three POKéMON\n"
# 424 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "required for the challenge.\p"
# 425 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To enter, you must provide three\n"
# 426 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "different kinds of POKéMON.\p"
# 427 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "These POKéMON must all be of\n"
# 428 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Level 50 or lower.\p"
# 429 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "They also must not be holding\n"
# 430 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the same kinds of items.\p"
# 431 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 432 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Come back when you have made\n"
# 433 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your preparations.$"
# 434 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 435 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
# 436 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Sigh…\p"
# 437 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You do not have the three POKéMON\n"
# 438 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "required for the challenge.\p"
# 439 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To enter, you must provide three\n"
# 440 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "different kinds of POKéMON.\p"
# 441 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "They also must not be holding\n"
# 442 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the same kinds of items.\p"
# 443 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 444 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Come back when you have made\n"
# 445 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your preparations.$"
# 446 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 447 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
# 448 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Good. Now, you must select your\n"
# 449 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "three POKéMON.$"
# 450 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 451 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
# 452 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I must save before I show you to\n"
# 453 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the BATTLE HALL. Is that okay?$"
# 454 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 455 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_FollowMe:
# 456 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Good.\n"
# 457 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Now, follow me.$"
# 458 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 459 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
# 460 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I feel privileged for having seen\n"
# 461 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your POKéMON's exploits.\p"
# 462 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The results will be recorded.\n"
# 463 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I must ask you to briefly wait.$"
# 464 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 465 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
# 466 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To achieve a 7-win streak…\p"
# 467 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The bonds that bind your heart with\n"
# 468 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your POKéMON seem firm and true.$"
# 469 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 470 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
# 471 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Your feat will be recorded.\n"
# 472 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I must ask you to briefly wait.$"
# 473 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 474 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
@ Unused
# 475 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
# 476 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "For the feat of your 7-win streak,\n"
# 477 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "we present you with Battle Point(s).$"
# 478 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 479 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
# 480 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You seem to have no space for\n"
# 481 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "our prize.\p"
# 482 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You should return when you have\n"
# 483 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "organized your BAG.$"
# 484 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 485 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
# 486 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "We have been waiting for you…$"
# 487 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 488 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
# 489 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I must save before I show you to\n"
# 490 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the BATTLE HALL. Is that okay?$"
# 491 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 492 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
# 493 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Sigh…\p"
# 494 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You failed to save before you ended\n"
# 495 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your challenge the last time.\p"
# 496 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "As a result, your challenge has been\n"
# 497 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "disqualified. It is most unfortunate.$"
# 498 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 499 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
@ Unused
# 500 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
# 501 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 502 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 503 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 504 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
# 505 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "For a hardy fellow like me,\n"
# 506 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "hardy POKéMON are the best.\p"
# 507 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Offense is the best defense!\n"
# 508 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "A relentless attack is the ultimate!\p"
# 509 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "But that's not what I wanted to chat\n"
# 510 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "about.\p"
# 511 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Every so often a really cute lady\n"
# 512 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "swings by here.\p"
# 513 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "She says that she can tell what\n"
# 514 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "POKéMON are thinking.\p"
# 515 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I don't know about that part,\n"
# 516 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "but she is really cute.\p"
# 517 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Huh?\n"
# 518 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Why are you looking at me like that?$"
# 519 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 520 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
# 521 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Hmm…\p"
# 522 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "It appears that the nature of POKéMON\n"
# 523 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "and the moves that they have been\l"
# 524 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "taught are the keys to battle here.\p"
# 525 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To be more precise, it's how well\n"
# 526 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the moves match the nature of\l"
# 527 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the POKéMON.\p"
# 528 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If your POKéMON is in trouble and\n"
# 529 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "unable to live up to its potential,\l"
# 530 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "you may need to examine how well\l"
# 531 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "its moves match its nature.$"
# 532 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 533 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
# 534 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "My POKéMON is usually very docile.\p"
# 535 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "But when it's in a BATTLE HALL,\n"
# 536 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "it sometimes seems to become\l"
# 537 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "transformed into something wicked!\p"
# 538 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "It becomes totally intimidating.\n"
# 539 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "It's shocking, even.$"
# 540 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 541 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
# 542 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I wonder what sort of nature a POKéMON\n"
# 543 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "would have if it favored enfeebling its\l"
# 544 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "opponents and chipping away slowly.\p"
# 545 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I'd be surprised if it was a LAX nature.\p"
# 546 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "But, nah, that can't be right.$"
# 547 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 548 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
# 549 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Where the hearts of TRAINERS\n"
# 550 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "are put to the test.\p"
# 551 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I welcome you to the BATTLE PALACE.\p"
# 552 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I accept challenges to the DOUBLE\n"
# 553 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "BATTLE HALLS.$"
# 554 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 555 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
# 556 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Do you wish to take\n"
# 557 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the DOUBLE BATTLE HALL challenge?$"
# 558 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 559 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
# 560 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "In the BATTLE PALACE, there are\n"
# 561 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "several auditoriums for DOUBLE BATTLES\l"
# 562 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "that are named DOUBLE BATTLE HALLS.\p"
# 563 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The DOUBLE BATTLES are conducted in\n"
# 564 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the usual way, except with one crucial\l"
# 565 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "rule that must be obeyed.\p"
# 566 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "TRAINERS are permitted only to switch\n"
# 567 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "their POKéMON in and out.\p"
# 568 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "TRAINERS are otherwise forbidden to\n"
# 569 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "command their POKéMON.\p"
# 570 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The POKéMON are to behave according\n"
# 571 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "to their nature and battle on their own.\p"
# 572 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You must put your trust in your\n"
# 573 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "POKéMON and watch over them.\p"
# 574 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you achieve the honor of beating\n"
# 575 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "seven TRAINERS in succession,\l"
# 576 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "we will present you with Battle Points.\p"
# 577 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 578 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 579 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 580 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "you will be disqualified.$"
# 581 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 582 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
# 583 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To defeat the PALACE MAVEN\n"
# 584 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "and seven TRAINERS in a row…$"
# 585 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 586 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
# 587 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "In honor of the bond you share with\n"
# 588 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your POKéMON, we present you with\l"
# 589 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "these Battle Point(s).$"
# 590 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 591 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
# 592 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Would you like to record your latest\n"
# 593 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "BATTLE PALACE match on your\l"
# 594 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 595 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 596 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
# 597 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The BATTLE HALL rules are listed.$"
# 598 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 599 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
# 600 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 601 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 602 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
# 603 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Here, POKéMON are required to think\n"
# 604 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "and battle by themselves.\p"
# 605 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Unlike in the wild, POKéMON that live\n"
# 606 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "with people behave differently\l"
# 607 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "depending on their nature.$"
# 608 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 609 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
# 610 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Depending on its nature, a POKéMON\n"
# 611 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "may prefer to attack no matter what.\p"
# 612 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Another POKéMON may prefer to protect\n"
# 613 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "itself from any harm.\p"
# 614 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Yet another may enjoy vexing or\n"
# 615 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "confounding its foes.\p"
# 616 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Due to its nature, a POKéMON\n"
# 617 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "will have favorite moves that it is good\l"
# 618 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "at using.\p"
# 619 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "It may also dislike certain moves that\n"
# 620 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "it has trouble using.$"
# 621 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 622 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
# 623 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "There are offensive moves that inflict\n"
# 624 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "direct damage on the foe.\p"
# 625 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "There are defensive moves that are\n"
# 626 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "used to prepare for enemy attacks or\l"
# 627 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "used to heal HP and so on.\p"
# 628 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "There are also other somewhat-odd\n"
# 629 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "moves that may enfeeble the foes with\l"
# 630 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "stat problems including poison and \l"
# 631 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "paralysis.\p"
# 632 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "POKéMON will consider using moves in\n"
# 633 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "these three categories.$"
# 634 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 635 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
# 636 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "When not under command by its TRAINER,\n"
# 637 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "a POKéMON may be unable to effectively\l"
# 638 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "use certain moves.\p"
# 639 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "A POKéMON is not good at using any\n"
# 640 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "move that it dislikes.\p"
# 641 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If a POKéMON only knows moves that\n"
# 642 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "do not match its nature, it will often\l"
# 643 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "be unable to live up to its potential.$"
# 644 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 645 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
# 646 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Depending on its nature, a POKéMON may\n"
# 647 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "start using moves that don't match its\l"
# 648 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "nature when it is in trouble.\p"
# 649 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If a POKéMON begins behaving oddly\n"
# 650 "data/maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "in a pinch, watch it carefully.$"
