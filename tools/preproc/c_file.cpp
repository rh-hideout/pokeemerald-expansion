// Copyright(c) 2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstdio>
#include <cstdarg>
#include <stdexcept>
#include <string>
#include <memory>
#include <cstring>
#include <cerrno>
#include "preproc.h"
#include "c_file.h"
#include "char_util.h"
#include "utf8.h"
#include "string_parser.h"
#include "io.h"

CFile::CFile(const char * filenameCStr, bool isStdin)
{
    if (isStdin)
        m_filename = std::string{"<stdin>/"}.append(filenameCStr);
    else
        m_filename = std::string(filenameCStr);

    m_buffer = ReadFileToBuffer(filenameCStr, isStdin, &m_size);

    m_pos = 0;
    m_lineNum = 1;
    m_isStdin = isStdin;
}

CFile::CFile(CFile&& other) : m_filename(std::move(other.m_filename))
{
    m_buffer = other.m_buffer;
    m_pos = other.m_pos;
    m_size = other.m_size;
    m_lineNum = other.m_lineNum;
    m_isStdin = other.m_isStdin;

    other.m_buffer = NULL;
}

CFile::~CFile()
{
    free(m_buffer);
}

void CFile::printf(const char *format, ...)
{
    std::va_list args;
    va_start(args, format);
    int n = vsnprintf(NULL, 0, format, args);
    va_end(args);

    char *s = new char[n + 1];
    va_start(args, format);
    std::vsnprintf(s, n + 1, format, args);
    va_end(args);
    m_output.append(s);
    delete[] s;
}

void CFile::putchar(char c)
{
    m_output.append(1, c);
}

void CFile::Preproc()
{
    char stringChar = 0;

    while (m_pos < m_size)
    {
        if (stringChar)
        {
            if (m_buffer[m_pos] == stringChar)
            {
                putchar(stringChar);
                m_pos++;
                stringChar = 0;
            }
            else if (m_buffer[m_pos] == '\\' && m_buffer[m_pos + 1] == stringChar)
            {
                putchar('\\');
                putchar(stringChar);
                m_pos += 2;
            }
            else
            {
                if (m_buffer[m_pos] == '\n')
                    m_lineNum++;
                putchar(m_buffer[m_pos]);
                m_pos++;
            }
        }
        else
        {
            TryConvertString();
            TryConvertCompoundString();
            TryConvertIncbin();

            if (m_pos >= m_size)
                break;

            char c = m_buffer[m_pos++];

            putchar(c);

            if (c == '\n')
                m_lineNum++;
            else if (c == '"')
                stringChar = '"';
            else if (c == '\'')
                stringChar = '\'';
        }
    }

    // TODO: Share the tails compound strings where possible (like the
    // 'ld' optimization for 'SHF_MERGE | SHF_STRINGS').
    for (auto it : m_compoundStrings)
    {
        // HINT: GCC puts the section name into the assembly without any
        // validation, so we're able to apply the 'SHF_MERGE' flag and
        // our own 'sh_entsize' by using '@' to comment out what GCC
        // would have put after the section name.
        // This will not work with Clang, see
        // https://discourse.llvm.org/t/creating-shf-merge-shf-strings-section/86399
        std::printf("static const unsigned char __attribute__((section(\".rodata.compound_string.%016lx,\\\"aM\\\",%%progbits,%ld @\"))) sCompoundString_%016lx[] = {", it.second, it.first.size(), it.second);
        if (it.first.size() > 0)
        {
            std::printf(" 0x%02X", it.first[0]);
            for (std::size_t i = 1; i < it.first.size(); i++)
                std::printf(", 0x%02X", it.first[i]);
        }
        std::printf(" };\n");
    }

    std::puts(m_output.c_str());
}

bool CFile::ConsumeHorizontalWhitespace()
{
    if (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
    {
        m_pos++;
        return true;
    }

    return false;
}

bool CFile::ConsumeNewline()
{
    if (m_buffer[m_pos] == '\r' && m_buffer[m_pos + 1] == '\n')
    {
        m_pos += 2;
        m_lineNum++;
        putchar('\n');
        return true;
    }

    if (m_buffer[m_pos] == '\n')
    {
        m_pos++;
        m_lineNum++;
        putchar('\n');
        return true;
    }

    return false;
}

void CFile::SkipWhitespace()
{
    while (ConsumeHorizontalWhitespace() || ConsumeNewline())
        ;
}

std::vector<unsigned char> CFile::ConvertString()
{
    std::vector<unsigned char> converted;

    while (true)
    {
        SkipWhitespace();

        if (m_buffer[m_pos] == '"')
        {
            unsigned char s[kMaxStringLength];
            int length = 0;
            StringParser stringParser(m_buffer, m_size);
            try
            {
                m_pos += stringParser.ParseString(m_pos, s, length);
            }
            catch (std::runtime_error& e)
            {
                RaiseError(e.what());
            }
            converted.insert(converted.end(), s, s + length);
        }
        else if (m_buffer[m_pos] == ')')
        {
            m_pos++;
            break;
        }
        else
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF");
            if (IsAsciiPrintable(m_buffer[m_pos]))
                RaiseError("unexpected character '%c'", m_buffer[m_pos]);
            else
                RaiseError("unexpected character '\\x%02X'", m_buffer[m_pos]);
        }
    }

    return converted;
}

void CFile::TryConvertString()
{
    long oldPos = m_pos;
    long oldLineNum = m_lineNum;
    bool noTerminator = false;

    if (m_buffer[m_pos] != '_' || (m_pos > 0 && IsIdentifierChar(m_buffer[m_pos - 1])))
        return;

    m_pos++;

    if (m_buffer[m_pos] == '_')
    {
        noTerminator = true;
        m_pos++;
    }

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_lineNum = oldLineNum;
        return;
    }

    m_pos++;

    SkipWhitespace();

    printf("{ ");

    std::vector<unsigned char> converted = ConvertString();
    for (std::size_t i = 0; i < converted.size(); i++)
        printf("0x%02X, ", converted[i]);

    if (noTerminator)
        printf(" }");
    else
        printf("0xFF }");
}

static std::uint64_t fnv1a(const std::vector<unsigned char>& bytes)
{
    std::uint64_t hash = 0xcbf29ce484222325UL;
    for (auto b : bytes)
        hash = (hash ^ b) * 0x00000100000001b3UL;
    return hash;
}

void CFile::TryConvertCompoundString()
{
    long oldPos = m_pos;
    long oldLineNum = m_lineNum;
    std::string ident = "COMPOUND_STRING";

    if ((m_pos > 0 && IsIdentifierChar(m_buffer[m_pos - 1])) || !CheckIdentifier(ident))
        return;

    m_pos += ident.length();

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_lineNum = oldLineNum;
        return;
    }

    m_pos++;
    std::vector<unsigned char> converted = ConvertString();
    converted.push_back(0xFF);

    std::uint64_t hash = fnv1a(converted);
    m_compoundStrings[converted] = hash;
    // WARNING: Assumes no collisions.
    // TODO: Incorporate filename to prevent cross-TU collisions.
    printf("sCompoundString_%016lx", hash);
}

bool CFile::CheckIdentifier(const std::string& ident)
{
    unsigned int i;

    for (i = 0; i < ident.length() && m_pos + i < (unsigned)m_size; i++)
        if (ident[i] != m_buffer[m_pos + i])
            return false;

    return (i == ident.length());
}

std::unique_ptr<unsigned char[]> CFile::ReadWholeFile(const std::string& path, int& size)
{
    FILE* fp = std::fopen(path.c_str(), "rb");

    if (fp == nullptr)
        RaiseError("Failed to open \"%s\" for reading.\n", path.c_str());

    std::fseek(fp, 0, SEEK_END);

    size = std::ftell(fp);

    std::unique_ptr<unsigned char[]> buffer = std::unique_ptr<unsigned char[]>(new unsigned char[size]);

    std::rewind(fp);

    if (std::fread(buffer.get(), size, 1, fp) != 1)
        RaiseError("Failed to read \"%s\".\n", path.c_str());

    std::fclose(fp);

    return buffer;
}

int ExtractData(const std::unique_ptr<unsigned char[]>& buffer, int offset, int size)
{
    switch (size)
    {
    case 1:
        return buffer[offset];
    case 2:
        return (buffer[offset + 1] << 8)
            | buffer[offset];
    case 4:
        return (buffer[offset + 3] << 24)
            | (buffer[offset + 2] << 16)
            | (buffer[offset + 1] << 8)
            | buffer[offset];
    default:
        FATAL_ERROR("Invalid size passed to ExtractData.\n");
    }
}

void CFile::TryConvertIncbin()
{
    std::string idents[8] = { "INCBIN_S8", "INCBIN_U8", "INCBIN_S16", "INCBIN_U16", "INCBIN_S32", "INCBIN_U32", "DUMMY", "INCBIN_COMP"};
    int incbinType = -1;

    for (int i = 0; i < 8; i++)
    {
        if (CheckIdentifier(idents[i]))
        {
            incbinType = i;
            break;
        }
    }

    if (incbinType == -1)
        return;

    int size = 1 << (incbinType / 2);
    if (size > 4)
        size = 4;
    bool isSigned = ((incbinType % 2) == 0);

    long oldPos = m_pos;
    long oldLineNum = m_lineNum;

    m_pos += idents[incbinType].length();

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_lineNum = oldLineNum;
        return;
    }

    m_pos++;

    printf("{");

    while (true)
    {
        SkipWhitespace();

        if (m_buffer[m_pos] != '"')
            RaiseError("expected double quote");

        m_pos++;

        int startPos = m_pos;

        while (m_buffer[m_pos] != '"')
        {
            if (m_buffer[m_pos] == 0)
            {
                if (m_pos >= m_size)
                    RaiseError("unexpected EOF in path string");
                else
                    RaiseError("unexpected null character in path string");
            }

            if (m_buffer[m_pos] == '\r' || m_buffer[m_pos] == '\n')
                RaiseError("unexpected end of line character in path string");

            if (m_buffer[m_pos] == '\\')
                RaiseError("unexpected escape in path string");

            m_pos++;
        }

        std::string path(&m_buffer[startPos], m_pos - startPos);

        // INCBIN_COMP; include *compressed* version of file
        if (incbinType == 7)
            path = path.append(".smol");

        m_pos++;

        int fileSize;
        std::unique_ptr<unsigned char[]> buffer = ReadWholeFile(path, fileSize);

        if ((fileSize % size) != 0)
            RaiseError("Size %d doesn't evenly divide file size %d.\n", size, fileSize);

        int count = fileSize / size;
        int offset = 0;

        for (int i = 0; i < count; i++)
        {
            int data = ExtractData(buffer, offset, size);
            offset += size;

            if (isSigned)
                printf("%d,", data);
            else
                printf("%uu,", data);
        }

        SkipWhitespace();

        if (m_buffer[m_pos] != ',')
            break;

        m_pos++;
    }

    if (m_buffer[m_pos] != ')')
        RaiseError("expected ')'");

    m_pos++;

    printf("}");
}

// Reports a diagnostic message.
void CFile::ReportDiagnostic(const char* type, const char* format, std::va_list args)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    std::vsnprintf(buffer, bufferSize, format, args);
    std::fprintf(stderr, "%s:%ld: %s: %s\n", m_filename.c_str(), m_lineNum, type, buffer);
}

#define DO_REPORT(type)                   \
do                                        \
{                                         \
    std::va_list args;                    \
    va_start(args, format);               \
    ReportDiagnostic(type, format, args); \
    va_end(args);                         \
} while (0)

// Reports an error diagnostic and terminates the program.
void CFile::RaiseError(const char* format, ...)
{
    DO_REPORT("error");
    std::exit(1);
}

// Reports a warning diagnostic.
void CFile::RaiseWarning(const char* format, ...)
{
    DO_REPORT("warning");
}
