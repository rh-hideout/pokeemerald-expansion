# 1 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
MossdeepCity_PokemonCenter_1F_MapScripts::
# 5 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
MossdeepCity_PokemonCenter_1F_OnTransition:
# 10 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
# 11 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	end
# 12 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"

# 13 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
# 14 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 15 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 16 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 17 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 18 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	release
# 19 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	end
# 20 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"

# 21 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
MossdeepCity_PokemonCenter_1F_EventScript_Woman::
# 22 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
# 23 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	end
# 24 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"

# 25 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
MossdeepCity_PokemonCenter_1F_EventScript_Girl::
# 26 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
# 27 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	end
# 28 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"

# 29 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
# 30 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	.string "The GYM LEADERS in this town are\n"
# 31 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	.string "a formidable duo.\p"
# 32 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	.string "Their combination attacks are, like,\n"
# 33 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	.string "excellent and wow!$"
# 34 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"

# 35 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
# 36 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	.string "Depending on the special abilities of\n"
# 37 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON, some moves might change\l"
# 38 "data/maps/MossdeepCity_PokemonCenter_1F/scripts.pory"
	.string "or not work at all.$"
