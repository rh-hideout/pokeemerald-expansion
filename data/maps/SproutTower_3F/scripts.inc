.set LOCALID_SPROUT_TOWER_SILVER, 5

SproutTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 60
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 60
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "ELDER: You are indeed skilled\n"
	.string "as a trainer.\p"
	.string "As promised, here is your HM.\p"
	.string "But let me say this: You should\n"
	.string "treat your POKéMON better.\p"
	.string "The way you battle is far too\n"
	.string "harsh.\p"
	.string "POKéMON are not tools of war…$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "…\n"
	.string "…Humph!\p"
	.string "He claims to be the ELDER but\n"
	.string "he's weak.\p"
	.string "It stands to reason.\p"
	.string "I'd never lose to fools who babble\n"
	.string "about being nice to POKéMON.\p"
	.string "I only care about strong\n"
	.string "POKéMON that can win.\p"
	.string "I really couldn't care less\n"
	.string "about weak POKéMON.$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "{RIVAL} used an ESCAPE ROPE!$"

SproutTower_Text_SageLi_Seen:
	.string "So good of you to come here!\p"
	.string "SPROUT TOWER is a place of\n"
	.string "training.\p"
	.string "People and POKéMON test their\n"
	.string "bonds to build a bright future\l"
	.string "together.\p"
	.string "I am the final test.\p"
	.string "Allow me to check the ties\n"
	.string "between your POKéMON and you!$"

SproutTower_Text_SageLi_Beaten:
	.string "Ah, excellent!$"

SproutTower_Text_SageLi_TakeFlash:
	.string "You and your POKéMON should\n"
	.string "have no problem using this move.\p"
	.string "Take this FLASH HM.$"

SproutTower_Text_SageLi_FlashExplain:
	.string "FLASH illuminates even the\n"
	.string "darkest of all places.\p"
	.string "But to use it out of battle, you\n"
	.string "need the BADGE from VIOLET's GYM.$"

SproutTower_Text_SageLi_AfterBattle:
	.string "I hope you learn and grow from\n"
	.string "your journey.$"

SproutTower_Text_SageJin_Seen:
	.string "I train to find enlightenment\n"
	.string "in POKéMON!$"

SproutTower_Text_SageJin_Beaten:
	.string "My training is incomplete…$"

SproutTower_Text_SageJin_AfterBattle:
	.string "As POKéMON grow stronger,\n"
	.string "so does the trainer.\p"
	.string "No, wait. As the trainer\n"
	.string "grows stronger, so do the\l"
	.string "POKéMON.$"

SproutTower_Text_SageTroy_Seen:
	.string "Let me see how much you trust\n"
	.string "your POKéMON.$"

SproutTower_Text_SageTroy_Beaten:
	.string "Yes, your trust is real!$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "It is not far to the ELDER.$"

SproutTower_Text_SageNeal_Seen:
	.string "The ELDER's HM lights even\n"
	.string "pitch-black darkness.$"

SproutTower_Text_SageNeal_Beaten:
	.string "It is my head that is bright!$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "Let there be light on your\n"
	.string "journey.$"

SproutTower_Text_3F_Painting:
	.string "It's a powerful painting of a\n"
	.string "BELLSPROUT.$"
