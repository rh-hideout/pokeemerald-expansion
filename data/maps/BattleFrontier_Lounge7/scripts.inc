# 1 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_MapScripts::
# 3 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
# 6 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	lock
# 7 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	faceplayer
# 8 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 9 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
# 10 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
# 11 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
# 12 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
# 13 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 14 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 15 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
# 16 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
# 17 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
# 18 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 20 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
# 21 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 22 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 23 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowBattlePointsWindow
# 24 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
# 25 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 26 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 0
# 27 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 28 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 29 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 30 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 31 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
# 32 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
# 33 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
# 34 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
# 35 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
# 36 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
# 37 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
# 38 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_Counter
# 39 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
# 40 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
# 41 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 42 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 43 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 45 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
# 46 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 47 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 48 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
# 49 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 50 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 1
# 51 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 52 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 53 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 54 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 55 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
# 56 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
# 57 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
# 58 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
# 59 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
# 60 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
# 61 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
# 62 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_Counter
# 63 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
# 64 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
# 65 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 66 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 67 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 68 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 69 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Softboiled::
# 70 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 16
# 71 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SOFT_BOILED
# 72 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 73 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 74 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 75 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_SeismicToss::
# 76 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 77 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
# 78 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 79 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 80 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 81 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_DreamEater::
# 82 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 83 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_DREAM_EATER
# 84 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 85 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 86 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 87 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MegaPunch::
# 88 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 89 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
# 90 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 91 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 92 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 93 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MegaKick::
# 94 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 95 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_MEGA_KICK
# 96 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 97 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 98 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 99 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_BodySlam::
# 100 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 101 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_BODY_SLAM
# 102 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 103 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 104 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 105 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_RockSlide::
# 106 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 107 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
# 108 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 109 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 110 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 111 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Counter::
# 112 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 113 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_COUNTER
# 114 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 115 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 116 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 117 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ThunderWave::
# 118 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 119 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
# 120 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 121 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 122 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 123 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_SwordsDance::
# 124 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 125 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
# 126 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 127 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 128 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 129 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_RightMoveTutor::
# 130 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	lock
# 131 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	faceplayer
# 132 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 133 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
# 134 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
# 135 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
# 136 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
# 137 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 138 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 139 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
# 140 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
# 141 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
# 142 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 143 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 144 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
# 145 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 146 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 147 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowBattlePointsWindow
# 148 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
# 149 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 150 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 0
# 151 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 152 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 153 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 154 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 155 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
# 156 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_Snore
# 157 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
# 158 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_Swift
# 159 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
# 160 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_Endure
# 161 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
# 162 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
# 163 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
# 164 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
# 165 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 166 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 167 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 168 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 169 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
# 170 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 171 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 172 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
# 173 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 174 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 1
# 175 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 176 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 177 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 178 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 179 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
# 180 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_Snore
# 181 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
# 182 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_Swift
# 183 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
# 184 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_Endure
# 185 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
# 186 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
# 187 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
# 188 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
# 189 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 190 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 191 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 192 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 193 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_DefenseCurl::
# 194 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 16
# 195 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
# 196 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 197 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 198 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 199 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Snore::
# 200 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 201 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SNORE
# 202 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 203 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 204 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 205 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MudSlap::
# 206 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 207 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_MUD_SLAP
# 208 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 209 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 210 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 211 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Swift::
# 212 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 213 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SWIFT
# 214 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 215 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 216 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 217 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_IcyWind::
# 218 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 219 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_ICY_WIND
# 220 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 221 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 222 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 223 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Endure::
# 224 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 225 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_ENDURE
# 226 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 227 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 228 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 229 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_PsychUp::
# 230 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 231 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_PSYCH_UP
# 232 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 233 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 234 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 235 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_IcePunch::
# 236 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 237 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_ICE_PUNCH
# 238 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 239 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 240 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 241 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ThunderPunch::
# 242 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 243 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
# 244 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 245 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 246 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 247 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_FirePunch::
# 248 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 249 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
# 250 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 251 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 252 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 253 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
# 254 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattleFrontierTutorWindow
# 255 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattlePointsWindow
# 256 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
# 257 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 258 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 259 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 260 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_CancelChooseMon::
# 261 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
# 262 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 263 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 264 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 265 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_0x8008 is the price
# 266 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_C is the scroll multichoice ID
# 267 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
# 268 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
# 269 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
# 270 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special BufferBattleFrontierTutorMoveName
# 271 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8008
# 272 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
# 273 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
# 274 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 275 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
# 276 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
# 277 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
# 278 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 279 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 280 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_TeachTutorMove::
# 281 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
# 282 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	fadescreen FADE_TO_BLACK
# 283 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattlePointsWindow
# 284 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattleFrontierTutorWindow
# 285 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ChooseMonForMoveTutor
# 286 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 287 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
# 288 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
# 289 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 290 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special TakeFrontierBattlePoints
# 291 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 292 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 293 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 294 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewMove::
# 295 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
# 296 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
# 297 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 298 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 299 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Sailor::
# 300 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
# 301 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 302 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 303 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Gentleman::
# 304 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
# 305 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 306 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 307 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LeftTutorIntro:
# 308 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Buhahaha!\p"
# 309 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You couldn't tell it from looking now,\n"
# 310 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "but I used to be one tough TRAINER.\p"
# 311 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I had a reputation as the toughest\n"
# 312 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "BEAUTY around, I tell you!\p"
# 313 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "… … … … … …\p"
# 314 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What is it now?\n"
# 315 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't believe me.\p"
# 316 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'm not like that blowhard woman over\n"
# 317 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "there. I'm actually talented!\p"
# 318 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Let me prove it to you.\n"
# 319 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can teach your POKéMON special and\l"
# 320 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet cute moves.\p"
# 321 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But my lessons don't come free.\n"
# 322 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "How about paying for the moves I teach\l"
# 323 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with a wee bit of Battle Points?$"
# 324 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 325 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
# 326 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Buhahaha!\p"
# 327 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Are you back to learn special and\n"
# 328 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet cute POKéMON moves?$"
# 329 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 330 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_TeachWhichMove:
# 331 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fine, fine, look here!\n"
# 332 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Which move should I teach?$"
# 333 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 334 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
# 335 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "The move {STR_VAR_1}, is it?\n"
# 336 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"
# 337 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 338 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
# 339 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fine, fine, now pick the POKéMON\n"
# 340 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I should teach the move to.$"
# 341 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 342 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
# 343 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What the…\n"
# 344 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You haven't got enough Battle Points!$"
# 345 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 346 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
# 347 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Do you see how skilled I am now?\n"
# 348 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'll take your Battle Points, thanks!$"
# 349 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 350 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_YouDontWantTo:
# 351 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What's that?\n"
# 352 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't want to…\p"
# 353 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "If you want to see how skilled I am,\n"
# 354 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "you come see me anytime!$"
# 355 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 356 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RightTutorIntro:
# 357 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ihihihi!\p"
# 358 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I know it's hard to see now, but I used\n"
# 359 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "to be one fantastic TRAINER.\p"
# 360 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I had a reputation as the most\n"
# 361 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "invincible SWIMMER around, I tell you!\p"
# 362 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "… … … … … …\p"
# 363 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What's wrong?\n"
# 364 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't believe me.\p"
# 365 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'm not like that buffoonish woman over\n"
# 366 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "there. I'm actually experienced!\p"
# 367 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can prove it to you.\n"
# 368 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can teach your POKéMON hard and\l"
# 369 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet pretty moves.\p"
# 370 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But my lessons don't come free.\n"
# 371 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "How about paying for the moves I teach\l"
# 372 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with a wee bit of Battle Points?$"
# 373 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 374 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
# 375 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ihihihi!\p"
# 376 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Have you come to learn hard and\n"
# 377 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet pretty POKéMON moves?$"
# 378 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 379 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
# 380 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Those ladies, the way they bad-mouth\n"
# 381 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "each other, you probably think that\l"
# 382 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "they don't get along.\p"
# 383 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But if that were true, they wouldn't\n"
# 384 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "stay out here together, would they?$"
# 385 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 386 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
# 387 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "When I was just a wee YOUNGSTER,\n"
# 388 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "those ladies were strong and beautiful.\p"
# 389 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "They were idols among us TRAINERS.\p"
# 390 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Even now, age hasn't dulled their\n"
# 391 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "abilities.\p"
# 392 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "In fact, their POKéMON moves have\n"
# 393 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "grown even more polished.\p"
# 394 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But… For some reason, I can't help\n"
# 395 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "but feel this…\p"
# 396 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Time is so cruel…$"
# 397 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 398 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SoftboiledDesc::
# 399 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Recovers up to\n"
# 400 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "half the user's\n"
# 401 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "maximum HP.$"
# 402 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 403 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SeismicTossDesc::
# 404 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Inflicts damage\n"
# 405 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "identical to the\n"
# 406 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "user's level.$"
# 407 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 408 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_DreamEaterDesc::
# 409 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Recovers half the\n"
# 410 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "damage inflicted\n"
# 411 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "on a sleeping foe.$"
# 412 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 413 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MegaPunchDesc::
# 414 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A strong punch\n"
# 415 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "thrown with\n"
# 416 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "incredible power.$"
# 417 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 418 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MegaKickDesc::
# 419 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An extremely\n"
# 420 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "powerful kick with\n"
# 421 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "intense force.$"
# 422 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 423 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_BodySlamDesc::
# 424 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A full-body slam\n"
# 425 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may cause\n"
# 426 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralysis.$"
# 427 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 428 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RockSlideDesc::
# 429 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Large boulders\n"
# 430 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "are hurled. May\n"
# 431 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "cause flinching.$"
# 432 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 433 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_CounterDesc::
# 434 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Retaliates any\n"
# 435 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "physical hit with\n"
# 436 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "double the power.$"
# 437 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 438 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThunderWaveDesc::
# 439 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A weak jolt of\n"
# 440 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "electricity that\n"
# 441 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralyzes the foe.$"
# 442 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 443 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SwordsDanceDesc::
# 444 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A fighting dance\n"
# 445 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that sharply\n"
# 446 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "raises ATTACK.$"
# 447 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 448 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_DefenseCurlDesc::
# 449 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Curls up to con-\n"
# 450 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ceal weak spots\n"
# 451 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "and raise DEFENSE.$"
# 452 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 453 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SnoreDesc::
# 454 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A loud attack\n"
# 455 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that can be used\n"
# 456 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "only while asleep.$"
# 457 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 458 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MudSlapDesc::
# 459 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hurls mud in the\n"
# 460 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's face to re-\n"
# 461 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "duce its accuracy.$"
# 462 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 463 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SwiftDesc::
# 464 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sprays star-\n"
# 465 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "shaped rays\n"
# 466 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that never miss.$"
# 467 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 468 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IcyWindDesc::
# 469 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A chilling attack\n"
# 470 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that lowers the\n"
# 471 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's SPEED.$"
# 472 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 473 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_EndureDesc::
# 474 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Endures any at-\n"
# 475 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "tack for 1 turn,\n"
# 476 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "leaving 1HP.$"
# 477 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 478 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_PsychUpDesc::
# 479 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Copies the foe's\n"
# 480 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "effect(s) and\n"
# 481 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "gives to the user.$"
# 482 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 483 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IcePunchDesc::
# 484 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An icy punch\n"
# 485 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may\n"
# 486 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "freeze the foe.$"
# 487 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 488 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThunderPunchDesc::
# 489 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An electrified\n"
# 490 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "punch that may\n"
# 491 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralyze the foe.$"
# 492 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 493 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_FirePunchDesc::
# 494 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A fiery punch\n"
# 495 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may burn\n"
# 496 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the foe.$"
