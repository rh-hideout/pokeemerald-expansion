.set LOCALID_BURNEDTOWER_ENTEI, 1
.set LOCALID_BURNEDTOWER_RAIKOU, 2
.set LOCALID_BURNEDTOWER_SUICUNE, 3
.set LOCALID_BURNEDTOWER2_EUSINE, 11

BurnedTower_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE,BurnedTower_B1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_B1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 3, BurnedTower_B1F_EventScript_ReleaseBeasts
	.2byte 0

BurnedTower_B1F_EventScript_ReleaseBeasts::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 60

	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
	applymovement LOCALID_BURNEDTOWER_ENTEI, BurnedTower_B1F_Movement_AwakenBeasts
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0

	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
	applymovement LOCALID_BURNEDTOWER_RAIKOU, BurnedTower_B1F_Movement_AwakenBeasts
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0

	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_BURNEDTOWER_SUICUNE, BurnedTower_B1F_Movement_AwakenBeasts
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0

	
	applymovement LOCALID_BURNEDTOWER_ENTEI, BurnedTower_B1F_Movement_EnteiLeave
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

	applymovement LOCALID_BURNEDTOWER_RAIKOU, BurnedTower_B1F_Movement_RaikouLeave
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

	applymovement LOCALID_BURNEDTOWER_SUICUNE, BurnedTower_B1F_Movement_SuicuneLeave
	delay 30
	playse SE_LEDGE
	delay 30
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitse
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement 0
	
	setflag FLAG_HIDE_BURNED_TOWER_BEASTS
	removeobject LOCALID_BURNEDTOWER_ENTEI
	removeobject LOCALID_BURNEDTOWER_RAIKOU
	removeobject LOCALID_BURNEDTOWER_SUICUNE
	delay 55

	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_BURNEDTOWER2_EUSINE, BurnedTower_B1F_Movement_EusineEnter
	waitmovement 0
	msgbox BurnedTowerB1FEusineText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNEDTOWER2_EUSINE, BurnedTower_B1F_Movement_EusineLeave
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	removeobject LOCALID_BURNEDTOWER2_EUSINE
	setflag FLAG_HIDE_BURNED_TOWER_NPCS
	setflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	setvar VAR_0x8004, 1
	special InitRoamer
	setflag FLAG_RELEASED_BEASTS
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	release
	end

BurnedTower_B1F_Movement_AwakenBeasts:
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	step_end

BurnedTower_B1F_Movement_EnteiLeave:
	jump_down
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

BurnedTower_B1F_Movement_RaikouLeave:
	jump_down
	jump_2_left
	jump_2_left
	jump_2_left
	jump_2_left
	step_end

BurnedTower_B1F_Movement_SuicuneLeave:
	jump_2_down
	delay_8
	jump_in_place_right_left
	jump_in_place_right_left
	jump_left
	jump_2_down
	jump_2_down
	jump_2_down
	step_end

BurnedTower_B1F_Movement_EusineEnter:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

BurnedTower_B1F_Movement_EusineLeave:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

BurnedTowerB1FEusineText:
	.string "EUSINE: I'm shocked!\p"
	.string "SUICUNE raced by like a blur,\n"
	.string "right in front of my eyes!\p"
	.string "For ten years I chased\n"
	.string "SUICUNE, and I finally got to\l"
	.string "see it.\p"
	.string "I'm all choked up!\p"
	.string "{PLAYER}, I owe this all to you!\p"
	.string "Thank you!\p"
	.string "I heard that the legendary\n"
	.string "POKéMON of ECRUTEAK test\l"
	.string "chosen humans by allowing them\l"
	.string "to get close.\p"
	.string "I'm going to track SUICUNE.\p"
	.string "{PLAYER}, let's meet again!\p"
	.string "Farewell!$"


BurnedTower_B1F_EventScript_Item_Taunt::
	finditem ITEM_TM_TAUNT
	end

BurnedTower_B1F_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

