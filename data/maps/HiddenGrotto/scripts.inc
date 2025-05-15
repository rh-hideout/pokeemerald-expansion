HiddenGrotto_MapScripts::
	.byte 0


HiddenGrotto_EventScript_Shaymin::
# 4 "data/maps/HiddenGrotto/scripts.pory"
	msgbox HiddenGrotto_EventScript_Shaymin_Text_0, MSGBOX_AUTOCLOSE
# 5 "data/maps/HiddenGrotto/scripts.pory"
	delay 20
# 6 "data/maps/HiddenGrotto/scripts.pory"
	waitmessage
# 7 "data/maps/HiddenGrotto/scripts.pory"
	lockall
# 8 "data/maps/HiddenGrotto/scripts.pory"
	setflag FLAG_NOCATCHING
# 9 "data/maps/HiddenGrotto/scripts.pory"
	setflag FLAG_NORUNNING
# 10 "data/maps/HiddenGrotto/scripts.pory"
	setflag FLAG_SHAYMIN
# 11 "data/maps/HiddenGrotto/scripts.pory"
	playmoncry SPECIES_SHAYMIN, CRY_MODE_ENCOUNTER
# 12 "data/maps/HiddenGrotto/scripts.pory"
	delay 40
# 13 "data/maps/HiddenGrotto/scripts.pory"
	waitmoncry
# 14 "data/maps/HiddenGrotto/scripts.pory"
	setwildbattle SPECIES_SHAYMIN, 20
# 15 "data/maps/HiddenGrotto/scripts.pory"
	dowildbattle
# 16 "data/maps/HiddenGrotto/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 17 "data/maps/HiddenGrotto/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq HiddenGrotto_EventScript_Shaymin_2
# 20 "data/maps/HiddenGrotto/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq HiddenGrotto_EventScript_Shaymin_3
HiddenGrotto_EventScript_Shaymin_1:
# 23 "data/maps/HiddenGrotto/scripts.pory"
	waitmessage
# 24 "data/maps/HiddenGrotto/scripts.pory"
	releaseall
	return

HiddenGrotto_EventScript_Shaymin_2:
# 18 "data/maps/HiddenGrotto/scripts.pory"
	call Won_or_Caught
	goto HiddenGrotto_EventScript_Shaymin_1

HiddenGrotto_EventScript_Shaymin_3:
# 21 "data/maps/HiddenGrotto/scripts.pory"
	call RanAway
	goto HiddenGrotto_EventScript_Shaymin_1


Won_or_Caught::
# 28 "data/maps/HiddenGrotto/scripts.pory"
	fadescreen FADE_TO_BLACK
# 29 "data/maps/HiddenGrotto/scripts.pory"
	removeobject 2
# 30 "data/maps/HiddenGrotto/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 31 "data/maps/HiddenGrotto/scripts.pory"
	clearflag FLAG_NOCATCHING
# 32 "data/maps/HiddenGrotto/scripts.pory"
	clearflag FLAG_NORUNNING
# 33 "data/maps/HiddenGrotto/scripts.pory"
	giveitem ITEM_LEPPA_BERRY
# 34 "data/maps/HiddenGrotto/scripts.pory"
	giveitem ITEM_SITRUS_BERRY
# 35 "data/maps/HiddenGrotto/scripts.pory"
	giveitem ITEM_STARDUST
# 36 "data/maps/HiddenGrotto/scripts.pory"
	giveitem ITEM_SWIFT_FEATHER
# 37 "data/maps/HiddenGrotto/scripts.pory"
	giveitem ITEM_HEAL_BALL
# 38 "data/maps/HiddenGrotto/scripts.pory"
	giveitem ITEM_QUICK_BALL
# 39 "data/maps/HiddenGrotto/scripts.pory"
	giveitem ITEM_CALCIUM
# 40 "data/maps/HiddenGrotto/scripts.pory"
	giveitem ITEM_PP_UP
	return


RanAway::
# 45 "data/maps/HiddenGrotto/scripts.pory"
	playmoncry SPECIES_SHAYMIN, CRY_MODE_ENCOUNTER
# 46 "data/maps/HiddenGrotto/scripts.pory"
	msgbox RanAway_Text_0, MSGBOX_AUTOCLOSE
# 47 "data/maps/HiddenGrotto/scripts.pory"
	delay 20
# 48 "data/maps/HiddenGrotto/scripts.pory"
	fadescreen FADE_TO_BLACK
# 49 "data/maps/HiddenGrotto/scripts.pory"
	removeobject 2
# 50 "data/maps/HiddenGrotto/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 51 "data/maps/HiddenGrotto/scripts.pory"
	clearflag FLAG_NOCATCHING
# 52 "data/maps/HiddenGrotto/scripts.pory"
	clearflag FLAG_NORUNNING
	return


HiddenGrotto_EventScript_Shaymin_Text_0:
# 4 "data/maps/HiddenGrotto/scripts.pory"
	.string "You feel a disturbance in the air...$"

RanAway_Text_0:
# 46 "data/maps/HiddenGrotto/scripts.pory"
	.string "Shayy....$"
