SixIsland_GreenPath_Frlg_MapScripts::
	.byte 0

SixIsland_GreenPath_EventScript_RightRouteSign::
	msgbox SixIsland_GreenPath_Text_LeftRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_EventScript_LeftRouteSign::
	msgbox SixIsland_GreenPath_Text_RightRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_Text_JaclynIntro::
	.string "…Huh?\p"
	.string "I was envisioning my house, but\n"
	.string "this is where I [Teleport]?$"

SixIsland_GreenPath_Text_JaclynDefeat::
	.string "Big boo-boo!$"

SixIsland_GreenPath_Text_JaclynPostBattle::
	.string "I am so scatterbrained!\p"
	.string "I need to focus so I can [Teleport]\n"
	.string "properly to my house!$"

SixIsland_GreenPath_Text_LeftRouteSign::
	.string "[Green Path]\n"
	.string "[Pattern Bush Ahead]$"

SixIsland_GreenPath_Text_RightRouteSign::
	.string "[Green Path]\n"
	.string "Think Green, Keep Nature Clean!$"
