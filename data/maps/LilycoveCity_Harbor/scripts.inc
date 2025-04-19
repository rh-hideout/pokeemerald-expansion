# 1 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 2 "data/maps/LilycoveCity_Harbor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/LilycoveCity_Harbor/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 4 "data/maps/LilycoveCity_Harbor/scripts.pory"
.set LOCALID_FERRY_SAILOR, 4
# 5 "data/maps/LilycoveCity_Harbor/scripts.pory"
.set LOCALID_BRINEY, 5
# 6 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 7 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_MapScripts::
# 8 "data/maps/LilycoveCity_Harbor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
# 9 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.byte 0
# 10 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 11 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_OnTransition:
# 12 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setescapewarp MAP_LILYCOVE_CITY, 12, 33
# 13 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 14 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 15 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryAttendant::
# 16 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock
# 17 "data/maps/LilycoveCity_Harbor/scripts.pory"
	faceplayer
# 18 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_FerryUnavailable
# 19 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEonTicketState
# 20 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetAuroraTicketState
# 21 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetOldSeaMapState
# 22 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetMysticTicketState
# 23 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket
# 24 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetHasTicketsState
# 25 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_C, 2, LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime
# 26 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_B, 1, LilycoveCity_Harbor_EventScript_EonTicketFirstTime
# 27 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_B, 2, LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime
# 28 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_B, 4, LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime
# 29 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_B, 8, LilycoveCity_Harbor_EventScript_MysticTicketFirstTime
# 30 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_ne VAR_TEMP_B, 0, LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime
# 31 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets
# 32 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 33 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 34 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ First goto_if_eq is unnecessary; identical scripts
# 35 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets::
# 36 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_A, 0, LilycoveCity_Harbor_EventScript_NoEventTickets
# 37 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 38 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
# 39 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 40 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 41 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 42 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 43 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect::
# 44 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 0
# 45 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
# 46 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 47 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special GetLilycoveSSTidalSelection
# 48 "data/maps/LilycoveCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 49 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 0, LilycoveCity_Harbor_EventScript_GoToSlateport
# 50 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 1, LilycoveCity_Harbor_EventScript_GoToBattleFrontier
# 51 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIsland
# 52 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRock
# 53 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIsland
# 54 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIsland
# 55 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 6, LilycoveCity_Harbor_EventScript_ExitSailSelect
# 56 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitSailSelect
# 57 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 58 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 59 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSouthernIsland::
# 60 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 61 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
# 62 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 63 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 64 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 65 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 66 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToNavelRock::
# 67 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 68 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
# 69 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 70 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 71 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 72 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 73 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBirthIsland::
# 74 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 75 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
# 76 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 77 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 78 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 79 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 80 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToFarawayIsland::
# 81 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 82 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 83 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 84 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 85 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 86 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 87 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSlateport::
# 88 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
# 89 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 90 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
# 91 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 92 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 93 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 94 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 95 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 96 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 97 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBattleFrontier::
# 98 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 99 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 100 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 101 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 102 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 103 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 104 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 105 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 106 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetEonTicketState::
# 107 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 0
# 108 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Common_EventScript_NopReturn
# 109 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_EON_TICKET
# 110 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
# 111 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 1
# 112 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_EON_TICKET, Common_EventScript_NopReturn
# 113 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 2
# 114 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 115 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 116 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetAuroraTicketState::
# 117 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 0
# 118 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, Common_EventScript_NopReturn
# 119 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 120 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
# 121 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 1
# 122 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_AURORA_TICKET, Common_EventScript_NopReturn
# 123 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 2
# 124 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 125 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 126 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetOldSeaMapState::
# 127 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 0
# 128 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
# 129 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_OLD_SEA_MAP
# 130 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
# 131 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 1
# 132 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, Common_EventScript_NopReturn
# 133 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 2
# 134 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 135 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 136 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetMysticTicketState::
# 137 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 0
# 138 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, Common_EventScript_NopReturn
# 139 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 140 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
# 141 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 1
# 142 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, Common_EventScript_NopReturn
# 143 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 2
# 144 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 145 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 146 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket::
# 147 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_B, 0
# 148 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_E, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket
# 149 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_D, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket
# 150 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_C, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap
# 151 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket
# 152 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 153 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 154 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket::
# 155 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 1
# 156 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 157 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 158 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket::
# 159 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 2
# 160 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 161 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 162 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap::
# 163 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 4
# 164 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 165 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 166 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket::
# 167 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 8
# 168 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 169 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 170 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetHasTicketsState::
# 171 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_A, 0
# 172 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_E, 1, LilycoveCity_Harbor_EventScript_SetHasEonTicket
# 173 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_D, 1, LilycoveCity_Harbor_EventScript_SetHasAuroraTicket
# 174 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_C, 1, LilycoveCity_Harbor_EventScript_SetHasOldSeaMap
# 175 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, LilycoveCity_Harbor_EventScript_SetHasMysticTicket
# 176 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 177 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 178 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasEonTicket::
# 179 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 1
# 180 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 181 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 182 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasAuroraTicket::
# 183 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 2
# 184 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 185 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 186 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasOldSeaMap::
# 187 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 4
# 188 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 189 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 190 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasMysticTicket::
# 191 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 8
# 192 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 193 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 194 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_EonTicketFirstTime::
# 195 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_EON_TICKET
# 196 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 197 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 198 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 199 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_DEFAULT
# 200 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
# 201 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 202 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 203 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime::
# 204 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 205 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 206 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
# 207 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 208 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 209 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 210 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 211 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime::
# 212 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 213 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 214 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 215 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 216 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
# 217 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
# 218 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 219 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 220 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime::
# 221 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 222 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 223 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
# 224 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 225 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 226 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 227 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 228 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime::
# 229 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_OLD_SEA_MAP
# 230 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ShowOldSeaMap, MSGBOX_DEFAULT
# 231 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 232 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 233 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
# 234 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 235 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
# 236 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 237 "data/maps/LilycoveCity_Harbor/scripts.pory"
	playse SE_PIN
# 238 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_ExclamationMark
# 239 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 240 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_Delay48
# 241 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 242 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth
# 243 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast
# 244 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addobject LOCALID_BRINEY
# 245 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth
# 246 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast
# 247 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_BrineyHoldOnASecond, MSGBOX_DEFAULT
# 248 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth
# 249 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast
# 250 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_BrineyLetsSail, MSGBOX_DEFAULT
# 251 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 252 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth
# 253 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast
# 254 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 255 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 256 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 257 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 258 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 259 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 260 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 261 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime::
# 262 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 263 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 264 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 265 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 266 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 267 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 268 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 269 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MysticTicketFirstTime::
# 270 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 271 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 272 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 273 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 274 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
# 275 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
# 276 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 277 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 278 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime::
# 279 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 280 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 281 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
# 282 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 283 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 284 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 285 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 286 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime::
# 287 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 288 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 289 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 290 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message EventTicket_Text_OddTicketsWhereTo
# 291 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 292 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 1
# 293 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
# 294 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 295 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special GetLilycoveSSTidalSelection
# 296 "data/maps/LilycoveCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 297 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
# 298 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
# 299 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
# 300 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime
# 301 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 6, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
# 302 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
# 303 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 304 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 305 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 306 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect::
# 307 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 308 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 309 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
# 310 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 311 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 312 "data/maps/LilycoveCity_Harbor/scripts.pory"
	removeobject LOCALID_FERRY_SAILOR
# 313 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 314 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterDown
# 315 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 316 "data/maps/LilycoveCity_Harbor/scripts.pory"
	showobjectat LOCALID_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
# 317 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 318 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 319 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 320 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 321 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 322 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetEventTicketSailor::
# 323 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 324 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 325 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 326 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
# 327 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 60
# 328 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addobject LOCALID_FERRY_SAILOR
# 329 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 330 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_FacePlayer
# 331 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 332 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 333 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 334 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithSailor::
# 335 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
# 336 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 337 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 338 "data/maps/LilycoveCity_Harbor/scripts.pory"
	removeobject LOCALID_FERRY_SAILOR
# 339 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
# 340 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
# 341 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 342 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 343 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 344 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 345 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 346 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 347 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryUnavailable::
# 348 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_DEFAULT
# 349 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 350 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 351 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 352 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoEventTickets::
# 353 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 354 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
# 355 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 356 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 357 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 358 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 359 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 360 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoTicket::
# 361 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_NoTicket, MSGBOX_DEFAULT
# 362 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 363 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 364 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 365 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 366 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSlateportUnused::
# 367 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
# 368 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 369 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
# 370 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 371 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 372 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 373 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 374 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 375 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 376 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 377 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBattleFrontierUnused::
# 378 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 379 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 380 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 381 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 382 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 383 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 384 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 385 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 386 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind::
# 387 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo
# 388 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 389 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 390 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 391 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 392 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerry::
# 393 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_PleaseBoard, MSGBOX_DEFAULT
# 394 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 395 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 396 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 397 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 398 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
# 399 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
# 400 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
# 401 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 402 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 403 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 404 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 405 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 406 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 407 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast::
# 408 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryEast
# 409 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 410 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 411 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 412 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth::
# 413 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth
# 414 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 415 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 416 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 417 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_ExitSailSelect::
# 418 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 419 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 420 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 421 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 422 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardFerryEast:
# 423 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 424 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 425 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 426 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 427 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth:
# 428 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 429 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 430 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 431 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_UnusedBoardFerry:
# 432 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 433 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 434 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 435 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_Sailor::
# 436 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock
# 437 "data/maps/LilycoveCity_Harbor/scripts.pory"
	faceplayer
# 438 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_SailorFerryAvailable
# 439 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailorFerryUnavailable, MSGBOX_DEFAULT
# 440 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 441 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 442 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 443 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SailorFerryAvailable::
# 444 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailorFerryAvailable, MSGBOX_DEFAULT
# 445 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 446 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 447 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 448 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth::
# 449 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayNorth
# 450 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 451 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 452 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 453 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast::
# 454 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayEast
# 455 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 456 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 457 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 458 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorOutOfWayNorth:
# 459 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_right
# 460 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock_facing_direction
# 461 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_left
# 462 "data/maps/LilycoveCity_Harbor/scripts.pory"
	unlock_facing_direction
# 463 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 464 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 465 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorOutOfWayEast:
# 466 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock_facing_direction
# 467 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_down
# 468 "data/maps/LilycoveCity_Harbor/scripts.pory"
	unlock_facing_direction
# 469 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 470 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 471 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth::
# 472 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterLeft
# 473 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 474 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 475 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 476 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast::
# 477 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterDown
# 478 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 479 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 480 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 481 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth::
# 482 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterDown
# 483 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 484 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 485 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 486 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast::
# 487 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterLeft
# 488 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 489 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 490 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 491 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth::
# 492 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
# 493 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth
# 494 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth
# 495 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 496 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 497 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 498 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast::
# 499 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
# 500 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast
# 501 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast
# 502 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 503 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 504 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 505 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_BrineyBoardFerry:
# 506 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 507 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_8
# 508 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 509 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 510 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 511 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth:
# 512 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 513 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 514 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 515 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 516 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 517 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 518 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth:
# 519 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 520 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 521 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 522 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 523 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 524 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 525 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 526 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 527 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 528 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast:
# 529 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 530 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 531 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 532 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 533 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 534 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 535 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 536 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast:
# 537 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 538 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 539 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 540 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 541 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 542 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 543 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 544 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 545 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_FerryUnavailable:
# 546 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I beg your pardon?\n"
# 547 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "You're looking for a ship?\p"
# 548 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
# 549 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "available at present…$"
# 550 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 551 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_MayISeeYourTicket:
# 552 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 553 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "May I see your TICKET?$"
# 554 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 555 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_NoTicket:
# 556 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "{PLAYER} doesn't have the TICKET…\p"
# 557 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I'm terribly sorry.\p"
# 558 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "You must have a TICKET to board\n"
# 559 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "the ferry.$"
# 560 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 561 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_FlashTicketWhereTo:
# 562 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "{PLAYER} flashed the TICKET.\p"
# 563 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 564 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "And where would you like to go?$"
# 565 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 566 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailAnotherTime:
# 567 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Please sail with us another time!$"
# 568 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 569 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SlateportItIs:
# 570 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "SLATEPORT CITY it is, then!$"
# 571 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 572 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_BattleFrontierItIs:
# 573 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "BATTLE FRONTIER it is, then!$"
# 574 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 575 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_PleaseBoard:
# 576 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 577 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "departure.$"
# 578 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 579 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo:
# 580 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Then, where would you like to go?$"
# 581 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 582 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailorFerryUnavailable:
# 583 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Until they finish making the ferry,\n"
# 584 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "we sailors have nothing to do…\p"
# 585 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I wish they'd get a move on, the folks\n"
# 586 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "at the SHIPYARD in SLATEPORT.$"
# 587 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 588 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailorFerryAvailable:
# 589 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "The ferry S.S. TIDAL is finally in\n"
# 590 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "operation.\p"
# 591 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "The folks at the SHIPYARD in SLATEPORT\n"
# 592 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "must've worked extra hard.\p"
# 593 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Well, it's my turn to get busy now!$"
