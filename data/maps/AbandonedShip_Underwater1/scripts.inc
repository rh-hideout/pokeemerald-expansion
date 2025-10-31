# 1 "data/maps/AbandonedShip_Underwater1/scripts.pory"

# 2 "data/maps/AbandonedShip_Underwater1/scripts.pory"
AbandonedShip_Underwater1_MapScripts::
# 3 "data/maps/AbandonedShip_Underwater1/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater1_OnResume
# 4 "data/maps/AbandonedShip_Underwater1/scripts.pory"
	.byte 0
# 5 "data/maps/AbandonedShip_Underwater1/scripts.pory"

# 6 "data/maps/AbandonedShip_Underwater1/scripts.pory"
AbandonedShip_Underwater1_OnResume:
# 7 "data/maps/AbandonedShip_Underwater1/scripts.pory"
	setdivewarp MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS, 0, 10
# 8 "data/maps/AbandonedShip_Underwater1/scripts.pory"
	end
