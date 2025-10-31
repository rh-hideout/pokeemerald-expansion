# 1 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 2 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_MapScripts::
# 3 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
# 4 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
# 5 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
# 6 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.byte 0
# 7 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 8 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnLoad:
# 9 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
# 10 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 11 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 12 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_HideStevensNote::
# 13 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
# 14 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 15 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 16 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnTransition:
# 17 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call_if_eq VAR_STEVENS_HOUSE_STATE, 2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
# 18 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 19 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 20 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SetStevenPos::
# 21 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setobjectxyperm LOCALID_STEVENS_HOUSE_STEVEN, 6, 5
# 22 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setobjectmovementtype LOCALID_STEVENS_HOUSE_STEVEN, MOVEMENT_TYPE_FACE_UP
# 23 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 24 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 25 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnFrame:
# 26 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
# 27 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.2byte 0
# 28 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 29 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_StevenGivesDive::
# 30 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 31 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_WalkInPlaceFasterLeft
# 32 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 33 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	playse SE_PIN
# 34 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_ExclamationMark
# 35 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 36 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_Delay48
# 37 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 38 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
# 39 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 40 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
# 41 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	giveitem ITEM_HM_DIVE
# 42 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM_DIVE
# 43 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
# 44 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
# 45 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	closemessage
# 46 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	delay 20
# 47 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
# 48 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 49 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
# 50 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
# 51 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 52 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 53 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 54 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 55 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
# 56 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 57 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 58 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 59 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 60 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 61 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 62 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_in_place_faster_down
# 63 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	step_end
# 64 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 65 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Movement_StevenReturn:
# 66 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_up
# 67 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 68 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 69 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 70 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_in_place_faster_up
# 71 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	step_end
# 72 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 73 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
# 74 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 75 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
# 76 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
# 77 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
# 78 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 79 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 80 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
# 81 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
# 82 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 83 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 84 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 85 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_GiveBeldum::
# 86 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
# 87 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	givemon SPECIES_BELDUM, 5
# 88 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
# 89 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
# 90 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 91 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 92 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 93 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
# 94 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
# 95 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 96 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
# 97 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 98 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 99 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
# 100 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 101 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 102 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
# 103 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
# 104 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 105 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
# 106 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 107 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
# 108 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 109 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 110 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
# 111 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_TransferredToPC
# 112 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
# 113 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 114 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 115 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
# 116 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
# 117 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	removeobject LOCALID_STEVENS_HOUSE_BALL
# 118 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 119 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
# 120 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmessage
# 121 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitfanfare
# 122 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
# 123 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 124 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 125 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
# 126 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
# 127 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_BELDUM
# 128 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 129 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 130 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 131 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_RockDisplay::
# 132 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
# 133 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 134 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 135 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_Steven::
# 136 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
# 137 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 138 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 139 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_Letter::
# 140 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 141 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
# 142 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 143 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 144 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 145 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
@ Unused, leftover from RS
# 146 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_DiveItemBall::
# 147 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	finditem ITEM_HM_DIVE
# 148 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM_DIVE
# 149 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 150 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 151 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_YouveEarnedHMDive:
# 152 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}…\p"
# 153 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "As you can see, there's not much here,\n"
# 154 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "but this is my home.\p"
# 155 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Thank you for all that you've done.\p"
# 156 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "This is my token of appreciation.\n"
# 157 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's the HIDDEN MACHINE DIVE.\p"
# 158 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "No need to be shy--you've earned\n"
# 159 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "this HM.$"
# 160 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 161 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_ExplainDive:
# 162 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN: While you're using SURF, you\n"
# 163 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "should notice dark patches of water.\p"
# 164 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Use DIVE if you come to deep water\n"
# 165 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "like it. You'll drop to the seafloor.\p"
# 166 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "When you want to come back up, use\n"
# 167 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "DIVE again.\p"
# 168 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "In some places, it won't be possible\n"
# 169 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "for you to surface, though.$"
# 170 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 171 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
# 172 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN: Apparently, there's an\n"
# 173 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "underwater cavern between\l"
# 174 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "MOSSDEEP and SOOTOPOLIS.\p"
# 175 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "You know, the one that CAPT. STERN\n"
# 176 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "found in his submarine.$"
# 177 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 178 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
# 179 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} checked the POKé BALL.\p"
# 180 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It contained the POKéMON\n"
# 181 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "BELDUM.\p"
# 182 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Take the POKé BALL?$"
# 183 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 184 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_ObtainedBeldum:
# 185 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} obtained a BELDUM.$"
# 186 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 187 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
@ Unused
# 188 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
# 189 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "There is no space for another POKéMON.$"
# 190 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 191 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
# 192 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} left the POKé BALL where\n"
# 193 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "it was.$"
# 194 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 195 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_LetterFromSteven:
# 196 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's a letter.\p"
# 197 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "… … … … … …\p"
# 198 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "To {PLAYER}{KUN}…\p"
# 199 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I've decided to do a little soul-\n"
# 200 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "searching and train on the road.\p"
# 201 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I don't plan to return home for some\n"
# 202 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "time.\p"
# 203 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I have a favor to ask of you.\p"
# 204 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I want you to take the POKé BALL on\n"
# 205 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "the desk.\p"
# 206 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Inside it is a BELDUM, my favorite\n"
# 207 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "POKéMON.\p"
# 208 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I'm counting on you.\p"
# 209 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "May our paths cross someday.\p"
# 210 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN STONE$"
# 211 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 212 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
# 213 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's a collection of rare rocks and\n"
# 214 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "stones assembled by STEVEN.$"
