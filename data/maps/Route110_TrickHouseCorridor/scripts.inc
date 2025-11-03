# 1 "data/maps/Route110_TrickHouseCorridor/scripts.pory"

# 2 "data/maps/Route110_TrickHouseCorridor/scripts.pory"
Route110_TrickHouseCorridor_MapScripts::
# 3 "data/maps/Route110_TrickHouseCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseCorridor_OnTransition
# 4 "data/maps/Route110_TrickHouseCorridor/scripts.pory"
	.byte 0
# 5 "data/maps/Route110_TrickHouseCorridor/scripts.pory"

# 6 "data/maps/Route110_TrickHouseCorridor/scripts.pory"
Route110_TrickHouseCorridor_OnTransition:
# 7 "data/maps/Route110_TrickHouseCorridor/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1
# 8 "data/maps/Route110_TrickHouseCorridor/scripts.pory"
	end
