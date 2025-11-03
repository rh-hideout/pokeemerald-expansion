# 1 "data/maps/AlteringCave/scripts.pory"

# 2 "data/maps/AlteringCave/scripts.pory"
AlteringCave_MapScripts::
# 3 "data/maps/AlteringCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
# 4 "data/maps/AlteringCave/scripts.pory"
	.byte 0
# 5 "data/maps/AlteringCave/scripts.pory"

# 6 "data/maps/AlteringCave/scripts.pory"
AlteringCave_OnTransition:
# 7 "data/maps/AlteringCave/scripts.pory"
	setflag FLAG_LANDMARK_ALTERING_CAVE
# 8 "data/maps/AlteringCave/scripts.pory"
	end
