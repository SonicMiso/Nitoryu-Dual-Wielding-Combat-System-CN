#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <fstream>
#include <string>

namespace
{
    std::wstring GetModuleDirectory()
    {
        HMODULE module = nullptr;

        if (!GetModuleHandleExW(
                GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                    GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                reinterpret_cast<LPCWSTR>(&GetModuleDirectory),
                &module))
        {
            return L"";
        }

        std::wstring path;
        DWORD size = MAX_PATH;

        for (;;)
        {
            path.resize(size);
            DWORD length = GetModuleFileNameW(module, path.data(), size);

            if (length == 0)
                return L"";

            if (length < size - 1)
            {
                path.resize(length);
                break;
            }

            size *= 2;
            if (size > 32768)
                return L"";
        }

        const size_t slash = path.find_last_of(L"\\/");
        if (slash == std::wstring::npos)
            return L"";

        path.resize(slash);
        return path;
    }

    bool FileExists(const std::wstring& path)
    {
        const DWORD attrs = GetFileAttributesW(path.c_str());
        return attrs != INVALID_FILE_ATTRIBUTES &&
               (attrs & FILE_ATTRIBUTE_DIRECTORY) == 0;
    }

    void Log(const std::wstring& message)
    {
        const std::wstring dir = GetModuleDirectory();
        if (dir.empty())
            return;

        std::ofstream log(dir + L"\\NitoryuCNBridge.log", std::ios::app);
        if (!log.is_open())
            return;

        const int required = WideCharToMultiByte(
            CP_UTF8, 0, message.c_str(), static_cast<int>(message.size()),
            nullptr, 0, nullptr, nullptr);

        if (required <= 0)
            return;

        std::string utf8(static_cast<size_t>(required), '\0');
        WideCharToMultiByte(
            CP_UTF8, 0, message.c_str(), static_cast<int>(message.size()),
            utf8.data(), required, nullptr, nullptr);

        log << utf8 << "\n";
    }

    bool CopyTranslationFile()
    {
        const std::wstring bridgeDir = GetModuleDirectory();
        if (bridgeDir.empty())
        {
            Log(L"[ERROR] Could not determine bridge plugin directory.");
            return false;
        }

        /*
         * Workshop layout:
         *   ...\steamapps\workshop\content\233860\<mod id>\
         *
         * The bridge itself is stored in the translation mod directory,
         * so its parent directory is the Kenshi Workshop content directory.
         */
        const size_t slash = bridgeDir.find_last_of(L"\\/");
        if (slash == std::wstring::npos)
        {
            Log(L"[ERROR] Could not determine Workshop content directory.");
            return false;
        }

        const std::wstring workshopGameDir = bridgeDir.substr(0, slash);

        // Original Nitoryu Workshop item.
        const std::wstring nitoryuRoot =
            workshopGameDir + L"\\3812165089";

        const std::wstring source =
            bridgeDir + L"\\lang\\zh.ini";
        const std::wstring targetDir =
            nitoryuRoot + L"\\lang";
        const std::wstring target =
            targetDir + L"\\zh.ini";

        if (!FileExists(source))
        {
            Log(L"[ERROR] Translation file not found: " + source);
            return false;
        }

        const DWORD nitoryuAttrs = GetFileAttributesW(nitoryuRoot.c_str());
        if (nitoryuAttrs == INVALID_FILE_ATTRIBUTES ||
            (nitoryuAttrs & FILE_ATTRIBUTE_DIRECTORY) == 0)
        {
            Log(L"[ERROR] Original Nitoryu Workshop directory not found: " + nitoryuRoot);
            return false;
        }

        if (!CreateDirectoryW(targetDir.c_str(), nullptr))
        {
            const DWORD error = GetLastError();
            if (error != ERROR_ALREADY_EXISTS)
            {
                Log(L"[ERROR] Could not create language directory: " + targetDir);
                return false;
            }
        }

        if (!CopyFileW(source.c_str(), target.c_str(), FALSE))
        {
            Log(L"[ERROR] CopyFileW failed. Error=" + std::to_wstring(GetLastError()));
            return false;
        }

        Log(L"[OK] Copied " + source + L" -> " + target);
        return true;
    }
}

// RE_Kenshi looks up the MSVC C++ decorated name:
// ?startPlugin@@YAXXZ
__declspec(dllexport) void startPlugin()
{
    CopyTranslationFile();
}
