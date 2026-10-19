#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include "preproc.h"
#include "localization.h"

LocTables* g_locTables = nullptr;

std::uint64_t Fnv1a64(const unsigned char* data, std::size_t length)
{
    std::uint64_t hash = 0xcbf29ce484222325UL;
    for (std::size_t i = 0; i < length; i++)
        hash = (hash ^ data[i]) * 0x00000100000001b3UL;
    return hash;
}

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

// WARNING: This must stay in-sync with 'tools/scaninc/localization.cpp'.
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

LocTables::LocTables(std::string tableDir, std::string usageLog)
    : m_tableDir(tableDir), m_usageLog(usageLog)
{
    if (!m_tableDir.empty() && m_tableDir[m_tableDir.length() - 1] != '/')
        m_tableDir.push_back('/');
}

static bool ParseHexBytes(const std::string& text, std::vector<unsigned char>& out)
{
    if (text == "-")
        return true;
    if (text.length() % 2 != 0)
        return false;
    for (std::size_t i = 0; i < text.length(); i += 2)
    {
        char buf[3] = { text[i], text[i + 1], 0 };
        char* end;
        unsigned long value = std::strtoul(buf, &end, 16);
        if (*end != 0)
            return false;
        out.push_back(static_cast<unsigned char>(value));
    }
    return true;
}

LocTables::Table& LocTables::GetTable(const std::string& file)
{
    auto it = m_tables.find(file);
    if (it != m_tables.end())
        return it->second;

    Table& table = m_tables[file];
    std::string normalized = NormalizeSourcePath(file);
    if (normalized.empty())
        return table;

    std::string tablePath = m_tableDir + normalized + ".tbl";
    std::ifstream in(tablePath);
    if (!in)
        return table;

    std::string line;
    long lineNum = 0;
    while (std::getline(in, line))
    {
        lineNum++;
        if (line.empty() || line[0] == '#')
            continue;

        std::istringstream fields(line);
        std::string kind, hashText, bytesText;
        long srcLine;
        Entry entry;

        if (!(fields >> kind >> srcLine >> hashText >> bytesText) || (kind != "C" && kind != "S"))
            FATAL_ERROR("%s:%ld: malformed localization table entry\n", tablePath.c_str(), lineNum);

        entry.line = srcLine;
        entry.hash = std::strtoull(hashText.c_str(), nullptr, 16);
        entry.drop = (bytesText == "-");
        if (!ParseHexBytes(bytesText, entry.bytes))
            FATAL_ERROR("%s:%ld: malformed bytes in localization table entry\n", tablePath.c_str(), lineNum);

        if (kind == "C")
            table.cEntries.insert(std::make_pair(entry.hash, entry));
        else
            table.asmEntries[srcLine] = entry;
    }

    return table;
}

void LocTables::LogUsage(const std::string& file, long line)
{
    if (m_usageLog.empty())
        return;
    FILE* fp = std::fopen(m_usageLog.c_str(), "a");
    if (fp == nullptr)
        return;
    std::fprintf(fp, "%s:%ld\n", NormalizeSourcePath(file).c_str(), line);
    std::fclose(fp);
}

bool LocTables::LookupC(const std::string& file, long line, const std::vector<unsigned char>& original, std::vector<unsigned char>& out)
{
    Table& table = GetTable(file);
    if (table.cEntries.empty())
        return false;

    std::uint64_t hash = Fnv1a64(original.data(), original.size());
    auto range = table.cEntries.equal_range(hash);
    const Entry* best = nullptr;
    long bestDistance = 0;

    for (auto it = range.first; it != range.second; ++it)
    {
        long distance = std::labs(it->second.line - line);
        if (best == nullptr || distance < bestDistance)
        {
            best = &it->second;
            bestDistance = distance;
        }
    }

    if (best == nullptr)
        return false;

    out = best->bytes;
    LogUsage(file, best->line);
    return true;
}

bool LocTables::LookupAsm(const std::string& file, long line, const unsigned char* original, int length, std::vector<unsigned char>& out, std::string& error)
{
    Table& table = GetTable(file);
    auto it = table.asmEntries.find(line);
    if (it == table.asmEntries.end())
        return false;

    if (it->second.hash != Fnv1a64(original, length))
    {
        error = "localization table is out of date for this line; re-run 'make' (or 'tools/localization/loc.py generate')";
        return true;
    }

    out = it->second.bytes;
    LogUsage(file, line);
    return true;
}
