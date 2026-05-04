Route43_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
    .string "I love POKéMON!\p"
    .string "That's why I started--and why I'll\n"
    .string "keep on collecting POKéMON!$"

Route43_Text_PokemaniacBenBeaten:
    .string "How could you do this to me?$"

Route43_Text_PokemaniacBenAfter:
    .string "What else do I like besides\n"
    .string "POKéMON?\p"
    .string "MARY on the radio. I bet she's\n"
    .string "cute!$"

Route43_Text_PokemaniacBrentSeen:
    .string "Hey! Do you have any rare\n"
    .string "POKéMON?$"

Route43_Text_PokemaniacBrentBeaten:
    .string "Oh, my poor POKéMON! Darlings!$"

Route43_Text_PokemaniacBrentAfter:
    .string "I'd be happy just to own a single\n"
    .string "rare POKéMON.$"

Route43_Text_PokemaniacRonSeen:
    .string "Would you get this?\p"
    .string "Some {RIVAL} guy made fun of my\n"
    .string "POKéMON!\p"
    .string "Darn it! My POKéMON's great!$"

Route43_Text_PokemaniacRonBeaten:
    .string "My NIDOKING did pretty right on!$"

Route43_Text_PokemaniacRonAfter:
    .string "It's okay for people to like\n"
    .string "different types of POKéMON.\p"
    .string "POKéMON isn't just about having the\n"
    .string "most powerful one.$"

Route43_Text_FisherMarvinSeen:
    .string "I'm in a slump.\p"
    .string "Maybe it's the gear I'm using.\p"
    .string "Let's battle for a change of pace!$"

Route43_Text_FisherMarvinBeaten:
    .string "I lost, but I feel better anyway.$"

Route43_Text_FisherMarvinAfter:
    .string "KURT's LURE BALL is the best for\n"
    .string "catching hooked POKéMON.\p"
    .string "It's much more effective than a\n"
    .string "ULTRA BALL.$"

Route43_Text_CamperSpencerSeen:
    .string "I can do so much with my\n"
    .string "POKéMON--it's super-fun!$"

Route43_Text_CamperSpencerBeaten:
    .string "Losing isn't fun at all…$"

Route43_Text_CamperSpencerAfter:
    .string "What is going on at LAKE OF RAGE?\p"
    .string "We were planning to camp there.$"

Route43_Text_PicnickerTiffanySeen:
    .string "Are you going to LAKE OF RAGE too?\p"
    .string "Let's play for a little while!$"

Route43_Text_PicnickerTiffanyBeaten:
    .string "I played too much!$"

Route43_Text_PicnickerTiffanyWantsPicnic:
    .string "I'm having a picnic with POKéMON.\p"
    .string "Won't you join us?$"

Route43_Sign1:
    .string "ROUTE 43\p"
    .string "LAKE OF RAGE - MAHOGANY TOWN$"

Route43_Sign2:
    .string "ROUTE 43\p"
    .string "LAKE OF RAGE - MAHOGANY TOWN$"

Route43_TrainerTips:
    .string "TRAINER TIPS\p"
    .string "All POKéMON have pros and cons\n"
    .string "depending on their types.\p"
    .string "If their types differ, a higher-\n"
    .string "level POKéMON may lose in battle.\p"
    .string "Learn which types are strong and\n"
    .string "weak against your POKéMON's type.$"
