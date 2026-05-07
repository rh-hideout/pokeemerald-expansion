BattleFrontier_BattlePikeThreePathRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnWarp_hns
	.byte 0

BattleFrontier_BattlePikeThreePathRoom_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_5, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom_hns
	map_script_2 VAR_TEMP_5, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint_hns
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_OnWarp_hns:
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_4, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY_HNS, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge_hns::
	lockall
	message BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume_hns
	waitmessage
	pike_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge_hns, MSGBOX_DEFAULT
	closemessage
	releaseall
	frontier_settrainers
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hns::
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Room number
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom1_hns
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom3_hns
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom5_hns
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom7_hns
	case 9, BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom9_hns
	case 11, BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom1_hns1_hns
	case 13, BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom1_hns3_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom1_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom3_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom5_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom7_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom9_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom1_hns1_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1_hns1_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant_hnsRoom1_hns3_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1_hns3_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge_hns
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge_hns::
	frontier_saveparty
	message BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData_hns
	waitmessage
	special LoadPlayerParty
	pike_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge_hns
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge_hns
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge_hns::
	message BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePike_EventScript_Retire
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom_hns::
	pike_sethintroom
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint_hns
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint_hns::
	setvar VAR_TEMP_5, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint_hns::
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer_hns
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent_hns, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos_hns
	waitmovement 0
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintGiver_hns::
	pike_gethint
	goto_if_eq VAR_RESULT, PIKE_HINT_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint_hns
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint_hns
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint_hns
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint_hns::
	pike_gethintroomid
	switch VAR_RESULT
	case PIKE_ROOM_LEFT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint_hns
	case PIKE_ROOM_CENTER, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint_hns
	case PIKE_ROOM_RIGHT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint_hns

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint_hns

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint_hns

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint_hns::
	pike_gethint
	switch VAR_RESULT
	case PIKE_HINT_NOSTALGIA, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia_hns
	case PIKE_HINT_WHISPERING, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering_hns
	case PIKE_HINT_POKEMON, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon_hns
	case PIKE_HINT_PEOPLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople_hns
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople_hns::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer_hns:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1_hns:
	.string "You are currently in\n"
	.string "the 1st room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3_hns:
	.string "You are currently in\n"
	.string "the 3rd room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5_hns:
	.string "You are currently in\n"
	.string "the 5th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7_hns:
	.string "You are currently in\n"
	.string "the 7th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9_hns:
	.string "You are currently in\n"
	.string "the 9th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1_hns1_hns:
	.string "You are currently in\n"
	.string "the 11th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1_hns3_hns:
	.string "You are currently in\n"
	.string "the 13th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge_hns:
	.string "Will you continue with\n"
	.string "your challenge?$"

BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit_hns:
	.string "Would you like to save your challenge\n"
	.string "and quit the game for now?$"

BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge_hns:
	.string "Do you wish to retire from your\n"
	.string "Battle Choice challenge?$"

BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume_hns:
	.string "We've been awaiting your return…\p"
	.string "Before resuming your Battle Choice\n"
	.string "challenge, let me save the game…$"

BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge_hns:
	.string "Please do enjoy your Battle Choice\n"
	.string "challenge…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData_hns:
	.string "I am saving your data…\n"
	.string "A little time, please…$"

BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack_hns:
	.string "The path is blocked!\n"
	.string "And there is no turning back…$"

BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose_hns:
	.string "I beg your pardon, but…\p"
	.string "Are you perhaps finding it difficult\n"
	.string "to choose your path?$"

BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence_hns:
	.string "I see…\n"
	.string "I apologize for my impertinence…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath_hns:
	.string "Ah, let me see… There is something\n"
	.string "about the path on the right…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath_hns:
	.string "Ah, let me see… There is something\n"
	.string "about the path in the center…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath_hns:
	.string "Ah, let me see… There is something\n"
	.string "about the path on the left…$"

BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon_hns:
	.string "It seems to have the distinct aroma\n"
	.string "of POKéMON wafting around it…$"

BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople_hns:
	.string "Is it… A TRAINER?\n"
	.string "I sense the presence of people…$"

BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering_hns:
	.string "I seem to have heard something…\n"
	.string "It may have been whispering…$"

BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga_hns:
	.string "For some odd reason, I felt a wave\n"
	.string "of nostalgia coming from it…$"

BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent_hns:
	.string "I am sorry to say…\p"
	.string "A terrifying event, yes, a horrible one,\n"
	.string "is about to befall you…\p"
	.string "I urge you to pay the utmost care\n"
	.string "and prepare for the worst…$"

BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence_hns:
	.string "From every path I sense a dreadful\n"
	.string "presence…$"
