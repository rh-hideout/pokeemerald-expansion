#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "bg.h"
#include "menu.h"
#include "sound.h"
#include "palette.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "sprite.h"
#include "text.h"
#include "string_util.h"
#include "text_window.h"
#include "random.h"
#include "rtc.h"
#include "pokemon.h"
#include "item.h"
#include "move.h"
#include "strings.h"
#include "wild_encounter.h"
#include "overworld.h"
#include "region_map.h"
#include "event_data.h"
#include "data.h"
#include "pokedex.h"
#include "constants/pokedex.h"
#include "constants/songs.h"
#include "constants/region_map_sections.h"
#include "constants/flags_hns.h"
#include "constants/vars_hns.h"
#include "constants/trainers.h"

#define RADIO_FRAME_BASE_TILE 150
#define RADIO_FRAME_PALETTE 4
#define RADIO_TEXT_PALETTE 5
#include "data/text/radio_strings.h"

#define GFXTAG_RADIO_DIAL 11
#define PALTAG_RADIO_DIAL 21

#define RADIO_TUNING_MIN 0
#define RADIO_TUNING_MAX 63
#define RADIO_TUNING_STEP 1
#define RADIO_DIAL_BASE_X 144
#define RADIO_DIAL_Y 28
#define RADIO_LINE_HEIGHT 16
#define RADIO_SCROLL_DELAY 90

#define MAX_RADIO_LINES 15
#define RADIO_LINE_BUF_SIZE 40
#define NUM_RADIO_LINE_BUFS 8

enum RadioStation
{
    RADIO_STATION_NONE,
    RADIO_STATION_POKEMON_TALK,
    RADIO_STATION_POKEDEX_SHOW,
    RADIO_STATION_POKEMON_MUSIC,
    RADIO_STATION_LUCKY_CHANNEL,
    RADIO_STATION_BUENAS_PASSWORD,
    RADIO_STATION_UNOWN,
    RADIO_STATION_PLACES_AND_PEOPLE,
    RADIO_STATION_LETS_ALL_SING,
    RADIO_STATION_POKE_FLUTE,
    RADIO_STATION_EVOLUTION,
    RADIO_STATION_ROCKET,
    RADIO_STATION_HOENN_SOUND,
    NUM_RADIO_STATIONS,
};

struct RadioChannelEntry
{
    s32 tuningPos;
    u8 station;
    const u8 *name;
};

#define OPT_SEGMENTS_PER_CYCLE 5
#define OPT_INTERLUDE_DELAY (RADIO_SCROLL_DELAY * 4)

enum OPT_Phase
{
    OPT_PHASE_INTRO,
    OPT_PHASE_POKEMON,
    OPT_PHASE_INTERLUDE,
    OPT_PHASE_REPORT,
};

struct Pokenav_Radio
{
    u32 (*callback)(void);
    s32 tuningPos;
    u8 tuneDelay;
    u8 currentStation;
    u16 scrollTimer;
    u8 currentLine;
    u8 numLines;
    bool8 needsScroll;
    u8 optSegmentCounter;
    u8 optPhase;
    u16 currentMusic;
    const u8 *lines[MAX_RADIO_LINES];
    u8 lineBuffers[NUM_RADIO_LINE_BUFS][RADIO_LINE_BUF_SIZE];
};

struct Pokenav_RadioGfx
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopedTaskId;
    struct Sprite *dialSprite;
    u16 stationNameWindowId;
    u16 radioTextWindowId;
    u16 bgTilemapBuffer1[BG_SCREEN_SIZE / 2];
    u16 bgTilemapBuffer2[BG_SCREEN_SIZE / 2];
};

enum
{
    POKENAV_RADIO_FUNC_NONE,
    POKENAV_RADIO_FUNC_TUNE,
    POKENAV_RADIO_FUNC_EXIT,
    POKENAV_RADIO_FUNC_SCROLL,
};

static u32 HandleRadioInput(void);
static u32 GetExitRadioMenuId(void);
static u32 LoopedTask_OpenRadio(s32 state);
static u32 LoopedTask_TuneRadio(s32 state);
static u32 LoopedTask_ExitRadio(s32 state);
static u32 LoopedTask_ScrollRadio(s32 state);
static bool32 GetCurrentRadioLoopedTaskActive(void);
static u8 FindStation(s32 tuningPos);
static void PrintStationName(struct Pokenav_RadioGfx *gfx, u8 station);
static void PrintRadioText(struct Pokenav_RadioGfx *gfx, const u8 *text);
static void ClearRadioText(struct Pokenav_RadioGfx *gfx);
static void GenerateStationContent(struct Pokenav_Radio *radio, u8 station);
static void GenerateOPTSegment(struct Pokenav_Radio *radio);
static void GeneratePokemonMusicContent(struct Pokenav_Radio *radio, u32 *n, u32 *buf, bool32 isBen);

static const u16 sRadioUI_Pal[] = INCBIN_U16("graphics/pokenav/hns/radio/ui.gbapal");
static const u32 sRadioUI_Gfx[] = INCBIN_U32("graphics/pokenav/hns/radio/ui_tiles.4bpp.smol");
static const u32 sRadioUI_Tilemap[] = INCBIN_U32("graphics/pokenav/hns/radio/ui_map.bin.smolTM");
static const u32 sRadioDial_Gfx[] = INCBIN_U32("graphics/pokenav/hns/radio/dial.4bpp.smol");

// Crystal frequencies (0-80) scaled to our range (0-63):
//   new = old * 63 / 80
static const struct RadioChannelEntry sRadioChannels[] =
{
    { .tuningPos = 13, .station = RADIO_STATION_POKEMON_TALK,     .name = sRadioStationName_OaksPkmnTalk },
    { .tuningPos = 22, .station = RADIO_STATION_POKEMON_MUSIC,    .name = sRadioStationName_PokemonMusic },
    { .tuningPos = 25, .station = RADIO_STATION_LUCKY_CHANNEL,    .name = sRadioStationName_LuckyChannel },
    { .tuningPos = 32, .station = RADIO_STATION_BUENAS_PASSWORD,  .name = sRadioStationName_BuenasPassword },
    { .tuningPos =  5, .station = RADIO_STATION_HOENN_SOUND,     .name = sRadioStationName_HoennSound },
    { .tuningPos = 41, .station = RADIO_STATION_UNOWN,            .name = sRadioStationName_Unown },
    { .tuningPos = 50, .station = RADIO_STATION_PLACES_AND_PEOPLE,.name = sRadioStationName_PlacesAndPeople },
    { .tuningPos = 57, .station = RADIO_STATION_LETS_ALL_SING,    .name = sRadioStationName_LetsAllSing },
    { .tuningPos = 61, .station = RADIO_STATION_POKE_FLUTE,       .name = sRadioStationName_PokeFlute },
    { .tuningPos = 63, .station = RADIO_STATION_EVOLUTION,        .name = sRadioStationName_Unown },
};

static const u8 sRadioText_NoStation[] = _("- - - -");

static const u16 sRadioStationMusic[NUM_RADIO_STATIONS] =
{
    [RADIO_STATION_NONE]             = 0,
    [RADIO_STATION_POKEMON_TALK]     = MUS_HG_RADIO_OAK,
    [RADIO_STATION_POKEDEX_SHOW]     = MUS_HG_RADIO_OAK,
    [RADIO_STATION_POKEMON_MUSIC]    = MUS_HG_RADIO_MARCH,
    [RADIO_STATION_LUCKY_CHANNEL]    = MUS_HG_RADIO_JINGLE,
    [RADIO_STATION_BUENAS_PASSWORD]  = MUS_HG_RADIO_BUENA,
    [RADIO_STATION_UNOWN]            = MUS_HG_RADIO_UNOWN,
    [RADIO_STATION_PLACES_AND_PEOPLE]= MUS_HG_RADIO_OAK,
    [RADIO_STATION_LETS_ALL_SING]    = MUS_HG_RADIO_LULLABY,
    [RADIO_STATION_POKE_FLUTE]       = MUS_HG_RADIO_POKE_FLUTE,
    [RADIO_STATION_EVOLUTION]        = MUS_HG_RADIO_UNOWN,
    [RADIO_STATION_ROCKET]           = MUS_HG_RADIO_ROCKET,
    [RADIO_STATION_HOENN_SOUND]      = MUS_HG_RADIO_ROUTE101,
};

struct OPTRouteEntry
{
    u8 mapGroup;
    u8 mapNum;
};

static const struct OPTRouteEntry sOPTRoutes[] =
{
    { MAP_GROUP(MAP_ROUTE29_HNS), MAP_NUM(MAP_ROUTE29_HNS) },
    { MAP_GROUP(MAP_ROUTE46_HNS), MAP_NUM(MAP_ROUTE46_HNS) },
    { MAP_GROUP(MAP_ROUTE30_HNS), MAP_NUM(MAP_ROUTE30_HNS) },
    { MAP_GROUP(MAP_ROUTE32_HNS), MAP_NUM(MAP_ROUTE32_HNS) },
    { MAP_GROUP(MAP_ROUTE34_HNS), MAP_NUM(MAP_ROUTE34_HNS) },
    { MAP_GROUP(MAP_ROUTE35_HNS), MAP_NUM(MAP_ROUTE35_HNS) },
    { MAP_GROUP(MAP_ROUTE37_HNS), MAP_NUM(MAP_ROUTE37_HNS) },
    { MAP_GROUP(MAP_ROUTE38_HNS), MAP_NUM(MAP_ROUTE38_HNS) },
    { MAP_GROUP(MAP_ROUTE39_HNS), MAP_NUM(MAP_ROUTE39_HNS) },
    { MAP_GROUP(MAP_ROUTE42_HNS), MAP_NUM(MAP_ROUTE42_HNS) },
    { MAP_GROUP(MAP_ROUTE43_HNS), MAP_NUM(MAP_ROUTE43_HNS) },
    { MAP_GROUP(MAP_ROUTE44_HNS), MAP_NUM(MAP_ROUTE44_HNS) },
    { MAP_GROUP(MAP_ROUTE45_HNS), MAP_NUM(MAP_ROUTE45_HNS) },
    { MAP_GROUP(MAP_ROUTE36_HNS), MAP_NUM(MAP_ROUTE36_HNS) },
    { MAP_GROUP(MAP_ROUTE31_HNS), MAP_NUM(MAP_ROUTE31_HNS) },
};

#define NUM_OPT_ROUTES ARRAY_COUNT(sOPTRoutes)

// Day-of-week name table
static const u8 *const sDayOfWeekNames[] =
{
    gText_Sunday, gText_Monday, gText_Tuesday, gText_Wednesday,
    gText_Thursday, gText_Friday, gText_Saturday,
};

static const u16 sPnPPlaces[] =
{
    MAPSEC_PALLET_TOWN,
    MAPSEC_ROUTE_22,
    MAPSEC_PEWTER_CITY,
    MAPSEC_CERULEAN_CITY,
    MAPSEC_ROUTE_12,
    MAPSEC_ROUTE_11,
    MAPSEC_ROUTE_16,
    MAPSEC_ROUTE_14,
    MAPSEC_CINNABAR_ISLAND,
};

// Buena's password categories
enum BuenaPasswordType
{
    BUENA_MON,
    BUENA_ITEM,
    BUENA_MOVE,
    BUENA_STRING,
};

struct BuenaPasswordEntry
{
    u8 type;
    u16 value;
};

static const struct BuenaPasswordEntry sBuenaPasswords[][3] =
{
    // Johto Starters
    {{ BUENA_MON, SPECIES_CYNDAQUIL }, { BUENA_MON, SPECIES_TOTODILE }, { BUENA_MON, SPECIES_CHIKORITA }},
    // Beverages
    {{ BUENA_ITEM, ITEM_FRESH_WATER }, { BUENA_ITEM, ITEM_SODA_POP }, { BUENA_ITEM, ITEM_LEMONADE }},
    // Healing Items
    {{ BUENA_ITEM, ITEM_POTION }, { BUENA_ITEM, ITEM_ANTIDOTE }, { BUENA_ITEM, ITEM_PARALYZE_HEAL }},
    // Balls
    {{ BUENA_ITEM, ITEM_POKE_BALL }, { BUENA_ITEM, ITEM_GREAT_BALL }, { BUENA_ITEM, ITEM_ULTRA_BALL }},
    // Pokemon 1
    {{ BUENA_MON, SPECIES_PIKACHU }, { BUENA_MON, SPECIES_RATTATA }, { BUENA_MON, SPECIES_GEODUDE }},
    // Pokemon 2
    {{ BUENA_MON, SPECIES_HOOTHOOT }, { BUENA_MON, SPECIES_SPINARAK }, { BUENA_MON, SPECIES_DROWZEE }},
    // Johto Towns
    {{ BUENA_STRING, 0 }, { BUENA_STRING, 1 }, { BUENA_STRING, 2 }},
    // Types
    {{ BUENA_STRING, 3 }, { BUENA_STRING, 4 }, { BUENA_STRING, 5 }},
    // Moves
    {{ BUENA_MOVE, MOVE_TACKLE }, { BUENA_MOVE, MOVE_GROWL }, { BUENA_MOVE, MOVE_MUD_SLAP }},
    // X Items
    {{ BUENA_ITEM, ITEM_X_ATTACK }, { BUENA_ITEM, ITEM_X_DEFENSE }, { BUENA_ITEM, ITEM_X_SPEED }},
    // Radio Stations
    {{ BUENA_STRING, 6 }, { BUENA_STRING, 7 }, { BUENA_STRING, 8 }},
};

#define NUM_BUENA_CATEGORIES ARRAY_COUNT(sBuenaPasswords)

static const u8 *const sBuenaStringPasswords[] =
{
    sRadioBuenaPassword_NewBarkTown,
    sRadioBuenaPassword_CherrygroveCity,
    sRadioBuenaPassword_AzaleaTown,
    sRadioBuenaPassword_Flying,
    sRadioBuenaPassword_Bug,
    sRadioBuenaPassword_Grass,
    sRadioBuenaPassword_PkmnTalk,
    sRadioBuenaPassword_PkmnMusic,
    sRadioBuenaPassword_LuckyChannel,
};

static const struct CompressedSpriteSheet sRadioDialSpriteSheet =
{
    .data = sRadioDial_Gfx,
    .size = 16 * 16 / 2,
    .tag = GFXTAG_RADIO_DIAL,
};

static const struct SpritePalette sRadioDialSpritePalette =
{
    .data = sRadioUI_Pal,
    .tag = PALTAG_RADIO_DIAL,
};

static const struct OamData sRadioDialOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const struct SpriteTemplate sRadioDialSpriteTemplate =
{
    .tileTag = GFXTAG_RADIO_DIAL,
    .paletteTag = PALTAG_RADIO_DIAL,
    .oam = &sRadioDialOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// Station name window: inside the text box area
static const struct WindowTemplate sStationNameWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 6,
    .tilemapTop = 8,
    .width = 19,
    .height = 4,
    .paletteNum = 2,
    .baseBlock = 200,
};

static const u8 sStationNameTextColors[] = {TEXT_COLOR_TRANSPARENT, 7, 5};

// Radio text window: bottom of screen for scrolling dialogue
static const struct WindowTemplate sRadioTextWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 13,
    .width = 28,
    .height = 4,
    .paletteNum = RADIO_TEXT_PALETTE,
    .baseBlock = 1,
};

static const u8 sRadioTextColors[] = {TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

static const struct BgTemplate sRadioBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const LoopedTask sRadioLoopTaskFuncs[] =
{
    [POKENAV_RADIO_FUNC_NONE] = NULL,
    [POKENAV_RADIO_FUNC_TUNE] = LoopedTask_TuneRadio,
    [POKENAV_RADIO_FUNC_EXIT] = LoopedTask_ExitRadio,
    [POKENAV_RADIO_FUNC_SCROLL] = LoopedTask_ScrollRadio,
};

// ========================================
// Station content generation
// ========================================

static void GetBuenaPasswordString(u8 *dest, u32 category, u32 word)
{
    const struct BuenaPasswordEntry *entry = &sBuenaPasswords[category][word];
    switch (entry->type)
    {
    case BUENA_MON:
        StringCopy(dest, GetSpeciesName(entry->value));
        break;
    case BUENA_ITEM:
        CopyItemName(entry->value, dest);
        break;
    case BUENA_MOVE:
        StringCopy(dest, GetMoveName(entry->value));
        break;
    case BUENA_STRING:
        StringCopy(dest, sBuenaStringPasswords[entry->value]);
        break;
    }
}

static u16 PickWildSpeciesFromRoute(u8 mapGroup, u8 mapNum)
{
    u32 i;
    for (i = 0; gWildMonHeaders[i].mapGroup != MAP_GROUP(MAP_UNDEFINED); i++)
    {
        if (gWildMonHeaders[i].mapGroup == mapGroup && gWildMonHeaders[i].mapNum == mapNum)
        {
            enum TimeOfDay tod = Random() % TIMES_OF_DAY_COUNT;
            const struct WildPokemonInfo *info;

            info = gWildMonHeaders[i].encounterTypes[tod].landMonsInfo;
            if (info != NULL && info->wildPokemon != NULL)
            {
                // Pick from the middle slots (2-4) like Crystal
                u32 slot = 2 + (Random() % 3);
                return info->wildPokemon[slot].species;
            }
            // Fallback: try any time of day with land mons
            for (tod = TIME_MORNING; tod < TIMES_OF_DAY_COUNT; tod++)
            {
                info = gWildMonHeaders[i].encounterTypes[tod].landMonsInfo;
                if (info != NULL && info->wildPokemon != NULL)
                    return info->wildPokemon[2 + (Random() % 3)].species;
            }
        }
    }
    return SPECIES_CHIKORITA;
}

static void GenerateOPTSegment(struct Pokenav_Radio *radio)
{
    u32 n = 0;
    u32 buf = 0;
    u8 *dst;

    switch (radio->optPhase)
    {
    case OPT_PHASE_INTRO:
        radio->lines[n++] = sRadioText_OPT_Intro;
        radio->lines[n++] = sRadioText_OPT_WithMeMary;
        radio->optPhase = OPT_PHASE_POKEMON;
        break;

    case OPT_PHASE_POKEMON:
    {
        u32 routeIdx = Random() % NUM_OPT_ROUTES;
        u8 mg = sOPTRoutes[routeIdx].mapGroup;
        u8 mn = sOPTRoutes[routeIdx].mapNum;
        u16 species = PickWildSpeciesFromRoute(mg, mn);
        const u8 *speciesName = GetSpeciesName(species);
        const struct MapHeader *header = Overworld_GetMapHeaderByGroupAndId(mg, mn);

        // "OAK: Bayleef"
        dst = radio->lineBuffers[buf];
        StringCopy(dst, sRadioText_OPT_OakPrefix);
        StringAppend(dst, speciesName);
        radio->lines[n++] = radio->lineBuffers[buf++];

        // "may be seen around Route 29."
        dst = radio->lineBuffers[buf];
        StringCopy(dst, sRadioText_OPT_SeenAround);
        {
            u8 *end = dst + StringLength(dst);
            *end++ = CHAR_SPACE;
            *end = EOS;
        }
        {
            u8 mapNameBuf[24];
            GetMapName(mapNameBuf, header->regionMapSectionId, 0);
            StringAppend(dst, mapNameBuf);
        }
        {
            u8 *end = dst + StringLength(dst);
            *end++ = CHAR_PERIOD;
            *end = EOS;
        }
        radio->lines[n++] = radio->lineBuffers[buf++];

        // "MARY: Bayleef's"
        dst = radio->lineBuffers[buf];
        StringCopy(dst, sRadioText_OPT_MaryPrefix);
        StringAppend(dst, speciesName);
        StringAppend(dst, sRadioText_OPT_MaryIs);
        radio->lines[n++] = radio->lineBuffers[buf++];

        // "sweet and adorably cute."
        dst = radio->lineBuffers[buf];
        StringCopy(dst, sRadioText_OPT_Adverbs[Random() % ARRAY_COUNT(sRadioText_OPT_Adverbs)]);
        {
            u8 *end = dst + StringLength(dst);
            *end++ = CHAR_SPACE;
            *end = EOS;
        }
        StringAppend(dst, sRadioText_OPT_Adjectives[Random() % ARRAY_COUNT(sRadioText_OPT_Adjectives)]);
        radio->lines[n++] = radio->lineBuffers[buf++];

        radio->optSegmentCounter--;
        if (radio->optSegmentCounter == 0)
            radio->optPhase = OPT_PHASE_INTERLUDE;
        break;
    }

    case OPT_PHASE_INTERLUDE:
        PlayNewMapMusic(MUS_HG_RADIO_JINGLE);
        radio->currentMusic = MUS_HG_RADIO_JINGLE;
        radio->lines[n++] = sRadioText_OPT_PokemonChannel;
        radio->optPhase = OPT_PHASE_REPORT;
        radio->needsScroll = FALSE;
        radio->numLines = n;
        radio->currentLine = 0;
        radio->scrollTimer = OPT_INTERLUDE_DELAY;
        return;

    case OPT_PHASE_REPORT:
    {
        u32 reportIdx = Random() % NUM_OPT_REPORTS;
        u32 i;
        PlayNewMapMusic(MUS_HG_RADIO_OAK);
        radio->currentMusic = MUS_HG_RADIO_OAK;
        for (i = 0; i < OPT_REPORT_LINES; i++)
            radio->lines[n++] = sOPT_Reports[reportIdx][i];
        radio->optPhase = OPT_PHASE_POKEMON;
        radio->optSegmentCounter = OPT_SEGMENTS_PER_CYCLE;
        break;
    }
    }

    radio->numLines = n;
    radio->currentLine = 0;
    radio->scrollTimer = RADIO_SCROLL_DELAY;
}

#define RADIO_LINE_PIXEL_WIDTH (28 * 8 - 4)

static bool8 IsRadioBreakChar(u8 c)
{
    return c == CHAR_SPACE || c == CHAR_NEWLINE
        || c == CHAR_PROMPT_SCROLL || c == CHAR_PROMPT_CLEAR;
}

static const u8 *SkipRadioBreakChars(const u8 *text)
{
    while (*text != EOS && IsRadioBreakChar(*text))
        text++;
    return text;
}

// Find the end of the current word (run of non-break, non-EOS chars)
static const u8 *FindWordEnd(const u8 *text)
{
    while (*text != EOS && !IsRadioBreakChar(*text))
        text++;
    return text;
}

static u32 WrapDexTextIntoLines(struct Pokenav_Radio *radio, const u8 *text, u32 *n, u32 *buf)
{
    u32 linesAdded = 0;

    text = SkipRadioBreakChars(text);

    while (*text != EOS && *buf < NUM_RADIO_LINE_BUFS && *n < MAX_RADIO_LINES)
    {
        u8 *dst = radio->lineBuffers[*buf];
        u32 pos = 0;
        dst[0] = EOS;

        while (*text != EOS)
        {
            const u8 *wordStart = text;
            const u8 *wordEnd = FindWordEnd(wordStart);
            u32 wordLen = wordEnd - wordStart;
            u32 needSpace = (pos > 0) ? 1 : 0;

            if (pos + needSpace + wordLen >= RADIO_LINE_BUF_SIZE)
                break;

            // Trial: append space + word, check pixel width
            if (needSpace)
                dst[pos++] = CHAR_SPACE;
            memcpy(&dst[pos], wordStart, wordLen);
            pos += wordLen;
            dst[pos] = EOS;

            if (GetStringWidth(FONT_NORMAL, dst, -1) > RADIO_LINE_PIXEL_WIDTH)
            {
                // Undo: this word doesn't fit
                pos -= wordLen + needSpace;
                dst[pos] = EOS;
                break;
            }

            text = SkipRadioBreakChars(wordEnd);
        }

        if (pos == 0)
            break;

        dst[pos] = EOS;
        radio->lines[(*n)++] = radio->lineBuffers[(*buf)++];
        linesAdded++;
    }
    return linesAdded;
}

static void GeneratePokemonMusicContent(struct Pokenav_Radio *radio, u32 *n, u32 *buf, bool32 isBen)
{
    u32 dayOfWeek = GetDayOfWeek();
    bool32 isEvenDay = (dayOfWeek % 2) == 0;
    u8 *dst;

    if (isBen)
    {
        radio->lines[(*n)++] = sRadioText_BenIntro;
        radio->lines[(*n)++] = sRadioText_BenIntro2;
    }
    else
    {
        radio->lines[(*n)++] = sRadioText_FernIntro;
        radio->lines[(*n)++] = sRadioText_FernIntro2;
    }

    dst = radio->lineBuffers[*buf];
    StringCopy(dst, sRadioText_BenFern_TodayIs);
    StringAppend(dst, sDayOfWeekNames[dayOfWeek]);
    {
        u8 *end = dst + StringLength(dst);
        *end++ = CHAR_COMMA;
        *end = EOS;
    }
    radio->lines[(*n)++] = radio->lineBuffers[(*buf)++];

    radio->lines[(*n)++] = isEvenDay ? sRadioText_BenFern_JamTo : sRadioText_BenFern_ChillTo;
    radio->lines[(*n)++] = isEvenDay ? sRadioText_BenFern_March : sRadioText_BenFern_Lullaby;
}

static u32 GetOrGenerateLuckyNumber(void)
{
    if (!FlagGet(FLAG_DAILY_LUCKY_NUMBER_SET))
    {
        u16 lo = Random();
        u16 hi = Random() % 2;
        u32 num = ((u32)hi << 16) | lo;
        num %= 100000;
        VarSet(VAR_RADIO_LUCKY_ID, num & 0xFFFF);
        VarSet(VAR_RADIO_LUCKY_ID_HI, num >> 16);
        FlagSet(FLAG_DAILY_LUCKY_NUMBER_SET);
    }
    return ((u32)VarGet(VAR_RADIO_LUCKY_ID_HI) << 16) | VarGet(VAR_RADIO_LUCKY_ID);
}

static void GetOrGenerateBuenaPassword(u32 *outCategory, u32 *outWord)
{
    u16 stored;
    if (!FlagGet(FLAG_DAILY_BUENAS_PASSWORD))
    {
        u32 cat, word;
        do { cat = Random() & 0xF; } while (cat >= NUM_BUENA_CATEGORIES);
        do { word = Random() & 0x3; } while (word >= 3);
        VarSet(VAR_RADIO_BUENAS_PASSWORD, (cat << 4) | word);
        FlagSet(FLAG_DAILY_BUENAS_PASSWORD);
    }
    stored = VarGet(VAR_RADIO_BUENAS_PASSWORD);
    *outCategory = (stored >> 4) & 0xF;
    *outWord = stored & 0xF;
}

static void GenerateStationContent(struct Pokenav_Radio *radio, u8 station)
{
    u32 n = 0;
    u32 buf = 0;
    u8 *dst;

    switch (station)
    {
    case RADIO_STATION_POKEMON_TALK:
        radio->optPhase = OPT_PHASE_INTRO;
        radio->optSegmentCounter = OPT_SEGMENTS_PER_CYCLE;
        GenerateOPTSegment(radio);
        return;

    case RADIO_STATION_POKEDEX_SHOW:
    {
        enum NationalDexOrder natDex;
        u16 species;
        u32 caughtCount = 0;
        u32 pick, seen;

        for (natDex = 1; natDex <= NATIONAL_DEX_COUNT; natDex++)
        {
            if (GetSetPokedexFlag(natDex, FLAG_GET_CAUGHT))
                caughtCount++;
        }

        if (caughtCount > 0)
        {
            pick = Random() % caughtCount;
            seen = 0;
            for (natDex = 1; natDex <= NATIONAL_DEX_COUNT; natDex++)
            {
                if (GetSetPokedexFlag(natDex, FLAG_GET_CAUGHT))
                {
                    if (seen == pick)
                        break;
                    seen++;
                }
            }

            species = NationalPokedexNumToSpecies(natDex);
            if (species != SPECIES_NONE)
            {
                const u8 *speciesName = GetSpeciesName(species);
                const u8 *dexText = GetSpeciesPokedexDescription(species);

                radio->lines[n++] = sRadioText_PokedexShow_Intro;

                dst = radio->lineBuffers[buf];
                StringCopy(dst, sRadioText_PokedexShow_TodaysPrefix);
                StringAppend(dst, speciesName);
                {
                    u8 *end = dst + StringLength(dst);
                    *end++ = CHAR_EXCL_MARK;
                    *end = EOS;
                }
                radio->lines[n++] = radio->lineBuffers[buf++];

                if (dexText != NULL)
                    WrapDexTextIntoLines(radio, dexText, &n, &buf);
            }
        }
        break;
    }

    case RADIO_STATION_POKEMON_MUSIC:
        GeneratePokemonMusicContent(radio, &n, &buf, TRUE);
        break;

    case RADIO_STATION_LETS_ALL_SING:
        GeneratePokemonMusicContent(radio, &n, &buf, FALSE);
        break;

    case RADIO_STATION_LUCKY_CHANNEL:
    {
        u32 luckyNum = GetOrGenerateLuckyNumber();

        radio->lines[n++] = sRadioText_LC1;
        radio->lines[n++] = sRadioText_LC2;
        radio->lines[n++] = sRadioText_LC3;
        radio->lines[n++] = sRadioText_LC4;
        radio->lines[n++] = sRadioText_LC5;

        dst = radio->lineBuffers[buf];
        ConvertIntToDecimalStringN(dst, luckyNum, STR_CONV_MODE_LEADING_ZEROS, 5);
        {
            u8 *end = dst + StringLength(dst);
            *end++ = CHAR_EXCL_MARK;
            *end = EOS;
        }
        radio->lines[n++] = radio->lineBuffers[buf++];

        radio->lines[n++] = sRadioText_LC_Repeat;
        radio->lines[n++] = sRadioText_LC5;

        dst = radio->lineBuffers[buf];
        ConvertIntToDecimalStringN(dst, luckyNum, STR_CONV_MODE_LEADING_ZEROS, 5);
        {
            u8 *end = dst + StringLength(dst);
            *end++ = CHAR_EXCL_MARK;
            *end = EOS;
        }
        radio->lines[n++] = radio->lineBuffers[buf++];

        radio->lines[n++] = sRadioText_LC_Match;
        radio->lines[n++] = sRadioText_LC_Tower;

        if (Random() % 2 == 0)
        {
            radio->lines[n++] = sRadioText_LC_Drag1;
            radio->lines[n++] = sRadioText_LC_Drag2;
        }
        break;
    }

    case RADIO_STATION_BUENAS_PASSWORD:
    {
        RtcCalcLocalTime();
        if (GetTimeOfDay() != TIME_NIGHT)
        {
            radio->lines[n++] = sRadioText_BuenaMidnight1;
            radio->lines[n++] = sRadioText_BuenaMidnight2;
            radio->lines[n++] = sRadioText_BuenaMidnight3;
            radio->lines[n++] = sRadioText_BuenaMidnight4;
            radio->lines[n++] = sRadioText_BuenaMidnight5;
            radio->lines[n++] = sRadioText_BuenaMidnight6;
            radio->lines[n++] = sRadioText_BuenaMidnight7;
            radio->lines[n++] = sRadioText_BuenaMidnight8;
            radio->lines[n++] = sRadioText_BuenaMidnight9;
            radio->lines[n++] = sRadioText_BuenaMidnight10;
            radio->lines[n++] = sRadioText_BuenaOffAir;
        }
        else
        {
            u32 category, word;
            GetOrGenerateBuenaPassword(&category, &word);

            radio->lines[n++] = sRadioText_Buena1;
            radio->lines[n++] = sRadioText_Buena2;
            radio->lines[n++] = sRadioText_Buena3;

            dst = radio->lineBuffers[buf];
            GetBuenaPasswordString(gStringVar1, category, word);
            StringExpandPlaceholders(dst, sRadioText_Buena4);
            radio->lines[n++] = radio->lineBuffers[buf++];

            radio->lines[n++] = sRadioText_Buena5;
            radio->lines[n++] = sRadioText_Buena6;
        }
        break;
    }

    case RADIO_STATION_PLACES_AND_PEOPLE:
    {
        bool32 doPeople = (Random() % 2) == 0;

        radio->lines[n++] = sRadioText_PnP_Intro;
        radio->lines[n++] = sRadioText_PnP_Intro2;

        while (n < MAX_RADIO_LINES - 1 && buf < NUM_RADIO_LINE_BUFS)
        {
            if (doPeople)
            {
                u16 trainerId;
                u8 trainerClass;
                bool8 excluded;
                do {
                    trainerId = (Random() % (TRAINERS_COUNT - 1)) + 1;
                    trainerClass = GetTrainerClassFromId(trainerId);
                    excluded = (trainerClass == TRAINER_CLASS_CHAMPION_HNS
                             || trainerClass == TRAINER_CLASS_ELITE_FOUR_HNS
                             || trainerClass == TRAINER_CLASS_LEADER_HNS
                             || trainerClass == TRAINER_CLASS_RIVAL_HNS
                             || trainerClass == TRAINER_CLASS_CHAMPION
                             || trainerClass == TRAINER_CLASS_ELITE_FOUR
                             || trainerClass == TRAINER_CLASS_LEADER
                             || trainerClass == TRAINER_CLASS_RIVAL);
                } while (excluded);

                dst = radio->lineBuffers[buf];
                StringCopy(dst, GetTrainerClassNameFromId(trainerId));
                StringAppend(dst, sRadioText_PnP_Space);
                StringAppend(dst, GetTrainerNameFromId(trainerId));
                radio->lines[n++] = radio->lineBuffers[buf++];
            }
            else
            {
                u8 mapNameBuf[24];
                u16 mapsec = sPnPPlaces[Random() % ARRAY_COUNT(sPnPPlaces)];
                GetMapName(mapNameBuf, mapsec, 0);

                dst = radio->lineBuffers[buf];
                StringCopy(dst, mapNameBuf);
                radio->lines[n++] = radio->lineBuffers[buf++];
            }

            radio->lines[n++] = sRadioText_PnP_PeopleAdj[Random() % ARRAY_COUNT(sRadioText_PnP_PeopleAdj)];

            if (Random() % 256 < 10)
                break;
            doPeople = (Random() % 2) == 0;
        }
        break;
    }

    case RADIO_STATION_ROCKET:
        radio->lines[n++] = sRadioText_Rocket1;
        radio->lines[n++] = sRadioText_Rocket2;
        radio->lines[n++] = sRadioText_Rocket3;
        radio->lines[n++] = sRadioText_Rocket4;
        radio->lines[n++] = sRadioText_Rocket5;
        radio->lines[n++] = sRadioText_Rocket6;
        radio->lines[n++] = sRadioText_Rocket7;
        radio->lines[n++] = sRadioText_Rocket8;
        radio->lines[n++] = sRadioText_Rocket9;
        radio->lines[n++] = sRadioText_Rocket10;
        break;

    case RADIO_STATION_HOENN_SOUND:
        radio->lines[n++] = sRadioText_Hoenn1;
        radio->lines[n++] = sRadioText_Hoenn2;
        radio->lines[n++] = sRadioText_Hoenn3;
        radio->lines[n++] = sRadioText_Hoenn4;
        break;

    case RADIO_STATION_UNOWN:
    case RADIO_STATION_POKE_FLUTE:
    case RADIO_STATION_EVOLUTION:
        break;

    default:
        break;
    }

    radio->numLines = n;
    radio->currentLine = 0;
    radio->scrollTimer = RADIO_SCROLL_DELAY;
    radio->needsScroll = FALSE;
}

// ========================================
// Core radio logic
// ========================================

bool32 PokenavCallback_Init_Radio(void)
{
    struct Pokenav_Radio *radio = AllocSubstruct(POKENAV_SUBSTRUCT_RADIO, sizeof(struct Pokenav_Radio));
    if (!radio)
        return FALSE;

    radio->callback = HandleRadioInput;
    radio->tuningPos = RADIO_TUNING_MIN;
    radio->currentStation = RADIO_STATION_NONE;
    radio->numLines = 0;
    radio->currentLine = 0;
    radio->scrollTimer = 0;
    radio->needsScroll = FALSE;
    radio->currentMusic = GetCurrLocationDefaultMusic();
    return TRUE;
}

s32 GetRadioTuningPos(void)
{
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);
    return radio->tuningPos;
}

u32 GetRadioCallback(void)
{
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);
    return radio->callback();
}

void FreeRadioSubstruct1(void)
{
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);
    if (radio->currentStation == RADIO_STATION_NONE)
        PlayNewMapMusic(GetCurrLocationDefaultMusic());
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RADIO);
}

void CheckRadioStation(void)
{
    u16 music = GetCurrentMapMusic();

    if (music == MUS_HG_RADIO_POKE_FLUTE)
        gSpecialVar_Result = 1;
    else if (music == MUS_HG_RADIO_ROUTE101)
        gSpecialVar_Result = 2;
    else
        gSpecialVar_Result = 0;
}

static bool8 IsPlayerInJohto(void)
{
    u16 mapsec = gMapHeader.regionMapSectionId;
    return (mapsec >= JOHTO_MAPSEC_START && mapsec <= JOHTO_MAPSEC_END);
}

static bool8 IsStationAvailable(u8 station)
{
    switch (station)
    {
    case RADIO_STATION_POKEMON_TALK:
    case RADIO_STATION_POKEDEX_SHOW:
    case RADIO_STATION_POKEMON_MUSIC:
    case RADIO_STATION_LUCKY_CHANNEL:
        return IsPlayerInJohto();

    case RADIO_STATION_BUENAS_PASSWORD:
        return IsPlayerInJohto() && GetTimeOfDay() == TIME_NIGHT;

    case RADIO_STATION_UNOWN:
        return gMapHeader.regionMapSectionId == MAPSEC_RUINS_OF_ALPH;

    case RADIO_STATION_EVOLUTION:
        return !FlagGet(FLAG_HIDE_MAHOGANY_ROCKETS)
            && (gMapHeader.regionMapSectionId == MAPSEC_MAHOGANY_TOWN
             || gMapHeader.regionMapSectionId == MAPSEC_ROUTE_43
             || gMapHeader.regionMapSectionId == MAPSEC_LAKE_OF_RAGE);

    case RADIO_STATION_PLACES_AND_PEOPLE:
    case RADIO_STATION_LETS_ALL_SING:
        return !IsPlayerInJohto() && FlagGet(FLAG_KANTO_RADIO_GOT);

    case RADIO_STATION_POKE_FLUTE:
        return !IsPlayerInJohto() && FlagGet(FLAG_KANTO_RADIO_GOT);

    case RADIO_STATION_HOENN_SOUND:
        return !IsPlayerInJohto() && FlagGet(FLAG_KANTO_RADIO_GOT);

    default:
        return TRUE;
    }
}

static u8 FindStation(s32 tuningPos)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sRadioChannels); i++)
    {
        if (sRadioChannels[i].tuningPos == tuningPos)
        {
            u8 station = sRadioChannels[i].station;

            // OPT frequency is shared: morning = Pokedex Show, else = OPT
            if (station == RADIO_STATION_POKEMON_TALK)
            {
                if (GetTimeOfDay() == TIME_MORNING)
                    station = RADIO_STATION_POKEDEX_SHOW;
            }

            if (!IsStationAvailable(station))
                return RADIO_STATION_NONE;

            // Rocket takeover overrides normal Johto stations
            // but not location-locked ones (Unown, Poke Flute, Evolution)
            if (!FlagGet(FLAG_HIDE_GOLDENROD_ROCKETS)
                && station != RADIO_STATION_UNOWN
                && station != RADIO_STATION_POKE_FLUTE
                && station != RADIO_STATION_EVOLUTION
                && station != RADIO_STATION_PLACES_AND_PEOPLE
                && station != RADIO_STATION_LETS_ALL_SING
                && station != RADIO_STATION_HOENN_SOUND)
            {
                return RADIO_STATION_ROCKET;
            }

            return station;
        }
    }
    return RADIO_STATION_NONE;
}

static const u8 *GetStationName(u8 station)
{
    u32 i;
    if (station == RADIO_STATION_NONE)
        return sRadioText_NoStation;
    if (station == RADIO_STATION_ROCKET)
        return sRadioStationName_Rocket;
    if (station == RADIO_STATION_POKEDEX_SHOW)
        return sRadioStationName_PokedexShow;
    for (i = 0; i < ARRAY_COUNT(sRadioChannels); i++)
    {
        if (sRadioChannels[i].station == station)
            return sRadioChannels[i].name;
    }
    return sRadioText_NoStation;
}

static void PrintStationName(struct Pokenav_RadioGfx *gfx, u8 station)
{
    const u8 *name = GetStationName(station);
    u32 width = GetStringWidth(FONT_NORMAL, name, -1);
    u32 windowWidth = 19 * 8;

    FillWindowPixelBuffer(gfx->stationNameWindowId, PIXEL_FILL(0));
    AddTextPrinterParameterized3(gfx->stationNameWindowId, FONT_NORMAL,
        (windowWidth - width) / 2, 1, sStationNameTextColors, TEXT_SKIP_DRAW, name);
    CopyWindowToVram(gfx->stationNameWindowId, COPYWIN_FULL);
}

static void PrintRadioText(struct Pokenav_RadioGfx *gfx, const u8 *text)
{
    FillWindowPixelBuffer(gfx->radioTextWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized3(gfx->radioTextWindowId, FONT_NORMAL,
        2, RADIO_LINE_HEIGHT + 1, sRadioTextColors, TEXT_SKIP_DRAW, text);
    CopyWindowToVram(gfx->radioTextWindowId, COPYWIN_GFX);
}

static void ClearRadioText(struct Pokenav_RadioGfx *gfx)
{
    FillWindowPixelBuffer(gfx->radioTextWindowId, PIXEL_FILL(1));
    CopyWindowToVram(gfx->radioTextWindowId, COPYWIN_GFX);
}

static u32 HandleRadioInput(void)
{
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        radio->callback = GetExitRadioMenuId;
        return POKENAV_RADIO_FUNC_EXIT;
    }

    if (radio->numLines > 0)
    {
        if (radio->scrollTimer > 0)
            radio->scrollTimer--;
        else
        {
            radio->scrollTimer = RADIO_SCROLL_DELAY;
            radio->currentLine++;
            if (radio->currentLine >= radio->numLines)
            {
                if (radio->currentStation == RADIO_STATION_POKEMON_TALK)
                {
                    GenerateOPTSegment(radio);
                    return POKENAV_RADIO_FUNC_SCROLL;
                }
                if (radio->currentStation == RADIO_STATION_BUENAS_PASSWORD)
                {
                    RtcCalcLocalTime();
                    if (GetTimeOfDay() != TIME_NIGHT)
                    {
                        GenerateStationContent(radio, RADIO_STATION_BUENAS_PASSWORD);
                        return POKENAV_RADIO_FUNC_SCROLL;
                    }
                }
                radio->currentLine = 0;
            }
            return POKENAV_RADIO_FUNC_SCROLL;
        }
    }

    if (JOY_HELD(DPAD_RIGHT) || JOY_HELD(DPAD_LEFT))
    {
        if (++radio->tuneDelay < 3)
            return POKENAV_RADIO_FUNC_NONE;
        radio->tuneDelay = 0;

        if (JOY_HELD(DPAD_RIGHT) && radio->tuningPos < RADIO_TUNING_MAX)
        {
            radio->tuningPos += RADIO_TUNING_STEP;
            radio->currentStation = FindStation(radio->tuningPos);
            return POKENAV_RADIO_FUNC_TUNE;
        }
        else if (JOY_HELD(DPAD_LEFT) && radio->tuningPos > RADIO_TUNING_MIN)
        {
            radio->tuningPos -= RADIO_TUNING_STEP;
            radio->currentStation = FindStation(radio->tuningPos);
            return POKENAV_RADIO_FUNC_TUNE;
        }
    }
    else
    {
        radio->tuneDelay = 0;
    }

    return POKENAV_RADIO_FUNC_NONE;
}

static u32 GetExitRadioMenuId(void)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_MAP;
}

bool32 OpenPokenavRadio(void)
{
    struct Pokenav_RadioGfx *gfx = AllocSubstruct(POKENAV_SUBSTRUCT_RADIO_GFX, sizeof(struct Pokenav_RadioGfx));
    if (!gfx)
        return FALSE;

    gfx->loopedTaskId = CreateLoopedTask(LoopedTask_OpenRadio, 1);
    gfx->isTaskActiveCB = GetCurrentRadioLoopedTaskActive;
    return TRUE;
}

void CreateRadioLoopedTask(s32 index)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    gfx->loopedTaskId = CreateLoopedTask(sRadioLoopTaskFuncs[index], 1);
    gfx->isTaskActiveCB = GetCurrentRadioLoopedTaskActive;
}

bool32 IsRadioLoopedTaskActive(void)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    return gfx->isTaskActiveCB();
}

void FreeRadioSubstruct2(void)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    if (gfx->dialSprite)
        DestroySprite(gfx->dialSprite);
    FreeSpriteTilesByTag(GFXTAG_RADIO_DIAL);
    FreeSpritePaletteByTag(PALTAG_RADIO_DIAL);
    RemoveWindow(gfx->stationNameWindowId);
    RemoveWindow(gfx->radioTextWindowId);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RADIO_GFX);
}

static bool32 GetCurrentRadioLoopedTaskActive(void)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    return IsLoopedTaskActive(gfx->loopedTaskId);
}

static u32 LoopedTask_OpenRadio(s32 state)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    switch (state)
    {
    case 0:
        InitBgTemplates(sRadioBgTemplates, ARRAY_COUNT(sRadioBgTemplates));
        ChangeBgX(2, 0x800, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        DecompressAndCopyTileDataToVram(2, sRadioUI_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(2, gfx->bgTilemapBuffer2);
        CopyToBgTilemapBuffer(2, sRadioUI_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(sRadioUI_Pal, BG_PLTT_ID(2), sizeof(sRadioUI_Pal));
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        BgDmaFill(1, 0, 0, 1);
        SetBgTilemapBuffer(1, gfx->bgTilemapBuffer1);
        FillBgTilemapBufferRect_Palette0(1, 0x1000, 0, 0, 32, 20);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        LoadCompressedSpriteSheet(&sRadioDialSpriteSheet);
        LoadSpritePalette(&sRadioDialSpritePalette);
        {
            u8 spriteId = CreateSprite(&sRadioDialSpriteTemplate, RADIO_DIAL_BASE_X + GetRadioTuningPos(), RADIO_DIAL_Y, 1);
            gfx->dialSprite = &gSprites[spriteId];
        }
        gfx->stationNameWindowId = AddWindow(&sStationNameWindowTemplate);
        PutWindowTilemap(gfx->stationNameWindowId);
        PrintStationName(gfx, RADIO_STATION_NONE);
        gfx->radioTextWindowId = AddWindow(&sRadioTextWindowTemplate);
        LoadPalette(gStandardMenuPalette, BG_PLTT_ID(RADIO_TEXT_PALETTE), PLTT_SIZE_4BPP);
        LoadUserWindowBorderGfx(gfx->radioTextWindowId, RADIO_FRAME_BASE_TILE, BG_PLTT_ID(RADIO_FRAME_PALETTE));
        DrawStdFrameWithCustomTileAndPalette(gfx->radioTextWindowId, FALSE, RADIO_FRAME_BASE_TILE, RADIO_FRAME_PALETTE);
        FillWindowPixelBuffer(gfx->radioTextWindowId, PIXEL_FILL(1));
        PutWindowTilemap(gfx->radioTextWindowId);
        CopyWindowToVram(gfx->radioTextWindowId, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(1);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_TuneRadio(s32 state)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);

    gfx->dialSprite->x = RADIO_DIAL_BASE_X + radio->tuningPos;
    PrintStationName(gfx, radio->currentStation);
    GenerateStationContent(radio, radio->currentStation);

    {
        u16 music;
        if (radio->currentStation != RADIO_STATION_NONE)
        {
            music = sRadioStationMusic[radio->currentStation];
            if (radio->currentStation == RADIO_STATION_POKEMON_MUSIC
                || radio->currentStation == RADIO_STATION_LETS_ALL_SING)
            {
                music = (GetDayOfWeek() % 2 == 0) ? MUS_HG_RADIO_MARCH : MUS_HG_RADIO_LULLABY;
            }
        }
        else
        {
            music = 0;
        }
        if (music != radio->currentMusic)
        {
            if (music != 0)
                PlayNewMapMusic(music);
            else
                StopMapMusic();
            radio->currentMusic = music;
        }
    }

    if (radio->numLines > 0)
    {
        PrintRadioText(gfx, radio->lines[0]);
        radio->needsScroll = TRUE;
    }
    else
    {
        ClearRadioText(gfx);
    }

    return LT_FINISH;
}

static u32 LoopedTask_ScrollRadio(s32 state)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);

    if (!radio->needsScroll)
    {
        FillWindowPixelBuffer(gfx->radioTextWindowId, PIXEL_FILL(1));
        radio->needsScroll = TRUE;
    }
    else
    {
        ScrollWindow(gfx->radioTextWindowId, 0, RADIO_LINE_HEIGHT, PIXEL_FILL(1));
    }
    AddTextPrinterParameterized3(gfx->radioTextWindowId, FONT_NORMAL,
        2, RADIO_LINE_HEIGHT + 1, sRadioTextColors, TEXT_SKIP_DRAW,
        radio->lines[radio->currentLine]);
    CopyWindowToVram(gfx->radioTextWindowId, COPYWIN_GFX);
    return LT_FINISH;
}

static u32 LoopedTask_ExitRadio(s32 state)
{
    switch (state)
    {
    case 0:
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        ShowBg(0);
        SetLeftHeaderSpritesInvisibility();
        SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 2:
        if (MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        HideBg(1);
        HideBg(2);
        HideBg(3);
        return LT_INC_AND_PAUSE;
    }
    return LT_FINISH;
}
