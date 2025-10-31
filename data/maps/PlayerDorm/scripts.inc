PlayerDorm_MapScripts::
# 2 "data/maps/PlayerDorm/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerDorm_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerDorm_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/PlayerDorm/scripts.pory"
	map_script_2 VAR_PLAYERDORM_STATE, 0, PlayerDorm_WakeUp
	.2byte 0


PlayerDorm_WakeUp::
# 13 "data/maps/PlayerDorm/scripts.pory"
	lockall
# 14 "data/maps/PlayerDorm/scripts.pory"
	hideobjectat LOCALID_TRACIE, MAP_PLAYER_DORM
# 15 "data/maps/PlayerDorm/scripts.pory"
	speakername Unknown
# 16 "data/maps/PlayerDorm/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerDorm_WakeUp_Movement_0
# 17 "data/maps/PlayerDorm/scripts.pory"
	delay 80
# 18 "data/maps/PlayerDorm/scripts.pory"
	call Player_Dorm_Door_Knocking
# 19 "data/maps/PlayerDorm/scripts.pory"
	delay 40
# 20 "data/maps/PlayerDorm/scripts.pory"
	msgbox PlayerDorm_WakeUp_Text_0, MSGBOX_DEFAULT
# 21 "data/maps/PlayerDorm/scripts.pory"
	closemessage
# 22 "data/maps/PlayerDorm/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 23 "data/maps/PlayerDorm/scripts.pory"
	delay 80
# 24 "data/maps/PlayerDorm/scripts.pory"
	call Player_Dorm_Door_Knocking
# 25 "data/maps/PlayerDorm/scripts.pory"
	delay 20
# 26 "data/maps/PlayerDorm/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerDorm_WakeUp_Movement_1
# 27 "data/maps/PlayerDorm/scripts.pory"
	playse SE_PIN
# 28 "data/maps/PlayerDorm/scripts.pory"
	waitse
# 29 "data/maps/PlayerDorm/scripts.pory"
	delay 60
# 30 "data/maps/PlayerDorm/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerDorm_WakeUp_Movement_2
# 31 "data/maps/PlayerDorm/scripts.pory"
	playse SE_LEDGE
# 32 "data/maps/PlayerDorm/scripts.pory"
	waitse
# 33 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 34 "data/maps/PlayerDorm/scripts.pory"
	call Player_Dorm_Enter_Tracie
	return


Player_Dorm_Door_Knocking::
# 38 "data/maps/PlayerDorm/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 39 "data/maps/PlayerDorm/scripts.pory"
	waitse
# 40 "data/maps/PlayerDorm/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 41 "data/maps/PlayerDorm/scripts.pory"
	waitse
# 42 "data/maps/PlayerDorm/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 43 "data/maps/PlayerDorm/scripts.pory"
	waitse
	return


Player_Dorm_Enter_Tracie::
# 48 "data/maps/PlayerDorm/scripts.pory"
	playse SE_DOOR
# 49 "data/maps/PlayerDorm/scripts.pory"
	showobjectat LOCALID_TRACIE, MAP_PLAYER_DORM
# 50 "data/maps/PlayerDorm/scripts.pory"
	applymovement LOCALID_TRACIE, Player_Dorm_Enter_Tracie_Movement_0
# 51 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 52 "data/maps/PlayerDorm/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Dorm_Enter_Tracie_Movement_1
# 53 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 54 "data/maps/PlayerDorm/scripts.pory"
	playbgm MUS_LILYCOVE_MUSEUM, TRUE
# 55 "data/maps/PlayerDorm/scripts.pory"
	delay 40
# 56 "data/maps/PlayerDorm/scripts.pory"
	speakername Tracie
# 57 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_Enter_Tracie_Text_0
# 58 "data/maps/PlayerDorm/scripts.pory"
	closemessage
# 59 "data/maps/PlayerDorm/scripts.pory"
	applymovement LOCALID_TRACIE, Player_Dorm_Tracie_Approach
# 60 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 61 "data/maps/PlayerDorm/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Dorm_Enter_Tracie_Movement_2
# 62 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 63 "data/maps/PlayerDorm/scripts.pory"
	speakername Tracie
# 64 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_Enter_Tracie_Text_1
# 65 "data/maps/PlayerDorm/scripts.pory"
	closemessage
# 66 "data/maps/PlayerDorm/scripts.pory"
	applymovement LOCALID_TRACIE, Player_Dorm_Enter_Tracie_Movement_3
# 67 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 68 "data/maps/PlayerDorm/scripts.pory"
	speakername Tracie
# 69 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_Enter_Tracie_Text_2
# 70 "data/maps/PlayerDorm/scripts.pory"
	closemessage
# 71 "data/maps/PlayerDorm/scripts.pory"
	applymovement LOCALID_TRACIE, Player_Dorm_Enter_Tracie_Movement_4
# 72 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 73 "data/maps/PlayerDorm/scripts.pory"
	speakername Tracie
# 74 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_Enter_Tracie_Text_3
# 75 "data/maps/PlayerDorm/scripts.pory"
	closemessage
# 76 "data/maps/PlayerDorm/scripts.pory"
	applymovement LOCALID_TRACIE, Player_Dorm_Tracie_Leaves
# 77 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 78 "data/maps/PlayerDorm/scripts.pory"
	hideobjectat LOCALID_TRACIE, MAP_PLAYER_DORM
# 79 "data/maps/PlayerDorm/scripts.pory"
	playse SE_EXIT
# 80 "data/maps/PlayerDorm/scripts.pory"
	removeobject LOCALID_TRACIE
# 81 "data/maps/PlayerDorm/scripts.pory"
	setflag FLAG_HIDE_TRACIE
# 82 "data/maps/PlayerDorm/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 83 "data/maps/PlayerDorm/scripts.pory"
	setvar VAR_PLAYERDORM_STATE, 1
# 84 "data/maps/PlayerDorm/scripts.pory"
	releaseall
	end


# 88 "data/maps/PlayerDorm/scripts.pory"
Player_Dorm_Tracie_Approach:
# 89 "data/maps/PlayerDorm/scripts.pory"
	walk_up
# 89 "data/maps/PlayerDorm/scripts.pory"
	walk_up
# 89 "data/maps/PlayerDorm/scripts.pory"
	walk_up
# 90 "data/maps/PlayerDorm/scripts.pory"
	walk_left
# 90 "data/maps/PlayerDorm/scripts.pory"
	walk_left
# 90 "data/maps/PlayerDorm/scripts.pory"
	walk_left
	step_end

# 93 "data/maps/PlayerDorm/scripts.pory"
Player_Dorm_Tracie_Leaves:
# 94 "data/maps/PlayerDorm/scripts.pory"
	walk_fast_right
# 94 "data/maps/PlayerDorm/scripts.pory"
	walk_fast_right
# 94 "data/maps/PlayerDorm/scripts.pory"
	walk_fast_right
# 95 "data/maps/PlayerDorm/scripts.pory"
	walk_fast_down
# 95 "data/maps/PlayerDorm/scripts.pory"
	walk_fast_down
# 95 "data/maps/PlayerDorm/scripts.pory"
	walk_fast_down
	step_end

Player_Dorm_Take_Eevee::
# 99 "data/maps/PlayerDorm/scripts.pory"
	setvar VAR_PLAYERDORM_STATE, 2
# 100 "data/maps/PlayerDorm/scripts.pory"
	givemon SPECIES_EEVEE, 10, ITEM_ORAN_BERRY
# 101 "data/maps/PlayerDorm/scripts.pory"
	removeobject LOCALID_EEVEE
# 102 "data/maps/PlayerDorm/scripts.pory"
	updatefollowingmon
# 103 "data/maps/PlayerDorm/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 104 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_Take_Eevee_Text_0
# 105 "data/maps/PlayerDorm/scripts.pory"
	waitfanfare
# 106 "data/maps/PlayerDorm/scripts.pory"
	setflag FLAG_TAKE_EEVEE
# 107 "data/maps/PlayerDorm/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 108 "data/maps/PlayerDorm/scripts.pory"
	call Player_Dorm_Nickname_Eevee
# 109 "data/maps/PlayerDorm/scripts.pory"
	release
	end


Player_Dorm_Nickname_Eevee::
# 114 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_Nickname_Eevee_Text_0, MSGBOX_YESNO
# 115 "data/maps/PlayerDorm/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Player_Dorm_Nickname_Eevee_2
Player_Dorm_Nickname_Eevee_1:
	return

Player_Dorm_Nickname_Eevee_2:
# 116 "data/maps/PlayerDorm/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 117 "data/maps/PlayerDorm/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto Player_Dorm_Nickname_Eevee_1


Player_Dorm_EventScript_CheckPlayersPC::
# 123 "data/maps/PlayerDorm/scripts.pory"
	setvar VAR_0x8004, 1
# 124 "data/maps/PlayerDorm/scripts.pory"
	special DoPCTurnOnEffect
# 125 "data/maps/PlayerDorm/scripts.pory"
	playse SE_PC_ON
# 126 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_EventScript_CheckPlayersPC_Text_0, MSGBOX_DEFAULT
# 127 "data/maps/PlayerDorm/scripts.pory"
	special BedroomPC
# 128 "data/maps/PlayerDorm/scripts.pory"
	waitstate
# 129 "data/maps/PlayerDorm/scripts.pory"
	releaseall
	end


Player_Dorm_Trigger_CantLeave::
# 134 "data/maps/PlayerDorm/scripts.pory"
	lock
# 135 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_Trigger_CantLeave_Text_0
# 136 "data/maps/PlayerDorm/scripts.pory"
	closemessage
# 137 "data/maps/PlayerDorm/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Dorm_Enter_Tracie_Movement_0
# 138 "data/maps/PlayerDorm/scripts.pory"
	waitmovement 0
# 139 "data/maps/PlayerDorm/scripts.pory"
	release
	end


Player_Dorm_NintendoSwitch::
# 144 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_NintendoSwitch_Text_0
# 145 "data/maps/PlayerDorm/scripts.pory"
	release
	end


Player_Dorm_Drawers::
# 150 "data/maps/PlayerDorm/scripts.pory"
	msgbox Player_Dorm_Drawers_Text_0
# 151 "data/maps/PlayerDorm/scripts.pory"
	release
	end


EventScript_New_TV::
# 156 "data/maps/PlayerDorm/scripts.pory"
	msgbox EventScript_New_TV_Text_0
# 157 "data/maps/PlayerDorm/scripts.pory"
	release
	end


# 16 "data/maps/PlayerDorm/scripts.pory"
PlayerDorm_WakeUp_Movement_0:
# 16 "data/maps/PlayerDorm/scripts.pory"
	face_left
	step_end

# 26 "data/maps/PlayerDorm/scripts.pory"
PlayerDorm_WakeUp_Movement_1:
# 26 "data/maps/PlayerDorm/scripts.pory"
	face_down
# 26 "data/maps/PlayerDorm/scripts.pory"
	emote_exclamation_mark
	step_end

# 30 "data/maps/PlayerDorm/scripts.pory"
PlayerDorm_WakeUp_Movement_2:
# 30 "data/maps/PlayerDorm/scripts.pory"
	jump_right
	step_end

# 50 "data/maps/PlayerDorm/scripts.pory"
Player_Dorm_Enter_Tracie_Movement_0:
# 50 "data/maps/PlayerDorm/scripts.pory"
	walk_up
	step_end

# 52 "data/maps/PlayerDorm/scripts.pory"
Player_Dorm_Enter_Tracie_Movement_1:
# 52 "data/maps/PlayerDorm/scripts.pory"
	face_down
	step_end

# 61 "data/maps/PlayerDorm/scripts.pory"
Player_Dorm_Enter_Tracie_Movement_2:
# 61 "data/maps/PlayerDorm/scripts.pory"
	face_right
	step_end

# 66 "data/maps/PlayerDorm/scripts.pory"
Player_Dorm_Enter_Tracie_Movement_3:
# 66 "data/maps/PlayerDorm/scripts.pory"
	walk_right
# 66 "data/maps/PlayerDorm/scripts.pory"
	walk_right
	step_end

# 71 "data/maps/PlayerDorm/scripts.pory"
Player_Dorm_Enter_Tracie_Movement_4:
# 71 "data/maps/PlayerDorm/scripts.pory"
	walk_fast_left
# 71 "data/maps/PlayerDorm/scripts.pory"
	walk_fast_left
	step_end

PlayerDorm_WakeUp_Text_0:
# 20 "data/maps/PlayerDorm/scripts.pory"
	.string "Hello…? {PLAYER}?\p"
	.string "{PLAYER}, are you there?$"

Player_Dorm_Enter_Tracie_Text_0:
# 57 "data/maps/PlayerDorm/scripts.pory"
	.string "Ugh! Seriously?$"

Player_Dorm_Enter_Tracie_Text_1:
# 64 "data/maps/PlayerDorm/scripts.pory"
	.string "You're sleeping right now?\n"
	.string "Today of all days?\p"
	.string "Come on! You didn't actually\n"
	.string "forget, did you?\p"
	.string "Our senior orientation is today!\n"
	.string "I can't believe you!\p"
	.string "We've been dreaming of this day since\n"
	.string "we were kids!$"

Player_Dorm_Enter_Tracie_Text_2:
# 69 "data/maps/PlayerDorm/scripts.pory"
	.string "I can’t believe it…\n"
	.string "Me… Tracie!\p"
	.string "Soon to be grad and official Pokémon\n"
	.string "Trainer!$"

Player_Dorm_Enter_Tracie_Text_3:
# 74 "data/maps/PlayerDorm/scripts.pory"
	.string "Well, what are we waiting for!?\p"
	.string "Grab Eevee and let's go!\n"
	.string "I'm so excited!$"

Player_Dorm_Take_Eevee_Text_0:
# 104 "data/maps/PlayerDorm/scripts.pory"
	.string "{PLAYER} picked up their\npartner, Eevee!$"

Player_Dorm_Nickname_Eevee_Text_0:
# 114 "data/maps/PlayerDorm/scripts.pory"
	.string "Does Eevee have a nickname?$"

Player_Dorm_EventScript_CheckPlayersPC_Text_0:
# 126 "data/maps/PlayerDorm/scripts.pory"
	.string "{PLAYER} booted up the laptop.$"

Player_Dorm_Trigger_CantLeave_Text_0:
# 135 "data/maps/PlayerDorm/scripts.pory"
	.string "You can't leave without Eevee.$"

Player_Dorm_NintendoSwitch_Text_0:
# 144 "data/maps/PlayerDorm/scripts.pory"
	.string "It's a Nintendo Switch 2.\p"
	.string "There are two JoyCons attached to the\n"
	.string "sides.$"

Player_Dorm_Drawers_Text_0:
# 150 "data/maps/PlayerDorm/scripts.pory"
	.string "The drawers are filled with clothes and\n"
	.string "school supplies.$"

EventScript_New_TV_Text_0:
# 156 "data/maps/PlayerDorm/scripts.pory"
	.string "Mom would like this show…\n"
	.string "… … …\p"
	.string "Time to go!$"

Tracie::
# 7 "data/maps/PlayerDorm/scripts.pory"
	.string "Tracie$"
