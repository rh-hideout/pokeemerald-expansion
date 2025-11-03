# 1 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 2 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_MapScripts::
# 3 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.byte 0
# 4 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 5 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_EventScript_Grunt3::
# 6 "data/maps/SeafloorCavern_Room4/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
# 7 "data/maps/SeafloorCavern_Room4/scripts.pory"
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/SeafloorCavern_Room4/scripts.pory"
	end
# 9 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 10 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_EventScript_Grunt4::
# 11 "data/maps/SeafloorCavern_Room4/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
# 12 "data/maps/SeafloorCavern_Room4/scripts.pory"
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/SeafloorCavern_Room4/scripts.pory"
	end
# 14 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 15 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_Text_Grunt3Intro:
# 16 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "Who are you?\n"
# 17 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "Where did you come in from?$"
# 18 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 19 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_Text_Grunt3Defeat:
# 20 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "Lost it…$"
# 21 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 22 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_Text_Grunt3PostBattle:
# 23 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "I can't find the way out!\p"
# 24 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "I'm not afraid. Don't get me wrong!$"
# 25 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 26 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_Text_Grunt4Intro:
# 27 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "Who are you?\n"
# 28 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "Where do you think you're going?$"
# 29 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 30 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_Text_Grunt4Defeat:
# 31 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "I failed to win!$"
# 32 "data/maps/SeafloorCavern_Room4/scripts.pory"

# 33 "data/maps/SeafloorCavern_Room4/scripts.pory"
SeafloorCavern_Room4_Text_Grunt4PostBattle:
# 34 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "My partner forgot the map in that\n"
# 35 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "submarine!\p"
# 36 "data/maps/SeafloorCavern_Room4/scripts.pory"
	.string "How's that for being useless?$"
