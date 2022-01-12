#pragma once

#include "vec.h"

struct Transform {
  Vec2 position = {0.f, 0.f};
  Vec2 scale = {1.f, 1.f};
  float rotation = 0.f;

  Transform(Vec2 position = {0.f, 0.f}, Vec2 scale = {1.f, 1.f},
            float rotation = 0.f)
      : position(position), scale(scale), rotation(rotation) {}
};
