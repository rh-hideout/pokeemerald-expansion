secreteRoomwithCode_MapScripts::
	.byte 0

secreteRoomwithCode_EventScript_ShowHint::
	lock
	faceplayer
	goto_if_set FLAG_CTF_SECRETROOM_HINT, secreteRoomwithCode_ShowHintOnly
	msgbox secreteRoomwithCode_Text_MatriculationRule, MSGBOX_DEFAULT
	setflag FLAG_CTF_SECRETROOM_HINT

secreteRoomwithCode_ShowHintOnly:
	callnative ShowTrainerCodeHint
	waitstate
	release
	end

secreteRoomwithCode_Text_MatriculationRule:
	.string "The Sign says:\n"
	.string "“By ancient rule of the DHBW,\p"
	.string "matriculation numbers are not chosen,\n"
	.string "but calculated.”$"
