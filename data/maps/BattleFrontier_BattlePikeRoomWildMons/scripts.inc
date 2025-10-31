# 1 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
BattleFrontier_BattlePikeRoomWildMons_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoomWildMons_OnResume
# 4 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomWildMons_OnFrame
# 5 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoomWildMons_OnWarp
# 6 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	.byte 0
# 7 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"

# 8 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
BattleFrontier_BattlePikeRoomWildMons_OnFrame:
# 9 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomWildMons_EventScript_SetInWildMonRoom
# 10 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	map_script_2 VAR_TEMP_1, 1, BattleFrontier_BattlePikeRoomWildMons_EventScript_WarpToLobbyLost
# 11 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	.2byte 0
# 12 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"

# 13 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
BattleFrontier_BattlePikeRoomWildMons_EventScript_SetInWildMonRoom::
# 14 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	pike_inwildmonroom
# 16 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	end
# 17 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"

# 18 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
BattleFrontier_BattlePikeRoomWildMons_EventScript_WarpToLobbyLost::
# 19 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 20 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
# 21 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	waitstate
# 22 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	end
# 23 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"

# 24 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
BattleFrontier_BattlePikeRoomWildMons_OnWarp:
# 25 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRoomWildMons_EventScript_TurnPlayerNorth
# 26 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	.2byte 0
# 27 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"

# 28 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
BattleFrontier_BattlePikeRoomWildMons_EventScript_TurnPlayerNorth::
# 29 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	setvar VAR_TEMP_4, 1
# 30 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 31 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	end
# 32 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"

# 33 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
BattleFrontier_BattlePikeRoomWildMons_OnResume:
# 34 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	call BattleFrontier_BattlePikeRoom_EventScript_ResetSketchedMoves
# 35 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 36 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePikeRoomWildMons_EventScript_SetLost
# 37 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePikeRoomWildMons_EventScript_SetLost
# 38 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	end
# 39 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"

# 40 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
BattleFrontier_BattlePikeRoomWildMons_EventScript_SetLost::
# 41 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	setvar VAR_TEMP_1, 1
# 42 "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.pory"
	end
