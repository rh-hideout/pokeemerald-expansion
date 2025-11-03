# 1 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 2 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_MapScripts::
# 3 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
# 4 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.byte 0
# 5 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 6 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_OnTransition:
# 7 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 8 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 9 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 10 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
# 11 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
# 12 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 13 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 14 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
# 15 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 16 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 17 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 18 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
# 19 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 20 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 21 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 22 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_BallScientist::
# 23 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 24 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 25 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 26 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
# 27 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
# 28 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 29 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 30 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 31 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
# 32 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
# 33 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 34 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 35 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 36 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
# 37 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 38 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 39 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 40 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
# 41 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
# 42 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 43 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 44 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 45 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
# 46 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
# 47 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 48 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 49 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 50 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
# 51 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 52 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 53 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 54 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
# 55 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 56 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 57 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 58 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
# 59 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 60 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 61 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
# 62 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
# 63 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 64 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 65 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
# 66 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 67 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
# 68 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 69 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 70 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 71 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ This whole section has needless duplication and could be condensed considerably
# 72 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
# 73 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 74 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 75 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 76 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 77 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 78 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 79 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 80 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 81 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 82 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 83 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 84 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 85 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 86 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
# 87 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
# 88 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 89 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 90 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 91 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
# 92 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 93 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 94 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 95 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
# 96 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 97 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 98 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 99 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 100 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 101 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 102 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 103 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 104 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 105 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 106 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 107 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 108 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 109 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
# 110 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
# 111 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 112 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 113 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 114 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
# 115 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 116 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 117 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 118 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
# 119 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 120 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 121 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 122 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 123 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
# 124 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 125 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 126 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 127 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 128 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
# 129 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
# 130 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
# 131 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 132 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 133 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_LileepReady::
# 134 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 135 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 136 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
# 137 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 138 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 139 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
# 140 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 141 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 142 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
# 143 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 144 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 145 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
# 146 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
# 147 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LILEEP, 20
# 148 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
# 149 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
# 150 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 151 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 152 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 153 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
# 154 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 155 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 156 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 157 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 158 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 159 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 160 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 161 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 162 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
# 163 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 164 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 165 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 166 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 167 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 168 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 169 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 170 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
# 171 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 172 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 173 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 174 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 175 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
# 176 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 177 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 178 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 179 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 180 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 181 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
# 182 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 183 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 184 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
# 185 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 186 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 187 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 188 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 189 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 190 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
# 191 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
# 192 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ANORITH, 20
# 193 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
# 194 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
# 195 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 196 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 197 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 198 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
# 199 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 200 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 201 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 202 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 203 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 204 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 205 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 206 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 207 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
# 208 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 209 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 210 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 211 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 212 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 213 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 214 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 215 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
# 216 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 217 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 218 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 219 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 220 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
# 221 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 222 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 223 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 224 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 225 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 226 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
# 227 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 228 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 229 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
# 230 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 231 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 232 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 233 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 234 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 235 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
# 236 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
# 237 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 238 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 17, 6, MULTI_FOSSIL, FALSE
# 239 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 240 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
# 241 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
# 242 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 243 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 244 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 245 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 246 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
# 247 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 248 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 249 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 250 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
# 251 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 252 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 253 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 254 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
# 255 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 256 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 257 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 258 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
# 259 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 260 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 261 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 262 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
# 263 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
# 264 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 265 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 266 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 267 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
# 268 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 269 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 270 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 271 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 272 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
# 273 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We're developing a device for talking\n"
# 274 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "with POKéMON.\p"
# 275 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But we haven't had much success…$"
# 276 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 277 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
# 278 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing new kinds of\n"
# 279 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS…\p"
# 280 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But I haven't made much headway…$"
# 281 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 282 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
# 283 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We finally made new kinds of\n"
# 284 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS!\p"
# 285 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The REPEAT BALL makes it easier to\n"
# 286 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "catch POKéMON you've caught before.\p"
# 287 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The TIMER BALL gets better at catching\n"
# 288 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON the longer a battle runs.\p"
# 289 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Both are proudly developed by\n"
# 290 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON CORPORATION.\p"
# 291 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please give them a try!$"
# 292 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 293 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_IMadePokenav:
# 294 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I made the POKéNAV!\p"
# 295 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 296 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "made something so great!$"
# 297 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 298 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
# 299 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, wow!\n"
# 300 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "That's a POKéNAV!\p"
# 301 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "It came about as a result of our\n"
# 302 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "PRESIDENT's desire to learn about\l"
# 303 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the feelings of POKéMON.\p"
# 304 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like me to describe its\n"
# 305 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "features in detail?\p"
# 306 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 307 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "trying the POKéNAV out.$"
# 308 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 309 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
# 310 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 311 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 312 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON…\p"
# 313 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 314 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 315 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
# 316 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
# 317 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "that resurrects POKéMON from fossils…\p"
# 318 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And, it's working!$"
# 319 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 320 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
# 321 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait! That thing you have there…\n"
# 322 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Is that a POKéMON fossil?\p"
# 323 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to bring that POKéMON\n"
# 324 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "back to life?\p"
# 325 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I can with my newly developed\n"
# 326 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "FOSSIL REGENERATOR.$"
# 327 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 328 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
# 329 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, is that so?\p"
# 330 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "DEVON's technological expertise\n"
# 331 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is outstanding, I tell you.$"
# 332 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 333 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
# 334 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, now that's a surprise!\n"
# 335 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have not one, but two, fossils?\p"
# 336 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Unfortunately, my machine can only\n"
# 337 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "regenerate one POKéMON at a time.\p"
# 338 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to pick one of your\n"
# 339 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "fossils for regeneration?$"
# 340 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 341 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
# 342 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Excellent!\n"
# 343 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Let's do this right away.\p"
# 344 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
# 345 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 346 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 347 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
# 348 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The FOSSIL REGENERATOR, which I made,\n"
# 349 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is incredible.\p"
# 350 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it has one drawback--it takes\n"
# 351 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "a long time to work.\p"
# 352 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "So, uh… How about you go for a stroll\n"
# 353 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "and look around for a while?$"
# 354 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 355 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
# 356 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Thanks for waiting!\p"
# 357 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Your fossilized POKéMON has been\n"
# 358 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "brought back to life!\p"
# 359 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The fossil was an ancient POKéMON.\n"
# 360 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{STR_VAR_2}, it was!$"
# 361 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 362 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
# 363 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
# 364 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 365 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 366 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ Unused
# 367 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
# 368 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Uh-oh, you've got too many POKéMON.\n"
# 369 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have no room for this one.$"
# 370 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 371 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
# 372 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 373 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "for the POKéNAV…\p"
# 374 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 375 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 376 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
# 377 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Well, now what shall I work on\n"
# 378 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "developing next?\p"
# 379 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Our company allows us to make our\n"
# 380 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "inspirations into reality.\p"
# 381 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "One couldn't ask for a better\n"
# 382 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "environment as an engineer.$"
