BlackthornCity_Mart_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "You can't buy MAX REVIVE, but it\n"
	.string "fully restores a fainted POKéMON.\p"
	.string "Beware--it won't restore PP, the\n"
	.string "POWER POINTS needed for moves.$"

BlackthornMart_Text_BlackBelt:
	.string "MAX REPEL keeps weak POKéMON away\n"
	.string "from you.\p"
	.string "It's the longest lasting of the\n"
	.string "REPEL sprays.$"
