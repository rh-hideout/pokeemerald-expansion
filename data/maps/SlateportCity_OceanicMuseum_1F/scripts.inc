# 1 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 2 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
.set LOCALID_FAMILIAR_GRUNT, 13
# 3 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 4 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_MapScripts::
# 5 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.byte 0
# 6 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 7 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
# 8 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
# 9 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 10 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 11 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
# 12 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	lockall
# 13 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 14 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 15 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
# 16 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 17 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 18 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
# 19 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	lockall
# 20 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 21 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 22 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
# 23 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 24 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 25 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
# 26 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	showmoneybox 0, 0
# 27 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
# 28 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
# 29 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	closemessage
# 30 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	hidemoneybox
# 31 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
# 32 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 33 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	releaseall
# 34 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 35 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 36 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
# 37 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	checkmoney 50
# 38 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
# 39 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	playse SE_SHOP
# 40 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	removemoney 50
# 41 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	updatemoneybox
# 42 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
# 43 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
# 44 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	hidemoneybox
# 45 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	releaseall
# 46 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 47 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 48 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
# 49 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
# 50 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 51 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	closemessage
# 52 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	hidemoneybox
# 53 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
# 54 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 55 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	releaseall
# 56 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 57 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 58 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
# 59 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
# 60 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
# 61 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	hidemoneybox
# 62 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	releaseall
# 63 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 64 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 65 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
# 66 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_down
# 67 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 68 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 69 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
# 70 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
# 71 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 72 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 73 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
# 74 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
# 75 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 76 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 77 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
# 78 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
# 79 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 80 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 81 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
# 82 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
# 83 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 84 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 85 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
# 86 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
# 87 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 88 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 89 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
# 90 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
# 91 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 92 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 93 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
# 94 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
# 95 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 96 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 97 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
# 98 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
# 99 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 100 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 101 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
# 102 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
# 103 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 104 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 105 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
# 106 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
# 107 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 108 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 109 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
# 110 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
# 111 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 112 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 113 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
# 114 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
# 115 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 116 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 117 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
# 118 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
# 119 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 120 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 121 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
# 122 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
# 123 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 124 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 125 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
# 126 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
# 127 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 128 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 129 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
# 130 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
# 131 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 132 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 133 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
# 134 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
# 135 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 136 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 137 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
# 138 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
# 139 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 140 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 141 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
# 142 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
# 143 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 144 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 145 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
# 146 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	lock
# 147 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	faceplayer
# 148 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay 8
# 149 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	playse SE_PIN
# 150 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
# 151 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 152 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
# 153 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 154 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
# 155 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	giveitem ITEM_TM_THIEF
# 156 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
# 157 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	setflag FLAG_RECEIVED_TM_THIEF
# 158 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
# 159 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	closemessage
# 160 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
# 161 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
# 162 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
# 163 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
# 164 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 165 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 166 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
# 167 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
# 168 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
# 169 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 170 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
# 171 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 172 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 173 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
# 174 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
# 175 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 176 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
# 177 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 178 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 179 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
# 180 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
# 181 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
# 182 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 183 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
# 184 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 185 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 186 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
# 187 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
# 188 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	playse SE_EXIT
# 189 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	removeobject LOCALID_FAMILIAR_GRUNT
# 190 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	release
# 191 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 192 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 193 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
# 194 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
# 195 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	release
# 196 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 197 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 198 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
# 199 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_16
# 200 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_8
# 201 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_4
# 202 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_in_place_faster_down
# 203 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 204 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 205 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
# 206 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_16
# 207 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_in_place_faster_down
# 208 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 209 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 210 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
# 211 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	face_down
# 212 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 213 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 214 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 215 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 216 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_8
# 217 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 218 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 219 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
# 220 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_right
# 221 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 222 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 223 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 224 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 225 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_8
# 226 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 227 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 228 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
# 229 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Welcome to the OCEANIC MUSEUM.\p"
# 230 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "The entrance fee is ¥50.\n"
# 231 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Would you like to enter?$"
# 232 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 233 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
# 234 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Please enjoy yourself.$"
# 235 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 236 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
# 237 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Oh? I'm sorry, but you don't seem to\n"
# 238 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "have enough money.$"
# 239 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 240 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
# 241 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Oh? You're with that group that\n"
# 242 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "went in earlier?\p"
# 243 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "You're the only one who's late.\n"
# 244 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "You'd better go catch up to them!$"
# 245 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 246 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
# 247 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "We, TEAM AQUA, exist for the good\n"
# 248 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "of all!$"
# 249 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 250 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
# 251 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "We were told to assemble here,\n"
# 252 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "so we did, but…\p"
# 253 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Our BOSS, the linchpin, isn't here.$"
# 254 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 255 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
# 256 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "If I ripped off the stuff here,\n"
# 257 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "would it make me rich?$"
# 258 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 259 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
# 260 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "What I learn here, I can put to use on\n"
# 261 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "nefarious deeds…$"
# 262 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 263 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
# 264 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "If our goons didn't bungle things\n"
# 265 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "in RUSTBORO, we wouldn't be here!$"
# 266 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 267 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
# 268 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I didn't have ¥50, so it took a long\n"
# 269 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "time getting by the receptionist.$"
# 270 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 271 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
# 272 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I want to learn about the sea and\n"
# 273 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "use that knowledge for battling.$"
# 274 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 275 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
# 276 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I get all giddy and gooey when\n"
# 277 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I see the sea!\p"
# 278 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "For me, CAPT. STERN is the number\n"
# 279 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "one role model!$"
# 280 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 281 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
# 282 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "The sea is vast without end, and\n"
# 283 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "infinitely deep…\p"
# 284 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "There must be many POKéMON that\n"
# 285 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "we don't know about.$"
# 286 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 287 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
# 288 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I want a sea POKéMON.\p"
# 289 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I think it would feel cool and nice\n"
# 290 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "to hug.$"
# 291 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 292 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
# 293 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Aiyeeeh!\n"
# 294 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "What are you doing here?\p"
# 295 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Me? I'm the TEAM AQUA member\n"
# 296 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "you thumped before, remember?\l"
# 297 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Back in RUSTURF TUNNEL?\p"
# 298 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Here, take this!\n"
# 299 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "You have to forgive me!$"
# 300 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 301 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
# 302 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "That TM, it suits you more than it\n"
# 303 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "does me.\p"
# 304 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Hope I never see you again!\n"
# 305 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Wahahaha!$"
# 306 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 307 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
# 308 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Awww, come on!\n"
# 309 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "You have to take this and let me go!$"
# 310 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 311 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
# 312 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "A blue fluid is spiraling inside\n"
# 313 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "a glass vessel.\p"
# 314 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“This is an experiment to create a\n"
# 315 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "WHIRLPOOL artificially using wind.”$"
# 316 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 317 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
# 318 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "A red ball is bobbing up and down\n"
# 319 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "inside a glass vessel.\p"
# 320 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“This is an experiment simulating a\n"
# 321 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "WATERFALL using the ball's buoyancy.”$"
# 322 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 323 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
# 324 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "It's a sample of soil from the ocean\n"
# 325 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "floor.\p"
# 326 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Over many years, the remains of\n"
# 327 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "life-forms settle at the bottom of\l"
# 328 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "the sea, making sedimentary layers.\p"
# 329 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“By analyzing these layers, the\n"
# 330 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "ancient past is revealed.”$"
# 331 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 332 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
# 333 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "It's a sample of beach sand.\p"
# 334 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Stones from mountains are washed\n"
# 335 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "down by rivers where they are\l"
# 336 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "chipped and ground down.\p"
# 337 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“They are reduced to grains and end\n"
# 338 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "up as sand on beaches.”$"
# 339 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 340 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
# 341 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“OCEANIC MINIFACT 1\n"
# 342 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Why is seawater blue?\p"
# 343 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Light is composed of many colors.\p"
# 344 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“When light passes through water,\n"
# 345 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "most kinds of light lose color.\p"
# 346 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“However, blue light retains its\n"
# 347 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "color, making the sea appear blue.”$"
# 348 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 349 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
# 350 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“OCEANIC MINIFACT 2\n"
# 351 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Why is the sea salty?\p"
# 352 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Seawater contains dissolved salt in\n"
# 353 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "the form of sodium and chlorine ions.\p"
# 354 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“These ions leech out of rocks\n"
# 355 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "and are carried out to sea by rain.\p"
# 356 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“The concentration of dissolved salt\n"
# 357 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "makes the sea salty.”$"
# 358 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 359 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
# 360 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“OCEANIC MINIFACT 3\n"
# 361 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Which is bigger? The sea or land?\p"
# 362 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“The sea covers about 70% of\n"
# 363 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "the planet, and the rest is land.\p"
# 364 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“The sea is therefore more than twice\n"
# 365 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "the size of land.”$"
# 366 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 367 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
# 368 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "It's a fossil with wavy ridges on it.\p"
# 369 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Soil on the ocean floor gets scoured\n"
# 370 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "by the tide.\p"
# 371 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“The flowing seawater marks the soil\n"
# 372 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "with small ridges and valleys.\p"
# 373 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“If this soil becomes fossilized, it is\n"
# 374 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "called a ripple mark.”$"
# 375 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 376 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
# 377 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "A strange machine is rotating under\n"
# 378 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "a glass dome.\p"
# 379 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Maybe it's for measuring the depth\n"
# 380 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "of something…$"
