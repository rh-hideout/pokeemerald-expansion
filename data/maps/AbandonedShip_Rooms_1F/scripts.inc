# 1 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 2 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_MapScripts::
# 3 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.byte 0
# 4 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 5 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_EventScript_Gentleman::
# 6 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
# 7 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	end
# 8 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 9 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_EventScript_Demetrius::
# 10 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
# 11 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
# 12 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	end
# 13 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 14 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_EventScript_Thalia::
# 15 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
# 16 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 17 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
# 18 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
# 19 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	release
# 20 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	end
# 21 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 22 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
# 23 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 24 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	waitmovement 0
# 25 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
# 26 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	register_matchcall TRAINER_THALIA_1
# 27 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	release
# 28 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	end
# 29 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 30 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
# 31 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
# 32 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
# 33 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	end
# 34 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 35 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_TakingALookAround:
# 36 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Ships of this sort are rare, so I'm\n"
# 37 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "taking a look around.\p"
# 38 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Hmhm…\n"
# 39 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "There appear to be other cabins…$"
# 40 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 41 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_ThaliaIntro:
# 42 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "What on earth would compel you to\n"
# 43 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "come here? You must be curious!$"
# 44 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 45 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
# 46 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Not just curious, but also strong…$"
# 47 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 48 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
# 49 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "The man next door…\p"
# 50 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "He says he's just sightseeing,\n"
# 51 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "but I don't know about that.$"
# 52 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 53 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_ThaliaRegister:
# 54 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "You're such a tough TRAINER!\n"
# 55 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Let me register you as a memento!$"
# 56 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 57 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
# 58 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "What on earth would compel you to\n"
# 59 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "come back? You must really be curious!$"
# 60 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 61 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
# 62 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Aren't you too strong?$"
# 63 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 64 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
# 65 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "I'm sure that man's up to something!\n"
# 66 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "He just acts so suspiciously!$"
# 67 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 68 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_DemetriusIntro:
# 69 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Waaah!\n"
# 70 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "I've been found! …Huh?$"
# 71 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 72 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
# 73 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Oh, you're not my mom.$"
# 74 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"

# 75 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
# 76 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "I'm in trouble with my mom, so I ran.\n"
# 77 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Keep it a secret where I am!$"
