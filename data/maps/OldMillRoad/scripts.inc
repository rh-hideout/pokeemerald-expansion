OldMillRoad_MapScripts::
	.byte 0

OldMillRoad_EventScript_Sign::
	msgbox OldMillRoad_Text_1, MSGBOX_SIGN
	end

OldMillRoad_EventScript_Mareep::
	lock
	playmoncry SPECIES_MAREEP, CRY_MODE_NORMAL
	setspeaker SP_NAME_NONE
	msgbox OldMillRoad_Text_2, MSGBOX_DEFAULT
	release
	end

OldMillRoad_EventScript_Juno::
	lock
	faceplayer
	goto_if_set FLAG_P_BEAT_JUNO_OMR, OldMillRoad_EventScript_JunoAfter
	setspeaker Pentara_Name_Juno
	msgbox OldMillRoad_Text_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_P_JUNO_OMR, OldMillRoad_Text_JunoLose
	goto_if_set FLAG_P_BATTLE_LOST, Pentara_EventScript_BattleLost
	setflag FLAG_P_BEAT_JUNO_OMR
	setspeaker Pentara_Name_Juno
	msgbox OldMillRoad_Text_4, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	giveitem ITEM_SOOTHE_BELL
	setspeaker Pentara_Name_Juno
	msgbox OldMillRoad_Text_5, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

OldMillRoad_EventScript_JunoAfter::
	setspeaker Pentara_Name_Juno
	msgbox OldMillRoad_Text_6, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

OldMillRoad_Text_1::
	.string "OLD MILL ROAD\p"
	.string "West: COBBLECROSS\p"
	.string "East: WHISPERWOOD$"

OldMillRoad_Text_2::
	.string "Baaah! The Mareep's wool crackles\n"
	.string "with static.$"

OldMillRoad_Text_3::
	.string "...You're the one who scattered\n"
	.string "Team Rust in Whisperwood.\p"
	.string "I'm Juno. The Rangers raised me. I\n"
	.string "don't talk much.\p"
	.string "I'd rather let our Pokémon talk.\n"
	.string "Ready?$"

OldMillRoad_Text_4::
	.string "...Good. You listen to your\n"
	.string "Pokémon.\p"
	.string "Take this. Rangers use it to calm\n"
	.string "frightened Pokémon.$"

OldMillRoad_Text_5::
	.string "Cobblecross is west. Garnet's Gym\n"
	.string "uses sandstorms. Bring something\l"
	.string "that can take a hit.$"

OldMillRoad_Text_6::
	.string "...See you at the League.$"

OldMillRoad_Text_JunoLose::
	.string "Juno: ...Well fought.$"

