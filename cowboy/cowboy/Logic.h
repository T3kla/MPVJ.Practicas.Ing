#pragma once

class Logic
{
  private:
    Logic(){};
    static Logic Instance;

    void PlayerLogic();
    void BulletMovement();
    void Collisions();
    void EnemyMovement();
    void EnemySpawning();

    int EnemyMovementDelayCounter = 0;

  public:
    Logic(const Logic &) = delete;

    static void Init();
    static void Run();
};
