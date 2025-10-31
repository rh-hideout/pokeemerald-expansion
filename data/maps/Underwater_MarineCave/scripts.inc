# 1 "data/maps/Underwater_MarineCave/scripts.pory"

# 2 "data/maps/Underwater_MarineCave/scripts.pory"
Underwater_MarineCave_MapScripts::
# 3 "data/maps/Underwater_MarineCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_MarineCave_OnResume
# 4 "data/maps/Underwater_MarineCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_MarineCave_OnTransition
# 5 "data/maps/Underwater_MarineCave/scripts.pory"
	.byte 0
# 6 "data/maps/Underwater_MarineCave/scripts.pory"

# 7 "data/maps/Underwater_MarineCave/scripts.pory"
Underwater_MarineCave_OnTransition:
# 8 "data/maps/Underwater_MarineCave/scripts.pory"
	setflag FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT
# 9 "data/maps/Underwater_MarineCave/scripts.pory"
	end
# 10 "data/maps/Underwater_MarineCave/scripts.pory"

# 11 "data/maps/Underwater_MarineCave/scripts.pory"
Underwater_MarineCave_OnResume:
# 12 "data/maps/Underwater_MarineCave/scripts.pory"
	setdivewarp MAP_MARINE_CAVE_ENTRANCE, 10, 17
# 13 "data/maps/Underwater_MarineCave/scripts.pory"
	end
