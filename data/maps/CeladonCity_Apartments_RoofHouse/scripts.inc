CeladonCity_Apartments_RoofHouse_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_REST, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_REST
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "Let me recount a terrifying tale…$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "Then again, it's not as scary\n"
	.string "while it's still light outside.\p"
	.string "Come back after sunset, OK?$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "Once upon a time, there was a\n"
	.string "little boy who was given a new\l"
	.string "BICYCLE…\p"
	.string "He wanted to try it right away…\p"
	.string "He was having so much fun that\n"
	.string "he didn't notice the sun had set…\p"
	.string "While riding home in the pitch-\n"
	.string "black night, the bike suddenly\l"
	.string "slowed!\p"
	.string "The pedals became heavy!\p"
	.string "When he stopped pedaling, the\n"
	.string "bike began slipping backwards!\p"
	.string "It was as if the bike were cursed\n"
	.string "and trying to drag him into\l"
	.string "oblivion!\p"
	.string "…\p"
	.string "…\p"
	.string "SHRIEEEEK!\p"
	.string "The boy had been riding uphill on\n"
	.string "CYCLING ROAD!\p"
	.string "…\n"
	.string "Ba-dum ba-dum!\p"
	.string "For listening so patiently, you\n"
	.string "may take this--TM44!$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "TM44 is REST.\p"
	.string "It will allow your POKéMON to nap\n"
	.string "mid-battle and regain health.\p"
	.string "But good luck sleeping after that\n"
	.string "terrifying tale!$"

