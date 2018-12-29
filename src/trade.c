#include "global.h"
#include "alloc.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "bg.h"
#include "cable_club.h"
#include "data2.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "mail.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "random.h"
#include "rom_8011DC0.h"
#include "save.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "trade.h"
#include "util.h"
#include "window.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define Trade_SendData(ptr) (SendBlock(bitmask_all_link_players_but_self(), ptr->linkData, 20))

struct InGameTrade {
    /*0x00*/ u8 name[11];
    /*0x0C*/ u16 species;
    /*0x0E*/ u8 ivs[6];
    /*0x14*/ bool8 secondAbility;
    /*0x18*/ u32 otId;
    /*0x1C*/ u8 stats[5];
    /*0x24*/ u32 personality;
    /*0x28*/ u16 heldItem;
    /*0x2A*/ u8 mailNum;
    /*0x2B*/ u8 otName[11];
    /*0x36*/ u8 otGender;
    /*0x37*/ u8 sheen;
    /*0x38*/ u16 playerSpecies;
};

extern u8 gUnknown_02022C2C;
extern struct {
    /*0x0000*/ u8 unk_0;
    /*0x0001*/ u8 unk_1;
    /*0x0002*/ u8 filler_2[0x28 - 2];
    /*0x0028*/ u8 unk_28[2][PARTY_SIZE];
    /*0x0034*/ u8 unk_34;
    /*0x0035*/ u8 unk_35;
    /*0x0036*/ u8 partyCounts[2];
    /*0x0038*/ u8 unk_38[12];
    /*0x0044*/ u8 unk_44;
    /*0x0045*/ u8 unk_45[2][PARTY_SIZE];
    /*0x0051*/ u8 unk_51[2][PARTY_SIZE];
    /*0x005D*/ u8 unk_5D[2][PARTY_SIZE];
    /*0x0069*/ u8 unk_69;
    /*0x006A*/ u8 filler_6A[0x6F - 0x6A];
    /*0x006F*/ u8 unk_6F;
    /*0x0070*/ u8 unk_70;
    /*0x0071*/ u8 filler_71;
    /*0x0072*/ u16 unk_72;
    /*0x0074*/ u8 unk_74[2];
    /*0x0076*/ u8 unk_76[2];
    /*0x0078*/ u8 unk_78;
    /*0x0079*/ u8 unk_79;
    /*0x007A*/ u8 unk_7A;
    /*0x007B*/ u8 unk_7B;
    /*0x007C*/ u8 filler_7C[0x7E - 0x7C];
    /*0x007E*/ u8 unk_7E;
    /*0x007F*/ u8 filler_7F;
    /*0x0080*/ u16 unk_80[2];
    /*0x0084*/ u8 filler_84[0xA8 - 0x84];
    /*0x00A8*/ u8 unk_A8;
    /*0x00A9*/ u8 unk_A9[11];
    /*0x00B4*/ u8 filler_B4[0x8D0-0xB4];
    /*0x08D0*/ struct {
        bool8 unk_0;
        u16 unk_2;
        u8 unk_4;
    } unk_8D0[4];
    /*0x08F0*/ u16 tilemapBuffer[0x400];
} *gUnknown_0203229C;
extern u8 *gUnknown_02032184;
extern u8 *gUnknown_02032188[14];
extern u8 gUnknown_02032298[2];
extern struct {
    /*0x00*/ struct Pokemon mon;
    /*0x64*/ u32 unk_64;
    /*0x68*/ u32 unk_68[2];
    /*0x70*/ u8 filler_70[2];
    /*0x72*/ u8 unk_72;
    /*0x73*/ u8 unk_73;
    /*0x74*/ u16 linkData[10];
    /*0x88*/ u8 unk_88;
    /*0x89*/ u8 unk_89;
    /*0x8A*/ u16 unk_8A;
    /*0x8C*/ u16 unk_8C;
    /*0x8E*/ u8 pokePicSpriteIdxs[2];
    /*0x90*/ u8 unk_90;
    /*0x91*/ u8 unk_91;
    /*0x92*/ u8 unk_92;
    /*0x93*/ u8 unk_93;
    /*0x94*/ u16 unk_94;
    /*0x96*/ u8 filler_96[0xD2 - 0x96];
    /*0xD2*/ u8 unk_D2;
    /*0xD3*/ u8 unk_D3;
    /*0xD4*/ u16 unk_D4;
    /*0xD6*/ u16 unk_D6;
    /*0xD8*/ u16 unk_D8;
    /*0xDA*/ u16 unk_DA;
    /*0xDC*/ s16 unk_DC;
    /*0xDE*/ s16 unk_DE;
    /*0xE0*/ s16 bg1vofs;
    /*0xE2*/ s16 bg1hofs;
    /*0xE4*/ s16 bg2vofs;
    /*0xE6*/ s16 bg2hofs;
    /*0xE8*/ s16 unk_E8;
    /*0xEA*/ u16 unk_EA;
    /*0xEC*/ u16 unk_EC;
    /*0xEE*/ bool8 isLinkTrade;
    /*0xEF*/ u8 filler_EF;
    /*0xF0*/ u16 tradeSpecies[2];
    /*0xF4*/ u16 unk_F4;
    /*0xF6*/ u8 unk_F6[3];
    /*0xF9*/ u8 filler_F9;
    /*0xFA*/ u8 unk_FA;
    /*0xFB*/ u8 unk_FB;
    /*0xFC*/ u8 unk_FC;
    /*0xFD*/ u8 unk_FD;
    /*0xFE*/ u8 unk_FE;
} *gUnknown_020322A0;

extern u8 gUnknown_0203CF20;

extern const struct BgTemplate gUnknown_0832DEE4[4];
extern const struct WindowTemplate gUnknown_0832DEF4[];
extern const u8 gUnknown_0832DE24[][2];
extern const u8 *gUnknown_0832DE94[];
extern const struct SpriteTemplate gSpriteTemplate_832DC94;
extern const struct SpriteTemplate gSpriteTemplate_832DCAC;
extern const u8 gTradeStripesBG2Tilemap[];
extern const u8 gTradeStripesBG3Tilemap[];
extern struct MailStruct gUnknown_020321C0[PARTY_SIZE];
extern const u8 gJPText_Shedinja[];
extern const u8 gText_IsThisTradeOkay[];
extern const u8 gUnknown_0832DCEC[][4][6];
extern const struct MenuAction gUnknown_0832DEAC[];
extern const struct WindowTemplate gUnknown_0832DF8C;
extern const u16 gTradePartyBoxTilemap[];
extern const u16 gTradeMovesBoxTilemap[];
extern const u8 gUnknown_0832DEE0[];
extern const u8 gUnknown_0832DF99[][2];
extern const u8 gText_EmptyString7[];
extern const u8 gText_NewLine3[];
extern const u8 gText_FourQuestionMarks[];
extern const u8 *gUnknown_0832DEBC[];
extern const struct SpritePalette gSpritePalette_TradeScreenText;
extern const struct SpritePalette gUnknown_0832DC44;
extern const struct SpriteSheet gUnknown_0832DC3C;
extern const u16 gUnknown_08338EA4[];
extern const struct SpriteSheet gUnknown_08338D18;
extern const struct SpritePalette gUnknown_08338D20;
extern const struct BgTemplate gUnknown_08339014[4];
extern const struct WindowTemplate gUnknown_08338FFC[];
extern const u16 gUnknown_08331F60[];
extern const u16 gUnknown_083359A0[];
extern const u16 gUnknown_083369A0[];
extern const u32 gUnknown_083379A0[];
extern const u16 gUnknown_0832FFC0[];
extern const u16 gUnknown_08337EA0[];
extern const u32 gUnknown_08337EC0[];
extern const u32 gUnknown_08338550[];
extern const u8 gUnknown_08332F60[];
extern const u8 gUnknown_083357A0[];
extern const u8 gUnknown_083358A0[];
extern const struct SpriteSheet gUnknown_08338D70;
extern const struct SpriteSheet gUnknown_08338DC0;
extern const struct SpriteSheet gUnknown_08338DF4;
extern const struct SpriteSheet gUnknown_08338E6C;
extern const struct SpritePalette gUnknown_08338D78;
extern const struct SpritePalette gUnknown_08338D80;
extern const struct InGameTrade gIngameTrades[];
extern const struct SpriteTemplate gSpriteTemplate_8338D28;
extern const struct SpriteTemplate gSpriteTemplate_8338E74;
extern const struct SpriteTemplate gSpriteTemplate_8338DFC;
extern const struct SpriteTemplate gUnknown_08338D88;
extern const struct SpriteTemplate gSpriteTemplate_8338DC8;
extern const union AffineAnimCmd *const gSpriteAffineAnimTable_8338ECC[];
extern const struct SpriteTemplate gSpriteTemplate_8338E74;
extern const struct SpriteTemplate gSpriteTemplate_8338E8C;
extern const s8 gTradeBallVerticalVelocityTable[];
extern const u16 gIngameTradeMail[][10];
extern const u8 gUnknown_08339090[][2];
extern const u16 gUnknown_08337AA0[];
extern const u16 gUnknown_08337CA0[];

// external to this file
extern const struct CompressedSpriteSheet gMonFrontPicTable[];
extern const struct MonCoords gMonFrontPicCoords[];

bool32 sub_8077260(void);
void sub_80773D0(void);
void sub_807811C(void);
void sub_807A19C(u8);
bool8 shedinja_maker_maybe(void);
void sub_807A308(const u8 *, u8 *, u8);
bool8 sub_807A1F0(void);
void sub_807A320(u8);
void sub_8079BE0(u8);
void sub_8078388(void);
void sub_80782B8(u8);
void sub_807A468(u8);
void sub_807A53C(void);
void sub_8078C34(void);
void sub_807825C(void);
void sub_807A5B0(void);
void sub_80795AC(void);
void sub_807A0C4(void);
void sub_80796B4(u8);
void sub_8079E44(u8);
void sub_807967C(u8);
void sub_807A048(u16, u8);
void sub_8079F74(void);
u32 sub_807A5F4(struct Pokemon *, int, int);
void sub_8079F88(u8);
u32 sub_807A09C(void);
u8 sub_8079A3C(u8 *, bool8, u8);
void sub_8079AA4(u8 *, u8, u8);
void sub_8079C4C(u8, u8, u8, u8, u8, u8);
void sub_807B170(void);
void sub_807B154(void);
void sub_807BA94(void);
void sub_807B140(void);
void sub_807BAD8(void);
void sub_807EA2C(void);
void sub_807B62C(u8);
void sub_807B60C(void);
u8 sub_807BBC8(void);
u8 sub_807CFC8(void);
u8 sub_807BBEC(void);
void sub_807F1A8(u8, const u8 *, u8);
void sub_807E5D8(struct Sprite *);
void sub_807AAE0(struct Sprite *);
void sub_807E6AC(struct Sprite *);
void sub_807F14C(void);
void sub_807E784(void);
void c3_08054588(u8);
void c3_0805465C(u8);
void sub_807F39C(u8);
void sub_807EB50(void);
void sub_807F464(void);
void sub_807E64C(struct Sprite *);
void sub_807E974(struct MailStruct *mail, const struct InGameTrade *trade);
void sub_807EACC(void);
void c2_080543C4(void);
void sub_807F110(u8);

bool8 sub_8077170(const void *a0, u32 a1)
{
    if (gUnknown_02022C2C == 29)
    {
        rfu_NI_setSendData(gUnknown_03004140.unk_00, 84, a0, a1);
        return TRUE;
    }
    else
    {
        return SendBlock(0, a0, a1);
    }
}

void sub_80771AC(u8 a0)
{
    sub_800A4D8(a0);
}

bool32 sub_80771BC(void)
{
    if (gUnknown_02022C2C == 29)
    {
        if (gUnknown_03007880[sub_800E87C(gUnknown_03004140.unk_00)]->unk_0 == 0)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return sub_800A520();
    }
}

u32 sub_8077200(void)
{
    return GetBlockReceivedStatus();
}

void sub_8077210(void)
{
    if (sub_8077260())
    {
        rfu_clearSlot(12, gUnknown_03004140.unk_00);
    }
    else
    {
        ResetBlockReceivedFlags();
    }
}

void sub_8077234(u32 a0)
{
    if (sub_8077260())
    {
        rfu_clearSlot(12, gUnknown_03004140.unk_00);
    }
    else
    {
        ResetBlockReceivedFlag(a0);
    }
}

bool32 sub_8077260(void)
{
    if (gWirelessCommType != 0 && gUnknown_02022C2C == 29)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void sub_8077288(u8 unused)
{
    sub_800ADF8();
}

bool32 IsLinkTaskFinished(void)
{
    return sub_800A520();
}

void sub_80772A4(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ResetPaletteFade();

    gPaletteFade.bufferTransferDisabled = TRUE;

    SetVBlankCallback(sub_807811C);
    LoadPalette(gUnknown_0860F074, 0xF0, 20);
    LoadPalette(gUnknown_0860F074, 0xD0, 20);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0832DEE4, ARRAY_COUNT(gUnknown_0832DEE4));
    SetBgTilemapBuffer(1, gUnknown_0203229C->tilemapBuffer);

    if (InitWindows(gUnknown_0832DEF4))
    {
        u32 i;

        DeactivateAllTextPrinters();

        for (i = 0; i < 18; i++)
        {
            ClearWindowTilemap(i);
            FillWindowPixelBuffer(i, 0);
        }

        FillBgTilemapBufferRect(0, 0, 0, 0, 30, 20, 15);
        LoadUserWindowBorderGfx_(0, 20, 0xC0);
        LoadUserWindowBorderGfx(2, 1, 0xE0);
        LoadMonIconPalettes();
        gUnknown_0203229C->unk_69 = 0;
        gUnknown_0203229C->unk_6F = 0;
        gUnknown_0203229C->unk_70 = 0;
        gUnknown_0203229C->unk_74[0] = 0;
        gUnknown_0203229C->unk_74[1] = 0;
        gUnknown_0203229C->unk_7A = 0;
        gUnknown_0203229C->unk_7B = 0;
        gUnknown_0203229C->unk_A8 = 0;
    }
}

void sub_80773AC(void)
{
    SetMainCallback2(sub_80773D0);
    gMain.callback1 = NULL;
    gEnemyPartyCount = 0;
}

void sub_80773D0(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;

    switch (gMain.state)
    {
    case 0:
        gUnknown_0203229C = AllocZeroed(sizeof(*gUnknown_0203229C));
        sub_80772A4();
        gUnknown_02032184 = AllocZeroed(0xE00);

        for (i = 0; i < 14; i++)
        {
            gUnknown_02032188[i] = &gUnknown_02032184[i * 256];
        }

        gMain.state++;
        break;
    case 1:
        gPaletteFade.bufferTransferDisabled = FALSE;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            CreateMon(&gEnemyParty[i], SPECIES_NONE, 0, 0x20, FALSE, 0, 0, 0);
        }

        sub_807A19C(0);
        ShowBg(0);

        if (gReceivedRemoteLinkPlayers == 0)
        {
            gLinkType = 0x1122;
            gUnknown_0203229C->unk_A8 = 0;

            if (gWirelessCommType != 0)
            {
                sub_800B488();
                OpenLink();
                sub_8011BA4();
            }
            else
            {
                OpenLink();
                gMain.state++;
                CreateTask(task00_08081A90, 1);
            }
        }
        else
        {
            gMain.state = 4;
        }
        break;
    case 2:
        gUnknown_0203229C->unk_A8++;
        if (gUnknown_0203229C->unk_A8 > 11)
        {
            gUnknown_0203229C->unk_A8 = 0;
            gMain.state++;
        }
        break;
    case 3:
        if (GetLinkPlayerCount_2() >= sub_800AA48())
        {
            if (IsLinkMaster())
            {
                if (++gUnknown_0203229C->unk_A8 > 30)
                {
                    sub_800A620();
                    gMain.state++;
                }
            }
            else
            {
                gMain.state++;
            }
        }
        break;
    case 4:
        if (gReceivedRemoteLinkPlayers == 1 && IsLinkPlayerDataExchangeComplete() == 1)
        {
            sub_8011BD0();
            CalculatePlayerPartyCount();
            gMain.state++;
            gUnknown_0203229C->unk_A8 = 0;
            if (gWirelessCommType != 0)
            {
                sub_801048C(TRUE);
                sub_800ADF8();
            }
        }
        break;
    case 5:
        if (gWirelessCommType != 0)
        {
            if (sub_8010500())
            {
                gMain.state++;
                sub_800E0E8();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            gMain.state++;
        }
        break;
    case 6:
        if (shedinja_maker_maybe())
        {
            sub_807A5B0();
            gMain.state++;
        }
        break;
    case 7:
        CalculateEnemyPartyCount();
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        gUnknown_0203229C->partyCounts[0] = gPlayerPartyCount;
        gUnknown_0203229C->partyCounts[1] = gEnemyPartyCount;

        for (i = 0; i < gUnknown_0203229C->partyCounts[0]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            gUnknown_0203229C->unk_28[0][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < gUnknown_0203229C->partyCounts[1]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            gUnknown_0203229C->unk_28[1][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i + PARTY_SIZE][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        sub_81B5D4C(&gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->unk_28[0], 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->unk_28[0], 1);
        gMain.state++;
        break;
    case 10:
        sub_80C6D80(gSaveBlock2Ptr->playerName, gUnknown_02032188[0], 0, 0, 3);
        id = GetMultiplayerId();
        sub_80C6D80(gLinkPlayers[id ^ 1].name, gUnknown_02032188[3], 0, 0, 3);
        sub_80C6D80(gUnknown_0832DE94[0], gUnknown_02032188[6], 0, 0, 2);
        sub_807A308(gUnknown_0832DE94[1], gUnknown_02032188[8], 24);
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 11:
        if (sub_807A1F0())
            gMain.state++;
        break;
    case 12:
        xPos = GetStringCenterAlignXOffset(1, gSaveBlock2Ptr->playerName, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i;
            CreateSprite(&temp, xPos + (i * 32) + 16, 10, 1);
        }

        xPos = GetStringCenterAlignXOffset(1, gLinkPlayers[GetMultiplayerId() ^ 1].name, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 3;
            CreateSprite(&temp, xPos + (i * 32) + 136, 10, 1);
        }
        gMain.state++;
        break;
    case 13:
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 6;
        CreateSprite(&temp, 215, 152, 1);
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 7;
        CreateSprite(&temp, 247, 152, 1);

        for (i = 0; i < PARTY_SIZE; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 8;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        gUnknown_0203229C->unk_34 = CreateSprite(&gSpriteTemplate_832DC94, gUnknown_0832DE24[0][0] * 8 + 32, gUnknown_0832DE24[0][1] * 8, 2);
        gUnknown_0203229C->unk_35 = 0;
        gMain.state++;
        rbox_fill_rectangle(0);
        break;
    case 14:
        sub_807A320(0);
        sub_8079BE0(0);
        gUnknown_0203229C->unk_0 = 0;
        gUnknown_0203229C->unk_1 = 0;
        sub_8078388();
        gMain.state++;
        PlayBGM(MUS_P_SCHOOL);
        break;
    case 15:
        sub_807A320(1);
        sub_8079BE0(1);
        gMain.state++;
    case 16: // fallthrough
        sub_80782B8(0);
        gMain.state++;
        break;
    case 17:
        sub_80782B8(1);
        gMain.state++;
        break;
    case 18:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        sub_80782B8(2);
        gMain.state++;
        break;
    case 20:
        sub_807A468(0);
        gMain.state++;
        break;
    case 21:
        sub_807A468(1);
        sub_807A53C();
        gMain.state++;
        break;
    case 22:
        if (!gPaletteFade.active)
        {
            gMain.callback1 = sub_8078C34;
            SetMainCallback2(sub_807825C);
        }
        break;
    }

    RunTextPrinters();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_8077B74(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;

    switch (gMain.state)
    {
    case 0:
        sub_80772A4();
        gMain.state++;
        break;
    case 1:
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 2:
        gMain.state++;
        break;
    case 3:
        gMain.state++;
        break;
    case 4:
        CalculatePlayerPartyCount();
        gMain.state++;
        break;
    case 5:
        if (gWirelessCommType != 0)
        {
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        gMain.state++;
        break;
    case 6:
        gMain.state++;
        break;
    case 7:
        CalculateEnemyPartyCount();
        gUnknown_0203229C->partyCounts[0] = gPlayerPartyCount;
        gUnknown_0203229C->partyCounts[1] = gEnemyPartyCount;
        ClearWindowTilemap(0);
        sub_8079BE0(0);
        sub_8079BE0(1);

        for (i = 0; i < gUnknown_0203229C->partyCounts[0]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            gUnknown_0203229C->unk_28[0][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < gUnknown_0203229C->partyCounts[1]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            gUnknown_0203229C->unk_28[1][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gUnknown_0832DE24[i + PARTY_SIZE][0] * 8) + 14,
                                                         (gUnknown_0832DE24[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        sub_81B5D4C(&gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->unk_28[0], 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->unk_28[0], 1);
        gMain.state++;
        break;
    case 10:
        sub_80C6D80(gSaveBlock2Ptr->playerName, gUnknown_02032188[0], 0, 0, 3);
        id = GetMultiplayerId();
        sub_80C6D80(gLinkPlayers[id ^ 1].name, gUnknown_02032188[3], 0, 0, 3);
        sub_80C6D80(gUnknown_0832DE94[0], gUnknown_02032188[6], 0, 0, 2);
        sub_807A308(gUnknown_0832DE94[1], gUnknown_02032188[8], 24);
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 11:
        if (sub_807A1F0())
            gMain.state++;
        break;
    case 12:
        xPos = GetStringCenterAlignXOffset(1, gSaveBlock2Ptr->playerName, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i;
            CreateSprite(&temp, xPos + (i * 32) + 16, 10, 1);
        }

        xPos = GetStringCenterAlignXOffset(1, gLinkPlayers[GetMultiplayerId() ^ 1].name, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 3;
            CreateSprite(&temp, xPos + (i * 32) + 136, 10, 1);
        }
        gMain.state++;
        break;
    case 13:
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 6;
        CreateSprite(&temp, 215, 152, 1);
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 7;
        CreateSprite(&temp, 247, 152, 1);

        for (i = 0; i < PARTY_SIZE; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 8;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        if (gUnknown_0203229C->unk_35 < PARTY_SIZE)
        {
            gUnknown_0203229C->unk_35 = gUnknown_0203CF20;
        }
        else
        {
            gUnknown_0203229C->unk_35 = gUnknown_0203CF20 + PARTY_SIZE;
        }

        gUnknown_0203229C->unk_34 = CreateSprite(&gSpriteTemplate_832DC94, gUnknown_0832DE24[gUnknown_0203229C->unk_35][0] * 8 + 32, gUnknown_0832DE24[gUnknown_0203229C->unk_35][1] * 8, 2);
        gMain.state = 16;
        break;
    case 16:
        sub_80782B8(0);
        gMain.state++;
        break;
    case 17:
        sub_80782B8(1);
        gUnknown_0203229C->unk_0 = 0;
        gUnknown_0203229C->unk_1 = 0;
        sub_8078388();
        gMain.state++;
        break;
    case 18:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        sub_80782B8(2);
        gMain.state++;
        break;
    case 20:
        gMain.state++;
        break;
    case 21:
        sub_807A53C();
        gMain.state++;
        break;
    case 22:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(sub_807825C);
        }
        break;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807811C(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_8078130(void)
{
    if (++gUnknown_0203229C->unk_A8 > 15)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_0203229C->unk_6F = 10;
    }
}

void sub_807816C(void)
{
    if (!gPaletteFade.active)
    {
        gUnknown_02032298[0] = gUnknown_0203229C->unk_35;
        gUnknown_02032298[1] = gUnknown_0203229C->unk_7E;

        if (gWirelessCommType != 0)
        {
            gUnknown_0203229C->unk_6F = 16;
        }
        else
        {
            sub_800ABF4(32);
            gUnknown_0203229C->unk_6F = 13;
        }
    }
}

void sub_80781C8(void)
{
    gMain.savedCallback = sub_80773AC;

    if (gWirelessCommType != 0)
    {
        if (sub_8010500())
        {
            Free(gUnknown_02032184);
            FreeAllWindowBuffers();
            Free(gUnknown_0203229C);
            gMain.callback1 = NULL;
            sub_800E084();
            SetMainCallback2(sub_807AE50);
        }
    }
    else
    {
        if (gReceivedRemoteLinkPlayers == 0)
        {
            Free(gUnknown_02032184);
            FreeAllWindowBuffers();
            Free(gUnknown_0203229C);
            gMain.callback1 = NULL;
            SetMainCallback2(sub_807AE50);
        }
    }
}

void sub_807825C(void)
{
    u8 temp;

    sub_80795AC();
    sub_807A0C4();
    sub_80796B4(0);
    sub_80796B4(1);

    SetGpuReg(REG_OFFSET_BG2HOFS, gUnknown_0203229C->unk_0++);
    SetGpuReg(REG_OFFSET_BG3HOFS, gUnknown_0203229C->unk_1--);

    RunTextPrintersAndIsPrinter0Active();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_80782B8(u8 a0)
{
    int i;

    switch (a0)
    {
    case 0:
        LoadPalette(gUnknown_08DDB3E4, 0, 0x60);
        LoadBgTiles(1, gUnknown_08DDB464, 0x1280, 0);
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDCF04, 0, 0, 32, 20, 0);
        LoadBgTilemap(2, gTradeStripesBG2Tilemap, 0x800, 0);
        break;
    case 1:
        LoadBgTilemap(3, gTradeStripesBG3Tilemap, 0x800, 0);
        sub_8079E44(0);
        sub_8079E44(1);
        CopyBgTilemapBufferToVram(1);
        break;
    case 2:
        for (i = 0; i < 4; i++)
        {
            SetGpuReg(REG_OFFSET_BG0HOFS + (i * 2), 0);
        }
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        break;
    }
}

void sub_8078388(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i < gUnknown_0203229C->partyCounts[0])
        {
            gSprites[gUnknown_0203229C->unk_28[0][i]].invisible = FALSE;
            gUnknown_0203229C->unk_38[i] = TRUE;
        }
        else
        {
            gUnknown_0203229C->unk_38[i] = FALSE;
        }

        if (i < gUnknown_0203229C->partyCounts[1])
        {
            gSprites[gUnknown_0203229C->unk_28[1][i]].invisible = FALSE;
            gUnknown_0203229C->unk_38[i + PARTY_SIZE] = TRUE;
        }
        else
        {
            gUnknown_0203229C->unk_38[i + PARTY_SIZE] = FALSE;
        }
    }

    gUnknown_0203229C->unk_44 = 1;
}

void sub_8078438(u8 *dest, const u8 *src, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++)
    {
        dest[i] = src[i];
    }
}

bool8 shedinja_maker_maybe(void)
{
    u8 id = GetMultiplayerId();
    int i;
    struct Pokemon *mon;

    switch (gUnknown_0203229C->unk_69)
    {
    case 0:
        sub_8078438(gBlockSendBuffer, (void *)&gPlayerParty[0], 200);
        gUnknown_0203229C->unk_69++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 1:
        if (sub_80771BC())
        {
            if (!sub_8077200())
            {
                gUnknown_0203229C->unk_69++;
            }
            else
            {
                sub_8077210();
                gUnknown_0203229C->unk_69++;
            }
        }
        break;
    case 3:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 4:
        if (sub_8077200() == 3)
        {
            sub_8078438((void *)&gEnemyParty[0], (void *)gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 5:
        sub_8078438(gBlockSendBuffer, (void *)&gPlayerParty[2], 200);
        gUnknown_0203229C->unk_69++;
        break;
    case 7:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 8:
        if (sub_8077200() == 3)
        {
            sub_8078438((void *)&gEnemyParty[2], (void *)gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 9:
        sub_8078438(gBlockSendBuffer, (void *)&gPlayerParty[4], 200);
        gUnknown_0203229C->unk_69++;
        break;
    case 11:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 12:
        if (sub_8077200() == 3)
        {
            sub_8078438((void *)&gEnemyParty[4], (void *)gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 13:
        sub_8078438(gBlockSendBuffer, (void *)gSaveBlock1Ptr->mail, 220);
        gUnknown_0203229C->unk_69++;
        break;
    case 15:
        if (id == 0)
        {
            sub_80771AC(3);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 16:
        if (sub_8077200() == 3)
        {
            sub_8078438((void *)gUnknown_020321C0, (void *)gBlockRecvBuffer[id ^ 1], 216);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 17:
        sub_8078438(gBlockSendBuffer, gSaveBlock1Ptr->giftRibbons, 11);
        gUnknown_0203229C->unk_69++;
        break;
    case 19:
        if (id == 0)
        {
            sub_80771AC(4);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 20:
        if (sub_8077200() == 3)
        {
            sub_8078438(gUnknown_0203229C->unk_A9, (void *)gBlockRecvBuffer[id ^ 1], 11);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 21:
        for (i = 0, mon = gEnemyParty; i < PARTY_SIZE; mon++, i++)
        {
            u8 name[POKEMON_NAME_LENGTH + 1];
            u16 species = GetMonData(mon, MON_DATA_SPECIES);

            if (species != SPECIES_NONE)
            {
                if (species == SPECIES_SHEDINJA && GetMonData(mon, MON_DATA_LANGUAGE) != LANGUAGE_JAPANESE)
                {
                    GetMonData(mon, MON_DATA_NICKNAME, name);

                    if (!StringCompareWithoutExtCtrlCodes(name, gJPText_Shedinja))
                    {
                        SetMonData(mon, MON_DATA_NICKNAME, gSpeciesNames[SPECIES_SHEDINJA]);
                    }
                }
            }
        }
        return TRUE;
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
        gUnknown_0203229C->unk_A8++;
        if (gUnknown_0203229C->unk_A8 > 10)
        {
            gUnknown_0203229C->unk_A8 = 0;
            gUnknown_0203229C->unk_69++;
        }
        break;
    }
    return FALSE;
}

void sub_80787B8(void)
{
    sub_807A308(gText_IsThisTradeOkay, (void *)(OBJ_VRAM0 + (gUnknown_0203229C->unk_72 * 32)), 24);
}

void sub_80787E0(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEAA:
            gUnknown_0203229C->unk_78 = 2;
            break;
        case 0xAABB:
            gUnknown_0203229C->unk_78 = 1;
            break;
        case 0xBBBB:
            gUnknown_0203229C->unk_7A = 1;
            break;
        case 0xBBCC:
            gUnknown_0203229C->unk_7A = 2;
            break;
        }
        sub_8077234(0);
    }

    if (a1 & 2)
    {
        switch (gBlockRecvBuffer[1][0])
        {
        case 0xEEAA:
            gUnknown_0203229C->unk_79 = 2;
            break;
        case 0xAABB:
            gUnknown_0203229C->unk_7E = gBlockRecvBuffer[1][1] + 6;
            gUnknown_0203229C->unk_79 = 1;
            break;
        case 0xBBBB:
            gUnknown_0203229C->unk_7B = 1;
            break;
        case 0xBBCC:
            gUnknown_0203229C->unk_7B = 2;
            break;
        }
        sub_8077234(1);
    }
}

void sub_8078900(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEBB:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sub_807A19C(4);
            gUnknown_0203229C->unk_6F = 11;
            break;
        case 0xEECC:
            sub_807A19C(5);
            gUnknown_0203229C->unk_6F = 8;
            break;
        case 0xDDDD:
            gUnknown_0203229C->unk_7E = gBlockRecvBuffer[0][1] + 6;
            rbox_fill_rectangle(0);
            sub_807967C(gUnknown_0203229C->unk_35);
            sub_807967C(gUnknown_0203229C->unk_7E);
            gUnknown_0203229C->unk_6F = 7;
            break;
        case 0xCCDD:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 10;
            break;
        case 0xDDEE:
            sub_807A19C(1);
            gUnknown_0203229C->unk_6F = 8;
        }
        sub_8077234(0);
    }

    if (a1 & 2)
    {
        sub_8077234(1);
    }
}

void sub_80789FC(void)
{
    if (gUnknown_0203229C->unk_78 && gUnknown_0203229C->unk_79)
    {
        if (gUnknown_0203229C->unk_78 == 1 && gUnknown_0203229C->unk_79 == 1)
        {
            gUnknown_0203229C->unk_6F = 6;
            gUnknown_0203229C->unk_80[0] = 0xDDDD;
            gUnknown_0203229C->unk_80[1] = gUnknown_0203229C->unk_35;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
        }
        else if (gUnknown_0203229C->unk_78 == 1 && gUnknown_0203229C->unk_79 == 2)
        {
            sub_807A19C(1);
            gUnknown_0203229C->unk_80[0] = 0xEECC;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
        else if (gUnknown_0203229C->unk_78 == 2 && gUnknown_0203229C->unk_79 == 1)
        {
            sub_807A19C(5);
            gUnknown_0203229C->unk_80[0] = 0xDDEE;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
        else if (gUnknown_0203229C->unk_78 == 2 && gUnknown_0203229C->unk_79 == 2)
        {
            gUnknown_0203229C->unk_80[0] = 0xEEBB;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_6F = 11;
        }
    }

    if (gUnknown_0203229C->unk_7A && gUnknown_0203229C->unk_7B)
    {
        if (gUnknown_0203229C->unk_7A == 1 && gUnknown_0203229C->unk_7B == 1)
        {
            gUnknown_0203229C->unk_80[0] = 0xCCDD;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = 0;
            gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_6F = 9;
        }

        if (gUnknown_0203229C->unk_7A == 2 || gUnknown_0203229C->unk_7B == 2)
        {
            sub_807A19C(1);
            gUnknown_0203229C->unk_80[0] = 0xDDEE;
            gUnknown_0203229C->unk_80[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = 0;
            gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
    }
}

void sub_8078BFC(u16 *a0, u16 a1, u16 a2)
{
    a0[0] = a1;
    a0[1] = a2;
    sub_807A048(5, 0);
}

void sub_8078C10(u16 a0, u16 a1)
{
    sub_8078BFC(gUnknown_0203229C->unk_80, a0, a1);
}

void sub_8078C34(void)
{
    u8 id = GetMultiplayerId();
    u8 unk;

    if ((unk = sub_8077200()))
    {
        if (id == 0)
        {
            sub_80787E0(id, unk);
        }
        else
        {
            sub_8078900(id, unk);
        }
    }

    if (id == 0)
    {
        sub_80789FC();
    }
}

u8 sub_8078C6C(u8 a0, u8 a1)
{
    int i;
    u8 ret = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gUnknown_0203229C->unk_38[gUnknown_0832DCEC[a0][a1][i]] == 1)
        {
            ret = gUnknown_0832DCEC[a0][a1][i];
            break;
        }
    }

    return ret;
}

void sub_8078CB8(u8 *a0, u8 a1)
{
    u8 unk = sub_8078C6C(*a0, a1);

    if (unk == 12)
    {
        StartSpriteAnim(&gSprites[gUnknown_0203229C->unk_34], 1);
        gSprites[gUnknown_0203229C->unk_34].pos1.x = 224;
        gSprites[gUnknown_0203229C->unk_34].pos1.y = 160;
    }
    else
    {
        StartSpriteAnim(&gSprites[gUnknown_0203229C->unk_34], 0);
        gSprites[gUnknown_0203229C->unk_34].pos1.x = gUnknown_0832DE24[unk][0] * 8 + 32;
        gSprites[gUnknown_0203229C->unk_34].pos1.y = gUnknown_0832DE24[unk][1] * 8;
    }

    if (*a0 != unk)
    {
        PlaySE(SE_SELECT);
    }

    *a0 = unk;
}

void sub_8078D78(void)
{
    sub_807A19C(0);
    gUnknown_0203229C->unk_6F = 100;

    if (GetMultiplayerId() == 1)
    {
        sub_8078C10(0xAABB, gUnknown_0203229C->unk_35);
    }
    else
    {
        gUnknown_0203229C->unk_78 = 1;
    }
}

void sub_8078DBC(void)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        sub_8078CB8(&gUnknown_0203229C->unk_35, 0);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        sub_8078CB8(&gUnknown_0203229C->unk_35, 1);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        sub_8078CB8(&gUnknown_0203229C->unk_35, 2);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        sub_8078CB8(&gUnknown_0203229C->unk_35, 3);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        if (gUnknown_0203229C->unk_35 < 6)
        {
            sub_8098858(1, 1, 14);
            FillWindowPixelBuffer(1, 0x11);
            PrintMenuTable(1, 2, gUnknown_0832DEAC);
            InitMenuInUpperLeftCornerPlaySoundWhenAPressed(1, 2, 0);
            PutWindowTilemap(1);
            CopyWindowToVram(1, 3);
            gUnknown_0203229C->unk_6F = 1;
        }
        else if (gUnknown_0203229C->unk_35 < 12)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 2;
        }
        else if (gUnknown_0203229C->unk_35 == 12)
        {
            CreateYesNoMenu(&gUnknown_0832DF8C, 1, 14, 0);
            gUnknown_0203229C->unk_6F = 4;
            sub_807A308(gUnknown_0832DE94[4], (void *)(OBJ_VRAM0 + gUnknown_0203229C->unk_72 * 32), 24);
        }
    }
}

void sub_8078EF8(void)
{
    sub_8079F74();
    gUnknown_0203229C->unk_6F = 0;
    gSprites[gUnknown_0203229C->unk_34].invisible = FALSE;
    sub_807A308(gUnknown_0832DE94[1], (void *)(OBJ_VRAM0 + gUnknown_0203229C->unk_72 * 32), 24);
}

void sub_8078F50(void)
{
    switch (Menu_ProcessInputNoWrap())
    {
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8078EF8();
            break;
        case MENU_NOTHING_CHOSEN:
            break;
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 2;
            break;
        case 1:
            switch (sub_807A5F4(gPlayerParty, gPlayerPartyCount, gUnknown_0203229C->unk_35))
            {
                case 0:
                    sub_8078D78();
                    gSprites[gUnknown_0203229C->unk_34].invisible = TRUE;
                    break;
                case 1:
                    sub_807A048(3, 3);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
                case 2:
                case 4:
                    sub_807A048(3, 6);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
                case 3:
                case 5:
                    sub_807A048(3, 7);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
            }
            break;
    }
}

void sub_8079034(void)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sub_8078EF8();
    }
}

void sub_807905C(void)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203229C->unk_35 < PARTY_SIZE)
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gPlayerParty, gUnknown_0203229C->unk_35, gUnknown_0203229C->partyCounts[0] - 1, sub_8077B74);
        }
        else
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gEnemyParty, gUnknown_0203229C->unk_35 - PARTY_SIZE, gUnknown_0203229C->partyCounts[1] - 1, sub_8077B74);
        }
        FreeAllWindowBuffers();
    }
}

u8 sub_80790D4(u8 *a0, u8 a1, u8 a2, u8 a3)
{
    int i;
    u16 species;
    u8 res = 0;

    for (i = 0; i < a1; i++)
    {
        if (a2 != i)
        {
            res += a0[i];
        }
    }

    a3 %= PARTY_SIZE;
    species = GetMonData(&gEnemyParty[a3], MON_DATA_SPECIES);

    if (species == SPECIES_DEOXYS || species == SPECIES_MEW)
    {
        if (!GetMonData(&gEnemyParty[a3], MON_DATA_OBEDIENCE))
        {
            return 2;
        }
    }

    if (!IsNationalPokedexEnabled())
    {
        if (gUnknown_0203229C->unk_51[1][a3] || !IsSpeciesInHoennDex(species))
        {
            return 2;
        }
    }

    if (res)
    {
        res = 1;
    }

    return res;
}

bool32 sub_8079174(void)
{
    int i;
    u8 arr[12];

    for (i = 0; i < gUnknown_0203229C->partyCounts[0]; i++)
    {
        arr[i] = gUnknown_0203229C->unk_45[0][i];
    }

    switch (sub_80790D4(arr, gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->unk_35, gUnknown_0203229C->unk_7E))
    {
        case 0:
            sub_807A048(3, 3);
            sub_8078C10(0xBBCC, 0);
            break;
        case 1:
            sub_807A048(3, 1);
            sub_8078C10(0xBBBB, 0);
            break;
        case 2:
            sub_807A048(3, 8);
            return TRUE;
    }

    return FALSE;
}

void sub_8079218(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            if (!sub_8079174())
            {
                gUnknown_0203229C->unk_6F = 100;
            }
            else
            {
                gUnknown_0203229C->unk_6F = 17;
            }
            PutWindowTilemap(17);
            break;
        case 1:
        case MENU_B_PRESSED:
            sub_807A048(3, 1);
            if (sub_80771BC())
            {
                sub_8078C10(0xBBCC, 0);
            }
            gUnknown_0203229C->unk_6F = 100;
            PutWindowTilemap(17);
            break;
    }
}

void sub_807929C(void)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->partyCounts[1] - 4; i++)
    {
        PutWindowTilemap(i + 12);
        CopyWindowToVram(i + 12, 1);
    }
}

void sub_80792E4(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            sub_807A19C(4);
            sub_8078C10(0xEEAA, 0);
            gSprites[gUnknown_0203229C->unk_34].invisible = TRUE;
            gUnknown_0203229C->unk_6F = 100;
            sub_807929C();
            break;
        case 1:
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8078EF8();
            break;
    }
}

void sub_807935C(void)
{
    if (GetMultiplayerId() == 0)
    {
        rbox_fill_rectangle(0);
        sub_807967C(gUnknown_0203229C->unk_35);
        sub_807967C(gUnknown_0203229C->unk_7E);
    }
    gUnknown_0203229C->unk_6F = 7;
}

void sub_8079398(void)
{
    if (gUnknown_0203229C->unk_74[0] == 5 && gUnknown_0203229C->unk_74[1] == 5)
    {
        sub_80787B8();
        gUnknown_0203229C->unk_6F = 14;
    }
}

void sub_80793C4(void)
{
    gUnknown_0203229C->unk_A8++;

    if (gUnknown_0203229C->unk_A8 > 120)
    {
        CreateYesNoMenu(&gUnknown_0832DF8C, 1, 14, 0);
        gUnknown_0203229C->unk_A8 = 0;
        gUnknown_0203229C->unk_6F = 3;
    }
}

void sub_8079408(void)
{
    int i;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        rbox_fill_rectangle(0);
        rbox_fill_rectangle(1);

        for (i = 0; i < 4; i++)
        {
            FillWindowPixelBuffer(i + 14, 0);
            rbox_fill_rectangle(i + 14);
        }

        sub_8079F88(0);
        sub_8079F88(1);
        gUnknown_0203229C->unk_6F = 0;
        gSprites[gUnknown_0203229C->unk_34].invisible = FALSE;
    }
}

void sub_8079490(void)
{
    if (!gPaletteFade.active)
    {
        if (gWirelessCommType)
        {
            sub_800ADF8();
        }
        else
        {
            sub_800ABF4(12);
        }

        gUnknown_0203229C->unk_6F = 12;
    }
}

void sub_80794CC(void)
{
    if (gWirelessCommType)
    {
        if (sub_80771BC() && sub_807A09C() == 0)
        {
            Free(gUnknown_02032184);
            Free(gUnknown_0203229C);
            FreeAllWindowBuffers();
            sub_800E084();
            SetMainCallback2(c2_8056854);
        }
    }
    else
    {
        if (gReceivedRemoteLinkPlayers == 0)
        {
            Free(gUnknown_02032184);
            Free(gUnknown_0203229C);
            FreeAllWindowBuffers();
            SetMainCallback2(c2_8056854);
        }
    }
}

void sub_8079550(void)
{
    if (!sub_801048C(FALSE) && sub_807A09C() == 0)
    {
        sub_800ADF8();
        gUnknown_0203229C->unk_6F = 13;
    }
}

void sub_807957C(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        sub_8078C10(0xBBCC, 0);
        gUnknown_0203229C->unk_6F = 100;
    }
}

void sub_80795AC(void)
{
    switch (gUnknown_0203229C->unk_6F)
    {
        case 0:
            sub_8078DBC();
            break;
        case 1:
            sub_8078F50();
            break;
        case 2:
            sub_807905C();
            break;
        case 3:
            sub_8079218();
            break;
        case 4:
            sub_80792E4();
            break;
        case 6:
            sub_807935C();
            break;
        case 7:
            sub_8079398();
            break;
        case 8:
            sub_8079408();
            break;
        case 9:
            sub_8078130();
            break;
        case 10:
            sub_807816C();
            break;
        case 11:
            sub_8079490();
            break;
        case 12:
            sub_80794CC();
            break;
        case 13:
            sub_80781C8();
            break;
        case 14:
            sub_80793C4();
            break;
        case 15:
            sub_8079034();
            break;
        case 16:
            sub_8079550();
            break;
        case 17:
            sub_807957C();
            break;
    }
}

void sub_807967C(u8 a0)
{
    u8 whichTeam = a0 / PARTY_SIZE;

    if (gUnknown_0203229C->unk_74[whichTeam] == 0)
    {
        gUnknown_0203229C->unk_74[whichTeam] = 1;
        gUnknown_0203229C->unk_76[whichTeam] = a0;
    }
}

void sub_80796B4(u8 a0)
{
    s8 test;
    u8 sp14[20];
    u8 sp28[56];
    u8 i;
    u8 r8;
    u8 r10;
    u8 sp60;
    u8 var = gUnknown_0203229C->unk_76[a0];

    sp60 = 1;
    if (gUnknown_0203229C->unk_76[a0] < 6)
        sp60 = 0;
    r10 = var % 6;
    test = 0;

    switch (gUnknown_0203229C->unk_74[a0])
    {
    case 1:
        for (i = 0; i < gUnknown_0203229C->partyCounts[a0]; i++)
        {
            gSprites[gUnknown_0203229C->unk_28[0][i + (sp60 * 6)]].invisible = TRUE;
        }

        for (i = 0; i < 6; i++)
        {
            ClearWindowTilemap(i + (a0 * 6 + 2));
        }

        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].invisible = FALSE;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].data[0] = 20;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].data[2] = (gUnknown_0832DE24[sp60 * 6][0] + gUnknown_0832DE24[sp60 * 6 + 1][0]) / 2 * 8 + 14;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].data[4] = (gUnknown_0832DE24[sp60 * 6][1] * 8) - 12;
        StoreSpriteCallbackInData6(&gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]], sub_80D3014);
        gUnknown_0203229C->unk_74[a0]++;
        sub_80A6DEC(&gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]]);
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, a0 * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);

        if (!sp60)
        {
            sub_8079F74();
        }
        break;
    case 2:
        if (gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].callback == sub_80D3014)
        {
            gUnknown_0203229C->unk_74[a0] = 3;
        }
        break;
    case 3:
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMovesBoxTilemap, sp60 * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].pos1.x = (gUnknown_0832DE24[sp60 * 6][0] + gUnknown_0832DE24[sp60 * 6 + 1][0]) / 2 * 8 + 14;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].pos1.y = (gUnknown_0832DE24[sp60 * 6][1] * 8) - 12;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].pos2.x = 0;
        gSprites[gUnknown_0203229C->unk_28[0][r10 + (sp60 * 6)]].pos2.y = 0;
        test = sub_8079A3C(sp14, sp60, r10);
        AddTextPrinterParameterized3((a0 * 2) + 14, 0, (80 - test) / 2, 4, gUnknown_0832DEE0, 0, sp14);
        sub_8079AA4(sp28, sp60, r10);
        AddTextPrinterParameterized4((a0 * 2) + 15, 1, 0, 0, 0, 0, gUnknown_0832DEE0, 0, sp28);
        PutWindowTilemap((a0 * 2) + 14);
        CopyWindowToVram((a0 * 2) + 14, 3);
        PutWindowTilemap((a0 * 2) + 15);
        CopyWindowToVram((a0 * 2) + 15, 3);
        gUnknown_0203229C->unk_74[a0]++;
        break;
    case 4:
        sub_8079C4C(a0, r10, gUnknown_0832DF99[a0][0] + 4, gUnknown_0832DF99[a0][1] + 1, gUnknown_0832DF99[a0][0], gUnknown_0832DF99[a0][1]);
        gUnknown_0203229C->unk_74[a0]++;
        break;
    }
}

u8 sub_8079A3C(u8 *a0, bool8 a1, u8 a2)
{
    u8 name[12];

    if (!a1)
    {
        GetMonData(&gPlayerParty[a2], MON_DATA_NICKNAME, name);
    }
    else
    {
        GetMonData(&gEnemyParty[a2], MON_DATA_NICKNAME, name);
    }

    StringCopy10(a0, name);
    return GetStringWidth(0, a0, GetFontAttribute(0, FONTATTR_LETTER_SPACING));
}

void sub_8079AA4(u8 *a0, u8 a1, u8 a2)
{
    u16 arr[4];
    u16 i;

    if (!gUnknown_0203229C->unk_51[a1][a2])
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (!a1)
            {
                arr[i] = GetMonData(&gPlayerParty[a2], i + MON_DATA_MOVE1, NULL);
            }
            else
            {
                arr[i] = GetMonData(&gEnemyParty[a2], i + MON_DATA_MOVE1, NULL);
            }
        }

        StringCopy(a0, gText_EmptyString7);

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (arr[i] != MOVE_NONE)
            {
                StringAppend(a0, gMoveNames[arr[i]]);
            }

            StringAppend(a0, gText_NewLine3);
        }
    }
    else
    {
        StringCopy(a0, gText_EmptyString7);
        StringAppend(a0, gText_FourQuestionMarks);
    }
}

void sub_8079B84(u8 a0, u8 a1, u8 *a2)
{
    u8 xPos;
    a1 += (a0 * 6) + 2;
    xPos = GetStringCenterAlignXOffset(0, a2, 64);
    AddTextPrinterParameterized3(a1, 0, xPos, 4, gUnknown_0832DEE0, 0, a2);
    PutWindowTilemap(a1);
    CopyWindowToVram(a1, 3);
}

void sub_8079BE0(u8 a0)
{
    u8 i;
    u8 sp[20];
    u8 sp14[32];
    struct Pokemon *mons = a0 == 0 ? gPlayerParty : gEnemyParty;

    for (i = 0; i < gUnknown_0203229C->partyCounts[a0]; i++)
    {
        GetMonData(&mons[i], MON_DATA_NICKNAME, sp);
        StringCopy10(sp14, sp);
        sub_8079B84(a0, i, sp14);
    }
}

void sub_8079C4C(u8 a0, u8 a1, u8 a2, u8 a3, u8 a4, u8 a5)
{
    u8 r6;
    u32 r2;
    u8 gender;
    u8 name[12];

    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDD704, a4, a5, 6, 3, 0);
    CopyBgTilemapBufferToVram(1);

    if (a0 == 0)
    {
        r6 = GetMonData(&gPlayerParty[a1], MON_DATA_LEVEL, NULL);
    }
    else
    {
        r6 = GetMonData(&gEnemyParty[a1], MON_DATA_LEVEL, NULL);
    }

    if (gUnknown_0203229C->unk_51[a0][a1] == 0)
    {
        if (r6 / 10 != 0)
        {
            gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32)] = (r6 / 10) + 0x60;
        }
        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) + 1] = (r6 % 10) + 0x70;
    }
    else
    {
        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 32] = gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 33];
        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 31] = gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 36] | 0x400;
    }

    if (gUnknown_0203229C->unk_51[a0][a1] != 0)
    {
        r2 = 0x480;
    }
    else
    {
        if (a0 == 0)
        {
            gender = GetMonGender(&gPlayerParty[a1]);
            GetMonData(&gPlayerParty[a1], MON_DATA_NICKNAME, name);
        }
        else
        {
            gender = GetMonGender(&gEnemyParty[a1]);
            GetMonData(&gEnemyParty[a1], MON_DATA_NICKNAME, name);
        }

        switch (gender)
        {
            case MON_MALE:
                r2 = !NameHasGenderSymbol(name, MON_MALE) ? 0x84 : 0x83;
                break;
            case MON_FEMALE:
                r2 = !NameHasGenderSymbol(name, MON_FEMALE) ? 0x85 : 0x83;
                break;
            default:
                r2 = 0x83;
                break;
        }
    }
    gUnknown_0203229C->tilemapBuffer[(a3 - 1) * 32 + a2 + 1] = r2;
}

extern const u8 gUnknown_0832DE3E[][6][2];
extern const u8 gUnknown_0832DE56[][6][2];
// Very close but loop preamble not working.
#ifdef NONMATCHING
void sub_8079E44(u8 whichParty)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->partyCounts[whichParty]; i++)
    {
        sub_8079C4C(whichParty, i, gUnknown_0832DE3E[whichParty][i][0], gUnknown_0832DE3E[whichParty][i][1], gUnknown_0832DE56[whichParty][i][0], gUnknown_0832DE56[whichParty][i][1]);
    }
}
#else
NAKED
void sub_8079E44(u8 whichParty)
{
    asm_unified("push {r4-r7,lr}\n\
    sub sp, 0x8\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    movs r7, 0\n\
    ldr r0, =gUnknown_0203229C\n\
    ldr r0, [r0]\n\
    adds r0, 0x36\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    bge _08079E94\n\
    lsls r0, r6, 1\n\
    adds r0, r6\n\
    ldr r1, =gUnknown_0832DE3E\n\
    lsls r0, 2\n\
    adds r5, r0, r1\n\
    ldr r1, =gUnknown_0832DE56\n\
    adds r4, r0, r1\n\
_08079E6A:\n\
    lsls r1, r7, 24\n\
    lsrs r1, 24\n\
    ldrb r2, [r5]\n\
    ldrb r3, [r5, 0x1]\n\
    ldrb r0, [r4]\n\
    str r0, [sp]\n\
    ldrb r0, [r4, 0x1]\n\
    str r0, [sp, 0x4]\n\
    adds r0, r6, 0\n\
    bl sub_8079C4C\n\
    adds r5, 0x2\n\
    adds r4, 0x2\n\
    adds r7, 0x1\n\
    ldr r0, =gUnknown_0203229C\n\
    ldr r0, [r0]\n\
    adds r0, 0x36\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    blt _08079E6A\n\
_08079E94:\n\
    add sp, 0x8\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif // NONMATCHING

void sub_8079EA8(u8 a0)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->partyCounts[a0]; i++)
    {
        gSprites[gUnknown_0203229C->unk_28[a0][i]].invisible = FALSE;
        gSprites[gUnknown_0203229C->unk_28[a0][i]].pos1.x = gUnknown_0832DE24[(a0 * 6) + i][0] * 8 + 14;
        gSprites[gUnknown_0203229C->unk_28[a0][i]].pos1.y = gUnknown_0832DE24[(a0 * 6) + i][1] * 8 - 12;
        gSprites[gUnknown_0203229C->unk_28[a0][i]].pos2.x = 0;
        gSprites[gUnknown_0203229C->unk_28[a0][i]].pos2.y = 0;
    }
}

void sub_8079F74(void)
{
    rbox_fill_rectangle(1);
    sub_8079BE0(1);
}

void sub_8079F88(u8 a0)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, a0 * 15, 0, 15, 17, 0);
    CopyBgTilemapBufferToVram(1);
    sub_8079E44(a0);
    sub_8079BE0(a0);
    sub_8079EA8(a0);
    sub_807A308(gUnknown_0832DE94[1], (void *)(OBJ_VRAM0 + (gUnknown_0203229C->unk_72 * 32)), 24);
    gUnknown_0203229C->unk_74[a0] = 0;
}

void sub_807A000(void)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

void sub_807A024(void)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

void sub_807A048(u16 a0, u8 a1)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (!gUnknown_0203229C->unk_8D0[i].unk_0)
        {
            gUnknown_0203229C->unk_8D0[i].unk_2 = a0;
            gUnknown_0203229C->unk_8D0[i].unk_4 = a1;
            gUnknown_0203229C->unk_8D0[i].unk_0 = TRUE;
            break;
        }
    }
}

u32 sub_807A09C(void)
{
    u32 acc = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        acc += gUnknown_0203229C->unk_8D0[i].unk_0;
    }

    return acc;
}

void sub_807A0C4(void)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (gUnknown_0203229C->unk_8D0[i].unk_0)
        {
            if (gUnknown_0203229C->unk_8D0[i].unk_2)
            {
                gUnknown_0203229C->unk_8D0[i].unk_2--;
            }
            else
            {
                switch (gUnknown_0203229C->unk_8D0[i].unk_4)
                {
                    case 0:
                        sub_8077170(gUnknown_0203229C->unk_80, 20);
                        break;
                    case 1:
                        sub_807A19C(0);
                        break;
                    case 2:
                        sub_807A19C(2);
                        break;
                    case 3:
                    case 4:
                    case 5:
                        sub_807A19C(3);
                        break;
                    case 6:
                        sub_807A19C(6);
                        break;
                    case 7:
                        sub_807A19C(7);
                        break;
                    case 8:
                        sub_807A19C(8);
                        break;
                }
                gUnknown_0203229C->unk_8D0[i].unk_0 = 0;
            }
        }
    }
}

void sub_807A19C(u8 a0)
{
    FillWindowPixelBuffer(0, 0x11);
    AddTextPrinterParameterized(0, 1, gUnknown_0832DEBC[a0], 0, 1, TEXT_SPEED_FF, NULL);
    sub_8098858(0, 20, 12);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

bool8 sub_807A1F0(void)
{
    struct SpriteSheet sheet;

    if (gUnknown_0203229C->unk_A8 < 14)
    {
        sheet.data = gUnknown_02032188[gUnknown_0203229C->unk_A8];
        sheet.size = 0x100;
        sheet.tag = 200 + gUnknown_0203229C->unk_A8;
    }

    switch (gUnknown_0203229C->unk_A8)
    {
        case 0 ... 7:
            LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 8:
            gUnknown_0203229C->unk_72 = LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 9 ... 13:
            LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 14:
            LoadSpritePalette(&gSpritePalette_TradeScreenText);
            gUnknown_0203229C->unk_A8++;
            break;
        case 15:
            LoadSpritePalette(&gUnknown_0832DC44);
            gUnknown_0203229C->unk_A8++;
            break;
        case 16:
            LoadSpriteSheet(&gUnknown_0832DC3C);
            gUnknown_0203229C->unk_A8++;
            break;
        case 17:
            gUnknown_0203229C->unk_A8 = 0;
            return TRUE;
    }

    return FALSE;
}

void sub_807A308(const u8 *a0, u8 *a1, u8 unused)
{
    sub_80C6D80(a0, a1, 0, 0, 6);
}

void sub_807A320(u8 who)
{
    int i;

    switch (who)
    {
        case 0:
            for (i = 0; i < gUnknown_0203229C->partyCounts[who]; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) == TRUE)
                {
                    gUnknown_0203229C->unk_45[who][i] = 0;
                    gUnknown_0203229C->unk_51[who][i] = 1;
                }
                else if (GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
                {
                    gUnknown_0203229C->unk_45[who][i] = 0;
                    gUnknown_0203229C->unk_51[who][i] = 0;
                }
                else
                {
                    gUnknown_0203229C->unk_45[who][i] = 1;
                    gUnknown_0203229C->unk_51[who][i] = 0;
                }
            }
            break;
        case 1:
            for (i = 0; i < gUnknown_0203229C->partyCounts[who]; i++)
            {
                if (GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG) == TRUE)
                {
                    gUnknown_0203229C->unk_45[who][i] = 0;
                    gUnknown_0203229C->unk_51[who][i] = 1;
                }
                else if (GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
                {
                    gUnknown_0203229C->unk_45[who][i] = 0;
                    gUnknown_0203229C->unk_51[who][i] = 0;
                }
                else
                {
                    gUnknown_0203229C->unk_45[who][i] = 1;
                    gUnknown_0203229C->unk_51[who][i] = 0;
                }
            }
            break;
    }
}

void sub_807A468(u8 who)
{
    u16 i, curHp, maxHp;

    switch (who)
    {
        case 0:
            for (i = 0; i < gUnknown_0203229C->partyCounts[0]; i++)
            {
                curHp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
                gUnknown_0203229C->unk_5D[0][i] = GetHPBarLevel(curHp, maxHp);
            }
            break;
        case 1:
            for (i = 0; i < gUnknown_0203229C->partyCounts[1]; i++)
            {
                curHp = GetMonData(&gEnemyParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gEnemyParty[i], MON_DATA_MAX_HP);
                gUnknown_0203229C->unk_5D[1][i] = GetHPBarLevel(curHp, maxHp);
            }
            break;
    }
}

void sub_807A53C(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < gUnknown_0203229C->partyCounts[i]; j++)
        {
            sub_80D32C8(&gSprites[gUnknown_0203229C->unk_28[i][j]], 4 - gUnknown_0203229C->unk_5D[i][j]);
        }
    }
}

void sub_807A5B0(void)
{
    int i;

    for (i = 0; i < 11; i++)
    {
        if (gSaveBlock1Ptr->giftRibbons[i] == 0 && gUnknown_0203229C->unk_A9[i] != 0)
        {
            if (gUnknown_0203229C->unk_A9[i] < 64)
            {
                gSaveBlock1Ptr->giftRibbons[i] = gUnknown_0203229C->unk_A9[i];
            }
        }
    }
}

u32 sub_807A5F4(struct Pokemon *a0, int a1, int a2)
{
    int i, sum;
    struct LinkPlayer *player;
    u32 species[6];
    u32 species2[6];

    for (i = 0; i < a1; i++)
    {
        species2[i] = GetMonData(&a0[i], MON_DATA_SPECIES2);
        species[i] = GetMonData(&a0[i], MON_DATA_SPECIES);
    }

    if (!IsNationalPokedexEnabled())
    {
        if (species2[a2] == SPECIES_EGG)
        {
            return 3;
        }

        if (!IsSpeciesInHoennDex(species2[a2]))
        {
            return 2;
        }
    }

    player = &gLinkPlayers[GetMultiplayerId() ^ 1];
    if ((player->version & 0xFF) != VERSION_RUBY &&
        (player->version & 0xFF) != VERSION_SAPPHIRE)
    {
        if ((player->name[10] & 0xF) == 0)
        {
            if (species2[a2] == SPECIES_EGG)
            {
                return 5;
            }

            if (!IsSpeciesInHoennDex(species2[a2]))
            {
                return 4;
            }
        }
    }

    if (species[a2] == SPECIES_DEOXYS || species[a2] == SPECIES_MEW)
    {
        if (!GetMonData(&a0[a2], MON_DATA_OBEDIENCE))
        {
            return 4;
        }
    }

    for (i = 0; i < a1; i++)
    {
        if (species2[i] == SPECIES_EGG)
        {
            species2[i] = SPECIES_NONE;
        }
    }

    for (sum = 0, i = 0; i < a1; i++)
    {
        if (i != a2)
        {
            sum += species2[i];
        }
    }

    if (sum != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

#ifdef NONMATCHING
s32 sub_807A728(void)
{
    s32 val;
    u16 version;

    if (gReceivedRemoteLinkPlayers != 0)
    {
        val = 0;
        version = (gLinkPlayers[GetMultiplayerId() ^ 1].version & 0xFF);

        if (version == VERSION_RUBY || version == VERSION_SAPPHIRE || version == VERSION_EMERALD)
        {
            // this value could actually be anything 0 or less
            val = 0;
        }
        else if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
        {
            val = 2;
        }

        if (val > 0)
        {
            if (gLinkPlayers[GetMultiplayerId()].name[10] & 0xF0)
            {
                if (val == 2)
                {
                    if (gLinkPlayers[GetMultiplayerId() ^ 1].name[10] & 0xF0)
                    {
                        return 0;
                    }
                    else
                    {
                        return 2;
                    }
                }
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}
#else
NAKED
s32 sub_807A728(void)
{
    asm_unified("push {r4-r7,lr}\n\
    ldr r0, =gReceivedRemoteLinkPlayers\n\
    ldrb r0, [r0]\n\
    cmp r0, 0\n\
    beq _0807A7B4\n\
    movs r4, 0\n\
    bl GetMultiplayerId\n\
    ldr r5, =gLinkPlayers\n\
    movs r7, 0x1\n\
    eors r0, r7\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    lsls r1, r0, 3\n\
    subs r1, r0\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r1, [r1]\n\
    subs r0, r1, 0x1\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, 0x2\n\
    bls _0807A7B4\n\
    subs r0, r1, 0x4\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, 0x1\n\
    bhi _0807A762\n\
    movs r4, 0x2\n\
_0807A762:\n\
    cmp r4, 0\n\
    ble _0807A7B4\n\
    bl GetMultiplayerId\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    lsls r1, r0, 3\n\
    subs r1, r0\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r1, [r1, 0x12]\n\
    movs r6, 0xF0\n\
    adds r0, r6, 0\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0807A7B0\n\
    cmp r4, 0x2\n\
    bne _0807A7B4\n\
    bl GetMultiplayerId\n\
    eors r0, r7\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    lsls r1, r0, 3\n\
    subs r1, r0\n\
    lsls r1, 2\n\
    adds r1, r5\n\
    ldrb r1, [r1, 0x12]\n\
    adds r0, r6, 0\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0807A7B4\n\
    movs r0, 0x2\n\
    b _0807A7B6\n\
    .pool\n\
_0807A7B0:\n\
    movs r0, 0x1\n\
    b _0807A7B6\n\
_0807A7B4:\n\
    movs r0, 0\n\
_0807A7B6:\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1");
}
#endif // NONMATCHING

bool32 sub_807A7BC(u16 a0, u8 a1)
{
    if (a0 == SPECIES_DEOXYS || a0 == SPECIES_MEW)
    {
        if (!a1)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int sub_807A7E0(struct UnkLinkRfuStruct_02022B14Substruct a0, struct UnkLinkRfuStruct_02022B14Substruct a1, u16 a2, u16 a3, u8 a4, u16 a5, u8 a6)
{
    u8 r9 = a0.unk_01_0;
    u8 r2 = a0.unk_00_7;
    u8 r10 = a1.unk_01_0;
    u8 r0 = a1.unk_00_7;
    u8 r1 = a1.unk_01_2;

    if (r1 != 3)
    {
        if (!r2)
        {
            return 8;
        }
        else if (!r0)
        {
            return 9;
        }
    }

    if (sub_807A7BC(a5, a6))
    {
        return 4;
    }

    if (a3 == SPECIES_EGG)
    {
        if (a2 != a3)
        {
            return 2;
        }
    }
    else
    {
        if (gBaseStats[a2].type1 != a4 && gBaseStats[a2].type2 != a4)
        {
            return 1;
        }
    }

    if (a2 == SPECIES_EGG && a2 != a3)
    {
        return 3;
    }

    if (!r9)
    {
        if (a2 == SPECIES_EGG)
        {
            return 6;
        }
        
        if (!IsSpeciesInHoennDex(a2))
        {
            return 4;
        }

        if (!IsSpeciesInHoennDex(a3))
        {
            return 5;
        }
    }

    if (!r10 && !IsSpeciesInHoennDex(a2))
    {
        return 7;
    }

    return 0;
}

int sub_807A8D0(struct UnkLinkRfuStruct_02022B14Substruct a0, u16 a1, u16 a2, u8 a3)
{
    u8 unk = a0.unk_01_0;

    if (sub_807A7BC(a2, a3))
    {
        return 1;
    }

    if (unk)
    {
        return 0;
    }

    if (a1 == SPECIES_EGG)
    {
        return 2;
    }

    if (IsSpeciesInHoennDex(a1))
    {
        return 0;
    }

    return 1;
}

// r6/r7 flip. Ugh.
#ifdef NONMATCHING
int sub_807A918(struct Pokemon *a0, u16 a1)
{
    int i, version, versions, unk, unk2;
    int arr[PARTY_SIZE];

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        arr[i] = GetMonData(&a0[i], MON_DATA_SPECIES2);
        if (arr[i] == SPECIES_EGG)
        {
            arr[i] = 0;
        }
    }

    versions = 0;
    unk = 1;
    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        version = gLinkPlayers[i].version & 0xFF;
        if (version == VERSION_FIRE_RED ||
            version == VERSION_LEAF_GREEN)
        {   
            versions = 0;
        }
        else
        {
            versions |= 1;
        }
    }

    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        struct LinkPlayer *player = &gLinkPlayers[i];
        if ((player->name[8] & 0xF) == 0)
        {
            unk = 0;
        }
        
        if (versions && (player->name[8] / 16))
        {
            unk = 0;
        }
    }

    if (unk == 0)
    {
        if (!IsSpeciesInHoennDex(arr[a1]))
        {
            return 2;
        }
        
        if (arr[a1] == SPECIES_NONE)
        {
            return 3;
        }
    }

    unk2 = 0;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (a1 != i)
        {
            unk2 += arr[i];
        }
    }

    if (!unk2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#else
NAKED
int sub_807A918(struct Pokemon *a0, u16 a1)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, 0x18\n\
	adds r6, r0, 0\n\
	lsls r1, 16\n\
	lsrs r1, 16\n\
	mov r8, r1\n\
	movs r5, 0\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	bge _0807A95A\n\
	mov r4, sp\n\
_0807A934:\n\
	movs r0, 0x64\n\
	muls r0, r5\n\
	adds r0, r6, r0\n\
	movs r1, 0x41\n\
	bl GetMonData\n\
	str r0, [r4]\n\
	movs r1, 0xCE\n\
	lsls r1, 1\n\
	cmp r0, r1\n\
	bne _0807A94E\n\
	movs r0, 0\n\
	str r0, [r4]\n\
_0807A94E:\n\
	adds r4, 0x4\n\
	adds r5, 0x1\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	blt _0807A934\n\
_0807A95A:\n\
	movs r7, 0\n\
	movs r6, 0x1\n\
	movs r5, 0\n\
	ldr r4, =gLinkPlayers\n\
	b _0807A980\n\
	.pool\n\
_0807A96C:\n\
	ldrb r0, [r4]\n\
	subs r0, 0x4\n\
	cmp r0, 0x1\n\
	bhi _0807A978\n\
	movs r7, 0\n\
	b _0807A97C\n\
_0807A978:\n\
	movs r0, 0x1\n\
	orrs r7, r0\n\
_0807A97C:\n\
	adds r4, 0x1C\n\
	adds r5, 0x1\n\
_0807A980:\n\
	bl GetLinkPlayerCount\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r5, r0\n\
	blt _0807A96C\n\
	movs r5, 0\n\
	movs r4, 0\n\
	b _0807A9B4\n\
_0807A992:\n\
	ldr r0, =gLinkPlayers\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2, 0x10]\n\
	movs r0, 0xF\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _0807A9A2\n\
	movs r6, 0\n\
_0807A9A2:\n\
	cmp r7, 0\n\
	beq _0807A9B0\n\
	ldrb r0, [r2, 0x10]\n\
	lsrs r0, 4\n\
	cmp r0, 0\n\
	beq _0807A9B0\n\
	movs r6, 0\n\
_0807A9B0:\n\
	adds r4, 0x1C\n\
	adds r5, 0x1\n\
_0807A9B4:\n\
	bl GetLinkPlayerCount\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r5, r0\n\
	blt _0807A992\n\
	cmp r6, 0\n\
	bne _0807A9EA\n\
	mov r1, r8\n\
	lsls r0, r1, 2\n\
	mov r1, sp\n\
	adds r4, r1, r0\n\
	ldrh r0, [r4]\n\
	bl IsSpeciesInHoennDex\n\
	cmp r0, 0\n\
	bne _0807A9E0\n\
	movs r0, 0x2\n\
	b _0807AA1A\n\
	.pool\n\
_0807A9E0:\n\
	ldr r0, [r4]\n\
	cmp r0, 0\n\
	bne _0807A9EA\n\
	movs r0, 0x3\n\
	b _0807AA1A\n\
_0807A9EA:\n\
	movs r2, 0\n\
	movs r5, 0\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	bge _0807AA0A\n\
	adds r3, r0, 0\n\
	mov r1, sp\n\
_0807A9FA:\n\
	cmp r8, r5\n\
	beq _0807AA02\n\
	ldr r0, [r1]\n\
	adds r2, r0\n\
_0807AA02:\n\
	adds r1, 0x4\n\
	adds r5, 0x1\n\
	cmp r5, r3\n\
	blt _0807A9FA\n\
_0807AA0A:\n\
	cmp r2, 0\n\
	beq _0807AA18\n\
	movs r0, 0\n\
	b _0807AA1A\n\
	.pool\n\
_0807AA18:\n\
	movs r0, 0x1\n\
_0807AA1A:\n\
	add sp, 0x18\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1");
}
#endif // NONMATCHING

void sub_807AA28(struct Sprite *sprite)
{
    if (++sprite->data[0] == 10)
    {
        PlaySE(SE_BOWA);
        sprite->data[0] = 0;
    }
}

void sub_807AA4C(struct Sprite *sprite)
{
    if (!sprite->invisible && ++sprite->data[0] == 10)
    {
        PlaySE(SE_W207B);
        sprite->data[0] = 0;
    }
}

void sub_807AA7C(struct Sprite *sprite)
{
    if (!sprite->data[1])
    {
        if (++sprite->data[0] == 12)
        {
            sprite->data[0] = 0;
        }

        LoadPalette(&gUnknown_08338EA4[sprite->data[0]], (sprite->oam.paletteNum + 16) * 16 + 4, 2);
    }
}

void sub_807AABC(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->pos2.y++;

    if (sprite->data[0] == 10)
    {
        DestroySprite(sprite);
    }
}

void sub_807AAE0(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->pos2.y--;

    if (sprite->data[0] == 10)
    {
        DestroySprite(sprite);
    }
}

void sub_807AB04(struct Sprite *sprite)
{
    if (++sprite->data[0] == 15)
    {
        PlaySE(SE_W107);
        sprite->data[0] = 0;
    }
}

void sub_807AB28(void)
{
    struct BgAffineDstData affine;

    DoBgAffineSet(&affine, gUnknown_020322A0->unk_D4 * 0x100, gUnknown_020322A0->unk_D6 * 0x100, gUnknown_020322A0->unk_DC, gUnknown_020322A0->unk_DE, gUnknown_020322A0->unk_E8, gUnknown_020322A0->unk_E8, gUnknown_020322A0->unk_EC);
    SetGpuReg(REG_OFFSET_BG2PA, affine.pa);
    SetGpuReg(REG_OFFSET_BG2PB, affine.pb);
    SetGpuReg(REG_OFFSET_BG2PC, affine.pc);
    SetGpuReg(REG_OFFSET_BG2PD, affine.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, affine.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, affine.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, affine.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, affine.dy >> 16);
}

void sub_807ABCC(void)
{
    u16 dispcnt;

    SetGpuReg(REG_OFFSET_BG1VOFS, gUnknown_020322A0->bg1vofs);
    SetGpuReg(REG_OFFSET_BG1HOFS, gUnknown_020322A0->bg1hofs);

    dispcnt = GetGpuReg(REG_OFFSET_DISPCNT);
    if (!(dispcnt & (DISPCNT_MODE_1 | DISPCNT_MODE_2 | DISPCNT_MODE_3 | DISPCNT_MODE_4 | DISPCNT_MODE_5)))
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_020322A0->bg2vofs);
        SetGpuReg(REG_OFFSET_BG2HOFS, gUnknown_020322A0->bg2hofs);
    }
    else
    {
        sub_807AB28();
    }
}

void sub_807AC24(void)
{
    sub_807ABCC();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_807AC3C(void)
{
    gUnknown_020322A0->unk_8A = 0;
    gUnknown_020322A0->unk_88 = 0;
    gUnknown_020322A0->unk_89 = 0;
}

void sub_807AC64(void)
{
    if (gUnknown_020322A0->unk_88 == gUnknown_020322A0->unk_89)
    {
        gUnknown_020322A0->unk_8A++;
    }
    else
    {
        gUnknown_020322A0->unk_8A = 0;
    }

    if (gUnknown_020322A0->unk_8A > 300)
    {
        CloseLink();
        SetMainCallback2(CB2_LinkError);
        gUnknown_020322A0->unk_8A = 0;
        gUnknown_020322A0->unk_89 = 0;
        gUnknown_020322A0->unk_88 = 0;
    }

    gUnknown_020322A0->unk_89 = gUnknown_020322A0->unk_88;
}

u32 sub_807ACDC(void)
{
    if (gReceivedRemoteLinkPlayers != 0)
    {
        return GetMultiplayerId();
    }

    return 0;
}

void sub_807ACFC(u8 a0, u8 a1)
{
    int unk = 0;
    struct Pokemon *mon = NULL;
    u16 species;
    u32 personality;

    if (a0 == 0)
    {
        mon = &gPlayerParty[gUnknown_02032298[0]];
        unk = 1;
    }

    if (a0 == 1)
    {
        mon = &gEnemyParty[gUnknown_02032298[1] % PARTY_SIZE];
        unk = 3;
    }

    switch (a1)
    {
        case 0:
            species = GetMonData(mon, MON_DATA_SPECIES2);
            personality = GetMonData(mon, MON_DATA_PERSONALITY);

            if (a0 == 0)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[1], species, personality);
            }
            else
            {
                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[a0 * 2 + 1], species, personality);
            }

            LoadCompressedSpritePalette(GetMonSpritePalStruct(mon));
            gUnknown_020322A0->tradeSpecies[a0] = species;
            gUnknown_020322A0->unk_68[a0] = personality;
            break;
        case 1:
            SetMultiuseSpriteTemplateToPokemon(GetMonSpritePalStruct(mon)->tag, unk);
            gUnknown_020322A0->pokePicSpriteIdxs[a0] = CreateSprite(&gMultiuseSpriteTemplate, 120, 60, 6);
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[a0]].invisible = TRUE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[a0]].callback = SpriteCallbackDummy;
            break;
    }
}

void sub_807AE50(void)
{
    switch (gMain.state)
    {
        case 0:
            if (gReceivedRemoteLinkPlayers == 0)
            {
                gLinkType = 0x1144;
                CloseLink();
            }
            gUnknown_020322A0 = AllocZeroed(sizeof(*gUnknown_020322A0));
            AllocateMonSpritesGfx();
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(sub_807AC24);
            sub_807B170();
            sub_807AC3C();
            gMain.state++;
            gUnknown_020322A0->unk_8C = 0;
            gUnknown_020322A0->unk_94 = 0;
            gUnknown_020322A0->isLinkTrade = TRUE;
            gUnknown_020322A0->unk_D4 = 64;
            gUnknown_020322A0->unk_D6 = 64;
            gUnknown_020322A0->unk_D8 = 0;
            gUnknown_020322A0->unk_DA = 0;
            gUnknown_020322A0->unk_DC = 120;
            gUnknown_020322A0->unk_DE = 80;
            gUnknown_020322A0->unk_E8 = 256;
            gUnknown_020322A0->unk_EC = 0;
            break;
        case 1:
            if (gReceivedRemoteLinkPlayers == 0)
            {
                gUnknown_020322A0->unk_FA = 1;
                OpenLink();
                gMain.state++;
                gUnknown_020322A0->unk_64 = 0;
            }
            else
            {
                gMain.state = 4;
            }
            break;
        case 2:
            if (++gUnknown_020322A0->unk_64 > 60)
            {
                gUnknown_020322A0->unk_64 = 0;
                gMain.state++;
            }
            break;
        case 3:
            if (IsLinkMaster())
            {
                if (GetLinkPlayerCount_2() >= sub_800AA48())
                {
                    if (++gUnknown_020322A0->unk_64 > 30)
                    {
                        sub_800A620();
                        gMain.state++;
                    }
                }
                else
                {
                    sub_807AC64();
                }
            }
            else
            {
                gMain.state++;
            }
            break;
        case 4:
            sub_807AC64();
            if (gReceivedRemoteLinkPlayers == 1 && IsLinkPlayerDataExchangeComplete() == TRUE)
            {
                gMain.state++;
            }
            break;
        case 5:
            gUnknown_020322A0->unk_72 = 0;
            gUnknown_020322A0->unk_73 = 0;
            gUnknown_020322A0->unk_93 = 0;
            sub_807ACFC(0, 0);
            gMain.state++;
            break;
        case 6:
            sub_807ACFC(0, 1);
            gMain.state++;
            break;
        case 7:
            sub_807ACFC(1, 0);
            gMain.state++;
            break;
        case 8:
            sub_807ACFC(1, 1);
            sub_807B154();
            gMain.state++;
            break;
        case 9:
            sub_807BA94();
            LoadSpriteSheet(&gUnknown_08338D18);
            LoadSpritePalette(&gUnknown_08338D20);
            gMain.state++;
            break;
        case 10:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            ShowBg(0);
            gMain.state++;
            break;
        case 11:
            sub_807B140();
            sub_807BAD8();
            gMain.state++;
            break;
        case 12:
            if (!gPaletteFade.active)
            {
                if (gWirelessCommType)
                {
                    sub_800E0E8();
                    CreateWirelessStatusIndicatorSprite(0, 0);
                }
                SetMainCallback2(sub_807EA2C);
            }
            break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807B140(void)
{
    sub_807B62C(5);
    sub_807B62C(0);
}

void sub_807B154(void)
{
    FillWindowPixelBuffer(0, 0xFF);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

void sub_807B170(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_08339014, ARRAY_COUNT(gUnknown_08339014));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    SetBgTilemapBuffer(0, Alloc(0x800));
    SetBgTilemapBuffer(1, Alloc(0x800));
    SetBgTilemapBuffer(3, Alloc(0x800));
    DeactivateAllTextPrinters();
    DecompressAndLoadBgGfxUsingHeap(0, gBattleTextboxTiles, 0, 0, 0);
    LZDecompressWram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, 0x800, 0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x20);
    InitWindows(gUnknown_08338FFC);
    DecompressAndLoadBgGfxUsingHeap(0, gBattleTextboxTiles, 0, 0, 0);
    LZDecompressWram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, 0x800, 0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x20);
}

// In-game trade init
void sub_807B270(void)
{
    u8 name[11];

    switch (gMain.state)
    {
        case 0:
            gUnknown_02032298[0] = gSpecialVar_0x8005;
            gUnknown_02032298[1] = 6;
            StringCopy(gLinkPlayers[0].name, gSaveBlock2Ptr->playerName);
            GetMonData(&gEnemyParty[0], MON_DATA_OT_NAME, name);
            StringCopy(gLinkPlayers[1].name, name);
            gLinkPlayers[0].language = LANGUAGE_ENGLISH;
            gLinkPlayers[1].language = GetMonData(&gEnemyParty[0], MON_DATA_LANGUAGE);
            gUnknown_020322A0 = AllocZeroed(sizeof(*gUnknown_020322A0));
            AllocateMonSpritesGfx();
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(sub_807AC24);
            sub_807B170();
            gUnknown_020322A0->isLinkTrade = FALSE;
            gUnknown_020322A0->unk_8C = 0;
            gUnknown_020322A0->unk_94 = 0;
            gUnknown_020322A0->unk_D4 = 64;
            gUnknown_020322A0->unk_D6 = 64;
            gUnknown_020322A0->unk_D8 = 0;
            gUnknown_020322A0->unk_DA = 0;
            gUnknown_020322A0->unk_DC = 120;
            gUnknown_020322A0->unk_DE = 80;
            gUnknown_020322A0->unk_E8 = 256;
            gUnknown_020322A0->unk_EC = 0;
            gUnknown_020322A0->unk_64 = 0;
            gMain.state = 5;
            break;
        case 5:
            sub_807ACFC(0, 0);
            gMain.state++;
            break;
        case 6:
            sub_807ACFC(0, 1);
            gMain.state++;
            break;
        case 7:
            sub_807ACFC(1, 0);
            ShowBg(0);
            gMain.state++;
            break;
        case 8:
            sub_807ACFC(1, 1);
            FillWindowPixelBuffer(0, 0xFF);
            PutWindowTilemap(0);
            CopyWindowToVram(0, 3);
            gMain.state++;
            break;
        case 9:
            sub_807BA94();
            LoadSpriteSheet(&gUnknown_08338D18);
            LoadSpritePalette(&gUnknown_08338D20);
            gMain.state++;
            break;
        case 10:
            ShowBg(0);
            gMain.state++;
            break;
        case 11:
            sub_807B62C(5);
            sub_807B62C(0);
            sub_807BAD8();
            gMain.state++;
            break;
        case 12:
            SetMainCallback2(sub_807B60C);
            break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807B464(u8 a0)
{
    struct Pokemon *mon = &gPlayerParty[a0];

    if (!GetMonData(mon, MON_DATA_IS_EGG))
    {
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
        species = SpeciesToNationalPokedexNum(species);
        GetSetPokedexFlag(species, FLAG_SET_SEEN);
        HandleSetPokedexFlag(species, FLAG_SET_CAUGHT, personality);
    }
}

void sub_807B4C4(void)
{
    u8 mpId = GetMultiplayerId();
    // Originally in Ruby but commented out
    /*if (gLinkPlayers[mpId ^ 1].lp_field_2 == 0x8000)
        EnableNationalPokedex();*/
}

void sub_807B4D0(u8 a0, u8 a1)
{
    u8 friendship;
    u16 mailId1;
    u16 mailId2;
    struct Pokemon *mon1 = &gPlayerParty[a0];
    struct Pokemon *mon2;

    mailId1 = GetMonData(mon1, MON_DATA_MAIL);
    mon2 = &gEnemyParty[a1];
    mailId2 = GetMonData(mon2, MON_DATA_MAIL);

    if (mailId1 != 0xFF)
    {
        ClearMailStruct(&gSaveBlock1Ptr->mail[mailId1]);
    }

    gUnknown_020322A0->mon = *mon1;
    *mon1 = *mon2;
    *mon2 = gUnknown_020322A0->mon;

    friendship = 70;
    if (!GetMonData(mon1, MON_DATA_IS_EGG))
    {
        SetMonData(mon1, MON_DATA_FRIENDSHIP, &friendship);
    }

    if (mailId2 != 0xFF)
    {
        GiveMailToMon2(mon1, &gUnknown_020321C0[mailId2]);
    }

    sub_807B464(a0);

    if (gReceivedRemoteLinkPlayers != 0)
    {
        sub_807B4C4();
    }
}

void sub_807B5B8(void)
{
    switch (gUnknown_020322A0->unk_93)
    {
        case 1:
            if (sub_800A520())
            {
                Trade_SendData(gUnknown_020322A0);
                gUnknown_020322A0->unk_93++;
            }
        case 2:
            gUnknown_020322A0->unk_93 = 0;
            break;
    }
}

void sub_807B60C(void)
{
    sub_807BBC8();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807B62C(u8 a0)
{
    switch (a0)
    {
        case 0:
            gUnknown_020322A0->bg2vofs = 0;
            gUnknown_020322A0->bg2hofs = 180;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT512x256);
            LoadPalette(gTradeGba2_Pal, 16, 0x60);
            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
            DmaCopy16Defvars(3, gUnknown_08331F60, (void *) BG_SCREEN_ADDR(18), 0x1000);
            break;
        case 1:
            gUnknown_020322A0->bg1hofs = 0;
            gUnknown_020322A0->bg1vofs = 348;
            SetGpuReg(REG_OFFSET_BG1VOFS, 348);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(0) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(5) |
                                         BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT256x512);
    
            if (gUnknown_020322A0->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083369A0, (void *) BG_SCREEN_ADDR(5), 0x1000);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083359A0, (void *) BG_SCREEN_ADDR(5), 0x1000);
            }

            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(0), 0x1420, 0x1000);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 2:
            gUnknown_020322A0->bg1vofs = 0;
            gUnknown_020322A0->bg1hofs = 0;
            if (!gUnknown_020322A0->unk_FA)
            {
                SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                              DISPCNT_OBJ_1D_MAP |
                                              DISPCNT_BG1_ON |
                                              DISPCNT_OBJ_ON);
                LZ77UnCompVram(gUnknown_083379A0, (void *) BG_SCREEN_ADDR(5));
                BlendPalettes(0x8, 16, RGB_BLACK);
            }
            else
            {
                SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                              DISPCNT_OBJ_1D_MAP |
                                              DISPCNT_BG1_ON |
                                              DISPCNT_OBJ_ON);
                DmaCopy16Defvars(3, gUnknown_0832FFC0, (void *) BG_SCREEN_ADDR(5), 0x800);
                BlendPalettes(0x1, 16, RGB_BLACK);
            }
            break;
        case 3:
            LoadPalette(gUnknown_08337EA0, 48, 0x20);
            LZ77UnCompVram(gUnknown_08337EC0, (void *) BG_CHAR_ADDR(1));
            LZ77UnCompVram(gUnknown_08338550, (void *) BG_SCREEN_ADDR(18));
            gUnknown_020322A0->bg2vofs = 80;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 4:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_256COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_AFF128x128);
            gUnknown_020322A0->unk_D4 = 64;
            gUnknown_020322A0->unk_D6 = 92;
            gUnknown_020322A0->unk_E8 = 32;
            gUnknown_020322A0->unk_EA = 1024;
            gUnknown_020322A0->unk_EC = 0;

            DmaCopyLarge16(3, gUnknown_08332F60, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);
            
            if (gUnknown_020322A0->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083357A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083358A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            break;
        case 5:
            gUnknown_020322A0->bg1vofs = 0;
            gUnknown_020322A0->bg1hofs = 0;
            break;
        case 6:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_256COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_AFF128x128);
            gUnknown_020322A0->unk_D4 = 64;
            gUnknown_020322A0->unk_D6 = 92;
            gUnknown_020322A0->unk_E8 = 256;
            gUnknown_020322A0->unk_EA = 128;
            gUnknown_020322A0->unk_DC = 120;
            gUnknown_020322A0->unk_DE = 80;
            gUnknown_020322A0->unk_EC = 0;

            DmaCopyLarge16(3, gUnknown_08332F60, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);
            
            if (gUnknown_020322A0->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083357A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083358A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            break;
        case 7:
            gUnknown_020322A0->bg2vofs = 0;
            gUnknown_020322A0->bg2hofs = 0;
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT512x256);
            LoadPalette(gTradeGba2_Pal, 16, 0x60);
            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
            DmaCopy16Defvars(3, gUnknown_08331F60, (void *) BG_SCREEN_ADDR(18), 0x1000);
            break;
    }
}

void sub_807BA94(void)
{
    LoadSpriteSheet(&gUnknown_08338D70);
    LoadSpriteSheet(&gUnknown_08338DC0);
    LoadSpriteSheet(&gUnknown_08338DF4);
    LoadSpriteSheet(&gUnknown_08338E6C);
    LoadSpritePalette(&gUnknown_08338D78);
    LoadSpritePalette(&gUnknown_08338D80);
}

void sub_807BAD8(void)
{
    /*Sets the variable strings printed on the
     *actual trading screen. For use in strings
     *like "[Pokemon] will be sent to [Trainer]."
     */
    u8 mpId;
    u8 name[20];
    const struct InGameTrade *ingameTrade;

    if (gUnknown_020322A0->isLinkTrade)
    {
        mpId = GetMultiplayerId();
        StringCopy(gStringVar1, gLinkPlayers[mpId ^ 1].name);
        GetMonData(&gEnemyParty[gUnknown_02032298[1] % PARTY_SIZE], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar3, name);
        GetMonData(&gPlayerParty[gUnknown_02032298[0]], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
    else
    {
        ingameTrade = &gIngameTrades[gSpecialVar_0x8004];
        StringCopy(gStringVar1, ingameTrade->otName);
        StringCopy10(gStringVar3, ingameTrade->name);
        GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
}

u8 sub_807BBC8(void)
{
    if (gUnknown_020322A0->unk_FA)
    {
        return sub_807BBEC();
    }
    else
    {
        return sub_807CFC8();
    }
}

bool8 sub_807BBEC(void)
{
    u16 evoTarget;

    switch (gUnknown_020322A0->unk_94)
    {
        case 0:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x = -180;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y = gMonFrontPicCoords[gUnknown_020322A0->tradeSpecies[0]].y_offset;
            gUnknown_020322A0->unk_94++;
            gUnknown_020322A0->unk_F4 = GetCurrentMapMusic();
            PlayNewMapMusic(MUS_SHINKA);
            break;
        case 1:
            if (gUnknown_020322A0->bg2hofs > 0)
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x += 3;
                gUnknown_020322A0->bg2hofs -= 3;
            }
            else
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x = 0;
                gUnknown_020322A0->bg2hofs = 0;
                gUnknown_020322A0->unk_94 = 10;
            }
            break;
        case 10:
            StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
            sub_807F1A8(0, gStringVar4, 0);

            if (gUnknown_020322A0->tradeSpecies[0] != SPECIES_EGG)
            {
                PlayCry1(gUnknown_020322A0->tradeSpecies[0], 0);
            }

            gUnknown_020322A0->unk_94 = 11;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 11:
            if (++gUnknown_020322A0->unk_64 == 80)
            {
                gUnknown_020322A0->unk_D2 = sub_807671C(gUnknown_020322A0->pokePicSpriteIdxs[0], gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
                gUnknown_020322A0->unk_94++;
                StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
                sub_807F1A8(0, gStringVar4, 0);
            }
            break;
        case 12:
            if (gSprites[gUnknown_020322A0->unk_D2].callback == SpriteCallbackDummy)
            {
                gUnknown_020322A0->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, 32, 0);
                gSprites[gUnknown_020322A0->unk_D3].callback = sub_807E5D8;
                DestroySprite(&gSprites[gUnknown_020322A0->unk_D2]);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 13:
            // The game waits here for the sprite to finish its animation sequence.
            break;
        case 14:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->unk_94 = 20;
            break;
        case 20:
            if (!gPaletteFade.active)
            {
                sub_807B62C(4);
                FillWindowPixelBuffer(0, 0xFF);
                CopyWindowToVram(0, 3);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 21:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_94++;
            break;
        case 22:
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->unk_94 = 23;
            }
            break;
        case 23:
            if (gUnknown_020322A0->unk_EA > 0x100)
            {
                gUnknown_020322A0->unk_EA -= 0x34;
            }
            else
            {
                sub_807B62C(1);
                gUnknown_020322A0->unk_EA = 0x80;
                gUnknown_020322A0->unk_94++;
                gUnknown_020322A0->unk_64 = 0;
            }
            gUnknown_020322A0->unk_E8 = 0x8000 / gUnknown_020322A0->unk_EA;
            break;
        case 24:
            if (++gUnknown_020322A0->unk_64 > 20)
            {
                sub_807AB28();
                gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 25:
            if (gSprites[gUnknown_020322A0->unk_91].animEnded)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND |
                                             BLDCNT_TGT2_BG1 |
                                             BLDCNT_TGT2_BG2);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 4));
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 26:
            if (--gUnknown_020322A0->bg1vofs == 316)
            {
                gUnknown_020322A0->unk_94++;
            }
            if (gUnknown_020322A0->bg1vofs == 328)
            {
                gUnknown_020322A0->unk_92 = CreateSprite(&gSpriteTemplate_8338DFC, 128, 65, 0);
            }
            break;
        case 27:
            gUnknown_020322A0->unk_90 = CreateSprite(&gUnknown_08338D88, 128, 80, 3);
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 128, 80, 0);
            StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_91], 1);
            gUnknown_020322A0->unk_94++;
            break;
        case 28:
            if ((gUnknown_020322A0->bg1vofs -= 2) == 166)
            {
                gUnknown_020322A0->unk_94 = 200;
            }
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 200:
            gSprites[gUnknown_020322A0->unk_90].pos1.y -= 2;
            gSprites[gUnknown_020322A0->unk_91].pos1.y -= 2;
            if (gSprites[gUnknown_020322A0->unk_90].pos1.y < -8)
            {
                gUnknown_020322A0->unk_94 = 29;
            }
            break;
        case 29:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            gUnknown_020322A0->unk_94 = 30;
            break;
        case 30:
            if (!gPaletteFade.active)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                sub_807B62C(2);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 31:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_90 = CreateSprite(&gSpriteTemplate_8338DC8, 111, 170, 0);
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 129, -10, 0);
            gUnknown_020322A0->unk_94++;
            break;
        case 32:
            if (!gPaletteFade.active)
            {
                PlaySE(SE_TK_WARPOUT);
                gUnknown_020322A0->unk_94++;
            }
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            break;
        case 33:
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y <= -90)
            {
                gSprites[gUnknown_020322A0->unk_90].data[1] = 1;
                gSprites[gUnknown_020322A0->unk_91].data[1] = 1;
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 34:
            BlendPalettes(0x1, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            break;
        case 35:
            BlendPalettes(0x1, 0, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            break;
        case 36:
            BlendPalettes(0x1, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            break;
        case 37:
            if (!IsMonSpriteNotFlipped(gUnknown_020322A0->tradeSpecies[0]))
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].affineAnims = gSpriteAffineAnimTable_8338ECC;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].oam.affineMode = 3;
                CalcCenterToCornerVec(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0, 3, 3);
                StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0);
            }
            else
            {
                StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0);
            }
            StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]], 0);
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos1.x = 60;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.x = 180;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos1.y = 192;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.y = -32;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].invisible = FALSE;
            gUnknown_020322A0->unk_94++;
            break;
        case 38:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y -= 3;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y < -160 && gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y >= -163)
            {
                PlaySE(SE_TK_WARPIN);
            }
            if (gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y < -222)
            {
                gSprites[gUnknown_020322A0->unk_90].data[1] = 0;
                gSprites[gUnknown_020322A0->unk_91].data[1] = 0;
                gUnknown_020322A0->unk_94++;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = TRUE;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].invisible = TRUE;
                BlendPalettes(0x1, 0, RGB_WHITEALPHA);
            }
            break;
        case 39:
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y <= -222)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
                gUnknown_020322A0->unk_94++;
                DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
            }
            break;
        case 40:
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->unk_94++;
                sub_807B62C(1);
                gUnknown_020322A0->bg1vofs = 166;
                gUnknown_020322A0->unk_90 = CreateSprite(&gUnknown_08338D88, 128, -20, 3);
                gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 128, -20, 0);
                StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_91], 1);
            }
            break;
        case 41:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_94++;
            break;
        case 42:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 43:
            gSprites[gUnknown_020322A0->unk_90].pos2.y += 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y + gSprites[gUnknown_020322A0->unk_90].pos1.y == 64)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 44:
            if ((gUnknown_020322A0->bg1vofs += 2) > 316)
            {
                gUnknown_020322A0->bg1vofs = 316;
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 45:
            DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
            DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
            gUnknown_020322A0->unk_94++;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 46:
            if (++gUnknown_020322A0->unk_64 == 10)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 47:
            if (++gUnknown_020322A0->bg1vofs > 348)
            {
                gUnknown_020322A0->bg1vofs = 348;
                gUnknown_020322A0->unk_94++;
            }
            if (gUnknown_020322A0->bg1vofs == 328 && gUnknown_020322A0->unk_FA)
            {
                gUnknown_020322A0->unk_92 = CreateSprite(&gSpriteTemplate_8338DFC, 128, 65, 0);
                gSprites[gUnknown_020322A0->unk_92].callback = sub_807AAE0;
            }
            break;
        case 48:
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
            gUnknown_020322A0->unk_94 = 50;
            break;
        case 50:
            if (gSprites[gUnknown_020322A0->unk_91].animEnded)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                sub_807B62C(6);
                gUnknown_020322A0->unk_94++;
                PlaySE(SE_W028);
            }
            break;
        case 51:
            if (gUnknown_020322A0->unk_EA < 0x400)
            {
                gUnknown_020322A0->unk_EA += 0x34;
            }
            else
            {
                gUnknown_020322A0->unk_EA = 0x400;
                gUnknown_020322A0->unk_94++;
            }
            gUnknown_020322A0->unk_E8 = 0x8000 / gUnknown_020322A0->unk_EA;
            break;
        case 52:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->unk_94 = 60;
            break;

        case 60:
            if (!gPaletteFade.active)
            {
                sub_807B62C(5);
                sub_807B62C(7);
                gPaletteFade.bufferTransferDisabled = TRUE;
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 61:
            gPaletteFade.bufferTransferDisabled = FALSE;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_94++;
            break;
        case 62:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 63:
            gUnknown_020322A0->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, -8, 0);
            gSprites[gUnknown_020322A0->unk_D3].data[3] = 74;
            gSprites[gUnknown_020322A0->unk_D3].callback = sub_807E6AC;
            StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_D3], 1);
            StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->unk_D3], 2);
            BlendPalettes(1 << (16 + gSprites[gUnknown_020322A0->unk_D3].oam.paletteNum), 16, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 64:
            BeginNormalPaletteFade(1 << (16 + gSprites[gUnknown_020322A0->unk_D3].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            break;
        case 65:
            if (gSprites[gUnknown_020322A0->unk_D3].callback == SpriteCallbackDummy)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[gUnknown_020322A0->tradeSpecies[1]], gMonSpritesGfxPtr->sprites[3], gUnknown_020322A0->tradeSpecies[1], gUnknown_020322A0->unk_68[1]);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 66:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.x = 120;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.y = gMonFrontPicCoords[gUnknown_020322A0->tradeSpecies[1]].y_offset + 60;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.x = 0;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.y = 0;
            StartSpriteAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]], 0);
            CreatePokeballSpriteToReleaseMon(gUnknown_020322A0->pokePicSpriteIdxs[1], gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, gUnknown_020322A0->tradeSpecies[1]);
            FreeSpriteOamMatrix(&gSprites[gUnknown_020322A0->unk_D3]);
            DestroySprite(&gSprites[gUnknown_020322A0->unk_D3]);
            gUnknown_020322A0->unk_94++;
            break;
        case 67:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
            sub_807F1A8(0, gStringVar4, 0);
            gUnknown_020322A0->unk_94 = 167;
            gUnknown_020322A0->unk_64 = 0;
            break;
        // 167 and 267 are extra cases added in for animations
        case 167:
            if (++gUnknown_020322A0->unk_64 > 60)
            {
                gUnknown_020322A0->unk_94 = 267;
                gUnknown_020322A0->unk_64 = 0;
            }
            break;
        case 267:
            if (IsCryFinished())
            {
                gUnknown_020322A0->unk_94 = 68;
            }
            break;
        case 68:
            if (++gUnknown_020322A0->unk_64 == 10)
            {
                PlayFanfare(MUS_FANFA5);
            }
            if (gUnknown_020322A0->unk_64 == 250)
            {
                gUnknown_020322A0->unk_94++;
                StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
                sub_807F1A8(0, gStringVar4, 0);
                gUnknown_020322A0->unk_64 = 0;
            }
            break;
        case 69:
            if (++gUnknown_020322A0->unk_64 == 60)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 70:
            sub_807F14C();
            gUnknown_020322A0->unk_94++;
            break;
        case 71:
            if (gUnknown_020322A0->isLinkTrade)
            {
                return TRUE;
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 72: // Only if in-game trade
            sub_807B4D0(gSpecialVar_0x8005, 0);
            gCB2_AfterEvolution = sub_807B60C;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gUnknown_02032298[0]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
            {
                TradeEvolutionScene(&gPlayerParty[gUnknown_02032298[0]], evoTarget, gUnknown_020322A0->pokePicSpriteIdxs[1], gUnknown_02032298[0]);
            }
            gUnknown_020322A0->unk_94++;
            break;
        case 73:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->unk_94++;
            break;
        case 74:
            if (!gPaletteFade.active)
            {
                PlayNewMapMusic(gUnknown_020322A0->unk_F4);
                if (gUnknown_020322A0)
                {
                    FreeAllWindowBuffers();
                    Free(GetBgTilemapBuffer(3));
                    Free(GetBgTilemapBuffer(1));
                    Free(GetBgTilemapBuffer(0));
                    FreeMonSpritesGfx();
                    FREE_AND_SET_NULL(gUnknown_020322A0);
                }
                SetMainCallback2(CB2_ReturnToField);
                sub_807E784();
            }
            break;
    }
    return FALSE;
}

bool8 sub_807CFC8(void)
{
    u16 evoTarget;

    switch (gUnknown_020322A0->unk_94)
    {
        case 0:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x = -180;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y = gMonFrontPicCoords[gUnknown_020322A0->tradeSpecies[0]].y_offset;
            gUnknown_020322A0->unk_94++;
            gUnknown_020322A0->unk_F4 = GetCurrentMapMusic();
            PlayNewMapMusic(MUS_SHINKA);
            break;
        case 1:
            if (gUnknown_020322A0->bg2hofs > 0)
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x += 3;
                gUnknown_020322A0->bg2hofs -= 3;
            }
            else
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x = 0;
                gUnknown_020322A0->bg2hofs = 0;
                gUnknown_020322A0->unk_94 = 10;
            }
            break;
        case 10:
            StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
            sub_807F1A8(0, gStringVar4, 0);

            if (gUnknown_020322A0->tradeSpecies[0] != SPECIES_EGG)
            {
                PlayCry1(gUnknown_020322A0->tradeSpecies[0], 0);
            }

            gUnknown_020322A0->unk_94 = 11;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 11:
            if (++gUnknown_020322A0->unk_64 == 80)
            {
                gUnknown_020322A0->unk_D2 = sub_807671C(gUnknown_020322A0->pokePicSpriteIdxs[0], gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
                gUnknown_020322A0->unk_94++;
                StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
                sub_807F1A8(0, gStringVar4, 0);
            }
            break;
        case 12:
            if (gSprites[gUnknown_020322A0->unk_D2].callback == SpriteCallbackDummy)
            {
                gUnknown_020322A0->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, 32, 0);
                gSprites[gUnknown_020322A0->unk_D3].callback = sub_807E5D8;
                DestroySprite(&gSprites[gUnknown_020322A0->unk_D2]);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 13:
            // The game waits here for the sprite to finish its animation sequence.
            break;
        case 14:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->unk_94 = 20;
            break;
        case 20:
            if (!gPaletteFade.active)
            {
                sub_807B62C(4);
                FillWindowPixelBuffer(0, 0xFF);
                CopyWindowToVram(0, 3);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 21:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_94++;
            break;
        case 22:
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->unk_94 = 23;
            }
            break;
        case 23:
            if (gUnknown_020322A0->unk_EA > 0x100)
            {
                gUnknown_020322A0->unk_EA -= 0x34;
            }
            else
            {
                sub_807B62C(1);
                gUnknown_020322A0->unk_EA = 0x80;
                gUnknown_020322A0->unk_94 = 124;
                gUnknown_020322A0->unk_64 = 0;
            }
            gUnknown_020322A0->unk_E8 = 0x8000 / gUnknown_020322A0->unk_EA;
            break;
        case 124:
            if (++gUnknown_020322A0->unk_64 > 20)
            {
                sub_807B62C(3);
                gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338E8C, 120, 80, 0);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 125:
            if (gSprites[gUnknown_020322A0->unk_91].animEnded)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 |
                                             BLDCNT_TGT1_OBJ |
                                             BLDCNT_EFFECT_BLEND |
                                             BLDCNT_TGT2_BG2);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 4));
                CreateTask(c3_08054588, 5);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 126:
            if (!FuncIsActiveTask(c3_08054588))
            {
                gUnknown_020322A0->unk_94 = 26;
            }
            break;
        case 26:
            if (--gUnknown_020322A0->bg1vofs == 316)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 27:
            gUnknown_020322A0->unk_90 = CreateSprite(&gUnknown_08338D88, 120, 80, 3);
            gSprites[gUnknown_020322A0->unk_90].callback = sub_807AA4C;
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 120, 80, 0);
            StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_91], 1);
            gUnknown_020322A0->unk_94++;
            break;
        case 28:
            if ((gUnknown_020322A0->bg1vofs -= 3) == 166)
            {
                gUnknown_020322A0->unk_94 = 200;
            }
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 200:
            gSprites[gUnknown_020322A0->unk_90].pos1.y -= 2;
            gSprites[gUnknown_020322A0->unk_91].pos1.y -= 2;
            if (gSprites[gUnknown_020322A0->unk_90].pos1.y < -8)
            {
                gUnknown_020322A0->unk_94 = 29;
            }
            break;
        case 29:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            gUnknown_020322A0->unk_94 = 30;
            break;
        case 30:
            if (!gPaletteFade.active)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                sub_807B62C(2);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 31:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_90 = CreateSprite(&gSpriteTemplate_8338DC8, 111, 170, 0);
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 129, -10, 0);
            gUnknown_020322A0->unk_94++;
            break;
        case 32:
            if (!gPaletteFade.active)
            {
                PlaySE(SE_TK_WARPOUT);
                gUnknown_020322A0->unk_94++;
            }
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            break;
        case 33:
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y <= -90)
            {
                gSprites[gUnknown_020322A0->unk_90].data[1] = 1;
                gSprites[gUnknown_020322A0->unk_91].data[1] = 1;
                gUnknown_020322A0->unk_94++;
                CreateTask(c3_0805465C, 5);
            }
            break;
        case 34:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            break;
        case 35:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            break;
        case 36:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            break;
        case 37:
            if (!IsMonSpriteNotFlipped(gUnknown_020322A0->tradeSpecies[0]))
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].affineAnims = gSpriteAffineAnimTable_8338ECC;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].oam.affineMode = 3;
                CalcCenterToCornerVec(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0, 3, 3);
                StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0);
            }
            else
            {
                StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0);
            }
            StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]], 0);
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos1.x = 40;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.x = 200;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos1.y = 192;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.y = -32;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].invisible = FALSE;
            gUnknown_020322A0->unk_94++;
            break;
        case 38:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y -= 3;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y < -160 && gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y >= -163)
            {
                PlaySE(SE_TK_WARPIN);
            }
            if (gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y < -222)
            {
                gSprites[gUnknown_020322A0->unk_90].data[1] = 0;
                gSprites[gUnknown_020322A0->unk_91].data[1] = 0;
                gUnknown_020322A0->unk_94++;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = TRUE;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].invisible = TRUE;
                CreateTask(sub_807F39C, 5);
            }
            break;
        case 39:
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y <= -222)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
                gUnknown_020322A0->unk_94++;
                DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
            }
            break;
        case 40:
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->unk_94++;
                sub_807B62C(1);
                gUnknown_020322A0->bg1vofs = 166;
                sub_807B62C(3);
                gUnknown_020322A0->bg2vofs = 412;
                gUnknown_020322A0->unk_90 = CreateSprite(&gUnknown_08338D88, 120, -20, 3);
                gSprites[gUnknown_020322A0->unk_90].callback = sub_807AA4C;
                gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 120, -20, 0);
                StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_91], 1);
            }
            break;
        case 41:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_94++;
            break;
        case 42:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 43:
            gSprites[gUnknown_020322A0->unk_90].pos2.y += 4;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 4;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y + gSprites[gUnknown_020322A0->unk_90].pos1.y == 64)
            {
                gUnknown_020322A0->unk_94 = 144;
                gUnknown_020322A0->unk_64 = 0;
            }
            break;
        case 144:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            gUnknown_020322A0->bg1vofs += 3;
            gUnknown_020322A0->bg2vofs += 3;
            if (++gUnknown_020322A0->unk_64 == 10)
            {
                u8 taskId = CreateTask(c3_08054588, 5);
                gTasks[taskId].data[2] = 1;
            }
            if (gUnknown_020322A0->bg1vofs > 316)
            {
                gUnknown_020322A0->bg1vofs = 316;
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 145:
            DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
            DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
            gUnknown_020322A0->unk_94++;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 146:
            if (!FuncIsActiveTask(c3_08054588))
            {
                gUnknown_020322A0->unk_94 = 46;
                gUnknown_020322A0->unk_64 = 0;
            }
            break;
        case 46:
            if (++gUnknown_020322A0->unk_64 == 10)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 47:
            if (++gUnknown_020322A0->bg1vofs > 348)
            {
                gUnknown_020322A0->bg1vofs = 348;
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 48:
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
            gUnknown_020322A0->unk_94 = 50;
            break;
        case 50:
            if (gSprites[gUnknown_020322A0->unk_91].animEnded)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                sub_807B62C(6);
                gUnknown_020322A0->unk_94++;
                PlaySE(SE_W028);
            }
            break;
        case 51:
            if (gUnknown_020322A0->unk_EA < 0x400)
            {
                gUnknown_020322A0->unk_EA += 0x34;
            }
            else
            {
                gUnknown_020322A0->unk_EA = 0x400;
                gUnknown_020322A0->unk_94++;
            }
            gUnknown_020322A0->unk_E8 = 0x8000 / gUnknown_020322A0->unk_EA;
            break;
        case 52:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->unk_94 = 60;
            break;
        case 60:
            if (!gPaletteFade.active)
            {
                sub_807B62C(5);
                sub_807B62C(7);
                gPaletteFade.bufferTransferDisabled = TRUE;
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 61:
            gPaletteFade.bufferTransferDisabled = FALSE;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_94++;
            break;
        case 62:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 63:
            gUnknown_020322A0->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, -8, 0);
            gSprites[gUnknown_020322A0->unk_D3].data[3] = 74;
            gSprites[gUnknown_020322A0->unk_D3].callback = sub_807E6AC;
            StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_D3], 1);
            StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->unk_D3], 2);
            BlendPalettes(1 << (16 + gSprites[gUnknown_020322A0->unk_D3].oam.paletteNum), 16, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 64:
            BeginNormalPaletteFade(1 << (16 + gSprites[gUnknown_020322A0->unk_D3].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
            gUnknown_020322A0->unk_94++;
            break;
        case 65:
            if (gSprites[gUnknown_020322A0->unk_D3].callback == SpriteCallbackDummy)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[gUnknown_020322A0->tradeSpecies[1]], gMonSpritesGfxPtr->sprites[3], gUnknown_020322A0->tradeSpecies[1], gUnknown_020322A0->unk_68[1]);
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 66:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.x = 120;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.y = gMonFrontPicCoords[gUnknown_020322A0->tradeSpecies[1]].y_offset + 60;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.x = 0;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.y = 0;
            StartSpriteAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]], 0);
            CreatePokeballSpriteToReleaseMon(gUnknown_020322A0->pokePicSpriteIdxs[1], gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, gUnknown_020322A0->tradeSpecies[1]);
            FreeSpriteOamMatrix(&gSprites[gUnknown_020322A0->unk_D3]);
            DestroySprite(&gSprites[gUnknown_020322A0->unk_D3]);
            gUnknown_020322A0->unk_94++;
            break;
        case 67:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
            sub_807F1A8(0, gStringVar4, 0);
            gUnknown_020322A0->unk_94 = 167;
            gUnknown_020322A0->unk_64 = 0;
            break;
        // 167 and 267 are extra cases added in for animations
        case 167:
            if (++gUnknown_020322A0->unk_64 > 60)
            {
                gUnknown_020322A0->unk_94 = 267;
                gUnknown_020322A0->unk_64 = 0;
            }
            break;
        case 267:
            if (IsCryFinished())
            {
                gUnknown_020322A0->unk_94 = 68;
            }
            break;
        case 68:
            if (++gUnknown_020322A0->unk_64 == 10)
            {
                PlayFanfare(MUS_FANFA5);
            }
            if (gUnknown_020322A0->unk_64 == 250)
            {
                gUnknown_020322A0->unk_94++;
                StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
                sub_807F1A8(0, gStringVar4, 0);
                gUnknown_020322A0->unk_64 = 0;
            }
            break;
        case 69:
            if (++gUnknown_020322A0->unk_64 == 60)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 70:
            sub_807F14C();
            gUnknown_020322A0->unk_94++;
            break;
        case 71:
            if (gUnknown_020322A0->isLinkTrade)
            {
                return TRUE;
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                gUnknown_020322A0->unk_94++;
            }
            break;
        case 72: // Only if in-game trade
            sub_807B4D0(gSpecialVar_0x8005, 0);
            gCB2_AfterEvolution = sub_807B60C;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gUnknown_02032298[0]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
            {
                TradeEvolutionScene(&gPlayerParty[gUnknown_02032298[0]], evoTarget, gUnknown_020322A0->pokePicSpriteIdxs[1], gUnknown_02032298[0]);
            }
            gUnknown_020322A0->unk_94++;
            break;
        case 73:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->unk_94++;
            break;
        case 74:
            if (!gPaletteFade.active)
            {
                PlayNewMapMusic(gUnknown_020322A0->unk_F4);
                if (gUnknown_020322A0)
                {
                    FreeAllWindowBuffers();
                    Free(GetBgTilemapBuffer(3));
                    Free(GetBgTilemapBuffer(1));
                    Free(GetBgTilemapBuffer(0));
                    FreeMonSpritesGfx();
                    FREE_AND_SET_NULL(gUnknown_020322A0);
                }
                SetMainCallback2(CB2_ReturnToField);
                sub_807E784();
            }
            break;
    }
    return FALSE;
}

void c2_08053788(void)
{
    u16 evoTarget;
    switch (gMain.state)
    {
        case 0:
            gMain.state = 4;
            gSoftResetDisabled = TRUE;
            break;
        case 4:
            gCB2_AfterEvolution = sub_807EB50;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gUnknown_02032298[0]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
                TradeEvolutionScene(&gPlayerParty[gUnknown_02032298[0]], evoTarget, gUnknown_020322A0->pokePicSpriteIdxs[1], gUnknown_02032298[0]);
            else if (sub_8077260())
                SetMainCallback2(sub_807F464);
            else
                SetMainCallback2(sub_807EB50);
            gUnknown_02032298[0] = 255;
            break;
    }
    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807E4DC(void)
{
    u8 blockReceivedStatus;
    sub_807ACDC();
    blockReceivedStatus = GetBlockReceivedStatus();
    if (blockReceivedStatus & 0x01)
    {
        if (gBlockRecvBuffer[0][0] == 0xDCBA)
        {
            SetMainCallback2(c2_08053788);
        }
        if (gBlockRecvBuffer[0][0] == 0xABCD)
        {
            gUnknown_020322A0->unk_72 = 1;
        }
        ResetBlockReceivedFlag(0);
    }
    if (blockReceivedStatus & 0x02)
    {
        if (gBlockRecvBuffer[1][0] == 0xABCD)
        {
            gUnknown_020322A0->unk_73 = 1;
        }
        ResetBlockReceivedFlag(1);
    }
}

void sub_807E55C(struct Sprite *sprite)
{
    sprite->pos1.y += sprite->data[0] / 10;
    sprite->data[5] += sprite->data[1];
    sprite->pos1.x = sprite->data[5] / 10;
    if (sprite->pos1.y > 0x4c)
    {
        sprite->pos1.y = 0x4c;
        sprite->data[0] = -(sprite->data[0] * sprite->data[2]) / 100;
        sprite->data[3] ++;
    }
    if (sprite->pos1.x == 0x78)
        sprite->data[1] = 0;
    sprite->data[0] += sprite->data[4];
    if (sprite->data[3] == 4)
    {
        sprite->data[7] = 1;
        sprite->callback = SpriteCallbackDummy;
    }
}

void sub_807E5D8(struct Sprite *sprite)
{
    sprite->pos2.y += gTradeBallVerticalVelocityTable[sprite->data[0]];
    if (sprite->data[0] == 22)
        PlaySE(SE_KON);
    if (++ sprite->data[0] == 44)
    {
        PlaySE(SE_W025);
        sprite->callback = sub_807E64C;
        sprite->data[0] = 0;
        BeginNormalPaletteFade(1 << (16 + sprite->oam.paletteNum), -1, 0, 16, RGB_WHITEALPHA);
    }
}

void sub_807E64C(struct Sprite *sprite)
{
    if (sprite->data[1] == 20)
        StartSpriteAffineAnim(sprite, 1);
    if (++ sprite->data[1] > 20)
    {
        sprite->pos2.y -= gTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++ sprite->data[0] == 23)
        {
            DestroySprite(sprite);
            gUnknown_020322A0->unk_94 = 14; // Resume the master trade animation
        }
    }
}

void sub_807E6AC(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        if ((sprite->pos1.y += 4) > sprite->data[3])
        {
            sprite->data[2] ++;
            sprite->data[0] = 0x16;
            PlaySE(SE_KON);
        }
    }
    else
    {
        if (sprite->data[0] == 0x42)
            PlaySE(SE_KON2);
        if (sprite->data[0] == 0x5c)
            PlaySE(SE_KON3);
        if (sprite->data[0] == 0x6b)
            PlaySE(SE_KON4);
        sprite->pos2.y += gTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++sprite->data[0] == 0x6c)
            sprite->callback = SpriteCallbackDummy;
    }
}

u16 GetInGameTradeSpeciesInfo(void)
{
    const struct InGameTrade *inGameTrade = &gIngameTrades[gSpecialVar_0x8004];
    StringCopy(gStringVar1, gSpeciesNames[inGameTrade->playerSpecies]);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
    return inGameTrade->playerSpecies;
}

void sub_807E784(void)
{
    u8 nickname[32];
    const struct InGameTrade *inGameTrade = &gIngameTrades[gSpecialVar_0x8004];
    GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, nickname);
    StringCopy10(gStringVar1, nickname);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
}

void _CreateInGameTradePokemon(u8 whichPlayerMon, u8 whichInGameTrade)
{
    const struct InGameTrade *inGameTrade = &gIngameTrades[whichInGameTrade];
    u8 level = GetMonData(&gPlayerParty[whichPlayerMon], MON_DATA_LEVEL);

    struct MailStruct mail;
    u8 metLocation = 0xFE;
    u8 isMail;
    struct Pokemon *pokemon = &gEnemyParty[0];

    CreateMon(pokemon, inGameTrade->species, level, 32, TRUE, inGameTrade->personality, TRUE, inGameTrade->otId);

    SetMonData(pokemon, MON_DATA_HP_IV, &inGameTrade->ivs[0]);
    SetMonData(pokemon, MON_DATA_ATK_IV, &inGameTrade->ivs[1]);
    SetMonData(pokemon, MON_DATA_DEF_IV, &inGameTrade->ivs[2]);
    SetMonData(pokemon, MON_DATA_SPEED_IV, &inGameTrade->ivs[3]);
    SetMonData(pokemon, MON_DATA_SPATK_IV, &inGameTrade->ivs[4]);
    SetMonData(pokemon, MON_DATA_SPDEF_IV, &inGameTrade->ivs[5]);
    SetMonData(pokemon, MON_DATA_NICKNAME, inGameTrade->name);
    SetMonData(pokemon, MON_DATA_OT_NAME, inGameTrade->otName);
    SetMonData(pokemon, MON_DATA_OT_GENDER, &inGameTrade->otGender);
    SetMonData(pokemon, MON_DATA_ALT_ABILITY, &inGameTrade->secondAbility);
    SetMonData(pokemon, MON_DATA_BEAUTY, &inGameTrade->stats[1]);
    SetMonData(pokemon, MON_DATA_CUTE, &inGameTrade->stats[2]);
    SetMonData(pokemon, MON_DATA_COOL, &inGameTrade->stats[0]);
    SetMonData(pokemon, MON_DATA_SMART, &inGameTrade->stats[3]);
    SetMonData(pokemon, MON_DATA_TOUGH, &inGameTrade->stats[4]);
    SetMonData(pokemon, MON_DATA_SHEEN, &inGameTrade->sheen);
    SetMonData(pokemon, MON_DATA_MET_LOCATION, &metLocation);

    isMail = FALSE;
    if (inGameTrade->heldItem != ITEM_NONE)
    {
        if (ItemIsMail(inGameTrade->heldItem))
        {
            sub_807E974(&mail, inGameTrade);
            gUnknown_020321C0[0] = mail;
            SetMonData(pokemon, MON_DATA_MAIL, &isMail);
            SetMonData(pokemon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
        else
        {
            SetMonData(pokemon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
    }
    CalculateMonStats(&gEnemyParty[0]);
}

void sub_807E974(struct MailStruct *mail, const struct InGameTrade *trade) {
    s32 i;

    for (i = 0; i < 9; i++)
    {
        mail->words[i] = gIngameTradeMail[trade->mailNum][i];
    }

    StringCopy(mail->playerName, trade->otName);
    PadNameString(mail->playerName, CHAR_SPACE);

    mail->trainerId[0] = trade->otId >> 24;
    mail->trainerId[1] = trade->otId >> 16;
    mail->trainerId[2] = trade->otId >> 8;
    mail->trainerId[3] = trade->otId;
    mail->species = trade->species;
    mail->itemId = trade->heldItem;
}

u16 GetTradeSpecies(void)
{
    if (GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_IS_EGG))
        return SPECIES_NONE;
    return GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_SPECIES);
}

void CreateInGameTradePokemon(void)
{
    _CreateInGameTradePokemon(gSpecialVar_0x8005, gSpecialVar_0x8004);
}

void sub_807EA2C(void)
{
    if (sub_807BBC8() == TRUE)
    {
        DestroySprite(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]]);
        FreeSpriteOamMatrix(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]]);
        sub_807B4D0(gUnknown_02032298[0], gUnknown_02032298[1] % 6);
        if (!sub_8077260())
        {
            gUnknown_020322A0->linkData[0] = 0xABCD;
            gUnknown_020322A0->unk_93 = 1;
        }
        SetMainCallback2(sub_807EACC);
    }
    sub_807B5B8();
    sub_807E4DC();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807EACC(void)
{
    u8 mpId = sub_807ACDC();
    if (sub_8077260())
    {
        SetMainCallback2(c2_08053788);
    }
    else
    {
        sub_807E4DC();
        if (mpId == 0 && gUnknown_020322A0->unk_72 == 1 && gUnknown_020322A0->unk_73 == 1)
        {
            gUnknown_020322A0->linkData[0] = 0xDCBA;
            Trade_SendData(gUnknown_020322A0);
            gUnknown_020322A0->unk_72 = 2;
            gUnknown_020322A0->unk_73 = 2;
        }
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807EB50(void)
{
    switch (gMain.state)
    {
        case 0:
            gMain.state++;
            StringExpandPlaceholders(gStringVar4, gText_CommunicationStandby5);
            sub_807F1A8(0, gStringVar4, 0);
            break;
        case 1:
            sub_8077288(0);
            gMain.state = 100;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 100:
            if (++gUnknown_020322A0->unk_64 > 180)
            {
                gMain.state = 101;
                gUnknown_020322A0->unk_64 = 0;
            }
            if (IsLinkTaskFinished())
            {
                gMain.state = 2;
            }
            break;
        case 101:
            if (IsLinkTaskFinished())
            {
                gMain.state = 2;
            }
            break;
        case 2:
            gMain.state = 50;
            StringExpandPlaceholders(gStringVar4, gText_SavingDontTurnOffPower);
            sub_807F1A8(0, gStringVar4, 0);
            break;
        case 50:
            if (!InUnionRoom())
                IncrementGameStat(GAME_STAT_POKEMON_TRADES);
            if (gWirelessCommType)
            {
                sub_801B990(2, gLinkPlayers[GetMultiplayerId() ^ 1].trainerId);
            }
            sub_8076D5C();
            sub_8153380();
            gMain.state++;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 51:
            if (++gUnknown_020322A0->unk_64 == 5)
            {
                gMain.state++;
            }
            break;
        case 52:
            if (sub_81533AC())
            {
                sav2_gender2_inplace_and_xFE();
                gMain.state = 4;
            }
            else
            {
                gUnknown_020322A0->unk_64 = 0;
                gMain.state = 51;
            }
            break;
        case 4:
            sub_81533E0();
            gMain.state = 40;
            gUnknown_020322A0->unk_64 = 0;
            break;
        case 40:
            if (++gUnknown_020322A0->unk_64 > 50)
            {
                if (GetMultiplayerId() == 0)
                {
                    gUnknown_020322A0->unk_64 = Random() % 30;
                }
                else
                {
                    gUnknown_020322A0->unk_64 = 0;
                }
                gMain.state = 41;
            }
            break;
        case 41:
            if (gUnknown_020322A0->unk_64 == 0)
            {
                sub_8077288(1);
                gMain.state = 42;
            }
            else
            {
                gUnknown_020322A0->unk_64--;
            }
            break;
        case 42:
            if (IsLinkTaskFinished())
            {
                sub_8153408();
                gMain.state = 5;
            }
            break;
        case 5:
            if (++gUnknown_020322A0->unk_64 > 60)
            {
                gMain.state++;
                sub_8077288(2);
            }
            break;
        case 6:
            if (IsLinkTaskFinished())
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gMain.state ++;
            }
            break;
        case 7:
            if (!gPaletteFade.active)
            {
                FadeOutBGM(3);
                gMain.state++;
            }
            break;
        case 8:
            if (IsBGMStopped() == TRUE)
            {
                if (gWirelessCommType && gMain.savedCallback == sub_80773AC)
                {
                    sub_8077288(3);
                }
                else
                {
                    sub_800AC34();
                }
                gMain.state++;
            }
            break;
        case 9:
            if (gWirelessCommType && gMain.savedCallback == sub_80773AC)
            {
                if (IsLinkTaskFinished())
                {
                    gSoftResetDisabled = FALSE;
                    SetMainCallback2(c2_080543C4);
                }
            }
            else if (!gReceivedRemoteLinkPlayers)
            {
                gSoftResetDisabled = FALSE;
                SetMainCallback2(c2_080543C4);
            }
            break;
    }
    if (!HasLinkErrorOccurred())
    {
        RunTasks();
    }
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void c2_080543C4(void)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        Free(GetBgTilemapBuffer(3));
        Free(GetBgTilemapBuffer(1));
        Free(GetBgTilemapBuffer(0));
        FreeMonSpritesGfx();
        FREE_AND_SET_NULL(gUnknown_020322A0);
        if (gWirelessCommType)
            sub_800E084();
        SetMainCallback2(gMain.savedCallback);
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void DoInGameTradeScene(void)
{
    ScriptContext2_Enable();
    CreateTask(sub_807F110, 10);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
}

void sub_807F110(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sub_807B270);
        gFieldCallback = sub_80AF168;
        DestroyTask(taskId);
    }
}

void sub_807F14C(void)
{
    u8 i;
    u8 numRibbons = 0;
    for (i = 0; i < 12; i ++)
    {
        numRibbons += GetMonData(&gEnemyParty[gUnknown_02032298[1] % 6], MON_DATA_CHAMPION_RIBBON + i);
    }
    if (numRibbons != 0)
        FlagSet(FLAG_SYS_RIBBON_GET);
}

void sub_807F19C(void)
{
    sub_807B170();
}

void sub_807F1A8(u8 windowId, const u8 *str, u8 speed)
{
    FillWindowPixelBuffer(windowId, 0xFF);
    gUnknown_020322A0->unk_F6[0] = 15;
    gUnknown_020322A0->unk_F6[1] = 1;
    gUnknown_020322A0->unk_F6[2] = 6;
    AddTextPrinterParameterized4(windowId, 1, 0, 2, 0, 0, gUnknown_020322A0->unk_F6, speed, str);
    CopyWindowToVram(windowId, 3);
}

void c3_08054588(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 unk = gUnknown_08339090[data[0]][0] * 16;

    if (!data[2])
    {
        if (unk == 0x100)
            LoadPalette(gUnknown_08337EA0, 0x30, 32);
        else
            LoadPalette(&gUnknown_08337AA0[unk], 0x30, 32);
    }
    else
    {
        if (unk == 0x100)
            LoadPalette(gUnknown_08337EA0, 0x30, 32);
        else
            LoadPalette(&gUnknown_08337CA0[unk], 0x30, 32);
    }

    if (gUnknown_08339090[data[0]][0] == 0 && data[1] == 0)
        PlaySE(SE_W215);

    if (data[1] == gUnknown_08339090[data[0]][1])
    {
        data[0]++;
        data[1] = 0;
        if (gUnknown_08339090[data[0]][1] == 0xFF)
        {
            DestroyTask(taskId);
        }
    }
    else
    {
        data[1]++;
    }
}

void c3_0805465C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        gUnknown_020322A0->unk_FB = gUnknown_020322A0->unk_FD = 120;
        gUnknown_020322A0->unk_FC = 0;
        gUnknown_020322A0->unk_FE = 160;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(gUnknown_020322A0->unk_FB, gUnknown_020322A0->unk_FD));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(gUnknown_020322A0->unk_FC, gUnknown_020322A0->unk_FE));
    
    data[0]++;
    gUnknown_020322A0->unk_FB -= 5;
    gUnknown_020322A0->unk_FD += 5;

    if (gUnknown_020322A0->unk_FB < 80)
    {
        DestroyTask(taskId);
    }
}
