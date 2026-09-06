.equ REQUIRED_OWNED_MONS, 20

Route10_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE10
	end

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Aide::
	lock
	faceplayer
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE, Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone
	msgbox Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_OWNED_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route10_PokemonCenter_1F_Text_GreatHereYouGo
	checkitemspace ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide, ITEM_EVERSTONE
	setflag FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone::
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_OWNED_MONS
	bufferitemname STR_VAR_2, ITEM_EVERSTONE
	return

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
	.string "The types of [Pokémon] match up\n"
	.string "differently with each other.\p"
	.string "Every type is stronger than some\n"
	.string "types and weaker than others.$"

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
	.string "A [Nugget] is totally useless.\n"
	.string "So I sold it for ¥5000.$"

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
	.string "I heard that ghosts haunt\n"
	.string "[Lavender Town].$"

Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons::
	.string "Oh… {PLAYER}!\n"
	.string "I've been looking for you!\p"
	.string "It's me, one of the ever-present\n"
	.string "[Aides] to [Prof. Oak].\p"
	.string "If your [Pokédex] has complete data\n"
	.string "on twenty species, I'm supposed to\l"
	.string "give you a reward from [Prof. Oak].\p"
	.string "He entrusted me with this\n"
	.string "[Everstone].\p"
	.string "So, {PLAYER}, let me ask you.\p"
	.string "Have you gathered data on at least\n"
	.string "twenty kinds of [Pokémon]?$"

Route10_PokemonCenter_1F_Text_GreatHereYouGo::
	.string "Great! You have caught or owned\n"
	.string "{STR_VAR_3} kinds of [Pokémon]!\p"
	.string "Congratulations!\n"
	.string "Here you go!$"

Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide::
	.string "{PLAYER} received the [Everstone]\n"
	.string "from the [Aide].$"

Route10_PokemonCenter_1F_Text_ExplainEverstone::
	.string "Making [Pokémon] evolve certainly\n"
	.string "can add to the [Pokédex].\p"
	.string "However, at times, you may not\n"
	.string "want a certain [Pokémon] to evolve.\p"
	.string "In that case, give the [Everstone]\n"
	.string "to that [Pokémon].\p"
	.string "It will prevent evolution according\n"
	.string "to the [Professor].$"
