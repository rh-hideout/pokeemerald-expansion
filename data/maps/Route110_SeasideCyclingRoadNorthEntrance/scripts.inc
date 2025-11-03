# 1 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 2 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_MapScripts::
# 3 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_SeasideCyclingRoadNorthEntrance_OnTransition
# 4 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.byte 0
# 5 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 6 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_OnTransition:
# 7 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 3, Route110_SeasideCyclingRoadNorthEntrance_EventScript_RestartChallenge
# 8 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 2, Route110_SeasideCyclingRoadNorthEntrance_EventScript_RestartChallenge
# 9 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 10 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 11 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_RestartChallenge::
# 12 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
# 13 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	return
# 14 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 15 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_Clerk::
# 16 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	lock
# 17 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	faceplayer
# 18 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
# 19 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	release
# 20 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 21 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 22 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_BikeCheck::
# 23 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	lockall
# 24 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	specialvar VAR_RESULT, GetPlayerAvatarBike
# 25 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	call_if_eq VAR_RESULT, 2, Route110_SeasideCyclingRoadNorthEntrance_EventScript_OnMachBike
# 26 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike
# 27 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setflag FLAG_SYS_CYCLING_ROAD
# 28 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setvar VAR_TEMP_1, 1
# 29 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	releaseall
# 30 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 31 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 32 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_OnMachBike::
# 33 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
# 34 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	return
# 35 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 36 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike::
# 37 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
# 38 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	closemessage
# 39 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter
# 40 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	waitmovement 0
# 41 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	releaseall
# 42 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 43 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 44 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter:
# 45 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	walk_left
# 46 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	step_end
# 47 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 48 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_ClearCyclingRoad::
# 49 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	lockall
# 50 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 0
# 51 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	clearflag FLAG_SYS_CYCLING_ROAD
# 52 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setvar VAR_TEMP_1, 0
# 53 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	releaseall
# 54 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 55 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 56 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad:
# 57 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "On CYCLING ROAD, you can go all out\n"
# 58 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "and cycle as fast as you'd like.\p"
# 59 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "It feels great to go that fast, but try\n"
# 60 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "not to crash into anyone!$"
# 61 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 62 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk:
# 63 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "Sorry, you can't walk on CYCLING\n"
# 64 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "ROAD. It's too dangerous.\p"
# 65 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "Please come back with a BIKE.$"
