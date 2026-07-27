LittlerootTown_Players_House_2F_MapScripts::
	.byte 0

LittlerootTown_PlayersHouse_2F_EventScript_Mom::
    lock
    faceplayer

    msgbox LittlerootTown_PlayersHouse_2F_Text_Mom, MSGBOX_NPC

    release
    end


LittlerootTown_PlayersHouse_2F_EventScript_Dad::
    lock
    faceplayer

    msgbox LittlerootTown_PlayersHouse_2F_Text_Dad, MSGBOX_NPC

    release
    end

LittlerootTown_PlayersHouse_2F_Text_Dad:
    .string "Morning, kiddo.\p"
    .string "Big day, huh? Your first POKéMON\n"
    .string "and the start of your journey.\p"
    .string "Don't rush out of town just yet.\n"
    .string "Take a look around first.\p"
    .string "You may find something useful.\p"
    .string "The library would be a good\n"
    .string "place to start.$"

LittlerootTown_PlayersHouse_2F_Text_Mom:
    .string "There you are, sweetheart.\p"
    .string "I know today's the day you get\n"
    .string "your first POKéMON.\p"
    .string "Before you head out, take some\n"
    .string "time to explore the town.\p"
    .string "You never know what might help\n"
    .string "you on your journey.\p"
    .string "You should visit the library.\n"
    .string "I've always loved it there.$"



