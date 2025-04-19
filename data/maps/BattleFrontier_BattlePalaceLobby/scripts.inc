# 1 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
.set LOCALID_ATTENDANT_SINGLES, 1
# 3 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
.set LOCALID_ATTENDANT_DOUBLES, 6
# 4 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 5 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_MapScripts::
# 6 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
# 7 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
# 8 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.byte 0
# 9 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 10 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_OnWarp:
# 11 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
# 12 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.2byte 0
# 13 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 14 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
# 15 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 16 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 17 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 18 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 19 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_OnFrame:
# 20 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
# 21 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
# 22 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
# 23 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
# 24 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
# 25 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.2byte 0
# 26 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 27 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
# 28 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_getstatus
# 29 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 30 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 31 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
# 32 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 33 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
# 34 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 35 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_set PALACE_DATA_WIN_STREAK, 0
# 36 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
# 37 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 38 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 39 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 40 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 41 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 42 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
# 43 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 44 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_isbrain
# 45 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
# 46 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
# 47 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints
# 48 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 49 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
# 50 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
# 51 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
# 52 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
# 53 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_givepoints
# 54 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 55 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
# 56 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 57 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
# 58 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
# 59 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 60 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 61 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 62 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 63 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 64 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
# 65 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 66 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
# 67 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 68 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
# 69 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
# 70 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
# 71 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 72 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 73 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 74 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 75 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 76 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
# 77 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_checkairshow
# 78 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special LoadPlayerParty
# 79 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special HealPlayerParty
# 80 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 81 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_save 0
# 82 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	playse SE_SAVE
# 83 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitse
# 84 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 85 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
# 86 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
# 87 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 88 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 89 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 90 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
# 91 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
# 92 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
# 93 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 94 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
# 95 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 96 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
# 97 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 98 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 99 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
# 100 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 101 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
# 102 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
# 103 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 104 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_save CHALLENGE_STATUS_SAVING
# 105 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	playse SE_SAVE
# 106 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitse
# 107 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 108 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 109 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge
# 110 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 111 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
# 112 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lock
# 113 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	faceplayer
# 114 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
# 115 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 116 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
# 117 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 118 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 119 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
# 120 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lock
# 121 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	faceplayer
# 122 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
# 123 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 124 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
# 125 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 126 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 127 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
# 128 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_get PALACE_DATA_PRIZE
# 129 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
# 130 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special SavePlayerParty
# 131 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
# 132 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
# 133 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
# 134 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
# 135 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
# 136 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 137 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 138 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 139 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
# 140 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
# 141 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 142 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 143 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 144 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
# 145 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
# 146 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 147 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 148 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 149 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 150 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 151 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_checkineligible
# 152 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
# 153 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 154 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
# 155 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 156 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 157 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 158 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 159 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 160 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 161 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitstate
# 162 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
# 163 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
# 164 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 165 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
# 166 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
# 167 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
# 168 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 169 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
# 170 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 171 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 172 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_init
# 173 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
# 174 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 175 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 176 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special LoadPlayerParty
# 177 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 178 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	delay 2
# 179 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 180 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 181 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
# 182 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
# 183 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special SavePlayerParty
# 184 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 185 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
# 186 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closemessage
# 187 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
# 188 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
# 189 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 190 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitstate
# 191 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 192 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 193 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
# 194 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
# 195 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
# 196 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge
# 197 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 198 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
# 199 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
# 200 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge
# 201 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 202 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
# 203 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 204 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
# 205 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen
# 206 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 207 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
# 208 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 209 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge
# 210 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 211 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
# 212 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 213 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge
# 214 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 215 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
# 216 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 217 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
# 218 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 219 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
# 220 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special LoadPlayerParty
# 221 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	callnative LoadPlayerParty
# 222 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
# 223 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
# 224 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
# 225 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	release
# 226 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 227 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 228 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
# 229 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 230 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 231 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 232 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
# 233 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 234 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 235 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 236 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
# 237 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
# 238 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 239 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 240 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
# 241 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
# 242 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 243 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 244 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
# 245 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
# 246 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
# 247 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
# 248 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
# 249 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmovement 0
# 250 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
# 251 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
# 252 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitdooranim
# 253 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
# 254 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
# 255 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmovement 0
# 256 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
# 257 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
# 258 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitdooranim
# 259 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 260 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 261 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
# 262 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
# 263 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 264 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 265 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
# 266 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
# 267 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 268 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 269 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
# 270 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	opendoor 5, 4
# 271 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 272 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 273 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
# 274 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	opendoor 19, 4
# 275 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 276 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 277 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
# 278 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closedoor 5, 4
# 279 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 280 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 281 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
# 282 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	closedoor 19, 4
# 283 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	return
# 284 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 285 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
# 286 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	walk_up
# 287 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	step_end
# 288 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 289 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
# 290 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	walk_up
# 291 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	set_invisible
# 292 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	step_end
# 293 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 294 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
# 295 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	walk_up
# 296 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	walk_up
# 297 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	set_invisible
# 298 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	step_end
# 299 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 300 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
# 301 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 302 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
# 303 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitbuttonpress
# 304 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special RemoveRecordsWindow
# 305 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 306 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 307 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 308 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
# 309 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 310 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
# 311 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitbuttonpress
# 312 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	special RemoveRecordsWindow
# 313 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 314 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 315 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 316 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
# 317 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
# 318 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 319 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 320 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_Man::
# 321 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
# 322 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 323 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 324 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
# 325 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
# 326 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 327 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 328 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
# 329 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
# 330 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 331 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 332 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
# 333 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	lockall
# 334 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 335 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 336 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 337 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 338 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
# 339 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
# 340 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	waitmessage
# 341 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
# 342 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	switch VAR_RESULT
# 343 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
# 344 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
# 345 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
# 346 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
# 347 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
# 348 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
# 349 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
# 350 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 351 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 352 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
# 353 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
# 354 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 355 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 356 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 357 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
# 358 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
# 359 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 360 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 361 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 362 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
# 363 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
# 364 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 365 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 366 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 367 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
# 368 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
# 369 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 370 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 371 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 372 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
# 373 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
# 374 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
# 375 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 376 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 377 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
# 378 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	releaseall
# 379 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	end
# 380 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 381 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
# 382 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Where the hearts of TRAINERS\n"
# 383 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "are put to the test.\p"
# 384 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I welcome you to the BATTLE PALACE.\p"
# 385 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I accept challenges to the SINGLE\n"
# 386 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "BATTLE HALLS.$"
# 387 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 388 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
# 389 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Do you wish to take\n"
# 390 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the SINGLE BATTLE HALL challenge?$"
# 391 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 392 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
# 393 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "In the BATTLE PALACE, there are\n"
# 394 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "several auditoriums for SINGLE BATTLES\l"
# 395 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "that are named SINGLE BATTLE HALLS.\p"
# 396 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The SINGLE BATTLES are conducted in\n"
# 397 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the usual way, except with one crucial\l"
# 398 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "rule that must be obeyed.\p"
# 399 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "TRAINERS are permitted only to switch\n"
# 400 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "their POKéMON in and out.\p"
# 401 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "TRAINERS are otherwise forbidden to\n"
# 402 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "command their POKéMON.\p"
# 403 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The POKéMON are to behave according\n"
# 404 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "to their nature and battle on their own.\p"
# 405 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You must put your trust in your\n"
# 406 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "POKéMON and watch over them.\p"
# 407 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you achieve the honor of beating\n"
# 408 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "seven TRAINERS in succession,\l"
# 409 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "we will present you with Battle Points.\p"
# 410 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 411 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "challenge, you must save the game.\p"
# 412 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 413 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "you will be disqualified.$"
# 414 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 415 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
# 416 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "When you have fortified your heart\n"
# 417 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "and POKéMON, you must return.$"
# 418 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 419 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
# 420 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "There are two BATTLE HALLS,\n"
# 421 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Level 50 and Open Level.\l"
# 422 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Which is your choice of a challenge?$"
# 423 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 424 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
# 425 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Sigh…\p"
# 426 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You do not have the three POKéMON\n"
# 427 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "required for the challenge.\p"
# 428 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To enter, you must provide three\n"
# 429 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "different kinds of POKéMON.\p"
# 430 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "These POKéMON must all be of\n"
# 431 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Level 50 or lower.\p"
# 432 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "They also must not be holding\n"
# 433 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the same kinds of items.\p"
# 434 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 435 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Come back when you have made\n"
# 436 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your preparations.$"
# 437 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 438 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
# 439 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Sigh…\p"
# 440 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You do not have the three POKéMON\n"
# 441 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "required for the challenge.\p"
# 442 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To enter, you must provide three\n"
# 443 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "different kinds of POKéMON.\p"
# 444 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "They also must not be holding\n"
# 445 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the same kinds of items.\p"
# 446 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 447 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Come back when you have made\n"
# 448 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your preparations.$"
# 449 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 450 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
# 451 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Good. Now, you must select your\n"
# 452 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "three POKéMON.$"
# 453 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 454 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
# 455 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I must save before I show you to\n"
# 456 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the BATTLE HALL. Is that okay?$"
# 457 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 458 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_FollowMe:
# 459 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Good.\n"
# 460 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Now, follow me.$"
# 461 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 462 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
# 463 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I feel privileged for having seen\n"
# 464 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your POKéMON's exploits.\p"
# 465 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The results will be recorded.\n"
# 466 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I must ask you to briefly wait.$"
# 467 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 468 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
# 469 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To achieve a 7-win streak…\p"
# 470 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The bonds that bind your heart with\n"
# 471 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your POKéMON seem firm and true.$"
# 472 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 473 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
# 474 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Your feat will be recorded.\n"
# 475 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I must ask you to briefly wait.$"
# 476 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 477 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
@ Unused
# 478 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
# 479 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "For the feat of your 7-win streak,\n"
# 480 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "we present you with Battle Point(s).$"
# 481 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 482 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
# 483 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You seem to have no space for\n"
# 484 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "our prize.\p"
# 485 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You should return when you have\n"
# 486 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "organized your BAG.$"
# 487 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 488 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
# 489 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "We have been waiting for you…$"
# 490 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 491 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
# 492 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I must save before I show you to\n"
# 493 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the BATTLE HALL. Is that okay?$"
# 494 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 495 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
# 496 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Sigh…\p"
# 497 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You failed to save before you ended\n"
# 498 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your challenge the last time.\p"
# 499 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "As a result, your challenge has been\n"
# 500 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "disqualified. It is most unfortunate.$"
# 501 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 502 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
@ Unused
# 503 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
# 504 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 505 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 506 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 507 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
# 508 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "For a hardy fellow like me,\n"
# 509 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "hardy POKéMON are the best.\p"
# 510 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Offense is the best defense!\n"
# 511 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "A relentless attack is the ultimate!\p"
# 512 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "But that's not what I wanted to chat\n"
# 513 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "about.\p"
# 514 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Every so often a really cute lady\n"
# 515 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "swings by here.\p"
# 516 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "She says that she can tell what\n"
# 517 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "POKéMON are thinking.\p"
# 518 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I don't know about that part,\n"
# 519 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "but she is really cute.\p"
# 520 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Huh?\n"
# 521 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Why are you looking at me like that?$"
# 522 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 523 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
# 524 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Hmm…\p"
# 525 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "It appears that the nature of POKéMON\n"
# 526 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "and the moves that they have been\l"
# 527 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "taught are the keys to battle here.\p"
# 528 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To be more precise, it's how well\n"
# 529 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the moves match the nature of\l"
# 530 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the POKéMON.\p"
# 531 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If your POKéMON is in trouble and\n"
# 532 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "unable to live up to its potential,\l"
# 533 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "you may need to examine how well\l"
# 534 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "its moves match its nature.$"
# 535 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 536 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
# 537 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "My POKéMON is usually very docile.\p"
# 538 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "But when it's in a BATTLE HALL,\n"
# 539 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "it sometimes seems to become\l"
# 540 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "transformed into something wicked!\p"
# 541 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "It becomes totally intimidating.\n"
# 542 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "It's shocking, even.$"
# 543 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 544 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
# 545 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I wonder what sort of nature a POKéMON\n"
# 546 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "would have if it favored enfeebling its\l"
# 547 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "opponents and chipping away slowly.\p"
# 548 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I'd be surprised if it was a LAX nature.\p"
# 549 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "But, nah, that can't be right.$"
# 550 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 551 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
# 552 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Where the hearts of TRAINERS\n"
# 553 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "are put to the test.\p"
# 554 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I welcome you to the BATTLE PALACE.\p"
# 555 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "I accept challenges to the DOUBLE\n"
# 556 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "BATTLE HALLS.$"
# 557 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 558 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
# 559 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Do you wish to take\n"
# 560 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the DOUBLE BATTLE HALL challenge?$"
# 561 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 562 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
# 563 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "In the BATTLE PALACE, there are\n"
# 564 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "several auditoriums for DOUBLE BATTLES\l"
# 565 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "that are named DOUBLE BATTLE HALLS.\p"
# 566 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The DOUBLE BATTLES are conducted in\n"
# 567 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "the usual way, except with one crucial\l"
# 568 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "rule that must be obeyed.\p"
# 569 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "TRAINERS are permitted only to switch\n"
# 570 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "their POKéMON in and out.\p"
# 571 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "TRAINERS are otherwise forbidden to\n"
# 572 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "command their POKéMON.\p"
# 573 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The POKéMON are to behave according\n"
# 574 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "to their nature and battle on their own.\p"
# 575 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "You must put your trust in your\n"
# 576 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "POKéMON and watch over them.\p"
# 577 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you achieve the honor of beating\n"
# 578 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "seven TRAINERS in succession,\l"
# 579 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "we will present you with Battle Points.\p"
# 580 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 581 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 582 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 583 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "you will be disqualified.$"
# 584 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 585 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
# 586 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "To defeat the PALACE MAVEN\n"
# 587 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "and seven TRAINERS in a row…$"
# 588 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 589 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
# 590 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "In honor of the bond you share with\n"
# 591 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "your POKéMON, we present you with\l"
# 592 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "these Battle Point(s).$"
# 593 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 594 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
# 595 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Would you like to record your latest\n"
# 596 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "BATTLE PALACE match on your\l"
# 597 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 598 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 599 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
# 600 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "The BATTLE HALL rules are listed.$"
# 601 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 602 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
# 603 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 604 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 605 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
# 606 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Here, POKéMON are required to think\n"
# 607 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "and battle by themselves.\p"
# 608 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Unlike in the wild, POKéMON that live\n"
# 609 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "with people behave differently\l"
# 610 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "depending on their nature.$"
# 611 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 612 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
# 613 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Depending on its nature, a POKéMON\n"
# 614 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "may prefer to attack no matter what.\p"
# 615 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Another POKéMON may prefer to protect\n"
# 616 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "itself from any harm.\p"
# 617 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Yet another may enjoy vexing or\n"
# 618 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "confounding its foes.\p"
# 619 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Due to its nature, a POKéMON\n"
# 620 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "will have favorite moves that it is good\l"
# 621 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "at using.\p"
# 622 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "It may also dislike certain moves that\n"
# 623 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "it has trouble using.$"
# 624 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 625 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
# 626 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "There are offensive moves that inflict\n"
# 627 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "direct damage on the foe.\p"
# 628 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "There are defensive moves that are\n"
# 629 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "used to prepare for enemy attacks or\l"
# 630 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "used to heal HP and so on.\p"
# 631 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "There are also other somewhat-odd\n"
# 632 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "moves that may enfeeble the foes with\l"
# 633 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "stat problems including poison and \l"
# 634 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "paralysis.\p"
# 635 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "POKéMON will consider using moves in\n"
# 636 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "these three categories.$"
# 637 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 638 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
# 639 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "When not under command by its TRAINER,\n"
# 640 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "a POKéMON may be unable to effectively\l"
# 641 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "use certain moves.\p"
# 642 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "A POKéMON is not good at using any\n"
# 643 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "move that it dislikes.\p"
# 644 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If a POKéMON only knows moves that\n"
# 645 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "do not match its nature, it will often\l"
# 646 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "be unable to live up to its potential.$"
# 647 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"

# 648 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
# 649 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "Depending on its nature, a POKéMON may\n"
# 650 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "start using moves that don't match its\l"
# 651 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "nature when it is in trouble.\p"
# 652 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "If a POKéMON begins behaving oddly\n"
# 653 "data//maps/BattleFrontier_BattlePalaceLobby/scripts.pory"
	.string "in a pinch, watch it carefully.$"
