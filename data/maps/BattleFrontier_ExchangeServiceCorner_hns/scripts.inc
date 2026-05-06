BattleFrontier_ExchangeServiceCorner_hns_MapScripts::
	.byte 0


BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints_hns, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize_hns::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize_hns
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints_hns, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1_hns
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2_hns
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize_hns::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor_hns
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor_hns::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor_hns
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC_hns, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull_hns, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem_hns::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull_hns
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize_hns, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt_hns, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1_hns::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster_hns
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion_hns
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll_hns
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll_hns
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll_hns
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll_hns
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll_hns
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll_hns
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll_hns
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll_hns
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster_hns::
	setitemandprice DECOR_KISS_POSTER, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion_hns::
	setitemandprice DECOR_KISS_CUSHION, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll_hns::
	setitemandprice DECOR_SMOOCHUM_DOLL, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll_hns::
	setitemandprice DECOR_TOGEPI_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll_hns::
	setitemandprice DECOR_MEOWTH_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll_hns::
	setitemandprice DECOR_CLEFAIRY_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll_hns::
	setitemandprice DECOR_DITTO_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll_hns::
	setitemandprice DECOR_CYNDAQUIL_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll_hns::
	setitemandprice DECOR_CHIKORITA_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll_hns::
	setitemandprice DECOR_TOTODILE_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1_hns

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2_hns::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll_hns
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll_hns
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll_hns
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll_hns
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll_hns
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2_hns::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll_hns::
	setitemandprice DECOR_LAPRAS_DOLL, 128
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2_hns

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll_hns::
	setitemandprice DECOR_SNORLAX_DOLL, 128
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2_hns

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll_hns::
	setitemandprice DECOR_VENUSAUR_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2_hns

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll_hns::
	setitemandprice DECOR_CHARIZARD_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2_hns

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll_hns::
	setitemandprice DECOR_BLASTOISE_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2_hns

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin_hns::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein_hns
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium_hns
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron_hns
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc_hns
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos_hns
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp_hns
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin_hns::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein_hns::
	setitemandprice ITEM_PROTEIN, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin_hns

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium_hns::
	setitemandprice ITEM_CALCIUM, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin_hns

BattleFrontier_ExchangeServiceCorner_EventScript_Iron_hns::
	setitemandprice ITEM_IRON, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin_hns

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc_hns::
	setitemandprice ITEM_ZINC, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin_hns

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos_hns::
	setitemandprice ITEM_CARBOS, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin_hns

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp_hns::
	setitemandprice ITEM_HP_UP, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin_hns


BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem_hns::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers_hns
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb_hns
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw_hns
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb_hns
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder_hns
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand_hns
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock_hns
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand_hns
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens_hns
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem_hns
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize_hns
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers_hns::
	setitemandprice ITEM_LEFTOVERS, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb_hns::
	setitemandprice ITEM_WHITE_HERB, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw_hns::
	setitemandprice ITEM_QUICK_CLAW, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb_hns::
	setitemandprice ITEM_MENTAL_HERB, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder_hns::
	setitemandprice ITEM_BRIGHT_POWDER, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand_hns::
	setitemandprice ITEM_CHOICE_BAND, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock_hns::
	setitemandprice ITEM_KINGS_ROCK, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand_hns::
	setitemandprice ITEM_FOCUS_BAND, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens_hns::
	setitemandprice ITEM_SCOPE_LENS, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem_hns

BattleFrontier_ExchangeServiceCorner_EventScript_Man_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF_hns::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize_hns:
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase_hns:
	.string "You've chosen the {STR_VAR_1}.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC_hns:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize_hns:
	.string "Here is your prize!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints_hns:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull_hns:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt_hns:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints_hns:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns:
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc_hns::
	.string "A large poster with a SMOOCHUM print.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc_hns::
	.string "A SMOOCHUM cushion.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc_hns::
	.string "A SMOOCHUM DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc_hns::
	.string "A TOGEPI DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc_hns::
	.string "A MEOWTH DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc_hns::
	.string "A CLEFAIRY DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc_hns::
	.string "A DITTO DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc_hns::
	.string "A CYNDAQUIL DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc_hns::
	.string "A CHIKORITA DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc_hns::
	.string "A TOTODILE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc_hns::
	.string "A large DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc_hns::
	.string "Raises the stat ATTACK of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc_hns::
	.string "Raises the stat SP. ATK of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc_hns::
	.string "Raises the stat DEFENSE of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc_hns::
	.string "Raises the stat SP. DEF of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc_hns::
	.string "Raises the stat SPEED of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc_hns::
	.string "Raises the HP of one POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc_hns::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc_hns::
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc_hns::
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc_hns::
	.string "A hold item that snaps POKéMON out\n"
	.string "of infatuation.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc_hns::
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc_hns::
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc_hns::
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc_hns::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc_hns::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"
