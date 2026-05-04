.set LOCALID_NURSE, 1

Route32_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "This is a great fishing spot.\p"
	.string "You saw people fishing?\n"
	.string "How about you?\p"
	.string "Would you like one of my RODS?$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "Heh, that's good to hear.\p"
	.string "Now you're an angler too!$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "Fishing is great!\p"
	.string "If there's water, be it the sea or\n"
	.string "a stream, try out your ROD.$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "Oh. That's rather disappointing…$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "Yo, kid. How are they biting?$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "What should I make my POKéMON hold?\p"
	.string "Maybe an item that increases\n"
	.string "ATTACK power…$"

