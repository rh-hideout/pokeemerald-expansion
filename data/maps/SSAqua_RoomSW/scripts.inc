SSAqua_RoomSW_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "I'm trying to forget my woes.\n"
    .string "Let's battle!$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "My heart weeps…$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "A voyage is best for getting over\n"
    .string "a broken heart.\p"
    .string "But a FAST SHIP trip is too short\n"
    .string "for grieving.$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "I'm going to audition my songs\n"
    .string "at GOLDENROD's RADIO STATION.$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "Yowza! Total distortion!$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "I was going to make my debut at\n"
    .string "the BATTLE TOWER…\p"
    .string "I should go back to VERMILION and\n"
    .string "redo my training…$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "Speaking of the RADIO STATION,\n"
    .string "what's this week's lucky number?$"
