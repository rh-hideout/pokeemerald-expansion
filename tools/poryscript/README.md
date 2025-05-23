# Poryscript

[![Actions Status](https://github.com/huderlem/poryscript/workflows/Go/badge.svg)](https://github.com/huderlem/poryscript/actions) [![codecov](https://codecov.io/gh/huderlem/poryscript/branch/master/graph/badge.svg)](https://codecov.io/gh/huderlem/poryscript)


Use the online [Poryscript Playground](http://www.huderlem.com/poryscript-playground/) to test it out.

Poryscript is a higher-level scripting language that compiles into the scripting language used in [pokeemerald](https://github.com/pret/pokeemerald), [pokefirered](https://github.com/pret/pokefirered), and [pokeruby](https://github.com/pret/pokeruby). It makes scripting faster and easier. Some advantages of using Poryscript are:
1. Branching control flow with `if`, `elif`, `else`, `while`, `do...while`, and `switch` statements.
2. Inline text
3. Auto-formatting text to fit within the in-game text box
4. Better map script organization

View the [Changelog](https://github.com/huderlem/poryscript/blob/master/CHANGELOG.md) to see what's new, and download the latest version from the [Releases](https://github.com/huderlem/poryscript/releases).

**Table of Contents**
- [Usage](#usage)
  * [Convert Existing Scripts](#convert-existing-scripts)
- [Poryscript Syntax (How to Write Scripts)](#poryscript-syntax-how-to-write-scripts)
  * [`script` Statement](#script-statement)
    + [Boolean Expressions](#boolean-expressions)
    + [`while` and `do...while` Loops](#while-and-dowhile-loops)
    + [Conditional Operators](#conditional-operators)
    + [Regular Commands](#regular-commands)
    + [Early-Exiting a Script](#early-exiting-a-script)
    + [`switch` Statement](#switch-statement)
    + [Labels](#labels)
  * [`text` Statement](#text-statement)
    + [Automatic Text Formatting](#automatic-text-formatting)
    + [Custom Text Encoding](#custom-text-encoding)
  * [`movement` Statement](#movement-statement)
  * [`mart` Statement](#mart-statement)
  * [`mapscripts` Statement](#mapscripts-statement)
  * [`raw` Statement](#raw-statement)
  * [Comments](#comments)
  * [Constants](#constants)
  * [Scope Modifiers](#scope-modifiers)
  * [AutoVar Commands](#autovar-commands)
  * [Compile-Time Switches](#compile-time-switches)
  * [Optimization](#optimization)
  * [Line Markers](#line-markers)
- [Local Development](#local-development)
  * [Building from Source](#building-from-source)
  * [Running the tests](#running-the-tests)
- [Versioning](#versioning)
- [License](#license)
- [Acknowledgments](#acknowledgments)


# Usage
Poryscript is a command-line program.  It reads an input script and outputs the resulting compiled bytecode script. You can either feed it the input script from a file or from `stdin`.  Similarly, Poryscript can output a file or to `stdout`.

```
> ./poryscript -h
Usage of poryscript:
  -cc string
        command config JSON file (default "command_config.json")
  -f string
        set default font id (leave empty to use default defined in font config file)
  -fc string
        font config JSON file (default "font_config.json")
  -h    show poryscript help information
  -i string
        input poryscript file (leave empty to read from standard input)
  -l int
        set default line length in pixels for formatted text (uses font config file for default)
  -lm
        include line markers in output (enables more helpful error messages when compiling the ROM). (To disable, use '-lm=false') (default true)
  -o string
        output script file (leave empty to write to standard output)
  -optimize
        optimize compiled script size (To disable, use '-optimize=false') (default true)
  -s value
        set a compile-time switch. Multiple -s options can be set. Example: -s VERSION=RUBY -s LANGUAGE=GERMAN
  -v    show version of poryscript
```

Convert a `.pory` script to a compiled `.inc` script, which can be directly included in a decompilation project:
```
./poryscript -i data/scripts/myscript.pory -o data/scripts/myscript.inc
```

To automatically convert your Poryscript scripts when compiling a decomp project, perform these two steps:
1. Create a new `tools/poryscript/` directory, and add the `poryscript` command-line executable tool to it. Also copy `command_config.json` and `font_config.json` to the same location.
```
# For example, on Windows, place the files here.
pokeemerald/tools/poryscript/poryscript.exe
pokeemerald/tools/poryscript/command_config.json
pokeemerald/tools/poryscript/font_config.json
```
It's also a good idea to add `tools/poryscript` to your `.gitignore` before your next commit.

2. Update the Makefile with these changes (Note, don't add the `+` symbol at the start of the lines. That's just to show the line is being added.):
```diff
FIX := tools/gbafix/gbafix$(EXE)
MAPJSON := tools/mapjson/mapjson$(EXE)
JSONPROC := tools/jsonproc/jsonproc$(EXE)
+ SCRIPT := tools/poryscript/poryscript$(EXE)
```
```diff
mostlyclean: tidynonmodern tidymodern
	...
	rm -f $(AUTO_GEN_TARGETS)
	@$(MAKE) clean -C libagbsyscall
+	rm -f $(patsubst %.pory,%.inc,$(shell find data/ -type f -name '*.pory'))
```
```diff
%.s: ;
%.png: ;
%.pal: ;
%.aif: ;
+ %.pory: ;
```
```diff
sound/%.bin: sound/%.aif ; $(AIF) $< $@
+ data/%.inc: data/%.pory; $(SCRIPT) -i $< -o $@ -fc tools/poryscript/font_config.json
```

## Convert Existing Scripts
If you're working on a large project, you may want to convert all of the existing `scripts.inc` files to their `scripts.pory` equivalents. Since there are a large number of script files in the Gen 3 projects, you can save yourself a lot of time by following these instructions. **Again, this is completely optional, and you would only want to perform this bulk conversion if you're emabarking on large project where it would be useful to have all the existing scripts setup as Poryscript files.**

<details>
  <summary>Click Here to View Instructions</summary>

  Convert all of your projects old map `scripts.inc` files into new `scripts.pory` files while maintaining the old scripts:

  1. Create a file in your `pokeemerald/` directory named `convert_inc.sh` with the following content:
     ```
     #!/bin/bash

     for directory in data/maps/* ; do
     	pory_exists=$(find $directory -name $"scripts.pory" | wc -l)
     	if [[ $pory_exists -eq 0 ]]; 
     	then
     		inc_exists=$(find $directory -name $"scripts.inc" | wc -l)
     		if [[ $inc_exists -ne 0 ]]; 
     		then
     			echo "Converting: $directory/scripts.inc"
     			touch "$directory/scripts.pory"
     			echo 'raw `' >> "$directory/scripts.pory"
     			cat "$directory/scripts.inc" >> "$directory/scripts.pory"
     			echo '`' >> "$directory/scripts.pory"
     		fi
     	fi 	
     done
     ```
  
  2. Run `chmod 777 convert_inc.sh` to ensure the script executable. 

  Finally you can execute it in your `pokeemerald/` directory by running `./convert_inc.sh` or `bash convert_inc.sh` in the console. This script will iterate through all your `data/map/` directories and convert the `scripts.inc` files into `scripts.pory` files by adding a `raw` tag around the old scripts. `convert_inc.sh` will skip over any directories that already have `scripts.pory` files in them, so that it will not overwrite any maps that you have already switched over to Poryscript.
</details>

# Poryscript Syntax (How to Write Scripts)

A single `.pory` file is composed of many top-level statements. The valid top-level statements are `script`, `text`, `movement`, `mart`, `mapscripts`, and `raw`.
```
mapscripts MyMap_MapScripts {
    ...
}

script MyScript {
    ...
}

text MyText {
    "Hi, I'm some text.\n"
    "I'm global and can be accessed in C code."
}

movement MyMovement {
    walk_left
    walk_right * 3
}

mart MyMart {
    ITEM_POTION
    ITEM_POKEBALL
}

raw `
MyLocalText:
    .string "I'm directly included.$"
`
```

## `script` Statement
The `script` statement creates a global script containing script commands and control flow logic.  Here is an example:
```
script MyScript {
    # Show a different message, depending on the state of different flags.
    lock
    faceplayer
    if (flag(FLAG_RECEIVED_TOP_PRIZE)) {
        msgbox("You received the best prize!")
    } elif (flag(FLAG_RECEIVED_WORST_PRIZE)) {
        msgbox("Ouch, you received the worst prize.")
    } else {
        msgbox("Hmm, you didn't receive anything.")
    }
    release
    end
}
```

As you can see, using `if` statements greatly simplifies writing scripts because it does not require the author to manually define new sub-labels with `goto` statements everywhere.

`if` statements can be nested inside each other, as you would expect.
```
    if (flag(FLAG_TEMP) == true) {
        if (var(VAR_BADGES) < 8) {
            ...
        } else {
            ...
        }
    }
```

Note the special keyword `elif`.  This is just the way Poryscript specifies an "else if". Many `elif` statements can be chained together.

### Boolean Expressions
Compound boolean expressions are also supported. This means you can use the AND (`&&`) and OR (`||`) logical operators to combine expressions. For example:
```
    # Basic AND of two conditions.
    if (!defeated(TRAINER_MISTY) && var(VAR_TIME) != DAY) {
        msgbox("The Cerulean Gym's doors don't\n"
               "open until morning.")
    }
    ...
    # Group nested conditions together with another set of parentheses.
    if (flag(FLAG_IS_CHAMPION) && !(flag(FLAG_SYS_TOWER_GOLD) || flag(FLAG_SYS_DOME_GOLD))) {
        msgbox("You should try to beat the\n"
               "Battle Tower or Battle Dome!")
    }
```

### `while` and `do...while` Loops
`while` statements are used to do loops.  They can be nested inside each or inside `if` statements, as one would expect.
```
    # Force player to answer "Yes" to NPC question.
    msgbox("Do you agree to the quest?", MSGBOX_YESNO)
    while (var(VAR_RESULT) != 1) {
        msgbox("...How about now?", MSGBOX_YESNO)
    }
    setvar(VAR_QUEST_ACCEPTED, 1)
```

The `while` statement can also be written as an infinite loop by omitting the boolean expression. This would be equivalent to `while(true)` in typical programming languages. (Of course, you'll want to `break` out of the infinite loop, or hard-stop the script.)
```
    while {
        msgbox("Want to see this message again?", MSGBOX_YESNO)
        if (var(VAR_RESULT) != 1) {
            break
        }
    }
```

`do...while` statements are very similar to `while` statements.  The only difference is that they always execute their body once before checking the condition.
```
    # Force player to answer "Yes" to NPC question.
    do {
        msgbox("Can you help me solve the puzzle?", MSGBOX_YESNO)
    } while (var(VAR_RESULT) == 0)
```

`break` can be used to break out of a loop, like many programming languages. Similary, `continue` returns to the start of the loop.

### Conditional Operators
The condition operators have strict rules about what conditions they accept. The operand on the left side of the condition must be a `flag()`, `var()`, `defeated()`, or [AutoVar](#autovar-commands) check. They each have a different set of valid comparison operators, described below.

| Type | Valid Operators |
| ---- | --------------- |
| `flag` | `==` |
| `var` or [AutoVar](#autovar-commands) | `==`, `!=`, `>`, `>=`, `<`, `<=` |
| `defeated` | `==` |

All operators support implicit truthiness, which means you don't have to specify any of the above operators in a condition. Below are some examples of equivalent conditions:
```
# Check if the flag is set.
if (flag(FLAG_1))
if (flag(FLAG_1) == true)

# Check if the flag is cleared.
if (!flag(FLAG_1))
if (flag(FLAG_1) == false)

# Check if the var is not equal to 0.
if (var(VAR_1))
if (var(VAR_1) != 0)

#Check if the var is equal to 0.
if (!var(VAR_1))
if (var(VAR_1) == 0)

# Check if the trainer has been defeated.
if (defeated(TRAINER_GARY))
if (defeated(TRAINER_GARY) == true)

# Check if the trainer hasn't been defeated.
if (!defeated(TRAINER_GARY))
if (defeated(TRAINER_GARY) == false)
```

When not using implicit truthiness, like in the above examples, they each have different valid comparison values on the right-hand side of the condition.

| Type | Valid Comparison Values |
| ---- | --------------- |
| `flag` | `TRUE`, `true`, `FALSE`, `false` |
| `var` | any value (e.g. `5`, `VAR_TEMP_1`, `VAR_FOO + BASE_OFFSET`) |
| `defeated` | `TRUE`, `true`, `FALSE`, `false` |

One quirk of the Gen 3 decomp scripting engine is that using the `compare` scripting command with a value in the range `0x4000 <= x <= 0x40FF` or `0x8000 <= x <= 0x8015` will result in comparing against a `var`, rather than the raw value. To force the comparison against a raw value, like `0x4000`, use the `value()` operator.  For example:

```
if (var(VAR_DAMAGE_DEALT) >= value(0x4000))
```

The resulting script use the `compare_var_to_value` command, rather than the usual `compare` command.

### Regular Commands
Regular non-branching commands that take arguments, such as `msgbox`, must wrap their arguments in parentheses. For example:
```
    lock
    faceplayer
    addvar(VAR_TALKED_COUNT, 1)
    msgbox("Hello.")
    release
    end
```

### Early-Exiting a Script
Use `end` or `return` to early-exit out of a script.
```
script MyScript {
    if (flag(FLAG_WON) == true) {
        end
    }
    ...
}
```

### `switch` Statement
A `switch` statement is an easy way to separate different logic for a set of concrete values. Poryscript `switch` statements behave similarly to other languages. However, the cases `break` implicitly. It is not possible to "fall through" to the next case by omitting a `break` at the end of a case, like in C. You *can* use `break` to break out of a case, though--it's just not required. Multiple cases can be designated by listing them immediately after another without a body. Finally, an optional `default` case will take over if none of the provided `case` values are met.  A `switch` statement's comparison value *must always be a `var()` operator*.  Of course, `switch` statements can appear anywhere in the script's logic, such as inside `while` loops, or even other `switch` statements.

```
    switch (var(VAR_NUM_THINGS)) {
        case 0:
            msgbox("You have 0 things.")
        case 1:
        case 2:
            msgbox("You have 1 or 2 things.")
        default:
            msgbox("You have at least 3 things.")
    }
```

### Labels
Labels can be defined inside a `script`, and they are very similar to C's `goto` labels. A label isn't usually desired or needed when writing Poryscript scripts, but it can be useful and in certain situations where you might want to jump to a common part of your script from several different places. To write a label, simply add a colon (`:`) after a name anywhere inside a `script`. Labels are rendered as regular assembly labels, and they can be marked as local or global. By default, labels have local scope, but they can be changed to global scope using the same syntax as other statements (e.g. `MyLabel(global):`).

Label Example:
```
// Note, this is a bad example of where a
// label would be useful.
script MyScript {
    lockall
    if (flag(FLAG_TEST)) {
        goto(MyScript_End)
    } elif (flag(FLAG_OTHER_TEST)) {
        addvar(VAR_SCORE, 1)
        goto(MyScript_End)
    }

MyScript_End:
    releaseall
}
```

## `text` Statement
Use `text` to include text that's intended to be shared between multiple scripts or in C code. The `text` statement is just a convenient way to write chunks of text, and it exports the text globally, so it is accessible in C code. Currently, there isn't much of a reason to use `text`, but it will be more useful in future updates of Poryscript.
```
script MyScript {
    msgbox(MyText)
}

text MyText {
    "Hello, there.\p"
    "You can refer to me in scripts or C code."
}
```
A small quality-of-life feature is that Poryscript automatically adds the `$` terminator character to text, so the user doesn't need to manually type it all the time.

### Automatic Text Formatting
Text auto-formatting is also supported by Poryscript. The `format()` function can be wrapped around any text, either inline or `text`, and Poryscript will automatically fit the text to the size of the in-game text window by inserting automatic line breaks. A simple example:
```
msgbox(format("Hello, this is some long text that I want Poryscript to automatically format for me."))
```
Becomes:
```
.string "Hello, this is some long text that I\n"
.string "want Poryscript to automatically\l"
.string "format for me.$"
```
Like other text, formatted text can span multiple lines if you use a new set of quotes for each line. You can also manually add your own line breaks (`\p`, `\n`, `\l`), and it will still work as expected.
```
text MyText {
    format("Hello, are you the real-live legendary {PLAYER} that everyone talks about?\p"
           "Amazing!\pSo glad to meet you!")
}
```
Becomes:
```
.string "Hello, are you the real-live legendary\n"
.string "{PLAYER} that everyone talks about?\p"
.string "Amazing!\p"
.string "So glad to meet you!$"
```

Additionally, `format()` supports a special line break `\N`, which will automatically insert the appropriate `\n` or `\l` line break. While this is an uncommon use case, it's useful in situations where a line break is desired for dramatic/stylistic purposes. In the following example, we want explicit line breaks for the `"..."` texts, but we don't know if the first one should use `\n` or `\l`. Using `\N` makes it easy:
```
text MyText {
    format("You are my favorite trainer!\N...\N...\N...\NBut I'm better!")
}
```

The font id can optionally be specified as the second parameter to `format()`.
```
text MyText {
    format("Hello, are you the real-live legendary {PLAYER} that everyone talks about?\pAmazing!\pSo glad to meet you!", "1_latin_rse")
}
```
Becomes:
```
.string "Hello, are you the real-live legendary\n"
.string "{PLAYER} that everyone talks about?\p"
.string "Amazing!\p"
.string "So glad to meet you!$"
```
The font configuration JSON file informs Poryscript how many pixels wide each character in the message is, as well as setting a default maximum line length. Fonts have different character widths, and games have different text box sizes. For convenience, Poryscript comes with `font_config.json`, which contains the configuration for pokeemerald's `1_latin` font as `1_latin_rse`, as well as pokefirered's equivalent as `1_latin_frlg`. More fonts can be added to this file by simply creating anothing font id node under the `fonts` key in `font_config.json`.

`cursorOverlapWidth` can be used to ensure there is always enough room for the cursor icon to be displayed in the text box. (This "cursor icon" is the small icon that's shown when the player needs to press A to advance the text box.)

`numLines` is the number of lines displayed within a single message box. If editing text for a taller space, this can be adjusted in `font_config.json`.

The length of a line can optionally be specified as the third parameter to `format()` if a font id was specified as the second parameter.

```
text MyText {
    format("Hello, are you the real-live legendary {PLAYER} that everyone talks about?\pAmazing!\pSo glad to meet you!", "1_latin_rse", 100)
}
```
Becomes:
```
.string "Hello, are you the\n"
.string "real-live\l"
.string "legendary\l"
.string "{PLAYER} that\l"
.string "everyone talks\l"
.string "about?\p"
.string "Amazing!\p"
.string "So glad to meet\n"
.string "you!$"
```

Finally, `format()` takes the following optional named parameters, which override settings from the font config:
- `fontId`
- `maxLineLength`
- `numLines`
- `cursorOverlapWidth`
```
text MyText {
    format("This is an example of named parameters!", numLines=3, maxLineLength=100)
}
```

### Custom Text Encoding
When Poryscript compiles text, the resulting text content is rendered using the `.string` assembler directive. The decomp projects' build process then processes those `.string` directives and substituted the string characters with the game-specific text representation. It can be useful to specify different types of strings, though. For example, implementing print-debugging commands might make use of ASCII text. Poryscript allows you to specify which assembler directive to use for text. Simply add the directive as a prefix to the string content like this:
```
ascii"My ASCII string."
custom"My Custom string."

// compiles to...
.ascii "My ASCII string.\0"
.custom "My Custom string."
```

Note that Poryscript will automatically add the `\0` suffix character to ASCII strings. It will **not** add suffix to any other directives.

## `movement` Statement
Use `movement` statements to conveniently define movement data that is typically used with the `applymovement` command. `*` can be used as a shortcut to repeat a single command many times. Data defined with `movement` is created with local scope, not global.
```
script MyScript {
    lock
    applymovement(2, MyMovement)
    waitmovement(0)
    release
}
movement MyMovement {
    walk_left
    walk_up * 5
    face_down
}
```
Becomes:
```
MyScript::
	lock
	applymovement 2, MyMovement
	waitmovement 0
	release
	return

MyMovement:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end
```

## `mart` Statement
Use `mart` statements to define a list of items for use with the `pokemart` command. Data defined with the `mart` statement is created with local scope by default. It is not neccesary to add `ITEM_NONE` to the end of the list, but if Poryscript encounters it, any items after it will be ignored.

```
script ScriptWithPokemart {
	lock
	message("Welcome to my store.")
	waitmessage
	pokemart(MyMartItems)
	msgbox("Come again soon.")
	release
}

mart MyMartItems {
	ITEM_LAVA_COOKIE
	ITEM_MOOMOO_MILK
	ITEM_RARE_CANDY
	ITEM_LEMONADE
	ITEM_BERRY_JUICE
}
```

Becomes:
```
ScriptWithPokemart::
	lock
	message ScriptWithPokemart_Text_0
	waitmessage
	pokemart MyMartItems
	msgbox ScriptWithPokemart_Text_1
	release
	return

	.align 2
MyMartItems:
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_LEMONADE
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_NONE

ScriptWithPokemart_Text_0:
	.string "Welcome to my store.$"

ScriptWithPokemart_Text_1:
	.string "Come again soon.$"
```

## `mapscripts` Statement
Use `mapscripts` to define a set of map script definitions. Scripts can be inlined for convenience, or a label to another script can simply be specified. Some map script types, like `MAP_SCRIPT_ON_FRAME_TABLE`, require a list of comparison variables and scripts to execute when the variable's value is equal to some value. In these cases, you use brackets `[]` to specify that list of scripts. Below is a full example showing map script definitions for a new map called `MyNewCity`:
```
mapscripts MyNewCity_MapScripts {
    MAP_SCRIPT_ON_RESUME: MyNewCity_OnResume
    MAP_SCRIPT_ON_TRANSITION {
        random(2)
        switch (var(VAR_RESULT)) {
            case 0: setweather(WEATHER_ASH)
            case 1: setweather(WEATHER_RAIN_HEAVY)
        }
    }
    MAP_SCRIPT_ON_FRAME_TABLE [
        VAR_TEMP_0, 0: MyNewCity_OnFrame_0
        VAR_TEMP_0, 1 {
            lock
            msgbox("This script is inlined.")
            setvar(VAR_TEMP_0, 2)
            release
        }
    ]
}

script MyNewCity_OnResume {
    ...
}

script MyNewCity_OnFrame_0 {
    ...
}
```

For maps with no map scripts, simply make an empty `mapscripts` statement:
```
mapscripts MyNewCity_MapScripts {}
```

## `raw` Statement
Use `raw` to include raw bytecode script. Anything in a `raw` statement will be directly included into the compiled script. This is useful for defining custom data, or data types not supported in regular Poryscript.
```
raw `
TestMap_MapScripts::
	.byte 0
`

script MyScript {
    lock
    faceplayer
    # Text can span multiple lines. Use a new set of quotes for each line.
    msgbox("This is shorter text,\n"
           "but we can still put it\l"
           "on multiple lines.")
    applymovement(OBJ_EVENT_ID_PLAYER, MyScript_Movement)
    waitmovement(0)
    msgbox(MyScript_LongText)
    release
    end
}

raw `
MyScript_Movement:
    walk_left
    walk_down
    step_end

MyScript_LongText:
    .string "Hi, there.\p"
    .string "This text is too long\n"
    .string "to inline above.\p"
    .string "We'll put it down here\n"
    .string "instead, so it's out of\l"
    .string "the way.$"
`
```

## Comments
Use single-line comments with `#` or `//`. Everything after the `#` or `//` will be ignored. Comments cannot be placed in a `raw` statement. (Users who wish to run the C preprocessor on Poryscript files should use `//` comments to avoid conflict with C preprocessor directives that use the `#` character.)
```
# This script does some cool things.
script MyScript {
    // This is also a valid comment.
    ...
}
```

## Constants
Use `const` to define constants that can be used in the current script. This is especially useful for giving human-friendly names to event object ids, or temporary flags. Constants must be defined before they are used. Constants can also be composed of previously-defined constants.
```
const PROF_BIRCH_ID = 3
const ASSISTANT_ID = PROF_BIRCH_ID + 1
const FLAG_GREETED_BIRCH = FLAG_TEMP_2

script ProfBirchScript {
    applymovement(PROF_BIRCH_ID, BirchMovementData)
    showobject(ASSISTANT_ID)
    setflag(FLAG_GREETED_BIRCH)
}
```

Note that these constants are **not** a general macro system. They can only be used in certain places in Poryscript syntax. Below is an example of all possible places where constants can be substituted into the script:
```
const CONSTANT = 1

mapscripts MyMapScripts {
    MAP_SCRIPT_ON_FRAME_TABLE [
        // The operand and comparison values can both use constants in a
        // table-based map script.
        CONSTANT, CONSTANT: MyOnFrameScript_0
    ]
}

script MyScript {
    // Any parameter of any command can use constants.
    somecommand(CONSTANT)

    // Any comparison operator can use constants, as well as their comparison values.
    if (flag(CONSTANT)) {}
    if (var(CONSTANT) == CONSTANT) {}
    if (defeated(CONSTANT)) {}

    // A switch var value can be a constant, as well as the individual cases.
    switch (var(CONSTANT)) {
        case CONSTANT: break
    }
}
```

## Scope Modifiers
To control whether a script should be global or local, a scope modifier can be specified. This is supported for `script`, `text`, `movement`, and `mapscripts`. In this context, "global" means that the label will be defined with two colons `::`.  Local scopes means one colon `:`.
```
script(global) MyGlobalScript {
    ...
}
script(local) MyLocalScript {
    ...
}
```
Becomes:
```
MyGlobalScript::
    ...

MyLocalScript:
    ...
```

The top-level statements have different default scopes. They are as follows:

| Type | Default Scope |
| ---- | --------------- |
| `script` | Global |
| `text` | Global |
| `movement` | Local |
| `mart` | Local |
| `mapscripts` | Global |

## AutoVar Commands
Some scripting commands always store their result in the same variable. For example, `checkitem` always stores its result in `VAR_RESULT`. Poryscript can simplify working with these commands with a concept called "AutoVar" commands.

*Without* using an AutoVar, a script would be written like this:
```
checkitem(ITEM_ROOT_FOSSIL)
if (var(VAR_RESULT) == TRUE) {
    // player has the Root Fossil
}
```

However, AutoVars can be used *inside* the condition, which helps streamline the script:
```
if (checkitem(ITEM_ROOT_FOSSIL) == TRUE) {
    // player has the Root Fossil
}
```

AutoVars can be used ***anywhere*** a `var()` operator can be used.  e.g. `if` conditions, `switch` statements--any boolean expression!

### Defining AutoVar Commands
AutoVar commands are fully configurable with the `command_config.json` file.  Use the `-cc` command line parameter to specifying the location of that config.

There are two types of AutoVar commands:
1. Implicit
    - The stored var is defined in the config file, and is not present in the authored script.
    - Examples: `checkitem`, `getpartysize`, `random`
2. Explicit
    - The stored var is provided as part of the command, and the config file stores the 0-based index of the command that specifies the stored var.
    - Examples: `specialvar`, `checkcoins`

Let's take a look at the example config file:
```json
// command_config.json
{
    "autovar_commands": {
        "specialvar": {
            "var_name_arg_position": 0
        },
        "checkitem": {
            "var_name": "VAR_RESULT"
        },
    ...
}
```

With the above config, a script could be written like so:
```
if (checkitem(ITEM_POKEBLOCK_CASE)) {
    if (specialvar(VAR_RESULT, GetFirstFreePokeblockSlot) != -1 && 
        specialvar(VAR_RESULT, PlayerHasBerries)
    ) {
        msgbox("Great! You can use the Berry Blender!)
    }
} else {
    msgbox("You don't have a Pokeblock case!")
}
```

## Compile-Time Switches
Use the `poryswitch` statement to change compiler behavior depending on custom switches. This makes it easy to make scripts behave different depending on, say, the `GAME_VERSION` or `LANGUAGE`. Any content that does not match the compile-time switch will not be included in the final output. To define custom switches, use the `-s` option when running `poryscript`.  You can specify multiple switches, and each key/value pair must be separated by an equals sign. For example:

```
./poryscript -i script.pory -o script.inc -s GAME_VERSION=RUBY -s LANGUAGE=GERMAN
```

The `poryswitch` statement can be embedded into any script section, including `text`, `movement`, and `mart` statements. The underscore `_` case is used as the fallback, if none of the other cases match. Cases that only contain a single statement or command can be started with a colon `:`.  Otherwise, use curly braces to define the case's block.

Here are some examples of compile-time switches. This assumes that two compile-time switches are defined, `GAME_VERSION` and `LANGUAGE`.

```
script MyScript {
    lock
    faceplayer
    poryswitch(GAME_VERSION) {
        RUBY {
            msgbox("Here, take this Ruby Orb.")
            giveitem(ITEM_RUBY_ORB)
        }
        SAPPHIRE {
            msgbox("Here, take this Sapphire Orb.")
            giveitem(ITEM_SAPPHIRE_ORB)
        }
        _: msgbox(format("This case is used when GAME_VERSION doesn't match either of the above."))
    }
    release
}

text MyText {
    poryswitch(LANGUAGE) {
        GERMAN:  "Hallo. Ich spreche Deutsch."
        ENGLISH: "Hello. I speak English."
    }
}

movement MyMovement {
    face_player
    walk_down
    poryswitch(GAME_VERSION) {
        RUBY: walk_left * 2
        SAPPHIRE {
            walk_right * 2
            walk_left * 4
        }
    }
}

mart MyMart {
    ITEM_POTION
    ITEM_POKEBALL
    poryswitch(GAME_VERSION) {
        RUBY {
            ITEM_LAVA_COOKIE
            ITEM_RED_SCARF
        }
        SAPPHIRE {
            ITEM_FRESH_WATER
            ITEM_BLUE_SCARF
        }
    }
}
```

Note, `poryswitch` can also be embedded inside inlined `mapscripts` scripts.

## Optimization
By default, Poryscript produces optimized output. It attempts to minimize the number of `goto` commands and unnecessary script labels. To disable optimizations, pass the `-optimize=false` option to `poryscript`.

## Line Markers
By default, Poryscript includes [C Preprocessor line markers](https://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp_9.html) in the compiled output.  This improves error messages.  To disable line markers, specify `-lm=false` when invoking Poryscript.

# Local Development

These instructions will get you setup and working with Poryscript's code. You can either build the Poryscript tool from source, or simply download the latest release from the Releases tab on GitHub.

## Building from Source

First, install [Go](http://golang.org).  Poryscript has no additional dependencies.  It uses Go modules, so you shouldn't need to be located in a Go workspace.

Navigate to the Poryscript working directory, and build it:
```
cd your/path/to/poryscript
go build
```

This will create a `poryscript` executable binary in the same directory. Then you can simply install it into your project by running `./install.sh ../yourprojectname` instead of manually copying the files over, similarly to how agbcc is installed into projects.

## Running the tests

Poryscript has automated tests for its `emitter`, `parser`, and `lexer` packages. To run all of the tests from the base directory:
```
> go test ./...
?       github.com/huderlem/poryscript  [no test files]
?       github.com/huderlem/poryscript/ast      [no test files]
ok      github.com/huderlem/poryscript/emitter  0.523s
ok      github.com/huderlem/poryscript/lexer    0.273s
ok      github.com/huderlem/poryscript/parser   0.779s
?       github.com/huderlem/poryscript/token    [no test files]
```


# Versioning

Poryscript uses [Semantic Versioning](http://semver.org/). For the available versions, see the [tags on this repository](https://github.com/huderlem/poryscript/tags).

# License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

# Acknowledgments

* Thorsten Ball's *Writing An Interpreter In Go* helped bootstrap the lexer, AST, and parser for this project. A chunk of that code was derived and/or copied from that book, as I had never written something of this nature before.
