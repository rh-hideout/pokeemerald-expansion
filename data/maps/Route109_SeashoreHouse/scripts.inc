# 1 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 2 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_MapScripts::
# 3 "data/maps/Route109_SeashoreHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
# 4 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 6 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_OnTransition:
# 7 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
# 8 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 9 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 10 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Owner::
# 11 "data/maps/Route109_SeashoreHouse/scripts.pory"
	lock
# 12 "data/maps/Route109_SeashoreHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
# 14 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
# 15 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
# 16 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
# 17 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 18 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 19 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 20 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 21 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
# 22 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
# 23 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 24 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 25 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 26 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_DefeatedTrainers::
# 27 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
# 28 "data/maps/Route109_SeashoreHouse/scripts.pory"
	giveitem ITEM_SODA_POP, 6
# 29 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
# 30 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_RECEIVED_6_SODA_POP
# 31 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 32 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 33 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 34 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_BagFull::
# 35 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
# 36 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 37 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 38 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 39 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
# 40 "data/maps/Route109_SeashoreHouse/scripts.pory"
	showmoneybox 0, 0
# 41 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
# 42 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
# 43 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
# 44 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 45 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 46 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 47 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 48 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_BuySodaPop::
# 49 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkmoney 300
# 50 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
# 51 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkitemspace ITEM_SODA_POP
# 52 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
# 53 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
# 54 "data/maps/Route109_SeashoreHouse/scripts.pory"
	removemoney 300
# 55 "data/maps/Route109_SeashoreHouse/scripts.pory"
	updatemoneybox
# 56 "data/maps/Route109_SeashoreHouse/scripts.pory"
.if OW_SHOW_ITEM_DESCRIPTIONS != OW_ITEM_DESCRIPTIONS_OFF
# 57 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 58 "data/maps/Route109_SeashoreHouse/scripts.pory"
	giveitem ITEM_SODA_POP
# 59 "data/maps/Route109_SeashoreHouse/scripts.pory"
.else
# 60 "data/maps/Route109_SeashoreHouse/scripts.pory"
	giveitem ITEM_SODA_POP
# 61 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 62 "data/maps/Route109_SeashoreHouse/scripts.pory"
.endif
# 63 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 64 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 65 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 66 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_NotEnoughMoney::
# 67 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 68 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 69 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 70 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 71 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 72 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_NotEnoughSpace::
# 73 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 74 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 75 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 76 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 77 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 78 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Dwayne::
# 79 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 80 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
# 81 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 82 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 83 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Johanna::
# 84 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 85 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
# 86 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 87 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 88 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Simon::
# 89 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 90 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
# 91 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 92 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 93 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
# 94 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 95 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 96 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 97 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
# 98 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 99 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 100 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 101 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
# 102 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 103 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 104 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 105 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SeashoreHouseIntro:
# 106 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm the owner of the SEASHORE HOUSE.\n"
# 107 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "But you can call me MR. SEA!\p"
# 108 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "What I love above all is to see hot\n"
# 109 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "POKéMON battles.\p"
# 110 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Let me see that your heart burns hot!\p"
# 111 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If you can defeat all the TRAINERS\n"
# 112 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "here, I'll reward your efforts.$"
# 113 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 114 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
# 115 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Show me some hot matches!\p"
# 116 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I run this SEASHORE HOUSE just for\n"
# 117 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "that reason alone!$"
# 118 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 119 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
# 120 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "You're scorching hot!\n"
# 121 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Those battles blazed!\l"
# 122 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm more than just satisfied!\p"
# 123 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "As thanks for showing me your hot\n"
# 124 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "streak, I want you to take these.\p"
# 125 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "It's half a dozen bottles of SODA POP!$"
# 126 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 127 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_BagFull:
# 128 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Oh, but hey, your BAG's jammed full.\n"
# 129 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'll hang on to these for you.$"
# 130 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 131 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_WantToBuySodaPop:
# 132 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Want to buy some SODA POP?\n"
# 133 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "POKéMON love it!\p"
# 134 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Just ¥300 a bottle!\n"
# 135 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Buy some!$"
# 136 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 137 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_HereYouGo:
# 138 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Here you go!$"
# 139 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 140 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_NotEnoughMoney:
# 141 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "You don't have the money.$"
# 142 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 143 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_ThatsTooBad:
# 144 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "No?\n"
# 145 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That's too bad.$"
# 146 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 147 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwayneIntro:
# 148 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If you're looking for a battle in the\n"
# 149 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "SEASHORE HOUSE, you'll find no\l"
# 150 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "hotter TRAINER than me, matey!$"
# 151 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 152 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwayneDefeated:
# 153 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That was a hot battle!\n"
# 154 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I can accept that loss, matey!$"
# 155 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 156 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwaynePostBattle:
# 157 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Whenever I'm in SLATEPORT, I enjoy\n"
# 158 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "hot battles and ice-cold SODA POP!$"
# 159 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 160 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaIntro:
# 161 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Boring battles aren't worth the effort.\p"
# 162 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Fiery hot battles are what toughen up\n"
# 163 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "TRAINERS and POKéMON!$"
# 164 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 165 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaDefeated:
# 166 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That's hot!$"
# 167 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 168 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaPostBattle:
# 169 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Whew, I'm all thirsty.\n"
# 170 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Maybe I'll have a SODA POP.$"
# 171 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 172 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonIntro:
# 173 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm going to show you how great\n"
# 174 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "my POKéMON are, but don't cry!$"
# 175 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 176 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonDefeated:
# 177 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "…I lost, but I won't cry…$"
# 178 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 179 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonPostBattle:
# 180 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If one of my POKéMON knew the move\n"
# 181 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "for carrying me across water on its\l"
# 182 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "back, I could get rid of this inner tube.$"
