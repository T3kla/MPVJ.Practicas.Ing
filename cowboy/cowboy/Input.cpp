#include "Input.h"
#include <conio.h>

char Input::CurrentInput = 0;

void Input::Run()
{
    CurrentInput = _kbhit() ? _getch() : 0;
}

char Input::GetInput()
{
    return CurrentInput;
}
