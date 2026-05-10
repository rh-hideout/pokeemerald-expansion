@##################################################################
@ Cut
@##################################################################

@ Interact with cuttable tree
EventScript_CutTree::
	    lockall
    checkfieldmove FIELD_MOVE_CUT
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, PARTY_SIZE, EventScript_CheckTreeCantCut
    goto_if_eq VAR_0x8004, PARTY_SIZE + 1, EventScript_CutTreeWithItem

    @ --- A Pokémon that can learn the move was found ---
    bufferpartymonnick STR_VAR_1, VAR_0x8004
    buffermovename STR_VAR_2, MOVE_CUT
	setfieldeffectargument 0, VAR_0x8004
    msgbox Text_WantToCutWithPokemon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
    msgbox Text_MonHelpedCut, MSGBOX_DEFAULT
    closemessage
    goto EventScript_CutTreeCommon

EventScript_CutTreeWithItem::
    @ --- The key item was found ---
    bufferitemname STR_VAR_2, ITEM_CUT_TOOL
    msgbox Text_WantToCutWithItem, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    closemessage
    setfieldeffectargument 1, TRUE @ Indicate that an item was used
    goto EventScript_CutTreeCommon

EventScript_CutTreeCommon::
    @ --- This is the shared logic that performs the cut ---
    isfollowerfieldmoveuser VAR_0x8004
    setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
    dofieldeffect FLDEFF_USE_CUT_ON_TREE
    waitstate
    @ fallthrough to CutTreeDown

EventScript_CutTreeDown::
    setflag FLAG_SAFE_FOLLOWER_MOVEMENT
    call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
    applymovement VAR_LAST_TALKED, Movement_CutTreeDown
    waitmovement 0
    removeobject VAR_LAST_TALKED
    releaseall
    end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
    releaseall
    end

EventScript_CancelCut::
	closemessage
    releaseall
    end

@ Use cut from party menu (for the bag item)
EventScript_UseCut::
    lockall
    goto EventScript_CutTreeCommon

Movement_CutTreeDown:
    cut_tree
    step_end

Text_WantToCutWithPokemon:
    .string "This tree can be CUT down.\n"
    .string "Want {STR_VAR_1} to help?$"

Text_MonHelpedCut:
    .string "{STR_VAR_1} helped you clear the way!$"

Text_WantToCutWithItem:
    .string "This tree can be CUT down.\n"
    .string "Use the {STR_VAR_2}?$"

Text_CantCut:
    .string "This tree looks like it can be\n"
    .string "CUT down!$"

Text_MonUsedFieldMove:
    .string "{STR_VAR_1} used {STR_VAR_2}!$"

@##################################################################
@ Rock Smash
@##################################################################

@ Interact with smashable rock
EventScript_RockSmash::
    lockall
    checkfieldmove FIELD_MOVE_ROCK_SMASH
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, PARTY_SIZE, EventScript_CantSmashRock
    goto_if_eq VAR_0x8004, PARTY_SIZE + 1, EventScript_RockSmashWithItem

    @ --- Pokémon with learnable move was found ---
    bufferpartymonnick STR_VAR_1, VAR_0x8004
    setfieldeffectargument 0, VAR_0x8004
    buffermovename STR_VAR_2, MOVE_ROCK_SMASH
    msgbox Text_WantToSmashWithPokemon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
    msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
    closemessage
    goto EventScript_RockSmashCommon

EventScript_RockSmashWithItem::
    @ --- The key item was found ---
    bufferitemname STR_VAR_2, ITEM_ROCK_SMASH_TOOL
    setfieldeffectargument 0, PARTY_SIZE
    msgbox Text_WantToSmashWithItem, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
    msgbox Text_PlayerUsedRockHammer, MSGBOX_DEFAULT
    closemessage
    setfieldeffectargument 1, TRUE @ Set arg 1 to TRUE to signal item use; prevents Pokémon animation
    goto EventScript_RockSmashCommon

@ Use rock smash from party menu
EventScript_UseRockSmash::
    lockall
    goto EventScript_RockSmashCommon

EventScript_RockSmashCommon:
    @ check if follower should use the field move
    isfollowerfieldmoveuser VAR_0x8004
    setfieldeffectargument 3, VAR_0x8004 @ Pass follower result to field effect to skip pose
    dofieldeffect FLDEFF_USE_ROCK_SMASH
    waitstate
    @ fallthrough to EventScript_SmashRock

EventScript_SmashRock::
    setflag FLAG_SAFE_FOLLOWER_MOVEMENT
    call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
    applymovement VAR_LAST_TALKED, Movement_SmashRock
    waitmovement 0
    removeobject VAR_LAST_TALKED
    specialvar VAR_RESULT, TryUpdateRusturfTunnelState
    goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
    special RockSmashWildEncounter
    goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
    waitstate
    releaseall
    end

@ --- Text ---
Text_WantToSmashWithPokemon:
    .string "This rock may be breakable.\n"
    .string "Want {STR_VAR_1} to help?$"

Text_WantToSmashWithItem:
    .string "This rock may be breakable.\n"
    .string "Use the {STR_VAR_2}?$"

Text_PlayerUsedRockHammer:
    .string "You used the {STR_VAR_2} and\n"
	.string "smashed the rock!$"

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"

Text_CantSmash:
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"

@##################################################################
@ Strength
@##################################################################

EventScript_StrengthBoulder::
    lockall
    goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
    checkfieldmove FIELD_MOVE_STRENGTH
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, PARTY_SIZE, EventScript_CantStrength
    goto_if_eq VAR_0x8004, PARTY_SIZE + 1, EventScript_StrengthWithItem

    @ --- Pokémon with learnable move was found ---
    bufferpartymonnick STR_VAR_1, VAR_0x8004
    setfieldeffectargument 0, VAR_0x8004
    msgbox Text_WantToUseStrengthWithPokemon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
    closemessage
    dofieldeffect FLDEFF_USE_STRENGTH
    waitstate
    goto EventScript_ActivateStrength

EventScript_StrengthWithItem::
    @ --- The key item was found ---
    bufferitemname STR_VAR_2, ITEM_STRENGTH_TOOL
    setfieldeffectargument 0, PARTY_SIZE @ No Pokémon is involved
    msgbox Text_WantToUseStrengthWithItem, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
    closemessage
    setfieldeffectargument 1, TRUE @ Signal item use to skip Pokémon animation
    dofieldeffect FLDEFF_USE_STRENGTH
    waitstate
    goto EventScript_ActivateStrength

@ Entry point for using Strength from a menu.
EventScript_UseStrength::
	lockall
    dofieldeffect FLDEFF_USE_STRENGTH
    waitstate
    goto EventScript_ActivateStrength
    end

@ Sets the flag that allows boulders to be pushed on the current map.
EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
    msgbox Text_StrengthActivated, MSGBOX_DEFAULT
    releaseall
    end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
    releaseall
    end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthAlreadyActivated, MSGBOX_DEFAULT
    releaseall
    end

EventScript_CancelStrength::
    closemessage
    releaseall
    end

Text_WantToUseStrengthWithPokemon:
    .string "It's a big boulder.\n"
    .string "Want {STR_VAR_1} to help move it?$"

Text_WantToUseStrengthWithItem:
    .string "It's a big boulder.\n"
    .string "Use the {STR_VAR_2}?$"

Text_StrengthActivated:
    .string "STRENGTH made it possible to move\n"
    .string "boulders around!$"

Text_StrengthAlreadyActivated:
    .string "STRENGTH is already in effect.$"

Text_CantStrength:
	.string "It's a big boulder, but a POKéMON\n"
    .string "may be able to push it aside.$"

@##################################################################
@ Waterfall
@##################################################################

EventScript_UseWaterfall::
	lockall
    checkfieldmove FIELD_MOVE_WATERFALL
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, PARTY_SIZE, EventScript_CantWaterfall
    goto_if_eq VAR_0x8004, PARTY_SIZE + 1, EventScript_UseWaterfallWithItem

    @ --- Pokémon with learnable move was found ---
    bufferpartymonnick STR_VAR_1, VAR_0x8004
    setfieldeffectargument 0, VAR_0x8004
    msgbox Text_WantToUseWaterfallWithPokemon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
    msgbox Text_MonHelpedWaterfall, MSGBOX_DEFAULT
    goto EventScript_UseWaterfallCommon

EventScript_UseWaterfallWithItem::
    @ --- The key item was found ---
    bufferitemname STR_VAR_2, ITEM_WATERFALL_TOOL
    setfieldeffectargument 0, PARTY_SIZE
    msgbox Text_WantToUseWaterfallWithItem, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
    msgbox Text_PlayerUsedWaterfallItem, MSGBOX_DEFAULT
    setfieldeffectargument 1, TRUE @ Set arg 1 to TRUE to signal item use; prevents Pokémon animation
    goto EventScript_UseWaterfallCommon

EventScript_UseWaterfallCommon:
    hidefollowernpc
    dofieldeffect FLDEFF_USE_WATERFALL
    callnative FollowerNPC_WarpSetEnd
    goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
    @ fallthrough to EventScript_EndWaterfall

EventScript_EndWaterfall::
	releaseall
	end

Text_WantToUseWaterfallWithPokemon:
    .string "It's a large waterfall.\n"
    .string "Want {STR_VAR_1} to help you ascend?$"
Text_MonHelpedWaterfall:
    .string "{STR_VAR_1} helped you scale the waterfall!$"
Text_WantToUseWaterfallWithItem:
    .string "It's a large waterfall.\n"
    .string "Use the {STR_VAR_2}?$"
Text_PlayerUsedWaterfallItem:
    .string "You used the {STR_VAR_2} to scale the waterfall!$"

Text_CantWaterfall:
    .string "A wall of water is crashing down with\n"
    .string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"

@##################################################################
@ Dive
@##################################################################

EventScript_UseDive::
	lockall
    checkfieldmove FIELD_MOVE_DIVE
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, PARTY_SIZE, EventScript_CantDive
    goto_if_eq VAR_0x8004, PARTY_SIZE + 1, EventScript_UseDiveWithItem

    @ --- Pokémon with learnable move was found ---
    bufferpartymonnick STR_VAR_1, VAR_0x8004
    setfieldeffectargument 0, VAR_0x8004
    msgbox Text_WantToDiveWithPokemon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_EndDive
    msgbox Text_MonUsedDive, MSGBOX_DEFAULT
    goto EventScript_UseDiveCommon

EventScript_UseDiveWithItem::
    @ --- The key item was found ---
    bufferitemname STR_VAR_2, ITEM_DIVE_TOOL
    setfieldeffectargument 0, PARTY_SIZE
    msgbox Text_WantToDiveWithItem, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_EndDive
    msgbox Text_PlayerUsedDiveItem, MSGBOX_DEFAULT
    setfieldeffectargument 1, TRUE @ Set arg 1 to TRUE to signal item use
    goto EventScript_UseDiveCommon

EventScript_UseDiveCommon:
    hidefollowernpc
    dofieldeffect FLDEFF_USE_DIVE
    goto EventScript_EndDive
    end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
    releaseall
    end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
    checkfieldmove FIELD_MOVE_DIVE
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, PARTY_SIZE, EventScript_CantSurface
    goto_if_eq VAR_0x8004, PARTY_SIZE + 1, EventScript_UseSurfaceWithItem

    @ --- Pokémon with learnable move was found ---
    bufferpartymonnick STR_VAR_1, VAR_0x8004
    setfieldeffectargument 0, VAR_0x8004
    msgbox Text_WantToSurfaceWithPokemon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
    msgbox Text_MonUsedDive, MSGBOX_DEFAULT
    goto EventScript_UseSurfaceCommon

EventScript_UseSurfaceWithItem::
    @ --- The key item was found ---
    bufferitemname STR_VAR_2, ITEM_DIVE_TOOL
    setfieldeffectargument 0, PARTY_SIZE
    msgbox Text_WantToSurfaceWithItem, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
    msgbox Text_PlayerUsedDiveItem, MSGBOX_DEFAULT
    setfieldeffectargument 1, TRUE @ Set arg 1 to TRUE to signal item use
    goto EventScript_UseSurfaceCommon

EventScript_UseSurfaceCommon:
    hidefollowernpc
    dofieldeffect FLDEFF_USE_DIVE
    goto EventScript_EndSurface
    end

EventScript_CantSurface::
	lockall
    msgbox Text_CantSurface, MSGBOX_DEFAULT
    goto EventScript_EndSurface
    end

EventScript_EndSurface::
	callnative SetFollowerNPCSurfSpriteAfterDive
EventScript_NoSurface::
    releaseall
    end

@ --- New Text ---
Text_WantToDiveWithPokemon:
    .string "The sea is deep here.\n"
    .string "Want {STR_VAR_1} to help you DIVE?$"

Text_WantToDiveWithItem:
    .string "The sea is deep here.\n"
    .string "Use the {STR_VAR_2}?$"

Text_PlayerUsedDiveItem:
    .string "You used the {STR_VAR_2}.$"

Text_WantToSurfaceWithPokemon:
    .string "Light is filtering down from above.\n"
    .string "Want {STR_VAR_1} to help you surface?$"

Text_WantToSurfaceWithItem:
    .string "Light is filtering down from above.\n"
    .string "Use the {STR_VAR_2}?$"

@##################################################################
@ Other Field Moves
@##################################################################

EventScript_DigCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ Pass follower result to field effect to skip pose
	dofieldeffect FLDEFF_USE_DIG
	waitstate
	end

@ This is for the special Dig spot in the Sealed Chamber.
EventScript_DigSealedChamber:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	callnative DoBrailleDigEffect
	releaseall
	end

@ Use Dig from party menu
EventScript_UseDig::
	lockall
	goto EventScript_DigCommon

@ This is the common script for cutting grass in the overworld.
EventScript_CutGrassCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ Pass follower result to field effect to skip pose
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
	waitstate

@ Entry point for using Cut on grass from a menu.
EventScript_UseCutGrass::
	lockall
	goto EventScript_CutGrassCommon

Text_CantDive:
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to go underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} used DIVE.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to surface.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"

EventScript_UseDefog::
	lockall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_DEFOG
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	waitmovement 0
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_DEFOG
	waitstate
	releaseall
	end

EventScript_UseRockClimb::
	lockall
	checkfieldmove FIELD_MOVE_ROCK_CLIMB
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantRockClimb
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToRockClimb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndRockClimb
	msgbox Text_MonUsedRockClimb, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_CLIMB
	waitstate
	goto EventScript_EndRockClimb
	end

EventScript_CantRockClimb::
	msgbox Text_CantRockClimb, MSGBOX_DEFAULT

EventScript_EndRockClimb::
	releaseall
	end

Text_WantToRockClimb:
    .string "The cliff is steep.\n"
    .string "Would you like to use Rock Climb?$"

Text_MonUsedRockClimb:
    .string "{STR_VAR_1} used Rock Climb!$"

Text_CantRockClimb:
    .string "The cliff is steep.\n"
    .string "A Pokémon may be able to climb it.$"

@##################################################################
@ Follower-related Scripts
@##################################################################

@ Common script for having the follower use the field move.
EventScript_FollowerFieldMove:
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
	specialvar VAR_0x8006, GetPlayerFacingDirection
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
	@ Swap follower and player
	call EventScript_FollowerSwap
	@ Face follower in direction and jump
	switch VAR_0x8006
	case DIR_NORTH, EventScript_FollowerJumpNorth
	case DIR_EAST, EventScript_FollowerJumpEast
	case DIR_SOUTH, EventScript_FollowerJumpSouth
	case DIR_WEST, EventScript_FollowerJumpWest
EventScript_FollowerFieldMoveEnd:
	return

EventScript_FollowerSwap:
	switch VAR_0x8005
	case DIR_NORTH, EventScript_FollowerMoveNorth
	case DIR_EAST, EventScript_FollowerMoveEast
	case DIR_SOUTH, EventScript_FollowerMoveSouth
	case DIR_WEST, EventScript_FollowerMoveWest
	return

EventScript_FollowerMoveNorth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

EventScript_FollowerMoveEast:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

EventScript_FollowerMoveSouth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_FollowerMoveWest:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

EventScript_FollowerJumpNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
	waitmovement 0
	return

EventScript_FollowerJumpEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
	waitmovement 0
	return

EventScript_FollowerJumpSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
	waitmovement 0
	return

EventScript_FollowerJumpWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
	waitmovement 0
	return

EventScript_EndSmash::
	releaseall
	end

Movement_WalkUp:
	walk_up
	step_end

Movement_JumpUp:
	jump_in_place_up
	step_end

Movement_WalkRight:
	walk_right
	step_end

Movement_JumpRight:
	jump_in_place_right
	step_end

Movement_WalkDown:
	walk_down
	step_end

Movement_JumpDown:
	jump_in_place_down
	step_end

Movement_WalkLeft:
	walk_left
	step_end

Movement_JumpLeft:
	jump_in_place_left
	step_end
