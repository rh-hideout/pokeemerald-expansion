# `Variant Colours`
Implements programmatic palette shifting in the OkLCH (Polar OKLab) colour space to allow for easy, deterministic colour variations.

More information on OKLab: [https://bottosson.github.io/posts/oklab/](https://bottosson.github.io/posts/oklab/)

![Image showing example colour variations of Zigzagoon, Poochyena, Wurmple and Smeargle](./pokemonVariations.jpeg)

## Getting the changes

### Directly

Copy the files [variant_colours.c](./src/variant_colours.c) and [variant_colours.h](./include/variant_colours.h) and place them into the `src` / `include` folder of your project respectively.

### Via Git

Either pull this branch directly:

```
git pull https://github.com/SpaceOtter99/pokeemerald-expansion.git refs/heads/colour-variants
```

Or add this repo as a remote, pull the branch, then (optionally) delete the remote:
```
git remote add SpaceOtter https://github.com/SpaceOtter99/pokeemerald-expansion
git pull colour-variants
git remote rm Spaceotter
```

## Getting it working

There are three main functions provided by the code.

### ApplyMonSpeciesVariantToPaletteBuffer
Takes in a mon's species, shiny flag, PID/personality and the loaded colour palette. Uses the mon's variant data as defined in [variant_colours.h](./include/variant_colours.h) and shifts the palette colours pseudo-randomly based on the PID. Of note - if a mon & its evolution have the same LCH values, the colours will be shifted by the same amount - which means your shifts will persist across evolutions if set up correctly.

To get this working automatically for pokemon front/back sprites in & out of battle, update the following file:

**[pokemon.c](./src/pokemon.c)**

First, rename `GetMonSpritePalFromSpecies` to `GetMonSpritePalFromSpeciesInternal`.

Then add/replace the following two functions:

```c
const u16 *GetMonSpritePalFromSpeciesAndPersonality(u16 species, bool32 isShiny, u32 personality)
{
    const u16 *base = GetMonSpritePalFromSpeciesInternal(species, isShiny, IsPersonalityFemale(species, personality));
    static u16 sVariantPal[16];
    CpuCopy16(base, sVariantPal, sizeof(sVariantPal));
    ApplyMonSpeciesVariantToPaletteBuffer(species, isShiny, personality, sVariantPal);
    return sVariantPal;
}

const u16 *GetMonSpritePalFromSpecies(u16 species, bool32 isShiny, bool32 isFemale)
{
    DebugPrintf((char *)GetTrainerClassNameFromId(TRAINER_BATTLE_PARAM.opponentA));
    const u16 *base = GetMonSpritePalFromSpeciesInternal(species, isShiny, isFemale);
    static u16 sVariantPal[16];
    CpuCopy16(base, sVariantPal, sizeof(sVariantPal));
    ApplyMonSpeciesVariantToPaletteBuffer(species, isShiny, 0x00000000, sVariantPal);
    return sVariantPal;
}
```

To set up new species variant colours, add to the `gSpeciesVariants` array in [variant_colours.h](./include/variant_colours.h) - tutorial further down the page.

### ApplyPaletteVariantToPaletteBuffer

Similar to the above, but applies a pre-determined `SpeciesPalette` to a given palette instead of automatically finding the palette given a species. I don't know when you'd use it, but it's exposed in case you do want to. (`ApplyMonSpeciesVariantToPaletteBuffer` calls it).

### ApplyCustomRestrictionToPalletteBuffer

Performs a similar funcitonality to [util.c](./src/util.c)'s `BlendPalette` function, but with a few differences. `BlendPalette` directly blends between two RGB values, encountering the exact issues OKLab aims to solve - colours often appear overly dark, light or desaturated; in some cases the colour itself is also lost due to strong opposing colours on the pokemon. `ApplyCustomRestrictionToPalletteBuffer` instead remaps the L, C or H to a given new range. Preserving L & C whilst varying the H range keeps the pokemon very recognisable whilst changing its colours. Here's a comparison of a normal pokemon (first row), a `BlendPalette` (second row) and a `ApplyCustomRestrictionToPalletteBuffer` (third row).

![An image showing three rows of a fight between Poochyene and Smeargle. The first row shows the pokemon as normal; the second and third row show recoloured variants of the pokemon](./pokemonColours.jpeg)

Similarly, it is very easy to create unique variants of pokemon - for example, shadow pokemon:

![An image showing three pokemon battles: One between a Smeargle and a Poochyena, one between Typhlosion and Wurmple, and one between Wobuffet and Metang. All of the pokemon are a shadowy purple colour.](./pokemonShadow.jpeg)

## Adding new Pokemon Variations

(For use with ApplyMonSpeciesVariantToPaletteBuffer)

Inside of [variant_colours.h](./include/variant_colours.h), there is a table `gSpeciesVariants`. 

Firstly - identify the the species name inside of [species.h](./include/constants/species.h). For most pokemon this will just be the word 'SPECIES' followed by their name in caps. e.g., let's say we want to add a variant for Tyranitar - we'd use `SPECIES_TYRANITAR`.

This gets added to the array as:

```
    [SPECIES_TYRANITAR] = {
      
    },
```

To fill out the actual variation data, we need to know what we want to modify. Open up your pokemon's `anim_front` in an image editor that supports indexed palettes - e.g. [https://www.gimp.org/downloads/](https://www.gimp.org/downloads/). Look at the palette itself - in the example image, it's in the top right:

![A screenshot of Tyranitar inside of the image editing software GIMP](./Tyranitar_Indexed.png)

Let's say we want to vary Tyranitar's blue chest slightly. We can see that the blue colours start at index 11 (remember - the index counts up from 0), and carries on for 3 entries total. We can ammend our array to add:

```
    [SPECIES_TYRANITAR] = {
      PAL1(11, 3),
    },
```

This means that the variation we're about to define will only apply to colours 11 - 13. A space-saving limitation is that the variations we define need to take place on 'chunks' of the palette. This usually isn't an issue for most pokemon - if it is, you can always rearrange the palette. We then need to decide what we want to vary, and by how much. We can choose from the following options:

- Hue: Represents the actual 'colour' of the image - e.g. red, blue, etc.
- Chroma: Represents how 'colourful' the image is - e.g. is it grey, or very vibrant?
- Luminance: Represents how bright the image is - e.g., is it dark, or very light?

Here's a helpful visualisation:

![A visualisation of changes in Hue, Chroma and Luminance](./HCL.jpeg)

For this example, let's say we want to vary the colour slightly and the saturation a lot, keeping the luminance as it is. This will give us a range of colour between a slightly more purple tone to a slightly more teal tone, ranging from colourless grey to normal. In our array, this would look like:

```
    [SPECIES_TYRANITAR] = {
      PAL1(11, 3),
      HCL1(30, 25, 0, TRUE),
    },
```

There's two things to note here - firstly, our choices of HCL values are limited. To save on size in the event that data is added for a large number of pokemon, I've restricted the ranges you can pick from to a set of discrete values. For Hue, it's one of {0, 10, 20, 30, 45, 60, 90, 180}; and for Chroma/Luma it's {0, 5, 10, 25}. There is also the final argument, which is 'TRUE' here. This represents the mode that we're applying Chroma/Luma in. When 'False', the inputted range will act as normal - so our final colour would be the original C/L value +/- our HCL1 C/L values. However, when it's 'True', this means we're using 'decreasing only' mode - so the range instead becomes a number between the original C/L value and ( - 2 * our HCL1 C/L values). 

As another, quicker example - lets say we want Tyranitar's green body to vary between dark green & light green slightly. We can look at the palettes again (Green from 1 to 5), and add in the following to our array:

```
    [SPECIES_TYRANITAR] = {
      PAL1(11, 3),
      HCL1(30, 25, 0, TRUE),
      PAL2(1, 5),
      HCL2(0, 0, 10, FALSE),
    },
```

Another note - each pokemon can have at most two entries (so in this case, there's nothing else we can do for Tyranitar!).

Compiling this, we can see how Tyranitar looks in the game now:

![A photo of multiple Tyranitar exhibiting slightly varying green skin tones & blue/grey belly tones](./TyranitarVariations.jpeg)

We've mostly achieved what we wanted - the Tyranitar have multiple slight differences in their green skin colour, and the chest is varying colours of blue with saturation down to grey. It's then easy to further refine this if we wanted to make any more changes - just edit the variables in the array!