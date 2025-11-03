# 1 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 2 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_MapScripts::
# 3 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
# 4 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 6 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_OnTransition:
# 7 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
# 8 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	end
# 9 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 10 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_EventScript_Tunneler1::
# 11 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
# 12 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	end
# 13 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 14 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_EventScript_Tunneler2::
# 15 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
# 16 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	end
# 17 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 18 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_EventScript_Tunneler3::
# 19 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	lock
# 20 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	faceplayer
# 21 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
# 22 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
# 23 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	release
# 24 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	end
# 25 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 26 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_EventScript_TunnelOpened::
# 27 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
# 28 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	release
# 29 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	end
# 30 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 31 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
# 32 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "That RUSTURF TUNNEL there…\p"
# 33 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "At first, we had a huge work crew boring\n"
# 34 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "through rock with the latest machinery.\l"
# 35 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "But, we had to stop.\p"
# 36 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "It turns out that we would have had\n"
# 37 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "a negative effect on wild POKéMON in\l"
# 38 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "the area.\p"
# 39 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "So, we've got nothing to do but loll\n"
# 40 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "around here doing nothing.$"
# 41 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 42 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
# 43 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "There's a man digging his way to\n"
# 44 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "VERDANTURF all by his lonesome.\l"
# 45 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "He's desperate to get through.\p"
# 46 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "He says that if he digs little by little\n"
# 47 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "without using machines, he won't\l"
# 48 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "disturb POKéMON, and he'll avoid\l"
# 49 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "harming the natural environment.\p"
# 50 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "I wonder if he made it through yet.$"
# 51 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 52 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
# 53 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "To get to VERDANTURF without using\n"
# 54 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "this TUNNEL, you'd have to cross the\l"
# 55 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "sea to DEWFORD, sail on to SLATEPORT,\l"
# 56 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "then travel through MAUVILLE.$"
# 57 "data/maps/Route116_TunnelersRestHouse/scripts.pory"

# 58 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
# 59 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "Did you hear? The TUNNEL to VERDANTURF\n"
# 60 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "has gone through!\p"
# 61 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "Sometimes, if you hope strongly enough,\n"
# 62 "data/maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "dreams do come true.$"
