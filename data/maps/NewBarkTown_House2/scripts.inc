NewBarkTown_House2_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "Hi, {PLAYER}! My husband's always\n"
	.string "so busy--I hope he's OK.\p"
	.string "When he's caught up in his\n"
	.string "POKéMON research, he even\l"
	.string "forgets to eat.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "When I grow up, I'm going to\n"
	.string "help my dad!\p"
	.string "I'm going to be a great\n"
	.string "POKéMON professor!$"
