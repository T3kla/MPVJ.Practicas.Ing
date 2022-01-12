#pragma once

#include "color.h"
#include "vec.h"

struct OvalRenderer {
  Vec2 offsetPosition = {0.f, 0.f};
  Vec2 offsetScale = {100.f, 100.f};
  Color color = {1.f, 1.f, 1.f, 1.f};
};
