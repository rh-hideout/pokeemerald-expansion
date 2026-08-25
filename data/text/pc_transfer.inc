gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} was transferred to\n"
	.string "[Someone's PC].\p"
	.string "It was placed in \n"
	.string "[Box] “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} was transferred to\n"
#if IS_FRLG
	.string "[Bill's PC].\p"
#else
	.string "[Lanette's PC].\p"
#endif
	.string "It was placed in \n"
	.string "[Box] “{STR_VAR_1}.”$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "[Box] “{STR_VAR_3}” on\n"
	.string "[Someone's PC] was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "[Box] “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "[Box] “{STR_VAR_3}” on\n"
#if IS_FRLG
	.string "[Bill's PC] was full.\p"
#else
	.string "[Lanette's PC] was full.\p"
#endif
	.string "{STR_VAR_2} was transferred to\n"
	.string "[Box] “{STR_VAR_1}.”$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} was sent to\n"
	.string "{B_PC_CREATOR_NAME} PC.\p"
	.string "It was placed in \n"
	.string "[Box] “{STR_VAR_1}”.$"

gText_PlayerObtainedTheMon::
	.string "{PLAYER} obtained\n"
	.string "the {STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "There's no more room for [Pokémon]!\p"
	.string "The [Pokémon Boxes] are full and\n"
	.string "can't accept any more!$"

gText_NicknameThisPokemon::
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"
