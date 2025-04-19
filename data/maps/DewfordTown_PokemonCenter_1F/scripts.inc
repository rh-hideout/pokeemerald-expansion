# 1 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 2 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 4 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_MapScripts::
# 5 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
# 6 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 9 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_OnTransition:
# 10 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
# 11 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 12 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 13 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 14 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_Nurse::
# 15 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 16 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 17 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 18 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 19 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
# 20 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 21 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 22 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
# 23 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
# 24 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 25 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 26 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_Man::
# 27 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
# 28 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 29 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 30 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_Text_StoneCavern:
# 31 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "There's a stone cavern at the edge\n"
# 32 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "of town.\p"
# 33 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "I've heard you can find rare stones\n"
# 34 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "there.$"
# 35 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 36 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
# 37 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Even if a POKéMON faints and can't\n"
# 38 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "battle, it can still use a move learned\l"
# 39 "data//maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "from a HIDDEN MACHINE (HM).$"
