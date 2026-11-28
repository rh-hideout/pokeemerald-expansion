BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	pokemartdecoration BattleFrontier_ExchangeServiceCorner_Mart_Decor1, MART_CURRENCY_BATTLE_POINTS, MART_MENU_BUY_ONLY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

	.align 2
BattleFrontier_ExchangeServiceCorner_Mart_Decor1:
	martinlineprices
	martitem DECOR_KISS_POSTER,     16
	martitem DECOR_KISS_CUSHION,    32
	martitem DECOR_SMOOCHUM_DOLL,   32
	martitem DECOR_TOGEPI_DOLL,     48
	martitem DECOR_MEOWTH_DOLL,     48
	martitem DECOR_CLEFAIRY_DOLL,   48
	martitem DECOR_DITTO_DOLL,      48
	martitem DECOR_CHIKORITA_DOLL,  80
	martitem DECOR_CYNDAQUIL_DOLL,  80
	martitem DECOR_TOTODILE_DOLL,   80
	martlistend

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	pokemartdecoration BattleFrontier_ExchangeServiceCorner_Mart_Decor2, MART_CURRENCY_BATTLE_POINTS, MART_MENU_BUY_ONLY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

	.align 2
BattleFrontier_ExchangeServiceCorner_Mart_Decor2:
	martinlineprices
	martitem DECOR_LAPRAS_DOLL,     128
	martitem DECOR_SNORLAX_DOLL,    128
	martitem DECOR_VENUSAUR_DOLL,   256
	martitem DECOR_CHARIZARD_DOLL,  256
	martitem DECOR_BLASTOISE_DOLL,  256
	martlistend

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	pokemart BattleFrontier_ExchangeServiceCorner_Mart_Vitamins, MART_CURRENCY_BATTLE_POINTS, MART_MENU_BUY_ONLY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

	.align 2
BattleFrontier_ExchangeServiceCorner_Mart_Vitamins:
	martinlineprices
	martitem ITEM_PROTEIN,  1
	martitem ITEM_CALCIUM,  1
	martitem ITEM_IRON,     1
	martitem ITEM_ZINC,     1
	martitem ITEM_CARBOS,   1
	martitem ITEM_HP_UP,    1
	martlistend

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	pokemart BattleFrontier_ExchangeServiceCorner_Mart_HoldItems, MART_CURRENCY_BATTLE_POINTS, MART_MENU_BUY_ONLY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

	.align 2
BattleFrontier_ExchangeServiceCorner_Mart_HoldItems:
	martinlineprices
	martitem ITEM_LEFTOVERS,      48
	martitem ITEM_WHITE_HERB,     48
	martitem ITEM_QUICK_CLAW,     48
	martitem ITEM_MENTAL_HERB,    48
	martitem ITEM_BRIGHT_POWDER,  64
	martitem ITEM_CHOICE_BAND,    64
	martitem ITEM_KINGS_ROCK,     64
	martitem ITEM_FOCUS_BAND,     64
	martitem ITEM_SCOPE_LENS,     64
	martlistend

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"
