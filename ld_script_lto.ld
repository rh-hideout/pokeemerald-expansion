SECTIONS
{
    /* TODO: Work out why we get '.postlink.elf' errors with LTO */
    /DISCARD/ : { *(.postlink*) }
}
INSERT BEFORE .ewram;
