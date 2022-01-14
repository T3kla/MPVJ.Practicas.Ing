#pragma once

#include "vec.h"

class Entity;

struct Rigidbody {
  Entity *entity = nullptr;
  bool enable = true;

  Vec2 velocity = {0.f, 0.f};
  float linearDamp = 0.01f;
};
