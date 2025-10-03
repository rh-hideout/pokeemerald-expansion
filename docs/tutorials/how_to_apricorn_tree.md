# How to interact with Apricorn Trees

TODO - REPLACE THIS GIF WITH LOCALLY INCLUDED UPDATED VARIANT (USING THE HGSS WORDING)
![apricot_tree](https://github.com/GraionDilach/spinarakgreen/assets/1136302/0f0c3f8c-1130-42f2-9f3c-8a31d6bcf98a)

### Adding a new apricorn tree

To add a new tree, first increase the tree count and expand the tree list in `include/constants/apricorn_tree.h`.

Note that each tree will take a bit in the savegame's `SaveBlock3` struct so increasing `APRICORN_TREE_COUNT` **breaks the savegame**.
Due to this, pokeemerald-expansion doesn't have any trees set up by default to prevent breaking downstream savegames.

```diff
#define APRICORN_TREE_NONE 0

-#define APRICORN_TREE_COUNT 0
+#define APRICORN_TREE_ROUTE101_RED_SAPLING 1
+
+#define APRICORN_TREE_COUNT 32
```

then list it's data in `src/data/apricorns.h`.

```diff
const struct ApricornTree gApricornTrees[APRICORN_TREE_COUNT] =
{
    [APRICORN_TREE_NONE] =
    {
        .isSapling = FALSE,
        .apricornType = APRICORN_RED,
    },

+   [APRICORN_TREE_ROUTE101_RED_SAPLING] =
+   {
+       .isSapling = TRUE, // Saplings grow a single apricot each day, trees grow two.
+       .apricornType = APRICORN_RED,
+   },
};
```
Afterwards, just place your new tree using porymap.
Similarly to berries, the Sight Radius / Berry Tree ID field is used for the tree's ID.

![apricorn-tree-porymap](/docs/tutorials/img/apricorn_tree/apricorn-tree-porymap.png)

### Add a new apricorn type

After you created your new item, expand the apricorn list in `include/constants/apricorn_tree.h`.

```diff
#define APRICORN_BERRY_MARANGA  73
+#define APRICORN_BROWN          74

-#define APRICORN_COUNT          74
+#define APRICORN_COUNT          75
```

then expand the lookup table in `src/data/apricorns.h` with your new apricorn.
```diff
const u16 ApricornTypes[APRICORN_COUNT] =
{
    [...]
    [APRICORN_BERRY_MARANGA] = ITEM_MARANGA_BERRY,
+    [APRICORN_BROWN]         = ITEM_BROWN_APRICORN,
};
```

Note that the default `ApricornTree` struct's `apricornType` member caps apricorn types to 127 and you'll have to expand it if you get past that amount.