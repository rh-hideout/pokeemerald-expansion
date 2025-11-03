# 1 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_MapScripts::
# 3 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume
# 4 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame
# 5 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
# 6 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.byte 0
# 7 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 8 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnResume:
# 9 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_initresultstree
# 10 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 11 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 12 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnWarp:
# 13 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth
# 14 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.2byte 0
# 15 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 16 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth::
# 17 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 18 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 19 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 20 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 21 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnFrame:
# 22 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus
# 23 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving
# 24 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge
# 25 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge
# 26 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge
# 27 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.2byte 0
# 28 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 29 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus::
# 30 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_getstatus
# 31 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 32 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 33 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving::
# 34 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 35 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 36 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 37 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK, 0
# 38 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
# 39 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 40 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 41 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 42 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 43 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WonChallenge::
# 46 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 47 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 48 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_isbrain
# 49 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce
# 50 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney, MSGBOX_DEFAULT
# 51 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints
# 52 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 53 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce::
# 54 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker, MSGBOX_DEFAULT
# 55 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints::
# 56 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints, MSGBOX_DEFAULT
# 57 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_givepoints
# 58 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 59 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
# 60 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 61 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 62 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 63 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkairshow
# 64 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 65 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
# 66 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
# 67 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 68 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 69 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 70 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle
# 71 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 72 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_LostChallenge::
# 73 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 74 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying, MSGBOX_DEFAULT
# 75 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
# 76 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 77 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 78 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 79 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkairshow
# 80 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
# 81 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 82 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 83 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 84 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 85 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle::
# 86 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_save 0
# 87 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	playse SE_SAVE
# 88 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitse
# 89 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 90 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 91 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch
# 92 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 93 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 94 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 95 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 96 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle
# 97 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 98 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 99 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RecordBattle::
# 100 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 101 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge::
# 102 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
# 103 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 104 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 105 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 106 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 107 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 108 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge::
# 109 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 110 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou, MSGBOX_DEFAULT
# 111 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2
# 112 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 113 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_save CHALLENGE_STATUS_SAVING
# 114 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	playse SE_SAVE
# 115 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitse
# 116 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 117 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 118 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge
# 119 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 120 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant::
# 121 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lock
# 122 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	faceplayer
# 123 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
# 124 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 125 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
# 126 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 127 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 128 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant::
# 129 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lock
# 130 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	faceplayer
# 131 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
# 132 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 133 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
# 134 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 135 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 136 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome::
# 137 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special SavePlayerParty
# 138 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles
# 139 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles
# 140 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge::
# 141 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge
# 142 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge
# 143 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 144 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 145 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge
# 147 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge
# 148 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 149 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 150 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 151 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge::
# 152 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode
# 153 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 154 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 155 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 156 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 157 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 158 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkineligible
# 159 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons
# 160 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 161 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 162 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 163 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 164 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 165 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 166 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 167 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 168 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 169 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 170 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 171 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 172 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 173 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge
# 174 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 175 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 176 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge::
# 177 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 178 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 179 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_init
# 180 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 181 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 182 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 183 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 184 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	delay 2
# 185 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 186 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 187 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed
# 188 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_inittrainers
# 189 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge::
# 190 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special SavePlayerParty
# 191 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 192 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_settrainers
# 193 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome, MSGBOX_DEFAULT
# 194 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 195 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor
# 196 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 197 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 23, 6
# 198 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 199 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 200 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 201 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 202 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge::
# 203 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge
# 204 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge
# 205 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge
# 206 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 207 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons::
# 208 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 209 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50
# 210 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen
# 211 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 212 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50::
# 213 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 214 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge
# 215 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 216 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen::
# 217 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 218 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge
# 219 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 220 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed::
# 221 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 222 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 223 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 224 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge::
# 225 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 226 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 227 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge::
# 228 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
# 229 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge::
# 230 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	release
# 231 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 232 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 233 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor::
# 234 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor
# 235 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor
# 236 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 237 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmovement 0
# 238 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor
# 239 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor
# 240 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitdooranim
# 241 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor
# 242 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor
# 243 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor
# 244 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmovement 0
# 245 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor
# 246 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor
# 247 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitdooranim
# 248 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 249 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 250 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor::
# 251 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 252 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 253 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 254 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor::
# 255 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 256 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 257 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 258 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor::
# 259 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
# 260 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 261 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 262 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor::
# 263 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
# 264 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 265 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 266 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles::
# 267 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle, MSGBOX_DEFAULT
# 268 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 269 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 270 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles::
# 271 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
# 272 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 273 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 274 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge::
# 275 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge
# 276 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 277 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 278 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge::
# 279 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge
# 280 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 281 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 282 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge::
# 283 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 284 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 285 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 286 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge::
# 287 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 288 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 289 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 290 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor::
# 291 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	opendoor 5, 4
# 292 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 293 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 294 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor::
# 295 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	opendoor 17, 4
# 296 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 297 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 298 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor::
# 299 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closedoor 5, 4
# 300 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 301 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 302 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor::
# 303 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closedoor 17, 4
# 304 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 305 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 306 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_WalkToDoor:
# 307 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 308 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 309 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 310 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 311 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 312 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 313 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 314 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor:
# 315 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 316 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	set_invisible
# 317 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 318 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 319 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor:
# 320 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 321 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 322 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	set_invisible
# 323 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 324 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 325 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults::
# 326 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 327 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
# 328 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitbuttonpress
# 329 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special RemoveRecordsWindow
# 330 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 331 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 332 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 333 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults::
# 334 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 335 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
# 336 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitbuttonpress
# 337 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special RemoveRecordsWindow
# 338 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 339 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 340 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 341 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree::
# 342 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
# 343 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50
# 344 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50
# 345 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen
# 346 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen
# 347 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 348 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_showprevtourneytree
# 349 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 350 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 351 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 352 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50::
# 353 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50, MSGBOX_SIGN
# 354 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 355 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 356 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50::
# 357 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50, MSGBOX_SIGN
# 358 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 359 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 360 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen::
# 361 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen, MSGBOX_SIGN
# 362 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 363 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 364 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen::
# 365 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen, MSGBOX_SIGN
# 366 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 367 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 368 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Maniac::
# 369 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_getwinnersname
# 370 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough, MSGBOX_NPC
# 371 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 372 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 373 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Lass::
# 374 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation, MSGBOX_NPC
# 375 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 376 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 377 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_FatMan::
# 378 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound, MSGBOX_NPC
# 379 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 380 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 381 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Man::
# 382 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully, MSGBOX_NPC
# 383 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 384 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 385 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ A few OutsideWest event scripts are inserted here instead, two of which are unused
# 386 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man3::
# 387 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier, MSGBOX_NPC
# 388 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 389 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 391 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2::
# 392 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2, MSGBOX_NPC
# 393 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 394 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 395 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 396 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign::
# 397 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction, MSGBOX_NPC
# 398 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 399 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 400 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesBoard::
# 401 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 402 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 403 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 404 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 405 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 406 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard::
# 407 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading
# 408 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 409 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
# 410 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 411 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup
# 412 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree
# 413 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO
# 414 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
# 415 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
# 416 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 417 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 418 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup::
# 419 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules, MSGBOX_DEFAULT
# 420 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 421 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 422 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 423 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree::
# 424 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree, MSGBOX_DEFAULT
# 425 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 426 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 427 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 428 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO::
# 429 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules, MSGBOX_DEFAULT
# 430 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 431 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 432 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 433 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExitRules::
# 434 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 435 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 436 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 437 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle:
# 438 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Where the strategies of TRAINERS\n"
# 439 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are put to the test!\p"
# 440 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Welcome to the BATTLE DOME!\p"
# 441 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I am your guide to the SINGLE BATTLE\n"
# 442 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament.$"
# 443 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 444 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge:
# 445 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to challenge\n"
# 446 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the SINGLE BATTLE Tournament?$"
# 447 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 448 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain:
# 449 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "We hope to see you again.$"
# 450 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 451 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge:
# 452 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The SINGLE BATTLE Tournament\n"
# 453 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "is exactly as the name suggests--\l"
# 454 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a tournament of SINGLE BATTLES.\p"
# 455 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "All participating TRAINERS must\n"
# 456 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "enter three POKéMON each.\p"
# 457 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In each battle, one of the three\n"
# 458 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "POKéMON must be held in reserve.\p"
# 459 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The other two POKéMON can battle\n"
# 460 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "one at a time.\p"
# 461 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Choose the two battling POKéMON after\n"
# 462 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "examining the opponent's trio.\p"
# 463 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You win the tournament by defeating\n"
# 464 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "four TRAINERS.\p"
# 465 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Battle Points are awarded to\n"
# 466 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the tournament winner.\p"
# 467 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 468 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament, please save the game.\p"
# 469 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 470 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you will be disqualified.$"
# 471 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 472 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge:
# 473 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Before I show you to the BATTLE DOME,\n"
# 474 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I must save the data. Is that okay?$"
# 475 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 476 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WhichLevelMode:
# 477 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament offers two levels\n"
# 478 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "of challenge, Level 50 and Open Level.\l"
# 479 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Which is your choice?$"
# 480 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 481 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_SelectThreeMons:
# 482 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Now select the three POKéMON that\n"
# 483 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you wish to enter, please.$"
# 484 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 485 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen:
# 486 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 487 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You don't have three eligible POKéMON.\p"
# 488 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Also, the POKéMON must be holding\n"
# 489 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "different kinds of items.\p"
# 490 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 491 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 492 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 493 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50:
# 494 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 495 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You don't have three eligible POKéMON.\p"
# 496 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You must have three different POKéMON\n"
# 497 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 498 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They also must be holding different\n"
# 499 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "kinds of items.\p"
# 500 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 501 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 502 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 503 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome:
# 504 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I will now show you to\n"
# 505 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the BATTLE DOME.$"
# 506 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 507 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting:
# 508 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 509 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You didn't save before you quit your\n"
# 510 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "challenge last time.\p"
# 511 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Because of that, your challenge so far\n"
# 512 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "has been disqualified. Sorry!$"
# 513 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 514 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney:
# 515 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Congratulations for winning\n"
# 516 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "your Battle Tournament!$"
# 517 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 518 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 519 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize:
# 520 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Here is your prize for your Battle\n"
# 521 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament victory.$"
# 522 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 523 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Used by Verdanturf Tent
# 524 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize:
# 525 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 526 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 527 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 528 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 529 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom:
# 530 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Oh, your BAG appears to be full.\p"
# 531 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please make room in your BAG, then come\n"
# 532 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "see me.$"
# 533 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 534 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying:
# 535 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Thank you for playing!$"
# 536 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 537 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved:
# 538 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Your record will be saved.\n"
# 539 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please wait.$"
# 540 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 541 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou:
# 542 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "We've been waiting for you!$"
# 543 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 544 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2:
# 545 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Before I show you to the BATTLE DOME,\n"
# 546 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I must save the data. Is that okay?$"
# 547 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 548 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle:
# 549 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Where the strategies of TRAINERS\n"
# 550 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are put to the test!\p"
# 551 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Welcome to the BATTLE DOME!\p"
# 552 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I am your guide to the DOUBLE BATTLE\n"
# 553 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament.$"
# 554 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 555 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge:
# 556 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to challenge\n"
# 557 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the DOUBLE BATTLE Tournament?$"
# 558 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 559 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge:
# 560 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The DOUBLE BATTLE Tournament\n"
# 561 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "is exactly as the name suggests--\l"
# 562 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a tournament of DOUBLE BATTLES.\p"
# 563 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "All participating TRAINERS must\n"
# 564 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "enter three POKéMON each.\p"
# 565 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In each battle, one of the three\n"
# 566 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "POKéMON must be held in reserve.\p"
# 567 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The remaining two POKéMON must take\n"
# 568 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "part in a DOUBLE BATTLE.\p"
# 569 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Choose the two battling POKéMON after\n"
# 570 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "examining the opponent's trio.\p"
# 571 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You win the tournament by defeating\n"
# 572 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "four TRAINERS.\p"
# 573 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Battle Points are awarded to\n"
# 574 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the tournament winner.\p"
# 575 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 576 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament, please save the game.\p"
# 577 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 578 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you will be disqualified.$"
# 579 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 580 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50:
# 581 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 582 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Level 50 SINGLE BATTLE Tournament.$"
# 583 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 584 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50:
# 585 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 586 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Level 50 DOUBLE BATTLE Tournament.$"
# 587 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 588 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen:
# 589 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 590 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Open Level SINGLE BATTLE Tournament.$"
# 591 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 592 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen:
# 593 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 594 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Open Level DOUBLE BATTLE Tournament.$"
# 595 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 596 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough:
# 597 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Did you see it?\n"
# 598 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The last Battle Tournament?\p"
# 599 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The winner, {STR_VAR_1}, was seriously\n"
# 600 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tough.\p"
# 601 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You should check out the results\n"
# 602 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "on the monitor beside the PC.$"
# 603 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 604 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier:
# 605 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The BATTLE FRONTIER…\n"
# 606 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I've long dreamed about a place like it.$"
# 607 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 608 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Functionally unused
# 609 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleDomeSign2:
# 610 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The BATTLE DOME\n"
# 611 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Become the Unbeatable Superstar!$"
# 612 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 613 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Functionally unused
# 614 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction:
# 615 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The ??????\n"
# 616 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Under Construction!$"
# 617 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 618 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation:
# 619 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "When a TRAINER chains tournament\n"
# 620 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "wins at the BATTLE DOME, he or she\l"
# 621 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "gains a reputation as a star.\p"
# 622 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tough TRAINERS are drawn by that\n"
# 623 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "reputation to the BATTLE DOME.\p"
# 624 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "A true superstar is a TRAINER who\n"
# 625 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "can keep winning tournaments.$"
# 626 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 627 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound:
# 628 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I ran into one of the tournament\n"
# 629 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "favorites in the very first round.\p"
# 630 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Of course I got trashed…$"
# 631 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 632 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully:
# 633 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I would've won if I'd kept this POKéMON\n"
# 634 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "held in reserve.\p"
# 635 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 636 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "POKéMON carefully before choosing\l"
# 637 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "your battling POKéMON.$"
# 638 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 639 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker:
# 640 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Congratulations!\p"
# 641 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You defeated the DOME ACE and won\n"
# 642 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the Battle Tournament!$"
# 643 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 644 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints:
# 645 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In recognition of your strategy--\n"
# 646 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a thing of beauty it was, too--\l"
# 647 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "we award you these Battle Point(s)!$"
# 648 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 649 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RecordLastMatch:
# 650 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to record your\n"
# 651 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "last BATTLE DOME match on your\l"
# 652 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 653 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 654 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RulesAreListed:
# 655 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Battle Tournament rules\n"
# 656 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are listed.$"
# 657 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 658 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading:
# 659 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 660 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 661 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules:
# 662 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament matchups are drawn up\n"
# 663 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "based on the toughness of POKéMON\l"
# 664 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "held by TRAINERS.\p"
# 665 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The matchups avoid having tough\n"
# 666 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "TRAINERS face each other right away.$"
# 667 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 668 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree:
# 669 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament chart, or as we call it,\n"
# 670 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the “Tree,” is available for viewing\l"
# 671 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "in the Waiting Room from any guide.\p"
# 672 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Tournament Tree will provide\n"
# 673 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "several kinds of data.\p"
# 674 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The data on view includes the previous\n"
# 675 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament's results, the POKéMON held\l"
# 676 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "by TRAINERS, and the battle styles of\l"
# 677 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "TRAINERS.$"
# 678 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 679 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules:
# 680 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If battling POKéMON faint at the same\n"
# 681 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "time--a double KO--in a tournament\l"
# 682 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "match, the REFEREES will review\l"
# 683 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the match and declare the winner.$"
