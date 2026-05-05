@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	goto_if_unset FLAG_RECEIVED_HM_CUT, EventScript_CheckTreeCantCut
	goto_if_unset FLAG_BADGE02_GET, EventScript_CheckTreeCantCut
	checkpartymove MOVE_CUT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_CutTreeCommon:
	isfollowerfieldmoveuser VAR_0x8004
EventScript_CutTreeDown:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	playse SE_M_CUT
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	goto EventScript_CutTreeCommon

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!\p"
	.string "Would you like to CUT it?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!$"

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	goto EventScript_RockSmashCommon

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	checkpartymove MOVE_ROCK_SMASH
	goto_if_unset FLAG_BADGE01_GET, EventScript_CantSmashRock
	goto_if_unset FLAG_RECEIVED_HM_ROCK_SMASH, EventScript_CantSmashRock
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_RockSmashCommon:
	isfollowerfieldmoveuser VAR_0x8004
EventScript_SmashRock:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	random 20
	call_if_eq VAR_RESULT, 1, EventScript_RockSmashHeartscale
	call_if_eq VAR_RESULT, 2, EventScript_RockSmashBlueShard
	call_if_eq VAR_RESULT, 3, EventScript_RockSmashRedShard
	call_if_eq VAR_RESULT, 4, EventScript_RockSmashGreenShard
	call_if_eq VAR_RESULT, 5, EventScript_RockSmashYellowShard
	waitstate
	releaseall
	end

@ Interact with headbutt tree
EventScript_Headbutt::
	lockall
	goto_if_unset FLAG_GET_HEADBUTT, EventScript_CantHeadbuttTree
	checkpartymove MOVE_HEADBUTT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantHeadbuttTree
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_MonUsedHeadbutt, MSGBOX_DEFAULT
	closemessage
EventScript_HeadbuttCommon:
	isfollowerfieldmoveuser VAR_0x8004
EventScript_HeadbuttTree:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_HeadbuttTree
	playse SE_M_HEADBUTT
	waitmovement 0
	special RockSmashWildEncounter
	goto EventScript_EndHeadbutt
	waitstate
	releaseall
	end

Movement_HeadbuttTree:
	rock_smash_break
	step_end

EventScript_CantHeadbuttTree::
	msgbox Text_CantHeadbutt, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelHeadbutt::
	closemessage
	releaseall
	end

EventScript_EndHeadbutt::
	releaseall
	end

Text_MonUsedHeadbutt::
	.string "{STR_VAR_1} used HEADBUTT!$"

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
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

EventScript_FollowerMoveEast:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

EventScript_FollowerMoveSouth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_FollowerMoveWest:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkLeft
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
	random 20
	call_if_eq VAR_RESULT, 1, EventScript_RockSmashHeartscale
	call_if_eq VAR_RESULT, 2, EventScript_RockSmashBlueShard
	call_if_eq VAR_RESULT, 3, EventScript_RockSmashRedShard
	call_if_eq VAR_RESULT, 4, EventScript_RockSmashGreenShard
	call_if_eq VAR_RESULT, 5, EventScript_RockSmashYellowShard
	releaseall
	end

EventScript_RockSmashHeartscale::
	giveitem ITEM_HEART_SCALE
	return

EventScript_RockSmashBlueShard::
	giveitem ITEM_BLUE_SHARD
	return

EventScript_RockSmashRedShard::
	giveitem ITEM_RED_SHARD
	return

EventScript_RockSmashGreenShard::
	giveitem ITEM_GREEN_SHARD
	return

EventScript_RockSmashYellowShard::
	giveitem ITEM_YELLOW_SHARD
	return

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

Text_WantToHeadbutt:
	.string "This tree may house POKéMON.\n"
	.string "Would you like to use HEADBUTT?$"

Text_CantHeadbutt:
	.string "It's a small tree, but a wild\n"
	.string "POKéMON may be living within.$"

EventScript_StrengthBoulder::
	lockall
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantStrength
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} used STRENGTH!$"

Text_CantStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated:
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"

EventScript_UseWaterfall::
	lockall
	goto_if_unset FLAG_BADGE08_GET, EventScript_CantWaterfall
	checkpartymove MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	callnative FollowerNPC_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"

Text_MonUsedWaterfall:
	.string "{STR_VAR_1} used WATERFALL.$"

EventScript_UseDive::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
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
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

@HnS Whirlpool
EventScript_Whirlpool::
	lockall
	goto_if_unset FLAG_BADGE07_GET, EventScript_CantWhirlpool
	playse SE_M_WATERFALL
	goto_if_eq VAR_FACING, DIR_NORTH, EventScript_WhirlpoolGoNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, EventScript_WhirlpoolGoSouth
	goto_if_eq VAR_FACING, DIR_EAST, EventScript_WhirlpoolGoEast
	goto_if_eq VAR_FACING, DIR_WEST, EventScript_WhirlpoolGoWest
	releaseall
	end

EventScript_WhirlpoolGoNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolNorth
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolSouth
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoEast::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolEast
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoWest::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolWest
	waitmovement 0
	releaseall
	end

EventScript_CantWhirlpool::
	msgbox Text_CantWhirlpool, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Movement_WhirlpoolNorth:
	slide_up
	slide_up
	slide_up
	step_end

Movement_WhirlpoolSouth:
	slide_down
	slide_down
	slide_down
	step_end

Movement_WhirlpoolEast:
	slide_right
	slide_right
	slide_right
	step_end

Movement_WhirlpoolWest:
	slide_left
	slide_left
	slide_left
	step_end

Text_CantWhirlpool:
	.string "The water is swirling and spinning\n"
	.string "around with a mighty roar.$"

EventScript_DigCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_DIG
	waitstate
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

EventScript_CutGrassCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
	waitstate

@ Use Cut grass from party menu
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
	.string "{STR_VAR_1} used WHIRLPOOL.$"

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

SetTimeEncounters::
	callnative SetTimeBasedEncounters
	return
