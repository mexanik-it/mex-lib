mex-lib
своя библиотека для работы с g++
---

#### 24/07/2026
 ***bool clear_console( );*** - очистка экрана 
```
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
```

#### 20/07/2026
[+] добавлена функция clear_console( ); очистка экрана \
**usage:**
```
#include <console_utils.h>
bool clear_console();
```
**source**
```

```

#### 17/07/2026
[+] первая версия библиотеки сделана,не содержит ничего полезного, просто тест

### Скачать локально
```cmd
git clone https://github.com/mexanik-it/mex-lib.git
```
======\
The end
