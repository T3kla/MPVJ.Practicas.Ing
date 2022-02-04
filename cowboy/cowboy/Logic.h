#pragma once

class Logic
{
  private:
    Logic(){};
    static Logic Instance;

    void EntityLogic();
    void PlayerLogic();
    void BulletsPerSide(int &Left, int &Right);

  public:
    Logic(const Logic &) = delete;

    static void Run();
};
