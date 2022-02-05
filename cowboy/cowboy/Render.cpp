#include "Render.h"

#include <iostream>

#include "Console.h"
#include "Entity.h"
#include "Game.h"

Render Render::Instance;

static char CharBuffer[64];

void Render::Run()
{
    auto &Registry = Game::GetRegistry();

    // Clear console
    cls::Clear();

    // Render Floor
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

        if (Type == EEntityType::Player)
            std::cout << 'X';
        else if (Type == EEntityType::EnemyL)
            std::cout << '*';
        else if (Type == EEntityType::EnemyR)
            std::cout << '*';
        else if (Type == EEntityType::BulletL)
            std::cout << '<';
        else if (Type == EEntityType::BulletR)
            std::cout << '>';
    }

    // Render Score
    cls::GotoXY(BOARD_SIZE + 2, 0);
    sprintf_s(CharBuffer, "%02d", Game::GetScore());
    std::cout << CharBuffer;

    // Flush console buffer
    std::cout << std::endl;
}
