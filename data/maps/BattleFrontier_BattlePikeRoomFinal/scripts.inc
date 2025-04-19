# 1 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 4 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_MapScripts::
# 5 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomFinal_OnFrame
# 6 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoomFinal_OnWarp
# 7 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 9 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_OnFrame:
# 10 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomFinal_EventScript_EnterRoom
# 11 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.2byte 0
# 12 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 13 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_EventScript_EnterRoom::
# 14 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	delay 16
# 15 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePikeRoomFinal_Movement_AttendantApproachPlayer
# 16 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	waitmovement 0
# 17 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 18 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	lockall
# 19 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease, MSGBOX_DEFAULT
# 20 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	closemessage
# 21 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	releaseall
# 22 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
# 23 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	waitstate
# 24 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	end
# 25 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 26 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_Movement_AttendantApproachPlayer:
# 27 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	walk_down
# 28 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	walk_down
# 29 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	step_end
# 30 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 31 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_OnWarp:
# 32 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRoomFinal_EventScript_TurnPlayerNorth
# 33 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.2byte 0
# 34 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 35 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_EventScript_TurnPlayerNorth::
# 36 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	setvar VAR_TEMP_4, 1
# 37 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 38 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	end
# 39 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 40 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease:
# 41 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.string "Congratulations…\n"
# 42 "data//maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.string "Now, this way, please…$"
