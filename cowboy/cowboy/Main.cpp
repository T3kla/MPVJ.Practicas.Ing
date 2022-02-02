#include <iostream>

#include "Console.h"
#include "Entity.h"

#include <Windows.h>
#include <conio.h>
#include <vector>

static constexpr int KEY_ESC = 27;

static constexpr int KEY_A = 97;
static constexpr int KEY_D = 100;
static constexpr int KEY_ARROWLEFT = 75;
static constexpr int KEY_ARROWRIGHT = 77;

static constexpr int REG_SIZE = 20;
static constexpr int BOARD_SIZE = 30;

static std::vector<Entity> Registry;
static char CharBuffer[64];

static int Input = 0;
static int Score = 0;

static auto ClampToBoard = [](int Pos) { return Pos <= 0 ? 1 : Pos >= BOARD_SIZE ? BOARD_SIZE - 1 : Pos; };
static auto CheckInBoard = [](int Pos) { return Pos > 0 || Pos < BOARD_SIZE; };

Entity &GetFreeEntity();
void Logic(Entity &Player);
void Render();

int main()
{
    // Registry Setup
    Registry.resize(REG_SIZE);
    for (int i = 0; i < REG_SIZE; i++)
        Registry[i] = Entity();

    // Player Setup
    Entity &Player = GetFreeEntity();
    Player.SetEntityType(E_EntityType::Player);
    Player.SetPosition(BOARD_SIZE / 2);

    do
    {
        Input = _kbhit() ? _getch() : 0;

        Logic(Player);

        Sleep(17);

        Render();

    } while (Input != KEY_ESC);
}

Entity &GetFreeEntity()
{
    // Get first deactivated entity
    for (int i = 0; i < REG_SIZE; i++)
        if (!Registry[i].GetIsActive())
        {
            auto &Entity = Registry.at(i);
            Entity.SetIsActive(true);
            return Entity;
        }
}

void Logic(Entity &Player)
{
    if (!Player.GetIsActive())
        return;

    int Position = 0;

    // Player movement
    Position = Player.GetPosition();
    if (Input != 0)
        if (Input == KEY_A)
            Player.SetPosition(ClampToBoard(Position - 1));
        else if (Input == KEY_D)
            Player.SetPosition(ClampToBoard(Position + 1));
        else if (Input == KEY_ARROWLEFT)
        {
            auto &Bullet = GetFreeEntity();
            Bullet.SetPosition(Position - 1);
            Bullet.SetEntityType(E_EntityType::BulletL);
        }
        else if (Input == KEY_ARROWRIGHT)
        {
            auto &Bullet = GetFreeEntity();
            Bullet.SetPosition(Position + 1);
            Bullet.SetEntityType(E_EntityType::BulletL);
        }

    // Enities movement
    for (int i = 0; i < REG_SIZE; i++)
    {
        if (!Registry[i].GetIsActive())
            continue;

        Position = Registry[i].GetPosition();

        if (!CheckInBoard(Position))
        {
            Registry[i].SetIsActive(false);
            continue;
        }

        auto Type = Registry[i].GetEntityType();

        if (Type == E_EntityType::EnemyL)
            Registry[i].SetPosition(Position - 1);
        else if (Type == E_EntityType::EnemyR)
            Registry[i].SetPosition(Position + 1);
        else if (Type == E_EntityType::BulletL)
            Registry[i].SetPosition(Position - 1);
        else if (Type == E_EntityType::BulletR)
            Registry[i].SetPosition(Position + 1);
    }
}

void Render()
{
    // Clear console
    cls::Clear();

    // Render Floor
    for (int i = 0; i <= BOARD_SIZE; i++)
        std::cout << (i == 0 ? '[' : i == BOARD_SIZE ? ']' : '_');

    // Render Entities
    for (int i = 0; i < REG_SIZE; i++)
    {
        if (!Registry[i].GetIsActive())
            continue;

        auto Type = Registry[i].GetEntityType();

        if (Type == E_EntityType::None)
            continue;

        cls::GotoXY(Registry[i].GetPosition(), 0);

        if (Type == E_EntityType::Player)
            std::cout << 'X';
        else if (Type == E_EntityType::EnemyL)
            std::cout << '}';
        else if (Type == E_EntityType::EnemyR)
            std::cout << '{';
        else if (Type == E_EntityType::BulletL)
            std::cout << '<';
        else if (Type == E_EntityType::BulletR)
            std::cout << '>';
    }

    // Render Score
    cls::GotoXY(BOARD_SIZE + 2, 0);
    sprintf_s(CharBuffer, "%02d", Score);
    std::cout << CharBuffer;

    // Flush console buffer
    std::cout << std::endl;
}
