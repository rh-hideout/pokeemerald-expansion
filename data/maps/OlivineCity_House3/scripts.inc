OlivineCity_House3_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "OLIVINE is on the sea!\p"
	.string "And if it's on the sea, there\n"
	.string "are bound to be fish!\p"
	.string "I've fished here for 30 years.\p"
	.string "Would you like to face the sea\n"
	.string "and try your hand at fishing?$"

OlivineCity_Text_GiveGoodRod:
	.string "Ah, hahah! We have ourselves\n"
	.string "a new angler in the making!$"

OlivineCity_Text_GaveGoodRod:
	.string "Fish aren't only found in the\n"
	.string "sea--they're wherever there's\l"
	.string "water.\p"
	.string "By the way, your POKéDEX shows\n"
	.string "fishing groups for POKéMON.\p"
	.string "Different spots may contain\n"
	.string "similar fish types.$"

OlivineCity_Text_DontWantGoodRod:
	.string "Whaaat? You don't like to fish!?\n"
	.string "That's incomprehensible!$"

OlivineCity_Text_HaveGoodRod:
	.string "How are things?\n"
	.string "Did you land the big one?$"
