#ifndef GUARD_GRID_MENU_H
#define GUARD_GRID_MENU_H

enum GridMenuDirection {
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT,
    DIRECTION_END
};

enum GridMenuMovementType {
    TYPE_MOVE,
    TYPE_SCROLL,
    TYPE_FAIL,
    TYPE_END
};

struct GridMenu
{
    /*
     * Max rows and cols, this is the width and height of the grid.
     */
    u8 maxCols;
    u8 maxRows;
    u32 maxSize;

    /*
     * The GridMenu assumes the caller has a backing array of items in the grid. `numItems' should store the size of
     * this array. And `topLeftItemIndex' stores the index in the array of the top left grid item.
     */
    u32 numItems;
    u32 topLeftItemIndex;

    /*
     * The currently selected grid item, can range from 0 to maxSize-1.
     */
    u8 selectedItem;

    /*
     * The actual size of the grid, computed from `numItems' and `topLeftItemIndex'. This number may be smaller than
     * `maxSize' when `numItems' is itself smaller than `maxSize'. It may also be smaller than `maxSize' when the grid
     * has been scrolled to the end, and `numItems' is not evenly divisible by `maxCols'.
     */
    u32 actualGridSize;

    /*
     * Callbacks to perform caller's actions when the menu's selected item changes. The onMoveX functions are for when
     * the menu does a simple move. The onScrollX functions are for when the user moves up from the top row or down from
     * the bottom row, forcing a grid menu scroll. In that case, the menu caller may want to run different code to
     * redraw menu items, labels, etc.
     */
    void (*inputCallbacks[DIRECTION_END][TYPE_END])(void);

    /*
     * A dynamically allocated array for this grid's icon sprite IDs. Callers who want each grid square to contain an
     * icon sprite can use this array to track the IDs. The caller will be responsible for setting the input callbacks
     * to manage the sprites and IDs. This array is freed by `GridMenu_Destroy'.
     */
    u8 *iconSpriteIds;

    /*
     * If this grid menu will wrap around verticaly when scrolling up at the start of the grid or down at the end.
     */
    bool8 verticalWrapAround;

    /*
     * If this grid menu will wrap around horizontally when scrolling left at the start of a row or right at the end.
     */
    bool8 horizontalWrapAround;
};

/*
 * Init a new GridMenu with a given number of maximum columns and maximum rows. You must also specify the number of
 * items in the backing array.
 */
struct GridMenu *GridMenu_Init(u8 maxCols, u8 maxRows, u32 numItems);

/*
 * Free the GridMenu and any heap resources it allocated.
 */
void GridMenu_Destroy(struct GridMenu *gridMenu);

/*
 * Compute and return the backing array index of the selected item.
 */
u32 GridMenu_SelectedIndex(struct GridMenu *gridMenu);

/*
 * Set the selected item to match the given index into the backing array. Try to put the index in the top row, if
 * possible. If that would cause the grid to have an empty bottom row, it puts the selected index in one of the middle
 * rows instead.
 */
void GridMenu_SetIndex(struct GridMenu *gridMenu, u32 index);

/*
 * Set the input callback for the given direction and type.
 */
void GridMenu_SetInputCallback(struct GridMenu *gridMenu, void (*inputCallback)(void), enum GridMenuDirection direction, enum GridMenuMovementType type);

/*
 * Call within some UI's input task to update grid menu state based on input.
 */
void GridMenu_HandleInput(struct GridMenu *gridMenu);

/*
 * Iterate over all possible cells in the given `GridMenu' and call the given callback for each cell. This function does
 * not account for the `actualGridSize'. It will always run `maxSize' times.
 */
void GridMenu_ForAll(struct GridMenu *gridMenu, void (*forAllCallback)(u32 linearIndex, u32 col, u32 row));

/*
 * Iterate over each actual cell in the given `GridMenu' and call the given callback for each cell. This function
 * accounts for the `actualGridSize'. It will skip calling the callback once the iteration runs past the actual end
 * of the grid menu.
 */
void GridMenu_ForEach(struct GridMenu *gridMenu, void (*forEachCallback)(u32 linearIndex, u32 col, u32 row));

/*
 * Set the given grid to vertically wrap around, i.e. when scrolling up at the start or down at the end, it will wrap
 * to the end or start, respectively.
 */
void GridMenu_EnableVerticalWrapAround(struct GridMenu *gridMenu);

/*
 * Disable vertical wrap around behaviour.
 */
void GridMenu_DisableVerticalWrapAround(struct GridMenu *gridMenu);

/*
 * Set the given grid to horizontally wrap around, i.e. when scrolling left at the start of a row or right at the end,
 * wrap around to the other side of the row.
 */
void GridMenu_EnableHorizontalWrapAround(struct GridMenu *gridMenu);

/*
 * Disable horizontal wrap around behaviour.
 */
void GridMenu_DisableHorizontalWrapAround(struct GridMenu *gridMenu);

#endif
