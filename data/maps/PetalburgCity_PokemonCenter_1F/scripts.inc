# 1 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_MapScripts::
# 3 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
# 4 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_OnTransition:
# 8 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_PETALBURG_CITY
# 9 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 10 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 11 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 12 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
# 13 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
# 14 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 15 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 16 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 17 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 18 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 19 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 20 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
# 21 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
# 22 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 23 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 24 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
# 25 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
# 26 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 27 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 28 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Woman::
# 29 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 30 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 31 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
# 32 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, IsStarterInParty
# 33 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
# 34 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 35 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 36 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 37 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
# 38 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
# 39 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
# 40 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
# 41 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 42 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 43 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 44 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
# 45 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
# 46 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 47 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 48 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
# 49 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
# 50 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 51 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 52 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
# 53 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
# 54 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 55 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 56 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
# 57 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "That PC-based POKéMON Storage\n"
# 58 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "System…\p"
# 59 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Whoever made it must be some kind\n"
# 60 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "of a scientific wizard!$"
# 61 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 62 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
# 63 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "When my POKéMON ate an\n"
# 64 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "ORAN BERRY, it regained HP!$"
# 65 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 66 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
# 67 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "There are many types of POKéMON.\p"
# 68 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "All types have their strengths and\n"
# 69 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "weaknesses against other types.\p"
# 70 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Depending on the types of POKéMON,\n"
# 71 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "a battle could be easy or hard.$"
# 72 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 73 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
# 74 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your TREECKO\n"
# 75 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a GRASS type.\p"
# 76 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the WATER and\n"
# 77 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "GROUND types.\p"
# 78 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against FIRE-type\n"
# 79 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON.$"
# 80 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 81 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
# 82 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your TORCHIC\n"
# 83 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a FIRE type.\p"
# 84 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the GRASS and\n"
# 85 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "BUG types.\p"
# 86 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against WATER-type\n"
# 87 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON.$"
# 88 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 89 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
# 90 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your MUDKIP\n"
# 91 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a WATER type.\p"
# 92 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the FIRE type.\p"
# 93 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against GRASS-type\n"
# 94 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "and ELECTRIC-type POKéMON.$"
