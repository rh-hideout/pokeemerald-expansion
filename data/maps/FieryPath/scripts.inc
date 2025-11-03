# 1 "data/maps/FieryPath/scripts.pory"

# 2 "data/maps/FieryPath/scripts.pory"
FieryPath_MapScripts::
# 3 "data/maps/FieryPath/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
# 4 "data/maps/FieryPath/scripts.pory"
	.byte 0
# 5 "data/maps/FieryPath/scripts.pory"

# 6 "data/maps/FieryPath/scripts.pory"
FieryPath_OnTransition:
# 7 "data/maps/FieryPath/scripts.pory"
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
# 8 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_LANDMARK_FIERY_PATH
# 9 "data/maps/FieryPath/scripts.pory"
	end
# 10 "data/maps/FieryPath/scripts.pory"

# 11 "data/maps/FieryPath/scripts.pory"
FieryPath_EventScript_MoveScottToFallarbor::
# 12 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
# 13 "data/maps/FieryPath/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
# 14 "data/maps/FieryPath/scripts.pory"
	return
