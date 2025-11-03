# 1 "data/maps/DesertUnderpass/scripts.pory"

# 2 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_MapScripts::
# 3 "data/maps/DesertUnderpass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
# 4 "data/maps/DesertUnderpass/scripts.pory"
	.byte 0
# 5 "data/maps/DesertUnderpass/scripts.pory"

# 6 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_OnTransition:
# 7 "data/maps/DesertUnderpass/scripts.pory"
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
# 8 "data/maps/DesertUnderpass/scripts.pory"
	end
# 9 "data/maps/DesertUnderpass/scripts.pory"

# 10 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_Fossil::
# 11 "data/maps/DesertUnderpass/scripts.pory"
	lock
# 12 "data/maps/DesertUnderpass/scripts.pory"
	faceplayer
# 13 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
# 14 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
# 15 "data/maps/DesertUnderpass/scripts.pory"
	release
# 16 "data/maps/DesertUnderpass/scripts.pory"
	end
# 17 "data/maps/DesertUnderpass/scripts.pory"

# 18 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_GiveClawFossil::
# 19 "data/maps/DesertUnderpass/scripts.pory"
	giveitem ITEM_CLAW_FOSSIL
# 20 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 21 "data/maps/DesertUnderpass/scripts.pory"
	removeobject LOCALID_UNDERPASS_FOSSIL
# 22 "data/maps/DesertUnderpass/scripts.pory"
	release
# 23 "data/maps/DesertUnderpass/scripts.pory"
	end
# 24 "data/maps/DesertUnderpass/scripts.pory"

# 25 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_GiveRootFossil::
# 26 "data/maps/DesertUnderpass/scripts.pory"
	giveitem ITEM_ROOT_FOSSIL
# 27 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 28 "data/maps/DesertUnderpass/scripts.pory"
	removeobject LOCALID_UNDERPASS_FOSSIL
# 29 "data/maps/DesertUnderpass/scripts.pory"
	release
# 30 "data/maps/DesertUnderpass/scripts.pory"
	end
# 31 "data/maps/DesertUnderpass/scripts.pory"

# 32 "data/maps/DesertUnderpass/scripts.pory"
@ Unused
# 33 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Text_FoundRootFossil::
# 34 "data/maps/DesertUnderpass/scripts.pory"
	.string "{PLAYER} found the ROOT FOSSIL.$"
# 35 "data/maps/DesertUnderpass/scripts.pory"

# 36 "data/maps/DesertUnderpass/scripts.pory"
@ Unused
# 37 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Text_FoundClawFossil::
# 38 "data/maps/DesertUnderpass/scripts.pory"
	.string "{PLAYER} found the CLAW FOSSIL.$"
