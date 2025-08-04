# 1 "data/maps/Route123/scripts.pory"

# 2 "data/maps/Route123/scripts.pory"

# 3 "data/maps/Route123/scripts.pory"

# 4 "data/maps/Route123/scripts.pory"
Route123_MapScripts::
# 5 "data/maps/Route123/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
# 6 "data/maps/Route123/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, Route123_OnResume
# 7 "data/maps/Route123/scripts.pory"
	.byte 0
# 8 "data/maps/Route123/scripts.pory"

# 9 "data/maps/Route123/scripts.pory"
Route123_OnTransition:
# 10 "data/maps/Route123/scripts.pory"
	special SetRoute123Weather
# 11 "data/maps/Route123/scripts.pory"
	end
# 12 "data/maps/Route123/scripts.pory"

# 13 "data/maps/Route123/scripts.pory"
Route123_OnResume:
# 14 "data/maps/Route123/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route123_EventScript_TryRemovePecharunt
# 15 "data/maps/Route123/scripts.pory"
    end
# 16 "data/maps/Route123/scripts.pory"

# 17 "data/maps/Route123/scripts.pory"
Route123_EventScript_Pecharunt::
# 18 "data/maps/Route123/scripts.pory"
    lock
# 19 "data/maps/Route123/scripts.pory"
    faceplayer
# 20 "data/maps/Route123/scripts.pory"
    waitse
# 21 "data/maps/Route123/scripts.pory"
    playmoncry SPECIES_PECHARUNT, CRY_MODE_ENCOUNTER
# 22 "data/maps/Route123/scripts.pory"
    delay 40
# 23 "data/maps/Route123/scripts.pory"
    waitmoncry
# 24 "data/maps/Route123/scripts.pory"
    setwildbattle SPECIES_PECHARUNT, 50
# 25 "data/maps/Route123/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 26 "data/maps/Route123/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 27 "data/maps/Route123/scripts.pory"
    waitstate
# 28 "data/maps/Route123/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 29 "data/maps/Route123/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 30 "data/maps/Route123/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route123_EventScript_DefeatedPecharunt
# 31 "data/maps/Route123/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route123_EventScript_RanFromPecharunt
# 32 "data/maps/Route123/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route123_EventScript_RanFromPecharunt
# 33 "data/maps/Route123/scripts.pory"
    setflag FLAG_DEFEATED_PECHARUNT
# 34 "data/maps/Route123/scripts.pory"
    release
# 35 "data/maps/Route123/scripts.pory"
    end
# 36 "data/maps/Route123/scripts.pory"

# 37 "data/maps/Route123/scripts.pory"

# 38 "data/maps/Route123/scripts.pory"
Route123_EventScript_DefeatedPecharunt::
# 39 "data/maps/Route123/scripts.pory"
    setflag FLAG_DEFEATED_PECHARUNT
# 40 "data/maps/Route123/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 41 "data/maps/Route123/scripts.pory"
    end
# 42 "data/maps/Route123/scripts.pory"

# 43 "data/maps/Route123/scripts.pory"

# 44 "data/maps/Route123/scripts.pory"
Route123_EventScript_RanFromPecharunt::
# 45 "data/maps/Route123/scripts.pory"
    setvar VAR_0x8004, SPECIES_PECHARUNT
# 46 "data/maps/Route123/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 47 "data/maps/Route123/scripts.pory"
    end
# 48 "data/maps/Route123/scripts.pory"

# 49 "data/maps/Route123/scripts.pory"

# 50 "data/maps/Route123/scripts.pory"
Route123_EventScript_TryRemovePecharunt::
# 51 "data/maps/Route123/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 52 "data/maps/Route123/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 53 "data/maps/Route123/scripts.pory"
    removeobject VAR_LAST_TALKED
# 54 "data/maps/Route123/scripts.pory"
    return
# 55 "data/maps/Route123/scripts.pory"

# 56 "data/maps/Route123/scripts.pory"
Route123_EventScript_GigaDrainGirl::
# 57 "data/maps/Route123/scripts.pory"
	lock
# 58 "data/maps/Route123/scripts.pory"
	faceplayer
# 59 "data/maps/Route123/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_GIGA_DRAIN, Route123_EventScript_ReceivedGigaDrain
# 60 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
# 61 "data/maps/Route123/scripts.pory"
	special IsGrassTypeInParty
# 62 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
# 63 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
# 64 "data/maps/Route123/scripts.pory"
	giveitem ITEM_TM_GIGA_DRAIN
# 65 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 66 "data/maps/Route123/scripts.pory"
	setflag FLAG_RECEIVED_TM_GIGA_DRAIN
# 67 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 68 "data/maps/Route123/scripts.pory"
	release
# 69 "data/maps/Route123/scripts.pory"
	end
# 70 "data/maps/Route123/scripts.pory"

# 71 "data/maps/Route123/scripts.pory"
Route123_EventScript_NoGrassMons::
# 72 "data/maps/Route123/scripts.pory"
	release
# 73 "data/maps/Route123/scripts.pory"
	end
# 74 "data/maps/Route123/scripts.pory"

# 75 "data/maps/Route123/scripts.pory"
Route123_EventScript_ReceivedGigaDrain::
# 76 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 77 "data/maps/Route123/scripts.pory"
	release
# 78 "data/maps/Route123/scripts.pory"
	end
# 79 "data/maps/Route123/scripts.pory"

# 80 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSign::
# 81 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
# 82 "data/maps/Route123/scripts.pory"
	end
# 83 "data/maps/Route123/scripts.pory"

# 84 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSignMtPyre::
# 85 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
# 86 "data/maps/Route123/scripts.pory"
	end
# 87 "data/maps/Route123/scripts.pory"

# 88 "data/maps/Route123/scripts.pory"
Route123_EventScript_BerryMastersHouseSign::
# 89 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
# 90 "data/maps/Route123/scripts.pory"
	end
# 91 "data/maps/Route123/scripts.pory"

# 92 "data/maps/Route123/scripts.pory"
Route123_EventScript_Wendy::
# 93 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
# 94 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
# 95 "data/maps/Route123/scripts.pory"
	end
# 96 "data/maps/Route123/scripts.pory"

# 97 "data/maps/Route123/scripts.pory"
Route123_EventScript_Braxton::
# 98 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
# 99 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
# 100 "data/maps/Route123/scripts.pory"
	end
# 101 "data/maps/Route123/scripts.pory"

# 102 "data/maps/Route123/scripts.pory"
Route123_EventScript_Violet::
# 103 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
# 104 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
# 105 "data/maps/Route123/scripts.pory"
	end
# 106 "data/maps/Route123/scripts.pory"

# 107 "data/maps/Route123/scripts.pory"
Route123_EventScript_Cameron::
# 108 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
# 109 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 110 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchCameron
# 111 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
# 112 "data/maps/Route123/scripts.pory"
	release
# 113 "data/maps/Route123/scripts.pory"
	end
# 114 "data/maps/Route123/scripts.pory"

# 115 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterCameron::
# 116 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 117 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 118 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
# 119 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_CAMERON_1
# 120 "data/maps/Route123/scripts.pory"
	release
# 121 "data/maps/Route123/scripts.pory"
	end
# 122 "data/maps/Route123/scripts.pory"

# 123 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchCameron::
# 124 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
# 125 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
# 126 "data/maps/Route123/scripts.pory"
	end
# 127 "data/maps/Route123/scripts.pory"

# 128 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jacki::
# 129 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
# 130 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 131 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchJacki
# 132 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
# 133 "data/maps/Route123/scripts.pory"
	release
# 134 "data/maps/Route123/scripts.pory"
	end
# 135 "data/maps/Route123/scripts.pory"

# 136 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterJacki::
# 137 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 138 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 139 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
# 140 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_JACKI_1
# 141 "data/maps/Route123/scripts.pory"
	release
# 142 "data/maps/Route123/scripts.pory"
	end
# 143 "data/maps/Route123/scripts.pory"

# 144 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchJacki::
# 145 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
# 146 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
# 147 "data/maps/Route123/scripts.pory"
	end
# 148 "data/maps/Route123/scripts.pory"

# 149 "data/maps/Route123/scripts.pory"
Route123_EventScript_Miu::
# 150 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
# 151 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
# 152 "data/maps/Route123/scripts.pory"
	end
# 153 "data/maps/Route123/scripts.pory"

# 154 "data/maps/Route123/scripts.pory"
Route123_EventScript_Yuki::
# 155 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
# 156 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
# 157 "data/maps/Route123/scripts.pory"
	end
# 158 "data/maps/Route123/scripts.pory"

# 159 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kindra::
# 160 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
# 161 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
# 162 "data/maps/Route123/scripts.pory"
	end
# 163 "data/maps/Route123/scripts.pory"

# 164 "data/maps/Route123/scripts.pory"
Route123_EventScript_Frederick::
# 165 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
# 166 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
# 167 "data/maps/Route123/scripts.pory"
	end
# 168 "data/maps/Route123/scripts.pory"

# 169 "data/maps/Route123/scripts.pory"
Route123_EventScript_Alberto::
# 170 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
# 171 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
# 172 "data/maps/Route123/scripts.pory"
	end
# 173 "data/maps/Route123/scripts.pory"

# 174 "data/maps/Route123/scripts.pory"
Route123_EventScript_Ed::
# 175 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
# 176 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
# 177 "data/maps/Route123/scripts.pory"
	end
# 178 "data/maps/Route123/scripts.pory"

# 179 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kayley::
# 180 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
# 181 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
# 182 "data/maps/Route123/scripts.pory"
	end
# 183 "data/maps/Route123/scripts.pory"

# 184 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jonas::
# 185 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
# 186 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
# 187 "data/maps/Route123/scripts.pory"
	end
# 188 "data/maps/Route123/scripts.pory"

# 189 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jazmyn::
# 190 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
# 191 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
# 192 "data/maps/Route123/scripts.pory"
	end
# 193 "data/maps/Route123/scripts.pory"

# 194 "data/maps/Route123/scripts.pory"
Route123_EventScript_Davis::
# 195 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
# 196 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
# 197 "data/maps/Route123/scripts.pory"
	end
# 198 "data/maps/Route123/scripts.pory"

# 199 "data/maps/Route123/scripts.pory"
Route123_EventScript_Fernando::
# 200 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
# 201 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 202 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchFernando
# 203 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
# 204 "data/maps/Route123/scripts.pory"
	release
# 205 "data/maps/Route123/scripts.pory"
	end
# 206 "data/maps/Route123/scripts.pory"

# 207 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterFernando::
# 208 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 209 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 210 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
# 211 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_FERNANDO_1
# 212 "data/maps/Route123/scripts.pory"
	release
# 213 "data/maps/Route123/scripts.pory"
	end
# 214 "data/maps/Route123/scripts.pory"

# 215 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchFernando::
# 216 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
# 217 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
# 218 "data/maps/Route123/scripts.pory"
	end
# 219 "data/maps/Route123/scripts.pory"

# 220 "data/maps/Route123/scripts.pory"
Route123_Text_LoveGrassMonsHaveAny:
# 221 "data/maps/Route123/scripts.pory"
	.string "I love GRASS-type POKéMON!\p"
# 222 "data/maps/Route123/scripts.pory"
	.string "Do you have any GRASS-type POKéMON?$"
# 223 "data/maps/Route123/scripts.pory"

# 224 "data/maps/Route123/scripts.pory"
Route123_Text_YouLikeGrassMonsTooHaveThis:
# 225 "data/maps/Route123/scripts.pory"
	.string "Oh?\p"
# 226 "data/maps/Route123/scripts.pory"
	.string "You like GRASS-type POKéMON, too,\n"
# 227 "data/maps/Route123/scripts.pory"
	.string "don't you?\p"
# 228 "data/maps/Route123/scripts.pory"
	.string "I'm so happy, you can have this!\n"
# 229 "data/maps/Route123/scripts.pory"
	.string "It's a token of our friendship.$"
# 230 "data/maps/Route123/scripts.pory"

# 231 "data/maps/Route123/scripts.pory"
Route123_Text_CheckTreesWithMyGrassMon:
# 232 "data/maps/Route123/scripts.pory"
	.string "I check trees with my GRASS-type\n"
# 233 "data/maps/Route123/scripts.pory"
	.string "POKéMON. I'm like a tree doctor.$"
# 234 "data/maps/Route123/scripts.pory"

# 235 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSign:
# 236 "data/maps/Route123/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 123\n"
# 237 "data/maps/Route123/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 118$"
# 238 "data/maps/Route123/scripts.pory"

# 239 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSignMtPyre:
# 240 "data/maps/Route123/scripts.pory"
	.string "{UP_ARROW} MT. PYRE\n"
# 241 "data/maps/Route123/scripts.pory"
	.string "“Forbidden to the faint of heart.”$"
# 242 "data/maps/Route123/scripts.pory"

# 243 "data/maps/Route123/scripts.pory"
Route123_Text_BerryMastersHouse:
# 244 "data/maps/Route123/scripts.pory"
	.string "BERRY MASTER'S HOUSE$"
