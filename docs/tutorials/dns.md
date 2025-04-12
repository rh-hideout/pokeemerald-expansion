## Day/Night system FAQ

### Q: How do I disable DNS?
A: Set `OW_ENABLE_DNS` to `FALSE` in `include/config/overworld.h`.

### Q: How do I mark certain colors in a palette as light-blended?
A: Create a `.pla` file in the same folder as the `.pal` with the same name.

In this file you can enter color indices [0,15]
on separate lines to mark those colors as being light-blended, i.e:

`06.pla:`
```
# A comment
0 # if color 0 is listed, uses it to blend with instead of the default!
1
9
10
```

### Q: How do I return to using regular shadows?
A: Set `OW_OBJECT_VANILLA_SHADOWS` to `TRUE` in `include/config/overworld.h`.

### Q: How do I disable shadows for certain locations?
A: Shadows can be disabled for certain locations by modifying the `CurrentMapHasShadows` function in `src/overworld.c`.
