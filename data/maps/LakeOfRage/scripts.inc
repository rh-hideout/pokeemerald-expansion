.set LOCALID_LAKEOFRAGE_GYARADOS, 8
.set LOCALID_LAKEOFRAGE_LANCE, 3
.set LOCALID_LAKEOFRAGE_DRAGONITE, 16
.set LOCALID_LAKEOFRAGE_OLDMAN, 4
.set LOCALID_LAKE_PRYCE, 17

LakeOfRage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
    .string "{PLAYER}.\p"
	.string "Even here, the cold keeps me sharp.\p"
	.string "If you wish to battle again, come\n"
	.string "to the FIGHTING DOJO.$"

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Max_Revive::
	finditem ITEM_MAX_REVIVE
	end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "DRAGONITE: Gyafooha!$"

LakeOfRage_Text_LanceForcedToEvolve:
    .string "This lake is full of GYARADOS\n"
    .string "but nothing else…\p"
    .string "So the MAGIKARP are being forced\n"
    .string "to evolve…$"

LakeOfRage_Text_LanceIntro1:
    .string "Did you come here because of\n"
    .string "the rumors?\p"
    .string "You're {PLAYER}? I'm LANCE, a\n"
    .string "trainer like you.$"

LakeOfRage_Text_LanceIntro2:
    .string "This man here informed me of\n"
    .string "some rumors.\p"
    .string "So we came to investigate…$"

LakeOfRage_Text_LanceIntro3:
    .string "I saw the way you battled\n"
    .string "earlier, {PLAYER}.\p"
    .string "I can tell that you're a trainer\n"
    .string "with considerable skill.\p"
    .string "If you don't mind, could you help\n"
    .string "us investigate?$"

LakeOfRage_Text_LanceRadioSignal:
    .string "LANCE: Excellent!\p"
    .string "It seems that the LAKE's MAGIKARP\n"
    .string "are being forced to evolve.\p"
    .string "A mysterious radio broadcast\n"
    .string "coming from MAHOGANY is the cause.\p"
    .string "We'll be waiting for you,\n"
    .string "{PLAYER}.$"

LakeOfRage_Text_LanceRefused:
    .string "Oh… Well, if you change your mind,\n"
    .string "please help us.$"

LakeOfRage_Text_LanceAskHelp:
    .string "LANCE: Hm? Are you going to help\n"
    .string "us?$"

LakeOfRage_Text_GyaradosCry:
    .string "GYARADOS: Gyashaa!$"

LakeOfRage_Text_Gramps:
    .string "The GYARADOS are angry!\p"
    .string "It's a bad omen!$"

LakeOfRage_Text_GrampsCleared:
    .string "Hahah! The MAGIKARP are biting!$"

LakeOfRage_Text_SuperNerd:
    .string "I heard this lake was made by\n"
    .string "rampaging GYARADOS.\p"
    .string "I wonder if there is any\n"
    .string "connection to their mass outbreak\l"
    .string "now?$"

LakeOfRage_Text_CooltrainerF:
    .string "Did my eyes deceive me? I saw a\n"
    .string "red GYARADOS in the LAKE…\p"
    .string "But I thought GYARADOS were\n"
    .string "usually blue?$"


LakeOfRage_Text_FisherAndreSeen:
    .string "Let me battle with the POKéMON I\n"
    .string "just caught!$"

LakeOfRage_Text_FisherAndreBeaten:
    .string "I might be an expert angler, but\n"
    .string "I stink as a POKéMON trainer…$"

LakeOfRage_Text_FisherAndreAfter:
    .string "I won't lose as an angler! I catch\n"
    .string "POKéMON all day.$"


LakeOfRage_Text_FisherRaymondSeen:
    .string "No matter what I do, all I catch\n"
    .string "are the same POKéMON…$"

LakeOfRage_Text_FisherRaymondBeaten:
    .string "My line's all tangled up…$"

LakeOfRage_Text_FisherRaymondAfter:
    .string "Why can't I catch any good\n"
    .string "POKéMON?$"

LakeOfRage_Text_CooltrainermAaronSeen:
    .string "If a trainer spots another trainer,\n"
    .string "he has to make a challenge.\p"
    .string "That is our destiny.$"

LakeOfRage_Text_CooltrainermAaronBeaten:
    .string "Whew… Good battle.$"

LakeOfRage_Text_CooltrainermAaronAfter:
    .string "POKéMON and their trainer become\n"
    .string "powerful through constant battling.$"

LakeOfRage_Text_CooltrainerfLoisSeen:
    .string "What happened to the red\n"
    .string "GYARADOS?\p"
    .string "It's gone?\p"
    .string "Oh, darn. I came here for\n"
    .string "nothing?\p"
    .string "I know--let's battle!$"

LakeOfRage_Text_CooltrainerfLoisBeaten:
    .string "Good going!$"

LakeOfRage_Text_CooltrainerfLoisAfter:
    .string "Come to think of it, I've seen a\n"
    .string "pink BUTTERFREE.$"



LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
    .string "WESLEY: Well, how do you do?\p"
    .string "I'm a member of the WEEKDAY family!\n"
	.string "Can you guess my favorite day?$"

LakeOfRage_Text_WesleyGivesGift:
    .string "Pleased to meet you. Please take a\n"
    .string "souvenir.$"

LakeOfRage_Text_WesleyGaveGift:
    .string "WESLEY: BLACK BELT beefs up the\n"
    .string "power of fighting moves.$"

LakeOfRage_Text_WesleyWednesday:
    .string "WESLEY: Since you found me, you\n"
    .string "must have met my brothers and\l"
    .string "sisters.\p"
    .string "Or did you just get lucky?$"

LakeOfRage_Text_WesleyNotWednesday:
    .string "WESLEY: Not exactly...$"

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
    .string "LAKE OF RAGE,\n"
    .string "also known as GYARADOS LAKE.$"

LakeOfRage_Text_FishingGuruSign:
    .string "FISHING GURU'S HOUSE$"
