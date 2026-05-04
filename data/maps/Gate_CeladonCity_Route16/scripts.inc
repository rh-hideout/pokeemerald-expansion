Gate_CeladonCity_Route16_MapScripts::
	.byte 0

Gate_CeladonCity_Route16_TriggerScript::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0, Gate_CeladonCity_Route16_NoBike
	goto_if_set FLAG_SYS_CYCLING_ROAD, Gate_CeladonCity_Route16_ExitCyclingRoad
	goto_if_unset FLAG_SYS_CYCLING_ROAD, Gate_CeladonCity_Route16_EnterCyclingRoad

Gate_CeladonCity_Route16_NoBike::
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	clearflag FLAG_SYS_CYCLING_ROAD
	releaseall
	end

Gate_CeladonCity_Route16_EnterCyclingRoad::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	setflag FLAG_SYS_CYCLING_ROAD
	end

Gate_CeladonCity_Route16_ExitCyclingRoad::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	clearflag FLAG_SYS_CYCLING_ROAD
	end

