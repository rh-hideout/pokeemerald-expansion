#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoPokeduel[] =
{
#endif

//Pokeduel Species
[SPECIES_ILLUSION_MAGICIAN] =
{
    .baseHP        = 50,
    .baseAttack    = 60,
    .baseDefense   = 50,
    .baseSpeed     = 65,
    .baseSpAttack  = 55,
    .baseSpDefense = 50,
    .types = MON_TYPES(TYPE_DARK),
    .catchRate = 45,
    .expYield = 70,
    .evYield_Attack = 1,
    .itemCommon = ITEM_NONE,
    .itemRare = ITEM_NONE, 
    .genderRatio = PERCENT_FEMALE(0),
    .eggCycles = 5,
    .friendship = STANDARD_FRIENDSHIP,
    .growthRate = GROWTH_MEDIUM_SLOW,
    .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_HUMAN_LIKE),
    .abilities = { ABILITY_COMPOUND_EYES, ABILITY_NONE, ABILITY_NONE },
    .bodyColor = BODY_COLOR_PURPLE,
    .speciesName = _("Illusion M"),
    .cryId = CRY_WOOPER,
    .natDexNum = NATIONAL_DEX_ILLUSION_MAGICIAN,
    .categoryName = _("Magician"),
    .height = 7,
    .weight = 85,
    .description = COMPOUND_STRING(
        "An Egyptian Spirit Monster summoned\n"
        "by Mahad to defeat Thief Bakura."
    ),
    .pokemonScale = 256,
    .pokemonOffset = 0,
    .trainerScale = 290,
    .trainerOffset = 2,
    .frontPic = gMonFrontPic_IllusionMagician,
    .frontPicSize = MON_COORDS_SIZE(64, 64),
    .frontPicYOffset = 0,
    .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
    ),
    .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
    .enemyMonElevation = 4,
    .backPic = gMonBackPic_IllusionMagician,
    .backPicSize = MON_COORDS_SIZE(64, 64),
    .backPicYOffset = 17,
    .backAnimId = BACK_ANIM_H_SLIDE,
    .palette = gMonPalette_IllusionMagician,
    .shinyPalette = gMonShinyPalette_IllusionMagician,
    .iconSprite = gMonIcon_IllusionMagician,
    .iconPalIndex = 0,
    .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
    SHADOW(1, 1, SHADOW_SIZE_S)
    FOOTPRINT(Mudkip)
    OVERWORLD(
        sPicTable_Mudkip,
        SIZE_32x32,
        SHADOW_SIZE_M,
        TRACKS_FOOT,
        sAnimTable_Following,
        gOverworldPalette_Mudkip,
        gShinyOverworldPalette_Mudkip
    )
    .levelUpLearnset = sIllusionMagicianLevelUpLearnset,
    .teachableLearnset = sIllusionMagicianTeachableLearnset,
    .eggMoveLearnset = sIllusionMagicianEggMoveLearnset,
    .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_MARSHTOMP}),
},




#ifdef __INTELLISENSE__
};
#endif
