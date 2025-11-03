# 1 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_MapScripts::
# 3 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
# 4 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_OnTransition:
# 8 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
# 9 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 10 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 11 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 12 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_Nurse::
# 13 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_DEWFORD_NURSE
# 14 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 15 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 16 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 17 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
# 18 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 19 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 20 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
# 21 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
# 22 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 23 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 24 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_Man::
# 25 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
# 26 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 27 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 28 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_Text_StoneCavern:
# 29 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "There's a stone cavern at the edge\n"
# 30 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "of town.\p"
# 31 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "I've heard you can find rare stones\n"
# 32 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "there.$"
# 33 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 34 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
# 35 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Even if a POKéMON faints and can't\n"
# 36 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "battle, it can still use a move learned\l"
# 37 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "from a HIDDEN MACHINE (HM).$"
