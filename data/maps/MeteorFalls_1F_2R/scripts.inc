# 1 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 2 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_MapScripts::
# 3 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.byte 0
# 4 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 5 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_Nicolas::
# 6 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
# 7 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 8 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
# 9 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
# 10 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 11 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 12 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 13 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RegisterNicolas::
# 14 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 15 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	waitmovement 0
# 16 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
# 17 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	register_matchcall TRAINER_NICOLAS_1
# 18 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 19 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 20 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 21 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RematchNicolas::
# 22 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
# 23 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
# 24 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 25 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 26 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_John::
# 27 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
# 28 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 29 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
# 30 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
# 31 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 32 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 33 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 34 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RegisterJohn::
# 35 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
# 36 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	register_matchcall TRAINER_JOHN_AND_JAY_1
# 37 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 38 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 39 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 40 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RematchJohn::
# 41 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
# 42 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
# 43 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 44 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 45 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_Jay::
# 46 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
# 47 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 48 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
# 49 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
# 50 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 51 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 52 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 53 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RegisterJay::
# 54 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
# 55 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	register_matchcall TRAINER_JOHN_AND_JAY_1
# 56 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 57 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 58 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 59 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RematchJay::
# 60 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
# 61 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
# 62 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 63 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 64 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasIntro:
# 65 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "This is where we DRAGON users do our\n"
# 66 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "training.\p"
# 67 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "The CHAMPION even visits.\n"
# 68 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Now do you see how special it is here?$"
# 69 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 70 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasDefeat:
# 71 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Urgh!\n"
# 72 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I didn't expect you to be so strong!$"
# 73 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 74 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasPostBattle:
# 75 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "The road ahead remains long and harsh.\p"
# 76 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "When will my POKéMON and I become\n"
# 77 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "the best?$"
# 78 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 79 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasRegister:
# 80 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I want to know more about your power.\n"
# 81 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 82 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 83 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasRematchIntro:
# 84 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Since we met, we have trained hard\n"
# 85 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "with our sights on number one.\p"
# 86 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Help us see how much stronger we've\n"
# 87 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "become!$"
# 88 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 89 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
# 90 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Urgh!\n"
# 91 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I didn't expect you to be so strong!$"
# 92 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 93 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasPostRematch:
# 94 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "You've obviously kept up your\n"
# 95 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "POKéMON training.\p"
# 96 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "So long as you remain strong, I, too,\n"
# 97 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "can become stronger!$"
# 98 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 99 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnIntro:
# 100 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: We've always battled POKéMON\n"
# 101 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "together as a twosome.\l"
# 102 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've confidence in ourselves.$"
# 103 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 104 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnDefeat:
# 105 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: Oh, my.\n"
# 106 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've lost, dear wife.$"
# 107 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 108 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnPostBattle:
# 109 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: We've been married for\n"
# 110 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "fifty years.\p"
# 111 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Come to think of it, I've yet to beat\n"
# 112 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "my dear wife in a battle.$"
# 113 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 114 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
# 115 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: Well, well, what a young TRAINER!\p"
# 116 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Will you battle with us? If so, you'll\n"
# 117 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "have to return with more POKéMON.$"
# 118 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 119 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnRegister:
# 120 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: Young TRAINER, if the chance\n"
# 121 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "arises, will you battle with us again?$"
# 122 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 123 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayIntro:
# 124 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: We've been married for\n"
# 125 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "fifty years.\p"
# 126 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "The bond we share as a couple could\n"
# 127 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "never be broken.$"
# 128 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 129 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayDefeat:
# 130 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: Oh, dear.\n"
# 131 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've lost, my dear husband.$"
# 132 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 133 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayPostBattle:
# 134 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: Fifty years of marriage…\p"
# 135 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "If we ever argued, we always settled\n"
# 136 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "it with a POKéMON battle…$"
# 137 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 138 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayNotEnoughMons:
# 139 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: Well, well, aren't you a young\n"
# 140 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "TRAINER?\p"
# 141 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "If you'd care to battle with us, you'll\n"
# 142 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "have to come back with more POKéMON.$"
# 143 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 144 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnRematchIntro:
# 145 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: We've always battled POKéMON\n"
# 146 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "together as a twosome.\l"
# 147 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've confidence in ourselves.$"
# 148 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 149 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnRematchDefeat:
# 150 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: Oh, my.\n"
# 151 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've lost, dear wife.$"
# 152 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 153 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnPostRematch:
# 154 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: Married for fifty years…\p"
# 155 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "On reflection, the dear wife and I,\n"
# 156 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "we battled day in and day out…$"
# 157 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 158 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
# 159 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: Well, well, what a young TRAINER!\p"
# 160 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Will you battle with us? If so, you'll\n"
# 161 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "have to return with more POKéMON.$"
# 162 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 163 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayRematchIntro:
# 164 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: We've been married for\n"
# 165 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "fifty years.\p"
# 166 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've supported each other all that\n"
# 167 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "time. We've made ourselves strong.$"
# 168 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 169 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayRematchDefeat:
# 170 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: Oh, dear.\n"
# 171 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've lost, my dear husband.$"
# 172 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 173 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayPostRematch:
# 174 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: Fifty years of marriage…\n"
# 175 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Many things have happened.\p"
# 176 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I hope that we will continue to make\n"
# 177 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "happy memories together.$"
# 178 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 179 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
# 180 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: Well, well, aren't you a young\n"
# 181 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "TRAINER?\p"
# 182 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "If you'd care to battle with us, you'll\n"
# 183 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "have to come back with more POKéMON.$"
