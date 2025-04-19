# 1 "data/maps/Route114/scripts.pory"

# 2 "data/maps/Route114/scripts.pory"
Route114_MapScripts::
# 3 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
# 4 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
# 5 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
# 6 "data/maps/Route114/scripts.pory"
	.byte 0
# 7 "data/maps/Route114/scripts.pory"

# 8 "data/maps/Route114/scripts.pory"
Route114_OnTransition:
# 9 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 10 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_StartGroudonWeather
# 11 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_StartGroudonWeather
# 12 "data/maps/Route114/scripts.pory"
	end
# 13 "data/maps/Route114/scripts.pory"

# 14 "data/maps/Route114/scripts.pory"
Route114_OnLoad:
# 15 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute114North
# 16 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute114South
# 17 "data/maps/Route114/scripts.pory"
	end
# 18 "data/maps/Route114/scripts.pory"

# 19 "data/maps/Route114/scripts.pory"
Route114_OnFrame:
# 20 "data/maps/Route114/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 21 "data/maps/Route114/scripts.pory"
	.2byte 0
# 22 "data/maps/Route114/scripts.pory"

# 23 "data/maps/Route114/scripts.pory"
Route114_EventScript_Man::
# 24 "data/maps/Route114/scripts.pory"
	lock
# 25 "data/maps/Route114/scripts.pory"
	faceplayer
# 26 "data/maps/Route114/scripts.pory"
	dotimebasedevents
# 27 "data/maps/Route114/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_ReceivedBerry
# 28 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LoveUsingBerryCrushShareBerry, MSGBOX_DEFAULT
# 29 "data/maps/Route114/scripts.pory"
	random NUM_ROUTE_114_MAN_BERRIES
# 30 "data/maps/Route114/scripts.pory"
	addvar VAR_RESULT, NUM_ROUTE_114_MAN_BERRIES_SKIPPED
# 31 "data/maps/Route114/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 32 "data/maps/Route114/scripts.pory"
	giveitem VAR_RESULT
# 33 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 34 "data/maps/Route114/scripts.pory"
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
# 35 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TryBerryCrushWithFriends, MSGBOX_DEFAULT
# 36 "data/maps/Route114/scripts.pory"
	release
# 37 "data/maps/Route114/scripts.pory"
	end
# 38 "data/maps/Route114/scripts.pory"

# 39 "data/maps/Route114/scripts.pory"
Route114_EventScript_ReceivedBerry::
# 40 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FunToThinkAboutBerries, MSGBOX_DEFAULT
# 41 "data/maps/Route114/scripts.pory"
	release
# 42 "data/maps/Route114/scripts.pory"
	end
# 43 "data/maps/Route114/scripts.pory"

# 44 "data/maps/Route114/scripts.pory"
Route114_EventScript_RoarGentleman::
# 45 "data/maps/Route114/scripts.pory"
	lock
# 46 "data/maps/Route114/scripts.pory"
	faceplayer
# 47 "data/maps/Route114/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_ROAR, Route114_EventScript_ReceivedRoar
# 48 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_AllMyMonDoesIsRoarTakeThis, MSGBOX_DEFAULT
# 49 "data/maps/Route114/scripts.pory"
	giveitem ITEM_TM_ROAR
# 50 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 51 "data/maps/Route114/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROAR
# 52 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
# 53 "data/maps/Route114/scripts.pory"
	release
# 54 "data/maps/Route114/scripts.pory"
	end
# 55 "data/maps/Route114/scripts.pory"

# 56 "data/maps/Route114/scripts.pory"
Route114_EventScript_ReceivedRoar::
# 57 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
# 58 "data/maps/Route114/scripts.pory"
	release
# 59 "data/maps/Route114/scripts.pory"
	end
# 60 "data/maps/Route114/scripts.pory"

# 61 "data/maps/Route114/scripts.pory"
Route114_EventScript_Poochyena::
# 62 "data/maps/Route114/scripts.pory"
	lock
# 63 "data/maps/Route114/scripts.pory"
	faceplayer
# 64 "data/maps/Route114/scripts.pory"
	waitse
# 65 "data/maps/Route114/scripts.pory"
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
# 66 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
# 67 "data/maps/Route114/scripts.pory"
	waitmoncry
# 68 "data/maps/Route114/scripts.pory"
	release
# 69 "data/maps/Route114/scripts.pory"
	end
# 70 "data/maps/Route114/scripts.pory"

# 71 "data/maps/Route114/scripts.pory"
Route114_EventScript_MeteorFallsSign::
# 72 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
# 73 "data/maps/Route114/scripts.pory"
	end
# 74 "data/maps/Route114/scripts.pory"

# 75 "data/maps/Route114/scripts.pory"
Route114_EventScript_FossilManiacsHouseSign::
# 76 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
# 77 "data/maps/Route114/scripts.pory"
	end
# 78 "data/maps/Route114/scripts.pory"

# 79 "data/maps/Route114/scripts.pory"
Route114_EventScript_LanettesHouseSign::
# 80 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
# 81 "data/maps/Route114/scripts.pory"
	end
# 82 "data/maps/Route114/scripts.pory"

# 83 "data/maps/Route114/scripts.pory"
Route114_EventScript_Lenny::
# 84 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_LENNY, Route114_Text_LennyIntro, Route114_Text_LennyDefeat
# 85 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
# 86 "data/maps/Route114/scripts.pory"
	end
# 87 "data/maps/Route114/scripts.pory"

# 88 "data/maps/Route114/scripts.pory"
Route114_EventScript_Lucas::
# 89 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_LUCAS_1, Route114_Text_LucasIntro, Route114_Text_LucasDefeat
# 90 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
# 91 "data/maps/Route114/scripts.pory"
	end
# 92 "data/maps/Route114/scripts.pory"

# 93 "data/maps/Route114/scripts.pory"
Route114_EventScript_Shane::
# 94 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_SHANE, Route114_Text_ShaneIntro, Route114_Text_ShaneDefeat
# 95 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
# 96 "data/maps/Route114/scripts.pory"
	end
# 97 "data/maps/Route114/scripts.pory"

# 98 "data/maps/Route114/scripts.pory"
Route114_EventScript_Nancy::
# 99 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_NANCY, Route114_Text_NancyIntro, Route114_Text_NancyDefeat
# 100 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route114/scripts.pory"
	end
# 102 "data/maps/Route114/scripts.pory"

# 103 "data/maps/Route114/scripts.pory"
Route114_EventScript_Steve::
# 104 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_STEVE_1, Route114_Text_SteveIntro, Route114_Text_SteveDefeat, Route114_EventScript_RegisterSteve
# 105 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 106 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchSteve
# 107 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostBattle, MSGBOX_DEFAULT
# 108 "data/maps/Route114/scripts.pory"
	release
# 109 "data/maps/Route114/scripts.pory"
	end
# 110 "data/maps/Route114/scripts.pory"

# 111 "data/maps/Route114/scripts.pory"
Route114_EventScript_RegisterSteve::
# 112 "data/maps/Route114/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 113 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 114 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_SteveRegister, MSGBOX_DEFAULT
# 115 "data/maps/Route114/scripts.pory"
	register_matchcall TRAINER_STEVE_1
# 116 "data/maps/Route114/scripts.pory"
	release
# 117 "data/maps/Route114/scripts.pory"
	end
# 118 "data/maps/Route114/scripts.pory"

# 119 "data/maps/Route114/scripts.pory"
Route114_EventScript_RematchSteve::
# 120 "data/maps/Route114/scripts.pory"
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_SteveRematchIntro, Route114_Text_SteveRematchDefeat
# 121 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostRematch, MSGBOX_AUTOCLOSE
# 122 "data/maps/Route114/scripts.pory"
	end
# 123 "data/maps/Route114/scripts.pory"

# 124 "data/maps/Route114/scripts.pory"
Route114_EventScript_Bernie::
# 125 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat, Route114_EventScript_RegisterBernie
# 126 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 127 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchBernie
# 128 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BerniePostBattle, MSGBOX_DEFAULT
# 129 "data/maps/Route114/scripts.pory"
	release
# 130 "data/maps/Route114/scripts.pory"
	end
# 131 "data/maps/Route114/scripts.pory"

# 132 "data/maps/Route114/scripts.pory"
Route114_EventScript_RegisterBernie::
# 133 "data/maps/Route114/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 134 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 135 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BernieRegister, MSGBOX_DEFAULT
# 136 "data/maps/Route114/scripts.pory"
	register_matchcall TRAINER_BERNIE_1
# 137 "data/maps/Route114/scripts.pory"
	release
# 138 "data/maps/Route114/scripts.pory"
	end
# 139 "data/maps/Route114/scripts.pory"

# 140 "data/maps/Route114/scripts.pory"
Route114_EventScript_RematchBernie::
# 141 "data/maps/Route114/scripts.pory"
	trainerbattle_rematch TRAINER_BERNIE_1, Route114_Text_BernieRematchIntro, Route114_Text_BernieRematchDefeat
# 142 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BerniePostRematch, MSGBOX_AUTOCLOSE
# 143 "data/maps/Route114/scripts.pory"
	end
# 144 "data/maps/Route114/scripts.pory"

# 145 "data/maps/Route114/scripts.pory"
Route114_EventScript_Claude::
# 146 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_CLAUDE, Route114_Text_ClaudeIntro, Route114_Text_ClaudeDefeat
# 147 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
# 148 "data/maps/Route114/scripts.pory"
	end
# 149 "data/maps/Route114/scripts.pory"

# 150 "data/maps/Route114/scripts.pory"
Route114_EventScript_Nolan::
# 151 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat
# 152 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
# 153 "data/maps/Route114/scripts.pory"
	end
# 154 "data/maps/Route114/scripts.pory"

# 155 "data/maps/Route114/scripts.pory"
Route114_EventScript_Tyra::
# 156 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_TyraIntro, Route114_Text_TyraDefeat, Route114_Text_TyraNotEnoughMons
# 157 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
# 158 "data/maps/Route114/scripts.pory"
	end
# 159 "data/maps/Route114/scripts.pory"

# 160 "data/maps/Route114/scripts.pory"
Route114_EventScript_Ivy::
# 161 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_IvyIntro, Route114_Text_IvyDefeat, Route114_Text_IvyNotEnoughMons
# 162 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
# 163 "data/maps/Route114/scripts.pory"
	end
# 164 "data/maps/Route114/scripts.pory"

# 165 "data/maps/Route114/scripts.pory"
Route114_EventScript_Angelina::
# 166 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_ANGELINA, Route114_Text_AngelinaIntro, Route114_Text_AngelinaDefeat
# 167 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
# 168 "data/maps/Route114/scripts.pory"
	end
# 169 "data/maps/Route114/scripts.pory"

# 170 "data/maps/Route114/scripts.pory"
Route114_EventScript_Charlotte::
# 171 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_CHARLOTTE, Route114_Text_CharlotteIntro, Route114_Text_CharlotteDefeat
# 172 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
# 173 "data/maps/Route114/scripts.pory"
	end
# 174 "data/maps/Route114/scripts.pory"

# 175 "data/maps/Route114/scripts.pory"
Route114_EventScript_Kai::
# 176 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_KAI, Route114_Text_KaiIntro, Route114_Text_KaiDefeat
# 177 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
# 178 "data/maps/Route114/scripts.pory"
	end
# 179 "data/maps/Route114/scripts.pory"

# 180 "data/maps/Route114/scripts.pory"
Route114_Text_AllMyMonDoesIsRoarTakeThis:
# 181 "data/maps/Route114/scripts.pory"
	.string "All my POKéMON does is ROAR…\n"
# 182 "data/maps/Route114/scripts.pory"
	.string "No one dares to come near me…\p"
# 183 "data/maps/Route114/scripts.pory"
	.string "Sigh… If you would, please take\n"
# 184 "data/maps/Route114/scripts.pory"
	.string "this TM away…$"
# 185 "data/maps/Route114/scripts.pory"

# 186 "data/maps/Route114/scripts.pory"
Route114_Text_ExplainRoar:
# 187 "data/maps/Route114/scripts.pory"
	.string "TM05 contains ROAR.\n"
# 188 "data/maps/Route114/scripts.pory"
	.string "A ROAR sends POKéMON scurrying.$"
# 189 "data/maps/Route114/scripts.pory"

# 190 "data/maps/Route114/scripts.pory"
Route114_Text_Poochyena:
# 191 "data/maps/Route114/scripts.pory"
	.string "Bow! Bowwow!$"
# 192 "data/maps/Route114/scripts.pory"

# 193 "data/maps/Route114/scripts.pory"
Route114_Text_MeteorFallsSign:
# 194 "data/maps/Route114/scripts.pory"
	.string "METEOR FALLS\n"
# 195 "data/maps/Route114/scripts.pory"
	.string "RUSTBORO CITY THROUGH HERE$"
# 196 "data/maps/Route114/scripts.pory"

# 197 "data/maps/Route114/scripts.pory"
Route114_Text_FossilManiacsHouseSign:
# 198 "data/maps/Route114/scripts.pory"
	.string "FOSSIL MANIAC'S HOUSE\n"
# 199 "data/maps/Route114/scripts.pory"
	.string "“Fossils gratefully accepted!”$"
# 200 "data/maps/Route114/scripts.pory"

# 201 "data/maps/Route114/scripts.pory"
Route114_Text_LanettesHouse:
# 202 "data/maps/Route114/scripts.pory"
	.string "LANETTE'S HOUSE$"
