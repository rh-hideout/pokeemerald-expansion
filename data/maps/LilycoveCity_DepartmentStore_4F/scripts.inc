# 1 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_MapScripts::
# 3 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
# 6 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
# 7 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	end
# 8 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 9 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_EventScript_Woman::
# 10 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
# 11 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	end
# 12 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 13 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
# 14 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
# 15 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	end
# 16 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 17 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
# 18 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	lock
# 19 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	faceplayer
# 20 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	message gText_HowMayIServeYou
# 21 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	waitmessage
# 22 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
# 23 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 24 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	release
# 25 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	end
# 26 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 27 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.align 2
# 28 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
# 29 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.2byte ITEM_TM_FIRE_BLAST
# 30 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.2byte ITEM_TM_THUNDER
# 31 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.2byte ITEM_TM_BLIZZARD
# 32 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.2byte ITEM_TM_HYPER_BEAM
# 33 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	pokemartlistend
# 34 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 35 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
# 36 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	lock
# 37 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	faceplayer
# 38 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	message gText_HowMayIServeYou
# 39 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	waitmessage
# 40 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
# 41 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 42 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	release
# 43 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	end
# 44 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 45 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.align 2
# 46 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
# 47 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.2byte ITEM_TM_PROTECT
# 48 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.2byte ITEM_TM_SAFEGUARD
# 49 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.2byte ITEM_TM_REFLECT
# 50 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.2byte ITEM_TM_LIGHT_SCREEN
# 51 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	pokemartlistend
# 52 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 53 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
# 54 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "Hmm…\p"
# 55 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "An attacking move…\n"
# 56 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "Or a defensive move…\p"
# 57 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "It's no easy matter to decide which TM\n"
# 58 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "moves should be taught to POKéMON…$"
# 59 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 60 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
# 61 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "There are so many different kinds of\n"
# 62 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "TM moves.\p"
# 63 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "A catalog I read said there are fifty\n"
# 64 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "different kinds.$"
# 65 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"

# 66 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
# 67 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "I'd like to get all the different TMs,\n"
# 68 "data/maps/LilycoveCity_DepartmentStore_4F/scripts.pory"
	.string "but a POKéMON learns only four moves.$"
