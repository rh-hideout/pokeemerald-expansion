#include <cstdio>
#include <sstream>
#include <vector>
#include "localization.h"

// WARNING: This must stay in-sync with 'tools/preproc/localization.cpp'.
std::string NormalizeSourcePath(const std::string& path)
{
    std::vector<std::string> parts;
    std::stringstream ss(path);
    std::string part;

    if (!path.empty() && path[0] == '/')
        return "";

    while (std::getline(ss, part, '/'))
    {
        if (part.empty() || part == ".")
            continue;
        if (part == "..")
        {
            if (parts.empty())
                return "";
            parts.pop_back();
            continue;
        }
        parts.push_back(part);
    }

    std::string result;
    for (std::size_t i = 0; i < parts.size(); i++)
    {
        if (i != 0)
            result += '/';
        result += parts[i];
    }
    return result;
}

static bool FileExists(const std::string& path)
{
    FILE* fp = std::fopen(path.c_str(), "rb");
    if (fp == nullptr)
        return false;
    std::fclose(fp);
    return true;
}

// WARNING: This must stay in-sync with 'tools/preproc/localization.cpp'.
std::string LocalizedGraphicsPath(const std::string& overlayDir, const std::string& path, bool isIncbin)
{
    if (overlayDir.empty())
        return path;

    std::string dir = overlayDir;
    if (dir[dir.length() - 1] != '/')
        dir.push_back('/');

    if (!isIncbin)
        return FileExists(dir + path) ? dir + path : path;

    std::size_t slash = path.find_last_of('/');
    std::size_t dot = path.find('.', slash == std::string::npos ? 0 : slash + 1);
    if (dot == std::string::npos)
        return path;

    std::string stem = path.substr(0, dot);
    if (FileExists(dir + stem + ".png") || FileExists(dir + stem + ".pal"))
        return dir + path;
    return path;
}
