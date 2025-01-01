PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	goto_if_unset FLAG_GAVE_TM_FLIP_TURN, PacifidlogTown_House2_EventScript_GiveStoneEdge
	release
	end

PacifidlogTown_House2_EventScript_GiveStoneEdge::
	giveitem ITEM_TM_STONE_EDGE
	setflag FLAG_GAVE_TM_FLIP_TURN
	msgbox PacifidlogTown_House2_ExplainStoneEdge, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_ExplainStoneEdge:
	.string "This is a very unlucky move.\n"
	.string "I don't like using it at all.\p"
	.string "Anyways, good luck!$"

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "I am the POKéMON FAN CLUB's most\n"
	.string "important person, the CHAIRMAN's\l"
	.string "younger brother.$"
