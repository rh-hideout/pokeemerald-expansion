BattleFrontier_PokemonCenter_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition_hns
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition_hns:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse_hns::
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon_hns:
	.string "There was someone here using a \n"
	.string "POKéMON I've never seen before.\p"
	.string "I never learned about it at\n"
	.string "TRAINER'S SCHOOL at least.\p"
	.string "I wonder where you can catch POKéMON\n"
	.string "like that.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena_hns:
	.string "Okay! Next stop, the BATTLE ARENA!\n"
	.string "I'd better get the right POKéMON from\l"
	.string "the PC Storage System.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge_hns:
	.string "Giggle… I'm going to go through every\n"
	.string "challenge with just this baby!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty_hns:
	.string "SKITTY: Mya myaaah!$"

