#pragma once

#include "vec.h"

class Entity;

struct Bullet {
  Entity *entity = nullptr;
  bool enable = true;

  float speed = 500.f;
  int damage = 5;
};
