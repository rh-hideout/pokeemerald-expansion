HowerClass_MapScripts::
	.byte 0

HowerClass_EventScript_Student1::
	lock
	faceplayer
	msgbox HowerClass_Text_StudentIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_StudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_Text_StudentIntro:
	.string "DHBW sounded great on paper.\p"
	.string "Theory at university, practice at\n"
	.string "the company...$"

HowerClass_Text_StudentPunchline:
	.string "No one told me I'd have both\n"
	.string "at the same time.$"
