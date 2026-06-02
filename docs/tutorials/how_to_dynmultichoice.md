# How to use Dynamic Multichoice Macros
The dynamic multichoice macros is a feature created by SBird to replace the much more cumbersome vanilla multichoice system. This document details how to use this feature.

## The Macros
There are three main macros that you can use in your scripting, `dynmultichoice`, `dynmultipush`, and `dynmultistack`.

**dynmultistack**<br>
The `dynmultistack` is the simplest macro and likely the one you'll be using the most. Here's a sample of using `dynmultichoice` in your script:
```
EventScript_ExampleScript::
    dynmultichoice 0, 0, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, EventScript_ExampleScript_Text_1, EventScript_ExampleScript_Text_2
    end

EventScript_ExampleScript_Text_1::
    .string "Choice 1$"

EventScript_ExampleScript_Text_2::
    .string "Choice 2$"
```

Here is a look at the macro and it's arguments:
`dynmultichoice left:req, top:req, ignoreBPress:req, maxBeforeScroll:req, initialSelected:req, callbacks:req argv:vararg`

| Argument        | Expected Value | Explanation                                                                                      |
| :---------------:| :--------------:| --------------------------------------------------------------------------------------------------|
| left            | Integer        | Determines the x-coordinate of where your menu starts from its top-left corner                   |
| top             | Integer        | Determines the y-coordinate of where your menu starts from its top-left corner                   |
| ignoreBPress    | True/False     | Controls whether the player can exit using the B button. If set to true, the player cannot exit. |
| maxBeforeScroll | Integer        | Shows how many options are shown before the player has to scroll.                                |
| initialSelected | Integer        | Chooses which option (from a 0-index) is already selected upon opening the menu.                 |
| callbacks       | Constant       | Designates which callback constants are used. Elaborated more later                              |
| argv            | String         | The choices that the player can choose from the menu.                                            |

