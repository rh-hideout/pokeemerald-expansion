# 2 "data/maps/MtPyre_5F/scripts.pory"

# 3 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_5F_MapScripts::
# 4 "data/maps/MtPyre_5F/scripts.pory"
map_script MAP_SCRIPT_ON_RESUME, MtPyre_5f_OnResume
# 5 "data/maps/MtPyre_5F/scripts.pory"

# 6 "data/maps/MtPyre_5F/scripts.pory"
	.byte 0
# 7 "data/maps/MtPyre_5F/scripts.pory"

# 8 "data/maps/MtPyre_5F/scripts.pory"
@ Seems like the scripts for the 4F and 5F were swapped
# 9 "data/maps/MtPyre_5F/scripts.pory"

# 10 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_4F_EventScript_Tasha::
# 11 "data/maps/MtPyre_5F/scripts.pory"
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
# 12 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/MtPyre_5F/scripts.pory"
	end
# 14 "data/maps/MtPyre_5F/scripts.pory"

# 15 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_4F_Text_TashaIntro:
# 16 "data/maps/MtPyre_5F/scripts.pory"
	.string "I love all things horrifying…\n"
# 17 "data/maps/MtPyre_5F/scripts.pory"
	.string "It's like a disease…\p"
# 18 "data/maps/MtPyre_5F/scripts.pory"
	.string "When I'm here…\n"
# 19 "data/maps/MtPyre_5F/scripts.pory"
	.string "I shiver with fear…$"
# 20 "data/maps/MtPyre_5F/scripts.pory"

# 21 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_4F_Text_TashaDefeat:
# 22 "data/maps/MtPyre_5F/scripts.pory"
	.string "Losing, I dislike…$"
# 23 "data/maps/MtPyre_5F/scripts.pory"

# 24 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_4F_Text_TashaPostBattle:
# 25 "data/maps/MtPyre_5F/scripts.pory"
	.string "I want to see dreadful things…\n"
# 26 "data/maps/MtPyre_5F/scripts.pory"
	.string "I can't leave…\p"
# 27 "data/maps/MtPyre_5F/scripts.pory"
	.string "Stay…\n"
# 28 "data/maps/MtPyre_5F/scripts.pory"
	.string "Won't you stay with me?$"
# 29 "data/maps/MtPyre_5F/scripts.pory"

# 30 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_5f_OnResume:
# 31 "data/maps/MtPyre_5F/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_5f_EventScript_TryRemoveDialga
# 32 "data/maps/MtPyre_5F/scripts.pory"
    end
# 33 "data/maps/MtPyre_5F/scripts.pory"

# 34 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_5f_EventScript_TryRemoveDialga::
# 35 "data/maps/MtPyre_5F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/MtPyre_5F/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 37 "data/maps/MtPyre_5F/scripts.pory"
    removeobject VAR_LAST_TALKED
# 38 "data/maps/MtPyre_5F/scripts.pory"
    return
# 39 "data/maps/MtPyre_5F/scripts.pory"

# 40 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_5f_EventScript_Dialga::
# 41 "data/maps/MtPyre_5F/scripts.pory"
    lock
# 42 "data/maps/MtPyre_5F/scripts.pory"
    faceplayer
# 43 "data/maps/MtPyre_5F/scripts.pory"
    waitse
# 44 "data/maps/MtPyre_5F/scripts.pory"
    playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
# 45 "data/maps/MtPyre_5F/scripts.pory"
    delay 40
# 46 "data/maps/MtPyre_5F/scripts.pory"
    waitmoncry
# 47 "data/maps/MtPyre_5F/scripts.pory"
    setwildbattle SPECIES_DIALGA, 50
# 48 "data/maps/MtPyre_5F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 49 "data/maps/MtPyre_5F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 50 "data/maps/MtPyre_5F/scripts.pory"
    waitstate
# 51 "data/maps/MtPyre_5F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 52 "data/maps/MtPyre_5F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 53 "data/maps/MtPyre_5F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtPyre_5f_EventScript_DefeatedDialga
# 54 "data/maps/MtPyre_5F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtPyre_5f_EventScript_RanFromDialga
# 55 "data/maps/MtPyre_5F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtPyre_5f_EventScript_RanFromDialga
# 56 "data/maps/MtPyre_5F/scripts.pory"
    setflag FLAG_DEFEATED_DIALGA
# 57 "data/maps/MtPyre_5F/scripts.pory"
    release
# 58 "data/maps/MtPyre_5F/scripts.pory"
    end
# 59 "data/maps/MtPyre_5F/scripts.pory"

# 60 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_5f_EventScript_DefeatedDialga::
# 61 "data/maps/MtPyre_5F/scripts.pory"
    setflag FLAG_DEFEATED_DIALGA
# 62 "data/maps/MtPyre_5F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 63 "data/maps/MtPyre_5F/scripts.pory"
    end
# 64 "data/maps/MtPyre_5F/scripts.pory"

# 65 "data/maps/MtPyre_5F/scripts.pory"
MtPyre_5f_EventScript_RanFromDialga::
# 66 "data/maps/MtPyre_5F/scripts.pory"
    setvar VAR_0x8004, SPECIES_DIALGA
# 67 "data/maps/MtPyre_5F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 68 "data/maps/MtPyre_5F/scripts.pory"
    end
