Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route13_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route13_EventScript_Alex::
	trainerbattle_single TRAINER_ALEX Route13_Text_PokefanmAlexSeen, Route13_Text_PokefanmAlexBeaten
	msgbox Route13_Text_PokefanmAlexAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA Route13_Text_PokefanmJoshuaSeen, Route13_Text_PokefanmJoshuaBeaten
	msgbox Route13_Text_PokefanmJoshuaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY Route13_Text_BirdKeeperPerrySeen, Route13_Text_BirdKeeperPerryBeaten
	msgbox Route13_Text_BirdKeeperPerryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Bret::
	trainerbattle_single TRAINER_BRET Route13_Text_BirdKeeperBretSeen, Route13_Text_BirdKeeperBretBeaten
	msgbox Route13_Text_BirdKeeperBretAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Kenny::
	trainerbattle_single TRAINER_KENNY Route13_Text_HikerKennySeen, Route13_Text_HikerKennyBeaten
	msgbox Route13_Text_HikerKennyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_TrainerTips::
	msgbox Route13_Text_TrainerTips, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_EventScript_DirectionsSign::
	msgbox Route13_Text_DirectionsSign, MSGBOX_SIGN
	end

Route13_Text_PokefanmAlexSeen:
	.string "Bow down before my regal POKéMON!$"

Route13_Text_PokefanmAlexBeaten:
	.string "How… How dare you mock royalty!$"

Route13_Text_PokefanmAlexAfterBattle:
	.string "Doesn't everyone wish to someday\n"
	.string "be a king?$"

Route13_Text_PokefanmJoshuaSeen:
	.string "Nihihi! Would you like to battle\n"
	.string "my PIKACHU gang?$"

Route13_Text_PokefanmJoshuaBeaten:
	.string "PI-PIKACHU!$"

Route13_Text_PokefanmJoshuaAfterBattle:
	.string "You look like you have many\n"
	.string "POKéMON, but PIKACHU\l"
	.string "is still the best.$"

Route13_Text_BirdKeeperPerrySeen:
	.string "Agility is the key attribute of\n"
	.string "bird POKéMON.$"

Route13_Text_BirdKeeperPerryBeaten:
	.string "You beat me with your speed…$"

Route13_Text_BirdKeeperPerryAfterBattle:
	.string "Your POKéMON are remarkably well-\n"
	.string "trained.$"

Route13_Text_BirdKeeperBretSeen:
	.string "Check out my POKéMON. Just look\n"
	.string "at their coloring and their\l"
	.string "plumage.$"

Route13_Text_BirdKeeperBretBeaten:
	.string "Shoot! Not good enough!$"

Route13_Text_BirdKeeperBretAfterBattle:
	.string "If you groom them, POKéMON get\n"
	.string "happy.$"

Route13_Text_HikerKennySeen:
	.string "I should go to ROCK TUNNEL to get\n"
	.string "myself an ONIX.$"

Route13_Text_HikerKennyBeaten:
	.string "I lost…$"

Route13_Text_HikerKennyAfterBattle:
	.string "Geological features don't appear\n"
	.string "to change.\p"
	.string "But they actually change, little\n"
	.string "by little.$"

Route13_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Look! Right there, at the left\n"
	.string "side of the post.$"

Route13_Text_Sign:
	.string "ROUTE 13\p"
	.string "NORTH TO SILENCE BRIDGE$"

Route13_Text_DirectionsSign:
	.string "NORTH TO LAVENDER TOWN\p"
	.string "WEST TO FUCHSIA CITY$"

