FuchsiaCity_House2_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "My grandpa is the SAFARI ZONE\n"
	.string "WARDEN.\p"
	.string "At least he was…\p"
	.string "He decided to go on a vacation and\n"
	.string "took off overseas all by himself.\p"
	.string "He quit running SAFARI ZONE just\n"
	.string "like that.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "Many people were disappointed that\n"
	.string "SAFARI ZONE closed down, but Grandpa\l"
	.string "is so stubborn…$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "It's a photo of a grinning old man\n"
	.string "who's surrounded by POKéMON.$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "It's a photo of a huge grassy plain\n"
	.string "with rare POKéMON frolicking in it.$"
