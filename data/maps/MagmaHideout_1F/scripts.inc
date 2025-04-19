# 1 "data/maps/MagmaHideout_1F/scripts.pory"

# 2 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_MapScripts::
# 3 "data/maps/MagmaHideout_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
# 4 "data/maps/MagmaHideout_1F/scripts.pory"
	.byte 0
# 5 "data/maps/MagmaHideout_1F/scripts.pory"

# 6 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_OnTransition:
# 7 "data/maps/MagmaHideout_1F/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
# 8 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 9 "data/maps/MagmaHideout_1F/scripts.pory"

# 10 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_Grunt1::
# 11 "data/maps/MagmaHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
# 12 "data/maps/MagmaHideout_1F/scripts.pory"
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 14 "data/maps/MagmaHideout_1F/scripts.pory"

# 15 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_Grunt2::
# 16 "data/maps/MagmaHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
# 17 "data/maps/MagmaHideout_1F/scripts.pory"
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 18 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 19 "data/maps/MagmaHideout_1F/scripts.pory"

# 20 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt1Intro:
# 21 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "When TEAM MAGMA has roll call, we get\n"
# 22 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "important guarding assignments in\l"
# 23 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "the order that we line up.\p"
# 24 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "That's why I'm stuck off in this corner.\n"
# 25 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I'm always late to roll call!$"
# 26 "data/maps/MagmaHideout_1F/scripts.pory"

# 27 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt1Defeat:
# 28 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I'm always late for training sessions,\n"
# 29 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "too!\p"
# 30 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I hate to say it, but I'm wimpy…$"
# 31 "data/maps/MagmaHideout_1F/scripts.pory"

# 32 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt1PostBattle:
# 33 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Okay, I'll try to put a little more\n"
# 34 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "effort into things from now on…$"
# 35 "data/maps/MagmaHideout_1F/scripts.pory"

# 36 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt2Intro:
# 37 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Our leader told us to dig into\n"
# 38 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "MT. CHIMNEY, so we dug and dug.\p"
# 39 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "And in the course of digging, we came\n"
# 40 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "across something that blew our minds!\p"
# 41 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "What did we find?\p"
# 42 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Fuhahaha!\n"
# 43 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I'll tell you if you beat me!$"
# 44 "data/maps/MagmaHideout_1F/scripts.pory"

# 45 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt2Defeat:
# 46 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Arrgh!\n"
# 47 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Taken down!$"
# 48 "data/maps/MagmaHideout_1F/scripts.pory"

# 49 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt2PostBattle:
# 50 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I won't tell you after all.\n"
# 51 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "You'll find out when you get there!\p"
# 52 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "It'd be better if you saved surprises\n"
# 53 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "to the end, don't you think?$"
