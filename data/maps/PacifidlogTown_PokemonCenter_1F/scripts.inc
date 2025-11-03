# 1 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_MapScripts::
# 3 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
# 4 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_OnTransition:
# 8 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
# 9 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 10 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 11 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
# 12 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
# 13 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 14 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 15 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 16 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	release
# 17 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 18 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 19 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
# 20 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
# 21 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 22 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 23 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
# 24 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
# 25 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 26 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 27 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
# 28 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
# 29 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 30 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 31 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
# 32 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "What color is your TRAINER CARD?\n"
# 33 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "Mine's copper!$"
# 34 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 35 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
# 36 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "PACIFIDLOG TOWN floats on top of\n"
# 37 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "a colony of CORSOLA.\p"
# 38 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "If I told you that, would you believe\n"
# 39 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "me?$"
# 40 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 41 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
# 42 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "The ancestors of the people in\n"
# 43 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "PACIFIDLOG were said to have been\l"
# 44 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "born on boats and then lived and died \l"
# 45 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "aboard them.\p"
# 46 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "I understand that they lived that way\n"
# 47 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "because they were searching for\l"
# 48 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "something.$"
