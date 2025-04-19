# 1 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_MapScripts::
# 3 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
# 6 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 10 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
# 11 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 13 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 14 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 15 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 16 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins:
# 17 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PROTEIN
# 18 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CALCIUM
# 19 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IRON
# 20 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ZINC
# 21 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CARBOS
# 22 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HP_UP
# 23 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemartlistend
# 24 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 25 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
# 26 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 27 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 28 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 29 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 30 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
# 31 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 32 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 33 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 34 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 35 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 36 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters:
# 37 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SPEED
# 38 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 39 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ATTACK
# 40 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 41 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 42 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 43 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 44 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemartlistend
# 45 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 46 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
# 47 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
# 48 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 49 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 50 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
# 51 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
# 52 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 53 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 54 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_Woman::
# 55 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
# 56 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 57 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 58 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
# 59 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "For quickly toughening up POKéMON,\n"
# 60 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "items are the best.\p"
# 61 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "PROTEIN boosts ATTACK,\n"
# 62 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and CALCIUM raises SP. ATK.$"
# 63 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 64 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
# 65 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I want my POKéMON to have more\n"
# 66 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "endurance.\p"
# 67 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I'm trying to decide whether to raise\n"
# 68 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"
# 69 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 70 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
# 71 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I gave a CARBOS to my POKéMON,\n"
# 72 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and its SPEED went up.$"
