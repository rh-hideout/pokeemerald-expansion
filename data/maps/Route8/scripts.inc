Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "We're the KANTO POKéMON FEDERATION\n"
	.string "trainer group.\p"
	.string "We'll drive you under our wheels!$"

Route8_Text_BikerDwayneBeaten:
	.string "S-sorry!$"

Route8_Text_BikerDwayneAfter:
	.string "The KANTO POKéMON FEDERATION will\n"
	.string "never fall!$"

Route8_Text_BikerHarrisSeen:
	.string "The cops shut down our\n"
	.string "UNDERGROUND PATH!\p"
	.string "That really fries me!$"

Route8_Text_BikerHarrisBeaten:
	.string "F-forgive me!$"

Route8_Text_BikerHarrisAfter:
	.string "Wiped out by some punk from\n"
	.string "JOHTO…$"

Route8_Text_BikerZekeSeen:
	.string "We're the KANTO POKéMON FEDERA-\n"
	.string "TION!\n"
	.string "Right on!$"

Route8_Text_BikerZekeBeaten:
	.string "Yikes! Sorry!$"

Route8_Text_BikerZekeAfter:
	.string "We'll try not to disturb anyone\n"
	.string "from now on…$"

Route8_Text_SupernerdSamSeen:
	.string "How does the MAGNET TRAIN work?$"

Route8_Text_SupernerdSamBeaten:
	.string "I just want to see the MAGNET\n"
	.string "TRAIN…$"

Route8_Text_SupernerdSamAfter:
	.string "The power of magnets is awesome!$"

Route8_Text_SupernerdTomSeen:
	.string "Hm… You've got many GYM BADGES.$"

Route8_Text_SupernerdTomBeaten:
	.string "Just as I thought… You're tough!$"

Route8_Text_SupernerdTomAfter:
	.string "GYM BADGES give you advantages in\n"
	.string "battles.$"

Route8_Text_LockedDoor:
	.string "It's locked…$"

Route8_Text_UndergroundPathSign:
	.string "The flyer's torn.\p"
	.string "It's impossible to read…$"
