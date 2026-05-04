.set LOCALID_NURSE, 1

CianwoodPokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkpartymove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "As far as water POKéMON go,\n"
	.string "TENTACOOL is the best by a\l"
	.string "nautical mile!$"

CianwoodPokemoncenter_Text_Fisher2:
	.string "You seem like you need a water\n"
	.string "POKéMON.\p"
	.string "Here, take this one, I have plenty.$"

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "Did you meet the POKéMANIAC?\p"
	.string "He's always bragging about his\n"
	.string "rare POKéMON.$"


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "The POKéMON GYM trainers here are\n"
	.string "macho bullies.\p"
	.string "If I stick around, they might\n"
	.string "come after me.\p"
	.string "Here's some advice: the GYM LEADER\n"
	.string "uses the FIGHTING-type.\p"
	.string "So you should confound him with\n"
	.string "psychic POKéMON.\p"
	.string "Wipe out his POKéMON before they\n"
	.string "can use their physical strength.\p"
	.string "And those boulders in the middle\n"
	.string "of the GYM?\p"
	.string "If you don't move them correctly,\n"
	.string "you won't reach the GYM LEADER.\p"
	.string "If you get stuck, go outside.$"

CianwoodCity_Text_GymGuideWin:
	.string "{PLAYER}! You won!\n"
	.string "I could tell by looking at you!$"

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "I love showing off the POKéMON\n"
	.string "that I've raised.\p"
	.string "Don't you?\p"
	.string "I'm going to get into a bunch of\n"
	.string "battles, and show off my POKéMON!$"
