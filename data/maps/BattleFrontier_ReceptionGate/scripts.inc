# 1 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 2 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_MapScripts::
# 3 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
# 4 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
# 5 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 7 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_OnTransition:
# 8 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
# 9 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 10 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 11 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_OnFrame:
# 12 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
# 13 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.2byte 0
# 14 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 15 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
# 16 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	lockall
# 17 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
# 18 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	playse SE_PIN
# 19 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
# 20 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 21 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
# 22 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 23 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
# 24 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	closemessage
# 25 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
# 26 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 27 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
# 28 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 29 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 30 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ScottScene::
# 31 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
# 32 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
# 33 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 34 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
# 35 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitfanfare
# 36 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmessage
# 37 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
# 38 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	setflag FLAG_SYS_FRONTIER_PASS
# 39 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 40 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
# 41 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	closemessage
# 42 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
# 43 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
# 44 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 45 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 46 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	playse SE_PIN
# 47 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
# 48 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
# 49 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 50 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 51 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
# 52 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	closemessage
# 53 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
# 54 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
# 55 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
# 56 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
# 57 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 58 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
# 59 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	closemessage
# 60 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
# 61 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmovement 0
# 62 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
# 63 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	releaseall
# 64 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 65 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 66 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
# 67 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 68 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 69 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_left
# 70 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_left
# 71 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 72 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 73 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
# 74 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 75 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 76 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 77 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_8
# 78 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_in_place_faster_right
# 79 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 80 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 81 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
@ Unused
# 82 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_WalkDown:
# 83 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 84 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 85 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 86 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 87 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_ScottEnter:
# 88 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 89 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 90 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 91 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 92 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 93 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_down
# 94 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_left
# 95 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 96 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 97 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_ScottExit:
# 98 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_right
# 99 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 100 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 101 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 102 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 103 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 104 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_up
# 105 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 106 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 107 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
# 108 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 109 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 110 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 111 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_8
# 112 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_in_place_faster_right
# 113 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 114 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 115 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
# 116 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 117 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 118 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_16
# 119 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	delay_8
# 120 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	walk_in_place_faster_left
# 121 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	step_end
# 122 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 123 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_Greeter::
# 124 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	lock
# 125 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	faceplayer
# 126 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
# 127 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 128 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	release
# 129 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 130 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 131 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
# 132 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	lock
# 133 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	faceplayer
# 134 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
# 135 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 136 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 137 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 138 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
# 139 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
# 140 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmessage
# 141 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
# 142 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	special ShowScrollableMultichoice
# 143 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitstate
# 144 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	switch VAR_RESULT
# 145 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
# 146 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
# 147 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
# 148 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
# 149 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
# 150 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
# 151 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
# 152 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
# 153 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
# 154 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
# 155 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
# 156 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 157 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 158 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattleTower::
# 159 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
# 160 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 161 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 162 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 163 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattleDome::
# 164 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
# 165 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 166 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 167 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 168 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattlePalace::
# 169 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
# 170 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 171 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 172 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 173 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattleArena::
# 174 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
# 175 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 176 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 177 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 178 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattleFactory::
# 179 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
# 180 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 181 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 182 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 183 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattlePike::
# 184 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
# 185 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 186 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 187 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 188 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
# 189 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
# 190 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 191 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 192 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 193 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_RankingHall::
# 194 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
# 195 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 196 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 197 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 198 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
# 199 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
# 200 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
# 201 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 202 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 203 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
# 204 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 205 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	release
# 206 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 207 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 208 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_RulesGuide::
# 209 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	lock
# 210 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	faceplayer
# 211 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
# 212 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 213 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 214 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 215 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
# 216 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
# 217 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmessage
# 218 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
# 219 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	switch VAR_RESULT
# 220 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
# 221 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
# 222 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
# 223 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
# 224 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
# 225 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
# 226 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
# 227 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 228 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 229 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_LevelMode::
# 230 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
# 231 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 232 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 233 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 234 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_Level50::
# 235 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
# 236 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 237 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 238 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 239 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_OpenLevel::
# 240 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
# 241 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 242 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 243 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 244 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_MonEntry::
# 245 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
# 246 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 247 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 248 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 249 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_HoldItems::
# 250 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
# 251 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
# 252 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 253 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 254 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
# 255 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 256 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	release
# 257 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 258 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 259 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
# 260 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	lock
# 261 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	faceplayer
# 262 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
# 263 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
# 264 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 265 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 266 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
# 267 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
# 268 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	waitmessage
# 269 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
# 270 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	switch VAR_RESULT
# 271 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
# 272 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
# 273 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
# 274 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
# 275 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
# 276 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 277 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 278 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_Symbols::
# 279 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
# 280 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
# 281 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 282 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 283 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_RecordBattle::
# 284 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
# 285 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
# 286 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 287 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 288 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_BattlePoints::
# 289 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
# 290 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
# 291 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 292 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 293 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
# 294 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
# 295 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	release
# 296 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	end
# 297 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 298 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
# 299 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Is it your first time here?\n"
# 300 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Please step this way!$"
# 301 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 302 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
# 303 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The front lines of POKéMON battling!\n"
# 304 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Welcome to the BATTLE FRONTIER!$"
# 305 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 306 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
# 307 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "For a first-time visitor, we issue\n"
# 308 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the FRONTIER PASS.\p"
# 309 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "It's for use at all the facilities\n"
# 310 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "in the BATTLE FRONTIER.\p"
# 311 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Here you are!$"
# 312 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 313 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
# 314 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "{PLAYER} obtained\n"
# 315 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the FRONTIER PASS.$"
# 316 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 317 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
# 318 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "{PLAYER} placed the TRAINER CARD\n"
# 319 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "in the FRONTIER PASS.$"
# 320 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 321 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
# 322 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "We hope you enjoy all that the BATTLE\n"
# 323 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "FRONTIER has to offer!$"
# 324 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 325 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
# 326 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "???: Well, if it isn't {PLAYER}{KUN}!\n"
# 327 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "You came out here!$"
# 328 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 329 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
# 330 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "GUIDE: Oh! MR. SCOTT, sir!\n"
# 331 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Good day to you, sir!$"
# 332 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 333 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
# 334 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "SCOTT: It's great to see you here,\n"
# 335 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "it really is!\p"
# 336 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I hope you'll take your time and\n"
# 337 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "explore everywhere.\p"
# 338 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Naturally, I hope you'll also experience\n"
# 339 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the pure essence of battling.\p"
# 340 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I also have my quarters here, so feel\n"
# 341 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "free to visit if you have time.$"
# 342 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 343 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
# 344 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I'm your guide to the various facilities\n"
# 345 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "here in the BATTLE FRONTIER.$"
# 346 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 347 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
# 348 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Which would you like to learn about?$"
# 349 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 350 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
# 351 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "It is the gigantic tower considered\n"
# 352 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "to be the BATTLE FRONTIER's symbol.\p"
# 353 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "There are four kinds of BATTLE ROOMS\n"
# 354 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "in the tower for SINGLE, DOUBLE, MULTI,\l"
# 355 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "and LINK MULTI BATTLES.$"
# 356 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 357 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
# 358 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE DOME is the large building\n"
# 359 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "shaped like a huge egg.\p"
# 360 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Events named Battle Tourneys are held\n"
# 361 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "in this facility.\p"
# 362 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Battle Tourneys are offered in\n"
# 363 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "two courses--for SINGLE and DOUBLE\l"
# 364 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "BATTLES.$"
# 365 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 366 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
# 367 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE PALACE is the red building\n"
# 368 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "on the right of the BATTLE FRONTIER.\p"
# 369 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "There are two kinds of BATTLE HALLS\n"
# 370 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "for SINGLE and DOUBLE BATTLES.$"
# 371 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 372 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
# 373 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE ARENA is the dojo-like\n"
# 374 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "building at the center-right of\l"
# 375 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER.\p"
# 376 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "An event called the Set KO Tourney\n"
# 377 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "takes place at the BATTLE ARENA.$"
# 378 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 379 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
# 380 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE FACTORY is the large\n"
# 381 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "building that is the closest to us.\p"
# 382 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "An event called the Battle Swap\n"
# 383 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "is conducted there.\p"
# 384 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Battle Swap event is offered in\n"
# 385 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "two courses for SINGLE and DOUBLE\l"
# 386 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "BATTLES.$"
# 387 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 388 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
# 389 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE PIKE is the building shaped\n"
# 390 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "like a POKéMON at the center-left of\l"
# 391 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER.\p"
# 392 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "An event called the Battle Choice\n"
# 393 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "is conducted there.$"
# 394 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 395 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
# 396 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The BATTLE PYRAMID is the enormous\n"
# 397 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "pyramid.\p"
# 398 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "An event called the Battle Quest\n"
# 399 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "is conducted there.$"
# 400 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 401 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_RankingHallInfo:
# 402 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The RANKING HALL is located near\n"
# 403 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE TOWER.\p"
# 404 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "There, you may see the most fantastic\n"
# 405 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "records left by the TRAINERS that\l"
# 406 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "took on the many challenges of\l"
# 407 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER.$"
# 408 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 409 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
# 410 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The EXCHANGE SERVICE CORNER is near\n"
# 411 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE TOWER.\p"
# 412 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Battle Points you have earned in\n"
# 413 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER may be exchanged\l"
# 414 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "for fabulous prizes there.$"
# 415 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 416 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_YourGuideToRules:
# 417 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I'm your guide to the basic rules that\n"
# 418 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "are common to all the challenges\l"
# 419 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "offered by the facilities in the BATTLE\l"
# 420 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "FRONTIER.$"
# 421 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 422 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
# 423 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "What would you like to learn about?$"
# 424 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 425 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_LevelModeInfo:
# 426 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "All the challenges at the BATTLE\n"
# 427 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "FRONTIER's facilities come in\l"
# 428 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "two courses--Level 50 and Open Level.$"
# 429 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 430 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_Level50Info:
# 431 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Level 50 course is open to POKéMON\n"
# 432 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "up to and including Level 50.\p"
# 433 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Please keep in mind, however, that\n"
# 434 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "no TRAINER you face will have any\l"
# 435 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "POKéMON below Level 50.\p"
# 436 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "This course is the entry level for\n"
# 437 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "battles at the BATTLE FRONTIER.\p"
# 438 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "To begin, we hope you will challenge\n"
# 439 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "this course.$"
# 440 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 441 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
# 442 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The Open Level course places no limit\n"
# 443 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "on the levels of POKéMON entering\l"
# 444 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "challenges.\p"
# 445 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The levels of your opponents will\n"
# 446 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "be adjusted to match the levels of\l"
# 447 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "your POKéMON.\p"
# 448 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "However, no TRAINER you face will\n"
# 449 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "have any POKéMON below Level 60.$"
# 450 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 451 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_MonEntryInfo:
# 452 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Virtually any kind of POKéMON may take\n"
# 453 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "on the challenges at all facilities.\p"
# 454 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "EGGS and certain kinds of POKéMON,\n"
# 455 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "however, are not permitted.\p"
# 456 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "The numbers of POKéMON required for\n"
# 457 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "challenges will depend on the facility.\p"
# 458 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "At all facilities, however, two or more\n"
# 459 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "of the same kind of POKéMON are not\l"
# 460 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "permitted.$"
# 461 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 462 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
# 463 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "When entering a challenge at a BATTLE\n"
# 464 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "FRONTIER facility, POKéMON may not\l"
# 465 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "be holding the same kind of item.\p"
# 466 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Please make sure that all POKéMON\n"
# 467 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "entering a challenge are holding\l"
# 468 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "different items.$"
# 469 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 470 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
# 471 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I'm your guide to the FRONTIER PASS.$"
# 472 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 473 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
# 474 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Which would you like to learn about?$"
# 475 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 476 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_SymbolsInfo:
# 477 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "There are seven facilities at\n"
# 478 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE FRONTIER.\p"
# 479 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "TRAINERS who gain recognition for\n"
# 480 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "their abilities may be rewarded with\l"
# 481 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "symbols from each of the facilities.\p"
# 482 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "To earn a symbol, TRAINERS may need\n"
# 483 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "to defeat other TRAINERS in a row,\l"
# 484 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "and may need to win events repeatedly.\p"
# 485 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "It's certainly not easy to win symbols.\n"
# 486 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "I wish you the best of luck!$"
# 487 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 488 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
# 489 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "It is possible to record one battle\n"
# 490 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "on your FRONTIER PASS.\p"
# 491 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "You may record a battle you had with\n"
# 492 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "a friend or friends.\p"
# 493 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Or you may record a battle conducted\n"
# 494 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "at the BATTLE FRONTIER excluding\l"
# 495 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "matches at the BATTLE PIKE or\l"
# 496 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "the BATTLE PYRAMID.\p"
# 497 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "You may choose to record your match\n"
# 498 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "at the end of a battle.$"
# 499 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"

# 500 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
# 501 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "Battle Points are rewards given to\n"
# 502 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "TRAINERS who battled outstandingly\l"
# 503 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "at the BATTLE FRONTIER.\p"
# 504 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "You may trade in your Battle Points\n"
# 505 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "for prizes at the EXCHANGE SERVICE\l"
# 506 "data/maps/BattleFrontier_ReceptionGate/scripts.pory"
	.string "CORNER.$"
