# 1 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_MapScripts::
# 3 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
# 4 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_OnTransition:
# 8 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
# 9 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
# 10 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 11 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 12 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott::
# 13 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
# 14 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
# 15 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	return
# 16 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 17 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_Nurse::
# 18 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_EVER_GRANDE_NURSE
# 19 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 20 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 21 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 22 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	release
# 23 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 24 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 25 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_Woman::
# 26 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
# 27 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 28 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 29 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM::
# 30 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
# 31 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 32 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 33 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_Scott::
# 34 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	lock
# 35 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 36 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
# 37 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	closemessage
# 38 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
# 39 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
# 40 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
# 41 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 42 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
# 43 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	playse SE_EXIT
# 44 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitse
# 45 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	removeobject LOCALID_EVER_GRANDE_SCOTT
# 46 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	release
# 47 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 48 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 49 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth::
# 50 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
# 51 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 52 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	return
# 53 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 54 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit::
# 55 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
# 56 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	return
# 58 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 59 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
# 60 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_left
# 61 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 62 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 63 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_left
# 64 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 65 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 66 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	step_end
# 67 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 68 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
# 69 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 70 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 71 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_left
# 72 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_left
# 73 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 74 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 75 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	step_end
# 76 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 77 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad:
# 78 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "The POKéMON LEAGUE is only a short\n"
# 79 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "distance after the VICTORY ROAD.\p"
# 80 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "If you've come this far, what choice\n"
# 81 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "do you have but to keep going?$"
# 82 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 83 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon:
# 84 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "The long and harrowing VICTORY ROAD…\p"
# 85 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "It's like reliving the path one has\n"
# 86 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "traveled in life…\p"
# 87 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "Believe in your POKéMON and give it\n"
# 88 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "your very best!$"
# 89 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 90 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou:
# 91 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "SCOTT: {PLAYER}{KUN}, you've clawed your\n"
# 92 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "way up to face the POKéMON LEAGUE!\p"
# 93 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "I'm happy for you!\n"
# 94 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "You made my cheering worthwhile!\p"
# 95 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER}{KUN}, if you were to become\n"
# 96 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "the POKéMON LEAGUE CHAMPION…\p"
# 97 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "I'll get in touch with you then.\p"
# 98 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "Okay, {PLAYER}{KUN}.\n"
# 99 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "Go for greatness!$"
