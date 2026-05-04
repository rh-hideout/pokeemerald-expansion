.set LOCALID_WELL_SLOWKING, 1

SlowpokeWell_B2F_MapScripts::
	.byte 0

SlowpokeWell_EventScript_Item_Kings_Rock::
	finditem ITEM_KINGS_ROCK
	end

SlowpokeWell_EventScript_Slowking::
	lock
	faceplayer
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	msgbox SlowpokeWell_Text_Slowking, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_set FLAG_ITEM_SLOWPOKE_WELL_RAIN_DANCE, SlowpokeWell_EventScript_Slowking2
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	applymovement LOCALID_WELL_SLOWKING, SlowpokeWell_Movement_RainDance1
	waitmovement 0
	delay 55
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	applymovement LOCALID_WELL_SLOWKING, SlowpokeWell_Movement_RainDance2
	waitmovement 0
	delay 55
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	applymovement LOCALID_WELL_SLOWKING, SlowpokeWell_Movement_RainDance3
	waitmovement 0
	delay 55
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	applymovement LOCALID_WELL_SLOWKING, SlowpokeWell_Movement_RainDance4
	waitmovement 0
	delay 55
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	setweather WEATHER_RAIN
	doweather
	waitmoncry
	giveitem ITEM_TM_RAIN_DANCE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_ITEM_SLOWPOKE_WELL_RAIN_DANCE
	release
	end

SlowpokeWell_EventScript_Slowking2::
	setweather WEATHER_RAIN
	doweather
	release
	end



SlowpokeWell_Movement_RainDance1:
	face_right
	delay_8
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_8
	step_end

SlowpokeWell_Movement_RainDance2:
	face_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_8
	step_end

SlowpokeWell_Movement_RainDance3:
	face_down
	lock_facing_direction
	walk_fast_right
	walk_fast_left
	unlock_facing_direction
	delay_8
	step_end

SlowpokeWell_Movement_RainDance4:
	lock_facing_direction
	walk_fast_left
	walk_fast_right
	unlock_facing_direction
	step_end

SlowpokeWell_Text_Slowking:
	.string "SLOWKING: ........................$"
