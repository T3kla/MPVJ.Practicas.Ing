#include "Logic.h"

#include <time.h>

#include "Entity.h"
#include "Game.h"
#include "Input.h"

static auto ClampToBoard = [](int Pos) { return Pos <= 0 ? 1 : Pos >= BOARD_SIZE ? BOARD_SIZE - 1 : Pos; };
static auto CheckInBoard = [](int Pos) { return Pos > 0 && Pos < BOARD_SIZE; };
static auto RandomRange = [](int min, int max) { return rand() % (++max - min) + min; };

void BulletsPerSide(int &Left, int &Right);
EEntityType ToLowerEnum(EEntityType Value);

Logic Logic::Instance;

void Logic::Init()
{
    // Seed rand
    srand((unsigned int)time(0));
}

void Logic::Run()
{
    // Don't update if player is dead
    if (!Game::GetPlayer()->GetIsActive())
        return;

    Instance.PlayerLogic();
    Instance.BulletMovement();
    Instance.Collisions();
    Instance.EnemyMovement();
    Instance.Collisions();
    Instance.EnemySpawning();
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
        Bullet->SetEntityType(EEntityType::BulletL);
    }
    else if (Input == KEY_ARROWRIGHT && Right < BULLETS_PER_SIDE)
    {
        Bullet->SetPosition(Position + 1);
        Bullet->SetEntityType(EEntityType::BulletR);
    }
}

void Logic::BulletMovement()
{
    auto &Registry = Game::GetRegistry();
    int Position = 0;

    for (int i = 0; i < REGISTRY_SIZE; i++)
    {
        if (!Registry[i].GetIsActive())
            continue;

        auto Type = Registry[i].GetEntityType();

        if (Registry[i].GetEntityType() != EEntityType::BulletL && Registry[i].GetEntityType() != EEntityType::BulletR)
            continue;

        Position = Registry[i].GetPosition();

        // Deactivate if out of bounds
        if (!CheckInBoard(Position))
        {
            Registry[i].SetIsActive(false);
            continue;
        }

        // Movement
        if (Type == EEntityType::BulletL)
            Registry[i].SetPosition(Position - 1);
        else if (Type == EEntityType::BulletR)
            Registry[i].SetPosition(Position + 1);
    }
}

void Logic::Collisions()
{
    auto &Registry = Game::GetRegistry();

    // Looks like O(n^2) but:

    for (int i = 0; i < REGISTRY_SIZE; i++)
        for (int j = 0; j < REGISTRY_SIZE; j++)
        {
            // No comparison against itself
            if (i == j)
                continue;

            auto &EntityA = Registry[i];
            auto &EntityB = Registry[j];

            if (!EntityA.GetIsActive() || !EntityB.GetIsActive())
                continue;

            // No comparison if not in the same spot
            if (EntityA.GetPosition() != EntityB.GetPosition())
                continue;

            auto EntityA_Type = ToLowerEnum(EntityA.GetEntityType());
            auto EntityB_Type = ToLowerEnum(EntityB.GetEntityType());

            // Player - Enemy Collision
            if (EntityA_Type == EEntityType::Player && EntityB_Type == EEntityType::Enemy)
            {
                EntityA.SetIsActive(false);
            }
            // Enemy - Bullet Collision
            else if (EntityA_Type == EEntityType::Enemy && EntityB_Type == EEntityType::Bullet)
            {
                EntityA.SetIsActive(false);
                EntityB.SetIsActive(false);

                Game::SetScore(Game::GetScore() + 1);
            }
        }
}

void Logic::EnemyMovement()
{
    auto &Registry = Game::GetRegistry();
    int Position = 0;

    if (EnemyMovementDelayCounter > ENEMY_MOVEMENT_DELAY)
        EnemyMovementDelayCounter = 0;
    else
        EnemyMovementDelayCounter++;

    for (int i = 0; i < REGISTRY_SIZE; i++)
    {
        if (!Registry[i].GetIsActive())
            continue;

        auto Type = Registry[i].GetEntityType();

        if (Registry[i].GetEntityType() != EEntityType::EnemyL && Registry[i].GetEntityType() != EEntityType::EnemyR)
            continue;

        Position = Registry[i].GetPosition();

        // Deactivate if out of bounds
        if (!CheckInBoard(Position))
        {
            Registry[i].SetIsActive(false);
            continue;
        }

        // TODO: IA básica, mirar la bullet más cercana y huir

        // Enemy Movement
        if (EnemyMovementDelayCounter == ENEMY_MOVEMENT_DELAY)
        {
            if (Type == EEntityType::EnemyL)
                Registry[i].SetPosition(Position + 1);
            else if (Type == EEntityType::EnemyR)
                Registry[i].SetPosition(Position - 1);
        }
    }
}

void Logic::EnemySpawning()
{
    auto Chance = RandomRange(0, 100);

    if (Chance < 97)
        return;

    auto *Enemy = Game::GetFreeEntity();

    if (!Enemy)
        return;

    if (RandomRange(0, 1) == 0)
    {
        Enemy->SetPosition(1);
        Enemy->SetEntityType(EEntityType::EnemyL);
    }
    else
    {
        Enemy->SetPosition(BOARD_SIZE - 1);
        Enemy->SetEntityType(EEntityType::EnemyR);
    }
}

void BulletsPerSide(int &Left, int &Right)
{
    auto &Registry = Game::GetRegistry();

    Left = 0;
    Right = 0;

    for (int i = 0; i < REGISTRY_SIZE; i++)
    {
        auto Type = Registry[i].GetEntityType();

        if (!Registry[i].GetIsActive())
            continue;

        if (Type == EEntityType::BulletL)
            Left++;
        else if (Type == EEntityType::BulletR)
            Right++;
    }
}

EEntityType ToLowerEnum(EEntityType Value)
{
    if (Value == EEntityType::Player)
        return EEntityType::Player;
    else if (Value == EEntityType::BulletL)
        return EEntityType::Bullet;
    else if (Value == EEntityType::BulletR)
        return EEntityType::Bullet;
    else if (Value == EEntityType::EnemyL)
        return EEntityType::Enemy;
    else if (Value == EEntityType::EnemyR)
        return EEntityType::Enemy;
}
