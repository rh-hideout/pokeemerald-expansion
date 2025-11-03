# 1 "data/maps/Route117/scripts.pory"

# 2 "data/maps/Route117/scripts.pory"
.set LOCALID_DAYCARE_MON_0, 25
# 3 "data/maps/Route117/scripts.pory"
.set LOCALID_DAYCARE_MON_1, 26
# 4 "data/maps/Route117/scripts.pory"

# 5 "data/maps/Route117/scripts.pory"
Route117_MapScripts::
# 6 "data/maps/Route117/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
# 7 "data/maps/Route117/scripts.pory"
	.byte 0
# 8 "data/maps/Route117/scripts.pory"

# 9 "data/maps/Route117/scripts.pory"
Route117_OnTransition:
# 10 "data/maps/Route117/scripts.pory"
	call Route117_EventScript_TryMoveDayCareMan
# 11 "data/maps/Route117/scripts.pory"
	@ set flags for OW daycare mons
# 12 "data/maps/Route117/scripts.pory"
	setflag FLAG_TEMP_1
# 13 "data/maps/Route117/scripts.pory"
	setflag FLAG_TEMP_2
# 14 "data/maps/Route117/scripts.pory"
	getdaycaregfx VAR_OBJ_GFX_ID_0, VAR_OBJ_GFX_ID_1, VAR_TEMP_0, VAR_TEMP_1
# 15 "data/maps/Route117/scripts.pory"
	switch VAR_RESULT
# 16 "data/maps/Route117/scripts.pory"
	case 2, Route117_EventScript_ShowDaycareMon1
# 17 "data/maps/Route117/scripts.pory"
	case 1, Route117_EventScript_ShowDaycareMon0
# 18 "data/maps/Route117/scripts.pory"
	end
# 19 "data/maps/Route117/scripts.pory"

# 20 "data/maps/Route117/scripts.pory"
Route117_EventScript_ShowDaycareMon1:
# 21 "data/maps/Route117/scripts.pory"
	@ set pokemon movement type based on compatibility
# 22 "data/maps/Route117/scripts.pory"
	special SetDaycareCompatibilityString
# 23 "data/maps/Route117/scripts.pory"
	call_if_eq VAR_RESULT, PARENTS_INCOMPATIBLE, Route117_EventScript_DaycareMonIncompatible
# 24 "data/maps/Route117/scripts.pory"
	@ Don't do anything if PARENTS_LOW_COMPATIBILITY
# 25 "data/maps/Route117/scripts.pory"
	call_if_eq VAR_RESULT, PARENTS_MED_COMPATIBILITY, Route117_EventScript_DaycareMonMedCompatibility
# 26 "data/maps/Route117/scripts.pory"
	call_if_eq VAR_RESULT, PARENTS_MAX_COMPATIBILITY, Route117_EventScript_DaycareMonMaxCompatibility
# 27 "data/maps/Route117/scripts.pory"
	clearflag FLAG_TEMP_2
# 28 "data/maps/Route117/scripts.pory"
Route117_EventScript_ShowDaycareMon0:
# 29 "data/maps/Route117/scripts.pory"
	clearflag FLAG_TEMP_1
# 30 "data/maps/Route117/scripts.pory"
	end
# 31 "data/maps/Route117/scripts.pory"

# 32 "data/maps/Route117/scripts.pory"
Route117_EventScript_DaycareMonIncompatible: @ mons never face each other
# 33 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT
# 34 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT
# 35 "data/maps/Route117/scripts.pory"
	return
# 36 "data/maps/Route117/scripts.pory"

# 37 "data/maps/Route117/scripts.pory"
Route117_EventScript_DaycareMonMedCompatibility: @ down and towards each other
# 38 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 39 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT
# 40 "data/maps/Route117/scripts.pory"
	return
# 41 "data/maps/Route117/scripts.pory"

# 42 "data/maps/Route117/scripts.pory"
Route117_EventScript_DaycareMonMaxCompatibility: @ facing; walk in place
# 43 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
# 44 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
# 45 "data/maps/Route117/scripts.pory"
	return
# 46 "data/maps/Route117/scripts.pory"

# 47 "data/maps/Route117/scripts.pory"
Route117_EventScript_TryMoveDayCareMan::
# 48 "data/maps/Route117/scripts.pory"
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_StopMoveDayCareMan
# 49 "data/maps/Route117/scripts.pory"
	setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6
# 50 "data/maps/Route117/scripts.pory"
Route117_EventScript_StopMoveDayCareMan::
# 51 "data/maps/Route117/scripts.pory"
	return
# 52 "data/maps/Route117/scripts.pory"

# 53 "data/maps/Route117/scripts.pory"
Route117_EventScript_Woman::
# 54 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_ArentTheseFlowersPretty, MSGBOX_NPC
# 55 "data/maps/Route117/scripts.pory"
	end
# 56 "data/maps/Route117/scripts.pory"

# 57 "data/maps/Route117/scripts.pory"
Route117_EventScript_LittleBoy::
# 58 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AirIsTastyHere, MSGBOX_NPC
# 59 "data/maps/Route117/scripts.pory"
	end
# 60 "data/maps/Route117/scripts.pory"

# 61 "data/maps/Route117/scripts.pory"
Route117_EventScript_Girl::
# 62 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
# 63 "data/maps/Route117/scripts.pory"
	end
# 64 "data/maps/Route117/scripts.pory"

# 65 "data/maps/Route117/scripts.pory"
Route117_EventScript_RouteSignVerdanturf::
# 66 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignVerdanturf, MSGBOX_SIGN
# 67 "data/maps/Route117/scripts.pory"
	end
# 68 "data/maps/Route117/scripts.pory"

# 69 "data/maps/Route117/scripts.pory"
Route117_EventScript_RouteSignMauville::
# 70 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignMauville, MSGBOX_SIGN
# 71 "data/maps/Route117/scripts.pory"
	end
# 72 "data/maps/Route117/scripts.pory"

# 73 "data/maps/Route117/scripts.pory"
Route117_EventScript_DayCareSign::
# 74 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCareSign, MSGBOX_SIGN
# 75 "data/maps/Route117/scripts.pory"
	end
# 76 "data/maps/Route117/scripts.pory"

# 77 "data/maps/Route117/scripts.pory"
Route117_EventScript_Isaac::
# 78 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_ISAAC_1, Route117_Text_IsaacIntro, Route117_Text_IsaacDefeat, Route117_EventScript_RegisterIsaac
# 79 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 80 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchIsaac
# 81 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostBattle, MSGBOX_DEFAULT
# 82 "data/maps/Route117/scripts.pory"
	release
# 83 "data/maps/Route117/scripts.pory"
	end
# 84 "data/maps/Route117/scripts.pory"

# 85 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterIsaac::
# 86 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 87 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 88 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacRegister, MSGBOX_DEFAULT
# 89 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ISAAC_1
# 90 "data/maps/Route117/scripts.pory"
	release
# 91 "data/maps/Route117/scripts.pory"
	end
# 92 "data/maps/Route117/scripts.pory"

# 93 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchIsaac::
# 94 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_IsaacRematchIntro, Route117_Text_IsaacRematchDefeat
# 95 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostRematch, MSGBOX_AUTOCLOSE
# 96 "data/maps/Route117/scripts.pory"
	end
# 97 "data/maps/Route117/scripts.pory"

# 98 "data/maps/Route117/scripts.pory"
Route117_EventScript_Lydia::
# 99 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_LYDIA_1, Route117_Text_LydiaIntro, Route117_Text_LydiaDefeat, Route117_EventScript_RegisterLydia
# 100 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 101 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchLydia
# 102 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostBattle, MSGBOX_DEFAULT
# 103 "data/maps/Route117/scripts.pory"
	release
# 104 "data/maps/Route117/scripts.pory"
	end
# 105 "data/maps/Route117/scripts.pory"

# 106 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterLydia::
# 107 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 108 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 109 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaRegister, MSGBOX_DEFAULT
# 110 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_LYDIA_1
# 111 "data/maps/Route117/scripts.pory"
	release
# 112 "data/maps/Route117/scripts.pory"
	end
# 113 "data/maps/Route117/scripts.pory"

# 114 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchLydia::
# 115 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_LydiaRematchIntro, Route117_Text_LydiaRematchDefeat
# 116 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostRematch, MSGBOX_AUTOCLOSE
# 117 "data/maps/Route117/scripts.pory"
	end
# 118 "data/maps/Route117/scripts.pory"

# 119 "data/maps/Route117/scripts.pory"
Route117_EventScript_Dylan::
# 120 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_DYLAN_1, Route117_Text_DylanIntro, Route117_Text_DylanDefeat, Route117_EventScript_RegisterDylan
# 121 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 122 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchDylan
# 123 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostBattle, MSGBOX_DEFAULT
# 124 "data/maps/Route117/scripts.pory"
	release
# 125 "data/maps/Route117/scripts.pory"
	end
# 126 "data/maps/Route117/scripts.pory"

# 127 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterDylan::
# 128 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 129 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 130 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanRegister, MSGBOX_DEFAULT
# 131 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_DYLAN_1
# 132 "data/maps/Route117/scripts.pory"
	release
# 133 "data/maps/Route117/scripts.pory"
	end
# 134 "data/maps/Route117/scripts.pory"

# 135 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchDylan::
# 136 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_DylanRematchIntro, Route117_Text_DylanRematchDefeat
# 137 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostRematch, MSGBOX_AUTOCLOSE
# 138 "data/maps/Route117/scripts.pory"
	end
# 139 "data/maps/Route117/scripts.pory"

# 140 "data/maps/Route117/scripts.pory"
Route117_EventScript_Maria::
# 141 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_MARIA_1, Route117_Text_MariaIntro, Route117_Text_MariaDefeat, Route117_EventScript_RegisterMaria
# 142 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 143 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchMaria
# 144 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostBattle, MSGBOX_DEFAULT
# 145 "data/maps/Route117/scripts.pory"
	release
# 146 "data/maps/Route117/scripts.pory"
	end
# 147 "data/maps/Route117/scripts.pory"

# 148 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterMaria::
# 149 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 150 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 151 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaRegister, MSGBOX_DEFAULT
# 152 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_MARIA_1
# 153 "data/maps/Route117/scripts.pory"
	release
# 154 "data/maps/Route117/scripts.pory"
	end
# 155 "data/maps/Route117/scripts.pory"

# 156 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchMaria::
# 157 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_MariaRematchIntro, Route117_Text_MariaRematchDefeat
# 158 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostRematch, MSGBOX_AUTOCLOSE
# 159 "data/maps/Route117/scripts.pory"
	end
# 160 "data/maps/Route117/scripts.pory"

# 161 "data/maps/Route117/scripts.pory"
Route117_EventScript_Derek::
# 162 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_DEREK, Route117_Text_DerekIntro, Route117_Text_DerekDefeat
# 163 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
# 164 "data/maps/Route117/scripts.pory"
	end
# 165 "data/maps/Route117/scripts.pory"

# 166 "data/maps/Route117/scripts.pory"
Route117_EventScript_Anna::
# 167 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaIntro, Route117_Text_AnnaDefeat, Route117_Text_AnnaNotEnoughMons, Route117_EventScript_RegisterAnna
# 168 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 169 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchAnna
# 170 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaPostBattle, MSGBOX_DEFAULT
# 171 "data/maps/Route117/scripts.pory"
	release
# 172 "data/maps/Route117/scripts.pory"
	end
# 173 "data/maps/Route117/scripts.pory"

# 174 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterAnna::
# 175 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
# 176 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ANNA_AND_MEG_1
# 177 "data/maps/Route117/scripts.pory"
	release
# 178 "data/maps/Route117/scripts.pory"
	end
# 179 "data/maps/Route117/scripts.pory"

# 180 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchAnna::
# 181 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaRematchIntro, Route117_Text_AnnaRematchDefeat, Route117_Text_AnnaRematchNotEnoughMons
# 182 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaPostRematch, MSGBOX_AUTOCLOSE
# 183 "data/maps/Route117/scripts.pory"
	end
# 184 "data/maps/Route117/scripts.pory"

# 185 "data/maps/Route117/scripts.pory"
Route117_EventScript_Meg::
# 186 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegIntro, Route117_Text_MegDefeat, Route117_Text_MegNotEnoughMons, Route117_EventScript_RegisterMeg
# 187 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 188 "data/maps/Route117/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchMeg
# 189 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MegPostBattle, MSGBOX_DEFAULT
# 190 "data/maps/Route117/scripts.pory"
	release
# 191 "data/maps/Route117/scripts.pory"
	end
# 192 "data/maps/Route117/scripts.pory"

# 193 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterMeg::
# 194 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
# 195 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ANNA_AND_MEG_1
# 196 "data/maps/Route117/scripts.pory"
	release
# 197 "data/maps/Route117/scripts.pory"
	end
# 198 "data/maps/Route117/scripts.pory"

# 199 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchMeg::
# 200 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegRematchIntro, Route117_Text_MegRematchDefeat, Route117_Text_MegRematchNotEnoughMons
# 201 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MegPostRematch, MSGBOX_AUTOCLOSE
# 202 "data/maps/Route117/scripts.pory"
	end
# 203 "data/maps/Route117/scripts.pory"

# 204 "data/maps/Route117/scripts.pory"
Route117_EventScript_Melina::
# 205 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_MELINA, Route117_Text_MelinaIntro, Route117_Text_MelinaDefeat
# 206 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
# 207 "data/maps/Route117/scripts.pory"
	end
# 208 "data/maps/Route117/scripts.pory"

# 209 "data/maps/Route117/scripts.pory"
Route117_EventScript_Brandi::
# 210 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_BRANDI, Route117_Text_BrandiIntro, Route117_Text_BrandiDefeat
# 211 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
# 212 "data/maps/Route117/scripts.pory"
	end
# 213 "data/maps/Route117/scripts.pory"

# 214 "data/maps/Route117/scripts.pory"
Route117_EventScript_Aisha::
# 215 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_AISHA, Route117_Text_AishaIntro, Route117_Text_AishaDefeat
# 216 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
# 217 "data/maps/Route117/scripts.pory"
	end
# 218 "data/maps/Route117/scripts.pory"

# 219 "data/maps/Route117/scripts.pory"
Route117_Text_DayCarePokemonHadNewMove:
# 220 "data/maps/Route117/scripts.pory"
	.string "I left my POKéMON at the DAY CARE.\p"
# 221 "data/maps/Route117/scripts.pory"
	.string "When I got it back, it had a new move\n"
# 222 "data/maps/Route117/scripts.pory"
	.string "that I didn't teach it.\l"
# 223 "data/maps/Route117/scripts.pory"
	.string "I was really, really surprised.$"
# 224 "data/maps/Route117/scripts.pory"

# 225 "data/maps/Route117/scripts.pory"
Route117_Text_ArentTheseFlowersPretty:
# 226 "data/maps/Route117/scripts.pory"
	.string "What do you think?\n"
# 227 "data/maps/Route117/scripts.pory"
	.string "Aren't these flowers pretty?\p"
# 228 "data/maps/Route117/scripts.pory"
	.string "I planted them all!$"
# 229 "data/maps/Route117/scripts.pory"

# 230 "data/maps/Route117/scripts.pory"
Route117_Text_AirIsTastyHere:
# 231 "data/maps/Route117/scripts.pory"
	.string "The air is tasty here!$"
# 232 "data/maps/Route117/scripts.pory"

# 233 "data/maps/Route117/scripts.pory"
Route117_Text_RouteSignVerdanturf:
# 234 "data/maps/Route117/scripts.pory"
	.string "ROUTE 117\n"
# 235 "data/maps/Route117/scripts.pory"
	.string "{LEFT_ARROW} VERDANTURF TOWN$"
# 236 "data/maps/Route117/scripts.pory"

# 237 "data/maps/Route117/scripts.pory"
Route117_Text_RouteSignMauville:
# 238 "data/maps/Route117/scripts.pory"
	.string "ROUTE 117\n"
# 239 "data/maps/Route117/scripts.pory"
	.string "{RIGHT_ARROW} MAUVILLE CITY$"
# 240 "data/maps/Route117/scripts.pory"

# 241 "data/maps/Route117/scripts.pory"
Route117_Text_DayCareSign:
# 242 "data/maps/Route117/scripts.pory"
	.string "POKéMON DAY CARE\n"
# 243 "data/maps/Route117/scripts.pory"
	.string "“Let us raise your POKéMON.”$"
