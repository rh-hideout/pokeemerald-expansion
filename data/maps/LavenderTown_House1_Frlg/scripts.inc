LavenderTown_House1_Frlg_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end

LavenderTown_House1_Text_Cubone::
	.string "[Cubone]: Kyarugoo!$"

LavenderTown_House1_Text_RocketsKilledCubonesMother::
	.string "Those horrible [Rockets]!\n"
	.string "They deserve no mercy!\p"
	.string "That poor [Cubone]'s mother…\p"
	.string "It was killed trying to escape from\n"
	.string "[Team Rocket].$"

LavenderTown_House1_Text_GhostOfPokemonTowerIsGone::
	.string "The ghost of [Pokémon Tower] is\n"
	.string "gone!\p"
	.string "Someone must have soothed its\n"
	.string "restless spirit!$"
