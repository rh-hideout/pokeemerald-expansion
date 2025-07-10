LittlerootTown_MapScripts::
	.byte 0

LittlerootTown_EventScript_FatMan::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

LittlerootTown_EventScript_Boy::
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

LittlerootTown_EventScript_Twin::
	lock
	faceplayer
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger1::
	lockall
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_LITTLEROOT_MOM, 11, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger

LittlerootTown_EventScript_GiveRunningShoesTrigger::
	lockall
	setvar VAR_0x8008, 0
	addobject LOCALID_LITTLEROOT_MOM
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	call LittlerootTown_EventScript_GiveRunningShoes
	goto LittlerootTown_EventScript_HardcoreMode
	end

LittlerootTown_EventScript_EndMomSpeech::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome
	waitmovement 0
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	releaseall
	end

LittlerootTown_EventScript_EnableHardcore::
	setflag FLAG_HARDCORE_MODE_ENABLED
	goto LittlerootTown_EventScript_EndMomSpeech
	releaseall
	end


LittlerootTown_EventScript_HardcoreMode:
	msgbox LittlerootTown_Text_HardcoreMode, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LittlerootTown_EventScript_EndMomSpeech
	case YES, LittlerootTown_EventScript_EnableHardcore
	releaseall
	end

LittlerootTown_Text_HardcoreMode:
	.string "Would you like to enable HARDCORE mode?$"


LittlerootTown_Movement_MomReturnHome:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
LittlerootTown_Movement_MomApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_EventScript_SetReceivedRunningShoes::
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	removeobject LOCALID_LITTLEROOT_MOM
	releaseall
	end

LittlerootTown_EventScript_GiveRunningShoes::
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	giveitem ITEM_RARE_CANDY
	msgbox OldaleTown_Text_ExplainCandies, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RUNNING_SHOES
	giveitem ITEM_MAX_REPEL, 99
	closemessage
	return

OldaleTown_Text_ExplainCandies:
	.string "It's unlimted candies because people\n"
	.string "are very lazy. Instead, POKéMON\l"
	.string "don't gain any exp. The Rare Candies\l"
	.string "are in the Key Items section of your bag.$"

LittlerootTown_Text_WaitPlayer:
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes:
	.string "Here, honey! Wear these RUNNING SHOES.$"

LittlerootTown_Text_CanUsePCToStoreItems:
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab:
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out! Vewy Scawy.$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab:
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"

