# 1 "data/maps/RustboroCity_Mart/scripts.pory"

# 2 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_MapScripts::
# 3 "data/maps/RustboroCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Mart/scripts.pory"

# 5 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_Clerk::
# 6 "data/maps/RustboroCity_Mart/scripts.pory"
	lock
# 7 "data/maps/RustboroCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/RustboroCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/RustboroCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/RustboroCity_Mart/scripts.pory"
	goto_if_unset FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartBasic
# 11 "data/maps/RustboroCity_Mart/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartExpanded
# 12 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 13 "data/maps/RustboroCity_Mart/scripts.pory"

# 14 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_PokemartBasic::
# 15 "data/maps/RustboroCity_Mart/scripts.pory"
	pokemart RustboroCity_Mart_Pokemart_Basic
# 16 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 17 "data/maps/RustboroCity_Mart/scripts.pory"
	release
# 18 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 19 "data/maps/RustboroCity_Mart/scripts.pory"

# 20 "data/maps/RustboroCity_Mart/scripts.pory"
	.align 2
# 21 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Pokemart_Basic:
# 22 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 23 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 24 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 25 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 26 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 27 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 28 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 29 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 30 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 31 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 32 "data/maps/RustboroCity_Mart/scripts.pory"
	pokemartlistend
# 33 "data/maps/RustboroCity_Mart/scripts.pory"

# 34 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_PokemartExpanded::
# 35 "data/maps/RustboroCity_Mart/scripts.pory"
	pokemart RustboroCity_Mart_Pokemart_Expanded
# 36 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 37 "data/maps/RustboroCity_Mart/scripts.pory"
	release
# 38 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 39 "data/maps/RustboroCity_Mart/scripts.pory"

# 40 "data/maps/RustboroCity_Mart/scripts.pory"
	.align 2
# 41 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Pokemart_Expanded:
# 42 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 43 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 44 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 45 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 46 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 47 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 48 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 49 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 50 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 51 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 52 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 53 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 54 "data/maps/RustboroCity_Mart/scripts.pory"
	pokemartlistend
# 55 "data/maps/RustboroCity_Mart/scripts.pory"

# 56 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_PokefanF::
# 57 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
# 58 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 59 "data/maps/RustboroCity_Mart/scripts.pory"

# 60 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_Boy::
# 61 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
# 62 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 63 "data/maps/RustboroCity_Mart/scripts.pory"

# 64 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_BugCatcher::
# 65 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
# 66 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 67 "data/maps/RustboroCity_Mart/scripts.pory"

# 68 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish:
# 69 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I'm buying some PARLYZ HEALS and\n"
# 70 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "ANTIDOTES.\p"
# 71 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "Just in case I run into SHROOMISH\n"
# 72 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "in PETALBURG WOODS.$"
# 73 "data/maps/RustboroCity_Mart/scripts.pory"

# 74 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead:
# 75 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "My POKéMON evolved.\n"
# 76 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "It has a lot of HP now.\p"
# 77 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I should buy SUPER POTIONS for it\n"
# 78 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "instead of ordinary POTIONS.$"
# 79 "data/maps/RustboroCity_Mart/scripts.pory"

# 80 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_GettingEscapeRopeJustInCase:
# 81 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I'm getting an ESCAPE ROPE just in\n"
# 82 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "case I get lost in a cave.\p"
# 83 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I just need to use it to get back to\n"
# 84 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "the entrance.$"
