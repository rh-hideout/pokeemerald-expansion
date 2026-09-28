MeadowLane_MapScripts::
	.byte 0

MeadowLane_EventScript_Sign::
	msgbox MeadowLane_Text_1, MSGBOX_SIGN
	end

MeadowLane_EventScript_GruntEvent::
	lockall
	setspeaker Pentara_Name_Grunt
	msgbox MeadowLane_Text_2, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	applymovement LOCALID_R1_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_R1_GRUNT, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Pentara_Name_Grunt
	msgbox MeadowLane_Text_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_P_RUST_GRUNT_R1, MeadowLane_Text_GruntLose
	goto_if_set FLAG_P_BATTLE_LOST, Pentara_EventScript_BattleLost
	setspeaker Pentara_Name_Grunt
	msgbox MeadowLane_Text_4, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	closemessage
	applymovement LOCALID_R1_GRUNT, MeadowLane_Movement_GruntFlee
	waitmovement 0
	removeobject LOCALID_R1_GRUNT
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	setspeaker SP_NAME_NONE
	msgbox MeadowLane_Text_5, MSGBOX_DEFAULT
	removeobject LOCALID_R1_PIDGEY
	setflag FLAG_P_HIDE_R1_GRUNT
	setvar VAR_P_ALD_STORY, 3
	releaseall
	end

MeadowLane_EventScript_Grunt::
	msgbox MeadowLane_Text_6, MSGBOX_NPC
	end

MeadowLane_EventScript_Pidgey::
	lock
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	setspeaker SP_NAME_NONE
	msgbox MeadowLane_Text_7, MSGBOX_DEFAULT
	release
	end

MeadowLane_Movement_GruntFlee:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MeadowLane_Text_1::
	.string "MEADOW LANE\p"
	.string "North: BRAMBLETON\p"
	.string "South: SPROUT HOLLOW$"

MeadowLane_Text_2::
	.string "Hold still, you stupid bird! Team\n"
	.string "Rust pays good money for plump\l"
	.string "little Pidgey!$"

MeadowLane_Text_3::
	.string "Huh? A kid? Buzz off! This is Team\n"
	.string "Rust business!\p"
	.string "...You're not leaving? Fine. I'll\n"
	.string "teach you to stick your nose in!$"

MeadowLane_Text_4::
	.string "Tch! Our boss will hear about you,\n"
	.string "kid. Team Rust never forgets a\l"
	.string "face!$"

MeadowLane_Text_5::
	.string "The Pidgey chirps happily and\n"
	.string "flies away!$"

MeadowLane_Text_6::
	.string "Get lost, kid!$"

MeadowLane_Text_7::
	.string "Pidgey is trembling...$"

MeadowLane_Text_GruntLose::
	.string "Ugh! Beaten by a rookie!$"

