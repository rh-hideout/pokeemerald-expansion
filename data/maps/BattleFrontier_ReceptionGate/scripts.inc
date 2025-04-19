# 1 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 2 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
.set LOCALID_GREETER, 1
# 3 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
.set LOCALID_GUIDE, 2
# 4 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
.set LOCALID_SCOTT, 4
# 5 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 6 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_MapScripts::
# 7 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
# 8 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
# 9 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.byte 0
# 10 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 11 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_OnTransition:
# 12 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
# 13 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 14 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 15 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_OnFrame:
# 16 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
# 17 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.2byte 0
# 18 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 19 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
# 20 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	lockall
# 21 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
# 22 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	playse SE_PIN
# 23 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
# 24 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 25 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_GREETER, Common_Movement_Delay48
# 26 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 27 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
# 28 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	closemessage
# 29 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
# 30 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 31 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
# 32 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 33 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 34 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ScottScene::
# 35 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
# 36 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
# 37 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 38 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
# 39 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitfanfare
# 40 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmessage
# 41 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
# 42 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	setflag FLAG_SYS_FRONTIER_PASS
# 43 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 44 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
# 45 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	closemessage
# 46 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
# 47 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
# 48 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 49 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 50 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	playse SE_PIN
# 51 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
# 52 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
# 53 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 54 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 55 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
# 56 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	closemessage
# 57 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
# 58 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
# 59 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
# 60 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
# 61 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 62 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
# 63 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	closemessage
# 64 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
# 65 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 66 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	removeobject LOCALID_SCOTT
# 67 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	releaseall
# 68 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 69 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 70 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
# 71 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 72 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 73 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_left
# 74 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_left
# 75 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 76 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 77 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
# 78 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 79 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 80 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 81 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_8
# 82 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_in_place_faster_right
# 83 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 84 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 85 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
@ Unused
# 86 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_WalkDown:
# 87 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 88 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 89 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 90 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 91 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_ScottEnter:
# 92 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 93 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 94 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 95 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 96 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 97 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 98 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_left
# 99 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 100 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 101 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_ScottExit:
# 102 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_right
# 103 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 104 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 105 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 106 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 107 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 108 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 109 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 110 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 111 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
# 112 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 113 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 114 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 115 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_8
# 116 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_in_place_faster_right
# 117 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 118 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 119 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
# 120 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 121 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 122 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 123 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_8
# 124 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_in_place_faster_left
# 125 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 126 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 127 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_Greeter::
# 128 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	lock
# 129 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	faceplayer
# 130 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
# 131 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 132 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	release
# 133 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 134 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 135 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
# 136 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	lock
# 137 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	faceplayer
# 138 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
# 139 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 140 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 141 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 142 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
# 143 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
# 144 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmessage
# 145 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
# 146 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	special ShowScrollableMultichoice
# 147 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitstate
# 148 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	switch VAR_RESULT
# 149 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
# 150 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
# 151 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
# 152 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
# 153 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
# 154 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
# 155 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
# 156 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
# 157 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
# 158 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
# 159 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
# 160 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 161 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 162 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattleTower::
# 163 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
# 164 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 165 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 166 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 167 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattleDome::
# 168 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
# 169 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 170 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 171 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 172 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattlePalace::
# 173 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
# 174 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 175 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 176 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 177 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattleArena::
# 178 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
# 179 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 180 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 181 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 182 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattleFactory::
# 183 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
# 184 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 185 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 186 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 187 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattlePike::
# 188 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
# 189 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 190 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 191 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 192 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
# 193 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
# 194 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 195 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 196 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 197 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_RankingHall::
# 198 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
# 199 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 200 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 201 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 202 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
# 203 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
# 204 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 205 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 206 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 207 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
# 208 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 209 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	release
# 210 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 211 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 212 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_RulesGuide::
# 213 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	lock
# 214 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	faceplayer
# 215 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
# 216 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 217 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 218 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 219 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
# 220 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
# 221 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmessage
# 222 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
# 223 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	switch VAR_RESULT
# 224 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
# 225 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
# 226 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
# 227 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
# 228 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
# 229 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
# 230 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
# 231 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 232 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 233 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_LevelMode::
# 234 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
# 235 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 236 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 237 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 238 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_Level50::
# 239 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
# 240 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 241 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 242 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 243 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_OpenLevel::
# 244 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
# 245 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 246 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 247 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 248 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_MonEntry::
# 249 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
# 250 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 251 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 252 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 253 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_HoldItems::
# 254 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
# 255 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 256 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 257 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 258 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
# 259 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 260 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	release
# 261 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 262 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 263 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
# 264 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	lock
# 265 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	faceplayer
# 266 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
# 267 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
# 268 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 269 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 270 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
# 271 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
# 272 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmessage
# 273 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
# 274 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	switch VAR_RESULT
# 275 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
# 276 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
# 277 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
# 278 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
# 279 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
# 280 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 281 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 282 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_Symbols::
# 283 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
# 284 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
# 285 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 286 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 287 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_RecordBattle::
# 288 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
# 289 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
# 290 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 291 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 292 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattlePoints::
# 293 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
# 294 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
# 295 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 296 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 297 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
# 298 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 299 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	release
# 300 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 301 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 302 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
# 303 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Is it your first time here?\n"
# 304 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Please step this way!$"
# 305 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 306 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
# 307 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The front lines of POKéMON battling!\n"
# 308 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Welcome to the BATTLE FRONTIER!$"
# 309 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 310 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
# 311 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "For a first-time visitor, we issue\n"
# 312 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the FRONTIER PASS.\p"
# 313 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "It's for use at all the facilities\n"
# 314 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "in the BATTLE FRONTIER.\p"
# 315 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Here you are!$"
# 316 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 317 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
# 318 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "{PLAYER} obtained\n"
# 319 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the FRONTIER PASS.$"
# 320 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 321 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
# 322 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "{PLAYER} placed the TRAINER CARD\n"
# 323 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "in the FRONTIER PASS.$"
# 324 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 325 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
# 326 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "We hope you enjoy all that the BATTLE\n"
# 327 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "FRONTIER has to offer!$"
# 328 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 329 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
# 330 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "???: Well, if it isn't {PLAYER}{KUN}!\n"
# 331 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "You came out here!$"
# 332 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 333 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
# 334 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "GUIDE: Oh! MR. SCOTT, sir!\n"
# 335 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Good day to you, sir!$"
# 336 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 337 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
# 338 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "SCOTT: It's great to see you here,\n"
# 339 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "it really is!\p"
# 340 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I hope you'll take your time and\n"
# 341 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "explore everywhere.\p"
# 342 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Naturally, I hope you'll also experience\n"
# 343 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the pure essence of battling.\p"
# 344 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I also have my quarters here, so feel\n"
# 345 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "free to visit if you have time.$"
# 346 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 347 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
# 348 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I'm your guide to the various facilities\n"
# 349 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "here in the BATTLE FRONTIER.$"
# 350 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 351 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
# 352 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Which would you like to learn about?$"
# 353 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 354 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
# 355 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "It is the gigantic tower considered\n"
# 356 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "to be the BATTLE FRONTIER's symbol.\p"
# 357 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "There are four kinds of BATTLE ROOMS\n"
# 358 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "in the tower for SINGLE, DOUBLE, MULTI,\l"
# 359 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "and LINK MULTI BATTLES.$"
# 360 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 361 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
# 362 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE DOME is the large building\n"
# 363 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "shaped like a huge egg.\p"
# 364 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Events named Battle Tourneys are held\n"
# 365 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "in this facility.\p"
# 366 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Battle Tourneys are offered in\n"
# 367 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "two courses--for SINGLE and DOUBLE\l"
# 368 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "BATTLES.$"
# 369 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 370 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
# 371 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE PALACE is the red building\n"
# 372 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "on the right of the BATTLE FRONTIER.\p"
# 373 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "There are two kinds of BATTLE HALLS\n"
# 374 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "for SINGLE and DOUBLE BATTLES.$"
# 375 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 376 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
# 377 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE ARENA is the dojo-like\n"
# 378 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "building at the center-right of\l"
# 379 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER.\p"
# 380 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "An event called the Set KO Tourney\n"
# 381 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "takes place at the BATTLE ARENA.$"
# 382 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 383 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
# 384 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE FACTORY is the large\n"
# 385 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "building that is the closest to us.\p"
# 386 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "An event called the Battle Swap\n"
# 387 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "is conducted there.\p"
# 388 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Battle Swap event is offered in\n"
# 389 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "two courses for SINGLE and DOUBLE\l"
# 390 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "BATTLES.$"
# 391 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 392 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
# 393 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE PIKE is the building shaped\n"
# 394 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "like a POKéMON at the center-left of\l"
# 395 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER.\p"
# 396 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "An event called the Battle Choice\n"
# 397 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "is conducted there.$"
# 398 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 399 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
# 400 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE PYRAMID is the enormous\n"
# 401 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "pyramid.\p"
# 402 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "An event called the Battle Quest\n"
# 403 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "is conducted there.$"
# 404 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 405 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_RankingHallInfo:
# 406 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The RANKING HALL is located near\n"
# 407 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE TOWER.\p"
# 408 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "There, you may see the most fantastic\n"
# 409 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "records left by the TRAINERS that\l"
# 410 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "took on the many challenges of\l"
# 411 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER.$"
# 412 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 413 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
# 414 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The EXCHANGE SERVICE CORNER is near\n"
# 415 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE TOWER.\p"
# 416 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Battle Points you have earned in\n"
# 417 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER may be exchanged\l"
# 418 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "for fabulous prizes there.$"
# 419 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 420 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_YourGuideToRules:
# 421 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I'm your guide to the basic rules that\n"
# 422 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "are common to all the challenges\l"
# 423 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "offered by the facilities in the BATTLE\l"
# 424 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "FRONTIER.$"
# 425 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 426 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
# 427 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "What would you like to learn about?$"
# 428 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 429 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_LevelModeInfo:
# 430 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "All the challenges at the BATTLE\n"
# 431 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "FRONTIER's facilities come in\l"
# 432 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "two courses--Level 50 and Open Level.$"
# 433 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 434 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_Level50Info:
# 435 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Level 50 course is open to POKéMON\n"
# 436 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "up to and including Level 50.\p"
# 437 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Please keep in mind, however, that\n"
# 438 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "no TRAINER you face will have any\l"
# 439 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "POKéMON below Level 50.\p"
# 440 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "This course is the entry level for\n"
# 441 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "battles at the BATTLE FRONTIER.\p"
# 442 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "To begin, we hope you will challenge\n"
# 443 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "this course.$"
# 444 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 445 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
# 446 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Open Level course places no limit\n"
# 447 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "on the levels of POKéMON entering\l"
# 448 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "challenges.\p"
# 449 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The levels of your opponents will\n"
# 450 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "be adjusted to match the levels of\l"
# 451 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "your POKéMON.\p"
# 452 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "However, no TRAINER you face will\n"
# 453 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "have any POKéMON below Level 60.$"
# 454 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 455 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_MonEntryInfo:
# 456 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Virtually any kind of POKéMON may take\n"
# 457 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "on the challenges at all facilities.\p"
# 458 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "EGGS and certain kinds of POKéMON,\n"
# 459 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "however, are not permitted.\p"
# 460 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The numbers of POKéMON required for\n"
# 461 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "challenges will depend on the facility.\p"
# 462 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "At all facilities, however, two or more\n"
# 463 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "of the same kind of POKéMON are not\l"
# 464 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "permitted.$"
# 465 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 466 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
# 467 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "When entering a challenge at a BATTLE\n"
# 468 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "FRONTIER facility, POKéMON may not\l"
# 469 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "be holding the same kind of item.\p"
# 470 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Please make sure that all POKéMON\n"
# 471 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "entering a challenge are holding\l"
# 472 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "different items.$"
# 473 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 474 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
# 475 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I'm your guide to the FRONTIER PASS.$"
# 476 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 477 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
# 478 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Which would you like to learn about?$"
# 479 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 480 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_SymbolsInfo:
# 481 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "There are seven facilities at\n"
# 482 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER.\p"
# 483 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "TRAINERS who gain recognition for\n"
# 484 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "their abilities may be rewarded with\l"
# 485 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "symbols from each of the facilities.\p"
# 486 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "To earn a symbol, TRAINERS may need\n"
# 487 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "to defeat other TRAINERS in a row,\l"
# 488 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "and may need to win events repeatedly.\p"
# 489 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "It's certainly not easy to win symbols.\n"
# 490 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I wish you the best of luck!$"
# 491 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 492 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
# 493 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "It is possible to record one battle\n"
# 494 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "on your FRONTIER PASS.\p"
# 495 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "You may record a battle you had with\n"
# 496 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "a friend or friends.\p"
# 497 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Or you may record a battle conducted\n"
# 498 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "at the BATTLE FRONTIER excluding\l"
# 499 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "matches at the BATTLE PIKE or\l"
# 500 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE PYRAMID.\p"
# 501 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "You may choose to record your match\n"
# 502 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "at the end of a battle.$"
# 503 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"

# 504 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
# 505 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Battle Points are rewards given to\n"
# 506 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "TRAINERS who battled outstandingly\l"
# 507 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "at the BATTLE FRONTIER.\p"
# 508 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "You may trade in your Battle Points\n"
# 509 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "for prizes at the EXCHANGE SERVICE\l"
# 510 "data//maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "CORNER.$"
