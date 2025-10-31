# 1 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_MapScripts::
# 3 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
# 4 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_OnTransition:
# 8 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
# 9 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 10 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 11 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
# 12 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
# 13 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 14 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	waitmessage
# 15 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 16 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	release
# 17 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 18 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 19 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
# 20 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
# 21 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 22 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 23 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_Man::
# 24 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
# 25 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 26 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 27 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
# 28 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
# 29 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 30 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 31 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
# 32 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	lock
# 33 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	faceplayer
# 34 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	waitse
# 35 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
# 36 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
# 37 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 38 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	release
# 39 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 41 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
# 42 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "There was someone here using a \n"
# 43 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "POKéMON I've never seen before.\p"
# 44 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "I never learned about it at\n"
# 45 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "TRAINER'S SCHOOL at least.\p"
# 46 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "I wonder where you can catch POKéMON\n"
# 47 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "like that.$"
# 48 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 49 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
# 50 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "Okay! Next stop, the BATTLE ARENA!\n"
# 51 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "I'd better get the right POKéMON from\l"
# 52 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "the PC Storage System.$"
# 53 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 54 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
# 55 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "Giggle… I'm going to go through every\n"
# 56 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "challenge with just this baby!$"
# 57 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 58 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_Text_Skitty:
# 59 "data/maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "SKITTY: Mya myaaah!$"
