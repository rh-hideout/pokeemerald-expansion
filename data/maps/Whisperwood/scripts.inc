Whisperwood_MapScripts::
	.byte 0

Whisperwood_EventScript_Sign::
	msgbox Whisperwood_Text_1, MSGBOX_SIGN
	end

Whisperwood_EventScript_Shrine::
	lockall
	setspeaker SP_NAME_NONE
	msgbox Whisperwood_Text_2, MSGBOX_DEFAULT
	releaseall
	end

Whisperwood_EventScript_CampEvent::
	lockall
	setspeaker Pentara_Name_Mira
	msgbox Whisperwood_Text_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	closemessage
	applymovement LOCALID_PLAYER, Whisperwood_Movement_ToVex
	waitmovement 0
	setspeaker Pentara_Name_Vex
	msgbox Whisperwood_Text_4, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_P_VEX_WW, Whisperwood_Text_VexLose
	goto_if_set FLAG_P_BATTLE_LOST, Pentara_EventScript_BattleLost
	setspeaker Pentara_Name_Vex
	msgbox Whisperwood_Text_5, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_WW_VEX
	removeobject LOCALID_WW_GRUNT1
	removeobject LOCALID_WW_GRUNT2
	setflag FLAG_P_HIDE_WW_CAMP
	fadescreen FADE_FROM_BLACK
	setspeaker Pentara_Name_Mira
	msgbox Whisperwood_Text_6, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	setvar VAR_P_ALD_WW, 1
	releaseall
	end

Whisperwood_EventScript_CagedEevee::
	lock
	faceplayer
	goto_if_eq VAR_P_ALD_WW, 0, Whisperwood_EventScript_EeveeCaged
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox Whisperwood_Text_7, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Whisperwood_EventScript_EeveeStay
	givemon SPECIES_EEVEE, 9
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Whisperwood_EventScript_EeveeFull
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	setspeaker SP_NAME_NONE
	msgbox Whisperwood_Text_8, MSGBOX_DEFAULT
	waitfanfare
	removeobject LOCALID_WW_EEVEE
	setflag FLAG_P_HIDE_WW_EEVEE
	release
	end

Whisperwood_EventScript_EeveeCaged::
	setspeaker SP_NAME_NONE
	msgbox Whisperwood_Text_9, MSGBOX_DEFAULT
	release
	end

Whisperwood_EventScript_EeveeStay::
	setspeaker SP_NAME_NONE
	msgbox Whisperwood_Text_10, MSGBOX_DEFAULT
	release
	end

Whisperwood_EventScript_EeveeFull::
	setspeaker SP_NAME_NONE
	msgbox Whisperwood_Text_11, MSGBOX_DEFAULT
	release
	end

Whisperwood_EventScript_Mira::
	lock
	faceplayer
	goto_if_eq VAR_P_ALD_WW, 0, Whisperwood_EventScript_MiraWaiting
	setspeaker Pentara_Name_Mira
	msgbox Whisperwood_Text_12, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Whisperwood_EventScript_MiraWaiting::
	setspeaker Pentara_Name_Mira
	msgbox Whisperwood_Text_13, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

Whisperwood_EventScript_Vex::
	msgbox Whisperwood_Text_14, MSGBOX_NPC
	end

Whisperwood_EventScript_Grunt::
	msgbox Whisperwood_Text_15, MSGBOX_NPC
	end

Whisperwood_Movement_ToVex:
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

Whisperwood_Text_1::
	.string "WHISPERWOOD\p"
	.string "The trees here are said to whisper\n"
	.string "the names of lost travelers.$"

Whisperwood_Text_2::
	.string "An old stone shrine, wrapped in\n"
	.string "moss. Something is carved on it:\p"
	.string "'When the forest's guardian hears\n"
	.string "a Grass Pokémon's song, it will\l"
	.string "come.'\p"
	.string "(Side story: THE FOREST GUARDIAN)$"

Whisperwood_Text_3::
	.string "Shh! Get down! Over there, by the\n"
	.string "cages.\p"
	.string "I'm Mira, Professor Linden's\n"
	.string "niece. I've been tracking these\l"
	.string "poachers for days.\p"
	.string "The one in the dark cloak is their\n"
	.string "admin, Vex. I'll handle the\l"
	.string "grunts. Can you take her?$"

Whisperwood_Text_4::
	.string "Well, well. A lost little trainer,\n"
	.string "wandering into Team Rust's\l"
	.string "business.\p"
	.string "Every Pokémon in these cages is\n"
	.string "already sold. Rare, healthy, and\l"
	.string "worth a fortune.\p"
	.string "You want them back? Then show me\n"
	.string "what you're worth!$"

Whisperwood_Text_5::
	.string "Hmph. You're sharper than you\n"
	.string "look.\p"
	.string "Fine, keep these runts. Brask will\n"
	.string "have bigger plans for kids like\l"
	.string "you.\p"
	.string "Team Rust, pull out!$"

Whisperwood_Text_6::
	.string "You did it! And those grunts ran\n"
	.string "the moment Vex lost.\p"
	.string "Let's open the cages... there,\n"
	.string "they're all free!\p"
	.string "Hey, look. That Eevee won't leave\n"
	.string "your side. I think it wants to\l"
	.string "come with you.$"

Whisperwood_Text_7::
	.string "Eevee looks up at you hopefully.\n"
	.string "Take Eevee with you?$"

Whisperwood_Text_8::
	.string "Eevee joined your team!$"

Whisperwood_Text_9::
	.string "An Eevee is locked in a cage. It\n"
	.string "looks scared.$"

Whisperwood_Text_10::
	.string "Eevee tilts its head. It will wait\n"
	.string "here for you.$"

Whisperwood_Text_11::
	.string "Your party and PC boxes are\n"
	.string "full...$"

Whisperwood_Text_12::
	.string "Vex mentioned someone named Brask.\n"
	.string "He must be Team Rust's boss.\p"
	.string "I'll keep watch here. Go on to\n"
	.string "Cobblecross, and I'll catch up\l"
	.string "with you, rival!$"

Whisperwood_Text_13::
	.string "Shh! The camp is just ahead.$"

Whisperwood_Text_14::
	.string "The Pokémon in these cages are\n"
	.string "already sold. Walk away, child.$"

Whisperwood_Text_15::
	.string "Get lost, kid! This clearing is\n"
	.string "off limits!$"

Whisperwood_Text_VexLose::
	.string "Vex: How... dull. You actually\n"
	.string "won.$"

