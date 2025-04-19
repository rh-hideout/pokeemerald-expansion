# 1 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 2 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 4 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_MapScripts::
# 5 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
# 6 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
# 7 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.byte 0
# 8 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 9 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room
# 10 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 11 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_OnWarp:
# 12 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
# 13 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.2byte 0
# 14 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 15 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
# 16 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 17 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
# 18 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	setobjectxy LOCALID_ATTENDANT, 2, 2
# 19 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
# 20 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
# 21 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 22 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	end
# 23 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 24 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_OnFrame:
# 25 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
# 26 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.2byte 0
# 27 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 28 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
# 29 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
# 30 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 31 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
# 32 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
# 33 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 34 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
# 35 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_generaterentalmons
# 36 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_generateopponentmons
# 37 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
# 38 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	fadescreen FADE_TO_BLACK
# 39 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_rentmons
# 40 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitstate
# 41 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
# 42 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
# 43 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	closemessage
# 44 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
# 45 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 46 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	opendoor 2, 1
# 47 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitdooranim
# 48 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
# 49 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
# 50 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 51 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	closedoor 2, 1
# 52 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitdooranim
# 53 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
# 54 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitstate
# 55 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	end
# 56 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 57 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
# 58 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	factory_setopponentmons
# 59 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	factory_resethelditems
# 60 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
# 61 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	playfanfare MUS_HEAL
# 62 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitfanfare
# 63 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	special HealPlayerParty
# 64 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
# 65 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 66 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
# 67 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
# 68 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 69 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	switch VAR_RESULT
# 70 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
# 71 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
# 72 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge
# 73 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 74 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
# 75 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 76 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	switch VAR_RESULT
# 77 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 78 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
# 79 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 80 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 81 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
# 82 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
# 83 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmessage
# 84 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 85 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	switch VAR_RESULT
# 86 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 87 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
# 88 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 89 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 90 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
# 91 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_generateopponentmons
# 92 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 93 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	switch VAR_RESULT
# 94 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
# 95 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
# 96 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
# 97 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 98 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_SwapMons::
# 99 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	fadescreen FADE_TO_BLACK
# 100 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_swapmons
# 101 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitstate
# 102 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
# 103 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
# 104 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
# 105 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 106 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
# 107 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
# 108 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmessage
# 109 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	return
# 110 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 111 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
# 112 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
# 113 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmessage
# 114 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	return
# 115 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 116 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
# 117 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
# 118 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmessage
# 119 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_save CHALLENGE_STATUS_PAUSED
# 120 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	playse SE_SAVE
# 121 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitse
# 122 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	fadescreen FADE_TO_BLACK
# 123 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	frontier_reset
# 124 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	end
# 125 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 126 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
# 127 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	special SavePlayerParty
# 128 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	factory_setparties 0
# 129 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 130 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 131 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
# 132 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 133 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 134 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 135 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 136 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	step_end
# 137 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 138 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_Movement_PlayerExit:
# 139 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 140 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 141 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	set_invisible
# 142 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	step_end
# 143 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 144 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
# 145 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 146 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 147 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 148 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 149 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_in_place_faster_down
# 150 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	step_end
# 151 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 152 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_Movement_AttendantExit:
# 153 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 154 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	set_invisible
# 155 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	step_end
# 156 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 157 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Leftover text from when this was a Contest Hall in R/S
# 158 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 159 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_AdviceForContests:
# 160 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Want a tasty little bit of advice\n"
# 161 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "for CONTESTS?\p"
# 162 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Using a certain move after another\n"
# 163 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "certain kind of move sometimes gets\l"
# 164 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "you extra attention.\p"
# 165 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "If you know what you're doing,\n"
# 166 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "you can score big in appeal.\p"
# 167 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Of course, your opponents might try\n"
# 168 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "disrupting your POKéMON's showing.$"
# 169 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 170 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 171 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
# 172 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "My papa, he's a CONTEST JUDGE.\p"
# 173 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I wonder what I should be when I\n"
# 174 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "grow up, a JUDGE or a GYM LEADER?$"
# 175 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 176 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 177 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
# 178 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Hey, man, I'm like majorly cheesed,\n"
# 179 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "you know. Like, you know, I just\l"
# 180 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "wanted to know why my POKéMON\l"
# 181 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "never won, you know, like, hey?\p"
# 182 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "So, like, I gave the JUDGE my two\n"
# 183 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "cents, you know, they're free.\p"
# 184 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "And he wouldn't hear me out, like, hey!\n"
# 185 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "So, like, total bummer, man!\p"
# 186 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Hey, like, you! Zip it, you know?\n"
# 187 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Just, you know, take this!$"
# 188 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 189 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 190 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_ExplainTorment:
# 191 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "That's, like, TM41, you know?\n"
# 192 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Hey, it's TORMENT, you hearing me?\p"
# 193 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Like, it won't let the other guy\n"
# 194 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "use the same move twice in a row, see?\p"
# 195 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Hey, now, you listen here, like,\n"
# 196 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I'm not laying a torment on you!$"
# 197 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 198 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 199 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
# 200 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "MC: Oh, my, my!\n"
# 201 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Now isn't that a dandy of a POKéMON?\p"
# 202 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Please! Do step right up and take\n"
# 203 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "part in our splendid CONTESTS!\p"
# 204 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "You'll do well! I'm sure of it!\n"
# 205 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "My eyes have never failed me!$"
# 206 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 207 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 208 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
# 209 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "JUDGE: Well, hello there!\n"
# 210 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I see that you're a TRAINER!\p"
# 211 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Then, it just wouldn't do for you\n"
# 212 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "to miss a POKéMON CONTEST!\p"
# 213 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Get a CONTEST PASS in VERDANTURF\n"
# 214 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "CITY and enter anytime!$"
# 215 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 216 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 217 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_ItsAppealTime:
# 218 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "It's appeal time!\n"
# 219 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "What should I lead with?$"
# 220 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 221 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 222 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
# 223 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "They didn't pay much attention to\n"
# 224 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "my POKéMON's appeal…\p"
# 225 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Humph, that JUDGE, he doesn't know\n"
# 226 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "a good thing when he sees it.$"
# 227 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 228 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 229 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
# 230 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Oh, hi! You must be a serious fan to get\n"
# 231 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "this close to the action.\p"
# 232 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I'll reward your enthusiasm with\n"
# 233 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "this sage advice.\p"
# 234 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "If a move goes over really well,\n"
# 235 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "the audience will get excited.\p"
# 236 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "The POKéMON that makes its appeal\n"
# 237 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "right when everyone's excited…\p"
# 238 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Well, you'd think something good has\n"
# 239 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "to happen!$"
# 240 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 241 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 242 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
# 243 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I can't do this! I'm more freaked out\n"
# 244 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "than my POKéMON.\p"
# 245 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I'm shivering and my heart is racing!$"
# 246 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 247 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 248 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_BattleAndContestAlike:
# 249 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "A battle and a CONTEST aren't the\n"
# 250 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "same, but they are alike, too.\p"
# 251 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "You need to work hard and believe\n"
# 252 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "in the POKéMON you've raised.$"
# 253 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 254 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 255 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
# 256 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "That POKéMON looks like it's on top\n"
# 257 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "of its game, huh?\p"
# 258 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "A POKéMON that does good in the\n"
# 259 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "secondary judging seems to be more\l"
# 260 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "relaxed when it's doing appeals.$"
# 261 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 262 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 263 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
# 264 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Will you look at that sorry sight?\p"
# 265 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Heh, my POKéMON's absolutely better\n"
# 266 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "than that lot!$"
# 267 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 268 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 269 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
# 270 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Don't you get the urge to move with\n"
# 271 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "POKéMON if they're putting on an\l"
# 272 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "energetic appeal?$"
# 273 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 274 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 275 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_HyperRankStage:
# 276 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "POKéMON CONTESTS\n"
# 277 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "HYPER RANK STAGE!$"
