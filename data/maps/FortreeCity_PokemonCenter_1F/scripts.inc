# 1 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_MapScripts::
# 5 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_OnTransition:
# 10 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_FORTREE_CITY
# 11 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	end
# 12 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 13 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_EventScript_Nurse::
# 14 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 15 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 16 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 17 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 18 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	release
# 19 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	end
# 20 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 21 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
# 22 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
# 23 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	end
# 24 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 25 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_EventScript_Man::
# 26 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
# 27 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	end
# 28 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 29 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_EventScript_Boy::
# 30 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
# 31 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	end
# 32 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 33 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
# 34 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "Listen, kid, are you working\n"
# 35 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "on a POKéDEX?\p"
# 36 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "Hmm… Go to the SAFARI ZONE.\n"
# 37 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "That's my suggestion.$"
# 38 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 39 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
# 40 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "Have you done anything at\n"
# 41 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "the RECORD CORNER?\p"
# 42 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "It's pretty neat. It mixes and matches\n"
# 43 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "the records of TRAINERS.\p"
# 44 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "I don't know quite how it works,\n"
# 45 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "but it's cool. It's exciting, even!$"
# 46 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"

# 47 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
# 48 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "Oh, wow, you have a POKéNAV!\n"
# 49 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "And it's just like mine!\p"
# 50 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "Do you know about POKéNAV's\n"
# 51 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "MATCH CALL system?\p"
# 52 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "Access it, and you can chat with\n"
# 53 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "registered TRAINERS anytime.\p"
# 54 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "It also shows you which TRAINERS\n"
# 55 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "want a rematch with you.\p"
# 56 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "It's really nifty! Those DEVON guys\n"
# 57 "data/maps/FortreeCity_PokemonCenter_1F/scripts.pory"
	.string "sure know what they're doing!$"
