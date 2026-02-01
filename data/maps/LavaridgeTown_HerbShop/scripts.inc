LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_Clerk2::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToMintShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart2:
	.2byte  ITEM_ADAMANT_MINT
	.2byte  ITEM_MODEST_MINT 
	.2byte  ITEM_TIMID_MINT 
	.2byte  ITEM_JOLLY_MINT 
	.2byte  ITEM_BOLD_MINT 
	.2byte  ITEM_IMPISH_MINT 
	.2byte  ITEM_CALM_MINT 
	.2byte  ITEM_CAREFUL_MINT 
	.2byte  ITEM_LONELY_MINT 
	.2byte  ITEM_BRAVE_MINT 
	.2byte  ITEM_RELAXED_MINT 
	.2byte  ITEM_MILD_MINT 
	.2byte  ITEM_RASH_MINT 
	.2byte  ITEM_QUIET_MINT 
	.2byte  ITEM_SASSY_MINT 
	.2byte  ITEM_NAUGHTY_MINT 
	.2byte  ITEM_HASTY_MINT 
	.2byte  ITEM_NAIVE_MINT 
	.2byte  ITEM_LAX_MINT 
	.2byte  ITEM_GENTLE_MINT 
	.2byte  ITEM_SERIOUS_MINT


 
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Welcome to the HERB SHOP, home of\n"
	.string "effective and inexpensive medicine!$"

LavaridgeTown_HerbShop_Text_WelcomeToMintShop:
	.string "Welcome to the HERB SHOP, home of\n"
	.string "healthy, tasty herbal mints!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "You've come to look at herbal medicine\n"
	.string "in LAVARIDGE?\p"
	.string "That's rather commendable.\p"
	.string "I like you! Take this!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "That CHARCOAL I gave you, it's used\n"
	.string "for making herbal medicine.\p"
	.string "It also does wonders when held by\n"
	.string "a POKéMON.\p"
	.string "It intensifies the power of FIRE-type\n"
	.string "moves.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Herbal medicine works impressively well.\n"
	.string "But your POKéMON will dislike you for it.\l"
	.string "It must be horribly bitter!$"

