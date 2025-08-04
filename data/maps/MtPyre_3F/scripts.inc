# 1 "data/maps/MtPyre_3F/scripts.pory"

# 2 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_MapScripts::
# 3 "data/maps/MtPyre_3F/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, MtPyre_3f_OnResume
# 4 "data/maps/MtPyre_3F/scripts.pory"
	.byte 0
# 5 "data/maps/MtPyre_3F/scripts.pory"

# 6 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_EventScript_William::
# 7 "data/maps/MtPyre_3F/scripts.pory"
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
# 8 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
# 9 "data/maps/MtPyre_3F/scripts.pory"
	end
# 10 "data/maps/MtPyre_3F/scripts.pory"

# 11 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_EventScript_Kayla::
# 12 "data/maps/MtPyre_3F/scripts.pory"
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
# 13 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
# 14 "data/maps/MtPyre_3F/scripts.pory"
	end
# 15 "data/maps/MtPyre_3F/scripts.pory"

# 16 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_EventScript_Gabrielle::
# 17 "data/maps/MtPyre_3F/scripts.pory"
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
# 18 "data/maps/MtPyre_3F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 19 "data/maps/MtPyre_3F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
# 20 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
# 21 "data/maps/MtPyre_3F/scripts.pory"
	release
# 22 "data/maps/MtPyre_3F/scripts.pory"
	end
# 23 "data/maps/MtPyre_3F/scripts.pory"

# 24 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_EventScript_RegisterGabrielle::
# 25 "data/maps/MtPyre_3F/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 26 "data/maps/MtPyre_3F/scripts.pory"
	waitmovement 0
# 27 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
# 28 "data/maps/MtPyre_3F/scripts.pory"
	register_matchcall TRAINER_GABRIELLE_1
# 29 "data/maps/MtPyre_3F/scripts.pory"
	release
# 30 "data/maps/MtPyre_3F/scripts.pory"
	end
# 31 "data/maps/MtPyre_3F/scripts.pory"

# 32 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_EventScript_RematchGabrielle::
# 33 "data/maps/MtPyre_3F/scripts.pory"
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
# 34 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
# 35 "data/maps/MtPyre_3F/scripts.pory"
	end
# 36 "data/maps/MtPyre_3F/scripts.pory"

# 37 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_WilliamIntro:
# 38 "data/maps/MtPyre_3F/scripts.pory"
	.string "The rich atmosphere of the mountain\n"
# 39 "data/maps/MtPyre_3F/scripts.pory"
	.string "has elevated my psychic power!\p"
# 40 "data/maps/MtPyre_3F/scripts.pory"
	.string "A mere child like you…\n"
# 41 "data/maps/MtPyre_3F/scripts.pory"
	.string "You dream of winning?$"
# 42 "data/maps/MtPyre_3F/scripts.pory"

# 43 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_WilliamDefeat:
# 44 "data/maps/MtPyre_3F/scripts.pory"
	.string "I drown in self-pity…$"
# 45 "data/maps/MtPyre_3F/scripts.pory"

# 46 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_WilliamPostBattle:
# 47 "data/maps/MtPyre_3F/scripts.pory"
	.string "My psychic powers have surely\n"
# 48 "data/maps/MtPyre_3F/scripts.pory"
	.string "grown several times, but…$"
# 49 "data/maps/MtPyre_3F/scripts.pory"

# 50 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_KaylaIntro:
# 51 "data/maps/MtPyre_3F/scripts.pory"
	.string "Ahahahaha!\p"
# 52 "data/maps/MtPyre_3F/scripts.pory"
	.string "This is no place for children, least\n"
# 53 "data/maps/MtPyre_3F/scripts.pory"
	.string "of all you!$"
# 54 "data/maps/MtPyre_3F/scripts.pory"

# 55 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_KaylaDefeat:
# 56 "data/maps/MtPyre_3F/scripts.pory"
	.string "I lost that cleanly…$"
# 57 "data/maps/MtPyre_3F/scripts.pory"

# 58 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_KaylaPostBattle:
# 59 "data/maps/MtPyre_3F/scripts.pory"
	.string "This means my training is still not\n"
# 60 "data/maps/MtPyre_3F/scripts.pory"
	.string "enough…\p"
# 61 "data/maps/MtPyre_3F/scripts.pory"
	.string "I've got to keep working toward the\n"
# 62 "data/maps/MtPyre_3F/scripts.pory"
	.string "summit…\p"
# 63 "data/maps/MtPyre_3F/scripts.pory"
	.string "Go, me!$"
# 64 "data/maps/MtPyre_3F/scripts.pory"

# 65 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_GabrielleIntro:
# 66 "data/maps/MtPyre_3F/scripts.pory"
	.string "Why have you come here?$"
# 67 "data/maps/MtPyre_3F/scripts.pory"

# 68 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_GabrielleDefeat:
# 69 "data/maps/MtPyre_3F/scripts.pory"
	.string "That was amazing!\n"
# 70 "data/maps/MtPyre_3F/scripts.pory"
	.string "You're a very special TRAINER.$"
# 71 "data/maps/MtPyre_3F/scripts.pory"

# 72 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_GabriellePostBattle:
# 73 "data/maps/MtPyre_3F/scripts.pory"
	.string "POKéMON no longer of this world.\n"
# 74 "data/maps/MtPyre_3F/scripts.pory"
	.string "POKéMON that are with you now.\p"
# 75 "data/maps/MtPyre_3F/scripts.pory"
	.string "And the POKéMON that you will meet\n"
# 76 "data/maps/MtPyre_3F/scripts.pory"
	.string "in the future…\p"
# 77 "data/maps/MtPyre_3F/scripts.pory"
	.string "They are all to be equally cherished.\n"
# 78 "data/maps/MtPyre_3F/scripts.pory"
	.string "Please remember that.$"
# 79 "data/maps/MtPyre_3F/scripts.pory"

# 80 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_GabrielleRegister:
# 81 "data/maps/MtPyre_3F/scripts.pory"
	.string "I would like to see your POKéMON\n"
# 82 "data/maps/MtPyre_3F/scripts.pory"
	.string "when they grow up some more…\p"
# 83 "data/maps/MtPyre_3F/scripts.pory"
	.string "Please, I need to see your POKéNAV.$"
# 84 "data/maps/MtPyre_3F/scripts.pory"

# 85 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_GabrielleRematchIntro:
# 86 "data/maps/MtPyre_3F/scripts.pory"
	.string "Oh, it's you…\p"
# 87 "data/maps/MtPyre_3F/scripts.pory"
	.string "Have you come to show me your grown\n"
# 88 "data/maps/MtPyre_3F/scripts.pory"
	.string "POKéMON?$"
# 89 "data/maps/MtPyre_3F/scripts.pory"

# 90 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_GabrielleRematchDefeat:
# 91 "data/maps/MtPyre_3F/scripts.pory"
	.string "How amazing!\n"
# 92 "data/maps/MtPyre_3F/scripts.pory"
	.string "You are a special person.$"
# 93 "data/maps/MtPyre_3F/scripts.pory"

# 94 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3F_Text_GabriellePostRematch:
# 95 "data/maps/MtPyre_3F/scripts.pory"
	.string "POKéMON no longer of this world.\n"
# 96 "data/maps/MtPyre_3F/scripts.pory"
	.string "POKéMON that are with you now.\p"
# 97 "data/maps/MtPyre_3F/scripts.pory"
	.string "And the POKéMON that you will meet\n"
# 98 "data/maps/MtPyre_3F/scripts.pory"
	.string "in the future…\p"
# 99 "data/maps/MtPyre_3F/scripts.pory"
	.string "They are all to be equally cherished.\n"
# 100 "data/maps/MtPyre_3F/scripts.pory"
	.string "I see that you've remembered that.$"
# 101 "data/maps/MtPyre_3F/scripts.pory"

# 102 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3f_OnResume:
# 103 "data/maps/MtPyre_3F/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_3f_EventScript_TryRemoveGiratina
# 104 "data/maps/MtPyre_3F/scripts.pory"
    end
# 105 "data/maps/MtPyre_3F/scripts.pory"

# 106 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3f_EventScript_TryRemoveGiratina::
# 107 "data/maps/MtPyre_3F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 108 "data/maps/MtPyre_3F/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 109 "data/maps/MtPyre_3F/scripts.pory"
    removeobject VAR_LAST_TALKED
# 110 "data/maps/MtPyre_3F/scripts.pory"
    return
# 111 "data/maps/MtPyre_3F/scripts.pory"

# 112 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3f_EventScript_Giratina::
# 113 "data/maps/MtPyre_3F/scripts.pory"
    lock
# 114 "data/maps/MtPyre_3F/scripts.pory"
    faceplayer
# 115 "data/maps/MtPyre_3F/scripts.pory"
    waitse
# 116 "data/maps/MtPyre_3F/scripts.pory"
    playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
# 117 "data/maps/MtPyre_3F/scripts.pory"
    delay 40
# 118 "data/maps/MtPyre_3F/scripts.pory"
    waitmoncry
# 119 "data/maps/MtPyre_3F/scripts.pory"
    setwildbattle SPECIES_GIRATINA, 50
# 120 "data/maps/MtPyre_3F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 121 "data/maps/MtPyre_3F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 122 "data/maps/MtPyre_3F/scripts.pory"
    waitstate
# 123 "data/maps/MtPyre_3F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 124 "data/maps/MtPyre_3F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 125 "data/maps/MtPyre_3F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtPyre_3f_EventScript_DefeatedGiratina
# 126 "data/maps/MtPyre_3F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtPyre_3f_EventScript_RanFromGiratina
# 127 "data/maps/MtPyre_3F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtPyre_3f_EventScript_RanFromGiratina
# 128 "data/maps/MtPyre_3F/scripts.pory"
    setflag FLAG_DEFEATED_GIRATINA
# 129 "data/maps/MtPyre_3F/scripts.pory"
    release
# 130 "data/maps/MtPyre_3F/scripts.pory"
    end
# 131 "data/maps/MtPyre_3F/scripts.pory"

# 132 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3f_EventScript_DefeatedGiratina::
# 133 "data/maps/MtPyre_3F/scripts.pory"
    setflag FLAG_DEFEATED_GIRATINA
# 134 "data/maps/MtPyre_3F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 135 "data/maps/MtPyre_3F/scripts.pory"
    end
# 136 "data/maps/MtPyre_3F/scripts.pory"

# 137 "data/maps/MtPyre_3F/scripts.pory"
MtPyre_3f_EventScript_RanFromGiratina::
# 138 "data/maps/MtPyre_3F/scripts.pory"
    setvar VAR_0x8004, SPECIES_GIRATINA
# 139 "data/maps/MtPyre_3F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 140 "data/maps/MtPyre_3F/scripts.pory"
    end
