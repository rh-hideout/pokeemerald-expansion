# How to localize the game

The ROM is translated at **build time**. Text and graphics for each language
live under `localization/`. When you run `make LANG=es`, the build generates
and validates tables from those files, and `preproc` swaps the translated text
in while it compiles. English is the code itself, so `make` with no `LANG` builds
the same ROM as before.

Supported languages: `en` (source), `es` (Spanish), `pt` (Portuguese),
`fr` (French).

## Building

| Command | Output |
| --- | --- |
| `make` / `make LANG=en` | `pokeemerald.gba` |
| `make LANG=es` or `make rom-es` | `pokeemerald-es.gba` |
| `make rom-pt BUILD=firered` | `pokefirered-pt.gba` |
| `make roms-all` | one ROM per language |
| `make release LANG=fr` | `pokeemerald-fr-release.gba` |

Each language builds into its own object directory (`build/emerald-es`, ...),
so switching languages doesn't throw away the other builds.
`GAME_LANGUAGE` is set to the language's ID (`LANGUAGE_SPANISH`, ...).
This ID is stored in the Pokémon you catch and in mail, and it is used by
trade and record-mixing code.

> `LANG` is also the name of your shell's locale variable (for example
> `en_US.UTF-8`). The build ignores the value that comes from the environment.
> Pass the game language on the command line (`make LANG=es`), or put
> `LANG := es` in `config.mk`.

Other switches:

* `LOC_STRICT=1` turns missing or stale translations into errors. Use it for
  release builds.
* `LOC_VERBOSE=1` prints every warning, not just the first 40.

Every run writes the full report to `build/loc/<lang>/report.txt`.

## Translating text

### The CSV files

`make loc-extract` scans the code and keeps one CSV per source file in
`localization/text/`, mirroring the source tree:

```
localization/text/data/maps/PetalburgCity/scripts.inc.csv
localization/text/data/text/surf.inc.csv
localization/text/src/data/items.h.csv
localization/text/src/strings.c.csv
```

```csv
key,context,max_width,en,es,pt,fr,status
PetalburgCity_Text_WallyHouseSign,,,WALLY'S HOUSE,CASA DE WALLY,CASA DO WALLY,MAISON DE WALLY,
gItemsInfo[ITEM_POTION].name,,,Potion,Poción,Poção,Potion,
```

| Column | Meaning |
| --- | --- |
| `key` | Where the text lives in the code (see below). Don't edit it. |
| `context` | Free-form notes for translators. Kept by `loc-extract`. |
| `max_width` | Optional pixel limit per line, overriding `rules.json`. |
| `en` | The source text, copied from the code by `loc-extract`. Don't edit it here; edit the code. |
| `es`, `pt`, `fr` | Translations. An empty cell falls back to English. |
| `status` | `stale:es,pt` means the English text changed after it was translated, so review it and clear the flag. `obsolete` means the key no longer exists in the code. |

Edit the files with any spreadsheet program or text editor, saved as UTF-8
CSV.

### Keys

Keys are the names the text already has in the code:

| Code | Key |
| --- | --- |
| `PetalburgCity_Text_Hi:` followed by `.string` lines | `PetalburgCity_Text_Hi` |
| `static const u8 sText_Foo[] = _("...");` | `sText_Foo` |
| `[ITEM_POTION] = { .name = ITEM_NAME("Potion") }` inside `gItemsInfo` | `gItemsInfo[ITEM_POTION].name` |
| `sTexts[] = { COMPOUND_STRING("A"), COMPOUND_STRING("B") }` | `sTexts[0]`, `sTexts[1]` |
| A string inside a function body | `FunctionName@1a2b3c` (hash of the English text) |
| A string whose pieces are chosen by `#if`/`#else` | `key` and `key/alt2` (one row per variant) |
| The same key twice (e.g. in `#if`/`#else` declarations) | `key`, `key~2` |
| A trainer in `src/data/trainers.party` | `[DIFFICULTY_NORMAL][TRAINER_SAWYER_1].trainerName` in `trainers.party.csv` |

Strings with no letters, Japanese-only data, debug menus, and files ignored by
git are not extracted. The exception is generated headers that hold game
text, such as map names and trainer names. Those are listed under
`sources.generated` in `rules.json`. `make loc-extract` generates them first,
and their text is filed under the file they are generated from (via `#line`),
e.g. `trainers.party.csv`. Strings that can't be keyed are
listed in `localization/text/_skipped.txt`. Examples are text built with a
macro (`"for "BINDING_TURNS" turns"`) and strings inside `#define` bodies.

### Text syntax

Translations use exactly the same syntax as the code:

* **New lines:** `\n` (next line), `\l` (scroll a line), `\p` (new page).
  Don't put real line breaks in a cell.
* **Placeholders:** `{PLAYER}`, `{STR_VAR_1}`, `{B_ATK_NAME_WITH_PREFIX}`,
  `{DYNAMIC 0}`, ... A translation must contain the same placeholders as the
  English text, in any order.
* **Control codes:** `{COLOR RED}`, `{PAUSE 15}`, `{FONT_SMALL}`, ... You can
  move or drop these, but you'll get a warning.
* **No `$` at the end.** The terminator is added for you.
* Every character must exist in `charmap.txt`. Portuguese `ã õ Ã Õ` were added
  by `tools/localization/compose_glyphs.py`.

### Workflow

1. Change the game's text in the code as usual.
2. Run `make loc-extract`. It adds new keys, updates `en`, marks changed
   translations `stale`, and keeps rows for removed keys as `obsolete`.
   `make loc-extract PRUNE=1` deletes obsolete rows.
3. Translate the empty and stale cells, then clear `status` for the ones you
   reviewed.
4. Run `make LANG=es` (or `make loc-validate`) and fix any errors it reports.
5. Commit the CSVs.

`make loc-stats` shows coverage per language.

### Are my translations safe?

Only you write the translation columns. The build and `loc-validate` only
read the CSVs, and `loc-extract` only updates `en` and `status`.

* **English text changed:** the translation is kept and marked `stale`.
* **Key renamed or text edited:** this happens when a label or array index
  changes, or when a string inside a function is edited (its key is a hash of
  the text). `loc-extract` moves the translation to the new key when the rows
  are clearly the same string: same English text, the same function or field
  with similar text, or very similar text in the same file. Edited text is
  marked `stale` for review.
* **Anything it can't pair** stays as an `obsolete` row with its translation,
  so you can copy it by hand.

Only two commands remove or overwrite translations:

* `make loc-extract PRUNE=1` deletes obsolete rows.
* `loc.py seed --force` overwrites filled cells. `make loc-seed` never does.

Commit the CSVs before running either of them.

`make loc-seed LANG=xx SEED=pseudo` fills empty cells with accented
pseudo-text. This is handy for spotting untranslated or hard-coded text in a
test ROM. Only accents that are no wider than their base letter are used, so
the result still passes width validation. `SEED=copy` copies the English text
instead.

## Validation

Every non-English build validates first and stops on errors. The format is
`file.csv:line: error: KEY [lang]: message`.

| Check | Example |
| --- | --- |
| Character set | `character 'Ж' (U+0416) is not in charmap.txt` |
| Placeholders | `placeholders differ from the source text: missing {PLAYER}` |
| Control codes (warning) | `control codes differ from the source text: missing {PAUSE 15}` |
| Line commands | `ends with a line command '\n'`, `must not end with '$'`, `contains a literal line break` |
| Pixel width | `line is 214px wide in FONT_NORMAL, limit is 208px: "..."` |
| Lines per page | `a page has 3 lines, the text box shows 2; split it with \p` |
| Fixed-length buffers | `needs 24 bytes, buffer holds 21` (also `.string "...", N` padding) |
| Stale source (warning) | `source text changed since the CSV was updated` |
| Missing (warning, or error with `LOC_STRICT=1`) | counted in the summary and listed in `report.txt` |

Widths are measured with the game's own glyph widths from `src/fonts.c`,
following `GetStringWidth()`. Placeholders count as their worst-case length.
A translation is never held to a tighter limit than the English text already
uses.

### `localization/rules.json`

* `languages`: code → display name and `LANGUAGE_*` constant. Also update
  `LOC_LANGUAGES` in `localization.mk` when adding a language.
* `sources`: what `loc-extract` scans (`c`, `asm`, and `generated` headers),
  and what it excludes.
* `string_macros`: macros that wrap a string (e.g. `ITEM_NAME`) and their
  byte limit.
* `buffers`: byte limits by key pattern, e.g. `gMovesInfo[*].name` →
  `MOVE_NAME_LENGTH + 1`. Limits are also detected automatically from
  `u8 name[N]` declarations and from `u8` struct fields with a single known
  size.
* `text_rules`: font, `max_width` and `max_lines` by file/key pattern. The
  default rule covers field message boxes: `FONT_NORMAL`, 208px, two lines
  per page.
* `placeholder_chars`: the worst-case length used to measure each
  placeholder.

## Localizing graphics

### Replacing a whole image

Put the translated image at `localization/locales/<lang>/` + the original path:

```
graphics/title_screen/press_start.png
localization/locales/es/graphics/title_screen/press_start.png
```

The override must have the same width, height and bit depth as the original,
and no more palette colors. It replaces the original wherever it is used with
`INCGFX_*` or `INCBIN_*` in C. Assets with a custom conversion rule in a
`*_rules.mk` file are converted with the generic rule, and you get a warning
about it. Graphics included from assembly with `.incbin` can't be overridden.

### Rendering text into a reserved part of a tilemap

Many screens have words drawn into their tiles. For those, reserve the tiles
under the word and let the build draw the translation with the game's font.

1. Add the text to `localization/assets.csv`:

   ```csv
   key,context,max_width,en,es,pt,fr,status
   SUMMARY_PAGE_INFO_TITLE,Summary screen: title of the info page,,PROFILE,PERFIL,PERFIL,PROFIL,
   ```

2. Describe where it goes in `localization/graphics.json`:

   ```json
   {
       "key": "SUMMARY_PAGE_INFO_TITLE",
       "image": "graphics/summary_screen/tiles.png",
       "tilemap": "graphics/summary_screen/page_info.bin",
       "rect": { "x": 12, "y": 3, "w": 8, "h": 1 },
       "font": "FONT_SMALL",
       "colors": { "fg": 2, "shadow": 6, "bg": 7 },
       "x_offset": 2,
       "y_offset": -4
   }
   ```

   | Field | Meaning |
   | --- | --- |
   | `rect` | The reserved area, in tilemap cells (`tilemap_width` defaults to 32). Leave out `tilemap` to give it in image pixels instead, aligned to 8. |
   | `colors` | Palette indices of the image used for the text, its shadow and the background. |
   | `x_offset`, `y_offset`, `align` | Placement inside the area (`left`, `center` or `right`). Fonts sit in 16px cells; `y_offset: -4` lifts `FONT_SMALL` capitals into an 8px row. |
   | `tile_base` | Subtract this from tilemap entries when the image is loaded after other tiles. |
   | `check_tilemaps` | Other tilemaps that show this image, to check the reserved tiles aren't used elsewhere. |
   | `render_source_language` | Also redraw for English (off by default, so the English art stays as drawn). |

The text is drawn on a single line. The build checks that:

* every cell in the area uses its own tile;
* no reserved tile is flipped;
* no reserved tile appears anywhere else in the listed tilemaps;
* the text fits the area.

Then it draws the text, on top of an image override if there is one.

## How it works

```
code ──loc.py extract──▶ localization/text/**.csv
CSV + charmap + fonts ──loc.py generate (validates)──▶ build/loc/<lang>/
    strings/<source>.tbl   per-source-file replacement tables
    gfx/<path>.png         localized images (overrides + rendered text)
    overlay.stamp          changes when the set of files above changes
preproc -t strings -L gfx  substitutes text and redirects INCGFX/INCBIN
scaninc -t strings -L gfx  adds those files as dependencies
```

* A C string (`_()`, `__()`, `COMPOUND_STRING()`) is matched by its source
  file and the hash of its encoded bytes, with the line number breaking ties.
  That way macros that repeat a string, like `ITEM_NAME`, are all replaced
  together.
* An assembly `.string` line is matched by file and line. If the source line
  changed since the table was made, preproc refuses to build with
  `localization table is out of date`.
* Editing one CSV only rebuilds the objects that include that source file.

The tools are plain Python 3 (`tools/localization/`, standard library only):

| Command | Purpose |
| --- | --- |
| `loc.py extract` | Sync the CSVs with the code |
| `loc.py seed LANG` | Add or fill a language column |
| `loc.py generate --lang LANG --out DIR` | Validate and emit build inputs (run by `make`) |
| `loc.py validate` | Validate without building |
| `loc.py stats` | Coverage |
| `loc.py audit-concat` | List messages assembled from fragments (see below) |

Run `make loc-test` for the tool's unit tests.

## Writing translatable code

Word order differs between languages, so build a sentence from **one** format
string instead of gluing pieces together:

```c
// Don't: fixes the English word order
StringCopy(gStringVar4, playerName);
StringAppend(gStringVar4, sText_HasNoBerriesToPut);   // " has no BERRIES..."

// Do: one translatable sentence
static const u8 sText_HasNoBerriesToPut[] = _("{DYNAMIC 0} has no BERRIES to put in\nthe BERRY BLENDER.");
StringFormat1(gStringVar4, sText_HasNoBerriesToPut, playerName);
```

`StringFormat()` (`include/localization.h`) fills `{DYNAMIC 0}` to
`{DYNAMIC 3}` without touching `gStringVar1-3`. `StringExpandPlaceholders()`
with `{STR_VAR_n}` works too. `make loc-audit` lists the remaining places that
build a message from fragments.

Use `LOC_IS(LANGUAGE_FRENCH)` for the rare logic that really depends on the
language, such as number formats.
