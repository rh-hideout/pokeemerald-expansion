# 1 "data//maps/Players_Bedroom/scripts.pory"

# 2 "data//maps/Players_Bedroom/scripts.pory"
.set LOCALID_RIVAL, 1
# 3 "data//maps/Players_Bedroom/scripts.pory"

# 4 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_MapScripts::
# 5 "data//maps/Players_Bedroom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
# 6 "data//maps/Players_Bedroom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
# 7 "data//maps/Players_Bedroom/scripts.pory"
	.byte 0
# 8 "data//maps/Players_Bedroom/scripts.pory"

# 9 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnTransition:
# 10 "data//maps/Players_Bedroom/scripts.pory"
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
# 11 "data//maps/Players_Bedroom/scripts.pory"
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
# 12 "data//maps/Players_Bedroom/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 13 "data//maps/Players_Bedroom/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 14 "data//maps/Players_Bedroom/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 15 "data//maps/Players_Bedroom/scripts.pory"
	end
# 16 "data//maps/Players_Bedroom/scripts.pory"

# 17 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
# 18 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 19 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 20 "data//maps/Players_Bedroom/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 21 "data//maps/Players_Bedroom/scripts.pory"

# 22 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
# 23 "data//maps/Players_Bedroom/scripts.pory"
	checkplayergender
# 24 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 25 "data//maps/Players_Bedroom/scripts.pory"
	@ Odd that the MaysHouse equivalent was used below instead
# 26 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 27 "data//maps/Players_Bedroom/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 0, 2
# 28 "data//maps/Players_Bedroom/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
# 29 "data//maps/Players_Bedroom/scripts.pory"
	return
# 30 "data//maps/Players_Bedroom/scripts.pory"

# 31 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Ret::
# 32 "data//maps/Players_Bedroom/scripts.pory"
	return
# 33 "data//maps/Players_Bedroom/scripts.pory"

# 34 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
# 35 "data//maps/Players_Bedroom/scripts.pory"
	checkplayergender
# 36 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
# 37 "data//maps/Players_Bedroom/scripts.pory"
	return
# 38 "data//maps/Players_Bedroom/scripts.pory"

# 39 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
# 40 "data//maps/Players_Bedroom/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 41 "data//maps/Players_Bedroom/scripts.pory"
	return
# 42 "data//maps/Players_Bedroom/scripts.pory"

# 43 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnWarp:
# 44 "data//maps/Players_Bedroom/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
# 45 "data//maps/Players_Bedroom/scripts.pory"
	.2byte 0
# 46 "data//maps/Players_Bedroom/scripts.pory"

# 47 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
# 48 "data//maps/Players_Bedroom/scripts.pory"
	checkplayergender
# 49 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
# 50 "data//maps/Players_Bedroom/scripts.pory"
	end
# 51 "data//maps/Players_Bedroom/scripts.pory"

# 52 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
# 53 "data//maps/Players_Bedroom/scripts.pory"
	lockall
# 54 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
# 55 "data//maps/Players_Bedroom/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 56 "data//maps/Players_Bedroom/scripts.pory"
	releaseall
# 57 "data//maps/Players_Bedroom/scripts.pory"
	end
# 58 "data//maps/Players_Bedroom/scripts.pory"

# 59 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
# 60 "data//maps/Players_Bedroom/scripts.pory"
	delay 10
# 61 "data//maps/Players_Bedroom/scripts.pory"
	addobject LOCALID_RIVAL
# 62 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
# 63 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 64 "data//maps/Players_Bedroom/scripts.pory"
	playse SE_PIN
# 65 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 66 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 67 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 68 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 69 "data//maps/Players_Bedroom/scripts.pory"
	delay 10
# 70 "data//maps/Players_Bedroom/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 71 "data//maps/Players_Bedroom/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
# 72 "data//maps/Players_Bedroom/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
# 73 "data//maps/Players_Bedroom/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
# 74 "data//maps/Players_Bedroom/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
# 75 "data//maps/Players_Bedroom/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 76 "data//maps/Players_Bedroom/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 77 "data//maps/Players_Bedroom/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 78 "data//maps/Players_Bedroom/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 79 "data//maps/Players_Bedroom/scripts.pory"
	savebgm MUS_DUMMY
# 80 "data//maps/Players_Bedroom/scripts.pory"
	fadedefaultbgm
# 81 "data//maps/Players_Bedroom/scripts.pory"
	releaseall
# 82 "data//maps/Players_Bedroom/scripts.pory"
	end
# 83 "data//maps/Players_Bedroom/scripts.pory"

# 84 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
# 85 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
# 86 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 87 "data//maps/Players_Bedroom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 88 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 89 "data//maps/Players_Bedroom/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 90 "data//maps/Players_Bedroom/scripts.pory"
	closemessage
# 91 "data//maps/Players_Bedroom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
# 92 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
# 93 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 94 "data//maps/Players_Bedroom/scripts.pory"
	return
# 95 "data//maps/Players_Bedroom/scripts.pory"

# 96 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
# 97 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
# 98 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 99 "data//maps/Players_Bedroom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 100 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 101 "data//maps/Players_Bedroom/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 102 "data//maps/Players_Bedroom/scripts.pory"
	closemessage
# 103 "data//maps/Players_Bedroom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
# 104 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
# 105 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 106 "data//maps/Players_Bedroom/scripts.pory"
	return
# 107 "data//maps/Players_Bedroom/scripts.pory"

# 108 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
# 109 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
# 110 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 111 "data//maps/Players_Bedroom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 112 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 113 "data//maps/Players_Bedroom/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 114 "data//maps/Players_Bedroom/scripts.pory"
	closemessage
# 115 "data//maps/Players_Bedroom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
# 116 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
# 117 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 118 "data//maps/Players_Bedroom/scripts.pory"
	return
# 119 "data//maps/Players_Bedroom/scripts.pory"

# 120 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
# 121 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
# 122 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 123 "data//maps/Players_Bedroom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 124 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 125 "data//maps/Players_Bedroom/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 126 "data//maps/Players_Bedroom/scripts.pory"
	closemessage
# 127 "data//maps/Players_Bedroom/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
# 128 "data//maps/Players_Bedroom/scripts.pory"
	waitmovement 0
# 129 "data//maps/Players_Bedroom/scripts.pory"
	return
# 130 "data//maps/Players_Bedroom/scripts.pory"

# 131 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
# 132 "data//maps/Players_Bedroom/scripts.pory"
	walk_down
# 133 "data//maps/Players_Bedroom/scripts.pory"
	walk_down
# 134 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_left
# 135 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 136 "data//maps/Players_Bedroom/scripts.pory"

# 137 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
# 138 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 139 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 140 "data//maps/Players_Bedroom/scripts.pory"
	walk_down
# 141 "data//maps/Players_Bedroom/scripts.pory"
	walk_down
# 142 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 143 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 144 "data//maps/Players_Bedroom/scripts.pory"

# 145 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
# 146 "data//maps/Players_Bedroom/scripts.pory"
	walk_up
# 147 "data//maps/Players_Bedroom/scripts.pory"
	walk_up
# 148 "data//maps/Players_Bedroom/scripts.pory"
	walk_up
# 149 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 150 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 151 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 152 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 153 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_up
# 154 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 155 "data//maps/Players_Bedroom/scripts.pory"

# 156 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
# 157 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 158 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_up
# 159 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 160 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 161 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 162 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 163 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_left
# 164 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 165 "data//maps/Players_Bedroom/scripts.pory"

# 166 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
# 167 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 168 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 169 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 170 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 171 "data//maps/Players_Bedroom/scripts.pory"

# 172 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
# 173 "data//maps/Players_Bedroom/scripts.pory"
	walk_up
# 174 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 175 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 176 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 177 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 178 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_up
# 179 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 180 "data//maps/Players_Bedroom/scripts.pory"

# 181 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
# 182 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 183 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_up
# 184 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 185 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 186 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_left
# 187 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 188 "data//maps/Players_Bedroom/scripts.pory"

# 189 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
# 190 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 191 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 192 "data//maps/Players_Bedroom/scripts.pory"
	walk_down
# 193 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_left
# 194 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 195 "data//maps/Players_Bedroom/scripts.pory"

# 196 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
# 197 "data//maps/Players_Bedroom/scripts.pory"
	walk_up
# 198 "data//maps/Players_Bedroom/scripts.pory"
	walk_up
# 199 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 200 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 201 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 202 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 203 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 204 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_up
# 205 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 206 "data//maps/Players_Bedroom/scripts.pory"

# 207 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
# 208 "data//maps/Players_Bedroom/scripts.pory"
	delay_8
# 209 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 210 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_up
# 211 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 212 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 213 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_left
# 214 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 215 "data//maps/Players_Bedroom/scripts.pory"

# 216 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
# 217 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 218 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 219 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 220 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 221 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 222 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_down
# 223 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 224 "data//maps/Players_Bedroom/scripts.pory"

# 225 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
# 226 "data//maps/Players_Bedroom/scripts.pory"
	walk_up
# 227 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 228 "data//maps/Players_Bedroom/scripts.pory"
	walk_left
# 229 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_up
# 230 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 231 "data//maps/Players_Bedroom/scripts.pory"

# 232 "data//maps/Players_Bedroom/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 233 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
# 234 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 235 "data//maps/Players_Bedroom/scripts.pory"
	delay_16
# 236 "data//maps/Players_Bedroom/scripts.pory"
	walk_in_place_faster_left
# 237 "data//maps/Players_Bedroom/scripts.pory"
	step_end
# 238 "data//maps/Players_Bedroom/scripts.pory"

# 239 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_PC::
# 240 "data//maps/Players_Bedroom/scripts.pory"
	lockall
# 241 "data//maps/Players_Bedroom/scripts.pory"
	checkplayergender
# 242 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
# 243 "data//maps/Players_Bedroom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
# 244 "data//maps/Players_Bedroom/scripts.pory"
	end
# 245 "data//maps/Players_Bedroom/scripts.pory"

# 246 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
# 247 "data//maps/Players_Bedroom/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 248 "data//maps/Players_Bedroom/scripts.pory"
	special DoPCTurnOnEffect
# 249 "data//maps/Players_Bedroom/scripts.pory"
	playse SE_PC_ON
# 250 "data//maps/Players_Bedroom/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 251 "data//maps/Players_Bedroom/scripts.pory"
	special BedroomPC
# 252 "data//maps/Players_Bedroom/scripts.pory"
	waitstate
# 253 "data//maps/Players_Bedroom/scripts.pory"
	releaseall
# 254 "data//maps/Players_Bedroom/scripts.pory"
	end
# 255 "data//maps/Players_Bedroom/scripts.pory"

# 256 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
# 257 "data//maps/Players_Bedroom/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 258 "data//maps/Players_Bedroom/scripts.pory"
	playse SE_PC_OFF
# 259 "data//maps/Players_Bedroom/scripts.pory"
	special DoPCTurnOffEffect
# 260 "data//maps/Players_Bedroom/scripts.pory"
	releaseall
# 261 "data//maps/Players_Bedroom/scripts.pory"
	end
# 262 "data//maps/Players_Bedroom/scripts.pory"

# 263 "data//maps/Players_Bedroom/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
# 264 "data//maps/Players_Bedroom/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 265 "data//maps/Players_Bedroom/scripts.pory"
	releaseall
# 266 "data//maps/Players_Bedroom/scripts.pory"
	end
# 267 "data//maps/Players_Bedroom/scripts.pory"

# 268 "data//maps/Players_Bedroom/scripts.pory"
PlayersHouse_2F_EventScript_Notebook::
# 269 "data//maps/Players_Bedroom/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 270 "data//maps/Players_Bedroom/scripts.pory"
	end
# 271 "data//maps/Players_Bedroom/scripts.pory"

# 272 "data//maps/Players_Bedroom/scripts.pory"
PlayersHouse_2F_EventScript_GameCube::
# 273 "data//maps/Players_Bedroom/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 274 "data//maps/Players_Bedroom/scripts.pory"
	end
# 275 "data//maps/Players_Bedroom/scripts.pory"

# 276 "data//maps/Players_Bedroom/scripts.pory"
PlayersHouse_2F_Text_ClockIsStopped:
# 277 "data//maps/Players_Bedroom/scripts.pory"
	.string "The clock is stopped…\p"
# 278 "data//maps/Players_Bedroom/scripts.pory"
	.string "Better set it and start it!$"
# 279 "data//maps/Players_Bedroom/scripts.pory"

# 280 "data//maps/Players_Bedroom/scripts.pory"
PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
# 281 "data//maps/Players_Bedroom/scripts.pory"
	.string "MOM: {PLAYER}, how do you like your\n"
# 282 "data//maps/Players_Bedroom/scripts.pory"
	.string "new room?\p"
# 283 "data//maps/Players_Bedroom/scripts.pory"
	.string "Good! Everything's put away neatly!\p"
# 284 "data//maps/Players_Bedroom/scripts.pory"
	.string "They finished moving everything in\n"
# 285 "data//maps/Players_Bedroom/scripts.pory"
	.string "downstairs, too.\p"
# 286 "data//maps/Players_Bedroom/scripts.pory"
	.string "POKéMON movers are so convenient!\p"
# 287 "data//maps/Players_Bedroom/scripts.pory"
	.string "Oh, you should make sure that\n"
# 288 "data//maps/Players_Bedroom/scripts.pory"
	.string "everything's all there on your desk.$"
# 289 "data//maps/Players_Bedroom/scripts.pory"

# 290 "data//maps/Players_Bedroom/scripts.pory"
PlayersHouse_2F_Text_Notebook:
# 291 "data//maps/Players_Bedroom/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 292 "data//maps/Players_Bedroom/scripts.pory"
	.string "ADVENTURE RULE NO. 1\n"
# 293 "data//maps/Players_Bedroom/scripts.pory"
	.string "Open the MENU with START.\p"
# 294 "data//maps/Players_Bedroom/scripts.pory"
	.string "ADVENTURE RULE NO. 2\n"
# 295 "data//maps/Players_Bedroom/scripts.pory"
	.string "Record your progress with SAVE.\p"
# 296 "data//maps/Players_Bedroom/scripts.pory"
	.string "The remaining pages are blank…$"
# 297 "data//maps/Players_Bedroom/scripts.pory"

# 298 "data//maps/Players_Bedroom/scripts.pory"
Common_Text_LookCloserAtMap:
# 299 "data//maps/Players_Bedroom/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 300 "data//maps/Players_Bedroom/scripts.pory"
	.string "HOENN region map.$"
# 301 "data//maps/Players_Bedroom/scripts.pory"

# 302 "data//maps/Players_Bedroom/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube:
# 303 "data//maps/Players_Bedroom/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 304 "data//maps/Players_Bedroom/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 305 "data//maps/Players_Bedroom/scripts.pory"
	.string "serve as the Controller.$"
