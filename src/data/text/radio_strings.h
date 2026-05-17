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
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("OAK's POKéDEX SHOW!");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("OAK: Today's POKéMON is ");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("MARY: PROF.OAK's POKéMON TALK!");
static const u8 sRadioText_OPT_WithMeMary[] = _("With me, MARY!");
static const u8 sRadioText_OPT_OakPrefix[] = _("OAK: ");
static const u8 sRadioText_OPT_SeenAround[] = _("may be seen around");
static const u8 sRadioText_OPT_MaryPrefix[] = _("MARY: ");
static const u8 sRadioText_OPT_MaryIs[] = _("'s ");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("POKéMON Channel");

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
static const u8 sRadioText_PnP_Space[] = _(" ");

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

static const u8 sRadioStationName_Rocket[] = _("TEAM ROCKET");
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

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("MARY: Tonight, a rare moonlight");
static const u8 sOPT_Report_Clefairy_1[]  = _("moment on POKéMON TALK!");
static const u8 sOPT_Report_Clefairy_2[]  = _("OAK: We're spotlighting the");
static const u8 sOPT_Report_Clefairy_3[]  = _("mystical CLEFAIRY!");
static const u8 sOPT_Report_Clefairy_4[]  = _("They gather at MT.MOON");
static const u8 sOPT_Report_Clefairy_5[]  = _("under full moons.");
static const u8 sOPT_Report_Clefairy_6[]  = _("MARY: They DANCE in circles!");
static const u8 sOPT_Report_Clefairy_7[]  = _("So adorably weird!");
static const u8 sOPT_Report_Clefairy_8[]  = _("OAK: A timeless mystery");
static const u8 sOPT_Report_Clefairy_9[]  = _("and a sight to behold!");

static const u8 sOPT_Report_Lapras_0[]  = _("MARY: A gentle giant takes");
static const u8 sOPT_Report_Lapras_1[]  = _("the stage on today's show!");
static const u8 sOPT_Report_Lapras_2[]  = _("OAK: It's the ocean ferry,");
static const u8 sOPT_Report_Lapras_3[]  = _("our beloved LAPRAS!");
static const u8 sOPT_Report_Lapras_4[]  = _("Seen in UNION CAVE, but only");
static const u8 sOPT_Report_Lapras_5[]  = _("on Evenings. How curious!");
static const u8 sOPT_Report_Lapras_6[]  = _("MARY: So rare and peaceful!");
static const u8 sOPT_Report_Lapras_7[]  = _("And it sings, too!");
static const u8 sOPT_Report_Lapras_8[]  = _("OAK: Some say its songs calm");
static const u8 sOPT_Report_Lapras_9[]  = _("the soul of the sea.");

static const u8 sOPT_Report_Ampharos_0[]  = _("MARY: Welcome back, everyone!");
static const u8 sOPT_Report_Ampharos_1[]  = _("Time for POKéMON TALK!");
static const u8 sOPT_Report_Ampharos_2[]  = _("OAK: Let's shine a light on");
static const u8 sOPT_Report_Ampharos_3[]  = _("our friend AMPHAROS!");
static const u8 sOPT_Report_Ampharos_4[]  = _("Its bright tail glows through");
static const u8 sOPT_Report_Ampharos_5[]  = _("fog to guide lost folks.");
static const u8 sOPT_Report_Ampharos_6[]  = _("MARY: Powerful, elegant,");
static const u8 sOPT_Report_Ampharos_7[]  = _("and undeniably friendly!");
static const u8 sOPT_Report_Ampharos_8[]  = _("OAK: A key part of many");
static const u8 sOPT_Report_Ampharos_9[]  = _("lighthouse stories!");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("MARY: Up next, a real oddball");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("on ROUTE 36...");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("OAK: SUDOWOODO! Looks like a");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("tree, but isn't one!");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("It blocks the road and won't");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("budge without water.");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("MARY: It only reacts to a");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("SQUIRTBOTTLE!");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("OAK: That's no bush, it's a");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("ROCK-type in disguise!");

static const u8 sOPT_Report_RedGyarados_0[]  = _("MARY: Today's story is a");
static const u8 sOPT_Report_RedGyarados_1[]  = _("shocking one from JOHTO!");
static const u8 sOPT_Report_RedGyarados_2[]  = _("OAK: Trainers spotted a RED");
static const u8 sOPT_Report_RedGyarados_3[]  = _("GYARADOS at LAKE OF RAGE!");
static const u8 sOPT_Report_RedGyarados_4[]  = _("Unlike the usual blue ones,");
static const u8 sOPT_Report_RedGyarados_5[]  = _("this one's bright crimson!");
static const u8 sOPT_Report_RedGyarados_6[]  = _("MARY: People say it's linked");
static const u8 sOPT_Report_RedGyarados_7[]  = _("to some strange radio waves!");
static const u8 sOPT_Report_RedGyarados_8[]  = _("OAK: A mysterious evolution…");
static const u8 sOPT_Report_RedGyarados_9[]  = _("Possibly unnatural.");

static const u8 sOPT_Report_Unown_0[]  = _("MARY: Ever visited the RUINS");
static const u8 sOPT_Report_Unown_1[]  = _("OF ALPH? Spooky stuff!");
static const u8 sOPT_Report_Unown_2[]  = _("OAK: Strange symbols line the");
static const u8 sOPT_Report_Unown_3[]  = _("walls, like ancient runes.");
static const u8 sOPT_Report_Unown_4[]  = _("Inside, you'll find UNOWN…");
static const u8 sOPT_Report_Unown_5[]  = _("each shaped like letters!");
static const u8 sOPT_Report_Unown_6[]  = _("MARY: They spell things,");
static const u8 sOPT_Report_Unown_7[]  = _("maybe? Or just freak us out!");
static const u8 sOPT_Report_Unown_8[]  = _("OAK: A true puzzle of nature,");
static const u8 sOPT_Report_Unown_9[]  = _("still unsolved to this day.");

static const u8 sOPT_Report_Snubbull_0[]  = _("MARY: GOLDENROD residents are");
static const u8 sOPT_Report_Snubbull_1[]  = _("searching high and low!");
static const u8 sOPT_Report_Snubbull_2[]  = _("OAK: A SNUBBULL has gone rogue");
static const u8 sOPT_Report_Snubbull_3[]  = _("and is on the run!");
static const u8 sOPT_Report_Snubbull_4[]  = _("Usually shy and fussy, it's");
static const u8 sOPT_Report_Snubbull_5[]  = _("been seen near the station.");
static const u8 sOPT_Report_Snubbull_6[]  = _("MARY: Maybe it's chasing");
static const u8 sOPT_Report_Snubbull_7[]  = _("love… or just adventure!");
static const u8 sOPT_Report_Snubbull_8[]  = _("OAK: Keep your eyes peeled,");
static const u8 sOPT_Report_Snubbull_9[]  = _("and your leash ready.");

static const u8 sOPT_Report_Slowpoke_0[]  = _("MARY: Big news from AZALEA");
static const u8 sOPT_Report_Slowpoke_1[]  = _("TOWN this week!");
static const u8 sOPT_Report_Slowpoke_2[]  = _("OAK: SLOWPOKE have returned");
static const u8 sOPT_Report_Slowpoke_3[]  = _("to their well after a crisis!");
static const u8 sOPT_Report_Slowpoke_4[]  = _("TEAM ROCKET had been cutting");
static const u8 sOPT_Report_Slowpoke_5[]  = _("off their tails! Horrible!");
static const u8 sOPT_Report_Slowpoke_6[]  = _("MARY: But a brave young");
static const u8 sOPT_Report_Slowpoke_7[]  = _("trainer shut them down!");
static const u8 sOPT_Report_Slowpoke_8[]  = _("OAK: The SLOWPOKE are safe");
static const u8 sOPT_Report_Slowpoke_9[]  = _("and happily dozing again.");

static const u8 sOPT_Report_LavenderTower_0[]  = _("MARY: LAVENDER TOWN's tower");
static const u8 sOPT_Report_LavenderTower_1[]  = _("has changed tunes!");
static const u8 sOPT_Report_LavenderTower_2[]  = _("OAK: The old ghost tower is");
static const u8 sOPT_Report_LavenderTower_3[]  = _("now a RADIO STATION!");
static const u8 sOPT_Report_LavenderTower_4[]  = _("Some locals say it still");
static const u8 sOPT_Report_LavenderTower_5[]  = _("feels… spooky.");
static const u8 sOPT_Report_LavenderTower_6[]  = _("MARY: I swear I saw a GASTLY");
static const u8 sOPT_Report_LavenderTower_7[]  = _("near the mic booth!");
static const u8 sOPT_Report_LavenderTower_8[]  = _("OAK: Might be static…");
static const u8 sOPT_Report_LavenderTower_9[]  = _("or specters!");

static const u8 sOPT_Report_Tentacruel_0[]  = _("MARY: Weird news from the");
static const u8 sOPT_Report_Tentacruel_1[]  = _("WHIRL ISLANDS today!");
static const u8 sOPT_Report_Tentacruel_2[]  = _("OAK: TENTACRUEL have been");
static const u8 sOPT_Report_Tentacruel_3[]  = _("surrounding cave entrances!");
static const u8 sOPT_Report_Tentacruel_4[]  = _("They're massive, and acting");
static const u8 sOPT_Report_Tentacruel_5[]  = _("almost territorial.");
static const u8 sOPT_Report_Tentacruel_6[]  = _("MARY: They block the way");
static const u8 sOPT_Report_Tentacruel_7[]  = _("without attacking…");
static const u8 sOPT_Report_Tentacruel_8[]  = _("OAK: As if guarding something");
static const u8 sOPT_Report_Tentacruel_9[]  = _("deep beneath the waves.");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
