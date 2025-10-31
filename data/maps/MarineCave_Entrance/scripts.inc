# 1 "data/maps/MarineCave_Entrance/scripts.pory"

# 2 "data/maps/MarineCave_Entrance/scripts.pory"
MarineCave_Entrance_MapScripts::
# 3 "data/maps/MarineCave_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_Entrance_OnResume
# 4 "data/maps/MarineCave_Entrance/scripts.pory"
	.byte 0
# 5 "data/maps/MarineCave_Entrance/scripts.pory"

# 6 "data/maps/MarineCave_Entrance/scripts.pory"
MarineCave_Entrance_OnResume:
# 7 "data/maps/MarineCave_Entrance/scripts.pory"
	setdivewarp MAP_UNDERWATER_MARINE_CAVE, 9, 6
# 8 "data/maps/MarineCave_Entrance/scripts.pory"
	end
