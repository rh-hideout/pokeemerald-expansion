Route1_Frlg_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Route1_Text_PutPotionAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_WorkAtPokeMartTakeSample::
	.string "Hi!\n"
	.string "I work at a [Pokémon Mart].\p"
	.string "It's part of a convenient chain\n"
	.string "selling all sorts of items.\p"
	.string "Please, visit us in [Viridian City].\p"
	.string "I know, I'll give you a sample.\n"
	.string "Here you go!$"

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
	.string "Please come see us if you need\n"
	.string "[Poké Balls] for catching [Pokémon].$"

Route1_Text_PutPotionAway::
	.string "{PLAYER} put the [Potion] away in\n"
	.string "the [Bag]'s [Items Pocket].$"

Route1_Text_CanJumpFromLedges::
	.string "See those ledges along the road?\p"
	.string "It's a bit scary, but you can jump\n"
	.string "from them.\p"
	.string "You can get back to [Pallet Town]\n"
	.string "quicker that way.$"

Route1_Text_RouteSign::
	.string "[Route 1]\n"
	.string "[Pallet Town] - [Viridian City]$"
