# 1 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomFinal_OnFrame
# 4 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoomFinal_OnWarp
# 5 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 7 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_OnFrame:
# 8 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomFinal_EventScript_EnterRoom
# 9 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 11 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_EventScript_EnterRoom::
# 12 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	delay 16
# 13 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	applymovement LOCALID_PIKE_FINAL_ROOM_ATTENDANT, BattleFrontier_BattlePikeRoomFinal_Movement_AttendantApproachPlayer
# 14 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	waitmovement 0
# 15 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 16 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	lockall
# 17 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease, MSGBOX_DEFAULT
# 18 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	closemessage
# 19 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	releaseall
# 20 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
# 21 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	waitstate
# 22 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	end
# 23 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 24 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_Movement_AttendantApproachPlayer:
# 25 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	walk_down
# 26 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	walk_down
# 27 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	step_end
# 28 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 29 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_OnWarp:
# 30 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRoomFinal_EventScript_TurnPlayerNorth
# 31 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.2byte 0
# 32 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 33 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_EventScript_TurnPlayerNorth::
# 34 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	setvar VAR_TEMP_4, 1
# 35 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 36 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	end
# 37 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"

# 38 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease:
# 39 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.string "Congratulations…\n"
# 40 "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.pory"
	.string "Now, this way, please…$"
