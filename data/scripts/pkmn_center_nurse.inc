Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	incrementgamestat GAME_STAT_USED_POKECENTER
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	end

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	hidefollower 0
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return

EventScript_PkmnCenterNurse_ReturnPkmn::
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	return

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterNurse_Turn:
	walk_in_place_faster_left
	step_end

Common_EventScript_PkmnCenterUtil::
    lock
    faceplayer
	message Text_PkmnCenterUtil_WhatToDo
	waitmessage
	multichoicedefault 21, 2, MULTI_CHOICE_POKEMON_CENTER, 0, FALSE
	switch VAR_RESULT
	case 0, PkmnCenterUtil_EventScript_InflictStatus
	case 1, MoveRelearner_EventScript_MoveRelearner
	case 2, PkmnCenterUtil_EventScript_SAbilityPatch
	case 3, PkmnCenterUtil_EventScript_NatureMint
	case 4, PkmnCenterUtil_EventScript_EVItems
	case MULTI_B_PRESSED, EventScript_CancelPkmnUtil
	releaseall
	end

PkmnCenterUtil_EventScript_EVItems::
	message Text_PkmnCenterUtil_WhichEVItem
	waitmessage
	multichoicedefault 21, 2, MULTI_CHOICE_EV_ITEMS, 0, FALSE
	switch VAR_RESULT
	case 0, PkmnCenterUtil_EventScript_HPEVs
	case 1, PkmnCenterUtil_EventScript_AtkEVs
	case 2, PkmnCenterUtil_EventScript_DefEVs
	case 3, PkmnCenterUtil_EventScript_SpAEVs
	case 4, PkmnCenterUtil_EventScript_SpDEVs
	case 5, PkmnCenterUtil_EventScript_SpeEVs
	case MULTI_B_PRESSED, EventScript_CancelPkmnUtil
	releaseall
	end
	
PkmnCenterUtil_EventScript_HPEVs::
	giveitem ITEM_HP_UP, 20
	removeitem ITEM_HEART_SCALE
	releaseall
	end
PkmnCenterUtil_EventScript_AtkEVs::
	giveitem ITEM_PROTEIN, 20
	removeitem ITEM_HEART_SCALE
	releaseall
	end
PkmnCenterUtil_EventScript_DefEVs::
	giveitem ITEM_IRON, 20
	removeitem ITEM_HEART_SCALE
	releaseall
	end
PkmnCenterUtil_EventScript_SpAEVs::
	giveitem ITEM_CALCIUM, 20
	removeitem ITEM_HEART_SCALE
	releaseall
	end
PkmnCenterUtil_EventScript_SpDEVs::
	giveitem ITEM_ZINC, 20
	removeitem ITEM_HEART_SCALE
	releaseall
	end
PkmnCenterUtil_EventScript_SpeEVs::
	giveitem ITEM_CARBOS, 20
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_InflictStatus::
    msgbox Text_PkmnCenterUtil_ExplainStatus MSGBOX_DEFAULT
    call Debug_EventScript_InflictStatus1
    releaseall
    end

PkmnCenterUtil_EventScript_SAbilityPatch::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, MoveRelearner_EventScript_ComeBackWithHeartScale
	msgbox Text_PkmnCenterUtil_SAP_Confirm MSGBOX_YESNO
	switch VAR_RESULT
	case NO, PkmnCenterUtil_EventScript_Cancel
	case YES, MoveRelearner_EventScript_GivePatch
    releaseall
    end
	
PkmnCenterUtil_EventScript_NatureMint::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, MoveRelearner_EventScript_ComeBackWithHeartScale
	msgbox Text_PkmnCenterUtil_Mint_Confirm MSGBOX_YESNO
	switch VAR_RESULT
	case NO, PkmnCenterUtil_EventScript_Cancel
	case YES, MoveRelearner_EventScript_GiveMint
    releaseall
    end        

MoveRelearner_EventScript_GiveMint::
	message Text_PkmnCenterUtil_WhichMint
	waitmessage
	multichoicedefault 21, 2, MULTI_CHOICE_NATURE_MINT, 0, FALSE
	switch VAR_RESULT
	case 0, MoveRelearner_EventScript_GiveAtkMint
	case 1, MoveRelearner_EventScript_GiveDefMint
	case 2, MoveRelearner_EventScript_GiveSpAMint
	case 3, MoveRelearner_EventScript_GiveSpDMint
	case 4, MoveRelearner_EventScript_GiveSpeMint
	case MULTI_B_PRESSED, EventScript_CancelPkmnUtil
	releaseall
	end
   
MoveRelearner_EventScript_GiveAtkMint::
	message Text_PkmnCenterUtil_WhichMint
	waitmessage
	multichoicedefault 21, 2, MULTI_CHOICE_ATK_MINT, 0, FALSE
	switch VAR_RESULT
	case 0, PkmnCenterUtil_EventScript_AtkMinusDef
	case 1, PkmnCenterUtil_EventScript_AtkMinusSpA
	case 2, PkmnCenterUtil_EventScript_AtkMinusSpD
	case 3, PkmnCenterUtil_EventScript_AtkMinusSpe
	case MULTI_B_PRESSED, EventScript_CancelPkmnUtil
	releaseall
	end
    
MoveRelearner_EventScript_GiveDefMint::
	message Text_PkmnCenterUtil_WhichMint
	waitmessage
	multichoicedefault 21, 2, MULTI_CHOICE_DEF_MINT, 0, FALSE
	switch VAR_RESULT
	case 0, PkmnCenterUtil_EventScript_DefMinusAtk
	case 1, PkmnCenterUtil_EventScript_DefMinusSpA
	case 2, PkmnCenterUtil_EventScript_DefMinusSpD
	case 3, PkmnCenterUtil_EventScript_DefMinusSpe
	case MULTI_B_PRESSED, EventScript_CancelPkmnUtil
	releaseall
	end

MoveRelearner_EventScript_GiveSpAMint::
	message Text_PkmnCenterUtil_WhichMint
	waitmessage
	multichoicedefault 21, 2, MULTI_CHOICE_SPA_MINT, 0, FALSE
	switch VAR_RESULT
	case 0, PkmnCenterUtil_EventScript_SpAMinusAtk
	case 1, PkmnCenterUtil_EventScript_SpAMinusDef
	case 2, PkmnCenterUtil_EventScript_SpAMinusSpD
	case 3, PkmnCenterUtil_EventScript_SpAMinusSpe
	case MULTI_B_PRESSED, EventScript_CancelPkmnUtil
	releaseall
	end

MoveRelearner_EventScript_GiveSpDMint::
	message Text_PkmnCenterUtil_WhichMint
	waitmessage
	multichoicedefault 21, 2, MULTI_CHOICE_SPD_MINT, 0, FALSE
	switch VAR_RESULT
	case 0, PkmnCenterUtil_EventScript_SpDMinusAtk
	case 1, PkmnCenterUtil_EventScript_SpDMinusDef
	case 2, PkmnCenterUtil_EventScript_SpDMinusSpA
	case 3, PkmnCenterUtil_EventScript_SpDMinusSpe
	case MULTI_B_PRESSED, EventScript_CancelPkmnUtil
	releaseall
	end

MoveRelearner_EventScript_GiveSpeMint::
	message Text_PkmnCenterUtil_WhichMint
	waitmessage
	multichoicedefault 21, 2, MULTI_CHOICE_SPE_MINT, 0, FALSE
	switch VAR_RESULT
	case 0, PkmnCenterUtil_EventScript_SpeMinusAtk
	case 1, PkmnCenterUtil_EventScript_SpeMinusDef
	case 2, PkmnCenterUtil_EventScript_SpeMinusSpA
	case 3, PkmnCenterUtil_EventScript_SpeMinusSpD
	case MULTI_B_PRESSED, EventScript_CancelPkmnUtil
	releaseall
	end

PkmnCenterUtil_EventScript_AtkMinusDef::
	giveitem ITEM_LONELY_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_AtkMinusSpA::
	giveitem ITEM_ADAMANT_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_AtkMinusSpD::
	giveitem ITEM_NAUGHTY_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_AtkMinusSpe::
	giveitem ITEM_BRAVE_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_DefMinusAtk::
	giveitem ITEM_BOLD_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_DefMinusSpA::
	giveitem ITEM_IMPISH_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_DefMinusSpD::
	giveitem ITEM_LAX_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_DefMinusSpe::
	giveitem ITEM_RELAXED_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpAMinusAtk::
	giveitem ITEM_MODEST_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpAMinusDef::
	giveitem ITEM_MILD_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpAMinusSpD::
	giveitem ITEM_RASH_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpAMinusSpe::
	giveitem ITEM_QUIET_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpDMinusAtk::
	giveitem ITEM_CALM_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpDMinusDef::
	giveitem ITEM_GENTLE_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpDMinusSpA::
	giveitem ITEM_CAREFUL_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpDMinusSpe::
	giveitem ITEM_SASSY_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpeMinusAtk::
	giveitem ITEM_TIMID_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpeMinusDef::
	giveitem ITEM_HASTY_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpeMinusSpA::
	giveitem ITEM_JOLLY_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_SpeMinusSpD::
	giveitem ITEM_NAIVE_MINT
	removeitem ITEM_HEART_SCALE
	releaseall
	end

MoveRelearner_EventScript_GivePatch::
	giveitem ITEM_ABILITY_PATCH
	removeitem ITEM_HEART_SCALE
	releaseall
	end

PkmnCenterUtil_EventScript_Cancel::
	releaseall
	end

EventScript_CancelPkmnUtil::
	releaseall
	end

Text_PkmnCenterUtil_SAP_Confirm:
	.string "Are you sure you want a Secret\n"
	.string "Ability Patch for a Heart Scale?$"

Text_PkmnCenterUtil_Mint_Confirm:
	.string "Are you sure you want a Nature\n"
	.string "Changing Mint for a Heart Scale?$"

Text_PkmnCenterUtil_WhatToDo:
	.string "What can I help you with?$"

Text_PkmnCenterUtil_WhichMint:
	.string "Which Mint would you like?$"

Text_PkmnCenterUtil_ExplainStatus:
    .string "What Pokemon should I status?$"

Text_PkmnCenterUtil_WhichEVItem:
	.string "Which EV Item do you want?$"

MoveRelearner_EventScript_MoveRelearner::
	lockall
	msgbox MoveRelearner_Text_TutorIntro, MSGBOX_DEFAULT
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, MoveRelearner_EventScript_ComeBackWithHeartScale
	goto MoveRelearner_EventScript_ChooseMon
	
MoveRelearner_EventScript_ChooseMon::
	msgbox MoveRelearner_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MoveRelearner_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MoveRelearner_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, MoveRelearner_EventScript_NoMoveToTeachMon
	msgbox MoveRelearner_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, MoveRelearner_EventScript_ChooseMon
	removeitem ITEM_HEART_SCALE
	end

MoveRelearner_EventScript_NoMoveToTeachMon::
	msgbox MoveRelearner_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto MoveRelearner_EventScript_ChooseMon
	end

MoveRelearner_EventScript_CantTeachEgg::
	msgbox MoveRelearner_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto MoveRelearner_EventScript_ChooseMon
	end

MoveRelearner_EventScript_ComeBackWithHeartScale::
	msgbox MoveRelearner_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

MoveRelearner_Text_ComeBackWithHeartScale:
	.string "You need a HEART SCALE to remember a move.$"

MoveRelearner_Text_TutorIntro:
	.string "I can remind a POKéMON a move\n"
	.string "in exchange for a HEART SCALE.$"

MoveRelearner_Text_TutorWhichMon:
	.string "Which POKéMON needs reminding?$"

MoveRelearner_Text_TeachWhichMove:
	.string "Which move should I teach?$"

MoveRelearner_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

MoveRelearner_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

MoveRelearner_Text_CantTeachEgg:
	.string "There isn't a single move that\n"
	.string "I can teach an EGG.$"
