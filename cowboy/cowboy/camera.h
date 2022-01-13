#pragma once

class Entity;

struct Camera {
  Entity *entity = nullptr;
  bool enable = true;

  bool main = false;
  float height = 1.f;
};
