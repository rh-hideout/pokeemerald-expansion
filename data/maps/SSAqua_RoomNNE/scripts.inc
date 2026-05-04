SSAqua_RoomNNE_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
    .string "I'm going to KANTO\n"
    .string "to test my skills.$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
    .string "I wanted to win!$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
    .string "Trainers from JOHTO\n"
    .string "can battle with KANTO\l"
    .string "GYM LEADERS.$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
    .string "I'm training to\n"
    .string "become the CHAMP!$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
    .string "What's so different\n"
    .string "between us?$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
    .string "I'm going to beat\n"
    .string "you someday!$"
