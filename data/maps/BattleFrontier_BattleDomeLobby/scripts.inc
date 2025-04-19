# 1 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
.set LOCALID_ATTENDANT_SINGLES, 1
# 3 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
.set LOCALID_ATTENDANT_DOUBLES, 6
# 4 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 5 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_MapScripts::
# 6 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume
# 7 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame
# 8 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
# 9 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.byte 0
# 10 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 11 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnResume:
# 12 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_initresultstree
# 13 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 14 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 15 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnWarp:
# 16 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth
# 17 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.2byte 0
# 18 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 19 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth::
# 20 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 21 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 22 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 23 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 24 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnFrame:
# 25 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus
# 26 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving
# 27 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge
# 28 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge
# 29 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge
# 30 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.2byte 0
# 31 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 32 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus::
# 33 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_getstatus
# 34 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 35 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 36 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving::
# 37 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 38 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 39 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 40 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK, 0
# 41 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
# 42 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 43 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 44 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 45 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 46 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 47 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 48 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WonChallenge::
# 49 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 50 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 51 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_isbrain
# 52 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce
# 53 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney, MSGBOX_DEFAULT
# 54 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints
# 55 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 56 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce::
# 57 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker, MSGBOX_DEFAULT
# 58 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints::
# 59 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints, MSGBOX_DEFAULT
# 60 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_givepoints
# 61 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 62 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
# 63 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 64 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 65 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 66 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkairshow
# 67 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 68 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
# 69 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
# 70 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 71 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 72 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 73 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle
# 74 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 75 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_LostChallenge::
# 76 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 77 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying, MSGBOX_DEFAULT
# 78 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
# 79 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 80 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 81 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 82 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkairshow
# 83 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
# 84 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 85 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 86 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 87 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 88 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle::
# 89 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_save 0
# 90 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	playse SE_SAVE
# 91 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitse
# 92 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 93 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 94 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch
# 95 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 96 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 97 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 98 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 99 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle
# 100 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 101 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 102 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RecordBattle::
# 103 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 104 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge::
# 105 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
# 106 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 107 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 108 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 109 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 110 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 111 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge::
# 112 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 113 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou, MSGBOX_DEFAULT
# 114 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2
# 115 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 116 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_save CHALLENGE_STATUS_SAVING
# 117 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	playse SE_SAVE
# 118 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitse
# 119 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 120 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 121 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge
# 122 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 123 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant::
# 124 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lock
# 125 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	faceplayer
# 126 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
# 127 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 128 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
# 129 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 130 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 131 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant::
# 132 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lock
# 133 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	faceplayer
# 134 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
# 135 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 136 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
# 137 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 138 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 139 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome::
# 140 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special SavePlayerParty
# 141 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles
# 142 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles
# 143 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge::
# 144 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge
# 145 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge
# 146 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 147 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 148 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 149 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge
# 150 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge
# 151 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 152 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 153 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 154 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge::
# 155 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode
# 156 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 157 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 158 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 159 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 160 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 161 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkineligible
# 162 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons
# 163 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 164 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 165 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 166 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 167 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 168 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 169 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 170 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 171 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 172 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 173 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 174 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 175 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 176 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge
# 177 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 178 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 179 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge::
# 180 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 181 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 182 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_init
# 183 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 184 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 185 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 186 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 187 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	delay 2
# 188 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 189 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 190 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed
# 191 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_inittrainers
# 192 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge::
# 193 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special SavePlayerParty
# 194 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 195 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_settrainers
# 196 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome, MSGBOX_DEFAULT
# 197 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 198 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor
# 199 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 200 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 23, 6
# 201 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 202 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 203 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 204 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 205 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge::
# 206 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge
# 207 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge
# 208 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge
# 209 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 210 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons::
# 211 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 212 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50
# 213 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen
# 214 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 215 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50::
# 216 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 217 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge
# 218 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 219 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen::
# 220 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 221 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge
# 222 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 223 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed::
# 224 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 225 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 226 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 227 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge::
# 228 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 229 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 230 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge::
# 231 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
# 232 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge::
# 233 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	release
# 234 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 235 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 236 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor::
# 237 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor
# 238 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor
# 239 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 240 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmovement 0
# 241 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor
# 242 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor
# 243 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitdooranim
# 244 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor
# 245 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor
# 246 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor
# 247 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmovement 0
# 248 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor
# 249 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor
# 250 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitdooranim
# 251 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 252 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 253 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor::
# 254 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 255 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 256 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 257 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor::
# 258 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 259 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 260 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 261 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor::
# 262 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
# 263 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 264 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 265 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor::
# 266 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
# 267 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 268 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 269 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles::
# 270 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle, MSGBOX_DEFAULT
# 271 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 272 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 273 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles::
# 274 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
# 275 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 276 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 277 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge::
# 278 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge
# 279 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 280 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 281 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge::
# 282 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge
# 283 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 284 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 285 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge::
# 286 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 287 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 288 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 289 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge::
# 290 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 291 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 292 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 293 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor::
# 294 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	opendoor 5, 4
# 295 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 296 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 297 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor::
# 298 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	opendoor 17, 4
# 299 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 300 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 301 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor::
# 302 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closedoor 5, 4
# 303 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 304 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 305 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor::
# 306 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closedoor 17, 4
# 307 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 308 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 309 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_WalkToDoor:
# 310 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 311 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 312 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 313 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 314 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 315 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 316 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 317 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor:
# 318 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 319 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	set_invisible
# 320 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 321 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 322 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor:
# 323 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 324 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 325 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	set_invisible
# 326 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 327 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 328 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults::
# 329 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 330 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
# 331 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitbuttonpress
# 332 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special RemoveRecordsWindow
# 333 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 334 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 335 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 336 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults::
# 337 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 338 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
# 339 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitbuttonpress
# 340 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special RemoveRecordsWindow
# 341 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 342 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 343 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 344 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree::
# 345 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
# 346 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50
# 347 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50
# 348 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen
# 349 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen
# 350 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 351 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_showprevtourneytree
# 352 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 353 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 354 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 355 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50::
# 356 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50, MSGBOX_SIGN
# 357 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 358 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 359 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50::
# 360 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50, MSGBOX_SIGN
# 361 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 362 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 363 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen::
# 364 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen, MSGBOX_SIGN
# 365 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 366 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 367 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen::
# 368 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen, MSGBOX_SIGN
# 369 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 370 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 371 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Maniac::
# 372 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_getwinnersname
# 373 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough, MSGBOX_NPC
# 374 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 375 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 376 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Lass::
# 377 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation, MSGBOX_NPC
# 378 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 379 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 380 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_FatMan::
# 381 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound, MSGBOX_NPC
# 382 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 383 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 384 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Man::
# 385 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully, MSGBOX_NPC
# 386 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 387 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 388 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ A few OutsideWest event scripts are inserted here instead, two of which are unused
# 389 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man3::
# 390 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier, MSGBOX_NPC
# 391 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 392 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 393 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 394 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2::
# 395 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2, MSGBOX_NPC
# 396 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 397 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 398 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 399 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign::
# 400 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction, MSGBOX_NPC
# 401 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 402 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 403 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesBoard::
# 404 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 405 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 406 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 407 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 408 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 409 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard::
# 410 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading
# 411 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 412 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
# 413 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 414 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup
# 415 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree
# 416 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO
# 417 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
# 418 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
# 419 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 420 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 421 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup::
# 422 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules, MSGBOX_DEFAULT
# 423 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 424 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 425 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 426 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree::
# 427 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree, MSGBOX_DEFAULT
# 428 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 429 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 430 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 431 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO::
# 432 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules, MSGBOX_DEFAULT
# 433 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 434 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 435 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 436 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExitRules::
# 437 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 438 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 439 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 440 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle:
# 441 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Where the strategies of TRAINERS\n"
# 442 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are put to the test!\p"
# 443 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Welcome to the BATTLE DOME!\p"
# 444 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I am your guide to the SINGLE BATTLE\n"
# 445 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament.$"
# 446 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 447 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge:
# 448 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to challenge\n"
# 449 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the SINGLE BATTLE Tournament?$"
# 450 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 451 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain:
# 452 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "We hope to see you again.$"
# 453 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 454 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge:
# 455 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The SINGLE BATTLE Tournament\n"
# 456 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "is exactly as the name suggests--\l"
# 457 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a tournament of SINGLE BATTLES.\p"
# 458 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "All participating TRAINERS must\n"
# 459 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "enter three POKéMON each.\p"
# 460 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In each battle, one of the three\n"
# 461 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "POKéMON must be held in reserve.\p"
# 462 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The other two POKéMON can battle\n"
# 463 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "one at a time.\p"
# 464 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Choose the two battling POKéMON after\n"
# 465 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "examining the opponent's trio.\p"
# 466 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You win the tournament by defeating\n"
# 467 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "four TRAINERS.\p"
# 468 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Battle Points are awarded to\n"
# 469 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the tournament winner.\p"
# 470 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 471 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament, please save the game.\p"
# 472 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 473 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you will be disqualified.$"
# 474 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 475 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge:
# 476 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Before I show you to the BATTLE DOME,\n"
# 477 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I must save the data. Is that okay?$"
# 478 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 479 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WhichLevelMode:
# 480 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament offers two levels\n"
# 481 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "of challenge, Level 50 and Open Level.\l"
# 482 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Which is your choice?$"
# 483 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 484 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_SelectThreeMons:
# 485 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Now select the three POKéMON that\n"
# 486 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you wish to enter, please.$"
# 487 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 488 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen:
# 489 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 490 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You don't have three eligible POKéMON.\p"
# 491 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Also, the POKéMON must be holding\n"
# 492 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "different kinds of items.\p"
# 493 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 494 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 495 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 496 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50:
# 497 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 498 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You don't have three eligible POKéMON.\p"
# 499 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You must have three different POKéMON\n"
# 500 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 501 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They also must be holding different\n"
# 502 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "kinds of items.\p"
# 503 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 504 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 505 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 506 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome:
# 507 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I will now show you to\n"
# 508 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the BATTLE DOME.$"
# 509 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 510 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting:
# 511 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 512 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You didn't save before you quit your\n"
# 513 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "challenge last time.\p"
# 514 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Because of that, your challenge so far\n"
# 515 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "has been disqualified. Sorry!$"
# 516 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 517 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney:
# 518 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Congratulations for winning\n"
# 519 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "your Battle Tournament!$"
# 520 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 521 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 522 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize:
# 523 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Here is your prize for your Battle\n"
# 524 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament victory.$"
# 525 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 526 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Used by Verdanturf Tent
# 527 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize:
# 528 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 529 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 530 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 531 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 532 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom:
# 533 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Oh, your BAG appears to be full.\p"
# 534 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please make room in your BAG, then come\n"
# 535 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "see me.$"
# 536 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 537 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying:
# 538 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Thank you for playing!$"
# 539 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 540 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved:
# 541 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Your record will be saved.\n"
# 542 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please wait.$"
# 543 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 544 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou:
# 545 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "We've been waiting for you!$"
# 546 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 547 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2:
# 548 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Before I show you to the BATTLE DOME,\n"
# 549 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I must save the data. Is that okay?$"
# 550 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 551 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle:
# 552 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Where the strategies of TRAINERS\n"
# 553 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are put to the test!\p"
# 554 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Welcome to the BATTLE DOME!\p"
# 555 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I am your guide to the DOUBLE BATTLE\n"
# 556 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament.$"
# 557 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 558 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge:
# 559 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to challenge\n"
# 560 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the DOUBLE BATTLE Tournament?$"
# 561 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 562 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge:
# 563 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The DOUBLE BATTLE Tournament\n"
# 564 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "is exactly as the name suggests--\l"
# 565 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a tournament of DOUBLE BATTLES.\p"
# 566 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "All participating TRAINERS must\n"
# 567 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "enter three POKéMON each.\p"
# 568 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In each battle, one of the three\n"
# 569 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "POKéMON must be held in reserve.\p"
# 570 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The remaining two POKéMON must take\n"
# 571 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "part in a DOUBLE BATTLE.\p"
# 572 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Choose the two battling POKéMON after\n"
# 573 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "examining the opponent's trio.\p"
# 574 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You win the tournament by defeating\n"
# 575 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "four TRAINERS.\p"
# 576 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Battle Points are awarded to\n"
# 577 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the tournament winner.\p"
# 578 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 579 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament, please save the game.\p"
# 580 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 581 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you will be disqualified.$"
# 582 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 583 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50:
# 584 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 585 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Level 50 SINGLE BATTLE Tournament.$"
# 586 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 587 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50:
# 588 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 589 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Level 50 DOUBLE BATTLE Tournament.$"
# 590 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 591 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen:
# 592 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 593 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Open Level SINGLE BATTLE Tournament.$"
# 594 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 595 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen:
# 596 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 597 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Open Level DOUBLE BATTLE Tournament.$"
# 598 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 599 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough:
# 600 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Did you see it?\n"
# 601 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The last Battle Tournament?\p"
# 602 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The winner, {STR_VAR_1}, was seriously\n"
# 603 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tough.\p"
# 604 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You should check out the results\n"
# 605 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "on the monitor beside the PC.$"
# 606 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 607 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier:
# 608 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The BATTLE FRONTIER…\n"
# 609 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I've long dreamed about a place like it.$"
# 610 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 611 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Functionally unused
# 612 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleDomeSign2:
# 613 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The BATTLE DOME\n"
# 614 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Become the Unbeatable Superstar!$"
# 615 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 616 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Functionally unused
# 617 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction:
# 618 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The ??????\n"
# 619 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Under Construction!$"
# 620 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 621 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation:
# 622 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "When a TRAINER chains tournament\n"
# 623 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "wins at the BATTLE DOME, he or she\l"
# 624 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "gains a reputation as a star.\p"
# 625 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tough TRAINERS are drawn by that\n"
# 626 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "reputation to the BATTLE DOME.\p"
# 627 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "A true superstar is a TRAINER who\n"
# 628 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "can keep winning tournaments.$"
# 629 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 630 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound:
# 631 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I ran into one of the tournament\n"
# 632 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "favorites in the very first round.\p"
# 633 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Of course I got trashed…$"
# 634 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 635 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully:
# 636 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I would've won if I'd kept this POKéMON\n"
# 637 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "held in reserve.\p"
# 638 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 639 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "POKéMON carefully before choosing\l"
# 640 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "your battling POKéMON.$"
# 641 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 642 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker:
# 643 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Congratulations!\p"
# 644 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You defeated the DOME ACE and won\n"
# 645 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the Battle Tournament!$"
# 646 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 647 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints:
# 648 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In recognition of your strategy--\n"
# 649 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a thing of beauty it was, too--\l"
# 650 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "we award you these Battle Point(s)!$"
# 651 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 652 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RecordLastMatch:
# 653 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to record your\n"
# 654 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "last BATTLE DOME match on your\l"
# 655 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 656 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 657 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RulesAreListed:
# 658 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Battle Tournament rules\n"
# 659 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are listed.$"
# 660 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 661 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading:
# 662 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 663 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 664 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules:
# 665 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament matchups are drawn up\n"
# 666 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "based on the toughness of POKéMON\l"
# 667 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "held by TRAINERS.\p"
# 668 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The matchups avoid having tough\n"
# 669 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "TRAINERS face each other right away.$"
# 670 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 671 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree:
# 672 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament chart, or as we call it,\n"
# 673 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the “Tree,” is available for viewing\l"
# 674 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "in the Waiting Room from any guide.\p"
# 675 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Tournament Tree will provide\n"
# 676 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "several kinds of data.\p"
# 677 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The data on view includes the previous\n"
# 678 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament's results, the POKéMON held\l"
# 679 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "by TRAINERS, and the battle styles of\l"
# 680 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "TRAINERS.$"
# 681 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 682 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules:
# 683 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If battling POKéMON faint at the same\n"
# 684 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "time--a double KO--in a tournament\l"
# 685 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "match, the REFEREES will review\l"
# 686 "data//maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the match and declare the winner.$"
