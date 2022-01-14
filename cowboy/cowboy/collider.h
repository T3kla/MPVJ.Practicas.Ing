#pragma once

#include "vec.h"

class Entity;

struct Collider {
  Entity *entity = nullptr;
  bool enable = true;

  enum class Type { None, Default, Square, Circle };

  Type type = Type::Default;

  Vec2 size = {1.f, 1.f};
  float radius = 1.f;
};
