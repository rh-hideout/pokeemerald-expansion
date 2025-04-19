# 1 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 2 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
.set LOCALID_STEVEN, 1
# 3 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
.set LOCALID_BELDUM_BALL, 2
# 4 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 5 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_MapScripts::
# 6 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
# 7 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
# 8 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
# 9 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.byte 0
# 10 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 11 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnLoad:
# 12 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
# 13 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 14 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 15 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_HideStevensNote::
# 16 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
# 17 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 18 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 19 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnTransition:
# 20 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call_if_eq VAR_STEVENS_HOUSE_STATE, 2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
# 21 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 22 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 23 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SetStevenPos::
# 24 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 6, 5
# 25 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setobjectmovementtype LOCALID_STEVEN, MOVEMENT_TYPE_FACE_UP
# 26 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 27 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 28 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnFrame:
# 29 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
# 30 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.2byte 0
# 31 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 32 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_StevenGivesDive::
# 33 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 34 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterLeft
# 35 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 36 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	playse SE_PIN
# 37 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
# 38 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 39 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
# 40 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 41 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
# 42 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 43 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
# 44 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	giveitem ITEM_HM_DIVE
# 45 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM_DIVE
# 46 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
# 47 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
# 48 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	closemessage
# 49 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	delay 20
# 50 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
# 51 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 52 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
# 53 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
# 54 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 55 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 56 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 57 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 58 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
# 59 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 60 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 61 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 62 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 63 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 64 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 65 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_in_place_faster_down
# 66 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	step_end
# 67 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 68 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Movement_StevenReturn:
# 69 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_up
# 70 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 71 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 72 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 73 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_in_place_faster_up
# 74 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	step_end
# 75 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 76 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
# 77 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 78 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
# 79 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
# 80 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
# 81 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 82 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 83 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
# 84 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
# 85 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 86 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 87 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 88 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_GiveBeldum::
# 89 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
# 90 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	givemon SPECIES_BELDUM, 5
# 91 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
# 92 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
# 93 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 94 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 95 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 96 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
# 97 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
# 98 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 99 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
# 100 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 101 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 102 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
# 103 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 104 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 105 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
# 106 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
# 107 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 108 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
# 109 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 110 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
# 111 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 112 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 113 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
# 114 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_TransferredToPC
# 115 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
# 116 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 117 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 118 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
# 119 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
# 120 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	removeobject LOCALID_BELDUM_BALL
# 121 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 122 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
# 123 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmessage
# 124 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitfanfare
# 125 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
# 126 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 127 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 128 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
# 129 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
# 130 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_BELDUM
# 131 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 132 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 133 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 134 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_RockDisplay::
# 135 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
# 136 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 137 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 138 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_Steven::
# 139 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
# 140 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 141 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 142 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_Letter::
# 143 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 144 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
# 145 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 146 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 147 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 148 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
@ Unused, leftover from RS
# 149 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_DiveItemBall::
# 150 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	finditem ITEM_HM_DIVE
# 151 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM_DIVE
# 152 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 153 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 154 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_YouveEarnedHMDive:
# 155 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}…\p"
# 156 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "As you can see, there's not much here,\n"
# 157 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "but this is my home.\p"
# 158 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Thank you for all that you've done.\p"
# 159 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "This is my token of appreciation.\n"
# 160 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's the HIDDEN MACHINE DIVE.\p"
# 161 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "No need to be shy--you've earned\n"
# 162 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "this HM.$"
# 163 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 164 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_ExplainDive:
# 165 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN: While you're using SURF, you\n"
# 166 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "should notice dark patches of water.\p"
# 167 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Use DIVE if you come to deep water\n"
# 168 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "like it. You'll drop to the seafloor.\p"
# 169 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "When you want to come back up, use\n"
# 170 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "DIVE again.\p"
# 171 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "In some places, it won't be possible\n"
# 172 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "for you to surface, though.$"
# 173 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 174 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
# 175 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN: Apparently, there's an\n"
# 176 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "underwater cavern between\l"
# 177 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "MOSSDEEP and SOOTOPOLIS.\p"
# 178 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "You know, the one that CAPT. STERN\n"
# 179 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "found in his submarine.$"
# 180 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 181 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
# 182 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} checked the POKé BALL.\p"
# 183 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It contained the POKéMON\n"
# 184 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "BELDUM.\p"
# 185 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Take the POKé BALL?$"
# 186 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 187 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_ObtainedBeldum:
# 188 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} obtained a BELDUM.$"
# 189 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 190 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
@ Unused
# 191 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
# 192 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "There is no space for another POKéMON.$"
# 193 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 194 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
# 195 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} left the POKé BALL where\n"
# 196 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "it was.$"
# 197 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 198 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_LetterFromSteven:
# 199 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's a letter.\p"
# 200 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "… … … … … …\p"
# 201 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "To {PLAYER}{KUN}…\p"
# 202 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I've decided to do a little soul-\n"
# 203 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "searching and train on the road.\p"
# 204 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I don't plan to return home for some\n"
# 205 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "time.\p"
# 206 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I have a favor to ask of you.\p"
# 207 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I want you to take the POKé BALL on\n"
# 208 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "the desk.\p"
# 209 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Inside it is a BELDUM, my favorite\n"
# 210 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "POKéMON.\p"
# 211 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I'm counting on you.\p"
# 212 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "May our paths cross someday.\p"
# 213 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN STONE$"
# 214 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 215 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
# 216 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's a collection of rare rocks and\n"
# 217 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "stones assembled by STEVEN.$"
