#ifndef GUARD_LOCALIZATION_H
#define GUARD_LOCALIZATION_H

// Text and graphics are localized at build time (see localization/README.md);
// this is the small runtime side of it.

// TRUE when the ROM is being built for 'language' (e.g. LANGUAGE_SPANISH).
#define LOC_IS(language) (GAME_LANGUAGE == (language))

// Builds a message from one translatable format string. {DYNAMIC 0} to
// {DYNAMIC 3} in 'format' are replaced by arg0 to arg3 (NULL if unused), so a
// translation can place them wherever its grammar needs. Prefer this over
// StringCopy/StringAppend chains, which fix the word order of every language.
u8 *StringFormat(u8 *dst, const u8 *format, const u8 *arg0, const u8 *arg1, const u8 *arg2, const u8 *arg3);

#define StringFormat1(dst, format, arg0) StringFormat(dst, format, arg0, NULL, NULL, NULL)
#define StringFormat2(dst, format, arg0, arg1) StringFormat(dst, format, arg0, arg1, NULL, NULL)

#endif // GUARD_LOCALIZATION_H
