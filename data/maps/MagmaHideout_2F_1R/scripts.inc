# 1 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 2 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_MapScripts::
# 3 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.byte 0
# 4 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 5 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_EventScript_Grunt14::
# 6 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
# 7 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	end
# 9 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 10 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_EventScript_Grunt3::
# 11 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
# 12 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	end
# 14 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 15 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_EventScript_Grunt4::
# 16 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
# 17 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 18 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	end
# 19 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 20 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_EventScript_Grunt5::
# 21 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
# 22 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
# 23 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	end
# 24 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 25 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt14Intro:
# 26 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "What, what, what?\p"
# 27 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Only TEAM MAGMA members are supposed\n"
# 28 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "to be in here!\p"
# 29 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "But you're not dressed in TEAM MAGMA's\n"
# 30 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "uniform…\p"
# 31 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "You rouse my suspicion!\n"
# 32 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Battle with me!$"
# 33 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 34 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt14Defeat:
# 35 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Aiyiyi…\n"
# 36 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "My pride as a TEAM MAGMA member…$"
# 37 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 38 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt14PostBattle:
# 39 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "If you suffer from chills, you should\n"
# 40 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "join TEAM MAGMA.$"
# 41 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 42 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt3Intro:
# 43 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Hold it right there!\p"
# 44 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "You don't really expect me to keep\n"
# 45 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "my trap shut and let you waltz by me?$"
# 46 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 47 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt3Defeat:
# 48 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Ooh wow!\n"
# 49 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "I concede!$"
# 50 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 51 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt3PostBattle:
# 52 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Maybe it would've been better if I did\n"
# 53 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "just let you go unchallenged…$"
# 54 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 55 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt4Intro:
# 56 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Ahah!\n"
# 57 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "An intruder!$"
# 58 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 59 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt4Defeat:
# 60 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Graaah!$"
# 61 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 62 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt4PostBattle:
# 63 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "I've already lost.\p"
# 64 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Do I really need to keep running\n"
# 65 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "around in a circle?$"
# 66 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 67 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt5Intro:
# 68 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Oh, oh!\n"
# 69 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "An intruder!$"
# 70 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 71 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt5Defeat:
# 72 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Mutter…$"
# 73 "data/maps/MagmaHideout_2F_1R/scripts.pory"

# 74 "data/maps/MagmaHideout_2F_1R/scripts.pory"
MagmaHideout_2F_1R_Text_Grunt5PostBattle:
# 75 "data/maps/MagmaHideout_2F_1R/scripts.pory"
	.string "Actually, I'm no expert at battling…$"
