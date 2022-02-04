#include "Logic.h"

#include "Entity.h"
#include "Game.h"
#include "Input.h"

static auto ClampToBoard = [](int Pos) { return Pos <= 0 ? 1 : Pos >= BOARD_SIZE ? BOARD_SIZE - 1 : Pos; };
static auto CheckInBoard = [](int Pos) { return Pos > 1 && Pos < BOARD_SIZE - 1; };

Logic Logic::Instance;

void Logic::Run()
{
    // Don't update if player is dead
    if (!Game::GetPlayer()->GetIsActive())
        return;

    // Player
    Instance.PlayerLogic();
    Instance.EntityLogic();
}

void Logic::EntityLogic()
{
    auto &Registry = Game::GetRegistry();
    int Position = 0;

    // Enities movement
    for (int i = 0; i < REG_SIZE; i++)
    {
        if (!Registry[i].GetIsActive() || Registry[i].GetEntityType() == E_EntityType::Player)
            continue;

        Position = Registry[i].GetPosition();

        // Deactivate if out of bounds
        if (!CheckInBoard(Position))
        {
            Registry[i].SetIsActive(false);
            continue;
        }

        auto Type = Registry[i].GetEntityType();

        // Movement of enemies and bullets
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

void Logic::PlayerLogic()
{
    auto Player = Game::GetPlayer();
    auto Input = Input::GetInput();
    int Position = Player->GetPosition();

    if (Input == 0)
        return;

    // Movement
    if (Input == KEY_A)
        Player->SetPosition(ClampToBoard(Position - 1));
    else if (Input == KEY_D)
        Player->SetPosition(ClampToBoard(Position + 1));

    // Shooting
    if (Input != KEY_ARROWLEFT && Input != KEY_ARROWRIGHT)
        return;

    int Left, Right;
    BulletsPerSide(Left, Right);

    auto *Bullet = Game::GetFreeEntity();

    if (!Bullet)
        return;

    if (Input == KEY_ARROWLEFT && Left < BULLETS_PER_SIDE)
    {
        Bullet->SetPosition(Position - 1);
        Bullet->SetEntityType(E_EntityType::BulletL);
    }
    else if (Input == KEY_ARROWRIGHT && Right < BULLETS_PER_SIDE)
    {
        Bullet->SetPosition(Position + 1);
        Bullet->SetEntityType(E_EntityType::BulletR);
    }
}

void Logic::BulletsPerSide(int &Left, int &Right)
{
    auto &Registry = Game::GetRegistry();

    Left = 0;
    Right = 0;

    for (int i = 0; i < REG_SIZE; i++)
    {
        auto Type = Registry[i].GetEntityType();

        if (!Registry[i].GetIsActive())
            return;

        if (Type == E_EntityType::BulletL)
            Left++;
        else if (Type == E_EntityType::BulletR)
            Right++;
    }
}
