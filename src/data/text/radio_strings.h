// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("OAK's POKéMON Talk");
static const u8 sRadioStationName_PokedexShow[]     = _("POKéDEX Show");
static const u8 sRadioStationName_PokemonMusic[]    = _("POKéMON Music");
static const u8 sRadioStationName_LuckyChannel[]    = _("Lucky Channel");
static const u8 sRadioStationName_BuenasPassword[]  = _("BUENA'S PASSWORD");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("Places & People");
static const u8 sRadioStationName_LetsAllSing[]     = _("Let's All Sing!");
static const u8 sRadioStationName_PokeFlute[]       = _("POKé FLUTE");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("MARY: PROF.OAK's POKéMON TALK!");
static const u8 sRadioText_OPT_WithMeMary[] = _("With me, MARY!");
static const u8 sRadioText_OPT_OakPrefix[] = _("OAK: ");
static const u8 sRadioText_OPT_SeenAround[] = _("may be seen around here.");
static const u8 sRadioText_OPT_MaryPrefix[] = _("MARY: ");
static const u8 sRadioText_OPT_MaryIs[] = _("'s ");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("sweet and adorably");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("wiggly and slickly");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("aptly named and");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("undeniably kind of");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("so, so unbearably");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("wow, impressively");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("almost poisonously");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("ooh, so sensually");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("so mischievously");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("so very topically");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("sure addictively");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("looks in water is");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("evolution must be");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("provocatively");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("so flipped out and");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("heart-meltingly");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("cute.");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("weird.");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("pleasant.");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("bold, sort of.");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("frightening.");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("suave & debonair!");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("powerful.");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("exciting.");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("groovy!");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("inspiring.");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("friendly.");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("hot, hot, hot!");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("stimulating.");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("guarded.");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("lovely.");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("speedy.");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("BEN: POKéMON MUSIC CHANNEL!");
static const u8 sRadioText_BenIntro2[] = _("It's me, DJ BEN!");
static const u8 sRadioText_FernIntro[] = _("FERN: POKéMUSIC!");
static const u8 sRadioText_FernIntro2[] = _("With DJ FERN!");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("Today's ");
static const u8 sRadioText_BenFern_JamTo[] = _("so let us jam to");
static const u8 sRadioText_BenFern_ChillTo[] = _("so chill out to");
static const u8 sRadioText_BenFern_March[] = _("POKéMON March!");
static const u8 sRadioText_BenFern_Lullaby[] = _("POKéMON Lullaby!");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("REED: Yeehaw! How y'all doin'");
static const u8 sRadioText_LC2[] = _("now? Whether you're up or way");
static const u8 sRadioText_LC3[] = _("down low, don't you miss the");
static const u8 sRadioText_LC4[] = _("LUCKY NUMBER SHOW!");
static const u8 sRadioText_LC5[] = _("This week's Lucky Number is");
// "{number}!" built dynamically
static const u8 sRadioText_LC6[] = _("I'll repeat that! Match it");
static const u8 sRadioText_LC7[] = _("and go to the RADIO TOWER!");
static const u8 sRadioText_LC_Drag[] = _("…Repeating gets old…");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("PLACES AND PEOPLE! Brought");
static const u8 sRadioText_PnP_Intro2[] = _("to you by me, DJ LILY!");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("is cute.");
static const u8 sRadioText_PnP_Lazy[]       = _("is sort of lazy.");
static const u8 sRadioText_PnP_Happy[]      = _("is always happy.");
static const u8 sRadioText_PnP_Noisy[]      = _("is quite noisy.");
static const u8 sRadioText_PnP_Precocious[] = _("is precocious.");
static const u8 sRadioText_PnP_Bold[]       = _("is somewhat bold.");
static const u8 sRadioText_PnP_Picky[]      = _("is too picky!");
static const u8 sRadioText_PnP_SortOfOK[]   = _("is sort of OK.");
static const u8 sRadioText_PnP_SoSo[]       = _("is just so-so.");
static const u8 sRadioText_PnP_Great[]       = _("is actually great.");
static const u8 sRadioText_PnP_MyType[]      = _("is just my type.");
static const u8 sRadioText_PnP_Cool[]        = _("is so cool, no?");
static const u8 sRadioText_PnP_Inspiring[]   = _("is inspiring!");
static const u8 sRadioText_PnP_Weird[]       = _("is kind of weird.");
static const u8 sRadioText_PnP_RightForMe[]  = _("is right for me?");
static const u8 sRadioText_PnP_Odd[]         = _("is definitely odd!");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioText_Rocket1[]  = _("… …Ahem, we are TEAM ROCKET!");
static const u8 sRadioText_Rocket2[]  = _("After three years of preparation,");
static const u8 sRadioText_Rocket3[]  = _("we have risen from the ashes!");
static const u8 sRadioText_Rocket4[]  = _("GIOVANNI! Can you hear?");
static const u8 sRadioText_Rocket5[]  = _("We did it! Where is our boss?");
static const u8 sRadioText_Rocket6[]  = _("Is he listening?");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("BUENA: BUENA here!");
static const u8 sRadioText_Buena2[] = _("Today's password!");
static const u8 sRadioText_Buena3[] = _("Let me think… It's");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1}!");
static const u8 sRadioText_Buena5[] = _("Don't forget it! I'm in");
static const u8 sRadioText_Buena6[] = _("GOLDENROD's RADIO TOWER!");

// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("NEW BARK TOWN");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("CHERRYGROVE CITY");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("AZALEA TOWN");
static const u8 sRadioBuenaPassword_Flying[]          = _("FLYING");
static const u8 sRadioBuenaPassword_Bug[]             = _("BUG");
static const u8 sRadioBuenaPassword_Grass[]           = _("GRASS");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("POKéMON Talk");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("POKéMON Music");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("Lucky Channel");

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
