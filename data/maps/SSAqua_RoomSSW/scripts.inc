SSAqua_RoomSSW_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "I'm going to KANTO to put\n"
    .string "on fire-breathing shows!$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "Fizzle… The flame's tiny…$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "I guess fire is weak on the sea.\n"
    .string "It doesn't matter? Really?$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "I'm visiting my grandma to\n"
    .string "catch me some bugs!$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "Ooh, wow. You're tough!$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "You can find lots of POKéMON\n"
    .string "in the trees of JOHTO!$"
