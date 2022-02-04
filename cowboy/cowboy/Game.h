#pragma once

#include <vector>

static constexpr int KEY_ESC = 27;

static constexpr int KEY_A = 97;
static constexpr int KEY_D = 100;
static constexpr int KEY_ARROWLEFT = 75;
static constexpr int KEY_ARROWRIGHT = 77;

static constexpr int REG_SIZE = 20;
static constexpr int BULLETS_PER_SIDE = 5;
static constexpr int BOARD_SIZE = 100;

static int Score = 0;

class Entity;

class Game
{
  private:
    Game(){};

    static Game Instance;
    static std::vector<Entity> Registry;
    static Entity *Player;

  public:
    Game(const Game &) = delete;

    static void Run();
    static Entity *GetFreeEntity();
    static std::vector<Entity> &GetRegistry();
    static Entity *GetPlayer();
};
