Cobblecross_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Cobblecross_OnTransition
	.byte 0

Cobblecross_OnTransition::
	setflag FLAG_P_VISITED_COBBLECROSS
	end

Cobblecross_EventScript_Sign::
	msgbox Cobblecross_Text_1, MSGBOX_SIGN
	end

Cobblecross_EventScript_GymSign::
	msgbox Cobblecross_Text_2, MSGBOX_SIGN
	end

Cobblecross_EventScript_NorthGate::
	lockall
	setspeaker Pentara_Name_Worker
	msgbox Cobblecross_Text_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	applymovement LOCALID_PLAYER, Cobblecross_Movement_StepDown
	waitmovement 0
	releaseall
	end

Cobblecross_EventScript_Worker::
	msgbox Cobblecross_Text_4, MSGBOX_NPC
	end

Cobblecross_EventScript_Dorian::
	lock
	faceplayer
	goto_if_set FLAG_P_BEAT_DORIAN_CC, Cobblecross_EventScript_DorianAfter
	setspeaker Pentara_Name_Dorian
	msgbox Cobblecross_Text_5, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_P_DORIAN_CC, Cobblecross_Text_DorianLose
	goto_if_set FLAG_P_BATTLE_LOST, Pentara_EventScript_BattleLost
	setflag FLAG_P_BEAT_DORIAN_CC
	setspeaker Pentara_Name_Dorian
	msgbox Cobblecross_Text_6, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	giveitem ITEM_NUGGET
	release
	end

Cobblecross_EventScript_DorianAfter::
	setspeaker Pentara_Name_Dorian
	msgbox Cobblecross_Text_7, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Cobblecross_Movement_StepDown:
	walk_down
	step_end

Cobblecross_Text_1::
	.string "COBBLECROSS\p"
	.string "Where every road in Aldermoor is\n"
	.string "paved.$"

Cobblecross_Text_2::
	.string "COBBLECROSS POKéMON GYM\p"
	.string "Leader: GARNET\p"
	.string "The Unshakable Stonewall!$"

Cobblecross_Text_3::
	.string "Sorry, the Cliffside Path is\n"
	.string "closed. Rockslides!\p"
	.string "Garnet's clearing it after she's\n"
	.string "done with Gym challenges today.$"

Cobblecross_Text_4::
	.string "These rocks came down from the\n"
	.string "cliffs last night. Funny... it\l"
	.string "wasn't raining.\p"
	.string "Almost like someone blasted them\n"
	.string "loose.$"

Cobblecross_Text_5::
	.string "Ah, a commoner! Behold: a Master\n"
	.string "Ball. Bought it this morning.\p"
	.string "Here in Cobblecross they're a mere\n"
	.string "two thousand. Pocket change,\l"
	.string "really.\p"
	.string "Now then, allow me to show you\n"
	.string "what money can buy!$"

Cobblecross_Text_6::
	.string "Impossible! My Pokémon are the\n"
	.string "finest money can buy!\p"
	.string "...Hmph. Perhaps training matters\n"
	.string "too. Take this; I have plenty.$"

Cobblecross_Text_7::
	.string "Next time, I'll have a Mega Stone.\n"
	.string "Then we'll see!$"

Cobblecross_Text_DorianLose::
	.string "Dorian: Wh-what?! That was a\n"
	.string "fluke!$"

