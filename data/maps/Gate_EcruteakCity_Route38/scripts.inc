Gate_EcruteakCity_Route38_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "Where did you say you're from?\p"
	.string "NEW BARK TOWN?\p"
	.string "PROF.ELM lives over there,\n"
	.string "right?\p"
	.string "You've come a long way to get\n"
	.string "here.$"
