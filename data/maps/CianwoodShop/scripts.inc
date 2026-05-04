CianwoodShop_MapScripts::
	.byte 0

CianwoodShop_EventScriptMan::	
	setvar VAR_OLIVINE_CITY_STATE, 4
	giveitem ITEM_SECRET_POTION
	end

CianwoodCity_EventScript_Pharmacist::
	lock
	faceplayer
	checkitem ITEM_SECRET_POTION
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_POTION
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 4
	release
	end

CianwoodCity_EventScript_PharmacistAfter::
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
	closemessage
	release
	end


CianwoodCity_Text_PharmacistGivePotion:
	.string "Your POKéMON appear to be fine.\p"
	.string "Is something worrying you?\p"
	.string "…\p"
	.string "The LIGHTHOUSE POKéMON is in\n"
	.string "trouble?\p"
	.string "I got it!\p"
	.string "This ought to do the trick.$"

CianwoodCity_Text_ReceivedSecretpotion:
	.string "{PLAYER} received SECRET POTION.$"

CianwoodCity_Text_PharmacistDescribePotion:
	.string "My SECRET POTION is a tad too\n"
	.string "strong, so I only offer it in an\l"
	.string "emergency.$"
