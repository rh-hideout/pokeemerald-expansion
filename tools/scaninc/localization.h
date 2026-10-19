// Build-time localization support for scaninc.
// WARNING: These must stay in-sync with 'tools/preproc/localization.cpp'.

#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <string>

std::string NormalizeSourcePath(const std::string& path);
std::string LocalizedGraphicsPath(const std::string& overlayDir, const std::string& path, bool isIncbin);

#endif // LOCALIZATION_H
