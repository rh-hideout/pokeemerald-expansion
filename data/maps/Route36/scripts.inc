.set LOCALID_ROUTE36_SUDOWOODO, 6
.set LOCALID_ROUTE36_ROCKSMASHGUY, 3

Route36_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE	
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked	
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
	.string "Use SQUIRTBOTTLE?$"

Route36_Text_UsedSquirtbottle:
	.string "{PLAYER} used the SQUIRTBOTTLE.$"

Route36_Text_SudowoodoAttacked:
	.string "The weird tree doesn't like the\n"
	.string "SQUIRTBOTTLE!\p"
	.string "The weird tree attacked!$"

Route36_Text_RockSmashGuy1:
	.string "Wa-hey!\p"
	.string "I was going to snap that tree\n"
	.string "with my straight-arm punch.\p"
	.string "But I couldn't! I'm a failure!$"

Route36_Text_RockSmashGuy2:
	.string "Did you clear that wretched tree?\p"
	.string "I'm impressed!\n"
	.string "I want you to have this.$"

Route36_Text_RockSmashGuy3:
	.string "That happens to be ROCK SMASH.\p"
	.string "You can shatter rocks with just a\n"
	.string "single well-aimed smack.\p"
	.string "If any rocks are in your way,\n"
	.string "just smash 'em up!$"

Route36_Text_OddTree:
	.string "A weird tree is blocking the way.$"

Route36_Text_Lass1:
	.string "Be careful at night on this route!\p"
	.string "I saw a POKéMON that looked like\n"
	.string "GROWLITHE, but it had a scary aura\l"
	.string "to it.$"

Route36_Text_Lass2_ClearedSudowoodo:
	.string "That odd tree disappeared without\n"
	.string "a trace.\p"
	.string "Oh! That tree was really a\n"
	.string "POKéMON?$"

Route36_Text_PsychicMarkSeen:
	.string "I'm going to read your thoughts!$"

Route36_Text_PsychicMarkBeaten:
	.string "I misread you!$"

Route36_Text_PsychicMarkAfter:
	.string "I'd be strong if only I could tell\n"
	.string "what my opponent was thinking.$"

Route36_Text_SchoolboyAlan1Seen:
	.string "Thanks to my studies, I'm ready\n"
	.string "for any POKéMON!$"

Route36_Text_SchoolboyAlan1Beaten:
	.string "Oops! Computation error?$"

Route36_Text_SchoolboyAlanAfter:
	.string "Darn. I study five hours a day too.\p"
	.string "There's more to learning than just\n"
	.string "reading books.$"

Route36_Text_MeetArthur:
	.string "ARTHUR: Who are you?\n"
	.string "I'm ARTHUR of the WEEKDAY FAMILY.\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"

Route36_Text_ArthurNope:
	.string "Not quite!$"

Route36_Text_ArthurGivesGift:
	.string "Here. You can have this.$"

Route36_Text_ArthurGaveGift:
	.string "ARTHUR: A POKéMON that uses ROCK-\n"
	.string "type moves should hold on to that.\p"
	.string "It pumps up ROCK-type attacks.$"

Route36_Text_ArthurThursday:
	.string "ARTHUR: I'm ARTHUR of Thursday.\n"
	.string "I'm the fifth son out of seven.$"

Route36_Text_Sign:
	.string "ROUTE 36$"

Route36_Text_Sign_RuinsNorth:
	.string "RUINS OF ALPH\n"
	.string "NORTH ENTRANCE$"

Route36_Text_Tips1:
	.string "TRAINER TIPS\n"
	.string "POKéMON stats vary--even within\l"
	.string "the same species.\p"
	.string "Their stats may be similar at first.\p"
	.string "However, differences will become\n"
	.string "pronounced as the POKéMON grow.$"

Route36_Text_Tips2:
	.string "TRAINER TIPS\n"
	.string "Use DIG to return to the entrance of\n"
	.string "any place.\p"
	.string "It is convenient for exploring\n"
	.string "caves and other landmarks.$"
