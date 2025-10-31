# 1 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_MapScripts::
# 3 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
# 4 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.byte 0
# 6 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnTransition:
# 8 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
# 9 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
# 10 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 13 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 14 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos::
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 17 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 18 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 19 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVALS_HOUSE_2F_RIVAL, 8, 2
# 25 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVALS_HOUSE_2F_RIVAL, MOVEMENT_TYPE_FACE_UP
# 26 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 27 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 28 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Ret::
# 29 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 30 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 31 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
# 32 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 33 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
# 34 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 35 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 36 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
# 37 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnWarp:
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.2byte 0
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 46 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, SecretBase_EventScript_InitDecorations
# 47 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 48 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 49 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
# 50 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 51 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 53 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 54 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 55 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 56 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMay::
# 57 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 58 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	addobject LOCALID_RIVALS_HOUSE_2F_RIVAL
# 59 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
# 60 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 61 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PIN
# 62 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_ExclamationMark
# 63 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 64 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_Delay48
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 66 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 67 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
# 69 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
# 70 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
# 72 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 73 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 74 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 75 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 76 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 77 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	fadedefaultbgm
# 78 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 79 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 80 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 81 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
# 82 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
# 83 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 84 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 85 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 86 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 87 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 88 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
# 89 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
# 90 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 92 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
# 95 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 96 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 97 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 98 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 99 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 100 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
# 101 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
# 102 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 103 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 105 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
# 106 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
# 107 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 109 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 110 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 111 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 112 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
# 113 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 114 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 115 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 116 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
# 117 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
# 118 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 120 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 121 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 123 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
# 124 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 126 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 127 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 128 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayEnters:
# 129 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 130 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 131 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 132 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 133 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 134 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
# 135 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 136 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 137 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 138 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 139 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 140 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 142 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
# 143 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 145 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 146 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 147 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 148 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 149 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 150 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 151 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 152 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 153 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 154 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
# 155 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 156 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 157 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 158 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 159 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 160 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 161 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 162 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 163 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 164 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
# 165 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 166 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 167 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 168 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 170 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
# 171 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 172 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 173 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 174 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 175 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 176 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 177 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 178 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 179 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 180 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
# 181 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 182 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 183 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 184 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 185 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 186 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 187 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 188 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
# 189 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 190 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 191 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 192 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 193 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 194 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 195 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 196 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 197 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
# 198 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 199 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 200 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 201 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 202 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 204 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 205 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 207 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 208 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 209 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 210 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 211 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
# 212 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 213 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 214 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 215 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 216 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 217 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 218 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
# 219 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 220 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 221 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 222 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 223 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 224 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 225 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 226 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 227 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 228 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 229 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
# 230 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 231 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 232 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 233 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 234 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 235 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 236 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 237 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Rival::
# 238 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 239 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
# 240 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 241 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_May
# 242 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_Brendan
# 243 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 244 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 245 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_May::
# 246 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
# 247 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 248 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 249 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 250 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Brendan::
# 251 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
# 252 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 253 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 254 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 255 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_RivalPostLilycove::
# 256 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 257 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 258 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 259 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_MayPostLilycove
# 260 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_BrendanPostLilycove
# 261 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
# 262 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 263 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 264 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 265 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayPostLilycove::
# 266 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
# 267 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
# 268 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 269 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 270 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanPostLilycove::
# 271 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
# 272 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
# 273 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 274 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 275 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
# 276 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 277 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 278 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 279 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
# 280 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 281 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 282 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 283 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_PC::
# 284 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 285 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 286 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
# 287 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
# 288 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 289 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 290 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
# 291 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 292 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 293 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 294 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 295 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
# 296 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 297 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 298 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 299 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 300 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 301 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 302 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 303 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 304 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 305 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
# 306 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 307 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 308 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 309 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 310 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 311 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 312 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhoAreYou:
# 313 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh?\n"
# 314 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who… Who are you?\p"
# 315 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\n"
# 316 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\p"
# 317 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}{KUN}.\n"
# 318 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So your move was today.\p"
# 319 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Um… I'm MAY.\n"
# 320 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Glad to meet you!\p"
# 321 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I…\n"
# 322 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I have this dream of becoming friends\l"
# 323 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "with POKéMON all over the world.\p"
# 324 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
# 325 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "my dad, PROF. BIRCH.\p"
# 326 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was hoping that you would be nice,\n"
# 327 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
# 328 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, this is silly, isn't it?\n"
# 329 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
# 330 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Eheheh…\p"
# 331 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, no! I forgot!\p"
# 332 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was supposed to go help Dad catch\n"
# 333 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild POKéMON!\p"
# 334 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I'll catch you later!$"
# 335 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 336 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayGettingReady:
# 337 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "POKéMON fully restored!\n"
# 338 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items ready, and…$"
# 339 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 340 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhoAreYou:
# 341 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey!\n"
# 342 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "You…\p"
# 343 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who are you?\p"
# 344 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}, aren't you?\n"
# 345 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Moved in next door, right?\p"
# 346 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I didn't know that you're a girl.\p"
# 347 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Dad, PROF. BIRCH, said that our new\n"
# 348 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "next-door neighbor is a GYM LEADER's\l"
# 349 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "kid, so I assumed you'd be a guy.\p"
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "My name's BRENDAN.\n"
# 351 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So, hi, neighbor!\p"
# 352 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "a POKéMON?\p"
# 354 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Do you want me to go catch you one?\p"
# 355 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Aw, darn, I forgot…\p"
# 356 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I'm supposed to go help my dad catch\n"
# 357 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild POKéMON.\p"
# 358 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Some other time, okay?$"
# 359 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 360 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanGettingReady:
# 361 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "POKéMON fully restored…\n"
# 362 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items all packed, and…$"
# 363 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 364 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_ItsRivalsPokeBall:
# 365 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's {RIVAL}'s POKé BALL!\p"
# 366 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Better leave it right where it is.$"
# 367 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 368 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
# 369 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 370 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking my POKéDEX.\p"
# 371 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There's still a lot of POKéMON that\n"
# 372 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I've seen but haven't caught.\p"
# 373 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "And there are many others that\n"
# 374 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I think will evolve.\p"
# 375 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I wonder where I should go catch\n"
# 376 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some POKéMON next?$"
# 377 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 378 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhereShouldIGoNext:
# 379 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: I wonder where I should go catch\n"
# 380 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some POKéMON next?\p"
# 381 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Wouldn't it be funny if we ran into each\n"
# 382 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "other, {PLAYER}{KUN}?$"
# 383 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 384 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
# 385 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: Hey, it's {PLAYER}.\p"
# 386 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking out my POKéDEX.\p"
# 387 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There are still many POKéMON that\n"
# 388 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I need to catch, I know, but this\l"
# 389 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "is looking pretty good.\p"
# 390 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Checking this POKéDEX out gives me\n"
# 391 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "the urge to hit the road again.$"
# 392 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 393 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
# 394 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: I'm having a hard time deciding\n"
# 395 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "where I should catch POKéMON next.\p"
# 396 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey, {PLAYER}, if I see you while I'm out\n"
# 397 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "catching POKéMON, I can pitch you a\l"
# 398 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "battle if you'd like.$"
