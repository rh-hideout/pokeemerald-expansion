FuchsiaCity_SafariZone_Office_Frlg_MapScripts::
	.byte 0

FuchsiaCity_SafariZone_Office_EventScript_Worker1::
	msgbox FuchsiaCity_SafariZone_Office_Text_NicknamedWardenSlowpoke, MSGBOX_NPC
	end

FuchsiaCity_SafariZone_Office_EventScript_Worker2::
	msgbox FuchsiaCity_SafariZone_Office_Text_WardenIsVeryKnowledgeable, MSGBOX_NPC
	end

FuchsiaCity_SafariZone_Office_EventScript_Worker3::
	msgbox FuchsiaCity_SafariZone_Office_Text_CouldntUnderstandWarden, MSGBOX_NPC
	end

FuchsiaCity_SafariZone_Office_EventScript_Worker4::
	msgbox FuchsiaCity_SafariZone_Office_Text_PrizeInSafariZone, MSGBOX_NPC
	end

FuchsiaCity_SafariZone_Office_Text_NicknamedWardenSlowpoke::
	.string "We nicknamed the [Warden]\n"
	.string "“[Slowpoke].”\p"
	.string "You know, he has that vacant look\n"
	.string "like a [Slowpoke].$"

FuchsiaCity_SafariZone_Office_Text_WardenIsVeryKnowledgeable::
	.string "[Warden Slowpoke] is very\n"
	.string "knowledgeable about [Pokémon].\p"
	.string "He even has some fossils of rare,\n"
	.string "extinct [Pokémon].$"

FuchsiaCity_SafariZone_Office_Text_CouldntUnderstandWarden::
	.string "[Warden Slowpoke] came in, but\n"
	.string "I couldn't understand him.\p"
	.string "I think he's got a speech problem!$"

FuchsiaCity_SafariZone_Office_Text_PrizeInSafariZone::
	.string "[Warden Slowpoke] is running a\n"
	.string "promotion campaign right now.\p"
	.string "Try to get to the farthest corner\n"
	.string "of the [Safari Zone].\p"
	.string "If you can make it, you'll win a\n"
	.string "very convenient prize.$"
