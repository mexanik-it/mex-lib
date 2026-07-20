#include "console_utils.h"

#ifdef _WIN32
    #include <windows.h>
    #include <iostream>

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

    // ANSI-верси€ (A) Ч безопаснее со св€зке с std::cout
    if (!FillConsoleOutputCharacterA(h, ' ', numCharsToWrite, start, &written)) {
        return false;
    }

    if (!SetConsoleCursorPosition(h, start)) {
        return false;
    }

    return true;
}
#else
    // «аглушка дл€ не-Windows: просто возвращаем true, чтобы код компилировалс€
    bool clear_console() {
        // Ќа Linux/FreeBSD можно добавить ANSI-очистку, если нужно
        return true; 
    }
#endif