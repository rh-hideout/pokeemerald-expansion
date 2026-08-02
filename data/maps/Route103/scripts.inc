Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition:
	call Route103_EventScript_SetupCounterpartGfx
	call ProfBirch_EventScript_UpdateLocation
	end

@ =============================================================================
@ ROUTE 103 — COUNTERPART GRAPHICS
@ =============================================================================

Route103_EventScript_SetupCounterpartGfx:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, Route103_SetCounterpartBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, Route103_SetCounterpartMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, Route103_SetCounterpartCeleste
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, Route103_SetCounterpartHiiro
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, Route103_SetCounterpartAleciya
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, Route103_SetCounterpartAster

    @ Safe fallback.
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
    return


Route103_SetCounterpartBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
    return


Route103_SetCounterpartMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
    return


Route103_SetCounterpartCeleste:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    return


Route103_SetCounterpartHiiro:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    return


Route103_SetCounterpartAleciya:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    return


Route103_SetCounterpartAster:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    return


Route103_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return




@ =============================================================================
@ OPTIONAL BATTLE CHOICE
@ =============================================================================

Route103_EventScript_OfferOptionalBattle:
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION, Route103_EventScript_OfferBattleCompanion
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL, Route103_EventScript_OfferBattleRival
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR, Route103_EventScript_OfferBattleMentor
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL, Route103_EventScript_OfferBattleFoil

    goto Route103_EventScript_OfferBattleUnknown


Route103_EventScript_OfferBattleCompanion:
    msgbox Route103_Text_OfferBattleCompanion, MSGBOX_DEFAULT
    goto Route103_EventScript_ShowBattleChoice


Route103_EventScript_OfferBattleRival:
    msgbox Route103_Text_OfferBattleRival, MSGBOX_DEFAULT
    goto Route103_EventScript_ShowBattleChoice


Route103_EventScript_OfferBattleMentor:
    msgbox Route103_Text_OfferBattleMentor, MSGBOX_DEFAULT
    goto Route103_EventScript_ShowBattleChoice


Route103_EventScript_OfferBattleFoil:
    msgbox Route103_Text_OfferBattleFoil, MSGBOX_DEFAULT
    goto Route103_EventScript_ShowBattleChoice


Route103_EventScript_OfferBattleUnknown:
    msgbox Route103_Text_OfferBattleUnknown, MSGBOX_DEFAULT
    goto Route103_EventScript_ShowBattleChoice


Route103_EventScript_ShowBattleChoice:
    yesnobox 20, 8
    compare VAR_RESULT, YES
    goto_if_eq Route103_EventScript_BattleAccepted

    goto Route103_EventScript_BattleDeclined

@ =============================================================================
@ BATTLE DECLINED
@ =============================================================================

Route103_EventScript_BattleDeclined:
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION, Route103_EventScript_DeclinedCompanion
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL, Route103_EventScript_DeclinedRival
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR, Route103_EventScript_DeclinedMentor
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL, Route103_EventScript_DeclinedFoil

    goto Route103_EventScript_DeclinedUnknown


Route103_EventScript_DeclinedCompanion:
    msgbox Route103_Text_DeclinedCompanion, MSGBOX_DEFAULT
    goto Route103_EventScript_FinishCounterpartEncounter


Route103_EventScript_DeclinedRival:
    msgbox Route103_Text_DeclinedRival, MSGBOX_DEFAULT
    goto Route103_EventScript_FinishCounterpartEncounter


Route103_EventScript_DeclinedMentor:
    msgbox Route103_Text_DeclinedMentor, MSGBOX_DEFAULT
    goto Route103_EventScript_FinishCounterpartEncounter


Route103_EventScript_DeclinedFoil:
    msgbox Route103_Text_DeclinedFoil, MSGBOX_DEFAULT
    goto Route103_EventScript_FinishCounterpartEncounter


Route103_EventScript_DeclinedUnknown:
    msgbox Route103_Text_DeclinedUnknown, MSGBOX_DEFAULT
    goto Route103_EventScript_FinishCounterpartEncounter

@ =============================================================================
@ BATTLE ACCEPTED
@
@ Temporary test battle. This will be replaced by the six-way identity router.
@ =============================================================================

Route103_EventScript_BattleAccepted:
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION, Route103_EventScript_AcceptedCompanion
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL, Route103_EventScript_AcceptedRival
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR, Route103_EventScript_AcceptedMentor
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL, Route103_EventScript_AcceptedFoil

    goto Route103_EventScript_AcceptedUnknown


Route103_EventScript_Rival::
    goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, Route103_EventScript_CounterpartAfterEncounter

    lockall
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0

    goto Route103_EventScript_OfferOptionalBattle


Route103_EventScript_CounterpartAfterEncounter:
    lock
    faceplayer
    msgbox Route103_Text_CounterpartAfterEncounter, MSGBOX_DEFAULT
    release
    end

Route103_EventScript_AcceptedCompanion:
    msgbox Route103_Text_AcceptedCompanion, MSGBOX_DEFAULT
    goto Route103_EventScript_StartTemporaryBattle


Route103_EventScript_AcceptedRival:
    msgbox Route103_Text_AcceptedRival, MSGBOX_DEFAULT
    goto Route103_EventScript_StartTemporaryBattle


Route103_EventScript_AcceptedMentor:
    msgbox Route103_Text_AcceptedMentor, MSGBOX_DEFAULT
    goto Route103_EventScript_StartTemporaryBattle


Route103_EventScript_AcceptedFoil:
    msgbox Route103_Text_AcceptedFoil, MSGBOX_DEFAULT
    goto Route103_EventScript_StartTemporaryBattle


Route103_EventScript_AcceptedUnknown:
    msgbox Route103_Text_AcceptedUnknown, MSGBOX_DEFAULT
    goto Route103_EventScript_StartTemporaryBattle


Route103_EventScript_StartTemporaryBattle:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, Route103_EventScript_BattleBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, Route103_EventScript_BattleMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, Route103_EventScript_BattleCeleste
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, Route103_EventScript_BattleHiiro
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, Route103_EventScript_BattleAleciya
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, Route103_EventScript_BattleAster
    goto Route103_EventScript_BattleCeleste


Route103_EventScript_BattleCeleste:
    trainerbattle_no_intro TRAINER_CELESTE_ROUTE_103, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle


Route103_EventScript_BattleHiiro:
    trainerbattle_no_intro TRAINER_HIIRO_ROUTE_103, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle


Route103_EventScript_BattleAleciya:
    trainerbattle_no_intro TRAINER_ALECIYA_ROUTE_103, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle


Route103_EventScript_BattleAster:
    trainerbattle_no_intro TRAINER_ASTER_ROUTE_103, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle

Route103_EventScript_BattleBrendan:
    switch VAR_STARTER_MON
    case 0, Route103_EventScript_BattleBrendanTreecko
    case 1, Route103_EventScript_BattleBrendanTorchic
    case 2, Route103_EventScript_BattleBrendanMudkip
    goto Route103_EventScript_BattleBrendanTreecko


Route103_EventScript_BattleMay:
    switch VAR_STARTER_MON
    case 0, Route103_EventScript_BattleMayTreecko
    case 1, Route103_EventScript_BattleMayTorchic
    case 2, Route103_EventScript_BattleMayMudkip
    goto Route103_EventScript_BattleMayTreecko


Route103_EventScript_BattleBrendanTreecko:
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle

Route103_EventScript_BattleBrendanTorchic:
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle

Route103_EventScript_BattleBrendanMudkip:
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle


Route103_EventScript_BattleMayTreecko:
    trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle

Route103_EventScript_BattleMayTorchic:
    trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle

Route103_EventScript_BattleMayMudkip:
    trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_TemporaryCounterpartDefeated
    goto Route103_EventScript_AfterOptionalBattle

Route103_EventScript_AfterOptionalBattle:
    msgbox Route103_Text_AfterOptionalBattle, MSGBOX_DEFAULT
    goto Route103_EventScript_FinishCounterpartEncounter

@ =============================================================================
@ SHARED ENCOUNTER FINISH
@ =============================================================================

Route103_EventScript_FinishCounterpartEncounter:
    goto Route103_EventScript_RivalExit



Route103_EventScript_RivalMay::
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko
	case 1, Route103_EventScript_StartMayBattleTorchic
	case 2, Route103_EventScript_StartMayBattleMudkip
	end


Route103_EventScript_RivalBrendan::
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko
	case 1, Route103_EventScript_StartBrendanBattleTorchic
	case 2, Route103_EventScript_StartBrendanBattleMudkip
	end

Route103_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle::
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle::
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd::
	removeobject LOCALID_ROUTE103_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

Route103_Movement_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

Route103_Movement_RivalExit1:
	walk_down
	step_end

Route103_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

Route103_EventScript_Boy::
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man::
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign::
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_Text_MayRoute103Pokemon:
	.string "OAK'S GRANDCHILD: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"

Route103_Text_MayLetsBattle:
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

Route103_Text_MayDefeated:
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

Route103_Text_MayTimeToHeadBack:
	.string "OAK'S GRANDCHILD: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route103_Text_BrendanRoute103Pokemon:
	.string "OAK'S GRANDCHILD: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"

Route103_Text_BrendanLetsBattle:
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

Route103_Text_BrendanDefeated:
	.string "Huh, {PLAYER}, you're not too shabby.$"

Route103_Text_BrendanTimeToHeadBack:
	.string "OAK'S GRANDCHILD: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route103_Text_ShouldHaveBroughtPotion:
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale:
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign:
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"

@ =============================================================================
@ OPTIONAL BATTLE OFFERS
@ =============================================================================

Route103_Text_OfferBattleCompanion:
    .string "Since we're both here...\p"
    .string "Want to train together?$"


Route103_Text_OfferBattleRival:
    .string "Enough talking.\p"
    .string "Are you going to battle me or not?$"


Route103_Text_OfferBattleMentor:
    .string "Would you like to test what you've\n"
    .string "learned in a battle?$"


Route103_Text_OfferBattleFoil:
    .string "Think you can actually beat me?$"


Route103_Text_OfferBattleUnknown:
    .string "Would you...\n"
    .string "maybe want to battle?$"


@ =============================================================================
@ BATTLE ACCEPTED RESPONSES
@ =============================================================================

Route103_Text_AcceptedCompanion:
    .string "Yes!\p"
    .string "Let's have some fun with it!$"


Route103_Text_AcceptedRival:
    .string "Good.\p"
    .string "Show me what you've got.$"


Route103_Text_AcceptedMentor:
    .string "All right.\p"
    .string "Show me what you've learned.$"


Route103_Text_AcceptedFoil:
    .string "Hmph.\p"
    .string "Try not to embarrass yourself.$"


Route103_Text_AcceptedUnknown:
    .string "Oh!\p"
    .string "Okay, then.\n"
    .string "Let's do it.$"


@ =============================================================================
@ BATTLE DECLINED RESPONSES
@ =============================================================================

Route103_Text_DeclinedCompanion:
    .string "No problem!\p"
    .string "We can train together whenever\n"
    .string "you're ready.$"


Route103_Text_DeclinedRival:
    .string "Seriously?\p"
    .string "Fine.\n"
    .string "But I'm not forgetting this.$"


Route103_Text_DeclinedMentor:
    .string "Knowing when you're not ready is\n"
    .string "important too.\p"
    .string "Just don't let caution become fear.$"


Route103_Text_DeclinedFoil:
    .string "That's what I expected.$"


Route103_Text_DeclinedUnknown:
    .string "Oh.\p"
    .string "That's fine.\n"
    .string "I was only asking.$"


@ =============================================================================
@ TEMPORARY BATTLE TEXT
@ =============================================================================

Route103_Text_TemporaryCounterpartDefeated:
    .string "Okay...\n"
    .string "You're better than I expected.$"


Route103_Text_AfterOptionalBattle:
    .string "Oak is probably waiting for us.\p"
    .string "We should head back to the LAB.$"

Route103_Text_CounterpartAfterEncounter:
    .string "Oak is probably waiting for us.\p"
    .string "We should head back soon.$"