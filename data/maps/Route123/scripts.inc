# 1 "data/maps/Route123/scripts.pory"

# 2 "data/maps/Route123/scripts.pory"
Route123_MapScripts::
# 3 "data/maps/Route123/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
# 4 "data/maps/Route123/scripts.pory"
	.byte 0
# 5 "data/maps/Route123/scripts.pory"

# 6 "data/maps/Route123/scripts.pory"
Route123_OnTransition:
# 7 "data/maps/Route123/scripts.pory"
	special SetRoute123Weather
# 8 "data/maps/Route123/scripts.pory"
	end
# 9 "data/maps/Route123/scripts.pory"

# 10 "data/maps/Route123/scripts.pory"
Route123_EventScript_GigaDrainGirl::
# 11 "data/maps/Route123/scripts.pory"
	lock
# 12 "data/maps/Route123/scripts.pory"
	faceplayer
# 13 "data/maps/Route123/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_GIGA_DRAIN, Route123_EventScript_ReceivedGigaDrain
# 14 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
# 15 "data/maps/Route123/scripts.pory"
	special IsGrassTypeInParty
# 16 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
# 17 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
# 18 "data/maps/Route123/scripts.pory"
	giveitem ITEM_TM_GIGA_DRAIN
# 19 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 20 "data/maps/Route123/scripts.pory"
	setflag FLAG_RECEIVED_TM_GIGA_DRAIN
# 21 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 22 "data/maps/Route123/scripts.pory"
	release
# 23 "data/maps/Route123/scripts.pory"
	end
# 24 "data/maps/Route123/scripts.pory"

# 25 "data/maps/Route123/scripts.pory"
Route123_EventScript_NoGrassMons::
# 26 "data/maps/Route123/scripts.pory"
	release
# 27 "data/maps/Route123/scripts.pory"
	end
# 28 "data/maps/Route123/scripts.pory"

# 29 "data/maps/Route123/scripts.pory"
Route123_EventScript_ReceivedGigaDrain::
# 30 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 31 "data/maps/Route123/scripts.pory"
	release
# 32 "data/maps/Route123/scripts.pory"
	end
# 33 "data/maps/Route123/scripts.pory"

# 34 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSign::
# 35 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
# 36 "data/maps/Route123/scripts.pory"
	end
# 37 "data/maps/Route123/scripts.pory"

# 38 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSignMtPyre::
# 39 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
# 40 "data/maps/Route123/scripts.pory"
	end
# 41 "data/maps/Route123/scripts.pory"

# 42 "data/maps/Route123/scripts.pory"
Route123_EventScript_BerryMastersHouseSign::
# 43 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
# 44 "data/maps/Route123/scripts.pory"
	end
# 45 "data/maps/Route123/scripts.pory"

# 46 "data/maps/Route123/scripts.pory"
Route123_EventScript_Wendy::
# 47 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
# 48 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
# 49 "data/maps/Route123/scripts.pory"
	end
# 50 "data/maps/Route123/scripts.pory"

# 51 "data/maps/Route123/scripts.pory"
Route123_EventScript_Braxton::
# 52 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
# 53 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
# 54 "data/maps/Route123/scripts.pory"
	end
# 55 "data/maps/Route123/scripts.pory"

# 56 "data/maps/Route123/scripts.pory"
Route123_EventScript_Violet::
# 57 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
# 58 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
# 59 "data/maps/Route123/scripts.pory"
	end
# 60 "data/maps/Route123/scripts.pory"

# 61 "data/maps/Route123/scripts.pory"
Route123_EventScript_Cameron::
# 62 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
# 63 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 64 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchCameron
# 65 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
# 66 "data/maps/Route123/scripts.pory"
	release
# 67 "data/maps/Route123/scripts.pory"
	end
# 68 "data/maps/Route123/scripts.pory"

# 69 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterCameron::
# 70 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 71 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 72 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
# 73 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_CAMERON_1
# 74 "data/maps/Route123/scripts.pory"
	release
# 75 "data/maps/Route123/scripts.pory"
	end
# 76 "data/maps/Route123/scripts.pory"

# 77 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchCameron::
# 78 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
# 79 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
# 80 "data/maps/Route123/scripts.pory"
	end
# 81 "data/maps/Route123/scripts.pory"

# 82 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jacki::
# 83 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
# 84 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 85 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchJacki
# 86 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
# 87 "data/maps/Route123/scripts.pory"
	release
# 88 "data/maps/Route123/scripts.pory"
	end
# 89 "data/maps/Route123/scripts.pory"

# 90 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterJacki::
# 91 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 92 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 93 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
# 94 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_JACKI_1
# 95 "data/maps/Route123/scripts.pory"
	release
# 96 "data/maps/Route123/scripts.pory"
	end
# 97 "data/maps/Route123/scripts.pory"

# 98 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchJacki::
# 99 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
# 100 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route123/scripts.pory"
	end
# 102 "data/maps/Route123/scripts.pory"

# 103 "data/maps/Route123/scripts.pory"
Route123_EventScript_Miu::
# 104 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
# 105 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
# 106 "data/maps/Route123/scripts.pory"
	end
# 107 "data/maps/Route123/scripts.pory"

# 108 "data/maps/Route123/scripts.pory"
Route123_EventScript_Yuki::
# 109 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
# 110 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
# 111 "data/maps/Route123/scripts.pory"
	end
# 112 "data/maps/Route123/scripts.pory"

# 113 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kindra::
# 114 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
# 115 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
# 116 "data/maps/Route123/scripts.pory"
	end
# 117 "data/maps/Route123/scripts.pory"

# 118 "data/maps/Route123/scripts.pory"
Route123_EventScript_Frederick::
# 119 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
# 120 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
# 121 "data/maps/Route123/scripts.pory"
	end
# 122 "data/maps/Route123/scripts.pory"

# 123 "data/maps/Route123/scripts.pory"
Route123_EventScript_Alberto::
# 124 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
# 125 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
# 126 "data/maps/Route123/scripts.pory"
	end
# 127 "data/maps/Route123/scripts.pory"

# 128 "data/maps/Route123/scripts.pory"
Route123_EventScript_Ed::
# 129 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
# 130 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
# 131 "data/maps/Route123/scripts.pory"
	end
# 132 "data/maps/Route123/scripts.pory"

# 133 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kayley::
# 134 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
# 135 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
# 136 "data/maps/Route123/scripts.pory"
	end
# 137 "data/maps/Route123/scripts.pory"

# 138 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jonas::
# 139 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
# 140 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
# 141 "data/maps/Route123/scripts.pory"
	end
# 142 "data/maps/Route123/scripts.pory"

# 143 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jazmyn::
# 144 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
# 145 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
# 146 "data/maps/Route123/scripts.pory"
	end
# 147 "data/maps/Route123/scripts.pory"

# 148 "data/maps/Route123/scripts.pory"
Route123_EventScript_Davis::
# 149 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
# 150 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
# 151 "data/maps/Route123/scripts.pory"
	end
# 152 "data/maps/Route123/scripts.pory"

# 153 "data/maps/Route123/scripts.pory"
Route123_EventScript_Fernando::
# 154 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
# 155 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 156 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchFernando
# 157 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
# 158 "data/maps/Route123/scripts.pory"
	release
# 159 "data/maps/Route123/scripts.pory"
	end
# 160 "data/maps/Route123/scripts.pory"

# 161 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterFernando::
# 162 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 163 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 164 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
# 165 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_FERNANDO_1
# 166 "data/maps/Route123/scripts.pory"
	release
# 167 "data/maps/Route123/scripts.pory"
	end
# 168 "data/maps/Route123/scripts.pory"

# 169 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchFernando::
# 170 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
# 171 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
# 172 "data/maps/Route123/scripts.pory"
	end
# 173 "data/maps/Route123/scripts.pory"

# 174 "data/maps/Route123/scripts.pory"
Route123_Text_LoveGrassMonsHaveAny:
# 175 "data/maps/Route123/scripts.pory"
	.string "I love GRASS-type POKéMON!\p"
# 176 "data/maps/Route123/scripts.pory"
	.string "Do you have any GRASS-type POKéMON?$"
# 177 "data/maps/Route123/scripts.pory"

# 178 "data/maps/Route123/scripts.pory"
Route123_Text_YouLikeGrassMonsTooHaveThis:
# 179 "data/maps/Route123/scripts.pory"
	.string "Oh?\p"
# 180 "data/maps/Route123/scripts.pory"
	.string "You like GRASS-type POKéMON, too,\n"
# 181 "data/maps/Route123/scripts.pory"
	.string "don't you?\p"
# 182 "data/maps/Route123/scripts.pory"
	.string "I'm so happy, you can have this!\n"
# 183 "data/maps/Route123/scripts.pory"
	.string "It's a token of our friendship.$"
# 184 "data/maps/Route123/scripts.pory"

# 185 "data/maps/Route123/scripts.pory"
Route123_Text_CheckTreesWithMyGrassMon:
# 186 "data/maps/Route123/scripts.pory"
	.string "I check trees with my GRASS-type\n"
# 187 "data/maps/Route123/scripts.pory"
	.string "POKéMON. I'm like a tree doctor.$"
# 188 "data/maps/Route123/scripts.pory"

# 189 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSign:
# 190 "data/maps/Route123/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 123\n"
# 191 "data/maps/Route123/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 118$"
# 192 "data/maps/Route123/scripts.pory"

# 193 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSignMtPyre:
# 194 "data/maps/Route123/scripts.pory"
	.string "{UP_ARROW} MT. PYRE\n"
# 195 "data/maps/Route123/scripts.pory"
	.string "“Forbidden to the faint of heart.”$"
# 196 "data/maps/Route123/scripts.pory"

# 197 "data/maps/Route123/scripts.pory"
Route123_Text_BerryMastersHouse:
# 198 "data/maps/Route123/scripts.pory"
	.string "BERRY MASTER'S HOUSE$"
