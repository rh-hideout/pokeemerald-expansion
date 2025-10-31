# 1 "data/maps/AquaHideout_1F/scripts.pory"

# 2 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_MapScripts::
# 3 "data/maps/AquaHideout_1F/scripts.pory"
	.byte 0
# 4 "data/maps/AquaHideout_1F/scripts.pory"

# 5 "data/maps/AquaHideout_1F/scripts.pory"
@ The below two entrance guards give hints about what to do to progress the story
# 6 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
# 7 "data/maps/AquaHideout_1F/scripts.pory"
	lock
# 8 "data/maps/AquaHideout_1F/scripts.pory"
	faceplayer
# 9 "data/maps/AquaHideout_1F/scripts.pory"
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
# 10 "data/maps/AquaHideout_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
# 11 "data/maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
# 12 "data/maps/AquaHideout_1F/scripts.pory"
	release
# 13 "data/maps/AquaHideout_1F/scripts.pory"
	end
# 14 "data/maps/AquaHideout_1F/scripts.pory"

# 15 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_MagmaHideoutHint1::
# 16 "data/maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
# 17 "data/maps/AquaHideout_1F/scripts.pory"
	release
# 18 "data/maps/AquaHideout_1F/scripts.pory"
	end
# 19 "data/maps/AquaHideout_1F/scripts.pory"

# 20 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_SlateportHint1::
# 21 "data/maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
# 22 "data/maps/AquaHideout_1F/scripts.pory"
	release
# 23 "data/maps/AquaHideout_1F/scripts.pory"
	end
# 24 "data/maps/AquaHideout_1F/scripts.pory"

# 25 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
# 26 "data/maps/AquaHideout_1F/scripts.pory"
	lock
# 27 "data/maps/AquaHideout_1F/scripts.pory"
	faceplayer
# 28 "data/maps/AquaHideout_1F/scripts.pory"
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
# 29 "data/maps/AquaHideout_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
# 30 "data/maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
# 31 "data/maps/AquaHideout_1F/scripts.pory"
	release
# 32 "data/maps/AquaHideout_1F/scripts.pory"
	end
# 33 "data/maps/AquaHideout_1F/scripts.pory"

# 34 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_MagmaHideoutHint2::
# 35 "data/maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
# 36 "data/maps/AquaHideout_1F/scripts.pory"
	release
# 37 "data/maps/AquaHideout_1F/scripts.pory"
	end
# 38 "data/maps/AquaHideout_1F/scripts.pory"

# 39 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_SlateportHint2::
# 40 "data/maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
# 41 "data/maps/AquaHideout_1F/scripts.pory"
	release
# 42 "data/maps/AquaHideout_1F/scripts.pory"
	end
# 43 "data/maps/AquaHideout_1F/scripts.pory"

# 44 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_Grunt1::
# 45 "data/maps/AquaHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
# 46 "data/maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 47 "data/maps/AquaHideout_1F/scripts.pory"
	end
# 48 "data/maps/AquaHideout_1F/scripts.pory"

# 49 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_Grunt1Defeated::
# 50 "data/maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
# 51 "data/maps/AquaHideout_1F/scripts.pory"
	release
# 52 "data/maps/AquaHideout_1F/scripts.pory"
	end
# 53 "data/maps/AquaHideout_1F/scripts.pory"

# 54 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_OurBossIsSnatchingSomething:
# 55 "data/maps/AquaHideout_1F/scripts.pory"
	.string "What? What? What do you want with \n"
# 56 "data/maps/AquaHideout_1F/scripts.pory"
	.string "TEAM AQUA?\p"
# 57 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Our BOSS isn't here! He's gone off to\n"
# 58 "data/maps/AquaHideout_1F/scripts.pory"
	.string "snatch something important!\p"
# 59 "data/maps/AquaHideout_1F/scripts.pory"
	.string "… …\n"
# 60 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Where did he go?\p"
# 61 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Wahaha! Do you really think I'd tell\n"
# 62 "data/maps/AquaHideout_1F/scripts.pory"
	.string "you something that crucial?$"
# 63 "data/maps/AquaHideout_1F/scripts.pory"

# 64 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
# 65 "data/maps/AquaHideout_1F/scripts.pory"
	.string "What? What?\n"
# 66 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Are you a TEAM MAGMA grunt?\p"
# 67 "data/maps/AquaHideout_1F/scripts.pory"
	.string "I hear that TEAM MAGMA is trying to\n"
# 68 "data/maps/AquaHideout_1F/scripts.pory"
	.string "awaken an awesome POKéMON at their\l"
# 69 "data/maps/AquaHideout_1F/scripts.pory"
	.string "HIDEOUT.\p"
# 70 "data/maps/AquaHideout_1F/scripts.pory"
	.string "But where might their HIDEOUT be?$"
# 71 "data/maps/AquaHideout_1F/scripts.pory"

# 72 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_BossWentToJackASubmarine:
# 73 "data/maps/AquaHideout_1F/scripts.pory"
	.string "What? What? What do you want with \n"
# 74 "data/maps/AquaHideout_1F/scripts.pory"
	.string "TEAM AQUA?\p"
# 75 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Our BOSS isn't here!\n"
# 76 "data/maps/AquaHideout_1F/scripts.pory"
	.string "He's gone off to jack a submarine!\p"
# 77 "data/maps/AquaHideout_1F/scripts.pory"
	.string "… …\n"
# 78 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Where did he go?\p"
# 79 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Wahaha! Do you really think I'd tell\n"
# 80 "data/maps/AquaHideout_1F/scripts.pory"
	.string "you something that crucial?$"
# 81 "data/maps/AquaHideout_1F/scripts.pory"

# 82 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_BossIsOnRoute122:
# 83 "data/maps/AquaHideout_1F/scripts.pory"
	.string "What? What? What do you want with \n"
# 84 "data/maps/AquaHideout_1F/scripts.pory"
	.string "TEAM AQUA?\p"
# 85 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Our BOSS isn't here! He's on his way to\n"
# 86 "data/maps/AquaHideout_1F/scripts.pory"
	.string "MT. PYRE on ROUTE 122!\p"
# 87 "data/maps/AquaHideout_1F/scripts.pory"
	.string "… …\n"
# 88 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Why did he go?\p"
# 89 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Wahaha! Do you really think I'd tell\n"
# 90 "data/maps/AquaHideout_1F/scripts.pory"
	.string "you something that crucial?$"
# 91 "data/maps/AquaHideout_1F/scripts.pory"

# 92 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_TeamMagmaAtMtChimney:
# 93 "data/maps/AquaHideout_1F/scripts.pory"
	.string "What? What?\n"
# 94 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Are you a TEAM MAGMA grunt?\p"
# 95 "data/maps/AquaHideout_1F/scripts.pory"
	.string "I hear that TEAM MAGMA is after\n"
# 96 "data/maps/AquaHideout_1F/scripts.pory"
	.string "an awesome POKéMON at MT. CHIMNEY.\p"
# 97 "data/maps/AquaHideout_1F/scripts.pory"
	.string "But what is that POKéMON like?$"
# 98 "data/maps/AquaHideout_1F/scripts.pory"

# 99 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_BossIsInSlateportCity:
# 100 "data/maps/AquaHideout_1F/scripts.pory"
	.string "What? What? What do you want with\n"
# 101 "data/maps/AquaHideout_1F/scripts.pory"
	.string "TEAM AQUA?\p"
# 102 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Our BOSS isn't here!\n"
# 103 "data/maps/AquaHideout_1F/scripts.pory"
	.string "He's on his way to SLATEPORT CITY!\p"
# 104 "data/maps/AquaHideout_1F/scripts.pory"
	.string "… …\n"
# 105 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Why did he go?\p"
# 106 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Wahaha! Do you really think I'd tell\n"
# 107 "data/maps/AquaHideout_1F/scripts.pory"
	.string "you something that crucial?$"
# 108 "data/maps/AquaHideout_1F/scripts.pory"

# 109 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_Grunt1Intro:
# 110 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Ayiyiyi!\n"
# 111 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Suspicious character spotted!$"
# 112 "data/maps/AquaHideout_1F/scripts.pory"

# 113 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_Grunt1Defeat:
# 114 "data/maps/AquaHideout_1F/scripts.pory"
	.string "Grrrrr…\n"
# 115 "data/maps/AquaHideout_1F/scripts.pory"
	.string "I lost it!$"
# 116 "data/maps/AquaHideout_1F/scripts.pory"

# 117 "data/maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_Grunt1PostBattle:
# 118 "data/maps/AquaHideout_1F/scripts.pory"
	.string "I took the loss for the TEAM,\n"
# 119 "data/maps/AquaHideout_1F/scripts.pory"
	.string "but I did my job…$"
