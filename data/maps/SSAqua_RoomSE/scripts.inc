SSAqua_RoomSE_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
    .string "Hey, kid! Want to battle\n"
    .string "with me?$"

SSAqua_RoomSE_Text_PokefanmColinBeaten:
    .string "You're strong!$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
    .string "You're traveling all alone?\n"
    .string "Isn't your mom worried?$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
    .string "You think I'm a baby?\n"
    .string "That's not fair!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
    .string "Oh! We lost!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
    .string "Baby is a rude name to call\n"
    .string "us girls!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
    .string "I'm not a baby!\n"
    .string "That's not nice to say to a lady!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
    .string "Oh! We lost!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
    .string "Sometimes, kids are smarter\n"
    .string "than grown-ups!$"
