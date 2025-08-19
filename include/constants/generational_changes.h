#ifndef GUARD_CONSTANTS_GENERATIONAL_CHANGES_H
#define GUARD_CONSTANTS_GENERATIONAL_CHANGES_H

/*
// Other move settings
#define B_INCINERATE_GEMS           GEN_LATEST // In Gen6+, Incinerate can destroy Gems.
#define B_CAN_SPITE_FAIL            GEN_LATEST // In Gen4+, Spite can no longer fail if the foe's last move only has 1 remaining PP.
#define B_CRASH_IF_TARGET_IMMUNE    GEN_LATEST // In Gen4+, The user of Jump Kick or High Jump Kick will "keep going and crash" if it attacks a target that is immune to the move.
#define B_MEMENTO_FAIL              GEN_LATEST // In Gen4+, Memento fails if there is no target or if the target is protected or behind substitute. But not if Atk/Sp. Atk are at -6.
#define B_GLARE_GHOST               GEN_LATEST // In Gen4+, Glare can hit Ghost-type Pokémon normally.
#define B_SKILL_SWAP                GEN_LATEST // In Gen4+, Skill Swap triggers switch-in abilities after use.
#define B_BRICK_BREAK               GEN_LATEST // In Gen4+, you can destroy your own side's screens. In Gen 5+, screens are not removed if the target is immune.
#define B_WISH_HP_SOURCE            GEN_LATEST // In Gen5+, Wish heals half of the user's max HP instead of the target's.
#define B_RAMPAGE_CANCELLING        GEN_LATEST // In Gen5+, a failed Thrash, etc, will cancel except on its last turn.
#define B_HEAL_BLOCKING             GEN_LATEST // In Gen5+, Heal Block prevents healing by Black Sludge, Leftovers, Shell Bell. Affected Pokémon will not consume held HP-restoring Berries or Berry Juice.
                                               // Draining abilities will not heal but will prevent damage. In Gen6+, Heal Block prevents the use of most HP-draining moves.
#define B_ROOTED_GROUNDING          GEN_LATEST // In Gen4+, Ingrain causes the affected Pokémon to become grounded.
#define B_METRONOME_MOVES           GEN_LATEST // This config will determine up to which generation will Metronome pull moves from.
#define B_TELEPORT_BEHAVIOR         GEN_LATEST // In LGPE onwards (Gen8+ here), Teleport allows the user to swap out with another party member.
#define B_BEAT_UP                   GEN_LATEST // In Gen5+, Beat Up uses a different formula to calculate its damage, and deals Dark-type damage. Prior to Gen 5, each hit also announces the party member's name.
#define B_DARK_VOID_FAIL            GEN_LATEST // In Gen7+, only Darkrai can use Dark Void.
#define B_BURN_HIT_THAW             GEN_LATEST // In Gen6+, damaging moves with a chance of burn will thaw the target, regardless if they're fire-type moves or not.
#define B_HEALING_WISH_SWITCH       GEN_LATEST // In Gen5+, the mon receiving Healing Wish is sent out at the end of the turn.
                                               // Additionally, in gen8+ the Healing Wish's effect will be stored until the user switches into a statused or hurt mon.
#define B_DEFOG_EFFECT_CLEARING     GEN_LATEST // In Gen6+, Defog clears Spikes, Toxic Spikes, Stealth Rock and Sticky Web from both sides. In Gen8+, Defog also clears active Terrain.
#define B_STOCKPILE_RAISES_DEFS     GEN_LATEST // In Gen4+, Stockpile also raises Defense and Sp. Defense stats. Once Spit Up / Swallow is used, these stat changes are lost.
#define B_TRANSFORM_SHINY           GEN_LATEST // In Gen4+, Transform will copy the shiny state of the opponent instead of maintaining its own shiny state.
#define B_TRANSFORM_FORM_CHANGES    GEN_LATEST // In Gen5+, Transformed Pokemon cannot change forms.
#define B_WIDE_GUARD                GEN_LATEST // In Gen5 only, Wide Guard has a chance to fail if used consecutively.
#define B_QUICK_GUARD               GEN_LATEST // In Gen5 only, Quick Guard has a chance to fail if used consecutively.
#define B_IMPRISON                  GEN_LATEST // In Gen5+, Imprison doesn't fail if opposing pokemon don't have any moves the user knows.
#define B_ALLY_SWITCH_FAIL_CHANCE   GEN_LATEST // In Gen9, using Ally Switch consecutively decreases the chance of success for each consecutive use.
#define B_SKETCH_BANS               GEN_LATEST // In Gen9+, Sketch is unable to copy more moves than in previous generations.
#define B_KNOCK_OFF_REMOVAL         GEN_LATEST // In Gen5+, Knock Off removes the foe's item instead of rendering it unusable.
#define B_HEAL_BELL_SOUNDPROOF      GEN_LATEST // In Gen5, Heal Bell affects all mons with Soundproof.  In Gen6-8 it affects inactive mons, but not battlers. In Gen9 it always affects the user.
#define B_CHARGE                    GEN_LATEST // In Gen8-, Charge status is lost regardless of the typing of the next move.
#define B_POWDER_RAIN               GEN_LATEST // In Gen7+, Powder doesn't damage the user of a Fire type move in heavy rain.
#define B_AFTER_YOU_TURN_ORDER      GEN_LATEST // In Gen8+, After You doesn't fail if the turn order wouldn't change after use.
#define B_QUASH_TURN_ORDER          GEN_LATEST // In Gen8+, Quash-affected battlers move according to speed order. Before Gen8, Quash-affected battlers move in the order they were affected by Quash.
#define B_DESTINY_BOND_FAIL         GEN_LATEST // In Gen7+, Destiny Bond fails if used repeatedly.
#define B_PURSUIT_TARGET            GEN_LATEST // In Gen4+, Pursuit attacks a switching opponent even if they weren't targeting them. Before Gen4, Pursuit only attacks a switching opponent that it originally targeted.
#define B_SKIP_RECHARGE             GEN_LATEST // In Gen1, recharging moves such as Hyper Beam skip the recharge if the target gets KO'd
#define B_ENCORE_TARGET             GEN_LATEST // In Gen5+, encored moves are allowed to choose a target
#define B_TIME_OF_DAY_HEALING_MOVES GEN_LATEST // In Gen2, Morning Sun, Moonlight, and Synthesis heal twice as much HP based off the time of day. Also changes how much they heal. Evening affects Moonlight.
                                               // If OW_TIMES_OF_DAY is set to Gen 3, then Morning Sun is boosted during the day.
#define B_DREAM_EATER_LIQUID_OOZE   GEN_LATEST // In Gen5+, Dream Eater is affected by Liquid Ooze.

// Ability settings
#define B_GALE_WINGS                GEN_LATEST // In Gen7+ requires full HP to trigger.
#define B_STANCE_CHANGE_FAIL        GEN_LATEST // In Gen7+, Stance Change fails if the Pokémon is unable to use a move because of confusion, paralysis, etc. In Gen6, it doesn't.
#define B_SHADOW_TAG_ESCAPE         GEN_LATEST // In Gen4+, if both sides have a Pokémon with Shadow Tag, all battlers can escape. Before, neither side could escape this situation.
#define B_MOODY_ACC_EVASION         GEN_LATEST // In Gen8, Moody CANNOT raise Accuracy and Evasion anymore.
#define B_FLASH_FIRE_FROZEN         GEN_LATEST // In Gen5+, Flash Fire can trigger even when frozen, when it couldn't before.
#define B_SYNCHRONIZE_TOXIC         GEN_LATEST // In Gen5+, if a Pokémon with Synchronize is badly poisoned, the opponent will also become badly poisoned. Previously, the opponent would become regular poisoned.
#define B_UPDATED_INTIMIDATE        GEN_LATEST // In Gen8, Intimidate doesn't work on opponents with the Inner Focus, Scrappy, Own Tempo or Oblivious abilities. It also activates Rattled.
#define B_OBLIVIOUS_TAUNT           GEN_LATEST // In Gen6+, Pokémon with Oblivious can't be taunted.
#define B_STURDY                    GEN_LATEST // In Gen5+, Sturdy causes the Pokémon to have 1 HP remaining if another Pokémon's attack or confusion damage would have brought it from full health to 0 HP.
#define B_PLUS_MINUS_INTERACTION    GEN_LATEST // In Gen5+, Plus and Minus can be activated with themselves and the opposite ability. Before, only the opposing ability could activate it.
#define B_WEATHER_FORMS             GEN_LATEST // In Gen5+, Castform and Cherrim revert to their base form upon losing their respective ability. Cherrim needs Flower Gift to swap forms.
#define B_SYMBIOSIS_GEMS            GEN_LATEST // In Gen7+, Symbiosis passes an item after a gem-boosted attack. Previously, items are passed before the gem-boosted attack hits, making the item effect apply.
#define B_ABSORBING_ABILITY_STRING  GEN_LATEST // In Gen5+, the abilities that absorb moves of a certain type use a generic string for stat increases and decreases.
#define B_REDIRECT_ABILITY_IMMUNITY GEN_LATEST // In Gen5+, Pokémon with Lightning Rod/Storm Drain become immune to Electric/Water-type moves and increase their Sp. Attack by 1 stage on top of the redirecting effect.
#define B_REDIRECT_ABILITY_ALLIES   GEN_LATEST // In Gen4+, Lightning Rod/Storm Drain redirect ally's moves as well.
#define B_LEAF_GUARD_PREVENTS_REST  GEN_LATEST // In Gen5+, Leaf Guard prevents the use of Rest in harsh sunlight.
#define B_TRANSISTOR_BOOST          GEN_LATEST // In Gen9+, Transistor will only boost Electric-type moves by 1.3x as opposed to 1.5x.
#define B_ILLUMINATE_EFFECT         GEN_LATEST // In Gen9+, Illuminate prevents accuracy reductions and ignores the target's evasion.
#define B_WEAK_ARMOR_SPEED          GEN_LATEST // In Gen7+, Weak Armor raises Speed by 2 stages instead of 1 when hit by a physical move.
#define B_PROTEAN_LIBERO            GEN_LATEST // In Gen9+, Protean and Libero change the user's type only once per Battle.
#define B_INTREPID_SWORD            GEN_LATEST // In Gen9+, Intrepid Sword raises Attack by one stage only once per Battle.
#define B_DAUNTLESS_SHIELD          GEN_LATEST // In Gen9+, Dauntless Shield raises Defense by one stage only once per Battle.
#define B_DISGUISE_HP_LOSS          GEN_LATEST // In Gen8+, when a Disguised Mimikyu's Disguise is busted, upon changing to its Busted Form it loses HP equal to 1/8 of its maximum HP.
#define B_ABILITY_TRIGGER_CHANCE    GEN_LATEST // In Gen3, Shed Skin, Cute Charm, Flame Body, Static and Poison Point have a 1/3 chance to trigger. In Gen 4+ it's 30%.
                                               // In Gen3, Effect Spore has a 10% chance to sleep, poison or paralyze, with an equal chance.
                                               // In Gen4, it's 30%. In Gen5+ it has 11% to sleep, 9% chance to poison and 10% chance to paralyze.
#define B_PICKUP_WILD               GEN_LATEST // In Gen9+, Pickup allows its user to pickup its own used item at the end of the turn in wild battles.
#define B_MAGIC_GUARD               GEN_LATEST // In Gen4 only, Magic Guard ignores immobilization caused by paralysis
#define B_BATTLE_BOND               GEN_LATEST // In Gen9+, Battle Bond increases Atk, SpAtk and Speed by one stage, once per battle
#define B_ATE_MULTIPLIER            GEN_LATEST // In Gen7+, -ate abilities (Aerilate, Galvanize, Normalize, Pixilate, Refrigerate) multiply damage by 1.2. Otherwise, it's 1.3, except Normalize which has no multiplier.
#define B_DEFIANT_STICKY_WEB        GEN_LATEST // In Gen9+, Defiant activates on Sticky Web regardless of who set it up. In Gen8, Defiant does not activate on Sticky Web set up by an ally after Court Change swaps its side.

// Item settings
#define B_HP_BERRIES                GEN_LATEST // In Gen4+, berries which restore HP activate immediately after HP drops to half. In Gen3, the effect occurs at the end of the turn.
#define B_BERRIES_INSTANT           GEN_LATEST // In Gen4+, most berries activate on battle start/switch-in if applicable. In Gen3, they only activate either at the move end or turn end.
#define B_CONFUSE_BERRIES_HEAL      GEN_LATEST // Before Gen7, Figy and similar berries restore 1/8th of HP and trigger at half HP. In Gen7 they restore half HP, triggering at 25% HP. In Gen8 they heal 1/3rd of HP.
#define B_X_ITEMS_BUFF              GEN_LATEST // In Gen7+, the X Items raise a stat by 2 stages instead of 1.
#define B_MENTAL_HERB               GEN_LATEST // In Gen5+, the Mental Herb cures Taunt, Encore, Torment, Heal Block, and Disable in addition to Infatuation from before.
#define B_TRAINERS_KNOCK_OFF_ITEMS  TRUE       // If TRUE, trainers can steal/swap your items (non-berries are restored after battle). In vanilla games trainers cannot steal items.
#define B_RETURN_STOLEN_NPC_ITEMS   GEN_LATEST // In Gen5+, Thief and Covet no longer steal items from NPCs.
#define B_STEAL_WILD_ITEMS          GEN_LATEST // In Gen9, Thief and Covet steal a wild pokemon's item and send it to the bag. Before Gen9, the stolen item would be held by the Thief/Covet user.
#define B_RESTORE_HELD_BATTLE_ITEMS GEN_LATEST // In Gen9, all non-berry items are restored after battle.
#define B_SOUL_DEW_BOOST            GEN_LATEST // In Gens3-6, Soul Dew boosts Latis' Sp. Atk and Sp. Def. In Gen7+ it boosts the power of their Psychic and Dragon type moves instead.
#define B_NET_BALL_MODIFIER         GEN_LATEST // In Gen7+, Net Ball's catch multiplier is x5 instead of x3.
#define B_DIVE_BALL_MODIFIER        GEN_LATEST // In Gen4+, Dive Ball's effectiveness increases by x3.5 when Surfing or Fishing.
#define B_NEST_BALL_MODIFIER        GEN_LATEST // Nest Ball's formula varies depending on the Gen. See Cmd_handleballthrow.
#define B_REPEAT_BALL_MODIFIER      GEN_LATEST // In Gen7+, Repeat Ball's catch multiplier is x3.5 instead of x3.
#define B_TIMER_BALL_MODIFIER       GEN_LATEST // In Gen5+, Timer Ball's effectiveness increases by x0.3 per turn instead of x0.1
#define B_DUSK_BALL_MODIFIER        GEN_LATEST // In Gen7+, Dusk Ball's catch multiplier is x3 instead of x3.5.
#define B_QUICK_BALL_MODIFIER       GEN_LATEST // In Gen5+, Quick Ball's catch multiplier is x5 instead of x4.
#define B_LURE_BALL_MODIFIER        GEN_LATEST // In Gen8+, Lure Ball's catch multiplier is x4. In Gen7, it's x5. In Gen6 and earlier, it's x3.
#define B_HEAVY_BALL_MODIFIER       GEN_LATEST // In Gen7+, Heavy Ball's ranges change. See Cmd_handleballthrow.
#define B_DREAM_BALL_MODIFIER       GEN_LATEST // In Gen8+, Dream Ball's catch multiplier is x4 when the target is asleep or has the ability Comatose.
#define B_SPORT_BALL_MODIFIER       GEN_LATEST // In Gen8+, Sport Ball's catch multiplier was reduced from x1.5 to x1.
#define B_SAFARI_BALL_MODIFIER      GEN_LATEST // In Gen8+, Safari Ball's catch multiplier was reduced from x1.5 to x1.
#define B_FRIEND_BALL_MODIFIER      GEN_LATEST // In Gen8+, Friend Ball's friendship boost was reduced from 200 to 150.
#define B_SERENE_GRACE_BOOST        GEN_LATEST // In Gen5+, Serene Grace boosts the added flinch chance of King's Rock and Razor Fang.
#define B_IRON_BALL                 GEN_LATEST // In Gen5+, Flying-type Pokemon holding Iron Ball take x1 damage from Ground-type moves regardless of their other types, except during Inverse Battles or if the Pokemon is grounded by any other effect.

// Flag settings
// To use the following features, change the 0 for a flag present in include/constants/flags.h, preferably an unused one.
// Eg: You may rename FLAG_UNUSED_0x264 to a descriptive name and use it below.

// Badge boost flags
#define B_FLAG_BADGE_BOOST_ATTACK   FLAG_BADGE01_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will multiply the player's Pokémon's Attack by x1.1
#define B_FLAG_BADGE_BOOST_DEFENSE  FLAG_BADGE05_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will multiply the player's Pokémon's Defense by x1.1
#define B_FLAG_BADGE_BOOST_SPEED    FLAG_BADGE03_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will multiply the player's Pokémon's Speed by x1.1
#define B_FLAG_BADGE_BOOST_SPATK    FLAG_BADGE07_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will multiply the player's Pokémon's Sp. Atk by x1.1
#define B_FLAG_BADGE_BOOST_SPDEF    FLAG_BADGE07_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will multiply the player's Pokémon's Sp. Def by x1.1
// Other battle flags
#define B_FLAG_INVERSE_BATTLE       0     // If this flag is set, the battle's type effectiveness are inversed. For example, fire is super effective against water.
#define B_FLAG_FORCE_DOUBLE_WILD    0     // If this flag is set, all land and surfing wild battles will be double battles.
#define B_SMART_WILD_AI_FLAG        0     // If this flag is set, wild Pokémon will become smart, with all AI flags enabled.
#define B_FLAG_NO_BAG_USE           0     // If this flag is set, the ability to use the bag in battle is disabled.
#define B_FLAG_NO_CATCHING          0     // If this flag is set, the ability to catch wild Pokémon is disabled.
#define B_FLAG_NO_RUNNING           0     // If this flag is set, the ability to escape from wild battles is disabled. Also makes Roar/Whirlwind and Teleport (under Gen8) fail.
#define B_FLAG_AI_VS_AI_BATTLE      0     // If this flag is set, the player's mons will be controlled by the ai next battles.
#define B_FLAG_DYNAMAX_BATTLE       0     // If this flag is set, the ability to Dynamax in battle is enabled for all trainers.
#define B_FLAG_TERA_ORB_CHARGED     0     // If this flag is set, the Tera Orb is charged. It is automatically set upon healing and cleared upon Terastallizing once configured.
#define B_FLAG_TERA_ORB_NO_COST     0     // If this flag is set, the Tera Orb does not use up its charge upon Terastallization. In S/V, this occurs after an event with Terapagos.
#define B_FLAG_SLEEP_CLAUSE         0     // If this flag is set, sleep clause is enabled; if the player / AI has already put a Pokémon on the opponent's side to sleep and it is still sleeping, another one can't be put to sleep. AI requires AI_FLAG_CHECK_BAD_MOVE to understand.
#define B_FLAG_NO_WHITEOUT          0     // If this flag is set, the player can not white out against Trainers. Please note that the party is not healed automatically!

// Var Settings
// To use the following features, change the 0 for a var present in include/constants/vars.h, preferably an unused one.
// Eg: You may rename VAR_UNUSED_0x404E to a descriptive name and use it below.
#define B_VAR_STARTING_STATUS       0     // If this var has a value, assigning a STATUS_FIELD_xx_TERRAIN to it before battle causes the battle to start with that terrain active.
                                          // This var should never remain non-zero long enough for the player to save.
#define B_VAR_STARTING_STATUS_TIMER 0     // If this var has a value greater or equal than 1 field terrains will last that number of turns, otherwise they will last until they're overwritten.
#define B_VAR_WILD_AI_FLAGS         0     // If not 0, you can use this var to add to default wild AI flags. IMPORTANT: NOT usable with flags above (1 << 15)
                                          // This var should never remain non-zero long enough for the player to save.
                                          // For better wild AI handling, edit GetWildAiFlags() in src/battle_ai_main.c

#define B_VAR_DIFFICULTY            0     // If not 0, you can use this var to control which difficulty version of a Trainer is loaded. This should be manually set by the developer using Script_SetDifficulty AFTER NewGameInitData has run.

// Sky Battles
#define B_FLAG_SKY_BATTLE                 0     // If this flag has a value, the player will be able to engage in scripted Sky Battles.
#define B_VAR_SKY_BATTLE                  0     // If this var has a value, the game will remember the positions of Pokémon used in Sky Battles.
#define B_SKY_BATTLE_STRICT_ELIGIBILITY   FALSE // If TRUE, Sky Battles will use the eligibility from Pokémon XY. If FALSE, all Flying-types or Pokémon with Levitate are allowed.

// Flag and Var settings
#define B_RESET_FLAGS_VARS_AFTER_WHITEOUT TRUE // If TRUE, Overworld_ResetBattleFlagsAndVars will reset battle-related Flags and Vars when the player whites out.

// Ingame partner flag
#define B_SHOW_PARTNER_TARGET             FALSE // Shows the battler partner will target.

// Weather settings
// Search for 'rain', 'sunny day', and 'hail' for move-specific or species-specific weather interactions.
#define B_ICE_WEATHER_BOTH              0
#define B_ICE_WEATHER_HAIL              1
#define B_ICE_WEATHER_SNOW              2

#define B_ABILITY_WEATHER               GEN_LATEST // In Gen6+, ability-induced weather lasts 5 turns. Before, it lasted until the battle ended or until it was changed by a move or a different weather-affecting ability.
#define B_SANDSTORM_SPDEF_BOOST         GEN_LATEST // In Gen4+, Sandstorm weather multiplies the Sp. Defense of Rock-type Pokémon by x1.5.
#define B_OVERWORLD_FOG                 GEN_LATEST // In Gen8+, overworld Fog summons Misty Terrain in battle. In Gen4 only, overworld Fog summons the unique fog weather condition in battle.
#define B_OVERWORLD_SNOW                GEN_LATEST // In Gen9+, overworld Snow will summon snow instead of hail in battle.
#define B_SNOW_WARNING                  GEN_LATEST // In Gen9+, Snow Warning will summon snow instead of hail.
#define B_PREFERRED_ICE_WEATHER         B_ICE_WEATHER_BOTH // Toggles Hail move effects to Snow and vice versa.

// Terrain settings
#define B_TERRAIN_BG_CHANGE         TRUE       // If set to TRUE, terrain moves permanently change the default battle background until the effect fades.
#define B_THUNDERSTORM_TERRAIN      TRUE       // If TRUE, overworld Thunderstorm generates Rain and Electric Terrain as in Gen 8.
#define B_TERRAIN_TYPE_BOOST        GEN_LATEST // In Gen8, damage is boosted by 30% instead of 50%.
#define B_SECRET_POWER_EFFECT       GEN_LATEST // Secret Power's effects change depending on terrain and generation. See MOVE_EFFECT_SECRET_POWER's case in `SetMoveEffect`.
#define B_SECRET_POWER_ANIMATION    GEN_LATEST // Secret Power's animations change depending on terrain and generation.
#define B_NATURE_POWER_MOVES        GEN_LATEST // Nature Power calls different moves depending on terrain and generation. See gBattleEnvironmentInfo.
#define B_CAMOUFLAGE_TYPES          GEN_LATEST // Camouflage changes the user to different types depending on terrain and generation. See sTerrainToType.
#define B_NEW_TERRAIN_BACKGROUNDS   FALSE      // If set to TRUE, uses new terrain backgrounds for Electric, Misty, Grassy and Psychic Terrain.

// Interface settings
#define B_ABILITY_POP_UP                    TRUE  // In Gen5+, the Pokémon abilities are displayed in a pop-up, when they activate in battle.
#define B_FAST_INTRO_PKMN_TEXT              TRUE  // If set to TRUE, battle intro texts print at the same time as animation of a Pokémon, as opposing to waiting for the animation to end.
#define B_FAST_INTRO_NO_SLIDE               FALSE // If set to TRUE, the slide animation that happens at the beginning of the battle is skipped.
#define B_FAST_HP_DRAIN                     TRUE  // If set to TRUE, HP bars will move faster.
#define B_FAST_EXP_GROW                     TRUE  // If set to TRUE, EXP bars will move faster.
#define B_SHOW_TARGETS                      TRUE  // If set to TRUE, all available targets, for moves hitting 2 or 3 Pokémon, will be shown before selecting a move.
#define B_SHOW_CATEGORY_ICON                TRUE  // If set to TRUE, it will show an icon in the summary and move relearner showing the move's category.
#define B_HIDE_HEALTHBOX_IN_ANIMS           TRUE  // If set to TRUE, hides healthboxes during move animations.
#define B_WAIT_TIME_MULTIPLIER              16    // This determines how long text pauses in battle last. Vanilla is 16. Lower values result in faster battles.
#define B_QUICK_MOVE_CURSOR_TO_RUN          FALSE // If set to TRUE, pushing B in the battle options against a wild encounter will move the cursor to the run option
#define B_RUN_TRAINER_BATTLE                TRUE  // If set to TRUE, players can run from Trainer battles. This is treated as a whiteout.
#define B_MOVE_DESCRIPTION_BUTTON           L_BUTTON // If set to a button other than B_LAST_USED_BALL_BUTTON, pressing this button will open the move description menu
#define B_SHOW_USELESS_Z_MOVE_INFO          FALSE // If set to TRUE, Z-moves without additional effects like newer gen status moves will say "no additional effect"
#define B_ANIMATE_MON_AFTER_KO              TRUE // If set to TRUE, if a Pokémon on the opposite site faints, the non-fainted Pokemon will display a victory animation.
#define B_ANIMATE_MON_AFTER_FAILED_POKEBALL TRUE  // If set to TRUE, if a Pokémon on the opposite side breaks out of a thrown Poké Ball, the wild Pokémon will display its animation.
#define B_SHOW_DYNAMAX_MESSAGE              FALSE // If set to TRUE, an additional battle message is shown after completing Dynamaxing/Gigantamaxing.

// Catching settings
#define B_SEMI_INVULNERABLE_CATCH       GEN_LATEST // In Gen4+, you cannot throw a ball against a Pokemon that is in a semi-invulnerable state (dig/fly/etc)
#define B_CATCHING_CHARM_BOOST          20         // % boost in Critical Capture odds if player has the Catching Charm.
#define B_CRITICAL_CAPTURE              TRUE       // If set to TRUE, Critical Capture will be enabled.
#define B_CRITICAL_CAPTURE_LOCAL_DEX    TRUE       // If set to FALSE, Critical Capture % is based off of the National Pokedex estimated by enabled generations.

#define B_LAST_USED_BALL            TRUE       // If TRUE, the "last used ball" feature from Gen 7 will be implemented
#define B_LAST_USED_BALL_BUTTON     R_BUTTON   // If last used ball is implemented, this button (or button combo) will trigger throwing the last used ball.
#define B_LAST_USED_BALL_CYCLE      TRUE       // If TRUE, then holding B_LAST_USED_BALL_BUTTON while pressing the D-Pad cycles through the balls
#define B_CATCH_SWAP_INTO_PARTY     GEN_LATEST // In Gen 7+, the option to swap the caught wild mon to the party will appear, allowing you to send a different mon to the box.
#define B_CATCH_SWAP_CHECK_HMS      TRUE       // If TRUE, the catch swap feature above will prevent returning mons to the box if they know HMs.

// Other settings
#define B_DOUBLE_WILD_CHANCE            0          // % chance of encountering two Pokémon in a Wild Encounter.
#define B_DOUBLE_WILD_REQUIRE_2_MONS    FALSE      // If set to TRUE, Wild Double Battles will default to Single Battles when the player only has 1 usable Pokémon, ignoring B_DOUBLE_WILD_CHANCE and B_FLAG_FORCE_DOUBLE_WILD.
#define B_MULTI_BATTLE_WHITEOUT         GEN_LATEST // In Gen4+, multi battles end when the Player and also their Partner don't have any more Pokémon to fight.
#define B_EVOLUTION_AFTER_WHITEOUT      GEN_LATEST // In Gen6+, Pokemon that qualify for evolution after battle will evolve even if the player loses.
#define B_WILD_NATURAL_ENEMIES          TRUE       // If set to TRUE, certain wild mon species will attack other species when partnered in double wild battles (eg. Zangoose vs Seviper)
#define B_AFFECTION_MECHANICS           TRUE       // In Gen6+, there's a stat called affection that can trigger different effects in battle. From LGPE onwards, those effects use friendship instead.
#define B_TRAINER_CLASS_POKE_BALLS      GEN_LATEST // In Gen7+, trainers will use certain types of Poké Balls depending on their trainer class.
#define B_TRAINER_MON_RANDOM_ABILITY    FALSE      // If this is set to TRUE a random legal ability will be generated for a trainer mon
#define B_OBEDIENCE_MECHANICS           GEN_LATEST // In PLA+ (here Gen8+), obedience restrictions also apply to non-outsider Pokémon, albeit based on their level met rather than actual level
#define B_USE_FROSTBITE                 FALSE      // In PLA, Frostbite replaces Freeze. Enabling this flag does the same here. Moves can still be cherry-picked to either Freeze or Frostbite. Freeze-Dry, Secret Power & Tri Attack depend on this config.
#define B_TOXIC_REVERSAL                GEN_LATEST // In Gen5+, bad poison will change to regular poison at the end of battles.
#define B_TRY_CATCH_TRAINER_BALL        GEN_LATEST // In Gen4+, trying to catch a Trainer's Pokémon does not consume the Poké Ball.
#define B_SLEEP_CLAUSE                  FALSE      // Enables Sleep Clause all the time in every case, overriding B_FLAG_SLEEP_CLAUSE. Use that for modularity.
*/


/* Config definitions */
#define CONFIG_DEFINITIONS(F) \
    /* Calculation settings */ \
    F(CRIT_CHANCE,               critChance,             (u32, GEN_9)) \
    F(CRIT_MULTIPLIER,           critMultiplier,         (u32, GEN_9)) \
    F(PARALYSIS_SPEED,           paralysisSpeed,         (u32, GEN_9)) \
    F(CONFUSION_SELF_DMG_CHANCE, confusionSelfDmgChance, (u32, GEN_9)) \
    F(MULTI_HIT_CHANCE,          multiHitChance,         (u32, GEN_9)) \
    F(WHITEOUT_MONEY,            whiteoutMoney,          (u32, GEN_9)) /* TODO */ \
    F(LIGHT_BALL_ATTACK_BOOST,   lightBallAttackBoost,   (u32, GEN_9)) /* TODO */ \
    /* Experience settings */ \
    F(EXP_CATCH,                 expCatch,               (u32, GEN_9)) /* TODO */ \
    F(TRAINER_EXP_MULTIPLIER,    trainerExpMultiplier,   (u32, GEN_9)) /* TODO */ \
    F(SPLIT_EXP,                 splitExp,               (u32, GEN_9)) /* TODO */ \
    F(SCALED_EXP,                scaledExp,              (u32, GEN_9)) /* TODO */ \
    F(UNEVOLVED_EXP_MULTIPLIER,  unevolvedExpMultiplier, (u32, GEN_9)) /* TODO */ \
    F(LEVEL_UP_NOTIFICATION,     levelUpNotification,    (u32, GEN_9)) /* TODO */ \
    /* Stat settings */ \
    F(BADGE_BOOST,               badgeBoost,             (u32, GEN_9)) /* TODO */ \
    F(FRIENDSHIP_BOOST,          friendshipBoost,        (u32, TRUE))  /* TODO */ \
    F(MAX_LEVEL_EV_GAINS,        maxLevelEvGains,        (u32, GEN_9)) /* TODO */ \
    F(RECALCULATE_STATS,         recalculateStats,       (u32, GEN_9)) /* TODO */ \
    /* Damage settings */ \
    F(BURN_DAMAGE,               burnDamage,             (u32, GEN_9)) /* TODO */ \
    F(BURN_FACADE_DMG,           burnFacadeDmg,          (u32, GEN_9)) /* TODO */ \
    F(BINDING_DAMAGE,            bindingDamage,          (u32, GEN_9)) /* TODO */ \
    F(PSYWAVE_DMG,               psywaveDmg,             (u32, GEN_9)) /* TODO */ \
    F(PAYBACK_SWITCH_BOOST,      paybackSwitchBoost,     (u32, GEN_9)) /* TODO */ \
    F(HIDDEN_POWER_DMG,          hiddenPowerDmg,         (u32, GEN_9)) /* TODO */ \
    F(ROUGH_SKIN_DMG,            roughSkinDmg,           (u32, GEN_9)) /* TODO */ \
    F(KNOCK_OFF_DMG,             knockOffDmg,            (u32, GEN_9)) /* TODO */ \
    F(SPORT_DMG_REDUCTION,       sportDmgReduction,      (u32, GEN_9)) /* TODO */ \
    F(EXPLOSION_DEFENSE,         explosionDefense,       (u32, GEN_9)) /* TODO */ \
    F(PARENTAL_BOND_DMG,         parentalBondDmg,        (u32, GEN_9)) /* TODO */ \
    F(MULTIPLE_TARGETS_DMG,      multipleTargetsDmg,     (u32, GEN_9)) /* TODO */ \
    /* Type settings */ \
    F(GHOSTS_ESCAPE,             ghostsEscape,           (u32, GEN_9)) /* TODO */ \
    F(PARALYZE_ELECTRIC,         paralyzeElectric,       (u32, GEN_9)) /* TODO */ \
    F(POWDER_GRASS,              powderGrass,            (u32, GEN_9)) /* TODO */ \
    F(UPDATED_TYPE_MATCHUPS,     updatedTypeMatchups,    (u32, GEN_9)) /* TODO */ \
    F(PRANKSTER_DARK_TYPES,      pranksterDarkTypes,     (u32, GEN_9)) /* TODO */ \
    F(SHEER_COLD_IMMUNITY,       sheerColdImmunity,      (u32, GEN_9)) /* TODO */ \
    F(ROOST_PURE_FLYING,         roostPureFlying,        (u32, GEN_9)) /* TODO */ \
    F(STATUS_TYPE_IMMUNITY,      statusTypeImmunity,     (u32, GEN_9)) /* TODO */ \
    /* Turn settings */ \
    F(BINDING_TURNS,             bindingTurns,           (u32, GEN_9)) /* TODO */ \
    F(UPROAR_TURNS,              uproarTurns,            (u32, GEN_9)) /* TODO */ \
    F(UPROAR_IGNORE_SOUNDPROOF,  uproarIgnoreSoundproof, (u32, GEN_9)) /* TODO */ \
    F(DISABLE_TURNS,             disableTurns,           (u32, GEN_9)) /* TODO */ \
    F(TAILWIND_TURNS,            tailwindTurns,          (u32, GEN_9)) /* TODO */ \
    F(SLEEP_TURNS,               sleepTurns,             (u32, GEN_9)) /* TODO */ \
    F(TAUNT_TURNS,               tauntTurns,             (u32, GEN_9)) /* TODO */ \
    F(SPORT_TURNS,               sportTurns,             (u32, GEN_9)) /* TODO */ \
    F(MEGA_EVO_TURN_ORDER,       megaEvoTurnOrder,       (u32, GEN_9)) /* TODO */ \
    F(RECALC_TURN_AFTER_ACTIONS, recalcTurnAfterActions, (u32, GEN_9)) /* TODO */ \
    F(FAINT_SWITCH_IN,           faintSwitchIn,          (u32, GEN_9)) /* TODO */ \
    /* Move data settings */ \
    F(UPDATED_MOVE_DATA,         updatedMoveData,        (u32, GEN_9)) /* TODO */ \
    F(UPDATED_MOVE_TYPES,        updatedMoveTypes,       (u32, GEN_9)) /* TODO */ \
    F(UPDATED_MOVE_FLAGS,        updatedMoveFlags,       (u32, GEN_9)) /* TODO */ \
    F(PHYSICAL_SPECIAL_SPLIT,    physicalSpecialSplit,   (u32, GEN_9)) /* TODO */ \
    F(RECOIL_IF_MISS_DMG,        recoilIfMissDmg,        (u32, GEN_9)) /* TODO */ \
    F(KLUTZ_FLING_INTERACTION,   klutzFlingInteraction,  (u32, GEN_9)) /* TODO */ \
    F(UPDATED_CONVERSION,        updatedConversion,      (u32, GEN_9)) /* TODO */ \
    F(UPDATED_CONVERSION_2,      updatedConversion2,     (u32, GEN_9)) /* TODO */ \
    F(PP_REDUCED_BY_SPITE,       ppReducedBySpite,       (u32, GEN_9)) /* TODO */ \
    F(EXTRAPOLATED_MOVE_FLAGS,   extrapolatedMoveFlags,  (u32, TRUE))  /* TODO */ \
    /* Ability data settings */ \
    F(UPDATED_ABILITY_DATA,      updatedAbilityData,     (u32, GEN_9)) /* TODO */ \
    /* Move accuracy settings */ \
    F(TOXIC_NEVER_MISS,          toxicNeverMiss,         (u32, GEN_9)) /* TODO */ \
    F(MINIMIZE_DMG_ACC,          minimizeDmgAcc,         (u32, GEN_9)) /* TODO */ \
    F(BLIZZARD_HAIL,             blizzardHail,           (u32, GEN_9)) /* TODO */ \
    F(SHEER_COLD_ACC,            sheerColdAcc,           (u32, GEN_9)) /* TODO */ \
    /* Move stat change settings */ \
    F(FELL_STINGER_STAT_RAISE,   fellStingerStatRaise,   (u32, GEN_9)) \
    F(KINGS_SHIELD_LOWER_ATK,    kingsShieldLowerAtk,    (u32, GEN_9)) /* TODO */ \
    F(SPEED_BUFFING_RAPID_SPIN,  speedBuffingRapidSpin,  (u32, GEN_9)) /* TODO */ \
    F(CHARGE_SPDEF_RAISE,        chargeSpDefRaise,       (u32, GEN_9)) /* TODO */ \
    F(MINIMIZE_EVASION,          minimizeEvasion,        (u32, GEN_9)) /* TODO */ \
    F(GROWTH_STAT_RAISE,         growthStatRaise,        (u32, GEN_9)) /* TODO */ \
    F(FOCUS_ENERGY_CRIT_RATIO,   focusEnergyCritRatio,   (u32, GEN_9)) \
    /**/ \
    /**/ \
    /**/ \
    F(GALE_WINGS,                galeWings,              (u32, GEN_9)) \
    F(HEAL_BELL_SOUNDPROOF,      healBellSoundproof,     (u32, GEN_9)) \
    F(TELEPORT_BEHAVIOR,         teleportBehavior,       (u32, GEN_9)) \
    F(ABILITY_WEATHER,           abilityWeather,         (u32, GEN_9)) \
    F(MOODY_ACC_EVASION,         moodyStats,             (u32, GEN_9)) \
    F(BATTLE_BOND,               battleBond,             (u32, GEN_9)) \
    F(ATE_MULTIPLIER,            ateMultiplier,          (u32, GEN_9)) \
    F(DEFIANT_STICKY_WEB,        defiantStickyWeb,       (u32, GEN_9)) \
    F(ENCORE_TARGET,             encoreTarget,           (u32, GEN_9)) \
    F(TIME_OF_DAY_HEALING_MOVES, timeOfDayHealingMoves,  (u32, GEN_9)) \
    F(PICKUP_WILD,               pickupWild,             (u32, GEN_9)) \
    F(PROTEAN_LIBERO,            proteanLibero,          (u32, GEN_9)) \
    F(INTREPID_SWORD,            intrepidSword,          (u32, GEN_9)) \
    F(DAUNTLESS_SHIELD,          dauntlessShield,        (u32, GEN_9)) \
    F(ILLUMINATE_EFFECT,         illuminateEffect,       (u32, GEN_9)) \
    F(STEAL_WILD_ITEMS,          stealWildItems,         (u32, GEN_9)) \
    F(SNOW_WARNING,              snowWarning,            (u32, GEN_9)) \
    F(ALLY_SWITCH_FAIL_CHANCE,   allySwitchFailChance,   (u32, GEN_9)) \
    F(DREAM_EATER_LIQUID_OOZE,   dreamEaterLiquidOoze,   (u32, GEN_9)) \
    F(TRANSISTOR_BOOST,          transistorBoost,        (u32, GEN_9)) \

#define GET_CONFIG_MAXIMUM(_typeMaxValue, ...) INVOKE_WITH_B(GET_CONFIG_MAXIMUM_, _typeMaxValue)
#define GET_CONFIG_MAXIMUM_(_type, ...) FIRST(__VA_OPT__(FIRST(__VA_ARGS__),) MAX_BITS((sizeof(_type) * 8)))

#define UNPACK_CONFIG_ENUMS(_name, ...) GEN_CONFIG_##_name,

enum GenConfigTag
{
    CONFIG_DEFINITIONS(UNPACK_CONFIG_ENUMS)
};

#endif // GUARD_CONSTANTS_GENERATIONAL_CHANGES_H
