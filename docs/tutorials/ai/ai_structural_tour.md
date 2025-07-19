# AI Structural Tour


## Foreword
This document is a near copy-paste answer to "Is there a guide or map to the AI?" asked in the RHH Discord. It will not teach you how to do anything specific, but should help provide a general understanding of the framework the AI code is built on.

**Disclaimer**: I work with the AI a tonne, but I definitely don't know everything. There are also exceptions / edge cases / other locations etc. for everything I'll be touching on, but this is hopefully a good starting point. I'm going to reference function names rather than filenames throughout. This is up to date as of 1.12 and halfway through the 1.3 upcoming lifecycle.

## Tour

The entry point to most of the AI's logic is in `HandleTurnActionSelectionState`, more of it used to be there but now it is largely outsourced through to `ComputeBattlerDecisions` for a given battler. `ComputeBattlerDecisions` is split into a few parts that are relevant.

`BattleAI_SetupAIData` and `SetupAIPredictionData` are self explanatory, and won't need to be touched for the vast majority of new behaviour. `SetupAIPredictionData` mirrors much of the structure of the latter half of `ComputeBattlerDecisions`, but does so to predict what the player's battler will do from the AI's perspective.

Past the setup functions, the AI does three things:
- Determine the best switchin candidate it has available this turn for a mid battle switch (the line with `GetMostSuitableMonToSwitchInto`)
- Determine whether or not it should switch this turn (the `ShouldSwitch` conditional)
- Determine what move it should use (the line with `BattleAI_ChooseMoveIndex`). This can then override the AI's switching decision (ie. switching is good; U-Turn is good; if U-Turn is good I should do that instead of switching) using `ModifySwitchAfterMoveScoring`.

If you're interested in handling for cases to trigger switches, you'll want to go to the `ShouldSwitch` function. It has several sub-functions that handle different cases.

If you're interested in how the AI chooses which mon is its best switchin candidate either mid battle or post-KO, you'll want to look into `GetMostSuitableMonToSwitchInto`, and if you're interested in the smart switching cases specifically, follow through that to `GetBestMonIntegrated`.

If you're interested in move scoring behaviour, we instead go through `BattleAI_ChooseMoveIndex`. It splits into two sub functions, `ChooseMoveOrAction_Singles` and `ChooseMoveOrAction_Doubles`, which handle the action *choosing* based on score. Changes aren't necessary here often, and it's not where most behaviour changes go.

Both of those functions call `BattleAI_DoAIProcessing`, and this is the function that iterates through the move scoring. It does this by iterating through *scoring functions*, each assigned to an AI flag.

AI flags are defined in `battle_ai.h`, and each has a slot for an AI function. You can see the full function list in `sBattleAiFuncTable`; some don't have functions because they aren't used for move scoring. If it is used for move scoring, it'll have a function.

Each of these sub functions such as `AI_CheckViability` have handling to manipulate the score of whatever input move. `BattleAI_DoAIProcessing` will iterate through every scoring function that's appropriate to the current AI based on which flags they have assigned. This score then gets passed back up through the functions as a chosen decision. If you want to manipulate behaviour via move scoring, these functions are the place to do it.

This isn't exhaustive as I said. There's additional handling for items (it is almost nonexistent) through `ShouldUseItem`. Both it and switching are actually *chosen* in `AI_TrySwitchOrUseItem`, which gets called by (generally) `OpponentHandleChooseAction`, from the opponent's battle controller. Similarly, the actual switch for things like post-KO switching is handled through `OpponentHandleChoosePokemon`, also from the battle controller.

There are a *tonne* of AI related helper functions ~~sneezed all over the place~~ largely centralized to `battle_ai_util.c`. If you want a helper function and aren't sure whether or not it exists, you can check there or ask. Sometimes they're in `battle_ai_switch_items` or `battle_ai_main` instead, it varies.
