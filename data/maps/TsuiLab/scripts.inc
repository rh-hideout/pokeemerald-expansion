TsuiLab_MapScripts::
# 2 "data/maps/TsuiLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TsuiLab_EventScript_BallDefault
	.byte 0


TsuiLab_EventScript_BallDefault::
# 6 "data/maps/TsuiLab/scripts.pory"
	setvar VAR_USED_STARTER, 0
	return


Start_StarterChoose_Sequence::
# 10 "data/maps/TsuiLab/scripts.pory"
	lock
# 11 "data/maps/TsuiLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MeetBirch
# 12 "data/maps/TsuiLab/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 13 "data/maps/TsuiLab/scripts.pory"
	msgbox BeginAdventureText
# 14 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 15 "data/maps/TsuiLab/scripts.pory"
	closemessage
# 16 "data/maps/TsuiLab/scripts.pory"
	applymovement 10, ProfMove
# 17 "data/maps/TsuiLab/scripts.pory"
	waitmovement 10
# 18 "data/maps/TsuiLab/scripts.pory"
	setvar VAR_MEETPROF, 1
# 19 "data/maps/TsuiLab/scripts.pory"
	setvar VAR_NOLEAVE, 1
# 20 "data/maps/TsuiLab/scripts.pory"
	release
	return


Start_StarterChoose_Sequence2::
# 24 "data/maps/TsuiLab/scripts.pory"
	lock
# 25 "data/maps/TsuiLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MeetBirch2
# 26 "data/maps/TsuiLab/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 27 "data/maps/TsuiLab/scripts.pory"
	goto Start_StarterChoose_Sequence
	return


TsuiLab_Trigger_FirstTest::
# 31 "data/maps/TsuiLab/scripts.pory"
	compare VAR_FIRSTTEST, 1
	goto_if_eq TsuiLab_Trigger_FirstTest_1
	return

TsuiLab_Trigger_FirstTest_1:
# 32 "data/maps/TsuiLab/scripts.pory"
	lockall
# 33 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_Trigger_FirstTest_Text_0
# 34 "data/maps/TsuiLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TsuiLab_Movement_Playerfaceup
# 35 "data/maps/TsuiLab/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 36 "data/maps/TsuiLab/scripts.pory"
	applymovement 10, TsuiLab_Movement_Tsuigoestoplayer
# 37 "data/maps/TsuiLab/scripts.pory"
	waitmovement 10
# 38 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_Trigger_FirstTest_Text_1
# 39 "data/maps/TsuiLab/scripts.pory"
	setvar VAR_FIRSTTEST, 2
# 40 "data/maps/TsuiLab/scripts.pory"
	compare VAR_FIRSTTEST, 2
	goto_if_eq TsuiLab_Trigger_FirstTest_4
TsuiLab_Trigger_FirstTest_3:
# 46 "data/maps/TsuiLab/scripts.pory"
	releaseall
	return

TsuiLab_Trigger_FirstTest_4:
# 41 "data/maps/TsuiLab/scripts.pory"
	applymovement 10, Tsui_Movement_Leave
# 42 "data/maps/TsuiLab/scripts.pory"
	waitmovement 10
# 43 "data/maps/TsuiLab/scripts.pory"
	removeobject 10
# 44 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_TSUIGONE
	goto TsuiLab_Trigger_FirstTest_3


# 50 "data/maps/TsuiLab/scripts.pory"
MeetBirch:
# 51 "data/maps/TsuiLab/scripts.pory"
	walk_up
# 51 "data/maps/TsuiLab/scripts.pory"
	walk_up
# 51 "data/maps/TsuiLab/scripts.pory"
	walk_up
	step_end

# 54 "data/maps/TsuiLab/scripts.pory"
MeetBirch2:
# 55 "data/maps/TsuiLab/scripts.pory"
	walk_left
	step_end

# 58 "data/maps/TsuiLab/scripts.pory"
ProfMove:
# 59 "data/maps/TsuiLab/scripts.pory"
	walk_right
# 59 "data/maps/TsuiLab/scripts.pory"
	walk_right
# 59 "data/maps/TsuiLab/scripts.pory"
	walk_right
# 59 "data/maps/TsuiLab/scripts.pory"
	walk_right
# 60 "data/maps/TsuiLab/scripts.pory"
	face_left
	step_end

# 63 "data/maps/TsuiLab/scripts.pory"
TsuiLab_Movement_Playerfaceup:
# 64 "data/maps/TsuiLab/scripts.pory"
	emote_exclamation_mark
# 65 "data/maps/TsuiLab/scripts.pory"
	face_up
	step_end

# 68 "data/maps/TsuiLab/scripts.pory"
TsuiLab_Movement_Tsuigoestoplayer:
# 69 "data/maps/TsuiLab/scripts.pory"
	walk_left
# 69 "data/maps/TsuiLab/scripts.pory"
	walk_left
# 69 "data/maps/TsuiLab/scripts.pory"
	walk_left
# 70 "data/maps/TsuiLab/scripts.pory"
	face_down
	step_end

# 73 "data/maps/TsuiLab/scripts.pory"
Tsui_Movement_Leave:
# 74 "data/maps/TsuiLab/scripts.pory"
	face_up
# 75 "data/maps/TsuiLab/scripts.pory"
	walk_up
# 75 "data/maps/TsuiLab/scripts.pory"
	walk_up
# 75 "data/maps/TsuiLab/scripts.pory"
	walk_up
# 75 "data/maps/TsuiLab/scripts.pory"
	walk_up
	step_end

StopLeaving::
# 89 "data/maps/TsuiLab/scripts.pory"
	lockall
# 90 "data/maps/TsuiLab/scripts.pory"
	msgbox StopLeaving_Text_0
# 91 "data/maps/TsuiLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DoNotLeave
# 92 "data/maps/TsuiLab/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 93 "data/maps/TsuiLab/scripts.pory"
	releaseall
	return


# 96 "data/maps/TsuiLab/scripts.pory"
DoNotLeave:
# 97 "data/maps/TsuiLab/scripts.pory"
	walk_up
	step_end

TsuiLab_EventScript_Tsui::
# 101 "data/maps/TsuiLab/scripts.pory"
	lockall
# 102 "data/maps/TsuiLab/scripts.pory"
	faceplayer
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_1_USED, TsuiLab_EventScript_Tsui_5
TsuiLab_EventScript_Tsui_4:
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_4_USED, TsuiLab_EventScript_Tsui_11
TsuiLab_EventScript_Tsui_10:
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_7_USED, TsuiLab_EventScript_Tsui_16
TsuiLab_EventScript_Tsui_3:
# 119 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_Tsui_Text_2
# 120 "data/maps/TsuiLab/scripts.pory"
	setvar VAR_FIRSTTEST, 1
# 121 "data/maps/TsuiLab/scripts.pory"
	setvar VAR_NOLEAVE, 2
# 122 "data/maps/TsuiLab/scripts.pory"
	clearflag FLAG_TSUIBATTLE
# 123 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
TsuiLab_EventScript_Tsui_1:
# 125 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 126 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_Tsui_2:
# 104 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_Tsui_Text_0, MSGBOX_YESNO
# 105 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_Tsui_21
# 115 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_Tsui_Text_1
	goto TsuiLab_EventScript_Tsui_1

TsuiLab_EventScript_Tsui_5:
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_2_USED, TsuiLab_EventScript_Tsui_7
	goto TsuiLab_EventScript_Tsui_4

TsuiLab_EventScript_Tsui_7:
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_3_USED, TsuiLab_EventScript_Tsui_2
	goto TsuiLab_EventScript_Tsui_4

TsuiLab_EventScript_Tsui_11:
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_5_USED, TsuiLab_EventScript_Tsui_13
	goto TsuiLab_EventScript_Tsui_10

TsuiLab_EventScript_Tsui_13:
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_6_USED, TsuiLab_EventScript_Tsui_2
	goto TsuiLab_EventScript_Tsui_10

TsuiLab_EventScript_Tsui_16:
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_8_USED, TsuiLab_EventScript_Tsui_18
	goto TsuiLab_EventScript_Tsui_3

TsuiLab_EventScript_Tsui_18:
# 103 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_9_USED, TsuiLab_EventScript_Tsui_2
	goto TsuiLab_EventScript_Tsui_3

TsuiLab_EventScript_Tsui_21:
# 106 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_ne TsuiLab_EventScript_Tsui_25
# 110 "data/maps/TsuiLab/scripts.pory"
	setvar VAR_USED_STARTER, 0
TsuiLab_EventScript_Tsui_24:
# 112 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_Tsui_Text_1
	goto TsuiLab_EventScript_Tsui_1

TsuiLab_EventScript_Tsui_25:
# 107 "data/maps/TsuiLab/scripts.pory"
	addvar VAR_USED_STARTER, 1
	goto TsuiLab_EventScript_Tsui_24


TsuiLab_EventScript_PokeballOne::
# 131 "data/maps/TsuiLab/scripts.pory"
	lockall
# 132 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_1_USED, TsuiLab_EventScript_PokeballOne_4
TsuiLab_EventScript_PokeballOne_3:
# 144 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballOne_1:
# 146 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 147 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballOne_2:
# 133 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballOne_9
# 136 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballOne_10
# 139 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballOne_11
	goto TsuiLab_EventScript_PokeballOne_1

TsuiLab_EventScript_PokeballOne_4:
# 132 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_2_USED, TsuiLab_EventScript_PokeballOne_6
	goto TsuiLab_EventScript_PokeballOne_3

TsuiLab_EventScript_PokeballOne_6:
# 132 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_3_USED, TsuiLab_EventScript_PokeballOne_2
	goto TsuiLab_EventScript_PokeballOne_3

TsuiLab_EventScript_PokeballOne_9:
# 134 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_RIOLU
	goto TsuiLab_EventScript_PokeballOne_1

TsuiLab_EventScript_PokeballOne_10:
# 137 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_WHISMUR
	goto TsuiLab_EventScript_PokeballOne_1

TsuiLab_EventScript_PokeballOne_11:
# 140 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_SHINX
	goto TsuiLab_EventScript_PokeballOne_1


TsuiLab_EventScript_PokeballTwo::
# 152 "data/maps/TsuiLab/scripts.pory"
	lockall
# 153 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_1_USED, TsuiLab_EventScript_PokeballTwo_4
TsuiLab_EventScript_PokeballTwo_3:
# 165 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballTwo_1:
# 167 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 168 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballTwo_2:
# 154 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballTwo_9
# 157 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballTwo_10
# 160 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballTwo_11
	goto TsuiLab_EventScript_PokeballTwo_1

TsuiLab_EventScript_PokeballTwo_4:
# 153 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_2_USED, TsuiLab_EventScript_PokeballTwo_6
	goto TsuiLab_EventScript_PokeballTwo_3

TsuiLab_EventScript_PokeballTwo_6:
# 153 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_3_USED, TsuiLab_EventScript_PokeballTwo_2
	goto TsuiLab_EventScript_PokeballTwo_3

TsuiLab_EventScript_PokeballTwo_9:
# 155 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_ROCKRUFF
	goto TsuiLab_EventScript_PokeballTwo_1

TsuiLab_EventScript_PokeballTwo_10:
# 158 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_PIKACHU
	goto TsuiLab_EventScript_PokeballTwo_1

TsuiLab_EventScript_PokeballTwo_11:
# 161 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_TOGEPI
	goto TsuiLab_EventScript_PokeballTwo_1


TsuiLab_EventScript_PokeballThree::
# 173 "data/maps/TsuiLab/scripts.pory"
	lockall
# 174 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_1_USED, TsuiLab_EventScript_PokeballThree_4
TsuiLab_EventScript_PokeballThree_3:
# 186 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballThree_1:
# 188 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 189 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballThree_2:
# 175 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballThree_9
# 178 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballThree_10
# 181 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballThree_11
	goto TsuiLab_EventScript_PokeballThree_1

TsuiLab_EventScript_PokeballThree_4:
# 174 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_2_USED, TsuiLab_EventScript_PokeballThree_6
	goto TsuiLab_EventScript_PokeballThree_3

TsuiLab_EventScript_PokeballThree_6:
# 174 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_3_USED, TsuiLab_EventScript_PokeballThree_2
	goto TsuiLab_EventScript_PokeballThree_3

TsuiLab_EventScript_PokeballThree_9:
# 176 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_SHROOMISH
	goto TsuiLab_EventScript_PokeballThree_1

TsuiLab_EventScript_PokeballThree_10:
# 179 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_FLETCHLING
	goto TsuiLab_EventScript_PokeballThree_1

TsuiLab_EventScript_PokeballThree_11:
# 182 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_ROOKIDEE
	goto TsuiLab_EventScript_PokeballThree_1


TsuiLab_EventScript_PokeballFour::
# 194 "data/maps/TsuiLab/scripts.pory"
	lockall
# 195 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_4_USED, TsuiLab_EventScript_PokeballFour_4
TsuiLab_EventScript_PokeballFour_3:
# 207 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballFour_1:
# 209 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 210 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballFour_2:
# 196 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballFour_9
# 199 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballFour_10
# 202 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballFour_11
	goto TsuiLab_EventScript_PokeballFour_1

TsuiLab_EventScript_PokeballFour_4:
# 195 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_5_USED, TsuiLab_EventScript_PokeballFour_6
	goto TsuiLab_EventScript_PokeballFour_3

TsuiLab_EventScript_PokeballFour_6:
# 195 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_6_USED, TsuiLab_EventScript_PokeballFour_2
	goto TsuiLab_EventScript_PokeballFour_3

TsuiLab_EventScript_PokeballFour_9:
# 197 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_SEWADDLE
	goto TsuiLab_EventScript_PokeballFour_1

TsuiLab_EventScript_PokeballFour_10:
# 200 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_MUNNA
	goto TsuiLab_EventScript_PokeballFour_1

TsuiLab_EventScript_PokeballFour_11:
# 203 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_TOXEL
	goto TsuiLab_EventScript_PokeballFour_1


TsuiLab_EventScript_PokeballFive::
# 215 "data/maps/TsuiLab/scripts.pory"
	lockall
# 216 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_4_USED, TsuiLab_EventScript_PokeballFive_4
TsuiLab_EventScript_PokeballFive_3:
# 228 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballFive_1:
# 230 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 231 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballFive_2:
# 217 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballFive_9
# 220 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballFive_10
# 223 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballFive_11
	goto TsuiLab_EventScript_PokeballFive_1

TsuiLab_EventScript_PokeballFive_4:
# 216 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_5_USED, TsuiLab_EventScript_PokeballFive_6
	goto TsuiLab_EventScript_PokeballFive_3

TsuiLab_EventScript_PokeballFive_6:
# 216 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_6_USED, TsuiLab_EventScript_PokeballFive_2
	goto TsuiLab_EventScript_PokeballFive_3

TsuiLab_EventScript_PokeballFive_9:
# 218 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_EEVEE
	goto TsuiLab_EventScript_PokeballFive_1

TsuiLab_EventScript_PokeballFive_10:
# 221 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_TADBULB
	goto TsuiLab_EventScript_PokeballFive_1

TsuiLab_EventScript_PokeballFive_11:
# 224 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_DEDENNE
	goto TsuiLab_EventScript_PokeballFive_1


TsuiLab_EventScript_PokeballSix::
# 236 "data/maps/TsuiLab/scripts.pory"
	lockall
# 237 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_4_USED, TsuiLab_EventScript_PokeballSix_4
TsuiLab_EventScript_PokeballSix_3:
# 249 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballSix_1:
# 251 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 252 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballSix_2:
# 238 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballSix_9
# 241 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballSix_10
# 244 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballSix_11
	goto TsuiLab_EventScript_PokeballSix_1

TsuiLab_EventScript_PokeballSix_4:
# 237 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_5_USED, TsuiLab_EventScript_PokeballSix_6
	goto TsuiLab_EventScript_PokeballSix_3

TsuiLab_EventScript_PokeballSix_6:
# 237 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_6_USED, TsuiLab_EventScript_PokeballSix_2
	goto TsuiLab_EventScript_PokeballSix_3

TsuiLab_EventScript_PokeballSix_9:
# 239 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_STARYU
	goto TsuiLab_EventScript_PokeballSix_1

TsuiLab_EventScript_PokeballSix_10:
# 242 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_ESPURR
	goto TsuiLab_EventScript_PokeballSix_1

TsuiLab_EventScript_PokeballSix_11:
# 245 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_DEWPIDER
	goto TsuiLab_EventScript_PokeballSix_1


TsuiLab_EventScript_PokeballSeven::
# 257 "data/maps/TsuiLab/scripts.pory"
	lockall
# 258 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_7_USED, TsuiLab_EventScript_PokeballSeven_4
TsuiLab_EventScript_PokeballSeven_3:
# 270 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballSeven_1:
# 272 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 273 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballSeven_2:
# 259 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballSeven_9
# 262 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballSeven_10
# 265 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballSeven_11
	goto TsuiLab_EventScript_PokeballSeven_1

TsuiLab_EventScript_PokeballSeven_4:
# 258 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_8_USED, TsuiLab_EventScript_PokeballSeven_6
	goto TsuiLab_EventScript_PokeballSeven_3

TsuiLab_EventScript_PokeballSeven_6:
# 258 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_9_USED, TsuiLab_EventScript_PokeballSeven_2
	goto TsuiLab_EventScript_PokeballSeven_3

TsuiLab_EventScript_PokeballSeven_9:
# 260 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_STUNFISK
	goto TsuiLab_EventScript_PokeballSeven_1

TsuiLab_EventScript_PokeballSeven_10:
# 263 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_BUIZEL
	goto TsuiLab_EventScript_PokeballSeven_1

TsuiLab_EventScript_PokeballSeven_11:
# 266 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_IGGLYBUFF
	goto TsuiLab_EventScript_PokeballSeven_1


TsuiLab_EventScript_PokeballEight::
# 278 "data/maps/TsuiLab/scripts.pory"
	lockall
# 279 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_7_USED, TsuiLab_EventScript_PokeballEight_4
TsuiLab_EventScript_PokeballEight_3:
# 291 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballEight_1:
# 293 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 294 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballEight_2:
# 280 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballEight_9
# 283 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballEight_10
# 286 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballEight_11
	goto TsuiLab_EventScript_PokeballEight_1

TsuiLab_EventScript_PokeballEight_4:
# 279 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_8_USED, TsuiLab_EventScript_PokeballEight_6
	goto TsuiLab_EventScript_PokeballEight_3

TsuiLab_EventScript_PokeballEight_6:
# 279 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_9_USED, TsuiLab_EventScript_PokeballEight_2
	goto TsuiLab_EventScript_PokeballEight_3

TsuiLab_EventScript_PokeballEight_9:
# 281 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_BLIPBUG
	goto TsuiLab_EventScript_PokeballEight_1

TsuiLab_EventScript_PokeballEight_10:
# 284 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_BOUNSWEET
	goto TsuiLab_EventScript_PokeballEight_1

TsuiLab_EventScript_PokeballEight_11:
# 287 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_NYMBLE
	goto TsuiLab_EventScript_PokeballEight_1


TsuiLab_EventScript_PokeballNine::
# 299 "data/maps/TsuiLab/scripts.pory"
	lockall
# 300 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_7_USED, TsuiLab_EventScript_PokeballNine_4
TsuiLab_EventScript_PokeballNine_3:
# 312 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PokeballOne_Text_0
TsuiLab_EventScript_PokeballNine_1:
# 314 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 315 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PokeballNine_2:
# 301 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 0
	goto_if_eq TsuiLab_EventScript_PokeballNine_9
# 304 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 1
	goto_if_eq TsuiLab_EventScript_PokeballNine_10
# 307 "data/maps/TsuiLab/scripts.pory"
	compare VAR_USED_STARTER, 2
	goto_if_eq TsuiLab_EventScript_PokeballNine_11
	goto TsuiLab_EventScript_PokeballNine_1

TsuiLab_EventScript_PokeballNine_4:
# 300 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_8_USED, TsuiLab_EventScript_PokeballNine_6
	goto TsuiLab_EventScript_PokeballNine_3

TsuiLab_EventScript_PokeballNine_6:
# 300 "data/maps/TsuiLab/scripts.pory"
	goto_if_unset FLAG_BALL_9_USED, TsuiLab_EventScript_PokeballNine_2
	goto TsuiLab_EventScript_PokeballNine_3

TsuiLab_EventScript_PokeballNine_9:
# 302 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_GLIGAR
	goto TsuiLab_EventScript_PokeballNine_1

TsuiLab_EventScript_PokeballNine_10:
# 305 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_CHARCADET
	goto TsuiLab_EventScript_PokeballNine_1

TsuiLab_EventScript_PokeballNine_11:
# 308 "data/maps/TsuiLab/scripts.pory"
	call TsuiLab_EventScript_PORYGON
	goto TsuiLab_EventScript_PokeballNine_1


TsuiLab_EventScript_RIOLU::
# 321 "data/maps/TsuiLab/scripts.pory"
	lockall
# 322 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_RIOLU, 10, 3
# 323 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_0, MSGBOX_YESNO
# 324 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_RIOLU_2
# 346 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 347 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_RIOLU_1:
# 349 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 350 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_RIOLU_2:
# 325 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_RIOLU, 10, ITEM_NONE
# 326 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_RIOLU_5
# 333 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_RIOLU_6
# 341 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 342 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_RIOLU_1

TsuiLab_EventScript_RIOLU_5:
# 327 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 328 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_1
# 329 "data/maps/TsuiLab/scripts.pory"
	removeobject 1
# 330 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_1_USED
# 331 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_RIOLU_1

TsuiLab_EventScript_RIOLU_6:
# 334 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 335 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_1
# 336 "data/maps/TsuiLab/scripts.pory"
	removeobject 1
# 337 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_1_USED
# 338 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_RIOLU_1


TsuiLab_EventScript_ROCKRUFF::
# 356 "data/maps/TsuiLab/scripts.pory"
	lockall
# 357 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_ROCKRUFF, 10, 3
# 358 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ROCKRUFF_Text_0, MSGBOX_YESNO
# 359 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_ROCKRUFF_2
# 381 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 382 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_ROCKRUFF_1:
# 384 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 385 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_ROCKRUFF_2:
# 360 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_ROCKRUFF, 10, ITEM_NONE
# 361 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_ROCKRUFF_5
# 368 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_ROCKRUFF_6
# 376 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 377 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_ROCKRUFF_1

TsuiLab_EventScript_ROCKRUFF_5:
# 362 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 363 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ROCKRUFF_Text_1
# 364 "data/maps/TsuiLab/scripts.pory"
	removeobject 2
# 365 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_2_USED
# 366 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_ROCKRUFF_1

TsuiLab_EventScript_ROCKRUFF_6:
# 369 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 370 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ROCKRUFF_Text_1
# 371 "data/maps/TsuiLab/scripts.pory"
	removeobject 2
# 372 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_2_USED
# 373 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_ROCKRUFF_1


TsuiLab_EventScript_SHROOMISH::
# 391 "data/maps/TsuiLab/scripts.pory"
	lockall
# 392 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_SHROOMISH, 10, 3
# 393 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SHROOMISH_Text_0, MSGBOX_YESNO
# 394 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_SHROOMISH_2
# 416 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 417 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_SHROOMISH_1:
# 419 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 420 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_SHROOMISH_2:
# 395 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_SHROOMISH, 10, ITEM_NONE
# 396 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_SHROOMISH_5
# 403 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_SHROOMISH_6
# 411 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 412 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_SHROOMISH_1

TsuiLab_EventScript_SHROOMISH_5:
# 397 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 398 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SHROOMISH_Text_1
# 399 "data/maps/TsuiLab/scripts.pory"
	removeobject 3
# 400 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_3_USED
# 401 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_SHROOMISH_1

TsuiLab_EventScript_SHROOMISH_6:
# 404 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 405 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SHROOMISH_Text_1
# 406 "data/maps/TsuiLab/scripts.pory"
	removeobject 3
# 407 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_3_USED
# 408 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_SHROOMISH_1


TsuiLab_EventScript_SEWADDLE::
# 426 "data/maps/TsuiLab/scripts.pory"
	lockall
# 427 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_SEWADDLE, 10, 3
# 428 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SEWADDLE_Text_0, MSGBOX_YESNO
# 429 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_SEWADDLE_2
# 451 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 452 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_SEWADDLE_1:
# 454 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 455 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_SEWADDLE_2:
# 430 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_SEWADDLE, 10, ITEM_NONE
# 431 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_SEWADDLE_5
# 438 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_SEWADDLE_6
# 446 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 447 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_SEWADDLE_1

TsuiLab_EventScript_SEWADDLE_5:
# 432 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 433 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SEWADDLE_Text_1
# 434 "data/maps/TsuiLab/scripts.pory"
	removeobject 4
# 435 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_4_USED
# 436 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_SEWADDLE_1

TsuiLab_EventScript_SEWADDLE_6:
# 439 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 440 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SEWADDLE_Text_1
# 441 "data/maps/TsuiLab/scripts.pory"
	removeobject 4
# 442 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_4_USED
# 443 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_SEWADDLE_1


TsuiLab_EventScript_EEVEE::
# 461 "data/maps/TsuiLab/scripts.pory"
	lockall
# 462 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_EEVEE, 10, 3
# 463 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_EEVEE_Text_0, MSGBOX_YESNO
# 464 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_EEVEE_2
# 486 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 487 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_EEVEE_1:
# 489 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 490 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_EEVEE_2:
# 465 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_EEVEE, 10, ITEM_NONE
# 466 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_EEVEE_5
# 473 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_EEVEE_6
# 481 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 482 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_EEVEE_1

TsuiLab_EventScript_EEVEE_5:
# 467 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 468 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_EEVEE_Text_1
# 469 "data/maps/TsuiLab/scripts.pory"
	removeobject 5
# 470 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_5_USED
# 471 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_EEVEE_1

TsuiLab_EventScript_EEVEE_6:
# 474 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 475 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_EEVEE_Text_1
# 476 "data/maps/TsuiLab/scripts.pory"
	removeobject 5
# 477 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_5_USED
# 478 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_EEVEE_1


TsuiLab_EventScript_STARYU::
# 496 "data/maps/TsuiLab/scripts.pory"
	lockall
# 497 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_STARYU, 10, 3
# 498 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_STARYU_Text_0, MSGBOX_YESNO
# 499 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_STARYU_2
# 521 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 522 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_STARYU_1:
# 524 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 525 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_STARYU_2:
# 500 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_STARYU, 10, ITEM_NONE
# 501 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_STARYU_5
# 508 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_STARYU_6
# 516 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 517 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_STARYU_1

TsuiLab_EventScript_STARYU_5:
# 502 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 503 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_STARYU_Text_1
# 504 "data/maps/TsuiLab/scripts.pory"
	removeobject 6
# 505 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_6_USED
# 506 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_STARYU_1

TsuiLab_EventScript_STARYU_6:
# 509 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 510 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_STARYU_Text_1
# 511 "data/maps/TsuiLab/scripts.pory"
	removeobject 6
# 512 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_6_USED
# 513 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_STARYU_1


TsuiLab_EventScript_STUNFISK::
# 531 "data/maps/TsuiLab/scripts.pory"
	lockall
# 532 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_STUNFISK, 10, 3
# 533 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_STUNFISK_Text_0, MSGBOX_YESNO
# 534 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_STUNFISK_2
# 556 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 557 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_STUNFISK_1:
# 559 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 560 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_STUNFISK_2:
# 535 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_STUNFISK, 10, ITEM_NONE
# 536 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_STUNFISK_5
# 543 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_STUNFISK_6
# 551 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 552 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_STUNFISK_1

TsuiLab_EventScript_STUNFISK_5:
# 537 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 538 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_STUNFISK_Text_1
# 539 "data/maps/TsuiLab/scripts.pory"
	removeobject 7
# 540 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_7_USED
# 541 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_STUNFISK_1

TsuiLab_EventScript_STUNFISK_6:
# 544 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 545 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_STUNFISK_Text_1
# 546 "data/maps/TsuiLab/scripts.pory"
	removeobject 7
# 547 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_7_USED
# 548 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_STUNFISK_1


TsuiLab_EventScript_BLIPBUG::
# 566 "data/maps/TsuiLab/scripts.pory"
	lockall
# 567 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_BLIPBUG, 10, 3
# 568 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BLIPBUG_Text_0, MSGBOX_YESNO
# 569 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_BLIPBUG_2
# 591 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 592 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_BLIPBUG_1:
# 594 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 595 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_BLIPBUG_2:
# 570 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_BLIPBUG, 10, ITEM_NONE
# 571 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_BLIPBUG_5
# 578 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_BLIPBUG_6
# 586 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 587 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_BLIPBUG_1

TsuiLab_EventScript_BLIPBUG_5:
# 572 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 573 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BLIPBUG_Text_1
# 574 "data/maps/TsuiLab/scripts.pory"
	removeobject 8
# 575 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_8_USED
# 576 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_BLIPBUG_1

TsuiLab_EventScript_BLIPBUG_6:
# 579 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 580 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BLIPBUG_Text_1
# 581 "data/maps/TsuiLab/scripts.pory"
	removeobject 8
# 582 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_8_USED
# 583 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_BLIPBUG_1


TsuiLab_EventScript_GLIGAR::
# 601 "data/maps/TsuiLab/scripts.pory"
	lockall
# 602 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_GLIGAR, 10, 3
# 603 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_GLIGAR_Text_0, MSGBOX_YESNO
# 604 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_GLIGAR_2
# 626 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 627 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_GLIGAR_1:
# 629 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 630 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_GLIGAR_2:
# 605 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_GLIGAR, 10, ITEM_NONE
# 606 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_GLIGAR_5
# 613 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_GLIGAR_6
# 621 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 622 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_GLIGAR_1

TsuiLab_EventScript_GLIGAR_5:
# 607 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 608 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_GLIGAR_Text_1
# 609 "data/maps/TsuiLab/scripts.pory"
	removeobject 9
# 610 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_9_USED
# 611 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_GLIGAR_1

TsuiLab_EventScript_GLIGAR_6:
# 614 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 615 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_GLIGAR_Text_1
# 616 "data/maps/TsuiLab/scripts.pory"
	removeobject 9
# 617 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_9_USED
# 618 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_GLIGAR_1


TsuiLab_EventScript_WHISMUR::
# 636 "data/maps/TsuiLab/scripts.pory"
	lockall
# 637 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_WHISMUR, 10, 3
# 638 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_WHISMUR_Text_0, MSGBOX_YESNO
# 639 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_WHISMUR_2
# 661 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 662 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_WHISMUR_1:
# 664 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 665 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_WHISMUR_2:
# 640 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_WHISMUR, 10, ITEM_NONE
# 641 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_WHISMUR_5
# 648 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_WHISMUR_6
# 656 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 657 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_WHISMUR_1

TsuiLab_EventScript_WHISMUR_5:
# 642 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 643 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_WHISMUR_Text_1
# 644 "data/maps/TsuiLab/scripts.pory"
	removeobject 1
# 645 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_1_USED
# 646 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_WHISMUR_1

TsuiLab_EventScript_WHISMUR_6:
# 649 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 650 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_WHISMUR_Text_1
# 651 "data/maps/TsuiLab/scripts.pory"
	removeobject 1
# 652 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_1_USED
# 653 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_WHISMUR_1


TsuiLab_EventScript_PIKACHU::
# 671 "data/maps/TsuiLab/scripts.pory"
	lockall
# 672 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_PIKACHU, 10, 3
# 673 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PIKACHU_Text_0, MSGBOX_YESNO
# 674 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_PIKACHU_2
# 696 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 697 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_PIKACHU_1:
# 699 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 700 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PIKACHU_2:
# 675 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_PIKACHU, 10, ITEM_NONE
# 676 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_PIKACHU_5
# 683 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_PIKACHU_6
# 691 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 692 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_PIKACHU_1

TsuiLab_EventScript_PIKACHU_5:
# 677 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 678 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PIKACHU_Text_1
# 679 "data/maps/TsuiLab/scripts.pory"
	removeobject 2
# 680 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_2_USED
# 681 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_PIKACHU_1

TsuiLab_EventScript_PIKACHU_6:
# 684 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 685 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PIKACHU_Text_1
# 686 "data/maps/TsuiLab/scripts.pory"
	removeobject 2
# 687 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_2_USED
# 688 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_PIKACHU_1


TsuiLab_EventScript_FLETCHLING::
# 706 "data/maps/TsuiLab/scripts.pory"
	lockall
# 707 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_FLETCHLING, 10, 3
# 708 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_FLETCHLING_Text_0, MSGBOX_YESNO
# 709 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_FLETCHLING_2
# 731 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 732 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_FLETCHLING_1:
# 734 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 735 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_FLETCHLING_2:
# 710 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_FLETCHLING, 10, ITEM_NONE
# 711 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_FLETCHLING_5
# 718 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_FLETCHLING_6
# 726 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 727 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_FLETCHLING_1

TsuiLab_EventScript_FLETCHLING_5:
# 712 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 713 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_FLETCHLING_Text_1
# 714 "data/maps/TsuiLab/scripts.pory"
	removeobject 3
# 715 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_3_USED
# 716 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_FLETCHLING_1

TsuiLab_EventScript_FLETCHLING_6:
# 719 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 720 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_FLETCHLING_Text_1
# 721 "data/maps/TsuiLab/scripts.pory"
	removeobject 3
# 722 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_3_USED
# 723 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_FLETCHLING_1


TsuiLab_EventScript_MUNNA::
# 741 "data/maps/TsuiLab/scripts.pory"
	lockall
# 742 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_MUNNA, 10, 3
# 743 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_MUNNA_Text_0, MSGBOX_YESNO
# 744 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_MUNNA_2
# 766 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 767 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_MUNNA_1:
# 769 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 770 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_MUNNA_2:
# 745 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_MUNNA, 10, ITEM_NONE
# 746 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_MUNNA_5
# 753 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_MUNNA_6
# 761 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 762 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_MUNNA_1

TsuiLab_EventScript_MUNNA_5:
# 747 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 748 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_MUNNA_Text_1
# 749 "data/maps/TsuiLab/scripts.pory"
	removeobject 4
# 750 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_4_USED
# 751 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_MUNNA_1

TsuiLab_EventScript_MUNNA_6:
# 754 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 755 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_MUNNA_Text_1
# 756 "data/maps/TsuiLab/scripts.pory"
	removeobject 4
# 757 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_4_USED
# 758 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_MUNNA_1


TsuiLab_EventScript_TADBULB::
# 776 "data/maps/TsuiLab/scripts.pory"
	lockall
# 777 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_TADBULB, 10, 3
# 778 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TADBULB_Text_0, MSGBOX_YESNO
# 779 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_TADBULB_2
# 801 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 802 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_TADBULB_1:
# 804 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 805 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_TADBULB_2:
# 780 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_TADBULB, 10, ITEM_NONE
# 781 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_TADBULB_5
# 788 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_TADBULB_6
# 796 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 797 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_TADBULB_1

TsuiLab_EventScript_TADBULB_5:
# 782 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 783 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TADBULB_Text_1
# 784 "data/maps/TsuiLab/scripts.pory"
	removeobject 5
# 785 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_5_USED
# 786 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_TADBULB_1

TsuiLab_EventScript_TADBULB_6:
# 789 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 790 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TADBULB_Text_1
# 791 "data/maps/TsuiLab/scripts.pory"
	removeobject 5
# 792 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_5_USED
# 793 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_TADBULB_1


TsuiLab_EventScript_ESPURR::
# 811 "data/maps/TsuiLab/scripts.pory"
	lockall
# 812 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_ESPURR, 10, 3
# 813 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ESPURR_Text_0, MSGBOX_YESNO
# 814 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_ESPURR_2
# 836 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 837 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_ESPURR_1:
# 839 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 840 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_ESPURR_2:
# 815 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_ESPURR, 10, ITEM_NONE
# 816 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_ESPURR_5
# 823 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_ESPURR_6
# 831 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 832 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_ESPURR_1

TsuiLab_EventScript_ESPURR_5:
# 817 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 818 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ESPURR_Text_1
# 819 "data/maps/TsuiLab/scripts.pory"
	removeobject 6
# 820 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_6_USED
# 821 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_ESPURR_1

TsuiLab_EventScript_ESPURR_6:
# 824 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 825 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ESPURR_Text_1
# 826 "data/maps/TsuiLab/scripts.pory"
	removeobject 6
# 827 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_6_USED
# 828 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_ESPURR_1


TsuiLab_EventScript_BUIZEL::
# 846 "data/maps/TsuiLab/scripts.pory"
	lockall
# 847 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_BUIZEL, 10, 3
# 848 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BUIZEL_Text_0, MSGBOX_YESNO
# 849 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_BUIZEL_2
# 871 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 872 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_BUIZEL_1:
# 874 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 875 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_BUIZEL_2:
# 850 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_BUIZEL, 10, ITEM_NONE
# 851 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_BUIZEL_5
# 858 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_BUIZEL_6
# 866 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 867 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_BUIZEL_1

TsuiLab_EventScript_BUIZEL_5:
# 852 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 853 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BUIZEL_Text_1
# 854 "data/maps/TsuiLab/scripts.pory"
	removeobject 7
# 855 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_7_USED
# 856 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_BUIZEL_1

TsuiLab_EventScript_BUIZEL_6:
# 859 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 860 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BUIZEL_Text_1
# 861 "data/maps/TsuiLab/scripts.pory"
	removeobject 7
# 862 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_7_USED
# 863 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_BUIZEL_1


TsuiLab_EventScript_BOUNSWEET::
# 881 "data/maps/TsuiLab/scripts.pory"
	lockall
# 882 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_BOUNSWEET, 10, 3
# 883 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BOUNSWEET_Text_0, MSGBOX_YESNO
# 884 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_BOUNSWEET_2
# 906 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 907 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_BOUNSWEET_1:
# 909 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 910 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_BOUNSWEET_2:
# 885 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_BOUNSWEET, 10, ITEM_NONE
# 886 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_BOUNSWEET_5
# 893 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_BOUNSWEET_6
# 901 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 902 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_BOUNSWEET_1

TsuiLab_EventScript_BOUNSWEET_5:
# 887 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 888 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BOUNSWEET_Text_1
# 889 "data/maps/TsuiLab/scripts.pory"
	removeobject 8
# 890 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_8_USED
# 891 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_BOUNSWEET_1

TsuiLab_EventScript_BOUNSWEET_6:
# 894 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 895 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_BOUNSWEET_Text_1
# 896 "data/maps/TsuiLab/scripts.pory"
	removeobject 8
# 897 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_8_USED
# 898 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_BOUNSWEET_1


TsuiLab_EventScript_CHARCADET::
# 916 "data/maps/TsuiLab/scripts.pory"
	lockall
# 917 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_CHARCADET, 10, 3
# 918 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_CHARCADET_Text_0, MSGBOX_YESNO
# 919 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_CHARCADET_2
# 941 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 942 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_CHARCADET_1:
# 944 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 945 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_CHARCADET_2:
# 920 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_CHARCADET, 10, ITEM_NONE
# 921 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_CHARCADET_5
# 928 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_CHARCADET_6
# 936 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 937 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_CHARCADET_1

TsuiLab_EventScript_CHARCADET_5:
# 922 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 923 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_CHARCADET_Text_1
# 924 "data/maps/TsuiLab/scripts.pory"
	removeobject 9
# 925 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_9_USED
# 926 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_CHARCADET_1

TsuiLab_EventScript_CHARCADET_6:
# 929 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 930 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_CHARCADET_Text_1
# 931 "data/maps/TsuiLab/scripts.pory"
	removeobject 9
# 932 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_9_USED
# 933 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_CHARCADET_1


TsuiLab_EventScript_SHINX::
# 951 "data/maps/TsuiLab/scripts.pory"
	lockall
# 952 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_SHINX, 10, 3
# 953 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SHINX_Text_0, MSGBOX_YESNO
# 954 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_SHINX_2
# 976 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 977 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_SHINX_1:
# 979 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 980 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_SHINX_2:
# 955 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_SHINX, 10, ITEM_NONE
# 956 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_SHINX_5
# 963 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_SHINX_6
# 971 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 972 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_SHINX_1

TsuiLab_EventScript_SHINX_5:
# 957 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 958 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SHINX_Text_1
# 959 "data/maps/TsuiLab/scripts.pory"
	removeobject 1
# 960 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_1_USED
# 961 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_SHINX_1

TsuiLab_EventScript_SHINX_6:
# 964 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 965 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_SHINX_Text_1
# 966 "data/maps/TsuiLab/scripts.pory"
	removeobject 1
# 967 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_1_USED
# 968 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_SHINX_1


TsuiLab_EventScript_TOGEPI::
# 986 "data/maps/TsuiLab/scripts.pory"
	lockall
# 987 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_TOGEPI, 10, 3
# 988 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TOGEPI_Text_0, MSGBOX_YESNO
# 989 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_TOGEPI_2
# 1011 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1012 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_TOGEPI_1:
# 1014 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 1015 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_TOGEPI_2:
# 990 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_TOGEPI, 10, ITEM_NONE
# 991 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_TOGEPI_5
# 998 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_TOGEPI_6
# 1006 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1007 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_TOGEPI_1

TsuiLab_EventScript_TOGEPI_5:
# 992 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 993 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TOGEPI_Text_1
# 994 "data/maps/TsuiLab/scripts.pory"
	removeobject 2
# 995 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_2_USED
# 996 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_TOGEPI_1

TsuiLab_EventScript_TOGEPI_6:
# 999 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1000 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TOGEPI_Text_1
# 1001 "data/maps/TsuiLab/scripts.pory"
	removeobject 2
# 1002 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_2_USED
# 1003 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_TOGEPI_1


TsuiLab_EventScript_ROOKIDEE::
# 1021 "data/maps/TsuiLab/scripts.pory"
	lockall
# 1022 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_ROOKIDEE, 10, 3
# 1023 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ROOKIDEE_Text_0, MSGBOX_YESNO
# 1024 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_ROOKIDEE_2
# 1046 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1047 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_ROOKIDEE_1:
# 1049 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 1050 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_ROOKIDEE_2:
# 1025 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_ROOKIDEE, 10, ITEM_NONE
# 1026 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_ROOKIDEE_5
# 1033 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_ROOKIDEE_6
# 1041 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1042 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_ROOKIDEE_1

TsuiLab_EventScript_ROOKIDEE_5:
# 1027 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1028 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ROOKIDEE_Text_1
# 1029 "data/maps/TsuiLab/scripts.pory"
	removeobject 3
# 1030 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_3_USED
# 1031 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_ROOKIDEE_1

TsuiLab_EventScript_ROOKIDEE_6:
# 1034 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1035 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_ROOKIDEE_Text_1
# 1036 "data/maps/TsuiLab/scripts.pory"
	removeobject 3
# 1037 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_3_USED
# 1038 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_ROOKIDEE_1


TsuiLab_EventScript_TOXEL::
# 1056 "data/maps/TsuiLab/scripts.pory"
	lockall
# 1057 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_TOXEL, 10, 3
# 1058 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TOXEL_Text_0, MSGBOX_YESNO
# 1059 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_TOXEL_2
# 1081 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1082 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_TOXEL_1:
# 1084 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 1085 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_TOXEL_2:
# 1060 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_TOXEL, 10, ITEM_NONE
# 1061 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_TOXEL_5
# 1068 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_TOXEL_6
# 1076 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1077 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_TOXEL_1

TsuiLab_EventScript_TOXEL_5:
# 1062 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1063 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TOXEL_Text_1
# 1064 "data/maps/TsuiLab/scripts.pory"
	removeobject 4
# 1065 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_4_USED
# 1066 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_TOXEL_1

TsuiLab_EventScript_TOXEL_6:
# 1069 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1070 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_TOXEL_Text_1
# 1071 "data/maps/TsuiLab/scripts.pory"
	removeobject 4
# 1072 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_4_USED
# 1073 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_TOXEL_1


TsuiLab_EventScript_DEDENNE::
# 1091 "data/maps/TsuiLab/scripts.pory"
	lockall
# 1092 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_DEDENNE, 10, 3
# 1093 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_DEDENNE_Text_0, MSGBOX_YESNO
# 1094 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_DEDENNE_2
# 1116 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1117 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_DEDENNE_1:
# 1119 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 1120 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_DEDENNE_2:
# 1095 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_DEDENNE, 10, ITEM_NONE
# 1096 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_DEDENNE_5
# 1103 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_DEDENNE_6
# 1111 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1112 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_DEDENNE_1

TsuiLab_EventScript_DEDENNE_5:
# 1097 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1098 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_DEDENNE_Text_1
# 1099 "data/maps/TsuiLab/scripts.pory"
	removeobject 5
# 1100 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_5_USED
# 1101 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_DEDENNE_1

TsuiLab_EventScript_DEDENNE_6:
# 1104 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1105 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_DEDENNE_Text_1
# 1106 "data/maps/TsuiLab/scripts.pory"
	removeobject 5
# 1107 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_5_USED
# 1108 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_DEDENNE_1


TsuiLab_EventScript_DEWPIDER::
# 1126 "data/maps/TsuiLab/scripts.pory"
	lockall
# 1127 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_DEWPIDER, 10, 3
# 1128 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_DEWPIDER_Text_0, MSGBOX_YESNO
# 1129 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_DEWPIDER_2
# 1151 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1152 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_DEWPIDER_1:
# 1154 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 1155 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_DEWPIDER_2:
# 1130 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_DEWPIDER, 10, ITEM_NONE
# 1131 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_DEWPIDER_5
# 1138 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_DEWPIDER_6
# 1146 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1147 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_DEWPIDER_1

TsuiLab_EventScript_DEWPIDER_5:
# 1132 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1133 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_DEWPIDER_Text_1
# 1134 "data/maps/TsuiLab/scripts.pory"
	removeobject 6
# 1135 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_6_USED
# 1136 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_DEWPIDER_1

TsuiLab_EventScript_DEWPIDER_6:
# 1139 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1140 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_DEWPIDER_Text_1
# 1141 "data/maps/TsuiLab/scripts.pory"
	removeobject 6
# 1142 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_6_USED
# 1143 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_DEWPIDER_1


TsuiLab_EventScript_IGGLYBUFF::
# 1161 "data/maps/TsuiLab/scripts.pory"
	lockall
# 1162 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_IGGLYBUFF, 10, 3
# 1163 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_IGGLYBUFF_Text_0, MSGBOX_YESNO
# 1164 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_IGGLYBUFF_2
# 1186 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1187 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_IGGLYBUFF_1:
# 1189 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 1190 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_IGGLYBUFF_2:
# 1165 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_IGGLYBUFF, 10, ITEM_NONE
# 1166 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_IGGLYBUFF_5
# 1173 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_IGGLYBUFF_6
# 1181 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1182 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_IGGLYBUFF_1

TsuiLab_EventScript_IGGLYBUFF_5:
# 1167 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1168 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_IGGLYBUFF_Text_1
# 1169 "data/maps/TsuiLab/scripts.pory"
	removeobject 7
# 1170 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_7_USED
# 1171 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_IGGLYBUFF_1

TsuiLab_EventScript_IGGLYBUFF_6:
# 1174 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1175 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_IGGLYBUFF_Text_1
# 1176 "data/maps/TsuiLab/scripts.pory"
	removeobject 7
# 1177 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_7_USED
# 1178 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_IGGLYBUFF_1


TsuiLab_EventScript_NYMBLE::
# 1196 "data/maps/TsuiLab/scripts.pory"
	lockall
# 1197 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_NYMBLE, 10, 3
# 1198 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_NYMBLE_Text_0, MSGBOX_YESNO
# 1199 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_NYMBLE_2
# 1221 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1222 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_NYMBLE_1:
# 1224 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 1225 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_NYMBLE_2:
# 1200 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_NYMBLE, 10, ITEM_NONE
# 1201 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_NYMBLE_5
# 1208 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_NYMBLE_6
# 1216 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1217 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_NYMBLE_1

TsuiLab_EventScript_NYMBLE_5:
# 1202 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1203 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_NYMBLE_Text_1
# 1204 "data/maps/TsuiLab/scripts.pory"
	removeobject 8
# 1205 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_8_USED
# 1206 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_NYMBLE_1

TsuiLab_EventScript_NYMBLE_6:
# 1209 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1210 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_NYMBLE_Text_1
# 1211 "data/maps/TsuiLab/scripts.pory"
	removeobject 8
# 1212 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_8_USED
# 1213 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_NYMBLE_1


TsuiLab_EventScript_PORYGON::
# 1231 "data/maps/TsuiLab/scripts.pory"
	lockall
# 1232 "data/maps/TsuiLab/scripts.pory"
	showmonpic SPECIES_PORYGON, 10, 3
# 1233 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PORYGON_Text_0, MSGBOX_YESNO
# 1234 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TsuiLab_EventScript_PORYGON_2
# 1256 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1257 "data/maps/TsuiLab/scripts.pory"
	msgbox NewProfessor_NotChosen
TsuiLab_EventScript_PORYGON_1:
# 1259 "data/maps/TsuiLab/scripts.pory"
	waitmessage
# 1260 "data/maps/TsuiLab/scripts.pory"
	releaseall
	end

TsuiLab_EventScript_PORYGON_2:
# 1235 "data/maps/TsuiLab/scripts.pory"
	givemon SPECIES_PORYGON, 10, ITEM_NONE
# 1236 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TsuiLab_EventScript_PORYGON_5
# 1243 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TsuiLab_EventScript_PORYGON_6
# 1251 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1252 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_RIOLU_Text_2
	goto TsuiLab_EventScript_PORYGON_1

TsuiLab_EventScript_PORYGON_5:
# 1237 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1238 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PORYGON_Text_1
# 1239 "data/maps/TsuiLab/scripts.pory"
	removeobject 9
# 1240 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_9_USED
# 1241 "data/maps/TsuiLab/scripts.pory"
	call NicknamePartyMon
	goto TsuiLab_EventScript_PORYGON_1

TsuiLab_EventScript_PORYGON_6:
# 1244 "data/maps/TsuiLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1245 "data/maps/TsuiLab/scripts.pory"
	msgbox TsuiLab_EventScript_PORYGON_Text_1
# 1246 "data/maps/TsuiLab/scripts.pory"
	removeobject 9
# 1247 "data/maps/TsuiLab/scripts.pory"
	setflag FLAG_BALL_9_USED
# 1248 "data/maps/TsuiLab/scripts.pory"
	call NicknameBoxMon
	goto TsuiLab_EventScript_PORYGON_1


NicknamePartyMon::
# 1266 "data/maps/TsuiLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 1267 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1268 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 1269 "data/maps/TsuiLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1270 "data/maps/TsuiLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 1278 "data/maps/TsuiLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 1279 "data/maps/TsuiLab/scripts.pory"
	hidemonpic
# 1280 "data/maps/TsuiLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 1283 "data/maps/TsuiLab/scripts.pory"
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
# 1281 "data/maps/TsuiLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


TsuiLab_Trigger_FirstTest_Text_0:
# 33 "data/maps/TsuiLab/scripts.pory"
	.string "PROF. TSUI: HEY WAIT!$"

TsuiLab_Trigger_FirstTest_Text_1:
# 38 "data/maps/TsuiLab/scripts.pory"
	.string "PROF. TSUI: Meet me at the back of my\n"
	.string "lab before you leave LITTLEROOT TOWN\l"
	.string "so I can prepare you for your journey.$"

StopLeaving_Text_0:
# 90 "data/maps/TsuiLab/scripts.pory"
	.string "You need to choose your POKéMON and\n"
	.string "let PROF. TSUI know afterwards.$"

TsuiLab_EventScript_Tsui_Text_0:
# 104 "data/maps/TsuiLab/scripts.pory"
	.string "PROF. TSUI: Hello, would you like to see\n"
	.string "more?$"

TsuiLab_EventScript_Tsui_Text_1:
# 112 "data/maps/TsuiLab/scripts.pory"
	.string "PROF. TSUI: Choose your POKéMON wisely.$"

TsuiLab_EventScript_Tsui_Text_2:
# 119 "data/maps/TsuiLab/scripts.pory"
	.string "PROF. TSUI: You made some great\n"
	.string "choices! Take care of your POKéMON.$"

TsuiLab_EventScript_PokeballOne_Text_0:
# 144 "data/maps/TsuiLab/scripts.pory"
	.string "Don't take another.$"

TsuiLab_EventScript_RIOLU_Text_0:
# 323 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose RIOLU?$"

TsuiLab_EventScript_RIOLU_Text_1:
# 328 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved RIOLU.$"

TsuiLab_EventScript_RIOLU_Text_2:
# 342 "data/maps/TsuiLab/scripts.pory"
	.string "No more room in party.$"

TsuiLab_EventScript_ROCKRUFF_Text_0:
# 358 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose ROCKRUFF?$"

TsuiLab_EventScript_ROCKRUFF_Text_1:
# 363 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved ROCKRUFF.$"

TsuiLab_EventScript_SHROOMISH_Text_0:
# 393 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose SHROOMISH?$"

TsuiLab_EventScript_SHROOMISH_Text_1:
# 398 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved SHROOMISH.$"

TsuiLab_EventScript_SEWADDLE_Text_0:
# 428 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose SEWADDLE?$"

TsuiLab_EventScript_SEWADDLE_Text_1:
# 433 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved SEWADDLE.$"

TsuiLab_EventScript_EEVEE_Text_0:
# 463 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose EEVEE?$"

TsuiLab_EventScript_EEVEE_Text_1:
# 468 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved EEVEE.$"

TsuiLab_EventScript_STARYU_Text_0:
# 498 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose STARYU?$"

TsuiLab_EventScript_STARYU_Text_1:
# 503 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved STARYU.$"

TsuiLab_EventScript_STUNFISK_Text_0:
# 533 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose STUNFISK?$"

TsuiLab_EventScript_STUNFISK_Text_1:
# 538 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved STUNFISK.$"

TsuiLab_EventScript_BLIPBUG_Text_0:
# 568 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose BLIPBUG?$"

TsuiLab_EventScript_BLIPBUG_Text_1:
# 573 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved BLIPBUG.$"

TsuiLab_EventScript_GLIGAR_Text_0:
# 603 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose GLIGAR?$"

TsuiLab_EventScript_GLIGAR_Text_1:
# 608 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved GLIGAR.$"

TsuiLab_EventScript_WHISMUR_Text_0:
# 638 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose WHISMUR?$"

TsuiLab_EventScript_WHISMUR_Text_1:
# 643 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved WHISMUR.$"

TsuiLab_EventScript_PIKACHU_Text_0:
# 673 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose PIKACHU?$"

TsuiLab_EventScript_PIKACHU_Text_1:
# 678 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved PIKACHU.$"

TsuiLab_EventScript_FLETCHLING_Text_0:
# 708 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose FLETCHLING?$"

TsuiLab_EventScript_FLETCHLING_Text_1:
# 713 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved FLETCHLING.$"

TsuiLab_EventScript_MUNNA_Text_0:
# 743 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose MUNNA?$"

TsuiLab_EventScript_MUNNA_Text_1:
# 748 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved MUNNA.$"

TsuiLab_EventScript_TADBULB_Text_0:
# 778 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose TADBULB?$"

TsuiLab_EventScript_TADBULB_Text_1:
# 783 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved TADBULB.$"

TsuiLab_EventScript_ESPURR_Text_0:
# 813 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose ESPURR?$"

TsuiLab_EventScript_ESPURR_Text_1:
# 818 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved ESPURR.$"

TsuiLab_EventScript_BUIZEL_Text_0:
# 848 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose BUIZEL?$"

TsuiLab_EventScript_BUIZEL_Text_1:
# 853 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved BUIZEL.$"

TsuiLab_EventScript_BOUNSWEET_Text_0:
# 883 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose BOUNSWEET?$"

TsuiLab_EventScript_BOUNSWEET_Text_1:
# 888 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved BOUNSWEET.$"

TsuiLab_EventScript_CHARCADET_Text_0:
# 918 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose CHARCADET?$"

TsuiLab_EventScript_CHARCADET_Text_1:
# 923 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved CHARCADET.$"

TsuiLab_EventScript_SHINX_Text_0:
# 953 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose SHINX?$"

TsuiLab_EventScript_SHINX_Text_1:
# 958 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved SHINX.$"

TsuiLab_EventScript_TOGEPI_Text_0:
# 988 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose TOGEPI?$"

TsuiLab_EventScript_TOGEPI_Text_1:
# 993 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved TOGEPI.$"

TsuiLab_EventScript_ROOKIDEE_Text_0:
# 1023 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose ROOKIDEE?$"

TsuiLab_EventScript_ROOKIDEE_Text_1:
# 1028 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved ROOKIDEE.$"

TsuiLab_EventScript_TOXEL_Text_0:
# 1058 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose TOXEL?$"

TsuiLab_EventScript_TOXEL_Text_1:
# 1063 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved TOXEL.$"

TsuiLab_EventScript_DEDENNE_Text_0:
# 1093 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose DEDENNE?$"

TsuiLab_EventScript_DEDENNE_Text_1:
# 1098 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved DEDENNE.$"

TsuiLab_EventScript_DEWPIDER_Text_0:
# 1128 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose DEWPIDER?$"

TsuiLab_EventScript_DEWPIDER_Text_1:
# 1133 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved DEWPIDER.$"

TsuiLab_EventScript_IGGLYBUFF_Text_0:
# 1163 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose IGGLYBUFF?$"

TsuiLab_EventScript_IGGLYBUFF_Text_1:
# 1168 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved IGGLYBUFF.$"

TsuiLab_EventScript_NYMBLE_Text_0:
# 1198 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose NYMBLE?$"

TsuiLab_EventScript_NYMBLE_Text_1:
# 1203 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved NYMBLE.$"

TsuiLab_EventScript_PORYGON_Text_0:
# 1233 "data/maps/TsuiLab/scripts.pory"
	.string "Do you want to choose PORYGON?$"

TsuiLab_EventScript_PORYGON_Text_1:
# 1238 "data/maps/TsuiLab/scripts.pory"
	.string "Recieved PORYGON.$"

NicknamePartyMon_Text_0:
# 1266 "data/maps/TsuiLab/scripts.pory"
	.string "Give it a nickname?$"

BeginAdventureText::
# 78 "data/maps/TsuiLab/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}PROF. TSUI:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} Hello {PLAYER}, my name is\n"
	.string "PROF. TSUI.\n"
	.string "This is my lab.\p"
	.string "Today is the day that you will be\n"
	.string "receiving three POKéMON.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Now choose wisely.\n"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}If you would like to see more options\l"
	.string "come and talk to me.\n"
	.string "$"

NewProfessor_NotChosen::
# 1287 "data/maps/TsuiLab/scripts.pory"
	.string "You did not choose the POKéMON.$"
