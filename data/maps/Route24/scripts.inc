.set LOCALID_ROUTE24_WOMAN, 4
.set LOCALID_ROUTE24_MAN, 3
.set LOCALID_ROUTE24_GRUNT, 1

Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 10, 28
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 10, 29
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement2 LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 FLAG_HIDE_CERULEAN_CAPE_ROCKET, Common_Movement_QuestionMark
	delay 50
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "Hey, kid! Me am a TEAM ROCKET\n"
	.string "member kind of guy!\p"
	.string "Come from another country, a\n"
	.string "trainer number one, me!\p"
	.string "Think I did, if stop the energy,\n"
	.string "be big panic for here people!\p"
	.string "Secret it is my mission, so tell\n"
	.string "you I not!\p"
	.string "But! If win you do versus me, a\n"
	.string "man I be and mine secret to you\l"
	.string "I tell.\p"
	.string "Hey, kid! Battle begin we do!$"

Route24_Text_RocketBeaten:
	.string "Ayieeeh! No, no, no, believe it\n"
	.string "I can't!\p"
	.string "Strong very much be you! Match\n"
	.string "I am not to you!$"

Route24_Text_RocketAfter:
	.string "OK. Tell you mine secret will I?\n"
	.string "MACHINE PART steal by me, hide it\l"
	.string "I did in GYM of the CERULEAN.\p"
	.string "Inside water put it I did. Look\n"
	.string "for in water center of GYM at.\p"
	.string "But you forget me not!\p"
	.string "Beat you for sure will TEAM\n"
	.string "ROCKET.\p"
	.string "Come from JOHTO will they, mine\n"
	.string "friends, yes. Will revenge they\l"
	.string "are.$"

Route24_Text_RocketDisappears:
	.string "…\p"
	.string "You say what? TEAM ROCKET bye-\n"
	.string "bye a go-go? Broken it is says\l"
	.string "you?\p"
	.string "Oh, no! Should I do what now on\n"
	.string "from, me?$"



Route24_Text_Woman:
	.string "Isn't it a lovely view?$"
Route24_Text_Man:
	.string "I could stay here all day.$"

Route24_Text_WomanRocket:
	.string "Nobody pushes me!$"
Route24_Text_ManRocket:
	.string "Nobody pushes my girlfriend!$"

Route24_Text_WomanAfterRocket:
	.string "What was that all about?$"
Route24_Text_ManAfterRocket:
	.string "Was that a ROCKET?$"
