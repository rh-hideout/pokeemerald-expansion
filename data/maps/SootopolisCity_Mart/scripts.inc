# 1 "data/maps/SootopolisCity_Mart/scripts.pory"

# 2 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_MapScripts::
# 3 "data/maps/SootopolisCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_Mart/scripts.pory"

# 5 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_Clerk::
# 6 "data/maps/SootopolisCity_Mart/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/SootopolisCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/SootopolisCity_Mart/scripts.pory"
	pokemart SootopolisCity_Mart_Pokemart
# 11 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 13 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 14 "data/maps/SootopolisCity_Mart/scripts.pory"

# 15 "data/maps/SootopolisCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Pokemart:
# 17 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 18 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 19 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_MAX_POTION
# 20 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 21 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 22 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 23 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 24 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 25 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_SHADOW_MAIL
# 26 "data/maps/SootopolisCity_Mart/scripts.pory"
	pokemartlistend
# 27 "data/maps/SootopolisCity_Mart/scripts.pory"

# 28 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_FatMan::
# 29 "data/maps/SootopolisCity_Mart/scripts.pory"
	lock
# 30 "data/maps/SootopolisCity_Mart/scripts.pory"
	faceplayer
# 31 "data/maps/SootopolisCity_Mart/scripts.pory"
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_FatManNoLegendaries
# 32 "data/maps/SootopolisCity_Mart/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_FatManNoLegendaries
# 33 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox SootopolisCity_Mart_Text_TooScaryOutside, MSGBOX_DEFAULT
# 34 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 35 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 36 "data/maps/SootopolisCity_Mart/scripts.pory"

# 37 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_FatManNoLegendaries::
# 38 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox SootopolisCity_Mart_Text_PPUpIsGreat, MSGBOX_DEFAULT
# 39 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 40 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 41 "data/maps/SootopolisCity_Mart/scripts.pory"

# 42 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_Gentleman::
# 43 "data/maps/SootopolisCity_Mart/scripts.pory"
	lock
# 44 "data/maps/SootopolisCity_Mart/scripts.pory"
	faceplayer
# 45 "data/maps/SootopolisCity_Mart/scripts.pory"
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
# 46 "data/maps/SootopolisCity_Mart/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
# 47 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox SootopolisCity_Mart_Text_DidSomethingAwaken, MSGBOX_DEFAULT
# 48 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 49 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 50 "data/maps/SootopolisCity_Mart/scripts.pory"

# 51 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_GentlemanNoLegendaries::
# 52 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox SootopolisCity_Mart_Text_FullRestoreItemOfDreams, MSGBOX_DEFAULT
# 53 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 54 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 55 "data/maps/SootopolisCity_Mart/scripts.pory"

# 56 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Text_PPUpIsGreat:
# 57 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "PP UP is great!\p"
# 58 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "It raises the POWER POINTS, the PP,\n"
# 59 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "of a POKéMON move.$"
# 60 "data/maps/SootopolisCity_Mart/scripts.pory"

# 61 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Text_TooScaryOutside:
# 62 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "What…\n"
# 63 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "What is happening?\p"
# 64 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "I really want to know, but it's too\n"
# 65 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "scary to go outside.$"
# 66 "data/maps/SootopolisCity_Mart/scripts.pory"

# 67 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Text_FullRestoreItemOfDreams:
# 68 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "Do you know FULL RESTORE?\p"
# 69 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "Full restoration of HP!\n"
# 70 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "Eradication of all status problems!\p"
# 71 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "It's truly an item of your dreams!$"
# 72 "data/maps/SootopolisCity_Mart/scripts.pory"

# 73 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Text_DidSomethingAwaken:
# 74 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "This weather…\n"
# 75 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "Did something awaken?$"
