#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include "engine.h"
#include "world.h"

// Compiled Data
// constexpr i8 BOARD_LEN = 30;
//
// constexpr char SPR_PLAYER = 'X';
// constexpr char SPR_BLANK = '_';
// constexpr char SPR_BLT_L = '<', SPR_BLT_R = '>';
// constexpr char SPR_ENEMY_L = '*', SPR_ENEMY_R = '&';
//
// constexpr char IN_MOVE_L = 'h', IN_MOVE_R = 'i';
// constexpr char IN_SHOOT_L = 'j', IN_SHOOT_R = 'k';
// constexpr char IN_EXIT = 27; // Esc

int main() {
  auto world = World();

  Engine::Run();
}
