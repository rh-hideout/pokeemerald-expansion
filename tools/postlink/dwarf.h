#ifndef DWARF_H
#define DWARF_H

struct PostlinkElf;

const char *parse_postlink_dwarf(const void *debug_info, size_t debug_info_size, const void *debug_abbrev, size_t debug_abbrev_size, const char *debug_str, size_t debug_str_size, struct PostlinkElf *elf);

#endif
