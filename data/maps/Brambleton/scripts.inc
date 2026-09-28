Brambleton_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Brambleton_OnTransition
	.byte 0

Brambleton_OnTransition::
	setflag FLAG_P_VISITED_BRAMBLETON
	end

Brambleton_EventScript_WestGate::
	lockall
	setspeaker Pentara_Name_Ranger
	msgbox Brambleton_Text_1, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	applymovement LOCALID_PLAYER, Brambleton_Movement_StepRight
	waitmovement 0
	releaseall
	end

Brambleton_EventScript_Ranger::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, Brambleton_EventScript_RangerOpen
	setspeaker Pentara_Name_Ranger
	msgbox Brambleton_Text_2, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Brambleton_EventScript_RangerOpen::
	setspeaker Pentara_Name_Ranger
	msgbox Brambleton_Text_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Brambleton_EventScript_TownSign::
	msgbox Brambleton_Text_4, MSGBOX_SIGN
	end

Brambleton_EventScript_GymSign::
	msgbox Brambleton_Text_5, MSGBOX_SIGN
	end

Brambleton_EventScript_BugCatcher::
	msgbox Brambleton_Text_6, MSGBOX_NPC
	end

Brambleton_EventScript_Woman::
	msgbox Brambleton_Text_7, MSGBOX_NPC
	end

Brambleton_EventScript_Kai::
	lock
	faceplayer
	setspeaker Pentara_Name_Kai
	msgbox Brambleton_Text_8, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Brambleton_Movement_StepRight:
	walk_right
	step_end

Brambleton_Text_1::
	.string "Hold on! Whisperwood is crawling\n"
	.string "with poachers right now.\p"
	.string "Nettle asked us to only let\n"
	.string "trainers with her Hive Badge\l"
	.string "through.$"

Brambleton_Text_2::
	.string "Only trainers with the Hive Badge\n"
	.string "may enter Whisperwood.$"

Brambleton_Text_3::
	.string "You've got the Hive Badge! Go on\n"
	.string "through, and watch out for Team\l"
	.string "Rust.$"

Brambleton_Text_4::
	.string "BRAMBLETON\p"
	.string "A village of hedges, honey and\n"
	.string "humming wings.$"

Brambleton_Text_5::
	.string "BRAMBLETON POKéMON GYM\p"
	.string "Leader: NETTLE\p"
	.string "The Queen of the Thicket!$"

Brambleton_Text_6::
	.string "Nettle's Gym has a web over the\n"
	.string "whole arena!\p"
	.string "Anything that switches in gets\n"
	.string "tangled and slowed. Pick your\l"
	.string "first Pokémon carefully!$"

Brambleton_Text_7::
	.string "Fire and Flying moves burn right\n"
	.string "through Bug Pokémon. Rock moves\l"
	.string "smash them too!$"

Brambleton_Text_8::
	.string "I already challenged Nettle... and\n"
	.string "lost. Her Beedrill is no joke!\p"
	.string "Level up on Meadow Lane first.\n"
	.string "Your Pokémon can't go past the\l"
	.string "level cap, so get everyone up to\n"
	.string "it!$"

