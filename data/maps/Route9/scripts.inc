Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_Text_CamperDeanSeen:
	.string "I came to explore ROCK TUNNEL.$"

Route9_Text_CamperDeanBeaten:
	.string "Whoa! Danger, man.$"

Route9_Text_CamperDeanAfter:
	.string "My POKéMON were hurt before even\n"
	.string "entering ROCK TUNNEL.\p"
	.string "I'd better take them to a POKéMON\n"
	.string "CENTER right away.$"

Route9_Text_PicnickerHeidiSeen:
	.string "Have you ever been to a picnic?\p"
	.string "They're so much fun!$"

Route9_Text_PicnickerHeidiBeaten:
	.string "Ohhhh!$"

Route9_Text_PicnickerHeidiAfter:
	.string "We bake lots of goodies and share\n"
	.string "them all around.\p"
	.string "They're delicious!$"

Route9_Text_CamperSidSeen:
	.string "Hey, you! Don't litter!$"

Route9_Text_CamperSidBeaten:
	.string "I was just pointing out…$"

Route9_Text_CamperSidAfter:
	.string "Sorry. You weren't littering. It\n"
	.string "was my mistake.$"

Route9_Text_PicnickerEdnaSeen:
	.string "People shouldn't leave any litter\n"
	.string "behind.$"

Route9_Text_PicnickerEdnaBeaten:
	.string "Ohh… I lost…$"

Route9_Text_PicnickerEdnaAfter:
	.string "Conserving energy is important,\n"
	.string "but the environment is even more\l"
	.string "vital.$"

Route9_Text_HikerTimSeen:
	.string "She'll be coming 'round MT.SILVER\n"
	.string "when she comes…\p"
	.string "MT.SILVER is in JOHTO, right?$"

Route9_Text_HikerTimBeaten:
	.string "I was too busy singing…$"

Route9_Text_HikerTimAfter:
	.string "Battles are about concentration.$"

Route9_Text_HikerSidneySeen:
	.string "I'll tell you a secret.\p"
	.string "But first, we battle!$"

Route9_Text_HikerSidneyBeaten:
	.string "Oh, dang! I lost that…$"

Route9_Text_HikerSidneyAfter:
	.string "The POWER PLANT is across a small\n"
	.string "river.$"

Route9_Text_Sign:
	.string "ROUTE 9\p"
	.string "CERULEAN CITY - ROCK TUNNEL$"
