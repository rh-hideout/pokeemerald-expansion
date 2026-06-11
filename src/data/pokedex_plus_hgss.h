static const u8 *const sTextsHGSS_Stats_Buttons[2] =
{
    COMPOUND_STRING("{A_BUTTON}TOGGLE   {DPAD_UPDOWN}MOVES"),
    COMPOUND_STRING("{A_BUTTON}Toggle   {DPAD_UPDOWN}Moves")
};

static const u8 *const sTextsHGSS_Stats_HP[2] =
{
    COMPOUND_STRING("HP"),
    COMPOUND_STRING("HP")
};

static const u8 *const sTextsHGSS_Stats_Attack[2] =
{
    COMPOUND_STRING("ATK"),
    COMPOUND_STRING("Atk")
};

static const u8 *const sTextsHGSS_Stats_Defense[2] =
{
    COMPOUND_STRING("DEF"),
    COMPOUND_STRING("Def")
};

static const u8 *const sTextsHGSS_Stats_Speed[2] =
{
    COMPOUND_STRING("SPE"),
    COMPOUND_STRING("Spe")
};

static const u8 *const sTextsHGSS_Stats_SpAttack[2] =
{
    COMPOUND_STRING("SP.A"),
    COMPOUND_STRING("Sp.A")
};

static const u8 *const sTextsHGSS_Stats_SpDefense[2] =
{
    COMPOUND_STRING("SP.D"),
    COMPOUND_STRING("Sp.D")
};

static const u8 *const sTextsHGSS_MoveEgg[2] =
{
    COMPOUND_STRING("EGG"),
    COMPOUND_STRING("Egg")
};

static const u8 *const sTextsHGSS_MoveLevel[2] =
{
    COMPOUND_STRING("LV."),
    gText_Level
};

static const u8 *const sTextsHGSS_MoveTutor[2] =
{
    COMPOUND_STRING("TUTOR"),
    COMPOUND_STRING("Tutor")
};

static const u8 *const sTextsHGSS_Stats_CatchRate[2] =
{
    COMPOUND_STRING("CATCH%:"),
    COMPOUND_STRING("Catch%:")
};

static const u8 *const sTextsHGSS_Stats_CatchRate_Legend[2] =
{
    COMPOUND_STRING("LEGENDARY"),
    COMPOUND_STRING("Legendary")
};

static const u8 *const sTextsHGSS_Stats_CatchRate_VeryHard[2] =
{
    COMPOUND_STRING("VERY HARD"),
    COMPOUND_STRING("Very Hard")
};

static const u8 *const sTextsHGSS_Stats_CatchRate_Difficult[2] =
{
    COMPOUND_STRING("DIFFICULT"),
    COMPOUND_STRING("Difficult")
};

static const u8 *const sTextsHGSS_Stats_CatchRate_Medium[2] =
{
    COMPOUND_STRING("MEDIUM"),
    COMPOUND_STRING("Medium")
};

static const u8 *const sTextsHGSS_Stats_CatchRate_Relaxed[2] =
{
    COMPOUND_STRING("RELAXED"),
    COMPOUND_STRING("Relaxed")
};

static const u8 *const sTextsHGSS_Stats_CatchRate_Easy[2] =
{
    COMPOUND_STRING("EASY"),
    COMPOUND_STRING("Easy")
};

static const u8 *const sTextsHGSS_Stats_ExpYield[2] =
{
    COMPOUND_STRING("EXP YIELD:"),
    COMPOUND_STRING("Exp Yield:")
};

static const u8 *const sTextsHGSS_Stats_EggCycles[2] =
{
    COMPOUND_STRING("EGG CYCLES:"),
    COMPOUND_STRING("Egg Cycles:")
};

static const u8 *const sTextsHGSS_Stats_GrowthRate[2] =
{
    COMPOUND_STRING("GROW:"),
    COMPOUND_STRING("Grow:")
};

static const u8 *const sTextsHGSS_Stats_Friendship[2] =
{
    COMPOUND_STRING("FRIENDSHIP:"),
    COMPOUND_STRING("Friendship:")
};

static const u8 *const sTextsHGSS_Stats_Medium_Fast[2] =
{
    COMPOUND_STRING("MED. FAST"),
    COMPOUND_STRING("Med. Fast")
};

static const u8 *const sTextsHGSS_Stats_Erratic[2] =
{
    COMPOUND_STRING("ERRATIC"),
    COMPOUND_STRING("Erratic")
};

static const u8 *const sTextsHGSS_Stats_Fluctuating[2] =
{
    COMPOUND_STRING("FLUCTUATING"),
    COMPOUND_STRING("Fluctuating")
};

static const u8 *const sTextsHGSS_Stats_Medium_Slow[2] =
{
    COMPOUND_STRING("MED. SLOW"),
    COMPOUND_STRING("Med. Slow")
};

static const u8 *const sTextsHGSS_Stats_Fast[2] =
{
    COMPOUND_STRING("FAST"),
    COMPOUND_STRING("Fast")
};

static const u8 *const sTextsHGSS_Stats_Slow[2] =
{
    COMPOUND_STRING("SLOW"),
    COMPOUND_STRING("Slow")
};

static const u8 *const sTextsHGSS_Stats_EggGroups[2] =
{
    COMPOUND_STRING("EGG GROUPS:"),
    COMPOUND_STRING("Egg Groups:")
};

static const u8 *const sTextsHGSS_EggGroups[NUM_EGG_GROUPS][2] =
{
    [EGG_GROUP_NONE]                = { COMPOUND_STRING("???"),             COMPOUND_STRING("???")              },
    [EGG_GROUP_MONSTER]             = { COMPOUND_STRING("MONSTER"),         COMPOUND_STRING("Monster")          },
    [EGG_GROUP_WATER_1]             = { COMPOUND_STRING("WATER {CIRCLE_1}"),COMPOUND_STRING("Water {CIRCLE_1}") },
    [EGG_GROUP_BUG]                 = { COMPOUND_STRING("BUG"),             COMPOUND_STRING("Bug")              },
    [EGG_GROUP_FLYING]              = { COMPOUND_STRING("FLYING"),          COMPOUND_STRING("Flying")           },
    [EGG_GROUP_FIELD]               = { COMPOUND_STRING("FIELD"),           COMPOUND_STRING("Field")            },
    [EGG_GROUP_FAIRY]               = { COMPOUND_STRING("FAIRY"),           COMPOUND_STRING("Fairy")            },
    [EGG_GROUP_GRASS]               = { COMPOUND_STRING("GRASS"),           COMPOUND_STRING("Grass")            },
    [EGG_GROUP_HUMAN_LIKE]          = { COMPOUND_STRING("HUMANE"),          COMPOUND_STRING("Humane")           },
    [EGG_GROUP_WATER_3]             = { COMPOUND_STRING("WATER {CIRCLE_3}"),COMPOUND_STRING("Water {CIRCLE_3}") },
    [EGG_GROUP_MINERAL]             = { COMPOUND_STRING("MINERAL"),         COMPOUND_STRING("Mineral")          },
    [EGG_GROUP_AMORPHOUS]           = { COMPOUND_STRING("AMORPHOUS"),       COMPOUND_STRING("Amorphous")        },
    [EGG_GROUP_WATER_2]             = { COMPOUND_STRING("WATER {CIRCLE_2}"),COMPOUND_STRING("Water {CIRCLE_2}") },
    [EGG_GROUP_DITTO]               = { COMPOUND_STRING("DITTO"),           COMPOUND_STRING("Ditto")            },
    [EGG_GROUP_DRAGON]              = { COMPOUND_STRING("DRAGON"),          COMPOUND_STRING("Dragon")           },
    [EGG_GROUP_NO_EGGS_DISCOVERED]  = { COMPOUND_STRING("---"),             COMPOUND_STRING("---")              },
};

static const u8 *const sTextsHGSS_Evolutions_Buttons[2] =
{
    COMPOUND_STRING("{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK  {START_BUTTON}FORMs"),
    COMPOUND_STRING("{DPAD_UPDOWN}Evos  {A_BUTTON}Check  {START_BUTTON}Forms")
};

static const u8 *const sTextsHGSS_Forms_Buttons[2] =
{
    COMPOUND_STRING("{A_BUTTON}FORM MODE  {START_BUTTON}EVOs"),
    COMPOUND_STRING("{A_BUTTON}Form Mode  {START_BUTTON}Evos")
};

static const u8 *const sTextsHGSS_Forms_Submenu_Buttons[2] =
{
    COMPOUND_STRING("{DPAD_NONE}FORMs {A_BUTTON}CHECK {START_BUTTON}EVOs"),
    COMPOUND_STRING("{DPAD_NONE}Forms {A_BUTTON}Check {START_BUTTON}Evos")
};

static const u8 *const sTextsHGSS_Evo_PreEvo_Mega[2] =
{
    COMPOUND_STRING("{STR_VAR_1} Mega Evolves with {STR_VAR_2}"),
    COMPOUND_STRING("{STR_VAR_1} Mega Evolves with {STR_VAR_2}")
};

static const u8 *const sTextsHGSS_Evo_PreEvo[2] =
{
    COMPOUND_STRING("{STR_VAR_1} evolves from {STR_VAR_2}"),
    COMPOUND_STRING("{STR_VAR_1} evolves from {STR_VAR_2}")
};

static const u8 *const sTextsHGSS_Evo_None[2] =
{
    COMPOUND_STRING("{STR_VAR_1} has no evolution."),
    COMPOUND_STRING("{STR_VAR_1} has no evolution.")
};

static const u8 *const sTextsHGSS_Form_None[2] =
{
    COMPOUND_STRING("{STR_VAR_1} has no alternate forms."),
    COMPOUND_STRING("{STR_VAR_1} has no alternate forms.")
};

static const u8 *const sTextsHGSS_Power[2] =
{
    gText_Power,
    COMPOUND_STRING("Power")
};

static const u8 *const sTextsHGSS_Accuracy[2] =
{
    gText_Accuracy2,
    COMPOUND_STRING("Accuracy")
};

static const u8 *const sTextsHGSS_Appeal[2] =
{
    gText_Appeal,
    COMPOUND_STRING("Appeal")
};

static const u8 *const sTextsHGSS_Jam[2] =
{
    gText_Jam,
    COMPOUND_STRING("Jam")
};

static const u8 *const sTextsHGSS_CryOf[2] =
{
    gText_CryOf,
    COMPOUND_STRING("Cry of")
};

static const u8 *const sTextsHGSS_SizeComparedTo[2] =
{
    gText_SizeComparedTo,
    COMPOUND_STRING("Size compared to ")
};
