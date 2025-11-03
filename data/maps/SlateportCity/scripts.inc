# 1 "data/maps/SlateportCity/scripts.pory"

# 2 "data/maps/SlateportCity/scripts.pory"
SlateportCity_MapScripts::
# 3 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
# 4 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
# 5 "data/maps/SlateportCity/scripts.pory"
	.byte 0
# 6 "data/maps/SlateportCity/scripts.pory"

# 7 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnTransition:
# 8 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
# 9 "data/maps/SlateportCity/scripts.pory"
	call SlateportCity_EventScript_EnterSlateport
# 10 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
# 11 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
# 12 "data/maps/SlateportCity/scripts.pory"
	end
# 13 "data/maps/SlateportCity/scripts.pory"

# 14 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnterSlateport::
# 15 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 16 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 17 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
# 18 "data/maps/SlateportCity/scripts.pory"
	return
# 19 "data/maps/SlateportCity/scripts.pory"

# 20 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MovePeopleForSternInterview::
# 21 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
# 22 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
# 23 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
# 24 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
# 25 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
# 26 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
# 27 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
# 28 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
# 29 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 30 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
# 31 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
# 32 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
# 33 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
# 34 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
# 35 "data/maps/SlateportCity/scripts.pory"
	return
# 36 "data/maps/SlateportCity/scripts.pory"

# 37 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SetReadyForScottScene::
# 38 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 39 "data/maps/SlateportCity/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 40 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
# 41 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
# 42 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 43 "data/maps/SlateportCity/scripts.pory"
	return
# 44 "data/maps/SlateportCity/scripts.pory"

# 45 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MoveScottLeft::
# 46 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
# 47 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 48 "data/maps/SlateportCity/scripts.pory"
	return
# 49 "data/maps/SlateportCity/scripts.pory"

# 50 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnFrame:
# 51 "data/maps/SlateportCity/scripts.pory"
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
# 52 "data/maps/SlateportCity/scripts.pory"
	.2byte 0
# 53 "data/maps/SlateportCity/scripts.pory"

# 54 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottScene::
# 55 "data/maps/SlateportCity/scripts.pory"
	lockall
# 56 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SLATEPORT_SCOTT
# 57 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
# 58 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
# 59 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 60 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
# 61 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 62 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 63 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 64 "data/maps/SlateportCity/scripts.pory"
	delay 60
# 65 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
# 66 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 67 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 68 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
# 69 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 70 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 71 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 72 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
# 73 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 74 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 75 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 76 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
# 77 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
# 78 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 79 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
# 80 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 81 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_SCOTT
# 82 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
# 83 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
# 84 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 85 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
# 86 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 87 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 88 "data/maps/SlateportCity/scripts.pory"
	end
# 89 "data/maps/SlateportCity/scripts.pory"

# 90 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceScott:
# 91 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 92 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 93 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 94 "data/maps/SlateportCity/scripts.pory"
	step_end
# 95 "data/maps/SlateportCity/scripts.pory"

# 96 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottApproachPlayer:
# 97 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 98 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 99 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 100 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 101 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 102 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 103 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 104 "data/maps/SlateportCity/scripts.pory"
	step_end
# 105 "data/maps/SlateportCity/scripts.pory"

# 106 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExit:
# 107 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 108 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 109 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 110 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 111 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 112 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 113 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 114 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 115 "data/maps/SlateportCity/scripts.pory"
	step_end
# 116 "data/maps/SlateportCity/scripts.pory"

# 117 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyGuru::
# 118 "data/maps/SlateportCity/scripts.pory"
	lock
# 119 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 120 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
# 121 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 122 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_EnergyGuru
# 123 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 124 "data/maps/SlateportCity/scripts.pory"
	release
# 125 "data/maps/SlateportCity/scripts.pory"
	end
# 126 "data/maps/SlateportCity/scripts.pory"

# 127 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 128 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_EnergyGuru:
# 129 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PROTEIN
# 130 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_IRON
# 131 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CARBOS
# 132 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ZINC
# 133 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CALCIUM
# 134 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_HP_UP
# 135 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 136 "data/maps/SlateportCity/scripts.pory"

# 137 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EffortRibbonWoman::
# 138 "data/maps/SlateportCity/scripts.pory"
	lock
# 139 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 140 "data/maps/SlateportCity/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 141 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
# 142 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
# 143 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
# 144 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
# 145 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
# 146 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
# 147 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 148 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ReceivedEffortRibbon
# 149 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 150 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
# 151 "data/maps/SlateportCity/scripts.pory"
	special GiveLeadMonEffortRibbon
# 152 "data/maps/SlateportCity/scripts.pory"
	release
# 153 "data/maps/SlateportCity/scripts.pory"
	end
# 154 "data/maps/SlateportCity/scripts.pory"

# 155 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonEVsNotMaxed::
# 156 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
# 157 "data/maps/SlateportCity/scripts.pory"
	release
# 158 "data/maps/SlateportCity/scripts.pory"
	end
# 159 "data/maps/SlateportCity/scripts.pory"

# 160 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonHasEffortRibbon::
# 161 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
# 162 "data/maps/SlateportCity/scripts.pory"
	release
# 163 "data/maps/SlateportCity/scripts.pory"
	end
# 164 "data/maps/SlateportCity/scripts.pory"

# 165 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Cook::
# 166 "data/maps/SlateportCity/scripts.pory"
	lock
# 167 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 168 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
# 169 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
# 170 "data/maps/SlateportCity/scripts.pory"
	release
# 171 "data/maps/SlateportCity/scripts.pory"
	end
# 172 "data/maps/SlateportCity/scripts.pory"

# 173 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CookSternInterview::
# 174 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
# 175 "data/maps/SlateportCity/scripts.pory"
	release
# 176 "data/maps/SlateportCity/scripts.pory"
	end
# 177 "data/maps/SlateportCity/scripts.pory"

# 178 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWoman::
# 179 "data/maps/SlateportCity/scripts.pory"
	lock
# 180 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 181 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
# 182 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
# 183 "data/maps/SlateportCity/scripts.pory"
	release
# 184 "data/maps/SlateportCity/scripts.pory"
	end
# 185 "data/maps/SlateportCity/scripts.pory"

# 186 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWomanSternInterview::
# 187 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
# 188 "data/maps/SlateportCity/scripts.pory"
	release
# 189 "data/maps/SlateportCity/scripts.pory"
	end
# 190 "data/maps/SlateportCity/scripts.pory"

# 191 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Girl::
# 192 "data/maps/SlateportCity/scripts.pory"
	lock
# 193 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 194 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
# 195 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
# 196 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
# 197 "data/maps/SlateportCity/scripts.pory"
	release
# 198 "data/maps/SlateportCity/scripts.pory"
	end
# 199 "data/maps/SlateportCity/scripts.pory"

# 200 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSternInterview::
# 201 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
# 202 "data/maps/SlateportCity/scripts.pory"
	release
# 203 "data/maps/SlateportCity/scripts.pory"
	end
# 204 "data/maps/SlateportCity/scripts.pory"

# 205 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSecretBase::
# 206 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
# 207 "data/maps/SlateportCity/scripts.pory"
	release
# 208 "data/maps/SlateportCity/scripts.pory"
	end
# 209 "data/maps/SlateportCity/scripts.pory"

# 210 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoy::
# 211 "data/maps/SlateportCity/scripts.pory"
	lock
# 212 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 213 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
# 214 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
# 215 "data/maps/SlateportCity/scripts.pory"
	release
# 216 "data/maps/SlateportCity/scripts.pory"
	end
# 217 "data/maps/SlateportCity/scripts.pory"

# 218 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoySternInterview::
# 219 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
# 220 "data/maps/SlateportCity/scripts.pory"
	release
# 221 "data/maps/SlateportCity/scripts.pory"
	end
# 222 "data/maps/SlateportCity/scripts.pory"

# 223 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatMan::
# 224 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
# 225 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
# 226 "data/maps/SlateportCity/scripts.pory"
	end
# 227 "data/maps/SlateportCity/scripts.pory"

# 228 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatManSternInterview::
# 229 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
# 230 "data/maps/SlateportCity/scripts.pory"
	end
# 231 "data/maps/SlateportCity/scripts.pory"

# 232 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1::
# 233 "data/maps/SlateportCity/scripts.pory"
	lock
# 234 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 235 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
# 236 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
# 237 "data/maps/SlateportCity/scripts.pory"
	release
# 238 "data/maps/SlateportCity/scripts.pory"
	end
# 239 "data/maps/SlateportCity/scripts.pory"

# 240 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1SternInterview::
# 241 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
# 242 "data/maps/SlateportCity/scripts.pory"
	release
# 243 "data/maps/SlateportCity/scripts.pory"
	end
# 244 "data/maps/SlateportCity/scripts.pory"

# 245 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1::
# 246 "data/maps/SlateportCity/scripts.pory"
	lock
# 247 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 248 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
# 249 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
# 250 "data/maps/SlateportCity/scripts.pory"
	release
# 251 "data/maps/SlateportCity/scripts.pory"
	end
# 252 "data/maps/SlateportCity/scripts.pory"

# 253 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1AquaGone::
# 254 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
# 255 "data/maps/SlateportCity/scripts.pory"
	release
# 256 "data/maps/SlateportCity/scripts.pory"
	end
# 257 "data/maps/SlateportCity/scripts.pory"

# 258 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BattleTentSign::
# 259 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
# 260 "data/maps/SlateportCity/scripts.pory"
	end
# 261 "data/maps/SlateportCity/scripts.pory"

# 262 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardSign::
# 263 "data/maps/SlateportCity/scripts.pory"
	lockall
# 264 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
# 265 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
# 266 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
# 267 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 268 "data/maps/SlateportCity/scripts.pory"
	end
# 269 "data/maps/SlateportCity/scripts.pory"

# 270 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardNearsCompletion::
# 271 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
# 272 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 273 "data/maps/SlateportCity/scripts.pory"
	end
# 274 "data/maps/SlateportCity/scripts.pory"

# 275 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardFerryComplete::
# 276 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
# 277 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 278 "data/maps/SlateportCity/scripts.pory"
	end
# 279 "data/maps/SlateportCity/scripts.pory"

# 280 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokemonFanClubSign::
# 281 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 282 "data/maps/SlateportCity/scripts.pory"
	end
# 283 "data/maps/SlateportCity/scripts.pory"

# 284 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OceanicMuseumSign::
# 285 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
# 286 "data/maps/SlateportCity/scripts.pory"
	end
# 287 "data/maps/SlateportCity/scripts.pory"

# 288 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CitySign::
# 289 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
# 290 "data/maps/SlateportCity/scripts.pory"
	end
# 291 "data/maps/SlateportCity/scripts.pory"

# 292 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MarketSign::
# 293 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
# 294 "data/maps/SlateportCity/scripts.pory"
	end
# 295 "data/maps/SlateportCity/scripts.pory"

# 296 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSign::
# 297 "data/maps/SlateportCity/scripts.pory"
	lockall
# 298 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
# 299 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
# 300 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 301 "data/maps/SlateportCity/scripts.pory"
	end
# 302 "data/maps/SlateportCity/scripts.pory"

# 303 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSignFerryComplete::
# 304 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
# 305 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 306 "data/maps/SlateportCity/scripts.pory"
	end
# 307 "data/maps/SlateportCity/scripts.pory"

# 308 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NameRatersHouseSign::
# 309 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
# 310 "data/maps/SlateportCity/scripts.pory"
	end
# 311 "data/maps/SlateportCity/scripts.pory"

# 312 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Maniac::
# 313 "data/maps/SlateportCity/scripts.pory"
	lock
# 314 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 315 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
# 316 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 317 "data/maps/SlateportCity/scripts.pory"
	release
# 318 "data/maps/SlateportCity/scripts.pory"
	end
# 319 "data/maps/SlateportCity/scripts.pory"

# 320 "data/maps/SlateportCity/scripts.pory"
@ Unclear if the text here was meant to be different, but its not
# 321 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ManiacSternInterview::
# 322 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 323 "data/maps/SlateportCity/scripts.pory"
	release
# 324 "data/maps/SlateportCity/scripts.pory"
	end
# 325 "data/maps/SlateportCity/scripts.pory"

# 326 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman2::
# 327 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
# 328 "data/maps/SlateportCity/scripts.pory"
	end
# 329 "data/maps/SlateportCity/scripts.pory"

# 330 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor1::
# 331 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
# 332 "data/maps/SlateportCity/scripts.pory"
	end
# 333 "data/maps/SlateportCity/scripts.pory"

# 334 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor2::
# 335 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
# 336 "data/maps/SlateportCity/scripts.pory"
	end
# 337 "data/maps/SlateportCity/scripts.pory"

# 338 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokefanF::
# 339 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
# 340 "data/maps/SlateportCity/scripts.pory"
	end
# 341 "data/maps/SlateportCity/scripts.pory"

# 342 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man2::
# 343 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
# 344 "data/maps/SlateportCity/scripts.pory"
	end
# 345 "data/maps/SlateportCity/scripts.pory"

# 346 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt1::
# 347 "data/maps/SlateportCity/scripts.pory"
	lock
# 348 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 349 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
# 350 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 351 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
# 352 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 353 "data/maps/SlateportCity/scripts.pory"
	release
# 354 "data/maps/SlateportCity/scripts.pory"
	end
# 355 "data/maps/SlateportCity/scripts.pory"

# 356 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt2::
# 357 "data/maps/SlateportCity/scripts.pory"
	lock
# 358 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 359 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
# 360 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 361 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
# 362 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 363 "data/maps/SlateportCity/scripts.pory"
	release
# 364 "data/maps/SlateportCity/scripts.pory"
	end
# 365 "data/maps/SlateportCity/scripts.pory"

# 366 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt3::
# 367 "data/maps/SlateportCity/scripts.pory"
	lock
# 368 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 369 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
# 370 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 371 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
# 372 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 373 "data/maps/SlateportCity/scripts.pory"
	release
# 374 "data/maps/SlateportCity/scripts.pory"
	end
# 375 "data/maps/SlateportCity/scripts.pory"

# 376 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt4::
# 377 "data/maps/SlateportCity/scripts.pory"
	lock
# 378 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 379 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
# 380 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 381 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
# 382 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 383 "data/maps/SlateportCity/scripts.pory"
	release
# 384 "data/maps/SlateportCity/scripts.pory"
	end
# 385 "data/maps/SlateportCity/scripts.pory"

# 386 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt5::
# 387 "data/maps/SlateportCity/scripts.pory"
	lock
# 388 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 389 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
# 390 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 391 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
# 392 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 393 "data/maps/SlateportCity/scripts.pory"
	release
# 394 "data/maps/SlateportCity/scripts.pory"
	end
# 395 "data/maps/SlateportCity/scripts.pory"

# 396 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt6::
# 397 "data/maps/SlateportCity/scripts.pory"
	lock
# 398 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 399 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
# 400 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 401 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
# 402 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 403 "data/maps/SlateportCity/scripts.pory"
	release
# 404 "data/maps/SlateportCity/scripts.pory"
	end
# 405 "data/maps/SlateportCity/scripts.pory"

# 406 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt7::
# 407 "data/maps/SlateportCity/scripts.pory"
	lock
# 408 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 409 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
# 410 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 411 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
# 412 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 413 "data/maps/SlateportCity/scripts.pory"
	release
# 414 "data/maps/SlateportCity/scripts.pory"
	end
# 415 "data/maps/SlateportCity/scripts.pory"

# 416 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt8::
# 417 "data/maps/SlateportCity/scripts.pory"
	lock
# 418 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 419 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
# 420 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 421 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
# 422 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 423 "data/maps/SlateportCity/scripts.pory"
	release
# 424 "data/maps/SlateportCity/scripts.pory"
	end
# 425 "data/maps/SlateportCity/scripts.pory"

# 426 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt9::
# 427 "data/maps/SlateportCity/scripts.pory"
	lock
# 428 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 429 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 430 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
# 431 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 432 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
# 433 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 434 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
# 435 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 436 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 437 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 438 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 439 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 440 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
# 441 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 442 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
# 443 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 444 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 445 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 446 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 447 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 448 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
# 449 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 450 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
# 451 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 452 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 453 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 454 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 455 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 456 "data/maps/SlateportCity/scripts.pory"
	release
# 457 "data/maps/SlateportCity/scripts.pory"
	end
# 458 "data/maps/SlateportCity/scripts.pory"

# 459 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_DelayAquaGrunt:
# 460 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 461 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 462 "data/maps/SlateportCity/scripts.pory"
	step_end
# 463 "data/maps/SlateportCity/scripts.pory"

# 464 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt10::
# 465 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
# 466 "data/maps/SlateportCity/scripts.pory"
	end
# 467 "data/maps/SlateportCity/scripts.pory"

# 468 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt11::
# 469 "data/maps/SlateportCity/scripts.pory"
	lock
# 470 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 471 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
# 472 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 473 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
# 474 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 475 "data/maps/SlateportCity/scripts.pory"
	release
# 476 "data/maps/SlateportCity/scripts.pory"
	end
# 477 "data/maps/SlateportCity/scripts.pory"

# 478 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DollClerk::
# 479 "data/maps/SlateportCity/scripts.pory"
	lock
# 480 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 481 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 482 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 483 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
# 484 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 485 "data/maps/SlateportCity/scripts.pory"
	release
# 486 "data/maps/SlateportCity/scripts.pory"
	end
# 487 "data/maps/SlateportCity/scripts.pory"

# 488 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 489 "data/maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor_Dolls:
# 490 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_AZURILL_DOLL
# 491 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_MARILL_DOLL
# 492 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_SKITTY_DOLL
# 493 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 494 "data/maps/SlateportCity/scripts.pory"

# 495 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ComeBackWithSecretPower::
# 496 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
# 497 "data/maps/SlateportCity/scripts.pory"
	release
# 498 "data/maps/SlateportCity/scripts.pory"
	end
# 499 "data/maps/SlateportCity/scripts.pory"

# 500 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DecorClerk::
# 501 "data/maps/SlateportCity/scripts.pory"
	lock
# 502 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 503 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
# 504 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 505 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 506 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor
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
SlateportCity_PokemartDecor:
# 513 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BRICK
# 514 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BRICK
# 515 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BRICK
# 516 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BALLOON
# 517 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BALLOON
# 518 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BALLOON
# 519 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_LOW_NOTE_MAT
# 520 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_D_NOTE_MAT
# 521 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_E_NOTE_MAT
# 522 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_F_NOTE_MAT
# 523 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_G_NOTE_MAT
# 524 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_A_NOTE_MAT
# 525 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_B_NOTE_MAT
# 526 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_HIGH_NOTE_MAT
# 527 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 528 "data/maps/SlateportCity/scripts.pory"

# 529 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PowerTMClerk::
# 530 "data/maps/SlateportCity/scripts.pory"
	lock
# 531 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 532 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 533 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 534 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_PowerTMs
# 535 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 536 "data/maps/SlateportCity/scripts.pory"
	release
# 537 "data/maps/SlateportCity/scripts.pory"
	end
# 538 "data/maps/SlateportCity/scripts.pory"

# 539 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 540 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_PowerTMs:
# 541 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_POUNCE
# 542 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_AIR_CUTTER
# 543 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_DRAINING_KISS
# 544 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_BULLDOZE
# 545 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 546 "data/maps/SlateportCity/scripts.pory"

# 547 "data/maps/SlateportCity/scripts.pory"
@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
# 548 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CaptStern::
# 549 "data/maps/SlateportCity/scripts.pory"
	lockall
# 550 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
# 551 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
# 552 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 553 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
# 554 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 555 "data/maps/SlateportCity/scripts.pory"
	delay 10
# 556 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
# 557 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 558 "data/maps/SlateportCity/scripts.pory"
	delay 25
# 559 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
# 560 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
# 561 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
# 562 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
# 563 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 564 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_GABBY
# 565 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_TY
# 566 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
# 567 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 568 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 569 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
# 570 "data/maps/SlateportCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 571 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
# 572 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
# 573 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
# 574 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
# 575 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
# 576 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
# 577 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 578 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
# 579 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 580 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
# 581 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 582 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
# 583 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 584 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
# 585 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 586 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 587 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 588 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
# 589 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 590 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 591 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
# 592 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
# 593 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 594 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_CAPT_STERN
# 595 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
# 596 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
# 597 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
# 598 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
# 599 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 2
# 600 "data/maps/SlateportCity/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
# 601 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 602 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 603 "data/maps/SlateportCity/scripts.pory"
	end
# 604 "data/maps/SlateportCity/scripts.pory"

# 605 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_OldWomanConcern:
# 606 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 607 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 608 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 609 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 610 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 611 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 612 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 613 "data/maps/SlateportCity/scripts.pory"
	step_end
# 614 "data/maps/SlateportCity/scripts.pory"

# 615 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ManConcern:
# 616 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 617 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 618 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 619 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 620 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 621 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 622 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 623 "data/maps/SlateportCity/scripts.pory"
	step_end
# 624 "data/maps/SlateportCity/scripts.pory"

# 625 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_GabbyExit:
# 626 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 627 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 628 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 629 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 630 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 631 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 632 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 633 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 634 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 635 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 636 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 637 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 638 "data/maps/SlateportCity/scripts.pory"
	step_end
# 639 "data/maps/SlateportCity/scripts.pory"

# 640 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_TyExit:
# 641 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 642 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 643 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 644 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 645 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 646 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 647 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 648 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 649 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 650 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 651 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 652 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 653 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 654 "data/maps/SlateportCity/scripts.pory"
	step_end
# 655 "data/maps/SlateportCity/scripts.pory"

# 656 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_Unused:
# 657 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 658 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 659 "data/maps/SlateportCity/scripts.pory"
	step_end
# 660 "data/maps/SlateportCity/scripts.pory"

# 661 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternEnterHarbor:
# 662 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 663 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 664 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 665 "data/maps/SlateportCity/scripts.pory"
	set_invisible
# 666 "data/maps/SlateportCity/scripts.pory"
	step_end
# 667 "data/maps/SlateportCity/scripts.pory"

# 668 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternWatchGabbyAndTyExit:
# 669 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 670 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 671 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 672 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 673 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 674 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 675 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 676 "data/maps/SlateportCity/scripts.pory"
	step_end
# 677 "data/maps/SlateportCity/scripts.pory"

# 678 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerEnterHarbor:
# 679 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 680 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 681 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 682 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 683 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 684 "data/maps/SlateportCity/scripts.pory"
	step_end
# 685 "data/maps/SlateportCity/scripts.pory"

# 686 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceStern:
# 687 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 688 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 689 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 690 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 691 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 692 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 693 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 694 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 695 "data/maps/SlateportCity/scripts.pory"
	step_end
# 696 "data/maps/SlateportCity/scripts.pory"

# 697 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Ty::
# 698 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
# 699 "data/maps/SlateportCity/scripts.pory"
	end
# 700 "data/maps/SlateportCity/scripts.pory"

# 701 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Gabby::
# 702 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
# 703 "data/maps/SlateportCity/scripts.pory"
	end
# 704 "data/maps/SlateportCity/scripts.pory"

# 705 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man3::
# 706 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
# 707 "data/maps/SlateportCity/scripts.pory"
	end
# 708 "data/maps/SlateportCity/scripts.pory"

# 709 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryPowderClerk::
# 710 "data/maps/SlateportCity/scripts.pory"
	lock
# 711 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 712 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
# 713 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
# 714 "data/maps/SlateportCity/scripts.pory"
	giveitem ITEM_POWDER_JAR
# 715 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_POWDER_JAR
# 716 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 717 "data/maps/SlateportCity/scripts.pory"
	release
# 718 "data/maps/SlateportCity/scripts.pory"
	end
# 719 "data/maps/SlateportCity/scripts.pory"

# 720 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ReceivedPowderJar::
# 721 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, 1
# 722 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 723 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
# 724 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
# 725 "data/maps/SlateportCity/scripts.pory"
	special DisplayBerryPowderVendorMenu
# 726 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 727 "data/maps/SlateportCity/scripts.pory"
	end
# 728 "data/maps/SlateportCity/scripts.pory"

# 729 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ExplainBerryPowder::
# 730 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 731 "data/maps/SlateportCity/scripts.pory"
	release
# 732 "data/maps/SlateportCity/scripts.pory"
	end
# 733 "data/maps/SlateportCity/scripts.pory"

# 734 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ChooseBerryPowderItem::
# 735 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ExchangeWhatWithIt
# 736 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 737 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
# 738 "data/maps/SlateportCity/scripts.pory"
	special ShowScrollableMultichoice
# 739 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 740 "data/maps/SlateportCity/scripts.pory"
	switch VAR_RESULT
# 741 "data/maps/SlateportCity/scripts.pory"
	case 0, SlateportCity_EventScript_EnergyPowder
# 742 "data/maps/SlateportCity/scripts.pory"
	case 1, SlateportCity_EventScript_EnergyRoot
# 743 "data/maps/SlateportCity/scripts.pory"
	case 2, SlateportCity_EventScript_HealPowder
# 744 "data/maps/SlateportCity/scripts.pory"
	case 3, SlateportCity_EventScript_RevivalHerb
# 745 "data/maps/SlateportCity/scripts.pory"
	case 4, SlateportCity_EventScript_Protein
# 746 "data/maps/SlateportCity/scripts.pory"
	case 5, SlateportCity_EventScript_Iron
# 747 "data/maps/SlateportCity/scripts.pory"
	case 6, SlateportCity_EventScript_Carbos
# 748 "data/maps/SlateportCity/scripts.pory"
	case 7, SlateportCity_EventScript_Calcium
# 749 "data/maps/SlateportCity/scripts.pory"
	case 8, SlateportCity_EventScript_Zinc
# 750 "data/maps/SlateportCity/scripts.pory"
	case 9, SlateportCity_EventScript_HPUp
# 751 "data/maps/SlateportCity/scripts.pory"
	case 10, SlateportCity_EventScript_PPUp
# 752 "data/maps/SlateportCity/scripts.pory"
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
# 753 "data/maps/SlateportCity/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
# 754 "data/maps/SlateportCity/scripts.pory"
	end
# 755 "data/maps/SlateportCity/scripts.pory"

# 756 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyPowder::
# 757 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
# 758 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
# 759 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 760 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 761 "data/maps/SlateportCity/scripts.pory"
	end
# 762 "data/maps/SlateportCity/scripts.pory"

# 763 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyRoot::
# 764 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
# 765 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
# 766 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 80
# 767 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 768 "data/maps/SlateportCity/scripts.pory"
	end
# 769 "data/maps/SlateportCity/scripts.pory"

# 770 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HealPowder::
# 771 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
# 772 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HEAL_POWDER
# 773 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 774 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 775 "data/maps/SlateportCity/scripts.pory"
	end
# 776 "data/maps/SlateportCity/scripts.pory"

# 777 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RevivalHerb::
# 778 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
# 779 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
# 780 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 300
# 781 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 782 "data/maps/SlateportCity/scripts.pory"
	end
# 783 "data/maps/SlateportCity/scripts.pory"

# 784 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Protein::
# 785 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PROTEIN
# 786 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PROTEIN
# 787 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 788 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 789 "data/maps/SlateportCity/scripts.pory"
	end
# 790 "data/maps/SlateportCity/scripts.pory"

# 791 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Iron::
# 792 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_IRON
# 793 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_IRON
# 794 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 795 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 796 "data/maps/SlateportCity/scripts.pory"
	end
# 797 "data/maps/SlateportCity/scripts.pory"

# 798 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Carbos::
# 799 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CARBOS
# 800 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CARBOS
# 801 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 802 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 803 "data/maps/SlateportCity/scripts.pory"
	end
# 804 "data/maps/SlateportCity/scripts.pory"

# 805 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Calcium::
# 806 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CALCIUM
# 807 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CALCIUM
# 808 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 809 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 810 "data/maps/SlateportCity/scripts.pory"
	end
# 811 "data/maps/SlateportCity/scripts.pory"

# 812 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Zinc::
# 813 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ZINC
# 814 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ZINC
# 815 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 816 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 817 "data/maps/SlateportCity/scripts.pory"
	end
# 818 "data/maps/SlateportCity/scripts.pory"

# 819 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HPUp::
# 820 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HP_UP
# 821 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HP_UP
# 822 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 823 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 824 "data/maps/SlateportCity/scripts.pory"
	end
# 825 "data/maps/SlateportCity/scripts.pory"

# 826 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PPUp::
# 827 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PP_UP
# 828 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PP_UP
# 829 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 3000
# 830 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 831 "data/maps/SlateportCity/scripts.pory"
	end
# 832 "data/maps/SlateportCity/scripts.pory"

# 833 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CancelPowderItemSelect::
# 834 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
# 835 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 836 "data/maps/SlateportCity/scripts.pory"
	release
# 837 "data/maps/SlateportCity/scripts.pory"
	end
# 838 "data/maps/SlateportCity/scripts.pory"

# 839 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_TryBuyBerryPowderItem::
# 840 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
# 841 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
# 842 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 843 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 844 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
# 845 "data/maps/SlateportCity/scripts.pory"
	giveitem VAR_0x8008
# 846 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
# 847 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 848 "data/maps/SlateportCity/scripts.pory"
	special TakeBerryPowder
# 849 "data/maps/SlateportCity/scripts.pory"
	special PrintPlayerBerryPowderAmount
# 850 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
# 851 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
# 852 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
# 853 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 854 "data/maps/SlateportCity/scripts.pory"
	release
# 855 "data/maps/SlateportCity/scripts.pory"
	end
# 856 "data/maps/SlateportCity/scripts.pory"

# 857 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NoRoomForBerryPowderItem::
# 858 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 859 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 860 "data/maps/SlateportCity/scripts.pory"
	release
# 861 "data/maps/SlateportCity/scripts.pory"
	end
# 862 "data/maps/SlateportCity/scripts.pory"

# 863 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NotEnoughBerryPowder::
# 864 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
# 865 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 866 "data/maps/SlateportCity/scripts.pory"
	end
# 867 "data/maps/SlateportCity/scripts.pory"

# 868 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottBattleTentScene::
# 869 "data/maps/SlateportCity/scripts.pory"
	lockall
# 870 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 871 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 872 "data/maps/SlateportCity/scripts.pory"
	opendoor 10, 12
# 873 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 874 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SLATEPORT_SCOTT
# 875 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
# 876 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
# 877 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 878 "data/maps/SlateportCity/scripts.pory"
	closedoor 10, 12
# 879 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 880 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
# 881 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 882 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
# 883 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
# 884 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 885 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_SCOTT
# 886 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 887 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 888 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 889 "data/maps/SlateportCity/scripts.pory"
	end
# 890 "data/maps/SlateportCity/scripts.pory"

# 891 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PushPlayerDown:
# 892 "data/maps/SlateportCity/scripts.pory"
	lock_facing_direction
# 893 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 894 "data/maps/SlateportCity/scripts.pory"
	unlock_facing_direction
# 895 "data/maps/SlateportCity/scripts.pory"
	step_end
# 896 "data/maps/SlateportCity/scripts.pory"

# 897 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerWatchScottExit:
# 898 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 899 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 900 "data/maps/SlateportCity/scripts.pory"
	step_end
# 901 "data/maps/SlateportCity/scripts.pory"

# 902 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitBattleTent:
# 903 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 904 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 905 "data/maps/SlateportCity/scripts.pory"
	step_end
# 906 "data/maps/SlateportCity/scripts.pory"

# 907 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitAfterBattleTent:
# 908 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 909 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 910 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 911 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 912 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 913 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 914 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 915 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 916 "data/maps/SlateportCity/scripts.pory"
	step_end
# 917 "data/maps/SlateportCity/scripts.pory"

# 918 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryCrushRankingsSign::
# 919 "data/maps/SlateportCity/scripts.pory"
	lockall
# 920 "data/maps/SlateportCity/scripts.pory"
	special ShowBerryCrushRankings
# 921 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 922 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 923 "data/maps/SlateportCity/scripts.pory"
	end
# 924 "data/maps/SlateportCity/scripts.pory"

# 925 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EnergyGuruSellWhatYouNeed:
# 926 "data/maps/SlateportCity/scripts.pory"
	.string "I'm the ENERGY GURU! I'll go for it and\n"
# 927 "data/maps/SlateportCity/scripts.pory"
	.string "sell you what you need!$"
# 928 "data/maps/SlateportCity/scripts.pory"

# 929 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhYourPokemon:
# 930 "data/maps/SlateportCity/scripts.pory"
	.string "Oh?\n"
# 931 "data/maps/SlateportCity/scripts.pory"
	.string "Your {STR_VAR_1}…$"
# 932 "data/maps/SlateportCity/scripts.pory"

# 933 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseGiveItThisEffortRibbon:
# 934 "data/maps/SlateportCity/scripts.pory"
	.string "Went for it stupendously!\p"
# 935 "data/maps/SlateportCity/scripts.pory"
	.string "As its reward, please give it this\n"
# 936 "data/maps/SlateportCity/scripts.pory"
	.string "EFFORT RIBBON.$"
# 937 "data/maps/SlateportCity/scripts.pory"

# 938 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ReceivedEffortRibbon:
# 939 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} received the EFFORT RIBBON.$"
# 940 "data/maps/SlateportCity/scripts.pory"

# 941 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PutEffortRibbonOnMon:
# 942 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} put the EFFORT RIBBON\n"
# 943 "data/maps/SlateportCity/scripts.pory"
	.string "on {STR_VAR_1}.$"
# 944 "data/maps/SlateportCity/scripts.pory"

# 945 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoForItLittleHarder:
# 946 "data/maps/SlateportCity/scripts.pory"
	.string "You have to go for it a little harder.\p"
# 947 "data/maps/SlateportCity/scripts.pory"
	.string "If you do, I'll give your POKéMON\n"
# 948 "data/maps/SlateportCity/scripts.pory"
	.string "something nice.$"
# 949 "data/maps/SlateportCity/scripts.pory"

# 950 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EffortRibbonLooksGoodOnIt:
# 951 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
# 952 "data/maps/SlateportCity/scripts.pory"
	.string "RIBBON looks good on it!$"
# 953 "data/maps/SlateportCity/scripts.pory"

# 954 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
# 955 "data/maps/SlateportCity/scripts.pory"
	.string "The light of the lighthouse reaches\n"
# 956 "data/maps/SlateportCity/scripts.pory"
	.string "dozens of miles away.\p"
# 957 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder if it doesn't startle POKéMON\n"
# 958 "data/maps/SlateportCity/scripts.pory"
	.string "in the sea.$"
# 959 "data/maps/SlateportCity/scripts.pory"

# 960 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaweedFullOfLife:
# 961 "data/maps/SlateportCity/scripts.pory"
	.string "Ooh, look at this!\p"
# 962 "data/maps/SlateportCity/scripts.pory"
	.string "The seaweed you can get around these\n"
# 963 "data/maps/SlateportCity/scripts.pory"
	.string "parts is fresh and full of life.\p"
# 964 "data/maps/SlateportCity/scripts.pory"
	.string "Why, it looks like it can even rear up\n"
# 965 "data/maps/SlateportCity/scripts.pory"
	.string "and attack!$"
# 966 "data/maps/SlateportCity/scripts.pory"

# 967 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HowTownIsBornAndGrows:
# 968 "data/maps/SlateportCity/scripts.pory"
	.string "Where the water is clean, the fruits\n"
# 969 "data/maps/SlateportCity/scripts.pory"
	.string "of bountiful harvest gather.\p"
# 970 "data/maps/SlateportCity/scripts.pory"
	.string "And where people gather, a market\n"
# 971 "data/maps/SlateportCity/scripts.pory"
	.string "soon starts.\p"
# 972 "data/maps/SlateportCity/scripts.pory"
	.string "That is how a town is born and grows.$"
# 973 "data/maps/SlateportCity/scripts.pory"

# 974 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SlateportWonderfulPlace:
# 975 "data/maps/SlateportCity/scripts.pory"
	.string "Shopping where you can breathe the\n"
# 976 "data/maps/SlateportCity/scripts.pory"
	.string "scent of the ocean…\p"
# 977 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT is such a wonderful place!$"
# 978 "data/maps/SlateportCity/scripts.pory"

# 979 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
# 980 "data/maps/SlateportCity/scripts.pory"
	.string "If you put DOLLS or CUSHIONS on\n"
# 981 "data/maps/SlateportCity/scripts.pory"
	.string "the floor, they'll get dirty.\p"
# 982 "data/maps/SlateportCity/scripts.pory"
	.string "I'm going to buy some BRICKS so my\n"
# 983 "data/maps/SlateportCity/scripts.pory"
	.string "DOLLS and CUSHIONS won't get dirty\l"
# 984 "data/maps/SlateportCity/scripts.pory"
	.string "when I leave them out.$"
# 985 "data/maps/SlateportCity/scripts.pory"

# 986 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoingToCompeteInBattleTent:
# 987 "data/maps/SlateportCity/scripts.pory"
	.string "Wroooar! I'm going to compete in\n"
# 988 "data/maps/SlateportCity/scripts.pory"
	.string "the BATTLE TENT, too!\p"
# 989 "data/maps/SlateportCity/scripts.pory"
	.string "But before that, I need to catch\n"
# 990 "data/maps/SlateportCity/scripts.pory"
	.string "some POKéMON!$"
# 991 "data/maps/SlateportCity/scripts.pory"

# 992 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BushedHikingFromMauville:
# 993 "data/maps/SlateportCity/scripts.pory"
	.string "Whew… I'm just bushed…\p"
# 994 "data/maps/SlateportCity/scripts.pory"
	.string "I hiked over from MAUVILLE CITY.\n"
# 995 "data/maps/SlateportCity/scripts.pory"
	.string "But, boy, this city's huge.\p"
# 996 "data/maps/SlateportCity/scripts.pory"
	.string "If I'd known this, I would've ridden\n"
# 997 "data/maps/SlateportCity/scripts.pory"
	.string "my BIKE here.$"
# 998 "data/maps/SlateportCity/scripts.pory"

# 999 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EveryoneCallsHimCaptStern:
# 1000 "data/maps/SlateportCity/scripts.pory"
	.string "STERN, the fellow who built the\n"
# 1001 "data/maps/SlateportCity/scripts.pory"
	.string "MUSEUM, also happens to be the leader\l"
# 1002 "data/maps/SlateportCity/scripts.pory"
	.string "of an undersea exploration team.\p"
# 1003 "data/maps/SlateportCity/scripts.pory"
	.string "So, everyone calls him CAPT. STERN.$"
# 1004 "data/maps/SlateportCity/scripts.pory"

# 1005 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsLongLineOverThere:
# 1006 "data/maps/SlateportCity/scripts.pory"
	.string "What is that over there?\n"
# 1007 "data/maps/SlateportCity/scripts.pory"
	.string "That long line…$"
# 1008 "data/maps/SlateportCity/scripts.pory"

# 1009 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_VisitedMuseumOften:
# 1010 "data/maps/SlateportCity/scripts.pory"
	.string "When I was a child, I visited\n"
# 1011 "data/maps/SlateportCity/scripts.pory"
	.string "the MUSEUM often.\p"
# 1012 "data/maps/SlateportCity/scripts.pory"
	.string "I used to dream about the mysteries of\n"
# 1013 "data/maps/SlateportCity/scripts.pory"
	.string "the sea after seeing the exhibits.$"
# 1014 "data/maps/SlateportCity/scripts.pory"

# 1015 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_QuitPushing:
# 1016 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, there! Quit pushing!\n"
# 1017 "data/maps/SlateportCity/scripts.pory"
	.string "This is the line, can't you see?$"
# 1018 "data/maps/SlateportCity/scripts.pory"

# 1019 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaHasPolicy:
# 1020 "data/maps/SlateportCity/scripts.pory"
	.string "TEAM AQUA has a policy of\n"
# 1021 "data/maps/SlateportCity/scripts.pory"
	.string "assembling and dispersing at\l"
# 1022 "data/maps/SlateportCity/scripts.pory"
	.string "the operation site.$"
# 1023 "data/maps/SlateportCity/scripts.pory"

# 1024 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BossIsBrilliant:
# 1025 "data/maps/SlateportCity/scripts.pory"
	.string "Our BOSS is brilliant.\p"
# 1026 "data/maps/SlateportCity/scripts.pory"
	.string "What would he want to do with\n"
# 1027 "data/maps/SlateportCity/scripts.pory"
	.string "a MUSEUM now?$"
# 1028 "data/maps/SlateportCity/scripts.pory"

# 1029 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsNewSchemeIWonder:
# 1030 "data/maps/SlateportCity/scripts.pory"
	.string "What's the new scheme, I wonder?\p"
# 1031 "data/maps/SlateportCity/scripts.pory"
	.string "Our BOSS is scary when he's mad, so\n"
# 1032 "data/maps/SlateportCity/scripts.pory"
	.string "I'd better not screw things up…$"
# 1033 "data/maps/SlateportCity/scripts.pory"

# 1034 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldTakeItAll:
# 1035 "data/maps/SlateportCity/scripts.pory"
	.string "If there's something we need in\n"
# 1036 "data/maps/SlateportCity/scripts.pory"
	.string "the MUSEUM, we should take it all!$"
# 1037 "data/maps/SlateportCity/scripts.pory"

# 1038 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontButtIn:
# 1039 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, you there!\n"
# 1040 "data/maps/SlateportCity/scripts.pory"
	.string "Don't butt in!$"
# 1041 "data/maps/SlateportCity/scripts.pory"

# 1042 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RemindsMeOfLongLineForGames:
# 1043 "data/maps/SlateportCity/scripts.pory"
	.string "A long line, huh?\p"
# 1044 "data/maps/SlateportCity/scripts.pory"
	.string "It reminds me of the times I lined up to\n"
# 1045 "data/maps/SlateportCity/scripts.pory"
	.string "buy smash-hit games…$"
# 1046 "data/maps/SlateportCity/scripts.pory"

# 1047 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhyAreWeLiningUp:
# 1048 "data/maps/SlateportCity/scripts.pory"
	.string "Why are we even lining up and paying?\n"
# 1049 "data/maps/SlateportCity/scripts.pory"
	.string "We should just march in!$"
# 1050 "data/maps/SlateportCity/scripts.pory"

# 1051 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatDoYouWant:
# 1052 "data/maps/SlateportCity/scripts.pory"
	.string "What?\n"
# 1053 "data/maps/SlateportCity/scripts.pory"
	.string "What do you want?$"
# 1054 "data/maps/SlateportCity/scripts.pory"

# 1055 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_IllReadSignForYou:
# 1056 "data/maps/SlateportCity/scripts.pory"
	.string "You want to read this sign?\n"
# 1057 "data/maps/SlateportCity/scripts.pory"
	.string "I'll read it for you!$"
# 1058 "data/maps/SlateportCity/scripts.pory"

# 1059 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
# 1060 "data/maps/SlateportCity/scripts.pory"
	.string "Let's see…\p"
# 1061 "data/maps/SlateportCity/scripts.pory"
	.string "Um… I think it says something like\n"
# 1062 "data/maps/SlateportCity/scripts.pory"
	.string "“the life in the sea is endless.”\p"
# 1063 "data/maps/SlateportCity/scripts.pory"
	.string "Yup, I'm pretty sure that's what\n"
# 1064 "data/maps/SlateportCity/scripts.pory"
	.string "it says.$"
# 1065 "data/maps/SlateportCity/scripts.pory"

# 1066 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldveBroughtMyGameBoy:
# 1067 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…\p"
# 1068 "data/maps/SlateportCity/scripts.pory"
	.string "I should've brought my Game Boy\n"
# 1069 "data/maps/SlateportCity/scripts.pory"
	.string "Advance so I wouldn't get bored in line…\p"
# 1070 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…$"
# 1071 "data/maps/SlateportCity/scripts.pory"

# 1072 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HotSpringsAfterOperation:
# 1073 "data/maps/SlateportCity/scripts.pory"
	.string "When this operation's over, I'll take\n"
# 1074 "data/maps/SlateportCity/scripts.pory"
	.string "you to a hot spring spa!\p"
# 1075 "data/maps/SlateportCity/scripts.pory"
	.string "That's what our leader said.\n"
# 1076 "data/maps/SlateportCity/scripts.pory"
	.string "I can't wait!$"
# 1077 "data/maps/SlateportCity/scripts.pory"

# 1078 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaIsSoWet:
# 1079 "data/maps/SlateportCity/scripts.pory"
	.string "The sea is just so vast…\p"
# 1080 "data/maps/SlateportCity/scripts.pory"
	.string "Could the sea have been made by\n"
# 1081 "data/maps/SlateportCity/scripts.pory"
	.string "the tears shed by POKéMON?$"
# 1082 "data/maps/SlateportCity/scripts.pory"

# 1083 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SinkOldBoats:
# 1084 "data/maps/SlateportCity/scripts.pory"
	.string "Do you know what they do with old\n"
# 1085 "data/maps/SlateportCity/scripts.pory"
	.string "ships that become too creaky to sail?\p"
# 1086 "data/maps/SlateportCity/scripts.pory"
	.string "They sink them in the sea so they\n"
# 1087 "data/maps/SlateportCity/scripts.pory"
	.string "become habitats for POKéMON.$"
# 1088 "data/maps/SlateportCity/scripts.pory"

# 1089 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyTooMuch:
# 1090 "data/maps/SlateportCity/scripts.pory"
	.string "Whenever I visit here, I get carried\n"
# 1091 "data/maps/SlateportCity/scripts.pory"
	.string "away and buy too much.$"
# 1092 "data/maps/SlateportCity/scripts.pory"

# 1093 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GetNameRaterToHelpYou:
# 1094 "data/maps/SlateportCity/scripts.pory"
	.string "If you want to change your POKéMON's\n"
# 1095 "data/maps/SlateportCity/scripts.pory"
	.string "nickname, you'll have to get the NAME\l"
# 1096 "data/maps/SlateportCity/scripts.pory"
	.string "RATER to help you.$"
# 1097 "data/maps/SlateportCity/scripts.pory"

# 1098 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CantChangeTradeMonName:
# 1099 "data/maps/SlateportCity/scripts.pory"
	.string "Any POKéMON you get in a trade,\n"
# 1100 "data/maps/SlateportCity/scripts.pory"
	.string "you can't change its nickname.\p"
# 1101 "data/maps/SlateportCity/scripts.pory"
	.string "The original TRAINER's love for that\n"
# 1102 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON is in the nickname.$"
# 1103 "data/maps/SlateportCity/scripts.pory"

# 1104 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentBuiltRecently:
# 1105 "data/maps/SlateportCity/scripts.pory"
	.string "Recently, a BATTLE TENT was built\n"
# 1106 "data/maps/SlateportCity/scripts.pory"
	.string "in SLATEPORT.\p"
# 1107 "data/maps/SlateportCity/scripts.pory"
	.string "GYMS are fun, but the BATTLE TENT's\n"
# 1108 "data/maps/SlateportCity/scripts.pory"
	.string "awesome in its own way.\p"
# 1109 "data/maps/SlateportCity/scripts.pory"
	.string "You should go find tough POKéMON\n"
# 1110 "data/maps/SlateportCity/scripts.pory"
	.string "for the BATTLE TENT!$"
# 1111 "data/maps/SlateportCity/scripts.pory"

# 1112 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptSternBeingInterviewed:
# 1113 "data/maps/SlateportCity/scripts.pory"
	.string "I was hoping that it was a famous star\n"
# 1114 "data/maps/SlateportCity/scripts.pory"
	.string "so I could get an autograph.\p"
# 1115 "data/maps/SlateportCity/scripts.pory"
	.string "But who's that being interviewed?\n"
# 1116 "data/maps/SlateportCity/scripts.pory"
	.string "Isn't that CAPT. STERN?$"
# 1117 "data/maps/SlateportCity/scripts.pory"

# 1118 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_InterviewerSoCool:
# 1119 "data/maps/SlateportCity/scripts.pory"
	.string "That lady interviewer is so cool\n"
# 1120 "data/maps/SlateportCity/scripts.pory"
	.string "and pretty.\p"
# 1121 "data/maps/SlateportCity/scripts.pory"
	.string "When I grow up, I'm going to be\n"
# 1122 "data/maps/SlateportCity/scripts.pory"
	.string "an international journalist!$"
# 1123 "data/maps/SlateportCity/scripts.pory"

# 1124 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternSaysDiscoveredSomething:
# 1125 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN says they discovered\n"
# 1126 "data/maps/SlateportCity/scripts.pory"
	.string "something at the bottom of the sea.\p"
# 1127 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder what it is?\n"
# 1128 "data/maps/SlateportCity/scripts.pory"
	.string "What could it be?$"
# 1129 "data/maps/SlateportCity/scripts.pory"

# 1130 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainComeBackWithBigFish:
# 1131 "data/maps/SlateportCity/scripts.pory"
	.string "What's going on here?\p"
# 1132 "data/maps/SlateportCity/scripts.pory"
	.string "Did the good CAPTAIN come back with\n"
# 1133 "data/maps/SlateportCity/scripts.pory"
	.string "a big fish from the ocean floor?$"
# 1134 "data/maps/SlateportCity/scripts.pory"

# 1135 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AmIOnTV:
# 1136 "data/maps/SlateportCity/scripts.pory"
	.string "Hey! Are you watching?\n"
# 1137 "data/maps/SlateportCity/scripts.pory"
	.string "Am I on TV?$"
# 1138 "data/maps/SlateportCity/scripts.pory"

# 1139 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainsACelebrity:
# 1140 "data/maps/SlateportCity/scripts.pory"
	.string "A TV interview! Here!\n"
# 1141 "data/maps/SlateportCity/scripts.pory"
	.string "The CAPTAIN's a celebrity!$"
# 1142 "data/maps/SlateportCity/scripts.pory"

# 1143 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BigSmileForCamera:
# 1144 "data/maps/SlateportCity/scripts.pory"
	.string "TY: Okay, CAPT. STERN, a big smile\n"
# 1145 "data/maps/SlateportCity/scripts.pory"
	.string "for the camera!$"
# 1146 "data/maps/SlateportCity/scripts.pory"

# 1147 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MostInvaluableExperience:
# 1148 "data/maps/SlateportCity/scripts.pory"
	.string "GABBY: I see, I see. You've had a most\n"
# 1149 "data/maps/SlateportCity/scripts.pory"
	.string "invaluable experience…$"
# 1150 "data/maps/SlateportCity/scripts.pory"

# 1151 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternMoveAheadWithExploration:
# 1152 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
# 1153 "data/maps/SlateportCity/scripts.pory"
	.string "move ahead with our exploration.$"
# 1154 "data/maps/SlateportCity/scripts.pory"

# 1155 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GabbyWonderfulThanksForInterview:
# 1156 "data/maps/SlateportCity/scripts.pory"
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
# 1157 "data/maps/SlateportCity/scripts.pory"
	.string "Thank you for taking the time from\l"
# 1158 "data/maps/SlateportCity/scripts.pory"
	.string "your busy schedule to talk to us.\p"
# 1159 "data/maps/SlateportCity/scripts.pory"
	.string "We hope we can interview you again\n"
# 1160 "data/maps/SlateportCity/scripts.pory"
	.string "with news of more discoveries!$"
# 1161 "data/maps/SlateportCity/scripts.pory"

# 1162 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhewFirstInterview:
# 1163 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Whew…\p"
# 1164 "data/maps/SlateportCity/scripts.pory"
	.string "That was my first time to be filmed for\n"
# 1165 "data/maps/SlateportCity/scripts.pory"
	.string "TV. That was nerve-wracking.$"
# 1166 "data/maps/SlateportCity/scripts.pory"

# 1167 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhPlayerWeMadeDiscovery:
# 1168 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! {PLAYER}{KUN}!\n"
# 1169 "data/maps/SlateportCity/scripts.pory"
	.string "You're looking great!\p"
# 1170 "data/maps/SlateportCity/scripts.pory"
	.string "We made a huge discovery on our last\n"
# 1171 "data/maps/SlateportCity/scripts.pory"
	.string "seafloor exploration.\p"
# 1172 "data/maps/SlateportCity/scripts.pory"
	.string "We found an underwater cavern on\n"
# 1173 "data/maps/SlateportCity/scripts.pory"
	.string "ROUTE 128.\p"
# 1174 "data/maps/SlateportCity/scripts.pory"
	.string "We think it's the habitat of a POKéMON\n"
# 1175 "data/maps/SlateportCity/scripts.pory"
	.string "that's said to have been long extinct.$"
# 1176 "data/maps/SlateportCity/scripts.pory"

# 1177 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
# 1178 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1179 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN, I presume.\p"
# 1180 "data/maps/SlateportCity/scripts.pory"
	.string "We of TEAM AQUA will assume\n"
# 1181 "data/maps/SlateportCity/scripts.pory"
	.string "control of your submarine!\p"
# 1182 "data/maps/SlateportCity/scripts.pory"
	.string "Your objections are meaningless!\n"
# 1183 "data/maps/SlateportCity/scripts.pory"
	.string "We expect your total cooperation!\p"
# 1184 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1185 "data/maps/SlateportCity/scripts.pory"
	.string "Just watch and learn what TEAM\l"
# 1186 "data/maps/SlateportCity/scripts.pory"
	.string "AQUA has planned!$"
# 1187 "data/maps/SlateportCity/scripts.pory"

# 1188 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhatWasAllThat:
# 1189 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: What was that all about?\p"
# 1190 "data/maps/SlateportCity/scripts.pory"
	.string "It sounded like someone using\n"
# 1191 "data/maps/SlateportCity/scripts.pory"
	.string "a megaphone…\p"
# 1192 "data/maps/SlateportCity/scripts.pory"
	.string "Where did it come from?$"
# 1193 "data/maps/SlateportCity/scripts.pory"

# 1194 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FromHarborTryingToTakeSub:
# 1195 "data/maps/SlateportCity/scripts.pory"
	.string "It's from the HARBOR!\p"
# 1196 "data/maps/SlateportCity/scripts.pory"
	.string "The submarine!\n"
# 1197 "data/maps/SlateportCity/scripts.pory"
	.string "They're trying to take it!$"
# 1198 "data/maps/SlateportCity/scripts.pory"

# 1199 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseComeWithMe:
# 1200 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 1201 "data/maps/SlateportCity/scripts.pory"
	.string "Please, come with me!$"
# 1202 "data/maps/SlateportCity/scripts.pory"

# 1203 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentSign:
# 1204 "data/maps/SlateportCity/scripts.pory"
	.string "BATTLE TENT SLATEPORT SITE\n"
# 1205 "data/maps/SlateportCity/scripts.pory"
	.string "“Find it! The ultimate POKéMON!”$"
# 1206 "data/maps/SlateportCity/scripts.pory"

# 1207 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardWantedSign:
# 1208 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1209 "data/maps/SlateportCity/scripts.pory"
	.string "“Wanted: A sailor capable of sailing\n"
# 1210 "data/maps/SlateportCity/scripts.pory"
	.string "in all currents.”$"
# 1211 "data/maps/SlateportCity/scripts.pory"

# 1212 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardNearsCompletion:
# 1213 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1214 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL nears\n"
# 1215 "data/maps/SlateportCity/scripts.pory"
	.string "completion for serving the ports of\l"
# 1216 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT and LILYCOVE.”$"
# 1217 "data/maps/SlateportCity/scripts.pory"

# 1218 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardFerryComplete:
# 1219 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1220 "data/maps/SlateportCity/scripts.pory"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
# 1221 "data/maps/SlateportCity/scripts.pory"
	.string "ferry S.S. TIDAL is handled at the\l"
# 1222 "data/maps/SlateportCity/scripts.pory"
	.string "HARBOR.”$"
# 1223 "data/maps/SlateportCity/scripts.pory"

# 1224 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PokemonFanClubSign:
# 1225 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON FAN CLUB\n"
# 1226 "data/maps/SlateportCity/scripts.pory"
	.string "“Calling all fans of POKéMON!”$"
# 1227 "data/maps/SlateportCity/scripts.pory"

# 1228 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OceanicMuseumSign:
# 1229 "data/maps/SlateportCity/scripts.pory"
	.string "“The endless sea sustains\n"
# 1230 "data/maps/SlateportCity/scripts.pory"
	.string "all life.”\p"
# 1231 "data/maps/SlateportCity/scripts.pory"
	.string "OCEANIC MUSEUM$"
# 1232 "data/maps/SlateportCity/scripts.pory"

# 1233 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CitySign:
# 1234 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT CITY\p"
# 1235 "data/maps/SlateportCity/scripts.pory"
	.string "“The port where people and POKéMON\n"
# 1236 "data/maps/SlateportCity/scripts.pory"
	.string "cross paths.”$"
# 1237 "data/maps/SlateportCity/scripts.pory"

# 1238 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MarketSign:
# 1239 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT MARKET\n"
# 1240 "data/maps/SlateportCity/scripts.pory"
	.string "“Unique items found nowhere else!”$"
# 1241 "data/maps/SlateportCity/scripts.pory"

# 1242 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborFerryUnderConstruction:
# 1243 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1244 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 1245 "data/maps/SlateportCity/scripts.pory"
	.string "construction in the SHIPYARD.\p"
# 1246 "data/maps/SlateportCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 1247 "data/maps/SlateportCity/scripts.pory"
	.string "shortly.”$"
# 1248 "data/maps/SlateportCity/scripts.pory"

# 1249 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborSign:
# 1250 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1251 "data/maps/SlateportCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 1252 "data/maps/SlateportCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 1253 "data/maps/SlateportCity/scripts.pory"

# 1254 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_NameRatersHouseSign:
# 1255 "data/maps/SlateportCity/scripts.pory"
	.string "NAME RATER'S HOUSE\n"
# 1256 "data/maps/SlateportCity/scripts.pory"
	.string "“POKéMON nicknames rated.”$"
# 1257 "data/maps/SlateportCity/scripts.pory"

# 1258 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerries:
# 1259 "data/maps/SlateportCity/scripts.pory"
	.string "If a wild POKéMON gets hurt, it heals\n"
# 1260 "data/maps/SlateportCity/scripts.pory"
	.string "itself by chewing on BERRIES.\p"
# 1261 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1262 "data/maps/SlateportCity/scripts.pory"
	.string "Somebody saw that and got the idea\n"
# 1263 "data/maps/SlateportCity/scripts.pory"
	.string "of making medicine from BERRIES.\p"
# 1264 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1265 "data/maps/SlateportCity/scripts.pory"
	.string "To turn BERRIES into medicine,\n"
# 1266 "data/maps/SlateportCity/scripts.pory"
	.string "they must be crushed into powder.\p"
# 1267 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1268 "data/maps/SlateportCity/scripts.pory"
	.string "You seem to have an interest\n"
# 1269 "data/maps/SlateportCity/scripts.pory"
	.string "in BERRIES!\p"
# 1270 "data/maps/SlateportCity/scripts.pory"
	.string "I've got something good for someone\n"
# 1271 "data/maps/SlateportCity/scripts.pory"
	.string "like you.$"
# 1272 "data/maps/SlateportCity/scripts.pory"

# 1273 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerryPowder:
# 1274 "data/maps/SlateportCity/scripts.pory"
	.string "I recently had machines installed at\n"
# 1275 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
# 1276 "data/maps/SlateportCity/scripts.pory"
	.string "The BERRY CRUSH machines are at\n"
# 1277 "data/maps/SlateportCity/scripts.pory"
	.string "the DIRECT CORNER upstairs.\p"
# 1278 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?\p"
# 1279 "data/maps/SlateportCity/scripts.pory"
	.string "Could you make BERRY POWDER for\n"
# 1280 "data/maps/SlateportCity/scripts.pory"
	.string "me using those machines?\p"
# 1281 "data/maps/SlateportCity/scripts.pory"
	.string "I can make you all sorts of medicine\n"
# 1282 "data/maps/SlateportCity/scripts.pory"
	.string "if you bring me lots of BERRY POWDER.$"
# 1283 "data/maps/SlateportCity/scripts.pory"

# 1284 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BroughtMeSomeBerryPowder:
# 1285 "data/maps/SlateportCity/scripts.pory"
	.string "Have you brought me some\n"
# 1286 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER?$"
# 1287 "data/maps/SlateportCity/scripts.pory"

# 1288 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeWhatWithIt:
# 1289 "data/maps/SlateportCity/scripts.pory"
	.string "What would you like to exchange\n"
# 1290 "data/maps/SlateportCity/scripts.pory"
	.string "it with?$"
# 1291 "data/maps/SlateportCity/scripts.pory"

# 1292 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeBerryPowderForItem:
# 1293 "data/maps/SlateportCity/scripts.pory"
	.string "Okay, you want to exchange your\n"
# 1294 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for one {STR_VAR_1}?$"
# 1295 "data/maps/SlateportCity/scripts.pory"

# 1296 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontHaveEnoughBerryPowder:
# 1297 "data/maps/SlateportCity/scripts.pory"
	.string "Oh, dear. You don't have enough\n"
# 1298 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER.$"
# 1299 "data/maps/SlateportCity/scripts.pory"

# 1300 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FineBerryPowderTradeSomethingElse:
# 1301 "data/maps/SlateportCity/scripts.pory"
	.string "This is fine BERRY POWDER.\n"
# 1302 "data/maps/SlateportCity/scripts.pory"
	.string "It will make excellent medicine.\p"
# 1303 "data/maps/SlateportCity/scripts.pory"
	.string "Would you like to trade more of your\n"
# 1304 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for something else?$"
# 1305 "data/maps/SlateportCity/scripts.pory"

# 1306 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhenYouGetMoreBringItToMe:
# 1307 "data/maps/SlateportCity/scripts.pory"
	.string "Okay! When you get some more\n"
# 1308 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER, bring it to me, please!$"
# 1309 "data/maps/SlateportCity/scripts.pory"

# 1310 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ComeBackToTradeBerryPowder:
# 1311 "data/maps/SlateportCity/scripts.pory"
	.string "Come back if you'd like to trade your\n"
# 1312 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for some medicine.\p"
# 1313 "data/maps/SlateportCity/scripts.pory"
	.string "I'm always running a bazaar here.\p"
# 1314 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?$"
# 1315 "data/maps/SlateportCity/scripts.pory"

# 1316 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_YouDroveTeamAquaAway:
# 1317 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Huh?\n"
# 1318 "data/maps/SlateportCity/scripts.pory"
	.string "I'm sure I met you somewhere before.\p"
# 1319 "data/maps/SlateportCity/scripts.pory"
	.string "Have I introduced myself to you?\n"
# 1320 "data/maps/SlateportCity/scripts.pory"
	.string "If not, my name's SCOTT.\p"
# 1321 "data/maps/SlateportCity/scripts.pory"
	.string "I just saw TEAM AQUA run away from\n"
# 1322 "data/maps/SlateportCity/scripts.pory"
	.string "here like they were stung.\p"
# 1323 "data/maps/SlateportCity/scripts.pory"
	.string "Let me guess--you drove them away?$"
# 1324 "data/maps/SlateportCity/scripts.pory"

# 1325 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MaybeThisTrainer:
# 1326 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Hmm…\n"
# 1327 "data/maps/SlateportCity/scripts.pory"
	.string "Maybe, just maybe, this TRAINER…$"
# 1328 "data/maps/SlateportCity/scripts.pory"

# 1329 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_LetsRegisterEachOther:
# 1330 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: All right! I think you're going\n"
# 1331 "data/maps/SlateportCity/scripts.pory"
	.string "to become a good friend.\p"
# 1332 "data/maps/SlateportCity/scripts.pory"
	.string "So, let's register each other in our\n"
# 1333 "data/maps/SlateportCity/scripts.pory"
	.string "POKéNAVS.\p"
# 1334 "data/maps/SlateportCity/scripts.pory"
	.string "… … … … … …$"
# 1335 "data/maps/SlateportCity/scripts.pory"

# 1336 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RegisteredScott:
# 1337 "data/maps/SlateportCity/scripts.pory"
	.string "Registered this SCOTT person\n"
# 1338 "data/maps/SlateportCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1339 "data/maps/SlateportCity/scripts.pory"

# 1340 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
# 1341 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: What I'd like to do is tag along\n"
# 1342 "data/maps/SlateportCity/scripts.pory"
	.string "with you, but I do want to keep an eye\l"
# 1343 "data/maps/SlateportCity/scripts.pory"
	.string "on the talents of other people, too.\p"
# 1344 "data/maps/SlateportCity/scripts.pory"
	.string "So, I'll be off to roam other towns\n"
# 1345 "data/maps/SlateportCity/scripts.pory"
	.string "a bit more.\p"
# 1346 "data/maps/SlateportCity/scripts.pory"
	.string "Be seeing you, {PLAYER}{KUN}!$"
# 1347 "data/maps/SlateportCity/scripts.pory"

# 1348 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_TakingBattleTentChallenge:
# 1349 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Oh, hey!\n"
# 1350 "data/maps/SlateportCity/scripts.pory"
	.string "If it isn't {PLAYER}{KUN}!\p"
# 1351 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
# 1352 "data/maps/SlateportCity/scripts.pory"
	.string "to take the BATTLE TENT challenge?\p"
# 1353 "data/maps/SlateportCity/scripts.pory"
	.string "Yeah! That's a good idea!\n"
# 1354 "data/maps/SlateportCity/scripts.pory"
	.string "That's a really great idea!\p"
# 1355 "data/maps/SlateportCity/scripts.pory"
	.string "After all, a tough TRAINER is\n"
# 1356 "data/maps/SlateportCity/scripts.pory"
	.string "the perfect fit for the BATTLE TENT!\p"
# 1357 "data/maps/SlateportCity/scripts.pory"
	.string "Give it your best effort!$"
