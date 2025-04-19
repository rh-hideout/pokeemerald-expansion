# 1 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
.set LOCALID_ATTENDANT_SINGLES, 1
# 3 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
.set LOCALID_ATTENDANT_DOUBLES, 7
# 4 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
.set LOCALID_ATTENDANT_MULTIS, 8
# 5 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
.set LOCALID_ATTENDANT_LINK_MULTIS, 9
# 6 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 7 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Note: LOCALID_BATTLE_TOWER_LOBBY_REPORTER is a local id for this map used elsewhere. It's defined in event_objects.h
# 8 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 9 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_MapScripts::
# 10 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerLobby_OnResume
# 11 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerLobby_OnTransition
# 12 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_OnFrame
# 13 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_OnWarp
# 14 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.byte 0
# 15 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 16 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_OnResume:
# 17 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TryHideBattleTowerReporter
# 18 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 19 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 20 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_OnTransition:
# 21 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_ShowOrHideReporter
# 22 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	apprentice_shouldcheckgone
# 23 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_0x8004, FALSE, BattleFrontier_BattleTowerLobby_EventScript_ShowApprentice  @ VAR_0x8004 always TRUE here
# 24 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, BattleFrontier_BattleTowerLobby_EventScript_HideApprentice
# 25 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowApprentice::
# 26 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_HIDE_APPRENTICE
# 27 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	apprentice_setgfx
# 28 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_EndShowOrHideApprentice::
# 29 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 30 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 31 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_HideApprentice::
# 32 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setflag FLAG_HIDE_APPRENTICE
# 33 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndShowOrHideApprentice
# 34 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 35 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_OnWarp:
# 36 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth
# 37 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.2byte 0
# 38 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 39 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth::
# 40 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 41 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 42 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 43 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 44 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_OnFrame:
# 45 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus
# 46 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving
# 47 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge
# 48 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleTowerLobby_EventScript_WonChallenge
# 49 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleTowerLobby_EventScript_LostChallenge
# 50 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.2byte 0
# 51 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 52 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus::
# 53 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_getstatus
# 54 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 55 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 56 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving::
# 57 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 58 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 59 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 60 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 61 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK, 0
# 62 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
# 63 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 64 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 65 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 66 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 67 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 68 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_WonChallenge::
# 69 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 70 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 71 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_isbrain
# 72 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden
# 73 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven
# 74 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 75 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons
# 76 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 77 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden::
# 78 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
# 79 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons::
# 80 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_giveribbons
# 81 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints
# 82 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons
# 83 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 84 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 85 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitfanfare
# 86 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons, MSGBOX_DEFAULT
# 87 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints::
# 88 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
# 89 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_givepoints
# 90 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 91 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
# 92 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 93 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_ne VAR_RESULT, 49, BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge
# 94 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
# 95 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge::
# 96 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 97 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 98 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 99 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 100 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 101 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 102 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 103 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LostChallenge::
# 104 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_ne VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
# 105 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
# 106 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 107 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying
# 108 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak::
# 109 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
# 110 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying::
# 111 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 112 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 113 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying
# 114 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 115 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
# 116 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 117 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 118 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 119 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 120 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 121 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 122 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 123 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle::
# 124 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved
# 125 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 126 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkairshow
# 127 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 128 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special HealPlayerParty
# 129 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save 0
# 130 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 131 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 132 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 133 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
# 134 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_RecordLastMatch
# 135 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 136 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 137 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 138 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
# 139 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_EventScript_SaveBattle
# 140 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
# 141 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 142 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_EventScript_SaveBattle::
# 143 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_savebattle
# 144 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_EventScript_BattleSaveFailed
# 145 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 146 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
# 147 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
# 148 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 149 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_EventScript_BattleSaveFailed::
# 150 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved, MSGBOX_DEFAULT
# 151 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle::
# 152 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 153 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 154 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_EventScript_GetCantRecordBattle::
# 155 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_get FRONTIER_DATA_RECORD_DISABLED
# 156 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 157 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 158 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge::
# 159 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 160 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 161 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_SetBravoTrainerOn
# 162 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou
# 163 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 164 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved
# 165 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 166 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 167 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 168 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 169 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 170 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 171 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 172 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 173 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SetBravoTrainerOn::
# 174 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
# 175 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 176 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 177 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SinglesAttendant::
# 178 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 179 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 180 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 181 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 182 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle, MSGBOX_DEFAULT
# 183 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskEnterSinglesChallenge::
# 184 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge
# 185 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 186 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 187 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 188 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge
# 189 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainSinglesChallenge
# 190 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 191 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 192 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 193 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge::
# 194 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 195 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 196 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 197 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 198 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 199 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 200 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 201 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 202 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 203 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 204 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 205 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 206 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 207 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 208 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 209 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 210 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 211 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 212 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 213 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 214 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 215 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 216 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge
# 217 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 218 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 219 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge::
# 220 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 221 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 222 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 223 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 224 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 225 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 226 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 227 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 228 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 229 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 230 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
# 231 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 232 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
# 233 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 234 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 235 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 236 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExplainSinglesChallenge::
# 237 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 238 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterSinglesChallenge
# 239 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 240 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 241 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_DoublesAttendant::
# 242 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 243 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 244 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 245 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 246 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
# 247 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskEnterDoublesChallenge::
# 248 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge
# 249 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 250 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 251 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 252 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge
# 253 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainDoublesChallenge
# 254 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 255 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 256 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 257 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge::
# 258 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 259 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 260 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 261 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 262 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 263 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 264 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 265 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 266 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 267 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 268 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
# 269 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 270 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 271 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 272 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 273 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
# 274 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 275 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 276 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 277 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 278 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 279 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 280 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge
# 281 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 282 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 283 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge::
# 284 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 285 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 286 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 287 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 288 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 289 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 290 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 291 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 292 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 293 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 294 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
# 295 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 296 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 297 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 298 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 299 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 300 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExplainDoublesChallenge::
# 301 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 302 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterDoublesChallenge
# 303 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 304 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 305 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_MultisAttendant::
# 306 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 307 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 308 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 309 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
# 310 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 311 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle, MSGBOX_DEFAULT
# 312 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskEnterMultisChallenge::
# 313 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge
# 314 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 315 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 316 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 317 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge
# 318 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainMultisChallenge
# 319 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 320 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 321 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 322 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge::
# 323 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 324 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 325 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 326 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 327 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 328 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 329 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 330 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 331 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 332 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 333 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons, MSGBOX_DEFAULT
# 334 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 335 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 336 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 337 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 338 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
# 339 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 340 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 341 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 342 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 343 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 344 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 345 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge
# 346 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 347 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 348 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge::
# 349 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 350 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 351 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 352 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 353 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 354 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 355 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 356 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 357 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 358 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 359 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
# 360 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 361 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 362 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 363 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 364 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 365 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExplainMultisChallenge::
# 366 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge, MSGBOX_DEFAULT
# 367 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterMultisChallenge
# 368 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 369 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 370 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LinkMultisAttendant::
# 371 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 372 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 373 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 374 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 375 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle, MSGBOX_DEFAULT
# 376 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskEnterLinkMultisChallenge::
# 377 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge
# 378 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 379 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 380 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 381 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterLinkMultisChallenge
# 382 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainLinkMultisChallenge
# 383 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 384 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 385 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 386 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryEnterLinkMultisChallenge::
# 387 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 388 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 389 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 390 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 391 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 392 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 393 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 394 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 395 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 396 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 397 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2, MSGBOX_DEFAULT
# 398 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 399 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	callnative RemoveFollowingPokemon
# 400 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 401 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 402 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
# 403 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 404 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 405 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 406 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 407 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 408 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 409 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge
# 410 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 411 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 412 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge::
# 413 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 414 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 415 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 416 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 417 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 418 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 419 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 420 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 421 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ The command tower_save ultimately calls TrySavingData(SAVE_LINK), which writes data in SaveBlock1 and SaveBlock2
# 422 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ to the flash, but not data in PokemonStorage. The SaveGame script that follows asks the player to do a full save,
# 423 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ which they can opt out of. As a result the player can save their party and quit without having saved the PC.
# 424 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ This allows players to clone pokemon and their held items by withdrawing them (or erase them by despositing).
# 425 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
#ifndef BUGFIX
# 426 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save 0
# 427 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
#endif
# 428 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 429 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 430 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
# 431 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ GAME_STAT_ENTERED_BATTLE_TOWER should not be incremented here, for two reasons:
# 432 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ 1. It is incremented again in BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful or BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
# 433 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ 2. If the player tries to connect, but fails, the counter will still be incremented even if the player never enters the tower.
# 434 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
#ifndef BUGFIX
# 435 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 436 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
#endif
# 437 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 438 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink
# 439 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink
# 440 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 441 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 442 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan::
# 443 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 444 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 445 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower
# 446 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 447 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 16, 4, MULTI_BATTLE_TOWER_FEELINGS, FALSE
# 448 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 449 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_FeelingsBattleNow
# 450 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsIWon
# 451 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_FeelingsILost
# 452 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 3, BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell
# 453 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell
# 454 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 455 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 456 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 457 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsBattleNow::
# 458 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin, MSGBOX_DEFAULT
# 459 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_START
# 460 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_ShowEasyChatScreen
# 461 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 462 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 463 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
# 464 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 465 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 466 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsIWon::
# 467 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon, MSGBOX_DEFAULT
# 468 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_WON
# 469 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_ShowEasyChatScreen
# 470 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 471 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 472 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
# 473 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 474 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 475 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsILost::
# 476 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost, MSGBOX_DEFAULT
# 477 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_LOST
# 478 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_ShowEasyChatScreen
# 479 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 480 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 481 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
# 482 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 483 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 484 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell::
# 485 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt, MSGBOX_DEFAULT
# 486 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 487 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 488 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 489 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings::
# 490 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CanceledEasyChat
# 491 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleTowerLobby_EventScript_SubmittedFeelings
# 492 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 493 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 494 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CanceledEasyChat::
# 495 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChangedYourMind, MSGBOX_DEFAULT
# 496 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 497 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 498 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 499 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SubmittedFeelings::
# 500 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel, MSGBOX_DEFAULT
# 501 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 502 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 503 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 504 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_Woman::
# 505 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded, MSGBOX_NPC
# 506 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 507 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 508 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_Boy::
# 509 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins, MSGBOX_NPC
# 510 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 511 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 512 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowSinglesResults::
# 513 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 514 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_SINGLES
# 515 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 516 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 517 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 518 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 519 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 520 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowDoublesResults::
# 521 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 522 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_DOUBLES
# 523 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 524 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 525 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 526 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 527 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 528 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowMultisResults::
# 529 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 530 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_MULTIS
# 531 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 532 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 533 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 534 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 535 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 536 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowLinkMultisResults::
# 537 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 538 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_LINK_MULTIS
# 539 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 540 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 541 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 542 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 543 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 544 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons::
# 545 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 546 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50
# 547 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen
# 548 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 549 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50::
# 550 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 551 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles
# 552 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles
# 553 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis, MSGBOX_DEFAULT
# 554 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 555 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 556 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 557 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles::
# 558 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
# 559 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 560 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 561 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 562 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles::
# 563 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
# 564 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 565 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 566 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 567 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen::
# 568 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 569 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles
# 570 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles
# 571 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis, MSGBOX_DEFAULT
# 572 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 573 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 574 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 575 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles::
# 576 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
# 577 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 578 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 579 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 580 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles::
# 581 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
# 582 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 583 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 584 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 585 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed::
# 586 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS  @ No status provided, so it relies on VAR_0x8006 being 0 already
# 587 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 588 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 589 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 590 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge::
# 591 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 592 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 593 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge::
# 594 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 595 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 596 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge::
# 597 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 598 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 599 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 600 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_EnterElevator::
# 601 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 602 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 603 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GetPartySize
# 604 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CallFrontierUtilFunc
# 605 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 606 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad::
# 607 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_loadlinkopponents
# 608 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 1
# 609 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_ne VAR_RESULT, 6, BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad
# 610 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom
# 611 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 612 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
# 613 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 614 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 615 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 616 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 617 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom::
# 618 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_BufferModeText
# 619 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom
# 620 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
# 621 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator
# 622 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 623 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom::
# 624 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	messageautoscroll BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom
# 625 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 626 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 48
# 627 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator::
# 628 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 629 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo
# 630 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord
# 631 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
# 632 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
# 633 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmovement 0
# 634 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	opendoor VAR_0x8004, 1
# 635 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitdooranim
# 636 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator
# 637 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator
# 638 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmovement 0
# 639 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closedoor VAR_0x8004, 1
# 640 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitdooranim
# 641 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 642 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 643 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_WalkToElevator:
# 644 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 645 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 646 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 647 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end
# 648 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 649 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator:
# 650 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 651 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	set_invisible
# 652 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end
# 653 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 654 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator:
# 655 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 656 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 657 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	set_invisible
# 658 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end
# 659 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 660 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 661 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_UnusedEnterElevator:
# 662 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 663 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 664 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 665 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 666 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 667 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	set_invisible
# 668 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end
# 669 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 670 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferModeText::
# 671 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle
# 672 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble
# 673 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti
# 674 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_BufferTextLinkMulti
# 675 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 676 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 677 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle::
# 678 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
# 679 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 680 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 681 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble::
# 682 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
# 683 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 684 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 685 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti::
# 686 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
# 687 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 688 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 689 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferTextLinkMulti::
# 690 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
# 691 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 692 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 693 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo::
# 694 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_TalkedToSinglesAttendant
# 695 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_TalkedToDoublesAttendant
# 696 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_TalkedToMultisAttendant
# 697 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_TalkedToLinkMultisAttendant
# 698 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 699 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 700 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TalkedToSinglesAttendant::
# 701 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
# 702 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 703 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 704 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TalkedToDoublesAttendant::
# 705 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
# 706 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 707 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 708 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TalkedToMultisAttendant::
# 709 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_MULTIS
# 710 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 711 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 712 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TalkedToLinkMultisAttendant::
# 713 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_LINK_MULTIS
# 714 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 715 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 716 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord::
# 717 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordSingles
# 718 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordDoubles
# 719 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordMultis
# 720 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordLinkMultis
# 721 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 722 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 723 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordSingles::
# 724 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 6
# 725 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 726 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 727 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordDoubles::
# 728 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 10
# 729 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 730 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 731 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordMultis::
# 732 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 14
# 733 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 734 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 735 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordLinkMultis::
# 736 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 18
# 737 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 738 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 739 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetPartySize::
# 740 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize
# 741 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize
# 742 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize
# 743 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetLinkMultisPartySize
# 744 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 745 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 746 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize::
# 747 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 748 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 749 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 750 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize::
# 751 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
# 752 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 753 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 754 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize::
# 755 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
# 756 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 757 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 758 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetLinkMultisPartySize::
# 759 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
# 760 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 761 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 762 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_EventScript_GetLvlMode::
# 763 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 764 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 765 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 766 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryCableLink::
# 767 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, USING_BATTLE_TOWER
# 768 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message gText_PleaseWaitForLink
# 769 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 770 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, 0
# 771 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TryBattleLinkup
# 772 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 773 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful
# 774 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
# 775 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections
# 776 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers
# 777 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 778 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
# 779 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
# 780 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 781 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 782 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections::
# 783 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 784 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_0x8005, 3, BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection
# 785 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
# 786 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 787 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 788 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 789 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection::
# 790 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
# 791 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
# 792 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 793 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 794 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 795 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers::
# 796 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers, MSGBOX_DEFAULT
# 797 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 798 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
# 799 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 800 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 801 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 802 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AbortLink::
# 803 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 804 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_0x8005, 0, BattleFrontier_BattleTowerLobby_EventScript_FriendChoseDifferentLvlMode
# 805 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_0x8005, 1, BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMon
# 806 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq VAR_0x8005, 2, BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMons
# 807 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
# 808 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 809 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 810 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 811 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FriendChoseDifferentLvlMode::
# 812 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
# 813 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 814 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 815 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMon::
# 816 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon, MSGBOX_DEFAULT
# 817 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 818 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 819 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMons::
# 820 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons, MSGBOX_DEFAULT
# 821 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 822 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 823 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful::
# 824 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 825 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 826 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
# 827 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 828 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 829 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SaveForBattleTowerLink
# 830 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 831 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 832 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 833 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TrySetBattleTowerLinkType
# 834 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 835 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 836 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 837 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExplainLinkMultisChallenge::
# 838 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge, MSGBOX_DEFAULT
# 839 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterLinkMultisChallenge
# 840 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 841 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 842 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink::
# 843 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_BATTLE_TOWER
# 844 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
# 845 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 846 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 847 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader::
# 848 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message CableClub_Text_ChooseGroupLeaderOfTwo
# 849 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 850 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
# 851 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 852 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
# 853 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
# 854 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 855 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 856 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 857 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 858 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader::
# 859 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call CableClub_EventScript_TryBecomeLinkLeader
# 860 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
# 861 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
# 862 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
# 863 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
# 864 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 865 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 866 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 867 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup::
# 868 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call CableClub_EventScript_TryJoinLinkGroup
# 869 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
# 870 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
# 871 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
# 872 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
# 873 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 874 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 875 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 876 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful::
# 877 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 878 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 879 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
# 880 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 881 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 882 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SaveForBattleTowerLink
# 883 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 884 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 885 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 886 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 887 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 888 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 889 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesBoard::
# 890 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 891 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 892 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 893 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 894 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 895 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard::
# 896 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
# 897 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 898 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 2, MULTI_BATTLE_TOWER_RULES, FALSE
# 899 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 900 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_RulesTower
# 901 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_RulesMons
# 902 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_RulesSalon
# 903 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 3, BattleFrontier_BattleTowerLobby_EventScript_RulesMultiLink
# 904 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 4, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
# 905 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
# 906 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 907 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 908 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesTower::
# 909 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules, MSGBOX_DEFAULT
# 910 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 911 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 912 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 913 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesMons::
# 914 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
# 915 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 916 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 917 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 918 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesSalon::
# 919 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules, MSGBOX_DEFAULT
# 920 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 921 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 922 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 923 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesMultiLink::
# 924 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules, MSGBOX_DEFAULT
# 925 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 926 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 927 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 928 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExitRules::
# 929 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 930 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 931 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 932 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 933 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DirectYouToBattleRoom:
# 934 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I'll direct you to your BATTLE ROOM now.$"
# 935 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 936 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting:
# 937 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 938 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You didn't save before you quit your\n"
# 939 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "challenge last time.\p"
# 940 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Because of that, your challenge so far\n"
# 941 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "has been disqualified. Sorry!$"
# 942 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 943 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven:
# 944 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Congratulations!\n"
# 945 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You've beaten all seven TRAINERS!\p"
# 946 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "$"
# 947 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 948 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 949 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_EarnedFabulousPrize:
# 950 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "For beating seven TRAINERS in a row,\n"
# 951 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you have earned this fabulous prize!\p"
# 952 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "$"
# 953 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 954 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ReceivedPrize:
# 955 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 956 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 957 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 958 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 959 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_BagFullMakeRoom:
# 960 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Oh, your BAG appears to be full.\p"
# 961 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please make room in your BAG, then come\n"
# 962 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "see me.$"
# 963 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 964 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying:
# 965 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Thank you for playing!\p"
# 966 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "$"
# 967 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 968 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved:
# 969 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your record will be saved.\n"
# 970 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please wait.$"
# 971 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 972 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou:
# 973 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 974 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "$"
# 975 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 976 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved:
# 977 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Before entering a BATTLE ROOM, your\n"
# 978 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "progress will be saved. Please wait.$"
# 979 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 980 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer:
# 981 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You're finally about to face the\n"
# 982 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "50th TRAINER.\p"
# 983 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "From here on, every time you beat seven\n"
# 984 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "TRAINERS in a row, your POKéMON will\l"
# 985 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "receive a commemorative RIBBON.\p"
# 986 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Good luck!$"
# 987 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 988 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons:
# 989 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Here are some RIBBONS for beating\n"
# 990 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "seven tough TRAINERS in a row.\p"
# 991 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} received some RIBBONS!$"
# 992 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 993 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons:
# 994 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} put the RIBBONS on\n"
# 995 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the challenger POKéMON.$"
# 996 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 997 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower:
# 998 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me, do you have a moment?\p"
# 999 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Can you describe your feelings when\n"
# 1000 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you're about to begin a BATTLE TOWER\l"
# 1001 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "match, or when you've either won or\l"
# 1002 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "lost a match?$"
# 1003 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1004 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin:
# 1005 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Okay, what are your feelings when\n"
# 1006 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you're about to begin a match?$"
# 1007 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1008 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon:
# 1009 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "What do you feel when you've won\n"
# 1010 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "a match?$"
# 1011 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1012 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost:
# 1013 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Can I hear about your feelings when\n"
# 1014 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you have lost a match?$"
# 1015 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1016 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt:
# 1017 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Oh, so you don't think much about it?\n"
# 1018 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You're one cool customer.$"
# 1019 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1020 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ChangedYourMind:
# 1021 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Hunh? You changed your mind?\n"
# 1022 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I guess you're fickle.$"
# 1023 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1024 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel:
# 1025 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Okay, so that's how you feel?\n"
# 1026 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "That's quite original.\p"
# 1027 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Thanks!$"
# 1028 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1029 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded:
# 1030 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The number of matches you win in a row\n"
# 1031 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "is recorded.\p"
# 1032 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I'd better not get beaten in\n"
# 1033 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "an embarrassing way!$"
# 1034 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1035 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins:
# 1036 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Once you've entered the BATTLE TOWER,\n"
# 1037 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you can't leave until you either lose\l"
# 1038 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "or you beat seven TRAINERS in a row.\p"
# 1039 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You'd best be certain that you're up\n"
# 1040 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to the challenge.$"
# 1041 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1042 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1043 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DoubleBattleRoomConstruction:
# 1044 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the BATTLE TOWER\n"
# 1045 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "DOUBLE BATTLE CORNER!\p"
# 1046 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Unfortunately, the BATTLE ROOMS\n"
# 1047 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are still under construction.\p"
# 1048 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come back when the work\n"
# 1049 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "is completed.$"
# 1050 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1051 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1052 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_MultiBattleRoomConstruction:
# 1053 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the BATTLE TOWER\n"
# 1054 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "MULTI BATTLE CORNER!\p"
# 1055 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Unfortunately, the BATTLE ROOMS\n"
# 1056 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are still under construction.\p"
# 1057 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come back when the work\n"
# 1058 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "is completed.$"
# 1059 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1060 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge:
# 1061 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "We look forward to seeing you on\n"
# 1062 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "another challenge!$"
# 1063 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1064 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WhichLevelMode:
# 1065 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE ROOM offers two levels\n"
# 1066 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of challenge, Level 50 and Open Level.\l"
# 1067 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Which is your choice?$"
# 1068 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1069 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1070 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PleaseSelectMons:
# 1071 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please select the POKéMON you wish\n"
# 1072 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.$"
# 1073 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1074 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering:
# 1075 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Before entering a BATTLE ROOM, your\n"
# 1076 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "progress must be saved. Is that okay?$"
# 1077 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1078 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom:
# 1079 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I will now show you to the\n"
# 1080 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{STR_VAR_1} BATTLE ROOM.$"
# 1081 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1082 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_RecordLastMatch:
# 1083 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Shall I record your last BATTLE TOWER\n"
# 1084 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 1085 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1086 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1087 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50:
# 1088 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1089 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have {STR_VAR_2} eligible POKéMON.\p"
# 1090 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have {STR_VAR_2} different POKéMON\n"
# 1091 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 1092 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1093 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1094 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1095 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1096 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1097 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1098 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpen:
# 1099 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1100 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have {STR_VAR_2} eligible POKéMON.\p"
# 1101 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have {STR_VAR_2} different POKéMON\n"
# 1102 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.\p"
# 1103 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1104 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1105 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1106 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1107 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1108 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles:
# 1109 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1110 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have three eligible POKéMON.\p"
# 1111 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have three different POKéMON\n"
# 1112 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 1113 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1114 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1115 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1116 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1117 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1118 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles:
# 1119 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1120 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have three eligible POKéMON.\p"
# 1121 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have three different POKéMON\n"
# 1122 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.\p"
# 1123 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1124 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1125 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1126 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1127 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1128 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles:
# 1129 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1130 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have four eligible POKéMON.\p"
# 1131 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have four different POKéMON\n"
# 1132 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 1133 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1134 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1135 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1136 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1137 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1138 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles:
# 1139 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1140 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have four eligible POKéMON.\p"
# 1141 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have four different POKéMON\n"
# 1142 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.\p"
# 1143 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1144 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1145 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1146 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1147 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1148 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis:
# 1149 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1150 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have two eligible POKéMON.\p"
# 1151 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have two different POKéMON\n"
# 1152 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 1153 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1154 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1155 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1156 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1157 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1158 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis:
# 1159 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1160 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have two eligible POKéMON.\p"
# 1161 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have two different POKéMON\n"
# 1162 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.\p"
# 1163 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1164 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1165 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1166 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1167 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1168 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle:
# 1169 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of TRAINERS\n"
# 1170 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are put to the test!\p"
# 1171 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the BATTLE TOWER!\p"
# 1172 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I am your guide to the SINGLE\n"
# 1173 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOMS.$"
# 1174 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1175 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge:
# 1176 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the SINGLE\n"
# 1177 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOM challenge?$"
# 1178 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1179 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge:
# 1180 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER's SINGLE BATTLE\n"
# 1181 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "ROOMS are facilities for conducting\l"
# 1182 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "SINGLE BATTLES with three POKéMON.\p"
# 1183 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "There are many SINGLE BATTLE ROOMS\n"
# 1184 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "in the BATTLE TOWER for team battles.\p"
# 1185 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In each of the SINGLE BATTLE ROOMS,\n"
# 1186 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "seven TRAINERS await your challenge.\p"
# 1187 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you manage to defeat all seven,\n"
# 1188 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will earn Battle Points.\p"
# 1189 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 1190 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 1191 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 1192 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will be disqualified.$"
# 1193 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1194 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_SelectThreeMons:
# 1195 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the three POKéMON\n"
# 1196 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "that are to be entered.$"
# 1197 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1198 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle:
# 1199 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of TRAINERS\n"
# 1200 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are put to the test!\p"
# 1201 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the BATTLE TOWER!\p"
# 1202 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I am your guide to the DOUBLE\n"
# 1203 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOMS.$"
# 1204 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1205 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge:
# 1206 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the DOUBLE\n"
# 1207 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOM challenge?$"
# 1208 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1209 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge:
# 1210 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER's DOUBLE BATTLE\n"
# 1211 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "ROOMS are facilities for conducting\l"
# 1212 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "DOUBLE BATTLES with four POKéMON.\p"
# 1213 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "There are many DOUBLE BATTLE ROOMS\n"
# 1214 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "in the BATTLE TOWER for team battles.\p"
# 1215 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In each of the DOUBLE BATTLE ROOMS,\n"
# 1216 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "seven TRAINERS await your challenge.\p"
# 1217 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you manage to defeat all seven,\n"
# 1218 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will earn Battle Points.\p"
# 1219 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 1220 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 1221 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 1222 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will be disqualified.$"
# 1223 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1224 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons:
# 1225 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the four POKéMON\n"
# 1226 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "that are to be entered.$"
# 1227 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1228 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle:
# 1229 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of TRAINERS\n"
# 1230 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are put to the test!\p"
# 1231 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the BATTLE TOWER!\p"
# 1232 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I am your guide to the MULTI\n"
# 1233 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOMS.$"
# 1234 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1235 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge:
# 1236 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the MULTI\n"
# 1237 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOM challenge?$"
# 1238 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1239 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge:
# 1240 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER's MULTI BATTLE\n"
# 1241 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "ROOMS are facilities for conducting\l"
# 1242 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "MULTI BATTLES.\p"
# 1243 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "For MULTI BATTLES, you must partner\n"
# 1244 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "with a TRAINER in the TOWER and enter\l"
# 1245 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "with two POKéMON each.\p"
# 1246 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Inside the TOWER is a room named\n"
# 1247 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the BATTLE SALON where you may meet\l"
# 1248 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "other TRAINERS.\p"
# 1249 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "There, you must find a TRAINER to act\n"
# 1250 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "as your partner in MULTI BATTLES.\p"
# 1251 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Once you have partnered up, you will\n"
# 1252 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "be shown to a MULTI BATTLE ROOM.\p"
# 1253 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In the MULTI BATTLE ROOM, seven\n"
# 1254 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "tag teams await your challenge.\p"
# 1255 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you manage to defeat all seven\n"
# 1256 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "teams, you will earn Battle Points.\p"
# 1257 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 1258 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 1259 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 1260 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will be disqualified.$"
# 1261 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1262 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons:
# 1263 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the two POKéMON\n"
# 1264 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "that are to be entered.$"
# 1265 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1266 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle:
# 1267 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of TRAINERS\n"
# 1268 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are put to the test!\p"
# 1269 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the BATTLE TOWER!\p"
# 1270 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I am your guide to the LINK MULTI\n"
# 1271 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOMS.$"
# 1272 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1273 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge:
# 1274 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the LINK MULTI\n"
# 1275 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOM challenge?$"
# 1276 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1277 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge:
# 1278 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER's MULTI BATTLE\n"
# 1279 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "ROOMS are facilities for conducting\l"
# 1280 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "MULTI BATTLES with a friend.\p"
# 1281 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must link with your friend using\n"
# 1282 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Wireless Adapters or a Game Boy\l"
# 1283 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Advance Game Link cable.\p"
# 1284 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must partner with your friend and\n"
# 1285 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "enter two different kinds of POKéMON.\p"
# 1286 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "There are many MULTI BATTLE ROOMS\n"
# 1287 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "in the BATTLE TOWER for team battles.\p"
# 1288 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In a MULTI BATTLE ROOM, seven\n"
# 1289 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "tag teams await you and your friend\l"
# 1290 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to make a tag-team challenge.\p"
# 1291 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you manage to defeat all seven\n"
# 1292 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "teams, you will earn Battle Points.\p"
# 1293 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please beware that unlike other ROOMS,\n"
# 1294 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you may not interrupt your challenge.\p"
# 1295 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Once you start, you must battle seven\n"
# 1296 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "MULTI BATTLES in a row nonstop.$"
# 1297 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1298 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2:
# 1299 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the two POKéMON\n"
# 1300 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "that are to be entered.$"
# 1301 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1302 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1303 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ChoseSameMonAsFriend:
# 1304 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You have chosen the same kind of\n"
# 1305 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "POKéMON as your friend.\p"
# 1306 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please choose two POKéMON different\n"
# 1307 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "from your friend's, match the level\l"
# 1308 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you wish to enter, and register again.$"
# 1309 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1310 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers:
# 1311 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The LINK MULTI BATTLE ROOM challenge\n"
# 1312 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "is only for two linked players.$"
# 1313 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1314 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon:
# 1315 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected\n"
# 1316 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the POKéMON {STR_VAR_1}.$"
# 1317 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1318 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons:
# 1319 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected the\n"
# 1320 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "POKéMON {STR_VAR_1} and {STR_VAR_2}.$"
# 1321 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1322 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode:
# 1323 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has chosen a different\n"
# 1324 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "battle level.$"
# 1325 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1326 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1327 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMon:
# 1328 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has chosen a different\n"
# 1329 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "battle level.\p"
# 1330 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected\n"
# 1331 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the POKéMON {STR_VAR_1}.$"
# 1332 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1333 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1334 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMons:
# 1335 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has chosen a different\n"
# 1336 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "battle level.\p"
# 1337 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected the\n"
# 1338 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "POKéMON {STR_VAR_1} and {STR_VAR_2}.$"
# 1339 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1340 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode:
# 1341 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please choose two POKéMON different\n"
# 1342 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "from your friend's, match the level\l"
# 1343 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you wish to enter, and register again.$"
# 1344 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1345 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn:
# 1346 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I will save the game before\n"
# 1347 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "showing you in. Please wait.$"
# 1348 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1349 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden:
# 1350 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Congratulations!\n"
# 1351 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You have defeated the SALON MAIDEN\l"
# 1352 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "and swept seven TRAINERS!$"
# 1353 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1354 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints:
# 1355 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In recognition of your infinite talent,\n"
# 1356 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 1357 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1358 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_Text_ObtainedXBattlePoints:
# 1359 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} obtained {STR_VAR_1} Battle Point(s).$"
# 1360 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1361 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_RulesAreListed:
# 1362 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER rules are listed.$"
# 1363 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1364 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading:
# 1365 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 1366 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1367 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules:
# 1368 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE TOWER is a facility where\n"
# 1369 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "four types of battles are waged--\l"
# 1370 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "SINGLE BATTLE, DOUBLE BATTLE, MULTI\l"
# 1371 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE, and LINK MULTI BATTLE.\p"
# 1372 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "For each of these types, there are\n"
# 1373 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "separate BATTLE ROOMS.\p"
# 1374 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please speak with a guide offering\n"
# 1375 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the type of battle you wish to enter.$"
# 1376 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1377 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainMonRules:
# 1378 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Depending on the BATTLE ROOM you are\n"
# 1379 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "entering, you will be required to take\l"
# 1380 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "a certain number of POKéMON.\p"
# 1381 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The SINGLE BATTLE mode requires\n"
# 1382 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "three POKéMON.\p"
# 1383 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The DOUBLE BATTLE mode requires four,\n"
# 1384 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "and the MULTI modes both require two.$"
# 1385 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1386 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules:
# 1387 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE SALON is where you must\n"
# 1388 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "find a partner to form a tag team for\l"
# 1389 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the MULTI BATTLE ROOM challenge.\p"
# 1390 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Choose the best partner for you by\n"
# 1391 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "examining other TRAINERS'\l"
# 1392 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "POKéMON and their moves.\p"
# 1393 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You may choose a new tag partner\n"
# 1394 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "after winning seven straight matches.$"
# 1395 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1396 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules:
# 1397 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The LINK MULTI BATTLE Mode is for two\n"
# 1398 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "friends to mount a challenge together.\p"
# 1399 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You and your friend must be linked with\n"
# 1400 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Wireless Adapters or a GBA Game Link\l"
# 1401 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "cable.\p"
# 1402 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must choose two POKéMON at\n"
# 1403 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the registration counter.\p"
# 1404 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "These POKéMON must be different\n"
# 1405 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "from those of your friend.\p"
# 1406 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You may not interrupt this challenge\n"
# 1407 "data//maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "in the middle, unlike other modes.$"
