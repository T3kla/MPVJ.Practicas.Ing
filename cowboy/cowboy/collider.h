#pragma once

#include "vec.h"

class Entity;
class CollisionBehaviour;

struct Collider {
  Entity *entity = nullptr;
  bool enable = true;

  enum class Type { None, Default, Square, Circle };

  CollisionBehaviour *collisionBehaviour = nullptr;
  Type type = Type::Default;
  Vec2 size = {1.f, 1.f};
  float radius = 1.f;
};
