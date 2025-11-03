# 1 "data/maps/Underwater_Route134/scripts.pory"

# 2 "data/maps/Underwater_Route134/scripts.pory"
Underwater_Route134_MapScripts::
# 3 "data/maps/Underwater_Route134/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route134_OnResume
# 4 "data/maps/Underwater_Route134/scripts.pory"
	.byte 0
# 5 "data/maps/Underwater_Route134/scripts.pory"

# 6 "data/maps/Underwater_Route134/scripts.pory"
Underwater_Route134_OnResume:
# 7 "data/maps/Underwater_Route134/scripts.pory"
	setdivewarp MAP_ROUTE134, 60, 31
# 8 "data/maps/Underwater_Route134/scripts.pory"
	end
