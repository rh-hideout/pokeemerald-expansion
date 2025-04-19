# 1 "data/maps/SlateportCity/scripts.pory"

# 2 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_FAT_MAN, 1
# 3 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_MAN_1, 2
# 4 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_RICH_BOY, 3
# 5 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_1, 5
# 6 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_COOK, 6
# 7 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_OLD_WOMAN, 7
# 8 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GIRL, 8
# 9 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_TY, 9
# 10 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GABBY, 10
# 11 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_CAPT_STERN, 11
# 12 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_2, 18
# 13 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_3, 19
# 14 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_4, 26
# 15 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_5, 27
# 16 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_6, 28
# 17 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_7, 29
# 18 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_8, 30
# 19 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_9, 31
# 20 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_11, 33
# 21 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_SCOTT, 35
# 22 "data/maps/SlateportCity/scripts.pory"

# 23 "data/maps/SlateportCity/scripts.pory"
@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h
# 24 "data/maps/SlateportCity/scripts.pory"

# 25 "data/maps/SlateportCity/scripts.pory"
SlateportCity_MapScripts::
# 26 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
# 27 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
# 28 "data/maps/SlateportCity/scripts.pory"
	.byte 0
# 29 "data/maps/SlateportCity/scripts.pory"

# 30 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnTransition:
# 31 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
# 32 "data/maps/SlateportCity/scripts.pory"
	call SlateportCity_EventScript_EnterSlateport
# 33 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
# 34 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
# 35 "data/maps/SlateportCity/scripts.pory"
	end
# 36 "data/maps/SlateportCity/scripts.pory"

# 37 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnterSlateport::
# 38 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 39 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 40 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
# 41 "data/maps/SlateportCity/scripts.pory"
	return
# 42 "data/maps/SlateportCity/scripts.pory"

# 43 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MovePeopleForSternInterview::
# 44 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
# 45 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
# 46 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
# 47 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_COOK, 27, 16
# 48 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_GIRL, 28, 16
# 49 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
# 50 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_MAN_1, 31, 14
# 51 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
# 52 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 53 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
# 54 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
# 55 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
# 56 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
# 57 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
# 58 "data/maps/SlateportCity/scripts.pory"
	return
# 59 "data/maps/SlateportCity/scripts.pory"

# 60 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SetReadyForScottScene::
# 61 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 62 "data/maps/SlateportCity/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 63 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
# 64 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 23, 27
# 65 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 66 "data/maps/SlateportCity/scripts.pory"
	return
# 67 "data/maps/SlateportCity/scripts.pory"

# 68 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MoveScottLeft::
# 69 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 22, 27
# 70 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 71 "data/maps/SlateportCity/scripts.pory"
	return
# 72 "data/maps/SlateportCity/scripts.pory"

# 73 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnFrame:
# 74 "data/maps/SlateportCity/scripts.pory"
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
# 75 "data/maps/SlateportCity/scripts.pory"
	.2byte 0
# 76 "data/maps/SlateportCity/scripts.pory"

# 77 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottScene::
# 78 "data/maps/SlateportCity/scripts.pory"
	lockall
# 79 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SCOTT
# 80 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
# 81 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
# 82 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 83 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
# 84 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 85 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 86 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 87 "data/maps/SlateportCity/scripts.pory"
	delay 60
# 88 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
# 89 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 90 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
# 92 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 93 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 94 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 95 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
# 96 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 97 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 98 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 99 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
# 100 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
# 101 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 102 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
# 103 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 104 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 105 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 10, 12
# 106 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
# 107 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 108 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
# 109 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 110 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 111 "data/maps/SlateportCity/scripts.pory"
	end
# 112 "data/maps/SlateportCity/scripts.pory"

# 113 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceScott:
# 114 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 115 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 116 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 117 "data/maps/SlateportCity/scripts.pory"
	step_end
# 118 "data/maps/SlateportCity/scripts.pory"

# 119 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottApproachPlayer:
# 120 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 121 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 122 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 123 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 124 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 125 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 126 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 127 "data/maps/SlateportCity/scripts.pory"
	step_end
# 128 "data/maps/SlateportCity/scripts.pory"

# 129 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExit:
# 130 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 131 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 132 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 133 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 134 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 135 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 136 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 137 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 138 "data/maps/SlateportCity/scripts.pory"
	step_end
# 139 "data/maps/SlateportCity/scripts.pory"

# 140 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyGuru::
# 141 "data/maps/SlateportCity/scripts.pory"
	lock
# 142 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 143 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
# 144 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 145 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_EnergyGuru
# 146 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 147 "data/maps/SlateportCity/scripts.pory"
	release
# 148 "data/maps/SlateportCity/scripts.pory"
	end
# 149 "data/maps/SlateportCity/scripts.pory"

# 150 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 151 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_EnergyGuru:
# 152 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PROTEIN
# 153 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_IRON
# 154 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CARBOS
# 155 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ZINC
# 156 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CALCIUM
# 157 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_HP_UP
# 158 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 159 "data/maps/SlateportCity/scripts.pory"

# 160 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EffortRibbonWoman::
# 161 "data/maps/SlateportCity/scripts.pory"
	lock
# 162 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 163 "data/maps/SlateportCity/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 164 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
# 165 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
# 166 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
# 167 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
# 168 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
# 169 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
# 170 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 171 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ReceivedEffortRibbon
# 172 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 173 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
# 174 "data/maps/SlateportCity/scripts.pory"
	special GiveLeadMonEffortRibbon
# 175 "data/maps/SlateportCity/scripts.pory"
	release
# 176 "data/maps/SlateportCity/scripts.pory"
	end
# 177 "data/maps/SlateportCity/scripts.pory"

# 178 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonEVsNotMaxed::
# 179 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
# 180 "data/maps/SlateportCity/scripts.pory"
	release
# 181 "data/maps/SlateportCity/scripts.pory"
	end
# 182 "data/maps/SlateportCity/scripts.pory"

# 183 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonHasEffortRibbon::
# 184 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
# 185 "data/maps/SlateportCity/scripts.pory"
	release
# 186 "data/maps/SlateportCity/scripts.pory"
	end
# 187 "data/maps/SlateportCity/scripts.pory"

# 188 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Cook::
# 189 "data/maps/SlateportCity/scripts.pory"
	lock
# 190 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 191 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
# 192 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
# 193 "data/maps/SlateportCity/scripts.pory"
	release
# 194 "data/maps/SlateportCity/scripts.pory"
	end
# 195 "data/maps/SlateportCity/scripts.pory"

# 196 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CookSternInterview::
# 197 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
# 198 "data/maps/SlateportCity/scripts.pory"
	release
# 199 "data/maps/SlateportCity/scripts.pory"
	end
# 200 "data/maps/SlateportCity/scripts.pory"

# 201 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWoman::
# 202 "data/maps/SlateportCity/scripts.pory"
	lock
# 203 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 204 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
# 205 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
# 206 "data/maps/SlateportCity/scripts.pory"
	release
# 207 "data/maps/SlateportCity/scripts.pory"
	end
# 208 "data/maps/SlateportCity/scripts.pory"

# 209 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWomanSternInterview::
# 210 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
# 211 "data/maps/SlateportCity/scripts.pory"
	release
# 212 "data/maps/SlateportCity/scripts.pory"
	end
# 213 "data/maps/SlateportCity/scripts.pory"

# 214 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Girl::
# 215 "data/maps/SlateportCity/scripts.pory"
	lock
# 216 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 217 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
# 218 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
# 219 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
# 220 "data/maps/SlateportCity/scripts.pory"
	release
# 221 "data/maps/SlateportCity/scripts.pory"
	end
# 222 "data/maps/SlateportCity/scripts.pory"

# 223 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSternInterview::
# 224 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
# 225 "data/maps/SlateportCity/scripts.pory"
	release
# 226 "data/maps/SlateportCity/scripts.pory"
	end
# 227 "data/maps/SlateportCity/scripts.pory"

# 228 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSecretBase::
# 229 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
# 230 "data/maps/SlateportCity/scripts.pory"
	release
# 231 "data/maps/SlateportCity/scripts.pory"
	end
# 232 "data/maps/SlateportCity/scripts.pory"

# 233 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoy::
# 234 "data/maps/SlateportCity/scripts.pory"
	lock
# 235 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 236 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
# 237 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
# 238 "data/maps/SlateportCity/scripts.pory"
	release
# 239 "data/maps/SlateportCity/scripts.pory"
	end
# 240 "data/maps/SlateportCity/scripts.pory"

# 241 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoySternInterview::
# 242 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
# 243 "data/maps/SlateportCity/scripts.pory"
	release
# 244 "data/maps/SlateportCity/scripts.pory"
	end
# 245 "data/maps/SlateportCity/scripts.pory"

# 246 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatMan::
# 247 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
# 248 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
# 249 "data/maps/SlateportCity/scripts.pory"
	end
# 250 "data/maps/SlateportCity/scripts.pory"

# 251 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatManSternInterview::
# 252 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
# 253 "data/maps/SlateportCity/scripts.pory"
	end
# 254 "data/maps/SlateportCity/scripts.pory"

# 255 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1::
# 256 "data/maps/SlateportCity/scripts.pory"
	lock
# 257 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 258 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
# 259 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
# 260 "data/maps/SlateportCity/scripts.pory"
	release
# 261 "data/maps/SlateportCity/scripts.pory"
	end
# 262 "data/maps/SlateportCity/scripts.pory"

# 263 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1SternInterview::
# 264 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
# 265 "data/maps/SlateportCity/scripts.pory"
	release
# 266 "data/maps/SlateportCity/scripts.pory"
	end
# 267 "data/maps/SlateportCity/scripts.pory"

# 268 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1::
# 269 "data/maps/SlateportCity/scripts.pory"
	lock
# 270 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 271 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
# 272 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
# 273 "data/maps/SlateportCity/scripts.pory"
	release
# 274 "data/maps/SlateportCity/scripts.pory"
	end
# 275 "data/maps/SlateportCity/scripts.pory"

# 276 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1AquaGone::
# 277 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
# 278 "data/maps/SlateportCity/scripts.pory"
	release
# 279 "data/maps/SlateportCity/scripts.pory"
	end
# 280 "data/maps/SlateportCity/scripts.pory"

# 281 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BattleTentSign::
# 282 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
# 283 "data/maps/SlateportCity/scripts.pory"
	end
# 284 "data/maps/SlateportCity/scripts.pory"

# 285 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardSign::
# 286 "data/maps/SlateportCity/scripts.pory"
	lockall
# 287 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
# 288 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
# 289 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
# 290 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 291 "data/maps/SlateportCity/scripts.pory"
	end
# 292 "data/maps/SlateportCity/scripts.pory"

# 293 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardNearsCompletion::
# 294 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
# 295 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 296 "data/maps/SlateportCity/scripts.pory"
	end
# 297 "data/maps/SlateportCity/scripts.pory"

# 298 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardFerryComplete::
# 299 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
# 300 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 301 "data/maps/SlateportCity/scripts.pory"
	end
# 302 "data/maps/SlateportCity/scripts.pory"

# 303 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokemonFanClubSign::
# 304 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 305 "data/maps/SlateportCity/scripts.pory"
	end
# 306 "data/maps/SlateportCity/scripts.pory"

# 307 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OceanicMuseumSign::
# 308 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
# 309 "data/maps/SlateportCity/scripts.pory"
	end
# 310 "data/maps/SlateportCity/scripts.pory"

# 311 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CitySign::
# 312 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
# 313 "data/maps/SlateportCity/scripts.pory"
	end
# 314 "data/maps/SlateportCity/scripts.pory"

# 315 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MarketSign::
# 316 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
# 317 "data/maps/SlateportCity/scripts.pory"
	end
# 318 "data/maps/SlateportCity/scripts.pory"

# 319 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSign::
# 320 "data/maps/SlateportCity/scripts.pory"
	lockall
# 321 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
# 322 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
# 323 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 324 "data/maps/SlateportCity/scripts.pory"
	end
# 325 "data/maps/SlateportCity/scripts.pory"

# 326 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSignFerryComplete::
# 327 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
# 328 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 329 "data/maps/SlateportCity/scripts.pory"
	end
# 330 "data/maps/SlateportCity/scripts.pory"

# 331 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NameRatersHouseSign::
# 332 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
# 333 "data/maps/SlateportCity/scripts.pory"
	end
# 334 "data/maps/SlateportCity/scripts.pory"

# 335 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Maniac::
# 336 "data/maps/SlateportCity/scripts.pory"
	lock
# 337 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 338 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
# 339 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 340 "data/maps/SlateportCity/scripts.pory"
	release
# 341 "data/maps/SlateportCity/scripts.pory"
	end
# 342 "data/maps/SlateportCity/scripts.pory"

# 343 "data/maps/SlateportCity/scripts.pory"
@ Unclear if the text here was meant to be different, but its not
# 344 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ManiacSternInterview::
# 345 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 346 "data/maps/SlateportCity/scripts.pory"
	release
# 347 "data/maps/SlateportCity/scripts.pory"
	end
# 348 "data/maps/SlateportCity/scripts.pory"

# 349 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman2::
# 350 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
# 351 "data/maps/SlateportCity/scripts.pory"
	end
# 352 "data/maps/SlateportCity/scripts.pory"

# 353 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor1::
# 354 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
# 355 "data/maps/SlateportCity/scripts.pory"
	end
# 356 "data/maps/SlateportCity/scripts.pory"

# 357 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor2::
# 358 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
# 359 "data/maps/SlateportCity/scripts.pory"
	end
# 360 "data/maps/SlateportCity/scripts.pory"

# 361 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokefanF::
# 362 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
# 363 "data/maps/SlateportCity/scripts.pory"
	end
# 364 "data/maps/SlateportCity/scripts.pory"

# 365 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man2::
# 366 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
# 367 "data/maps/SlateportCity/scripts.pory"
	end
# 368 "data/maps/SlateportCity/scripts.pory"

# 369 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt1::
# 370 "data/maps/SlateportCity/scripts.pory"
	lock
# 371 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 372 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
# 373 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 374 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
# 375 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 376 "data/maps/SlateportCity/scripts.pory"
	release
# 377 "data/maps/SlateportCity/scripts.pory"
	end
# 378 "data/maps/SlateportCity/scripts.pory"

# 379 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt2::
# 380 "data/maps/SlateportCity/scripts.pory"
	lock
# 381 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 382 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
# 383 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 384 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
# 385 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 386 "data/maps/SlateportCity/scripts.pory"
	release
# 387 "data/maps/SlateportCity/scripts.pory"
	end
# 388 "data/maps/SlateportCity/scripts.pory"

# 389 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt3::
# 390 "data/maps/SlateportCity/scripts.pory"
	lock
# 391 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 392 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
# 393 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 394 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
# 395 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 396 "data/maps/SlateportCity/scripts.pory"
	release
# 397 "data/maps/SlateportCity/scripts.pory"
	end
# 398 "data/maps/SlateportCity/scripts.pory"

# 399 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt4::
# 400 "data/maps/SlateportCity/scripts.pory"
	lock
# 401 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 402 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
# 403 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 404 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
# 405 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 406 "data/maps/SlateportCity/scripts.pory"
	release
# 407 "data/maps/SlateportCity/scripts.pory"
	end
# 408 "data/maps/SlateportCity/scripts.pory"

# 409 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt5::
# 410 "data/maps/SlateportCity/scripts.pory"
	lock
# 411 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 412 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
# 413 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 414 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
# 415 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 416 "data/maps/SlateportCity/scripts.pory"
	release
# 417 "data/maps/SlateportCity/scripts.pory"
	end
# 418 "data/maps/SlateportCity/scripts.pory"

# 419 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt6::
# 420 "data/maps/SlateportCity/scripts.pory"
	lock
# 421 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 422 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
# 423 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 424 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
# 425 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 426 "data/maps/SlateportCity/scripts.pory"
	release
# 427 "data/maps/SlateportCity/scripts.pory"
	end
# 428 "data/maps/SlateportCity/scripts.pory"

# 429 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt7::
# 430 "data/maps/SlateportCity/scripts.pory"
	lock
# 431 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 432 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
# 433 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 434 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
# 435 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 436 "data/maps/SlateportCity/scripts.pory"
	release
# 437 "data/maps/SlateportCity/scripts.pory"
	end
# 438 "data/maps/SlateportCity/scripts.pory"

# 439 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt8::
# 440 "data/maps/SlateportCity/scripts.pory"
	lock
# 441 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 442 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
# 443 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 444 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
# 445 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 446 "data/maps/SlateportCity/scripts.pory"
	release
# 447 "data/maps/SlateportCity/scripts.pory"
	end
# 448 "data/maps/SlateportCity/scripts.pory"

# 449 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt9::
# 450 "data/maps/SlateportCity/scripts.pory"
	lock
# 451 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 452 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 453 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
# 454 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 455 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
# 456 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 457 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
# 458 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 459 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 460 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 461 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 462 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 463 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
# 464 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 465 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
# 466 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 467 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 468 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 469 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 470 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 471 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
# 472 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 473 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
# 474 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 475 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 476 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 477 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 478 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 479 "data/maps/SlateportCity/scripts.pory"
	release
# 480 "data/maps/SlateportCity/scripts.pory"
	end
# 481 "data/maps/SlateportCity/scripts.pory"

# 482 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_DelayAquaGrunt:
# 483 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 484 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 485 "data/maps/SlateportCity/scripts.pory"
	step_end
# 486 "data/maps/SlateportCity/scripts.pory"

# 487 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt10::
# 488 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
# 489 "data/maps/SlateportCity/scripts.pory"
	end
# 490 "data/maps/SlateportCity/scripts.pory"

# 491 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt11::
# 492 "data/maps/SlateportCity/scripts.pory"
	lock
# 493 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 494 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
# 495 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 496 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
# 497 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 498 "data/maps/SlateportCity/scripts.pory"
	release
# 499 "data/maps/SlateportCity/scripts.pory"
	end
# 500 "data/maps/SlateportCity/scripts.pory"

# 501 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DollClerk::
# 502 "data/maps/SlateportCity/scripts.pory"
	lock
# 503 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 504 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 505 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 506 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
# 507 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 508 "data/maps/SlateportCity/scripts.pory"
	release
# 509 "data/maps/SlateportCity/scripts.pory"
	end
# 510 "data/maps/SlateportCity/scripts.pory"

# 511 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 512 "data/maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor_Dolls:
# 513 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_AZURILL_DOLL
# 514 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_MARILL_DOLL
# 515 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_SKITTY_DOLL
# 516 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 517 "data/maps/SlateportCity/scripts.pory"

# 518 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ComeBackWithSecretPower::
# 519 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
# 520 "data/maps/SlateportCity/scripts.pory"
	release
# 521 "data/maps/SlateportCity/scripts.pory"
	end
# 522 "data/maps/SlateportCity/scripts.pory"

# 523 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DecorClerk::
# 524 "data/maps/SlateportCity/scripts.pory"
	lock
# 525 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 526 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
# 527 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 528 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 529 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor
# 530 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 531 "data/maps/SlateportCity/scripts.pory"
	release
# 532 "data/maps/SlateportCity/scripts.pory"
	end
# 533 "data/maps/SlateportCity/scripts.pory"

# 534 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 535 "data/maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor:
# 536 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BRICK
# 537 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BRICK
# 538 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BRICK
# 539 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BALLOON
# 540 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BALLOON
# 541 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BALLOON
# 542 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_LOW_NOTE_MAT
# 543 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_D_NOTE_MAT
# 544 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_E_NOTE_MAT
# 545 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_F_NOTE_MAT
# 546 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_G_NOTE_MAT
# 547 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_A_NOTE_MAT
# 548 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_B_NOTE_MAT
# 549 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_HIGH_NOTE_MAT
# 550 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 551 "data/maps/SlateportCity/scripts.pory"

# 552 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PowerTMClerk::
# 553 "data/maps/SlateportCity/scripts.pory"
	lock
# 554 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 555 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 556 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 557 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_PowerTMs
# 558 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 559 "data/maps/SlateportCity/scripts.pory"
	release
# 560 "data/maps/SlateportCity/scripts.pory"
	end
# 561 "data/maps/SlateportCity/scripts.pory"

# 562 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 563 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_PowerTMs:
# 564 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_HIDDEN_POWER
# 565 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_SECRET_POWER
# 566 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 567 "data/maps/SlateportCity/scripts.pory"

# 568 "data/maps/SlateportCity/scripts.pory"
@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
# 569 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CaptStern::
# 570 "data/maps/SlateportCity/scripts.pory"
	lockall
# 571 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
# 572 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
# 573 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 574 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
# 575 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 576 "data/maps/SlateportCity/scripts.pory"
	delay 10
# 577 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
# 578 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 579 "data/maps/SlateportCity/scripts.pory"
	delay 25
# 580 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
# 581 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
# 582 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
# 583 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
# 584 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 585 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_GABBY
# 586 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_TY
# 587 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
# 588 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 589 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 590 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
# 591 "data/maps/SlateportCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 592 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
# 593 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
# 594 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
# 595 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
# 596 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
# 597 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
# 598 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 599 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
# 600 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 601 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
# 602 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 603 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
# 604 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 605 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
# 606 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 607 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 608 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 609 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
# 610 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 611 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 612 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
# 613 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
# 614 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 615 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_CAPT_STERN
# 616 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
# 617 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
# 618 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
# 619 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
# 620 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 2
# 621 "data/maps/SlateportCity/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
# 622 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 623 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 624 "data/maps/SlateportCity/scripts.pory"
	end
# 625 "data/maps/SlateportCity/scripts.pory"

# 626 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_OldWomanConcern:
# 627 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 628 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 629 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 630 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 631 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 632 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 633 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 634 "data/maps/SlateportCity/scripts.pory"
	step_end
# 635 "data/maps/SlateportCity/scripts.pory"

# 636 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ManConcern:
# 637 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 638 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 639 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 640 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 641 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 642 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 643 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 644 "data/maps/SlateportCity/scripts.pory"
	step_end
# 645 "data/maps/SlateportCity/scripts.pory"

# 646 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_GabbyExit:
# 647 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 648 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 649 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 650 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 651 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 652 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 653 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 654 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 655 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 656 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 657 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 658 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 659 "data/maps/SlateportCity/scripts.pory"
	step_end
# 660 "data/maps/SlateportCity/scripts.pory"

# 661 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_TyExit:
# 662 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 663 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 664 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 665 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 666 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 667 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 668 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 669 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 670 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 671 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 672 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 673 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 674 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 675 "data/maps/SlateportCity/scripts.pory"
	step_end
# 676 "data/maps/SlateportCity/scripts.pory"

# 677 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_Unused:
# 678 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 679 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 680 "data/maps/SlateportCity/scripts.pory"
	step_end
# 681 "data/maps/SlateportCity/scripts.pory"

# 682 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternEnterHarbor:
# 683 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 684 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 685 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 686 "data/maps/SlateportCity/scripts.pory"
	set_invisible
# 687 "data/maps/SlateportCity/scripts.pory"
	step_end
# 688 "data/maps/SlateportCity/scripts.pory"

# 689 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternWatchGabbyAndTyExit:
# 690 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 691 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 692 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 693 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 694 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 695 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 696 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 697 "data/maps/SlateportCity/scripts.pory"
	step_end
# 698 "data/maps/SlateportCity/scripts.pory"

# 699 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerEnterHarbor:
# 700 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 701 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 702 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 703 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 704 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 705 "data/maps/SlateportCity/scripts.pory"
	step_end
# 706 "data/maps/SlateportCity/scripts.pory"

# 707 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceStern:
# 708 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 709 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 710 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 711 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 712 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 713 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 714 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 715 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 716 "data/maps/SlateportCity/scripts.pory"
	step_end
# 717 "data/maps/SlateportCity/scripts.pory"

# 718 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Ty::
# 719 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
# 720 "data/maps/SlateportCity/scripts.pory"
	end
# 721 "data/maps/SlateportCity/scripts.pory"

# 722 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Gabby::
# 723 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
# 724 "data/maps/SlateportCity/scripts.pory"
	end
# 725 "data/maps/SlateportCity/scripts.pory"

# 726 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man3::
# 727 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
# 728 "data/maps/SlateportCity/scripts.pory"
	end
# 729 "data/maps/SlateportCity/scripts.pory"

# 730 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryPowderClerk::
# 731 "data/maps/SlateportCity/scripts.pory"
	lock
# 732 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 733 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
# 734 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
# 735 "data/maps/SlateportCity/scripts.pory"
	giveitem ITEM_POWDER_JAR
# 736 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_POWDER_JAR
# 737 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 738 "data/maps/SlateportCity/scripts.pory"
	release
# 739 "data/maps/SlateportCity/scripts.pory"
	end
# 740 "data/maps/SlateportCity/scripts.pory"

# 741 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ReceivedPowderJar::
# 742 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, 1
# 743 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 744 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
# 745 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
# 746 "data/maps/SlateportCity/scripts.pory"
	special DisplayBerryPowderVendorMenu
# 747 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 748 "data/maps/SlateportCity/scripts.pory"
	end
# 749 "data/maps/SlateportCity/scripts.pory"

# 750 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ExplainBerryPowder::
# 751 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 752 "data/maps/SlateportCity/scripts.pory"
	release
# 753 "data/maps/SlateportCity/scripts.pory"
	end
# 754 "data/maps/SlateportCity/scripts.pory"

# 755 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ChooseBerryPowderItem::
# 756 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ExchangeWhatWithIt
# 757 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 758 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
# 759 "data/maps/SlateportCity/scripts.pory"
	special ShowScrollableMultichoice
# 760 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 761 "data/maps/SlateportCity/scripts.pory"
	switch VAR_RESULT
# 762 "data/maps/SlateportCity/scripts.pory"
	case 0, SlateportCity_EventScript_EnergyPowder
# 763 "data/maps/SlateportCity/scripts.pory"
	case 1, SlateportCity_EventScript_EnergyRoot
# 764 "data/maps/SlateportCity/scripts.pory"
	case 2, SlateportCity_EventScript_HealPowder
# 765 "data/maps/SlateportCity/scripts.pory"
	case 3, SlateportCity_EventScript_RevivalHerb
# 766 "data/maps/SlateportCity/scripts.pory"
	case 4, SlateportCity_EventScript_Protein
# 767 "data/maps/SlateportCity/scripts.pory"
	case 5, SlateportCity_EventScript_Iron
# 768 "data/maps/SlateportCity/scripts.pory"
	case 6, SlateportCity_EventScript_Carbos
# 769 "data/maps/SlateportCity/scripts.pory"
	case 7, SlateportCity_EventScript_Calcium
# 770 "data/maps/SlateportCity/scripts.pory"
	case 8, SlateportCity_EventScript_Zinc
# 771 "data/maps/SlateportCity/scripts.pory"
	case 9, SlateportCity_EventScript_HPUp
# 772 "data/maps/SlateportCity/scripts.pory"
	case 10, SlateportCity_EventScript_PPUp
# 773 "data/maps/SlateportCity/scripts.pory"
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
# 774 "data/maps/SlateportCity/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
# 775 "data/maps/SlateportCity/scripts.pory"
	end
# 776 "data/maps/SlateportCity/scripts.pory"

# 777 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyPowder::
# 778 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
# 779 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
# 780 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 781 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 782 "data/maps/SlateportCity/scripts.pory"
	end
# 783 "data/maps/SlateportCity/scripts.pory"

# 784 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyRoot::
# 785 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
# 786 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
# 787 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 80
# 788 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 789 "data/maps/SlateportCity/scripts.pory"
	end
# 790 "data/maps/SlateportCity/scripts.pory"

# 791 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HealPowder::
# 792 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
# 793 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HEAL_POWDER
# 794 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 795 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 796 "data/maps/SlateportCity/scripts.pory"
	end
# 797 "data/maps/SlateportCity/scripts.pory"

# 798 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RevivalHerb::
# 799 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
# 800 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
# 801 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 300
# 802 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 803 "data/maps/SlateportCity/scripts.pory"
	end
# 804 "data/maps/SlateportCity/scripts.pory"

# 805 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Protein::
# 806 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PROTEIN
# 807 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PROTEIN
# 808 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 809 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 810 "data/maps/SlateportCity/scripts.pory"
	end
# 811 "data/maps/SlateportCity/scripts.pory"

# 812 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Iron::
# 813 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_IRON
# 814 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_IRON
# 815 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 816 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 817 "data/maps/SlateportCity/scripts.pory"
	end
# 818 "data/maps/SlateportCity/scripts.pory"

# 819 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Carbos::
# 820 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CARBOS
# 821 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CARBOS
# 822 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 823 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 824 "data/maps/SlateportCity/scripts.pory"
	end
# 825 "data/maps/SlateportCity/scripts.pory"

# 826 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Calcium::
# 827 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CALCIUM
# 828 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CALCIUM
# 829 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 830 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 831 "data/maps/SlateportCity/scripts.pory"
	end
# 832 "data/maps/SlateportCity/scripts.pory"

# 833 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Zinc::
# 834 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ZINC
# 835 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ZINC
# 836 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 837 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 838 "data/maps/SlateportCity/scripts.pory"
	end
# 839 "data/maps/SlateportCity/scripts.pory"

# 840 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HPUp::
# 841 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HP_UP
# 842 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HP_UP
# 843 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 844 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 845 "data/maps/SlateportCity/scripts.pory"
	end
# 846 "data/maps/SlateportCity/scripts.pory"

# 847 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PPUp::
# 848 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PP_UP
# 849 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PP_UP
# 850 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 3000
# 851 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 852 "data/maps/SlateportCity/scripts.pory"
	end
# 853 "data/maps/SlateportCity/scripts.pory"

# 854 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CancelPowderItemSelect::
# 855 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
# 856 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 857 "data/maps/SlateportCity/scripts.pory"
	release
# 858 "data/maps/SlateportCity/scripts.pory"
	end
# 859 "data/maps/SlateportCity/scripts.pory"

# 860 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_TryBuyBerryPowderItem::
# 861 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
# 862 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
# 863 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 864 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 865 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
# 866 "data/maps/SlateportCity/scripts.pory"
	giveitem VAR_0x8008
# 867 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
# 868 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 869 "data/maps/SlateportCity/scripts.pory"
	special TakeBerryPowder
# 870 "data/maps/SlateportCity/scripts.pory"
	special PrintPlayerBerryPowderAmount
# 871 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
# 872 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
# 873 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
# 874 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 875 "data/maps/SlateportCity/scripts.pory"
	release
# 876 "data/maps/SlateportCity/scripts.pory"
	end
# 877 "data/maps/SlateportCity/scripts.pory"

# 878 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NoRoomForBerryPowderItem::
# 879 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 880 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 881 "data/maps/SlateportCity/scripts.pory"
	release
# 882 "data/maps/SlateportCity/scripts.pory"
	end
# 883 "data/maps/SlateportCity/scripts.pory"

# 884 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NotEnoughBerryPowder::
# 885 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
# 886 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 887 "data/maps/SlateportCity/scripts.pory"
	end
# 888 "data/maps/SlateportCity/scripts.pory"

# 889 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottBattleTentScene::
# 890 "data/maps/SlateportCity/scripts.pory"
	lockall
# 891 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 892 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 893 "data/maps/SlateportCity/scripts.pory"
	opendoor 10, 12
# 894 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 895 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SCOTT
# 896 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
# 897 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
# 898 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 899 "data/maps/SlateportCity/scripts.pory"
	closedoor 10, 12
# 900 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 901 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
# 902 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 903 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
# 904 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
# 905 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 906 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 907 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 908 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 909 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 910 "data/maps/SlateportCity/scripts.pory"
	end
# 911 "data/maps/SlateportCity/scripts.pory"

# 912 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PushPlayerDown:
# 913 "data/maps/SlateportCity/scripts.pory"
	lock_facing_direction
# 914 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 915 "data/maps/SlateportCity/scripts.pory"
	unlock_facing_direction
# 916 "data/maps/SlateportCity/scripts.pory"
	step_end
# 917 "data/maps/SlateportCity/scripts.pory"

# 918 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerWatchScottExit:
# 919 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 920 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 921 "data/maps/SlateportCity/scripts.pory"
	step_end
# 922 "data/maps/SlateportCity/scripts.pory"

# 923 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitBattleTent:
# 924 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 925 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 926 "data/maps/SlateportCity/scripts.pory"
	step_end
# 927 "data/maps/SlateportCity/scripts.pory"

# 928 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitAfterBattleTent:
# 929 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 930 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 931 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 932 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 933 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 934 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 935 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 936 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 937 "data/maps/SlateportCity/scripts.pory"
	step_end
# 938 "data/maps/SlateportCity/scripts.pory"

# 939 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryCrushRankingsSign::
# 940 "data/maps/SlateportCity/scripts.pory"
	lockall
# 941 "data/maps/SlateportCity/scripts.pory"
	special ShowBerryCrushRankings
# 942 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 943 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 944 "data/maps/SlateportCity/scripts.pory"
	end
# 945 "data/maps/SlateportCity/scripts.pory"

# 946 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EnergyGuruSellWhatYouNeed:
# 947 "data/maps/SlateportCity/scripts.pory"
	.string "I'm the ENERGY GURU! I'll go for it and\n"
# 948 "data/maps/SlateportCity/scripts.pory"
	.string "sell you what you need!$"
# 949 "data/maps/SlateportCity/scripts.pory"

# 950 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhYourPokemon:
# 951 "data/maps/SlateportCity/scripts.pory"
	.string "Oh?\n"
# 952 "data/maps/SlateportCity/scripts.pory"
	.string "Your {STR_VAR_1}…$"
# 953 "data/maps/SlateportCity/scripts.pory"

# 954 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseGiveItThisEffortRibbon:
# 955 "data/maps/SlateportCity/scripts.pory"
	.string "Went for it stupendously!\p"
# 956 "data/maps/SlateportCity/scripts.pory"
	.string "As its reward, please give it this\n"
# 957 "data/maps/SlateportCity/scripts.pory"
	.string "EFFORT RIBBON.$"
# 958 "data/maps/SlateportCity/scripts.pory"

# 959 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ReceivedEffortRibbon:
# 960 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} received the EFFORT RIBBON.$"
# 961 "data/maps/SlateportCity/scripts.pory"

# 962 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PutEffortRibbonOnMon:
# 963 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} put the EFFORT RIBBON\n"
# 964 "data/maps/SlateportCity/scripts.pory"
	.string "on {STR_VAR_1}.$"
# 965 "data/maps/SlateportCity/scripts.pory"

# 966 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoForItLittleHarder:
# 967 "data/maps/SlateportCity/scripts.pory"
	.string "You have to go for it a little harder.\p"
# 968 "data/maps/SlateportCity/scripts.pory"
	.string "If you do, I'll give your POKéMON\n"
# 969 "data/maps/SlateportCity/scripts.pory"
	.string "something nice.$"
# 970 "data/maps/SlateportCity/scripts.pory"

# 971 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EffortRibbonLooksGoodOnIt:
# 972 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
# 973 "data/maps/SlateportCity/scripts.pory"
	.string "RIBBON looks good on it!$"
# 974 "data/maps/SlateportCity/scripts.pory"

# 975 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
# 976 "data/maps/SlateportCity/scripts.pory"
	.string "The light of the lighthouse reaches\n"
# 977 "data/maps/SlateportCity/scripts.pory"
	.string "dozens of miles away.\p"
# 978 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder if it doesn't startle POKéMON\n"
# 979 "data/maps/SlateportCity/scripts.pory"
	.string "in the sea.$"
# 980 "data/maps/SlateportCity/scripts.pory"

# 981 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaweedFullOfLife:
# 982 "data/maps/SlateportCity/scripts.pory"
	.string "Ooh, look at this!\p"
# 983 "data/maps/SlateportCity/scripts.pory"
	.string "The seaweed you can get around these\n"
# 984 "data/maps/SlateportCity/scripts.pory"
	.string "parts is fresh and full of life.\p"
# 985 "data/maps/SlateportCity/scripts.pory"
	.string "Why, it looks like it can even rear up\n"
# 986 "data/maps/SlateportCity/scripts.pory"
	.string "and attack!$"
# 987 "data/maps/SlateportCity/scripts.pory"

# 988 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HowTownIsBornAndGrows:
# 989 "data/maps/SlateportCity/scripts.pory"
	.string "Where the water is clean, the fruits\n"
# 990 "data/maps/SlateportCity/scripts.pory"
	.string "of bountiful harvest gather.\p"
# 991 "data/maps/SlateportCity/scripts.pory"
	.string "And where people gather, a market\n"
# 992 "data/maps/SlateportCity/scripts.pory"
	.string "soon starts.\p"
# 993 "data/maps/SlateportCity/scripts.pory"
	.string "That is how a town is born and grows.$"
# 994 "data/maps/SlateportCity/scripts.pory"

# 995 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SlateportWonderfulPlace:
# 996 "data/maps/SlateportCity/scripts.pory"
	.string "Shopping where you can breathe the\n"
# 997 "data/maps/SlateportCity/scripts.pory"
	.string "scent of the ocean…\p"
# 998 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT is such a wonderful place!$"
# 999 "data/maps/SlateportCity/scripts.pory"

# 1000 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
# 1001 "data/maps/SlateportCity/scripts.pory"
	.string "If you put DOLLS or CUSHIONS on\n"
# 1002 "data/maps/SlateportCity/scripts.pory"
	.string "the floor, they'll get dirty.\p"
# 1003 "data/maps/SlateportCity/scripts.pory"
	.string "I'm going to buy some BRICKS so my\n"
# 1004 "data/maps/SlateportCity/scripts.pory"
	.string "DOLLS and CUSHIONS won't get dirty\l"
# 1005 "data/maps/SlateportCity/scripts.pory"
	.string "when I leave them out.$"
# 1006 "data/maps/SlateportCity/scripts.pory"

# 1007 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoingToCompeteInBattleTent:
# 1008 "data/maps/SlateportCity/scripts.pory"
	.string "Wroooar! I'm going to compete in\n"
# 1009 "data/maps/SlateportCity/scripts.pory"
	.string "the BATTLE TENT, too!\p"
# 1010 "data/maps/SlateportCity/scripts.pory"
	.string "But before that, I need to catch\n"
# 1011 "data/maps/SlateportCity/scripts.pory"
	.string "some POKéMON!$"
# 1012 "data/maps/SlateportCity/scripts.pory"

# 1013 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BushedHikingFromMauville:
# 1014 "data/maps/SlateportCity/scripts.pory"
	.string "Whew… I'm just bushed…\p"
# 1015 "data/maps/SlateportCity/scripts.pory"
	.string "I hiked over from MAUVILLE CITY.\n"
# 1016 "data/maps/SlateportCity/scripts.pory"
	.string "But, boy, this city's huge.\p"
# 1017 "data/maps/SlateportCity/scripts.pory"
	.string "If I'd known this, I would've ridden\n"
# 1018 "data/maps/SlateportCity/scripts.pory"
	.string "my BIKE here.$"
# 1019 "data/maps/SlateportCity/scripts.pory"

# 1020 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EveryoneCallsHimCaptStern:
# 1021 "data/maps/SlateportCity/scripts.pory"
	.string "STERN, the fellow who built the\n"
# 1022 "data/maps/SlateportCity/scripts.pory"
	.string "MUSEUM, also happens to be the leader\l"
# 1023 "data/maps/SlateportCity/scripts.pory"
	.string "of an undersea exploration team.\p"
# 1024 "data/maps/SlateportCity/scripts.pory"
	.string "So, everyone calls him CAPT. STERN.$"
# 1025 "data/maps/SlateportCity/scripts.pory"

# 1026 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsLongLineOverThere:
# 1027 "data/maps/SlateportCity/scripts.pory"
	.string "What is that over there?\n"
# 1028 "data/maps/SlateportCity/scripts.pory"
	.string "That long line…$"
# 1029 "data/maps/SlateportCity/scripts.pory"

# 1030 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_VisitedMuseumOften:
# 1031 "data/maps/SlateportCity/scripts.pory"
	.string "When I was a child, I visited\n"
# 1032 "data/maps/SlateportCity/scripts.pory"
	.string "the MUSEUM often.\p"
# 1033 "data/maps/SlateportCity/scripts.pory"
	.string "I used to dream about the mysteries of\n"
# 1034 "data/maps/SlateportCity/scripts.pory"
	.string "the sea after seeing the exhibits.$"
# 1035 "data/maps/SlateportCity/scripts.pory"

# 1036 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_QuitPushing:
# 1037 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, there! Quit pushing!\n"
# 1038 "data/maps/SlateportCity/scripts.pory"
	.string "This is the line, can't you see?$"
# 1039 "data/maps/SlateportCity/scripts.pory"

# 1040 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaHasPolicy:
# 1041 "data/maps/SlateportCity/scripts.pory"
	.string "TEAM AQUA has a policy of\n"
# 1042 "data/maps/SlateportCity/scripts.pory"
	.string "assembling and dispersing at\l"
# 1043 "data/maps/SlateportCity/scripts.pory"
	.string "the operation site.$"
# 1044 "data/maps/SlateportCity/scripts.pory"

# 1045 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BossIsBrilliant:
# 1046 "data/maps/SlateportCity/scripts.pory"
	.string "Our BOSS is brilliant.\p"
# 1047 "data/maps/SlateportCity/scripts.pory"
	.string "What would he want to do with\n"
# 1048 "data/maps/SlateportCity/scripts.pory"
	.string "a MUSEUM now?$"
# 1049 "data/maps/SlateportCity/scripts.pory"

# 1050 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsNewSchemeIWonder:
# 1051 "data/maps/SlateportCity/scripts.pory"
	.string "What's the new scheme, I wonder?\p"
# 1052 "data/maps/SlateportCity/scripts.pory"
	.string "Our BOSS is scary when he's mad, so\n"
# 1053 "data/maps/SlateportCity/scripts.pory"
	.string "I'd better not screw things up…$"
# 1054 "data/maps/SlateportCity/scripts.pory"

# 1055 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldTakeItAll:
# 1056 "data/maps/SlateportCity/scripts.pory"
	.string "If there's something we need in\n"
# 1057 "data/maps/SlateportCity/scripts.pory"
	.string "the MUSEUM, we should take it all!$"
# 1058 "data/maps/SlateportCity/scripts.pory"

# 1059 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontButtIn:
# 1060 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, you there!\n"
# 1061 "data/maps/SlateportCity/scripts.pory"
	.string "Don't butt in!$"
# 1062 "data/maps/SlateportCity/scripts.pory"

# 1063 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RemindsMeOfLongLineForGames:
# 1064 "data/maps/SlateportCity/scripts.pory"
	.string "A long line, huh?\p"
# 1065 "data/maps/SlateportCity/scripts.pory"
	.string "It reminds me of the times I lined up to\n"
# 1066 "data/maps/SlateportCity/scripts.pory"
	.string "buy smash-hit games…$"
# 1067 "data/maps/SlateportCity/scripts.pory"

# 1068 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhyAreWeLiningUp:
# 1069 "data/maps/SlateportCity/scripts.pory"
	.string "Why are we even lining up and paying?\n"
# 1070 "data/maps/SlateportCity/scripts.pory"
	.string "We should just march in!$"
# 1071 "data/maps/SlateportCity/scripts.pory"

# 1072 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatDoYouWant:
# 1073 "data/maps/SlateportCity/scripts.pory"
	.string "What?\n"
# 1074 "data/maps/SlateportCity/scripts.pory"
	.string "What do you want?$"
# 1075 "data/maps/SlateportCity/scripts.pory"

# 1076 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_IllReadSignForYou:
# 1077 "data/maps/SlateportCity/scripts.pory"
	.string "You want to read this sign?\n"
# 1078 "data/maps/SlateportCity/scripts.pory"
	.string "I'll read it for you!$"
# 1079 "data/maps/SlateportCity/scripts.pory"

# 1080 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
# 1081 "data/maps/SlateportCity/scripts.pory"
	.string "Let's see…\p"
# 1082 "data/maps/SlateportCity/scripts.pory"
	.string "Um… I think it says something like\n"
# 1083 "data/maps/SlateportCity/scripts.pory"
	.string "“the life in the sea is endless.”\p"
# 1084 "data/maps/SlateportCity/scripts.pory"
	.string "Yup, I'm pretty sure that's what\n"
# 1085 "data/maps/SlateportCity/scripts.pory"
	.string "it says.$"
# 1086 "data/maps/SlateportCity/scripts.pory"

# 1087 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldveBroughtMyGameBoy:
# 1088 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…\p"
# 1089 "data/maps/SlateportCity/scripts.pory"
	.string "I should've brought my Game Boy\n"
# 1090 "data/maps/SlateportCity/scripts.pory"
	.string "Advance so I wouldn't get bored in line…\p"
# 1091 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…$"
# 1092 "data/maps/SlateportCity/scripts.pory"

# 1093 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HotSpringsAfterOperation:
# 1094 "data/maps/SlateportCity/scripts.pory"
	.string "When this operation's over, I'll take\n"
# 1095 "data/maps/SlateportCity/scripts.pory"
	.string "you to a hot spring spa!\p"
# 1096 "data/maps/SlateportCity/scripts.pory"
	.string "That's what our leader said.\n"
# 1097 "data/maps/SlateportCity/scripts.pory"
	.string "I can't wait!$"
# 1098 "data/maps/SlateportCity/scripts.pory"

# 1099 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaIsSoWet:
# 1100 "data/maps/SlateportCity/scripts.pory"
	.string "The sea is just so vast…\p"
# 1101 "data/maps/SlateportCity/scripts.pory"
	.string "Could the sea have been made by\n"
# 1102 "data/maps/SlateportCity/scripts.pory"
	.string "the tears shed by POKéMON?$"
# 1103 "data/maps/SlateportCity/scripts.pory"

# 1104 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SinkOldBoats:
# 1105 "data/maps/SlateportCity/scripts.pory"
	.string "Do you know what they do with old\n"
# 1106 "data/maps/SlateportCity/scripts.pory"
	.string "ships that become too creaky to sail?\p"
# 1107 "data/maps/SlateportCity/scripts.pory"
	.string "They sink them in the sea so they\n"
# 1108 "data/maps/SlateportCity/scripts.pory"
	.string "become habitats for POKéMON.$"
# 1109 "data/maps/SlateportCity/scripts.pory"

# 1110 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyTooMuch:
# 1111 "data/maps/SlateportCity/scripts.pory"
	.string "Whenever I visit here, I get carried\n"
# 1112 "data/maps/SlateportCity/scripts.pory"
	.string "away and buy too much.$"
# 1113 "data/maps/SlateportCity/scripts.pory"

# 1114 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GetNameRaterToHelpYou:
# 1115 "data/maps/SlateportCity/scripts.pory"
	.string "If you want to change your POKéMON's\n"
# 1116 "data/maps/SlateportCity/scripts.pory"
	.string "nickname, you'll have to get the NAME\l"
# 1117 "data/maps/SlateportCity/scripts.pory"
	.string "RATER to help you.$"
# 1118 "data/maps/SlateportCity/scripts.pory"

# 1119 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CantChangeTradeMonName:
# 1120 "data/maps/SlateportCity/scripts.pory"
	.string "Any POKéMON you get in a trade,\n"
# 1121 "data/maps/SlateportCity/scripts.pory"
	.string "you can't change its nickname.\p"
# 1122 "data/maps/SlateportCity/scripts.pory"
	.string "The original TRAINER's love for that\n"
# 1123 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON is in the nickname.$"
# 1124 "data/maps/SlateportCity/scripts.pory"

# 1125 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentBuiltRecently:
# 1126 "data/maps/SlateportCity/scripts.pory"
	.string "Recently, a BATTLE TENT was built\n"
# 1127 "data/maps/SlateportCity/scripts.pory"
	.string "in SLATEPORT.\p"
# 1128 "data/maps/SlateportCity/scripts.pory"
	.string "GYMS are fun, but the BATTLE TENT's\n"
# 1129 "data/maps/SlateportCity/scripts.pory"
	.string "awesome in its own way.\p"
# 1130 "data/maps/SlateportCity/scripts.pory"
	.string "You should go find tough POKéMON\n"
# 1131 "data/maps/SlateportCity/scripts.pory"
	.string "for the BATTLE TENT!$"
# 1132 "data/maps/SlateportCity/scripts.pory"

# 1133 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptSternBeingInterviewed:
# 1134 "data/maps/SlateportCity/scripts.pory"
	.string "I was hoping that it was a famous star\n"
# 1135 "data/maps/SlateportCity/scripts.pory"
	.string "so I could get an autograph.\p"
# 1136 "data/maps/SlateportCity/scripts.pory"
	.string "But who's that being interviewed?\n"
# 1137 "data/maps/SlateportCity/scripts.pory"
	.string "Isn't that CAPT. STERN?$"
# 1138 "data/maps/SlateportCity/scripts.pory"

# 1139 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_InterviewerSoCool:
# 1140 "data/maps/SlateportCity/scripts.pory"
	.string "That lady interviewer is so cool\n"
# 1141 "data/maps/SlateportCity/scripts.pory"
	.string "and pretty.\p"
# 1142 "data/maps/SlateportCity/scripts.pory"
	.string "When I grow up, I'm going to be\n"
# 1143 "data/maps/SlateportCity/scripts.pory"
	.string "an international journalist!$"
# 1144 "data/maps/SlateportCity/scripts.pory"

# 1145 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternSaysDiscoveredSomething:
# 1146 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN says they discovered\n"
# 1147 "data/maps/SlateportCity/scripts.pory"
	.string "something at the bottom of the sea.\p"
# 1148 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder what it is?\n"
# 1149 "data/maps/SlateportCity/scripts.pory"
	.string "What could it be?$"
# 1150 "data/maps/SlateportCity/scripts.pory"

# 1151 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainComeBackWithBigFish:
# 1152 "data/maps/SlateportCity/scripts.pory"
	.string "What's going on here?\p"
# 1153 "data/maps/SlateportCity/scripts.pory"
	.string "Did the good CAPTAIN come back with\n"
# 1154 "data/maps/SlateportCity/scripts.pory"
	.string "a big fish from the ocean floor?$"
# 1155 "data/maps/SlateportCity/scripts.pory"

# 1156 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AmIOnTV:
# 1157 "data/maps/SlateportCity/scripts.pory"
	.string "Hey! Are you watching?\n"
# 1158 "data/maps/SlateportCity/scripts.pory"
	.string "Am I on TV?$"
# 1159 "data/maps/SlateportCity/scripts.pory"

# 1160 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainsACelebrity:
# 1161 "data/maps/SlateportCity/scripts.pory"
	.string "A TV interview! Here!\n"
# 1162 "data/maps/SlateportCity/scripts.pory"
	.string "The CAPTAIN's a celebrity!$"
# 1163 "data/maps/SlateportCity/scripts.pory"

# 1164 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BigSmileForCamera:
# 1165 "data/maps/SlateportCity/scripts.pory"
	.string "TY: Okay, CAPT. STERN, a big smile\n"
# 1166 "data/maps/SlateportCity/scripts.pory"
	.string "for the camera!$"
# 1167 "data/maps/SlateportCity/scripts.pory"

# 1168 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MostInvaluableExperience:
# 1169 "data/maps/SlateportCity/scripts.pory"
	.string "GABBY: I see, I see. You've had a most\n"
# 1170 "data/maps/SlateportCity/scripts.pory"
	.string "invaluable experience…$"
# 1171 "data/maps/SlateportCity/scripts.pory"

# 1172 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternMoveAheadWithExploration:
# 1173 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
# 1174 "data/maps/SlateportCity/scripts.pory"
	.string "move ahead with our exploration.$"
# 1175 "data/maps/SlateportCity/scripts.pory"

# 1176 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GabbyWonderfulThanksForInterview:
# 1177 "data/maps/SlateportCity/scripts.pory"
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
# 1178 "data/maps/SlateportCity/scripts.pory"
	.string "Thank you for taking the time from\l"
# 1179 "data/maps/SlateportCity/scripts.pory"
	.string "your busy schedule to talk to us.\p"
# 1180 "data/maps/SlateportCity/scripts.pory"
	.string "We hope we can interview you again\n"
# 1181 "data/maps/SlateportCity/scripts.pory"
	.string "with news of more discoveries!$"
# 1182 "data/maps/SlateportCity/scripts.pory"

# 1183 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhewFirstInterview:
# 1184 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Whew…\p"
# 1185 "data/maps/SlateportCity/scripts.pory"
	.string "That was my first time to be filmed for\n"
# 1186 "data/maps/SlateportCity/scripts.pory"
	.string "TV. That was nerve-wracking.$"
# 1187 "data/maps/SlateportCity/scripts.pory"

# 1188 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhPlayerWeMadeDiscovery:
# 1189 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! {PLAYER}{KUN}!\n"
# 1190 "data/maps/SlateportCity/scripts.pory"
	.string "You're looking great!\p"
# 1191 "data/maps/SlateportCity/scripts.pory"
	.string "We made a huge discovery on our last\n"
# 1192 "data/maps/SlateportCity/scripts.pory"
	.string "seafloor exploration.\p"
# 1193 "data/maps/SlateportCity/scripts.pory"
	.string "We found an underwater cavern on\n"
# 1194 "data/maps/SlateportCity/scripts.pory"
	.string "ROUTE 128.\p"
# 1195 "data/maps/SlateportCity/scripts.pory"
	.string "We think it's the habitat of a POKéMON\n"
# 1196 "data/maps/SlateportCity/scripts.pory"
	.string "that's said to have been long extinct.$"
# 1197 "data/maps/SlateportCity/scripts.pory"

# 1198 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
# 1199 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1200 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN, I presume.\p"
# 1201 "data/maps/SlateportCity/scripts.pory"
	.string "We of TEAM AQUA will assume\n"
# 1202 "data/maps/SlateportCity/scripts.pory"
	.string "control of your submarine!\p"
# 1203 "data/maps/SlateportCity/scripts.pory"
	.string "Your objections are meaningless!\n"
# 1204 "data/maps/SlateportCity/scripts.pory"
	.string "We expect your total cooperation!\p"
# 1205 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1206 "data/maps/SlateportCity/scripts.pory"
	.string "Just watch and learn what TEAM\l"
# 1207 "data/maps/SlateportCity/scripts.pory"
	.string "AQUA has planned!$"
# 1208 "data/maps/SlateportCity/scripts.pory"

# 1209 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhatWasAllThat:
# 1210 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: What was that all about?\p"
# 1211 "data/maps/SlateportCity/scripts.pory"
	.string "It sounded like someone using\n"
# 1212 "data/maps/SlateportCity/scripts.pory"
	.string "a megaphone…\p"
# 1213 "data/maps/SlateportCity/scripts.pory"
	.string "Where did it come from?$"
# 1214 "data/maps/SlateportCity/scripts.pory"

# 1215 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FromHarborTryingToTakeSub:
# 1216 "data/maps/SlateportCity/scripts.pory"
	.string "It's from the HARBOR!\p"
# 1217 "data/maps/SlateportCity/scripts.pory"
	.string "The submarine!\n"
# 1218 "data/maps/SlateportCity/scripts.pory"
	.string "They're trying to take it!$"
# 1219 "data/maps/SlateportCity/scripts.pory"

# 1220 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseComeWithMe:
# 1221 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 1222 "data/maps/SlateportCity/scripts.pory"
	.string "Please, come with me!$"
# 1223 "data/maps/SlateportCity/scripts.pory"

# 1224 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentSign:
# 1225 "data/maps/SlateportCity/scripts.pory"
	.string "BATTLE TENT SLATEPORT SITE\n"
# 1226 "data/maps/SlateportCity/scripts.pory"
	.string "“Find it! The ultimate POKéMON!”$"
# 1227 "data/maps/SlateportCity/scripts.pory"

# 1228 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardWantedSign:
# 1229 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1230 "data/maps/SlateportCity/scripts.pory"
	.string "“Wanted: A sailor capable of sailing\n"
# 1231 "data/maps/SlateportCity/scripts.pory"
	.string "in all currents.”$"
# 1232 "data/maps/SlateportCity/scripts.pory"

# 1233 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardNearsCompletion:
# 1234 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1235 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL nears\n"
# 1236 "data/maps/SlateportCity/scripts.pory"
	.string "completion for serving the ports of\l"
# 1237 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT and LILYCOVE.”$"
# 1238 "data/maps/SlateportCity/scripts.pory"

# 1239 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardFerryComplete:
# 1240 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1241 "data/maps/SlateportCity/scripts.pory"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
# 1242 "data/maps/SlateportCity/scripts.pory"
	.string "ferry S.S. TIDAL is handled at the\l"
# 1243 "data/maps/SlateportCity/scripts.pory"
	.string "HARBOR.”$"
# 1244 "data/maps/SlateportCity/scripts.pory"

# 1245 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PokemonFanClubSign:
# 1246 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON FAN CLUB\n"
# 1247 "data/maps/SlateportCity/scripts.pory"
	.string "“Calling all fans of POKéMON!”$"
# 1248 "data/maps/SlateportCity/scripts.pory"

# 1249 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OceanicMuseumSign:
# 1250 "data/maps/SlateportCity/scripts.pory"
	.string "“The endless sea sustains\n"
# 1251 "data/maps/SlateportCity/scripts.pory"
	.string "all life.”\p"
# 1252 "data/maps/SlateportCity/scripts.pory"
	.string "OCEANIC MUSEUM$"
# 1253 "data/maps/SlateportCity/scripts.pory"

# 1254 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CitySign:
# 1255 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT CITY\p"
# 1256 "data/maps/SlateportCity/scripts.pory"
	.string "“The port where people and POKéMON\n"
# 1257 "data/maps/SlateportCity/scripts.pory"
	.string "cross paths.”$"
# 1258 "data/maps/SlateportCity/scripts.pory"

# 1259 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MarketSign:
# 1260 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT MARKET\n"
# 1261 "data/maps/SlateportCity/scripts.pory"
	.string "“Unique items found nowhere else!”$"
# 1262 "data/maps/SlateportCity/scripts.pory"

# 1263 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborFerryUnderConstruction:
# 1264 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1265 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 1266 "data/maps/SlateportCity/scripts.pory"
	.string "construction in the SHIPYARD.\p"
# 1267 "data/maps/SlateportCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 1268 "data/maps/SlateportCity/scripts.pory"
	.string "shortly.”$"
# 1269 "data/maps/SlateportCity/scripts.pory"

# 1270 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborSign:
# 1271 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1272 "data/maps/SlateportCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 1273 "data/maps/SlateportCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 1274 "data/maps/SlateportCity/scripts.pory"

# 1275 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_NameRatersHouseSign:
# 1276 "data/maps/SlateportCity/scripts.pory"
	.string "NAME RATER'S HOUSE\n"
# 1277 "data/maps/SlateportCity/scripts.pory"
	.string "“POKéMON nicknames rated.”$"
# 1278 "data/maps/SlateportCity/scripts.pory"

# 1279 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerries:
# 1280 "data/maps/SlateportCity/scripts.pory"
	.string "If a wild POKéMON gets hurt, it heals\n"
# 1281 "data/maps/SlateportCity/scripts.pory"
	.string "itself by chewing on BERRIES.\p"
# 1282 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1283 "data/maps/SlateportCity/scripts.pory"
	.string "Somebody saw that and got the idea\n"
# 1284 "data/maps/SlateportCity/scripts.pory"
	.string "of making medicine from BERRIES.\p"
# 1285 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1286 "data/maps/SlateportCity/scripts.pory"
	.string "To turn BERRIES into medicine,\n"
# 1287 "data/maps/SlateportCity/scripts.pory"
	.string "they must be crushed into powder.\p"
# 1288 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1289 "data/maps/SlateportCity/scripts.pory"
	.string "You seem to have an interest\n"
# 1290 "data/maps/SlateportCity/scripts.pory"
	.string "in BERRIES!\p"
# 1291 "data/maps/SlateportCity/scripts.pory"
	.string "I've got something good for someone\n"
# 1292 "data/maps/SlateportCity/scripts.pory"
	.string "like you.$"
# 1293 "data/maps/SlateportCity/scripts.pory"

# 1294 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerryPowder:
# 1295 "data/maps/SlateportCity/scripts.pory"
	.string "I recently had machines installed at\n"
# 1296 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
# 1297 "data/maps/SlateportCity/scripts.pory"
	.string "The BERRY CRUSH machines are at\n"
# 1298 "data/maps/SlateportCity/scripts.pory"
	.string "the DIRECT CORNER upstairs.\p"
# 1299 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?\p"
# 1300 "data/maps/SlateportCity/scripts.pory"
	.string "Could you make BERRY POWDER for\n"
# 1301 "data/maps/SlateportCity/scripts.pory"
	.string "me using those machines?\p"
# 1302 "data/maps/SlateportCity/scripts.pory"
	.string "I can make you all sorts of medicine\n"
# 1303 "data/maps/SlateportCity/scripts.pory"
	.string "if you bring me lots of BERRY POWDER.$"
# 1304 "data/maps/SlateportCity/scripts.pory"

# 1305 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BroughtMeSomeBerryPowder:
# 1306 "data/maps/SlateportCity/scripts.pory"
	.string "Have you brought me some\n"
# 1307 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER?$"
# 1308 "data/maps/SlateportCity/scripts.pory"

# 1309 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeWhatWithIt:
# 1310 "data/maps/SlateportCity/scripts.pory"
	.string "What would you like to exchange\n"
# 1311 "data/maps/SlateportCity/scripts.pory"
	.string "it with?$"
# 1312 "data/maps/SlateportCity/scripts.pory"

# 1313 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeBerryPowderForItem:
# 1314 "data/maps/SlateportCity/scripts.pory"
	.string "Okay, you want to exchange your\n"
# 1315 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for one {STR_VAR_1}?$"
# 1316 "data/maps/SlateportCity/scripts.pory"

# 1317 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontHaveEnoughBerryPowder:
# 1318 "data/maps/SlateportCity/scripts.pory"
	.string "Oh, dear. You don't have enough\n"
# 1319 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER.$"
# 1320 "data/maps/SlateportCity/scripts.pory"

# 1321 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FineBerryPowderTradeSomethingElse:
# 1322 "data/maps/SlateportCity/scripts.pory"
	.string "This is fine BERRY POWDER.\n"
# 1323 "data/maps/SlateportCity/scripts.pory"
	.string "It will make excellent medicine.\p"
# 1324 "data/maps/SlateportCity/scripts.pory"
	.string "Would you like to trade more of your\n"
# 1325 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for something else?$"
# 1326 "data/maps/SlateportCity/scripts.pory"

# 1327 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhenYouGetMoreBringItToMe:
# 1328 "data/maps/SlateportCity/scripts.pory"
	.string "Okay! When you get some more\n"
# 1329 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER, bring it to me, please!$"
# 1330 "data/maps/SlateportCity/scripts.pory"

# 1331 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ComeBackToTradeBerryPowder:
# 1332 "data/maps/SlateportCity/scripts.pory"
	.string "Come back if you'd like to trade your\n"
# 1333 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for some medicine.\p"
# 1334 "data/maps/SlateportCity/scripts.pory"
	.string "I'm always running a bazaar here.\p"
# 1335 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?$"
# 1336 "data/maps/SlateportCity/scripts.pory"

# 1337 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_YouDroveTeamAquaAway:
# 1338 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Huh?\n"
# 1339 "data/maps/SlateportCity/scripts.pory"
	.string "I'm sure I met you somewhere before.\p"
# 1340 "data/maps/SlateportCity/scripts.pory"
	.string "Have I introduced myself to you?\n"
# 1341 "data/maps/SlateportCity/scripts.pory"
	.string "If not, my name's SCOTT.\p"
# 1342 "data/maps/SlateportCity/scripts.pory"
	.string "I just saw TEAM AQUA run away from\n"
# 1343 "data/maps/SlateportCity/scripts.pory"
	.string "here like they were stung.\p"
# 1344 "data/maps/SlateportCity/scripts.pory"
	.string "Let me guess--you drove them away?$"
# 1345 "data/maps/SlateportCity/scripts.pory"

# 1346 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MaybeThisTrainer:
# 1347 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Hmm…\n"
# 1348 "data/maps/SlateportCity/scripts.pory"
	.string "Maybe, just maybe, this TRAINER…$"
# 1349 "data/maps/SlateportCity/scripts.pory"

# 1350 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_LetsRegisterEachOther:
# 1351 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: All right! I think you're going\n"
# 1352 "data/maps/SlateportCity/scripts.pory"
	.string "to become a good friend.\p"
# 1353 "data/maps/SlateportCity/scripts.pory"
	.string "So, let's register each other in our\n"
# 1354 "data/maps/SlateportCity/scripts.pory"
	.string "POKéNAVS.\p"
# 1355 "data/maps/SlateportCity/scripts.pory"
	.string "… … … … … …$"
# 1356 "data/maps/SlateportCity/scripts.pory"

# 1357 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RegisteredScott:
# 1358 "data/maps/SlateportCity/scripts.pory"
	.string "Registered this SCOTT person\n"
# 1359 "data/maps/SlateportCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1360 "data/maps/SlateportCity/scripts.pory"

# 1361 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
# 1362 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: What I'd like to do is tag along\n"
# 1363 "data/maps/SlateportCity/scripts.pory"
	.string "with you, but I do want to keep an eye\l"
# 1364 "data/maps/SlateportCity/scripts.pory"
	.string "on the talents of other people, too.\p"
# 1365 "data/maps/SlateportCity/scripts.pory"
	.string "So, I'll be off to roam other towns\n"
# 1366 "data/maps/SlateportCity/scripts.pory"
	.string "a bit more.\p"
# 1367 "data/maps/SlateportCity/scripts.pory"
	.string "Be seeing you, {PLAYER}{KUN}!$"
# 1368 "data/maps/SlateportCity/scripts.pory"

# 1369 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_TakingBattleTentChallenge:
# 1370 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Oh, hey!\n"
# 1371 "data/maps/SlateportCity/scripts.pory"
	.string "If it isn't {PLAYER}{KUN}!\p"
# 1372 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
# 1373 "data/maps/SlateportCity/scripts.pory"
	.string "to take the BATTLE TENT challenge?\p"
# 1374 "data/maps/SlateportCity/scripts.pory"
	.string "Yeah! That's a good idea!\n"
# 1375 "data/maps/SlateportCity/scripts.pory"
	.string "That's a really great idea!\p"
# 1376 "data/maps/SlateportCity/scripts.pory"
	.string "After all, a tough TRAINER is\n"
# 1377 "data/maps/SlateportCity/scripts.pory"
	.string "the perfect fit for the BATTLE TENT!\p"
# 1378 "data/maps/SlateportCity/scripts.pory"
	.string "Give it your best effort!$"
