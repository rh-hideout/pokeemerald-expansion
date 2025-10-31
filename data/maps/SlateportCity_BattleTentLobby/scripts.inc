# 1 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 2 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_MapScripts::
# 3 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentLobby_OnFrame
# 4 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentLobby_OnWarp
# 5 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.byte 0
# 6 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 7 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_OnWarp:
# 8 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth
# 9 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.2byte 0
# 10 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 11 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth::
# 12 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 15 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 16 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_OnFrame:
# 17 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus
# 18 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving
# 19 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, SlateportCity_BattleTentLobby_EventScript_ResumeChallenge
# 20 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, SlateportCity_BattleTentLobby_EventScript_WonChallenge
# 21 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, SlateportCity_BattleTentLobby_EventScript_LostChallenge
# 22 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.2byte 0
# 23 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 24 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus::
# 25 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_getstatus
# 26 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 27 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 28 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving::
# 29 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 30 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 31 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 32 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 33 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 34 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 35 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 36 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 37 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 38 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_WonChallenge::
# 39 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 40 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons
# 41 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 42 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_setrandomprize
# 43 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 44 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save 0
# 45 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 46 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 47 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_GivePrize::
# 48 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_AwardYouThisPrize, MSGBOX_DEFAULT
# 49 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_giveprize
# 50 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 51 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case FALSE, SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize
# 52 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 53 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize  @ Odd that it uses Tower's instead of Factory's or its own
# 54 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 55 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 56 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitfanfare
# 57 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize
# 58 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 59 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize::
# 60 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
# 61 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize
# 62 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 63 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_LostChallenge::
# 64 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 65 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
# 66 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 67 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 68 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save 0
# 69 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 70 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 71 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 72 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_EndGivePrize::
# 73 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 74 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 75 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 76 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 77 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 78 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 79 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ResumeChallenge::
# 80 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 81 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_BeenWaitingForYou
# 82 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 83 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save CHALLENGE_STATUS_SAVING
# 84 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 85 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 86 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 87 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 88 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 89 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EnterChallenge
# 90 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 91 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Attendant::
# 92 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lock
# 93 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	faceplayer
# 94 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_getprize
# 95 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_ne VAR_RESULT, ITEM_NONE, SlateportCity_BattleTentLobby_EventScript_GivePrize
# 96 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	special SavePlayerParty
# 97 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
# 98 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge::
# 99 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_TakeChallenge
# 100 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 101 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 102 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 103 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 0, SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge
# 104 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 1, SlateportCity_BattleTentLobby_EventScript_ExplainChallenge
# 105 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 2, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 106 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 107 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 108 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge::
# 109 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 110 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 111 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
# 112 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
# 113 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 114 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case NO, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 115 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case YES, SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge
# 116 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 117 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 118 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge::
# 119 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 120 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 121 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_init
# 122 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 123 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 124 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 125 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	delay 2
# 126 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 127 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 128 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
# 129 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 130 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_EnterChallenge::
# 131 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 132 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 133 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	call SlateportCity_BattleTentLobby_EventScript_WalkToDoor
# 134 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 2, 7
# 135 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 136 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitstate
# 137 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 138 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 139 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_WalkToDoor::
# 140 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement LOCALID_SLATEPORT_TENT_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor
# 141 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor
# 142 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmovement 0
# 143 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	opendoor 6, 1
# 144 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitdooranim
# 145 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement LOCALID_SLATEPORT_TENT_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor
# 146 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor
# 147 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmovement 0
# 148 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closedoor 6, 1
# 149 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitdooranim
# 150 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	return
# 151 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 152 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor:
# 153 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 154 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 155 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 156 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 157 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 158 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor:
# 159 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 160 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 161 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 162 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 163 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor:
# 164 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 165 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 166 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 167 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 168 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 169 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor:
# 170 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 171 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 172 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 173 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 174 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 175 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ExplainChallenge::
# 176 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSlateportTent, MSGBOX_DEFAULT
# 177 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge
# 178 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 179 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
# 180 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 181 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 182 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 183 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
# 184 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	special LoadPlayerParty
# 185 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_CancelChallenge::
# 186 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 187 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 188 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 189 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 190 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
@ Unused
# 191 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_UnusedEnterDoor::
# 192 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 193 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 194 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 195 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 196 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 197 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 198 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TormentGiver::
# 199 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lock
# 200 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	faceplayer
# 201 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_TORMENT, SlateportCity_BattleTentLobby_EventScript_ReceivedTorment
# 202 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe, MSGBOX_DEFAULT
# 203 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	giveitem ITEM_TM_TORMENT
# 204 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 205 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setflag FLAG_RECEIVED_TM_TORMENT
# 206 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
# 207 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 208 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 209 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 210 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ReceivedTorment::
# 211 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
# 212 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 213 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 214 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 215 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Man::
# 216 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons, MSGBOX_NPC
# 217 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 218 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 219 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Girl::
# 220 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons, MSGBOX_NPC
# 221 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 222 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 223 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Woman::
# 224 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection, MSGBOX_NPC
# 225 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 226 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 227 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesBoard::
# 228 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 229 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 230 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 231 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 232 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 233 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard::
# 234 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 235 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 236 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	multichoice 17, 0, MULTI_SLATEPORT_TENT_RULES, FALSE
# 237 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 238 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 0, SlateportCity_BattleTentLobby_EventScript_RulesBasics
# 239 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 1, SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner
# 240 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 2, SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber
# 241 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 3, SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes
# 242 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 4, SlateportCity_BattleTentLobby_EventScript_RulesMons
# 243 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 5, SlateportCity_BattleTentLobby_EventScript_ExitRules
# 244 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_ExitRules
# 245 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 246 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 247 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesBasics::
# 248 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 249 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 250 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 251 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 252 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner::
# 253 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 254 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 255 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 256 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 257 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber::
# 258 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 259 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 260 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 261 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 262 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes::
# 263 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNotes, MSGBOX_DEFAULT
# 264 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 265 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 266 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 267 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesMons::
# 268 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
# 269 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 270 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 271 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 272 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ExitRules::
# 273 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 274 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 275 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 276 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe:
# 277 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, like, I couldn't find myself any\n"
# 278 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "POKéMON that were, like, for me.\p"
# 279 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, I figured, like, hey, I should file\n"
# 280 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a complaint to the guy there?\p"
# 281 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "And he wouldn't hear me out, like, hey!\n"
# 282 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, like, total bummer, man!\p"
# 283 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, like, you! Zip it, you know?\n"
# 284 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Just, you know, take this!$"
# 285 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 286 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_ExplainTorment:
# 287 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "That's, like, TM41, you know?\n"
# 288 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, it's TORMENT, you hearing me?\p"
# 289 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Like, it won't let the other guy\n"
# 290 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "use the same move twice in a row, see?\p"
# 291 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, now, you listen here, like,\n"
# 292 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "I'm not laying a torment on you!$"
# 293 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 294 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons:
# 295 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "I don't really like BUG POKéMON,\n"
# 296 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "but maybe I'll try using some for\l"
# 297 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a change of pace.\p"
# 298 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Who knows, I might even get to like\n"
# 299 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "them!$"
# 300 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 301 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons:
# 302 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "You can battle all you want here even\n"
# 303 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "if you don't have any tough POKéMON.$"
# 304 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 305 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection:
# 306 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Wouldn't it be nice if they had more of\n"
# 307 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a selection?$"
