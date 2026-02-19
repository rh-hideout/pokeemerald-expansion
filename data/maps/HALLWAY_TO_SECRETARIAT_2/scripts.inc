HALLWAY_TO_SECRETARIAT_2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, HALLWAY_TO_SECRETARIAT_2_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HALLWAY_TO_SECRETARIAT_2_OnFrame
	.byte 0

HALLWAY_TO_SECRETARIAT_2_OnFrame:
	map_script_2 VAR_TEMP_B, 0, HALLWAY_TO_SECRETARIAT_2_EventScript_StartHouvertFlashback
	.2byte 0

HALLWAY_TO_SECRETARIAT_2_OnLoad:
	setvar VAR_TEMP_B, 1
	setvar VAR_TEMP_F, 0
	call HALLWAY_TO_SECRETARIAT_2_EventScript_ApplySecretDoorMetatiles
	call HALLWAY_TO_SECRETARIAT_2_EventScript_UpdateHintNpc
	call_if_set FLAG_CTF_HOUVERT_EXAM_FLASHBACK, HALLWAY_TO_SECRETARIAT_2_EventScript_EnableHouvertFlashback
	end

HALLWAY_TO_SECRETARIAT_2_EventScript_EnableHouvertFlashback::
	goto_if_set FLAG_CTF_HOUVERT_FLASHBACK_INTRO_SEEN, HALLWAY_TO_SECRETARIAT_2_EventScript_EnableHouvertFlashbackReturn
	setvar VAR_TEMP_B, 0
	goto HALLWAY_TO_SECRETARIAT_2_EventScript_EnableHouvertFlashbackReturn

HALLWAY_TO_SECRETARIAT_2_EventScript_EnableHouvertFlashbackReturn::
	return

HALLWAY_TO_SECRETARIAT_2_EventScript_StartHouvertFlashback::
	setvar VAR_TEMP_B, 1
	lockall
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	msgbox HALLWAY_TO_SECRETARIAT_2_Text_PlayerRemembersHallway, MSGBOX_DEFAULT
	setflag FLAG_CTF_HOUVERT_FLASHBACK_INTRO_SEEN
	releaseall
	end

HALLWAY_TO_SECRETARIAT_2_EventScript_UpdateHintNpc::
	goto_if_set FLAG_SECRETARIAT_HIDDEN_DOOR_OPEN, HALLWAY_TO_SECRETARIAT_2_EventScript_HideHintNpc
	call HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirement
	goto_if_eq VAR_RESULT, TRUE, HALLWAY_TO_SECRETARIAT_2_EventScript_ShowHintNpc
HALLWAY_TO_SECRETARIAT_2_EventScript_HideHintNpc::
	setflag FLAG_HIDE_SECRETARIAT_HINT_NPC
	return

HALLWAY_TO_SECRETARIAT_2_EventScript_ShowHintNpc::
	clearflag FLAG_HIDE_SECRETARIAT_HINT_NPC
	return

HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirement::
	setvar VAR_RESULT, FALSE
	goto_if_lt VAR_CTF_CLASSROOM_LEFT_VISITS, 2, HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirementReturn
	goto_if_lt VAR_CTF_CLASSROOM_LEFT2_VISITS, 2, HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirementReturn
	goto_if_lt VAR_CTF_CLASSROOM_TOP_VISITS, 2, HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirementReturn
	goto_if_lt VAR_CTF_CLASSROOM_TOP2_VISITS, 2, HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirementReturn
	goto_if_lt VAR_CTF_CLASSROOM_RIGHT_VISITS, 2, HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirementReturn
	goto_if_lt VAR_CTF_CLASSROOM_RIGHT2_VISITS, 2, HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirementReturn
	goto_if_lt VAR_CTF_ADMIN_OFFICE_VISITS, 2, HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirementReturn
	setvar VAR_RESULT, TRUE
HALLWAY_TO_SECRETARIAT_2_EventScript_CheckVisitRequirementReturn::
	return

HALLWAY_TO_SECRETARIAT_2_EventScript_ApplySecretDoorMetatiles::
	goto_if_set FLAG_SECRETARIAT_HIDDEN_DOOR_OPEN, HALLWAY_TO_SECRETARIAT_2_EventScript_ShowSecretDoor_OnLoad
	goto HALLWAY_TO_SECRETARIAT_2_EventScript_HideSecretDoor_OnLoad

HALLWAY_TO_SECRETARIAT_2_EventScript_ShowSecretDoor_OnLoad::
	setmetatile 12, 0, METATILE_DHBWFLOORS_SecretDoor_TopLeft, TRUE
	setmetatile 13, 0, METATILE_DHBWFLOORS_SecretDoor_TopMid, TRUE
	setmetatile 14, 0, METATILE_DHBWFLOORS_SecretDoor_TopRight, TRUE
	setmetatile 12, 1, METATILE_DHBWFLOORS_SecretDoor_BottomLeft, TRUE
	setmetatile 13, 1, METATILE_DHBWFLOORS_SecretDoor_BottomMid, TRUE
	setmetatile 14, 1, METATILE_DHBWFLOORS_SecretDoor_BottomRight, TRUE
	return

HALLWAY_TO_SECRETARIAT_2_EventScript_HideSecretDoor_OnLoad::
	setmetatile 12, 0, METATILE_DHBWFLOORS_Wall_Top, TRUE
	setmetatile 13, 0, METATILE_DHBWFLOORS_Wall_Top, TRUE
	setmetatile 14, 0, METATILE_DHBWFLOORS_Wall_Top, TRUE
	setmetatile 12, 1, METATILE_DHBWFLOORS_Wall_Bottom, TRUE
	setmetatile 13, 1, METATILE_DHBWFLOORS_Wall_Bottom, TRUE
	setmetatile 14, 1, METATILE_DHBWFLOORS_Wall_Bottom, TRUE
	return

HALLWAY_TO_SECRETARIAT_2_EventScript_SecretDoor::
	lockall
	goto_if_set FLAG_SECRETARIAT_HIDDEN_DOOR_OPEN, HALLWAY_TO_SECRETARIAT_2_EventScript_DoorAlreadyOpen
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	call HALLWAY_TO_SECRETARIAT_2_EventScript_ShowSecretDoor_Runtime
	special DrawWholeMapView
	playse SE_DOOR
	setflag FLAG_SECRETARIAT_HIDDEN_DOOR_OPEN
	msgbox HALLWAY_TO_SECRETARIAT_2_Text_DoorRevealed, MSGBOX_DEFAULT
	releaseall
	end

HALLWAY_TO_SECRETARIAT_2_EventScript_ShowSecretDoor_Runtime::
	setmetatile 12, 0, METATILE_DHBWFLOORS_SecretDoor_TopLeft, FALSE
	setmetatile 13, 0, METATILE_DHBWFLOORS_SecretDoor_TopMid, FALSE
	setmetatile 14, 0, METATILE_DHBWFLOORS_SecretDoor_TopRight, FALSE
	setmetatile 12, 1, METATILE_DHBWFLOORS_SecretDoor_BottomLeft, FALSE
	setmetatile 13, 1, METATILE_DHBWFLOORS_SecretDoor_BottomMid, FALSE
	setmetatile 14, 1, METATILE_DHBWFLOORS_SecretDoor_BottomRight, FALSE
	return

HALLWAY_TO_SECRETARIAT_2_EventScript_DoorAlreadyOpen::
	msgbox HALLWAY_TO_SECRETARIAT_2_Text_DoorAlreadyOpen, MSGBOX_DEFAULT
	releaseall
	end

HALLWAY_TO_SECRETARIAT_2_EventScript_HintStudent::
	lock
	faceplayer
	msgbox HALLWAY_TO_SECRETARIAT_2_Text_HintStudent, MSGBOX_DEFAULT
	release
	end

HALLWAY_TO_SECRETARIAT_2_EventScript_TeleporterHouvert::
	lockall
	setvar VAR_TEMP_F, 1
	goto_if_set FLAG_CTF_HOUVERT_EXAM_FLASHBACK, HALLWAY_TO_SECRETARIAT_2_EventScript_TeleporterHouvertDisabled
	setvar VAR_TEMP_F, 0
	releaseall
	warpsilent MAP_HOUVERT_CLASS, 255, 9, 4
	end

HALLWAY_TO_SECRETARIAT_2_EventScript_TeleporterHouvertDisabled::
	msgbox HALLWAY_TO_SECRETARIAT_2_Text_TeleporterHouvertDisabled, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, HALLWAY_TO_SECRETARIAT_2_Movement_PlayerStepAwayFromTeleporter
	waitmovement 0
	setvar VAR_TEMP_F, 0
	releaseall
	end

HALLWAY_TO_SECRETARIAT_2_Text_DoorRevealed:
	.string "A hidden door slid open!$"

HALLWAY_TO_SECRETARIAT_2_Text_DoorAlreadyOpen:
	.string "The hidden door is already open.$"

HALLWAY_TO_SECRETARIAT_2_Text_HintStudent:
	.string "Random Guy: I've been through every classroom twice…\p"
	.string "but this hallway still feels off.\p"
	.string "It's a very secrete feeling?$"

HALLWAY_TO_SECRETARIAT_2_Text_PlayerRemembersHallway:
	.string "You: ...Right.\p"
	.string "This is where I enrolled.\p"
	.string "This is where I received my\n"
	.string "Registration Number.\p"
	.string "It's only a flashback... but it feels\n"
	.string "like I'm standing here again.$"

HALLWAY_TO_SECRETARIAT_2_Text_TeleporterHouvertDisabled:
	.string "Of course.\p"
	.string "I'm here to enroll.\p"
	.string "That's when I received it.\p"
	.string "I need to remember how it was generated.$"

HALLWAY_TO_SECRETARIAT_2_Movement_PlayerStepAwayFromTeleporter:
	walk_down
	step_end
