#ifndef WINCOLOR_H
#define WINCOLOR_H

#include <stdio.h>
#include <wchar.h>
#include <windows.h>


#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif // ENABLE_VIRTUAL_TERMINAL_PROCESSING

#define BLACK_FG wprintf(L"\x1b[30m");
#define RED_FG wprintf(L"\x1b[31m");
#define GREEN_FG wprintf(L"\x1b[32m");
#define YELLOW_FG wprintf(L"\x1b[33m");
#define BLUE_FG wprintf(L"\x1b[34m");
#define MAGENTA_FG wprintf(L"\x1b[35m");
#define CYAN_FG wprintf(L"\x1b[36m");
#define WHITE_FG wprintf(L"\x1b[37m");

#define BLACK_BG wprintf(L"\x1b[40m");
#define RED_BG wprintf(L"\x1b[41m");
#define GREEN_BG wprintf(L"\x1b[42m");
#define YELLOW_BG wprintf(L"\x1b[43m");
#define BLUE_BG wprintf(L"\x1b[44m");
#define MAGENTA_BG wprintf(L"\x1b[45m");
#define CYAN_BG wprintf(L"\x1b[46m");
#define WHITE_BG wprintf(L"\x1b[47m");


int winc_main()
{
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }

    // Set Graphics Rendition (SGR) terminal escape sequences


}

#endif // WINCOLOR_H
