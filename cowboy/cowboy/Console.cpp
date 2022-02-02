#include "Console.h"
#include <Windows.h>

namespace cls
{

void GotoXY(int x, int y)
{
    COORD pos = {(short)x, (short)y};
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out, pos);
}

void Clear()
{
    system("cls");
}

} // namespace cls
