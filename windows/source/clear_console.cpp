/***************************************************************************************************/
/* simle cleaning screen                                                                           */
/*-------------------------------------------------------------------------------------------------*/
/***************************************************************************************************/
/* просто очищает экран                                                                            */
/*-------------------------------------------------------------------------------------------------*/
/* clear_console.cpp   правильная очистка экрана, по всем канонам C++                              */

#include "console_utils.h"
#include <windows.h>
#include <iostream>

bool clear_console() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h == INVALID_HANDLE_VALUE || h == nullptr) {
        return false;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi{};
    if (!GetConsoleScreenBufferInfo(h, &csbi)) {
        return false;
    }

    // Используем видимую область окна, а не весь буфер памяти
    const DWORD width = static_cast<DWORD>(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    const DWORD height = static_cast<DWORD>(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
    const DWORD cellCount = width * height;
    
    COORD start{0, 0};
    DWORD writtenChars = 0;
    DWORD writtenAttrs = 0;

    // 1. Чистим символы
    if (!FillConsoleOutputCharacterA(h, ' ', cellCount, start, &writtenChars)) {
        return false;
    }

    // 2. КРИТИЧНО: Чистим атрибуты цветов (сброс к белому на черном)
    WORD defaultAttr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    if (!FillConsoleOutputAttribute(h, defaultAttr, cellCount, start, &writtenAttrs)) {
        return false;
    }

    // 3. Гарантируем полную очистку
    if (writtenChars != cellCount || writtenAttrs != cellCount) {
        std::cerr << "[Error] Failed to fully clear console buffer." << std::endl;
        return false;
    }

    // 4. Возвращаем курсор
    return SetConsoleCursorPosition(h, start);
}
/*  старая версия
bool clear_console() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h == INVALID_HANDLE_VALUE) {
        return false;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(h, &csbi)) {
        return false;
    }

    DWORD written = 0;
    COORD start = {0, 0};
    DWORD numCharsToWrite = csbi.dwSize.X * csbi.dwSize.Y;

    // ANSI-версия (A) — безопаснее со связке с std::cout
    if (!FillConsoleOutputCharacterA(h, ' ', numCharsToWrite, start, &written)) {
        return false;
    }

    if (!SetConsoleCursorPosition(h, start)) {
        return false;
    }

    return true;
} */
