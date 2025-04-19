# 1 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 4 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_MapScripts::
# 5 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeCorridor_OnFrame
# 6 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	.byte 0
# 7 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 8 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_OnFrame:
# 9 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor
# 10 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	.2byte 0
# 11 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 12 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor::
# 13 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	delay 16
# 14 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 16 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen
# 17 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50
# 18 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50
# 19 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 20 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	opendoor 13, 3
# 21 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 22 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50
# 23 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50
# 24 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 25 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	closedoor 13, 3
# 26 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 27 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	goto BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom
# 28 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 29 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen::
# 30 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen
# 31 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen
# 32 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 33 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	opendoor 37, 3
# 34 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 35 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen
# 36 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen
# 37 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 38 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	closedoor 37, 3
# 39 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 40 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom::
# 41 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 42 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	setvar VAR_0x8006, 0
# 43 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 7
# 44 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitstate
# 45 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	end
# 46 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 47 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50:
# 48 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 49 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 50 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 51 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 52 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 53 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 54 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 55 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 56 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 57 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 58 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 59 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_in_place_faster_up
# 60 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 61 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 62 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50:
# 63 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 64 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 65 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 66 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 67 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 68 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50:
# 69 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 70 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 71 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 72 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 73 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 74 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 75 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 76 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 77 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 78 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 79 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 80 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 81 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 82 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50:
# 83 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 84 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 85 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 86 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 87 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen:
# 88 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 89 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 90 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 91 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 92 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 93 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 94 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 95 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 96 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 97 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 98 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 99 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 100 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 101 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 102 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 103 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_in_place_faster_up
# 104 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 105 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 106 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen:
# 107 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 108 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 109 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 110 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 111 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 112 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen:
# 113 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 114 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 115 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 116 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 117 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 118 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 119 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 120 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 121 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 122 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 123 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 124 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 125 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 126 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 127 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 128 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 129 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 130 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen:
# 131 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 132 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 133 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 134 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 135 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
@ Unused
# 136 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_WalkToBattleRoomMidRight:
# 137 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 138 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 139 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 140 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 141 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 142 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 143 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 144 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 145 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 146 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 147 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 148 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 149 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 150 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 151 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 152 "data//maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
