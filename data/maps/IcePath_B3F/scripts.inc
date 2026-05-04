.set LOCALID_ICEPATH4_ICYWIND_SWINUB,2
.set LOCALID_ICEPATH4_ICYWIND_DELIBIRD, 1
.set LOCALID_ICEPATH4_STUCK_SWINUB, 4

IcePath_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_B3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath_B3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

IcePath_B3F_Trigger_Swinub_Jump::
	goto_if_set FLAG_DAY_POKEMON, IcePath_B3F_Trigger_Night
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	waitse
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playmoncry SPECIES_SWINUB, CRY_MODE_NORMAL
	applymovement LOCALID_ICEPATH4_STUCK_SWINUB, IcePath_B3F_Movement_StuckSwinubJump0
	waitmovement LOCALID_ICEPATH4_STUCK_SWINUB
	delay 20
	playse SE_LEDGE
	applymovement LOCALID_ICEPATH4_STUCK_SWINUB, IcePath_B3F_Movement_StuckSwinubJump
	waitmovement 0
	setobjectxyperm LOCALID_ICEPATH4_STUCK_SWINUB, 3, 19
	setobjectmovementtype LOCALID_ICEPATH4_STUCK_SWINUB, MOVEMENT_TYPE_FACE_DOWN
	setvar VAR_TEMP_0, 1
	end
IcePath_B3F_Trigger_Night::
	setvar VAR_TEMP_0, 1
	end

IcePath_B3F_EventScript_Swinub::
	lockall
	faceplayer
	playmoncry SPECIES_SWINUB, CRY_MODE_NORMAL
	msgbox IcePath_B3F_Text_Swinub, MSGBOX_DEFAULT
	waitmoncry
	goto_if_set FLAG_ITEM_ICEPATH4_TM_BLIZZARD, IcePath_B3F_EventScript_SwinubBlowPlayer
	msgbox IcePath_B3F_Text_SwinubBerry, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IcePath_B3F_EventScript_SwinubBlowPlayer
	chooseitem BERRIES_POCKET
	removeitem VAR_ITEM_ID, 1
	goto_if_ne VAR_ITEM_ID, ITEM_ASPEAR_BERRY, IcePath_B3F_EventScript_SwinubDislikedBerry
	msgbox IcePath_B3F_Text_SwinubAteBerry, MSGBOX_DEFAULT
	giveitem ITEM_TM_BLIZZARD
	setflag FLAG_ITEM_ICEPATH4_TM_BLIZZARD
IcePath_B3F_EventScript_SwinubBlowPlayer::
	closemessage
	playse SE_M_BLIZZARD
	setweather WEATHER_SNOW
	doweather
	call_if_eq VAR_FACING, DIR_SOUTH, IcePath_B3F_EventScript_SwinubBlowPlayerUp
	call_if_eq VAR_FACING, DIR_EAST, IcePath_B3F_EventScript_SwinubBlowPlayerLeft
	releaseall
	end
IcePath_B3F_EventScript_SwinubDislikedBerry::
	msgbox IcePath_B3F_Text_SwinubTurnedAway, MSGBOX_DEFAULT
	goto IcePath_B3F_EventScript_SwinubBlowPlayer

IcePath_B3F_EventScript_SwinubBlowPlayerUp::
	applymovement LOCALID_ICEPATH4_ICYWIND_SWINUB, IcePath_B3F_Movement_JumpUp
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_B3F_Movement_Player_BlownUp
	waitmovement 0
	return

IcePath_B3F_EventScript_SwinubBlowPlayerLeft::
	applymovement LOCALID_ICEPATH4_ICYWIND_SWINUB, IcePath_B3F_Movement_JumpLeft
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_B3F_Movement_Player_BlownLeft
	waitmovement 0
	return

IcePath_B3F_EventScript_Delibird::
	lockall
	faceplayer
	playmoncry SPECIES_DELIBIRD, CRY_MODE_NORMAL
	msgbox IcePath_B3F_Text_Delibird, MSGBOX_DEFAULT
	waitmoncry
	goto_if_set FLAG_ITEM_ICEPATH4_TM_BLIZZARD, IcePath_B3F_EventScript_DelibirdBlowPlayer
	msgbox IcePath_B3F_Text_DelibirdBerry, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IcePath_B3F_EventScript_DelibirdBlowPlayer
	chooseitem BERRIES_POCKET
	removeitem VAR_ITEM_ID, 1
	goto_if_ne VAR_ITEM_ID, ITEM_ASPEAR_BERRY, IcePath_B3F_EventScript_DelibirdDislikedBerry
	msgbox IcePath_B3F_Text_DelibirdAteBerry, MSGBOX_DEFAULT
	giveitem ITEM_TM_BLIZZARD
	setflag FLAG_ITEM_ICEPATH4_TM_BLIZZARD
IcePath_B3F_EventScript_DelibirdBlowPlayer::
	closemessage
	playse SE_M_BLIZZARD
	setweather WEATHER_SNOW
	doweather
	call_if_eq VAR_FACING, DIR_SOUTH, IcePath_B3F_EventScript_DelibirdBlowPlayerUp
	call_if_eq VAR_FACING, DIR_EAST, IcePath_B3F_EventScript_DelibirdBlowPlayerLeft
	releaseall
	end
IcePath_B3F_EventScript_DelibirdDislikedBerry::
	msgbox IcePath_B3F_Text_DelibirdTurnedAway, MSGBOX_DEFAULT
	goto IcePath_B3F_EventScript_DelibirdBlowPlayer

IcePath_B3F_EventScript_DelibirdBlowPlayerUp::
	applymovement LOCALID_ICEPATH4_ICYWIND_DELIBIRD, IcePath_B3F_Movement_JumpUp
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_B3F_Movement_Player_BlownUp
	waitmovement 0
	return

IcePath_B3F_EventScript_DelibirdBlowPlayerLeft::
	applymovement LOCALID_ICEPATH4_ICYWIND_DELIBIRD, IcePath_B3F_Movement_JumpLeft
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_B3F_Movement_Player_BlownLeft
	waitmovement 0
	return

IcePath_B3F_Movement_Player_BlownUp:
	lock_facing_direction
	walk_up
	walk_up
	unlock_facing_direction
	step_end

IcePath_B3F_Movement_Player_BlownLeft:
	lock_facing_direction
	walk_left
	walk_left
	unlock_facing_direction
	step_end

IcePath_B3F_Movement_JumpUp:
	jump_in_place_up
	step_end

IcePath_B3F_Movement_JumpLeft:
	jump_in_place_left
	step_end

IcePath_B3F_Movement_StuckSwinubJump0:
	jump_in_place_up
	step_end

IcePath_B3F_Movement_StuckSwinubJump:
	jump_2_up
	jump_in_place_left_right
	jump_in_place_left_right
	face_left
	step_end

IcePath_B3F_Text_Swinub:
	.string "SWINUB: Swiiiiii!$"
IcePath_B3F_Text_SwinubBerry:
	.string "Give the SWINUB a BERRY?$"
IcePath_B3F_Text_SwinubAteBerry:
	.string "SWINUB enjoyed the ASPEAR BERRY!$"
IcePath_B3F_Text_SwinubTurnedAway:
	.string "SWINUB doesn't like it!$"

IcePath_B3F_Text_Delibird:
	.string "DELIBIRD: SKWAAAAA!$"
IcePath_B3F_Text_DelibirdBerry:
	.string "Give the DELIBIRD a BERRY?$"
IcePath_B3F_Text_DelibirdAteBerry:
	.string "DELIBIRD enjoyed the ASPEAR BERRY!$"
IcePath_B3F_Text_DelibirdTurnedAway:
	.string "DELIBIRD doesn't like it!$"
