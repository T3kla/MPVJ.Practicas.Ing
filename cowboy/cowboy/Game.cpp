#include "Game.h"

#include <Windows.h>

#include "Entity.h"
#include "Input.h"
#include "Logic.h"
#include "Render.h"

Game Game::Instance;
std::vector<Entity> Game::Registry;
Entity *Game::Player;

void Game::Run()
{
    // Registry Setup
    Registry.resize(REG_SIZE);
    for (int i = 0; i < REG_SIZE; i++)
        Registry[i] = Entity();

    // Player Setup
    Player = GetFreeEntity();
    Player->SetEntityType(E_EntityType::Player);
    Player->SetPosition(BOARD_SIZE / 2);

    // Game Loop
    while (Input::GetInput() != KEY_ESC)
    {
        Input::Run();
        Logic::Run();
        Sleep(17);
        Render::Run();
    }
}

Entity *Game::GetFreeEntity()
{
    for (int i = 0; i < REG_SIZE; i++)
        if (!Registry[i].GetIsActive())
        {
            auto *Entity = &Registry[i];
            Entity->SetIsActive(true);
            return Entity;
        }
    return nullptr;
}

std::vector<Entity> &Game::GetRegistry()
{
    return Registry;
}

Entity *Game::GetPlayer()
{
    return Player;
}
