CeladonCity_Apartments_2F_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER} turned on the PC.\p"
	.string "…\p"
	.string "Someone was in the middle of\n"
	.string "composing an e-mail.\p"
	.string "…I hope you'll come visit KANTO.\p"
	.string "I think you'll be surprised at\n"
	.string "how much things have changed here.\p"
	.string "You'll also see many POKéMON that\n"
	.string "aren't native to JOHTO.\p"
	.string "To the PRODUCER\p"
	.string "…$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "HEART & SOUL DEVELOPMENT OFFICE$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "Hi all, Patch 15--\p"
	.string "Sorry, I mean...\p"
	.string "Hi there, I'm the GAME DIRECTOR!\p"
	.string "I built the maps, the tilesets, the\n"
	.string "the scripts, and much more.\p"
	.string "But I couldn't have done it without\n"
	.string "the other devs and the playtesters.\p"
	.string "Thank you for playing! I hope you've\n"
	.string "enjoyed POKéMON HEART & SOUL.$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "We're working to rebuild this game\n"
	.string "in pokeemerald expansion!$"

CeladonMansion2F_Text_TixoRebel:
	.string "Have you heard of THE EGGENING?\n"
	.string "It was a bug from the playtest\l"
	.string "that randomly changed POKéMON into\l"
	.string "EGGs!\p"
	.string "I developed the fix for it!$"

CeladonMansion2F_Text_Phant:
	.string "I love DEMAKES!\p"
	.string "Have you played SWORD AND SHIELD\n"
	.string "ULTIMATE PLUS - ENGLISH?\l"
	.string "I translated it!\p"
	.string "For my next DEMAKE, I think I'll\n"
	.string "do ALOLA!$"

CeladonMansion2F_Text_Exclsior:
	.string "I implemented the unique surfing\n"
	.string "surfing sprites for each POKéMON!\p"
	.string "Since the project is OPEN SOURCE,\n"
	.string "you can add your own features too!$"

CeladonMansion2F_Text_DaniRaibow:
	.string "Hi!\p"
	.string "I am pretty good at finding problems,\n"
	.string "and can fix little ones.\p"
    .string "Wanna hear a joke?\p"
    .string "Lance tried to teach DRAGONITE the\n"
    .string "move DRAGON BREATH.\p"
    .string "However, DRAGONITE was moving too\n"
    .string "fast from EXTREMESPEED; it couldn't\l"
    .string "catch it!$"
