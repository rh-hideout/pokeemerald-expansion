# 1 "data/maps/FortreeCity_Mart/scripts.pory"

# 2 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_MapScripts::
# 3 "data/maps/FortreeCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/FortreeCity_Mart/scripts.pory"

# 5 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Clerk::
# 6 "data/maps/FortreeCity_Mart/scripts.pory"
	lock
# 7 "data/maps/FortreeCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/FortreeCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/FortreeCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/FortreeCity_Mart/scripts.pory"
	pokemart FortreeCity_Mart_Pokemart
# 11 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/FortreeCity_Mart/scripts.pory"
	release
# 13 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 14 "data/maps/FortreeCity_Mart/scripts.pory"

# 15 "data/maps/FortreeCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Pokemart:
# 17 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 18 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 19 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 20 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 21 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 22 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 23 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 24 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 25 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 26 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_WOOD_MAIL
# 27 "data/maps/FortreeCity_Mart/scripts.pory"
	pokemartlistend
# 28 "data/maps/FortreeCity_Mart/scripts.pory"

# 29 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Woman::
# 30 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
# 31 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 32 "data/maps/FortreeCity_Mart/scripts.pory"

# 33 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Girl::
# 34 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
# 35 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 36 "data/maps/FortreeCity_Mart/scripts.pory"

# 37 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Boy::
# 38 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
# 39 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 40 "data/maps/FortreeCity_Mart/scripts.pory"

# 41 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_SuperRepelBetter:
# 42 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "SUPER REPEL lasts a long time,\n"
# 43 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "and it gets the job done.\p"
# 44 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "It's much better than an ordinary\n"
# 45 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "REPEL.$"
# 46 "data/maps/FortreeCity_Mart/scripts.pory"

# 47 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_StockUpOnItems:
# 48 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "I always stock up on more items than\n"
# 49 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "I'm sure I'll need.\p"
# 50 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "You never know what might happen.\n"
# 51 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Better to be safe than sorry!$"
# 52 "data/maps/FortreeCity_Mart/scripts.pory"

# 53 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_RareCandyMakesMonGrow:
# 54 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "A RARE CANDY makes a POKéMON grow\n"
# 55 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "immediately by one level.$"
