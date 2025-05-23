Version: 5.4.1
Date: March 21st, 2024

This version of porymap works with pokeruby and pokeemerald as of the following commit hashes:
* pokeemerald: c76beed98990a57c84d3930190fd194abfedf7e8
* pokefirered: 52591dcee42933d64f60c59276fc13c3bb89c47b
* pokeruby: d99cb43736dd1d4ee4820f838cb259d773d8bf25

Official Porymap documentation: https://huderlem.github.io/porymap/

Please report any issues on GitHub: [https://github.com/huderlem/porymap/issues](https://github.com/huderlem/porymap/issues)

-------------------------

## [5.4.1] - 2024-03-21
### Fixed
- Fix object event sprites not loading for some struct data formats.

## [5.4.0] - 2024-02-13
### Added
- Add a `Check for Updates` option to show new releases (Windows and macOS only).

### Changed
- If Wild Encounters fail to load they are now only disabled for that session, and the settings remain unchanged.
- Defaults are used if project constants are missing, rather than failing to open the project or changing settings.
- Selector images now center on the selection when eyedropping or zooming.

### Fixed
- Fix some minor visual issues with the various zoom sliders.
- Smooth out scrolling when mouse is over tile/metatile images.
- Fix the Tileset Editor selectors getting extra white space when changing tilesets.
- Fix a crash when adding disabled events with the Pencil tool.
- Fix error log about failing to find the scripts file when a new map is created.

## [5.3.0] - 2024-01-15
### Added
- Add zoom sliders to the Tileset Editor.
- Add `getMetatileBehaviorName` and `setMetatileBehaviorName` to the API.
- Add `metatile_behaviors`, `num_primary_palettes`, and `num_secondary_palettes` to `constants` in the API.

### Changed
- Metatile ID strings are now padded to their current max, not the overall max.
- Non-existent directories are now removed from the Open Recent Project menu.
- Hovering on the layer view in the Tileset Editor now displays the tile ID.
- Labels in the Script dropdown are now sorted alphabetically.
- The name of the Heal Locations table is no longer enforced.
- The API functions `addImage` and `createImage` now support project-relative paths.

### Fixed
- Fix the metatile selector rectangle jumping when selecting up or left of the origin.
- Fix the event group tabs sometimes showing an event from the wrong group.
- Fix the clear buttons in the Shortcuts Editor not actually removing shortcuts.
- Fix slow speed for the script label autcomplete.
- Fix deleted script labels still appearing in the autocomplete after project reload.
- Fix the map search bar stealing focus on startup.
- Fix border metatiles view not resizing properly.
- Fix Open Recent Project not clearing the API overlay
- Fix API error reporting.

## [5.2.0] - 2024-01-02
### Added
- Add an editor window under `Options -> Project Settings...` to customize the project-specific settings in `porymap.project.cfg` and `porymap.user.cfg`.
- Add an editor window under `Options -> Custom Scripts...` for Porymap's API scripts.
- Add an `Open Recent Project` menu
- Add a warning to warp events if they're on an incompatible metatile behavior.
- Add settings for custom images, including the collision graphics, default event icons, and pokémon icons.
- Add settings to override any symbol or macro names Porymap expects to find.
- Add a zoom slider to the Collision tab.
- Add toggleable grids to the Tileset Editor.
- Support for custom metatile ID, collision, and elevation data sizes.
- Support for 8bpp tileset tile images.

### Changed
- `Script` dropdowns now include scripts from the current map's scripts file.
- Encounter Rate now defaults to the most commonly used value, rather than 0.
- The Collision tab now allows selection of any valid elevation/collision value.
- The Palette Editor now remembers the Bit Depth setting.
- The min/max levels on the Wild Pokémon tab will now adjust automatically if they invalidate each other.
- If the recent project directory doesn't exist Porymap will open an empty project instead of failing with a misleading error message.
- Settings under `Options` were relocated either to the `Preferences` window or `Options -> Project Settings`.
- Secret Base and Weather Trigger events are automatically disabled if their respective constants files fail to parse, instead of not opening the project.
- If a Pokémon icon fails to load Porymap will attempt to predict its filepath. If this also fails it will appear with a placeholder icon, and won't disappear when edited.
- The bits in metatile attribute masks are now allowed to be non-contiguous.
- Porymap will now attempt to read metatile attribute masks from the project.

### Fixed
- Fix text boxes in the Palette Editor calculating color incorrectly.
- Fix metatile labels being sorted incorrectly for tileset names with multiple underscores.
- Fix default object sprites retaining dimensions and transparency of the previous sprite.
- Fix connections not being deleted when the map name text box is cleared.
- Fix the map border not updating when a tileset is changed.
- Improve the poor speed of the API functions `setMetatileTile` and `setMetatileTiles`.
- Stop the Tileset Editor from scrolling to the initially selected metatile when saving.
- Fix `0x0`/`NULL` appearing more than once in the scripts dropdown.
- Fix the selection outline sticking in single-tile mode on the Prefab tab.
- Fix heal location data being cleared if certain spaces aren't used in the table.
- Fix bad URL color contrast on dark themes.
- Fix some issues when too few/many pokémon are specified for a wild encounter group.
- Fix Porymap reporting errors for macros it doesn't use.
- Fix painting on the Collision tab with the opacity slider at 0 painting metatiles.
- Fix crashes when File->Reload Project fails.
- Fix overworld sprite facing directions if spritesheet has vertical layout.
- Stop reporting `Error: Interrupted` for custom scripts during project reopen

## [5.1.1] - 2023-02-20
### Added
- Add `registerToggleAction` to the scripting API

### Changed
- Change encounter tab copy and paste behavior.
- A warning will appear if a custom script fails to load or an action fails to run.

### Fixed
- Fix null characters being unpredictably written to some JSON files.
- Fix tilesets that share part of their name loading incorrectly.
- Fix events being hidden behind connecting maps.
- Metatile labels with values defined outside their tileset are no longer deleted.
- Fix the Tileset Editor retaining edit history after changing tilesets.
- Fix some minor visual issues on the Connections tab.
- Fix bug which caused encounter configurator to crash if slots in fields containing groups were deleted.
- Fix bug which caused encounter configurator to crash if last field was deleted.
- Fix map render when collision view was active while map changed.
- Fix the updated pokefirered region map graphics appearing in grayscale.
- Fix the API function `registerAction` not correctly handling actions with the same name.

## [5.1.0] - 2023-01-22
### Added
- Add new config options for reorganizing metatile attributes.
- Add `setScale` to the scripting API.
- Add option to turn off the checkerboard fill for new tilesets.
- Add option to copy wild encounters from another encounters tab.

### Changed
- Double-clicking on a connecting map on the Map or Events tabs will now open that map.
- Hovering on border metatiles with the mouse will now display their information in the bottom bar.
- The last-used directory is now preserved in import/export file dialogs.
- Encounter editing has been slightly modified in favor of a more performant ui.
- Pokémon icons in the encounter editor have their transparency set.

### Fixed
- Fix the Region Map Editor being opened by the Shortcuts Editor.
- Fix New Map settings being preserved when switching projects.
- Fix scripting API callback `onMapResized` not triggering.
- Fix crash when importing AdvanceMap metatiles while `enable_triple_layer_metatiles` is enabled.
- Fix `File -> Open Project` not resolving folder shortcuts.
- Fix bug where "Requires Itemfinder" checkbox is being checked by wrong data.
- Fix the map border not immediately reflecting Tileset Editor changes.
- Fix pasting metatiles in the Tileset Editor not triggering the unsaved changes warning.

## [5.0.0] - 2022-10-30
### Breaking Changes
- Proper support for pokefirered's clone objects was added, which requires the changes made in [pokefirered/#484](https://github.com/pret/pokefirered/pull/484).
- Warp IDs are now treated as strings, which requires the change to `mapjson` made in [pokeemerald/#1755](https://github.com/pret/pokeemerald/pull/1755). Additionally `MAP_NONE` was renamed to `MAP_DYNAMIC`. Both changes also apply to pokefirered and pokeruby.
- Overhauled the region map editor, adding support for tilemaps, and significant customization. Also now supports pokefirered. Requires the changes made in [pokeemerald/#1651](https://github.com/pret/pokeemerald/pull/1651), [pokefirered/#500](https://github.com/pret/pokefirered/pull/500), or [pokeruby/#842](https://github.com/pret/pokeruby/pull/842).
- Many API functions which were previously accessible via the `map` object are now accessible via one of the new objects `overlay`, `utility`, or `constants`. Some functions were renamed accordingly. See [porymap/#460](https://github.com/huderlem/porymap/pull/460) for a full list of API function name changes.
- Arguments for the API function `createImage` have changed: `xflip` and `yflip`  have been replaced with `hScale` and `vScale`, and `offset` has been replaced with `xOffset` and `yOffset`.
- The API function `addFilledRect` has been removed; it's been replaced by new arguments in `addRect`: `color` has been replaced with `borderColor` and `fillColor`, and a new `rounding` argument allows ellipses to be drawn.

### Added
- Add prefab support
- Add Cut/Copy/Paste for metatiles in the Tileset Editor.
- Add button to copy the full metatile label to the clipboard in the Tileset Editor.
- Add ability to export an image of the primary or secondary tileset's metatiles.
- Add new config options for customizing how new maps are filled, setting default tilesets, and whether the most recent project should be opened on launch.
- Add color picker to palette editor for taking colors from the screen.
- Add new features to the scripting API, including the ability to display messages and user input windows, set the overlay's opacity, rotation, scale, and clipping, interact with map header properties and the map border, read tile pixel data, and more.

### Changed
- Previous settings will be remembered in the New Map Options window.
- The Custom Attributes table for map headers and events now supports types other than strings.
- If an object event is inanimate, it will always render using its first frame.
- Unused metatile attribute bits are preserved instead of being cleared.
- The wild encounter editor is automatically disabled if the encounter JSON data cannot be read
- Metatiles are always rendered accurately with 3 layers, and the unused layer is not assumed to be transparent.
- `object_event_graphics_info.h` can now be parsed correctly if it uses structs with attributes.
- Tileset data in `headers`, `graphics`, and `metatiles` can now be parsed if written in C.
- The amount of time it takes to render the event panel has been reduced, which is most noticeable when selecting multiple events at once.
- The selection is no longer reset when pasting events. The newly pasted events are selected instead.
- The currently selected event for each event group will persist between tabs.
- An object event's sprite will now render if a number is specified instead of a graphics constant.
- Palette editor ui is updated a bit to allow hex and rgb value input.
- Heal location constants will no longer be deleted if they're not used in the data tables.
- The heal location prefixes `SPAWN_` and `HEAL_LOCATION_` may now be used interchangeably.
- The number and order of entries in the heal location data tables can now be changed arbitrarily, and independently of each other.
- The metatile behavior is now displayed in the bottom bar mouseover text.
- Number values are now allowed in the Tileset Editor's Metatile Behavior field.
- Removed some unnecessary error logs from the scripting API and added new useful ones.
- If any JSON data is the incorrect type Porymap will now attempt to convert it.

### Fixed
- Fix events losing their assigned script when the script autocomplete is used.
- Fix the unsaved changes indicator not disappearing when saving changes to events.
- Fix copy and paste for events not including their custom attributes.
- Fix cursor tile outline not updating at the end of a dragged selection.
- Fix cursor tile and player view outlines exiting map bounds while painting.
- Fix cursor tile and player view outlines not updating immediately when toggled in Collision view.
- Fix selected space not updating while painting in Collision view.
- Fix collision values of 2 or 3 not rendering properly.
- Fix the map tree view arrows not displaying for custom themes.
- Fix the map music dropdown being empty when importing a map from Advance Map.
- Fix object events added by pasting ignoring the map event limit.
- Fix a bug where saving the tileset editor would reselect the main editor's first selected metatile.
- Fix crashes / unexpected behavior if certain scripting API functions are given invalid palette or tile numbers.
- Fix drawing large amounts of text with the scripting API causing a significant drop in performance.
- Silence unnecessary error logging when parsing C defines Porymap doesn't use.
- Fix some windows like the Tileset Editor not raising to the front when reactivated.
- Fix incorrect limits on Floor Number and Border Width/Height in the New Map Options window.
- Fix Border Width/Height being set to 0 when creating a new map from an existing layout.
- Fix certain UI elements not highlighting red on some platforms.
- Fix Open Config Folder not responding
- Properly update the minimum offset for a connection when the map is changed.

## [4.5.0] - 2021-12-26
### Added
- WSL project paths are now supported. (For example, \wsl$\Ubuntu-20.04\home\huderlem\pokeemerald)
- Add ability to export map timelapse animated GIFs with `File -> Export Map Timelapse Image...`.
- Add tool to count the times each metatile or tile is used in the tileset editor.
- Events, current metatile selections, and map images can now be copied and pasted, including between windows.
- The grid and map border visibility are now saved as config options.
- Add ~60 new scripting API functions, including new features like reading/writing metatile data, layering, moving, and hiding items in the overlay, creating modified images and tile/metatile images, reading tileset sizes, logging warnings and errors, and more.
- Add 7 new scripting API callbacks.
- Porymap is now compatible with Qt6.

### Changed
- New events will be placed in the center of the current view of the map.
- Scripting API errors are more detailed and logged in more situations.
- Add new optional arguments to 5 existing API functions.
- Top-level UI elements now render above the scripting overlay.
- The onBlockChanged script callback is now called for blocks changed by Undo/Redo.

### Fixed
- Fix % operator in C defines not being evaluated
- Fix tileset palette editor crash that could occur when switching maps or tilesets with it open.
- The metatile selection is no longer reset if it becomes invalid by changing the tileset. Invalid metatiles in the selection will be temporarily replaced with metatile 0.
- Loading wild encounters will now properly preserve the original order, so saving the file will not give huge diffs.
- Fix bug where the tile selection cursor could be toggld on in the Events tab.

## [4.4.0] - 2020-12-20
### Added
- Add undoable edit history for Events tab.
- Add keyboard shortcut for `DEL` key to delete the currently selected event(s).
- Disable ui while there is no open project to prevent crashing.
- Add "Straight Paths" feature for drawing straight lines while holding `Ctrl`.
- The New Map dialog now gives an option to specify the "Show Location Name" field.
- Some new shortcuts were added in [porymap/#290](https://github.com/huderlem/porymap/pull/290).
- All plain text boxes now have a clear button to delete the text.
- The window sizes and positions of the tileset editor, palette editor, and region map editor are now stored in `porymap.cfg`.
- Add ruler tool for measuring metatile distance in events tab (Right-click to turn on/off, left-click to lock in place).
- Add delete button to wild pokemon encounters tab.
- Add shortcut customization via `Options -> Edit Shortcuts`.
- Add custom text editor commands in `Options -> Edit Preferences`, a tool-button next to the `Script` combo-box, and `Tools -> Open Project in Text Editor`. The tool-button will open the containing file to the cooresponding script.

### Changed
- Holding `shift` now toggles "Smart Path" drawing; when the "Smart Paths" checkbox is checked, holding `shift` will temporarily disable it.

### Fixed
- Fix a bug with the current metatile selection zoom.
- Fix bug preventing the status bar from updating the current position while dragging events.
- Fix porymap icon not showing on window or panel on Linux.
- The main window can now be resized to fit on lower resolution displays.
- Zooming the map in/out will now focus on the cursor.
- Fix bug where object event sprites whose name contained a 0 character would display the placeholder "N" picture.

## [4.3.1] - 2020-07-17
### Added
- Add keyboard shortcut `Ctrl + D` for duplicating map events.
- Add keyboard shortcut `Ctrl + Shift + Z` for "redo" in the tileset editor.
- Add scripting api to reorder metatile layers and draw them with opacity.

### Changed
- The tileset editor now syncs its metatile selection with the map's metatile selector.
- The number of object events per map is now limited to OBJECT_EVENT_TEMPLATES_COUNT
- The tileset editor can now flip selections that were taken from an existing metatile.

### Fixed
- Fix bug where editing a metatile layer would have no effect.
- Fix a crash that occured when creating a new tileset using triple layer mode.
- Fix crash when reducing number of metatiles past current selection.
- Fix various methods of selecting invalid metatiles.
- Fix sprite transparency not updating when changing object event graphics.
- Fix dropdown menu item selection when using the arrow keys.

## [4.3.0] - 2020-06-27
### Added
- Add triple-layer metatiles support.

### Changed
- The "Open Scripts" button will fall back to `scripts.inc` if `scripts.pory` doesn't exist. 

### Fixed
- Fix bug where exported tileset images could be horizontally or vertically flipped.
- Fix bug where the map list wasn't filtered properly after switching filter types.
- Don't zoom in map when mouse middle button is pressed.

## [4.2.0] - 2020-06-06
### Added
- Add more project-specific configs to better support porting features from different projects.
- Add metatile label names to the status bar when hovering over metatiles in the map editor tab.
- Add mouse coordinates to the status bar when hovering in the events tab.

### Changed
- `metatile_labels.h` is now watched for changes.

### Fixed
- Reduce time it takes to load maps and save in the tileset editor.
- Fix crash that could occur when parsing unknown symbols when evaluating `define` expressions.

## [4.1.0] - 2020-05-18
### Added
- Add scripting capabilities, which allows the user to add custom behavior to Porymap using JavaScript scripts.
- Add ability to import FRLG tileset .bvd files from Advance Map 1.92.

### Changed
- Edit modes are no longer shared between the Map and Events tabs. Pencil is default for Map tab, and Pointer is default for Events tab.

### Fixed
- Disallow drawing new heal locations in the events tab.
- Fix issue where the metatile selection window was not resizable.
- Show warning when closing project with unsaved wild Pokémon changes.
- Fix bug where negative object event coordinates were saved as "0".
- Fix maximum map dimension limits.
- Fix crash when using the Pencil tool to create an event on a map with no existing events.

## [4.0.0] - 2020-04-28
### Breaking Changes
- If you are using pokeemerald or pokeruby, there were changes made in [pokeemerald/#1010](https://github.com/pret/pokeemerald/pull/1010) and [pokeruby/#776](https://github.com/pret/pokeruby/pull/776) that you will need to integrate in order to use this version of porymap.

### Added
- Support for [pokefirered](https://github.com/pret/pokefirered). Kanto fans rejoice! At long last porymap supports the FRLG decompilation project.
- Add ability to export map stitches with `File -> Export Map Stitch Image...`.
- Add new project config option `use_custom_border_size`.
- Add ability to toggle project settings in `Options` menu.
- Add file monitoring, so Porymap will prompt the user to reload the project if certain project files are modified outside of Porymap.
- Add ability to reload project.
- Add `Pencil`, `Move`, and `Map Shift` tools to the Events tab.

### Changed
- Porymap now saves map and encounter json data in an order consistent with the upstream repos. This will provide more comprehensible diffs when files are saved.
- Update Porymap icon.
- The "Map" and "Events" tabs now render using the same view, so jumping between them is smooth.
- Extend connection min and max offsets to player's view boundary, rather than the map's boundary.

### Fixed
- Fix bug where pressing TAB key did not navigate through widgets in the wild encounter tables.
- Fix bug that allowed selecting an invalid metatile in the metatile selector.
- Don't allow `.` or `-` characters in new tileset names.
- Fix regression that prevented selecting empty region map squares

## [3.0.1] - 2020-03-04
### Fixed
- Fix bug on Mac where tileset images were corrupted when saving.

## [3.0.0] - 2020-03-04
### Breaking Changes
- pokeemerald and pokeruby both underwent a naming consistency update with respect to "object events". As such, these naming changes break old versions of Porymap.
  - pokeemerald object event PR: https://github.com/pret/pokeemerald/pull/910
  - pokeruby object event PR: https://github.com/pret/pokeruby/pull/768

### Added
- Add optional support for Poryscript script files via the `use_poryscript` config option.
- Selecting a group of metatiles from the map area now also copies the collision properties, too.
- Add keyboard shortcut `Ctrl + G` for toggling the map grid.

### Changed
- Draw map connections with the current map's tilesets to more accurately mimic their appearance in-game.

### Fixed
- Fix index-out-of-bounds crash when deleting the last event in an event type group.
- Fix bug where exporting tileset images could add an extra row of junk at the end.
- Fix crashes when encountering an error opening a project or map.
- Fix bug where comboboxes and wild pokemon data could grow large when opening projects multiple times during the same porymap session.
- Fix bug where dragging the metatile selector would visually extend beyond map boundary.


## [2.0.0] - 2019-10-16
### Breaking Changes
- Accomodate event object graphics pointer table being explicitly indexed. From changes introduced in commits [cdae0c1444bed98e652c87dc3e3edcecacfef8be](https://github.com/pret/pokeemerald/commit/cdae0c1444bed98e652c87dc3e3edcecacfef8be) and [0e8ccfc4fd3544001f4c25fafd401f7558bdefba](https://github.com/pret/pokeruby/commit/0e8ccfc4fd3544001f4c25fafd401f7558bdefba).
- New "field" key in wild encounter JSON data from pokeemerald and pokeruby commits [adb0a444577b59eb02788c782a3d04bc285be0ba](https://github.com/pret/pokeemerald/commit/adb0a444577b59eb02788c782a3d04bc285be0ba) and [https://github.com/pret/pokeruby/commit/c73de8bed752ca538d90cfc93c4a9e8c7965f8c9](c73de8bed752ca538d90cfc93c4a9e8c7965f8c9).


### Added
- Add wild encounter table editor.
- Add dark themes.
- Support metatile labels file introduced in pokeruby and pokeemerald commits [ad365a35c1536740cbcbc10bee66e5dd908c39e7](https://github.com/pret/pokeruby/commit/ad365a35c1536740cbcbc10bee66e5dd908c39e7) and [c68ba9f4e8e260f2e3389eccd15f6ee5f4bdcd3e](https://github.com/pret/pokeemerald/commit/c68ba9f4e8e260f2e3389eccd15f6ee5f4bdcd3e).
- Add warning when closing porymap with unsaved changes.

### Changed
- Exporting map images is now more configurable. Events, connections, collision, etc. can be toggled on and off before exporting the image.
- The entire Tileset Editor selection is now conveniently flipped when selecting x-flip or y-flip.
- Autocomplete for porymap's comboboxes no longer require typing the full string prefix.

### Fixed
- Fix bug where map group names were hardcoded when creating a new map.
- Fix bug in Tileset Editor where multi-tile selections weren't properly painted when clicking on the bottom row of the metatile layers.
- Fix bug where line breaks in C headers were not parsed properly.
- Fix bug when exporting tileset images using palettes with duplicate colors.
- Fix bug where creating new maps from existing layouts created an empty layout folder.
- Fix bug where exported tile images did not contain the last row of tiles.


## [1.2.2] - 2019-05-16
### Added
- Add region map editor
- Add ability to add new tilesets
- Add official Porymap documentation website: https://huderlem.github.io/porymap/

### Changed
- Event sprites now display as facing the direction of their movement type.
- Default values for newly-created events now use valid values from the project, rather than hardcoded values.
- Deleting events will stay in the same events tab for easier bulk deletions.
- Double-clicking on a secret base event will open the corresponding secret base map.
- Selected events are now rendered above other events.
- Default values for new events are now more sensible and guaranteed to be valid.

### Fixed
- Fix bug in zoomed metatile selector where a large selection rectangle was being rendered.
- Fix bug where edited map icons were not rendered properly.
- Fix bug where right-click copying a tile from the tileset editor's metatile layers wouldn't copy the x/y flip status.
- Parsing project data is now more resilient to crashing, and it reports more informative errors.


## [1.2.1] - 2019-02-16
### Added
- Add ability to zoom in and out the map metatile selector via a slider at the bottom of the metatile selector window.

### Fixed
- Fix crash when creating a new map from a layout that has no pre-existing maps that use it.
- Fix bug where `var_value`, `trainer_type` and `trainer_sight_or_berry_tree_id` JSON fields were being interpreted as integers.

## [1.2.0] - 2019-02-04
### Breaking Changes
- New JSON map data format in pokeemerald and pokeruby from commits  [82abc164dc9f6a74fdf0c535cc1621b7ed05318b](https://github.com/pret/pokeemerald/commit/82abc164dc9f6a74fdf0c535cc1621b7ed05318b) and [a0ba1b7c6353f7e4f3066025514c05b323a0123d](https://github.com/pret/pokeruby/commit/a0ba1b7c6353f7e4f3066025514c05b323a0123d).

### Added
- Add "magic fill" mode to fill tool (hold down CTRL key). This fills all matching metatiles on the map, rather than only the contiguous region.
- Add ability to import tileset palettes (JASC, .pal, .tpl, .gpl, .act).
- Add ability to export tileset tiles as indexed .png images. The currently-selected palette is used.
- Restore window sizes the next time the application is opened.
- Add ability to import metatiles from Advance Map 1.92 (.bvd files).
- Add About window that contains porymap information and changelog. (Found in file menu `Help > About Porymap`)
- Add option to show player's in-game view when hovering the mouse on the map.
- Add option to show an outline around the currently-hovered map tile. Its size depends on the size of the current metatile selection.
- Add ability to define custom fields for map header and all events.

### Changed
- Collapse the map list by default.
- Collision view now has a transparency slider to help make it easier to view the underlying metatiles.
- When importing tileset tiles from an image that is not indexed, the user can also provide a palette for the image. This is for the scenario where the user exports tiles and a palette from Advance Map.
- When creating a new map, the user specifies all of the map properties in a new window prompt.
- New maps can be created using existing layouts by right-clicking on an existing layout folder in the map list panel when sorted by "Layout".
- The map list panel now has "expand-all" and "collapse-all" buttons.
- Events without sprites are now partially transparent so the underlying metatile can be seen. (Warps, signs, etc.)
- Changed the Trainer checkbox to a combobox, since there are actually 3 valid values for the trainer type.
- Multiline comments are now respected when parsing C defines.
- The tiles image in the tileset editor will no longer flip according to the x/y flip checkboxes. The individual tile selection still flips, though.

### Fixed
- Fix bug where smart paths could be auto-enabled, despite the checkbox being disabled.
- Fix crash that could occur when changing the palette id in the tileset palette editor.
- Fix crash that could occur when shrinking the number of metatiles in a tileset.
- Fix bug where exported tile images from Advance Map were not handled correctly due to Advance Map using incorrect file extensions.

## [1.1.0] - 2018-12-27
### Breaking Changes
- New map header format in pokeemerald from commit [a1ea3b5e394bc115ba9b86348c161094a00dcca7](https://github.com/pret/pokeemerald/commit/a1ea3b5e394bc115ba9b86348c161094a00dcca7).

### Added
- Add `porymap.project.cfg` config file to project repos, in order to house project-specific settings, such as `base_game_version=pokeemerald`.
- Write all logs to `porymap.log` file, so users can view any errors that porymap hits.
- Changelog

### Changed
- Add `porymap.cfg` base config file, rather than using built-in system settings (e.g. registry on Windows).
- Properly read/write map headers for `pokeemerald`.
- Overhauled event editing pane, which now contains tabs for each different event. Events of the same type can be iterated through using the spinner at the top of the tab. This makes it possible to edit events that are outside the viewing window.

### Fixed
- Creating new hidden-item events now uses a valid default flag value.
- Fix bug where tilesets were sometimes not displaying their bottom row of metatiles.
- Fix bug where porymap crashes on startup due to missing map headers.
- Fix tileset editor crash that only happened on macOS.
- Fix minor bug when parsing C defines.
- Write `MAP_GROUPS_COUNT` define to `maps.h`.
- Fix bug where opening multiple projects and saving would cause junk to be written to `layouts_table.inc`.
- Fix porymap icon on macOS.

## [1.0.0] - 2018-10-26
This was the initial release.
