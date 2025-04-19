# 1 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 2 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 4 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_MapScripts::
# 5 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
# 6 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 9 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_OnTransition:
# 10 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
# 11 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 12 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 13 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
# 14 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 15 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 16 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	waitmessage
# 17 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 18 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	release
# 19 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 20 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 21 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
# 22 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
# 23 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 24 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 25 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_Man::
# 26 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
# 27 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 28 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 29 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
# 30 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
# 31 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 32 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 33 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
# 34 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	lock
# 35 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	faceplayer
# 36 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	waitse
# 37 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
# 38 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
# 39 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 40 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	release
# 41 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	end
# 42 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 43 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
# 44 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "There was someone here using a \n"
# 45 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "POKéMON I've never seen before.\p"
# 46 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "I never learned about it at\n"
# 47 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "TRAINER'S SCHOOL at least.\p"
# 48 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "I wonder where you can catch POKéMON\n"
# 49 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "like that.$"
# 50 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 51 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
# 52 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "Okay! Next stop, the BATTLE ARENA!\n"
# 53 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "I'd better get the right POKéMON from\l"
# 54 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "the PC Storage System.$"
# 55 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 56 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
# 57 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "Giggle… I'm going to go through every\n"
# 58 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "challenge with just this baby!$"
# 59 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"

# 60 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
BattleFrontier_PokemonCenter_1F_Text_Skitty:
# 61 "data//maps/BattleFrontier_PokemonCenter_1F/scripts.pory"
	.string "SKITTY: Mya myaaah!$"
