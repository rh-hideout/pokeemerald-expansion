# Shop Menu Assets

## Credits: mudskip

This folder contains the real asset of the shop menu's new visual structure used for this branch, this is used for those who wants to design their own shop design.

If you're using Aseprite or the art program of your choice supports Aseprite's save format (`.aseprite`), you just need to open `shop_example.aseprite`. Otherwise, you'd have to import each .png images located in the `example-png` folder.

The `shop_example.aseprite` file contains 3 palettes, that is:

```sh
menu.pal # tiles (main, scrolling bg)
money.pal # sprites (cursor, money)
jerry.pal # mugshot
```

Each layers/images are named based on where they are stored and what they contain on the screen in-game so they should be straight-forward to follow.

The `_img.png` images contains the final result of the exported menu image before converted into tilemaps. And of course lastly, those converted results are found in the root `shop` folder with the same name (just without the `_img`).

Tips: When you're trying to convert with Tilemap Studio, make sure the most top left 8x8 tiles is transparent so that that transparent tiles is going to be the first tile on the generated tileset.

When exporting, you must name certain file a specific name depending on what the image contains. For example, you must export the `bg3-scroll` layer as `scroll.png` in the root `shop` folder. Note that you cannot export these ones:
```sh
bg-windowsPos
bg0-text
cursorPos
```
The reason is that all of these are only used as a "guide" for placing certain things on certain coordinate, such as the windows positions, the text positions, and cursor positions respectively.

So, Here's a list of other layers that are possible to export:
```sh
# You must name this one 'name.png' (w/o the quote), where 'name' is what you wanted it be called as e.g. 'jerry.png'. make sure that the img size is 104x96
bg1-mugshot
# You must name this one 'main_img.png' if exported for converting with tilemap studio, otherwise 'main.png' (w/o the quote)
bg2-main
# You must name this one 'scroll_img.png' if exported for converting with tilemap studio, otherwise 'scroll.png' (w/o the quote)
bg3-scroll
# Note that the only thing you need to care on this layer is the cursor at the bottom, not the potions/poke balls/arrow sign. You must name this one 'cursor.png' (w/o the quote) with size 64x128 where the first 64x0 is the first frame and  64x64 is the second frame.
bgS-sprites
```
