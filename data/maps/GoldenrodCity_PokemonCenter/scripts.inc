.set LOCALID_NURSE, 1

GoldenrodCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
    .string "I just love living in the big city!\n"
    .string "I moved here when I was a young\l"
    .string "trainer, like you!$"

GoldenrodCity_PokemonCenter_GameboyKidText1:
    .string "This is a special POKéMON CENTER.\n"
    .string "The roof is made of gold!$"

GoldenrodCity_PokemonCenter_GameboyKidText2:
    .string "I told my brother that the roof is\n"
    .string "made of real gold. He'll believe\l"
	.string "anything!$"

GoldenrodCity_PokemonCenter_LassText:
    .string "A higher level POKéMON doesn't\n"
    .string "always win.\p"
    .string "After all, it may have a type\n"
    .string "disadvantage.\p"
    .string "I don't think there is a single\n"
    .string "POKéMON that is the toughest.$"

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
    .string "{PLAYER}, isn't it?\p"
    .string "Congratulations!\p"
    .string "As a special deal, a GS BALL has\n"
    .string "been sent just for you!\p"
    .string "Please accept it!$"

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
    .string "Please do come again!$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
    .string "Oh my, your pack looks so heavy!\p"
    .string "Oh! Do you happen to have\n"
    .string "something named EON MAIL?\p"
    .string "My daughter is after one.\p"
    .string "You can part with one, can't you?$"

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
    .string "Give away an EON MAIL?$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
    .string "Oh, that's great! Thank you,\n"
    .string "honey!\p"
    .string "Here, this is for you in return!$"

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
    .string "My daughter will be delighted!$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
    .string "Oh? You don't have one? Too bad.$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
    .string "Oh… Well, another time, then.$"

GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
    .string "{PLAYER} gave away the EON MAIL.$"
