# 1 "data/maps/DesertUnderpass/scripts.pory"

# 2 "data/maps/DesertUnderpass/scripts.pory"
.set LOCALID_FOSSIL, 1
# 3 "data/maps/DesertUnderpass/scripts.pory"

# 4 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_MapScripts::
# 5 "data/maps/DesertUnderpass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
# 6 "data/maps/DesertUnderpass/scripts.pory"
	.byte 0
# 7 "data/maps/DesertUnderpass/scripts.pory"

# 8 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_OnTransition:
# 9 "data/maps/DesertUnderpass/scripts.pory"
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
# 10 "data/maps/DesertUnderpass/scripts.pory"
	end
# 11 "data/maps/DesertUnderpass/scripts.pory"

# 12 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_Fossil::
# 13 "data/maps/DesertUnderpass/scripts.pory"
	lock
# 14 "data/maps/DesertUnderpass/scripts.pory"
	faceplayer
# 15 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_set FLAG_DAILY_FOSSIL_RECEIVED, DesertUnderpass_EventScript_GiveFossil
# 16 "data/maps/DesertUnderpass/scripts.pory"
	release
# 17 "data/maps/DesertUnderpass/scripts.pory"
	end
# 18 "data/maps/DesertUnderpass/scripts.pory"

# 19 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_GiveFossil::
# 20 "data/maps/DesertUnderpass/scripts.pory"
	random 15
# 21 "data/maps/DesertUnderpass/scripts.pory"
	addvar VAR_RESULT, ITEM_HELIX_FOSSIL
# 22 "data/maps/DesertUnderpass/scripts.pory"
	finditem VAR_RESULT
# 23 "data/maps/DesertUnderpass/scripts.pory"
    setflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
# 24 "data/maps/DesertUnderpass/scripts.pory"
	waitmessage
# 25 "data/maps/DesertUnderpass/scripts.pory"
	waitfanfare
# 26 "data/maps/DesertUnderpass/scripts.pory"
    release
# 27 "data/maps/DesertUnderpass/scripts.pory"
    end
# 28 "data/maps/DesertUnderpass/scripts.pory"

# 29 "data/maps/DesertUnderpass/scripts.pory"
@ Unused
# 30 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Text_FoundRootFossil::
# 31 "data/maps/DesertUnderpass/scripts.pory"
	.string "{PLAYER} found the ROOT FOSSIL.$"
# 32 "data/maps/DesertUnderpass/scripts.pory"

# 33 "data/maps/DesertUnderpass/scripts.pory"
@ Unused
# 34 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Text_FoundClawFossil::
# 35 "data/maps/DesertUnderpass/scripts.pory"
	.string "{PLAYER} found the CLAW FOSSIL.$"
