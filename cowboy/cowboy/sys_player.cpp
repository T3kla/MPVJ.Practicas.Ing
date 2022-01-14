#include "sys_player.h"

#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "entity.h"
#include "player.h"
#include "rigidbody.h"
#include "stasis.h"
#include "transform.h"
#include "vec.h"

SysPlayer::SysPlayer() {}
SysPlayer::~SysPlayer() {}

void SysPlayer::Awake() {}

void SysPlayer::Start() {}

void SysPlayer::Update() {
  Transform *ptrTF = nullptr;
  Rigidbody *ptrRB = nullptr;
  Player *ptrPL = nullptr;

  auto players = Engine::GetRegistry().view<Transform, Rigidbody, Player>();

  for (auto [entity, tf, rb, pl] : players.each()) {
    ptrTF = &tf;
    ptrRB = &rb;
    ptrPL = &pl;
    break;
  }

  if (!ptrPL)
    return;

  // Look towards mouse
  auto ang = (EngineInput::GetMousePosInWorld() - ptrTF->position).AngleDeg();
  ptrTF->rotation = ang;

  // Movement
  Vec2 vel = ptrRB->velocity;
  Vec2 add = {0.f, 0.f};

  if (EngineInput::GetKey(EngineInput::KeyCode::W))
    add.y--;
  if (EngineInput::GetKey(EngineInput::KeyCode::S))
    add.y++;
  if (EngineInput::GetKey(EngineInput::KeyCode::A))
    add.x++;
  if (EngineInput::GetKey(EngineInput::KeyCode::D))
    add.x--;

  vel += (add.Normalized() * ptrPL->maxSpeed) / ptrPL->acceleration;

  // Shooting TODO: shoot
  // if (EngineInput::GetKey(EngineInput::KeyCode::Mouse1))
  //  add.x--;

  // auto players = Engine::GetRegistry().view<Transform, Rigidbody, Player>();

  // for (auto [entity, tf, rb, pl] : players.each()) {
  //   ptrTF = &tf;
  //   ptrRB = &rb;
  //   ptrPL = &pl;
  //   break;
  // }
}

void SysPlayer::Fixed() {}

void SysPlayer::Quit() {}
