# Habitat Temporary Copy Inventory

This is an approval inventory, not a copy deck. It records the 41 temporary
player-facing strings identified in the audit so that their replacement cannot
quietly create narrative canon. Every row needs its stated approval before it
may be changed. Generic interface labels are deliberately not included in the
41-string audit count.

## Approval rule

Player-facing habitat prose needs narrative approval. A replacement may state
only the listed mechanical facts until an approved copy packet says otherwise.
It must not add a biography, dialogue, place history, occupant, tutorial
explanation, or reunion outcome. “Not supplied” is an intentional replacement
reference, not permission to write copy.

## Audited habitat hints (27)

All 27 entries are generated from the nine spot/state records below. Their
only established facts are the spot state and the dynamic species name.

| File / symbol | Mechanical purpose | Allowed facts | Prohibited inventions | Approval | Replacement reference |
| --- | --- | --- | --- | --- | --- |
| `src/habitat/spot_data.c:sHintDormant_Skitty` | Skitty dormant hint | dormant state; species name | want, biography, scene | Narrative | Not supplied: Skitty/dormant |
| `src/habitat/spot_data.c:sHintStirring_Skitty` | Skitty stirring hint | stirring state; species name | want, biography, scene | Narrative | Not supplied: Skitty/stirring |
| `src/habitat/spot_data.c:sHintActive_Skitty` | Skitty active hint | active state; species name | want, biography, scene | Narrative | Not supplied: Skitty/active |
| `src/habitat/spot_data.c:sHintDormant_Lotad` | Lotad dormant hint | dormant state; species name | want, biography, scene | Narrative | Not supplied: Lotad/dormant |
| `src/habitat/spot_data.c:sHintStirring_Lotad` | Lotad stirring hint | stirring state; species name | want, biography, scene | Narrative | Not supplied: Lotad/stirring |
| `src/habitat/spot_data.c:sHintActive_Lotad` | Lotad active hint | active state; species name | want, biography, scene | Narrative | Not supplied: Lotad/active |
| `src/habitat/spot_data.c:sHintDormant_Machop` | Machop dormant hint | dormant state; species name | want, biography, scene | Narrative | Not supplied: Machop/dormant |
| `src/habitat/spot_data.c:sHintStirring_Machop` | Machop stirring hint | stirring state; species name | want, biography, scene | Narrative | Not supplied: Machop/stirring |
| `src/habitat/spot_data.c:sHintActive_Machop` | Machop active hint | active state; species name | want, biography, scene | Narrative | Not supplied: Machop/active |
| `src/habitat/spot_data.c:sHintDormant_Vulpix` | Vulpix dormant hint | dormant state; species name | want, biography, scene | Narrative | Not supplied: Vulpix/dormant |
| `src/habitat/spot_data.c:sHintStirring_Vulpix` | Vulpix stirring hint | stirring state; species name | want, biography, scene | Narrative | Not supplied: Vulpix/stirring |
| `src/habitat/spot_data.c:sHintActive_Vulpix` | Vulpix active hint | active state; species name | want, biography, scene | Narrative | Not supplied: Vulpix/active |
| `src/habitat/spot_data.c:sHintDormant_Heracross` | Heracross dormant hint | dormant state; species name | want, biography, scene | Narrative | Not supplied: Heracross/dormant |
| `src/habitat/spot_data.c:sHintStirring_Heracross` | Heracross stirring hint | stirring state; species name | want, biography, scene | Narrative | Not supplied: Heracross/stirring |
| `src/habitat/spot_data.c:sHintActive_Heracross` | Heracross active hint | active state; species name | want, biography, scene | Narrative | Not supplied: Heracross/active |
| `src/habitat/spot_data.c:sHintDormant_Pinsir` | Pinsir dormant hint | dormant state; species name | want, biography, scene | Narrative | Not supplied: Pinsir/dormant |
| `src/habitat/spot_data.c:sHintStirring_Pinsir` | Pinsir stirring hint | stirring state; species name | want, biography, scene | Narrative | Not supplied: Pinsir/stirring |
| `src/habitat/spot_data.c:sHintActive_Pinsir` | Pinsir active hint | active state; species name | want, biography, scene | Narrative | Not supplied: Pinsir/active |
| `src/habitat/spot_data.c:sHintDormant_FrameTorchic` | Torchic frame dormant hint | dormant state; species name | lab occupant/history | Narrative | Not supplied: FrameTorchic/dormant |
| `src/habitat/spot_data.c:sHintStirring_FrameTorchic` | Torchic frame stirring hint | stirring state; species name | lab occupant/history | Narrative | Not supplied: FrameTorchic/stirring |
| `src/habitat/spot_data.c:sHintActive_FrameTorchic` | Torchic frame active hint | active state; species name | lab occupant/history | Narrative | Not supplied: FrameTorchic/active |
| `src/habitat/spot_data.c:sHintDormant_FrameTreecko` | Treecko frame dormant hint | dormant state; species name | lab occupant/history | Narrative | Not supplied: FrameTreecko/dormant |
| `src/habitat/spot_data.c:sHintStirring_FrameTreecko` | Treecko frame stirring hint | stirring state; species name | lab occupant/history | Narrative | Not supplied: FrameTreecko/stirring |
| `src/habitat/spot_data.c:sHintActive_FrameTreecko` | Treecko frame active hint | active state; species name | lab occupant/history | Narrative | Not supplied: FrameTreecko/active |
| `src/habitat/spot_data.c:sHintDormant_FrameMudkip` | Mudkip frame dormant hint | dormant state; species name | lab occupant/history | Narrative | Not supplied: FrameMudkip/dormant |
| `src/habitat/spot_data.c:sHintStirring_FrameMudkip` | Mudkip frame stirring hint | stirring state; species name | lab occupant/history | Narrative | Not supplied: FrameMudkip/stirring |
| `src/habitat/spot_data.c:sHintActive_FrameMudkip` | Mudkip frame active hint | active state; species name | lab occupant/history | Narrative | Not supplied: FrameMudkip/active |

## Audited script messages (14)

| File / symbol | Mechanical purpose | Allowed facts | Prohibited inventions | Approval | Replacement reference |
| --- | --- | --- | --- | --- | --- |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_BoutPrompt` | Former optional-bout prompt | none; path removed | battle framing or challenge prose | Not applicable | Removed by Task 2 |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_BoutStart` | Former bout-start acknowledgement | none; path removed | battle framing or companion claims | Not applicable | Removed by Task 2 |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_BoutLost` | Former bout-loss acknowledgement | none; path removed | battle framing or species feelings | Not applicable | Removed by Task 2 |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_NoBattler` | Former missing-battler notice | none; path removed | party or companion story | Not applicable | Removed by Task 2 |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_OfferRejected` | Rejected offer without consumption | offer invalid; item retained | motive, dialogue, biography | Narrative | Not supplied: offer rejection |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_Befriended` | Successful befriend transition | befriend success; resident state | future promise, biography | Narrative | Not supplied: befriend success |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_NothingToPlace` | No matching placeable item | no matching item | place history or tutorial story | Narrative | Not supplied: no matching placement |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_Placed` | Successful placement transition | placement success | arrangement story or occupant history | Narrative | Not supplied: placement success |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_RecruitPrompt` | Grove assignment confirmation | Grove assignment choice | worker biography or Grove history | Narrative | Not supplied: assignment prompt |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_Recruited` | Successful Grove assignment | assignment success | species motive or destination story | Narrative | Not supplied: assignment success |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_GroveFull` | Global six-worker capacity reached | current capacity unavailable | Grove section claim or story reason | Narrative | Not supplied: capacity notice |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_CannotCome` | Resident cannot be assigned | assignment unavailable | species motive or place history | Narrative | Not supplied: assignment refusal |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_Ambient` | Befriended ambient interaction | resident state | personality, dialogue, biography | Narrative | Not supplied: resident ambient |
| `data/scripts/habitat_spot.inc:HabitatSpot_Text_NotASpot` | Unbound-object fallback | object is not a habitat spot | world/town/lab narrative | Narrative | Not supplied: fallback notice |

## Additional current fallback

`src/habitat/spot_interaction.c:sText_NotASpot` is a later engine-side
fallback, outside the 41-string audit count. It has the same approval rule:
it may state only that the target is not a habitat spot until a narrative
replacement is supplied.

## Temporary furnishing icons (6)

| Item / source | Mechanical purpose | Allowed facts | Prohibited inventions | Approval | Replacement reference |
| --- | --- | --- | --- | --- | --- |
| `ITEM_HH_CAMPFIRE` / question-mark icon | Campfire inventory icon | item identity only | visual history or lab occupant claim | Art | Not supplied: approved source record |
| `ITEM_HH_POTTED_PLANT` / question-mark icon | Plant inventory icon | item identity only | visual history or lab occupant claim | Art | Not supplied: approved source record |
| `ITEM_HH_WATER_BASIN` / question-mark icon | Basin inventory icon | item identity only | visual history or lab occupant claim | Art | Not supplied: approved source record |
| `ITEM_HH_LAB_PC` / question-mark icon | PC inventory icon | item identity only | visual history or lab occupant claim | Art | Not supplied: approved source record |
| `ITEM_HH_BOOKSHELF` / question-mark icon | Bookshelf inventory icon | item identity only | visual history or lab occupant claim | Art | Not supplied: approved source record |
| `ITEM_HH_POKEBALL_HOLDER` / question-mark icon | Ball Holder inventory icon | item identity only | visual history or lab occupant claim | Art | Not supplied: approved source record |

Each temporary image is listed in `docs/assets/placeholder-assets.json` with
its repository path, owner, provenance, date, replacement requirement, and
release-blocking flag. A release remains blocked until every entry is removed
and each replacement has a commissioned or hand-made source record.
