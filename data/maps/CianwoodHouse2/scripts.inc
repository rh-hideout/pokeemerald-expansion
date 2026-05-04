CianwoodHouse2_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "You came from OLIVINE?\p"
	.string "Do you remember the four islands\n"
	.string "along the way?\p"
	.string "I heard that a mythical sea crea-\n"
	.string "ture is hiding in them.$"

CianwoodCity_Text_LugiaHouseLass:
	.string "I heard that you can only see it\n"
	.string "if you have a SILVER WING.\p"
	.string "It must have the same scent as\n"
	.string "the creature.$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "I've heard that the whirlpools\n"
	.string "around the islands are caused by\l"
	.string "the sea creature.\p"
	.string "You might need a special move\n"
	.string "to get past them.$"
