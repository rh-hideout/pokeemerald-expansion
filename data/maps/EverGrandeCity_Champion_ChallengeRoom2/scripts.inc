EverGrandeCity_Champion_ChallengeRoom2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_Champion_ChallengeRoom2_OnWarp
	.byte 0

EverGrandeCity_Champion_ChallengeRoom2_OnWarp:
	map_script_2 VAR_TEMP_0, 0, EverGrandeCity_Champion_ChallengeRoom2_OnTransition
	.2byte 0

EverGrandeCity_Champion_ChallengeRoom2_OnTransition::
	lock
	setvar VAR_TEMP_0, 1
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Player_MoveToArena
	waitmovement 0
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_Choose_Trainer_Battle

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Choose_Trainer_Battle::
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_1, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_1
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_2, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_2
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_3, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_3
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_4, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_4
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_5, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_5
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_6, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_6
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_7, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_7
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_8, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_8
	goto_if_unset FLAG_HIDE_CHAMPION_CHALLENGER_9, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_9

// START TRAINER SPECIFIC BATTLE SCRIPTS ------------------------------------------

// TRAINER 1 ----------------------------------------------------------------------


EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_1::
	trainerbattle_single TRAINER_CHAMPION_BRANDON, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_1_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_1_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_1_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_1_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_1
	cleartrainerflag TRAINER_CHAMPION_BRANDON
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_1_Intro::
	.string "A champion's duty isn't over\n"
	.string "after one victory. It's time to\l"
	.string "defend that title!$"

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_1_Defeat::
	.string "I gave it everything I had.\n"
	.string "You truly are a champion.$"

// TRAINER 2 ----------------------------------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_2::
	trainerbattle_single TRAINER_CHAMPION_GRETA, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_2_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_2_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_2_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_2_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_2
	cleartrainerflag TRAINER_CHAMPION_GRETA
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_2_Intro::
	.string "I've waited for a real challenge.\n"
	.string "You won't disappoint me, will you?$"

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_2_Defeat::
	.string "Defeat never tasted so sweet.\n"
	.string "What a battle!$"

// TRAINER 3 ----------------------------------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_3::
	trainerbattle_single TRAINER_CHAMPION_ANABEL, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_3_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_3_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_3_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_3_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_3
	cleartrainerflag TRAINER_CHAMPION_ANABEL
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_3_Intro::
	.string "This is the battle I've been dreaming\n"
	.string "of. Don't hold anything back!$"

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_3_Defeat::
	.string "Losing to you, somehow it doesn't\n"
	.string "sting as much...$"

// TRAINER 4 ----------------------------------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_4::
	trainerbattle_single TRAINER_CHAMPION_SPENSER, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_4_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_4_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_4_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_4_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_4
	cleartrainerflag TRAINER_CHAMPION_SPENSER
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_4_Intro::
	.string "Titles mean nothing without true\n"
	.string "strength. Let's see which of us\l"
	.string "deserves it!$"

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_4_Defeat::
	.string "You surpassed me today. Wear your\n"
	.string "title with pride.$"

// TRAINER 5 ----------------------------------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_5::
	trainerbattle_single TRAINER_CHAMPION_TUCKER, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_5_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_5_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_5_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_5_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_5
	cleartrainerflag TRAINER_CHAMPION_TUCKER
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_5_Intro::
	.string "Two champions, one battlefield.\n"
	.string "Let's make this legendary!$"

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_5_Defeat::
	.string "I have no regrets. That was a fight\n"
	.string "worthy of legends.$"

// TRAINER 6 ----------------------------------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_6::
	trainerbattle_single TRAINER_CHAMPION_LUCY, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_6_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_6_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_6_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_6_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_6
	cleartrainerflag TRAINER_CHAMPION_LUCY
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_6_Intro::
	.string "Only one can stand at the top!\n"
	.string "Come at me with everything that\l"
	.string "you've got!$"

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_6_Defeat::
	.string "This battle will stay with me.\n"
	.string "I'll be chasing you from now on.$"

// TRAINER 7 ----------------------------------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_7::
	trainerbattle_single TRAINER_CHAMPION_NOLAND, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_7_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_7_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_7_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_7_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_7
	cleartrainerflag TRAINER_CHAMPION_NOLAND
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_7_Intro::
	.string "No more training, no more waiting.\n"
	.string "It's time to clash at full force!$"

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_7_Defeat::
	.string "I wanted a clash of legends, and you\n"
	.string "certainly delivered it!$"

// TRAINER 8 ----------------------------------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_8::
	trainerbattle_single TRAINER_CHAMPION_LEAF, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_8_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_8_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_8_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_8_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_8
	cleartrainerflag TRAINER_CHAMPION_LEAF
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_8_Intro::
	.string "I've studied every one of your moves.\n"
	.string "Let's see if you can surprise me!$"

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_8_Defeat::
	.string "This battle will stay with me.\n"
	.string "I'll be chasing you from now on.$"

// TRAINER 9 ----------------------------------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_9::
	trainerbattle_single TRAINER_CHAMPION_RED, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_9_Intro, EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_9_Defeat, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_9_SetFlag
	end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Battle_9_SetFlag::
	setflag FLAG_BEAT_CHAMPION_CHALLENGER_9
	cleartrainerflag TRAINER_CHAMPION_RED
	goto EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath

EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_9_Intro::
	.string "Steel your heart. Champions fight with\n"
	.string "everything they have!$"


EverGrandeCity_Champion_ChallengeRoom2_Text_Battle_9_Defeat::
	.string "A true champion never fears defeat,\n"
	.string "only dishonor. And you have fought\l"
	.string "with honor.$"

// END TRAINER SPECIFIC BATTLE SCRIPTS ------------------------------------------

EverGrandeCity_Champion_ChallengeRoom2_EventScript_BattleAfterMath::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_Champion_ChallengeRoom2_EventScript_Player_MoveToDoor
	waitmovement 0
	warp MAP_EVER_GRANDE_CITY_CHAMPION_CHALLENGE_ROOM1, 4, 4
	waitstate
	
EverGrandeCity_Champion_ChallengeRoom2_EventScript_Player_MoveToArena::
	face_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_right
	step_end

EverGrandeCity_Champion_ChallengeRoom2_EventScript_Player_MoveToDoor::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
