# 1 "data/maps/Route113/scripts.pory"

# 2 "data/maps/Route113/scripts.pory"
Route113_MapScripts::
# 3 "data/maps/Route113/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route113_OnResume
# 4 "data/maps/Route113/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_OnTransition
# 5 "data/maps/Route113/scripts.pory"
	.byte 0
# 6 "data/maps/Route113/scripts.pory"

# 7 "data/maps/Route113/scripts.pory"
Route113_OnResume:
# 8 "data/maps/Route113/scripts.pory"
	setstepcallback STEP_CB_ASH
# 9 "data/maps/Route113/scripts.pory"
	end
# 10 "data/maps/Route113/scripts.pory"

# 11 "data/maps/Route113/scripts.pory"
Route113_OnTransition:
# 12 "data/maps/Route113/scripts.pory"
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
# 13 "data/maps/Route113/scripts.pory"
	call Route113_EventScript_CheckSetAshWeather
# 14 "data/maps/Route113/scripts.pory"
	end
# 15 "data/maps/Route113/scripts.pory"

# 16 "data/maps/Route113/scripts.pory"
Route113_EventScript_CheckSetAshWeather::
# 17 "data/maps/Route113/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 18 "data/maps/Route113/scripts.pory"
	goto_if_lt VAR_TEMP_0, 19, Route113_EventScript_DontSetAshWeather
# 19 "data/maps/Route113/scripts.pory"
	goto_if_gt VAR_TEMP_0, 84, Route113_EventScript_DontSetAshWeather
# 20 "data/maps/Route113/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 21 "data/maps/Route113/scripts.pory"
	return
# 22 "data/maps/Route113/scripts.pory"

# 23 "data/maps/Route113/scripts.pory"
Route113_EventScript_DontSetAshWeather::
# 24 "data/maps/Route113/scripts.pory"
	return
# 25 "data/maps/Route113/scripts.pory"

# 26 "data/maps/Route113/scripts.pory"
Route113_EventScript_Gentleman::
# 27 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_AshCanBeFashionedIntoGlass, MSGBOX_NPC
# 28 "data/maps/Route113/scripts.pory"
	end
# 29 "data/maps/Route113/scripts.pory"

# 30 "data/maps/Route113/scripts.pory"
Route113_EventScript_NinjaBoy::
# 31 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_FunWalkingThroughAsh, MSGBOX_NPC
# 32 "data/maps/Route113/scripts.pory"
	end
# 33 "data/maps/Route113/scripts.pory"

# 34 "data/maps/Route113/scripts.pory"
Route113_EventScript_RouteSign111::
# 35 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_RouteSign111, MSGBOX_SIGN
# 36 "data/maps/Route113/scripts.pory"
	end
# 37 "data/maps/Route113/scripts.pory"

# 38 "data/maps/Route113/scripts.pory"
Route113_EventScript_RouteSignFallarbor::
# 39 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_RouteSignFallarbor, MSGBOX_SIGN
# 40 "data/maps/Route113/scripts.pory"
	end
# 41 "data/maps/Route113/scripts.pory"

# 42 "data/maps/Route113/scripts.pory"
Route113_EventScript_GlassWorkshopSign::
# 43 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_GlassWorkshopSign, MSGBOX_SIGN
# 44 "data/maps/Route113/scripts.pory"
	end
# 45 "data/maps/Route113/scripts.pory"

# 46 "data/maps/Route113/scripts.pory"
Route113_EventScript_TrainerTipsRegisterKeyItems::
# 47 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_TrainerTipsRegisterKeyItems, MSGBOX_SIGN
# 48 "data/maps/Route113/scripts.pory"
	end
# 49 "data/maps/Route113/scripts.pory"

# 50 "data/maps/Route113/scripts.pory"
Route113_EventScript_Jaylen::
# 51 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_JAYLEN, Route113_Text_JaylenIntro, Route113_Text_JaylenDefeat
# 52 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_JaylenPostBattle, MSGBOX_AUTOCLOSE
# 53 "data/maps/Route113/scripts.pory"
	end
# 54 "data/maps/Route113/scripts.pory"

# 55 "data/maps/Route113/scripts.pory"
Route113_EventScript_Dillon::
# 56 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_DILLON, Route113_Text_DillonIntro, Route113_Text_DillonDefeat
# 57 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_DillonPostBattle, MSGBOX_AUTOCLOSE
# 58 "data/maps/Route113/scripts.pory"
	end
# 59 "data/maps/Route113/scripts.pory"

# 60 "data/maps/Route113/scripts.pory"
Route113_EventScript_Madeline::
# 61 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_MADELINE_1, Route113_Text_MadelineIntro, Route113_Text_MadelineDefeat, Route113_EventScript_RegisterMadeline
# 62 "data/maps/Route113/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 63 "data/maps/Route113/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route113_EventScript_RematchMadeline
# 64 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_MadelinePostBattle, MSGBOX_DEFAULT
# 65 "data/maps/Route113/scripts.pory"
	release
# 66 "data/maps/Route113/scripts.pory"
	end
# 67 "data/maps/Route113/scripts.pory"

# 68 "data/maps/Route113/scripts.pory"
Route113_EventScript_RegisterMadeline::
# 69 "data/maps/Route113/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 70 "data/maps/Route113/scripts.pory"
	waitmovement 0
# 71 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_MadelineRegister, MSGBOX_DEFAULT
# 72 "data/maps/Route113/scripts.pory"
	register_matchcall TRAINER_MADELINE_1
# 73 "data/maps/Route113/scripts.pory"
	release
# 74 "data/maps/Route113/scripts.pory"
	end
# 75 "data/maps/Route113/scripts.pory"

# 76 "data/maps/Route113/scripts.pory"
Route113_EventScript_RematchMadeline::
# 77 "data/maps/Route113/scripts.pory"
	trainerbattle_rematch TRAINER_MADELINE_1, Route113_Text_MadelineRematchIntro, Route113_Text_MadelineRematchDefeat
# 78 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_MadelinePostRematch, MSGBOX_AUTOCLOSE
# 79 "data/maps/Route113/scripts.pory"
	end
# 80 "data/maps/Route113/scripts.pory"

# 81 "data/maps/Route113/scripts.pory"
Route113_EventScript_Lao::
# 82 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_LAO_1, Route113_Text_LaoIntro, Route113_Text_LaoDefeat, Route113_EventScript_RegisterLao
# 83 "data/maps/Route113/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 84 "data/maps/Route113/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route113_EventScript_RematchLao
# 85 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LaoPostBattle, MSGBOX_DEFAULT
# 86 "data/maps/Route113/scripts.pory"
	release
# 87 "data/maps/Route113/scripts.pory"
	end
# 88 "data/maps/Route113/scripts.pory"

# 89 "data/maps/Route113/scripts.pory"
Route113_EventScript_RegisterLao::
# 90 "data/maps/Route113/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 91 "data/maps/Route113/scripts.pory"
	waitmovement 0
# 92 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LaoRegister, MSGBOX_DEFAULT
# 93 "data/maps/Route113/scripts.pory"
	register_matchcall TRAINER_LAO_1
# 94 "data/maps/Route113/scripts.pory"
	release
# 95 "data/maps/Route113/scripts.pory"
	end
# 96 "data/maps/Route113/scripts.pory"

# 97 "data/maps/Route113/scripts.pory"
Route113_EventScript_RematchLao::
# 98 "data/maps/Route113/scripts.pory"
	trainerbattle_rematch TRAINER_LAO_1, Route113_Text_LaoRematchIntro, Route113_Text_LaoRematchDefeat
# 99 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LaoPostRematch, MSGBOX_AUTOCLOSE
# 100 "data/maps/Route113/scripts.pory"
	end
# 101 "data/maps/Route113/scripts.pory"

# 102 "data/maps/Route113/scripts.pory"
Route113_EventScript_Lung::
# 103 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_LUNG, Route113_Text_LungIntro, Route113_Text_LungDefeat
# 104 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LungPostBattle, MSGBOX_AUTOCLOSE
# 105 "data/maps/Route113/scripts.pory"
	end
# 106 "data/maps/Route113/scripts.pory"

# 107 "data/maps/Route113/scripts.pory"
Route113_EventScript_Tori::
# 108 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_TORI_AND_TIA, Route113_Text_ToriIntro, Route113_Text_ToriDefeat, Route113_Text_ToriNotEnoughMons
# 109 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_ToriPostBattle, MSGBOX_AUTOCLOSE
# 110 "data/maps/Route113/scripts.pory"
	end
# 111 "data/maps/Route113/scripts.pory"

# 112 "data/maps/Route113/scripts.pory"
Route113_EventScript_Tia::
# 113 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_TORI_AND_TIA, Route113_Text_TiaIntro, Route113_Text_TiaDefeat, Route113_Text_TiaNotEnoughMons
# 114 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_TiaPostBattle, MSGBOX_AUTOCLOSE
# 115 "data/maps/Route113/scripts.pory"
	end
# 116 "data/maps/Route113/scripts.pory"

# 117 "data/maps/Route113/scripts.pory"
Route113_EventScript_Sophie::
# 118 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_SOPHIE, Route113_Text_SophieIntro, Route113_Text_SophieDefeat
# 119 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_SophiePostBattle, MSGBOX_AUTOCLOSE
# 120 "data/maps/Route113/scripts.pory"
	end
# 121 "data/maps/Route113/scripts.pory"

# 122 "data/maps/Route113/scripts.pory"
Route113_EventScript_Coby::
# 123 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_COBY, Route113_Text_CobyIntro, Route113_Text_CobyDefeat
# 124 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_CobyPostBattle, MSGBOX_AUTOCLOSE
# 125 "data/maps/Route113/scripts.pory"
	end
# 126 "data/maps/Route113/scripts.pory"

# 127 "data/maps/Route113/scripts.pory"
Route113_EventScript_Lawrence::
# 128 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_LAWRENCE, Route113_Text_LawrenceIntro, Route113_Text_LawrenceDefeat
# 129 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LawrencePostBattle, MSGBOX_AUTOCLOSE
# 130 "data/maps/Route113/scripts.pory"
	end
# 131 "data/maps/Route113/scripts.pory"

# 132 "data/maps/Route113/scripts.pory"
Route113_EventScript_Wyatt::
# 133 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_WYATT, Route113_Text_WyattIntro, Route113_Text_WyattDefeat
# 134 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_WyattPostBattle, MSGBOX_AUTOCLOSE
# 135 "data/maps/Route113/scripts.pory"
	end
# 136 "data/maps/Route113/scripts.pory"

# 137 "data/maps/Route113/scripts.pory"
Route113_Text_AshCanBeFashionedIntoGlass:
# 138 "data/maps/Route113/scripts.pory"
	.string "Wahahaha! Today's technology is a\n"
# 139 "data/maps/Route113/scripts.pory"
	.string "wondrous thing!\p"
# 140 "data/maps/Route113/scripts.pory"
	.string "Take this volcanic ash here.\n"
# 141 "data/maps/Route113/scripts.pory"
	.string "It can be fashioned into glass.$"
# 142 "data/maps/Route113/scripts.pory"

# 143 "data/maps/Route113/scripts.pory"
Route113_Text_FunWalkingThroughAsh:
# 144 "data/maps/Route113/scripts.pory"
	.string "It's fun walking through the volcano's\n"
# 145 "data/maps/Route113/scripts.pory"
	.string "ashes on the ground and grass.\p"
# 146 "data/maps/Route113/scripts.pory"
	.string "You can see where you walked--it's\n"
# 147 "data/maps/Route113/scripts.pory"
	.string "really neat!$"
# 148 "data/maps/Route113/scripts.pory"

# 149 "data/maps/Route113/scripts.pory"
Route113_Text_RouteSign111:
# 150 "data/maps/Route113/scripts.pory"
	.string "ROUTE 113\n"
# 151 "data/maps/Route113/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 111$"
# 152 "data/maps/Route113/scripts.pory"

# 153 "data/maps/Route113/scripts.pory"
Route113_Text_RouteSignFallarbor:
# 154 "data/maps/Route113/scripts.pory"
	.string "ROUTE 113\n"
# 155 "data/maps/Route113/scripts.pory"
	.string "{LEFT_ARROW} FALLARBOR TOWN$"
# 156 "data/maps/Route113/scripts.pory"

# 157 "data/maps/Route113/scripts.pory"
Route113_Text_TrainerTipsRegisterKeyItems:
# 158 "data/maps/Route113/scripts.pory"
	.string "TRAINER TIPS\p"
# 159 "data/maps/Route113/scripts.pory"
	.string "You may register one of the KEY ITEMS\n"
# 160 "data/maps/Route113/scripts.pory"
	.string "in your BAG as SELECT.\p"
# 161 "data/maps/Route113/scripts.pory"
	.string "Simply press SELECT to use\n"
# 162 "data/maps/Route113/scripts.pory"
	.string "the registered item conveniently.$"
# 163 "data/maps/Route113/scripts.pory"

# 164 "data/maps/Route113/scripts.pory"
Route113_Text_GlassWorkshopSign:
# 165 "data/maps/Route113/scripts.pory"
	.string "GLASS WORKSHOP\n"
# 166 "data/maps/Route113/scripts.pory"
	.string "“Turning Volcanic Ash into Glass Items”$"
