.set LOCALID_MTMOON_JIRACHI, 9

MtMoon_Outside_MapScripts::
	.byte 0

MtMoon_EventScript_Moonstone::
	finditem ITEM_MOON_STONE
	end

MtMoon_Outside_EventScript_Sign::
	msgbox MtMoon_Outside_Text_DontLitterSign, MSGBOX_SIGN
	end

MtMoon_Outside_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox MtMoon_Outside_Text_Clefairy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MtMoon_Outside_EventScript_WhiteRock::
	lock
	msgbox MtMoon_Outside_Text_WhiteRockTouchIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MtMoon_Outside_EventScript_WhiteRockNoOp
	goto_if_set FLAG_SUMMONED_MTMOON_JIRACHI, MtMoon_OutsideEventScript_WhiteRockNoReaction
	goto_if_unset FLAG_NIGHT_POKEMON, MtMoon_Outside_EventScript_WhiteRockSpawnJirachi
MtMoon_OutsideEventScript_WhiteRockNoReaction::
	msgbox MtMoon_Outside_Text_WhiteRockTouchDay, MSGBOX_DEFAULT
	closemessage
	release
	end

MtMoon_Outside_EventScript_WhiteRockNoOp::
	release
	end

MtMoon_Outside_EventScript_WhiteRockSpawnJirachi::
	msgbox MtMoon_Outside_Text_WhiteRockTouchNight, MSGBOX_DEFAULT
	playse SE_M_SELF_DESTRUCT
	waitse
	closemessage
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playse SE_M_GUST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	delay 60
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	delay 30
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_M_GUST2
	waitse
	playse SE_M_EXPLOSION
	fadescreenswapbuffers FADE_TO_WHITE
	clearflag FLAG_HIDE_MTMOON_JIRACHI
	setflag FLAG_SUMMONED_MTMOON_JIRACHI
	addobject LOCALID_MTMOON_JIRACHI
	waitse
	delay 70
	fadescreenswapbuffers FADE_FROM_WHITE
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, MtMoon_Outside_Movement_CameraPanDown
	waitmovement 0
	applymovement2 LOCALID_MTMOON_JIRACHI, MtMoon_Outside_Movement_Jirachi
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
	applymovement2 OBJ_EVENT_ID_CAMERA, MtMoon_Outside_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	release
	end

MtMoon_Outside_Movement_CameraPanDown:
	walk_down
	walk_down
	step_end

MtMoon_Outside_Movement_CameraPanUp:
	walk_up
	walk_up
	step_end

MtMoon_Outside_Movement_Jirachi:
	jump_in_place_down
	jump_in_place_down
	step_end

MtMoon_Outside_Text_WhiteRockTouchIt:
	.string "An unusual white rock.\n"
	.string "The color reminds you of the moon.\p"
	.string "Touch it?$"

MtMoon_Outside_Text_WhiteRockTouchDay:
	.string "{PLAYER} touched the unusual rock.\n"
	.string "..........................\l"
	.string "..........................\l"
	.string "But nothing happened.$"

MtMoon_Outside_Text_WhiteRockTouchNight:
	.string "{PLAYER} touched the unusual rock.\n"
	.string "..........................\l"
	.string "..........................$"

MtMoon_Outside_EventScript_Jirachi::
	lock
	faceplayer
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	msgbox MtMoon_Outside_Text_Jirachi
	delay 40
	waitmoncry
	seteventmon SPECIES_JIRACHI, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtMoon_Outside_EventScript_JirachiRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MTMOON_JIRACHI
	setflag FLAG_HIDE_MTMOON_JIRACHI
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtMoon_Outside_EventScript_JirachiRan::
	release
	end


MtMoon_Outside_Text_DontLitterSign:
	.string "MT.MOON SQUARE\n"
	.string "DON'T LITTER$"

MtMoon_Outside_Text_Jirachi:
    .string "JIRACHI: Chi!$"

MtMoon_Outside_Text_Clefairy:
    .string "CLEFAIRY: Pi pippippi!$"

