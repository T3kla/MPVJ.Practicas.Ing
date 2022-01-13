#pragma once

#include "vec.h"

class Entity;

struct Transform {
  Entity *entity = nullptr;
  bool enable = true;

  Vec2 position = {0.f, 0.f};
  Vec2 scale = {1.f, 1.f};
  float rotation = 0.f;
};
