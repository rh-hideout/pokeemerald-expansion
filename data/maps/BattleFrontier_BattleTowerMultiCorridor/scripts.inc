# 1 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 3 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_TOWER_MULTI_CORRIDOR_PLAYER).
# 4 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_F.
# 5 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
@ The graphics of the partner are represented with VAR_OBJ_GFX_ID_E, which will ultimately be set by tower_setpartnergfx.
# 6 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_MapScripts::
# 8 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiCorridor_OnTransition
# 9 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiCorridor_OnWarp
# 10 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiCorridor_OnFrame
# 11 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.byte 0
# 12 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnTransition:
# 14 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx
# 15 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx
# 16 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 17 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 18 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx::
# 19 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	tower_setpartnergfx
# 20 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	checkplayergender
# 21 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetPlayerGfxFemale
# 22 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 23 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 24 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 25 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetPlayerGfxFemale::
# 26 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
# 27 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 28 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 29 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx::
# 30 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	special SetBattleTowerLinkPlayerGfx
# 31 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 32 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 33 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnWarp:
# 34 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects
# 35 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.2byte 0
# 36 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 37 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects::
# 38 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 39 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 40 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 41 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	special OffsetCameraForBattle
# 42 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 43 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 44 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnFrame:
# 45 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor
# 46 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.2byte 0
# 47 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 48 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor::
# 49 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	lockall
# 50 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 51 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8004, 14  @ x coord of far door, used by DrawDoor
# 52 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8005, 1   @ y coord of far door, used by DrawDoor
# 53 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	opendoor 1, 1
# 54 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 55 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 56 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	showobjectat LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 57 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	showobjectat LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 58 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
# 59 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
# 60 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 61 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 62 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8004, 14  @ x coord of far door, used by DrawDoor
# 63 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8005, 1   @ y coord of far door, used by DrawDoor
# 64 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	closedoor 1, 1
# 65 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 66 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 67 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor
# 68 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor
# 69 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_2, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor
# 70 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_1, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor
# 71 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 72 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay 40
# 73 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_2, Common_Movement_WalkInPlaceFasterUp
# 74 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_1, Common_Movement_WalkInPlaceFasterUp
# 75 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 76 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	opendoor 7, 1
# 77 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 78 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_2, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
# 79 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_1, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
# 80 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
# 81 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
# 82 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 83 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	closedoor 7, 1
# 84 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 85 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay 30
# 86 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 87 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom
# 88 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	releaseall
# 89 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 90 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 91 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom::
# 92 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom
# 93 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom
# 94 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToMultiBattleRoom
# 95 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToLinkMultiBattleRoom
# 96 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 97 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 98 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom::
# 99 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 4, 8
# 100 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 101 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 102 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 103 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToMultiBattleRoom::
# 104 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 4, 5
# 105 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 106 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 107 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 108 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
@ Unnecessary duplicate of the above
# 109 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToLinkMultiBattleRoom::
# 110 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 4, 5
# 111 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 112 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 113 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 114 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor:
# 115 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 116 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 117 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 118 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 119 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 120 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 121 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 122 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 123 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 124 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor:
# 125 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 126 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 127 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 128 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 129 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 130 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 131 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 132 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 133 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 134 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor:
# 135 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 136 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 137 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 138 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 139 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 140 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 141 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 142 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_in_place_faster_right
# 143 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 144 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 145 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor:
# 146 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 147 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 148 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 149 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 150 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 151 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 152 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 153 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_in_place_faster_left
# 154 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 155 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 156 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor:
# 157 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay_16
# 158 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 159 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 160 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	set_invisible
# 161 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 162 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 163 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor:
# 164 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 165 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	set_invisible
# 166 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 167 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 168 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator:
# 169 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 170 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
