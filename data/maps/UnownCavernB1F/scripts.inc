UnownCavernB1F_MapScripts::
	.byte 0


# 3 "data/maps/UnownCavernB1F/scripts.pory"

# 4 "data/maps/UnownCavernB1F/scripts.pory"

# 5 "data/maps/UnownCavernB1F/scripts.pory"
EventScript_NavelRGift::
# 6 "data/maps/UnownCavernB1F/scripts.pory"
    lock
# 7 "data/maps/UnownCavernB1F/scripts.pory"
    faceplayer
# 8 "data/maps/UnownCavernB1F/scripts.pory"
    message gText_NAVELRtext
# 9 "data/maps/UnownCavernB1F/scripts.pory"
    waitmessage
# 10 "data/maps/UnownCavernB1F/scripts.pory"
    checkitem ITEM_MYSTIC_TICKET, 1
# 11 "data/maps/UnownCavernB1F/scripts.pory"
    compare VAR_RESULT, 1
# 12 "data/maps/UnownCavernB1F/scripts.pory"
    goto_if_eq Script_haveticket
# 13 "data/maps/UnownCavernB1F/scripts.pory"
    waitmessage
# 14 "data/maps/UnownCavernB1F/scripts.pory"
    message gText_Hereisticket
# 15 "data/maps/UnownCavernB1F/scripts.pory"
    giveitem ITEM_MYSTIC_TICKET
# 16 "data/maps/UnownCavernB1F/scripts.pory"
    playfanfare MUS_OBTAIN_ITEM
# 17 "data/maps/UnownCavernB1F/scripts.pory"
    setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 18 "data/maps/UnownCavernB1F/scripts.pory"
    release
# 19 "data/maps/UnownCavernB1F/scripts.pory"
    end
# 20 "data/maps/UnownCavernB1F/scripts.pory"

# 21 "data/maps/UnownCavernB1F/scripts.pory"
Script_haveticket::
# 22 "data/maps/UnownCavernB1F/scripts.pory"
    msgbox gText_haveticket
# 23 "data/maps/UnownCavernB1F/scripts.pory"
    release
# 24 "data/maps/UnownCavernB1F/scripts.pory"
    end
# 25 "data/maps/UnownCavernB1F/scripts.pory"

# 26 "data/maps/UnownCavernB1F/scripts.pory"
gText_NAVELRtext::
# 27 "data/maps/UnownCavernB1F/scripts.pory"
    .string "You seem like the right person...\p $"
# 28 "data/maps/UnownCavernB1F/scripts.pory"

# 29 "data/maps/UnownCavernB1F/scripts.pory"
gText_haveticket::
# 30 "data/maps/UnownCavernB1F/scripts.pory"
    .string "Oh Wait! How did it go?$"
# 31 "data/maps/UnownCavernB1F/scripts.pory"

# 32 "data/maps/UnownCavernB1F/scripts.pory"
gText_Hereisticket::
# 33 "data/maps/UnownCavernB1F/scripts.pory"
    .string "Here you go! I hope your confident!$"
