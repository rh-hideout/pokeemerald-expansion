# 1 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_LANETTE, 4
# 4 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 5 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_MapScripts::
# 6 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
# 7 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 8 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 9 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 10 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_OnTransition:
# 11 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
# 12 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 13 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 14 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 15 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_Nurse::
# 16 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 17 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 18 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 19 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 20 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	release
# 21 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 22 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 23 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_Girl::
# 24 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
# 25 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 26 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 27 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
# 28 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
# 29 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 30 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 31 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_Lanette::
# 32 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	lock
# 33 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 34 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
# 35 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 36 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	switch VAR_FACING
# 37 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
# 38 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
# 39 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 40 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 41 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
# 42 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
# 43 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 44 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
# 45 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 46 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 47 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
# 48 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
# 49 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 50 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
# 51 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 52 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 53 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
# 54 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	playse SE_SLIDING_DOOR
# 55 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	removeobject LOCALID_LANETTE
# 56 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
# 57 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	release
# 58 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 59 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 60 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
# 61 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 62 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 63 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 64 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 65 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 66 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 67 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 68 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 69 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 70 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 71 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 72 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	delay_8
# 73 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	step_end
# 74 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 75 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
# 76 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 77 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 78 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 79 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 80 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 81 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 82 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 83 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 84 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 85 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	delay_8
# 86 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	step_end
# 87 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 88 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
# 89 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Oh, hello.\n"
# 90 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "You are?\p"
# 91 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Okay, your name's {PLAYER}{KUN}.\n"
# 92 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "I can see that you're a TRAINER.\p"
# 93 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "So that means you use the POKéMON\n"
# 94 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Storage System I developed.\p"
# 95 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "How I arrived at that conclusion is\n"
# 96 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "a simple deductive process.\p"
# 97 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "You spoke to me because you wanted\n"
# 98 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "to access something on this PC.\p"
# 99 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Oh, I'm sorry. I'm LANETTE.\p"
# 100 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Honestly, I'm glad to meet you--it's\n"
# 101 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "great you're using the Storage System.\p"
# 102 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "If you could, please visit me at home.\n"
# 103 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "My house is on ROUTE 114.$"
# 104 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 105 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
# 106 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "I wonder what POKéMON looked like\n"
# 107 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "long, long ago?\p"
# 108 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Maybe the FOSSIL MANIAC at the edge\n"
# 109 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "of town will know.$"
# 110 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 111 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
# 112 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "In the fields of FALLARBOR, we plant\n"
# 113 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "seedlings of hardy trees that thrive\l"
# 114 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "even in volcanic ash.$"
