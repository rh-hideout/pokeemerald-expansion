# 1 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 2 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
.set LOCALID_CAPT_STERN, 1
# 3 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
.set LOCALID_ARCHIE, 2
# 4 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
.set LOCALID_GRUNT_1, 3
# 5 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
.set LOCALID_GRUNT_2, 4
# 6 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 7 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_MapScripts::
# 8 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.byte 0
# 9 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 10 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
# 11 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock
# 12 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	faceplayer
# 13 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
# 14 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 15 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, TRUE
# 16 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_GRUNT_1
# 17 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
# 18 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 19 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_GRUNT_2
# 20 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
# 21 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 22 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
# 23 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
# 24 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 25 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
# 26 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
# 27 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
# 28 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
# 29 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
# 30 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
# 31 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 32 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
# 33 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 34 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
# 35 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
# 36 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
# 37 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
# 38 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 39 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
# 40 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 41 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
# 42 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 43 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
# 44 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
# 45 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
# 46 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 47 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
# 48 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
# 49 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 50 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
# 51 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 52 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay 35
# 53 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_ARCHIE
# 54 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
# 55 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
# 56 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 57 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
# 58 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 59 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
# 60 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 61 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
# 62 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 63 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	savebgm MUS_DUMMY
# 64 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadedefaultbgm
# 65 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 66 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_ARCHIE
# 67 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 68 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 69 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 70 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay 30
# 71 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
# 72 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 73 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 74 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
# 75 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_0x8004, ITEM_DEVON_PARTS
# 76 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 77 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
# 78 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 79 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 80 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	playfanfare MUS_HEAL
# 81 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitfanfare
# 82 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	special HealPlayerParty
# 83 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	callnative UpdateFollowingPokemon
# 84 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_CAPT_STERN
# 85 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
# 86 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
# 87 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_DELIVERED_DEVON_GOODS
# 88 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
# 89 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 90 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
# 91 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 92 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	release
# 93 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 94 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 95 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
# 96 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 1
# 97 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 98 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 99 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
# 100 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 101 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 102 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 103 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 104 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
# 105 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
# 106 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 107 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 108 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 109 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
# 110 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
# 111 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 112 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 113 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 114 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
# 115 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
# 116 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 117 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 118 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 119 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
# 120 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 121 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 122 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_faster_left
# 123 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 124 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 125 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
# 126 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 127 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 128 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 129 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 130 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_faster_left
# 131 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 132 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 133 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_Unused:
# 134 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 135 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 136 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 137 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 138 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 139 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 140 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 141 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 142 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 143 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 144 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 145 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 146 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_8
# 147 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 148 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 149 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
# 150 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 151 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 152 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 153 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
# 154 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 155 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 156 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 157 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 158 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 159 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 160 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 161 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 162 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 163 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 164 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 165 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
# 166 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 167 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 168 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 169 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
# 170 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 171 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 172 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_faster_down
# 173 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 174 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 175 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
# 176 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 177 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 178 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 179 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 180 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 181 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 182 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 183 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 184 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
# 185 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock_facing_direction
# 186 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 187 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	unlock_facing_direction
# 188 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 189 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 190 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
# 191 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 192 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 193 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 194 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
# 195 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 196 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 197 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 198 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 199 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 200 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 201 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 202 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 203 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 204 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 205 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
# 206 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 207 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 208 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 209 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 210 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 211 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 212 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 213 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 214 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_8
# 215 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_fast_down
# 216 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_faster_up
# 217 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 218 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 219 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
# 220 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
# 221 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 222 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 223 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
# 224 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
# 225 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 226 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 227 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
# 228 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
# 229 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 230 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 231 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
# 232 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
# 233 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 234 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 235 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
# 236 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
# 237 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 238 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 239 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
# 240 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
# 241 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 242 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 243 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
# 244 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
# 245 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 246 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 247 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
# 248 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
# 249 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 250 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 251 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
# 252 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
# 253 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 254 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 255 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
# 256 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
# 257 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 258 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 259 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
# 260 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
# 261 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 262 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 263 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
# 264 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
# 265 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 266 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 267 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
# 268 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock
# 269 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	faceplayer
# 270 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
# 271 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 272 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 273 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 274 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	release
# 275 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 276 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 277 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
# 278 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Yes? If you're looking for STERN,\n"
# 279 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "that would be me.\p"
# 280 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah! Those must be the parts I ordered\n"
# 281 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "from MR. STONE of DEVON.\p"
# 282 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thank you! That's great!\n"
# 283 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We can prepare for our expedition now.$"
# 284 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 285 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
# 286 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Hehehe, hold it!\n"
# 287 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We'll take those parts!$"
# 288 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 289 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
# 290 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "CAPT. STERN: Wh-what?\n"
# 291 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Who are you people?$"
# 292 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 293 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
# 294 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 295 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Our BOSS wants those parts!\n"
# 296 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Shut your yap and fork them over!$"
# 297 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 298 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
# 299 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Awaaaah!\n"
# 300 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "A kid beat me!$"
# 301 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 302 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
# 303 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Oh, man, what a disaster…\n"
# 304 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The BOSS is going to be furious…$"
# 305 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 306 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
# 307 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Humph, sniveling wimp!\n"
# 308 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Let me take care of this!$"
# 309 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 310 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
# 311 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "What?!\n"
# 312 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I lost, too!$"
# 313 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 314 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
# 315 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Now what? If we don't get the parts,\n"
# 316 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "we're in for it!\p"
# 317 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Arrgh, I didn't count on being meddled\n"
# 318 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "with by some meddling kid!$"
# 319 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 320 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
# 321 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I came to see what was taking so\n"
# 322 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "long to snatch some parts, and you\l"
# 323 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "simps are held up by a mere child?$"
# 324 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 325 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
# 326 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We are TEAM AQUA,\n"
# 327 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "and we love the sea!\p"
# 328 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "And I am TEAM AQUA's leader,\n"
# 329 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "ARCHIE!\p"
# 330 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "What makes you interfere with us?\p"
# 331 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "…No! You can't be!\n"
# 332 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're not one of TEAM MAGMA?\p"
# 333 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Wait, that can't be right.\n"
# 334 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're not dressed for the part.\p"
# 335 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "… … … … … …\n"
# 336 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "… … … … … …\p"
# 337 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "POKéMON, people… All life depends on\n"
# 338 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the sea.\p"
# 339 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "So, TEAM AQUA is dedicated to\n"
# 340 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the expansion of the sea.\p"
# 341 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Don't you agree? What we are doing\n"
# 342 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "is a magnificent undertaking.\p"
# 343 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah, fine…\n"
# 344 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're still too young to understand\l"
# 345 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "our noble objective.\p"
# 346 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "But, I warn you, don't even consider\n"
# 347 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "interfering with our plans again.\p"
# 348 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The consequences will cost you\n"
# 349 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "dearly!\p"
# 350 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "And don't you forget it!$"
# 351 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 352 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
# 353 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "CAPT. STERN: You're…\n"
# 354 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah, okay, you're {PLAYER}{KUN}…\p"
# 355 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Anyway, that was a tense situation!\n"
# 356 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thank you for saving us!\p"
# 357 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Oh, yes, I almost forgot that you\n"
# 358 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "even brought the parts from DEVON!$"
# 359 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 360 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
# 361 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "CAPT. STERN: Whoops!\n"
# 362 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "There's no time to lose!\p"
# 363 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We have to set out on our ocean-floor\n"
# 364 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "expedition really soon.\p"
# 365 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thanks again, but now I've got\n"
# 366 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "to go!\p"
# 367 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Feel free to wander around and check\n"
# 368 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "out our facilities, though.$"
# 369 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 370 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
# 371 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I saw a model of a ship here.\p"
# 372 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It reminded me of the ABANDONED SHIP\n"
# 373 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "near DEWFORD TOWN…$"
# 374 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 375 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
# 376 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Don't you dare run around inside\n"
# 377 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the MUSEUM!$"
# 378 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 379 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
# 380 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Wow, the submarine's awesome!\n"
# 381 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I want to go for a ride!$"
# 382 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 383 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
# 384 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“WATER QUALITY SAMPLE 1,” the\n"
# 385 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "label says.\p"
# 386 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The sea is all connected, but the\n"
# 387 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "water seems to differ by region.$"
# 388 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 389 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
# 390 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“WATER QUALITY SAMPLE 2,” the\n"
# 391 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "label says.\p"
# 392 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Does the saltiness of seawater differ\n"
# 393 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "by region, too?$"
# 394 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 395 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
# 396 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "A rubber ball is expanding and\n"
# 397 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "shrinking.\p"
# 398 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“In the sea, the weight of water itself\n"
# 399 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "exerts pressure.\p"
# 400 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“In shallow water, the pressure is not\n"
# 401 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "very heavy.\p"
# 402 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“However, in extremely deep water,\n"
# 403 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the pressure can reach even tens of\l"
# 404 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "thousands of tons on a small area.”$"
# 405 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 406 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_HoennModel:
# 407 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“MODEL OF HOENN REGION”\p"
# 408 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a miniature diorama of the\n"
# 409 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "HOENN region.\p"
# 410 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Where is LITTLEROOT TOWN on this?$"
# 411 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 412 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
# 413 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a display on the flow of seawater.\p"
# 414 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“Near the bottom of the sea, water\n"
# 415 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "flows due to differences in such\l"
# 416 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "factors as temperature and salinity.”$"
# 417 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 418 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
# 419 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a display on the flow of seawater.\p"
# 420 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“Toward the surface, seawater flows\n"
# 421 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "as currents driven by the winds.”$"
# 422 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 423 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
# 424 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“THE FERRY S.S. TIDAL\p"
# 425 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A scale replica of the ship under\n"
# 426 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "construction at STERN'S SHIPYARD.”$"
# 427 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 428 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
# 429 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“SUBMARINE EXPLORER 1\p"
# 430 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of the high-performance\n"
# 431 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "ocean floor exploration submarine.”$"
# 432 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 433 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
# 434 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“SUBMERSIBLE POD\p"
# 435 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of a compact, unmanned\n"
# 436 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "pod for seafloor exploration.”$"
# 437 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 438 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
# 439 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“S.S. ANNE\p"
# 440 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of the luxury liner that\n"
# 441 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "circles the globe.”$"
