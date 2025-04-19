# 1 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 2 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_MapScripts::
# 3 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_SeafloorCavern_OnResume
# 4 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_SeafloorCavern_OnTransition
# 5 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Underwater_SeafloorCavern_OnLoad
# 6 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.byte 0
# 7 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 8 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_OnTransition:
# 9 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setflag FLAG_LANDMARK_SEAFLOOR_CAVERN
# 10 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_EventScript_HideSubmarine
# 11 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 12 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 13 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_EventScript_HideSubmarine::
# 14 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setflag FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE
# 15 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 16 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 17 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_OnLoad:
# 18 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	call_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_EventScript_SetSubmarineGoneMetatiles
# 19 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 20 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 21 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_EventScript_SetSubmarineGoneMetatiles::
# 22 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 5, 3, METATILE_Underwater_RockWall, TRUE
# 23 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 6, 3, METATILE_Underwater_RockWall, TRUE
# 24 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 7, 3, METATILE_Underwater_RockWall, TRUE
# 25 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 8, 3, METATILE_Underwater_RockWall, TRUE
# 26 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 5, 4, METATILE_Underwater_FloorShadow, FALSE
# 27 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 6, 4, METATILE_Underwater_FloorShadow, FALSE
# 28 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 7, 4, METATILE_Underwater_FloorShadow, FALSE
# 29 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 8, 4, METATILE_Underwater_FloorShadow, FALSE
# 30 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 5, 5, METATILE_Underwater_FloorShadow, FALSE
# 31 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 6, 5, METATILE_Underwater_FloorShadow, FALSE
# 32 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 7, 5, METATILE_Underwater_FloorShadow, FALSE
# 33 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 8, 5, METATILE_Underwater_FloorShadow, FALSE
# 34 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	return
# 35 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 36 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_OnResume:
# 37 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setdivewarp MAP_SEAFLOOR_CAVERN_ENTRANCE, 10, 17
# 38 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 39 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 40 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_EventScript_CheckStolenSub::
# 41 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	msgbox Underwater_SeafloorCavern_Text_SubExplorer1, MSGBOX_SIGN
# 42 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 43 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 44 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_Text_SubExplorer1:
# 45 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "“SUBMARINE EXPLORER 1” is painted\n"
# 46 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "on the hull.\p"
# 47 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "This is the submarine TEAM AQUA\n"
# 48 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "stole in SLATEPORT!\p"
# 49 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "TEAM AQUA must have gone\n"
# 50 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "ashore here.$"
