# 1 "data/maps/CaveOfOrigin_1F/scripts.pory"

# 2 "data/maps/CaveOfOrigin_1F/scripts.pory"
CaveOfOrigin_1F_MapScripts::
# 3 "data/maps/CaveOfOrigin_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_1F_OnTransition
# 4 "data/maps/CaveOfOrigin_1F/scripts.pory"
	.byte 0
# 5 "data/maps/CaveOfOrigin_1F/scripts.pory"

# 6 "data/maps/CaveOfOrigin_1F/scripts.pory"
CaveOfOrigin_1F_OnTransition:
# 7 "data/maps/CaveOfOrigin_1F/scripts.pory"
	call_if_set FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE, CaveOfOrigin_EventScript_DisableTriggers
# 8 "data/maps/CaveOfOrigin_1F/scripts.pory"
	end
