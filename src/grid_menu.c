#include "global.h"
#include "main.h"
#include "malloc.h"
#include "sprite.h"
#include "grid_menu.h"

static void CalculateNewGridSize(struct GridMenu *gridMenu);

struct GridMenu *GridMenu_Init(u8 maxCols, u8 maxRows, u32 numItems)
{
    u32 i;
    struct GridMenu *gridMenu;

    gridMenu = AllocZeroed(sizeof(struct GridMenu));
    if (gridMenu == NULL)
        return NULL;

    gridMenu->maxCols = maxCols;
    gridMenu->maxRows = maxRows;
    gridMenu->maxSize = maxCols * maxRows;
    gridMenu->numItems = numItems;
    gridMenu->topLeftItemIndex = 0;
    gridMenu->selectedItem = 0;
    gridMenu->actualGridSize = min(numItems, gridMenu->maxSize);

    gridMenu->iconSpriteIds = AllocZeroed(gridMenu->maxSize * sizeof(u8));
    if (gridMenu->iconSpriteIds == NULL)
        return NULL;

    for (i = 0; i < gridMenu->maxSize; i++)
        gridMenu->iconSpriteIds[i] = SPRITE_NONE;

    CalculateNewGridSize(gridMenu);
    gridMenu->verticalWrapAround = FALSE;
    gridMenu->horizontalWrapAround = FALSE;

    return gridMenu;
}

void GridMenu_Destroy(struct GridMenu *gridMenu)
{
    TRY_FREE_AND_SET_NULL(gridMenu->iconSpriteIds);
    TRY_FREE_AND_SET_NULL(gridMenu);
}

u32 GridMenu_SelectedIndex(struct GridMenu *gridMenu)
{
    return gridMenu->topLeftItemIndex + gridMenu->selectedItem;
}

void GridMenu_SetIndex(struct GridMenu *gridMenu, u32 index)
{
    u32 mod;
    if (index >= gridMenu->numItems)
    {
        // Index was too large, just bail
        return;
    }
    if (gridMenu->numItems <= gridMenu->maxSize)
    {
        // Easy case, entire backing array fits on a single grid
        gridMenu->topLeftItemIndex = 0;
        gridMenu->selectedItem = index;
        CalculateNewGridSize(gridMenu);
        return;
    }
    /*
     * Compute which "page" the index is in, make the index in the top row unless that would leave the bottom row empty,
     * in which case we put the index in a middle row.
     */
    mod = index % gridMenu->maxCols;
    gridMenu->topLeftItemIndex = index - mod;
    gridMenu->selectedItem = mod;
    CalculateNewGridSize(gridMenu);
    while (gridMenu->actualGridSize <= gridMenu->maxSize - gridMenu->maxCols)
    {
        gridMenu->topLeftItemIndex -= gridMenu->maxCols;
        gridMenu->selectedItem += gridMenu->maxCols;
        CalculateNewGridSize(gridMenu);
    }
}

void GridMenu_SetInputCallback(struct GridMenu *gridMenu, void (*inputCallback)(void), enum GridMenuDirection direction, enum GridMenuMovementType type)
{
    if (gridMenu == NULL)
        return;

    gridMenu->inputCallbacks[direction][type] = inputCallback;
}

static void GridMenuHelper_HandleInputUp(struct GridMenu *gridMenu);
static void GridMenuHelper_HandleInputDown(struct GridMenu *gridMenu);
static void GridMenuHelper_HandleInputLeft(struct GridMenu *gridMenu);
static void GridMenuHelper_HandleInputRight(struct GridMenu *gridMenu);

void GridMenu_HandleInput(struct GridMenu *gridMenu)
{
    if (JOY_REPEAT(DPAD_UP))
    {
        GridMenuHelper_HandleInputUp(gridMenu);
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        GridMenuHelper_HandleInputDown(gridMenu);
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        GridMenuHelper_HandleInputLeft(gridMenu);
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        GridMenuHelper_HandleInputRight(gridMenu);
    }
}

static void GridMenuHelper_HandleInputUp(struct GridMenu *gridMenu)
{
    u32 selectedCol, colOfLastElement;
    if (gridMenu->numItems <= gridMenu->maxCols)
    {
        /*
         * There is only one total row, just fail, no sense in handling wrap-around.
         */
        if (gridMenu->inputCallbacks[DIRECTION_UP][TYPE_FAIL] != NULL)
            gridMenu->inputCallbacks[DIRECTION_UP][TYPE_FAIL]();
    }
    else if ((gridMenu->selectedItem + 1) > gridMenu->maxCols)
    {
        /*
         * We not in the first grid row, so move up by a whole row. This will always work, since we are
         * always guaranteed to have a cell directly above us. Then call the input callback for this input.
         */
        gridMenu->selectedItem -= gridMenu->maxCols;
        if (gridMenu->inputCallbacks[DIRECTION_UP][TYPE_MOVE] != NULL)
            gridMenu->inputCallbacks[DIRECTION_UP][TYPE_MOVE]();
    }
    else
    {
        /*
         * We are in the first grid row, so we'll need to either scroll up (or wrap), or fail.
         */
        if (gridMenu->topLeftItemIndex < gridMenu->maxCols)
        {
            /*
             * We are in the first grid row, but there is no "room" to scroll up in the backing array.
             */
            if (gridMenu->verticalWrapAround)
            {
                /*
                 * The grid has `verticalWrapAround' enabled so recalculate grid parameters and call the scroll callback
                 * for the UP direction.
                 */

                selectedCol = gridMenu->selectedItem % gridMenu->maxCols;
                colOfLastElement = (gridMenu->numItems - 1) % gridMenu->maxCols;

                if (selectedCol > colOfLastElement)
                {
                    GridMenu_SetIndex(gridMenu, gridMenu->numItems - 1);
                }
                else
                {
                    GridMenu_SetIndex(gridMenu, gridMenu->numItems - (colOfLastElement - selectedCol) - 1);
                }

                CalculateNewGridSize(gridMenu);
                if (gridMenu->inputCallbacks[DIRECTION_UP][TYPE_SCROLL] != NULL)
                    gridMenu->inputCallbacks[DIRECTION_UP][TYPE_SCROLL]();
            }
            else
            {
                /*
                 * Grid `verticalWrapAround' is disabled so call the failure callback for UP direction.
                 */
                if (gridMenu->inputCallbacks[DIRECTION_UP][TYPE_FAIL] != NULL)
                    gridMenu->inputCallbacks[DIRECTION_UP][TYPE_FAIL]();
            }
        }
        else
        {
            /*
             * We are in the first grid row but there is "room" to scroll up in the backing array. So we need to
             * perform the scroll. We also need to re-calculate the grid size since we may be scrolling up from a
             * very-bottom row that is not fully sized.
             */
            gridMenu->topLeftItemIndex -= gridMenu->maxCols;
            CalculateNewGridSize(gridMenu);
            if (gridMenu->inputCallbacks[DIRECTION_UP][TYPE_SCROLL] != NULL)
                gridMenu->inputCallbacks[DIRECTION_UP][TYPE_SCROLL]();
        }
    }
}

static void GridMenuHelper_HandleInputDown(struct GridMenu *gridMenu)
{
    if (gridMenu->numItems <= gridMenu->maxCols)
    {
        /*
         * There is only one total row, just fail, no sense in handling wrap-around.
         */
        if (gridMenu->inputCallbacks[DIRECTION_UP][TYPE_FAIL] != NULL)
            gridMenu->inputCallbacks[DIRECTION_UP][TYPE_FAIL]();
    }
    else if (gridMenu->selectedItem < (gridMenu->maxCols * (gridMenu->maxRows - 1)) &&
             gridMenu->selectedItem + gridMenu->maxCols < gridMenu->actualGridSize)
    {
        /*
         * We are not in the last row (there is a row below us), and there is a cell below us, so jump to it.
         */
        gridMenu->selectedItem += gridMenu->maxCols;
        if (gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_MOVE] != NULL)
            gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_MOVE]();
    }
    else if (gridMenu->selectedItem < (gridMenu->maxCols * (gridMenu->maxRows - 1)) &&
             gridMenu->selectedItem + gridMenu->maxCols >= gridMenu->actualGridSize &&
             gridMenu->selectedItem / gridMenu->maxCols != (gridMenu->actualGridSize - 1) / gridMenu->maxCols)
    {
        /*
         * We are not in the last row (there is a row below us), but there is no cell below us to jump to, so jump to
         * the last cell of the below row.
         */
        gridMenu->selectedItem = gridMenu->actualGridSize - 1;
        if (gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_MOVE] != NULL)
            gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_MOVE]();
    }
    else
    {
        /*
         * We are in the last grid row: handle either a scroll, or a grid wrap-around, or a fail.
         */
        if (gridMenu->topLeftItemIndex + gridMenu->maxSize < gridMenu->numItems)
        {
            /*
             * Only scroll down if there are actually more items to display. If we are jumping down to a row that
             * is not full, and we'd be jumping past the end, just jump to the end instead.
             */
            gridMenu->topLeftItemIndex += gridMenu->maxCols;
            CalculateNewGridSize(gridMenu);
            gridMenu->selectedItem = min(gridMenu->selectedItem, gridMenu->actualGridSize - 1);
            if (gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_SCROLL] != NULL)
                gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_SCROLL]();
        }
        else
        {
            /*
             * There are no more items to display below this row. Handle either a wrap around or scroll.
             */
            if (gridMenu->verticalWrapAround)
            {
                /*
                * The grid has `verticalWrapAround' enabled so recalculate grid parameters and call the scroll callback
                * for the DOWN direction.
                */
                gridMenu->topLeftItemIndex = 0;
                gridMenu->selectedItem = gridMenu->selectedItem % gridMenu->maxCols;
                CalculateNewGridSize(gridMenu);
                if (gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_SCROLL] != NULL)
                    gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_SCROLL]();
            }
            else
            {
                /*
                * Grid `verticalWrapAround' is disabled so call the failure callback for DOWN direction.
                */
                if (gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_FAIL] != NULL)
                    gridMenu->inputCallbacks[DIRECTION_DOWN][TYPE_FAIL]();
            }
        }
    }
}

static void GridMenuHelper_HandleInputLeft(struct GridMenu *gridMenu)
{
    u32 tmp;
    if (gridMenu->selectedItem % gridMenu->maxCols != 0)
    {
        // Move to previous cell in row
        gridMenu->selectedItem -= 1;
        if (gridMenu->inputCallbacks[DIRECTION_LEFT][TYPE_MOVE] != NULL)
            gridMenu->inputCallbacks[DIRECTION_LEFT][TYPE_MOVE]();
    }
    else if (gridMenu->selectedItem % gridMenu->maxCols == 0 && (gridMenu->selectedItem + 1) != gridMenu->actualGridSize)
    {
        // We are at first cell in row
        if (gridMenu->horizontalWrapAround)
        {
            // Horizontal wrap enabled, so cycle back to last cell (accounting for possible shortened row)
            tmp = min(gridMenu->maxCols - 1, gridMenu->actualGridSize - gridMenu->selectedItem - 1);
            gridMenu->selectedItem += tmp;
            if (gridMenu->inputCallbacks[DIRECTION_LEFT][TYPE_MOVE] != NULL)
                gridMenu->inputCallbacks[DIRECTION_LEFT][TYPE_MOVE]();
        }
        else
        {
            // Horizontal wrap disabled, so fail
            if (gridMenu->inputCallbacks[DIRECTION_LEFT][TYPE_FAIL] != NULL)
                gridMenu->inputCallbacks[DIRECTION_LEFT][TYPE_FAIL]();
        }
    }
    else
    {
        // Only one cell in this row, so just fail
        if (gridMenu->inputCallbacks[DIRECTION_LEFT][TYPE_FAIL] != NULL)
            gridMenu->inputCallbacks[DIRECTION_LEFT][TYPE_FAIL]();
    }
}

static void GridMenuHelper_HandleInputRight(struct GridMenu *gridMenu)
{
    if ((gridMenu->selectedItem + 1) % gridMenu->maxCols != 0 && (gridMenu->selectedItem + 1) < gridMenu->actualGridSize)
    {
        // Advance to next cell in the row
        gridMenu->selectedItem += 1;
        if (gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_MOVE] != NULL)
            gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_MOVE]();
    }
    else if (gridMenu->selectedItem % gridMenu->maxCols != 0 && (gridMenu->selectedItem + 1) != gridMenu->actualGridSize)
    {
        // We are at end of full row
        if (gridMenu->horizontalWrapAround)
        {
            // Horizontal wrap enabled, so cycle back to start
            gridMenu->selectedItem -= gridMenu->maxCols - 1;
            if (gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_MOVE] != NULL)
                gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_MOVE]();
        }
        else
        {
            // Horizontal wrap disabled, so fail
            if (gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_FAIL] != NULL)
                gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_FAIL]();
        }
    }
    else if (gridMenu->selectedItem % gridMenu->maxCols != 0 && (gridMenu->selectedItem + 1) == gridMenu->actualGridSize)
    {
        // We are at end of last row, which may not be full length, handle cycle correctly if wrap enabled
        if (gridMenu->horizontalWrapAround)
        {
            // gridSize % maxCols == maxCols-1 => subtract maxCols-2
            // gridSize % maxCols == maxCols-2 => subtract maxCols-3
            // ...
            // gridSize % maxCols == 2         => subtract 1
            // gridSize % maxCols == 1         => subtract 0
            // gridSize % maxCols == 0         => subtract maxCols-1
            // => subtract (gridSize % maxCols + maxCols-1) % maxCols
            gridMenu->selectedItem -= (gridMenu->actualGridSize % gridMenu->maxCols + (gridMenu->maxCols - 1)) % gridMenu->maxCols;
            if (gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_MOVE] != NULL)
                gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_MOVE]();
        }
        else
        {
            // Wrap disabled, fail
            if (gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_FAIL] != NULL)
                gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_FAIL]();
        }
    }
    else if (gridMenu->selectedItem % gridMenu->maxCols == 0 && gridMenu->selectedItem == (gridMenu->actualGridSize - 1))
    {
        // If we are the only cell on our row, call failure since cycling back to ourself is weird
        if (gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_FAIL] != NULL)
            gridMenu->inputCallbacks[DIRECTION_RIGHT][TYPE_FAIL]();
    }
}

void GridMenu_ForAll(struct GridMenu *gridMenu, void (*forAllCallback)(u32 linearIndex, u32 col, u32 row))
{
    u32 row, col, linearIndex;

    // Row-major traversal
    linearIndex = 0;
    for (row = 0; row < gridMenu->maxRows; row++)
    {
        for (col = 0; col < gridMenu->maxCols; col++)
        {
            forAllCallback(linearIndex, col, row);
            linearIndex++;
        }
    }
}

void GridMenu_ForEach(struct GridMenu *gridMenu, void (*forEachCallback)(u32 linearIndex, u32 col, u32 row))
{
    u32 row, col, linearIndex;

    // Row-major traversal
    linearIndex = 0;
    for (row = 0; row < gridMenu->maxRows; row++)
    {
        for (col = 0; col < gridMenu->maxCols; col++)
        {
            if (linearIndex < gridMenu->actualGridSize)
                forEachCallback(linearIndex, col, row);
            else
                break;
            linearIndex++;
        }
    }
}

void GridMenu_EnableVerticalWrapAround(struct GridMenu *gridMenu)
{
    gridMenu->verticalWrapAround = TRUE;
}

void GridMenu_DisableVerticalWrapAround(struct GridMenu *gridMenu)
{
    gridMenu->verticalWrapAround = FALSE;
}

void GridMenu_EnableHorizontalWrapAround(struct GridMenu *gridMenu)
{
    gridMenu->horizontalWrapAround = TRUE;
}

void GridMenu_DisableHorizontalWrapAround(struct GridMenu *gridMenu)
{
    gridMenu->horizontalWrapAround = FALSE;
}

// Static methods
static void CalculateNewGridSize(struct GridMenu *gridMenu)
{
    if (gridMenu->topLeftItemIndex + gridMenu->maxSize > gridMenu->numItems)
    {
        gridMenu->actualGridSize = gridMenu->numItems - gridMenu->topLeftItemIndex;
    }
    else
    {
        gridMenu->actualGridSize = gridMenu->maxSize;
    }
}
