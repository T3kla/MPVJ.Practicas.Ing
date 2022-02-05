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
    Registry.resize(REGISTRY_SIZE);
    for (int i = 0; i < REGISTRY_SIZE; i++)
        Registry[i] = Entity();

    // Player Setup
    Player = GetFreeEntity();
    Player->SetEntityType(EEntityType::Player);
    Player->SetPosition(BOARD_SIZE / 2);

    // Set random seed
    Logic::Init();

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
    for (int i = 0; i < REGISTRY_SIZE; i++)
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

int Game::GetScore()
{
    return Instance.Score;
}

void Game::SetScore(int Value)
{
    Instance.Score = Value;
}
