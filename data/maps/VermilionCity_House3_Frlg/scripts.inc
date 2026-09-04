VermilionCity_House3_Frlg_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_PidgeyFlyLetterToSaffron, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_SendMyPidgeyToUnionRoom, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_House3_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_DearPippiLetter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_PidgeyFlyLetterToSaffron::
	.string "I'm getting my [Pidgey] to fly a\n"
	.string "letter to [Saffron] in the north.$"

VermilionCity_House3_Text_Pidgey::
	.string "[Pidgey]: Kurukkoo!$"

VermilionCity_House3_Text_DearPippiLetter::
	.string "Dear [Pippi],\n"
	.string "I hope to see you soon.\p"
	.string "I heard [Saffron] has problems with\n"
	.string "[Team Rocket].\p"
	.string "[Vermilion] appears to be safe.$"

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
	.string "I want to exchange [Mail] with all\n"
	.string "sorts of people.\p"
	.string "I send my [Pidgey] to a [Union Room]\n"
	.string "to exchange [Mail] for me.$"
