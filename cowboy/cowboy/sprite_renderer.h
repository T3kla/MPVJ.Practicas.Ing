#pragma once

#include "litegfx.h"
#include "vec.h"

class Entity;
struct Sprite;

struct SpriteRenderer {
  Entity *entity = nullptr;
  bool enable = true;

  Sprite *sprite = nullptr;

  Vec2 offsetPosition = {0.f, 0.f};
  float offsetRotation = 0.f;

  Vec2 size = {100.f, 100.f};
  Vec2 pivot = {0.5f, 0.5f};
  int layer = 0;

  lblend_t blend = BLEND_ADD;
};
