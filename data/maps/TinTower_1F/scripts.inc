TinTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "According to legend…\n"
	.string "When the souls of POKéMON and humans\p"
	.string "commune, from the heavens descends a\n"
	.string "POKéMON of rainbow colors…\p"
	.string "Could it mean the legendary POKéMON\n"
	.string "are testing us humans?$"

TinTower_1F_Sage2_Text:
	.string "When the BRASS TOWER burned down,\n"
	.string "three nameless POKéMON were said\l"
	.string "to have perished. It was tragic.\p"
	.string "However…\p"
	.string "A rainbow-colored POKéMON…\n"
	.string "In other words…\p"
	.string "HO-OH descended from the sky and\n"
	.string "gave new life to the three POKéMON.\p"
	.string "They are…\n"
	.string "SUICUNE, ENTEI and RAIKOU.\p"
	.string "That is what they say.$"

TinTower_1F_Sage3_Text:
	.string "The two TOWERS are said to have been\n"
	.string "built to foster friendship and\p"
	.string "hope between POKéMON and people.\n"
	.string "That was 700 years ago, but the ideal\p"
	.string "still remains important today.$"

TinTower_1F_Sage4_Text1:
	.string "HO-OH appears to have descended\n"
	.string "upon this, the TIN TOWER!$"

TinTower_1F_Sage4_Text2:
	.string "The legendary POKéMON are said\n"
	.string "to embody three powers…\p"
	.string "The lightning that struck the TOWER.\n"
	.string "The fire that burned the TOWER.\p"
	.string "And the rain that put out the fire…$"

TinTower_1F_Sage6_Text2:
	.string "Of the legendary POKéMON, SUICUNE\n"
	.string "is said to be the closest to HO-OH.\p"
	.string "I hear there may also be a link to\n"
	.string "POKéMON known as UNOWN.\p"
	.string "The POKéMON UNOWN must be sharing a\n"
	.string "cooperative bond with SUICUNE.$"

TinTower_1F_EusineHoOh_Text:
	.string "I knew it.\p"
	.string "I knew you'd get to see the POKéMON\n"
	.string "of rainbow colors, <PLAYER>.\p"
	.string "It happened just as I envisioned.\n"
	.string "My research isn't bad, I might say.\p"
	.string "I'm going to keep studying POKéMON\n"
	.string "to become a famous POKéMANIAC!$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE: Awesome! Too awesome, even!\n"
	.string "I've never seen a battle that great.\p"
	.string "That was truly inspiring to see.\n"
	.string "SUICUNE was tough, but you were even\p"
	.string "more incredible, <PLAYER>.\n"
	.string "I heard SUICUNE's mystic power\p"
	.string "summons a rainbow-colored POKéMON.\n"
	.string "Maybe, just maybe, what went on today\p"
	.string "will cause that POKéMON to appear.\n"
	.string "I'm going to study the legends more.\p"
	.string "Thanks for showing me that fantastic\n"
	.string "battle.\p"
	.string "Later, <PLAYER>!$"
