Route46_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "Awright! I'll show you the\n"
	.string "power of mountain POKéMON!$"

Route46_Text_HikerBaileyBeaten:
	.string "Mercy! You showed me your\n"
	.string "power!$"

Route46_Text_HikerBaileyAfterBattle:
	.string "It's over. I don't mind.\n"
	.string "We HIKERS are like that.$"

Route46_Text_CamperTedSeen:
	.string "I'm raising POKéMON too!\p"
	.string "Will you battle with me?$"

Route46_Text_CamperTedBeaten:
	.string "Wha…?$"

Route46_Text_CamperTedAfterBattle:
	.string "I did my best but came up\n"
	.string "short.\p"
	.string "No excuses--I admit I lost.$"

Route46_Text_PicnickerErinSeen:
	.string "I raise POKéMON too!\p"
	.string "Will you battle with me?$"

Route46_Text_PicnickerErinBeaten:
	.string "Oh, rats!$"

Route46_Text_PicnickerErinAfterBattle:
	.string "I've been to many GYMS, but the\n"
	.string "GYM in GOLDENROD is my favorite.\p"
	.string "It's filled with pretty flowers!$"

Route46_Text_PicnickerErin2Beaten:
	.string "Aww… I keep losing all the time!\p"
	.string "I'll just have to try harder!\n"
	.string "Anyway, thanks for battling\n"
	.string "me again and again.\p"
	.string "Here's that present from the\n"
	.string "other time.$"

Route46_Text_Sign:
	.string "ROUTE 46\n"
	.string "MOUNTAIN RD. AHEAD$"
