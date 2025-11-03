# 1 "data/maps/AbandonedShip_Deck/scripts.pory"

# 2 "data/maps/AbandonedShip_Deck/scripts.pory"
AbandonedShip_Deck_MapScripts::
# 3 "data/maps/AbandonedShip_Deck/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_Deck_OnTransition
# 4 "data/maps/AbandonedShip_Deck/scripts.pory"
	.byte 0
# 5 "data/maps/AbandonedShip_Deck/scripts.pory"

# 6 "data/maps/AbandonedShip_Deck/scripts.pory"
AbandonedShip_Deck_OnTransition:
# 7 "data/maps/AbandonedShip_Deck/scripts.pory"
	setflag FLAG_LANDMARK_ABANDONED_SHIP
# 8 "data/maps/AbandonedShip_Deck/scripts.pory"
	end
