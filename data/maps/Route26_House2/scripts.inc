Route26_House2_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "There's something written here.\p"
    .string "Read it?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "To my brothers and sisters:\p"
    .string "We take pride in serving POKéMON\n"
    .string "trainers.\p"
    .string "When trainers talk to you, give\n"
    .string "them something useful.\p"
    .string "Love,\n"
    .string "MONICA\p"
    .string "Keep reading?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "Monday, MONICA\n"
    .string "ROUTE 40\p"
    .string "Tuesday, TUSCANY\n"
    .string "ROUTE 29\p"
    .string "Wednesday, WESLEY\n"
    .string "LAKE OF RAGE\p"
    .string "Thursday, ARTHUR\n"
    .string "ROUTE 36\p"
    .string "Friday, FRIEDA\n"
    .string "ROUTE 32\p"
    .string "Saturday, SANTOS\n"
    .string "BLACKTHORN CITY\p"
    .string "Sunday, SUNNY\n"
    .string "ROUTE 37$"
