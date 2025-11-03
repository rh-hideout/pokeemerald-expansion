# 1 "data/maps/BattleFrontier_Mart/scripts.pory"

# 2 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_MapScripts::
# 3 "data/maps/BattleFrontier_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Mart/scripts.pory"

# 5 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_Clerk::
# 6 "data/maps/BattleFrontier_Mart/scripts.pory"
	lock
# 7 "data/maps/BattleFrontier_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/BattleFrontier_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/BattleFrontier_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/BattleFrontier_Mart/scripts.pory"
	pokemart BattleFrontier_Mart_Pokemart
# 11 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/BattleFrontier_Mart/scripts.pory"
	release
# 13 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 14 "data/maps/BattleFrontier_Mart/scripts.pory"

# 15 "data/maps/BattleFrontier_Mart/scripts.pory"
	.align 2
# 16 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Pokemart:
# 17 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 18 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 19 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_MAX_POTION
# 20 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 21 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 22 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 23 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 24 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_PROTEIN
# 25 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_CALCIUM
# 26 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_IRON
# 27 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_ZINC
# 28 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_CARBOS
# 29 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_HP_UP
# 30 "data/maps/BattleFrontier_Mart/scripts.pory"
	pokemartlistend
# 31 "data/maps/BattleFrontier_Mart/scripts.pory"

# 32 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_OldMan::
# 33 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
# 34 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 35 "data/maps/BattleFrontier_Mart/scripts.pory"

# 36 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_OldWoman::
# 37 "data/maps/BattleFrontier_Mart/scripts.pory"
	lock
# 38 "data/maps/BattleFrontier_Mart/scripts.pory"
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
# 39 "data/maps/BattleFrontier_Mart/scripts.pory"
	waitmovement 0
# 40 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
# 41 "data/maps/BattleFrontier_Mart/scripts.pory"
	release
# 42 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 43 "data/maps/BattleFrontier_Mart/scripts.pory"

# 44 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_Boy::
# 45 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
# 46 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 47 "data/maps/BattleFrontier_Mart/scripts.pory"

# 48 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_ChaperonGrandson:
# 49 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "We came here to chaperon our\n"
# 50 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "grandson.\p"
# 51 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "But since we're here, we thought\n"
# 52 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "we should get some souvenirs.$"
# 53 "data/maps/BattleFrontier_Mart/scripts.pory"

# 54 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_ProteinMakeNiceGift:
# 55 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "Dear, what do you think of this?\n"
# 56 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "Wouldn't this make a nice gift?\p"
# 57 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "It's…PRO…TE…IN?\n"
# 58 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "It sounds delicious, doesn't it?$"
# 59 "data/maps/BattleFrontier_Mart/scripts.pory"

# 60 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
# 61 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "A lot of the BATTLE FRONTIER's\n"
# 62 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "facilities don't allow the use of items\l"
# 63 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "during battles.\p"
# 64 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "That rule makes things tougher than\n"
# 65 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "they already are!$"
