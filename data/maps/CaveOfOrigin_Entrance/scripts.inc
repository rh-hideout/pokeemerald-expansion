# 1 "data/maps/CaveOfOrigin_Entrance/scripts.pory"

# 2 "data/maps/CaveOfOrigin_Entrance/scripts.pory"
CaveOfOrigin_Entrance_MapScripts::
# 3 "data/maps/CaveOfOrigin_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CaveOfOrigin_Entrance_OnResume
# 4 "data/maps/CaveOfOrigin_Entrance/scripts.pory"
	.byte 0
# 5 "data/maps/CaveOfOrigin_Entrance/scripts.pory"

# 6 "data/maps/CaveOfOrigin_Entrance/scripts.pory"
CaveOfOrigin_Entrance_OnResume:
# 7 "data/maps/CaveOfOrigin_Entrance/scripts.pory"
	setescapewarp MAP_SOOTOPOLIS_CITY, 31, 17
# 8 "data/maps/CaveOfOrigin_Entrance/scripts.pory"
	end
