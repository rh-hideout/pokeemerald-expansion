ContestHall_hns_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ContestHall_OnWarp_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ContestHall_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, ContestHall_OnTransition_hns
	map_script MAP_SCRIPT_ON_RESUME, ContestHall_OnResume_hns
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, ContestHall_OnReturn_hns
	.byte 0

ContestHall_OnReturn_hns:
	special LoadLinkContestPlayerPalettes
	end

ContestHall_OnTransition_hns:
	call ContestHall_EventScript_ReadyContestMusic_hns
	setvar VAR_TEMP_0, 1
	call ContestHall_EventScript_AddRandomAudienceMembers_hns
	end

ContestHall_EventScript_ReadyContestMusic_hns::
	call ContestHall_EventScript_TryWaitForLink
	special GetContestMultiplayerId
	call_if_eq VAR_RESULT, 0, ContestHall_EventScript_SaveContestMusicPlayer1_hns
	call_if_eq VAR_RESULT, 1, ContestHall_EventScript_SaveContestMusicPlayer2_hns
	call_if_eq VAR_RESULT, 2, ContestHall_EventScript_SaveContestMusicPlayer3_hns
	call_if_eq VAR_RESULT, 3, ContestHall_EventScript_SaveContestMusicPlayer4_hns
	call_if_eq VAR_RESULT, 4, ContestHall_EventScript_SaveContestMusic_hns
	return

ContestHall_EventScript_SaveContestMusicPlayer1_hns::
	savebgm MUS_LINK_CONTEST_P1
	return

ContestHall_EventScript_SaveContestMusicPlayer2_hns::
	savebgm MUS_LINK_CONTEST_P2
	return

ContestHall_EventScript_SaveContestMusicPlayer3_hns::
	savebgm MUS_LINK_CONTEST_P3
	return

ContestHall_EventScript_SaveContestMusicPlayer4_hns::
	savebgm MUS_LINK_CONTEST_P4
	return

ContestHall_EventScript_SaveContestMusic_hns::
	savebgm MUS_CONTEST
	return

ContestHall_OnResume_hns:
	call_if_eq VAR_TEMP_9, 1, ContestHall_EventScript_ReShowAudience_hns
	end

ContestHall_EventScript_ReShowAudience_hns::
	call ContestHall_EventScript_CreateAudience_hns
	return

ContestHall_OnFrame_hns:
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_Contest_hns
	.2byte 0

ContestHall_OnWarp_hns:
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_SetContestObjects_hns
	.2byte 0

ContestHall_EventScript_Contest_hns::
	call ContestHall_EventScript_DoContest
	call ContestHall_EventScript_SetExitWarp_hns
	end

ContestHall_EventScript_SetContestObjects_hns::
	special LoadLinkContestPlayerPalettes
	hideobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
	call ContestHall_EventScript_CreateAudience_hns
	end

@ There are 8 audience member object events, 7 of which are given random gfx below (the 8th is the Artist)
@ The rest of the audience is created statically by ContestHall_EventScript_CreateAudience_hns
ContestHall_EventScript_AddRandomAudienceMembers_hns::
	call ContestHall_EventScript_GetRandomAudienceGfxId_hns
	call ContestHall_EventScript_SetRandomAudienceGfx_hns
	goto_if_lt VAR_TEMP_0, 8, ContestHall_EventScript_AddRandomAudienceMembers_hns
	return

ContestHall_EventScript_SetRandomAudienceGfx_hns::
	switch VAR_TEMP_0
	case 1, ContestHall_EventScript_SetRandomAudience1_hns
	case 2, ContestHall_EventScript_SetRandomAudience2_hns
	case 3, ContestHall_EventScript_SetRandomAudience3_hns
	case 4, ContestHall_EventScript_SetRandomAudience4_hns
	case 5, ContestHall_EventScript_SetRandomAudience5_hns
	case 6, ContestHall_EventScript_SetRandomAudience6_hns
	case 7, ContestHall_EventScript_SetRandomAudience7_hns
	end

ContestHall_EventScript_SetRandomAudience1_hns::
	copyvar VAR_OBJ_GFX_ID_4, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience2_hns::
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience3_hns::
	copyvar VAR_OBJ_GFX_ID_6, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience4_hns::
	copyvar VAR_OBJ_GFX_ID_7, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience5_hns::
	copyvar VAR_OBJ_GFX_ID_8, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience6_hns::
	copyvar VAR_OBJ_GFX_ID_9, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience7_hns::
	copyvar VAR_OBJ_GFX_ID_A, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_GetRandomAudienceGfxId_hns::
	setvar VAR_RESULT, 32
	special GenerateContestRand
	addvar VAR_RESULT, 1
	switch VAR_RESULT
	case 1, ContestHall_EventScript_RandomAudienceNinjaBoy_hns
	case 2, ContestHall_EventScript_RandomAudienceTwin_hns
	case 3, ContestHall_EventScript_RandomAudienceBoy1_hns
	case 4, ContestHall_EventScript_RandomAudienceGirl1_hns
	case 5, ContestHall_EventScript_RandomAudienceGirl2_hns
	case 6, ContestHall_EventScript_RandomAudienceLittleBoy_hns
	case 7, ContestHall_EventScript_RandomAudienceGirl_hns
	case 8, ContestHall_EventScript_RandomAudienceBoy3_hns
	case 9, ContestHall_EventScript_RandomAudienceGirl3_hns
	case 10, ContestHall_EventScript_RandomAudienceRichBoy_hns
	case 11, ContestHall_EventScript_RandomAudienceFatMan_hns
	case 12, ContestHall_EventScript_RandomAudiencePokefanF_hns
	case 13, ContestHall_EventScript_RandomAudienceMan1_hns
	case 14, ContestHall_EventScript_RandomAudienceWoman2_hns
	case 15, ContestHall_EventScript_RandomAudienceExpertM_hns
	case 16, ContestHall_EventScript_RandomAudienceExpertF_hns
	case 17, ContestHall_EventScript_RandomAudiencePokefanM_hns
	case 18, ContestHall_EventScript_RandomAudienceWoman4_hns
	case 19, ContestHall_EventScript_RandomAudienceCook_hns
	case 20, ContestHall_EventScript_RandomAudienceLass_hns
	case 21, ContestHall_EventScript_RandomAudienceOldWoman_hns
	case 22, ContestHall_EventScript_RandomAudienceCamper_hns
	case 23, ContestHall_EventScript_RandomAudiencePicnicker_hns
	case 24, ContestHall_EventScript_RandomAudienceMan3_hns
	case 25, ContestHall_EventScript_RandomAudienceWoman5_hns
	case 26, ContestHall_EventScript_RandomAudienceYoungster_hns
	case 27, ContestHall_EventScript_RandomAudienceBugCatcher_hns
	case 28, ContestHall_EventScript_RandomAudiencePsychicM_hns
	case 29, ContestHall_EventScript_RandomAudienceSchoolKidM_hns
	case 30, ContestHall_EventScript_RandomAudienceBlackBelt_hns
	case 31, ContestHall_EventScript_RandomAudienceBeauty_hns
	case 32, ContestHall_EventScript_RandomAudienceScientist1_hns
	end

ContestHall_EventScript_RandomAudienceNinjaBoy_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_NINJA_BOY
	return

ContestHall_EventScript_RandomAudienceTwin_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_TWIN
	return

ContestHall_EventScript_RandomAudienceBoy1_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_1
	return

ContestHall_EventScript_RandomAudienceGirl1_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_1
	return

ContestHall_EventScript_RandomAudienceGirl2_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_2
	return

ContestHall_EventScript_RandomAudienceLittleBoy_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_BOY
	return

ContestHall_EventScript_RandomAudienceGirl_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_GIRL
	return

ContestHall_EventScript_RandomAudienceBoy3_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_3
	return

ContestHall_EventScript_RandomAudienceGirl3_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_3
	return

ContestHall_EventScript_RandomAudienceRichBoy_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_RICH_BOY
	return

ContestHall_EventScript_RandomAudienceFatMan_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_FAT_MAN
	return

ContestHall_EventScript_RandomAudiencePokefanF_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_F
	return

ContestHall_EventScript_RandomAudienceMan1_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_1
	return

ContestHall_EventScript_RandomAudienceWoman2_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_2
	return

ContestHall_EventScript_RandomAudienceExpertM_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_M
	return

ContestHall_EventScript_RandomAudienceExpertF_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_F
	return

ContestHall_EventScript_RandomAudiencePokefanM_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_M
	return

ContestHall_EventScript_RandomAudienceWoman4_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_4
	return

ContestHall_EventScript_RandomAudienceCook_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_COOK
	return

ContestHall_EventScript_RandomAudienceLass_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LASS
	return

ContestHall_EventScript_RandomAudienceOldWoman_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_OLD_WOMAN
	return

ContestHall_EventScript_RandomAudienceCamper_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_CAMPER
	return

ContestHall_EventScript_RandomAudiencePicnicker_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PICNICKER
	return

ContestHall_EventScript_RandomAudienceMan3_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_3
	return

ContestHall_EventScript_RandomAudienceWoman5_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_5
	return

ContestHall_EventScript_RandomAudienceYoungster_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_YOUNGSTER
	return

ContestHall_EventScript_RandomAudienceBugCatcher_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BUG_CATCHER
	return

ContestHall_EventScript_RandomAudiencePsychicM_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PSYCHIC_M
	return

ContestHall_EventScript_RandomAudienceSchoolKidM_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCHOOL_KID_M
	return

ContestHall_EventScript_RandomAudienceBlackBelt_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BLACK_BELT
	return

ContestHall_EventScript_RandomAudienceBeauty_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BEAUTY
	return

ContestHall_EventScript_RandomAudienceScientist1_hns::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCIENTIST_1
	return

ContestHall_EventScript_CreateAudience_hns::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_CreateWirelessContestAudience_hns
	switch VAR_CONTEST_TYPE
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_CreateNormalContestAudience_hns
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_CreateSuperContestAudience_hns
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_CreateHyperContestAudience_hns
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_CreateMasterContestAudience_hns
	case CONTEST_TYPE_LINK, ContestHall_EventScript_CreateMasterContestAudience_hns
	return

ContestHall_EventScript_CreateNormalContestAudience_hns::
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_CreateSuperContestAudience_hns::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_LASS, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_CreateHyperContestAudience_hns::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_2, 20, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_5, 20, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 8, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
	return

ContestHall_EventScript_CreateMasterContestAudience_hns::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SAILOR, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
	return

ContestHall_EventScript_CreateWirelessContestAudience_hns::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_SetExitWarp_hns::
	special ClearLinkContestFlags
	switch VAR_CONTEST_TYPE
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_SetExitWarpNormalContest_hns
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_SetExitWarpSuperContest_hns
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_SetExitWarpHyperContest_hns
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_SetExitWarpMasterContest_hns
	case CONTEST_TYPE_LINK, ContestHall_EventScript_SetExitWarpLinkContest_hns
	return

ContestHall_EventScript_SetExitWarpNormalContest_hns::
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY_HNS, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpSuperContest_hns::
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY_HNS, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpHyperContest_hns::
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY_HNS, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpMasterContest_hns::
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY_HNS, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpLinkContest_hns::
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY_HNS, 15, 4
	waitstate
	end

LilycoveCity_ContestLobby_EventScript_SetPlayerGfx_hns::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_ContestLobby_EventScript_SetPlayerGfxBrendan_hns
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay_hns
	return

LilycoveCity_ContestLobby_EventScript_SetPlayerGfxBrendan_hns::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_GOLD_NORMAL_HNS
	return

LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay_hns::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_KRIS_NORMAL_HNS
	return

