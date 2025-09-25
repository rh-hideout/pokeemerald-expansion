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

# 25 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Woman::
# 26 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 27 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 28 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
# 29 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, IsStarterInParty
# 30 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
# 31 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 32 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 33 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 34 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
# 35 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
# 36 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
# 37 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
# 38 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 39 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 40 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 41 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
# 42 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
# 43 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 44 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 45 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
# 46 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
# 47 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 48 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 49 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
# 50 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
# 51 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 52 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 53 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
# 54 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "That PC-based POKéMON Storage\n"
# 55 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "System…\p"
# 56 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Whoever made it must be some kind\n"
# 57 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "of a scientific wizard!$"
# 58 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 59 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
# 60 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "There are many types of POKéMON.\p"
# 61 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "All types have their strengths and\n"
# 62 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "weaknesses against other types.\p"
# 63 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Depending on the types of POKéMON,\n"
# 64 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "a battle could be easy or hard.$"
# 65 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 66 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
# 67 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your TREECKO\n"
# 68 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a GRASS type.\p"
# 69 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the WATER and\n"
# 70 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "GROUND types.\p"
# 71 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against FIRE-type\n"
# 72 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON.$"
# 73 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 74 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
# 75 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your TORCHIC\n"
# 76 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a FIRE type.\p"
# 77 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the GRASS and\n"
# 78 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "BUG types.\p"
# 79 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against WATER-type\n"
# 80 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON.$"
# 81 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 82 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
# 83 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your MUDKIP\n"
# 84 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a WATER type.\p"
# 85 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the FIRE type.\p"
# 86 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against GRASS-type\n"
# 87 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "and ELECTRIC-type POKéMON.$"
# 88 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 89 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
.align 2
# 90 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
Petalburg_Center_Item_Mart::
# 91 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_ORAN_BERRY
# 92 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_POMEG_BERRY
# 93 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 94 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 95 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 96 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 97 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 98 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_POKE_VIAL
# 99 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_ESCAPE_ROPE
# 100 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_NONE
# 101 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
    release
# 102 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
    end
# 103 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 104 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
.align 2
# 105 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
Petalburg_Center_Mon_Mart::
# 106 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LONELY_MINT
# 107 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ADAMANT_MINT
# 108 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NAUGHTY_MINT
# 109 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_BRAVE_MINT
# 110 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_BOLD_MINT
# 111 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_IMPISH_MINT
# 112 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LAX_MINT
# 113 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_RELAXED_MINT
# 114 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MODEST_MINT
# 115 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MILD_MINT
# 116 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_RASH_MINT
# 117 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_QUIET_MINT
# 118 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_CALM_MINT
# 119 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GENTLE_MINT
# 120 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_CAREFUL_MINT
# 121 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SASSY_MINT
# 122 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_TIMID_MINT
# 123 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HASTY_MINT
# 124 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_JOLLY_MINT
# 125 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NAIVE_MINT
# 126 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SERIOUS_MINT
# 127 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NONE

PetalburgCity_PokemonCenter_1F_EventScript_Merchant::
# 132 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 133 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 134 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	message PetalburgCity_PokemonCenter_1F_EventScript_Merchant_Text_0
# 135 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 136 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	pokemart Petalburg_Center_Item_Mart
# 137 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	message PetalburgCity_PokemonCenter_1F_EventScript_Merchant_Text_1
# 138 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
	end


PetalburgCity_PokemonCenter_1F_EventScript_Bookcase::
# 143 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_EventScript_Bookcase_Text_0, MSGBOX_SIGN
	end


PetalburgCity_PokemonCenter_1F_EventScript_NatureGuy::
# 148 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 149 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 150 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	message PetalburgCity_PokemonCenter_1F_EventScript_Merchant_Text_0
# 151 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 152 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	pokemart Petalburg_Center_Mon_Mart
# 153 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	message PetalburgCity_PokemonCenter_1F_EventScript_NatureGuy_Text_0
# 154 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
	end


PetalburgCity_PokemonCenter_1F_EventScript_Merchant_Text_0:
# 134 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "How can I help you?$"

PetalburgCity_PokemonCenter_1F_EventScript_Merchant_Text_1:
# 137 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Come again soon!$"

PetalburgCity_PokemonCenter_1F_EventScript_Bookcase_Text_0:
# 143 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "A collection of books about Hoenn, and\n"
	.string "how to identify different species.$"

PetalburgCity_PokemonCenter_1F_EventScript_NatureGuy_Text_0:
# 153 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "I'm always here!$"
