#include "sys_player.h"

#include "bullet.h"
#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "entity.h"
#include "gameobject.h"
#include "player.h"
#include "rigidbody.h"
#include "stasis.h"
#include "transform.h"
#include "vec.h"

Transform *tf = nullptr;
Rigidbody *rb = nullptr;
Player *pl = nullptr;

bool SearchForPlayer() {
  auto players = Engine::GetRegistry().view<Transform, Rigidbody, Player>();
  for (auto [entity, tf0, rb0, pl0] : players.each()) {
    tf = &tf0;
    rb = &rb0;
    pl = &pl0;
    break;
  }
  return pl != 0 ? true : false;
}

SysPlayer::SysPlayer() {}
SysPlayer::~SysPlayer() {}

void SysPlayer::Awake() {}

void SysPlayer::Start() {}

void SysPlayer::Update() {
  if (!SearchForPlayer())
    return;

  // Look towards mouse
  auto ang = (EngineInput::GetMousePosInWorld() - tf->position).AngleDeg();
  tf->rotation = ang;

  // Shooting TODO: shoot
  if (EngineInput::GetKey(EngineInput::KeyCode::Left)) {
    entt::entity bullet;

    auto bullets = Engine::GetRegistry().view<GameObject, Bullet>();
    for (auto [entity, go, bl] : bullets.each()) {
      if (!go.isActive)
        bullet = entity;
      break;
    }
  }
}

void SysPlayer::Fixed() {
  if (!SearchForPlayer())
    return;

  // Movement
  Vec2 vel = rb->velocity;
  Vec2 add = {0.f, 0.f};
  float max = pl->maxSpeed;
  float acc = pl->acceleration;

  if (EngineInput::GetKey(EngineInput::KeyCode::W))
    add.y--;
  if (EngineInput::GetKey(EngineInput::KeyCode::S))
    add.y++;
  if (EngineInput::GetKey(EngineInput::KeyCode::A))
    add.x--;
  if (EngineInput::GetKey(EngineInput::KeyCode::D))
    add.x++;

  vel += (add.Normalized() * max) * acc;
  vel = vel.Magnitude() < max ? vel : vel.Normalized() * max;
  rb->velocity = vel;
}

void SysPlayer::Quit() {}
