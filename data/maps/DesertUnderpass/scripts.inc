# 1 "data//maps/DesertUnderpass/scripts.pory"

# 2 "data//maps/DesertUnderpass/scripts.pory"
.set LOCALID_FOSSIL, 1
# 3 "data//maps/DesertUnderpass/scripts.pory"

# 4 "data//maps/DesertUnderpass/scripts.pory"
DesertUnderpass_MapScripts::
# 5 "data//maps/DesertUnderpass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
# 6 "data//maps/DesertUnderpass/scripts.pory"
	.byte 0
# 7 "data//maps/DesertUnderpass/scripts.pory"

# 8 "data//maps/DesertUnderpass/scripts.pory"
DesertUnderpass_OnTransition:
# 9 "data//maps/DesertUnderpass/scripts.pory"
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
# 10 "data//maps/DesertUnderpass/scripts.pory"
	end
# 11 "data//maps/DesertUnderpass/scripts.pory"

# 12 "data//maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_Fossil::
# 13 "data//maps/DesertUnderpass/scripts.pory"
	lock
# 14 "data//maps/DesertUnderpass/scripts.pory"
	faceplayer
# 15 "data//maps/DesertUnderpass/scripts.pory"
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
# 16 "data//maps/DesertUnderpass/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
# 17 "data//maps/DesertUnderpass/scripts.pory"
	release
# 18 "data//maps/DesertUnderpass/scripts.pory"
	end
# 19 "data//maps/DesertUnderpass/scripts.pory"

# 20 "data//maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_GiveClawFossil::
# 21 "data//maps/DesertUnderpass/scripts.pory"
	giveitem ITEM_CLAW_FOSSIL
# 22 "data//maps/DesertUnderpass/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 23 "data//maps/DesertUnderpass/scripts.pory"
	removeobject LOCALID_FOSSIL
# 24 "data//maps/DesertUnderpass/scripts.pory"
	release
# 25 "data//maps/DesertUnderpass/scripts.pory"
	end
# 26 "data//maps/DesertUnderpass/scripts.pory"

# 27 "data//maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_GiveRootFossil::
# 28 "data//maps/DesertUnderpass/scripts.pory"
	giveitem ITEM_ROOT_FOSSIL
# 29 "data//maps/DesertUnderpass/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 30 "data//maps/DesertUnderpass/scripts.pory"
	removeobject LOCALID_FOSSIL
# 31 "data//maps/DesertUnderpass/scripts.pory"
	release
# 32 "data//maps/DesertUnderpass/scripts.pory"
	end
# 33 "data//maps/DesertUnderpass/scripts.pory"

# 34 "data//maps/DesertUnderpass/scripts.pory"
@ Unused
# 35 "data//maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Text_FoundRootFossil::
# 36 "data//maps/DesertUnderpass/scripts.pory"
	.string "{PLAYER} found the ROOT FOSSIL.$"
# 37 "data//maps/DesertUnderpass/scripts.pory"

# 38 "data//maps/DesertUnderpass/scripts.pory"
@ Unused
# 39 "data//maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Text_FoundClawFossil::
# 40 "data//maps/DesertUnderpass/scripts.pory"
	.string "{PLAYER} found the CLAW FOSSIL.$"
