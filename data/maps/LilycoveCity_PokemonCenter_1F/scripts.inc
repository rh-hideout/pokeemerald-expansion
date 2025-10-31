# 1 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_MapScripts::
# 3 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
# 4 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_OnTransition:
# 8 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
# 9 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	goto LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx
# 10 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 11 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 12 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
@ SetLilycoveLadyGfx returns TRUE if its the Contest Lady
# 13 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx::
# 14 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	special SetLilycoveLadyGfx
# 15 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
# 16 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
# 17 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 18 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 19 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon::
# 20 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
# 21 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 22 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 23 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon::
# 24 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
# 25 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 26 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 27 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Nurse::
# 28 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_LILYCOVE_NURSE
# 29 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 30 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 31 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 32 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	release
# 33 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 34 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 35 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Boy::
# 36 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon, MSGBOX_NPC
# 37 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 38 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 39 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Maniac::
# 40 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	lock
# 41 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 42 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
# 43 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
# 44 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	release
# 45 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 46 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 47 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone::
# 48 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
# 49 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	release
# 50 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 51 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 52 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon:
# 53 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "I wonder how many kinds of POKéMON\n"
# 54 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "there are in the world.\p"
# 55 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "It'd be great to cross seas and\n"
# 56 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "trade POKéMON with people far away.$"
# 57 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 58 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels:
# 59 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "I've been hearing about some rotten\n"
# 60 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "scoundrels who steal POKéMON and rip\l"
# 61 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "off METEORITES.$"
# 62 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 63 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels:
# 64 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "Those rotten scoundrels who steal\n"
# 65 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON and rip off METEORITES…\p"
# 66 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "I haven't seen them around recently.$"
