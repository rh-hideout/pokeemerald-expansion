# 1 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_MapScripts::
# 3 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
# 4 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_OnTransition:
# 8 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_OLDALE_TOWN
# 9 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 10 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 11 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 12 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_Nurse::
# 13 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
# 14 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 15 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 16 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 17 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
# 18 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 19 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 20 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
# 21 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
# 22 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 23 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 24 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_Boy::
# 25 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
# 26 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 27 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 28 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_Girl::
# 29 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 30 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 31 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
# 32 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
# 33 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
# 34 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 35 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 36 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
# 37 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
# 38 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
# 39 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 40 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 41 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
# 42 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "That PC in the corner there is\n"
# 43 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "for any POKéMON TRAINER to use.\p"
# 44 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Naturally, that means you're welcome\n"
# 45 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "to use it, too.$"
# 46 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 47 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
# 48 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "POKéMON CENTERS are great!\p"
# 49 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You can use their services as much\n"
# 50 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "as you like, and it's all for free.\l"
# 51 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You never have to worry!$"
# 52 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 53 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
# 54 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "The POKéMON WIRELESS CLUB on\n"
# 55 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "the second floor was built recently.\p"
# 56 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "But they say they're still making\n"
# 57 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "adjustments.$"
# 58 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 59 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
# 60 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "The POKéMON WIRELESS CLUB on\n"
# 61 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "the second floor was built recently.\p"
# 62 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I traded POKéMON right away.$"
# 63 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 64 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 65 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 66 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
.align 2
# 67 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_Center_Item_Mart::
# 68 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_ORAN_BERRY
# 69 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_POMEG_BERRY
# 70 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 71 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 72 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 73 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 74 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 75 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_POKE_VIAL
# 76 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_ESCAPE_ROPE
# 77 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
    .2byte ITEM_NONE
# 78 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
    release
# 79 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
    end
# 80 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 81 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
.align 2
# 82 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_Center_Mon_Mart::
# 83 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LONELY_MINT
# 84 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ADAMANT_MINT
# 85 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NAUGHTY_MINT
# 86 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_BRAVE_MINT
# 87 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_BOLD_MINT
# 88 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_IMPISH_MINT
# 89 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LAX_MINT
# 90 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_RELAXED_MINT
# 91 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MODEST_MINT
# 92 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MILD_MINT
# 93 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_RASH_MINT
# 94 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_QUIET_MINT
# 95 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_CALM_MINT
# 96 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GENTLE_MINT
# 97 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_CAREFUL_MINT
# 98 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SASSY_MINT
# 99 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_TIMID_MINT
# 100 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HASTY_MINT
# 101 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_JOLLY_MINT
# 102 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NAIVE_MINT
# 103 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SERIOUS_MINT
# 104 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NONE

OldaleTown_PokemonCenter_1F_EventScript_Merchant::
# 107 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 108 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 109 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message OldaleTown_PokemonCenter_1F_EventScript_Merchant_Text_0
# 110 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 111 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart OldaleTown_Center_Item_Mart
# 112 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message OldaleTown_PokemonCenter_1F_EventScript_Merchant_Text_1
# 113 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end


OldaleTown_PokemonCenter_1F_EventScript_NatureGuy::
# 118 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 119 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 120 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message OldaleTown_PokemonCenter_1F_EventScript_Merchant_Text_0
# 121 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 122 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart OldaleTown_Center_Mon_Mart
# 123 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message OldaleTown_PokemonCenter_1F_EventScript_NatureGuy_Text_0
# 124 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end


OldaleTown_PokemonCenter_1F_EventScript_Merchant_Text_0:
# 109 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "How can I help you?$"

OldaleTown_PokemonCenter_1F_EventScript_Merchant_Text_1:
# 112 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Come again soon!$"

OldaleTown_PokemonCenter_1F_EventScript_NatureGuy_Text_0:
# 123 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I'm always here!$"
