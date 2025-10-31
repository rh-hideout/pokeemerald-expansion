SouthCampus_Mart_MapScripts::
	.byte 0


SouthCampus_Mart_Clerk::
# 7 "data/maps/SouthCampus_Mart/scripts.pory"
	lock
# 8 "data/maps/SouthCampus_Mart/scripts.pory"
	faceplayer
# 9 "data/maps/SouthCampus_Mart/scripts.pory"
	msgbox SouthCampus_Mart_Clerk_Text_0
# 10 "data/maps/SouthCampus_Mart/scripts.pory"
	waitmessage
# 11 "data/maps/SouthCampus_Mart/scripts.pory"
	pokemart MyMartItems
# 12 "data/maps/SouthCampus_Mart/scripts.pory"
	msgbox SouthCampus_Mart_Clerk_Text_1
# 13 "data/maps/SouthCampus_Mart/scripts.pory"
	release
	end


	.align 2
# 17 "data/maps/SouthCampus_Mart/scripts.pory"
MyMartItems:
# 18 "data/maps/SouthCampus_Mart/scripts.pory"
	.2byte ITEM_POTION
# 19 "data/maps/SouthCampus_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 20 "data/maps/SouthCampus_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_NONE

SouthCampus_Mart_Clerk_Text_0:
# 9 "data/maps/SouthCampus_Mart/scripts.pory"
	.string "Welcome!\nHow may I serve you?$"

SouthCampus_Mart_Clerk_Text_1:
# 12 "data/maps/SouthCampus_Mart/scripts.pory"
	.string "Please come again.$"
