    .ifndef __KEYSPLIT_MACROS_INC__
    .set __KEYSPLIT_MACROS_INC__, 1

    /* Running index to bind KeySplitTable1..5 to the first tables encountered */
    .ifndef __KS_INDEX
    .set __KS_INDEX, 0
    .endif

    /* Current MIDI note during table construction */
    .ifndef __KS_CUR
    .set __KS_CUR, 0
    .endif

    /* Start a new keysplit table.
       usage: keysplit <name>, <base_midi_note>
       Expands two things:
       1) An absolute symbol 'keysplit_<name>' equal to (current_location - base).
       2) For the first five tables, also define KeySplitTable1..5 the same way.
       Then sets the running note pointer to 'base' for subsequent 'split' macros. */
    .macro keysplit name:req, base:req
        /* Bind a named symbol used by voicegroups (absolute value expression). */
        .set keysplit_\name, . - \base
        .global keysplit_\name

        /* Also support KeySplitTable1..5 for older refs. */
        .set __KS_INDEX, __KS_INDEX + 1
        .if __KS_INDEX == 1
            .set KeySplitTable1, . - \base
            .global KeySplitTable1
        .elseif __KS_INDEX == 2
            .set KeySplitTable2, . - \base
            .global KeySplitTable2
        .elseif __KS_INDEX == 3
            .set KeySplitTable3, . - \base
            .global KeySplitTable3
        .elseif __KS_INDEX == 4
            .set KeySplitTable4, . - \base
            .global KeySplitTable4
        .elseif __KS_INDEX == 5
            .set KeySplitTable5, . - \base
            .global KeySplitTable5
        .endif

        /* Initialize the running note for subsequent 'split' ranges. */
        .set __KS_CUR, \base
    .endm

    /* Add a split region from the current note up to and including 'max'.
       Each note emits one byte: the region index. After emitting, advance current note. */
    .macro split region:req, max:req
        .set __KS_COUNT, (\max - __KS_CUR + 1)
        .rept __KS_COUNT
            .byte \region
            .set __KS_CUR, __KS_CUR + 1
        .endr
    .endm

    .endif
