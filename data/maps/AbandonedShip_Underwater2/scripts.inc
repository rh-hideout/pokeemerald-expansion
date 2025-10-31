# 1 "data/maps/AbandonedShip_Underwater2/scripts.pory"

# 2 "data/maps/AbandonedShip_Underwater2/scripts.pory"
AbandonedShip_Underwater2_MapScripts::
# 3 "data/maps/AbandonedShip_Underwater2/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater2_OnResume
# 4 "data/maps/AbandonedShip_Underwater2/scripts.pory"
	.byte 0
# 5 "data/maps/AbandonedShip_Underwater2/scripts.pory"

# 6 "data/maps/AbandonedShip_Underwater2/scripts.pory"
AbandonedShip_Underwater2_OnResume:
# 7 "data/maps/AbandonedShip_Underwater2/scripts.pory"
	setdivewarp MAP_ABANDONED_SHIP_ROOMS_B1F, 13, 7
# 8 "data/maps/AbandonedShip_Underwater2/scripts.pory"
	end
