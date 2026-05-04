.set LOCALID_UNION_CAVE_LAPRAS, 6

UnionCave_B2F_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_NICK, UnionCave_B2F_Text_CooltrainermNickSeen, UnionCave_B2F_Text_CooltrainermNickBeaten
	msgbox UnionCave_B2F_Text_CooltrainermNickAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfGwen::
	trainerbattle_single TRAINER_GWEN, UnionCave_B2F_Text_CooltrainerfGwenSeen, UnionCave_B2F_Text_CooltrainerfGwenBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfGwenAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfEmma::
	trainerbattle_single TRAINER_EMMA, UnionCave_B2F_Text_CooltrainerfEmmaSeen, UnionCave_B2F_Text_CooltrainerfEmmaBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfEmmaAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 20
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnionCave_B2F_EventScript_LaprasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_UNION_CAVE_LAPRAS
	setflag FLAG_HIDE_UNION_CAVE_LAPRAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

UnionCave_B2F_EventScript_LaprasRan::
	release
	end


UnionCave_B2F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

UnionCave_B2F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

UnionCave_B2F_EventScript_Item_MaxRevive::
	finditem ITEM_MAX_REVIVE
	end

UnionCave_B2F_Text_CooltrainermNickSeen:
	.string "There are two kinds of people.\p"
	.string "Those who have style, and those\n"
	.string "who don't.\p"
	.string "What kind of person are you?$"

UnionCave_B2F_Text_CooltrainermNickBeaten:
	.string "You've got dazzling style!$"

UnionCave_B2F_Text_CooltrainermNickAfter:
	.string "Your POKéMON style is stunning and\n"
	.string "colorful, I admit.\p"
	.string "You'll just keep getting better!$"

UnionCave_B2F_Text_CooltrainerfGwenSeen:
	.string "I'm in training. Care for a round?$"

UnionCave_B2F_Text_CooltrainerfGwenBeaten:
	.string "Aww, no! You're too good for me.$"

UnionCave_B2F_Text_CooltrainerfGwenAfter:
	.string "I'm going to train by myself until I\n"
	.string "improve.$"

UnionCave_B2F_Text_CooltrainerfEmmaSeen:
	.string "If the POKéMON I liked were there,\n"
	.string "I'd go anywhere.\p"
	.string "That's what a real trainer does.$"

UnionCave_B2F_Text_CooltrainerfEmmaBeaten:
	.string "I'd rather pet my babies than this!$"

UnionCave_B2F_Text_CooltrainerfEmmaAfter:
	.string "Just once a week, a POKéMON comes to\n"
	.string "the water's edge.\p"
	.string "I wanted to see that POKéMON…$"
