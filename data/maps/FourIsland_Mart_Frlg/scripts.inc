FourIsland_Mart_Frlg_MapScripts::
	.byte 0

FourIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FourIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
FourIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FourIsland_Mart_EventScript_Camper::
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
	end

FourIsland_Mart_Text_LoreleiGrewUpOnThisIsland::
	.string "We've had a great and powerful\n"
	.string "[Trainer] grow up on this island.\p"
	.string "I bet even you'd know her.\n"
	.string "It's [Lorelei] of the [Elite Four]!\p"
	.string "When [Lorelei] was just a tyke,\n"
	.string "I taught her about [Pokémon].$"

FourIsland_Mart_Text_IcefallCaveIsFrigid::
	.string "The [Sevii Islands] are in a warm\n"
	.string "region overall.\p"
	.string "But there is one exception you\n"
	.string "need to know about.\p"
	.string "The [Icefall Cave] is frigid because\n"
	.string "of the [Pokémon] that live in it.$"
