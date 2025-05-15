# 1 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 2 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
.set LOCALID_RIVAL, 1
# 3 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 4 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_MapScripts::
# 5 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
# 6 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
# 7 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.byte 0
# 8 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 9 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnTransition:
# 10 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
# 11 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
# 12 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 13 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 14 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 15 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 16 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 17 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos::
# 18 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 19 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 20 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 21 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 22 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
# 23 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 24 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 25 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 26 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 8, 2
# 27 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
# 28 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 29 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 30 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Ret::
# 31 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 32 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 33 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
# 34 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 35 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
# 36 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 37 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 38 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
# 39 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 40 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 41 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 42 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnWarp:
# 43 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
# 44 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.2byte 0
# 45 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 46 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
# 47 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 48 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, SecretBase_EventScript_InitDecorations
# 49 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 50 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 51 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
# 52 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 53 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
# 54 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 55 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 56 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 57 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 58 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMay::
# 59 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 60 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	addobject LOCALID_RIVAL
# 61 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
# 62 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 63 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PIN
# 64 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 65 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 66 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 67 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 68 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 69 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 70 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
# 71 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
# 72 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
# 73 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
# 74 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 75 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar TSUIHOUSE_STATE, 1
# 76 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 77 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 78 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 79 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 80 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	fadedefaultbgm
# 81 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 82 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 83 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 84 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
# 85 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
# 86 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 87 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 88 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 89 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 90 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 91 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
# 92 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
# 93 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 94 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 95 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 96 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
# 97 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
# 98 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 99 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 100 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 101 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 102 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 103 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
# 104 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
# 105 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 106 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 107 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 108 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
# 109 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
# 110 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 111 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 112 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 113 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 114 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 115 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
# 116 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 117 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 118 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 119 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
# 120 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
# 121 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 122 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 123 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 124 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 125 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 126 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
# 127 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
# 128 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 129 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 130 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 131 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayEnters:
# 132 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 133 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 134 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 135 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 136 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 137 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
# 138 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 139 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 140 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 141 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 142 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 143 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 144 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 145 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
# 146 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 147 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 148 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 149 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 150 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 151 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 152 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 153 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 154 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 155 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 156 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 157 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
# 158 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 159 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 160 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 161 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 162 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 163 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 164 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 165 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 166 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 167 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
# 168 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 169 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 170 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 171 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 172 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 173 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
# 174 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 175 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 176 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 177 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 178 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 179 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 180 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 181 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 182 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 183 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
# 184 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 185 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 186 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 187 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 188 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 189 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 190 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 191 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
# 192 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 193 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 194 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 195 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 196 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 197 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 198 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 199 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 200 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
# 201 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 202 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 203 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 204 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 205 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 206 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 207 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 208 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
# 209 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 210 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 211 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 212 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 213 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 214 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
# 215 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 216 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 217 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 218 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 219 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 220 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 221 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
# 222 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 223 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 224 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 225 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 226 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 227 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 228 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 229 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 230 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 231 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 232 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
# 233 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 234 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 235 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 236 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 237 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 238 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 239 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 240 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Rival::
# 241 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 242 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
# 243 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 244 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_May
# 245 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_Brendan
# 246 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 247 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 248 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_May::
# 249 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
# 250 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayLookTsui, MSGBOX_DEFAULT
# 251 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 252 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 253 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 254 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Brendan::
# 255 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
# 256 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 257 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 258 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 259 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_RivalPostLilycove::
# 260 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 261 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 262 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 263 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_MayPostLilycove
# 264 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_BrendanPostLilycove
# 265 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
# 266 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 267 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 268 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 269 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayPostLilycove::
# 270 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
# 271 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
# 272 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 273 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 274 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanPostLilycove::
# 275 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
# 276 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
# 277 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 278 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 279 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
# 280 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 281 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 282 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 283 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
# 284 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 285 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 286 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 287 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_PC::
# 288 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 289 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 290 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
# 291 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
# 292 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 293 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 294 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
# 295 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 296 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 297 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 298 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 299 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
# 300 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 301 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 302 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 303 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 304 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 305 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 306 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 307 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 308 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 309 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
# 310 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 311 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 312 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 313 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 314 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 315 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 316 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhoAreYou:
# 317 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh?\n"
# 318 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who… Who are you?\p"
# 319 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\n"
# 320 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\p"
# 321 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}{KUN}.\n"
# 322 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So your move was today.\p"
# 323 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Um… I'm MAY.\n"
# 324 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Glad to meet you!\p"
# 325 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I…\n"
# 326 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I have this dream of becoming friends\l"
# 327 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "with POKéMON all over the world.\p"
# 328 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
# 329 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "my dad, PROF. TSUI.\p"
# 330 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was hoping that you would be nice,\n"
# 331 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
# 332 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, this is silly, isn't it?\n"
# 333 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
# 334 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Eheheh…\p"
# 335 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, no! I forgot!\p"
# 336 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was supposed to go help Dad catch\n"
# 337 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild POKéMON!\p"
# 338 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I'll catch you later!$"
# 339 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 340 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayGettingReady:
# 341 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "POKéMON fully restored!\n"
# 342 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items ready, and…$"
# 343 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 344 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhoAreYou:
# 345 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey!\n"
# 346 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "You…\p"
# 347 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who are you?\p"
# 348 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}, aren't you?\n"
# 349 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Moved in next door, right?\p"
# 350 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I didn't know that you're a girl.\p"
# 351 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Dad, PROF. TSUI, said that our new\n"
# 352 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "next-door neighbor is a GYM LEADER's\l"
# 353 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "kid, so I assumed you'd be a guy.\p"
# 354 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "My name's BRENDAN.\n"
# 355 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So, hi, neighbor!\p"
# 356 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
# 357 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "a POKéMON?\p"
# 358 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Do you want me to go catch you one?\p"
# 359 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Aw, darn, I forgot…\p"
# 360 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I'm supposed to go help my dad catch\n"
# 361 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild POKéMON.\p"
# 362 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Some other time, okay?$"
# 363 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 364 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanGettingReady:
# 365 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "POKéMON fully restored…\n"
# 366 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items all packed, and…$"
# 367 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 368 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_ItsRivalsPokeBall:
# 369 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's {RIVAL}'s POKé BALL!\p"
# 370 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Better leave it right where it is.$"
# 371 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 372 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
# 373 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 374 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking my POKéDEX.\p"
# 375 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There's still a lot of POKéMON that\n"
# 376 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I've seen but haven't caught.\p"
# 377 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "And there are many others that\n"
# 378 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I think will evolve.\p"
# 379 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I wonder where I should go catch\n"
# 380 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some POKéMON next?$"
# 381 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 382 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhereShouldIGoNext:
# 383 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: I wonder where I should go catch\n"
# 384 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some POKéMON next?\p"
# 385 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Wouldn't it be funny if we ran into each\n"
# 386 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "other, {PLAYER}{KUN}?$"
# 387 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 388 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
# 389 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: Hey, it's {PLAYER}.\p"
# 390 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking out my POKéDEX.\p"
# 391 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There are still many POKéMON that\n"
# 392 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I need to catch, I know, but this\l"
# 393 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "is looking pretty good.\p"
# 394 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Checking this POKéDEX out gives me\n"
# 395 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "the urge to hit the road again.$"
# 396 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 397 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
# 398 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: I'm having a hard time deciding\n"
# 399 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "where I should catch POKéMON next.\p"
# 400 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey, {PLAYER}, if I see you while I'm out\n"
# 401 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "catching POKéMON, I can pitch you a\l"
# 402 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "battle if you'd like.$"

RivalsHouse_2F_Text_MayLookTsui::
# 404 "data//maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "If you're looking for PROF. TSUI, you\n"
	.string "should probably check his lab.$"
