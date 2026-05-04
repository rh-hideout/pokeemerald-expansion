GoldenrodCity_UndergroundEntrance_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "I was challenged to a battle\n"
	.string "downstairs.\p"
	.string "It's rough down there. You'd\n"
	.string "better be careful.$"


GoldenrodUnderground1_Text_Teacher:
	.string "There are some shops downstairs…\n"
	.string "But there are also trainers.\p"
	.string "I'm scared to go down there.$"
