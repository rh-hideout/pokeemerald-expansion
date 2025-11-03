# 1 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_MapScripts::
# 3 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeCorridor_OnFrame
# 4 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	.byte 0
# 5 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 6 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_OnFrame:
# 7 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor
# 8 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	.2byte 0
# 9 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 10 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor::
# 11 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	delay 16
# 12 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 13 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 14 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen
# 15 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50
# 16 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50
# 17 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 18 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	opendoor 13, 3
# 19 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 20 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50
# 21 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50
# 22 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 23 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	closedoor 13, 3
# 24 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 25 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	goto BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom
# 26 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 27 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen::
# 28 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen
# 29 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen
# 30 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 31 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	opendoor 37, 3
# 32 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 33 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_DOME_CORRIDOR_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen
# 34 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen
# 35 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 36 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	closedoor 37, 3
# 37 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 38 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom::
# 39 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 40 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	setvar VAR_0x8006, 0
# 41 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 7
# 42 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitstate
# 43 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50:
# 46 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 47 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 48 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 49 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 50 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 51 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 52 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 53 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 54 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 55 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 56 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 57 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_in_place_faster_up
# 58 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 59 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 60 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50:
# 61 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 62 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 63 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 64 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 65 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 66 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50:
# 67 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 68 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 69 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 70 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 71 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 72 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 73 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 74 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 75 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 76 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 77 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 78 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 79 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 80 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50:
# 81 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 82 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 83 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 84 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 85 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen:
# 86 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 87 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 88 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 89 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 90 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 91 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 92 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 93 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 94 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 95 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 96 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 97 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 98 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 99 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 100 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 101 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_in_place_faster_up
# 102 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 103 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 104 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen:
# 105 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 106 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 107 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 108 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 109 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 110 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen:
# 111 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 112 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 113 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 114 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 115 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 116 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 117 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 118 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 119 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 120 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 121 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 122 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 123 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 124 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 125 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 126 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 127 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 128 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen:
# 129 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 130 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 131 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 132 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 133 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
@ Unused
# 134 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_WalkToBattleRoomMidRight:
# 135 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 136 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 137 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 138 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 139 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 140 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 141 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 142 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 143 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 144 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 145 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 146 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 147 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 148 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 149 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 150 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
