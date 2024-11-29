# 1 "data/maps/Route127/scripts.pory"

# 2 "data/maps/Route127/scripts.pory"
Route127_MapScripts::
# 3 "data/maps/Route127/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route127_OnTransition
# 4 "data/maps/Route127/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route127_OnLoad
# 5 "data/maps/Route127/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route127_OnFrame
# 6 "data/maps/Route127/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, Route127_OnResume
# 7 "data/maps/Route127/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, Route127_OnResume1
# 8 "data/maps/Route127/scripts.pory"
	.byte 0
# 9 "data/maps/Route127/scripts.pory"

# 10 "data/maps/Route127/scripts.pory"
Route127_OnTransition:
# 11 "data/maps/Route127/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 12 "data/maps/Route127/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 13 "data/maps/Route127/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_NORTH, AbnormalWeather_StartKyogreWeather
# 14 "data/maps/Route127/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_SOUTH, AbnormalWeather_StartKyogreWeather
# 15 "data/maps/Route127/scripts.pory"
	end
# 16 "data/maps/Route127/scripts.pory"

# 17 "data/maps/Route127/scripts.pory"
Route127_OnLoad:
# 18 "data/maps/Route127/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute127North
# 19 "data/maps/Route127/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute127South
# 20 "data/maps/Route127/scripts.pory"
	end
# 21 "data/maps/Route127/scripts.pory"

# 22 "data/maps/Route127/scripts.pory"
Route127_OnFrame:
# 23 "data/maps/Route127/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 24 "data/maps/Route127/scripts.pory"
	.2byte 0
# 25 "data/maps/Route127/scripts.pory"

# 26 "data/maps/Route127/scripts.pory"
Route127_EventScript_Camden::
# 27 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_CAMDEN, Route127_Text_CamdenIntro, Route127_Text_CamdenDefeat
# 28 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_CamdenPostBattle, MSGBOX_AUTOCLOSE
# 29 "data/maps/Route127/scripts.pory"
	end
# 30 "data/maps/Route127/scripts.pory"

# 31 "data/maps/Route127/scripts.pory"
Route127_EventScript_Donny::
# 32 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_DONNY, Route127_Text_DonnyIntro, Route127_Text_DonnyDefeat
# 33 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_DonnyPostBattle, MSGBOX_AUTOCLOSE
# 34 "data/maps/Route127/scripts.pory"
	end
# 35 "data/maps/Route127/scripts.pory"

# 36 "data/maps/Route127/scripts.pory"
Route127_EventScript_Jonah::
# 37 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_JONAH, Route127_Text_JonahIntro, Route127_Text_JonahDefeat
# 38 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
# 39 "data/maps/Route127/scripts.pory"
	end
# 40 "data/maps/Route127/scripts.pory"

# 41 "data/maps/Route127/scripts.pory"
Route127_EventScript_Henry::
# 42 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_HENRY, Route127_Text_HenryIntro, Route127_Text_HenryDefeat
# 43 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_HenryPostBattle, MSGBOX_AUTOCLOSE
# 44 "data/maps/Route127/scripts.pory"
	end
# 45 "data/maps/Route127/scripts.pory"

# 46 "data/maps/Route127/scripts.pory"
Route127_EventScript_Roger::
# 47 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_ROGER, Route127_Text_RogerIntro, Route127_Text_RogerDefeat
# 48 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_RogerPostBattle, MSGBOX_AUTOCLOSE
# 49 "data/maps/Route127/scripts.pory"
	end
# 50 "data/maps/Route127/scripts.pory"

# 51 "data/maps/Route127/scripts.pory"
Route127_EventScript_Aidan::
# 52 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_AIDAN, Route127_Text_AidanIntro, Route127_Text_AidanDefeat
# 53 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_AidanPostBattle, MSGBOX_AUTOCLOSE
# 54 "data/maps/Route127/scripts.pory"
	end
# 55 "data/maps/Route127/scripts.pory"

# 56 "data/maps/Route127/scripts.pory"
Route127_EventScript_Athena::
# 57 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_ATHENA, Route127_Text_AthenaIntro, Route127_Text_AthenaDefeat
# 58 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_AthenaPostBattle, MSGBOX_AUTOCLOSE
# 59 "data/maps/Route127/scripts.pory"
	end
# 60 "data/maps/Route127/scripts.pory"

# 61 "data/maps/Route127/scripts.pory"
Route127_EventScript_Koji::
# 62 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_KOJI_1, Route127_Text_KojiIntro, Route127_Text_KojiDefeat, Route127_EventScript_RegisterKoji
# 63 "data/maps/Route127/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 64 "data/maps/Route127/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route127_EventScript_RematchKoji
# 65 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_KojiPostBattle, MSGBOX_DEFAULT
# 66 "data/maps/Route127/scripts.pory"
	release
# 67 "data/maps/Route127/scripts.pory"
	end
# 68 "data/maps/Route127/scripts.pory"

# 69 "data/maps/Route127/scripts.pory"
Route127_EventScript_RegisterKoji::
# 70 "data/maps/Route127/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 71 "data/maps/Route127/scripts.pory"
	waitmovement 0
# 72 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_KojiRegister, MSGBOX_DEFAULT
# 73 "data/maps/Route127/scripts.pory"
	register_matchcall TRAINER_KOJI_1
# 74 "data/maps/Route127/scripts.pory"
	release
# 75 "data/maps/Route127/scripts.pory"
	end
# 76 "data/maps/Route127/scripts.pory"

# 77 "data/maps/Route127/scripts.pory"
Route127_EventScript_RematchKoji::
# 78 "data/maps/Route127/scripts.pory"
	trainerbattle_rematch TRAINER_KOJI_1, Route127_Text_KojiRematchIntro, Route127_Text_KojiRematchDefeat
# 79 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_KojiPostRematch, MSGBOX_AUTOCLOSE
# 80 "data/maps/Route127/scripts.pory"
	end
# 81 "data/maps/Route127/scripts.pory"

# 82 "data/maps/Route127/scripts.pory"
Route127_OnResume:
# 83 "data/maps/Route127/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route127_EventScript_TryRemoveCresselia
# 84 "data/maps/Route127/scripts.pory"
    end
# 85 "data/maps/Route127/scripts.pory"

# 86 "data/maps/Route127/scripts.pory"
Route127_EventScript_TryRemoveCresselia::
# 87 "data/maps/Route127/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 88 "data/maps/Route127/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 89 "data/maps/Route127/scripts.pory"
    removeobject VAR_LAST_TALKED
# 90 "data/maps/Route127/scripts.pory"
    return
# 91 "data/maps/Route127/scripts.pory"

# 92 "data/maps/Route127/scripts.pory"
Route127_EventScript_Cresselia::
# 93 "data/maps/Route127/scripts.pory"
    lock
# 94 "data/maps/Route127/scripts.pory"
    faceplayer
# 95 "data/maps/Route127/scripts.pory"
    waitse
# 96 "data/maps/Route127/scripts.pory"
    playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
# 97 "data/maps/Route127/scripts.pory"
    delay 40
# 98 "data/maps/Route127/scripts.pory"
    waitmoncry
# 99 "data/maps/Route127/scripts.pory"
    setwildbattle SPECIES_CRESSELIA, 60
# 100 "data/maps/Route127/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 101 "data/maps/Route127/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 102 "data/maps/Route127/scripts.pory"
    waitstate
# 103 "data/maps/Route127/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 104 "data/maps/Route127/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 105 "data/maps/Route127/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route127_EventScript_DefeatedCresselia
# 106 "data/maps/Route127/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route127_EventScript_RanFromCresselia
# 107 "data/maps/Route127/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route127_EventScript_RanFromCresselia
# 108 "data/maps/Route127/scripts.pory"
    setflag FLAG_DEFEATED_CRESSELIA
# 109 "data/maps/Route127/scripts.pory"
    release
# 110 "data/maps/Route127/scripts.pory"
    end
# 111 "data/maps/Route127/scripts.pory"

# 112 "data/maps/Route127/scripts.pory"
Route127_EventScript_DefeatedCresselia::
# 113 "data/maps/Route127/scripts.pory"
    setflag FLAG_DEFEATED_CRESSELIA
# 114 "data/maps/Route127/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 115 "data/maps/Route127/scripts.pory"
    end
# 116 "data/maps/Route127/scripts.pory"

# 117 "data/maps/Route127/scripts.pory"
Route127_EventScript_RanFromCresselia::
# 118 "data/maps/Route127/scripts.pory"
    setvar VAR_0x8004, SPECIES_CRESSELIA
# 119 "data/maps/Route127/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 120 "data/maps/Route127/scripts.pory"
    end
# 121 "data/maps/Route127/scripts.pory"

# 122 "data/maps/Route127/scripts.pory"
Route127_OnResume1:
# 123 "data/maps/Route127/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route127_EventScript_TryRemoveDarkrai
# 124 "data/maps/Route127/scripts.pory"
    end
# 125 "data/maps/Route127/scripts.pory"

# 126 "data/maps/Route127/scripts.pory"
Route127_EventScript_TryRemoveDarkrai::
# 127 "data/maps/Route127/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 128 "data/maps/Route127/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 129 "data/maps/Route127/scripts.pory"
    removeobject VAR_LAST_TALKED
# 130 "data/maps/Route127/scripts.pory"
    return
# 131 "data/maps/Route127/scripts.pory"

# 132 "data/maps/Route127/scripts.pory"
Route127_EventScript_Darkrai::
# 133 "data/maps/Route127/scripts.pory"
    lock
# 134 "data/maps/Route127/scripts.pory"
    faceplayer
# 135 "data/maps/Route127/scripts.pory"
    waitse
# 136 "data/maps/Route127/scripts.pory"
    playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
# 137 "data/maps/Route127/scripts.pory"
    delay 40
# 138 "data/maps/Route127/scripts.pory"
    waitmoncry
# 139 "data/maps/Route127/scripts.pory"
    setwildbattle SPECIES_DARKRAI, 60
# 140 "data/maps/Route127/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 141 "data/maps/Route127/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 142 "data/maps/Route127/scripts.pory"
    waitstate
# 143 "data/maps/Route127/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 144 "data/maps/Route127/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 145 "data/maps/Route127/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route127_EventScript_DefeatedDarkrai
# 146 "data/maps/Route127/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route127_EventScript_RanFromDarkrai
# 147 "data/maps/Route127/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route127_EventScript_RanFromDarkrai
# 148 "data/maps/Route127/scripts.pory"
    setflag FLAG_DEFEATED_DARKRAI
# 149 "data/maps/Route127/scripts.pory"
    release
# 150 "data/maps/Route127/scripts.pory"
    end
# 151 "data/maps/Route127/scripts.pory"

# 152 "data/maps/Route127/scripts.pory"

# 153 "data/maps/Route127/scripts.pory"
Route127_EventScript_DefeatedDarkrai::
# 154 "data/maps/Route127/scripts.pory"
    setflag FLAG_DEFEATED_DARKRAI
# 155 "data/maps/Route127/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 156 "data/maps/Route127/scripts.pory"
    end
# 157 "data/maps/Route127/scripts.pory"

# 158 "data/maps/Route127/scripts.pory"
Route127_EventScript_RanFromDarkrai::
# 159 "data/maps/Route127/scripts.pory"
    setvar VAR_0x8004, SPECIES_DARKRAI
# 160 "data/maps/Route127/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 161 "data/maps/Route127/scripts.pory"
    end
