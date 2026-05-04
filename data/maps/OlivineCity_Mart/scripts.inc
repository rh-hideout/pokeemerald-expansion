OlivineCity_Mart_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "Do your POKéMON already know\n"
	.string "the move for carrying people\l"
	.string "across water?$"

OlivineCity_Text_MartLass:
	.string "My BUTTERFREE came from my\n"
	.string "boyfriend overseas.\p"
	.string "It carried some MAIL from him.\p"
	.string "Want to know what it says?\p"
	.string "Let's see... Nope! It's a\n"
	.string "secret!$"
