#include <iostream>

#include <Windows.h>
#include <array>
#include <conio.h>

// Aesthetics
using i64 = long long;
using i32 = int;
using i16 = short;
using i8 = char;

using u64 = unsigned long long;
using u32 = unsigned int;
using u16 = unsigned short;
using u8 = unsigned char;

using f64 = double;
using f32 = float;

// Compiled Data
constexpr f64 FPS = 30.;
constexpr f64 STP = 1000. / FPS;

constexpr i8 BOARD_LEN = 30;

constexpr char SPR_PLAYER = 'X';
constexpr char SPR_BLANK = '_';
constexpr char SPR_BLT_L = '<', SPR_BLT_R = '>';
constexpr char SPR_ENEMY_L = '*', SPR_ENEMY_R = '&';

constexpr char IN_MOVE_L = 'h', IN_MOVE_R = 'i'; // Esto me duele
constexpr char IN_SHOOT_L = 'j', IN_SHOOT_R = 'k';
constexpr char IN_EXIT = 27; // Esc

// Data
i8 input = '-';
std::array<char, BOARD_LEN> board;

u32 player_score = 0;

// Functions
void Input();
void Game();
void Render();
i8 Collide(i8 a, i8 b);

// Helper Lambdas
auto ClampPos = [](const i8 &pos) {
  if (pos < 0)
    return (i8)0;
  if (pos > BOARD_LEN)
    return BOARD_LEN;
  return pos;
};

auto FindInBoard = [](const i8 &spr) {
  for (i8 i = 0; i < BOARD_LEN; i++)
    if (board[i] == spr)
      return i;

  return (i8)-1;
};

// Game Loop
int main() {
  for (i8 i = 0; i < BOARD_LEN; i++)
    board[i] = SPR_BLANK;
  board[BOARD_LEN / 2] = SPR_PLAYER;

  do {
    Input();
    Game();
    Render();

    Sleep((DWORD)STP);
  } while (input != IN_EXIT);
}

void Input() {
  input = SPR_BLANK;

  if (!_kbhit())
    return;

  input = _getch();
  auto ppos = FindInBoard(SPR_PLAYER);

  switch (input) {
  case IN_MOVE_L:
    board[ppos - 1] = Collide(SPR_PLAYER, board[ppos - 1]);
    board[ppos] = SPR_BLANK;
    break;
  case IN_MOVE_R:
    board[ppos + 1] = Collide(SPR_PLAYER, board[ppos + 1]);
    board[ppos] = SPR_BLANK;
    break;
  case IN_SHOOT_L:
    board[ppos - 1] = Collide(SPR_BLT_L, board[ppos - 1]);
    break;
  case IN_SHOOT_R:
    board[ppos + 1] = Collide(SPR_BLT_R, board[ppos + 1]);
    break;
  }
}

void Game() {
  for (i8 i = 0; i < BOARD_LEN; i++) {

    if (i == 0 || i == 29) {
      board[i] = SPR_BLANK;
      continue;
    }

    if (board[i] == SPR_ENEMY_L) {
      board[i + 1] = Collide(SPR_ENEMY_L, board[i + 1]);
      board[i] = SPR_BLANK;
      i++;
    } else if (board[i] == SPR_ENEMY_R) {
      board[i - 1] = Collide(SPR_ENEMY_R, board[i - 1]);
      board[i] = SPR_BLANK;
    } else if (board[i] == SPR_BLT_L) {
      board[i - 1] = Collide(SPR_BLT_L, board[i - 1]);
      board[i] = SPR_BLANK;
    } else if (board[i] == SPR_BLT_R) {
      board[i + 1] = Collide(SPR_BLT_R, board[i + 1]);
      board[i] = SPR_BLANK;
      i++;
    }
  }
}

void Render() {
  system("cls");

  for (i8 i = 0; i < BOARD_LEN; i++)
    std::cout << board[i];

  std::cout << std::endl;
}

i8 Collide(i8 a, i8 b) {
  if (a == SPR_BLANK)
    return b;
  if (b == SPR_BLANK)
    return a;

  if (a == SPR_PLAYER && (b == SPR_ENEMY_L || b == SPR_ENEMY_R))
    return b;

  if (a == SPR_ENEMY_L && (b == SPR_BLT_R || b == SPR_BLT_L))
    return SPR_BLANK;

  return SPR_BLANK;
}
