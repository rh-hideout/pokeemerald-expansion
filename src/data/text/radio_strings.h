// Radio station strings ported from pokecrystal
// Source: pokecrystal/data/text/common_1.asm + engine/pokegear/pokegear.asm

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// Pokemon Channel name for the radio UI restart
static const u8 sRadioText_PokemonChannel[] = _("POKéMON");

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

// Intro
static const u8 sRadioText_OPT_Intro1[] = _("MARY: PROF.OAK's");
static const u8 sRadioText_OPT_Intro2[] = _("POKéMON TALK!");
static const u8 sRadioText_OPT_Intro3[] = _("With me, MARY!");

// Oak describes a Pokemon on a route
// Uses {STR_VAR_1} for Pokemon name, {STR_VAR_2} for route name
static const u8 sRadioText_OPT_Oak1[]   = _("OAK: {STR_VAR_1}");
static const u8 sRadioText_OPT_Oak2[]   = _("may be seen around");
static const u8 sRadioText_OPT_Oak3[]   = _("{STR_VAR_1}.");

// Mary's reaction
// Uses {STR_VAR_1} for Pokemon name
static const u8 sRadioText_OPT_Mary1[]  = _("MARY: {STR_VAR_1}'s");

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
// POKéDEX Show
// Uses {STR_VAR_1} for Pokemon name / dex entry text
// ==========================================================

static const u8 sRadioText_PokedexShow[] = _("{STR_VAR_1}");

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

// Ben's intro
static const u8 sRadioText_BenIntro1[] = _("BEN: POKéMON MUSIC");
static const u8 sRadioText_BenIntro2[] = _("CHANNEL!");
static const u8 sRadioText_BenIntro3[] = _("It's me, DJ BEN!");

// Fern's intro
static const u8 sRadioText_FernIntro1[] = _("FERN: POKéMUSIC!");
static const u8 sRadioText_FernIntro2[] = _("With DJ FERN!");

// Shared lines
// Uses {STR_VAR_1} for day of week
static const u8 sRadioText_BenFern1[]  = _("Today's {STR_VAR_1},");
static const u8 sRadioText_BenFern2A[] = _("so let us jam to");
static const u8 sRadioText_BenFern2B[] = _("so chill out to");
static const u8 sRadioText_BenFern3A[] = _("POKéMON March!");
static const u8 sRadioText_BenFern3B[] = _("POKéMON Lullaby!");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[]     = _("REED: Yeehaw! How");
static const u8 sRadioText_LC2[]     = _("y'all doin' now?");
static const u8 sRadioText_LC3[]     = _("Whether you're up");
static const u8 sRadioText_LC4[]     = _("or way down low,");
static const u8 sRadioText_LC5[]     = _("don't you miss the");
static const u8 sRadioText_LC6[]     = _("LUCKY NUMBER SHOW!");
static const u8 sRadioText_LC7[]     = _("This week's Lucky");
// Uses {STR_VAR_1} for the lucky number
static const u8 sRadioText_LC8[]     = _("Number is {STR_VAR_1}!");
static const u8 sRadioText_LC9[]     = _("I'll repeat that!");
static const u8 sRadioText_LC10[]    = _("Match it and go to");
static const u8 sRadioText_LC11[]    = _("the RADIO TOWER!");
static const u8 sRadioText_LC_Drag1[] = _("…Repeating myself");
static const u8 sRadioText_LC_Drag2[] = _("gets to be a drag…");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP1[] = _("PLACES AND PEOPLE!");
static const u8 sRadioText_PnP2[] = _("Brought to you by");
static const u8 sRadioText_PnP3[] = _("me, DJ LILY!");

// Uses {STR_VAR_1} for trainer class, {STR_VAR_2} for name
static const u8 sRadioText_PnP4[] = _("{STR_VAR_2} {STR_VAR_1}");

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

// Places description
// Uses {STR_VAR_1} for place name
static const u8 sRadioText_PnP5[] = _("{STR_VAR_1}");

// Places adjectives (same pool reused for places)
// (Crystal uses the same 16 adjectives for places as for people)

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioText_Rocket1[]  = _("… …Ahem, we are");
static const u8 sRadioText_Rocket2[]  = _("TEAM ROCKET!");
static const u8 sRadioText_Rocket3[]  = _("After three years");
static const u8 sRadioText_Rocket4[]  = _("of preparation, we");
static const u8 sRadioText_Rocket5[]  = _("have risen again");
static const u8 sRadioText_Rocket6[]  = _("from the ashes!");
static const u8 sRadioText_Rocket7[]  = _("GIOVANNI! Can you");
static const u8 sRadioText_Rocket8[]  = _("hear? We did it!");
static const u8 sRadioText_Rocket9[]  = _("Where is our boss?");
static const u8 sRadioText_Rocket10[] = _("Is he listening?");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[]  = _("BUENA: BUENA here!");
static const u8 sRadioText_Buena2[]  = _("Today's password!");
static const u8 sRadioText_Buena3[]  = _("Let me think… It's");
// Uses {STR_VAR_1} for the password
static const u8 sRadioText_Buena4[]  = _("{STR_VAR_1}!");
static const u8 sRadioText_Buena5[]  = _("Don't forget it!");
static const u8 sRadioText_Buena6[]  = _("I'm in GOLDENROD's");
static const u8 sRadioText_Buena7[]  = _("RADIO TOWER!");

// Midnight signoff
static const u8 sRadioText_BuenaMidnight1[]  = _("BUENA: Oh my…");
static const u8 sRadioText_BuenaMidnight2[]  = _("It's midnight! I");
static const u8 sRadioText_BuenaMidnight3[]  = _("have to shut down!");
static const u8 sRadioText_BuenaMidnight4[]  = _("Thanks for tuning");
static const u8 sRadioText_BuenaMidnight5[]  = _("in to the end! But");
static const u8 sRadioText_BuenaMidnight6[]  = _("don't stay up too");
static const u8 sRadioText_BuenaMidnight7[]  = _("late! Presented to");
static const u8 sRadioText_BuenaMidnight8[]  = _("you by DJ BUENA!");
static const u8 sRadioText_BuenaMidnight9[]  = _("I'm outta here!");
static const u8 sRadioText_BuenaMidnight10[] = _("…");

// Off the air
static const u8 sRadioText_BuenaOffAir[]     = _("");

// ==========================================================
// Buena's Password Categories & Options
// (from data/radio/buenas_passwords.asm)
// Each category has 3 password options; one is chosen daily.
// The string type tells the game how to resolve the name
// (MON = species name, ITEM = item name, MOVE = move name,
//  STRING = literal inline string).
// ==========================================================

// Category: Johto Starters   — CYNDAQUIL, TOTODILE, CHIKORITA
// Category: Beverages         — FRESH WATER, SODA POP, LEMONADE
// Category: Healing Items     — POTION, ANTIDOTE, PARLYZ HEAL
// Category: Balls             — POKé BALL, GREAT BALL, ULTRA BALL
// Category: Pokemon 1         — PIKACHU, RATTATA, GEODUDE
// Category: Pokemon 2         — HOOTHOOT, SPINARAK, DROWZEE
// Category: Johto Towns       — "NEW BARK TOWN", "CHERRYGROVE CITY", "AZALEA TOWN"
// Category: Types             — "FLYING", "BUG", "GRASS"
// Category: Moves             — TACKLE, GROWL, MUD-SLAP
// Category: X Items           — X ATTACK, X DEFEND, X SPEED
// Category: Radio Stations    — "POKéMON Talk", "POKéMON Music", "Lucky Channel"

static const u8 sRadioBuenaPassword_NewBarkTown[]    = _("NEW BARK TOWN");
static const u8 sRadioBuenaPassword_CherrygroveCity[] = _("CHERRYGROVE CITY");
static const u8 sRadioBuenaPassword_AzaleaTown[]     = _("AZALEA TOWN");
static const u8 sRadioBuenaPassword_Flying[]         = _("FLYING");
static const u8 sRadioBuenaPassword_Bug[]            = _("BUG");
static const u8 sRadioBuenaPassword_Grass[]          = _("GRASS");
static const u8 sRadioBuenaPassword_PkmnTalk[]       = _("POKéMON Talk");
static const u8 sRadioBuenaPassword_PkmnMusic[]      = _("POKéMON Music");
static const u8 sRadioBuenaPassword_LuckyChannel[]   = _("Lucky Channel");

// ==========================================================
// Oak's Pokemon Talk — Route list
// (from data/radio/oaks_pkmn_talk_routes.asm)
// Routes whose wild encounters Oak can discuss.
// These will need to be mapped to HnS map IDs.
// ==========================================================

// Crystal routes: 29, 46, 30, 32, 34, 35, 37, 38, 39, 42, 43, 44, 45, 36, 31

// ==========================================================
// Places & People — Location list
// (from data/radio/pnp_places.asm)
// Landmarks the Places segment can describe.
// ==========================================================

// Crystal places: PALLET_TOWN, ROUTE_22, PEWTER_CITY, CERULEAN_CITY,
//                 ROUTE_12, ROUTE_11, ROUTE_16, ROUTE_14, CINNABAR_ISLAND

// ==========================================================
// Places & People — Hidden trainers
// (from data/radio/pnp_hidden_people.asm)
// Trainer classes excluded from the People segment.
// ==========================================================

// Always hidden: WILL, BRUNO, KAREN, KOGA, CHAMPION
// Hidden until E4 beaten: BROCK, MISTY, LT_SURGE, ERIKA, JANINE, SABRINA, BLAINE, BLUE
// Hidden until Kanto beaten: RIVAL1, POKEMON_PROF, CAL, RIVAL2, RED

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
