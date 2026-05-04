.set LOCALID_MINT_CLERK, 3

GoldenrodCity_FlowerShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_FlowerShop_OnTransition
	.byte 0

GoldenrodCity_FlowerShop_OnTransition::
	call_if_unset FLAG_MINTS_ENABLED, GoldenrodCity_FlowerShop_HideMintClerk
	call_if_set FLAG_MINTS_ENABLED, GoldenrodCity_FlowerShop_ShowMintClerk
	end

GoldenrodCity_FlowerShop_HideMintClerk::
	goto_if_set FLAG_SYS_GAME_CLEAR, GoldenrodCity_FlowerShop_ShowMintClerkPostgame
	setflag FLAG_MINTS_CLERK
	removeobject LOCALID_MINT_CLERK
	return

GoldenrodCity_FlowerShop_ShowMintClerkPostgame::
	clearflag FLAG_MINTS_CLERK
	addobject LOCALID_MINT_CLERK
	end

GoldenrodCity_FlowerShop_ShowMintClerk::
	clearflag FLAG_MINTS_CLERK
	addobject LOCALID_MINT_CLERK
	return

GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_Floria:
	.string "When I told my sis about the jiggly\n"
	.string "tree, she said it's dangerous.\p"
	.string "If I beat WHITNEY, I wonder if\n"
	.string "she'll lend me her water bottle…$"

GoldenrodCity_FlowerShop_Text_Owner1:
.string "Apparently, there is an odd tree\n"
.string "on ROUTE 36.\p"
.string "They say it dances when you water\n"
.string "it...\p"
.string "Oh, of course not!\p"
.string "This is a flower shop, so we do\n"
.string "have watering cans...\p"
.string "But I cannot let you have one!\n"
.string "It's too dangerous!\p"
.string "Well, maybe if you manage to\n"
.string "defeat gym leader WHITNEY, it\l"
.string "might be okay.$"

GoldenrodCity_FlowerShop_Text_Owner2:
.string "Apparently, there is an odd tree\n"
.string "on ROUTE 36.\p"
.string "They say it dances when you water\n"
.string "it...\p"
.string "Oh, that's a PLAINBADGE from\n"
.string "The GOLDENROD GYM!\p"
.string "Did you defeat WHITNEY?!\p"
.string "Well, then there's nothing to worry\n"
.string "about, is there?\p"
.string "I'll let you use this SQUIRTBOTTLE\n"
.string "for a while then.\l"
.string "...\p"
.string "Oh, never mind. Keep it!$"

GoldenrodCity_FlowerShop_Text_Owner3:
.string "The odd tree is on ROUTE 36.\n"
.string "Please be careful!$"

GoldenrodCity_FlowerShop_Text_Owner4:
    .string "Lalala lalalala. Have plenty of\n"
    .string "water, my lovely!$"

GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
    .string "Wow, you beat WHITNEY? Cool!$"

GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
    .string "So it really was a POKéMON!$"
