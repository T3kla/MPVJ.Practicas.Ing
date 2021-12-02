#include "console.h"
#include <conio.h>
#include <windows.h>

namespace cls
{

void gotoxy(i16 x, i16 y)
{
    COORD pos = {x, y};
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out, pos);
}

void clear()
{
    system("cls");
}

} // namespace cls
