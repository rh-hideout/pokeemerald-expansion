# 1 "data/maps/MtPyre_4F/scripts.pory"

# 2 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_MapScripts::
# 3 "data/maps/MtPyre_4F/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, MtPyre_4f_OnResume
# 4 "data/maps/MtPyre_4F/scripts.pory"
	.byte 0
# 5 "data/maps/MtPyre_4F/scripts.pory"

# 6 "data/maps/MtPyre_4F/scripts.pory"
@ Seems like the scripts for the 4F and 5F were swapped
# 7 "data/maps/MtPyre_4F/scripts.pory"

# 8 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_5F_EventScript_Atsushi::
# 9 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
# 10 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
# 11 "data/maps/MtPyre_4F/scripts.pory"
	end
# 12 "data/maps/MtPyre_4F/scripts.pory"

# 13 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_5F_Text_AtsushiIntro:
# 14 "data/maps/MtPyre_4F/scripts.pory"
	.string "Teacher…\n"
# 15 "data/maps/MtPyre_4F/scripts.pory"
	.string "Please watch over my progress!$"
# 16 "data/maps/MtPyre_4F/scripts.pory"

# 17 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_5F_Text_AtsushiDefeat:
# 18 "data/maps/MtPyre_4F/scripts.pory"
	.string "Teacher…\n"
# 19 "data/maps/MtPyre_4F/scripts.pory"
	.string "Please forgive me!$"
# 20 "data/maps/MtPyre_4F/scripts.pory"

# 21 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_5F_Text_AtsushiPostBattle:
# 22 "data/maps/MtPyre_4F/scripts.pory"
	.string "Until I improve, my teacher, who rests\n"
# 23 "data/maps/MtPyre_4F/scripts.pory"
	.string "here, will never find true peace…$"
# 24 "data/maps/MtPyre_4F/scripts.pory"

# 25 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4f_OnResume:
# 26 "data/maps/MtPyre_4F/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_4f_EventScript_TryRemovePalkia
# 27 "data/maps/MtPyre_4F/scripts.pory"
    end
# 28 "data/maps/MtPyre_4F/scripts.pory"

# 29 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4f_EventScript_TryRemovePalkia::
# 30 "data/maps/MtPyre_4F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 31 "data/maps/MtPyre_4F/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 32 "data/maps/MtPyre_4F/scripts.pory"
    removeobject VAR_LAST_TALKED
# 33 "data/maps/MtPyre_4F/scripts.pory"
    return
# 34 "data/maps/MtPyre_4F/scripts.pory"

# 35 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4f_EventScript_Palkia::
# 36 "data/maps/MtPyre_4F/scripts.pory"
    lock
# 37 "data/maps/MtPyre_4F/scripts.pory"
    faceplayer
# 38 "data/maps/MtPyre_4F/scripts.pory"
    waitse
# 39 "data/maps/MtPyre_4F/scripts.pory"
    playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
# 40 "data/maps/MtPyre_4F/scripts.pory"
    delay 40
# 41 "data/maps/MtPyre_4F/scripts.pory"
    waitmoncry
# 42 "data/maps/MtPyre_4F/scripts.pory"
    setwildbattle SPECIES_PALKIA, 50
# 43 "data/maps/MtPyre_4F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 44 "data/maps/MtPyre_4F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 45 "data/maps/MtPyre_4F/scripts.pory"
    waitstate
# 46 "data/maps/MtPyre_4F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 47 "data/maps/MtPyre_4F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 48 "data/maps/MtPyre_4F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtPyre_4f_EventScript_DefeatedPalkia
# 49 "data/maps/MtPyre_4F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtPyre_4f_EventScript_RanFromPalkia
# 50 "data/maps/MtPyre_4F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtPyre_4f_EventScript_RanFromPalkia
# 51 "data/maps/MtPyre_4F/scripts.pory"
    setflag FLAG_DEFEATED_PALKIA
# 52 "data/maps/MtPyre_4F/scripts.pory"
    release
# 53 "data/maps/MtPyre_4F/scripts.pory"
    end
# 54 "data/maps/MtPyre_4F/scripts.pory"

# 55 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4f_EventScript_DefeatedPalkia::
# 56 "data/maps/MtPyre_4F/scripts.pory"
    setflag FLAG_DEFEATED_PALKIA
# 57 "data/maps/MtPyre_4F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 58 "data/maps/MtPyre_4F/scripts.pory"
    end
# 59 "data/maps/MtPyre_4F/scripts.pory"

# 60 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4f_EventScript_RanFromPalkia::
# 61 "data/maps/MtPyre_4F/scripts.pory"
    setvar VAR_0x8004, SPECIES_PALKIA
# 62 "data/maps/MtPyre_4F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 63 "data/maps/MtPyre_4F/scripts.pory"
    end
