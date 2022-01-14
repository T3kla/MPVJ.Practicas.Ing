#include "sys_physics.h"

#include "collider.h"
#include "engine.h"
#include "rigidbody.h"
#include "stasis.h"
#include "transform.h"
#include "vec.h"

#include <entt/entt.hpp>

SysPhysics::SysPhysics() {}
SysPhysics::~SysPhysics() {}

void SysPhysics::Awake() {}

void SysPhysics::Start() {}

void SysPhysics::Update() {}

void SysPhysics::Fixed() {
  auto bullets = Engine::GetRegistry().view<Transform, Rigidbody, Collider>();

  for (auto [entity, tf0, rb0, cl0] : bullets.each()) {
    tf0.position += rb0.velocity * (float)STP * 0.001f;
    rb0.velocity = rb0.velocity / rb0.linearDamp;

    auto xTop0 = tf0.position.x + cl0.size.x / 2.f;
    auto xBot0 = tf0.position.x - cl0.size.x / 2.f;
    auto yTop0 = tf0.position.y + cl0.size.y / 2.f;
    auto yBot0 = tf0.position.y - cl0.size.y / 2.f;

    auto Inside = [](const float &t, const float &b, const float &v) {
      return v > t ? false : v < b ? false : true;
    };

    for (auto [entity, tf1, rb1, cl1] : bullets.each()) {

      auto sqr = Collider::Type::Square;
      auto crl = Collider::Type::Square;

      // Collision Square vs Square
      if (cl0.type == sqr && cl1.type == sqr) {

        auto xTop1 = tf1.position.x + cl1.size.x / 2.f;
        auto xBot1 = tf1.position.x - cl1.size.x / 2.f;
        auto yTop1 = tf1.position.y + cl1.size.y / 2.f;
        auto yBot1 = tf1.position.y - cl1.size.y / 2.f;

        if ((Inside(xTop0, xBot0, xTop1) || Inside(xTop0, xBot0, xBot1)) &&
            (Inside(yTop0, yBot0, yTop1) || Inside(yTop0, yBot0, yBot1))) {
          // TODO: collision
        }
      }

      // Collision Circle vs Circle
      if (cl0.type == crl && cl1.type == crl) {

        if ((tf0.position - tf1.position).MagnitudeSq() <=
            powf(cl0.radius + cl1.radius, 2)) {
          // TODO: collision
        }
      }
    }
  }
}

void SysPhysics::Quit() {}
