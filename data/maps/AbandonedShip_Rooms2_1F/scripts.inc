# 1 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 2 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_MapScripts::
# 3 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.byte 0
# 4 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 5 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_Dan::
# 6 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
# 7 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 8 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
# 9 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
# 10 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	release
# 11 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 12 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 13 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
# 14 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
# 15 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	register_matchcall TRAINER_KIRA_AND_DAN_1
# 16 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	release
# 17 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 18 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 19 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_DanRematch::
# 20 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
# 21 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
# 22 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 23 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 24 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_Kira::
# 25 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
# 26 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 27 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
# 28 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
# 29 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	release
# 30 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 31 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 32 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
# 33 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
# 34 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	register_matchcall TRAINER_KIRA_AND_DAN_1
# 35 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	release
# 36 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 37 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 38 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
# 39 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
# 40 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
# 41 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 42 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 43 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_Jani::
# 44 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
# 45 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
# 46 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 47 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 48 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_Garrison::
# 49 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
# 50 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
# 51 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 52 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 53 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanIntro:
# 54 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: While searching for treasures,\n"
# 55 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "we discovered a TRAINER!$"
# 56 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 57 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanDefeat:
# 58 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: We couldn't win even though\n"
# 59 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "we worked together…$"
# 60 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 61 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanPostBattle:
# 62 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: We can't find any treasures…\n"
# 63 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I wonder if someone got them already?$"
# 64 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 65 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
# 66 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: You don't even have two POKéMON.\n"
# 67 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "You can't expect to beat us like that.$"
# 68 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 69 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraIntro:
# 70 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Oh?\n"
# 71 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "We were searching for treasures.\l"
# 72 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "But we discovered a TRAINER instead!$"
# 73 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 74 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraDefeat:
# 75 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Ooh, so strong!$"
# 76 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 77 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
# 78 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Where could the treasures be?\p"
# 79 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I've already decided what I'm buying\n"
# 80 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "when we find the treasures!$"
# 81 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 82 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
# 83 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Oh, you don't have two POKéMON?\n"
# 84 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "We'll have to battle some other time!$"
# 85 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 86 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraRegister:
# 87 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Oh, you make me so angry!\n"
# 88 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I'm going to register you for that!$"
# 89 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 90 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
# 91 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: We've been searching for\n"
# 92 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "treasures all this time.\p"
# 93 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Our POKéMON have grown stronger, too.\n"
# 94 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Let us show you, okay?$"
# 95 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 96 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
# 97 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: You're strong, as usual!$"
# 98 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 99 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanPostRematch:
# 100 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: We can't find any treasures,\n"
# 101 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "we lose at POKéMON…\p"
# 102 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I want to go home… But if I say that,\n"
# 103 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "she gets all angry with me…$"
# 104 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 105 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
# 106 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: You don't even have two POKéMON.\n"
# 107 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "You can't expect to beat us like that.$"
# 108 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 109 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
# 110 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Oh? We meet again!\p"
# 111 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Just like us, you still haven't given up\n"
# 112 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "searching for treasures, have you?\p"
# 113 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Want to make it so the loser has\n"
# 114 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "to give up searching?$"
# 115 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 116 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
# 117 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Oh, we lost again…$"
# 118 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 119 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
# 120 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: We're not leaving until we raise\n"
# 121 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "our POKéMON some more and we find\l"
# 122 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "the treasures here!$"
# 123 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 124 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
# 125 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Oh, you don't have two POKéMON?\n"
# 126 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "We'll have to battle some other time!$"
# 127 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 128 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_JaniIntro:
# 129 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I'm not good at swimming,\n"
# 130 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "but I am good at battles!$"
# 131 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 132 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_JaniDefeat:
# 133 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Oops.\n"
# 134 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "That didn't go very well.$"
# 135 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 136 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
# 137 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Walking around barefoot in this ship\n"
# 138 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "is kind of gross.$"
# 139 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 140 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
# 141 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Strength and compassion…\n"
# 142 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Those are a TRAINER's treasures!$"
# 143 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 144 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
# 145 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Ah, there is something about you\n"
# 146 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "that sparkles.$"
# 147 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 148 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
# 149 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "In a cabin somewhere on board,\n"
# 150 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I saw something sparkle.$"
