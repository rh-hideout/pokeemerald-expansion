# 1 "data/maps/AquaHideout_B1F/scripts.pory"

# 2 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_MapScripts::
# 3 "data/maps/AquaHideout_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
# 4 "data/maps/AquaHideout_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
# 5 "data/maps/AquaHideout_B1F/scripts.pory"
	.byte 0
# 6 "data/maps/AquaHideout_B1F/scripts.pory"

# 7 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_OnResume:
# 8 "data/maps/AquaHideout_B1F/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
# 9 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 10 "data/maps/AquaHideout_B1F/scripts.pory"

# 11 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_TryRemoveElectrode::
# 12 "data/maps/AquaHideout_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data/maps/AquaHideout_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 15 "data/maps/AquaHideout_B1F/scripts.pory"
	return
# 16 "data/maps/AquaHideout_B1F/scripts.pory"

# 17 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_OnTransition:
# 18 "data/maps/AquaHideout_B1F/scripts.pory"
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
# 19 "data/maps/AquaHideout_B1F/scripts.pory"
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
# 20 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 21 "data/maps/AquaHideout_B1F/scripts.pory"

# 22 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_ShowElectrode1::
# 23 "data/maps/AquaHideout_B1F/scripts.pory"
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
# 24 "data/maps/AquaHideout_B1F/scripts.pory"
	return
# 25 "data/maps/AquaHideout_B1F/scripts.pory"

# 26 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_ShowElectrode2::
# 27 "data/maps/AquaHideout_B1F/scripts.pory"
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
# 28 "data/maps/AquaHideout_B1F/scripts.pory"
	return
# 29 "data/maps/AquaHideout_B1F/scripts.pory"

# 30 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Electrode1::
# 31 "data/maps/AquaHideout_B1F/scripts.pory"
	lock
# 32 "data/maps/AquaHideout_B1F/scripts.pory"
	faceplayer
# 33 "data/maps/AquaHideout_B1F/scripts.pory"
	setwildbattle SPECIES_ELECTRODE, 30
# 34 "data/maps/AquaHideout_B1F/scripts.pory"
	waitse
# 35 "data/maps/AquaHideout_B1F/scripts.pory"
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
# 36 "data/maps/AquaHideout_B1F/scripts.pory"
	delay 40
# 37 "data/maps/AquaHideout_B1F/scripts.pory"
	waitmoncry
# 38 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 39 "data/maps/AquaHideout_B1F/scripts.pory"
	dowildbattle
# 40 "data/maps/AquaHideout_B1F/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 41 "data/maps/AquaHideout_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 42 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode1
# 43 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode1
# 44 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode1
# 45 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
# 46 "data/maps/AquaHideout_B1F/scripts.pory"
	release
# 47 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 48 "data/maps/AquaHideout_B1F/scripts.pory"

# 49 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_DefeatedElectrode1::
# 50 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
# 51 "data/maps/AquaHideout_B1F/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 52 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 53 "data/maps/AquaHideout_B1F/scripts.pory"

# 54 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Electrode2::
# 55 "data/maps/AquaHideout_B1F/scripts.pory"
	lock
# 56 "data/maps/AquaHideout_B1F/scripts.pory"
	faceplayer
# 57 "data/maps/AquaHideout_B1F/scripts.pory"
	setwildbattle SPECIES_ELECTRODE, 30
# 58 "data/maps/AquaHideout_B1F/scripts.pory"
	waitse
# 59 "data/maps/AquaHideout_B1F/scripts.pory"
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
# 60 "data/maps/AquaHideout_B1F/scripts.pory"
	delay 40
# 61 "data/maps/AquaHideout_B1F/scripts.pory"
	waitmoncry
# 62 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 63 "data/maps/AquaHideout_B1F/scripts.pory"
	dowildbattle
# 64 "data/maps/AquaHideout_B1F/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 65 "data/maps/AquaHideout_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 66 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode2
# 67 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode2
# 68 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode2
# 69 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
# 70 "data/maps/AquaHideout_B1F/scripts.pory"
	release
# 71 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 72 "data/maps/AquaHideout_B1F/scripts.pory"

# 73 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_DefeatedElectrode2::
# 74 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
# 75 "data/maps/AquaHideout_B1F/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 76 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 77 "data/maps/AquaHideout_B1F/scripts.pory"

# 78 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt2::
# 79 "data/maps/AquaHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
# 80 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 81 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 82 "data/maps/AquaHideout_B1F/scripts.pory"

# 83 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt2Defeated::
# 84 "data/maps/AquaHideout_B1F/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 85 "data/maps/AquaHideout_B1F/scripts.pory"
	waitmovement 0
# 86 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
# 87 "data/maps/AquaHideout_B1F/scripts.pory"
	release
# 88 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 89 "data/maps/AquaHideout_B1F/scripts.pory"

# 90 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt3::
# 91 "data/maps/AquaHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
# 92 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 93 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 94 "data/maps/AquaHideout_B1F/scripts.pory"

# 95 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt3Defeated::
# 96 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
# 97 "data/maps/AquaHideout_B1F/scripts.pory"
	release
# 98 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 99 "data/maps/AquaHideout_B1F/scripts.pory"

# 100 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt5::
# 101 "data/maps/AquaHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
# 102 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
# 103 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 104 "data/maps/AquaHideout_B1F/scripts.pory"

# 105 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt7::
# 106 "data/maps/AquaHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_7, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
# 107 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
# 108 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 109 "data/maps/AquaHideout_B1F/scripts.pory"

# 110 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt2Intro:
# 111 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "If you want to know the secret about\n"
# 112 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "our HIDEOUT, you have me to beat!$"
# 113 "data/maps/AquaHideout_B1F/scripts.pory"

# 114 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt2Defeat:
# 115 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "I can't win at all…$"
# 116 "data/maps/AquaHideout_B1F/scripts.pory"

# 117 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt2PostBattle:
# 118 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Our HIDEOUT's secret?\p"
# 119 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Well, let's just say…\n"
# 120 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "There's a submarine at the far end!\p"
# 121 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "But, by now…\n"
# 122 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Kekekeke…$"
# 123 "data/maps/AquaHideout_B1F/scripts.pory"

# 124 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt3Intro:
# 125 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Fuel supply loaded A-OK!\n"
# 126 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "In-cruise snacks loaded A-OK!\p"
# 127 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Nothing left to do but KO a pesky\n"
# 128 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "meddler!$"
# 129 "data/maps/AquaHideout_B1F/scripts.pory"

# 130 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt3Defeat:
# 131 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "I took a serious licking!$"
# 132 "data/maps/AquaHideout_B1F/scripts.pory"

# 133 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt3PostBattle:
# 134 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Humph!\n"
# 135 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "This was supposed to happen!\p"
# 136 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "My mission was to just hold you up!$"
# 137 "data/maps/AquaHideout_B1F/scripts.pory"

# 138 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt5Intro:
# 139 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Yawn… Keeping watch over the\n"
# 140 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "HIDEOUT bores me. I'll take you on.$"
# 141 "data/maps/AquaHideout_B1F/scripts.pory"

# 142 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt5Defeat:
# 143 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Yawn…\n"
# 144 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Oh, I lost…$"
# 145 "data/maps/AquaHideout_B1F/scripts.pory"

# 146 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt5PostBattle:
# 147 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "If you scurry too much, other TEAM\n"
# 148 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "AQUA members might get you.$"
# 149 "data/maps/AquaHideout_B1F/scripts.pory"

# 150 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt7Intro:
# 151 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Hey!\n"
# 152 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "You there!\p"
# 153 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Which do you think is cooler?\n"
# 154 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "TEAM AQUA's uniform or TEAM MAGMA's?$"
# 155 "data/maps/AquaHideout_B1F/scripts.pory"

# 156 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt7Defeat:
# 157 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "I lost in a cool way…$"
# 158 "data/maps/AquaHideout_B1F/scripts.pory"

# 159 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt7PostBattle:
# 160 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "If you have a cool uniform, you look\n"
# 161 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "good even in a loss, don't you think?$"
