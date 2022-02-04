#pragma once

class Logic
{
  private:
    Logic(){};
    static Logic Instance;

    void EntityLogic();
    void PlayerLogic();
    void BulletsPerSide(int &Left, int &Right);
    void EnemySpawning();

  public:
    Logic(const Logic &) = delete;

    static void Init();
    static void Run();
};
