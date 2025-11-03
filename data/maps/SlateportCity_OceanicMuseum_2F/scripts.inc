# 1 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 2 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_MapScripts::
# 3 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.byte 0
# 4 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 5 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
# 6 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock
# 7 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	faceplayer
# 8 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
# 9 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 10 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, TRUE
# 11 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
# 12 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
# 13 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 14 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
# 15 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
# 16 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 17 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
# 18 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
# 19 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 20 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
# 21 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
# 22 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
# 23 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
# 24 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
# 25 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
# 26 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 27 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
# 28 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 29 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
# 30 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
# 31 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
# 32 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
# 33 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 34 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
# 35 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 36 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
# 37 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 38 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
# 39 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
# 40 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
# 41 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 42 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
# 43 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
# 44 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 45 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
# 46 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 47 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay 35
# 48 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
# 49 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
# 50 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
# 51 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 52 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
# 53 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 54 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
# 55 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 56 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
# 57 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 58 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	savebgm MUS_DUMMY
# 59 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadedefaultbgm
# 60 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 61 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
# 62 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
# 63 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
# 64 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 65 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay 30
# 66 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
# 67 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 68 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 69 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
# 70 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_0x8004, ITEM_DEVON_PARTS
# 71 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 72 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
# 73 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 74 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 75 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	playfanfare MUS_HEAL
# 76 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitfanfare
# 77 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	special HealPlayerParty
# 78 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	callnative UpdateFollowingPokemon
# 79 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
# 80 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
# 81 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
# 82 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_DELIVERED_DEVON_GOODS
# 83 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
# 84 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 85 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
# 86 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 87 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	release
# 88 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 89 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 90 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
# 91 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 1
# 92 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 93 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 94 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
# 95 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 96 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 97 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 98 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 99 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
# 100 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
# 101 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 102 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 103 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 104 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
# 105 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
# 106 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 107 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 108 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 109 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
# 110 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
# 111 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 112 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 113 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 114 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
# 115 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 116 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 117 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_faster_left
# 118 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 119 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 120 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
# 121 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 122 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 123 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 124 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 125 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_faster_left
# 126 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 127 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 128 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_Unused:
# 129 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 130 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 131 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 132 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 133 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 134 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 135 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 136 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 137 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 138 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 139 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 140 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 141 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_8
# 142 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 143 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 144 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
# 145 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 146 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 147 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 148 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
# 149 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 150 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 151 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 152 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 153 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 154 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 155 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 156 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 157 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 158 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 159 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 160 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
# 161 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 162 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 163 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 164 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
# 165 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 166 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 167 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_faster_down
# 168 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 169 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 170 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
# 171 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 172 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 173 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 174 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 175 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 176 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 177 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 178 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 179 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
# 180 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock_facing_direction
# 181 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 182 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	unlock_facing_direction
# 183 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 184 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 185 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
# 186 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 187 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 188 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 189 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
# 190 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 191 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 192 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 193 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 194 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 195 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 196 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 197 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 198 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 199 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 200 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
# 201 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 202 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 203 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 204 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 205 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 206 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 207 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 208 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 209 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_8
# 210 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_fast_down
# 211 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_faster_up
# 212 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 213 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 214 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
# 215 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
# 216 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 217 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 218 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
# 219 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
# 220 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 221 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 222 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
# 223 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
# 224 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 225 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 226 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
# 227 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
# 228 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 229 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 230 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
# 231 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
# 232 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 233 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 234 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
# 235 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
# 236 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 237 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 238 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
# 239 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
# 240 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 241 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 242 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
# 243 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
# 244 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 245 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 246 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
# 247 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
# 248 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 249 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 250 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
# 251 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
# 252 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 253 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 254 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
# 255 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
# 256 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 257 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 258 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
# 259 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
# 260 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 261 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 262 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
# 263 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock
# 264 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	faceplayer
# 265 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
# 266 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 267 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 268 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 269 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	release
# 270 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 271 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 272 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
# 273 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Yes? If you're looking for STERN,\n"
# 274 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "that would be me.\p"
# 275 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah! Those must be the parts I ordered\n"
# 276 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "from MR. STONE of DEVON.\p"
# 277 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thank you! That's great!\n"
# 278 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We can prepare for our expedition now.$"
# 279 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 280 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
# 281 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Hehehe, hold it!\n"
# 282 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We'll take those parts!$"
# 283 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 284 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
# 285 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "CAPT. STERN: Wh-what?\n"
# 286 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Who are you people?$"
# 287 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 288 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
# 289 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 290 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Our BOSS wants those parts!\n"
# 291 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Shut your yap and fork them over!$"
# 292 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 293 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
# 294 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Awaaaah!\n"
# 295 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "A kid beat me!$"
# 296 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 297 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
# 298 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Oh, man, what a disaster…\n"
# 299 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The BOSS is going to be furious…$"
# 300 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 301 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
# 302 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Humph, sniveling wimp!\n"
# 303 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Let me take care of this!$"
# 304 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 305 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
# 306 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "What?!\n"
# 307 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I lost, too!$"
# 308 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 309 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
# 310 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Now what? If we don't get the parts,\n"
# 311 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "we're in for it!\p"
# 312 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Arrgh, I didn't count on being meddled\n"
# 313 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "with by some meddling kid!$"
# 314 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 315 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
# 316 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I came to see what was taking so\n"
# 317 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "long to snatch some parts, and you\l"
# 318 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "simps are held up by a mere child?$"
# 319 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 320 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
# 321 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We are TEAM AQUA,\n"
# 322 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "and we love the sea!\p"
# 323 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "And I am TEAM AQUA's leader,\n"
# 324 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "ARCHIE!\p"
# 325 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "What makes you interfere with us?\p"
# 326 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "…No! You can't be!\n"
# 327 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're not one of TEAM MAGMA?\p"
# 328 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Wait, that can't be right.\n"
# 329 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're not dressed for the part.\p"
# 330 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "… … … … … …\n"
# 331 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "… … … … … …\p"
# 332 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "POKéMON, people… All life depends on\n"
# 333 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the sea.\p"
# 334 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "So, TEAM AQUA is dedicated to\n"
# 335 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the expansion of the sea.\p"
# 336 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Don't you agree? What we are doing\n"
# 337 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "is a magnificent undertaking.\p"
# 338 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah, fine…\n"
# 339 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're still too young to understand\l"
# 340 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "our noble objective.\p"
# 341 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "But, I warn you, don't even consider\n"
# 342 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "interfering with our plans again.\p"
# 343 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The consequences will cost you\n"
# 344 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "dearly!\p"
# 345 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "And don't you forget it!$"
# 346 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 347 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
# 348 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "CAPT. STERN: You're…\n"
# 349 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah, okay, you're {PLAYER}{KUN}…\p"
# 350 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Anyway, that was a tense situation!\n"
# 351 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thank you for saving us!\p"
# 352 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Oh, yes, I almost forgot that you\n"
# 353 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "even brought the parts from DEVON!$"
# 354 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 355 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
# 356 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "CAPT. STERN: Whoops!\n"
# 357 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "There's no time to lose!\p"
# 358 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We have to set out on our ocean-floor\n"
# 359 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "expedition really soon.\p"
# 360 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thanks again, but now I've got\n"
# 361 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "to go!\p"
# 362 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Feel free to wander around and check\n"
# 363 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "out our facilities, though.$"
# 364 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 365 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
# 366 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I saw a model of a ship here.\p"
# 367 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It reminded me of the ABANDONED SHIP\n"
# 368 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "near DEWFORD TOWN…$"
# 369 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 370 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
# 371 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Don't you dare run around inside\n"
# 372 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the MUSEUM!$"
# 373 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 374 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
# 375 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Wow, the submarine's awesome!\n"
# 376 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I want to go for a ride!$"
# 377 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 378 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
# 379 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“WATER QUALITY SAMPLE 1,” the\n"
# 380 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "label says.\p"
# 381 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The sea is all connected, but the\n"
# 382 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "water seems to differ by region.$"
# 383 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 384 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
# 385 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“WATER QUALITY SAMPLE 2,” the\n"
# 386 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "label says.\p"
# 387 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Does the saltiness of seawater differ\n"
# 388 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "by region, too?$"
# 389 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 390 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
# 391 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "A rubber ball is expanding and\n"
# 392 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "shrinking.\p"
# 393 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“In the sea, the weight of water itself\n"
# 394 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "exerts pressure.\p"
# 395 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“In shallow water, the pressure is not\n"
# 396 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "very heavy.\p"
# 397 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“However, in extremely deep water,\n"
# 398 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the pressure can reach even tens of\l"
# 399 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "thousands of tons on a small area.”$"
# 400 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 401 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_HoennModel:
# 402 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“MODEL OF HOENN REGION”\p"
# 403 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a miniature diorama of the\n"
# 404 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "HOENN region.\p"
# 405 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Where is LITTLEROOT TOWN on this?$"
# 406 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 407 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
# 408 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a display on the flow of seawater.\p"
# 409 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“Near the bottom of the sea, water\n"
# 410 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "flows due to differences in such\l"
# 411 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "factors as temperature and salinity.”$"
# 412 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 413 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
# 414 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a display on the flow of seawater.\p"
# 415 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“Toward the surface, seawater flows\n"
# 416 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "as currents driven by the winds.”$"
# 417 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 418 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
# 419 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“THE FERRY S.S. TIDAL\p"
# 420 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A scale replica of the ship under\n"
# 421 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "construction at STERN'S SHIPYARD.”$"
# 422 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 423 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
# 424 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“SUBMARINE EXPLORER 1\p"
# 425 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of the high-performance\n"
# 426 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "ocean floor exploration submarine.”$"
# 427 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 428 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
# 429 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“SUBMERSIBLE POD\p"
# 430 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of a compact, unmanned\n"
# 431 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "pod for seafloor exploration.”$"
# 432 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 433 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
# 434 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“S.S. ANNE\p"
# 435 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of the luxury liner that\n"
# 436 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "circles the globe.”$"
