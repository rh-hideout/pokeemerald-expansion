.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "To the north of LAVENDER is ROCK\n"
	.string "TUNNEL. Go through it to get to\l"
	.string "the POWER PLANT.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "There's a radio program that plays\n"
	.string "POKé FLUTE music.\p"
	.string "Oh? Ah, your radio needs a RADIO\n"
	.string "UPGRADE to tune into it.\p"
	.string "Maybe the RADIO STATION here\n"
	.string "in town can provide you one?$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "If the POWER PLANT isn't running,\n"
	.string "the MAGNET TRAIN won't run either…\p"
	.string "It also means the RADIO STATION\n"
	.string "can't broadcast…$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "The DIRECTOR of the RADIO STATION\n"
	.string "sure was happy.\p"
	.string "He said they're back on the air\n"
	.string "because the POWER PLANT is running\l"
	.string "smoothly again.$"
