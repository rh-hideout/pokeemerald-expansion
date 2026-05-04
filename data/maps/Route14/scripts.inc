.set LOCALID_ROUTE14_SUICUNE, 5
.set LOCALID_ROUTE14_EUSINE, 6
.set LOCALID_ROUTE14_PIDGEOTTO, 9

Route14_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route14_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route14_TriggerSuicune_5::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_5
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_4::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_4
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_3::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_3
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_2::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_1::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	goto Route14_EventScript_Suicune

Route14_Movement_5:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_4:
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_3:
	walk_right
	walk_right
	step_end

Route14_EventScript_Suicune::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE14_SUICUNE, Route14_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE14_EUSINE
	addobject LOCALID_ROUTE14_EUSINE
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineEnter
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 0
	msgbox Route14_Text_Eusine, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineLeave
	waitmovement 0
	setflag FLAG_HIDE_ROUTE14_EUSINE
	setflag FLAG_HIDE_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 5
	call_if_ge VAR_CERULEAN_CITY_STATE, 3, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

Route14_Movement_SuicuneLeave:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	step_end

Route14_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_slow_up
	walk_slow_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	walk_slow_right
	step_end

Route14_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER Route14_Text_PokefanmCarterSeen, Route14_Text_PokefanmCarterBeaten
	msgbox Route14_Text_PokefanmCarterAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Roy::
	trainerbattle_single TRAINER_ROY Route14_Text_BirdKeeperRoySeen, Route14_Text_BirdKeeperRoyBeaten
	msgbox Route14_Text_BirdKeeperRoyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Trevor::
	trainerbattle_single TRAINER_TREVOR Route14_Text_PokefanmTrevorSeen, Route14_Text_PokefanmTrevorBeaten
	msgbox Route14_Text_PokefanmTrevorAfterBattle, MSGBOX_AUTOCLOSE
	end



Route14_Text_Eusine:
	.string "EUSINE: {PLAYER}! Not again!\n"
	.string "I'll be there first next time!\p"
	.string "Having followed it here, I'm\n"
	.string "starting to understand what SUICUNE\l"
	.string "is after.\p"
	.string "To be honest, I would like to keep\n"
	.string "this information to myself.\p"
	.string "But I want to be an honest trainer\n"
	.string "in front of SUICUNE!\p"
	.string "That's why I am sharing a clue with\n"
	.string "you.\p"
	.string "It seems that...\n"
	.string "SUICUNE prefers a hilly place...\l"
	.string "Near water...\l"
	.string "Somewhere north...\p"
	.string "I don't know exactly where yet.\n"
	.string "It will just be you and me!\p"
	.string "Who'll find it first?\n"
	.string "I challenge you!$"

Route14_Text_PokefanmCarterSeen:
	.string "Let me tell you, I had a hard time\n"
	.string "catching my prized POKéMON.$"

Route14_Text_PokefanmCarterBeaten:
	.string "Awaaah!$"

Route14_Text_PokefanmCarterAfterBattle:
	.string "TOTODILE, CYNDAQUIL, CHIKORITA…\p"
	.string "I think that's a well-balanced mix.$"

Route14_Text_BirdKeeperRoySeen:
	.string "My dream is to fly with my beloved\n"
	.string "bird POKéMON.$"

Route14_Text_BirdKeeperRoyBeaten:
	.string "I can dream, but I can't ever fly…$"

Route14_Text_BirdKeeperRoyAfterBattle:
	.string "You have POKéMON that know the HM\n"
	.string "move FLY, don't you? I envy you.$"

Route14_Text_PokefanmTrevorSeen:
	.string "Hi. Did you know…?\p"
	.string "POKéMON get more friendly if you\n"
	.string "train them in a place that they\l"
	.string "remember.$"

Route14_Text_PokefanmTrevorBeaten:
	.string "Where did I meet this SCIZOR?$"

Route14_Text_PokefanmTrevorAfterBattle:
	.string "If only there were an easy way to\n"
	.string "identify where I got my POKéMON…$"

Route14_EventScript_Pidgeotto::
	lockall
	faceplayer
	playmoncry SPECIES_PIDGEOTTO, CRY_MODE_NORMAL
	msgbox Route14_Text_Pidgeotto, MSGBOX_DEFAULT
	waitmoncry
	goto_if_set FLAG_GOT_ROUTE_14_AERIAL_ACE, Route14_EventScript_PidgeottoBlowPlayer
	msgbox Route14_Text_PidgeottoBerry, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route14_EventScript_PidgeottoBlowPlayer
	chooseitem BERRIES_POCKET
	removeitem VAR_ITEM_ID, 1
	goto_if_ne VAR_ITEM_ID, ITEM_QUALOT_BERRY, Route14_EventScript_PidgeottoDislikedBerry
	msgbox Route14_Text_PidgeottoAteBerry, MSGBOX_DEFAULT
	giveitem ITEM_TM_AERIAL_ACE
	setflag FLAG_GOT_ROUTE_14_AERIAL_ACE
Route14_EventScript_PidgeottoBlowPlayer::
	closemessage
	playse SE_M_TWISTER
	call_if_eq VAR_FACING, DIR_EAST, Route14_EventScript_PidgeottoBlowPlayerLeft
	releaseall
	end
Route14_EventScript_PidgeottoDislikedBerry::
	msgbox Route14_Text_PidgeottoTurnedAway, MSGBOX_DEFAULT
	goto Route14_EventScript_PidgeottoBlowPlayer

Route14_EventScript_PidgeottoBlowPlayerLeft::
	applymovement LOCALID_ROUTE14_PIDGEOTTO, Route14_Movement_JumpLeft
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_Player_BlownLeft
	waitmovement 0
	return

Route14_Movement_Player_BlownUp:
	lock_facing_direction
	walk_up
	walk_up
	unlock_facing_direction
	step_end

Route14_Movement_Player_BlownLeft:
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	lock_facing_direction
	walk_left
	walk_left
	unlock_facing_direction
	step_end

Route14_Movement_JumpUp:
	jump_in_place_up
	step_end

Route14_Movement_JumpLeft:
	jump_in_place_left
	step_end

Route14_Movement_StuckPidgeottoJump0:
	jump_in_place_up
	step_end

Route14_Movement_StuckPidgeottoJump:
	jump_2_up
	jump_in_place_left_right
	jump_in_place_left_right
	face_left
	step_end

Route14_Text_Pidgeotto:
	.string "PIDGEOTTO: Kaaaaa!$"
Route14_Text_PidgeottoBerry:
	.string "Give the PIDGEOTTO a BERRY?$"
Route14_Text_PidgeottoAteBerry:
	.string "PIDGEOTTO enjoyed the QUALOT BERRY!$"
Route14_Text_PidgeottoTurnedAway:
	.string "PIDGEOTTO doesn't like it!$"

