#include "Render.h"

#include <Windows.h>
#include <iostream>

#include "Console.h"
#include "Entity.h"
#include "Game.h"

Render Render::Instance;

static char CharBuffer[64];

void Render::Run()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    auto &Registry = Game::GetRegistry();

    // Clear console
    cls::Clear();

    // Render Floor
    SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i <= BOARD_SIZE; i++)
        std::cout << (i == 0 ? '[' : i == BOARD_SIZE ? ']' : '_');

    // Render Entities
    for (int i = 0; i < REGISTRY_SIZE; i++)
    {
        if (!Registry[i].GetIsActive())
            continue;

        auto Type = Registry[i].GetEntityType();

        if (Type == EEntityType::None)
            continue;

        cls::GotoXY(Registry[i].GetPosition(), 0);

        // Print box
        if (Type == EEntityType::Player)
        {
            SetConsoleTextAttribute(hConsole, 2);
            std::cout << 'X';
        }
        else if (Type == EEntityType::EnemyL)
        {
            SetConsoleTextAttribute(hConsole, 4);
            std::cout << '*';
        }
        else if (Type == EEntityType::EnemyR)
        {
            SetConsoleTextAttribute(hConsole, 4);
            std::cout << '*';
        }
        else if (Type == EEntityType::BulletL)
        {
            SetConsoleTextAttribute(hConsole, 3);
            std::cout << '<';
        }
        else if (Type == EEntityType::BulletR)
        {
            SetConsoleTextAttribute(hConsole, 3);
            std::cout << '>';
        }
    }

    // Render Score
    SetConsoleTextAttribute(hConsole, 15);
    cls::GotoXY(BOARD_SIZE + 2, 0);
    sprintf_s(CharBuffer, "%02d", Game::GetScore());
    std::cout << CharBuffer;

    // Flush console buffer
    std::cout << std::endl;
}
