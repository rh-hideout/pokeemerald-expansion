SproutHollow_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutHollow_OnTransition
	.byte 0

SproutHollow_OnTransition::
	setflag FLAG_P_VISITED_SPROUT_HOLLOW
	end

SproutHollow_EventScript_TownSign::
	msgbox SproutHollow_Text_1, MSGBOX_SIGN
	end

SproutHollow_EventScript_LabSign::
	msgbox SproutHollow_Text_2, MSGBOX_SIGN
	end

SproutHollow_EventScript_Girl::
	msgbox SproutHollow_Text_3, MSGBOX_NPC
	end

SproutHollow_EventScript_OldMan::
	msgbox SproutHollow_Text_4, MSGBOX_NPC
	end

SproutHollow_EventScript_NeedPokemon::
	lockall
	setspeaker Pentara_Name_Kai
	msgbox SproutHollow_Text_5, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	applymovement LOCALID_PLAYER, SproutHollow_Movement_StepBack
	waitmovement 0
	releaseall
	end

SproutHollow_EventScript_NeedPokemon2::
	goto SproutHollow_EventScript_NeedPokemon

SproutHollow_Movement_StepBack:
	walk_down
	step_end

SproutHollow_Text_1::
	.string "SPROUT HOLLOW\p"
	.string "Every great journey needs a first\n"
	.string "step.$"

SproutHollow_Text_2::
	.string "LINDEN POKéMON LAB\p"
	.string "Studying how the five regions of\n"
	.string "Pentara shape their Pokémon.$"

SproutHollow_Text_3::
	.string "Did you know? Each region of\n"
	.string "Pentara only has its own Pokémon!\p"
	.string "You can't catch a Pokémon from\n"
	.string "another region until you sail\l"
	.string "there.$"

SproutHollow_Text_4::
	.string "In my day we trained by battling\n"
	.string "every kid on every route!\p"
	.string "Nowadays trainers grow strong on\n"
	.string "the road itself. Wild Pokémon\l"
	.string "teach plenty.$"

SproutHollow_Text_5::
	.string "Hey, {PLAYER}! Hold it!\p"
	.string "The tall grass on Meadow Lane is\n"
	.string "full of wild Pokémon. You can't go\l"
	.string "out there alone!\p"
	.string "Professor Linden wants to see us\n"
	.string "at the lab. Come on!$"

