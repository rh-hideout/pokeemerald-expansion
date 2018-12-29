#include "constants/species.h"
#include "constants/items.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0832C6A8:: @ 832C6A8
	.4byte 0x00000f2c, 0x00003d88, 0x0000001c, 0x00000024, 0x00000064, 0x00000528

	.align 1
gTradeMovesBoxTilemap:: @ 832C6C0
	.incbin "graphics/trade/moves_box_map.bin"

	.align 1
gTradePartyBoxTilemap:: @ 832C8BE
	.incbin "graphics/trade/party_box_map.bin"

	.align 1
gTradeStripesBG2Tilemap:: @ 832CABC
	.incbin "graphics/trade/stripes_bg2_map.bin"

	.align 1
gTradeStripesBG3Tilemap:: @ 832D2BC
	.incbin "graphics/trade/stripes_bg3_map.bin"

gText_EmptyString7:: @ 832DABC
	.string "$"

gText_ClrWhtHltTrspntShdwDrkGry:: @ 832DABD
	.string "{COLOR WHITE}{HIGHLIGHT TRANSPARENT}{SHADOW DARK_GREY}$"

gText_MaleSymbol4:: @ 832DAC7
	.string "♂$"

gText_FemaleSymbol4:: @ 832DAC9
	.string "♀$"

gText_GenderlessSymbol:: @ 832DACB
	.string "$"

gText_SpaceMove:: @ 832DACC
	.string " MOVE$"

gText_NewLine3:: @ 832DAD2
	.string "\n$"

gText_Slash2:: @ 832DAD4
	.string "/$"

gText_Lv2:: @ 832DAD6
	.string "Lv. $"

gText_ThreeDashes2:: @ 832DADB
	.string "---$"

gText_FourQuestionMarks:: @ 832DADF
	.string "????$"

gText_832DAE4:: @ 832DAE4
	.string "$"

gText_IsThisTradeOkay:: @ 832DAE5
	.string "Is this trade okay?$"

gText_Cancel6:: @ 832DAF9
	.string "CANCEL$"

gText_ChooseAPkmn:: @ 832DB00
	.string "Choose a POKéMON.$"

gText_Summary3:: @ 832DB12
	.string "SUMMARY$"

gText_Trade2:: @ 832DB1A
	.string "TRADE$"

gText_CancelTrade:: @ 832DB20
	.string "Cancel trade?$"

gJPText_832DB2E:: @ 832DB2E
	.string "Bボタン　で　もどります$"

gText_Summary4:: @ 832DB3B
	.string "SUMMARY$"

gText_Trade3:: @ 832DB43
	.string "TRADE$"

gText_CommunicationStandby6:: @ 832DB49
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}Communication standby…\nPlease wait.$"

gText_TheTradeHasBeenCanceled:: @ 832DB76
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}The trade has\nbeen canceled.$"

gText_YourOnlyPkmnForBattle:: @ 832DB9C
	.string "That's your only\nPOKéMON for battle.$"

gText_WaitingForYourFriend:: @ 832DBC1
	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}Waiting for your friend\nto finish…$"

gText_YourFriendWantsToTrade:: @ 832DBED
	.string "Your friend wants\nto trade POKéMON.$"

	.align 2
gOamData_832DC14:: @ 832DC14
	.2byte 0x4000, 0x8000, 0x0400, 0x0000

	.align 2
gOamData_832DC1C:: @ 832DC1C
	.2byte 0x4000, 0xc000, 0x0400, 0x0000

	.align 2
gSpriteAnim_832DC24:: @ 832DC24
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC2C:: @ 832DC2C
	.2byte 0x0020, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_832DC34:: @ 832DC34
	.4byte gSpriteAnim_832DC24
	.4byte gSpriteAnim_832DC2C

	.align 2
gUnknown_0832DC3C:: @ 832DC3C
	obj_tiles gUnknown_08DDC6E4, 0x0800, 0x012c

	.align 2
gUnknown_0832DC44:: @ 832DC44
	obj_pal gUnknown_08DDB444, 0x0929

	.align 2
gSpriteAnim_832DC4C:: @ 832DC4C
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC54:: @ 832DC54
	.2byte 0x0008, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC5C:: @ 832DC5C
	.2byte 0x0010, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC64:: @ 832DC64
	.2byte 0x0018, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC6C:: @ 832DC6C
	.2byte 0x0020, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC74:: @ 832DC74
	.2byte 0x0028, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_832DC7C:: @ 832DC7C
	.4byte gSpriteAnim_832DC4C
	.4byte gSpriteAnim_832DC54
	.4byte gSpriteAnim_832DC5C
	.4byte gSpriteAnim_832DC64
	.4byte gSpriteAnim_832DC6C
	.4byte gSpriteAnim_832DC74

	.align 2
gSpriteTemplate_832DC94:: @ 832DC94
	spr_template 0x012c, 0x0929, gOamData_832DC1C, gSpriteAnimTable_832DC34, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gSpriteTemplate_832DCAC:: @ 832DCAC
	spr_template 0x00c8, 0x133d, gOamData_832DC14, gSpriteAnimTable_832DC7C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
TradeScreenTextPalette:: @ 832DCC4
	.incbin "graphics/trade/text.gbapal"

	.align 2
gSpritePalette_TradeScreenText:: @ 832DCE4
	obj_pal TradeScreenTextPalette, 0x133d

gUnknown_0832DCEC:: @ 832DCEC
	.byte 0x04, 0x02, 0x0c, 0x0c, 0x00, 0x00, 0x02, 0x04, 0x0c, 0x0c, 0x00, 0x00, 0x07, 0x06, 0x01, 0x00, 0x00, 0x00, 0x01, 0x06, 0x07, 0x00, 0x00, 0x00, 0x05, 0x03, 0x0c, 0x0c, 0x00, 0x00, 0x03, 0x05
	.byte 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x07, 0x06, 0x01, 0x00, 0x00, 0x06, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x08, 0x07, 0x06
	.byte 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x05, 0x01, 0x01, 0x01, 0x00, 0x00, 0x02, 0x09, 0x08, 0x07, 0x00, 0x00, 0x08, 0x09, 0x06, 0x06, 0x00, 0x00
	.byte 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x0a, 0x09, 0x08, 0x07, 0x06, 0x05, 0x03, 0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01
	.byte 0x01, 0x01, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x0a, 0x08, 0x06, 0x00, 0x00, 0x00, 0x0a, 0x08, 0x0c, 0x00, 0x00, 0x00, 0x08, 0x0a, 0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x06, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x0c
	.byte 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x04, 0x03, 0x02
	.byte 0x01, 0x00, 0x0b, 0x09, 0x07, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00
	.byte 0x0b, 0x09, 0x07, 0x06, 0x00, 0x00, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00

gUnknown_0832DE24:: @ 832DE24
	.byte 0x01, 0x05, 0x08, 0x05, 0x01, 0x0a, 0x08, 0x0a, 0x01, 0x0f, 0x08, 0x0f, 0x10, 0x05, 0x17, 0x05, 0x10, 0x0a, 0x17, 0x0a, 0x10, 0x0f, 0x17, 0x0f, 0x17, 0x12

gUnknown_0832DE3E:: @ 832DE3E
	.byte 0x05, 0x04, 0x0c, 0x04, 0x05, 0x09, 0x0c, 0x09, 0x05, 0x0e, 0x0c, 0x0e, 0x14, 0x04, 0x1b, 0x04, 0x14, 0x09, 0x1b, 0x09, 0x14, 0x0e, 0x1b, 0x0e

gUnknown_0832DE56:: @ 832DE56
	.byte 0x01, 0x03, 0x08, 0x03, 0x01, 0x08, 0x08, 0x08, 0x01, 0x0d, 0x08, 0x0d, 0x10, 0x03, 0x17, 0x03, 0x10, 0x08, 0x17, 0x08, 0x10, 0x0d, 0x17, 0x0d, 0x00, 0x0e, 0x0f, 0x1d, 0x03, 0x05, 0x03, 0x07
	.byte 0x12, 0x05, 0x12, 0x07, 0x08, 0x07, 0x16, 0x0c, 0x08, 0x07, 0x16, 0x0c, 0x06, 0x07, 0x18, 0x0c, 0x06, 0x07, 0x18, 0x0c, 0x08, 0x07, 0x16, 0x0c, 0x07, 0x07, 0x17, 0x0c, 0x00, 0x00

	.align 2
gUnknown_0832DE94:: @ 832DE94
	.4byte gText_Cancel6
	.4byte gText_ChooseAPkmn
	.4byte gText_Summary3
	.4byte gText_Trade2
	.4byte gText_CancelTrade
	.4byte gJPText_832DB2E

	.align 2
gUnknown_0832DEAC:: @ 832DEAC
	.4byte gText_Summary4, sub_807A000
	.4byte gText_Trade3, sub_807A024

	.align 2
gUnknown_0832DEBC:: @ 832DEBC
	.4byte gText_CommunicationStandby6
	.4byte gText_TheTradeHasBeenCanceled
	.4byte gText_YourOnlyPkmnForBattle
	.4byte gText_OnlyPkmnForBattle
	.4byte gText_WaitingForYourFriend
	.4byte gText_YourFriendWantsToTrade
	.4byte gText_PkmnCantBeTradedNow
	.4byte gText_EggCantBeTradedNow
	.4byte gText_OtherTrainersPkmnCantBeTraded

gUnknown_0832DEE0:: @ 832DEE0
	.byte 0x00, 0x01, 0x02, 0x00

	.align 2
gUnknown_0832DEE4:: @ 832DEE4
	.4byte 0x000001f8, 0x00001051, 0x00002062, 0x00003073

	.align 2
gUnknown_0832DEF4:: @ 832DEF4
	window_template 0x00, 0x04, 0x07, 0x16, 0x04, 0x0f, 0x001e
	window_template 0x00, 0x13, 0x0f, 0x0a, 0x04, 0x0f, 0x0076
	window_template 0x00, 0x00, 0x05, 0x08, 0x02, 0x0d, 0x009e
	window_template 0x00, 0x07, 0x05, 0x08, 0x02, 0x0d, 0x00ae
	window_template 0x00, 0x00, 0x0a, 0x08, 0x02, 0x0d, 0x00be
	window_template 0x00, 0x07, 0x0a, 0x08, 0x02, 0x0d, 0x00ce
	window_template 0x00, 0x00, 0x0f, 0x08, 0x02, 0x0d, 0x00de
	window_template 0x00, 0x07, 0x0f, 0x08, 0x02, 0x0d, 0x00ee
	window_template 0x00, 0x0f, 0x05, 0x08, 0x02, 0x0d, 0x00fe
	window_template 0x00, 0x16, 0x05, 0x08, 0x02, 0x0d, 0x010e
	window_template 0x00, 0x0f, 0x0a, 0x08, 0x02, 0x0d, 0x011e
	window_template 0x00, 0x16, 0x0a, 0x08, 0x02, 0x0d, 0x012e
	window_template 0x00, 0x0f, 0x0f, 0x08, 0x02, 0x0d, 0x013e
	window_template 0x00, 0x16, 0x0f, 0x08, 0x02, 0x0d, 0x014e
	window_template 0x00, 0x02, 0x05, 0x0e, 0x02, 0x0d, 0x015e
	window_template 0x00, 0x03, 0x08, 0x0b, 0x08, 0x0f, 0x017a
	window_template 0x00, 0x11, 0x05, 0x0e, 0x02, 0x0f, 0x01d2
	window_template 0x00, 0x12, 0x08, 0x0b, 0x08, 0x0f, 0x01ee
	null_window_template

	.align 2
gUnknown_0832DF8C:: @ 832DF8C
	window_template 0x00, 0x17, 0x0d, 0x05, 0x04, 0x0f, 0x0246

gJPText_Shedinja:: @ 832DF94
	.string "ヌケニン$"

gUnknown_0832DF99:: @ 832DF99
	.byte 0x04, 0x03, 0x13, 0x03, 0x00, 0x00, 0x00

	.align 2
gTradeBallPalette:: @ 832DFA0
	.incbin "graphics/trade/ball.gbapal"

	.align 2
gTradeBallTiles:: @ 832DFC0
	.incbin "graphics/trade/ball.4bpp"

	.align 2
gUnknown_832E5C0:: @ 832E5C0
	.incbin "graphics/trade/pokeball_symbol.8bpp"

	.align 2
gUnknown_0832FFC0:: @ 832FFC0
	.incbin "graphics/trade/cable_closeup_map.bin"

	.align 2
gUnknown_083307C0:: @ 83307C0
	.incbin "graphics/trade/pokeball_symbol_map.bin"

	.align 2
gUnknown_083308C0:: @ 83308C0
	.incbin "graphics/trade/unknown_3308C0.gbapal"

	.align 2
gUnknown_083308E0:: @ 83308E0
	.incbin "graphics/trade/gba.gbapal"
	.incbin "graphics/trade/shadow.gbapal"
	.incbin "graphics/trade/black.gbapal"

	.align 2
gUnknown_08330940:: @ 8330940
	.incbin "graphics/trade/misc.gbapal"

	.align 2
gTradeGlow1Tiles:: @ 8330960
	.incbin "graphics/trade/glow1.4bpp"

	.align 2
gTradeGlow2Tiles:: @ 8330B60
	.incbin "graphics/trade/glow2.4bpp"

	.align 2
gTradeCableEndTiles:: @ 8330D60
	.incbin "graphics/trade/cable_end.4bpp"

	.align 2
gTradeGBAScreenTiles:: @ 8330F60
	.incbin "graphics/trade/gba_screen.4bpp"

	.align 2
gUnknown_08331F60:: @ 8331F60
	.incbin "graphics/trade/shadow_map.bin"

	.align 2
gUnknown_08332F60:: @ 8332F60
	.incbin "graphics/trade/gba_affine.8bpp"

	.space 0x40

	.align 2
gUnknown_083357A0:: @ 83357A0
	.incbin "graphics/trade/gba_affine_map_cable.bin"

	.align 2
gUnknown_083358A0:: @ 83358A0
	.incbin "graphics/trade/gba_affine_map_wireless.bin"

	.align 2
gUnknown_083359A0:: @ 83359A0
	.incbin "graphics/trade/gba_map_wireless.bin"

	.align 2
gUnknown_083369A0:: @ 83369A0
	.incbin "graphics/trade/gba_map_cable.bin"

	.align 2
gUnknown_083379A0:: @ 83379A0
	.incbin "graphics/trade/unknown_3379A0.bin.lz"

	.align 2
gUnknown_08337AA0:: @ 8337AA0
	.incbin "graphics/trade/wireless_signal_send.gbapal"

	.align 2
gUnknown_08337CA0:: @ 8337CA0
	.incbin "graphics/trade/wireless_signal_receive.gbapal"

	.align 2
gUnknown_08337EA0:: @ 8337EA0
	.incbin "graphics/trade/black.gbapal"

	.align 2
gUnknown_08337EC0:: @ 8337EC0
	.incbin "graphics/trade/wireless_signal.4bpp.lz"

	.align 2
gUnknown_08338550:: @ 8338550
	.incbin "graphics/trade/wireless_signal.bin.lz"

	.align 2
gOamData_8338C44:: @ 8338C44
	.2byte 0x0100, 0x4000, 0x0000, 0x0000

	.align 2
gSpriteAnim_8338C4C:: @ 8338C4C
	.2byte 0x0000, 0x0003, 0x0004, 0x0003, 0x0008, 0x0003, 0x000c, 0x0003, 0x0010, 0x0003, 0x0014, 0x0003, 0x0018, 0x0003, 0x001c, 0x0003
	.2byte 0x0020, 0x0003, 0x0024, 0x0003, 0x0028, 0x0003, 0x002c, 0x0003, 0xfffd, 0x0001, 0x0000, 0x0003, 0xffff, 0x0000

	.align 2
gSpriteAnim_8338C88:: @ 8338C88
	.2byte 0x0000, 0x0003, 0x0004, 0x0003, 0x0008, 0x0003, 0x000c, 0x0003, 0x0010, 0x0003, 0x0014, 0x0003, 0x0018, 0x0003, 0x001c, 0x0003
	.2byte 0x0020, 0x0003, 0x0024, 0x0003, 0x0028, 0x0003, 0x002c, 0x0003, 0xfffd, 0x0002, 0x0000, 0x0003, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_8338C88:: @ 8338CC4
	.4byte gSpriteAnim_8338C4C
	.4byte gSpriteAnim_8338C88

	.align 2
gSpriteAffineAnim_8338CCC:: @ 8338CCC
	.2byte 0x0000, 0x0000, 0x0100, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_8338CDC:: @ 8338CDC
	.2byte 0xfff8, 0x0000, 0x1400, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_8338CEC:: @ 8338CEC
	.2byte 0x0060, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0500, 0x0000, 0x0008, 0x0000, 0x1400, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_8338D0C:: @ 8338D0C
	.4byte gSpriteAffineAnim_8338CCC
	.4byte gSpriteAffineAnim_8338CDC
	.4byte gSpriteAffineAnim_8338CEC

	.align 2
gUnknown_08338D18:: @ 8338D18
	obj_tiles gTradeBallTiles, 0x0600, 0x15b5

	.align 2
gUnknown_08338D20:: @ 8338D20
	obj_pal gTradeBallPalette, 0x15b6

	.align 2
gSpriteTemplate_8338D28:: @ 8338D28
	spr_template 0x15b5, 0x15b6, gOamData_8338C44, gSpriteAnimTable_8338C88, NULL, gSpriteAffineAnimTable_8338D0C, sub_807E55C

	.align 2
gOamData_8338D40:: @ 8338D40
	.2byte 0x0500, 0x8000, 0x0400, 0x0000

	.align 2
gSpriteAnim_8338D48:: @ 8338D48
	.2byte 0x0000, 0x00c5, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_8338D50:: @ 8338D50
	.4byte gSpriteAnim_8338D48

	.align 2
gSpriteAffineAnim_8338D54:: @ 8338D54
	.2byte 0xfff6, 0xfff6, 0x0500, 0x0000, 0x000a, 0x000a, 0x0500, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_8338D6C:: @ 8338D6C
	.4byte gSpriteAffineAnim_8338D54

	.align 2
gUnknown_08338D70:: @ 8338D70
	obj_tiles gTradeGlow1Tiles, 0x0200, 0x15ae

	.align 2
gUnknown_08338D78:: @ 8338D78
	obj_pal gUnknown_08330940, 0x15af

	.align 2
gUnknown_08338D80:: @ 8338D80
	obj_pal gUnknown_083308E0, 0x15b3

	.align 2
gUnknown_08338D88:: @ 8338D88
	spr_template 0x15ae, 0x15af, gOamData_8338D40, gSpriteAnimTable_8338D50, NULL, gSpriteAffineAnimTable_8338D6C, sub_807AA28

	.align 2
gOamData_8338DA0:: @ 8338DA0
	.2byte 0x8000, 0x8000, 0x0400, 0x0000

	.align 2
gSpriteAnim_8338DA8:: @ 8338DA8
	.2byte 0x0000, 0x00c5, 0xffff, 0x0000

	.align 2
gSpriteAnim_8338DB0:: @ 8338DB0
	.2byte 0x0008, 0x00c5, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_8338DB8:: @ 8338DB8
	.4byte gSpriteAnim_8338DA8
	.4byte gSpriteAnim_8338DB0

	.align 2
gUnknown_08338DC0:: @ 8338DC0
	obj_tiles gTradeGlow2Tiles, 0x0300, 0x15b0

	.align 2
gSpriteTemplate_8338DC8:: @ 8338DC8
	spr_template 0x15b0, 0x15af, gOamData_8338DA0, gSpriteAnimTable_8338DB8, NULL, gDummySpriteAffineAnimTable, sub_807AA7C

	.align 2
gOamData_8338DE0:: @ 8338DE0
	.2byte 0x8000, 0x8000, 0x0400, 0x0000

	.align 2
gSpriteAnim_8338DE8:: @ 8338DE8
	.2byte 0x0000, 0x000a, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_8338DF0:: @ 8338DF0
	.4byte gSpriteAnim_8338DE8

	.align 2
gUnknown_08338DF4:: @ 8338DF4
	obj_tiles gTradeCableEndTiles, 0x0100, 0x15b2

	.align 2
gSpriteTemplate_8338DFC:: @ 8338DFC
	spr_template 0x15b2, 0x15b3, gOamData_8338DE0, gSpriteAnimTable_8338DF0, NULL, gDummySpriteAffineAnimTable, sub_807AABC

	.align 2
gOamData_8338E14:: @ 8338E14
	.2byte 0x4000, 0xc000, 0x0400, 0x0000

	.align 2
gSpriteAnim_8338E1C:: @ 8338E1C
	.2byte 0x0000, 0x00c2, 0x0020, 0x00c2, 0x0040, 0x00c2, 0x0060, 0x00c2, 0x0040, 0x00c2, 0x0020, 0x00c2, 0x0000, 0x00c2, 0xfffd, 0x0008
	.2byte 0xffff, 0x0000

	.align 2
gSpriteAnim_8338E40:: @ 8338E40
	.2byte 0x0000, 0x00c2, 0x0020, 0x00c2, 0x0040, 0x00c2, 0x0060, 0x00c2, 0x0040, 0x00c2, 0x0020, 0x00c2, 0x0000, 0x00c2, 0xfffd, 0x0002
	.2byte 0xffff, 0x0000

	.align 2
gSpriteAnimTable_8338E64:: @ 8338E64
	.4byte gSpriteAnim_8338E1C

	.align 2
gSpriteAnimTable_8338E68:: @ 8338E68
	.4byte gSpriteAnim_8338E40

gUnknown_08338E6C:: @ 8338E6C
	obj_tiles gTradeGBAScreenTiles, 0x1000, 0x15b4

	.align 2
gSpriteTemplate_8338E74:: @ 8338E74
	spr_template 0x15b4, 0x15b3, gOamData_8338E14, gSpriteAnimTable_8338E64, NULL, gDummySpriteAffineAnimTable, sub_807AB04

	.align 2
gSpriteTemplate_8338E8C:: @ 8338E8C
	spr_template 0x15b4, 0x15b3, gOamData_8338E14, gSpriteAnimTable_8338E68, NULL, gDummySpriteAffineAnimTable, sub_807AB04

	.align 1
gUnknown_08338EA4:: @ 8338EA4
	.incbin "graphics/trade/unknown_338EA4.gbapal"

	.align 2
gSpriteAffineAnim_8338EBC:: @ 8338EBC
	.2byte 0xff00, 0x0100, 0x0000, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_8338ECC:: @ 8338ECC
	.4byte gSpriteAffineAnim_8338EBC

	.align 2
gIngameTrades:: @ 8338ED0
	.string "DOTS$", 11
	.align 1
	.2byte SPECIES_SEEDOT
	.byte 5, 4, 5, 4, 4, 4
	.byte 1
	.align 2
	.4byte 0x9746
	.byte 30, 5, 5, 5, 5
	.align 2
	.4byte 0x84
	.2byte ITEM_CHESTO_BERRY
	.byte -1
	.string "KOBE$", 11
	.byte 0
	.byte 10
	.2byte SPECIES_RALTS

	.align 2
	.string "PLUSES$", 11
	.align 1
	.2byte SPECIES_PLUSLE
	.byte 4, 4, 4, 5, 5, 4
	.byte 0
	.align 2
	.4byte 0x1210c
	.byte 5, 5, 30, 5, 5
	.align 2
	.4byte 0x6f
	.2byte ITEM_WOOD_MAIL
	.byte 0
	.string "ROMAN$", 11
	.byte 0
	.byte 10
	.2byte SPECIES_VOLBEAT

	.align 2
	.string "SEASOR$", 11
	.align 1
	.2byte SPECIES_HORSEA
	.byte 5, 4, 4, 4, 5, 4
	.byte 0
	.align 2
	.4byte 0xb4cd
	.byte 5, 5, 5, 5, 30
	.align 2
	.4byte 0x7f
	.2byte ITEM_WAVE_MAIL
	.byte 1
	.string "SKYLAR$", 11
	.byte 0
	.byte 10
	.2byte SPECIES_BAGON

	.align 2
	.string "MEOWOW$", 11
	.align 1
	.2byte SPECIES_MEOWTH
	.byte 4, 5, 4, 5, 4, 4
	.byte 0
	.align 2
	.4byte 0x16559
	.byte 5, 5, 5, 30, 5
	.align 2
	.4byte 0x8b
	.2byte ITEM_RETRO_MAIL
	.byte 2
	.string "ISIS$", 11
	.byte 1
	.byte 10
	.2byte SPECIES_SKITTY

	.align 2
gIngameTradeMail:: @ 8338FC0
	.2byte 0x1006, 0x1232, 0x102f, 0x0161, 0x0c00, 0x0182, 0x1000, 0x1006, 0x0e3b, 0x0000, 0x0a01, 0x1000, 0x161e, 0x018b, 0x0433, 0x1611
	.2byte 0x180f, 0x0074, 0x1440, 0x0000, 0x0811, 0x102b, 0x013b, 0x2a34, 0x0c16, 0x1037, 0x1020, 0x0418, 0x0c23, 0x0000

	.align 2
gUnknown_08338FFC:: @ 8338FFC
	window_template 0x00, 0x02, 0x0f, 0x1a, 0x04, 0x00, 0x0040
	null_window_template

	.align 2
gUnknown_0833900C:: @ 833900C
	window_template 0x00, 0x15, 0x09, 0x05, 0x04, 0x0f, 0x00bc

	.align 2
gUnknown_08339014:: @ 8339014
	.4byte 0x000001fc, 0x00002051, 0x00002326, 0x00003063

gTradeBallVerticalVelocityTable:: @ 8339024
	.byte 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0xfc, 0xfc, 0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe
	.byte 0xfe, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04
	.byte 0x04, 0x04, 0xfc, 0xfd, 0xfd, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0xfc, 0xfd, 0xfe, 0xff
	.byte 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x02, 0x03

gUnknown_08339090:: @ 8339090
	.byte 0x00, 0x01, 0x01, 0x01, 0x02, 0x01, 0x03, 0x01, 0x04, 0x01, 0x05, 0x02, 0x06, 0x02, 0x07, 0x02, 0x08, 0x02, 0x09, 0x02, 0x0a, 0x03, 0x0b, 0x03, 0x0c, 0x03, 0x0d, 0x04, 0x0e, 0x05, 0x0f, 0x02
	.byte 0x00, 0x01, 0x01, 0x01, 0x02, 0x01, 0x03, 0x01, 0x04, 0x01, 0x05, 0x02, 0x06, 0x02, 0x07, 0x02, 0x08, 0x02, 0x09, 0x02, 0x0a, 0x03, 0x0b, 0x03, 0x0c, 0x03, 0x0d, 0x04, 0x0e, 0x05, 0x10, 0x01
	.byte 0x10, 0xff, 0x00, 0x00
