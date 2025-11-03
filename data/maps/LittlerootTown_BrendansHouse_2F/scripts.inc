# 1 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_MapScripts::
# 3 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
# 4 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
# 5 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.byte 0
# 6 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 7 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnTransition:
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 11 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 12 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 13 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 17 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 18 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 19 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 20 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
# 21 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 22 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 23 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	@ Odd that the MaysHouse equivalent was used below instead
# 24 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 25 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVALS_HOUSE_2F_RIVAL, 0, 2
# 26 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVALS_HOUSE_2F_RIVAL, MOVEMENT_TYPE_FACE_UP
# 27 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 28 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 29 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Ret::
# 30 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 32 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
# 33 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 34 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
# 35 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 36 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 37 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
# 38 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 39 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 41 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnWarp:
# 42 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
# 43 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.2byte 0
# 44 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 45 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
# 46 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 47 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
# 48 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 49 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 50 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
# 51 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 52 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
# 53 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 54 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 55 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 56 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 57 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
# 58 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 59 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	addobject LOCALID_RIVALS_HOUSE_2F_RIVAL
# 60 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
# 61 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 62 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PIN
# 63 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_ExclamationMark
# 64 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 65 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_Delay48
# 66 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 67 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 68 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 69 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
# 70 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
# 71 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
# 72 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
# 73 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 74 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 75 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 76 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 77 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 78 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	fadedefaultbgm
# 79 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 80 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 81 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 82 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
# 83 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
# 84 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 85 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 86 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 87 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 88 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 89 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
# 90 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
# 91 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 92 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 93 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 94 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
# 95 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
# 96 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 97 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 98 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 99 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 100 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 101 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
# 102 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
# 103 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 104 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 105 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 106 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
# 107 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
# 108 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 109 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 110 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 111 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 112 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 113 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
# 114 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
# 115 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 116 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 117 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 118 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
# 119 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
# 120 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 121 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 122 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 123 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 124 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 125 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
# 126 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 127 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 128 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 129 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
# 130 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 131 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 132 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 133 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 134 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 135 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
# 136 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 137 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 138 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 139 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 140 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 141 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 142 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 143 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
# 144 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 145 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 146 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 147 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 148 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 149 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 150 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 151 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 152 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 153 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 154 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
# 155 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 156 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 157 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 158 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 159 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 160 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 161 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 162 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 163 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 164 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
# 165 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 166 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 167 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 168 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 169 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 170 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
# 171 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 172 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 173 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 174 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 175 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 176 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 177 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 178 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 179 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
# 180 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 181 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 182 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 183 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 184 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 185 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 186 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 187 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
# 188 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 189 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 190 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 191 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 192 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 193 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 194 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
# 195 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 196 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 197 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 198 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 199 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 200 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 201 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 202 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 203 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 204 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 205 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
# 206 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_8
# 207 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 208 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 209 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 210 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 211 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 212 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 213 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 214 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
# 215 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 216 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 217 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 218 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 219 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 220 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 221 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 222 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 223 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
# 224 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 225 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 226 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 227 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 228 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 229 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 230 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 231 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
# 232 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 233 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 234 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 235 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 236 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 237 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_PC::
# 238 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 239 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 240 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
# 241 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
# 242 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 243 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 244 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
# 245 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 246 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 247 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_ON
# 248 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 249 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special BedroomPC
# 250 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitstate
# 251 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 252 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 253 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 254 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
# 255 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 256 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 257 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 258 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 259 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 260 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 261 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
# 262 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 263 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 264 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 265 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 266 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_Notebook::
# 267 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 268 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 269 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 270 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_GameCube::
# 271 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 272 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 273 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 274 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ClockIsStopped:
# 275 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
# 276 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Better set it and start it!$"
# 277 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 278 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
# 279 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "MOM: {PLAYER}, how do you like your\n"
# 280 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "new room?\p"
# 281 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Good! Everything's put away neatly!\p"
# 282 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "They finished moving everything in\n"
# 283 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "downstairs, too.\p"
# 284 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "POKéMON movers are so convenient!\p"
# 285 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Oh, you should make sure that\n"
# 286 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "everything's all there on your desk.$"
# 287 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 288 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_Notebook:
# 289 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 290 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 1\n"
# 291 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Open the MENU with START.\p"
# 292 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 2\n"
# 293 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Record your progress with SAVE.\p"
# 294 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The remaining pages are blank…$"
# 295 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 296 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
Common_Text_LookCloserAtMap:
# 297 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 298 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "HOENN region map.$"
# 299 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 300 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube:
# 301 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 302 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 303 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "serve as the Controller.$"
