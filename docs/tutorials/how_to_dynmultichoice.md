# How to use Dynamic Multichoice Macros
The dynamic multichoice macros is a feature created by SBird to replace the much more cumbersome vanilla multichoice system. This document details how to use this feature.

## The Macros
There are three main macros that you can use in your scripting, `dynmultichoice`, `dynmultipush`, and `dynmultistack`.

**dynmultistack**<br>
The `dynmultichoice` is the simplest macro and likely the one you'll be using the most. Here's a sample of using `dynmultichoice` in your script:
```
EventScript_ExampleScript::
    dynmultichoice 0, 0, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, EventScript_ExampleScript_Text_1, EventScript_ExampleScript_Text_2, EventScript_ExampleScript_Text_3
    end

EventScript_ExampleScript_Text_1::
    .string "Choice 1$"

EventScript_ExampleScript_Text_2::
    .string "Choice 2$"

EventScript_ExampleScript_Text_3::
    .string "Choice 3$"
```

Here is a look at the macro and it's arguments:
`dynmultichoice left:req, top:req, ignoreBPress:req, maxBeforeScroll:req, initialSelected:req, callbacks:req argv:vararg`

| Argument        | Expected Value | Explanation                                                                                           |
| :---------------:| :--------------:| -------------------------------------------------------------------------------------------------------|
| left            | Integer (0-26) | Determines the x-coordinate of where your menu starts from its top-left corner<br>(explanation below) |
| top             | Integer (0-19) | Determines the y-coordinate of where your menu starts from its top-left corner<br>(explanation below) |
| ignoreBPress    | True/False     | Controls whether the player can exit using the B button. If set to true, the player cannot exit.      |
| maxBeforeScroll | Integer        | Shows how many options are shown before the player has to scroll.                                     |
| initialSelected | Integer        | Chooses which option (from a 0-index) is already selected upon opening the menu.                      |
| callbacks       | Constant       | Designates which callback constants are used. Elaborated more later                                   |
| argv            | String         | The choices that the player can choose from the menu.                                                 |

*How to position arguments left and top*:

Below is a breakdown of the Emerald Screen into a 30x20 grid. These are all the possible starting positions that you can have your multichoice menu begin. Do note, while the macro can create a menu that clips below the bottom of the screen, it cannot create one that clips through the right border. It will always adjust so that the full width of the menu is visible, but it's possible to have it clip beyond the bottom.

Grid Guide:<br>
![guide_to_coordinates](./img/dynmultichoice/coordinates_guide.png)

Example of clipping:<br>
![clipping_example](./img/dynmultichoice/clipping_example.png)

<!--- Need to insert recommended of how to plan your dynamic multichoice, if one wishes.--->

Let's take a look at the `dynmultichoice` from earlier:

`dynmultichoice 0, 0, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, EventScript_ExampleScript_Text_1, EventScript_ExampleScript_Text_2`

| Argument        | Value                                                                                                    | Explanation                                                                                         |
| :----------------| :---------------------------------------------------------------------------------------------------------| -----------------------------------------------------------------------------------------------------|
| left            | 0                                                                                                        | X Coordinate will be on the first tile (8x8 pixels) of the x-axis                                   |
| top             | 0                                                                                                        | X Coordinate will be on the first tile (8x8 pixels) of the y-axis                                   |
| ignoreBPress    | FALSE                                                                                                    | Pressing B will exit the multichoice.                                                               |
| maxBeforeScroll | 2                                                                                                        | Shows 2 options before player has to scroll. This means the 3rd option is hidden until scrolled to. |
| initialSelected | 0                                                                                                        | The first option is selected when the menu is opened through the script.                            |
| callbacks       | DYN_MULTICHOICE_CB_NONE                                                                                  | No callback will be used.                                                                           |
| argv            | EventScript_ExampleScript_Text_1<br>EventScript_ExampleScript_Text_2<br>EventScript_ExampleScript_Text_2 | The choices that the player can choose from the menu.                                               |

