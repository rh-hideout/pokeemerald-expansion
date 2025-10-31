# 1 "data/maps/MossdeepCity_Mart/scripts.pory"

# 2 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_MapScripts::
# 3 "data/maps/MossdeepCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/MossdeepCity_Mart/scripts.pory"

# 5 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_EventScript_Clerk::
# 6 "data/maps/MossdeepCity_Mart/scripts.pory"
	lock
# 7 "data/maps/MossdeepCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/MossdeepCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/MossdeepCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/MossdeepCity_Mart/scripts.pory"
	pokemart MossdeepCity_Mart_Pokemart
# 11 "data/maps/MossdeepCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/MossdeepCity_Mart/scripts.pory"
	release
# 13 "data/maps/MossdeepCity_Mart/scripts.pory"
	end
# 14 "data/maps/MossdeepCity_Mart/scripts.pory"

# 15 "data/maps/MossdeepCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_Pokemart:
# 17 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 18 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_NET_BALL
# 19 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 20 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 21 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 22 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 23 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 24 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 25 "data/maps/MossdeepCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 26 "data/maps/MossdeepCity_Mart/scripts.pory"
	pokemartlistend
# 27 "data/maps/MossdeepCity_Mart/scripts.pory"

# 28 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_EventScript_Woman::
# 29 "data/maps/MossdeepCity_Mart/scripts.pory"
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
# 30 "data/maps/MossdeepCity_Mart/scripts.pory"
	end
# 31 "data/maps/MossdeepCity_Mart/scripts.pory"

# 32 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_EventScript_Boy::
# 33 "data/maps/MossdeepCity_Mart/scripts.pory"
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
# 34 "data/maps/MossdeepCity_Mart/scripts.pory"
	end
# 35 "data/maps/MossdeepCity_Mart/scripts.pory"

# 36 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_EventScript_Sailor::
# 37 "data/maps/MossdeepCity_Mart/scripts.pory"
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
# 38 "data/maps/MossdeepCity_Mart/scripts.pory"
	end
# 39 "data/maps/MossdeepCity_Mart/scripts.pory"

# 40 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_Text_ReviveIsFantastic:
# 41 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "REVIVE is fantastic!\p"
# 42 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "Give it to a fainted POKéMON,\n"
# 43 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "and the POKéMON will arise.\p"
# 44 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "But be careful, REVIVE doesn't restore\n"
# 45 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "the used-up PP of moves.$"
# 46 "data/maps/MossdeepCity_Mart/scripts.pory"

# 47 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_Text_MaxRepelLastsLongest:
# 48 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "MAX REPEL keeps all weak POKéMON away.\p"
# 49 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "Out of all the REPEL sprays, it lasts\n"
# 50 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "the longest.$"
# 51 "data/maps/MossdeepCity_Mart/scripts.pory"

# 52 "data/maps/MossdeepCity_Mart/scripts.pory"
MossdeepCity_Mart_Text_NetAndDiveBallsRare:
# 53 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "The NET and DIVE BALLS are rare POKé\n"
# 54 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "BALLS that are only made in MOSSDEEP.\p"
# 55 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "A NET BALL is effective against\n"
# 56 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "BUG-type and WATER-type POKéMON.\p"
# 57 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "A DIVE BALL works best on POKéMON\n"
# 58 "data/maps/MossdeepCity_Mart/scripts.pory"
	.string "at the bottom of the sea.$"
