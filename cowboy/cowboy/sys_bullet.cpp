#include "sys_bullet.h"

#include "bullet.h"
#include "engine.h"
#include "rigidbody.h"
#include "stasis.h"
#include "transform.h"
#include "vec.h"

#include <entt/entt.hpp>

SysBullet::SysBullet() {}
SysBullet::~SysBullet() {}

void SysBullet::Awake() {}

void SysBullet::Start() {}

void SysBullet::Update() {
  // auto bullets = Engine::GetRegistry().view<Transform, Rigidbody, Bullet>();

  // for (auto [entity, tf, bl] : bullets.each()) {
  //   tf.position +=
  //       bl.direction * bl.speed * (float)Stasis::GetDeltaScaled() * 0.001f;
  // }
}

void SysBullet::Fixed() {}

void SysBullet::Quit() {}
