.set LOCALID_ROUTE42_EUSINE, 19
.set LOCALID_ROUTE42_SUICUNE, 17

Route42_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route42_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route42_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route42_MapScript_HideTrigger::
	setvar VAR_TEMP_0, 1
	return

Route42_EventScript_Suicune_Trigger::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0

	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune3
	applymovement OBJ_EVENT_ID_PLAYER, Route42_Movement_Player
	playse SE_LEDGE
	delay 60
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement LOCALID_ROUTE42_SUICUNE
	waitmovement 0
	delay 60
	removeobject LOCALID_ROUTE42_SUICUNE
	setflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_HIDE_ROUTE42_EUSINE
	addobject LOCALID_ROUTE42_EUSINE
	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine1
	waitmovement 0
	msgbox Route42_Text_EusineAdmireSuicune, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE42_EUSINE, DIR_WEST
	msgbox Route42_Text_EusineJealous, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE42_EUSINE, DIR_EAST
	msgbox Route42_Text_EusineWontGiveUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine2
	waitmovement 0
	setflag FLAG_HIDE_ROUTE42_EUSINE
	removeobject LOCALID_ROUTE42_EUSINE
	setvar VAR_TEMP_0, 1
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 2, Route42_EventScript_DoneJohtoSuicune
	release
	end

Route42_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

Route42_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	step_end

Route42_Movement_Suicune2:
	jump_2_left
	jump_2_left
	jump_2_left
	jump_2_up
	step_end

Route42_Movement_Suicune3:
	jump_in_place_up
	delay_2
	face_up
	jump_2_up
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

Route42_Movement_Player:
	lock_facing_direction
	delay_2
	jump_2_up
	unlock_facing_direction
	step_end

Route42_Movement_Eusine1:
	walk_down
	walk_down
	walk_left
	face_right
	step_end

Route42_Movement_Eusine2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route42_Text_EusineAdmireSuicune:
	.string "EUSINE: SUICUNE...\n"
	.string "How brave it is!\p"
	.string "How refreshing it is!\n"
	.string "How beautiful it is!\p"
	.string "And how quickly it moves!$"

Route42_Text_EusineJealous:
	.string "{PLAYER}!\p"
	.string "You seem to be around where\n"
	.string "SUICUNE would appear.\p"
	.string "Well, that's OK.\l"
	.string "My desire to search for\n"
	.string "SUICUNE is far beyond yours...\p"
	.string "My grandpa was... quite into\n"
	.string "myths.\p"
	.string "I've heard so many stories\n"
	.string "about SUICUNE from him.$"

Route42_Text_EusineWontGiveUp:
	.string "SUICUNE...\n"
	.string "I won't stop following you\l"
	.string "until I've found out what\l"
	.string "you're after...\p"
	.string "You hear me!$"


Route42_EventScript_Tully::
	trainerbattle_single TRAINER_TULLY Route42_Text_FisherTullySeen, Route42_Text_FisherTullyBeaten
	msgbox Route42_Text_FisherTullyAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Ben::
	trainerbattle_single TRAINER_BENJAMIN Route42_Text_HikerBenjaminSeen, Route42_Text_HikerBenjaminBeaten
	msgbox Route42_Text_HikerBenjaminAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE Route42_Text_PokemaniacShaneSeen, Route42_Text_PokemaniacShaneBeaten
	msgbox Route42_Text_PokemaniacShaneAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign::
	lock
	msgbox Route42_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_MortarSign::
	lock
	msgbox Route42_Text_MtMortarSign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end
Route42_EventScript_Item_Mint::
	finditem ITEM_MODEST_MINT
	end
Route42_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route42_Text_FisherTullySeen:
	.string "Let me demonstrate the power\n"
	.string "of the POKéMON I caught!$"

Route42_Text_FisherTullyBeaten:
	.string "What? That's not right.\n"
	.string "I can't believe this!$"

Route42_Text_FisherTullyAfter:
	.string "I want to become the trainer\n"
	.string "CHAMP using the POKéMON I\l"
	.string "caught myself.\p"
	.string "That's the best part of fishing!$"

Route42_Text_HikerBenjaminSeen:
	.string "Ah, it's good to be outside!\n"
	.string "I feel so free!$"

Route42_Text_HikerBenjaminBeaten:
	.string "Gahahah! That was a good\n"
	.string "battle!$"

Route42_Text_HikerBenjaminAfter:
	.string "Losing feels insignificant\n"
	.string "if you look up at the big sky!$"

Route42_Text_PokemaniacShaneSeen:
	.string "HEY!\p"
	.string "This is my secret place!\n"
	.string "Get lost, you outsider!$"

Route42_Text_PokemaniacShaneBeaten:
	.string "I should have used my\n"
	.string "MOON STONE…$"

Route42_Text_PokemaniacShaneAfter:
	.string "You're working on a POKéDEX?\p"
	.string "Wow, you must know some\n"
	.string "pretty rare POKéMON!\p"
	.string "May I please see it?\n"
	.string "Please?$"

Route42_Text_Sign1:
	.string "ROUTE 42\p"
	.string "ECRUTEAK CITY - MAHOGANY TOWN$"

Route42_Text_MtMortarSign1:
	.string "MT.MORTAR\p"
	.string "WATERFALL CAVE INSIDE$"
