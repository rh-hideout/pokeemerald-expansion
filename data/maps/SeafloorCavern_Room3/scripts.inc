# 1 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 2 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_MapScripts::
# 3 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.byte 0
# 4 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 5 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_EventScript_Shelly::
# 6 "data/maps/SeafloorCavern_Room3/scripts.pory"
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
# 7 "data/maps/SeafloorCavern_Room3/scripts.pory"
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/SeafloorCavern_Room3/scripts.pory"
	end
# 9 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 10 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_EventScript_Grunt5::
# 11 "data/maps/SeafloorCavern_Room3/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
# 12 "data/maps/SeafloorCavern_Room3/scripts.pory"
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/SeafloorCavern_Room3/scripts.pory"
	end
# 14 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 15 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_Text_ShellyIntro:
# 16 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Ahahahaha!\p"
# 17 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "How did you manage to get here without\n"
# 18 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "a submarine?\l"
# 19 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "What an impressive child!\p"
# 20 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "But… It won't do to have you\n"
# 21 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "meddling about here.\p"
# 22 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "And, I do want payback for what\n"
# 23 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "happened at the WEATHER INSTITUTE…\p"
# 24 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "I'm going to give you a little taste\n"
# 25 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "of pain! Resign yourself to it!$"
# 26 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 27 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_Text_ShellyDefeat:
# 28 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Ahahahaha!\p"
# 29 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Ouch!$"
# 30 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 31 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_Text_ShellyPostBattle:
# 32 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Ahahahaha!\n"
# 33 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "You're so darn strong.\p"
# 34 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "It's terribly disappointing that you're\n"
# 35 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "not a TEAM AQUA member.\p"
# 36 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "You could have enjoyed the fabulous\n"
# 37 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "world our BOSS has promised as\l"
# 38 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "one of us…$"
# 39 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 40 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_Text_Grunt5Intro:
# 41 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "For our dream to become real, we need\n"
# 42 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "the power of POKéMON.\p"
# 43 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "But meddlers like you use the power of\n"
# 44 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "POKéMON to mess with us even at\l"
# 45 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "a place like this!\p"
# 46 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Life just doesn't work the way we\n"
# 47 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "need it to!$"
# 48 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 49 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_Text_Grunt5Defeat:
# 50 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Gwah!$"
# 51 "data/maps/SeafloorCavern_Room3/scripts.pory"

# 52 "data/maps/SeafloorCavern_Room3/scripts.pory"
SeafloorCavern_Room3_Text_Grunt5PostBattle:
# 53 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "You know, we don't dare question\n"
# 54 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "the motives of our leader.\p"
# 55 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "But here you are, just some punk,\n"
# 56 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "going up against our BOSS.\p"
# 57 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Maybe…\n"
# 58 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "You must be something…$"
