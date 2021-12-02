#include <iostream>

#include "board/board.h"
#include "console/console.h"
#include "typedef.h"
#include <chrono>
#include <thread>

auto sleep = [](u8 t) { std::this_thread::sleep_for(std::chrono::milliseconds(t)); };

int main()
{
    do
    {
        sleep(17);
    } while (true);
}
