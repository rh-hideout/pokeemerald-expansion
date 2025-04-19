# 1 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_MapScripts::
# 5 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_OnTransition:
# 10 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
# 11 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 12 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 13 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
# 14 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 15 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 16 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 17 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 18 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 19 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 20 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 21 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
# 22 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	lock
# 23 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 24 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
# 25 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
# 26 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
# 27 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 28 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 29 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 30 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
# 31 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
# 32 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 33 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 34 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 35 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_Woman::
# 36 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	lock
# 37 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 38 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
# 39 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
# 40 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
# 41 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 42 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 43 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 44 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
# 45 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
# 46 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 47 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 48 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 49 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
# 50 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "WALLACE is rumored to be the toughest\n"
# 51 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "TRAINER in the whole HOENN region.\p"
# 52 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "This town's GYM is led by the TRAINER\n"
# 53 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "who taught WALLACE.\p"
# 54 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "But the ELITE FOUR… They're said to be\n"
# 55 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "even stronger than WALLACE's mentor.\p"
# 56 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "How strong could they be?$"
# 57 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 58 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
# 59 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Everyone in town has taken refuge\n"
# 60 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "and won't come out of their homes.\p"
# 61 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Even I would rather not venture\n"
# 62 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "outside.$"
# 63 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 64 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
# 65 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Whenever, wherever, and whatever\n"
# 66 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "happens, I will always be friends with\l"
# 67 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON.\p"
# 68 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Because it's fun to be with POKéMON!$"
# 69 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 70 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
# 71 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Aren't POKéMON our friends?\p"
# 72 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Why are they going wild this way?$"
